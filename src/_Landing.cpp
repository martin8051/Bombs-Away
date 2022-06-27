#include "_Landing.h"
#include "_timer.h"

_Landing::_Landing() //INITIAL X,Y,Z COORDINATES of landing page
{
     //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -2.0;
}

_Landing::~_Landing()
{

}

void _Landing::drawSquare(float width, float height)  //used to draw quad
{
    glColor3f(1.0,1.0,1.0);
    landTex->TextureBinder();
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

void _Landing::landingInit(char* fileName) // load image
{
    landTex->loadTexture(fileName);
}



