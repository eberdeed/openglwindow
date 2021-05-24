############################################################
#   The CMake File for OpenGLGLFW3.  It provides for
#   the following libraries:  Boost, GLM, GL, GLEW,
#   stdc++, freeimageplus, SDL2, assimp and pthread.
#   Created by Edward C. Eberle <eberdeed@ebedeed.net>
#   March 2020 San Diego California USA
############################################################
cmake_minimum_required(VERSION 3.12)
if(POLICY CMP0015)
  cmake_policy(SET CMP0015 NEW)
endif()
project(openglglfw3)
add_executable(openglglfw3 openglglfw3.cpp threadcreate.cpp)
add_definitions(-g -fPIC -std=c++17 -pthread)
include_directories(/usr/local/include /usr/include/glm /usr/include/GL
/usr/local/include/assimp /usr/include/boost /usr/include/GLFW
/usr/local/include/SDL2 /usr/local/include/allegro5 ../../datagen/assimpopengl/include 
../../datagen/include)
link_directories(/usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib)
target_link_libraries(openglglfw3 stdc++ GL GLEW glfw freeimage freeimageplus 
boost_filesystem boost_system assimp assimpopengl openglscene pthread X11 sfml-audio sfml-system)
install(TARGETS openglglfw3 DESTINATION /usr/bin)
