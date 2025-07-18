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
// Created by WangYunlai on 2022/11/17.
//

#pragma once

#include <memory>
#include <string>

#include "sql/expr/tuple.h"
#include "sql/operator/physical_operator.h"

class Session;

/**
 * @brief SQL执行结果
 * @details
 * 如果当前SQL生成了执行计划，那么在返回客户端时，调用执行计划返回结果。
 * 否则返回的结果就是当前SQL的执行结果，比如DDL语句，通过return_code和state_string来描述。
 * 如果出现了一些错误，也可以通过return_code和state_string来获取信息。
 */
class SqlResult
{
public:
  SqlResult(Session *session);
  ~SqlResult() {}

  void set_tuple_schema(const TupleSchema &schema);
  void set_return_code(RC rc) { return_code_ = rc; }
  void set_state_string(const std::string &state_string) { state_string_ = state_string; }

  void set_operator(std::unique_ptr<PhysicalOperator> oper);

  bool               has_operator() const { return operator_ != nullptr; }
  const TupleSchema &tuple_schema() const { return tuple_schema_; }
  RC                 return_code() const { return return_code_; }
  const std::string &state_string() const { return state_string_; }
  const PhysicalOperatorType get_physicalOperator_type() const 
  {
    return operator_->type();
  }
  std::vector<std::pair<RelAttrSqlNode, OrderOp>> &get_order_rules() { 
    return order_rules_; 
  }
  std::vector<ConditionSqlNode> &get_having_stmt() { 
    return having_stmts; 
  }

  VecOrderByNode &get_vec_order_rules() { 
    return vec_order_rules_; 
  }

  VecExplainNode &get_vec_explain_rules() { 
    return vec_explain_rules; 
  }



  RC open();
  RC close();
  RC next_tuple(Tuple *&tuple);
  RC next_chunk(Chunk &chunk);

  std::unique_ptr<PhysicalOperator> operator_=nullptr;           ///< 执行计划
private:
  Session                          *session_ = nullptr;  ///< 当前所属会话

  TupleSchema                       tuple_schema_;       ///< 返回的表头信息。可能有也可能没有
  RC                                return_code_ = RC::SUCCESS;
  std::string                       state_string_;
  std::vector<std::pair<RelAttrSqlNode, OrderOp>> order_rules_;
  std::vector<ConditionSqlNode>     having_stmts;
  VecOrderByNode                    vec_order_rules_;
  VecExplainNode                    vec_explain_rules;
};
