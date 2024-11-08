/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Meiyi & Wangyunlai on 2021/5/13.
//

#include <limits.h>
#include <string.h>

#include "common/defs.h"
#include "common/lang/string.h"
#include "common/lang/span.h"
#include "common/lang/algorithm.h"
#include "common/log/log.h"
#include "common/global_context.h"
#include "storage/db/db.h"
#include "storage/buffer/disk_buffer_pool.h"
#include "storage/common/condition_filter.h"
#include "storage/common/meta_util.h"
#include "storage/index/bplus_tree_index.h"
#include "storage/index/index.h"
#include "storage/record/record_manager.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "cmath"

Table::~Table()
{
  if (record_handler_ != nullptr) {
    delete record_handler_;
    record_handler_ = nullptr;
  }

  if (data_buffer_pool_ != nullptr) {
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
  }

  if(text_buffer_pool_ != nullptr) {
    text_buffer_pool_->close_file();
    text_buffer_pool_ = nullptr;
  }

  for (vector<Index *>::iterator it = indexes_.begin(); it != indexes_.end(); ++it) {
    Index *index = *it;
    delete index;
  }
  indexes_.clear();

  LOG_INFO("Table has been closed: %s", name());
}

RC Table::create(Db *db, int32_t table_id, const char *path, const char *name, const char *base_dir,
    span<const AttrInfoSqlNode> attributes, StorageFormat storage_format)
{
  if (table_id < 0) {
    LOG_WARN("invalid table id. table_id=%d, table_name=%s", table_id, name);
    return RC::INVALID_ARGUMENT;
  }

  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }
  LOG_INFO("Begin to create table %s:%s", base_dir, name);

  if (attributes.size() == 0) {
    LOG_WARN("Invalid arguments. table_name=%s, attribute_count=%d", name, attributes.size());
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;

  // 使用 table_name.table记录一个表的元数据
  // 判断表文件是否已经存在
  int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  if (fd < 0) {
    if (EEXIST == errno) {
      LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s", path, strerror(errno));
      return RC::SCHEMA_TABLE_EXIST;
    }
    LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s", path, errno, strerror(errno));
    return RC::IOERR_OPEN;
  }

  close(fd);

  // 创建文件
  const vector<FieldMeta> *trx_fields = db->trx_kit().trx_fields();
  if ((rc = table_meta_.init(table_id, name, trx_fields, attributes, storage_format)) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
    return rc;  // delete table file
  }

  fstream fs;
  fs.open(path, ios_base::out | ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", path, strerror(errno));
    return RC::IOERR_OPEN;
  }

  // 记录元数据到文件中
  table_meta_.serialize(fs);
  fs.close();

  db_       = db;
  base_dir_ = base_dir;

  string             data_file = table_data_file(base_dir, name);
  BufferPoolManager &bpm       = db->buffer_pool_manager();
  rc                           = bpm.create_file(data_file.c_str());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create disk buffer pool of data file. file name=%s", data_file.c_str());
    return rc;
  }

  rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create table %s due to init record handler failed.", data_file.c_str());
    // don't need to remove the data_file
    return rc;
  }

  // 创建文件存放text
  bool have_text = false;
  for (const FieldMeta &field : *table_meta_.field_metas()) {
    if (field.type() == AttrType::TEXTS || field.type() == AttrType::VECTORS) {
      have_text = true;
      break;
    }
  }
  if (have_text) {
    std::string text_file = table_text_file(base_dir, name);
    rc = bpm.create_file(text_file.c_str());
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create disk buffer pool of text file. file name=%s", text_file.c_str());
      return rc;
    }
    rc = init_text_handler(base_dir);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create table %s due to init text handler failed.", text_file.c_str());
      // don't need to remove the data_file
      return rc;
    }
  }

  base_dir_ = base_dir;
  LOG_INFO("Successfully create table %s:%s", base_dir, name);
  return rc;
}
RC Table::drop(const char *path)
{
  if(::remove(path)<0){
    LOG_ERROR("Failed to delete table file,filename=%s,errmsg=%s",path,strerror(errno));
    return RC::INTERNAL;
  }
  string             data_file = table_data_file(base_dir_.c_str(), table_meta_.name());
  BufferPoolManager &bpm       = db_->buffer_pool_manager();
  bpm.remove_file(data_file.c_str());
  data_buffer_pool_=nullptr;
  if(record_handler_!=nullptr){
    delete record_handler_;
    record_handler_=nullptr;
  }

  if (text_buffer_pool_ != nullptr) {
    string text_file = table_text_file(base_dir_.c_str(), table_meta_.name());
    bpm.remove_file(text_file.c_str());
  }

  for(auto &index : indexes_){
    index->destroy();
    delete index;
    index=nullptr;
  }
  return RC::SUCCESS;
}
RC Table::open(Db *db, const char *meta_file, const char *base_dir)
{
  // 加载元数据文件
  fstream fs;
  string  meta_file_path = string(base_dir) + common::FILE_PATH_SPLIT_STR + meta_file;
  fs.open(meta_file_path, ios_base::in | ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open meta file for read. file name=%s, errmsg=%s", meta_file_path.c_str(), strerror(errno));
    return RC::IOERR_OPEN;
  }
  if (table_meta_.deserialize(fs) < 0) {
    LOG_ERROR("Failed to deserialize table meta. file name=%s", meta_file_path.c_str());
    fs.close();
    return RC::INTERNAL;
  }
  fs.close();

  db_       = db;
  base_dir_ = base_dir;

  // 加载数据文件
  RC rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open table %s due to init record handler failed.", base_dir);
    // don't need to remove the data_file
    return rc;
  }

  // rc = init_text_handler(base_dir);
  // if (rc != RC::SUCCESS) {
  //   LOG_ERROR("Failed to open table %s due to init text handler failed.", base_dir);
  //   return rc;
  // }

  const int index_num = table_meta_.index_num();
  for (int i = 0; i < index_num; i++) {
    const IndexMeta *index_meta = table_meta_.index(i);
    // const FieldMeta *field_meta = table_meta_.field(index_meta->field());
    std::vector<FieldMeta> field_metas;
    for (const char * field: index_meta->fields()){
      const FieldMeta *field_meta = table_meta_.field(field);
      if (field_meta == nullptr){
        return RC::INTERNAL;
      }
      field_metas.emplace_back(*table_meta_.field(field));
    }

    if (field_metas.size()==0){
      LOG_ERROR("Found invalid index meta info which has a non-exists field. table=%s, index=%s, field=%s",
                name(), index_meta->name(), index_meta->all_field());
      // skip cleanup
      //  do all cleanup action in destructive Table function
      return RC::INTERNAL;
    }

    BplusTreeIndex *index      = new BplusTreeIndex();
    string          index_file = table_index_file(base_dir, name(), index_meta->name());

    rc = index->open(this, index_file.c_str(), *index_meta, field_metas);
    if (rc != RC::SUCCESS) {
      delete index;
      LOG_ERROR("Failed to open index. table=%s, index=%s, file=%s, rc=%s",
                name(), index_meta->name(), index_file.c_str(), strrc(rc));
      // skip cleanup
      //  do all cleanup action in destructive Table function.
      return rc;
    }
    indexes_.push_back(index);
  }

  return rc;
}

