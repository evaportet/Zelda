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
	intendedPos = pos;
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

	if (updateDelay < 3) {
		updateDelay++;
		return;
	}
	switch (dir)
	{
	case Direction::Up:
		intendedPos.y = pos.y - 1;
		break;
	case Direction::Down:
		intendedPos.y = pos.y + 1;
		break;
	case Direction::Left:
		intendedPos.x = pos.x - 1;
		break;
	case Direction::Right:
		intendedPos.x = pos.x + 1;
		break;
	default:
		break;
	}
	updateDelay = 0;
}

void Enemy::Movement()
{
	prevPos = pos;
	pos = intendedPos;
}

Vector2 Enemy::GetIntendedPos()
{
	return intendedPos;
}
