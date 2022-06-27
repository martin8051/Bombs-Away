#include "_help.h"

_help::_help()   // initial coordinates for help page
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_help::~_help()
{
    //dtor
}
void _help::drawSquare(float width, float height) // draw quad for image
{
    glColor3f(1.0,1.0,1.0);
    helpTex->TextureBinder();
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

void _help::helpInit(char* fileName) // load image
{
    helpTex->loadTexture(fileName);
}