RC Table::insert_record(Record &record)
{
  RC rc = RC::SUCCESS;
  rc    = record_handler_->insert_record(record.data(), table_meta_.record_size(), &record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  rc = insert_entry_of_indexes(record.data(), record.rid());
  if (rc != RC::SUCCESS) {  // 可能出现了键值重复
    RC rc2 = record_handler_->delete_record(&record.rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
  }
  return rc;
}


RC Table::update_record(Record &new_record, Record &old_record)
{

  RC rc = RC::SUCCESS;

  // 1. 删除旧记录的索引条目
  for (Index *index : indexes_) {
    rc = index->delete_entry(old_record.data(), &old_record.rid());
    ASSERT(RC::SUCCESS == rc, 
           "failed to delete entry from index. table name=%s, index name=%s, rid=%s, rc=%s",
           name(), index->index_meta().name(), old_record.rid().to_string().c_str(), strrc(rc));
  }
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete index entries for old record. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  // 2. 删除旧记录
  rc = record_handler_->delete_record(&old_record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete old record. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  // 3. 插入新记录
  rc = record_handler_->insert_record(new_record.data(), table_meta_.record_size(), &new_record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to insert new record. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  // 4. 插入新记录的索引条目
  rc = insert_entry_of_indexes(new_record.data(), new_record.rid());
  if (rc != RC::SUCCESS) {  
    // 插入新记录的索引失败，回滚新插入的记录
    LOG_ERROR("Failed to insert index entries for new record. table name=%s, rc=%s", table_meta_.name(), strrc(rc));

    // 回滚: 删除新插入的记录
    RC rc2 = record_handler_->delete_record(&new_record.rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback new record after index insertion failure. table name=%s, rc=%s", table_meta_.name(), strrc(rc2));
    }

    return rc;  // 返回索引插入失败的错误码
  }

  return RC::SUCCESS;  // 更新成功
}


RC Table::visit_record(const RID &rid, function<bool(Record &)> visitor)
{
  return record_handler_->visit_record(rid, visitor);
}

RC Table::get_record(const RID &rid, Record &record)
{
  RC rc = record_handler_->get_record(rid, record);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to visit record. rid=%s, table=%s, rc=%s", rid.to_string().c_str(), name(), strrc(rc));
    return rc;
  }

  return rc;
}

RC Table::recover_insert_record(Record &record)
{
  RC rc = RC::SUCCESS;
  rc    = record_handler_->recover_insert_record(record.data(), table_meta_.record_size(), record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  rc = insert_entry_of_indexes(record.data(), record.rid());
  if (rc != RC::SUCCESS) {  // 可能出现了键值重复
    RC rc2 = delete_entry_of_indexes(record.data(), record.rid(), false /*error_on_not_exists*/);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
    rc2 = record_handler_->delete_record(&record.rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
  }
  return rc;
}

const char *Table::name() const { return table_meta_.name(); }

const TableMeta &Table::table_meta() const { return table_meta_; }

RC Table::make_record(int value_num, const Value *values, Record &record)
{
  RC rc = RC::SUCCESS;

  // 检查字段数量是否一致
  // 同样，由于bitmap列的存在，value_num需要+1
  if (1 + value_num + table_meta_.sys_field_num() != table_meta_.field_num()) {
    LOG_WARN("Input values don't match the table's schema, table name:%s", table_meta_.name());
    return RC::SCHEMA_FIELD_MISSING;
  }
  // 检查字段类型是否一致
  // 当不一致时，要判断该字段是否允许NULL值
  std::vector<int> bit_map(value_num, !NULL_FLAG);
  const int normal_field_start_index = table_meta_.sys_field_num();
  // 复制所有字段的值
  int record_size = table_meta_.record_size() + 4;
  char *record_data = (char *)malloc(record_size);

  for (int i = 0; i < value_num; i++) {
    const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
    const Value &value = values[i];

    
    // 类型不一致，字段nullable，且value为INTS && NULL_VALUE，表明该记录的该字段为null
    if (field->nullable() && value.attr_type() == AttrType::NULLS) {
      bit_map[i] = NULL_FLAG;
      continue;
    }
    if (!field->nullable() && value.attr_type() == AttrType::NULLS) {
      rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
      LOG_WARN("field can not be null. table name:%s,field name:%s", table_meta_.name(), field->name());
      return rc;
    }
    if (field->type() != value.attr_type()) {
      if (field->type() == AttrType::TEXTS && value.attr_type() == AttrType::CHARS) {
        // 需要将value中的字符串插入到文件中，然后将offset、length写入record
        int64_t position[2];
        position[1] = value.length();
        text_buffer_pool_->append_data(position[0], position[1], value.data());
        memcpy(record_data + field->offset(), position, 2 * sizeof(int64_t));
      } else {
        Value real_value;
        rc = Value::cast_to(value, field->type(), real_value);
        if (OB_FAIL(rc)) {
          LOG_WARN("failed to cast value. table name:%s,field name:%s,value:%s ",
            table_meta_.name(), field->name(), value.to_string().c_str());
          break;
        }
        rc = set_value_to_record(record_data, real_value, field);
      }
    } else {
      if (field->type() == AttrType::VECTORS && value.get_vector().size() > 1000) {
        int64_t position[2];
        position[1] = value.length();
        text_buffer_pool_->append_data(position[0], position[1], value.data());
        memcpy(record_data + field->offset(), position, 2 * sizeof(int64_t));
      } else rc = set_value_to_record(record_data, value, field);
    }
  }

  if (OB_FAIL(rc)) {
    LOG_WARN("failed to make record. table name:%s", table_meta_.name());
    free(record_data);
    return rc;
  }

  // 写入bitmap字段的值
  const FieldMeta *field = table_meta_.field(value_num + normal_field_start_index);
  Value* value = new Value(bitmap2int(bit_map));
  size_t copy_len = field->len();
  memcpy(record_data + field->offset(), value->data(), copy_len);

  record.set_data_owner(record_data, record_size);
  return RC::SUCCESS;
}

RC Table::set_value_to_record(char *record_data, const Value &value, const FieldMeta *field)
{
  size_t       copy_len = field->len();
  const size_t data_len = strlen(value.data());
  if (field->type() == AttrType::CHARS || field->type() == AttrType::VECTORS) {
    if (copy_len > data_len) {
      copy_len = data_len + 1;
    }
  }

  memcpy(record_data + field->offset(), value.data(), copy_len);
  return RC::SUCCESS;
}


RC Table::write_text(int64_t &offset, int64_t length, const char *data)
{
  RC rc = RC::SUCCESS;
  rc = text_buffer_pool_->append_data(offset, length, data);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to append text into disk_buffer_pool, rc=%s", strrc(rc));
    offset = -1;
    length = -1;
  }
  LOG_INFO("write text to disk_buffer_pool, offset=%ld, length=%ld", offset, length);
  return rc;
}
RC Table::read_text(int64_t offset, int64_t length, char *data) const
{
  RC rc = RC::SUCCESS;
  if (offset < 0 || length < 0) {
    LOG_ERROR("Invalid param: text offset %ld, length %ld", offset, length);
    return RC::INVALID_ARGUMENT;
  }
  rc = text_buffer_pool_->get_data(offset, length, data);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to get text from disk_buffer_pool, rc=%s", strrc(rc));
  }
  return rc;
}

RC Table::init_record_handler(const char *base_dir)
{
  string data_file = table_data_file(base_dir, table_meta_.name());

  BufferPoolManager &bpm = db_->buffer_pool_manager();
  RC                 rc  = bpm.open_file(db_->log_handler(), data_file.c_str(), data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s", data_file.c_str(), rc, strrc(rc));
    return rc;
  }

  record_handler_ = new RecordFileHandler(table_meta_.storage_format());

  rc = record_handler_->init(*data_buffer_pool_, db_->log_handler(), &table_meta_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to init record handler. rc=%s", strrc(rc));
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
    delete record_handler_;
    record_handler_ = nullptr;
    return rc;
  }

  return rc;
}

RC Table::init_text_handler(const char *base_dir)
{
  RC rc = RC::SUCCESS;
  std::string text_file = table_text_file(base_dir, table_meta_.name());

  bool exist = false;
  int fd = ::open(text_file.c_str(), O_RDONLY, 0600);
  if (fd > 0) exist = true;
  close(fd);
  
  if (exist) {
      BufferPoolManager &bpm = db_->buffer_pool_manager();
      rc = bpm.open_file(db_->log_handler(),text_file.c_str(), text_buffer_pool_);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s", text_file.c_str(), rc, strrc(rc));
      return rc;
    }
  }
  return rc;
}

RC Table::get_record_scanner(RecordFileScanner &scanner, Trx *trx, ReadWriteMode mode)
{
  RC rc = scanner.open_scan(this, *data_buffer_pool_, trx, db_->log_handler(), mode, nullptr);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%s", strrc(rc));
  }
  return rc;
}

RC Table::get_chunk_scanner(ChunkFileScanner &scanner, Trx *trx, ReadWriteMode mode)
{
  RC rc = scanner.open_scan_chunk(this, *data_buffer_pool_, db_->log_handler(), mode);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%s", strrc(rc));
  }
  return rc;
}

