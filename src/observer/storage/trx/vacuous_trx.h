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
// Created by Wangyunlai on 2023/4/24.
//

#pragma once

#include "storage/trx/trx.h"

/**
 * @brief Vacuous(真空的)，顾名思义就是没有实现事务功能
 */
class VacuousTrxKit : public TrxKit
{
public:
  VacuousTrxKit()          = default;
  virtual ~VacuousTrxKit() = default;

  RC                       init() override;
  const vector<FieldMeta> *trx_fields() const override;

  Trx *create_trx(LogHandler &log_handler) override;
  Trx *create_trx(LogHandler &log_handler, int32_t trx_id) override;
  Trx *find_trx(int32_t trx_id) override;
  void all_trxes(vector<Trx *> &trxes) override;

  void destroy_trx(Trx *trx) override;

  LogReplayer *create_log_replayer(Db &db, LogHandler &log_handler) override;
};

class VacuousTrx : public Trx
{
public:
  VacuousTrx()          = default;
  virtual ~VacuousTrx() = default;

  RC insert_record(Table *table, Record &record) override;
  RC delete_record(Table *table, Record &record) override;
  // RC update_record(Table *table, Record &old_record, Record &new_record) override;
  RC visit_record(Table *table, Record &record, ReadWriteMode mode) override;
  RC start_if_need() override;
  RC commit() override;
  RC rollback() override;

  RC redo(Db *db, const LogEntry &log_entry) override;

  int32_t id() const override { return 0; }
};

class VacuousTrxLogReplayer : public LogReplayer
{
public:
  VacuousTrxLogReplayer()          = default;
  virtual ~VacuousTrxLogReplayer() = default;

  RC replay(const LogEntry &) override { return RC::SUCCESS; }
};