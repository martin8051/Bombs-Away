#include "_intro3.h"

_intro3::_intro3()  // initial coordinates for level 3 intro page
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_intro3::~_intro3()
{
    //dtor
}

void _intro3::drawSquare(float width, float height) // draw quad for image
{
    glColor3f(1.0,1.0,1.0);
    intro3Tex->TextureBinder();
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

void _intro3::_intro3Init(char* fileName) // load image
{
    intro3Tex->loadTexture(fileName);
}
