#ifndef _1PAUSEMENU_H
#define _1PAUSEMENU_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

class _1pauseMenu
{
    public:
        _1pauseMenu();
        virtual ~_1pauseMenu();
        void drawPauseMenu();
        void initPauseMenu(char*);
        _1textureLoader *texture = new _1textureLoader();

        int counter;                            //counter to keep track of how many times pause is hit (odd # = pause menu is up)
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _PAUSEMENU_H
