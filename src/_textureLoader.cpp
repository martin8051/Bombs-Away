#include "_textureLoader.h"

_textureLoader::_textureLoader()
{
    //ctor
}

_textureLoader::~_textureLoader()
{
    //dtor
}
void _textureLoader::loadTexture(char* fileName)
{
    glGenTextures(1,&tex);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);


    glBindTexture(GL_TEXTURE_2D, tex);
    image = SOIL_load_image(fileName,&width,&height, 0,SOIL_LOAD_RGBA);

    if(!image)cout<<"fail to find image"<<endl;


    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glEnable(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void _textureLoader::TextureBinder()
{
    glBindTexture(GL_TEXTURE_2D,tex);
}
