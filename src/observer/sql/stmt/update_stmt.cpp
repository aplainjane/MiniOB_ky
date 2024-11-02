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

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/parser/parse_defs.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "net/sql_task_handler.h"
#include "net/cli_communicator.h"
#include "net/plain_communicator.h"

UpdateStmt::UpdateStmt(Table *table, std::vector<Field> field, std::vector<Value> value, FilterStmt *filter_stmt)
    : table_(table), fields_(field), values_(value), filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update_sql, Stmt *&stmt)
{
  // check dbb
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  const char *table_name = update_sql.relation_name.c_str();
  // check whether the table exists
  if (nullptr == table_name) {
    LOG_WARN("invalid argument. relation name is null.");
    return RC::INVALID_ARGUMENT;
  }
  
  Table *table = db->find_table(table_name);

 /*
  struct RelAttrSqlNode *relation_attr;
  relation_attr->attribute_name = update_sql.attribute_name;
  relation_attr->relation_name = update_sql.relation_name;
 */

  if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
  std::vector<Value> new_values = update_sql.values;
  for(int i = 0;i<(int)update_sql.subquery_values.size();i++)
  {
    vector<Value> tuple_list;
    CliCommunicator communicator;
    RC rc = communicator.init(STDIN_FILENO, make_unique<Session>(Session::default_session()), "stdin");
    SessionEvent *event = new SessionEvent(&communicator);
    event->set_query(update_sql.subquery_values[i]);
    SQLStageEvent sql_event(event, event->query());
    SqlTaskHandler temp;
    rc = temp.handle_sql(&sql_event);
    if (OB_FAIL(rc)) {
      LOG_TRACE("failed to handle sql. rc=%s", strrc(rc));
      event->sql_result()->set_return_code(rc);
      return RC::INVALID_ARGUMENT;
    }
    SqlResult *sql_result=event->sql_result();
  
    rc=sql_result->open();
    
    Tuple* tuple=nullptr;
    
    while(RC::SUCCESS==(rc=sql_result->next_tuple(tuple))){
      Value value;
      if(tuple->cell_num()!=1){
        return RC::INTERNAL;
      }
      tuple->cell_at(0,value);
      tuple_list.emplace_back(value);
    }
    sql_result->close();
    if(tuple_list.size()==0)
    {
      //等待null
      Value *tempvalue=new Value();
      tempvalue->set_null(0);
      new_values.insert(new_values.begin()+update_sql.record[i],*tempvalue);
    }
    else{
      bool flag=true;
      if(tuple_list.size()>1)
      {
        string temp=tuple_list[0].to_string();
        for(long unsigned int i = 1;i<tuple_list.size();i++)
        {
          if(tuple_list[i].to_string()!=temp){
            flag=false;
          }
        }
      }
      if(flag){
        new_values.insert(new_values.begin()+update_sql.record[i],tuple_list[0]);
      }
      else{
        return RC::INTERNAL;
      }
      }
    }
  std::vector<const FieldMeta *> fields;
   // check whether the field exists
  if (update_sql.attribute_names.size() != new_values.size()) {
    LOG_WARN("invalid argument. fields and values are not matched.");
    return RC::INVALID_ARGUMENT;
  }

  for( auto &attribute_name : update_sql.attribute_names){
    const FieldMeta *field_meta = table->table_meta().field(attribute_name.c_str());
    
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), attribute_name.c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }
    fields.emplace_back(field_meta);   
  }
  

  // 过滤算子
  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(table_name, table));
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(
      db, 
      table,
      &table_map,
      update_sql.conditions.data(),
      static_cast<int>(update_sql.conditions.size()),
      filter_stmt
    );

  if (rc != RC::SUCCESS){
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  std::vector<Field> cons_fields;

  for (int i=0;i<(int)fields.size();++i){
    cons_fields.emplace_back(Field(table,fields[i]));
  }
  UpdateStmt *update_stmt = new UpdateStmt(table,
      cons_fields, 
      new_values, 
      filter_stmt
    );
  // std::cout<<"update!"<<std::endl;
  stmt = update_stmt;
  return RC::SUCCESS;
  
}