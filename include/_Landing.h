#ifndef _LANDING_H
#define _LANDING_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>

using namespace std;

class _Landing                          // landing picture class
{
    public:
        _Landing();
        virtual ~_Landing();

        double z;                       // used to mess with z value
        void drawSquare(float, float);  // draw quad
        void landingInit(char *);       // load image

       _textureLoader *landTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;      //  texture coordinates

    protected:
    private:
};

#endif // _LANDING_H
