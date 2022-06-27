#include "_intro2.h"

_intro2::_intro2() // initial coordinates for level 2 intro page
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_intro2::~_intro2()
{
    //dtor
}
void _intro2::drawSquare(float width, float height) // draw quad for image
{
    glColor3f(1.0,1.0,1.0);
    intro2Tex->TextureBinder();
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

void _intro2::_intro2Init(char* fileName) // load image
{
     intro2Tex->loadTexture(fileName);
}
