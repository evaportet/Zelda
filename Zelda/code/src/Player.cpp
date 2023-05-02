#include "../include/Player.h"

Player::Player()
{
}

Player::~Player()
{
}

DIRECTION Player::getDirection()
{
	return direction;
}

Vector2 Player::getPos()
{
	return pos;
}

Vector2 Player::getPrevPos()
{
	return prevPos;
}

void Player::Update()
{
}
