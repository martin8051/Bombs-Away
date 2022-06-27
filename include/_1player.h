#ifndef _1PLAYER_H
#define _1PLAYER_H

#include <GL/gl.h>
#include <_1textureLoader.h>
#include <_1timer.h>

typedef struct
{
    float x;
    float y;
    float z;
}vec3;

class _1player
{
    public:
        _1player();
        virtual ~_1player();

        float scale[3]={1.0,1.0,1.0};
        vec3 verticies[4];

        float xPos;   //x position of the Player
        float yPos;   //y position of the Player
        float zPos;   //z position of the Player

        float xSize;
        float ySize;

        float xRotation;
        float yRotation;
        float zRotation;

        int numLives;   //num lives for player
        float runSpeed; //default movement speed
        float sprintSpeed; //sprint speed

        void drawPlayer();  //for openGL draw function
        void placePlayer(); //coordinates to place player
        void initPlayer(char *);    //openGL initialization function
        void layDown();      //lay down function called when player dies

        void actions();   // may have to pass different frame numbers
        int action;          // give values for run jump etc.
        float frames;
        float xMax,xMin,yMax,yMin;
        bool isShiftHeld;

    protected:

    private:
};

#endif // _PLAYER_H
