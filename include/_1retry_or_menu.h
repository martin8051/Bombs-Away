#ifndef _1RETRY_OR_MENU_H
#define _1RETRY_OR_MENU_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

using namespace std;

class _1retry_or_menu
{
    public:
        _1retry_or_menu();
        virtual ~_1retry_or_menu();
        void drawRetyScreen();
        void initRetry(char*);
        void scrollUp();      //function to scroll scene upward

        _1textureLoader *texture = new _1textureLoader();
        float scrollSpeed;      //scroll speed for when scroll up is called
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _RETRY_OR_MENU_H

