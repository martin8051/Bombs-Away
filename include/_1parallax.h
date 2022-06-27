#ifndef _1PARALLAX_H
#define _1PARALLAX_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

class _1parallax
{
    public:
        _1parallax();
        virtual ~_1parallax();

        void drawSquare(float, float); // to draw a quad for the background
        void parallaxInit(char *);     // Load images to the background
        void scroll(bool,string,float);// bool for Auto, string for direction

       _1textureLoader *bTex = new _1textureLoader();

        float xMax,yMax,xMin,yMin;     //  For texture coordinates

    protected:

    private:
};

#endif // _PARALLAX_H
