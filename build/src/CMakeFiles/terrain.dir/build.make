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
CMAKE_SOURCE_DIR = /Users/ericgan/Documents/6837FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ericgan/Documents/6837FinalProject/build

# Include any dependencies generated for this target.
include src/CMakeFiles/terrain.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/terrain.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/terrain.dir/flags.make

src/CMakeFiles/terrain.dir/main.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/terrain.dir/main.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/main.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/main.cpp

src/CMakeFiles/terrain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/main.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/main.cpp > CMakeFiles/terrain.dir/main.cpp.i

src/CMakeFiles/terrain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/main.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/main.cpp -o CMakeFiles/terrain.dir/main.cpp.s

src/CMakeFiles/terrain.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/main.cpp.o.requires

src/CMakeFiles/terrain.dir/main.cpp.o.provides: src/CMakeFiles/terrain.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/main.cpp.o.provides

src/CMakeFiles/terrain.dir/main.cpp.o.provides.build: src/CMakeFiles/terrain.dir/main.cpp.o


src/CMakeFiles/terrain.dir/Bullet.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/Bullet.cpp.o: ../src/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/terrain.dir/Bullet.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/Bullet.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/Bullet.cpp

src/CMakeFiles/terrain.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/Bullet.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/Bullet.cpp > CMakeFiles/terrain.dir/Bullet.cpp.i

src/CMakeFiles/terrain.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/Bullet.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/Bullet.cpp -o CMakeFiles/terrain.dir/Bullet.cpp.s

src/CMakeFiles/terrain.dir/Bullet.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/Bullet.cpp.o.requires

src/CMakeFiles/terrain.dir/Bullet.cpp.o.provides: src/CMakeFiles/terrain.dir/Bullet.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/Bullet.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/Bullet.cpp.o.provides

src/CMakeFiles/terrain.dir/Bullet.cpp.o.provides.build: src/CMakeFiles/terrain.dir/Bullet.cpp.o


src/CMakeFiles/terrain.dir/Camera.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/terrain.dir/Camera.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/Camera.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/Camera.cpp

src/CMakeFiles/terrain.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/Camera.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/Camera.cpp > CMakeFiles/terrain.dir/Camera.cpp.i

src/CMakeFiles/terrain.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/Camera.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/Camera.cpp -o CMakeFiles/terrain.dir/Camera.cpp.s

src/CMakeFiles/terrain.dir/Camera.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/Camera.cpp.o.requires

src/CMakeFiles/terrain.dir/Camera.cpp.o.provides: src/CMakeFiles/terrain.dir/Camera.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/Camera.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/Camera.cpp.o.provides

src/CMakeFiles/terrain.dir/Camera.cpp.o.provides.build: src/CMakeFiles/terrain.dir/Camera.cpp.o


src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o: ../src/FirstPersonCamera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/FirstPersonCamera.cpp

src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/FirstPersonCamera.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/FirstPersonCamera.cpp > CMakeFiles/terrain.dir/FirstPersonCamera.cpp.i

src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/FirstPersonCamera.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/FirstPersonCamera.cpp -o CMakeFiles/terrain.dir/FirstPersonCamera.cpp.s

src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.requires

src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.provides: src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.provides

src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.provides.build: src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o


src/CMakeFiles/terrain.dir/Generator.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/Generator.cpp.o: ../src/Generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/terrain.dir/Generator.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/Generator.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/Generator.cpp

src/CMakeFiles/terrain.dir/Generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/Generator.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/Generator.cpp > CMakeFiles/terrain.dir/Generator.cpp.i

src/CMakeFiles/terrain.dir/Generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/Generator.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/Generator.cpp -o CMakeFiles/terrain.dir/Generator.cpp.s

src/CMakeFiles/terrain.dir/Generator.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/Generator.cpp.o.requires

src/CMakeFiles/terrain.dir/Generator.cpp.o.provides: src/CMakeFiles/terrain.dir/Generator.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/Generator.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/Generator.cpp.o.provides

src/CMakeFiles/terrain.dir/Generator.cpp.o.provides.build: src/CMakeFiles/terrain.dir/Generator.cpp.o


src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o: ../src/ParticleSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/ParticleSystem.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/ParticleSystem.cpp

src/CMakeFiles/terrain.dir/ParticleSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/ParticleSystem.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/ParticleSystem.cpp > CMakeFiles/terrain.dir/ParticleSystem.cpp.i

src/CMakeFiles/terrain.dir/ParticleSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/ParticleSystem.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/ParticleSystem.cpp -o CMakeFiles/terrain.dir/ParticleSystem.cpp.s

src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.requires

src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.provides: src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.provides

src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.provides.build: src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o


src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o: ../src/ProceduralBlock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/ProceduralBlock.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/ProceduralBlock.cpp

src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/ProceduralBlock.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/ProceduralBlock.cpp > CMakeFiles/terrain.dir/ProceduralBlock.cpp.i

src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/ProceduralBlock.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/ProceduralBlock.cpp -o CMakeFiles/terrain.dir/ProceduralBlock.cpp.s

src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.requires

src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.provides: src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.provides

src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.provides.build: src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o


src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o: ../src/ProceduralWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/ProceduralWorld.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/ProceduralWorld.cpp

src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/ProceduralWorld.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/ProceduralWorld.cpp > CMakeFiles/terrain.dir/ProceduralWorld.cpp.i

src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/ProceduralWorld.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/ProceduralWorld.cpp -o CMakeFiles/terrain.dir/ProceduralWorld.cpp.s

src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.requires

src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.provides: src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.provides

