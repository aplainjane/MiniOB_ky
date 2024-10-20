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
// Created by Wangyunlai on 2022/07/08.
//

#include "sql/operator/index_scan_physical_operator.h"
#include "storage/index/index.h"
#include "storage/trx/trx.h"

IndexScanPhysicalOperator::IndexScanPhysicalOperator(Table *table, Index *index, ReadWriteMode mode, const Value *left_value,
    bool left_inclusive, const Value *right_value, bool right_inclusive)
    : table_(table),
      index_(index),
      mode_(mode),
      left_inclusive_(left_inclusive),
      right_inclusive_(right_inclusive)
{
  if (left_value) {
    left_value_ = *left_value;
  }
  if (right_value) {
    right_value_ = *right_value;
  }
}

IndexScanPhysicalOperator::IndexScanPhysicalOperator(
    Table *table, Index *index, ReadWriteMode mode,
    std::vector<Value> left_values, bool left_inclusive, 
    std::vector<Value> right_values, bool right_inclusive)
    : table_(table), 
      index_(index),
      mode_(mode),
      left_values_(left_values),
      left_inclusive_(left_inclusive), 
      right_values_(right_values),
      right_inclusive_(right_inclusive){}

RC IndexScanPhysicalOperator::open(Trx *trx)
{
    if (nullptr == table_ || nullptr == index_) {
        return RC::INTERNAL;
    }

    size_t total_left_length = 0;
    size_t total_right_length = 0;

    for (const auto &value : left_values_) {
        total_left_length += value.length()+64;
    }
    for (const auto &value : right_values_) {
        total_right_length += value.length()+64;
    }

    char *left_key = (char *)malloc(total_left_length);
    char *right_key = (char *)malloc(total_right_length);

    if (left_key == nullptr || right_key == nullptr) {
        LOG_WARN("Failed to alloc memory for key.");
        free(left_key);
        free(right_key);
        return RC::INTERNAL;
    }

    int left_allocate_idx = 0;
    int right_allocate_idx = 0;

    for (size_t i = 0; i < left_values_.size(); ++i) {
        memcpy(left_key + left_allocate_idx, left_values_[i].data(), left_values_[i].length());
        left_allocate_idx += left_values_[i].length();
    }

    for (size_t i = 0; i < right_values_.size(); ++i) {
        memcpy(right_key + right_allocate_idx, right_values_[i].data(), right_values_[i].length());
        right_allocate_idx += right_values_[i].length();
    }

    IndexScanner *index_scanner = index_->create_scanner(left_key, left_allocate_idx, left_inclusive_,
                                                         right_key, right_allocate_idx, right_inclusive_);

    if (nullptr == index_scanner) {
        LOG_WARN("failed to create index scanner");
        free(left_key);
        free(right_key);
        return RC::INTERNAL;
    }

    record_handler_ = table_->record_handler();
    if (nullptr == record_handler_) {
        LOG_WARN("invalid record handler");
        index_scanner->destroy();
        free(left_key);
        free(right_key);
        return RC::INTERNAL;
    }

    index_scanner_ = index_scanner;
    tuple_.set_schema(table_, table_->table_meta().field_metas());

    trx_ = trx;
    free(left_key);
    free(right_key);
    return RC::SUCCESS;
}


RC IndexScanPhysicalOperator::next()
{
  RID rid;
  RC  rc = RC::SUCCESS;

  bool filter_result = false;
  while (RC::SUCCESS == (rc = index_scanner_->next_entry(&rid))) {
    rc = record_handler_->get_record(rid, current_record_);
    if (OB_FAIL(rc)) {
      LOG_TRACE("failed to get record. rid=%s, rc=%s", rid.to_string().c_str(), strrc(rc));
      return rc;
    }

    LOG_TRACE("got a record. rid=%s", rid.to_string().c_str());

    tuple_.set_record(&current_record_);
    rc = filter(tuple_, filter_result);
    if (OB_FAIL(rc)) {
      LOG_TRACE("failed to filter record. rc=%s", strrc(rc));
      return rc;
    }

    if (!filter_result) {
      LOG_TRACE("record filtered");
      continue;
    }

    rc = trx_->visit_record(table_, current_record_, mode_);
    if (rc == RC::RECORD_INVISIBLE) {
      LOG_TRACE("record invisible");
      continue;
    } else {
      return rc;
    }
  }

  return rc;
}

RC IndexScanPhysicalOperator::close()
{
  index_scanner_->destroy();
  index_scanner_ = nullptr;
  return RC::SUCCESS;
}

Tuple *IndexScanPhysicalOperator::current_tuple()
{
  tuple_.set_record(&current_record_);
  return &tuple_;
}

void IndexScanPhysicalOperator::set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs)
{
  predicates_ = std::move(exprs);
}

RC IndexScanPhysicalOperator::filter(RowTuple &tuple, bool &result)
{
  RC    rc = RC::SUCCESS;
  Value value;
  for (std::unique_ptr<Expression> &expr : predicates_) {
    rc = expr->get_value(tuple, value);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool tmp_result = value.get_boolean();
    if (!tmp_result) {
      result = false;
      return rc;
    }
  }

  result = true;
  return rc;
}

std::string IndexScanPhysicalOperator::param() const
{
  return std::string(index_->index_meta().name()) + " ON " + table_->name();
}
