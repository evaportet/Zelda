#pragma once
#include "Vector2.h"
#include <windows.h>
#include <iostream>

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

    DIRECTION direction;
    Vector2 pos;
    Vector2 prevPos;

public:
    Player(int initialX, int initialY) : pos(initialX, initialY), prevPos(initialX, initialY), direction(DIRECTION::UP) {}
    ~Player();

    //Input Manager
    void gotoxy(int x, int y);

    //TODO declare functions
    DIRECTION getDirection();
    Vector2 getPos();
    Vector2 getPrevPos();

    void Movement(Vector2& pos, int dx, int dy);
    void Update();
    void Draw();
};