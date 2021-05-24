#include "../include/openglwindow.h"

OpenGLWindow::OpenGLWindow()
{
    cout << "\n\n\tCreating OpenGLWindow.\n\n";
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
    image = new CreateImage();
    boxmodel = mat4(1.0f);
    boxmodel = scale(boxmodel, vec3(1000.0f, 1000.0f, 1000.0f));
    for (int x = 0; x < 4; x++)
    {
        lightItem.position = pointLightPositions[x];
        lightItem.ambient = vec3(0.05f, 0.05f, 0.05f);
        lightItem.diffuse = vec3(1.0f, 1.0f, 1.0f);
        lightItem.specular = vec3(1.0f, 1.0f, 1.0f);
        lightItem.constant = 1.0f;
        lightItem.linear = 0.9f;
        lightItem.quadratic = 0.032f;
        lights.push_back(lightItem);
        spotItem.position = spotLightPositions[x];
        spotItem.direction = getDirection(spotItem.position, vec3(0.0f, 0.0f, 0.0f));
        spotItem.cutOff = 25.0f;
        spotItem.outerCutOff = 30.0f;
        spotItem.ambient = vec3(0.05f, 0.05f, 0.05f);
        spotItem.diffuse = vec3(1.0f, 1.0f, 1.0f);
        spotItem.specular = vec3(1.0f, 1.0f, 1.0f);
        spotItem.constant = 1.0f;
        spotItem.linear = 0.9f;
        spotItem.quadratic = 0.032f; 
        spotLights.push_back(spotItem);
    }
    defineObjects();
}

OpenGLWindow::~OpenGLWindow()
{
    cout << "\n\n\tDestroying OpenGLWindow.\n\n";
    delete model;
    delete image;
    delete shader;
    delete skyboxShader;
    delete explodeShader;
    delete cloudShader;
    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteBuffers(1, &skyboxVBO);
    glDeleteTextures(1, &skyBox);
    exit(0);
}

void OpenGLWindow::defineObjects()
{
    //! Set up the skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), &skyboxVertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    /** Here is where the Blender object file name and
     *  position information are provided.  For more
     *  information about the structure ModelInfo
     *  see the file "info.h".
     */
    //! The individual item, reused many times.
    ModelInfo item;
    //! The translation or location information.
    transvec = vec3(5.0f, 0.0f, 2.0f);
    //! The file name.
    item.path = "/usr/share/openglresources/objects/monkey.blend";
    vertmodel = mat4(1.0f);
    vertmodel = translate(vertmodel, transvec);
    vertmodel = rotate(vertmodel, pi180, vec3(0.0f, 1.0f, 0.0f));
    vertmodel = rotate(vertmodel, pi90, vec3(1.0f, 0.0f, 0.0f));
    vertmodel = scale(vertmodel, vec3(3.0, 3.0, 3.0));
    //! The position and orientation matrix.
    item.model = vertmodel;
    item.location = transvec;
    item.gamma = 1.5f;
    item.diffOnly = true;
    //! Tack it onto the vector.
    modelinfo.push_back(item);
    transvec = vec3(2.0f, 0.0f, -5.0f);
    item.path = "/usr/share/openglresources/objects/dice.blend";
    item.location = transvec;
    vertmodel = mat4(1.0f);
    vertmodel = translate(vertmodel, transvec);
    item.model = vertmodel;
    modelinfo.push_back(item);
    transvec = vec3(-2.0f, 0.0f, -3.0f);
    item.path = "/usr/share/openglresources/objects/dice.blend";
    vertmodel = mat4(1.0f);
    vertmodel = translate(vertmodel, transvec);
    //vertmodel = scale(vertmodel, vec3(1.8f, 1.8f, 1.8f));
    item.location = transvec;
    item.model = vertmodel;
    modelinfo.push_back(item);
    transvec = vec3(-7.0f, 1.3f, -3.0f);
    item.path  = "/usr/share/openglresources/objects/wineglass.blend";
    vertmodel = mat4(1.0f);
    vertmodel = translate(vertmodel, transvec);
    vertmodel = rotate(vertmodel, pi180, vec3(1.0f, 0.0f, 0.0f));
    vertmodel = scale(vertmodel, vec3(0.5f, 0.5f, 0.5f));
    item.location = transvec;
    item.model = vertmodel;
    modelinfo.push_back(item);
    transvec = vec3(7.0f, 2.0f, -7.0f);
    item.path = "/usr/share/openglresources/objects/carafe.blend";
    vertmodel = mat4(1.0f);
    vertmodel = translate(vertmodel, transvec);
    vertmodel = rotate(vertmodel, pi180, vec3(1.0f, 0.0f, 0.0f));
    vertmodel = scale(vertmodel, vec3(0.8f, 0.8f, 0.8f));
    item.location = transvec;
    item.model = vertmodel;
    modelinfo.push_back(item);
    for (int x = 0; x < modelinfo.size(); x++)
    {
        modelinfo[x].idval = x;
    }

    skyboxShader = new Shader();
    skyboxShader->initShader(vertexSkyShader, fragmentSkyShader, "glwinskyboxshader.bin");
    shader = new Shader();
    shader->initShader(objectVertexShader, objectFragmentShader, "glwinobjshader.bin");
    explodeShader = new Shader();
    explodeShader->initShader(explodeVertex, explodeFragment, "glwinbanger.bin");
    cloudShader = new Shader();
    cloudShader->initShader(cloudVertex, cloudFragment, "glwincloud.bin");
    glGenTextures(1, &skyBox);
    image->createSkyBoxTex(skyBox, skyBoxNames);
    model = new Model(modelinfo, shader, explodeShader, cloudShader, 2);
}

