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
CMAKE_COMMAND = /private/var/folders/0r/c545811d30338l9b7lb33pzw0000gn/T/AppTranslocation/D56EC948-7475-49E3-BC15-8E69684F51C8/d/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /private/var/folders/0r/c545811d30338l9b7lb33pzw0000gn/T/AppTranslocation/D56EC948-7475-49E3-BC15-8E69684F51C8/d/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build

# Utility rule file for antlr4_runtime-build_static.

# Include any custom commands dependencies for this target.
include CMakeFiles/antlr4_runtime-build_static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/antlr4_runtime-build_static.dir/progress.make

CMakeFiles/antlr4_runtime-build_static: antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static

antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Performing build_static step for 'antlr4_runtime'"
	cd /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build/antlr4_runtime/src/antlr4_runtime/runtime/Cpp && $(MAKE) antlr4_static
	cd /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build/antlr4_runtime/src/antlr4_runtime/runtime/Cpp && /private/var/folders/0r/c545811d30338l9b7lb33pzw0000gn/T/AppTranslocation/D56EC948-7475-49E3-BC15-8E69684F51C8/d/CMake.app/Contents/bin/cmake -E touch /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build/antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static

antlr4_runtime-build_static: CMakeFiles/antlr4_runtime-build_static
antlr4_runtime-build_static: antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static
antlr4_runtime-build_static: CMakeFiles/antlr4_runtime-build_static.dir/build.make
.PHONY : antlr4_runtime-build_static

# Rule to build all files generated by this target.
CMakeFiles/antlr4_runtime-build_static.dir/build: antlr4_runtime-build_static
.PHONY : CMakeFiles/antlr4_runtime-build_static.dir/build

CMakeFiles/antlr4_runtime-build_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/antlr4_runtime-build_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/antlr4_runtime-build_static.dir/clean

CMakeFiles/antlr4_runtime-build_static.dir/depend:
	cd /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/build/CMakeFiles/antlr4_runtime-build_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/antlr4_runtime-build_static.dir/depend

