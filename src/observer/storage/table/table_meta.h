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
// Created by Wangyunlai on 2021/5/12.
//

#pragma once

#include <string>
#include <vector>
#include <span>

#include "common/lang/serializable.h"
#include "common/rc.h"
#include "common/types.h"
#include "storage/field/field_meta.h"
#include "storage/index/index_meta.h"

/**
 * @brief 表元数据
 *
 */
class TableMeta : public common::Serializable
{
public:
  TableMeta()          = default;
  virtual ~TableMeta() = default;

  TableMeta(const TableMeta &other);

  void swap(TableMeta &other) noexcept;

  RC init(int32_t table_id, const char *name, const std::vector<FieldMeta> *trx_fields,
      std::span<const AttrInfoSqlNode> attributes, StorageFormat storage_format);

  RC add_index(const IndexMeta &index);
  RC add_vec_index(const IndexMeta &index);

public:
  int32_t             table_id() const { return table_id_; }
  const char         *name() const;
  const FieldMeta    *trx_field() const;
  const FieldMeta    *field(int index) const;
  const FieldMeta    *field(const char *name) const;
  const FieldMeta    *find_field_by_offset(int offset) const;
  auto                field_metas() const -> const std::vector<FieldMeta>                *{ return &fields_; }
  auto                trx_fields() const -> std::span<const FieldMeta>;
  const StorageFormat storage_format() const { return storage_format_; }

  int field_num() const;  // sys field included
  int sys_field_num() const;

  const IndexMeta *index(const char *name) const;
  const IndexMeta *find_index_by_fields(std::vector<const char *> fields) const;
  const IndexMeta *find_vec_index_by_fields(const char *field) const;
  const IndexMeta *index(int i) const;
  int              index_num() const;

  int record_size() const;

public:
  int  serialize(std::ostream &os) const override;
  int  deserialize(std::istream &is) override;
  int  get_serial_size() const override;
  void to_string(std::string &output) const override;
  void desc(std::ostream &os) const;

protected:
  int32_t                table_id_ = -1;
  std::string            name_;
  std::vector<FieldMeta> trx_fields_;
  std::vector<FieldMeta> fields_;  // 包含sys_fields
  std::vector<IndexMeta> indexes_;
  std::vector<IndexMeta> vec_indexes_;
  StorageFormat          storage_format_;

  int record_size_ = 0;
};

std::vector<int> int2bitmap(int num, int size);
int bitmap2int(std::vector<int>& bitmap);