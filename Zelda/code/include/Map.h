#pragma once
#include "Player.h"
#include "Vector2.h"
#include <string>
#include <assert.h>
#include <iostream>

#define WALL 'X'
#define DOOR 'P'
#define PLAYERUP '^'
#define PLAYERDOWN 'v'
#define PLAYERLEFT '<'
#define PLAYERRIGHT '>'
#define EMPTY ' '

enum class ROOMTYPE
{
    CLASS = 0,
    HALL = 1,
    CAFETERIA = 2
};

class Map
{
private:
    ROOMTYPE type;

    int height;
    int width;
    int numEnemies;
    char **map;

    Player *player;

    int doors;
    Vector2 *doorPos;

public:
    Map(ROOMTYPE _type, Player* _player);
    Map() = default;
    ~Map();

    int Update();
    void Draw();
    
    void SetPlayer(Player* _player);
    void SetMap(int height, int width, int numEnemies, ROOMTYPE _type);
};