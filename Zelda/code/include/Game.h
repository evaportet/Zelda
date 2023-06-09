#pragma once
#include "Map.h"
#include "Player.h"
#include "MapLoader.h"

enum CURRENT
{
    CLASS = 0,
    HALL = 1,
    CAFETERIA = 2
};

class Game
{
private:
    int rooms = 3;
    int currentMap;
    Map *maps;
    MapLoader *loader;
    Player* player;

public:
    Game(std::string path);
    ~Game();

    bool running;

    void Start();
    //TODO finish change scene
    void Update();
    void Draw();
    //TODO framecontrol
    void FrameControl();
};