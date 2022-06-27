#ifndef _DIGIT_H
#define _DIGIT_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_timer.h>
#include<_textureLoader.h>

class _digit
{
    public:
        _digit();
        virtual ~_digit();
        void drawDigit();
        void initDigit(char*);
        void showDigit(int num); // This function will be used to change
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xPos, yPos, zPos;
        float xSize, ySize;
        int frames;                         //sprite sheet frames

    protected:

    private:
        _textureLoader *textLoad = new _textureLoader();
};

#endif // _DIGIT_H
