#include "../include/Ganon.h"
//JAJA GANON'T

Ganon::Ganon(int x, int y)
{
	pos.x = x;
	pos.y = y;
	intendedPos = pos;
}

void Ganon::Update()
{
	intendedPos = pos;

	int randDir = rand() % 4;
	switch (randDir)
	{
	case 0:
		dir = Direction::Up;
		break;
	case 1:
		dir = Direction::Down;
		break;
	case 2:
		dir = Direction::Left;
	case 3:
		dir = Direction::Right;
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
}

void Ganon::SetLifes(int amount)
{
	life = amount;
}

void Ganon::Movement()
{
	prevPos = pos;
	pos = intendedPos;
}

void Ganon::TakeDmg()
{
	life--;
}
