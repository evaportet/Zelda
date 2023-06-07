#include "../include/Enemy.h"

Enemy::Enemy(int x, int y) : pos(Vector2(x, y)), prevPos(Vector2(x, y))
{
	int randomMovement = rand() % 2;
	verticalMov = randomMovement;
}

Enemy::Enemy(const Enemy& enemy)
{
	pos = enemy.pos;
	prevPos = enemy.prevPos;
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
