#pragma once
#include "Vector2.h"

enum class DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}

class Player
{
private:
    DIRECTION direction;
    Vector2 pos;
    Vector2 prevPos
public:
    Player();
    ~Player();
    //TODO declare functions
    DIRECTION getDirection();
    Vector2 getPos();
    Vector2 getPrevPos()
};