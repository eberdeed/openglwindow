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
include openglwindow/src/CMakeFiles/openglwindow.dir/depend.make

# Include the progress variables for this target.
include openglwindow/src/CMakeFiles/openglwindow.dir/progress.make

# Include the compile flags for this target's objects.
include openglwindow/src/CMakeFiles/openglwindow.dir/flags.make

openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.o: openglwindow/src/CMakeFiles/openglwindow.dir/flags.make
openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.o: ../openglwindow/src/windowspawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.o"
	cd /home/eberdeed/programs/openglwindow/build/openglwindow/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openglwindow.dir/windowspawn.cpp.o -c /home/eberdeed/programs/openglwindow/openglwindow/src/windowspawn.cpp

openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglwindow.dir/windowspawn.cpp.i"
	cd /home/eberdeed/programs/openglwindow/build/openglwindow/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eberdeed/programs/openglwindow/openglwindow/src/windowspawn.cpp > CMakeFiles/openglwindow.dir/windowspawn.cpp.i

openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglwindow.dir/windowspawn.cpp.s"
	cd /home/eberdeed/programs/openglwindow/build/openglwindow/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eberdeed/programs/openglwindow/openglwindow/src/windowspawn.cpp -o CMakeFiles/openglwindow.dir/windowspawn.cpp.s

# Object files for target openglwindow
openglwindow_OBJECTS = \
"CMakeFiles/openglwindow.dir/windowspawn.cpp.o"

# External object files for target openglwindow
openglwindow_EXTERNAL_OBJECTS =

openglwindow/src/openglwindow: openglwindow/src/CMakeFiles/openglwindow.dir/windowspawn.cpp.o
openglwindow/src/openglwindow: openglwindow/src/CMakeFiles/openglwindow.dir/build.make
openglwindow/src/openglwindow: datagen/src/libopenglscene.so
openglwindow/src/openglwindow: datagen/assimpopengl/src/libassimpopengl.so.1.0
openglwindow/src/openglwindow: openglwindow/src/CMakeFiles/openglwindow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable openglwindow"
	cd /home/eberdeed/programs/openglwindow/build/openglwindow/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openglwindow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openglwindow/src/CMakeFiles/openglwindow.dir/build: openglwindow/src/openglwindow

.PHONY : openglwindow/src/CMakeFiles/openglwindow.dir/build

openglwindow/src/CMakeFiles/openglwindow.dir/clean:
	cd /home/eberdeed/programs/openglwindow/build/openglwindow/src && $(CMAKE_COMMAND) -P CMakeFiles/openglwindow.dir/cmake_clean.cmake
.PHONY : openglwindow/src/CMakeFiles/openglwindow.dir/clean

openglwindow/src/CMakeFiles/openglwindow.dir/depend:
	cd /home/eberdeed/programs/openglwindow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eberdeed/programs/openglwindow /home/eberdeed/programs/openglwindow/openglwindow/src /home/eberdeed/programs/openglwindow/build /home/eberdeed/programs/openglwindow/build/openglwindow/src /home/eberdeed/programs/openglwindow/build/openglwindow/src/CMakeFiles/openglwindow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openglwindow/src/CMakeFiles/openglwindow.dir/depend
