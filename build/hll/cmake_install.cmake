# Install script for directory: C:/Gitee/apache-datasketches-cpp/hll

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
  include("C:/Gitee/apache-datasketches-cpp/build/hll/test/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "C:/Gitee/apache-datasketches-cpp/hll/include/hll.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/AuxHashMap.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CompositeInterpolationXTable.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/hll.private.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllSketchImplFactory.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CouponHashSet.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CouponList.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CubicInterpolation.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HarmonicNumbers.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll4Array.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll6Array.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll8Array.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllArray.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllSketchImpl.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllUtil.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/coupon_iterator.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/RelativeErrorTables.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/AuxHashMap-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CompositeInterpolationXTable-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CouponHashSet-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CouponList-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/CubicInterpolation-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HarmonicNumbers-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll4Array-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll6Array-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/Hll8Array-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllArray-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllSketch-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllSketchImpl-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/HllUnion-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/coupon_iterator-internal.hpp"
    "C:/Gitee/apache-datasketches-cpp/hll/include/RelativeErrorTables-internal.hpp"
    )
endif()

