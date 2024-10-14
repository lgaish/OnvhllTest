# Install script for directory: /home/rui/datasketches/github/OnvhllTest/theta

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
  include("/home/rui/datasketches/github/OnvhllTest/build/theta/test/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_sketch.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_sketch_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_union.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_union_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_intersection.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_intersection_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_a_not_b.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_a_not_b_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_jaccard_similarity.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_comparators.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_constants.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_helpers.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_update_sketch_base.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_update_sketch_base_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_union_base.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_union_base_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_intersection_base.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_intersection_base_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_set_difference_base.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_set_difference_base_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/theta_jaccard_similarity_base.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/bounds_on_ratios_in_sampled_sets.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/bounds_on_ratios_in_theta_sketched_sets.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/compact_theta_sketch_parser.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/compact_theta_sketch_parser_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/theta/include/bit_packing.hpp"
    )
endif()

