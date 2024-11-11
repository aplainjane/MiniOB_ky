/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2021/6/9.
//
#include <mutex>

#include "sql/operator/update_physical_operator.h"
#include "sql/stmt/insert_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(Table *table, std::vector<Field> fields, std::vector<Value> values,bool flag)
    : table_(table), fields_(fields), values_(values),flag_(flag)
{}

RC UpdatePhysicalOperator::open(Trx *trx)
{
  std::lock_guard<std::mutex> lock(mutex_); // 加锁

  if (children_.empty()) {
    return RC::SUCCESS;
  }

  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC                                 rc    = child->open(trx);

  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  while(OB_SUCC(rc = child->next())) {
    if(flag_==false){
      return RC::INTERNAL;
    }
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }
    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record   &record    = row_tuple->record();

    Record old_record = record;
    // rc = trx_->delete_record(table_, record);
    rc = table_->delete_record(record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    } else {
      const std::vector<FieldMeta> *table_field_metas = table_->table_meta().field_metas();
      std::vector<int> field_idx;

      for (auto field_:fields_){
        
        const char *target_field_name= field_.field_name();

        int meta_num = table_field_metas->size();
        int target_index = -1;
        for (int i=0; i<meta_num; ++i){
          FieldMeta fieldmeta = (*table_field_metas)[i];
          const char *field_name = fieldmeta.name();
          if (0 == strcmp(field_name, target_field_name)){
            target_index = i;
            break;
          }
        }

        if (target_index == -1){
          LOG_WARN("failed to find index");
          return RC::INTERNAL;
        }

        field_idx.emplace_back(target_index);
      }

      std::vector<Value> values;
      int cell_num = row_tuple->cell_num() - 1;
      for (int i = table_->table_meta().sys_field_num(); i < cell_num; ++i){
        Value cell;
        // find field_index
        int find_flag = -1;
        for (long unsigned int k=0;k<field_idx.size();++k){
          int target_index = field_idx[k];
          if (target_index == i){
            find_flag = k;
            break;
          } 
        }

        if (find_flag !=-1){
          cell.set_value(values_[find_flag]);
        }else{
          row_tuple->cell_at(i,cell);
        }

        values.emplace_back(cell);
      }

      Record new_record;
      RC rc = table_->make_record(static_cast<int>(values.size()), values.data(), new_record);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to make record. rc=%s", strrc(rc));
        // trx_->insert_record(table_,old_record);
        table_->insert_record(old_record);
        return rc;
      }
      rc = table_->insert_record(new_record);
      //insert_records.emplace_back(new_record);
      if (rc != RC::SUCCESS) {      
        LOG_WARN("failed to insert record: %s", strrc(rc));
        return rc;
      }
    }
    
  }

  child->close();

  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next()
{
  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close()
{
  return RC::SUCCESS;
}
