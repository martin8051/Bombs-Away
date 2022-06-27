#include "_intro1.h"

_intro1::_intro1() // initial coordinates for level 1 intro page
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_intro1::~_intro1()
{
    //dtor
}

void _intro1::drawSquare(float width, float height) // draw quad
{
    glColor3f(1.0,1.0,1.0);
    intro1Tex->TextureBinder();
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

void _intro1::_intro1Init(char* fileName) // load image
{
    intro1Tex->loadTexture(fileName);
}
