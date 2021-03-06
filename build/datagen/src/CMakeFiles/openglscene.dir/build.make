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
include datagen/src/CMakeFiles/openglscene.dir/depend.make

# Include the progress variables for this target.
include datagen/src/CMakeFiles/openglscene.dir/progress.make

# Include the compile flags for this target's objects.
include datagen/src/CMakeFiles/openglscene.dir/flags.make

datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.o: datagen/src/CMakeFiles/openglscene.dir/flags.make
datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.o: ../datagen/src/openglwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.o"
	cd /home/eberdeed/programs/openglwindow/build/datagen/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openglscene.dir/openglwindow.cpp.o -c /home/eberdeed/programs/openglwindow/datagen/src/openglwindow.cpp

datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglscene.dir/openglwindow.cpp.i"
	cd /home/eberdeed/programs/openglwindow/build/datagen/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eberdeed/programs/openglwindow/datagen/src/openglwindow.cpp > CMakeFiles/openglscene.dir/openglwindow.cpp.i

datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglscene.dir/openglwindow.cpp.s"
	cd /home/eberdeed/programs/openglwindow/build/datagen/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eberdeed/programs/openglwindow/datagen/src/openglwindow.cpp -o CMakeFiles/openglscene.dir/openglwindow.cpp.s

# Object files for target openglscene
openglscene_OBJECTS = \
"CMakeFiles/openglscene.dir/openglwindow.cpp.o"

# External object files for target openglscene
openglscene_EXTERNAL_OBJECTS =

datagen/src/libopenglscene.so: datagen/src/CMakeFiles/openglscene.dir/openglwindow.cpp.o
datagen/src/libopenglscene.so: datagen/src/CMakeFiles/openglscene.dir/build.make
datagen/src/libopenglscene.so: datagen/assimpopengl/src/libassimpopengl.so.1.0
datagen/src/libopenglscene.so: datagen/src/CMakeFiles/openglscene.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libopenglscene.so"
	cd /home/eberdeed/programs/openglwindow/build/datagen/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openglscene.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
datagen/src/CMakeFiles/openglscene.dir/build: datagen/src/libopenglscene.so

.PHONY : datagen/src/CMakeFiles/openglscene.dir/build

datagen/src/CMakeFiles/openglscene.dir/clean:
	cd /home/eberdeed/programs/openglwindow/build/datagen/src && $(CMAKE_COMMAND) -P CMakeFiles/openglscene.dir/cmake_clean.cmake
.PHONY : datagen/src/CMakeFiles/openglscene.dir/clean

datagen/src/CMakeFiles/openglscene.dir/depend:
	cd /home/eberdeed/programs/openglwindow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eberdeed/programs/openglwindow /home/eberdeed/programs/openglwindow/datagen/src /home/eberdeed/programs/openglwindow/build /home/eberdeed/programs/openglwindow/build/datagen/src /home/eberdeed/programs/openglwindow/build/datagen/src/CMakeFiles/openglscene.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : datagen/src/CMakeFiles/openglscene.dir/depend