RC Table::create_index(Trx *trx, std::vector<FieldMeta> field_metas, const char *index_name, bool unique)
{
  if (common::is_blank(index_name) || !field_metas.size()) {
    LOG_INFO("Invalid input arguments, table name is %s, index_name is blank or attribute_name is blank", name());
    return RC::INVALID_ARGUMENT;
  }

  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, field_metas, unique);
  if (rc != RC::SUCCESS) {
    // LOG_INFO("Failed to init IndexMeta in table:%s, index_name:%s, field_name:%s", 
    //          name(), index_name, field_metas);
    return rc;
  }

  // 创建索引相关数据
  BplusTreeIndex *index = new BplusTreeIndex();
  std::string index_file = table_index_file(base_dir_.c_str(), name(), index_name);
  rc = index->create(this, index_file.c_str(), new_index_meta, field_metas, unique);
  if (rc != RC::SUCCESS) {
    delete index;
    LOG_ERROR("Failed to create bplus tree index. file name=%s, rc=%d:%s", index_file.c_str(), rc, strrc(rc));
    return rc;
  }

  // 遍历当前的所有数据，插入这个索引
  RecordFileScanner scanner;
  rc = get_record_scanner(scanner, trx, ReadWriteMode::READ_ONLY/*readonly*/);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create scanner while creating index. table=%s, index=%s, rc=%s", 
             name(), index_name, strrc(rc));
    return rc;
  }

  Record record;
  while (OB_SUCC(rc = scanner.next(record))) {
    rc = index->insert_entry(record.data(), &record.rid());
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record into index while creating index. table=%s, index=%s, rc=%s",
               name(), index_name, strrc(rc));
      return rc;         
    }
  }
  scanner.close_scan();
  LOG_INFO("inserted all records into new index. table=%s, index=%s", name(), index_name);
  
  indexes_.push_back(index);

  /// 接下来将这个索引放到表的元数据中
  TableMeta new_table_meta(table_meta_);
  rc = new_table_meta.add_index(new_index_meta);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to add index (%s) on table (%s). error=%d:%s", index_name, name(), rc, strrc(rc));
    return rc;
  }

  /// 内存中有一份元数据，磁盘文件也有一份元数据。修改磁盘文件时，先创建一个临时文件，写入完成后再rename为正式文件
  /// 这样可以防止文件内容不完整
  // 创建元数据临时文件
  std::string tmp_file = table_meta_file(base_dir_.c_str(), name()) + ".tmp";
  std::fstream fs;
  fs.open(tmp_file, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", tmp_file.c_str(), strerror(errno));
    return RC::IOERR_OPEN;  // 创建索引中途出错，要做还原操作
  }
  if (new_table_meta.serialize(fs) < 0) {
    LOG_ERROR("Failed to dump new table meta to file: %s. sys err=%d:%s", tmp_file.c_str(), errno, strerror(errno));
    return RC::IOERR_WRITE;
  }
  fs.close();

  // 覆盖原始元数据文件
  std::string meta_file = table_meta_file(base_dir_.c_str(), name());
  int ret = rename(tmp_file.c_str(), meta_file.c_str());
  if (ret != 0) {
    LOG_ERROR("Failed to rename tmp meta file (%s) to normal meta file (%s) while creating index (%s) on table (%s). "
              "system error=%d:%s",
              tmp_file.c_str(), meta_file.c_str(), index_name, name(), errno, strerror(errno));
    return RC::IOERR_WRITE;
  }

  table_meta_.swap(new_table_meta);

  LOG_INFO("Successfully added a new index (%s) on the table (%s)", index_name, name());
  return rc;
}

