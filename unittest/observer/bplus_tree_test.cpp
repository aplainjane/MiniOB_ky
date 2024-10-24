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
// Created by longda on 2022
//

#include <iostream>
#include <list>
#include <filesystem>

#include "common/log/log.h"
#include "common/lang/memory.h"
#include "common/lang/filesystem.h"
#include "sql/parser/parse_defs.h"
#include "storage/buffer/disk_buffer_pool.h"
#include "storage/index/bplus_tree.h"
#include "storage/clog/vacuous_log_handler.h"
#include "storage/buffer/double_write_buffer.h"
#include "gtest/gtest.h"

using namespace common;

#define TIMES 3
// order must small real order
// if page is 8k, it is 400
#define ORDER 4
#define INSERT_NUM (TIMES * ORDER * ORDER * ORDER * ORDER)
#define POOL_NUM 2



int main(int argc, char **argv)
{

  // 分析gtest程序的命令行参数
  testing::InitGoogleTest(&argc, argv);

  // 调用RUN_ALL_TESTS()运行所有测试用例
  // main函数返回RUN_ALL_TESTS()的运行结果

  LoggerFactory::init_default("test.log", LOG_LEVEL_TRACE);
  int rc = RUN_ALL_TESTS();

  return rc;
}
