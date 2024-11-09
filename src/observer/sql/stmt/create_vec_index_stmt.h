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

struct CreateVecIndexSqlNode;
class Table;
class FieldMeta;

/**
 * @brief 创建索引的语句
 * @ingroup Statement
 */
class CreateVecIndexStmt : public Stmt
{
public:
  CreateVecIndexStmt(Table *table, const FieldMeta *field_meta, const std::string &index_name, FuncOp distance_name, int nlist, int probes)
        : table_(table),
          field_meta_(field_meta),
          index_name_(index_name),
          distance_name_(distance_name),
          nlist_(nlist),
          probes_(probes)
  {}

  virtual ~CreateVecIndexStmt() = default;

  StmtType type() const override { return StmtType::CREATE_VEC_INDEX; }

  Table             *table() const { return table_; }
  const FieldMeta *field_meta() const { return field_meta_; }
  const std::string &index_name() const { return index_name_; }
  const FuncOp distance_name() const { return distance_name_; }
  const int nlist() const { return nlist_; }
  const int probes() const { return probes_; }


public:
  static RC create(Db *db, const CreateVecIndexSqlNode &create_vec_index, Stmt *&stmt);

private:
  Table *table_ = nullptr;
  const FieldMeta *field_meta_;
  std::string index_name_;
  FuncOp distance_name_;
  // std::string type_name_; no type name. only suppose ivfflat
  int nlist_;
  int probes_;
};
