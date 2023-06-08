#pragma once
#include "Vector2.h"
#include "Direction.h"
#include <ctime>
#include <cstdlib>

class Enemy
{
private:
	bool verticalMov; //This will help us decide wether it moves vertically or horizontally
	Vector2 intendedPos;
	int updateDelay;//This will be to make them move slower;

public:
	Enemy(int x, int y);
	Enemy(const Enemy& enemy);
	Enemy() = default;

	void Update();
	void Movement();

	Vector2 pos;
	Vector2 prevPos;

	Vector2 GetIntendedPos();
};

