cmake_minimum_required(VERSION 3.31.0)
set(CMAKE_MODULE_PATH "/home/yonf/DB/MiniOB_ky/cmake;/home/yonf/DB/MiniOB_ky/deps/faiss/cmake")
project(CheckFortran Fortran)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/result.cmake"
  "set(CMAKE_Fortran_COMPILER \"${CMAKE_Fortran_COMPILER}\")\n"
  
  )