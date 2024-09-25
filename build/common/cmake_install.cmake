# Install script for directory: C:/Gitee/apache-datasketches-cpp/common

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
  include("C:/Gitee/apache-datasketches-cpp/build/common/test/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "C:/Gitee/apache-datasketches-cpp/build/common/include/version.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/binomial_bounds.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/bounds_binomial_proportions.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/ceiling_power_of_2.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/common_defs.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/conditional_back_inserter.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/conditional_forward.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/count_zeros.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/inv_pow2_table.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/kolmogorov_smirnov_impl.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/kolmogorov_smirnov.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/memory_operations.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/MurmurHash3.h"
    "C:/Gitee/apache-datasketches-cpp/common/include/optional.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/quantiles_sorted_view_impl.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/quantiles_sorted_view.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/serde.hpp"
    "C:/Gitee/apache-datasketches-cpp/common/include/xxhash64.h"
    "C:/Gitee/apache-datasketches-cpp/common/include/xxhash32.h"
    )
endif()

