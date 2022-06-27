#ifndef _INTRO2_H
#define _INTRO2_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _intro2                                  // level 2 intro page
{
    public:
        _intro2();
        virtual ~_intro2();

        double z;                              // z location of image
        int num = 0;                           // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float);         // draw quad
        void _intro2Init(char *);              // load image

       _textureLoader *intro2Tex = new _textureLoader();

        float xMax,yMax,xMin,yMin;             // texture coordinates
};

#endif // _INTRO2_H
