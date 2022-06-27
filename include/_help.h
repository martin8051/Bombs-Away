#ifndef _HELP_H
#define _HELP_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _help                            // class for help page in menu
{
    public:
        _help();
        virtual ~_help();

        double z;                      // z location of image
        int num = 0;                   // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float); // draw quad
        void helpInit(char *);         // load image

       _textureLoader *helpTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;     // texture coordinates

    protected:
    private:
};

#endif // _HELP_H
