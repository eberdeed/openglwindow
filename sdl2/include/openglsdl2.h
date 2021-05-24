/********************************************************************
 * OpenGLSDL2:  A class to encapsulate an SDL2 window.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
 ********************************************************************/

#ifndef OPENGLSDL2_H
#define OPENGLSDL2_H

#include "../../datagen/include/commonheader.h"
#include "../../datagen/assimpopengl/include/shader.h"
#include "../../datagen/include/openglwindow.h"

/** \class OpenGLSDL2 A class to encapsulate an SDL2 Window.
 */
class OpenGLSDL2
{
public:
    //! \brief Initialize the program and start the event loop.
    OpenGLSDL2();
    //! \breif Destroy the program objects.
    ~OpenGLSDL2();

protected:
    /* Functions */
    //! \brief Create the SDL window.
    void initProg();
    //! \breif the event loop to draw the window.
    void eventLoop();
    //! \brief adjust the size of the OpenGL viewport.
    void framebufferSize(int width, int height);
    //! \brief Handle key events.
    void keyDown(SDL_Event e);
    //! \brief Handle window events.
	void windowEvent(SDL_Event e);
    //! \brief Handle mouse motion events.
    void mouseMove(SDL_Event e);
    //! \breif Display error messages.
    void logSDLError(ostream &os, const string &msg);
    /** \brief A static sound creation function
     *  that can fit in a thread.
     */
    static void sndMaker();
    /* Variables */
    //! A thread to hold the sound function.
    SDL_Thread *thread;
    //! The SDL window variables.
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_GLContext context;
    //! Mouse position variables.
    vec2 mousePos1, mousePos2;
    /** Booleans to define holding down the alt key 
     * and the first use of the mouse.
     */
    bool altSet = false, firstMouse = true;
    //! Start up screen width.
    unsigned int SCR_WIDTH = 1000;
    //! Start up screen height.
    unsigned int SCR_HEIGHT = 700;
    //! The scene drawing class.
    OpenGLWindow *datagen;
    //! The camera class to define camera location and orientation.
    Camera *camera;
    //! The affine transforms for view and perspective.
    mat4 view, projection;
    //! The camera position.
    vec3 viewPos;
    //! Timing for the animation and the camera.
    chrono::system_clock::time_point intbegin, intend;
    //! The debug flag.
    bool debug1 = false;
    //! Thread return value.
    int threadReturnValue;
    //! The Xlib objects to determine display size.
    _XDisplay* d;
    Screen*  s;
};
//! The end of program flag.
bool quit = false;
//! The file names for the music.
string soundFiles[2]
{
    "/usr/share/openglresources/sound/gamelan1a.wav",
    "/usr/share/openglresources/sound/celticfive.wav"
};

//! \brief The simplest possible main.
int main(int argc, char **argv)
{
    OpenGLSDL2 openglsdl2;
    return 0;
}
#endif // OPENGLSDL2_H
