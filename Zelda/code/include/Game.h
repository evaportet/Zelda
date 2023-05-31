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
    Map **maps;
    GameState currentState;
    Player* player;

public:
    Game(std::string path);
    ~Game();

    bool running;

    void Start();
    void Update();
    void Draw();

    void FrameControl();
    Player* GetPlayer();
};