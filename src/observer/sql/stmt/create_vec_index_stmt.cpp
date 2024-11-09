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
// Created by Wangyunlai on 2023/4/25.
//

#include "sql/stmt/create_vec_index_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "storage/index/ivfflat_index.h"

using namespace std;
using namespace common;

RC CreateVecIndexStmt::create(Db *db, const CreateVecIndexSqlNode &create_vec_index, Stmt *&stmt)
{
  stmt = nullptr;

  const char *table_name = create_vec_index.relation_name.c_str();
  if (is_blank(table_name) || is_blank(create_vec_index.index_name.c_str())) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, index name=%s",
        db, table_name, create_vec_index.index_name.c_str());
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  const FieldMeta *field_meta = table->table_meta().field(create_vec_index.attribute_name.c_str());
  if (field_meta == nullptr){
    LOG_WARN("no such field in table. db=%s, table=%s, field name=%s", 
       db->name(), table_name, create_vec_index.attribute_name.c_str());
    return RC::SCHEMA_FIELD_NOT_EXIST;   
  }

  if (field_meta->type() !=AttrType::VECTORS ){
    LOG_WARN("field type is not vector. db=%s, table=%s, field name=%s", 
       db->name(), table_name, create_vec_index.attribute_name.c_str());
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  // 检查索引是否已存在
  Index *index = table->find_vec_index(create_vec_index.index_name.c_str());
  if (nullptr != index) {
    LOG_WARN("index with name(%s) already exists. table name=%s", create_vec_index.index_name.c_str(), table_name);
    return RC::SCHEMA_INDEX_NAME_REPEAT;
  }

  if (create_vec_index.distance_name != FuncOp::I2_DISTANCE && create_vec_index.distance_name != FuncOp::COSINE_DISTANCE && create_vec_index.distance_name != FuncOp::INNER_PRODUCT){
    LOG_WARN("distance name is illegal.");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  if (create_vec_index.nlist <= 0 || create_vec_index.probes <= 0) {
    LOG_WARN("nlist or probes is illegal.");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  stmt = new CreateVecIndexStmt(table, field_meta, create_vec_index.index_name, create_vec_index.distance_name, create_vec_index.nlist, create_vec_index.probes);
  return RC::SUCCESS;
}

