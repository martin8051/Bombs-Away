#include "_digit.h"

// Initialization of variables
_digit::_digit()
{
    yMin = 0.0;
    yMax = 1.0;
    xSize = 0.22;
    ySize = 0.35;
    yPos = 1.3;
    zPos = -4.5;
    frames = 10;
    xPos = 0.55;
    xMin = 0.0;
    xMax = 1.0;
}

_digit::~_digit()
{
    //dtor
}

//openGL draw function
void _digit::drawDigit()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    textLoad->TextureBinder();
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
void _digit::initDigit(char* fileName)
{
    textLoad->loadTexture(fileName);
}

// Shows the specific digit from the digit image
// takes the digit from 0-9 and shows them
void _digit::showDigit(int num)
{

    xMin = ((float)num) / 10.0;
    xMax = ((float)num + 1.0)/10.0;
}
