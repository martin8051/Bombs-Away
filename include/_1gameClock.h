#ifndef _1GAMECLOCK_H
#define _1GAMECLOCK_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_1timer.h>
#include<_1textureLoader.h>

//gameClock will be used by each digit image
class _1gameClock
{
    public:
        _1gameClock(int);
        void start();
        virtual ~_1gameClock();
        void drawClock();
        void initClock(char*);
        void tickClock();                   //tick clock will be used by last digit as it will be reliant on a timer
        void dependClock(float, bool);      //other digits will use this to count down
        void stopClock();                   //used to stop gameclock (when scene ends)
        void pause();                       //used to pause gameCLock (when scene is paused)
        void resume();                      //resume clock (when scene is unpaused)
        bool run, clockFlip;                //bools to initiate clock running and flip digits
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xPos, yPos, zPos;
        float xSize, ySize;
        int frames;                         //sprite sheet frames


    protected:

    private:
};

#endif // _GAMECLOCK_H
