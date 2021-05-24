/********************************************************************
 * WindowSpawn:  A class to encapsulate an SDL2 window displaying a
 * series of programs demonstrating the use of windowing libraries.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
 ********************************************************************/

#include "../include/windowspawn.h"


WindowSpawn::WindowSpawn()
{

    cout << "\n\n\tCreating WindowSpawn\n\n";
    quit = false;
    image = new CreateImage();
    initProg();
    defineObjects();
    eventLoop();
}

WindowSpawn::~WindowSpawn()
{
    cout << "\n\n\tDestroying WindowSpawn\n\n";
    free(pixelData);
    SDL_DestroyTexture(sdlred);
    SDL_DestroyTexture(sdllilac);
    SDL_DestroyTexture(glutred);
    SDL_DestroyTexture(glutlilac);    
    SDL_DestroyTexture(glfwred);
    SDL_DestroyTexture(glfwlilac);
    SDL_DestroyTexture(allegrored);
    SDL_DestroyTexture(allegrolilac);
    SDL_DestroyTexture(opengltitle);
    SDL_DestroyTexture(sfmlred);
    SDL_DestroyTexture(sfmllilac);
    SDL_DestroyTexture(closered);
    SDL_DestroyTexture(closelilac);
}

void WindowSpawn::logSDLError(ostream &os, const string &msg)
{
    os << "\n\n\t" << msg << " error: " << SDL_GetError() << "\n\n";
}

void WindowSpawn::initProg()
{
    cout << "\n\n\tIn initProg.\n\n";
    try
    {
        d = XOpenDisplay(NULL);
        s = DefaultScreenOfDisplay(d);

            // Setup the window
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            logSDLError(cout, "SDL_Init");
            exit(1);
        }
        else
        {
            cout << "\n\n\tInitialized SDL.\n\n";
        }
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
        window = SDL_CreateWindow("OpenGL Window Demo", (s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2), SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL);
        if (window == nullptr){
            logSDLError(cout, "CreateWindow");
            SDL_Quit();
            exit(1);
        }
        else
        {
            cout << "\n\n\tCreated SDL window.\n\n";
        }
        
        context = SDL_GL_CreateContext(window);
        if (context == nullptr){
            logSDLError(cout, "CreateContext");
            SDL_DestroyWindow(window);
            SDL_GL_DeleteContext(context);
            SDL_Quit();
            exit(1);
        }
        else
        {
            cout << "\n\n\tCreated SDL context.\n\n";
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        if (renderer == nullptr){
            logSDLError(cout, "CreateRenderer");
            SDL_DestroyWindow(window);
            SDL_GL_DeleteContext(context);
            SDL_Quit();
            exit(1);
        }
        else
        {
            cout << "\n\n\tCreated renderer.\n";
        }
        SDL_ShowWindow(window);
        SDL_GL_MakeCurrent(window, context);
        SDL_GL_SetSwapInterval(1);
        glewExperimental=true;
        GLenum err=glewInit();
        if(err!=GLEW_OK)
        {
            //Problem: glewInit failed, something is seriously wrong.
            cout<< "\n\n\tglewInit failed, aborting.\n\n";
            exit(1);
        }
        else
        {
            cout << "\n\n\tInitialized glew.\n";
        }
        cout << "\n\n\tInitialized viewport.\n";
        framebufferSize(SCR_WIDTH, SCR_HEIGHT);
    }
    catch(exception exc)
    {
        cout << "\n\n\tProgram Initialization Error:  " << exc.what() << "\n\n";
    }
}

