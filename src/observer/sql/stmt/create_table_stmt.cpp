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
// Created by Wangyunlai on 2023/6/13.
//

#include "common/log/log.h"
#include "common/types.h"
#include "sql/stmt/select_stmt.h"
#include "sql/expr/expression.h"
#include "sql/stmt/create_table_stmt.h"
#include "event/sql_debug.h"
#include "common/value.h"
RC CreateTableStmt::create(Db *db, const CreateTableSqlNode &create_table, Stmt *&stmt, SelectSqlNode &select_sql)
{
  StorageFormat storage_format = StorageFormat::UNKNOWN_FORMAT;
  if (create_table.storage_format.length() == 0) {
    storage_format = StorageFormat::ROW_FORMAT;
  } else {
    storage_format = get_storage_format(create_table.storage_format.c_str());
  }
  if (storage_format == StorageFormat::UNKNOWN_FORMAT) {
    return RC::INVALID_ARGUMENT;
  }

  for (int i = 0; i < create_table.attr_infos.size(); i++){
    if (create_table.attr_infos[i].type == AttrType::VECTORS && create_table.attr_infos[i].length > 16000) {
      return RC::INVALID_ARGUMENT;
    }
  }
  
  RC rc = RC::SUCCESS;
  if (select_sql.expressions.size() != 0) {
    Stmt *select_stmt = nullptr;
    std::vector<AttrInfoSqlNode> attr_infos;
    rc = SelectStmt::create(db, select_sql, select_stmt);
    if (RC::SUCCESS != rc) {
      LOG_WARN("failed to create select_stmt when create_table_select, rc=%s", strrc(rc));
      return rc;
    }
    for (std::unique_ptr<Expression> &attr_expr : static_cast<SelectStmt*>(select_stmt)->query_expressions()) {
      AttrInfoSqlNode attr_info;
      std::string str(attr_expr->alias());
      if (0 != str.length()) {
        size_t pos = str.find('.');
        if (std::string::npos == pos) {
          attr_info.name = str;
        } else {
          attr_info.name = str.substr(pos + 1);
        }
      } else {
        attr_info.name = attr_expr->name();
      }
      attr_info.type = attr_expr->value_type();
      if (ExprType::FIELD == attr_expr->type()) {
        FieldExpr *field_expr = dynamic_cast<FieldExpr*>(attr_expr.get());
        FieldMeta field = field_expr->get_field_meta();
        attr_info.length = field.len();
        attr_info.isnull = field.nullable();
      } else {
        if (ExprType::VALUE == attr_expr->type()) {
          ValueExpr *value_expr = dynamic_cast<ValueExpr*>(attr_expr.get());
          attr_info.length = value_expr->get_value().length();
         }
        bool nullable = true;
        attr_info.isnull = nullable;
      }
      attr_infos.emplace_back(attr_info);
    }
    
    if (0 != create_table.attr_infos.size()) {
      if (attr_infos.size() != create_table.attr_infos.size()) {
        LOG_ERROR("field size mismatch with output column size of select_stmt");
        return RC::INVALID_ARGUMENT;
      }
      for (size_t i = 0; i < attr_infos.size(); i++) {
        if (attr_infos[i].type != create_table.attr_infos[i].type) {
          LOG_ERROR("create_table info mismatch with sub_query");
          return RC::INVALID_ARGUMENT;
        }
      }
      AttrInfoSqlNode attr_info;
      attr_info.name = NULL_FIELD_NAME;
      attr_info.type = AttrType::INTS;
      attr_info.length = 4;
      std::vector<AttrInfoSqlNode> temp=create_table.attr_infos;
      temp.emplace_back(attr_info);
      stmt = new CreateTableStmt(db, create_table.relation_name, temp, select_stmt,storage_format);
    } else {
      AttrInfoSqlNode attr_info;
      attr_info.name = NULL_FIELD_NAME;
      attr_info.type = AttrType::INTS;
      attr_info.length = 4;
      attr_infos.emplace_back(attr_info);
      stmt = new CreateTableStmt(db, create_table.relation_name, attr_infos, select_stmt,storage_format);
    }
  } else {
    stmt = new CreateTableStmt(db, create_table.relation_name, create_table.attr_infos, nullptr,storage_format);
  }
  sql_debug("create table statement: table name %s", create_table.relation_name.c_str());
  return RC::SUCCESS;

}

StorageFormat CreateTableStmt::get_storage_format(const char *format_str) {
  StorageFormat format = StorageFormat::UNKNOWN_FORMAT;
  if (0 == strcasecmp(format_str, "ROW")) {
    format = StorageFormat::ROW_FORMAT;
  } else if (0 == strcasecmp(format_str, "PAX")) {
    format = StorageFormat::PAX_FORMAT;
  } else {
    format = StorageFormat::UNKNOWN_FORMAT;
  }
  return format;
}
