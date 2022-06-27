#include "_hsDigit.h"
#include <_glLight.h>

_hsDigit::_hsDigit() // initial coordinates for every digit of high score
{
    //ctor
    xMax =0.0;
    xMin =1.0;
    yMax =0.0;
    yMin =1.0;
    z = -15.0;
}

_hsDigit::~_hsDigit()
{
    //dtor
}
void _hsDigit::drawSquare(float width, float height) // draw quad of image
{
    glColor3f(1.0,1.0,1.0);
    hsDigitTex->TextureBinder();

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

void _hsDigit::hsDigitInit(char digit) // used to load image, each digit takes in char value (num) and loads correct digit image respectively
{
    switch(digit) // char values
    {
        case 48: // 0
        {
            hsDigitTex->loadTexture("images/digit/0.png");
            break;
        }
        case 49: // 1
        {
            hsDigitTex->loadTexture("images/digit/1.png");
            break;
        }
        case 50: // 2
        {
            hsDigitTex->loadTexture("images/digit/2.png");
            break;
        }
        case 51: // 3
        {
            hsDigitTex->loadTexture("images/digit/3.png");
            break;
        }
        case 52: // 4
        {
            hsDigitTex->loadTexture("images/digit/4.png");
            break;
        }
        case 53: // 5
        {
            hsDigitTex->loadTexture("images/digit/5.png");
            break;
        }
        case 54: // 6
        {
            hsDigitTex->loadTexture("images/digit/6.png");
            break;
        }
        case 55: // 7
        {
            hsDigitTex->loadTexture("images/digit/7.png");
            break;
        }
        case 56: // 8
        {
            hsDigitTex->loadTexture("images/digit/8.png");
            break;
        }
        case 57: // 9
        {
            hsDigitTex->loadTexture("images/digit/9.png");
            break;
        }
    }
}
