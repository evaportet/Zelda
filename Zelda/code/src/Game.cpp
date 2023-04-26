#include "../include/Game.h"

Game::Game(std::string path)
{
    loader = new MapLoader(path, rooms);
    maps = new Map[rooms];
    running = true;
}

Game::~Game()
{
    delete[] maps;
    delete loader;
    delete player;
}

void Game::Start()
{
    if (!(loader->LoadMaps(maps))) {
        running = false;
        std::cout << "Error 404: file not found";
    }
    player = new Player();
    currentMap = CLASS;
    maps[currentMap].SetPlayer(player);

}

void Game::Update()
{
    player->Update();
    currentMap = maps[currentMap].Update();

}

void Game::Draw()
{
    maps[currentMap].Draw();
}

void Game::FrameControl()
{
}
