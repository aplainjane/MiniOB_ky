# CMake generated Testfile for 
# Source directory: /home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest
# Build directory: /home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(xscblat1 "/home/yonf/DB/MiniOB_ky/build_debug/bin/xscblat1")
set_tests_properties(xscblat1 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;54;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xscblat2 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xscblat2" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/sin2")
set_tests_properties(xscblat2 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;83;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xscblat3 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xscblat3" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/sin3")
set_tests_properties(xscblat3 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;146;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xdcblat1 "/home/yonf/DB/MiniOB_ky/build_debug/bin/xdcblat1")
set_tests_properties(xdcblat1 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;54;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xdcblat2 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xdcblat2" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/din2")
set_tests_properties(xdcblat2 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;83;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xdcblat3 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xdcblat3" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/din3")
set_tests_properties(xdcblat3 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;146;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xccblat1 "/home/yonf/DB/MiniOB_ky/build_debug/bin/xccblat1")
set_tests_properties(xccblat1 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;54;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xccblat2 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xccblat2" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/cin2")
set_tests_properties(xccblat2 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;83;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xccblat3 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xccblat3" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/cin3")
set_tests_properties(xccblat3 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;146;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xccblat3_3m "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xccblat3_3m" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/cin3_3m")
set_tests_properties(xccblat3_3m PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;150;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xzcblat1 "/home/yonf/DB/MiniOB_ky/build_debug/bin/xzcblat1")
set_tests_properties(xzcblat1 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;54;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xzcblat2 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xzcblat2" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/zin2")
set_tests_properties(xzcblat2 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;83;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xzcblat3 "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xzcblat3" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/zin3")
set_tests_properties(xzcblat3 PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;146;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
add_test(xzcblat3_3m "sh" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/test_cblas_helper.sh" "/home/yonf/DB/MiniOB_ky/build_debug/bin/xzcblat3_3m" "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/zin3_3m")
set_tests_properties(xzcblat3_3m PROPERTIES  _BACKTRACE_TRIPLES "/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;150;add_test;/home/yonf/DB/MiniOB_ky/deps/OpenBLAS/ctest/CMakeLists.txt;0;")
