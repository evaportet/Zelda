#pragma once
#include "Vector2.h"
#include "Direction.h"
#include <windows.h>
#include <iostream>


class Player
{
private:

    Direction direction;
    Vector2 pos;
    Vector2 intendedPos;
    Vector2 prevPos;
    Vector2 attackPos;

    int lives = 5;
    int score = 0;
    bool isAttackng = false;
    bool hasWon = false;
      
public:
     Player(int initialX, int initialY) : pos(initialX, initialY), intendedPos(initialX,initialY), prevPos(initialX, initialY), attackPos(initialX, initialY), direction(Direction::Up) {}
    ~Player();

    Direction getDirection();
    //Input Manager
    void gotoxy(int x, int y);

    Vector2 getPos();
    Vector2 getIntendedPos();
    Vector2 getPrevPos();
    Vector2 getAttackPos();
    bool IsAttacking();

    //Para el cambio de escenas
    int getPlayerLives();
    bool getHasWon();
    void OverridePos(int newX, int newY);

    //Para las pots
    void AddScore(int amount);
    int getScore();
    //int totalGems = 0;

    void setLives(int amount);

    void Movement();
    void AttemptMove(int x, int y);

    void Update();
    void Draw();

    
};