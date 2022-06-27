#include "_1gameClock.h"

_1textureLoader *text = new _1textureLoader();
_1timer *gameTime = new _1timer();

//game clock constructor. Takes in an integer as parameter.
//integer dictates correct sprite sheet coordinates and scene placement.
_1gameClock::_1gameClock(int digit)
{
    yMin = 0.0;
    yMax = 1.0;
    xSize = 0.22;
    ySize = 0.35;
    yPos = 1.05;
    zPos = -4.1;
    frames = 10;
    run = true;
    if (digit == 1) {       //place digit one in proper place
        xPos = -0.28;
        xMin = 6.0/frames;
        xMax = 7.0/frames;
    }
    else if (digit == 2) {
        xPos = -0.03;       //place digit two in proper place
        xMin = 0.0;
        xMax = 1.0/frames;
    }
}

_1gameClock::~_1gameClock()
{
    //dtor
}

//to pause the game clock
void _1gameClock::pause() {
    gameTime->pause();
}

//to resume the game clock
void _1gameClock::resume() {
    gameTime->resume();
}

//openGL draw function
void _1gameClock::drawClock()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    text->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotation,1.0,0.0,0.0);
    glRotatef(yRotation,0.0,1.0,0.0);
    glRotatef(zRotation,0.0,0.0,1.0);
    glScalef(xSize,ySize,1);

    glBegin(GL_QUADS);
      glTexCoord2f(xMin,yMax);
      glVertex3f(0, 0, 0);
      glTexCoord2f(xMax,yMax);
      glVertex3f(1, 0, 0);
      glTexCoord2f(xMax,yMin);
      glVertex3f(1, 1, 0);
      glTexCoord2f(xMin, yMin);
      glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();
}

//openGL initialize function
void _1gameClock::initClock(char* fileName)
{
    text->loadTexture(fileName);
}

//function to stop game clock when scene ends
void _1gameClock::stopClock() {
    clockFlip = false;
    run = false;
    gameTime->stop();
}

void _1gameClock::start()
{
    clockFlip = true;
    run = true;
    gameTime->start();
}


//tick clock will be used by the last digit of the scene,
//since that digit will be the only one actually counting.
void _1gameClock::tickClock()
{
        clockFlip = false;      //clock flip set to false by default so dependClock doesn't continue to change
        if (!gameTime->isStarted()) {   //start clock is
        gameTime->start();
        }
        if (run == true) {      //if clock is running
            if(gameTime->getTicks()>1000) { //if a second has passed
                xMin-=1.0/frames;           //change sprite values
                xMax-=1.0/frames;
                if(xMax <= 0.0){            //reset sprite dimensions for when sprite is going from 9 to 0
                xMax = 1.0;
                xMin = 9.0/frames;
                clockFlip = true;           //clockFlip being set to true allows depending digits to flip
            }
           gameTime->reset();               //reset trailing digits timer
            }
        }
}

//digit sprite sheet movement for all digits that aren't the last.
//they will take in the floats of trailing digit
void _1gameClock::dependClock(float digitTwo, bool clockFlip)
{
    if (clockFlip == true) {    //clockFlip ensures only one flip is made when previous digit switches to value that initiates change
        if (digitTwo == 1.0) {
            xMin -= 1.0/frames;     //move sprite sheet frames for depending digit
            xMax -= 1.0/frames;
        }
    }
}

