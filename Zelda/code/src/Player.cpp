#include "../include/Player.h"

Player::~Player()
{
}

void Player::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

void Player::Movement(Vector2& pos, int dx, int dy)
{
    /*prevPos = pos;
	pos = pos + direction;*/

    pos.x += dx;
    pos.y += dy;
}


void Player::Update()
{
    //////MOVEMENT//////
    while (true) {
        // Clear
        system("cls");

        // Draw
        gotoxy(pos.x, pos.y);
        //std::cout << "P";

        //InputManager
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            Movement(pos, 0, -1); //Up
            direction = DIRECTION::UP;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            Movement(pos, 0, 1); //Down
            direction = DIRECTION::DOWN;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            Movement(pos, -1, 0); //Left
            direction = DIRECTION::LEFT;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            Movement(pos, 1, 0); //Right
            direction = DIRECTION::RIGHT;
        }
    }
}

void Player::Draw()
{
}
