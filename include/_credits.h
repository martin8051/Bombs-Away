#ifndef _CREDITS_H
#define _CREDITS_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _credits                            // class for credits page in menu
{
    public:
        _credits();
        virtual ~_credits();

        double z;                      // z location of image
        int num = 0;                   // # OF TIMES credits PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float); // draw quad
        void creditsInit(char *);         // load image

       _textureLoader *creditsTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;     // texture coordinates

    protected:
    private:
};
#endif // _CREDITS_H
