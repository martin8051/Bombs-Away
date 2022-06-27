#ifndef _GAMETIMER_H
#define _GAMETIMER_H

#include<iostream>
#include<gl/gl.h>
#include<windows.h>
#include<_timer.h>
#include<_textureLoader.h>
#include<_digit.h>
#include<vector>
#include<string>

//gameClock will be used by each digit image
class _gameTimer
{
    public:
        _gameTimer(int,char,int);
        virtual ~_gameTimer();
        void rePosGameTimer(float,float); // repositions game timer
        void changeScore();   // changes the game timer score
        void drawGameTimer();     // draws the game timer
        void initGameTimer(char*);    // Initializes the game timer
        void stopGameTimer();                 //used to stop game timer (when scene ends)
        void pause();                       //used to pause game timer (when scene is paused)
        void resume();                      //resume game timer (when scene is unpaused)
        int frames;                         //sprite sheet frames
        vector<_digit*> digits;
        int score,numberOfDigits;        // current score and no of digits we want to show
        char gameTimerType;              // 'A' or 'B'
        bool run;                        // To check whether game is running or not


    protected:

    private:
        _timer *gameTime = new _timer();
};

#endif // _GAMECLOCK_H
