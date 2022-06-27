#ifndef _1TEXTURELOADER_H
#define _1TEXTURELOADER_H

#include<SOIL.h>
#include<GL/gl.h>
#include<iostream>
using namespace std;

class _1textureLoader
{
    public:
        _1textureLoader();
        virtual ~_1textureLoader();

        void loadTexture(char *);
        void TextureBinder();
        int width,height;
        unsigned char *image;
        GLuint tex;

    protected:

    private:
};

#endif // _TEXTURELOADER_H
