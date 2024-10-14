# Install script for directory: /home/rui/datasketches/github/OnvhllTest/hll

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
  include("/home/rui/datasketches/github/OnvhllTest/build/hll/test/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "/home/rui/datasketches/github/OnvhllTest/hll/include/hll.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/AuxHashMap.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CompositeInterpolationXTable.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/hll.private.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllSketchImplFactory.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CouponHashSet.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CouponList.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CubicInterpolation.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HarmonicNumbers.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll4Array.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll6Array.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll8Array.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllArray.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllSketchImpl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllUtil.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/coupon_iterator.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/RelativeErrorTables.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/AuxHashMap-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CompositeInterpolationXTable-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CouponHashSet-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CouponList-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/CubicInterpolation-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HarmonicNumbers-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll4Array-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll6Array-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/Hll8Array-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllArray-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllSketch-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllSketchImpl-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/HllUnion-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/coupon_iterator-internal.hpp"
    "/home/rui/datasketches/github/OnvhllTest/hll/include/RelativeErrorTables-internal.hpp"
    )
endif()

