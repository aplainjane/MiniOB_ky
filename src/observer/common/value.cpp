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
// Created by WangYunlai on 2023/06/28.
//

#include <cstring>
#include "common/value.h"

#include "common/lang/comparator.h"
#include "common/lang/exception.h"
#include "common/lang/sstream.h"
#include "common/lang/string.h"
#include "common/log/log.h"

using ElementType = std::variant<int, float>;
char* vectorToCharArray(const std::vector<ElementType>& vector_values);

Value::Value(int val) { set_int(val); }

Value::Value(float val) { set_float(val); }

Value::Value(bool val) { set_boolean(val); }

Value::Value(int val, int flag)
{
  set_null(val);
}

Value::Value(const char *s, int len /*= 0*/) {
  if (s[0] == '[' || s[strlen(s) - 1] == ']') {
    parse_vector(s);
  }
  else {
    set_string(s, len);
  } 
}

Value::Value(const Value &other)
{
  this->attr_type_ = other.attr_type_;
  this->length_    = other.length_;
  this->own_data_  = other.own_data_;
  switch (this->attr_type_) {
    case AttrType::CHARS: {
      set_string_from_other(other);
    } break;

    default: {
      this->value_ = other.value_;
      this->vector_values_ = other.vector_values_;
    } break;
  }
}

Value::Value(Value &&other)
{
  this->attr_type_ = other.attr_type_;
  this->length_    = other.length_;
  this->own_data_  = other.own_data_;
  this->value_     = other.value_;
  this->vector_values_ = other.vector_values_;
  other.own_data_  = false;
  other.length_    = 0;
}

Value &Value::operator=(const Value &other)
{
  if (this == &other) {
    return *this;
  }
  reset();
  this->attr_type_ = other.attr_type_;
  this->length_    = other.length_;
  this->own_data_  = other.own_data_;
  switch (this->attr_type_) {
    case AttrType::CHARS: {
      set_string_from_other(other);
    } break;

    default: {
      this->value_ = other.value_;
      this->vector_values_ = other.vector_values_;
    } break;
  }
  return *this;
}

Value &Value::operator=(Value &&other)
{
  if (this == &other) {
    return *this;
  }
  reset();
  this->attr_type_ = other.attr_type_;
  this->length_    = other.length_;
  this->own_data_  = other.own_data_;
  this->value_     = other.value_;
  this->vector_values_ = other.vector_values_;
  other.own_data_  = false;
  other.length_    = 0;
  return *this;
}

void Value::reset()
{
  switch (attr_type_) {
    case AttrType::CHARS:
      if (own_data_ && value_.pointer_value_ != nullptr) {
        delete[] value_.pointer_value_;
        value_.pointer_value_ = nullptr;
      }
      break;
    case AttrType::VECTORS:
      if (own_data_ && !vector_values_.empty()) {
        vector_values_.clear();
      }
      break;
    default: break;
  }

  attr_type_ = AttrType::UNDEFINED;
  length_    = 0;
  own_data_  = false;
}

void Value::set_data(char *data, int length)
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      set_string(data, length);
    } break;
    case AttrType::INTS: {
      value_.int_value_ = *(int *)data;
      length_           = length;
    } break;
    case AttrType::FLOATS: {
      value_.float_value_ = *(float *)data;
      length_             = length;
    } break;
    case AttrType::BOOLEANS: {
      value_.bool_value_ = *(int *)data != 0;
      length_            = length;
    } break;
    case AttrType::NULLS: {
      value_.null_value_ = *(int* )data;
    } break;
    case AttrType::DATES: {
      value_.int_value_ = *(int *)data;
      length_           = length;
    } break;
    case AttrType::VECTORS: {
      std::cout<<"data: "<<data<<std::endl;
      std::cout<<"length: "<<length<<std::endl;
      parse_vector(data);
      length_        = length;
    } break;
    default: {
      LOG_WARN("unknown data type: %d", attr_type_);
    } break;
  }
}

