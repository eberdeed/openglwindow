/********************************************************************
 * OpenGLSFML:  A class to encapsulate an SFML window.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * May 2020 San Diego, California USA
 ********************************************************************/

#ifndef OPENGLSFML_H
#define OPENGLSFML_H

#include "../../datagen/include/commonheader.h"
#include "threadcreate.h"
#include "../../datagen/include/openglwindow.h"

/** \class OpenGLSFML A class to encapsulate the creation and use
 * of an SFML window.
 */
class OpenGLSFML
{
public:
    /** \brief Create the window and start the execution loop.
     */
    OpenGLSFML();

    /** \brief Destroy the program objects.
     */
    ~OpenGLSFML();
protected:
    /* Functions */
    //! \brief Initialize the window and other objects used to support the window.
    void initProg();
    //! \brief Draw the scene and handle keyboard, mouse and window events.
    void eventLoop();
    //! \brief adjust the size of the OpenGL viewport.
    void framebufferSize(int width, int height);
    //! \brief Handle key events.
    void keyDown(sf::Event e);
    //! \brief Handle window events.
	void windowEvent(sf::Event e);
    //! \brief Handle mouse motion events.
    void mouseMove(sf::Event e);
    //! \brief Music creation function.
    static void* soundMaker(void *arg);
    /* Variables */
    //! The libopenglscene.so object.
    OpenGLWindow *datagen;;
    //! An SFML event.
    sf::Event event;
    //! An SFML window.
    sf::Window *window;
    //! Screen width.
    unsigned int SCR_WIDTH = 1000;
    //! Screen height.
    unsigned int SCR_HEIGHT = 700;
    //! The pthread to put the playing music in.
    ThreadCreate *sndthread;
    //! The vector with the thread information.
    vector<ThreadInfo>threadInfo;
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
    //! The Alt key pressed flag.
    bool altSet = false;
    //! The first time use of the mouse flag.
    bool firstMouse = true;
    //! The full screen flag;
    bool fullScreen = true;
    //! The mouse motion vectors.
    vec2 mousePos1, mousePos2;
    //! Thread return value.
    int threadReturnValue;
    //! The name of the sound thread.
    string arg = "sfmlsound";
    //! The Xlib objects to determine display size.
    _XDisplay* d;
    Screen*  s;
};
/** These variables are placed outside the class so they
 *  can be shared with the static soundMaker function.
 */
//! The sound buffer class from SFML.
sf::SoundBuffer *buffer;
//! The sound class from SFML.
sf::Sound *sound;
//! The end of program flag.
bool quit = false;
//! The file location of the music.
string soundFile = "/usr/share/openglresources/sound/chinese1b.wav";

//! \brief The simplest main possible.
int main(int argc, char **argv)
{
    OpenGLSFML winsfml;
    return 0;
}

#endif // OPENGLSFML_H
