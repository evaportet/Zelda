#include "../include/Enemy.h"

Enemy::Enemy()
{
	int randomMovement = rand() % 2;
	verticalMov = randomMovement;
}

void Enemy::Update()
{
	Direction dir;
	if (verticalMov)
	{
		int randDir = rand() % 2;
		if (randDir == 0)
			dir = Direction::Up;
		else
			dir = Direction::Down;
	}
	else
	{
		int randDir = rand() % 2;
		if (randDir == 0)
			dir = Direction::Left;
		else
			dir = Direction::Right;
	}
}
