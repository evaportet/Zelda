#include "../include/Map.h"

Map::Map(Player* _player, int h, int w, int enemies, ROOMTYPE _type, int pots) : type(_type), player(_player), height(h), width(w), numEnemies(enemies), numPots(pots)
{
	// Declare 2d dynamic array
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
	}

	potArr = new Pots[numPots];

	// Set all walls
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (j == 0 || i == 0 || j == height - 1 || i == width - 1)
				map[j][i] = WALL;
			else
				map[j][i] = EMPTY;
		}
	}

	//Set doors
	switch (type)
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

	//Set player
	map[player->getPos().y][player->getPos().x] = PLAYERUP;

	//Gen gem pos
	for (int i = 0; i < numPots; i++) 
	{
		do {
			int randomX = rand() % (width - 2) + 1;
			int randomY = rand() % (height - 2) + 1;
			potArr[i].pos = Vector2(randomX, randomY);
		} while (potArr[i].pos == player->getPos());

		map[potArr[i].pos.y][potArr[i].pos.x] == VASE;
	}
}

Map::~Map()
{
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

	map[player->getPrevPos().y][player->getPrevPos().x] = EMPTY;

	char playerChar;
	switch (player->getDirection())
	{
	case Direction::Up:
	{
		playerChar = PLAYERUP;
		break;
	}
	case Direction::Down:
	{
		playerChar = PLAYERDOWN;
		break;
	}
	case Direction::Left:
	{
		playerChar = PLAYERLEFT;
		break;
	}
	case Direction::Right:
	{
		playerChar = PLAYERRIGHT;
		break;
	}
	}
	map[player->getPos().y][player->getPos().x] = playerChar;
	return 0;
}

void Map::Draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}