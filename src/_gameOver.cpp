#include "_gameOver.h"
#include<string>

_gameOver::_gameOver()
{
    //ctor
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = 4.0;
    ySize = 2.0;
    xPos = -2.0;
    yPos = 3.0;
    zPos = -4.05;
    scrollSpeed = 0.001;
}

_gameOver::~_gameOver()
{
    //dtor
}

void _gameOver::drawGameOver()
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

void _gameOver::initGameOver(char* fileName)
{
    texture->loadTexture(fileName);
}

// Scrolls down the game over screen
void _gameOver::scrollDown() {
    if (yPos >= -1.2) {
        yPos -= scrollSpeed;
    }
}
