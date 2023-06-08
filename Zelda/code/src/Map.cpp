#include "../include/Map.h"

Map::Map(Player* _player, int h, int w, int _enemies, ROOMTYPE _type, int pots) : type(_type), player(_player), height(h), width(w), numEnemies(_enemies), numPots(pots)
{
	// Declare 2d dynamic array
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
	}

	//potArr = new Pots[numPots];

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
			map[0][(width / 2)] = DOOR;
			doorPos[0].x = (width / 2);
			doorPos[0].y = 0;
			map[height - 1][(width / 2)] = DOOR;
			doorPos[1].x = (width / 2);
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
			map[height - 1][(width / 2)] = DOOR;
			doorPos[0].x = (width / 2);
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
			map[0][(width / 2)] = DOOR;
			doorPos[0].x = (width / 2);
			doorPos[0].y = 0;
		}
		break;
	}
	}

	//Set player
	//map[player->getPos().y][player->getPos().x] = PLAYERUP;

	//Gen gem pos
	for (int i = 0; i < numPots; i++)
	{
		int randomX;
		int randomY;
		do {
			randomX = rand() % (width - 2) + 1;
			randomY = rand() % (height - 2) + 1;
		} while (Vector2(randomX, randomY) == player->getPos());

		map[randomY][randomX] = VASE;
	}

	enemies = new Enemy[numEnemies];
	//Gen enemies pos
	for (int i = 0; i < numEnemies; i++)
	{
		int randomX;
		int randomY;
		do {
			randomX = rand() % (width - 2) + 1;
			randomY = rand() % (height - 2) + 1;
		} while (map[randomY][randomX] != EMPTY);

		enemies[i] = Enemy(randomX, randomY);
		map[randomY][randomX] = HOG;
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
	int retrn = (int)type;
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

	//check player collision
	if (map[player->getIntendedPos().y][player->getIntendedPos().x] != WALL
		&& map[player->getIntendedPos().y][player->getIntendedPos().x] != VASE
		&& map[player->getIntendedPos().y][player->getIntendedPos().x] != HOG)
	{
		if (map[player->getIntendedPos().y][player->getIntendedPos().x] == DOOR)
		{
			map[player->getPos().y][player->getPos().x] = EMPTY;
			switch (type)
			{
			case ROOMTYPE::CLASS:
			{
				player->OverridePos(7, 10);
				retrn = (int)ROOMTYPE::HALL;
				return retrn;
			} break;
			case ROOMTYPE::HALL: {

				if (player->getPos().y > height / 2)
				{
					player->OverridePos(3, 1);
					retrn = (int)ROOMTYPE::CLASS;
					return retrn;
				}
				else {
					player->OverridePos(12, 18);
					retrn = (int)ROOMTYPE::CAFETERIA;
					return retrn;
				}

			} break;
			case ROOMTYPE::CAFETERIA:
			{
				player->OverridePos(7, 1);
				retrn = (int)ROOMTYPE::HALL;
				return retrn;
			} break;
			default: break;
			}
		}
		if (map[player->getIntendedPos().y][player->getIntendedPos().x] == GREENGEM)
		{
			player->AddScore(1);
		}
		else if (map[player->getIntendedPos().y][player->getIntendedPos().x] == BLUEGEM)
		{
			player->AddScore(5);
		}
		else if (map[player->getIntendedPos().y][player->getIntendedPos().x] == REDGEM)
		{
			player->AddScore(20);
		}

		player->Movement();
		map[player->getPrevPos().y][player->getPrevPos().x] = EMPTY;
	}
	if (player->IsAttacking())
	{
		if (map[player->getAttackPos().y][player->getAttackPos().x] == VASE)
		{
			Pots p;
			map[player->getAttackPos().y][player->getAttackPos().x] = p.Drop();
		}
		else if (map[player->getAttackPos().y][player->getAttackPos().x] == HOG)
		{
			for (int i = 0; i < numEnemies; i++)
			{
				if (player->getAttackPos() == enemies[i].pos)
				{
					map[enemies[i].pos.y][enemies[i].pos.x] = EMPTY;
					Enemy* newArr = new Enemy[numEnemies - 1];
					bool skiped = false;
					for (int j = 0; j < numEnemies; j++)
					{
						bool skip = false;
						if (j == i)
						{
							skiped = true;
							skip = true;
						}
						if (!skip) {
							if (!skiped)
								newArr[j] = enemies[j];
							else
								newArr[j - 1] = enemies[j];
						}
					}
					numEnemies--;
					delete[] enemies;
					enemies = newArr;
					newArr = nullptr;
					return retrn;
				}
			}
		}
	}

	for (int i = 0; i < numEnemies; i++)
	{
		if (enemies != nullptr) {
			enemies[i].Update();
			if (map[enemies[i].GetIntendedPos().y][enemies[i].GetIntendedPos().x] != WALL
				&& map[enemies[i].GetIntendedPos().y][enemies[i].GetIntendedPos().x] != VASE
				&& map[enemies[i].GetIntendedPos().y][enemies[i].GetIntendedPos().x] != HOG
				&& enemies[i].GetIntendedPos() != player->getPos())
				enemies[i].Movement();
			else if (enemies[i].GetIntendedPos() == player->getPos())
				player->TakeDmg();
			else
				enemies[i].ResetIntendedPos();
			map[enemies[i].prevPos.y][enemies[i].prevPos.x] = EMPTY;
			map[enemies[i].pos.y][enemies[i].pos.x] = HOG;
		}
	}

	map[player->getPos().y][player->getPos().x] = playerChar;
	return retrn;
}

void Map::Draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << " " << map[i][j];
		}
		std::cout << std::endl;
	}
}
