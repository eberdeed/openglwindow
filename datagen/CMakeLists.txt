############################################################
#   The CMake File for OpenGLWindow.  It provides for
#   the following libraries:  Boost, GLM, GL, GLEW,
#   stdc++, freeimageplus, SDL2, assimp, pthread.
#   Created by Edward C. Eberle <eberdeed@ebedeed.net>
#   March 2020 San Diego California USA
############################################################
cmake_minimum_required(VERSION 3.12)
project(openglscene)
add_subdirectory(assimpopengl)
add_subdirectory(src)
