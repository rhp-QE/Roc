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
CMAKE_SOURCE_DIR = /root/project/roc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/project/roc/build

# Include any dependencies generated for this target.
include CMakeFiles/roc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/roc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/roc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roc.dir/flags.make

CMakeFiles/roc.dir/main.cpp.o: CMakeFiles/roc.dir/flags.make
CMakeFiles/roc.dir/main.cpp.o: ../main.cpp
CMakeFiles/roc.dir/main.cpp.o: CMakeFiles/roc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/project/roc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roc.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/roc.dir/main.cpp.o -MF CMakeFiles/roc.dir/main.cpp.o.d -o CMakeFiles/roc.dir/main.cpp.o -c /root/project/roc/main.cpp

CMakeFiles/roc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roc.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/roc/main.cpp > CMakeFiles/roc.dir/main.cpp.i

CMakeFiles/roc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roc.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/roc/main.cpp -o CMakeFiles/roc.dir/main.cpp.s

CMakeFiles/roc.dir/test.cpp.o: CMakeFiles/roc.dir/flags.make
CMakeFiles/roc.dir/test.cpp.o: ../test.cpp
CMakeFiles/roc.dir/test.cpp.o: CMakeFiles/roc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/project/roc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/roc.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/roc.dir/test.cpp.o -MF CMakeFiles/roc.dir/test.cpp.o.d -o CMakeFiles/roc.dir/test.cpp.o -c /root/project/roc/test.cpp

CMakeFiles/roc.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roc.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/roc/test.cpp > CMakeFiles/roc.dir/test.cpp.i

CMakeFiles/roc.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roc.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/roc/test.cpp -o CMakeFiles/roc.dir/test.cpp.s

# Object files for target roc
roc_OBJECTS = \
"CMakeFiles/roc.dir/main.cpp.o" \
"CMakeFiles/roc.dir/test.cpp.o"

# External object files for target roc
roc_EXTERNAL_OBJECTS =

roc: CMakeFiles/roc.dir/main.cpp.o
roc: CMakeFiles/roc.dir/test.cpp.o
roc: CMakeFiles/roc.dir/build.make
roc: /root/tools/vcpkg/installed/x64-linux/debug/lib/libglog.a
roc: /root/tools/vcpkg/installed/x64-linux/debug/lib/libgflags_debug.a
roc: CMakeFiles/roc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/project/roc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable roc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roc.dir/build: roc
.PHONY : CMakeFiles/roc.dir/build

CMakeFiles/roc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roc.dir/clean

CMakeFiles/roc.dir/depend:
	cd /root/project/roc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/project/roc /root/project/roc /root/project/roc/build /root/project/roc/build /root/project/roc/build/CMakeFiles/roc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roc.dir/depend

