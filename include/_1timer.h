#ifndef _1TIMER_H
#define _1TIMER_H
#include<time.h>

class _1timer
{
    public:
        _1timer();
        virtual ~_1timer();

        clock_t startAt;
        clock_t pauseAt;

        bool started;       //started flag
        bool paused;        //pause flag

        bool isStarted();   //check if timer has started
        bool isStoped();    //check if timer is stopped
        bool isSpaused();   //check if timer is paused

        void pause();   //pause timer
        void resume();  //resume timer
        void start();   //start timer
        void stop();    //stop timer
        void reset();   //timer reset

        clock_t getTicks();


    protected:

    private:
};

#endif // _TIMER_H
