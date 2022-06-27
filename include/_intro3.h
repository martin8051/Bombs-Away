#ifndef _INTRO3_H
#define _INTRO3_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _intro3                               // level 3 intro page
{
    public:
        _intro3();
        virtual ~_intro3();

        double z;                            // z location of image
        int num = 0;                         // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float);       // draw quad
        void _intro3Init(char *);            // load image

       _textureLoader *intro3Tex = new _textureLoader();

        float xMax,yMax,xMin,yMin;           // texture coordinates
};

#endif // _INTRO3_H
