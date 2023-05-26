#pragma once
#include "Player.h"
#include "Vector2.h"
#include "Roomtype.h"
#include <string>
#include <assert.h>
#include <iostream>

class Map
{
private:
	ROOMTYPE type;
	int height;
	int width;
	int numEnemies;
	char** map;
	int doors;
	Vector2* doorPos;

	Player* player;


public:
	Map(Player* _player, int h, int w, int enemies, ROOMTYPE _type);
	Map() = default;
	~Map();

	int Update();
	void Draw();
};