# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build

# Include any dependencies generated for this target.
include sparks/CMakeFiles/sparks.dir/depend.make

# Include the progress variables for this target.
include sparks/CMakeFiles/sparks.dir/progress.make

# Include the compile flags for this target's objects.
include sparks/CMakeFiles/sparks.dir/flags.make

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o: sparks/CMakeFiles/sparks.dir/flags.make
sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o: ../sparks/src/sparks.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o"
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sparks.dir/src/sparks.cpp.o -c /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/sparks/src/sparks.cpp

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sparks.dir/src/sparks.cpp.i"
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/sparks/src/sparks.cpp > CMakeFiles/sparks.dir/src/sparks.cpp.i

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sparks.dir/src/sparks.cpp.s"
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/sparks/src/sparks.cpp -o CMakeFiles/sparks.dir/src/sparks.cpp.s

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.requires:
.PHONY : sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.requires

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.provides: sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.requires
	$(MAKE) -f sparks/CMakeFiles/sparks.dir/build.make sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.provides.build
.PHONY : sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.provides

sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.provides.build: sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o

# Object files for target sparks
sparks_OBJECTS = \
"CMakeFiles/sparks.dir/src/sparks.cpp.o"

# External object files for target sparks
sparks_EXTERNAL_OBJECTS =

sparks/sparks: sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o
sparks/sparks: sparks/CMakeFiles/sparks.dir/build.make
sparks/sparks: /usr/lib/x86_64-linux-gnu/libglut.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libXmu.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libXi.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libGLU.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libGL.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libSM.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libICE.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libX11.so
sparks/sparks: /usr/lib/x86_64-linux-gnu/libXext.so
sparks/sparks: sparks/CMakeFiles/sparks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sparks"
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sparks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sparks/CMakeFiles/sparks.dir/build: sparks/sparks
.PHONY : sparks/CMakeFiles/sparks.dir/build

sparks/CMakeFiles/sparks.dir/requires: sparks/CMakeFiles/sparks.dir/src/sparks.cpp.o.requires
.PHONY : sparks/CMakeFiles/sparks.dir/requires

sparks/CMakeFiles/sparks.dir/clean:
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks && $(CMAKE_COMMAND) -P CMakeFiles/sparks.dir/cmake_clean.cmake
.PHONY : sparks/CMakeFiles/sparks.dir/clean

sparks/CMakeFiles/sparks.dir/depend:
	cd /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/sparks /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks /afs/athena.mit.edu/user/s/a/samueli/Downloads/opengl-play-master/build/sparks/CMakeFiles/sparks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sparks/CMakeFiles/sparks.dir/depend

