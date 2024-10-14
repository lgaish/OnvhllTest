# Install script for directory: /home/rui/datasketches/github/OnvhllTest/tuple

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
  include("/home/rui/datasketches/github/OnvhllTest/build/tuple/test/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DataSketches" TYPE FILE FILES
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_sketch.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_sketch_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_union.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_union_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_intersection.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_intersection_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_a_not_b.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_a_not_b_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/tuple_jaccard_similarity.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_of_doubles_sketch.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_sketch.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_sketch_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_union.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_union_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_intersection.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_intersection_impl.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_a_not_b.hpp"
    "/home/rui/datasketches/github/OnvhllTest/tuple/include/array_tuple_a_not_b_impl.hpp"
    )
endif()

