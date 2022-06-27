#include "_1player.h"

_1textureLoader *T = new _1textureLoader();
_1timer *tmr = new _1timer();

_1player::_1player()
{
    //ctor
    isShiftHeld = false;
    verticies[0].x=0.0; verticies[0].y=0.0;verticies[0].z=0.0;
    verticies[1].x=1.0; verticies[1].y=0.0;verticies[1].z=0.0;
    verticies[2].x=1.0; verticies[2].y=1.0;verticies[2].z=0.0;
    verticies[3].x=0.0; verticies[3].y=1.0;verticies[3].z=0.0;

    runSpeed = 0.08; //default run speed
    sprintSpeed = 0.12;   //increased speed for sprint

    xPos=-0.3;   //x position of the Player
    yPos=-1.5;   //y position of the Player
    zPos=-4.0;   //z position of the Player

    xSize =0.5;
    ySize =0.5;

    xRotation=0.0;
    yRotation=0.0;
    zRotation=0.0;

    action = -1;

    frames = 10.0;
    xMin=0.0;
    yMin=0.0;
    yMax=1.0/8;
    xMax=1.0/frames;
    numLives = 5;
}

_1player::~_1player()
{
    //dtor
}

//to set player where needed, (though unused)
void _1player::placePlayer()
{

}

//function to make player lay down after dying
void _1player::layDown() {
    if (xPos < -2.5) {
        xPos = -2.5;
    }

    xMin = 2.0/frames;  //set correct sprite sheet coordinates
    xMax = 3.0/frames;
    yMin = 3.0/8.0;
    yMax = 4.0/8.0;

    zRotation = 90.0;   //rotate player onto his back
    runSpeed = 0.0;     //set run speed to zero to not allow scene movement
}

//openGL draw function
void _1player::drawPlayer()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    T->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotation,1.0,0.0,0.0);
    glRotatef(yRotation,0.0,1.0,0.0);
    glRotatef(zRotation,0.0,0.0,1.0);
    glScalef(xSize,ySize,1);

    glBegin(GL_QUADS);
      glTexCoord2f(xMin,yMax);
      glVertex3f(verticies[0].x, verticies[0].y,verticies[0].z);
      glTexCoord2f(xMax,yMax);
      glVertex3f(verticies[1].x, verticies[1].y,verticies[1].z);
      glTexCoord2f(xMax,yMin);
      glVertex3f(verticies[2].x, verticies[2].y,verticies[2].z);
      glTexCoord2f(xMin, yMin);
      glVertex3f(verticies[3].x, verticies[3].y,verticies[3].z);
    glEnd();
    glPopMatrix();

}

//openGL initialization function
void _1player::initPlayer(char *fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->loadTexture(fileName);
    tmr->start();
}

//player actions
void _1player::actions()
{
    switch(action)
    {

        case 0: //move left case
            if (runSpeed != 0) {    //this evaluation keeps player static when laying down
                if(isShiftHeld)
                {
                    runSpeed = 0.15;
                } else
                {
                    runSpeed = 0.08;
                }
                if(tmr->getTicks()>60)
                {
                xMin+=1.0/frames;
                xMax+=1.0/frames;
                yMin= 5.0/8.0;
                yMax= 6.0/8.0;
                if (xPos > -2.9) {  //if player is within camera range, allow movement
                    xPos = xPos - runSpeed;
                }
                if(xMax<=0.0){xMin=9.0/frames; xMax=1.0;}   //reset sprite walking animation

                tmr->reset();
                }
            }
         break;

        case 1: //move right case
            if (runSpeed != 0) {    //this evaluation keeps player static when laying down
                if(isShiftHeld)
                {
                    runSpeed = 0.15;
                } else
                {
                    runSpeed = 0.08;
                }
                if(tmr->getTicks()>60)
                {
                xMin+=1.0/frames;
                xMax+=1.0/frames;
                yMin= 7.0/8.0;
                yMax= 1.0;
                if (xPos < 2.4) {  //if player is within camera range, allow movement
                    xPos = xPos + runSpeed;
                }
                if(xMax>=1){xMin= 0.0; xMax=1.0/frames;}    //reset sprite walking animation

                tmr->reset();
                }
            }
            break;

        case 3: //standing still case
        if (runSpeed != 0) {       //this evaluation keeps player static when laying down
            frames = 10.0;
            xMin=0.0;
            yMin=0.0;
            yMax=1.0/8;
            xMax=1.0/frames;
            break;
        }

    }

}
