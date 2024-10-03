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
// Created by wangyunlai on 2021/6/11.
//

#include "common/defs.h"
#include <string.h>

#include "common/lang/algorithm.h"
#include "comparator.h"

namespace common {

int compare_int(void *arg1, void *arg2)
{
  int v1 = *(int *)arg1;
  int v2 = *(int *)arg2;
  if (v1 > v2) {
    return 1;
  } else if (v1 < v2) {
    return -1;
  } else {
    return 0;
  }
}

int compare_float(void *arg1, void *arg2)
{
  float v1  = *(float *)arg1;
  float v2  = *(float *)arg2;
  float cmp = v1 - v2;
  if (cmp > EPSILON) {
    return 1;
  }
  if (cmp < -EPSILON) {
    return -1;
  }
  return 0;
}

int compare_string(void *arg1, int arg1_max_length, void *arg2, int arg2_max_length)
{
  const char *s1     = (const char *)arg1;
  const char *s2     = (const char *)arg2;
  int         maxlen = min(arg1_max_length, arg2_max_length);
  int         result = strncmp(s1, s2, maxlen);
  if (0 != result) {
    return result < 0 ? -1 : 1;
  }

  if (arg1_max_length > maxlen) {
    return 1;
  }

  if (arg2_max_length > maxlen) {
    return -1;
  }
  return 0;
}

// 支持%和_的模式匹配
int like_string(void *arg1, void *arg2){
  
    const char *s1     = (const char *)arg1;
    const char *s2     = (const char *)arg2;
    
    // 指向当前要比较的字符串和模式
    const char *s = s1;
    const char *p = s2;

    // 记录模式中的 `%` 位置
    const char *star = nullptr;
    const char *s_backup = nullptr;

    while (*s) {
        // 跳过引号
        if (*s == '\'' || *s == '\"') {
            s++;
            continue;
        }
        if (*p == '\'' || *p == '\"') {
            p++;
            continue;
        }

        // 当模式字符和字符串字符匹配，或者模式字符是 `_` 时
        if (*p == *s || *p == '_') {
            p++;
            s++;
        }
        // 当模式字符是 `%` 时，记录位置
        else if (*p == '%') {
            star = p++;
            s_backup = s;
        }
        // 当字符不匹配
        else if (star) {
            // 尝试匹配下一个字符
            p = star + 1;
            s = ++s_backup;
        }
        // 不匹配的情况
        else {
            return 0;
        }
    }

    // 检查模式中的剩余字符
    while (*p == '%' || *p == '\'' || *p == '\"') {
        p++;
    }

    return *p == '\0' ? 1 : 0;
}

}  // namespace common
