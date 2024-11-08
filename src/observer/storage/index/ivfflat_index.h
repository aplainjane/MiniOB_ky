/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#pragma once

#include "storage/index/index.h"
#include "storage/index/IndexIVVFlat.h"

/**
 * @brief ivfflat 向量索引
 * @ingroup Index
 */
class IvfflatIndex : public Index
{
public:
  IvfflatIndex(FuncOp distance_name, int nlist, int probes, vector<RID> rids)
        : distance_name_(distance_name),
          lists_(nlist),
          probes_(probes),
          dim_(0),
          rids_(rids),
          index_(nullptr)
  {}
  virtual ~IvfflatIndex() noexcept { close(); };

  RC create(Table *table, const IndexMeta &index_meta, const FieldMeta &field_meta);
  RC open(Table *table, const char *file_name, const IndexMeta &index_meta, const FieldMeta &field_meta) { return RC::UNIMPLEMENTED; };
  vector<Value> ann_search(const Value &base, size_t limit);

  RC close();

  RC insert_entry(const char *record, const RID *rid) override { return RC::UNIMPLEMENTED; };
  RC delete_entry(const char *record, const RID *rid) override { return RC::UNIMPLEMENTED; };

  RC sync() override { return RC::UNIMPLEMENTED; };

  IndexScanner *create_scanner(const char *left_key, int left_len, bool left_inclusive, const char *right_key,
      int right_len, bool right_inclusive) override { return nullptr; }

  void destroy() override {};

private:
  bool   inited_ = false;
  Table *table_  = nullptr;
  FuncOp distance_name_;
  int    lists_  = 1;
  int    probes_ = 1;
  int    dim_   = 0;
  vector<RID> rids_;
  vector<Value>  values_;
  IndexIVFFlat *index_ = nullptr; // FAISS IVFFlat index
};
