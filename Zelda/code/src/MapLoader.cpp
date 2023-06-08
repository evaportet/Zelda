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
		int  lives, ganonHits;
		char dump;
		file >> lives;
		file >> dump;
		file >> ganonHits;
		file >> dump;
		player->setLives(lives);
		Ganon* ganon = new Ganon();
		ganon->SetLifes(ganonHits);
		//std::cout << lives <<"," << ganonHits<<",";

		for (int i = 0; i < rooms; i++) {
			int height, width, numEnemies, pots;
			file >> height;
			file >> dump;
			file >> width;
			file >> dump;
			file >> numEnemies;
			file >> dump;
			file >> pots;
			file >> dump;

			//std::cout << height << "," << width << "," << numEnemies<<","<<pots;
			//maps[i] = nullptr;
			switch (i)
			{
			case 0: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::CLASS, pots, ganon);
				break;
			}
			case 1: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::HALL, pots, ganon);
				break;
			}
			case 2: {
				maps[i] = new Map(player, height, width, numEnemies, ROOMTYPE::CAFETERIA, pots, ganon);
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
