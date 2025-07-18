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
// Created by Wangyunlai on 2022/07/05.
//
#include <cmath>

#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/expr/arithmetic_operator.hpp"
#include "sql/executor/sql_result.h"
#include "event/sql_event.h"
#include "net/sql_task_handler.h"
#include "event/session_event.h"
#include "net/cli_communicator.h"
using namespace std;
class SqlResult;
class SQLStageEvent;
class SessionEvent;
RC FieldExpr::get_value(const Tuple &tuple, Value &value) const
{
  return tuple.find_cell(TupleCellSpec(table_name(), field_name()), value);
}

bool FieldExpr::equal(const Expression &other) const
{
  if (this == &other) {
    return true;
  }
  if (other.type() != ExprType::FIELD) {
    return false;
  }
  const auto &other_field_expr = static_cast<const FieldExpr &>(other);
  return table_name() == other_field_expr.table_name() && field_name() == other_field_expr.field_name();
}

// TODO: 在进行表达式计算时，`chunk` 包含了所有列，因此可以通过 `field_id` 获取到对应列。
// 后续可以优化成在 `FieldExpr` 中存储 `chunk` 中某列的位置信息。
RC FieldExpr::get_column(Chunk &chunk, Column &column)
{
  if (pos_ != -1) {
    column.reference(chunk.column(pos_));
  } else {
    column.reference(chunk.column(field().meta()->field_id()));
  }
  return RC::SUCCESS;
}

bool SubqueryExpr::equal(const Expression &other) const
{
  if (this == &other) {
    return true;
  }
  if (other.type() != ExprType::SUBQUERY) {
    return false;
  }
  return false;
}

bool ValueExpr::equal(const Expression &other) const
{
  if (this == &other) {
    return true;
  }
  if (other.type() != ExprType::VALUE) {
    return false;
  }
  const auto &other_value_expr = static_cast<const ValueExpr &>(other);
  return value_.compare(other_value_expr.get_value()) == 0;
}

RC ValueExpr::get_value(const Tuple &tuple, Value &value) const
{
  value = value_;
  return RC::SUCCESS;
}

