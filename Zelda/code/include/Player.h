#pragma once
#include "Vector2.h"
#include <windows.h>
#include <iostream>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Player
{
private:

    Direction direction;
    Vector2 pos;
    Vector2 prevPos;

public:
     Player(int initialX, int initialY) : pos(initialX, initialY), prevPos(initialX, initialY), direction(Direction::Up) {}
    ~Player();

    Direction getDirection();
    //Input Manager
    void gotoxy(int x, int y);

    Vector2 getPos();
    Vector2 getPrevPos();

    void Movement(Vector2& pos, int dx, int dy);
    void Update();
    void Draw();
};