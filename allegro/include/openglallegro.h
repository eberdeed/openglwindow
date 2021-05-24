/********************************************************************
 * OpenAllegro:  A class encapsulate the display of an Allegro 
 * library window.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * 12/2019 San Diego, California USA
********************************************************************/

#ifndef OPENGLALLEGRO_H
#define OPENGLALLEGRO_H
//! Defines for the Allegro sound module.
#define RESERVED_SAMPLES   16
#define MAX_SAMPLE_DATA    10

#include "../../datagen/include/commonheader.h"
#include "../../datagen/assimpopengl/include/camera.h"
#include "../../datagen/include/openglwindow.h"

/** \class OpenGLAllegro A class to encapsulate the showing of
 * an Allegro library window.  It also provides sound using
 * the Allegro sound module.
 */
class OpenGLAllegro
{
public:
    //! \brief Initialize the program.
    OpenGLAllegro();
    //! \brief Delete the items created by the program.
    ~OpenGLAllegro();
protected:
    /** \brief Initialize the program by creating the window,
     * the scene, the sound and the camera.
     */
    void initProg();
    /** \brief The event loop where the picture is drawn
     * and the keyboard and mouse are accounted for.
     */
    void events();
    //! \brief Adjust the viewport and camera view.
    void framebufferSize(int width, int height);
    //! \brief Handles the window and mouse events.
    void processInput(ALLEGRO_EVENT event);
    //! \brief Handles the keyboard events.
    void processKey(ALLEGRO_EVENT event);
    //! Booleans to mark holding down the alt key and toggling full screen.
    bool altSet = false, fullScreen = false;
    //! The class holding the OpenGL scene.
    OpenGLWindow *datagen;
    //! The camera to abstract away from system I/O.
    Camera *camera;
    //! The view and perspective affine transform matrices.
    mat4 view, projection;
    //! The camera position.
    vec3 viewPos;
    //! Timing for the animation and the camera.
    chrono::system_clock::time_point intbegin, intend;
    //! Keyboard event state.
    ALLEGRO_KEYBOARD_STATE *keybrd;
    //! Incoming audio stream.
    ALLEGRO_AUDIO_STREAM *astream;
    //! Audio sample ID.
    ALLEGRO_SAMPLE_ID new_sample_id;
    //! Samples to hold audio data.
    ALLEGRO_SAMPLE *sample_data[MAX_SAMPLE_DATA] = {NULL};
    //! The file where the music is held.
    string soundFile = "/usr/share/openglresources/sound/celticfive.wav";
};
//! Screen width.
unsigned int SCR_WIDTH = 1000;
//! Screen height.
unsigned int SCR_HEIGHT = 700;
//! Window handle.
ALLEGRO_DISPLAY *display;
//! Event queue handle.
ALLEGRO_EVENT_QUEUE *queue;
//! Input event.
ALLEGRO_EVENT event;
//! Variables to hold the mouse location.
int oldx = 0, oldy = 0;
//! Variables to determine the display size.
_XDisplay* d;
Screen*  s;
//! \breif an Allegro item to deal with errors.
void abort_example(char const *format, ...)
{
   char str[1024];
   va_list args;
   ALLEGRO_DISPLAY *display;

   va_start(args, format);
   vsnprintf(str, sizeof str, format, args);
   va_end(args);

   if (al_init_native_dialog_addon()) {
      display = al_is_system_installed() ? al_get_current_display() : NULL;
      al_show_native_message_box(display, "Error", "Cannot run example", str, NULL, 0);
   }
   else {
      fprintf(stderr, "%s", str);
   }
   exit(1);
}


/** \brief A main to install the keyboard and 
 * mouse as well as audio and display size.
 */
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    d = XOpenDisplay(NULL);
    s = DefaultScreenOfDisplay(d);
    if (!al_init()) {
        abort_example("Could not init Allegro.\n");
    }

    al_install_keyboard();
    al_install_mouse();
    if (!al_install_audio()) {
        abort_example("Could not init sound!\n");
    }

    if (!al_reserve_samples(RESERVED_SAMPLES)) {
        abort_example("Could not set up voice and mixer.\n");
    }
    al_set_new_window_position((s->width / 2) - (SCR_WIDTH / 2), (s->height / 2) - (SCR_HEIGHT / 2));
    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);
    display = al_create_display(SCR_WIDTH, SCR_HEIGHT);
    if (!display) {
        abort_example("Could not create display.\n");
    }

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    OpenGLAllegro *test1 = new OpenGLAllegro();
    delete test1;
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    return 0;
}
#endif // OPENGLALLEGRO_H
