/********************************************************************
 * OpenGLGLFW3:  A class to create a window using the GLFW library.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
********************************************************************/

#ifndef OPENGLGLFW3_H
#define OPENGLGLFW3_H

#include "../../datagen/include/commonheader.h"
#include "../../datagen/assimpopengl/include/camera.h"
#include "../../datagen/include/openglwindow.h"
#include "threadcreate.h"
/** \class OpenGLGLFW3 Creates a window using the GLFW library.
 * It displays a scene defined by libopenglscene.so.
 */
class OpenGLGLFW3
{
public:
    //! \breif Echo the creation of the class and initialize the program.
    OpenGLGLFW3();
    //! \brief Delete the program's objects.
    ~OpenGLGLFW3();

protected:
    /* Functions */
    //! \brief Initialize the window and start the sound.
    void initProg();
    //! \brief The event loop to draw the scene.
    void events();
    //! \brief Handle keyboard input.
    static void keyDown(GLFWwindow* window, int key, int scancode, int action, int mods);
    //! \brief Handle mouse motion.
    static void mouseMove(GLFWwindow *window, double x, double y);
    //! \brief Redefine OpenGL viewport and window size.
    static void windowResize(GLFWwindow *window, int width, int height);
    //! \brief Create the background music.
    static void *soundMaker(void *arg);
    /* Variables */
    //! GLFW window handle.
    GLFWwindow* window;
    //! The OpenGL scene to draw in the window.
    OpenGLWindow *datagen;
    //! The pthread to put the playing music in.
    ThreadCreate *sndthread;
    //! The vector with the thread information.
    vector<ThreadInfo>threadInfo;
    //! The affine transformation matrices to define view and perspective.
    mat4 view, projection;
    //! The camera position.
    vec3 viewPos;
    //! The name of the sound thread.
    string arg = "sound thread";
};
//! Start up screen width.
const unsigned int SCR_WIDTH = 1000;
//! Start up screen height.
const unsigned int SCR_HEIGHT = 700;
//! Camera class to define position and orientation of the camera.
Camera *camera;
//! Mouse position variables.
float lastX, lastY;
/** Booleans:  Flag for the first time the mouse is used.
 * Full screen toggle.
 * End of program flag.
 */
bool firstMouse = true, fullScreen = false, quit = false;
//! Xlib objects for getting display size.
_XDisplay* d;
Screen*  s;
//! The file location of the music.
string soundFile = "/usr/share/openglresources/sound/chinese1b.wav";
//! Timing for the animation and the camera.
chrono::system_clock::time_point intbegin, intend;
//! The SFML sound objects.
sf::Sound *sound;
sf::SoundBuffer *buffer;

//! \brief Instantiate and run the program.
int main(int argc, char **argv)
{
    OpenGLGLFW3 glglfw3;
    return 0;
}

#endif // OPENGLGLFW3_H
