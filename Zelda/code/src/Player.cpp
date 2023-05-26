#include "../include/Player.h"

Player::~Player()
{
}

Direction Player::getDirection()
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

void Player::Movement(const Vector2& direction)
{
    prevPos = pos;
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
