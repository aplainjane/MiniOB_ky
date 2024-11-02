# pragma once

#include "common/type/data_type.h"

class LongType : public DataType {
public:

    LongType() : DataType(AttrType::LONGS)
    {
    }

    virtual ~LongType()= default;

    int compare(const Value &left, const Value &right) const { return INT32_MAX; }
    
    RC to_string(const Value &val, string &result) const { return RC::UNSUPPORTED; }
    
    RC set_value_from_str(Value &val, const string &data) const { return RC::UNSUPPORTED; }
};