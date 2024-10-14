# CMake generated Testfile for 
# Source directory: /home/rui/datasketches/github/OnvhllTest/common/test
# Build directory: /home/rui/datasketches/github/OnvhllTest/build/common/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(common_test "/home/rui/datasketches/github/OnvhllTest/build/common/test/common_test")
set_tests_properties(common_test PROPERTIES  _BACKTRACE_TRIPLES "/home/rui/datasketches/github/OnvhllTest/common/test/CMakeLists.txt;63;add_test;/home/rui/datasketches/github/OnvhllTest/common/test/CMakeLists.txt;0;")
add_test(integration_test "/home/rui/datasketches/github/OnvhllTest/build/common/test/integration_test")
set_tests_properties(integration_test PROPERTIES  _BACKTRACE_TRIPLES "/home/rui/datasketches/github/OnvhllTest/common/test/CMakeLists.txt;84;add_test;/home/rui/datasketches/github/OnvhllTest/common/test/CMakeLists.txt;0;")
subdirs("../../_deps/catch2-build")
