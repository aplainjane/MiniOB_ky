/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "common/lang/comparator.h"
#include "common/log/log.h"
#include "common/type/char_type.h"
#include "common/value.h"
#include "common/time/datetime.h"

int CharType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::CHARS && right.attr_type() == AttrType::CHARS, "invalid type");
  return common::compare_string(
      (void *)left.value_.pointer_value_, left.length_, (void *)right.value_.pointer_value_, right.length_);
}

int CharType::like(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::CHARS && right.attr_type() == AttrType::CHARS, "invalid type");
  return common::like_string(
      (void *)left.value_.pointer_value_,(void *)right.value_.pointer_value_);
}
RC CharType::set_value_from_str(Value &val, const string &data) const
{
  val.set_string(data.c_str());
  return RC::SUCCESS;
}

RC CharType::cast_to(const Value &val, AttrType type, Value &result) const
{
  switch (type) {
    case AttrType::DATES:{
      result.attr_type_ = AttrType::DATES;
      int y,m,d;
      if (sscanf(val.value_.pointer_value_, "%d-%d-%d", &y, &m, &d) != 3) {
        LOG_WARN("invalid date format: %s", val.value_.pointer_value_);
        return RC::INVALID_ARGUMENT;
      }
      bool check_ret = common::check_date(y,m,d);
      if (!check_ret) {
        LOG_WARN("invalid date format: %s", val.value_.pointer_value_);
        return RC::INVALID_ARGUMENT;
      }
      result.set_date(y,m,d);
        
    }break;
    case AttrType::INTS:{
      result.attr_type_ = AttrType::INTS;
      int val_int = atoi(val.value_.pointer_value_);
      if(val_int == 0 && val.to_string() != "0") {        
        return RC::INTERNAL;
      }
      else{
        result.set_int(val_int);
      }
    }break;
    case AttrType::FLOATS:{ 
      result.attr_type_ = AttrType::FLOATS;
      float val_float = atof(val.value_.pointer_value_);
      result.set_float(val_float);
    }break;
    default: return RC::UNIMPLEMENTED;
  }
  return RC::SUCCESS;
}

int CharType::cast_cost(AttrType type)
{
  if (type == AttrType::CHARS) {
    return 0;
  }
  if (type == AttrType::DATES) {
    return 1;
  }
  if (type == AttrType::FLOATS) {
    return 1;
  }
  if (type == AttrType::INTS) {
    return 1;
  }
  return INT32_MAX;
}

RC CharType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << val.value_.pointer_value_;
  result = ss.str();
  return RC::SUCCESS;
}