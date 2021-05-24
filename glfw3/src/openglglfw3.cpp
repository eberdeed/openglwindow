/********************************************************************
 * OpenGLGLFW3:  A class to draw a simple triangle.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
 ********************************************************************/

#include "../include/openglglfw3.h"


OpenGLGLFW3::OpenGLGLFW3()
{
    cout << "\n\n\tCreating OpenGLGLFW3\n\n";
    initProg();
}

OpenGLGLFW3::~OpenGLGLFW3()
{
    cout << "\n\n\tDestroying OpenGLGLFW3\n\n";
    delete camera;
    delete datagen;
    sound->stop();
    sound->resetBuffer();
    delete sound;
    delete buffer;
    sndthread->cancelThread(0);
    delete sndthread;
    glfwDestroyWindow (window);
}

void OpenGLGLFW3::initProg()
{
    try
    {
        d = XOpenDisplay(NULL);
        s = DefaultScreenOfDisplay(d);
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_REFRESH_RATE, 60);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GLFW OpenGL Demo", nullptr, nullptr);
        if (window == nullptr)
        {
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetWindowPos(window, (s->width / 2) - (SCR_WIDTH / 2), 
        (s->height / 2) - (SCR_HEIGHT / 2));
        
                // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            cout << "\n\n\tFailed to initialize GLEW.\n\n";
            glfwTerminate();
       }
        cout << "\n\n\tUsing GLEW Version: " << glewGetString(GLEW_VERSION) << "\n\n"; 
        ThreadInfo tmpInfo;
        threadInfo.push_back(tmpInfo);
        sndthread = new ThreadCreate(arg, threadInfo);
        int error = sndthread->execute(OpenGLGLFW3::soundMaker, 0);
        if (error != 0)
        {
            cout << "\n\n\tSound thread error.\n\n";
        }
        else
        {
            cout << "\n\n\tSound thread success.\n\n";
        }
        glfwSetKeyCallback(window, OpenGLGLFW3::keyDown);   
        glfwSetCursorPosCallback(window, OpenGLGLFW3::mouseMove);
        glfwSetWindowSizeCallback(window, OpenGLGLFW3::windowResize);
        datagen = new OpenGLWindow();
        camera = new Camera(SCR_WIDTH, SCR_HEIGHT, vec3(10.0f, -10.0f, 30.0f), vec3(0.0f, 0.0f, 0.0f));
        windowResize(window, SCR_WIDTH, SCR_HEIGHT);
    }
    catch(exception exc)
    {
        cout << "\n\n\tProgram Initialization Error:  " << exc.what() << "\n\n";
    }
    events();
}

void OpenGLGLFW3::events()
{
    while ((!quit) && (!glfwWindowShouldClose(window)))
    {
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        intbegin = chrono::system_clock::now();
        viewPos = camera->getPosition();
        view = camera->getViewMatrix(); //! render
        projection = camera->getPerspective();
        datagen->execDraw(view, projection, viewPos);
        intend = chrono::system_clock::now();
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    this->~OpenGLGLFW3();
    
    
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void OpenGLGLFW3::keyDown(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    int delta = (int)
    //! Use timing to create a cameraSpeed variable.
    chrono::duration_cast<chrono::nanoseconds>(intend -
    intbegin).count();
    float deltaTime = (float)delta / 1000000.0f;
    float cameraSpeed = 0.5f * deltaTime;
    if (action != GLFW_RELEASE)
    {
    switch(key)
    {
        case GLFW_KEY_ESCAPE:
            quit = true;
            break;
        //! Forward motion.
        case GLFW_KEY_W:
            camera->processKeyboard(Camera::Camera_Movement::FORWARD, cameraSpeed);
            break;
        //! Backwards motion.
        case GLFW_KEY_S:
            camera->processKeyboard(Camera::Camera_Movement::BACKWARD, cameraSpeed);
            break;
        //! Move left.
        case GLFW_KEY_A:
            camera->processKeyboard(Camera::Camera_Movement::LEFT, cameraSpeed);
            break;
        //! Move right.
        case GLFW_KEY_D:
            camera->processKeyboard(Camera::Camera_Movement::RIGHT, cameraSpeed);
            break;
        //! Move up.
        case GLFW_KEY_R:
            camera->processKeyboard(Camera::Camera_Movement::UP, cameraSpeed);
            break;
        //! Move down.
        case GLFW_KEY_F:
            camera->processKeyboard(Camera::Camera_Movement::DOWN, cameraSpeed);
            break;
        //! Reset the camera.
        case GLFW_KEY_Z:
            camera->resetCamera();
            break;
        //! Reverse the camera.
        case GLFW_KEY_X:
            camera->reverseDirection();
            break;
        //! Zoom keys.
        //! Zoom in.
        case GLFW_KEY_UP:
            camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
            break;
        //! Zoom out.
        case GLFW_KEY_DOWN:
            camera->processMouseScroll(Camera::Camera_Movement::AWAY);
            break;
        case GLFW_KEY_ENTER:
            if (mods == GLFW_MOD_ALT)
            {
                fullScreen = !fullScreen;
                if (fullScreen)
                {
                        glfwSetWindowSize (window, s->width, s->height);
                        windowResize(window, s->width, s->height);
                }
                else
                {
                    glfwSetWindowSize (window, SCR_WIDTH, SCR_HEIGHT);
                    glfwSetWindowPos(window, (s->width / 2) - (SCR_WIDTH / 2), 
                    (s->height / 2) - (SCR_HEIGHT / 2));
                    windowResize(window, SCR_WIDTH, SCR_HEIGHT);
                }
            }
            break;
        }
    }
}    

void OpenGLGLFW3::mouseMove(GLFWwindow *window, double x, double y)
{
    if(firstMouse)
    {
        lastX = (float) x;
        lastY = (float) y;
        firstMouse = false;
    }
    float xoffset = (float) x - lastX;
    float yoffset = (float) y - lastY; 
    /** Call the camera class with the information
     *  about the movement of the mouse.
     */
    camera->processMouseMovement(xoffset, yoffset);
    lastX = (float) x;
    lastY = (float) y;
}

void OpenGLGLFW3::windowResize(GLFWwindow *window, int width, int height)
{
    cout << "\n\tWindow Size:  " << width << ", " << height;
    glViewport(0, 0, width, height);
    camera->resizeView(width, height);
}

void *OpenGLGLFW3::soundMaker(void *arg)
{
    ThreadInfo *tinfo = (ThreadInfo*) arg;
    string uargv = "";
    char *tmpptr;
    cout << "\n\n\tThread " << tinfo->threadNum 
    << " : Thread Name " << tinfo->threadName << "\n\n";
    for (int x = 0; x < tinfo->threadName.length(); x++)
    {
        uargv = + toupper(tinfo->threadName.at(x));
    }
    if (uargv.length() == 0)
    {
        cout << "\n\n\tNo string name alloted.\n\n";
    }
    buffer = new sf::SoundBuffer();
    if (!buffer->loadFromFile(soundFile)){
        cout << "\n\n\tUnable to load sound.\n\n";
    }
    sound = new sf::Sound();
    sound->setBuffer(*buffer);
    while(!quit)
    {
        sound->play();
        sleep(452000);
    }
    tmpptr = (char*) uargv.c_str();
    return (void*) tmpptr;
}


