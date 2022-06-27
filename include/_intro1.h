#ifndef _INTRO1_H
#define _INTRO1_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _intro1                                 // level 1 intro page
{
    public:
        _intro1();
        virtual ~_intro1();

        double z;                             // z location of image
        int num = 0;                          // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float);        // draw quad
        void _intro1Init(char *);             // load image

       _textureLoader *intro1Tex = new _textureLoader();

        float xMax,yMax,xMin,yMin;            // texture coordinates
};

#endif // _INTRO1_H
