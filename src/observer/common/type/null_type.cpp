#include <iomanip>

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/null_type.h"
#include "common/value.h"

int NullType::compare(const Value &left, const Value &right) const
{
    return INT32_MAX;
}

RC NullType::to_string(const Value &val, string &result) const
{
    stringstream ss;
    ss << "NULL";
    result = ss.str();
    return RC::SUCCESS;
}