void Value::set_int(int val)
{
  reset();
  attr_type_        = AttrType::INTS;
  value_.int_value_ = val;
  length_           = sizeof(val);
}

void Value::set_float(float val)
{
  reset();
  attr_type_          = AttrType::FLOATS;
  value_.float_value_ = val;
  length_             = sizeof(val);
}
void Value::set_boolean(bool val)
{
  reset();
  attr_type_         = AttrType::BOOLEANS;
  value_.bool_value_ = val;
  length_            = sizeof(val);
}
void Value::set_null(int val)
{
  reset();
  attr_type_ = AttrType::NULLS;
  value_.int_value_ = val;
  value_.null_value_ = val;
  length_ = sizeof(val);
}

void Value::set_string(const char *s, int len /*= 0*/)
{
  reset();
  attr_type_ = AttrType::CHARS;
  if (s == nullptr) {
    value_.pointer_value_ = nullptr;
    length_               = 0;
  } else {
    own_data_ = true;
    if (len > 0) {
      len = strnlen(s, len);
    } else {
      len = strlen(s);
    }
    value_.pointer_value_ = new char[len + 1];
    length_               = len;
    memcpy(value_.pointer_value_, s, len);
    value_.pointer_value_[len] = '\0';
  }
}

void Value::parse_vector(const char *s)
{
  reset();
  attr_type_ = AttrType::VECTORS;
  own_data_ = true;
  std::string content(s + 1, s + strlen(s) - 1); // 去掉中括号
  std::istringstream ss(content);
  std::string item;
  std::vector<ElementType> vector_values;
  std::cout<<"content: "<<content<<std::endl;
  while (std::getline(ss, item, ',')) {
    // 去掉可能的空格
    item.erase(std::remove_if(item.begin(), item.end(), ::isspace), item.end());

    // 判断类型并添加到向量中
    try {
      if (!item.empty()) {
        if (item.find('.') != std::string::npos) {
          // 处理 float 类型
          float value = std::stof(item);
          vector_values.push_back(value);
        } else {
          // 处理 int 类型
          int value = std::stoi(item);
          vector_values.push_back(value);
        }
      }
    } catch (const std::exception &e) {
      LOG_WARN("Invalid value in vector: %s", item.c_str());
      vector_values.push_back(0);
    }
  }
  vector_values_ = vector_values;
}

void Value::set_value(const Value &value)
{
  switch (value.attr_type_) {
    case AttrType::INTS: {
      set_int(value.get_int());
    } break;
    case AttrType::FLOATS: {
      set_float(value.get_float());
    } break;
    case AttrType::CHARS: {
      set_string(value.get_string().c_str());
    } break;
    case AttrType::NULLS: {
      set_null(value.get_null());
    } break;
    case AttrType::BOOLEANS: {
      set_boolean(value.get_boolean());
    } break;
    case AttrType::VECTORS: {
      attr_type_ = AttrType::VECTORS;
      vector_values_ = value.vector_values_;
    }
    default: {
      ASSERT(false, "got an invalid value type");
    } break;
  }
}

void Value::set_string_from_other(const Value &other)
{
  ASSERT(attr_type_ == AttrType::CHARS, "attr type is not CHARS");
  if (own_data_ && other.value_.pointer_value_ != nullptr && length_ != 0) {
    this->value_.pointer_value_ = new char[this->length_ + 1];
    memcpy(this->value_.pointer_value_, other.value_.pointer_value_, this->length_);
    this->value_.pointer_value_[this->length_] = '\0';
  }
}

const char *Value::data() const
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      return value_.pointer_value_;
    } break;
    case AttrType::VECTORS: {
      char *data_values = vectorToCharArray(vector_values_);
      return data_values;
    }
    default: {
      return (const char *)&value_;
    } break;
  }
}

string Value::to_string() const
{
  string res;
  RC     rc = DataType::type_instance(this->attr_type_)->to_string(*this, res);
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to convert value to string. type=%s", attr_type_to_string(this->attr_type_));
    return "";
  }
  return res;
}

