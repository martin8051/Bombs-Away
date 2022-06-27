#ifndef _IMAGELOADER_H
#define _IMAGELOADER_H

#include<_textureLoader.h>
#include<string>

class _imageLoader
{
    public:
        _imageLoader();
        virtual ~_imageLoader();
        void initImage(char*);
        void drawImage();
        void placeImage(float,float,float);   // To place an image at (x,y,z)
        void resizeImage(float,float);        // To resize an image
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
        _textureLoader *imageTexture = new _textureLoader();
};

#endif // _IMAGELOADER_H
