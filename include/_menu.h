#ifndef _MENU_H
#define _MENU_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>

class _menu                              // used for games menu page
{
    public:
        _menu();
        virtual ~_menu();
        int num = 0;
        double z;                       // used to modify z value of picture
        void drawSquare(float, float);  // draw the quad of image
        void menuInit(char *);          // load images

       _textureLoader *menuTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;      // texture coordinates for menu page

    protected:
    private:
};

#endif // _MENU_H
