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

#include "sql/stmt/filter_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "net/sql_task_handler.h"
#include "net/cli_communicator.h"
#include "net/plain_communicator.h"
FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt  = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;

    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }
  if(condition_num!=0){
    tmp_stmt->conjunction=conditions[0].conjunction;
  }
  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;
  if (condition.left_is_attr==1) {
    Table           *table = nullptr;
    const FieldMeta *field = nullptr;
    rc                     = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_attr(Field(table, field));
    filter_unit->set_left(filter_obj);
  } else if(condition.left_is_attr==0){
    FilterObj filter_obj;
    filter_obj.init_value(condition.left_value);
    filter_unit->set_left(filter_obj);
  } else if(condition.left_is_attr==2){
    FilterObj filter_obj;
    // vector<Value> tuple_list;
    // CliCommunicator communicator;
    // communicator.init(STDIN_FILENO, make_unique<Session>(Session::default_session()), "stdin");
    // SessionEvent *event = new SessionEvent(&communicator);
    // event->set_query(condition.left_subquery);
    // SQLStageEvent sql_event(event, event->query());
    // SqlTaskHandler temp;
    // rc = temp.handle_sql(&sql_event);
    // if (OB_FAIL(rc)) {
    //   LOG_TRACE("failed to handle sql. rc=%s", strrc(rc));
    //   event->sql_result()->set_return_code(rc);
    // }
    // SqlResult *sql_result=event->sql_result();
  
    // rc=sql_result->open();
    
    // Tuple* tuple=nullptr;
    
    // while(RC::SUCCESS==(rc=sql_result->next_tuple(tuple))){
    //   Value value;
    //   if(tuple->cell_num()!=1){
    //     return RC::INTERNAL;
    //   }
    //   tuple->cell_at(0,value);
    //   tuple_list.emplace_back(value);
    // }
    // sql_result->close();
    // if(!(comp==IN_LIST||comp==NOTIN_LIST||comp==EXIST_LIST||comp==NOTEXIST_LIST)&&tuple_list.size()>1)
    // {
    //   return RC::INTERNAL;
    // }
    filter_obj.init_sql_result(condition.left_subquery,*tables);
    filter_unit->set_left(filter_obj);
  }
  else if(condition.left_is_attr==4){
    FilterObj filter_obj;
    
    std::vector<std::unique_ptr<Expression>> bound_expressions;
    BinderContext binder_context;

    // 遍历传入的 tables，添加每个表到 binder_context
    if (tables != nullptr) {
        for (const auto &pair : *tables) {
            const std::string &table_name = pair.first;
            Table *table = pair.second;

            if (table != nullptr) {
                binder_context.add_table(table);
            } else {
                LOG_WARN("Table pointer is null for table name: %s", table_name.c_str());
                return RC::INVALID_ARGUMENT; // 或其他合适的错误码
            }
        }
    }
    ExpressionBinder expression_binder(binder_context);
    auto tmp_expr = std::unique_ptr<Expression>(condition.left_expr);
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
    
    if (!bound_expressions.empty()) {
      auto tmp_expr1 = std::move(bound_expressions[0]);
      filter_obj.init_aggr(tmp_expr1);
      filter_unit->set_left(filter_obj);
    } else {
      LOG_ERROR("Expected an AggregateExpr but got a different type");
      return RC::INTERNAL;
    }  
  }
  else if(condition.left_is_attr==5){
    FilterObj filter_obj;
    std::vector<std::unique_ptr<Expression>> bound_expressions;
    BinderContext binder_context;

    // 遍历传入的 tables，添加每个表到 binder_context
    if (tables != nullptr) {
        for (const auto &pair : *tables) {
            const std::string &table_name = pair.first;
            Table *table = pair.second;

            if (table != nullptr) {
                binder_context.add_table(table);
            } else {
                LOG_WARN("Table pointer is null for table name: %s", table_name.c_str());
                return RC::INVALID_ARGUMENT; // 或其他合适的错误码
            }
        }
    }
    ExpressionBinder expression_binder(binder_context);
    auto tmp_expr = std::unique_ptr<Expression>(condition.left_expr);
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
    if (!bound_expressions.empty()) {
      auto tmp_expr1 = std::move(bound_expressions[0]);
      filter_obj.init_arthi(tmp_expr1);
      filter_unit->set_left(filter_obj);
    } else {
      LOG_ERROR("Expected an AggregateExpr but got a different type");
      return RC::INTERNAL;
    }  
  }
  else{
    FilterObj filter_obj;
    if(!(comp==IN_LIST||comp==NOTIN_LIST||comp==EXIST_LIST||comp==NOTEXIST_LIST)&&condition.left_list.size()>1)
    {
      return RC::INTERNAL;
    }
    const std::vector<Value>& vector_ref=condition.left_list;
    filter_obj.init_tuple(const_cast<std::vector<Value>&>(vector_ref));
    filter_unit->set_left(filter_obj);
  }

  if (condition.right_is_attr==1) {
    Table           *table = nullptr;
    const FieldMeta *field = nullptr;
    rc                     = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_attr(Field(table, field));
    filter_unit->set_right(filter_obj);
  } else if(condition.right_is_attr==0){
    FilterObj filter_obj;
    filter_obj.init_value(condition.right_value);
    filter_unit->set_right(filter_obj);
  }
  else if(condition.right_is_attr==2){
    FilterObj filter_obj;
    // CliCommunicator communicator;
    // communicator.init(STDIN_FILENO, make_unique<Session>(Session::default_session()), "stdin");
    // SessionEvent *event = new SessionEvent(&communicator);
    // event->set_query(condition.right_subquery);
    // SQLStageEvent sql_event(event, event->query());
    // SqlTaskHandler temp;
    // sql_event.table_map=*tables;
    // rc = temp.handle_sql(&sql_event);
    // if (OB_FAIL(rc)) {
    //   LOG_TRACE("failed to handle sql. rc=%s", strrc(rc));
    //   event->sql_result()->set_return_code(rc);
    // }
    // SqlResult *sql_result=event->sql_result();
  
    // rc=sql_result->open();
    // Tuple* tuple=nullptr;
    // vector<Value> tuple_list;
    // while(RC::SUCCESS==(rc=sql_result->next_tuple(tuple))){
    //   Value value;
    //   if(tuple->cell_num()!=1){
    //     return RC::INTERNAL;
    //   }
    //   tuple->cell_at(0,value);
    //   tuple_list.emplace_back(value);
    // }
    // sql_result->close();
    // if(!(comp==IN_LIST||comp==NOTIN_LIST||comp==EXIST_LIST||comp==NOTEXIST_LIST)&&tuple_list.size()>1)
    // {
    //   return RC::INTERNAL;
    // }
    filter_obj.init_sql_result(condition.right_subquery,*tables);
    filter_unit->set_right(filter_obj);
  } 
  else if(condition.right_is_attr==4){
    FilterObj filter_obj;
    
    
    std::vector<std::unique_ptr<Expression>> bound_expressions;
    BinderContext binder_context;

    // 遍历传入的 tables，添加每个表到 binder_context
    if (tables != nullptr) {
        for (const auto &pair : *tables) {
            const std::string &table_name = pair.first;
            Table *table = pair.second;

            if (table != nullptr) {
                binder_context.add_table(table);
            } else {
                LOG_WARN("Table pointer is null for table name: %s", table_name.c_str());
                return RC::INVALID_ARGUMENT; // 或其他合适的错误码
            }
        }
    }
    ExpressionBinder expression_binder(binder_context);
    auto tmp_expr = unique_ptr<Expression>(condition.right_expr);
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
    
    if (!bound_expressions.empty()) {
      auto tmp_expr1 = std::move(bound_expressions[0]);
      filter_obj.init_aggr(tmp_expr1);
      filter_unit->set_right(filter_obj);
    } else {
      LOG_ERROR("Expected an AggregateExpr but got a different type");
      return RC::INTERNAL;
    }  
  }
  else if(condition.right_is_attr==5){
    FilterObj filter_obj;
    std::vector<std::unique_ptr<Expression>> bound_expressions;
    BinderContext binder_context;

    // 遍历传入的 tables，添加每个表到 binder_context
    if (tables != nullptr) {
        for (const auto &pair : *tables) {
            const std::string &table_name = pair.first;
            Table *table = pair.second;

            if (table != nullptr) {
                binder_context.add_table(table);
            } else {
                LOG_WARN("Table pointer is null for table name: %s", table_name.c_str());
                return RC::INVALID_ARGUMENT; // 或其他合适的错误码
            }
        }
    }
    ExpressionBinder expression_binder(binder_context);
    auto tmp_expr = std::unique_ptr<Expression>(condition.right_expr);
    RC rc = expression_binder.bind_expression(tmp_expr, bound_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
    if (!bound_expressions.empty()) {
      auto tmp_expr1 = std::move(bound_expressions[0]);
      filter_obj.init_arthi(tmp_expr1);
      filter_unit->set_right(filter_obj);
    } else {
      LOG_ERROR("Expected an AggregateExpr but got a different type");
      return RC::INTERNAL;
    }  
  }
  else{
    FilterObj filter_obj;
    if(!(comp==IN_LIST||comp==NOTIN_LIST||comp==EXIST_LIST||comp==NOTEXIST_LIST)&&condition.right_list.size()>1)
    {
      return RC::INTERNAL;
    }
    const std::vector<Value>& vector_ref=condition.right_list;
    filter_obj.init_tuple(const_cast<std::vector<Value>&>(vector_ref));
    filter_unit->set_right(filter_obj);
  }
  filter_unit->set_comp(comp);
  // 检查两个类型是否能够比较
  return rc;
}
