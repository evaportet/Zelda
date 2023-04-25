#pragma once
#include "Player.h"
#include "Vector2.h"
#include <string>
#include <assert.h>

#define WALL 'X'
#define DOOR 'P'
#define PLAYERUP '^'
#define PLAYERDOWN 'v'
#define PLAYERLEFT '<'
#define PLAYERRIGHT '>'
#define EMPTY ' '

enum class ROOMTYPE
{
    CLASS,
    HALL,
    CAFETERIA
};

class Map
{
private:
    std::string path;
    ROOMTYPE type;

    int height;
    int width;
    int numEnemies;
    char **map;

    Player *player;

    int doors;
    Vector2 *doorPos[];

    //TODO Load map settings from TXT
    bool LoadFromTXT();

public:
    Map(std::string path, ROOMTYPE type, Player* player);
    ~Map();

    int Update();
    void Draw();
};