RC ValueExpr::get_column(Chunk &chunk, Column &column)
{
  column.init(value_);
  return RC::SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
CastExpr::CastExpr(unique_ptr<Expression> child, AttrType cast_type) : child_(std::move(child)), cast_type_(cast_type)
{}

CastExpr::~CastExpr() {}

RC CastExpr::cast(const Value &value, Value &cast_value) const
{
  RC rc = RC::SUCCESS;
  if (this->value_type() == value.attr_type()) {
    cast_value = value;
    return rc;
  }
  rc = Value::cast_to(value, cast_type_, cast_value);
  return rc;
}

RC CastExpr::get_value(const Tuple &tuple, Value &result) const
{
  Value value;
  RC rc = child_->get_value(tuple, value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, result);
}

RC CastExpr::try_get_value(Value &result) const
{
  Value value;
  RC rc = child_->try_get_value(value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, result);
}

////////////////////////////////////////////////////////////////////////////////

ComparisonExpr::ComparisonExpr(CompOp comp, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : comp_(comp), left_(std::move(left)), right_(std::move(right))
{}

ComparisonExpr::~ComparisonExpr() {}

RC ComparisonExpr::compare_value(const Value &left, const Value &right, bool &result) const
{
  RC  rc         = RC::SUCCESS;
  result = false;
  // NULL和数值的运算符，结果永远false
  if(
    (left.attr_type() == AttrType::NULLS || right.attr_type() == AttrType::NULLS) &&
    (comp_ == EQUAL_TO || comp_ == LESS_EQUAL || comp_ == NOT_EQUAL || comp_ == LESS_THAN || comp_ == GREAT_EQUAL || comp_ == GREAT_THAN)
  ) {
    result = false;
    return rc;
  }
  int cmp_result = 0;
  if(left.attr_type() != AttrType::NULLS && right.attr_type() != AttrType::NULLS){
    cmp_result = left.compare(right);
  } 
  switch (comp_) {
    case EQUAL_TO: {
      result = (0 == cmp_result);
    } break;
    case LESS_EQUAL: {
      result = (cmp_result <= 0);
    } break;
    case NOT_EQUAL: {
      result = (cmp_result != 0);
    } break;
    case LESS_THAN: {
      result = (cmp_result < 0);
    } break;
    case GREAT_EQUAL: {
      result = (cmp_result >= 0);
    } break;
    case GREAT_THAN: {
      result = (cmp_result > 0);
    } break;
    case CLIKE:{
      result = left.like(right);
    } break;
    case OP_ISNULL: {
      result = left.attr_type() == AttrType::NULLS;
    }break;
    case OP_ISNOTNULL: {
      result = !(left.attr_type() == AttrType::NULLS);
    }break;
    case CNLIKE:{
      result = !left.like(right);
    } break;
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }

  return rc;
}

RC ComparisonExpr::try_get_value(Value &cell) const
{
  if (left_->type() == ExprType::VALUE && right_->type() == ExprType::VALUE) {
    ValueExpr *  left_value_expr  = static_cast<ValueExpr *>(left_.get());
    ValueExpr *  right_value_expr = static_cast<ValueExpr *>(right_.get());
    const Value &left_cell        = left_value_expr->get_value();
    const Value &right_cell       = right_value_expr->get_value();

    bool value = false;
    RC   rc    = compare_value(left_cell, right_cell, value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to compare tuple cells. rc=%s", strrc(rc));
    } else {
      cell.set_boolean(value);
    }
    return rc;
  }

  return RC::INVALID_ARGUMENT;
}

RC ComparisonExpr::get_value(const Tuple &tuple, Value &value) const
{
  Value left_value;
  Value right_value;
  bool bool_value = false;
  vector<Value> left_tuple;
  RC rc=RC::SUCCESS;
  if(left_->type()==ExprType::SUBQUERY&&left_->is_tuple_list()){
    rc = left_->get(left_tuple);
  }
  else if(left_->type()==ExprType::SUBQUERY&&left_->is_tuple_list()==false)
  {
    string sql = left_->getsqlresult();
    //std::cout<<sql<<std::endl;
    CliCommunicator communicator;
    communicator.init(STDIN_FILENO, make_unique<Session>(Session::default_session()), "stdin");
    SessionEvent *event = new SessionEvent(&communicator);
    event->set_query(sql);
    SQLStageEvent sql_event(event, event->query());
    // sql_event.table_map=*left_->gettable();
    SqlTaskHandler temp;
    rc = temp.handle_sql(&sql_event);
    SqlResult *sql_result=sql_event.session_event()->sql_result();
    // sql_result->operator_->set_parent_tuple(&tuple);
    rc=sql_result->open();
    
    Tuple* temptuple=nullptr;
    
    while(RC::SUCCESS==(rc=sql_result->next_tuple(temptuple))){
      Value value;
      if(temptuple->cell_num()!=1){
        return RC::INTERNAL;
      }
      temptuple->cell_at(0,value);
      left_tuple.emplace_back(value);
    }
      sql_result->close();
    if(!(comp_==IN_LIST||comp_==NOTIN_LIST||comp_==EXIST_LIST||comp_==NOTEXIST_LIST)&&left_tuple.size()>1)
    {
      return RC::INTERNAL;
    }
    rc=RC::SUCCESS;
  }
  vector<Value> right_tuple;
  if(right_->type()==ExprType::SUBQUERY&&right_->is_tuple_list()){
    rc = right_->get(right_tuple);
  }
  else if(right_->type()==ExprType::SUBQUERY&&right_->is_tuple_list()==false)
  {
    string sql = right_->getsqlresult();
    CliCommunicator communicator;
    communicator.init(STDIN_FILENO, make_unique<Session>(Session::default_session()), "stdin");
    SessionEvent *event = new SessionEvent(&communicator);
    event->set_query(sql);
    SQLStageEvent sql_event(event, event->query());
    sql_event.table_map=right_->gettable();
    SqlTaskHandler temp;
    rc = temp.handle_sql(&sql_event);
    if(rc!=RC::SUCCESS){
      return RC::INTERNAL;
    }
    SqlResult *sql_result=event->sql_result();
    if(sql_result->operator_.get()!=nullptr){
      sql_result->operator_->set_parent_tuple(&tuple);
    }
    rc=sql_result->open();
    if(rc==RC::INTERNAL){
      return rc;
    }
    Tuple* temptuple=nullptr;
    
    while(RC::SUCCESS==(rc=sql_result->next_tuple(temptuple))){
      Value value;
      if(temptuple->cell_num()!=1){
        return RC::INTERNAL;
      }
      temptuple->cell_at(0,value);
      right_tuple.emplace_back(value);
    }
      sql_result->close();
    if(rc==RC::INTERNAL){
      return rc;
    }
    if(!(comp_==IN_LIST||comp_==NOTIN_LIST||comp_==EXIST_LIST||comp_==NOTEXIST_LIST)&&right_tuple.size()>1)
    {
      return RC::INTERNAL;
    }
    rc=RC::SUCCESS;
  }
  if(comp_==IN_LIST||comp_==NOTIN_LIST||comp_==EXIST_LIST||comp_==NOTEXIST_LIST){
    if(right_tuple.size()==0){
      if(comp_==IN_LIST||comp_==EXIST_LIST){
        value.set_boolean(false);
      }
      else{
        value.set_boolean(true);
      }
      return RC::SUCCESS;
    }
    else{
      if(left_->type()==ExprType::SUBQUERY){
        left_value=left_tuple[0];
      }
      else{
      rc=left_->get_value(tuple,left_value);
      }
      for(int i = 0;i<(int)right_tuple.size();i++){
        int cmp_result = left_value.compare(right_tuple[i]);
        bool_value = (0 == cmp_result);
        if(bool_value==true){
          if(comp_==IN_LIST||comp_==EXIST_LIST){
            value.set_boolean(true);
          }
          else{
            value.set_boolean(false);
          }
          return rc;
        }
      }
      if(comp_==IN_LIST||comp_==EXIST_LIST){
        value.set_boolean(false);
      }
      else{
        value.set_boolean(true);
      }
      return rc;
    }
  }
  if(left_->type() == ExprType::SUBQUERY&&right_->type() == ExprType::SUBQUERY)
  {
    if(left_tuple.size()==0)
    {
      value.set_boolean(bool_value);
      return RC::SUCCESS;
    }
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
    if(right_tuple.size()==0)
    {
      value.set_boolean(bool_value);
      return RC::SUCCESS;
    }
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
    rc = compare_value(left_tuple[0],right_tuple[0], bool_value);
    value.set_boolean(bool_value);
    return rc;
  }
  if(left_->type() == ExprType::SUBQUERY){
    RC rc = right_->get_value(tuple, right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
    if(left_tuple.size()==0)
    {
      value.set_boolean(bool_value);
      return RC::SUCCESS;
    }
    else{
      rc = compare_value(left_tuple[0],right_value, bool_value);
      value.set_boolean(bool_value);
      return rc;
    }
  }
  else if(right_->type() == ExprType::SUBQUERY){
    RC rc = left_->get_value(tuple, left_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
    if(right_tuple.size()==0)
    {
      value.set_boolean(bool_value);
      return RC::SUCCESS;
    }
    else{
      rc = compare_value(left_value,right_tuple[0], bool_value);
      value.set_boolean(bool_value);
      return rc;
    }
  }
  else{
  RC rc = left_->get_value(tuple, left_value);
  if(rc == RC::SQL_SYNTAX){
    value.set_boolean(false);
    return RC::SUCCESS;
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  
  rc = right_->get_value(tuple, right_value);
  if(rc == RC::SQL_SYNTAX){
    value.set_boolean(false);
    return RC::SUCCESS;
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }

  

  rc = compare_value(left_value, right_value, bool_value);
  if (rc == RC::SUCCESS) {
    value.set_boolean(bool_value);
  }
  return rc;
  }
}

RC ComparisonExpr::eval(Chunk &chunk, std::vector<uint8_t> &select)
{
  RC     rc = RC::SUCCESS;
  Column left_column;
  Column right_column;

  rc = left_->get_column(chunk, left_column);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_column(chunk, right_column);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  if (left_column.attr_type() != right_column.attr_type()) {
    LOG_WARN("cannot compare columns with different types");
    return RC::INTERNAL;
  }
  if (left_column.attr_type() == AttrType::INTS) {
    rc = compare_column<int>(left_column, right_column, select);
  } else if (left_column.attr_type() == AttrType::FLOATS) {
    rc = compare_column<float>(left_column, right_column, select);
  } else {
    // TODO: support string compare
    LOG_WARN("unsupported data type %d", left_column.attr_type());
    return RC::INTERNAL;
  }
  return rc;
}

template <typename T>
RC ComparisonExpr::compare_column(const Column &left, const Column &right, std::vector<uint8_t> &result) const
{
  RC rc = RC::SUCCESS;

  bool left_const  = left.column_type() == Column::Type::CONSTANT_COLUMN;
  bool right_const = right.column_type() == Column::Type::CONSTANT_COLUMN;
  if (left_const && right_const) {
    compare_result<T, true, true>((T *)left.data(), (T *)right.data(), left.count(), result, comp_);
  } else if (left_const && !right_const) {
    compare_result<T, true, false>((T *)left.data(), (T *)right.data(), right.count(), result, comp_);
  } else if (!left_const && right_const) {
    compare_result<T, false, true>((T *)left.data(), (T *)right.data(), left.count(), result, comp_);
  } else {
    compare_result<T, false, false>((T *)left.data(), (T *)right.data(), left.count(), result, comp_);
  }
  return rc;
}

////////////////////////////////////////////////////////////////////////////////
ConjunctionExpr::ConjunctionExpr(Type type, vector<unique_ptr<Expression>> &children)
    : conjunction_type_(type), children_(std::move(children))
{}

RC ConjunctionExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    value.set_boolean(true);
    return rc;
  }

  Value tmp_value;
  for (const unique_ptr<Expression> &expr : children_) {
    rc = expr->get_value(tuple, tmp_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value by child expression. rc=%s", strrc(rc));
      return rc;
    }
    bool bool_value = tmp_value.get_boolean();
    if ((conjunction_type_ == Type::AND && !bool_value) || (conjunction_type_ == Type::OR && bool_value)) {
      value.set_boolean(bool_value);
      return rc;
    }
  }

  bool default_value = (conjunction_type_ == Type::AND);
  value.set_boolean(default_value);
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, Expression *left, Expression *right)
    : arithmetic_type_(type), left_(left), right_(right)
{}
ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : arithmetic_type_(type), left_(std::move(left)), right_(std::move(right))
{}

bool ArithmeticExpr::equal(const Expression &other) const
{
  if (this == &other) {
    return true;
  }
  if (type() != other.type()) {
    return false;
  }
  auto &other_arith_expr = static_cast<const ArithmeticExpr &>(other);
  return arithmetic_type_ == other_arith_expr.arithmetic_type() && left_->equal(*other_arith_expr.left_) &&
         right_->equal(*other_arith_expr.right_);
}
AttrType ArithmeticExpr::value_type() const
{
  if (!right_) {
    return left_->value_type();
  }

  if(left_->value_type() == AttrType::NULLS || right_->value_type() == AttrType::NULLS){
    return AttrType::NULLS;
  }

  if (left_->value_type() == AttrType::INTS && right_->value_type() == AttrType::INTS &&
      arithmetic_type_ != Type::DIV) {
    return AttrType::INTS;
  }

  if (left_->value_type() ==AttrType::VECTORS || right_->value_type() == AttrType::VECTORS){
    return AttrType::VECTORS;
  }

  return AttrType::FLOATS;
}

RC ArithmeticExpr::calc_value(const Value &left_value, const Value &right_value, Value &value) const
{
  RC rc = RC::SUCCESS;

  const AttrType target_type = value_type();
  value.set_type(target_type);
  if(target_type == AttrType::NULLS || left_value.attr_type() == AttrType::NULLS || right_value.attr_type() == AttrType::NULLS)
  {
    value.set_null(0);
    return rc;
  }

  switch (arithmetic_type_) {
    case Type::ADD: {
      Value::add(left_value, right_value, value);
    } break;

    case Type::SUB: {
      Value::subtract(left_value, right_value, value);
    } break;

    case Type::MUL: {
      Value::multiply(left_value, right_value, value);
    } break;

    case Type::DIV: {
      if(right_value.get_int() == 0){
        return RC::SQL_SYNTAX;
      }
      Value::divide(left_value, right_value, value);
    } break;

    case Type::NEGATIVE: {
      Value::negative(left_value, value);
    } break;

    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported arithmetic type. %d", arithmetic_type_);
    } break;
  }
  return rc;
}

template <bool LEFT_CONSTANT, bool RIGHT_CONSTANT>
RC ArithmeticExpr::execute_calc(
    const Column &left, const Column &right, Column &result, Type type, AttrType attr_type) const
{
  RC rc = RC::SUCCESS;
  switch (type) {
    case Type::ADD: {
      if (attr_type == AttrType::INTS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, int, AddOperator>(
            (int *)left.data(), (int *)right.data(), (int *)result.data(), result.capacity());
      } else if (attr_type == AttrType::FLOATS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, float, AddOperator>(
            (float *)left.data(), (float *)right.data(), (float *)result.data(), result.capacity());
      } else {
        rc = RC::UNIMPLEMENTED;
      }
    } break;
    case Type::SUB:
      if (attr_type == AttrType::INTS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, int, SubtractOperator>(
            (int *)left.data(), (int *)right.data(), (int *)result.data(), result.capacity());
      } else if (attr_type == AttrType::FLOATS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, float, SubtractOperator>(
            (float *)left.data(), (float *)right.data(), (float *)result.data(), result.capacity());
      } else {
        rc = RC::UNIMPLEMENTED;
      }
      break;
    case Type::MUL:
      if (attr_type == AttrType::INTS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, int, MultiplyOperator>(
            (int *)left.data(), (int *)right.data(), (int *)result.data(), result.capacity());
      } else if (attr_type == AttrType::FLOATS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, float, MultiplyOperator>(
            (float *)left.data(), (float *)right.data(), (float *)result.data(), result.capacity());
      } else {
        rc = RC::UNIMPLEMENTED;
      }
      break;
    case Type::DIV:
      if (attr_type == AttrType::INTS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, int, DivideOperator>(
            (int *)left.data(), (int *)right.data(), (int *)result.data(), result.capacity());
      } else if (attr_type == AttrType::FLOATS) {
        binary_operator<LEFT_CONSTANT, RIGHT_CONSTANT, float, DivideOperator>(
            (float *)left.data(), (float *)right.data(), (float *)result.data(), result.capacity());
      } else {
        rc = RC::UNIMPLEMENTED;
      }
      break;
    case Type::NEGATIVE:
      if (attr_type == AttrType::INTS) {
        unary_operator<LEFT_CONSTANT, int, NegateOperator>((int *)left.data(), (int *)result.data(), result.capacity());
      } else if (attr_type == AttrType::FLOATS) {
        unary_operator<LEFT_CONSTANT, float, NegateOperator>(
            (float *)left.data(), (float *)result.data(), result.capacity());
      } else {
        rc = RC::UNIMPLEMENTED;
      }
      break;
    default: rc = RC::UNIMPLEMENTED; break;
  }
  if (rc == RC::SUCCESS) {
    result.set_count(result.capacity());
  }
  return rc;
}

RC ArithmeticExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;
  rc = left_->get_value(tuple, left_value);
  
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_value(tuple, right_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_value(left_value, right_value, value);
}

RC ArithmeticExpr::get_column(Chunk &chunk, Column &column)
{
  RC rc = RC::SUCCESS;
  if (pos_ != -1) {
    column.reference(chunk.column(pos_));
    return rc;
  }
  Column left_column;
  Column right_column;

  rc = left_->get_column(chunk, left_column);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get column of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_column(chunk, right_column);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get column of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_column(left_column, right_column, column);
}

RC ArithmeticExpr::calc_column(const Column &left_column, const Column &right_column, Column &column) const
{
  RC rc = RC::SUCCESS;

  const AttrType target_type = value_type();
  column.init(target_type, left_column.attr_len(), std::max(left_column.count(), right_column.count()));
  bool left_const  = left_column.column_type() == Column::Type::CONSTANT_COLUMN;
  bool right_const = right_column.column_type() == Column::Type::CONSTANT_COLUMN;
  if (left_const && right_const) {
    column.set_column_type(Column::Type::CONSTANT_COLUMN);
    rc = execute_calc<true, true>(left_column, right_column, column, arithmetic_type_, target_type);
  } else if (left_const && !right_const) {
    column.set_column_type(Column::Type::NORMAL_COLUMN);
    rc = execute_calc<true, false>(left_column, right_column, column, arithmetic_type_, target_type);
  } else if (!left_const && right_const) {
    column.set_column_type(Column::Type::NORMAL_COLUMN);
    rc = execute_calc<false, true>(left_column, right_column, column, arithmetic_type_, target_type);
  } else {
    column.set_column_type(Column::Type::NORMAL_COLUMN);
    rc = execute_calc<false, false>(left_column, right_column, column, arithmetic_type_, target_type);
  }
  return rc;
}

RC ArithmeticExpr::try_get_value(Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->try_get_value(left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  if (right_) {
    rc = right_->try_get_value(right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
  }

  return calc_value(left_value, right_value, value);
}

////////////////////////////////////////////////////////////////////////////////

UnboundAggregateExpr::UnboundAggregateExpr(const char *aggregate_name, std::vector<std::unique_ptr<Expression> >*child)
    : aggregate_name_(aggregate_name), childs_(child)
{
  if (childs_ && !childs_->empty()) {
    child_ = std::move((*childs_)[0]);
  }

  if(child->size()!=1)
    this->error_ = true;
}

////////////////////////////////////////////////////////////////////////////////
AggregateExpr::AggregateExpr(Type type, Expression *child) : aggregate_type_(type), child_(child) {}

AggregateExpr::AggregateExpr(Type type, unique_ptr<Expression> child) : aggregate_type_(type), child_(std::move(child))
{}

RC AggregateExpr::get_column(Chunk &chunk, Column &column)
{
  RC rc = RC::SUCCESS;
  if (pos_ != -1) {
    column.reference(chunk.column(pos_));
  } else {
    rc = RC::INTERNAL;
  }
  return rc;
}

bool AggregateExpr::equal(const Expression &other) const
{
  if (this == &other) {
    return true;
  }
  if (other.type() != type()) {
    return false;
  }
  const AggregateExpr &other_aggr_expr = static_cast<const AggregateExpr &>(other);
  return aggregate_type_ == other_aggr_expr.aggregate_type() && child_->equal(*other_aggr_expr.child());
}

unique_ptr<Aggregator> AggregateExpr::create_aggregator() const
{
  unique_ptr<Aggregator> aggregator;
  switch (aggregate_type_) {
    case Type::SUM: {
      aggregator = make_unique<SumAggregator>();
      break;
    }
    case Type::AVG: {
      aggregator = make_unique<AvgAggregator>();
      break;
    }
    case Type::MAX:{
      aggregator = make_unique<MaxAggregator>();
      break;
    }
    case Type::MIN:{
      aggregator = make_unique<MinAggregator>();
      break;
    }
    case Type::COUNT: {
      aggregator = make_unique<CountAggregator>();
      break;
    }
    default: {
      ASSERT(false, "unsupported aggregate type");
      break;
    }
  }
  return aggregator;
}

RC AggregateExpr::get_value(const Tuple &tuple, Value &value) const
{
  return tuple.find_cell(TupleCellSpec(name()), value);
}

RC AggregateExpr::type_from_string(const char *type_str, AggregateExpr::Type &type)
{
  RC rc = RC::SUCCESS;
  if (0 == strcasecmp(type_str, "count")) {
    type = Type::COUNT;
  } else if (0 == strcasecmp(type_str, "sum")) {
    type = Type::SUM;
  } else if (0 == strcasecmp(type_str, "avg")) {
    type = Type::AVG;
  } else if (0 == strcasecmp(type_str, "max")) {
    type = Type::MAX;
  } else if (0 == strcasecmp(type_str, "min")) {
    type = Type::MIN;
  } else {
    rc = RC::INVALID_ARGUMENT;
  }
  return rc;
}

/////////////////////////////////////////////////////////////////////////////////

AttrType FunctionExpr::value_type() const
{
  switch (func_type_) {
    case I2_DISTANCE:
      return AttrType::FLOATS;
      break;
    case COSINE_DISTANCE:
      return AttrType::FLOATS;
      break;
    case INNER_PRODUCT:
      return AttrType::FLOATS;
      break;
    default:
      break;
  }
  return AttrType::UNDEFINED;
}

RC FunctionExpr::get_I2_value(const Tuple &tuple, Value &value) const
{
  auto & param_left = params_[0];
  auto & param_right = params_[1];

  Value param_left_cell;
  Value param_right_cell;
  param_left->get_value(tuple, param_left_cell);
  param_right->get_value(tuple, param_right_cell);

  if (param_left_cell.attr_type() != AttrType::VECTORS || param_right_cell.attr_type() != AttrType::VECTORS) {
    return RC::INTERNAL;
  }

  vector<std::variant<int, float>> left_vec = param_left_cell.get_vector();
  vector<std::variant<int, float>> right_vec = param_right_cell.get_vector();

  if (left_vec.size() != right_vec.size()) {
    LOG_WARN("left_vec.size() != right_vec.size()");
    return RC::INTERNAL;
  }

  float result = 0.0f;
  for (int i = 0; i < left_vec.size(); i++) {
    std::visit([&result, &right_vec, i](auto&& left_val) {
      float left_float = static_cast<float>(left_val);
      float right_float = static_cast<float>(std::visit([](auto&& right_val) {
        return static_cast<float>(right_val);
      }, right_vec[i]));
    
      result += pow(left_float - right_float, 2);
    }, left_vec[i]);
  }
  result = sqrt(result);

  // 处理结果，判断是否为整数
  if (std::floor(result) == result) {
    value.set_type(AttrType::INTS); 
    value.set_int(static_cast<int>(result));
  } else {
    value.set_type(AttrType::FLOATS);
    // 保留两位小数，去除不必要的0
    float rounded_result = std::round(result * 100) / 100;
    value.set_float(rounded_result);
  }

  return RC::SUCCESS;
}

RC FunctionExpr::get_COSINE_value(const Tuple &tuple, Value &value) const
{
  auto & param_left = params_[0];
  auto & param_right = params_[1];

  Value param_left_cell;
  Value param_right_cell;
  param_left->get_value(tuple, param_left_cell);
  param_right->get_value(tuple, param_right_cell);

  if (param_left_cell.attr_type() != AttrType::VECTORS || param_right_cell.attr_type() != AttrType::VECTORS) {
    return RC::INTERNAL;
  }

  vector<std::variant<int, float>> left_vec = param_left_cell.get_vector();
  vector<std::variant<int, float>> right_vec = param_right_cell.get_vector();

  if (left_vec.size() != right_vec.size()) {
    LOG_WARN("left_vec.size() != right_vec.size()");
    return RC::INTERNAL;
  }

  float sumA2 = 0.0f;
  float sumB2 = 0.0f;
  float sumAB = 0.0f;
  float result = 0.0f;

  for (size_t i = 0; i < left_vec.size(); i++) {
    std::visit([&sumA2, &sumB2, &sumAB, &right_vec, i](auto&& left_val) {
      float left_float = static_cast<float>(left_val);
      float right_float = static_cast<float>(std::visit([](auto&& right_val) {
        return static_cast<float>(right_val);
      }, right_vec[i]));
    
      sumA2 += left_float * left_float;
      sumB2 += right_float * right_float;
      sumAB += left_float * right_float;
    }, left_vec[i]);
  }

  result = 1 - sumAB / (sqrt(sumA2) * sqrt(sumB2));

  // 处理结果，判断是否为整数
  if (std::floor(result) == result) {
    value.set_type(AttrType::INTS);
    value.set_int(static_cast<int>(result));
  } else {
    value.set_type(AttrType::FLOATS);
    // 保留两位小数，去除不必要的0
    float rounded_result = std::round(result * 100) / 100;
    value.set_float(rounded_result);
  }

  return RC::SUCCESS;
}

RC FunctionExpr::get_INNER_value(const Tuple &tuple, Value &value) const
{
  auto & param_left = params_[0];
  auto & param_right = params_[1];

  Value param_left_cell;
  Value param_right_cell;
  param_left->get_value(tuple, param_left_cell);
  param_right->get_value(tuple, param_right_cell);

  if (param_left_cell.attr_type() != AttrType::VECTORS || param_right_cell.attr_type() != AttrType::VECTORS) {
    return RC::INTERNAL;
  }

  vector<std::variant<int, float>> left_vec = param_left_cell.get_vector();
  vector<std::variant<int, float>> right_vec = param_right_cell.get_vector();

  if (left_vec.size() != right_vec.size()) {
    LOG_WARN("left_vec.size() != right_vec.size()");
    return RC::INTERNAL;
  }

  float result = 0.0f;
  for (int i = 0; i < left_vec.size(); i++) {
    std::visit([&result, &right_vec, i](auto&& left_val) {
      float left_float = static_cast<float>(left_val);
      std::visit([&result, left_float](auto&& right_val) {
        float right_float = static_cast<float>(right_val);
        result += (left_float * right_float);
      }, right_vec[i]);
    }, left_vec[i]);
  }

  // 处理结果，判断是否为整数
  if (std::floor(result) == result) {
    value.set_type(AttrType::INTS); 
    value.set_int(static_cast<int>(result));
  } else {
    value.set_type(AttrType::FLOATS);
    // 保留两位小数，去除不必要的0
    float rounded_result = std::round(result * 100) / 100;
    value.set_float(rounded_result);
  }

  return RC::SUCCESS;
}

RC FunctionExpr::check_param() const
{
  RC rc = RC::SUCCESS;
  if (params_.size() != 2) rc = RC::INVALID_ARGUMENT;
  if (params_[0]->value_type() != AttrType::VECTORS || params_[1]->value_type() != AttrType::VECTORS) rc = RC::INVALID_ARGUMENT;
  return rc;
}

RC FunctionExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;
  if (rc != RC::SUCCESS) {
    return rc;
  }
  switch (func_type_) {
    case I2_DISTANCE: {
      rc = get_I2_value(tuple, value);
    } break;
    case COSINE_DISTANCE: {
      rc = get_COSINE_value(tuple, value);
    } break;
    case INNER_PRODUCT: {
      rc = get_INNER_value(tuple, value);
    } break;
    default:
      break;
  }
  return rc;
}