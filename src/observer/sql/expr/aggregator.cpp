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
// Created by Wangyunlai on 2024/05/29.
//

#include "sql/expr/aggregator.h"
#include "common/log/log.h"

RC SumAggregator::accumulate(const Value &value)
{
  if (value.attr_type() == AttrType::NULLS) {
    // 忽略 NULL 值
    return RC::SUCCESS;
  }
  if (value_.attr_type() == AttrType::UNDEFINED) {
    value_ = value;
    return RC::SUCCESS;
  }
  
  ASSERT(value.attr_type() == value_.attr_type(), "type mismatch. value type: %s, value_.type: %s", 
        attr_type_to_string(value.attr_type()), attr_type_to_string(value_.attr_type()));
  
  Value::add(value, value_, value_);
  return RC::SUCCESS;
}

RC SumAggregator::evaluate(Value& result)
{
  if (value_.attr_type() == AttrType::UNDEFINED) {
    Value vals(0);
    result = vals; 
  } else {
    result = value_;
  }
  return RC::SUCCESS;
}

RC AvgAggregator::accumulate(const Value &value)
{
  if (value.attr_type() == AttrType::NULLS) {
    // 忽略 NULL 值
    return RC::SUCCESS;
  }
  if (value_.attr_type() == AttrType::UNDEFINED) {
    value_ = value;
    return RC::SUCCESS;
  }
  
  ASSERT(value.attr_type() == value_.attr_type(), "type mismatch. value type: %s, value_.type: %s", 
        attr_type_to_string(value.attr_type()), attr_type_to_string(value_.attr_type()));
  
  Value::add(value, value_, value_);
  count_++;
  return RC::SUCCESS;
}
RC AvgAggregator::evaluate(Value& result)
{ 
  if (value_.attr_type() == AttrType::UNDEFINED) {
    Value vals;
    vals.make_null();
    result = vals; 
  } else {
    float tempresult=value_.get_float()/count_;
    Value temp2(tempresult);
    result = temp2;
  }
  return RC::SUCCESS;
}
RC CountAggregator::accumulate(const Value &value)
{
  if (value.attr_type() == AttrType::NULLS) {
    // 忽略 NULL 值
    return RC::SUCCESS;
  }
  if (value_.attr_type() == AttrType::UNDEFINED) {
    value_ = value;
    return RC::SUCCESS;
  }
  
  ASSERT(value.attr_type() == value_.attr_type(), "type mismatch. value type: %s, value_.type: %s", 
        attr_type_to_string(value.attr_type()), attr_type_to_string(value_.attr_type()));
  
  count_++;
  return RC::SUCCESS;
}
RC CountAggregator::evaluate(Value& result)
{ 
  if(count_ == 1 && value_.attr_type() == AttrType::UNDEFINED) {  count_ = 0;}
  result = Value(count_);
  return RC::SUCCESS;
}
RC MaxAggregator::accumulate(const Value &value)
{
  if (value.attr_type() == AttrType::NULLS) {
    // 忽略 NULL 值
    return RC::SUCCESS;
  }
  
  if (value_.attr_type() == AttrType::UNDEFINED) {
    value_ = value;
    return RC::SUCCESS;
  }
  
  ASSERT(value.attr_type() == value_.attr_type(), "type mismatch. value type: %s, value_.type: %s", 
        attr_type_to_string(value.attr_type()), attr_type_to_string(value_.attr_type()));
        
  if(value_.compare(value)<0){
    value_=value;
  }
  return RC::SUCCESS;
}
RC MaxAggregator::evaluate(Value& result)
{
  // 检查是否是未定义，以便返回 NULL
  if (value_.attr_type() == AttrType::UNDEFINED) {
    Value vals;
    vals.make_null();
    result = vals; 
  } else {
    result = value_;
  }
  return RC::SUCCESS;
}
RC MinAggregator::accumulate(const Value &value)
{
  if (value.attr_type() == AttrType::NULLS) {
    // 忽略 NULL 值
    return RC::SUCCESS;
  }
  if (value_.attr_type() == AttrType::UNDEFINED) {
    value_ = value;
    return RC::SUCCESS;
  }
  
  ASSERT(value.attr_type() == value_.attr_type(), "type mismatch. value type: %s, value_.type: %s", 
        attr_type_to_string(value.attr_type()), attr_type_to_string(value_.attr_type()));
  
  if(value_.compare(value)>0){
    value_=value;
  }
  return RC::SUCCESS;
}
RC MinAggregator::evaluate(Value& result)
{
  // 检查是否是未定义，以便返回 NULL
  if (value_.attr_type() == AttrType::UNDEFINED) {
    Value vals;
    vals.make_null();
    result = vals; 
  } else {
    result = value_;
  }
  return RC::SUCCESS;
}
