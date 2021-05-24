/*******************************************************************
 * CommonHeader:  A header file to reduce repetition of #define
 * and #include statements.
 * Edward C. Eberle <eberdeed@eberdeed.net>
 * March 2020 San Diego, California USA
****************************************************************/

#ifndef COMMONHEADER_H
//! The defines.
#define COMMONHEADER_H
//! GLEW The OpenGL library manager
#define GLEW_STATIC
#include <GL/glew.h>
//! GLM The OpenGL math library
#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/quaternion.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/matrix_interpolation.hpp>
#include <gtc/matrix_access.hpp> 
#include <gtx/euler_angles.hpp>
// SDL The Simple Direct Media Layer
#include <SDL.h>
#include <SDL_pixels.h>
// Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "allegro5/allegro_native_dialog.h"
// GLFW
#include <glfw3.h>
// GLUT
#include <glut.h>
#include <GL/freeglut.h>
// Simple Fast Multimedia Library SFML
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.h>
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
// Std C++
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <cmath>
#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sstream>

// Free Image Plus
#include <FreeImagePlus.h>
#include <FreeImage.h>

// Boost
#include <filesystem.hpp>

// X11
#include <X11/Xlib.h>

// Mine 
#include "../assimpopengl/include/assimpopengl.h"

// The namespaces used.
using namespace std;
using namespace glm;
using namespace boost::filesystem;

//! Mine, but most of it came from www.learnopengl.com

/** \brief The thread information.  
 * detach and stacksize can be adjusted.
 */
struct ThreadInfo {    
    //! ID to access the pthread with.
    pthread_t   threadID;        
    //! ID returned by pthread_create()
    int         threadNum;       
    //! Application-defined thread number.
    string      threadName;      
    //! Set whether the thread is detached or joinable.  
    bool        detached = true;
    //! Set the stack size for each thread.
    int         stackSize  = 50000;
    
};


#endif // COMMONHEADER_H
