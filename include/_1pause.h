#ifndef _1PAUSE_H
#define _1PAUSE_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

class _1pause
{
    public:
        _1pause();
        virtual ~_1pause();
        void drawPause();
        void initPause(char*);

        _1textureLoader *texture = new _1textureLoader();
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _PAUSE_H
