#include "_1collisionFlag.h"

_1collisionFlag::_1collisionFlag()
{
    //ctor
}

_1collisionFlag::~_1collisionFlag()
{
    //dtor
}

//function to test if player and enemy have collided
bool _1collisionFlag::linearCollision(float x1, float y1, float x2, float y2) {
    //take the difference in y/x positions of bomb and player
    float xDiff = x1 - x2;
    float yDiff = y1 - y2;

    if (xDiff < 0) {    //use absolute value for comparison
        xDiff = xDiff * -1.0;
    }

    if (yDiff < 0) {    //use absolute value for comparison
        yDiff = yDiff * -1.0;
    }

    if (y2 <= -1.02) { //if bomb is withing striking distance on x-axis
        if (xDiff < 0.2) {  //if they're close enough on the x-axis
            return true;
        }
    }
    //else return false
    return false;
}

//function to test if bombs has hit the floor
bool _1collisionFlag::floorCollision(float yPos)
{
    if (yPos <= -1.475) {   //if yPos hits floor height, return true
        return true;
    }
    return false;
}
