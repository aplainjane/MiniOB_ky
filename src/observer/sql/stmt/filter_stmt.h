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


#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/parser/expression_binder.h"
#include "sql/expr/expression.h"
#include <unordered_map>
#include <vector>

class Db;
class Table;
class FieldMeta;
class Field;
class Expression;

class FilterObj
{
  public:
  // 进行类型判断，默认为value
  bool                  is_tuple=false;
  bool                  is_attr=false;
  bool                  is_aggr=false;
  bool                  is_arthi=false; 
  bool                  is_subquery=false;
  
  Field field;
  Value value;
  vector<Value> tuple_list;
  unique_ptr<Expression>   expr;
  string sql_result="";
  std::unordered_map<std::string, Table *> tables;
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
  void init_sql_result(string sql_result,std::unordered_map<std::string, Table *> tables)
  {
    is_attr     = false;
    is_aggr    = false;
    is_arthi   = false;
    is_tuple    = false;
    is_subquery =true;
    this->sql_result = sql_result;
    this->tables=tables;
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

  string conjunction;
private:
  std::vector<FilterUnit *> filter_units_;  // 默认当前都是AND关系
  
};
