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
include glfw3/src/CMakeFiles/openglglfw3.dir/depend.make

# Include the progress variables for this target.
include glfw3/src/CMakeFiles/openglglfw3.dir/progress.make

# Include the compile flags for this target's objects.
include glfw3/src/CMakeFiles/openglglfw3.dir/flags.make

glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o: glfw3/src/CMakeFiles/openglglfw3.dir/flags.make
glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o: ../glfw3/src/openglglfw3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o -c /home/eberdeed/programs/openglwindow/glfw3/src/openglglfw3.cpp

glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglglfw3.dir/openglglfw3.cpp.i"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eberdeed/programs/openglwindow/glfw3/src/openglglfw3.cpp > CMakeFiles/openglglfw3.dir/openglglfw3.cpp.i

glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglglfw3.dir/openglglfw3.cpp.s"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eberdeed/programs/openglwindow/glfw3/src/openglglfw3.cpp -o CMakeFiles/openglglfw3.dir/openglglfw3.cpp.s

glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.o: glfw3/src/CMakeFiles/openglglfw3.dir/flags.make
glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.o: ../glfw3/src/threadcreate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.o"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openglglfw3.dir/threadcreate.cpp.o -c /home/eberdeed/programs/openglwindow/glfw3/src/threadcreate.cpp

glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglglfw3.dir/threadcreate.cpp.i"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eberdeed/programs/openglwindow/glfw3/src/threadcreate.cpp > CMakeFiles/openglglfw3.dir/threadcreate.cpp.i

glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglglfw3.dir/threadcreate.cpp.s"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eberdeed/programs/openglwindow/glfw3/src/threadcreate.cpp -o CMakeFiles/openglglfw3.dir/threadcreate.cpp.s

# Object files for target openglglfw3
openglglfw3_OBJECTS = \
"CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o" \
"CMakeFiles/openglglfw3.dir/threadcreate.cpp.o"

# External object files for target openglglfw3
openglglfw3_EXTERNAL_OBJECTS =

glfw3/src/openglglfw3: glfw3/src/CMakeFiles/openglglfw3.dir/openglglfw3.cpp.o
glfw3/src/openglglfw3: glfw3/src/CMakeFiles/openglglfw3.dir/threadcreate.cpp.o
glfw3/src/openglglfw3: glfw3/src/CMakeFiles/openglglfw3.dir/build.make
glfw3/src/openglglfw3: datagen/src/libopenglscene.so
glfw3/src/openglglfw3: datagen/assimpopengl/src/libassimpopengl.so.1.0
glfw3/src/openglglfw3: glfw3/src/CMakeFiles/openglglfw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eberdeed/programs/openglwindow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable openglglfw3"
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openglglfw3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw3/src/CMakeFiles/openglglfw3.dir/build: glfw3/src/openglglfw3

.PHONY : glfw3/src/CMakeFiles/openglglfw3.dir/build

glfw3/src/CMakeFiles/openglglfw3.dir/clean:
	cd /home/eberdeed/programs/openglwindow/build/glfw3/src && $(CMAKE_COMMAND) -P CMakeFiles/openglglfw3.dir/cmake_clean.cmake
.PHONY : glfw3/src/CMakeFiles/openglglfw3.dir/clean

glfw3/src/CMakeFiles/openglglfw3.dir/depend:
	cd /home/eberdeed/programs/openglwindow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eberdeed/programs/openglwindow /home/eberdeed/programs/openglwindow/glfw3/src /home/eberdeed/programs/openglwindow/build /home/eberdeed/programs/openglwindow/build/glfw3/src /home/eberdeed/programs/openglwindow/build/glfw3/src/CMakeFiles/openglglfw3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw3/src/CMakeFiles/openglglfw3.dir/depend
