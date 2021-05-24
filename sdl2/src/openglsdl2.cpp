/********************************************************************
 * OpenGLSDL2:  A class to encapsulate and SDL2 window.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
 ********************************************************************/

#include "../include/openglsdl2.h"


OpenGLSDL2::OpenGLSDL2()
{

    cout << "\n\n\tCreating OpenGLSDL2\n\n";
    quit = false;
    initProg();
    eventLoop();
    SDL_WaitThread(thread, &threadReturnValue);
    cout << "\n\n\tThread returned value:  " << threadReturnValue << "\n\n";
}

OpenGLSDL2::~OpenGLSDL2()
{
    cout << "\n\n\tDestroying OpenGLSDL2\n\n";
    delete datagen;
    delete camera;
    SDL_Quit();
    exit(0);
}

void OpenGLSDL2::logSDLError(ostream &os, const string &msg)
{
    os << "\n\n\t" << msg << " error: " << SDL_GetError() << "\n\n";
}

void OpenGLSDL2::initProg()
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
        window = SDL_CreateWindow("SDL2 OpenGL Demo", (s->width / 2) - (SCR_WIDTH / 2), 
        (s->height / 2) - (SCR_HEIGHT / 2), SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
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
        thread = SDL_CreateThread((SDL_ThreadFunction)OpenGLSDL2::sndMaker, "SoundThread", (void *)NULL);

        if (NULL == thread) 
        {
            logSDLError(cout, "SDL_CreateThread failed");
        } else 
        {
            cout << "\n\n\tSound thread successfully created.\n\n";
        }
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
        camera = new Camera(SCR_WIDTH, SCR_HEIGHT, vec3(10.0f, -10.0f, 30.0f), vec3(0.0f, 0.0f, 0.0f));
        cout << "\n\n\tCreated Camera in OpenGLSDL2.\n\n";
        datagen = new OpenGLWindow();
        cout << "\n\n\tCreated OpenGLWindow in OpenGLSDL2.\n\n";
        framebufferSize(SCR_WIDTH, SCR_HEIGHT);
        cout << "\n\n\tCalled framebufferSize.\n\n";
    }
    catch(exception exc)
    {
        cout << "\n\n\tProgram Initialization Error:  " << exc.what() << "\n\n";
    }
}

void OpenGLSDL2::eventLoop()
{
    cout << "\n\n\tIn OpenGL SDL2 events.\n\n";
    SDL_Event e;
    int count = 0;
    string quitVal = "False";
    if (debug1)
    {
        if (quit)
        {
            quitVal = "True";
        }
        cout << "\n\n\tQuit is " << quitVal << "\n\n";
    }
    while (!quit)
    {
        if (debug1)
        {
            quitVal = "False";
            if (quit)
            {
                quitVal = "True";
            }
            cout << "\n\n\tQuit is " << quitVal << "\n\n";
        }
        // render
        // ------
        intbegin = chrono::system_clock::now();
        viewPos = camera->getPosition();
        view = camera->getViewMatrix(); //! render
        projection = camera->getPerspective();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        datagen->execDraw(view, projection, viewPos);
        SDL_GL_SwapWindow(window);
        intend = chrono::system_clock::now();
        while (SDL_PollEvent(&e))
        {
            keyDown(e);
            mouseMove(e);
            windowEvent(e);
        };
    };
    cout << "\n\n\tOutside execution loop.\n\n";
    // Terminate SDL, clearing any resources allocated by SDL.
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_DestroyRenderer(renderer);
    this->~OpenGLSDL2();
}

// ---------------------------------------------------------------------------------------------------------
void OpenGLSDL2::keyDown(SDL_Event e)
{
    int delta = (int)
    //! Use timing to create a cameraSpeed variable.
    chrono::duration_cast<chrono::milliseconds>(intend -
    intbegin).count();
    float cameraSpeed = 0.5f * delta;
    //! Motion keys.
    if (e.type == SDL_KEYDOWN) 
    {
        cout << "\n\n\tIn keyDown:  " << SDL_GetKeyName(e.key.keysym.sym) << "\n\n";
        cout << "\n\tdelta:  " << delta << " cameraSpeed:  " << cameraSpeed << "\n";
        switch (e.key.keysym.sym)
        {
            //! Forward motion.
            case SDLK_w:
                camera->processKeyboard(Camera::Camera_Movement::FORWARD, cameraSpeed);
                break;
            //! Backwards motion.
            case SDLK_s:
                camera->processKeyboard(Camera::Camera_Movement::BACKWARD, cameraSpeed);
                break;
            //! Move left.
            case SDLK_a:
                camera->processKeyboard(Camera::Camera_Movement::LEFT, cameraSpeed);
                break;
            //! Move right.
            case SDLK_d:
                camera->processKeyboard(Camera::Camera_Movement::RIGHT, cameraSpeed);
                break;
            //! Move up.
            case SDLK_r:
                camera->processKeyboard(Camera::Camera_Movement::UP, cameraSpeed);
                break;
            //! Move down.
            case SDLK_f:
                camera->processKeyboard(Camera::Camera_Movement::DOWN, cameraSpeed);
                break;
            //! Reset the camera.
            case SDLK_z:
                camera->resetCamera();
                break;
            //! Reverse the camera.
            case SDLK_x:
                camera->reverseDirection();
                break;
            //! Zoom keys.
            //! Zoom in.
            case SDLK_UP:
                camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
                break;
            //! Zoom out.
            case SDLK_DOWN:
                camera->processMouseScroll(Camera::Camera_Movement::AWAY);
                break;
            case SDLK_ESCAPE:
                cout << "\n\n\tIn SDL Escape.\n\n";
                quit = true;
                break;
           case SDLK_RALT:
                altSet = true;
                break;
            case SDLK_LALT:
                altSet = true;
                break;
            case SDLK_RETURN:
                if (altSet)
                {
                    cout << "\n\n\tSet window fullscreen.\n\n";
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    altSet = false;
                }
                break;
        }
    }
}    

