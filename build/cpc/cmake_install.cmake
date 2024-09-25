# Install script for directory: C:/Gitee/apache-datasketches-cpp/cpc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/DataSketches")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Gitee/apache-datasketches-cpp/build/cpc/test/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "C:/Gitee/apache-datasketches-cpp/cpc/include/compression_data.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_common.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_compressor.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_compressor_impl.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_confidence.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_sketch.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_sketch_impl.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_union.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_union_impl.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/cpc_util.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/icon_estimator.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/kxp_byte_lookup.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/u32_table.hpp"
    "C:/Gitee/apache-datasketches-cpp/cpc/include/u32_table_impl.hpp"
    )
endif()

