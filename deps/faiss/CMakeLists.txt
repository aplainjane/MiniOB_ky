cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

set(FAISS_LANGUAGES CXX)
add_compile_options(-Wno-unused-variable)
add_compile_options(-Wno-switch-unreachable)
add_compile_options(-Wno-unused-function)
# Ensure GPU and Python support are disabled
set(FAISS_ENABLE_GPU OFF)
set(FAISS_ENABLE_PYTHON OFF)

project(faiss
  VERSION 1.9.0
  DESCRIPTION "A library for efficient similarity search and clustering of dense vectors."
  HOMEPAGE_URL "https://github.com/facebookresearch/faiss"
  LANGUAGES ${FAISS_LANGUAGES})
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Valid values are "generic", "avx2", "avx512", "sve".
option(FAISS_OPT_LEVEL "" "generic")
option(FAISS_ENABLE_C_API "Build C API." ON)
option(FAISS_USE_LTO "Enable Link-Time optimization" OFF)

add_subdirectory(faiss)

# Remove GPU-related subdirectories
# if(FAISS_ENABLE_GPU)
#   if(FAISS_ENABLE_ROCM)
#     add_subdirectory(faiss/gpu-rocm)
#   else()
#     add_subdirectory(faiss/gpu)
#   endif()
# endif()

# Remove Python-related subdirectory
# if(FAISS_ENABLE_PYTHON)
#   add_subdirectory(faiss/python)
# endif()

add_subdirectory(demos)
add_subdirectory(benchs)
add_subdirectory(tutorial/cpp)

# CTest must be included in the top level to enable `make test` target.
# include(CTest)
# if(BUILD_TESTING)
#   add_subdirectory(tests)
#   add_subdirectory(perf_tests)
#   # Remove GPU test subdirectories
#   # if(FAISS_ENABLE_GPU)
#   #   if(FAISS_ENABLE_ROCM)
#   #     add_subdirectory(faiss/gpu-rocm/test)
#   #   else()
#   #     add_subdirectory(faiss/gpu/test)
#   #   endif()
#   # endif()
# endif()