#include "_1health.h"

_1textureLoader *texture = new _1textureLoader();

//health constructor
_1health::_1health()
{

    xPos = -3.0;        //positions
    yPos = 1.4;
    zPos = -4.1;

    frames = 6;         //# sprite sheet frames
    xSize = 1.0;        //screen sizes
    ySize = .2;
    xRotate = yRotate = zRotate = 0.0;

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0/frames;
}

_1health::~_1health()
{
    //dtor
}

//function to set health image sprite sheet dimensions to proper positions.
//parameter is the player's # of lives, passed from the scene.
void _1health::healthStatus(int lives)
{
    if(lives == 5)
    {
        yMin = 0.0/frames;
        yMax = 1.0/frames;
    }
    else if (lives == 4) {
        yMin = 1.0/frames;
        yMax = 2.0/frames;
    }
    else if (lives == 3) {
        yMin = 2.0/frames;
        yMax = 0.5;
    }
    else if (lives == 2) {
        yMin = 0.5;
        yMax = 4.0/frames;
    }
    else if (lives == 1) {
        yMin = 4.0/frames;
        yMax = 5.0/frames;
    }
    else if (lives == 0) {
        yMin = 5.0/frames;
        yMax = 1.0;
    }
}

//openGL draw function
void _1health::drawHealth()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    texture->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotate,1.0,0.0,0.0);
    glRotatef(yRotate,0.0,1.0,0.0);
    glRotatef(zRotate,0.0,0.0,1.0);
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

//openGL texture initialize function
void _1health::initHealth(char* fileName) {
    texture->loadTexture(fileName);
}
