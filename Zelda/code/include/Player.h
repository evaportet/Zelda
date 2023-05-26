#pragma once
#include "Vector2.h"
#include "InputManager.h"

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
    //input manager
    InputManager inputManager;

    Direction direction;
    Vector2 pos;
    Vector2 prevPos;

public:
     Player(int initialX, int initialY) : pos(initialX, initialY), prevPos(initialX, initialY), direction(Direction::Up) {}
    ~Player();

    Direction getDirection();
    Vector2 getPos();
    Vector2 getPrevPos();

    void Movement(const Vector2& pos);
    void Update();
};