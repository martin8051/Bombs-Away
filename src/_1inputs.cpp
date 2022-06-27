#include "_1inputs.h"

_1inputs::_1inputs()
{
    //ctor
    Mouse_Rotate=false;
    Mouse_Translate=false;
}

_1inputs::~_1inputs()
{
    //dtor
}

//input call for when key is pressed
void _1inputs::keyEnv(_1parallax* plx, float speed)
{
    switch(wParam){
            case VK_LEFT:
            plx->xMin +=speed;
            plx->xMax +=speed;
            break;
        case VK_RIGHT:
            plx->xMin -=speed;
            plx->xMax -=speed;
             break;
        case VK_DOWN:
            break;
        case VK_UP:
            break;
    }
}

void _1inputs::keyPressed(_1player* ply, int scene)
{
        switch(wParam)
    {
        case VK_LEFT:
            ply->action=0;
            break;
        case VK_RIGHT:
            ply->action=1;
             break;
        case VK_SHIFT:
            if(scene > 1)
            {
            ply->isShiftHeld = true;
            }
            break;
        case VK_DOWN:
            break;
        case VK_UP:
            break;
    }
}
void _1inputs::keyUp(_1player* ply)
{
    if(wParam == VK_RIGHT|| wParam == VK_LEFT)
    {
    ply->action=3;
    }
    else if (wParam == VK_SHIFT)
    {
        ply->isShiftHeld = false;
    }
}


void _1inputs::keyUp()   // Fill this depending on your game actions
{
    switch(wParam)
    {
        default: break;
    }
}

//input that deals with pausing game
void _1inputs::pause(_1pauseMenu *pause, _1player *ply, _1enms enms[], _1gameClock *gameClock, _gameTimer *gameTimer, float initialY, float pauseY, int currentScene) {

    if (currentScene == 1)
    {
        if (wParam == VK_ESCAPE) {
            pause->counter++;   //when esc is hit in scene, esc counter++
            if (pause->counter % 2 == 1) {  //if odd number of presses, game is paused
                pause->yPos = pauseY;       //bring up pause menu
                for (int i = 0; i < 15; i++) {  //freeze all bombs in scene
                    enms[i].yMove = 0.0;
                    enms[i].timerPause();       //pause animation timer if bomb is exploding
                }
                gameClock->pause();             //pause game clock
                ply->runSpeed = 0.0;            //set player run speed to 0
            }
            else {  //when counter is even, game is un-paused
                pause->yPos = initialY; //move pause menu above the scene to its initial Y-values
                for (int i = 0; i < 15; i++) {  //set all bombs move speeds back to original
                    enms[i].yMove = -0.0009;
                    enms[i].timerUnpause();     //unpause animation timer if bomb is exploding
                }
                gameClock->resume();            //resume clock
                ply->runSpeed = 0.08;           //set player run speed back to original
            }
        }
    } else if (currentScene == 2)
    {
        if (wParam == VK_ESCAPE) {
        pause->counter++;   //when esc is hit in scene, esc counter++
        if (pause->counter % 2 == 1) {  //if odd number of presses, game is paused
            pause->yPos = pauseY;       //bring up pause menu
            for (int i = 0; i < 25; i++) {  //freeze all bombs in scene
                    enms[i].yMove = 0.00000;
                    enms[i].timerPause();
            }
            gameClock->pause();             //pause game clock
            ply->runSpeed = 0.0;            //set player run speed to 0
        }
        else {  //when counter is even, game is un-paused
            pause->yPos = initialY; //move pause menu above the scene to its initial Y-values
            for (int i = 0; i < 25; i++) {  //set all bombs move speeds back to original
                enms[i].yMove = enms[i].storeYmove; //reset yMove to its stored variable
                enms[i].timerUnpause();
            }
            gameClock->resume();            //resume clock
            ply->runSpeed = 0.08;           //set player run speed back to original
        }
    }

    }else if(currentScene == 3)
    {
        if (wParam == VK_ESCAPE) {
        pause->counter++;   //when esc is hit in scene, esc counter++
        if (pause->counter % 2 == 1) {  //if odd number of presses, game is paused
            pause->yPos = pauseY;       //bring up pause menu
            for (int i = 0; i < 35; i++) {  //freeze all bombs in scene
                    enms[i].yMove = 0.00000;
                    enms[i].timerPause();
            }
            gameTimer->pause();             //pause game clock
            ply->runSpeed = 0.0;            //set player run speed to 0
        }
        else {  //when counter is even, game is un-paused
            pause->yPos = initialY; //move pause menu above the scene to its initial Y-values
            for (int i = 0; i < 35; i++) {  //set all bombs move speeds back to original
                enms[i].yMove = enms[i].storeYmove; //reset yMove to its stored variable
                enms[i].timerUnpause();
            }
            gameTimer->resume();            //resume clock
            ply->runSpeed = 0.08;           //set player run speed back to original
        }
    }
    }
}

void _1inputs::mouseEventUp()
{
    Mouse_Rotate=false;
    Mouse_Translate=false;
}



