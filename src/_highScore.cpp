#include "_highScore.h"

_highScore::_highScore() // initial coordinates for high score background image
{
    //ctor
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
    z = -15.0;
}

_highScore::~_highScore()
{
    //dtor
}
void _highScore::drawSquare(float width , float height) // draw quad for image
{
    glColor3f(1.0,1.0,1.0);
    highscoreTex->TextureBinder();
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

void _highScore::highScoreInit(char* fileName) // load image
{
    highscoreTex->loadTexture(fileName);
}
