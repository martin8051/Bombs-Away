#include "_1timer.h"

_1timer::_1timer()
{
    //ctor
    startAt =0;
    pauseAt =0;
    paused =false;
    started =false;
}

_1timer::~_1timer()
{
    //dtor
}

//check if timer has started
bool _1timer::isStarted()
{
    return started;
}

//check if timer is started
bool _1timer::isStoped()
{
    return !started;
}

//check if timer is paused
bool _1timer::isSpaused()
{
    return paused;
}

//pause timer
void _1timer::pause()
{
    if(paused || !started)
        return;
    paused = true;
    pauseAt= clock();

}

//resume the paused timer
void _1timer::resume()
{
    if(!paused)return;
    paused = false;
    startAt +=clock()-pauseAt;
}

//start timer if it hasn't started
void _1timer::start()
{
    if(started)return;
    started= true;
    paused = false;
    startAt= clock();

}

//stop timer
void _1timer::stop()
{
    started = false;
}

//reset the clock
void _1timer::reset()
{
    paused = false;
    startAt = clock();
}

//get ms of clock
clock_t _1timer::getTicks()
{
    if(!started)return 0;
    if(paused)return pauseAt - startAt;
    return clock()-startAt;
}
