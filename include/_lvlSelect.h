#ifndef _LVLSELECT_H
#define _LVLSELECT_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>

using namespace std;

class _lvlSelect                            // level section page
{
    public:
        _lvlSelect();
        virtual ~_lvlSelect();
        double z;                           // used to modify z value of pic
        void drawSquare(float, float);      // draw quad
        void levelInit(char *);             // load image

       _textureLoader *lvlTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;          //  texture coordinates

    protected:

    private:
};
#endif // _LVLSELECT_H
