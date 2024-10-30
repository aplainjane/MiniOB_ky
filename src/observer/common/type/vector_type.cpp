#include <iomanip>
#include <cstring>

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/vector_type.h"
#include "common/value.h"

int VectorType::compare(const Value &left, const Value &right) const
{
  if (left.attr_type()!=AttrType::VECTORS || right.attr_type()!=AttrType::VECTORS){
    LOG_WARN("type not match");
    return INT32_MAX;
  }

  const auto &left_values = left.get_vector();
  const auto &right_values = right.get_vector();
  // Compare element by element
  size_t min_size = std::min(left_values.size(), right_values.size());
  for (size_t i = 0; i < min_size; ++i) {
    // Compare the two variants
    if (left_values[i] < right_values[i]) {
        return -1; // left is less than right
    } else if (left_values[i] > right_values[i]) {
        return 1;  // left is greater than right
    }
  }

  // If all compared elements are equal, the shorter vector is "less"
  if (left_values.size() < right_values.size()) {
    return -1; // left is less than right
  } else if (left_values.size() > right_values.size()) {
    return 1;  // left is greater than right
  }
  
  return 0; // They are equal
}

RC VectorType::add(const Value &left, const Value &right, Value &result) const
{
  if (left.attr_type()!=AttrType::VECTORS || right.attr_type()!=AttrType::VECTORS){
    LOG_WARN("type not match");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  const auto &left_values = left.get_vector();
  const auto &right_values = right.get_vector();
  // add element by element
  ASSERT(left_values.size() == right_values.size(),"size must be equal");
  result.set_type(AttrType::VECTORS);
  std::vector<std::variant<int, float>> sum_values;
  for (size_t i = 0; i < left.vector_values_.size(); ++i) {
    if (left.vector_values_[i].index() != right.vector_values_[i].index()) {
      return RC::INTERNAL; // 不同类型的元素不能相加
    }
    std::variant<int, float> sum;
    if (std::holds_alternative<int>(left.vector_values_[i])) {
      sum = std::get<int>(left.vector_values_[i]) + std::get<int>(right.vector_values_[i]);
    } else {
      sum = std::get<float>(left.vector_values_[i]) + std::get<float>(right.vector_values_[i]);
    }
    sum_values.push_back(sum);
  }
  result.set_vector(sum_values);
  return RC::SUCCESS;
}

RC VectorType::to_string(const Value &val, string &result) const
{
    std::ostringstream oss;
    oss << "[";
    const auto &val_vec = val.get_vector();
    for (size_t i = 0; i < val_vec.size(); ++i) {
        if (i != 0) oss << ", ";
            if (std::holds_alternative<int>(val_vec[i])) {
                oss << std::get<int>(val_vec[i]);
            } else {
                oss << std::get<float>(val_vec[i]);
            }
    }
    oss << "]";
    result = oss.str();
    return RC::SUCCESS;
}
