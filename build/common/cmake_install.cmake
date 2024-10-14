# Install script for directory: /home/rui/datasketches/github/OnvhllTest/common

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/rui/datasketches/github/OnvhllTest/build/common/test/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "/home/rui/datasketches/github/OnvhllTest/build/common/include/version.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/binomial_bounds.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/bounds_binomial_proportions.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/ceiling_power_of_2.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/common_defs.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/conditional_back_inserter.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/conditional_forward.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/count_zeros.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/inv_pow2_table.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/kolmogorov_smirnov_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/kolmogorov_smirnov.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/memory_operations.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/MurmurHash3.h"
    "/home/rui/datasketches/github/OnvhllTest/common/include/optional.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/quantiles_sorted_view_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/quantiles_sorted_view.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/serde.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/xxhash64.h"
    "/home/rui/datasketches/github/OnvhllTest/common/include/xxhash32.h"
    "/home/rui/datasketches/github/OnvhllTest/common/include/AccessStatics.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/CardinalityMap.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/EMatrix.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/Histogram.hpp"
    "/home/rui/datasketches/github/OnvhllTest/common/include/MurmurHash3.h"
    "/home/rui/datasketches/github/OnvhllTest/common/include/TwoTupleSketch.h"
    "/home/rui/datasketches/github/OnvhllTest/common/include/leader_zero.hpp"
    )
endif()

