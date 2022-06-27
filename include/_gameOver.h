#ifndef _GAMEOVER_H
#define _GAMEOVER_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>
#include<string>


class _gameOver
{
    public:
        _gameOver();
        virtual ~_gameOver();
        void initGameOver(char*);     // Initializes the game over screen
        void scrollDown();           // Scrolls down the game over screen
        void drawGameOver();         // Draws the game over screen
        _textureLoader *texture = new _textureLoader();
        float xRotation, yRotation, zRotation;
        float xMin, xMax, yMin, yMax;
        float xSize, ySize;
        float xPos, yPos, zPos;
        float scrollSpeed;               // Scroll speed

    protected:

    private:
};

#endif // _GAMEOVER_H
