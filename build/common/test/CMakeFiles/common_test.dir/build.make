# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rui/datasketches/github/OnvhllTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rui/datasketches/github/OnvhllTest/build

# Include any dependencies generated for this target.
include common/test/CMakeFiles/common_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include common/test/CMakeFiles/common_test.dir/compiler_depend.make

# Include the progress variables for this target.
include common/test/CMakeFiles/common_test.dir/progress.make

# Include the compile flags for this target's objects.
include common/test/CMakeFiles/common_test.dir/flags.make

common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o: common/test/CMakeFiles/common_test.dir/flags.make
common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o: ../common/test/quantiles_sorted_view_test.cpp
common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o: common/test/CMakeFiles/common_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o -MF CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o.d -o CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o -c /home/rui/datasketches/github/OnvhllTest/common/test/quantiles_sorted_view_test.cpp

common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.i"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rui/datasketches/github/OnvhllTest/common/test/quantiles_sorted_view_test.cpp > CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.i

common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.s"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rui/datasketches/github/OnvhllTest/common/test/quantiles_sorted_view_test.cpp -o CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.s

common/test/CMakeFiles/common_test.dir/optional_test.cpp.o: common/test/CMakeFiles/common_test.dir/flags.make
common/test/CMakeFiles/common_test.dir/optional_test.cpp.o: ../common/test/optional_test.cpp
common/test/CMakeFiles/common_test.dir/optional_test.cpp.o: common/test/CMakeFiles/common_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object common/test/CMakeFiles/common_test.dir/optional_test.cpp.o"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT common/test/CMakeFiles/common_test.dir/optional_test.cpp.o -MF CMakeFiles/common_test.dir/optional_test.cpp.o.d -o CMakeFiles/common_test.dir/optional_test.cpp.o -c /home/rui/datasketches/github/OnvhllTest/common/test/optional_test.cpp

common/test/CMakeFiles/common_test.dir/optional_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common_test.dir/optional_test.cpp.i"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rui/datasketches/github/OnvhllTest/common/test/optional_test.cpp > CMakeFiles/common_test.dir/optional_test.cpp.i

common/test/CMakeFiles/common_test.dir/optional_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common_test.dir/optional_test.cpp.s"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rui/datasketches/github/OnvhllTest/common/test/optional_test.cpp -o CMakeFiles/common_test.dir/optional_test.cpp.s

# Object files for target common_test
common_test_OBJECTS = \
"CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o" \
"CMakeFiles/common_test.dir/optional_test.cpp.o"

# External object files for target common_test
common_test_EXTERNAL_OBJECTS = \
"/home/rui/datasketches/github/OnvhllTest/build/common/test/CMakeFiles/common_test_lib.dir/catch_runner.cpp.o" \
"/home/rui/datasketches/github/OnvhllTest/build/common/test/CMakeFiles/common_test_lib.dir/test_allocator.cpp.o"

common/test/common_test: common/test/CMakeFiles/common_test.dir/quantiles_sorted_view_test.cpp.o
common/test/common_test: common/test/CMakeFiles/common_test.dir/optional_test.cpp.o
common/test/common_test: common/test/CMakeFiles/common_test_lib.dir/catch_runner.cpp.o
common/test/common_test: common/test/CMakeFiles/common_test_lib.dir/test_allocator.cpp.o
common/test/common_test: common/test/CMakeFiles/common_test.dir/build.make
common/test/common_test: common/test/CMakeFiles/common_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable common_test"
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/test/CMakeFiles/common_test.dir/build: common/test/common_test
.PHONY : common/test/CMakeFiles/common_test.dir/build

common/test/CMakeFiles/common_test.dir/clean:
	cd /home/rui/datasketches/github/OnvhllTest/build/common/test && $(CMAKE_COMMAND) -P CMakeFiles/common_test.dir/cmake_clean.cmake
.PHONY : common/test/CMakeFiles/common_test.dir/clean

common/test/CMakeFiles/common_test.dir/depend:
	cd /home/rui/datasketches/github/OnvhllTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rui/datasketches/github/OnvhllTest /home/rui/datasketches/github/OnvhllTest/common/test /home/rui/datasketches/github/OnvhllTest/build /home/rui/datasketches/github/OnvhllTest/build/common/test /home/rui/datasketches/github/OnvhllTest/build/common/test/CMakeFiles/common_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/test/CMakeFiles/common_test.dir/depend
