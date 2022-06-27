#include "_credits.h"

_credits::_credits()
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_credits::~_credits()
{
    //dtor
}
void _credits::drawSquare(float width, float height)
{
    glColor3f(1.0,1.0,1.0);
    creditsTex->TextureBinder();
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

void _credits::creditsInit(char* fileName)
{
    creditsTex->loadTexture(fileName);
}
