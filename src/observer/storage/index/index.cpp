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
// Created by wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/index.h"

RC Index::init(const IndexMeta &index_meta, std::vector<FieldMeta> &field_metas)
{
  index_meta_ = index_meta;
  field_metas_ = field_metas;
  return RC::SUCCESS;
}

RC Index::init(const IndexMeta &index_meta, const FieldMeta &field_meta)
{
  index_meta_ = index_meta;
  field_metas_.push_back(field_meta);
  return RC::SUCCESS;
}