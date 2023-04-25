#include "../include/Game.h"

Game::Game(std::string path)
{
    MapLoader *loader = new MapLoader(path);
    maps = new Map[rooms];
    running = true;
}

Game::~Game()
{
    delete[] maps;
    delete loader;
}

bool Game::Start()
{
    if (!(loader->LoadMaps(maps)))
        running = false;
    currentMap = CLASS;
}

void Game::Update()
{
    currentMap = maps[currentMap]->Update();
}

void Game::Draw()
{
    maps[currentMap]->Draw();
}

void Game::FrameControl()
{
}
