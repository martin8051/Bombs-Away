#include "_1completed.h"

_1completed::_1completed()
{
    dropSpeed = 0.0001;                     //rate at which completed screen will fall when player dies
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;                        //sprite dimensions
    xMax = yMax = 1.0;
    xSize = 1.5;                             //screen sizes
    ySize = 0.6;
    xPos = -0.8;                            //center of screen
    yPos = 1.8;                             //y = 1.8 keeps screen out of sight until it is to drop
    zPos = -3.5;
}

_1completed::~_1completed()
{
    //dtor
}

//openGL draw function
void _1completed::drawCompleted()
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
void _1completed::initCompleted(char* fileName)
{
    texture->loadTexture(fileName);
}

//function to scroll screen down to wanted position
void _1completed::scrollDown()
{
    if (yPos >= 0.1) {
        yPos = yPos - dropSpeed;
    }
}
