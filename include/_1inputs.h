#ifndef _1INPUTS_H
#define _1INPUTS_H

#include<windows.h>
#include<_1parallax.h>
#include<_1player.h>
#include<_1pauseMenu.h>
#include<_1enms.h>
#include<_1gameClock.h>
#include <_gameTimer.h>

class _1inputs
{
    public:
        _1inputs();
        virtual ~_1inputs();

        void keyPressed(_1player *, int);   // model handling
        void keyUp(_1player *);   // model handling
        void keyEnv(_1parallax *,float); // handles the background movement
        void keyUp();
        void pause(_1pauseMenu*, _1player*, _1enms[], _1gameClock*, _gameTimer *, float, float, int);    //function to pause game


        void mouseEventUp();

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Rotate;

        WPARAM wParam;


    protected:

    private:
};

#endif // _INPUTS_H
