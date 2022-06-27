#ifndef _1ENMS_H
#define _1ENMS_H

#include <GL/gl.h>
#include <_1textureLoader.h>
#include <_1timer.h>
#include <cstdlib>

class _1enms
{
    public:
        _1enms();
        virtual ~_1enms();

        void setSpeed();
        void drawEnemy();                       //draw object(s)
        void placeEnemy(float, float, float);   //Place enemy
        void initEnemy(GLuint);
        float RandFloat(float, float);          //used for randomized placement in scene
        void actions();                         //Movement/actions
        void actions2();                         //Movement/actions
        void timerPause();                      //pause bomb timer for pauses
        void timerUnpause();                    //unpause bomb timer for pauses
        bool isEnemyLive;                       //status of enemy
        GLuint EnemyTex;                        //handle texture
        float xPos, yPos, zPos;                 //placements
        float xSize, ySize;                     //scaling factor
        float rotateX, rotateY, rotateZ;        //rotations
        int frames;                             //# frames
        float storeYmove;                       //for storing y-moves when game is paused
        float yMove;                            //y-axis movement speed
        int action;                             //to generate an action
        int bombStatus;

        _1timer *TE = new _1timer();
    protected:

    private:
        float xMin, yMin, xMax, yMax;
};

#endif // _ENMS_H