RC Table::delete_record(const RID &rid)
{
  RC     rc = RC::SUCCESS;
  Record record;
  rc = get_record(rid, record);
  if (OB_FAIL(rc)) {
    return rc;
  }

  return delete_record(record);
}

RC Table::delete_record(const Record &record)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record.data(), &record.rid());
    ASSERT(RC::SUCCESS == rc, 
           "failed to delete entry from index. table name=%s, index name=%s, rid=%s, rc=%s",
           name(), index->index_meta().name(), record.rid().to_string().c_str(), strrc(rc));
  }
  rc = record_handler_->delete_record(&record.rid());
  return rc;
}

RC Table::insert_entry_of_indexes(const char *record, const RID &rid)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->insert_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      break;
    }
  }
  return rc;
}

RC Table::delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      if (rc != RC::RECORD_INVALID_KEY || !error_on_not_exists) {
        break;
      }
    }
  }
  return rc;
}

Index *Table::find_index(const char *index_name) const
{
  for (Index *index : indexes_) {
    if (0 == strcmp(index->index_meta().name(), index_name)) {
      return index;
    }
  }
  return nullptr;
}
Index *Table::find_index_by_fields(std::vector<const char *> fields) const
{
  const TableMeta &table_meta = this->table_meta();
  const IndexMeta *index_meta = table_meta.find_index_by_fields(fields);
  if (index_meta != nullptr) {
    return this->find_index(index_meta->name());
  }
  return nullptr;
}

RC Table::sync()
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->sync();
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to flush index's pages. table=%s, index=%s, rc=%d:%s",
          name(),
          index->index_meta().name(),
          rc,
          strrc(rc));
      return rc;
    }
  }

  rc = data_buffer_pool_->flush_all_pages();
  LOG_INFO("Sync table over. table=%s", name());
  return rc;
}


int bitmap2int(std::vector<int>& bitmap) {
  int ret = 0;
  for(int i = 0; i < bitmap.size(); i++) {      
    ret |= (bitmap[i] << i); 
  }
  return ret;
}

std::vector<int> int2bitmap(int num,int size) {
  std::vector<int> bitmap;
  while (num != 0)
  {
    bitmap.push_back(num & 1);
    num = num >> 1;
  }
  while(bitmap.size() < size) {
    bitmap.push_back(!NULL_FLAG);
  }
  return bitmap;
}