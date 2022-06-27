#include "_menu.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

_menu::_menu()    //USED TO INITILIZE STARTING X,Y,Z COORDINATES
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -2.0;
}

_menu::~_menu()
{
    //dtor
}

void _menu::drawSquare(float width, float height) // used to draw quad
{
    glColor3f(1.0,1.0,1.0);
    menuTex->TextureBinder();
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, -1, z);

    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, -1, z);

    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, 1, z);

    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, 1, z);

    glEnd();
}

void _menu::menuInit(char* fileName)   // used to load image
{
     menuTex->loadTexture(fileName);
}
