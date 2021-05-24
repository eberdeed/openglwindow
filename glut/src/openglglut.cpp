/********************************************************************
 * OpenGLGlut:  A class to draw a simple triangle.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
 ********************************************************************/

#include "../include/openglglut.h"


OpenGLGlut::OpenGLGlut()
{
    cout << "\n\n\tCreating OpenGLGlut\n\n";
    initProg();
}

OpenGLGlut::~OpenGLGlut()
{
    cout << "\n\n\tDestroying OpenGLGlut\n\n";
    sound->stop();
    sound->resetBuffer();
    delete sound;
    delete buffer;
    sndthread->cancelThread(0);
    delete sndthread;
    delete camera;
    delete datagen;
    delete sndthread;
}

void OpenGLGlut::initProg()
{
    try
    {
        d = XOpenDisplay(NULL);
        s = DefaultScreenOfDisplay(d);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
        glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT); 
        glutInitWindowPosition((s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2)); 
        glutCreateWindow("Glut OpenGL Demo");
        cout << "\n\tWindow width:  " << glutGet(GLUT_WINDOW_WIDTH) << "  Window height:  " 
        << glutGet(GLUT_WINDOW_HEIGHT) << "\n\n";
        glutDisplayFunc(OpenGLGlut::events);
        glutReshapeFunc(OpenGLGlut::windowEvent);
        glutKeyboardFunc(OpenGLGlut::processInput);
        glutSpecialFunc(OpenGLGlut::specialKeys);
        glutPassiveMotionFunc(OpenGLGlut::mouseMove);
        glewExperimental=true;
        GLenum err=glewInit();
        if(err!=GLEW_OK)
        {
            //Problem: glewInit failed, something is seriously wrong.
            cout<<"glewInit failed, aborting."<<endl;
            exit(1);
        }
        ThreadInfo tmpInfo;
        threadInfo.push_back(tmpInfo);
        sndthread = new ThreadCreate(arg, threadInfo);
        int error = sndthread->execute(OpenGLGlut::soundMaker, 0);
        if (error != 0)
        {
            cout << "\n\n\tSound thread error.\n\n";
        }
        else
        {
            cout << "\n\n\tSound thread success.\n\n";
        }
        datagen = new OpenGLWindow();
        camera = new Camera(SCR_WIDTH, SCR_HEIGHT, vec3(10.0f, -10.0f, 30.0f), vec3(0.0f, 0.0f, 0.0f));
        windowEvent(SCR_WIDTH, SCR_HEIGHT);
    }
    catch(exception exc)
    {
        cout << "\n\n\tProgram Initialization Error:  " << exc.what() << "\n\n";
    }
}

void OpenGLGlut::events()
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

    glutSwapBuffers();

    
}

// ---------------------------------------------------------------------------------------------------------
void OpenGLGlut::processInput(unsigned char key, int x, int y)
{
    int keyval = (int) key;
    int mods = glutGetModifiers();
    if (debug1)
    {
        cout << "\n\tKey:  " << keyval  << " : " << key;
    }
    int glutWin = glutGetWindow();
    int delta = (int)
    //! Use timing to create a cameraSpeed variable.
    chrono::duration_cast<chrono::nanoseconds>(intend -
    intbegin).count();
    float deltaTime = (float)delta / 1000000.0f;
    float cameraSpeed = 0.5f * deltaTime;
    switch(keyval)
    {
        case 0x001B:
            glutDestroyWindow(glutWin);
            break;
        //! Forward motion.
        case 0x0077:
        case 0x0057:
            camera->processKeyboard(Camera::Camera_Movement::FORWARD, cameraSpeed);
            break;
        //! Backwards motion.
        case 0x0073:
        case 0x0053:
            camera->processKeyboard(Camera::Camera_Movement::BACKWARD, cameraSpeed);
            break;
        //! Move left.
        case 0x0061:
        case 0x0041:
            camera->processKeyboard(Camera::Camera_Movement::LEFT, cameraSpeed);
            break;
        //! Move right.
        case 0x0064:
        case 0x0044:
            camera->processKeyboard(Camera::Camera_Movement::RIGHT, cameraSpeed);
            break;
        //! Move up.
        case 0x0072:
        case 0x0052:
            camera->processKeyboard(Camera::Camera_Movement::UP, cameraSpeed);
            break;
        //! Move down.
        case 0x0066:
        case 0x0046:
            camera->processKeyboard(Camera::Camera_Movement::DOWN, cameraSpeed);
            break;
        //! Reset the camera.
        case 0x007A:
        case 0x005A:
            camera->resetCamera();
            break;
        //! Reverse the camera.
        case 0x0078:
        case 0x0058:
            camera->reverseDirection();
            break;
        case 0x000D:
            if (mods == GLUT_ACTIVE_ALT)
            {
                fullScreen = !fullScreen;
                if (fullScreen)
                {
                    glutFullScreen();
                    windowEvent(s->width, s->height);
                }
                else
                {
                    glutReshapeWindow(SCR_WIDTH, SCR_HEIGHT);
                    glutPositionWindow((s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2)); 
                    windowEvent(SCR_WIDTH, SCR_HEIGHT);
                }
            }
            break;
    }
    glutPostRedisplay();
}

void OpenGLGlut::specialKeys(int key, int x, int y)
{
    switch(key)
    {
        //! Zoom keys.
        //! Zoom in.
        case GLUT_KEY_UP:
            camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
            break;
        //! Zoom out.
        case GLUT_KEY_DOWN:
            camera->processMouseScroll(Camera::Camera_Movement::AWAY);
            break;
    }
    glutPostRedisplay();
}

void OpenGLGlut::mouseMove(int x, int y)
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
    glutPostRedisplay();
}
    
void OpenGLGlut::windowEvent(int width, int height)
{
    glViewport(0, 0, width, height);
    camera->resizeView(width, height);
}

void* OpenGLGlut::soundMaker(void *arg)
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
    sound->setLoop(true);
    sound->play();
    sleep(452000);
    tmpptr = (char*) uargv.c_str();
    return (void*) tmpptr;
}

