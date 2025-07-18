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
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/integer_type.h"
#include "common/value.h"

int IntegerType::compare(const Value &left, const Value &right) const
{
  Value temp;
  temp.set_float(static_cast<float>(left.get_int()));
  ASSERT(left.attr_type() == AttrType::INTS, "left type is not integer");
  ASSERT(right.attr_type() == AttrType::INTS || right.attr_type() == AttrType::FLOATS, "right type is not numeric");
  if (right.attr_type() == AttrType::INTS) {
    return common::compare_int((void *)&left.value_.int_value_, (void *)&right.value_.int_value_);
  } else if (right.attr_type() == AttrType::FLOATS) {
    return common::compare_float((void *)&temp.value_.float_value_, (void *)&right.value_.float_value_);
  }
  return INT32_MAX;
}

RC IntegerType::add(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() + right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::subtract(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() - right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::multiply(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() * right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::negative(const Value &val, Value &result) const
{
  result.set_int(-val.get_int());
  return RC::SUCCESS;
}

RC IntegerType::set_value_from_str(Value &val, const string &data) const
{
  RC                rc = RC::SUCCESS;
  stringstream deserialize_stream;
  deserialize_stream.clear();  // 清理stream的状态，防止多次解析出现异常
  deserialize_stream.str(data);
  int int_value;
  deserialize_stream >> int_value;
  if (!deserialize_stream || !deserialize_stream.eof()) {
    rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
  } else {
    val.set_int(int_value);
  }
  return rc;
}

RC IntegerType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << val.value_.int_value_;
  result = ss.str();
  return RC::SUCCESS;
}

int IntegerType::cast_cost(AttrType type)
{
  if (type == attr_type_) {
    return 0;
  }
  else if(type == AttrType::FLOATS)
  {
    return 1;
  }
  else if(type == AttrType::CHARS)
  {
    return 2;
  }
  return INT32_MAX;
}

RC IntegerType::cast_to(const Value &val, AttrType type, Value &result) const 
{ 
  // 首先检查输入值的类型
    if (val.attr_type() != AttrType::INTS) {
        return RC::UNSUPPORTED; // 只支持从整数类型转换
    }

    // 获取整数值
    int int_value = val.get_int();

    // 根据目标类型进行转换
    switch (type) {
        case AttrType::FLOATS:
            // 转换为浮点数
            result.set_float(static_cast<float>(int_value));
            break;


        case AttrType::INTS:
            // 如果目标类型是整数，直接赋值
            result.set_int(int_value);
            break;

        case AttrType::CHARS:
          // 如果目标类型是整数，直接赋值
          result.set_string(val.to_string().c_str());
          break;

        default:
            return RC::UNSUPPORTED; // 不支持的目标类型
    }

    return RC::SUCCESS; // 转换成功
}