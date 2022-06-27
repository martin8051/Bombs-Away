#include "_1continue.h"

_1continue::_1continue()
{
    scrollSpeed = 0.0001;                   //rate at which losing screen will scroll when player wins
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = 1.5;                            //sizes of the continue screen
    ySize = 0.75;
    xPos = -0.8;                            //center of screen
    yPos = -2.8;                            //y = -2.8 keeps screen out of sight until it is to scroll up
    zPos = -3.5;
}

_1continue::~_1continue()
{
    //dtor
}

//openGL draw function
void _1continue::drawContinueScreen()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    texture->TextureBinder();

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
void _1continue::initContinueScreen(char* fileName)
{
    texture->loadTexture(fileName);
}

//scrolls continue function up
void _1continue::scrollUp()
{
    if (yPos <= -1.2) {     //scroll to this point
        yPos = yPos + scrollSpeed;
    }
}
