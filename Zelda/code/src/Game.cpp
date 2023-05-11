#include "../include/Game.h"

Game::Game(std::string path)
{
	player = new Player(3, 4);
	loader = new MapLoader(path, rooms);
	maps = new Map[rooms];
	running = true;
}

Game::~Game()
{	delete[] maps;
	delete loader;
	delete player;

}

void Game::Start()
{
	if (!(loader->LoadMaps(maps))) {
		running = false;
		std::cout << "Error 404: file not found";
	}
	currentMap = CLASS;
	maps[currentMap].UpdatePlayer(player->getPos(), player->getPrevPos(), player->getDirection());
}

void Game::Update()
{
	player->Update();
	currentMap = maps[currentMap].Update();
	maps[currentMap].UpdatePlayer(player->getPos(), player->getPrevPos(), player->getDirection());
}

void Game::Draw()
{
	maps[currentMap].Draw();
}

void Game::FrameControl()
{
}
