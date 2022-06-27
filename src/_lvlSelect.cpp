#include "_lvlSelect.h"

#include "_Landing.h"
#include "_timer.h"

_lvlSelect::_lvlSelect() //INITIAL X,Y,Z COORDINATES
{
     //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -3.0;
}

_lvlSelect::~_lvlSelect()
{
    //dtor
}

void _lvlSelect::drawSquare(float width, float height)  //draw quad for image
{
    glColor3f(1.0,1.0,1.0);
    lvlTex->TextureBinder();
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

void _lvlSelect::levelInit(char* fileName) // load image
{
    lvlTex->loadTexture(fileName);
}