void WindowSpawn::defineObjects()
{
    image->setImage(buttons[0]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    size = image->getSize();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    sdlredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (sdlredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface sdlredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[1]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    sdllilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (sdllilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface sdllilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[2]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    glutredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (glutredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface glutredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[3]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    glutlilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (glutlilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface glutlilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[4]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    glfwredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (glfwredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface glfwredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[5]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    glfwlilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (glfwlilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface glfwlilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[6]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    allegroredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (allegroredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface allegroredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[7]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    allegrolilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (allegrolilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface allegrolilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[8]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    size = image->getSize();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    sfmlredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (sfmlredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface sfmlredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[9]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    sfmllilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (sfmllilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface sfmllilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[10]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    closeredbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (closeredbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface closeredbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[11]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    closelilacbttn = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (closelilacbttn == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface closelilacbttn:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    image->setImage(buttons[12]);
    pixelData = image->getData();
    width = image->getWidth();
    height = image->getHeight();
    pitch = width *  4;
    pixelData = flipImage(pixelData, width, height);
    opengltitleimage = SDL_CreateRGBSurfaceWithFormatFrom(pixelData, width, height, 
    depth, pitch, SDL_PIXELFORMAT_RGBA8888);
    if (opengltitleimage == NULL)
    {
        cout << "\n\n\tFailed to create sdl surface opengltitleimage:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    sdlred = SDL_CreateTextureFromSurface(renderer, sdlredbttn);
    SDL_FreeSurface(sdlredbttn);
    if (sdlred == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for sdlred:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    sdllilac = SDL_CreateTextureFromSurface(renderer, sdllilacbttn);
    SDL_FreeSurface(sdllilacbttn);
    if (sdllilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for sdllilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    glutred = SDL_CreateTextureFromSurface(renderer, glutredbttn);
    SDL_FreeSurface(glutredbttn);
    if (glutred == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for glutred:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    glutlilac = SDL_CreateTextureFromSurface(renderer, glutlilacbttn);
    SDL_FreeSurface(glutlilacbttn);
    if (glutlilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for glutlilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    glfwred = SDL_CreateTextureFromSurface(renderer, glfwredbttn);
    SDL_FreeSurface(glfwredbttn);
    if (glfwred == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for glfwred:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    glfwlilac = SDL_CreateTextureFromSurface(renderer, glfwlilacbttn);
    SDL_FreeSurface(glfwlilacbttn);
    if (glfwlilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for glfwlilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    allegrored = SDL_CreateTextureFromSurface(renderer, allegroredbttn);
    SDL_FreeSurface(allegroredbttn);
    if (allegrored == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for allegrored:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    allegrolilac = SDL_CreateTextureFromSurface(renderer, allegrolilacbttn);
    SDL_FreeSurface(allegrolilacbttn);
    if (allegrolilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for allegrolilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    sfmlred = SDL_CreateTextureFromSurface(renderer, sfmlredbttn);
    SDL_FreeSurface(sfmlredbttn);
    if (sfmlred == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for sfmlred:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    sfmllilac = SDL_CreateTextureFromSurface(renderer, sfmllilacbttn);
    SDL_FreeSurface(sfmllilacbttn);
    if (sfmllilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for sfmllilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    closered = SDL_CreateTextureFromSurface(renderer, closeredbttn);
    SDL_FreeSurface(closeredbttn);
    if (closered == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for closered:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    closelilac = SDL_CreateTextureFromSurface(renderer, closelilacbttn);
    SDL_FreeSurface(closelilacbttn);
    if (closelilac == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for closelilac:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    opengltitle = SDL_CreateTextureFromSurface(renderer, opengltitleimage);
    SDL_FreeSurface(opengltitleimage);
    if (opengltitle == nullptr){
        cout << "\n\n\tSDL_CreateTextureFromSurface Error for opengltitle:  " << SDL_GetError() << "\n\n";
        exit(-1);
    }
    tmpButton.w = 250;
    tmpButton.h = 100;
    tmpButton.y = (SCR_HEIGHT / 2) - 40;
    tmpButton.x = 85;
    buttonSize[0] = tmpButton;
    tmpButton.x = 375;
    buttonSize[1] = tmpButton;
    tmpButton.x = 665;
    buttonSize[2] = tmpButton;
    tmpButton.y = (SCR_HEIGHT / 2) + 80;
    tmpButton.x = 85;
    buttonSize[3] = tmpButton;
    tmpButton.x = 375;
    buttonSize[4] = tmpButton;
    tmpButton.x = 665;
    buttonSize[5] = tmpButton;
    tmpButton.y = 50;
    tmpButton.x = (SCR_WIDTH / 2) - 125;
    buttonSize[6] = tmpButton;
    for (int x = 0; x < 6; x++)
    {
        clicked[x] = false;
    }
    
}

void *WindowSpawn::flipImage(void *data, int width, int height)
{
    reverseData = new unsigned char[width * height * 4];
    unsigned char *tmpData = (unsigned char*) data;
    size--;
    int count = 0;
    for (int x = height - 1; x >= 0 ; x--)
    {
        for (int y = 0; y < width * 4; y++)
        {
            reverseData[(x * width * 4) + y] = tmpData[count++];
        }
    }
    return (void*) reverseData;
}

void WindowSpawn::eventLoop()
{
    cout << "\n\n\tIn OpenGL Window events.\n\n";
    SDL_Event e;
    int count = 0;
    string quitVal = "False";
    if (quit)
    {
        quitVal = "True";
    }
    while (!quit)
    {
        quitVal = "False";
        if (quit)
        {
            quitVal = "True";
        }
        // render
        // ------
        intbegin = chrono::system_clock::now();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        //Draw the texture
        SDL_RenderCopy(renderer, opengltitle, NULL, &buttonSize[6]);
        if (clicked[0])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, sdllilac, NULL, &buttonSize[0]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, sdlred, NULL, &buttonSize[0]);
        }
        if (clicked[1])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, glutlilac, NULL, &buttonSize[1]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, glutred, NULL, &buttonSize[1]);
        }
        if (clicked[2])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, glfwlilac, NULL, &buttonSize[2]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, glfwred, NULL, &buttonSize[2]);
        }
        if (clicked[3])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, allegrolilac, NULL, &buttonSize[3]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, allegrored, NULL, &buttonSize[3]);
        }
        if (clicked[4])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, sfmllilac, NULL, &buttonSize[4]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, sfmlred, NULL, &buttonSize[4]);
        }
        if (clicked[5])
        {
            //Draw the texture
            SDL_RenderCopy(renderer, closelilac, NULL, &buttonSize[5]);
        }
        else
        {
            //Draw the texture
            SDL_RenderCopy(renderer, closered, NULL, &buttonSize[5]);
        }
        //Update the screen
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
        intend = chrono::system_clock::now();
        while (SDL_PollEvent(&e))
        {
            mouseMove(e);
            windowEvent(e);
        };
    };
    // Terminate SDL, clearing any resources allocated by SDL.
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
}

void WindowSpawn::windowEvent(SDL_Event e)
{
    if (e.type == SDL_WINDOWEVENT) {
        switch (e.window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            cout << "\n\n\tWindow " << e.window.windowID << " shown.\n\n";
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            cout << "\n\n\tWindow " << e.window.windowID << " hidden.\n\n";
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            cout << "\n\n\tWindow " << e.window.windowID << " exposed.\n\n";
            break;
        case SDL_WINDOWEVENT_MOVED:
            cout << "\n\n\tWindow " << e.window.windowID << " moved to " 
            << e.window.data1 << ", " << e.window.data2 << "\n\n";
            break;
        case SDL_WINDOWEVENT_RESIZED:
            cout << "\n\n\tWindow " << e.window.windowID << " resized to " 
            << e.window.data1 << ", " << e.window.data2 << "\n\n";
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            cout << "\n\n\tWindow " << e.window.windowID << " size changed to " 
            << e.window.data1 << ", " << e.window.data2 << "\n\n";
            framebufferSize(e.window.data1, e.window.data2);
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            cout << "\n\n\tWindow " << e.window.windowID << " minimized.\n\n";
            break;
            framebufferSize(0, 0);
        case SDL_WINDOWEVENT_MAXIMIZED:
            cout << "\n\n\tWindow " << e.window.windowID << " maximized.\n\n";
            framebufferSize(SCR_WIDTH, SCR_HEIGHT);
            break;
        case SDL_WINDOWEVENT_RESTORED:
            cout << "\n\n\tWindow " << e.window.windowID << " restored.\n\n";
            break;
        case SDL_WINDOWEVENT_ENTER:
            cout << "\n\n\tMouse entered window " << e.window.windowID << ".\n\n";
            break;
        case SDL_WINDOWEVENT_LEAVE:
            cout << "\n\n\tMouse left window " << e.window.windowID << ".\n\n";
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            cout << "\n\n\tWindow " << e.window.windowID << " gained keyboard focus.\n\n";
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            cout << "\n\n\tWindow " << e.window.windowID << " lost keyboard focus.\n\n";
            break;
        case SDL_WINDOWEVENT_CLOSE:
            cout << "\n\n\tWindow " << e.window.windowID << " closed.\n\n";
            quit = true;
            break;
        case SDL_WINDOWEVENT_TAKE_FOCUS:
            cout << "\n\n\tWindow " << e.window.windowID << " is offered focus.\n\n";
            break;
        case SDL_WINDOWEVENT_HIT_TEST:
            cout << "\n\n\tWindow " << e.window.windowID << " has a special hit test.\n\n";
            break;
        default:
            cout << "\n\n\tWindow " << e.window.windowID << " received an unknown event.\n\n";
            break;
        }
    }
}

void WindowSpawn::mouseMove(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        mousePos1.x = e.motion.x;
        mousePos1.y = e.motion.y;
        if (true)
        {
            cout << "\n\tMouse Position:  " << mousePos1.x << ", " << mousePos1.y;
        }
        for (int x = 0; x < 6; x++)
        {
            if (((mousePos1.x > buttonSize[x].x) && (mousePos1.x < (buttonSize[x].x + buttonSize[x].w)))
            && ((mousePos1.y > buttonSize[x].y) && (mousePos1.y < (buttonSize[x].y + buttonSize[x].h))))
            {
                cout << "\n\tClicked button " << x;
                clicked[x] = true;
            }
        }
    }
    if (e.type == SDL_MOUSEBUTTONUP)
    {
        mousePos1.x = e.motion.x;
        mousePos1.y = e.motion.y;
        for (int x = 0; x < 6; x++)
        {
            if (((mousePos1.x > buttonSize[x].x) && (mousePos1.x < (buttonSize[x].x + buttonSize[x].w)))
            && ((mousePos1.y > buttonSize[x].y) && (mousePos1.y < (buttonSize[x].y + buttonSize[x].h)))
            && (clicked[x]))
            {
                if (x == 5)
                {
                    quit = true;
                }
                else
                {
                    system(progTitles[x].c_str());
                }
            }
        }
        for (int x = 0; x < 5; x++)
        {
             clicked[x] = false;
        }
    }
}    

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void WindowSpawn::framebufferSize(int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    // Set a videomode - 640x480
}