void OpenGLWindow::execDraw(mat4 view, mat4 projection, vec3 viewPos)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    skyboxShader->Use();
    skyboxShader->setMat4("view", view);
    skyboxShader->setMat4("projection", projection);
    skyboxShader->setMat4("model", boxmodel);
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyBox);
    skyboxShader->setInt("skybox", 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    glBindVertexArray(0);
    
    //! Pass into the shader the light definitions.
    shader->Use();
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyBox);
    shader->setInt("SkyBoxOne", 1);
    shader->setInt("debug", 0);
    if (debug1)
    {        
        debug(modelinfo, viewPos);
    }
    for (int x = 0; x < modelinfo.size(); x++)
    {
        model->Draw(x, view, projection, modelinfo, lights, spotLights, viewPos);
    }
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    
}

vec3 OpenGLWindow::getDirection(vec3 viewer, vec3 viewed)
{
    vec3 tmpval = normalize(viewed - viewer);
    if (debug1)
    {
        cout << "\n\tViewer:  ";
        printVec3(viewer);
        cout <<  "  Viewed:  ";
        printVec3(viewed);
        cout << "  Direction:  ";
        printVec3(tmpval);
        cout << "\n";
    }
    return(tmpval);
}

void OpenGLWindow::printVec3(vec3 vecVal)
{
    cout << "  3 Float Vector:  ";
    for  (int x = 0; x < 3; x++)
    {
        cout << vecVal[x] << ", ";
    }
}

void OpenGLWindow::printMat4(mat4 matVal)
{
    cout << "  4x4 Matrix\n\t";
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            cout << matVal[y][x] << ", ";
        }
        cout << "\n\t";
    }
}

void OpenGLWindow::debug(vector<ModelInfo>model, vec3 viewPos)
{
    
    cout << "\n\tBlender Model Data";
    for (int x = 0; x < model.size(); x++)
    {
        cout << "\n\tPath:  " << model[x].path;
        cout << "\n\tAffine Matrix:  ";
        printMat4(model[x].model);
        cout << "\n\tLocation:  ";
        printVec3(model[x].location);
        cout << "\n\tDistance from camera:  " << model[x].dist;
        cout << "\n\tIndex for sorting:  " << model[x].idval;
        cout << "\n\tDiffuse Only flag:  " << model[x].diffOnly;
        cout << "\n\tGamma:  " << model[x].gamma;
    }
    cout << "\n\tCamera Position:  ";
    printVec3(viewPos);
    cout << "\n\n";
}
