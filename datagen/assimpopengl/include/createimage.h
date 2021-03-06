/**********************************************************
 *   CreateImage:  A class to encapsulate loading an image
 *   into a GLvoid blob.  Designed for OpenGL. 
 *   Created by: Edward Charles Eberle <eberdeed@eberdeed.net>
 *   March 2020 San Diego, California USA
 * ********************************************************/

#ifndef CREATEIMAGE_H
#define CREATEIMAGE_H
#include "commonheader.h"

using namespace std;

/* \class CreateImage : Using Free Image Plus, this class loads an 
 * image into memory, converts it to a 32 bit format with alpha, 
 * and then passes it to an array of unsigned characters, which 
 * is then passed using a cast to a GLvoid blob. Optionally the 
 * image can be turned into an OpenGL buffer object. It provides
 * for a single image, a vector of images, or a sky box containing
 * six images. 
 */
class CreateImage
{
public:
    //! \breif Echo the creation of the class.
    CreateImage();
    //! Free the storage used by the pixels array.
    ~CreateImage();
    /* Functions */
    //!  Load image and convert it.
    bool setImage(string imagefile);
    //! Accessor functions for the given image's dimensions and data.
    //! Image width in pixels.
    GLsizei getWidth();
    //! Image height in pixels.
    GLsizei getHeight();
    //! The overall size of the image in bytes.
    GLsizei getSize();
    //! The void* blob containing the picture data.
    GLvoid *getData();
    //! Return an OpenGL buffer object.
    GLuint textureObject();
    //! Return an OpenGL sky box object.
    void createSkyBoxTex(GLuint &textureID, string filenames[6]);
    //! Create an array of images for an OpenGL Texture2DArray object.
    void create2DTexArray(GLuint &textureID, vector<string>filenames);
protected:
    /* Variables */
    //! Class global variables.
    //! The Free Image Plus image object.
    fipImage txtImage;
    //! A line of image data.
    BYTE *picLine;
    //! Image dimensions.
    GLsizei width;
    GLsizei height;
    //! The size in bytes.
    int size = 0;
    //! Image data.
    unsigned char *pixels = nullptr;
    //! Byte and line counters.
    int count, line;
    //! A little tiny bit of debug info.
    bool debug1 = true;
};
#endif // CreateImage.h
