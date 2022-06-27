#ifndef _HSDIGIT_H
#define _HSDIGIT_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>
#include <GL/glut.h>

class _hsDigit                         // class for high score digit
{
    public:
        _hsDigit();
        virtual ~_hsDigit();

        double z;                      // z location of image
        int num = 0;                   // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float); // draw quad
        void hsDigitInit(char);        // load image

       _textureLoader *hsDigitTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;     // texture coordinates

};
#endif // _HSDIGIT_H
