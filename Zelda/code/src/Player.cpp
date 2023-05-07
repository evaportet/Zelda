#include "../include/Player.h"

Player::Player()
{
}

Player::~Player()
{
}

DIRECTION Player::getDirection()
{
	return DIRECTION();
}

Vector2 Player::getPos()
{
	return Vector2();
}

Vector2 Player::getPrevPos()
{
	return Vector2();
}

void Player::Movement(const Vector2& direction)
{
	pos = pos + direction;
}


void Player::Update()
{
        char input;
        
        if (inputManager.isKeyPressed()) {
            input = inputManager.getKey();
            Vector2 direction(0, 0);
           
            switch (input) {
            case 'a':
            case 'A':
                direction.x = -1;
                break;

            case 'd':
            case 'D':
                direction.x = 1;
                break;

            case 'w':
            case 'W':
                direction.y = -1;
                break;

            case 's':
            case 'S':
                direction.y = 1;
                break;
            }
            
            Movement(direction);
        }
}
