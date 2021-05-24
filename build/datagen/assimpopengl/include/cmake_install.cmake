# Install script for directory: /home/eberdeed/programs/openglwindow/datagen/assimpopengl/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/assimpopengl-1.0/assimpopengl.h;/usr/include/assimpopengl-1.0/createimage.h;/usr/include/assimpopengl-1.0/info.h;/usr/include/assimpopengl-1.0/mesh.h;/usr/include/assimpopengl-1.0/model.h;/usr/include/assimpopengl-1.0/shader.h;/usr/include/assimpopengl-1.0/commonheader.h;/usr/include/assimpopengl-1.0/camera.h;/usr/include/assimpopengl-1.0/uniformprinter.h;/usr/include/assimpopengl-1.0/smokecloud.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/assimpopengl-1.0" TYPE FILE PERMISSIONS WORLD_READ FILES
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/assimpopengl.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/createimage.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/info.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/mesh.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/model.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/shader.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/commonheader.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/camera.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/uniformprinter.h"
    "/home/eberdeed/programs/openglwindow/datagen/assimpopengl/include/smokecloud.h"
    )
endif()

