# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.3.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.3.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tcheyne/6.837/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tcheyne/6.837/test/build

# Include any dependencies generated for this target.
include vecmath/CMakeFiles/vecmath.dir/depend.make

# Include the progress variables for this target.
include vecmath/CMakeFiles/vecmath.dir/progress.make

# Include the compile flags for this target's objects.
include vecmath/CMakeFiles/vecmath.dir/flags.make

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o: ../vecmath/src/Matrix2f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Matrix2f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Matrix2f.cpp > CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Matrix2f.cpp -o CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o: ../vecmath/src/Matrix3f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Matrix3f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Matrix3f.cpp > CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Matrix3f.cpp -o CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o: ../vecmath/src/Matrix4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Matrix4f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Matrix4f.cpp > CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Matrix4f.cpp -o CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o: ../vecmath/src/Quat4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Quat4f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Quat4f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Quat4f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Quat4f.cpp > CMakeFiles/vecmath.dir/src/Quat4f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Quat4f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Quat4f.cpp -o CMakeFiles/vecmath.dir/src/Quat4f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o: ../vecmath/src/Vector2f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector2f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Vector2f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector2f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Vector2f.cpp > CMakeFiles/vecmath.dir/src/Vector2f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector2f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Vector2f.cpp -o CMakeFiles/vecmath.dir/src/Vector2f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o: ../vecmath/src/Vector3f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector3f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Vector3f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector3f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Vector3f.cpp > CMakeFiles/vecmath.dir/src/Vector3f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector3f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Vector3f.cpp -o CMakeFiles/vecmath.dir/src/Vector3f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o


vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o: vecmath/CMakeFiles/vecmath.dir/flags.make
vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o: ../vecmath/src/Vector4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector4f.cpp.o -c /Users/tcheyne/6.837/test/vecmath/src/Vector4f.cpp

vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector4f.cpp.i"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/tcheyne/6.837/test/vecmath/src/Vector4f.cpp > CMakeFiles/vecmath.dir/src/Vector4f.cpp.i

vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector4f.cpp.s"
	cd /Users/tcheyne/6.837/test/build/vecmath && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/tcheyne/6.837/test/vecmath/src/Vector4f.cpp -o CMakeFiles/vecmath.dir/src/Vector4f.cpp.s

vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.requires:

.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.requires

vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.provides: vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.requires
	$(MAKE) -f vecmath/CMakeFiles/vecmath.dir/build.make vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.provides.build
.PHONY : vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.provides

vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.provides.build: vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o


# Object files for target vecmath
vecmath_OBJECTS = \
"CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Quat4f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector2f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector3f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector4f.cpp.o"

# External object files for target vecmath
vecmath_EXTERNAL_OBJECTS =

vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/build.make
vecmath/libvecmath.a: vecmath/CMakeFiles/vecmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tcheyne/6.837/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libvecmath.a"
	cd /Users/tcheyne/6.837/test/build/vecmath && $(CMAKE_COMMAND) -P CMakeFiles/vecmath.dir/cmake_clean_target.cmake
	cd /Users/tcheyne/6.837/test/build/vecmath && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vecmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vecmath/CMakeFiles/vecmath.dir/build: vecmath/libvecmath.a

.PHONY : vecmath/CMakeFiles/vecmath.dir/build

vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o.requires
vecmath/CMakeFiles/vecmath.dir/requires: vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o.requires

.PHONY : vecmath/CMakeFiles/vecmath.dir/requires

vecmath/CMakeFiles/vecmath.dir/clean:
	cd /Users/tcheyne/6.837/test/build/vecmath && $(CMAKE_COMMAND) -P CMakeFiles/vecmath.dir/cmake_clean.cmake
.PHONY : vecmath/CMakeFiles/vecmath.dir/clean

vecmath/CMakeFiles/vecmath.dir/depend:
	cd /Users/tcheyne/6.837/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tcheyne/6.837/test /Users/tcheyne/6.837/test/vecmath /Users/tcheyne/6.837/test/build /Users/tcheyne/6.837/test/build/vecmath /Users/tcheyne/6.837/test/build/vecmath/CMakeFiles/vecmath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vecmath/CMakeFiles/vecmath.dir/depend
