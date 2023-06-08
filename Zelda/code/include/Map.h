#pragma once
#include "Player.h"
#include "Vector2.h"
#include "Roomtype.h"
#include "Pots.h"
#include "Enemy.h"
#include "Ganon.h"
#include <string>
#include <assert.h>
#include <iostream>

class Map
{
private:
	int height;
	int width;
	int numEnemies;
	int numPots;
	char** map;
	ROOMTYPE type;

	int doors;
	Vector2* doorPos;

	Player* player;
	Enemy* enemies;
	Ganon* ganon;

	void resizeEnemyArray();

public:
	Map(Player* _player, int h, int w, int _enemies, ROOMTYPE _type, int pots, Ganon* ganon);
	Map() = default;
	~Map();

	int Update();
	void Draw();
};