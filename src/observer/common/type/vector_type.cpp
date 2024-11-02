#include <iomanip>
#include <cstring>

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/vector_type.h"
#include "common/value.h"

#include <cmath>
#include <variant>


int VectorType::compare(const Value &left, const Value &right) const {
    if (left.attr_type() != AttrType::VECTORS || right.attr_type() != AttrType::VECTORS) {
        LOG_WARN("type not match");
        return INT32_MAX;
    }

    const auto &left_values = left.get_vector();
    const auto &right_values = right.get_vector();
    
    // Compare element by element
    size_t min_size = std::min(left_values.size(), right_values.size());

    float product = 0;
    for (size_t i = 0; i < min_size; ++i) {
        bool left_is_float = std::holds_alternative<float>(left.vector_values_[i]);
        bool right_is_float = std::holds_alternative<float>(right.vector_values_[i]);

        if (left_is_float || right_is_float) {
          float left_value = left_is_float ? std::get<float>(left.vector_values_[i]) : static_cast<float>(std::get<int>(left.vector_values_[i]));
          float right_value = right_is_float ? std::get<float>(right.vector_values_[i]) : static_cast<float>(std::get<int>(right.vector_values_[i]));
          product = left_value - right_value;
        } else {
          product = std::get<int>(left.vector_values_[i]) - std::get<int>(right.vector_values_[i]);
        }
        if (product > 0.001) {
            return 1;
        } else if (product < -0.001) {
            return -1;
        }
    }

    // 如果所有比较的元素相等，较短的向量被认为是“较小的”
    if (left_values.size() < right_values.size()) {
        return -1; // left is less than right
    } else if (left_values.size() > right_values.size()) {
        return 1;  // left is greater than right
    }

    return 0; // They are equal
}

RC VectorType::add(const Value &left, const Value &right, Value &result) const
{
  if (left.attr_type()!=AttrType::VECTORS || right.attr_type()!=AttrType::VECTORS){
    LOG_WARN("type not match");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  const auto &left_values = left.get_vector();
  const auto &right_values = right.get_vector();
  
  ASSERT(left_values.size() == right_values.size(),"size must be equal");
  result.set_type(AttrType::VECTORS);

  // add element by element
  std::vector<std::variant<int, float>> sum_values;
  for (size_t i = 0; i < left.vector_values_.size(); ++i) {
    // 检查元素类型
    bool left_is_float = std::holds_alternative<float>(left.vector_values_[i]);
    bool right_is_float = std::holds_alternative<float>(right.vector_values_[i]);

    if (left_is_float || right_is_float) {
      float left_value = left_is_float ? std::get<float>(left.vector_values_[i]) : static_cast<float>(std::get<int>(left.vector_values_[i]));
      float right_value = right_is_float ? std::get<float>(right.vector_values_[i]) : static_cast<float>(std::get<int>(right.vector_values_[i]));
      float product = left_value + right_value;
      // 保留两位小数，使用浮点数表示
      product = std::round(product * 100.0f) / 100.0f;
      // 将结果存入结果向量
      sum_values.push_back(product);
    } else {
      // 两个都是整数
      sum_values.push_back(std::get<int>(left.vector_values_[i]) + std::get<int>(right.vector_values_[i]));
    }
  }

  result.set_vector(sum_values);
  return RC::SUCCESS;
}

RC VectorType::subtract(const Value &left, const Value &right, Value &result) const
{
  if (left.attr_type()!=AttrType::VECTORS || right.attr_type()!=AttrType::VECTORS){
    LOG_WARN("type not match");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  const auto &left_values = left.get_vector();
  const auto &right_values = right.get_vector();
  
  ASSERT(left_values.size() == right_values.size(),"size must be equal");
  result.set_type(AttrType::VECTORS);

  // subtract element by element
  std::vector<std::variant<int, float>> sub_values;
  for (size_t i = 0; i < left.vector_values_.size(); ++i) {
    // 检查元素类型
    bool left_is_float = std::holds_alternative<float>(left.vector_values_[i]);
    bool right_is_float = std::holds_alternative<float>(right.vector_values_[i]);

    if (left_is_float || right_is_float) {
      float left_value = left_is_float ? std::get<float>(left.vector_values_[i]) : static_cast<float>(std::get<int>(left.vector_values_[i]));
      float right_value = right_is_float ? std::get<float>(right.vector_values_[i]) : static_cast<float>(std::get<int>(right.vector_values_[i]));
      
      float product = left_value - right_value;
      // 保留两位小数，使用浮点数表示
      product = std::round(product * 100.0f) / 100.0f;
      // 将结果存入结果向量
      sub_values.push_back(product);
    } else {
      // 两个都是整数
      sub_values.push_back(std::get<int>(left.vector_values_[i]) - std::get<int>(right.vector_values_[i]));
    }
  }
  
  result.set_vector(sub_values);
  return RC::SUCCESS;
}

RC VectorType::multiply(const Value &left, const Value &right, Value &result) const
{
  if (left.attr_type()!=AttrType::VECTORS || right.attr_type()!=AttrType::VECTORS){
    LOG_WARN("type not match");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  const auto &left_values = left.get_vector();
  const auto &right_values = right.get_vector();

  ASSERT(left_values.size() == right_values.size(),"size must be equal");
  result.set_type(AttrType::VECTORS);

  // multiply element by element
  std::vector<std::variant<int, float>> mul_values;
  for (size_t i = 0; i < left.vector_values_.size(); ++i) {
    // 检查元素类型
    bool left_is_float = std::holds_alternative<float>(left.vector_values_[i]);
    bool right_is_float = std::holds_alternative<float>(right.vector_values_[i]);

    if (left_is_float || right_is_float) {
      float left_value = left_is_float ? std::get<float>(left.vector_values_[i]) : static_cast<float>(std::get<int>(left.vector_values_[i]));
      float right_value = right_is_float ? std::get<float>(right.vector_values_[i]) : static_cast<float>(std::get<int>(right.vector_values_[i]));
      
      // 计算乘积
      float product = left_value * right_value;

      // 保留两位小数
      product = std::round(product * 100.0f) / 100.0f;

      // 将结果存入结果向量
      mul_values.push_back(product);
    } else {
      // 两个都是整数
      mul_values.push_back(std::get<int>(left.vector_values_[i]) * std::get<int>(right.vector_values_[i]));
    }
  }

  result.set_vector(mul_values);
  return RC::SUCCESS;
}

RC VectorType::to_string(const Value &val, string &result) const
{
    std::ostringstream oss;
    oss << "[";
    const auto &val_vec = val.get_vector();
    for (size_t i = 0; i < val_vec.size(); ++i) {
        if (i != 0) oss << ",";
            if (std::holds_alternative<int>(val_vec[i])) {
                oss << std::get<int>(val_vec[i]);
            } else {
                oss << std::get<float>(val_vec[i]);
            }
    }
    oss << "]";
    result = oss.str();
    return RC::SUCCESS;
}
