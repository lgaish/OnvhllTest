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
include count/test/CMakeFiles/count_min_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include count/test/CMakeFiles/count_min_test.dir/compiler_depend.make

# Include the progress variables for this target.
include count/test/CMakeFiles/count_min_test.dir/progress.make

# Include the compile flags for this target's objects.
include count/test/CMakeFiles/count_min_test.dir/flags.make

count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o: count/test/CMakeFiles/count_min_test.dir/flags.make
count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o: ../count/test/count_min_test.cpp
count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o: count/test/CMakeFiles/count_min_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o -MF CMakeFiles/count_min_test.dir/count_min_test.cpp.o.d -o CMakeFiles/count_min_test.dir/count_min_test.cpp.o -c /home/rui/datasketches/github/OnvhllTest/count/test/count_min_test.cpp

count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/count_min_test.dir/count_min_test.cpp.i"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rui/datasketches/github/OnvhllTest/count/test/count_min_test.cpp > CMakeFiles/count_min_test.dir/count_min_test.cpp.i

count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/count_min_test.dir/count_min_test.cpp.s"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rui/datasketches/github/OnvhllTest/count/test/count_min_test.cpp -o CMakeFiles/count_min_test.dir/count_min_test.cpp.s

count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o: count/test/CMakeFiles/count_min_test.dir/flags.make
count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o: ../count/test/count_min_allocation_test.cpp
count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o: count/test/CMakeFiles/count_min_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o -MF CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o.d -o CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o -c /home/rui/datasketches/github/OnvhllTest/count/test/count_min_allocation_test.cpp

count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.i"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rui/datasketches/github/OnvhllTest/count/test/count_min_allocation_test.cpp > CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.i

count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.s"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rui/datasketches/github/OnvhllTest/count/test/count_min_allocation_test.cpp -o CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.s

# Object files for target count_min_test
count_min_test_OBJECTS = \
"CMakeFiles/count_min_test.dir/count_min_test.cpp.o" \
"CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o"

# External object files for target count_min_test
count_min_test_EXTERNAL_OBJECTS = \
"/home/rui/datasketches/github/OnvhllTest/build/common/test/CMakeFiles/common_test_lib.dir/catch_runner.cpp.o" \
"/home/rui/datasketches/github/OnvhllTest/build/common/test/CMakeFiles/common_test_lib.dir/test_allocator.cpp.o"

count/test/count_min_test: count/test/CMakeFiles/count_min_test.dir/count_min_test.cpp.o
count/test/count_min_test: count/test/CMakeFiles/count_min_test.dir/count_min_allocation_test.cpp.o
count/test/count_min_test: common/test/CMakeFiles/common_test_lib.dir/catch_runner.cpp.o
count/test/count_min_test: common/test/CMakeFiles/common_test_lib.dir/test_allocator.cpp.o
count/test/count_min_test: count/test/CMakeFiles/count_min_test.dir/build.make
count/test/count_min_test: count/test/CMakeFiles/count_min_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rui/datasketches/github/OnvhllTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable count_min_test"
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/count_min_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
count/test/CMakeFiles/count_min_test.dir/build: count/test/count_min_test
.PHONY : count/test/CMakeFiles/count_min_test.dir/build

count/test/CMakeFiles/count_min_test.dir/clean:
	cd /home/rui/datasketches/github/OnvhllTest/build/count/test && $(CMAKE_COMMAND) -P CMakeFiles/count_min_test.dir/cmake_clean.cmake
.PHONY : count/test/CMakeFiles/count_min_test.dir/clean

count/test/CMakeFiles/count_min_test.dir/depend:
	cd /home/rui/datasketches/github/OnvhllTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rui/datasketches/github/OnvhllTest /home/rui/datasketches/github/OnvhllTest/count/test /home/rui/datasketches/github/OnvhllTest/build /home/rui/datasketches/github/OnvhllTest/build/count/test /home/rui/datasketches/github/OnvhllTest/build/count/test/CMakeFiles/count_min_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : count/test/CMakeFiles/count_min_test.dir/depend

