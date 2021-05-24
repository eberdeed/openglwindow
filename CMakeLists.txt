############################################################
#   The CMake File for OpenGLWindow.  It provides for
#   the following libraries:  Boost, GLM, GL, GLEW,
#   stdc++, freeimageplus, SDL2, assimp, pthread.
#   Created by Edward C. Eberle <eberdeed@ebedeed.net>
#   March 2020 San Diego California USA
############################################################
cmake_minimum_required(VERSION 3.12)
if (POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()
project(openglwindow)
add_subdirectory(datagen)
add_subdirectory(sdl2)
add_subdirectory(allegro)
add_subdirectory(glfw3)
add_subdirectory(glut)
add_subdirectory(sfml)
add_subdirectory(openglwindow)
find_package(Doxygen REQUIRED dot)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN YES)
set(PROJECT_NAME "The OpenGL Window Demo")
set(PROJECT_BRIEF "A program to display an OpenGL scene in a number of library window types.")
doxygen_add_docs(doc glut/include glut/src sdl2/include sdl2/src glfw3/src glfw3/include
allegro/src allegro/include sfml/src sfml/include datagen/src datagen/include 
datagen/assimpopengl/include datagen/assimpopengl/src openglwindow/src 
openglwindow/include COMMENT "Generating documentation.")
install(DIRECTORY openglresources DESTINATION /usr/share FILE_PERMISSIONS WORLD_READ)
install(DIRECTORY datagen/assimpopengl/LGPL DESTINATION /usr/share/doc/openglwindow-doc FILE_PERMISSIONS WORLD_READ)
install(DIRECTORY build/html DESTINATION /usr/share/doc/openglwindow-doc FILE_PERMISSIONS WORLD_READ)
install(DIRECTORY build/man DESTINATION /usr/share/doc/openglwindow-doc FILE_PERMISSIONS WORLD_READ)
install(FILES README.txt CHANGELOG.txt openglwindowwriteup.odt openglwindowwriteup.pdf
DESTINATION /usr/share/doc/openglwindow-doc PERMISSIONS WORLD_READ)
