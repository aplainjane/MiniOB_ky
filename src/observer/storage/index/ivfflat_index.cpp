#include "storage/index/ivfflat_index.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "storage/db/db.h"
#include "storage/index/IndexIVVFlat.h"


RC IvfflatIndex::create(Table *table, const IndexMeta &index_meta, const FieldMeta &field_meta)
{
  if (inited_) {
    LOG_WARN("Failed to create index due to the index has been created before.index:%s, field:%s",
        index_meta.name(),
        index_meta.all_field());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_meta);

  // 特征维度从 field_meta 中获取
  dim_ = (field_meta.len() - 2)/20;

  if (distance_name_ == I2_DISTANCE) {
    index_ = new IndexIVFFlat(dim_, lists_, I2_DISTANCE);
  } else if (distance_name_ == COSINE_DISTANCE) {
    index_ = new IndexIVFFlat(dim_, lists_, COSINE_DISTANCE);
  } else if (distance_name_ == INNER_PRODUCT) {
    index_ = new IndexIVFFlat(dim_, lists_, INNER_PRODUCT);
  } else {
    return RC::INVALID_ARGUMENT; // 无效的距离类型
  }

  // 训练索引 (需要用到训练数据) vector<RID>
  std::vector<std::vector<float>> vector_values;

  if (rids_.empty()) {
    inited_ = true;
    return RC::SUCCESS;
  }
  for (int i = 0; i < rids_.size(); i++) {
    Record record;
    RC rc = table->get_record(rids_[i], record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to get record from table. rid:%d", rids_[i].page_num);
      return RC::INTERNAL;
    }

    char *vec_data = record.data() + field_meta.offset();

    Value *val = new Value(vec_data);
    values_.push_back(*val);

    std::string content(vec_data + 1, vec_data + strlen(vec_data) - 1); // 去掉中括号
    std::istringstream ss(content);
    std::string item;
    std::vector<float> vector_value;
    while (std::getline(ss, item, ',')) {
      item.erase(std::remove_if(item.begin(), item.end(), ::isspace), item.end());
      // 判断类型并添加到向量中
      try {
        if (!item.empty()) {
          if (item.find('.') != std::string::npos) {
            // 处理 float 类型
            float value = std::stof(item);
            // 四舍五入保留两位小数
            value = std::round(value * 100.0f) / 100.0f;
            vector_value.push_back(value); // 插入为 float
          } else {
            // 处理 int 类型
            int value = std::stoi(item);
            float value_float = static_cast<float>(value);
            vector_value.push_back(value_float);
          }
        }
      } catch (const std::exception &e) {
        LOG_WARN("Invalid value in vector: %s", item.c_str());
        return RC::INTERNAL;
      }
    }
    vector_values.push_back(vector_value);  
  }

  std::vector<float> flat_vector_values;
  flat_vector_values.reserve(vector_values.size() * dim_); // 预留空间

  for (const auto& vec : vector_values) {
    flat_vector_values.insert(flat_vector_values.end(), vec.begin(), vec.end());
  }

	index_->train(rids_.size(), flat_vector_values.data()); // 训练
	index_->add(rids_.size(), flat_vector_values.data()); // 插入

  inited_ = true; 
  LOG_INFO(
      "Successfully create vec index, index:%s, field:%s", index_meta.name(), index_meta.all_field());
  return RC::SUCCESS;
}

RC IvfflatIndex::close()
{
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s, field:%s", index_meta_.name(), index_meta_.fields());
    delete index_;
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

std::vector<Value> IvfflatIndex::ann_search(const Value &base, size_t limit) {
  if (base.attr_type() != AttrType::VECTORS) {
    LOG_ERROR("Invalid base value type for ANN search. Expected VECTORS");
    return vector<Value>();
  };

  vector<std::variant<int, float>> base_vector = base.get_vector();
  if (base_vector.size() != dim_) {
    LOG_ERROR("Invalid base vector size for ANN search.");
    return vector<Value>();
  }

  // 创建一个 float 向量来存储转换后的数据
  std::vector<float> float_vector;
  float_vector.reserve(dim_); // 预留空间以提高性能

  // 将 base_vector 中的 std::variant 转换为 float
  for (const auto &value : base_vector) {
    if (std::holds_alternative<float>(value)) {
      float_vector.push_back(std::get<float>(value));
    } else if (std::holds_alternative<int>(value)) {
      float_vector.push_back(static_cast<float>(std::get<int>(value)));
    } else {
      LOG_ERROR("Invalid type in base vector.");
      return vector<Value>();
    }
  }

  std::vector<Value> results;
  std::vector<std::vector<float>> float_results;
  
  std::vector<long> indices(limit);
  std::vector<float> distances(limit); // 接收查询结果的距离

	index_->setNProbe(probes_); // 设置查询时探查的簇数量
	index_->search(1, float_vector.data(), limit, distances.data(), indices.data());

  for (size_t i = 0; i < limit; i++) {
    long original_index = indices[i];
    Value val = values_[original_index];
    results.push_back(val);
  }

  return results;
}
