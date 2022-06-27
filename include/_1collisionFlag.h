#ifndef _1COLLISIONFLAG_H
#define _1COLLISIONFLAG_H
#include <cmath>


class _1collisionFlag
{
    public:
        _1collisionFlag();
        virtual ~_1collisionFlag();
        bool linearCollision(float, float, float, float);   //player collision test
        bool floorCollision(float);                         //floor collision test

    protected:

    private:
};

#endif // _COLLISIONFLAG_H
