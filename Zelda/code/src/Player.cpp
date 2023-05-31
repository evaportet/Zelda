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

int Player::getPlayerLives()
{
    return lives;
}

bool Player::getHasWon()
{
    return hasWon;
}

int Player::getTotalGems()
{
    return totalGems;
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
            direction = Direction::Up;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            Movement(pos, 0, 1); //Down
            direction = Direction::Down;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            Movement(pos, -1, 0); //Left
            direction = Direction::Left;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            Movement(pos, 1, 0); //Right
            direction = Direction::Right;
        }
    }
}

void Player::Draw()
{
}
