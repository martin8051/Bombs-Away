#include "_score.h"
#include<_digit.h>
#include<vector>


_score::_score()
{
    //ctor
    score = 0;
    // Using 5 _digit class to show 5 digit score after game over and in high score
    for(int i=0; i<5; i++)
    {
        _digit *dig = new _digit();
        digits.push_back(dig);
    }
}

_score::~_score()
{
    //dtor
}

void _score::drawScore() {
    for(int i=0; i<5; i++)
    {
        digits[i]->drawDigit();
    }
}

void _score::initScore(char *fileName, int scoreVal) {
    score = scoreVal;  // Store the value of score

    // Initializes the values of every digit for all 5 digits
    for(int i=0; i<5; i++)
    {
        digits[i]->initDigit(fileName); // Initializes i'th digit using file name
        digits[i]->showDigit(scoreVal%10); // calculates i'th digit using given scoreValue
        scoreVal/=10;
    }
}

// To place digits of score as using their x,y,z positions
// space-> tells us the spacing between the digits that we want to show
// 0th digit will be right most digit
void _score::placeScore(float x, float y,float z,float space) {

    for(int i=0; i<5; i++)
    {
        /*
        if i==0 that means it is right most digit so place it at pos x
        else we will place other digits using the space value.
        means next digit will be placed previous_digit->xPos - spacing
        */
        digits[i]->xPos = i == 0? x : digits[i-1]->xPos-space;
        digits[i]->yPos = y;
        digits[i]->zPos = z;
    }
}

/* Takes the score and updates the score in the game over screen*/
void _score::changeScore(int val) {
    score = val;
    for(int i=0; i<5; i++)
    {
        digits[i]->showDigit(val%10);
        val/=10;
    }
}


/* Takes the xSize and ySize and resizes score*/
void _score::resizeScore(float x, float y) {
    for(int i=0; i<5; i++)
    {
        digits[i]->xSize = x;
        digits[i]->ySize = y;
    }
}
