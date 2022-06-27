#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>


class _highScore                       // class for high score page background
{
    public:
        _highScore();
        virtual ~_highScore();

        double z;                      // z location of image
        int num = 0;                   // # OF TIMES intro 3 PAGE HAS BEEN OPENED/CLOSED : EVEN = CLOSED  ODD = OPEN
        void drawSquare(float, float); // draw quad
        void highScoreInit(char *);    // load image

       _textureLoader *highscoreTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;    // texture coordinates

};

#endif // _HIGHSCORE_H
