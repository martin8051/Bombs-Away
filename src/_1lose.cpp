#include "_1lose.h"


_1lose::_1lose()
{
    dropSpeed = 0.0001;                     //rate at which losing screen will fall when player dies
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = ySize = 1.5;                    //screen size
    xPos = -0.8;                            //center of screen
    yPos = 1.8;                             //y = 1.8 keeps screen out of sight until it is to drop
    zPos = -3.5;
}

_1lose::~_1lose()
{

}

//function to call when losing screen animation plays
void _1lose::scrollDown() {
    if (yPos >= 0.0) {
        yPos = yPos - dropSpeed;
    }
}

//openGL draw scene
void _1lose::drawLoseScreen()
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

//openGL initialization
void _1lose::initLost(char* fileName)
{
    texture->loadTexture(fileName);
}