src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.provides.build: src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o


src/CMakeFiles/terrain.dir/Stand.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/Stand.cpp.o: ../src/Stand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/terrain.dir/Stand.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/Stand.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/Stand.cpp

src/CMakeFiles/terrain.dir/Stand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/Stand.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/Stand.cpp > CMakeFiles/terrain.dir/Stand.cpp.i

src/CMakeFiles/terrain.dir/Stand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/Stand.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/Stand.cpp -o CMakeFiles/terrain.dir/Stand.cpp.s

src/CMakeFiles/terrain.dir/Stand.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/Stand.cpp.o.requires

src/CMakeFiles/terrain.dir/Stand.cpp.o.provides: src/CMakeFiles/terrain.dir/Stand.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/Stand.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/Stand.cpp.o.provides

src/CMakeFiles/terrain.dir/Stand.cpp.o.provides.build: src/CMakeFiles/terrain.dir/Stand.cpp.o


src/CMakeFiles/terrain.dir/Target.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/Target.cpp.o: ../src/Target.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/terrain.dir/Target.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/Target.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/Target.cpp

src/CMakeFiles/terrain.dir/Target.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/Target.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/Target.cpp > CMakeFiles/terrain.dir/Target.cpp.i

src/CMakeFiles/terrain.dir/Target.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/Target.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/Target.cpp -o CMakeFiles/terrain.dir/Target.cpp.s

src/CMakeFiles/terrain.dir/Target.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/Target.cpp.o.requires

src/CMakeFiles/terrain.dir/Target.cpp.o.provides: src/CMakeFiles/terrain.dir/Target.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/Target.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/Target.cpp.o.provides

src/CMakeFiles/terrain.dir/Target.cpp.o.provides.build: src/CMakeFiles/terrain.dir/Target.cpp.o


src/CMakeFiles/terrain.dir/World.cpp.o: src/CMakeFiles/terrain.dir/flags.make
src/CMakeFiles/terrain.dir/World.cpp.o: ../src/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/terrain.dir/World.cpp.o"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/terrain.dir/World.cpp.o -c /Users/ericgan/Documents/6837FinalProject/src/World.cpp

src/CMakeFiles/terrain.dir/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terrain.dir/World.cpp.i"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ericgan/Documents/6837FinalProject/src/World.cpp > CMakeFiles/terrain.dir/World.cpp.i

src/CMakeFiles/terrain.dir/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terrain.dir/World.cpp.s"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ericgan/Documents/6837FinalProject/src/World.cpp -o CMakeFiles/terrain.dir/World.cpp.s

src/CMakeFiles/terrain.dir/World.cpp.o.requires:

.PHONY : src/CMakeFiles/terrain.dir/World.cpp.o.requires

src/CMakeFiles/terrain.dir/World.cpp.o.provides: src/CMakeFiles/terrain.dir/World.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/terrain.dir/build.make src/CMakeFiles/terrain.dir/World.cpp.o.provides.build
.PHONY : src/CMakeFiles/terrain.dir/World.cpp.o.provides

src/CMakeFiles/terrain.dir/World.cpp.o.provides.build: src/CMakeFiles/terrain.dir/World.cpp.o


# Object files for target terrain
terrain_OBJECTS = \
"CMakeFiles/terrain.dir/main.cpp.o" \
"CMakeFiles/terrain.dir/Bullet.cpp.o" \
"CMakeFiles/terrain.dir/Camera.cpp.o" \
"CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o" \
"CMakeFiles/terrain.dir/Generator.cpp.o" \
"CMakeFiles/terrain.dir/ParticleSystem.cpp.o" \
"CMakeFiles/terrain.dir/ProceduralBlock.cpp.o" \
"CMakeFiles/terrain.dir/ProceduralWorld.cpp.o" \
"CMakeFiles/terrain.dir/Stand.cpp.o" \
"CMakeFiles/terrain.dir/Target.cpp.o" \
"CMakeFiles/terrain.dir/World.cpp.o"

# External object files for target terrain
terrain_EXTERNAL_OBJECTS =

src/terrain: src/CMakeFiles/terrain.dir/main.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/Bullet.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/Camera.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/Generator.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/Stand.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/Target.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/World.cpp.o
src/terrain: src/CMakeFiles/terrain.dir/build.make
src/terrain: vecmath/libvecmath.a
src/terrain: src/CMakeFiles/terrain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ericgan/Documents/6837FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable terrain"
	cd /Users/ericgan/Documents/6837FinalProject/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/terrain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/terrain.dir/build: src/terrain

.PHONY : src/CMakeFiles/terrain.dir/build

src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/main.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/Bullet.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/Camera.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/FirstPersonCamera.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/Generator.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/ParticleSystem.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/ProceduralBlock.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/ProceduralWorld.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/Stand.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/Target.cpp.o.requires
src/CMakeFiles/terrain.dir/requires: src/CMakeFiles/terrain.dir/World.cpp.o.requires

.PHONY : src/CMakeFiles/terrain.dir/requires

src/CMakeFiles/terrain.dir/clean:
	cd /Users/ericgan/Documents/6837FinalProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/terrain.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/terrain.dir/clean

src/CMakeFiles/terrain.dir/depend:
	cd /Users/ericgan/Documents/6837FinalProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ericgan/Documents/6837FinalProject /Users/ericgan/Documents/6837FinalProject/src /Users/ericgan/Documents/6837FinalProject/build /Users/ericgan/Documents/6837FinalProject/build/src /Users/ericgan/Documents/6837FinalProject/build/src/CMakeFiles/terrain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/terrain.dir/depend

