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
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include "sql/expr/expression.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/parser/expression_binder.h"

#include <unordered_map>
#include <vector>

class Db;
class Table;
class FieldMeta;

class FilterObj
{
  public:
  // 进行类型判断，默认为value
  bool                  is_tuple=false;
  bool                  is_attr;
  bool                  is_aggr;
  bool                  is_arthi; 
  
  Field field;
  Value value;
  unique_ptr<Expression>   expr;
  vector<Value>         tuple_list;
  void init_attr(const Field &field)
  {
    is_attr     = true;
    is_aggr     = false;
    is_arthi    = false;
    is_tuple    = false;
    this->field = field;
    
  }

  void init_value(const Value &value)
  {
    is_attr     = false;
    is_aggr     = false;
    is_arthi    = false;
    is_tuple    = false;
    this->value = value;
  }
  void init_tuple(vector<Value>& tuple)
  {
    is_attr          = false;
    is_aggr          = false;
    is_arthi         = false;
    is_tuple         = true;
    this->tuple_list = tuple;
  }
  
  void init_aggr(unique_ptr<Expression> &aggr)
  {
    is_attr    = false;
    is_aggr    = true;
    is_arthi   = false;
    is_tuple   = false;
    this->expr = std::move(aggr);
  }
  void init_arthi(unique_ptr<Expression> &arthi)
  {
    is_attr     = false;
    is_aggr     = false;
    is_arthi    = true;
    is_tuple    = false;
    this->expr = std::move(arthi);
  }
};

class FilterUnit
{
public:
  FilterUnit() = default;
  ~FilterUnit() {}

  void set_comp(CompOp comp) { comp_ = comp; }

  CompOp comp() const { return comp_; }

  void set_left(FilterObj &obj) { left_ = std::move(obj); }
  void set_right(FilterObj &obj) { right_ = std::move(obj); }

  FilterObj &left() { return left_; }
  FilterObj &right() { return right_; }

private:
  CompOp    comp_ = NO_OP;
  FilterObj left_;
  FilterObj right_;
};

/**
 * @brief Filter/谓词/过滤语句
 * @ingroup Statement
 */
class FilterStmt
{
public:
  FilterStmt() = default;
  virtual ~FilterStmt();

public:
  std::vector<FilterUnit *> &filter_units() { return filter_units_; }

public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const ConditionSqlNode &condition, FilterUnit *&filter_unit);

private:
  std::vector<FilterUnit *> filter_units_;  // 默认当前都是AND关系
};
