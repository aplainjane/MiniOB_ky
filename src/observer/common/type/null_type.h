# pragma once

#include "common/type/data_type.h"

class NullType : public DataType {
public:

    NullType() : DataType(AttrType::NULLS)
    {
    }

    virtual ~NullType()= default;

    int compare(const Value &left, const Value &right) const override;
    
    RC to_string(const Value &val, string &result) const override;
    
    RC set_value_from_str(Value &val, const string &data) const override;
};