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

#pragma once

#include <string>

#include "sql/stmt/stmt.h"

struct CreateIndexSqlNode;
class Table;
class FieldMeta;

/**
 * @brief 创建索引的语句
 * @ingroup Statement
 */
class CreateIndexStmt : public Stmt
{
public:
<<<<<<< HEAD
  // 构造函数支持多个字段元信息
  CreateIndexStmt(Table *table, const std::vector<const FieldMeta *> &field_metas, const std::string &index_name)
      : table_(table), field_metas_(field_metas), index_name_(index_name)
=======
  CreateIndexStmt(Table *table, std::vector<FieldMeta> field_metas, const std::string &index_name, bool unique)
        : table_(table),
          field_metas_(field_metas),
          index_name_(index_name),
          unique_(unique)
>>>>>>> Update
  {}

  virtual ~CreateIndexStmt() = default;

  StmtType type() const override { return StmtType::CREATE_INDEX; }

<<<<<<< HEAD
  Table *table() const { return table_; }

  // 返回多个字段元信息
  const std::vector<const FieldMeta *> &field_metas() const { return field_metas_; }
  
=======
  Table             *table() const { return table_; }
  const std::vector<FieldMeta> field_metas() const { return field_metas_; }
>>>>>>> Update
  const std::string &index_name() const { return index_name_; }

  const bool unique() const { return unique_; }


public:
  static RC create(Db *db, const CreateIndexSqlNode &create_index, Stmt *&stmt);

private:
  Table *table_ = nullptr;
<<<<<<< HEAD
  
  // 支持多个字段元信息
  std::vector<const FieldMeta *> field_metas_;
  
  std::string index_name_;
};
=======
  const std::vector<FieldMeta> field_metas_;
  std::string index_name_;
  bool unique_;
};
>>>>>>> Update
