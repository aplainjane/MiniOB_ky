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
// Created by Wangyunlai on 2024/01/10.
//

#include "net/sql_task_handler.h"
#include "net/communicator.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"

RC SqlTaskHandler::handle_event(Communicator *communicator)
{
  LOG_INFO("handle request HERE TASK");
  SessionEvent *event = nullptr;
  RC rc = communicator->read_event(event);
  if (OB_FAIL(rc)) {
    return rc;
  }

  if (nullptr == event) {
    return RC::SUCCESS;
  }

  session_stage_.handle_request2(event);

  SQLStageEvent sql_event(event, event->query());

  rc = handle_sql(&sql_event);
  if (OB_FAIL(rc)) {
    LOG_TRACE("failed to handle sql. rc=%s", strrc(rc));
    event->sql_result()->set_return_code(rc);
  }

  bool need_disconnect = false;

  SessionEvent *session_event = sql_event.session_event();
  SqlResult* sql_result = session_event->sql_result();
  sql_result->get_order_rules() = (*(sql_event.sql_node())).selection.order_rules;
  sql_result->get_having_stmt() = (*(sql_event.sql_node())).selection.having_conditions;
  sql_result->get_vec_order_rules() = (*(sql_event.sql_node())).selection.vec_order_rules;
  rc = communicator->write_result(session_event, need_disconnect);
  LOG_INFO("write result return %s", strrc(rc));
  event->session()->set_current_request(nullptr);
  Session::set_current_session(nullptr);

    delete event;

  if (need_disconnect) {
    return RC::INTERNAL;
  }
  return RC::SUCCESS;
}

RC SqlTaskHandler::handle_sql(SQLStageEvent *sql_event)
{
  RC rc = query_cache_stage_.handle_request(sql_event);
  if (OB_FAIL(rc)) {
    LOG_TRACE("failed to do query cache. rc=%s", strrc(rc));
    return rc;
  }

  rc = parse_stage_.handle_request(sql_event);
  if (OB_FAIL(rc)) {
    LOG_TRACE("failed to do parse. rc=%s", strrc(rc));
    return rc;
  }

  SessionEvent *session_event = sql_event->session_event();
  SqlResult* sql_result = session_event->sql_result();
  sql_result->get_order_rules() = (*(sql_event->sql_node())).selection.order_rules;
  sql_result->get_having_stmt() = (*(sql_event->sql_node())).selection.having_conditions;

  rc = resolve_stage_.handle_request(sql_event);
  if (OB_FAIL(rc)) {
    LOG_TRACE("failed to do resolve. rc=%s", strrc(rc));
    return rc;
  }

  sql_result->get_vec_order_rules() = (*(sql_event->sql_node())).selection.vec_order_rules;

  sql_result->get_vec_explain_rules() = (*(sql_event->sql_node())).vec_explain;
  if(sql_result->get_vec_explain_rules().inited == 1)
  {
    return RC::SUCCESS;
  }

  rc = optimize_stage_.handle_request(sql_event);
  if (rc != RC::UNIMPLEMENTED && rc != RC::SUCCESS) {
    LOG_TRACE("failed to do optimize. rc=%s", strrc(rc));
    return rc;
  }

  rc = execute_stage_.handle_request(sql_event);
  if (OB_FAIL(rc)) {
    LOG_TRACE("failed to do execute. rc=%s", strrc(rc));
    return rc;
  }

  return rc;
}