#include "_imageLoader.h"



_imageLoader::_imageLoader()
{
    //ctor
    xRotation, yRotation, zRotation = 0.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    xSize = 1.4;
    ySize = 0.7;
    xPos = -1.3;
    yPos = 1.05;
    zPos = -4.05;
}

_imageLoader::~_imageLoader()
{
    //dtor
}

void _imageLoader::initImage(char *fileName) {
    imageTexture->loadTexture(fileName);
}

void _imageLoader::drawImage() {
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();  //ouping the Quad
    imageTexture->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotation,1.0,0.0,0.0);
    glRotatef(yRotation,0.0,1.0,0.0);
    glRotatef(zRotation,0.0,0.0,1.0);
    glScalef(xSize,ySize,1);

    glBegin(GL_QUADS);
      glTexCoord2f(xMin,yMax);
      glVertex3f(0, 0, 0);
      glTexCoord2f(xMax,yMax);
      glVertex3f(1, 0, 0);
      glTexCoord2f(xMax,yMin);
      glVertex3f(1, 1, 0);
      glTexCoord2f(xMin, yMin);
      glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();
}

// Changes the positions of and image as we don't want to set all variables directly from scene class
void _imageLoader::placeImage(float x,float y,float z) {
    xPos = x;
    yPos = y;
    zPos = z;
}


// Changes the size of an image as we don't want to set all variables directly from scene class
void _imageLoader::resizeImage(float x, float y) {
    xSize = x;
    ySize = y;
}


