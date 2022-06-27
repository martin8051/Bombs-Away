#ifndef _1HEALTH_H
#define _1HEALTH_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_1textureLoader.h>

class _1health
{
    public:
        _1health();
        virtual ~_1health();
        void healthStatus(int);     //updates health sprite sheet relative to player health
        void drawHealth();          //to draw health on screen
        void drawSquare(float, float);
        void initHealth(char*);
        GLuint healthTex;


        int frames;
        float xRotate, yRotate, zRotate;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;

    protected:

    private:
};

#endif // _HEALTH_H
