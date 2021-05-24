/********************************************************************
 * OpenGLAllegro:  A class to draw a simple triangle.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
********************************************************************/

#include "../include/openglallegro.h"


OpenGLAllegro::OpenGLAllegro()
{
    cout << "\n\n\tCreating OpenGLAllegro\n\n";
    initProg();
}

OpenGLAllegro::~OpenGLAllegro()
{
    cout << "\n\n\tDestroying OpenGLAllegro\n\n";
    delete datagen;
    delete camera;
}

void OpenGLAllegro::initProg()
{
    try
    {
        d = XOpenDisplay(NULL);
        s = DefaultScreenOfDisplay(d);
        al_set_window_title(display, "Allegro OpenGL Demo");
        al_set_window_position(display, (s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2));
        glewExperimental=true;
        GLenum err=glewInit();
        if(err!=GLEW_OK)
        {
            //Problem: glewInit failed, something is seriously wrong.
            cout<<"glewInit failed, aborting."<<endl;
            exit(1);
        }
        al_reserve_samples(5);
        al_init_acodec_addon();
        memset(sample_data, 0, sizeof(sample_data));
        /* Load the entire sound file from disk. */
        sample_data[0] = al_load_sample(soundFile.c_str());
        if (!sample_data[0]) 
        {
            cout << "\n\n\tCould not load audio sample from " << soundFile << ".\n\n";
        }
        al_play_sample(sample_data[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &new_sample_id);
        datagen = new OpenGLWindow();
        camera = new Camera(SCR_WIDTH, SCR_HEIGHT, vec3(10.0f, -10.0f, 30.0f), vec3(0.0f, 0.0f, 0.0f));
    }
    catch(exception exc)
    {
        cout << "\n\n\tProgram Initialization Error:  " << exc.what() << "\n\n";
    }
    cout << "\n\t9";
    while(true)
    {
        events();
    }
}

void OpenGLAllegro::events()
{
    // render
    // ------
      if (!al_is_event_queue_empty(queue)) {
         while (al_get_next_event(queue, &event)) {
            processInput(event);
            processKey(event);
         }
      }
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    intbegin = chrono::system_clock::now();
    viewPos = camera->getPosition();
    view = camera->getViewMatrix(); //! render
    projection = camera->getPerspective();
    datagen->execDraw(view, projection, viewPos);
    intend = chrono::system_clock::now();


    al_flip_display();
    
}

// ---------------------------------------------------------------------------------------------------------
void OpenGLAllegro::processInput(ALLEGRO_EVENT event)
{
    int width = SCR_WIDTH, height = SCR_HEIGHT;
    ALLEGRO_MOUSE_STATE mousepos;
    switch (event.type) {
         case ALLEGRO_EVENT_DISPLAY_CLOSE:
            this->~OpenGLAllegro();
            break;
       case ALLEGRO_EVENT_DISPLAY_RESIZE:
            width = al_get_display_width(display);
            height = al_get_display_height(display);
            glViewport(0, 0, width, height);
            camera->resizeView(width, height);
            al_resize_display(display, width, height);
            break;
    }
    al_get_mouse_state(&mousepos);
    camera->processMouseMovement(mousepos.x - oldx, mousepos.y - oldy);
    oldx = mousepos.x;
    oldy = mousepos.y;
}

void OpenGLAllegro::processKey(ALLEGRO_EVENT event)
{
    int width = SCR_WIDTH, height = SCR_HEIGHT;
    int delta = (int)
    //! Use timing to create a cameraSpeed variable.
    chrono::duration_cast<chrono::nanoseconds>(intend -
    intbegin).count();
    float deltaTime = (float)delta / 1000000.0f;
    float cameraSpeed = 0.5f * deltaTime;
    //! Motion keys.
    switch(event.keyboard.keycode)
    {
        case ALLEGRO_KEY_ESCAPE:
            this->~OpenGLAllegro();
            break;
        //! Forward motion.
        case ALLEGRO_KEY_W:
            camera->processKeyboard(Camera::Camera_Movement::FORWARD, cameraSpeed);
            break;
        case ALLEGRO_KEY_S:
            camera->processKeyboard(Camera::Camera_Movement::BACKWARD, cameraSpeed);
            break;
        //! Move left.
        case ALLEGRO_KEY_A:
            camera->processKeyboard(Camera::Camera_Movement::LEFT, cameraSpeed);
            break;
        //! Move right.
        case ALLEGRO_KEY_D:
            camera->processKeyboard(Camera::Camera_Movement::RIGHT, cameraSpeed);
            break;
        //! Move up.
        case ALLEGRO_KEY_R:
            camera->processKeyboard(Camera::Camera_Movement::UP, cameraSpeed);
            break;
        //! Move down.
        case ALLEGRO_KEY_F:
            camera->processKeyboard(Camera::Camera_Movement::DOWN, cameraSpeed);
            break;
        //! Reset the camera.
        case ALLEGRO_KEY_Z:
            camera->resetCamera();
            break;
        //! Reverse the camera.
        case ALLEGRO_KEY_X:
            camera->reverseDirection();
            break;
        //! Zoom keys.
        //! Zoom in.
        case ALLEGRO_KEY_UP:
            camera->processMouseScroll(Camera::Camera_Movement::CLOSER);
            break;
        //! Zoom out.
        case ALLEGRO_KEY_DOWN:
            camera->processMouseScroll(Camera::Camera_Movement::AWAY);
            break;
        case ALLEGRO_KEY_ALT:
            altSet = true;
            break;
        case ALLEGRO_KEY_ENTER:
            if (altSet)
            {
                cout << "\n\n\tToggle window fullscreen.\n\n";
                fullScreen = !fullScreen;
                al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, fullScreen);
                if (fullScreen)
                {
                    width = s->width;
                    height = s->height;
                }
                else
                {
                     al_set_window_position(display, (s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2));
                }
            glViewport(0, 0, width, height);
            camera->resizeView(width, height);
            altSet = false;
        }
        break;
    }
}
// glfw: whenever the ewindow size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void OpenGLAllegro::framebufferSize(int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    // Set a videomode - 640x480
}

