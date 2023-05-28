#include "../include/MapLoader.h"

MapLoader* MapLoader::instance = nullptr;

MapLoader::MapLoader()
{
}

bool MapLoader::LoadMaps(Map *maps[], std::string path, Player* player)
{
	bool success = false;

	std::ifstream file;
	file.open(path);
	if (file.is_open())
	{
		success = true;
		char dump;
		for (int i = 0; i < rooms; i++) {
			int height, width, numEnemies;
			file >> height;
			file >> dump;
			file >> width;
			file >> dump;
			file >> numEnemies;
			file >> dump;
			//std::cout << height << "," << width << "," << numEnemies;
			//maps[i] = nullptr;
			switch (i)
			{
			case 0: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::CLASS);
				break;
			}
			case 1: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::HALL);
				break;
			}
			case 2: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::CAFETERIA);
				break;
			}
			}

		}
	}
	return success;
}

MapLoader* MapLoader::GetInstance()
{
	if (instance == nullptr)
		instance = new MapLoader();
	return instance;
}
