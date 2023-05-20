#include "../include/Game.h"

Game::Game(std::string path)
{
	player = new Player(3, 5);
	maps = new Map[rooms];
	if (!(MapLoader::GetInstance()->LoadMaps(maps, path, player)))
	{
		std::cout << "Error moading maps";
		running = false;
	}
	else
		std::cout << "Map loading was successful";
	currentMap = CLASS;
	running = true;
}

Game::~Game()
{
	delete[] maps;
	delete player;
}

void Game::Start()
{
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

Player* Game::GetPlayer()
{
	return player;
}
