# CMake generated Testfile for 
# Source directory: C:/Gitee/apache-datasketches-cpp/common/test
# Build directory: C:/Gitee/apache-datasketches-cpp/build/common/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(common_test "C:/Gitee/apache-datasketches-cpp/build/common/test/common_test.exe")
set_tests_properties(common_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Gitee/apache-datasketches-cpp/common/test/CMakeLists.txt;63;add_test;C:/Gitee/apache-datasketches-cpp/common/test/CMakeLists.txt;0;")
add_test(integration_test "C:/Gitee/apache-datasketches-cpp/build/common/test/integration_test.exe")
set_tests_properties(integration_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Gitee/apache-datasketches-cpp/common/test/CMakeLists.txt;84;add_test;C:/Gitee/apache-datasketches-cpp/common/test/CMakeLists.txt;0;")
subdirs("../../_deps/catch2-build")
