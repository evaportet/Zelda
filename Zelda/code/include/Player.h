#pragma once
#include "Vector2.h"
#include "InputManager.h"

enum class DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player
{
private:
    //input manager
    InputManager inputManager;


    DIRECTION direction;
    Vector2 pos;
    Vector2 prevPos;

public:
    Player(int initialX, int initialY) : pos(initialX, initialY), prevPos(initialX, initialY), direction(DIRECTION::UP) {}
    ~Player();

    //TODO declare functions
    DIRECTION getDirection();
    Vector2 getPos();
    Vector2 getPrevPos();
    void Movement(const Vector2& pos);
    void Update();
};