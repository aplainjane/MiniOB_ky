# Copyright (c) Facebook, Inc. and its affiliates.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

add_compile_options(-Wno-unused-variable)
add_compile_options(-Wno-switch-unreachable)
add_compile_options(-Wno-unused-function)

project(faiss
  VERSION 1.7.3
  DESCRIPTION "A library for efficient similarity search and clustering of dense vectors."
  HOMEPAGE_URL "https://github.com/facebookresearch/faiss"
  LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Valid values are "generic", "avx2".
option(FAISS_OPT_LEVEL "" "generic")
option(FAISS_ENABLE_C_API "Build C API." OFF)

add_subdirectory(../OpenBLAS ${CMAKE_CURRENT_SOURCE_DIR}/../OpenBLAS)
find_library(BLAS_LIBRARIES OpenBLAS PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../OpenBLAS)
add_subdirectory(faiss)

if(FAISS_ENABLE_C_API)
  add_subdirectory(c_api)
endif()

add_subdirectory(demos)
add_subdirectory(benchs)
add_subdirectory(tutorial/cpp)


