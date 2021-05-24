
    openglwindow is a program that displays a group
    of different kinds of windows with sound using OpenGL.
    Initially there is a selection screen to select 
    the type of window to display.  Each display 
    has a number of keys enabled.
    The keys are as follows.
    a right
    s back
    d left
    w forward
    r up
    f down
    x reverse view.
    z reset view.
    Escape ends the program.
    Alt+Return sets full screen.
    Up arrow zooms in.
    Down arrow zooms out.
    
    To compile the program you will need the following libraries:
    FreeImage, GLEW, boost, pthread, Assimp, GLM, Xlib, SFML, and 
    the window libaries, SDL2, freeglut, Allegro5, SFML, and GLFW3. 
    You must also have cmake and doxygen.
    The commands are:
    
    mkdir build
    cd build
    cmake ..
    sudo make doc
    sudo make install
    
    To run a program use:
    
    openglwindow
    
    To run one individually use:
    
    openglallegro
    openglsdl2
    openglglut
    openglglfw3
    openglsfml
    
    The documentation is located in:
    
    /usr/share/doc/openglwindow-doc
    
    The assimpopengl subdirectory can be made into a separate program and 
    used to provide Assimp library support for any project you may
    care to undertake.  Just copy the assimpopengl directory:
    
    cp -r openglwindow/datagen/assimpopengl yourlocation
    
    and use it as you wish.
    
    The sources I used to educate myself concerning OpenGL are
    as follows:
        "OpenGL ES 3.0 Programming Guide Second Edition" 
    by Dan Ginsburg and Budirijanto Purnomo published by Addison-Wesley 2014.
        www.learnopengl.com.
    GLEW http://glew.sourceforge.net, and
    CMAKE http://www.cmake.org.
    Doxygen http://www.doxygen.nl
    GraphViz https://www.graphviz.org for the "dot" program used by doxygen.
    SDL2 https://wiki.libsdl.org/FrontPage
    Allegro https://liballeg.org
    GLFW https://www.glfw.org
    Glut http://freeglut.sourceforge.net
    Assimp https://www.assimp.org
    SFML https://www.sfml-dev.org
    pthread https://www.gnu.org/software/hurd/libpthread.html
    OpenGL is generally available on any system as part 
    of the underlying graphics subsystem and GLEW will 
    get you access to it.
    
    The program was written and compiled on debian linux available at:  www.debian.org.
    
    You can reach me at <eberdeed@eberdeed.net>.
    Updates will be available at www.eberdeed.net.
    Edward Charles Eberle 
    April 17th, 2020 San Diego, California United States of America
    
    This program is licensed under the Lesser GNU Public license.
    It can be found in the assimpopengl/LGPL directory 
    and once installed it will be also found at 
    /usr/share/doc/openglwindow-doc/LGPL.  This 
    program is given as an instructional aid for learning
    and using the libraries presented and is not to 
    be considered fit for any particular use.
    
    
