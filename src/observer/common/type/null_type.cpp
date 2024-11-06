#include <iomanip>

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/null_type.h"
#include "common/value.h"

int NullType::compare(const Value &left, const Value &right) const
{
  if(left.attr_type()==AttrType::NULLS && right.attr_type()==AttrType::NULLS) {
    return 0;
  }
    return INT32_MAX;
}

RC NullType::to_string(const Value &val, string &result) const
{
    stringstream ss;
    ss << "NULL";
    result = ss.str();
    return RC::SUCCESS;
}

RC NullType::set_value_from_str(Value &val, const string &data) const
{
RC                rc = RC::SUCCESS;
  stringstream deserialize_stream;
  deserialize_stream.clear();  // 清理stream的状态，防止多次解析出现异常
  deserialize_stream.str(data);
  int null_value;
  deserialize_stream >> null_value;
  if (!deserialize_stream || !deserialize_stream.eof()) {
    rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
  } else {
    val.set_null(null_value);;
  }
  return rc;
}