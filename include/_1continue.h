#ifndef _1CONTINUE_H
#define _1CONTINUE_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

class _1continue
{
    public:
        _1continue();
        virtual ~_1continue();
        void drawContinueScreen();
        void initContinueScreen(char*);
        void scrollUp();

        _1textureLoader *texture = new _1textureLoader();
        float scrollSpeed;
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _CONTINUE_H
