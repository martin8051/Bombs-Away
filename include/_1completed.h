#ifndef _1COMPLETED_H
#define _1COMPLETED_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

class _1completed
{
    public:
        _1completed();
        virtual ~_1completed();
        void drawCompleted();
        void initCompleted(char*);
        void scrollDown();      //function to scroll scene downward

        _1textureLoader *texture = new _1textureLoader();
        float dropSpeed;                                //drop speed for completed scene
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _1COMPLETED_H
