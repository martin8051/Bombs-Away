#ifndef _1LOSE_H
#define _1LOSE_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

//losing-scene picture's class
class _1lose
{
    public:
        _1lose();
        virtual ~_1lose();
        void drawLoseScreen();
        void initLost(char*);
        void scrollDown();      //function to scroll scene downward

        _1textureLoader *texture = new _1textureLoader();
        float dropSpeed;
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif
