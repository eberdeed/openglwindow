/********************************************************************
 * OpenGLSFML:  A class to encapsulate a SFML window.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * May 2020 San Diego, California USA
 ********************************************************************/


#include "../include/openglsfml.h"

OpenGLSFML::OpenGLSFML()
{
    cout << "\n\n\tCreating OpenGLSFML.\n\n";
    initProg();
    eventLoop();
}

OpenGLSFML::~OpenGLSFML()
{
    cout << "\n\n\tDestroying OpenGLSFML.\n\n";
    sound->stop();
    sound->resetBuffer();
    delete sound;
    delete buffer;
    sndthread->cancelThread(0);
    delete sndthread;
    delete camera;
    delete datagen;
}

void OpenGLSFML::initProg()
{
    d = XOpenDisplay(NULL);
    s = DefaultScreenOfDisplay(d);
    // Create the main window
    window = new sf::Window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML window with OpenGL");
    window->setPosition(sf::Vector2i((s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2))); 
    // Make it the active window for OpenGL calls
    window->setActive();
    ThreadInfo tmpInfo;
    threadInfo.push_back(tmpInfo);
    sndthread = new ThreadCreate(arg, threadInfo);
    int error = sndthread->execute(OpenGLSFML::soundMaker, 0);
    if (error != 0)
    {
        cout << "\n\n\tSound thread error.\n\n";
    }
    else
    {
        cout << "\n\n\tSound thread success.\n\n";
    }
    glewExperimental=true;
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        //Problem: glewInit failed, something is seriously wrong.
        cout<< "\n\n\tglewInit failed, aborting.\n\n";
        exit(1);
    }
    else
    {
        cout << "\n\n\tInitialized glew.\n";
    }
    datagen = new OpenGLWindow();
    cout << "\n\n\tInitialized viewport.\n";
    camera = new Camera(SCR_WIDTH, SCR_HEIGHT, vec3(10.0f, -10.0f, 30.0f), vec3(0.0f, 0.0f, 0.0f));
}
void OpenGLSFML::eventLoop()
{
    while (!quit)
    {
        intbegin = chrono::system_clock::now();
        viewPos = camera->getPosition();
        view = camera->getViewMatrix(); //! render
        projection = camera->getPerspective();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        datagen->execDraw(view, projection, viewPos);
        intend = chrono::system_clock::now();
        while (window->pollEvent(event))
        {
            keyDown(event);
            windowEvent(event);
            mouseMove(event);
            
        }
        // Finally, display the rendered frame on screen
        window->display();
    }
}
// ---------------------------------------------------------------------------------------------------------
void OpenGLSFML::keyDown(sf::Event e)
{
    int delta = (int)
    //! Use timing to create a cameraSpeed variable.
    chrono::duration_cast<chrono::milliseconds>(intend -
    intbegin).count();
    float cameraSpeed = 0.5f * delta;
    //! Motion keys.
    if (e.type == sf::Event::KeyPressed) 
    {
        cout << "\n\tdelta:  " << delta << " cameraSpeed:  " << cameraSpeed << "\n";
        switch (e.key.code)
        {
            //! Forward motion.
            case sf::Keyboard::W:
                camera->processKeyboard(Camera::Camera_Movement::FORWARD, cameraSpeed);
                break;
            //! Backwards motion.
            case sf::Keyboard::S:
                camera->processKeyboard(Camera::Camera_Movement::BACKWARD, cameraSpeed);
                break;
            //! Move left.
            case sf::Keyboard::A:
                camera->processKeyboard(Camera::Camera_Movement::LEFT, cameraSpeed);
                break;
            //! Move right.
            case sf::Keyboard::D:
                camera->processKeyboard(Camera::Camera_Movement::RIGHT, cameraSpeed);
                break;
            //! Move up.
            case sf::Keyboard::R:
                camera->processKeyboard(Camera::Camera_Movement::UP, cameraSpeed);
                break;
            //! Move down.
            case sf::Keyboard::F:
                camera->processKeyboard(Camera::Camera_Movement::DOWN, cameraSpeed);
                break;
            //! Reset the camera.
            case sf::Keyboard::Z:
                camera->resetCamera();
                break;
            //! Reverse the camera.
            case sf::Keyboard::X:
                camera->reverseDirection();
                break;
            //! Zoom keys.
            //! Zoom in.
            case sf::Keyboard::Up:
                camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
                break;
            //! Zoom out.
            case sf::Keyboard::Down:
                camera->processMouseScroll(Camera::Camera_Movement::AWAY);
                break;
            case sf::Keyboard::Escape:
                cout << "\n\n\tIn SDL Escape.\n\n";
                quit = true;
                break;
           case sf::Keyboard::RAlt:
                altSet = true;
                break;
            case sf::Keyboard::LAlt:
                altSet = true;
                break;
            case sf::Keyboard::Enter:
                if (altSet)
                {
                    if (fullScreen)
                    {
                        sf::Vector2u sizeVec(s->width, s->height); 
                        cout << "\n\n\tSet window fullscreen.\n\n";
                        window->setSize(sizeVec);
                        framebufferSize(s->width, s->height); 
                    }
                    else
                    {
                        sf::Vector2u sizeVec(SCR_WIDTH, SCR_HEIGHT); 
                        cout << "\n\n\tSet window windowed.\n\n";
                        window->setSize(sizeVec);
                        framebufferSize(SCR_WIDTH, SCR_HEIGHT);
                        window->setPosition(sf::Vector2i((s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2))); 
                    }
                    fullScreen = !fullScreen;
                    altSet = false;
                }                    
                break;
        }
    }
}    

void OpenGLSFML::windowEvent(sf::Event e)
{
    switch (e.type) 
    {
        case sf::Event::Closed:
            quit = true;
            break;
        case sf::Event::Resized:
            cout << "\n\n\tWindow resized to " 
            << e.size.height << ", " << e.size.height << "\n\n";
            sf::Vector2u sizeVec(e.size.width, e.size.height);
            window->setSize(sizeVec);
            break;
    }
}

void OpenGLSFML::mouseMove(sf::Event e)
{
    if (e.type == sf::Event::MouseWheelMoved)
    {
            if(e.mouseWheel.delta > 0)
            {
                camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
            }
            else if (e.mouseWheel.delta < 0)
            {
                camera->processMouseScroll(Camera::Camera_Movement::AWAY);
            }
    }
    if (e.type == sf::Event::MouseMoved)
    {
        if (firstMouse)
        {
            mousePos2.x = e.mouseMove.x;
            mousePos2.y = e.mouseMove.y;
            firstMouse = false;
        }
        mousePos1.x = e.mouseMove.x;
        mousePos1.y = e.mouseMove.y;
        if (debug1)
        {
            cout << "\n\n\tIn mouseMove() Mouse Up X, Y:  " << e.mouseMove.x << ", " << e.mouseMove.y << "\n\n";
        }
        camera->processMouseMovement(mousePos1.x - mousePos2.x, mousePos1.y - mousePos2.y);
        mousePos2.x = e.mouseMove.x;
        mousePos2.y = e.mouseMove.y;
    }
    
}    
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void OpenGLSFML::framebufferSize(int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    camera->resizeView(width, height);
    // Set a videomode - 640x480
}


void* OpenGLSFML::soundMaker(void *arg)
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
        cout << "\n\n\tUnable to load \n\n";
    }
    sound =  new sf::Sound();
    sound->setBuffer(*buffer);
    sound->setLoop(true);
    sound->play();
    sleep(452000);
    tmpptr = (char*) uargv.c_str();
    return (void*) tmpptr;
}

