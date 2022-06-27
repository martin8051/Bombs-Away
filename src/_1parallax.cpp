#include "_1parallax.h"



_1parallax::_1parallax()
{
    //ctor
    //initialize the texture coordinates
    xMax =0.0;
    yMax =0.0;
    xMin =1.0;
    yMin =1.0;
}

_1parallax::~_1parallax()
{
    //dtor
}

//openGL draw square function
void _1parallax::drawSquare(float width, float height)
{

    glColor3f(1.0,1.0,1.0);
    bTex->TextureBinder();
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, -1, -10.0);
    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, -1, -10.0);
    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, 1, -10.0);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, 1, -10.0);

    glEnd();


}

//openGL initialize function
void _1parallax::parallaxInit(char* fileName)
{
    bTex->loadTexture(fileName);
}

//scroll function takes in direction as a sting and moves scene in said direction
void _1parallax::scroll(bool Auto, string dir, float speed)
{
   if(Auto)     // To Address Automatic movement of the background
   {
       if(dir=="up")  // keyword "up"
       {
           yMin -=speed;
           yMax -=speed;
       }

        if(dir=="down")  // keyword "down"
       {
           yMin +=speed;
           yMax +=speed;
       }
        if(dir=="left")  // keyword "left"
       {
           xMin -=speed;
           xMax -=speed;
       }
        if(dir=="right")  // keyword "right"
       {
           xMin +=speed;
           xMax +=speed;
       }
   }
}
