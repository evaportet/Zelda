#pragma once
#include "Vector2.h"
#include "Direction.h"
#include <ctime>
#include <cstdlib>

class Ganon //TODO: Ganon
{
private:
	Direction dir;

public:
	Ganon() = default;
	Ganon(int x, int y);

	void SetLifes(int amount);
	void TakeDmg();
	int life;

	void Update();
	void Movement();

	Vector2 pos;
	Vector2 prevPos;
	Vector2 intendedPos;
};

