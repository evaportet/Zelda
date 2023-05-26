#pragma once
#include "Map.h"
#include "Player.h"
#include "MapLoader.h"
#include <chrono>
#include <thread>

enum CURRENT
{
    CLASS = 0,
    HALL = 1,
    CAFETERIA = 2
};

enum class GameState
{
    SplashScreen,
    MainMenu,
    Game,
    GameOver
};

class Game
{
private:
    int rooms = 3;
    int currentMap;
    bool playSelected;
    Map *maps;
    MapLoader *loader;
    Player* player;
    GameState currentState;

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