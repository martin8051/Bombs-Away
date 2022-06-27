#include "_gameTimer.h"
#include<_digit.h>
#include<vector>
#include<string>

/**
* Game Timer constructor. Takes in two integers, a character as parameters.
      1. number of digits that will be shown in game timer for us it will be 5.
      2. timer type:
            type A: Decreasing timer
            type B: Increasing timer
      3. takes an integer value -> for type 'A', it will be maximum value and for type 'B', will be minimum value[we can say it is initial score]
*/

_gameTimer::_gameTimer(int numberOfdigits,char gametimertype, int value)
{
    numberOfDigits = numberOfdigits;
    gameTimerType = gametimertype;
    score = value;
    run = true;
    for(int i=0; i<numberOfDigits; i++)
    {
        _digit *dig = new _digit();
        dig->xPos -= ((float)i * 0.25); // 0.25 is spacing between  two consecutive digits

        digits.push_back(dig);
    }
}

_gameTimer::~_gameTimer()
{
    //dtor
}

//to pause the game Timer
void _gameTimer::pause()
{
    run = false;
    gameTime->pause();
}

//to resume the game Timer
void _gameTimer::resume()
{
    run = true;
    gameTime->resume();
}

// Game timer draw function
void _gameTimer::drawGameTimer()
{
    int sz = digits.size(); // It will be size of digits vector basically 5.
    for(int i=0; i<sz; i++)
    {
        digits[i]->drawDigit();
    }
}

// Game timer initialize function
// We are basically initializing every digit
void _gameTimer::initGameTimer(char* fileName)
{
    int sz = digits.size();
    int value = score;
    for(int i=0; i<sz; i++)
    {
        digits[i]->initDigit(fileName);
        digits[i]->showDigit(value%10);
        value/=10;
    }
}

//function to stop game Timer when scene ends
void _gameTimer::stopGameTimer()
{
    run = false;
    gameTime->stop();
}


// Changes the score
void _gameTimer::changeScore()
{
    if (!gameTime->isStarted())     //start game timer
    {
        gameTime->start();
    }
    if (run == true)        //if game timer is running
    {
        if(gameTime->getTicks()>1000)   //if a second has passed
        {
            if(gameTimerType == 'A')      // Changing the score according to game timer type
                score--;
            else if(gameTimerType == 'B')
                score++;
            int scoreVal = score;
            int sz = digits.size();
            for(int i=0; i<sz; i++)     // Showing digits using sprite sheet and value according to the current score
            {
                digits[i]->showDigit(scoreVal%10);
                scoreVal/=10;
            }
            gameTime->reset();               //reset trailing digits timer
        }
    }
}

// Repositions the game timer by the value we want to reposition it
void _gameTimer::rePosGameTimer(float deltaX, float deltaY) {
    for(int i=0;i<numberOfDigits;i++) {
        digits[i]->xPos+=deltaX;
        digits[i]->xPos+=deltaY;
    }
}


