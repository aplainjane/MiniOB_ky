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
#include "common/type/float_type.h"
#include "common/value.h"
#include "common/lang/limits.h"
#include "common/value.h"

int FloatType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::FLOATS, "left type is not integer");
  ASSERT(right.attr_type() == AttrType::INTS || right.attr_type() == AttrType::FLOATS, "right type is not numeric");
  float left_val  = left.get_float();
  float right_val = right.get_float();
  return common::compare_float((void *)&left_val, (void *)&right_val);
}

RC FloatType::add(const Value &left, const Value &right, Value &result) const
{
  result.set_float(left.get_float() + right.get_float());
  return RC::SUCCESS;
}
RC FloatType::subtract(const Value &left, const Value &right, Value &result) const
{
  result.set_float(left.get_float() - right.get_float());
  return RC::SUCCESS;
}
RC FloatType::multiply(const Value &left, const Value &right, Value &result) const
{
  result.set_float(left.get_float() * right.get_float());
  return RC::SUCCESS;
}

RC FloatType::divide(const Value &left, const Value &right, Value &result) const
{
  if (right.get_float() > -EPSILON && right.get_float() < EPSILON) {
    // NOTE:
    // 设置为浮点数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为浮点数最大值。
    result.set_float(numeric_limits<float>::max());
  } else {
    result.set_float(left.get_float() / right.get_float());
  }
  return RC::SUCCESS;
}

RC FloatType::negative(const Value &val, Value &result) const
{
  result.set_float(-val.get_float());
  return RC::SUCCESS;
}

RC FloatType::set_value_from_str(Value &val, const string &data) const
{
  RC                rc = RC::SUCCESS;
  stringstream deserialize_stream;
  deserialize_stream.clear();
  deserialize_stream.str(data);

  float float_value;
  deserialize_stream >> float_value;
  if (!deserialize_stream || !deserialize_stream.eof()) {
    rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
  } else {
    val.set_float(float_value);
  }
  return rc;
}

RC FloatType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << common::double_to_str(val.value_.float_value_);
  result = ss.str();
  return RC::SUCCESS;
}

int FloatType::cast_cost(AttrType type)
{
  if (type == attr_type_) {
    return 0;
  }
  else if(type == AttrType::INTS)
  {
    return 2;
  }
  else if(type == AttrType::CHARS)
  {
    return 3;
  }
  return INT32_MAX;
}

RC FloatType::cast_to(const Value &val, AttrType type, Value &result) const {
    // 首先检查输入值的类型
    if (val.attr_type() != AttrType::FLOATS) {
        return RC::UNSUPPORTED; // 只支持从浮点数类型转换
    }

    // 获取浮点数值
    float float_value = val.get_float();

    // 根据目标类型进行转换
    switch (type) {
        case AttrType::INTS:
            // 转换为整数（向下取整）
            int num;
            if((static_cast<int>(val.get_float()*10)% 10) >= 5)
            {
              num = static_cast<int>(val.get_float()) + 1;
            }
            else
            {
              num = static_cast<int>(val.get_float());
            }
            result.set_int(num);
            break;

        case AttrType::FLOATS:
            // 如果目标类型是浮点数，直接赋值
            result.set_float(float_value);
            break;
        
        case AttrType::CHARS:
            // 如果目标类型是浮点数，直接赋值
            result.set_string(val.to_string().c_str());
            break;

        default:
            return RC::UNSUPPORTED; // 不支持的目标类型
    }

    return RC::SUCCESS; // 转换成功
}