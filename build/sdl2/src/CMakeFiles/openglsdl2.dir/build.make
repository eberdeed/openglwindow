# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eberdeed/programs/openglwindow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eberdeed/programs/openglwindow/build

# Include any dependencies generated for this target.
include sdl2/src/CMakeFiles/openglsdl2.dir/depend.make

# Include the progress variables for this target.
include sdl2/src/CMakeFiles/openglsdl2.dir/progress.make

# Include the compile flags for this target's objects.
include sdl2/src/CMakeFiles/openglsdl2.dir/flags.make

sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o: sdl2/src/CMakeFiles/openglsdl2.dir/flags.make
sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o: ../sdl2/src/openglsdl2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o"
	cd /home/eberdeed/programs/openglwindow/build/sdl2/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o -c /home/eberdeed/programs/openglwindow/sdl2/src/openglsdl2.cpp

sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglsdl2.dir/openglsdl2.cpp.i"
	cd /home/eberdeed/programs/openglwindow/build/sdl2/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eberdeed/programs/openglwindow/sdl2/src/openglsdl2.cpp > CMakeFiles/openglsdl2.dir/openglsdl2.cpp.i

sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglsdl2.dir/openglsdl2.cpp.s"
	cd /home/eberdeed/programs/openglwindow/build/sdl2/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eberdeed/programs/openglwindow/sdl2/src/openglsdl2.cpp -o CMakeFiles/openglsdl2.dir/openglsdl2.cpp.s

# Object files for target openglsdl2
openglsdl2_OBJECTS = \
"CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o"

# External object files for target openglsdl2
openglsdl2_EXTERNAL_OBJECTS =

sdl2/src/openglsdl2: sdl2/src/CMakeFiles/openglsdl2.dir/openglsdl2.cpp.o
sdl2/src/openglsdl2: sdl2/src/CMakeFiles/openglsdl2.dir/build.make
sdl2/src/openglsdl2: datagen/src/libopenglscene.so
sdl2/src/openglsdl2: datagen/assimpopengl/src/libassimpopengl.so.1.0
sdl2/src/openglsdl2: sdl2/src/CMakeFiles/openglsdl2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable openglsdl2"
	cd /home/eberdeed/programs/openglwindow/build/sdl2/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openglsdl2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdl2/src/CMakeFiles/openglsdl2.dir/build: sdl2/src/openglsdl2

.PHONY : sdl2/src/CMakeFiles/openglsdl2.dir/build

sdl2/src/CMakeFiles/openglsdl2.dir/clean:
	cd /home/eberdeed/programs/openglwindow/build/sdl2/src && $(CMAKE_COMMAND) -P CMakeFiles/openglsdl2.dir/cmake_clean.cmake
.PHONY : sdl2/src/CMakeFiles/openglsdl2.dir/clean

sdl2/src/CMakeFiles/openglsdl2.dir/depend:
	cd /home/eberdeed/programs/openglwindow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eberdeed/programs/openglwindow /home/eberdeed/programs/openglwindow/sdl2/src /home/eberdeed/programs/openglwindow/build /home/eberdeed/programs/openglwindow/build/sdl2/src /home/eberdeed/programs/openglwindow/build/sdl2/src/CMakeFiles/openglsdl2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdl2/src/CMakeFiles/openglsdl2.dir/depend

