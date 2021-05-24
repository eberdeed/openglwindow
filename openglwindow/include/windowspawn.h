/********************************************************************
 * WindowSpawn:  A class to encapsulate an SDL2 window displaying a
 * series of programs demonstrating the use of windowing libraries.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
 ********************************************************************/

#ifndef WINDOWSPAWN_H
#define WINDOWSPAWN_H

#include "../../datagen/include/commonheader.h"
#include "../../datagen/assimpopengl/include/shader.h"
#include "../../datagen/assimpopengl/include/createimage.h"
#include "../../datagen/include/openglwindow.h"

/** \class WindowSpawn A class to call all the programs provided, demonstrating 
 *  OpenGL in their respective library's window.
 */
class WindowSpawn
{
public:
    //! \brief Initialize variables and the program and start program execution.
    WindowSpawn();
    //! \brief Destroy the SDL textures used to create the buttons.
    ~WindowSpawn();

protected:
    /* Functions */
    //! Initialize the program by creating the window.
    void initProg();
    //! Define the surfaces and textures for the buttons.
    void defineObjects();
    //! Program event loop to draw the screen.
    void eventLoop();
    //! Change the OpenGL viewport size.
    void framebufferSize(int width, int height);
    //! Handle window events like maximizing and minimizing the window.
	void windowEvent(SDL_Event e);
    //! Handle mouse clicks.
    void mouseMove(SDL_Event e);
    //! Print associated error messages.
    void logSDLError(ostream &os, const string &msg);
    //! Reverse the order of the rows of data in an image.
    void *flipImage(void *data, int width, int height);
    /* Variables */
    //! SDL window variables.
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_GLContext context;
    //! Image management class.
    CreateImage *image;
    //! Void blob to hold the picture data.
    void *pixelData;
    //! Another void blob to hold the vertically reversed picture data.
    unsigned char *reverseData;
    //! Picture variables defining the picture.
    int width, height, depth = 8, pitch, size;
    //! Rectangles to define the button and title locations as well as a temporary value.
    SDL_Rect buttonSize[8], tmpButton;
    //! Booleans to define where the use has last clicked on the screen.
    bool clicked[7];
    //! SDL surfaces to define the buttons and titles.
    SDL_Surface *sdlredbttn, *sdllilacbttn, *glutredbttn, *glutlilacbttn,
    *glfwredbttn, *glfwlilacbttn, *allegroredbttn, *allegrolilacbttn, 
    *sfmlredbttn, *sfmllilacbttn, *opengltitleimage, *closeredbttn, *closelilacbttn;
    //! SDL textures to define the buttons and titles.
    SDL_Texture *sdlred, *sdllilac, *glutred, *glutlilac,
    *glfwred, *glfwlilac, *allegrored, *allegrolilac, *sfmlred, *sfmllilac, 
    *opengltitle, *closered, *closelilac;
    //! File names for the button and title images.
    string buttons[15] =
    {
        "/usr/share/openglresources/buttons/sdlred.png",
        "/usr/share/openglresources/buttons/sdllilac.png",
        "/usr/share/openglresources/buttons/glutred.png",
        "/usr/share/openglresources/buttons/glutlilac.png",
        "/usr/share/openglresources/buttons/glfwred.png",
        "/usr/share/openglresources/buttons/glfwlilac.png",
        "/usr/share/openglresources/buttons/allegrored.png",
        "/usr/share/openglresources/buttons/allegrolilac.png",
        "/usr/share/openglresources/buttons/sfmlred.png",
        "/usr/share/openglresources/buttons/sfmllilac.png",
        "/usr/share/openglresources/buttons/closered.png",
        "/usr/share/openglresources/buttons/closelilac.png",
        "/usr/share/openglresources/buttons/opengltitle.png"
    };
    //! Names of the programs to execute.
    string progTitles[6] =
    {
        "openglsdl2", "openglglut", "openglglfw3", "openglallegro", "openglsfml"
    };
    //! Mouse location variable.
    vec2 mousePos1;
    //! Screen width.
    unsigned int SCR_WIDTH = 1000;
    //! Screen height.
    unsigned int SCR_HEIGHT = 700;
    //! The camera class defining camera location and orientation.
    Camera *camera;
    //! The affine transform matrices defining view and perspective.
    mat4 view, projection;
    //! The camera position.
    vec3 viewPos;
    //! Timing for the animation and the camera.
    chrono::system_clock::time_point intbegin, intend;
    //! Boolean flag for debug.
    bool debug1 = false;
    //! Xlib objects to define display size.
    _XDisplay* d;
    Screen*  s;
    //! Boolean to define end of program.
    bool quit = false;

};

//! \brief The simplest main possible.
int main(int argc, char **argv)
{
    WindowSpawn winSpawn;
    return 0;
}
#endif // WINDOWSPAWN_H