void OpenGLSDL2::windowEvent(SDL_Event e)
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

void OpenGLSDL2::mouseMove(SDL_Event e)
{
    if (e.type == SDL_MOUSEWHEEL)
    {
            if(e.wheel.y > 0)
            {
                camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
            }
            else if (e.wheel.y < 0)
            {
                camera->processMouseScroll(Camera::Camera_Movement::AWAY);
            }
    }
    if (e.type == SDL_MOUSEMOTION)
    {
        if (firstMouse)
        {
            mousePos2.x = e.motion.x;
            mousePos2.y = e.motion.y;
            firstMouse = false;
        }
        mousePos1.x = e.motion.x;
        mousePos1.y = e.motion.y;
        if (debug1)
        {
            cout << "\n\n\tIn mouseMove() Mouse Up X, Y:  " << e.motion.x << ", " << e.motion.y << "\n\n";
        }
        camera->processMouseMovement(mousePos1.x - mousePos2.x, mousePos1.y - mousePos2.y);
        mousePos2.x = e.motion.x;
        mousePos2.y = e.motion.y;
    }
    
}    

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void OpenGLSDL2::framebufferSize(int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    camera->resizeView(width, height);
    // Set a videomode - 640x480
}

void OpenGLSDL2::sndMaker()
{
    Uint32 wave_len1, wave_len2; // length of our sample
    Uint8 *wave_buf1, *wave_buf2; // buffer containing our audio file
    int result = 0;
    SDL_AudioSpec wave_spec, ret_spec; // the specs of our piece of music
    cout << "\n\n\tStarting sound production.";
    cout << "\n\tLoading WAV file.\n\n";
    try
    {
        if (SDL_LoadWAV(soundFiles[0].c_str(), &wave_spec, &wave_buf1, &wave_len1) ==  NULL)
        {
            cout << "\n\n\tUnable to load WAV file:  " << SDL_GetError() << "\n\n";
            exit(-1);
        }
        else
        {
            cout << "\n\n\tWAV file successfully loaded.\n\n";
        }
        if (SDL_LoadWAV(soundFiles[1].c_str(), &wave_spec, &wave_buf2, &wave_len2) ==  NULL)
        {
            cout << "\n\n\tUnable to load WAV file:  " << SDL_GetError() << "\n\n";
            exit(-1);
        }
        else
        {
            cout << "\n\n\tWAV file successfully loaded.\n\n";
        }
        string name  = SDL_GetAudioDeviceName(0, 0);
        cout << "\n\n\tAudio device:  " << name << "\n\n";
        SDL_AudioDeviceID dev = SDL_OpenAudioDevice(name.c_str(), 0, &wave_spec, &ret_spec, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
        if (dev < 0)
        {
            cout << "\n\n\tUnable to open audio device:  " << SDL_GetError() << "\n\n";
            exit(-1);
        }
        else
        {
            cout << "\n\n\tAudio device successfully opened for 2 WAV files with length:  "  << wave_len1 
            << ", " << wave_len2 << ".\n\n";
            result = SDL_QueueAudio(dev, wave_buf1, wave_len1);
            if (result != 0)
            {
                cout <<  "\n\n\tUnable to queue audio data.\n\n";
                exit(-1);
            }
            else
            {
                cout << "\n\n\tAudio data successfully queued.\n\n";
            }
        }
        while (!quit)
        {
            SDL_PauseAudioDevice(dev, 0); /* start audio playing. */
            cout << "\n\n\tPlayed the audio.\n\n";
            SDL_Delay(196000); /* let the audio callback play some sound for 1543 seconds. */
            result = SDL_QueueAudio(dev, wave_buf2, wave_len2);
            if (result != 0)
            {
                cout <<  "\n\n\tUnable to queue audio data.\n\n";
                exit(-1);
            }
            else
            {
                cout << "\n\n\tAudio data successfully queued.\n\n";
            }
            SDL_PauseAudioDevice(dev, 0); /* start audio playing. */
            SDL_Delay(300000); /* let the audio callback play some sound for 2034 seconds. */
            result = SDL_QueueAudio(dev, wave_buf1, wave_len1);
            if (result != 0)
            {
                cout <<  "\n\n\tUnable to queue audio data.\n\n";
                exit(-1);
            }
            else
            {
                cout << "\n\n\tAudio data successfully queued.\n\n";
            }
        }
        SDL_CloseAudioDevice(dev);
        cout << "\n\n\tClosed audio device.\n\n";
        SDL_FreeWAV(wave_buf1);
        SDL_FreeWAV(wave_buf2);
    }
    catch(exception exc)
    {
        cout << "\n\n\tError on audio output:  " << exc.what() << "\n\n";
    }
}
