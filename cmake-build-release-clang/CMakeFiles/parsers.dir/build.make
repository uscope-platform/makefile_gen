# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /snap/clion/248/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/248/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fils/git/makefilegen_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fils/git/makefilegen_v2/cmake-build-release-clang

# Utility rule file for parsers.

# Include any custom commands dependencies for this target.
include CMakeFiles/parsers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parsers.dir/progress.make

parsers: CMakeFiles/parsers.dir/build.make
.PHONY : parsers

# Rule to build all files generated by this target.
CMakeFiles/parsers.dir/build: parsers
.PHONY : CMakeFiles/parsers.dir/build

CMakeFiles/parsers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parsers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parsers.dir/clean

CMakeFiles/parsers.dir/depend:
	cd /home/fils/git/makefilegen_v2/cmake-build-release-clang && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fils/git/makefilegen_v2 /home/fils/git/makefilegen_v2 /home/fils/git/makefilegen_v2/cmake-build-release-clang /home/fils/git/makefilegen_v2/cmake-build-release-clang /home/fils/git/makefilegen_v2/cmake-build-release-clang/CMakeFiles/parsers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parsers.dir/depend

