/********************************************************************
 * OpenGLGlut:  A class to encapsulate the creation of a Glut 
 * window used for the drawing of an OpenGL scene.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
********************************************************************/

#ifndef OPENGLGLUT_H
#define OPENGLGLUT_H

#include "../../datagen/include/commonheader.h"
#include "../../datagen/assimpopengl/include/camera.h"
#include "threadcreate.h"
#include "../../datagen/include/openglwindow.h"

/** \class OpenGLGlut A class to encapsulate the creation of a Glut 
 * window used for the drawing of an OpenGL scene.
 */
class OpenGLGlut
{
public:
    //! \brief Echo the creation of the class and initialize the program.
    OpenGLGlut();
    //! \brief Destroy the program's variables.
    ~OpenGLGlut();

protected:
    /* Functions */
    //! \brief Create the window and start the sound.
    static void initProg();
    //! \brief Draw the scene.
    static void events();
    //! \brief Handle keyboard input.
    static void processInput(unsigned char key, int x, int y);
    //! \brief Handle keys that do not have ASCII code definitions.
    static void specialKeys(int key, int x, int y);
    //! \brief Handle mouse motion.
    static void mouseMove(int x, int y);
    //! \brief Resize the window and OpenGL viewport.
	static void windowEvent(int width, int height);
    //! \brief Music creation function.
    static void* soundMaker(void *arg);
};

/* Variables */
//! The OpenGL scene to draw.
OpenGLWindow *datagen;
//! The Camera class defining the user's view in the scene.
Camera *camera;
//! The pthread to put the playing music in.
ThreadCreate *sndthread;
//! The vector with the thread information.
vector<ThreadInfo>threadInfo;
//! The affine transformations defining view and perspective.
mat4 view, projection;
//! The sound buffer class from SFML.
sf::SoundBuffer *buffer;
//! The sound class from SFML.
sf::Sound *sound;
//! The camera position.
vec3 viewPos;
//! Timing for the animation and the camera.
chrono::system_clock::time_point intbegin, intend;
//! The screen width at startup.
unsigned int SCR_WIDTH = 1000;
//! The screen height at startup.
unsigned int SCR_HEIGHT = 700;
//! The mouse position.
float lastX = 0, lastY = 0;
/** Booleans for: The first time a mouse is used.
 * Full screen toggle.  Debugging.
 */
bool firstMouse = true, fullScreen = false, debug1 = false;
//! Xlib objects to obtain display size.
_XDisplay* d;
Screen*  s;
//! The file location of the music.
string soundFile = "/usr/share/openglresources/sound/gamelan1b.wav";
//! The name of the sound thread.
string arg = "soundout";

//! \brief Initialize glut and instatiate the class.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    OpenGLGlut test1;
    glutMainLoop();
    return 0;
}
#endif // OPENGLGLUT_H
