#pragma once
#include "Player.h"
#include "Vector2.h"
#include "Roomtype.h"
#include "Pots.h"
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
	Pots* potArr;

public:
	Map(Player* _player, int h, int w, int enemies, ROOMTYPE _type, int pots);
	Map() = default;
	~Map();

	int Update();
	void Draw();
};