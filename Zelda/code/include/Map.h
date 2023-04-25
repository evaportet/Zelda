#pragma once
#include "Player.h"
#include <string>

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

    bool LoadFromTXT();

public:
    Map(std::string path, ROOMTYPE type, Player* player);
    ~Map();

    void Update();
    void Draw();
};