int Value::compare(const Value &other) const { return DataType::type_instance(this->attr_type_)->compare(*this, other); }

int Value::like(const Value &other) const
{
  return DataType::type_instance(this->attr_type_)->like(*this, other);
}
int Value::in(const Value &other) const
{
  return DataType::type_instance(this->attr_type_)->like(*this, other);
}
int Value::exist(const Value &other) const
{
  return DataType::type_instance(this->attr_type_)->like(*this, other);
}
int Value::get_int() const
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      try {
        return (int)(std::stol(value_.pointer_value_));
      } catch (exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s", value_.pointer_value_, ex.what());
        return 0;
      }
    }
    case AttrType::INTS: {
      return value_.int_value_;
    }
    case AttrType::FLOATS: {
      return (int)(value_.float_value_);
    }
    case AttrType::BOOLEANS: {
      return (int)(value_.bool_value_);
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

float Value::get_float() const
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      try {
        return std::stof(value_.pointer_value_);
      } catch (exception const &ex) {
        LOG_TRACE("failed to convert string to float. s=%s, ex=%s", value_.pointer_value_, ex.what());
        return 0.0;
      }
    } break;
    case AttrType::INTS: {
      return float(value_.int_value_);
    } break;
    case AttrType::FLOATS: {
      return value_.float_value_;
    } break;
    case AttrType::BOOLEANS: {
      return float(value_.bool_value_);
    } break;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

string Value::get_string() const { return this->to_string(); }

bool Value::get_boolean() const
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      try {
        float val = std::stof(value_.pointer_value_);
        if (val >= EPSILON || val <= -EPSILON) {
          return true;
        }

        int int_val = std::stol(value_.pointer_value_);
        if (int_val != 0) {
          return true;
        }

        return value_.pointer_value_ != nullptr;
      } catch (exception const &ex) {
        LOG_TRACE("failed to convert string to float or integer. s=%s, ex=%s", value_.pointer_value_, ex.what());
        return value_.pointer_value_ != nullptr;
      }
    } break;
    case AttrType::INTS: {
      return value_.int_value_ != 0;
    } break;
    case AttrType::FLOATS: {
      float val = value_.float_value_;
      return val >= EPSILON || val <= -EPSILON;
    } break;
    case AttrType::BOOLEANS: {
      return value_.bool_value_;
    } break;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return false;
    }
  }
  return false;
}

vector<ElementType> Value::get_vector() const
{
  ASSERT(attr_type_ == AttrType::VECTORS, "attr type is not VECTORS");
  return vector_values_;
}

char* vectorToCharArray(const std::vector<ElementType>& vector_values) {
    std::ostringstream oss;
    oss << "["; // 开始括号

    for (size_t i = 0; i < vector_values.size(); ++i) {
        std::visit([&oss](auto&& arg) {
            oss << arg; // 将元素添加到输出流
        }, vector_values[i]);

        if (i < vector_values.size() - 1) {
            oss << ", "; // 添加逗号和空格分隔
        }
    }

    oss << "]"; // 结束括号

    std::string result = oss.str();
    result += '\0'; // 添加字符串终止符

    size_t result_size = result.size() + 1; // +1 for null terminato

    char* char_array = new char[result_size];
    std::strcpy(char_array, result.c_str());

    return char_array;
}

int Value::get_null() const
{
  switch (attr_type_) {
    case AttrType::CHARS: {
      std::cout << "Value::get_null() ERROR" << std::endl;
    }
    case AttrType::INTS: {
      std::cout << "Value::get_null() ERROR" << std::endl;
    }
    case AttrType::FLOATS: {
      std::cout << "Value::get_null() ERROR" << std::endl;
    }
    case AttrType::BOOLEANS: {
      std::cout << "Value::get_null() ERROR" << std::endl;
    }
    case AttrType::DATES: {
      std::cout << "Value::get_null() ERROR" << std::endl;
    }
    case AttrType::NULLS: {
      return value_.null_value_;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}