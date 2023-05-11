#include "../include/Player.h"

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
            Vector2 dir(0, 0);
           
            switch (input) {
            case 'a':
            case 'A':
                dir.x = -1;
                direction = DIRECTION::LEFT;
                break;

            case 'd':
            case 'D':
                dir.x = 1;
                direction = DIRECTION::RIGHT;
                break;

            case 'w':
            case 'W':
                dir.y = -1;
                direction = DIRECTION::RIGHT;
                break;

            case 's':
            case 'S':
                direction = DIRECTION::RIGHT;
                dir.y = 1;
                break;
            }
            
            Movement(dir);
        }
}
