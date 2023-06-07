#pragma once
#include "Vector2.h"
#include "Direction.h"
#include <ctime>
#include <cstdlib>

class Enemy
{
private:
	bool verticalMov; //This will help us decide wether it moves vertically or horizontally

public:
	Enemy(int x, int y);
	Enemy() = default;
	~Enemy() {}

	void Update();

	Vector2 pos;
	Vector2 prevPos;
};

