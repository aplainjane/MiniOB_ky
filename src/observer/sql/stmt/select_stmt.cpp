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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/parser/expression_binder.h"

using namespace std;
using namespace common;

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

RC SelectStmt::create(Db *db, SelectSqlNode &select_sql, Stmt *&stmt,const unordered_map<string, Table *> &table_map1)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  BinderContext binder_context;

  // collect tables in `from` statement
  vector<Table *>                tables;
  unordered_map<string, Table *> table_map=table_map1;
  unordered_map<string, string> table_alias;
  std::unordered_set<std::string> table_alias_set;
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    const char *table_name;
    table_name = select_sql.relations[i].first.c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    binder_context.add_table(table);
    tables.push_back(table);
    table_map.insert({table_name, table});

    if(select_sql.vec_order_rules.first_attr.relation_name == "")
    {
      select_sql.vec_order_rules.first_attr.relation_name = table_name;
    }
    if(select_sql.relations[i].second!="")
    {
      string alias=select_sql.relations[i].second.c_str();
      if (table_alias_set.count(alias) != 0) {
        return RC::INVALID_ARGUMENT;
      }
      table_alias_set.insert(alias);
      table_alias.insert({alias, table_name});
      table_map.insert({alias, table});
    }
  }

  // collect query fields in `select` statement
  vector<unique_ptr<Expression>> bound_expressions;
  ExpressionBinder expression_binder(binder_context);
  std::vector<std::string> expression_alias_set;
  for (int i = 0;i<(int)select_sql.expressions.size();i++) {
    RC rc = expression_binder.bind_expression(select_sql.expressions[i], bound_expressions,table_alias);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
    if(strcmp(bound_expressions[i]->alias(), "") != 0)
    {
      string alias=bound_expressions[i]->alias();
      for(int j =0;j<(int)expression_alias_set.size();j++){
        if(alias==expression_alias_set[j])
          return RC::INTERNAL;
      }
      expression_alias_set.push_back(alias);
    }
    
  }
  for (ConditionSqlNode &condition : select_sql.having_conditions)
  {
    if(condition.left_is_attr != 4)
      continue;
    unique_ptr<Expression> tmp_expr = std::unique_ptr<Expression>(condition.left_expr->deep_copy());
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
  }
  if(select_sql.vec_order_rules.type != NO_Func)
  {
    unique_ptr<Expression> tmp_expr = std::unique_ptr<Expression>(select_sql.vec_order_rules.expr);
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
    }
  } 


  vector<unique_ptr<Expression>> group_by_expressions;
  for (unique_ptr<Expression> &expression : select_sql.group_by) {
    RC rc = expression_binder.bind_expression(expression, group_by_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
  }
  

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }
  if(select_sql.group_by.size()==0){
    for(unique_ptr<Expression> &expression :bound_expressions){
      if(expression->type()==ExprType::AGGREGATION){
        for(unique_ptr<Expression> &expression2 :bound_expressions){
          if(expression2->type()==ExprType::FIELD){
            return RC::INTERNAL;
          }
        }
       break;
      }
    }
  }
  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  RC          rc          = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.conditions.data(),
      static_cast<int>(select_sql.conditions.size()),
      filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }
  
  FilterStmt *having_filter_stmt = nullptr;
  // create filter statement in having clause
  if (select_sql.having_conditions.size() > 0) {
    rc = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.having_conditions.data(),
      static_cast<int>(select_sql.having_conditions.size()),
      having_filter_stmt);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot construct filter stmt");
      return rc;
    }
  }
  

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();

  select_stmt->tables_.swap(tables);
  select_stmt->query_expressions_.swap(bound_expressions);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->group_by_.swap(group_by_expressions);
  select_stmt->having_filter_stmt_ = having_filter_stmt;
  stmt                      = select_stmt;
  return RC::SUCCESS;
}
