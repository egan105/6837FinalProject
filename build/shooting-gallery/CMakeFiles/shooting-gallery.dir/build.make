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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.3.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.3.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ericgan/Code/6837FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ericgan/Code/6837FinalProject/build

# Include any dependencies generated for this target.
include shooting-gallery/CMakeFiles/shooting-gallery.dir/depend.make

# Include the progress variables for this target.
include shooting-gallery/CMakeFiles/shooting-gallery.dir/progress.make

# Include the compile flags for this target's objects.
include shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o: ../shooting-gallery/src/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Bullet.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Bullet.cpp > CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Bullet.cpp -o CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o


shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o: ../shooting-gallery/src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Camera.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/Camera.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Camera.cpp > CMakeFiles/shooting-gallery.dir/src/Camera.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/Camera.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Camera.cpp -o CMakeFiles/shooting-gallery.dir/src/Camera.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o


shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o: ../shooting-gallery/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/main.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/main.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/main.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/main.cpp > CMakeFiles/shooting-gallery.dir/src/main.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/main.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/main.cpp -o CMakeFiles/shooting-gallery.dir/src/main.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o


shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o: ../shooting-gallery/src/Stand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Stand.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/Stand.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Stand.cpp > CMakeFiles/shooting-gallery.dir/src/Stand.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/Stand.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Stand.cpp -o CMakeFiles/shooting-gallery.dir/src/Stand.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o


shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o: ../shooting-gallery/src/Target.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/Target.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Target.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/Target.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Target.cpp > CMakeFiles/shooting-gallery.dir/src/Target.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/Target.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/Target.cpp -o CMakeFiles/shooting-gallery.dir/src/Target.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o


shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o: shooting-gallery/CMakeFiles/shooting-gallery.dir/flags.make
shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o: ../shooting-gallery/src/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shooting-gallery.dir/src/World.cpp.o -c /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/World.cpp

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shooting-gallery.dir/src/World.cpp.i"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/World.cpp > CMakeFiles/shooting-gallery.dir/src/World.cpp.i

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shooting-gallery.dir/src/World.cpp.s"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Code/6837FinalProject/shooting-gallery/src/World.cpp -o CMakeFiles/shooting-gallery.dir/src/World.cpp.s

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.requires:

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.provides: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.requires
	$(MAKE) -f shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.provides.build
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.provides

shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.provides.build: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o


# Object files for target shooting-gallery
shooting__gallery_OBJECTS = \
"CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o" \
"CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o" \
"CMakeFiles/shooting-gallery.dir/src/main.cpp.o" \
"CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o" \
"CMakeFiles/shooting-gallery.dir/src/Target.cpp.o" \
"CMakeFiles/shooting-gallery.dir/src/World.cpp.o"

# External object files for target shooting-gallery
shooting__gallery_EXTERNAL_OBJECTS =

shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/build.make
shooting-gallery/shooting-gallery: shooting-gallery/CMakeFiles/shooting-gallery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ericgan/Code/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable shooting-gallery"
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shooting-gallery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
shooting-gallery/CMakeFiles/shooting-gallery.dir/build: shooting-gallery/shooting-gallery

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/build

shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Bullet.cpp.o.requires
shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Camera.cpp.o.requires
shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/main.cpp.o.requires
shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Stand.cpp.o.requires
shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/Target.cpp.o.requires
shooting-gallery/CMakeFiles/shooting-gallery.dir/requires: shooting-gallery/CMakeFiles/shooting-gallery.dir/src/World.cpp.o.requires

.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/requires

shooting-gallery/CMakeFiles/shooting-gallery.dir/clean:
	cd /Users/ericgan/Code/6837FinalProject/build/shooting-gallery && $(CMAKE_COMMAND) -P CMakeFiles/shooting-gallery.dir/cmake_clean.cmake
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/clean

shooting-gallery/CMakeFiles/shooting-gallery.dir/depend:
	cd /Users/ericgan/Code/6837FinalProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ericgan/Code/6837FinalProject /Users/ericgan/Code/6837FinalProject/shooting-gallery /Users/ericgan/Code/6837FinalProject/build /Users/ericgan/Code/6837FinalProject/build/shooting-gallery /Users/ericgan/Code/6837FinalProject/build/shooting-gallery/CMakeFiles/shooting-gallery.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shooting-gallery/CMakeFiles/shooting-gallery.dir/depend

