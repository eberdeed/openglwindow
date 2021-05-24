############################################################
#   The CMake File for OpenGLWindow.  It provides for
#   the following libraries:  Boost, GLM, GL, GLEW,
#   stdc++, freeimageplus, SDL2, assimp and pthread.
#   Created by Edward C. Eberle <eberdeed@ebedeed.net>
#   March 2020 San Diego California USA
############################################################
cmake_minimum_required(VERSION 3.12)
if(POLICY CMP0015)
  cmake_policy(SET CMP0015 NEW)
endif()
project(openglglut)
add_executable(openglglut openglglut.cpp threadcreate.cpp)
add_definitions(-g -fPIC -std=c++17 -pthread)
include_directories(/usr/local/include /usr/include/glm /usr/include/GL
/usr/local/include/assimp /usr/include/boost /usr/include/GLFW
/usr/local/include/SDL2 /usr/local/include/allegro5 ../../datagen/assimpopengl/include 
../../datagen/include)
link_directories(/usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib)
target_link_libraries(openglglut stdc++ GL GLEW glut freeimage freeimageplus 
boost_filesystem boost_system assimp assimpopengl openglscene pthread X11 sfml-audio sfml-system)
install(TARGETS openglglut DESTINATION /usr/bin)
