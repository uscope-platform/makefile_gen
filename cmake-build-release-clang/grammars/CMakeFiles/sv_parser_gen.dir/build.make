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

# Utility rule file for sv_parser_gen.

# Include any custom commands dependencies for this target.
include grammars/CMakeFiles/sv_parser_gen.dir/compiler_depend.make

# Include the progress variables for this target.
include grammars/CMakeFiles/sv_parser_gen.dir/progress.make

grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.h
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.h
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.h
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.h
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.cpp
grammars/CMakeFiles/sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.h

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h: /home/fils/git/makefilegen_v2/grammars/sv2017.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fils/git/makefilegen_v2/cmake-build-release-clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "generating sources for System Verilog parser"
	cd /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars && java -cp /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar/antlr-4.11.1-complete.jar org.antlr.v4.Tool -package mgp_sv -Dlanguage=Cpp -visitor -listener -encoding iso-8859-1 -o /home/fils/git/makefilegen_v2/includes/mgp_sv /home/fils/git/makefilegen_v2/grammars/sv2017.g4
	cd /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars && java -cp /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar/antlr-4.11.1-complete.jar org.antlr.v4.Tool -package mgp_sv -Dlanguage=Cpp -visitor -listener -encoding iso-8859-1 -o /home/fils/git/makefilegen_v2/includes/mgp_sv /home/fils/git/makefilegen_v2/grammars/sv2017Lexer.g4

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.h: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.h

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.h: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.h

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.h: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.h

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.h: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.h

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.cpp: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.cpp

/home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.h: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
	@$(CMAKE_COMMAND) -E touch_nocreate /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.h

sv_parser_gen: grammars/CMakeFiles/sv_parser_gen
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017.h
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseListener.h
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017BaseVisitor.h
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Lexer.h
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Listener.h
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.cpp
sv_parser_gen: /home/fils/git/makefilegen_v2/src/includes/mgp_sv/sv2017Visitor.h
sv_parser_gen: grammars/CMakeFiles/sv_parser_gen.dir/build.make
.PHONY : sv_parser_gen

# Rule to build all files generated by this target.
grammars/CMakeFiles/sv_parser_gen.dir/build: sv_parser_gen
.PHONY : grammars/CMakeFiles/sv_parser_gen.dir/build

grammars/CMakeFiles/sv_parser_gen.dir/clean:
	cd /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars && $(CMAKE_COMMAND) -P CMakeFiles/sv_parser_gen.dir/cmake_clean.cmake
.PHONY : grammars/CMakeFiles/sv_parser_gen.dir/clean

grammars/CMakeFiles/sv_parser_gen.dir/depend:
	cd /home/fils/git/makefilegen_v2/cmake-build-release-clang && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fils/git/makefilegen_v2 /home/fils/git/makefilegen_v2/grammars /home/fils/git/makefilegen_v2/cmake-build-release-clang /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars /home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/CMakeFiles/sv_parser_gen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : grammars/CMakeFiles/sv_parser_gen.dir/depend

