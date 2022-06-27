#include "_1enms.h"

_1timer *timer = new _1timer();

_1enms::_1enms()
{
    xPos = yPos = 0;
    zPos = -4.0;

    xSize = 0.15;
    ySize = 0.15;

    rotateX = rotateY = rotateZ = 0.0;

    yMove = -0.0009;       //bomb fall speed
    action = 1;             //default action causes bomb to continue to fall
    frames = 4.0;
    xMin=0.0;
    yMin=0.0;
    yMax=1.0;
    xMax=1.0/frames;
    bombStatus = 1.0;       //bomb status ensures bomb can't hit player multiple times while exploding
}

_1enms::~_1enms()
{
    //dtor
}

void _1enms::setSpeed()
{
    yMove = RandFloat(-0.0025, -0.001);
    storeYmove = yMove;
}


//returns random float between a and b.
//used for randomly placing bombs in scene.
float _1enms::RandFloat(float a, float b) {
    float low, high;
    if (a < b) {
        low = a;
        high = b;
    }
    else {
        low = b;
        high = a;
    }

    float random = ((float) rand()) / (float) RAND_MAX;
    float difference = high - low;
    float rand = random * difference;
    return low + rand;
}

//openGL drawn enemy
void _1enms::drawEnemy()
{
    glBindTexture(GL_TEXTURE_2D, EnemyTex);

    glPushMatrix();
            glTranslatef(xPos,yPos,zPos);
            glRotatef(rotateX, 1.0,0.0,0.0);
            glRotatef(rotateY, 0.0,1.0,0.0);
            glRotatef(rotateZ, 0.0,0.0,1.0);
            glScalef(xSize,ySize,1);
    glBegin(GL_POLYGON);
            glTexCoord2f(xMin,yMin);
            glVertex3f(1.0, 1.0, 0.0);
            glTexCoord2f(xMax,yMin);
            glVertex3f(-1.0, 1.0, 0.0);
            glTexCoord2f(xMax,yMax);
            glVertex3f(-1.0, -1.0, 0.0);
            glTexCoord2f(xMin,yMax);
            glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glPopMatrix();
}

//used to initialize enemy placement
void _1enms::placeEnemy(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
}

//pause timer for bomb animation (only if bomb action == 2)
void _1enms::timerPause()
{
   if (action == 2) {
        timer->pause();
   }
}

//unpause timer for bomb animation (only if bomb action == 2)
void _1enms::timerUnpause()
{
    if (action == 2) {
        timer->resume();
    }
}


//openGL texture initialization
void _1enms::initEnemy(GLuint tex)
{
    EnemyTex = tex;
}

void _1enms::actions2()
{
 switch (action) {
    case 1:
        bombStatus = 1;     //bomb can take player lives when status = 1
        xMin = 0.0;         //re-initialize correct sprite position after explosion for re-spawn
        xMax = 1.0/frames;
        yPos += yMove;      //movement
        break;
    case 2:
        bombStatus = 0;     //once explosion is initiated, bomb is no longer active
        if (!timer->isStarted()) {  //begin timer for explosion animation (if it just started)
        timer->start();
        }
        if(timer->getTicks()>80) {
            xMin+=1.0/frames;       //sprite movement for explosion
            xMax+=1.0/frames;
            if(xMax >= 1){          //once explosion is done, re-spawn bomb and set action back to 1 for movement/correct sprite placement
                placeEnemy(RandFloat(-2.95, 2.65), RandFloat(2.5, 6.0), -4.0);
                setSpeed();
                action = 1;
                timer->stop();  //stop/reset timer for next time bomb explodes
            }
           timer->reset();
        }

        break;
    }
}

//actions for enemy bombs
void _1enms::actions()
{
    switch (action) {
    case 1:
        bombStatus = 1;     //bomb can take player lives when status = 1
        xMin = 0.0;         //re-initialize correct sprite position after explosion for re-spawn
        xMax = 1.0/frames;
        yPos += yMove;      //movement
        break;
    case 2:
        bombStatus = 0;     //once explosion is initiated, bomb is no longer active
        if (!timer->isStarted()) {  //begin timer for explosion animation (if it just started)
        timer->start();
        }
        if(timer->getTicks()>80) {
            xMin+=1.0/frames;       //sprite movement for explosion
            xMax+=1.0/frames;
            if(xMax >= 1){          //once explosion is done, re-spawn bomb and set action back to 1 for movement/correct sprite placement
                placeEnemy(RandFloat(-2.95, 2.65), RandFloat(2.0, 5.0), -4.0);
                action = 1;
                timer->stop();  //stop/reset timer for next time bomb explodes
            }
           timer->reset();
        }

        break;
    }
}
