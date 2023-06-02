#pragma once
#include "Vector2.h"
#include "Direction.h"
#include <ctime>
#include <cstdlib>

class Enemy
{
private:
	int health;
	bool verticalMov; //This will help us decide wether it moves vertically or horizontally

public:
	Enemy();

	void Update();

	Vector2 pos;
};

