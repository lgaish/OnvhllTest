# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
# include_directories(../include/)
# include_directories(../../common/include/)
add_executable(onvhll_test)


target_link_libraries(onvhll_test onvhll common_test_lib)

set_target_properties(onvhll_test PROPERTIES
  CXX_STANDARD_REQUIRED YES
)

file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ONVHLL_TEST_BINARY_PATH)
string(APPEND ONVHLL_TEST_BINARY_PATH "/")
target_compile_definitions(onvhll_test
  PRIVATE
    TEST_BINARY_INPUT_PATH="${ONVHLL_TEST_BINARY_PATH}"
)

add_test(
  NAME onvhll_test
  COMMAND onvhll_test
)

target_sources(onvhll_test
  PRIVATE
    test_onvhll.cpp
)

# if (SERDE_COMPAT)
# target_sources(onvhll_test
#   PRIVATE
#    frequent_items_sketch_deserialize_from_java_test.cpp
# )
# endif()

# if (GENERATE)
# target_sources(onvhll_test
#   PRIVATE
#    frequent_items_sketch_serialize_for_java.cpp
# )
# endif()
