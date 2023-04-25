#pragma once
#include "Map.h"
#include "Player.h"
#include "MapLoader.h"

class Game{
private:
    int rooms = 4;
    Map* maps[];

public:
    Game(std::string path);
    ~Game();
};