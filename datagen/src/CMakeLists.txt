############################################################
#   The CMake File for openglscene.  This is a add_library
#   to isolate the drawing of an OpenGL scene.
#   Created by Edward C. Eberle <eberdeed@ebedeed.net>
#   April 2020 San Diego California USA
############################################################
cmake_minimum_required(VERSION 3.12)
if(POLICY CMP0015)
  cmake_policy(SET CMP0015 NEW)
endif()
project(openglscene)
add_library(openglscene SHARED openglwindow.cpp)
add_definitions(-g -fPIC -std=c++17 -pthread)
include_directories(/usr/local/include /usr/include/glm /usr/include/GL
/usr/local/include/assimp /usr/include/boost /usr/local/include/SDL2 
/usr/local/include/allegro5 /usr/include/GLFW /usr/include/assimpopengl 
../datagen/assimpopengl/include )
link_directories(/usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib ../datagen/assimpopengl/src)
target_link_libraries(openglscene stdc++ GL GLEW freeimage freeimageplus 
boost_filesystem boost_system assimp assimpopengl pthread)
install(TARGETS openglscene DESTINATION /usr/lib)
