#include "_1pauseMenu.h"

//pause menu constructor initializes sizes/positions
_1pauseMenu::_1pauseMenu()
{
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = 1.5;
    ySize = 0.65;
    xPos = -0.8;
    yPos = 3.0;
    zPos = -3.5;
    counter = 0;
}

_1pauseMenu::~_1pauseMenu()
{
    //dtor
}

void _1pauseMenu::drawPauseMenu()
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

void _1pauseMenu::initPauseMenu(char* fileName)
{
    texture->loadTexture(fileName);
}

