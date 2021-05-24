/*******************************************************************
 * OpenGLWindow:  An opengl scene draw by the libassimpopengl.so library.
 * Edward C. Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
****************************************************************/

#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include "commonheader.h"
#include "../assimpopengl/include/info.h"
#include "../assimpopengl/include/model.h"
#include "../assimpopengl/include/shader.h"
#include "../assimpopengl/include/createimage.h"

/** \class OpenGLWindow A class to define a scene and 
 *  draw it using the libassimpopengl.so library.
 */
class OpenGLWindow
{
public:
    //! \brief Define various variables and the lights.
    OpenGLWindow();
    //! \brief Delete the classes and variables used by this library.
    ~OpenGLWindow();
    /* Functions */
    //! \brief Draw the scene.
    void execDraw(mat4 view, mat4 projection, vec3 viewPos);
protected:
    //! \brief Define the blender objects and sky box.
    void defineObjects();
    //! Find the direction towards an object.
    vec3 getDirection(vec3 viewer, vec3 viewed);
    //! Print a vec3 value. For debugging.
    void printVec3(vec3 vecVal);
    //! Print a mat4 value. For debugging.
    void printMat4(mat4 matVal);
    //! Print the blender model definition data.
    void debug(vector<ModelInfo>model, vec3 viewPos);
    /* Variables */
    //! File names for the sky box.
    string skyBoxNames[6] = 
    {
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_rt.tga",
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_lf.tga",
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_up.tga",
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_dn.tga",
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_ft.tga",
        "/usr/share/openglresources/skyboxes/mp_dot/dawn-of-time_bk.tga"
    };
    //! The shader programs;
    Shader *shader, *skyboxShader, *explodeShader, *cloudShader;

    //! The assimpopengl entrance point class.
    Model *model;
    //! The image management class, also from assimpopengl.
    CreateImage *image;
    //! The sky box handles.
    unsigned int skyboxVAO, skyboxVBO, skyBox;
    //! Radian measurements for rotations.
    const float pi90 = acos(-1.0f) / 2.0f;
    const float pi180 = acos(-1.0f);
    //! The affine transform of the given blender object's position.
    mat4 vertmodel, boxmodel;
    //! The position of the blend object.
    vec3 transvec;
    //! Debug flag.
    bool debug1 = false;
    //! Blender object definitions.
    vector<ModelInfo>modelinfo;
    //! Point light positions.
    vec3 pointLightPositions[4] = 
    {
        vec3( 20.0f,  10.0f,  20.0f),
        vec3( -20.0f,  10.0f,  -20.0f),
        vec3( -20.0f,  10.0f,  20.0f),
        vec3( 20.0f,  10.0f, -20.0f),
    };
    //! Positions of the spot lights.
    vec3 spotLightPositions[4] = 
    {
        vec3( 20.0f,  10.0f,  20.0f),
        vec3( -20.0f,  10.0f,  -20.0f),
        vec3( -20.0f,  10.0f,  20.0f),
        vec3( 20.0f,  10.0f, -20.0f),
    };
    //! Temporary variable to hold a point light.
    PointLight lightItem;
    //! The point light definition array.
    vector<PointLight> lights;
    //! Temporary variable to hold a spot light.
    SpotLight spotItem;
    //! The spot light definition array.
    vector<SpotLight> spotLights;
    //! Definition of the sky cube.
    string objectVertexShader = "/usr/share/openglresources/shaders/diffspecbinorm.vs";
    string objectFragmentShader = "/usr/share/openglresources/shaders/diffspecbinorm.frag";
    string vertexSkyShader = "/usr/share/openglresources/shaders/skyboxshader.vs";
    string fragmentSkyShader = "/usr/share/openglresources/shaders/skyboxshader.frag";
    string explodeVertex = "/usr/share/openglresources/shaders/explode.vs";
    string explodeFragment = "/usr/share/openglresources/shaders/explode.frag";
    string cloudVertex = "/usr/share/openglresources/shaders/cloud.vs";
    string cloudFragment = "/usr/share/openglresources/shaders/cloud.frag";
    GLfloat skyboxVertices[108] = {
        // Positions          
       -1.0f,  1.0f, -1.0f,
       -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,
        
       -1.0f, -1.0f,  1.0f,
       -1.0f, -1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f,
        
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        
       -1.0f, -1.0f,  1.0f,
       -1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f,
        
       -1.0f,  1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
       -1.0f,  1.0f,  1.0f,
       -1.0f,  1.0f, -1.0f,
        
       -1.0f, -1.0f, -1.0f,
       -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
       -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f
    };
};

#endif // OPENGLWINDOW_H
