#include "../include/Game.h"

Game::Game(std::string path)
{
	player = new Player(3, 5);
	loader = new MapLoader(path, rooms);
	maps = new Map[rooms];
	for (int i = 0; i < rooms; i++) {
		switch (i)
		{
		case 0:
			maps[i] = Map(ROOMTYPE::CLASS, player);
			break;
		case 1:
			maps[i] = Map(ROOMTYPE::HALL, player);
			break;
		case 2:
			maps[i] = Map(ROOMTYPE::CAFETERIA, player);
			break;
		default:
			break;
		}
	}
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
	currentMap = CLASS;
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
