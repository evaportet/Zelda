#include "../include/Map.h"

Map::Map(ROOMTYPE _type, Player* _player) : type(_type), player(_player)
{}

Map::~Map()
{
	delete player;

	// Delete 2D dynamic array
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

int Map::Update()
{
	int retrn;

	char playerChar;
	switch (player->getDirection())
	{
	case DIRECTION::UP:
	{
		playerChar = PLAYERUP;
		break;
	}
	case DIRECTION::DOWN:
	{
		playerChar = PLAYERDOWN;
		break;
	}
	case DIRECTION::LEFT:
	{
		playerChar = PLAYERLEFT;
		break;
	}
	case DIRECTION::RIGHT:
	{
		playerChar = PLAYERRIGHT;
		break;
	}
	}
	map[player->getPos().y][player->getPos().x] = playerChar;
	return 0;
}

void Map::UpdatePlayer(Vector2 playerPos, Vector2 prevPlayerPos, DIRECTION direction)
{
	map[prevPlayerPos.y][prevPlayerPos.x] = EMPTY;

	char playerChar;

	switch (player->getDirection())
	{
	case DIRECTION::UP:
	{
		playerChar = PLAYERUP;
		break;
	}
	case DIRECTION::DOWN:
	{
		playerChar = PLAYERDOWN;
		break;
	}
	case DIRECTION::LEFT:
	{
		playerChar = PLAYERLEFT;
		break;
	}
	case DIRECTION::RIGHT:
	{
		playerChar = PLAYERRIGHT;
		break;
	}
	}
	map[playerPos.y][playerPos.x] = playerChar;
}

void Map::Draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; i < width; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}


void Map::SetMap(int h, int w, int enemies, ROOMTYPE _type) {
	height = h;
	width = w;
	numEnemies = enemies;
	type = _type;

	// Declare 2d dynamic array
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
	}

	// Set all walls
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || x == 0 || y == height - 1 || x == width - 1)
				map[y][x] = WALL;
			else
				map[y][x] = EMPTY;
			switch (this->type)
			{
			case ROOMTYPE::HALL:
			{
				doors = 2;
				doorPos = new Vector2[doors];
				if (width % 2 == 0)
				{
					map[0][width / 2] = DOOR;
					doorPos[0].x = width / 2;
					doorPos[0].y = 0;
					map[height - 1][width / 2] = DOOR;
					doorPos[1].x = width / 2;
					doorPos[1].y = height - 1;
				}
				else
				{
					map[0][(width / 2) + 1] = DOOR;
					doorPos[0].x = (width / 2) + 1;
					doorPos[0].y = 0;
					map[height - 1][(width / 2) + 1] = DOOR;
					doorPos[1].x = (width / 2) + 1;
					doorPos[1].y = height - 1;
				}
				break;
			}
			case ROOMTYPE::CAFETERIA:
			{
				doors = 1;
				doorPos = new Vector2[doors];
				if (width % 2 == 0)
				{
					map[height - 1][width / 2] = DOOR;
				}
				else
				{
					map[height - 1][(width / 2) + 1] = DOOR;
					doorPos[0].x = (width / 2) + 1;
					doorPos[0].y = height - 1;
				}
				break;
			}
			case ROOMTYPE::CLASS:
			{
				doors = 1;
				doorPos = new Vector2[doors];
				if (width % 2 == 0)
				{
					map[0][width / 2] = DOOR;
				}
				else
				{
					map[0][(width / 2) + 1] = DOOR;
					doorPos[0].x = (width / 2) + 1;
					doorPos[0].y = 0;
				}
				break;
			}
			}
		}
	}
}