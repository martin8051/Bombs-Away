#include "_1retry_or_menu.h"

//constructor initializes sizes for retry screen
_1retry_or_menu::_1retry_or_menu()
{
    scrollSpeed = 0.0001;                     //rate at which losing screen will scroll when player dies
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = 1.5;
    ySize = 0.75;
    xPos = -0.8;                            //center of screen
    yPos = -2.8;                            //y = -2.8 keeps screen out of sight until it is to scroll up
    zPos = -3.5;
}

_1retry_or_menu::~_1retry_or_menu()
{
    //dtor
}

//openGL retry screen
void _1retry_or_menu::drawRetyScreen()
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

//openGL init
void _1retry_or_menu::initRetry(char* fileName)
{
    texture->loadTexture(fileName);
}

//function to make screen scroll up once player has died
void _1retry_or_menu::scrollUp()
{
    if (yPos <= -1.0) { //scroll scene until it hits desired location
        yPos = yPos + scrollSpeed;
    }
}

