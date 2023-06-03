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

Vector2 Player::getIntendedPos()
{
    return intendedPos;
}

Vector2 Player::getPrevPos()
{
	return prevPos;
}

Vector2 Player::getAttackPos()
{
    return attackPos;
}

bool Player::IsAttacking()
{
    return isAttackng;
}

int Player::getPlayerLives()
{
    return lives;
}

bool Player::getHasWon()
{
    return hasWon;
}

void Player::OverridePos(int newX, int newY)
{
    pos = Vector2(newX, newY);
    intendedPos = pos;
    prevPos = pos;
    attackPos = pos;
}

void Player::AddScore(int amount)
{
    score += amount;
}

int Player::getScore()
{
    return score;
}

void Player::setLives(int amount)
{
    lives = amount;
}

void Player::Movement()
{
    prevPos = pos;
    pos = intendedPos;
}

void Player::AttemptMove(int x, int y)
{
    intendedPos.x = pos.x + x;
    intendedPos.y = pos.y + y;
}

void Player::Update()
{
    //////MOVEMENT//////
    // Clear
    system("cls");

    // Draw
    gotoxy(pos.x, pos.y);
    //std::cout << "P";

    intendedPos = pos;
    isAttackng = false;
    attackPos = pos;

    //InputManager
    if (GetAsyncKeyState(VK_UP)) {
        AttemptMove(0, -1); //Up
        direction = Direction::Up;
    }
    else if (GetAsyncKeyState(VK_DOWN)) {
        AttemptMove(0, 1); //Down
        direction = Direction::Down;
    }
    else if (GetAsyncKeyState(VK_LEFT)) {
        AttemptMove(-1, 0); //Left
        direction = Direction::Left;
    }
    else if (GetAsyncKeyState(VK_RIGHT)) {
        AttemptMove(1, 0); //Right
        direction = Direction::Right;
    }
    if (GetAsyncKeyState(VK_SPACE)) {
        isAttackng = true;
        switch (direction)
        {
        case Direction::Up:
            attackPos = Vector2(pos.x, pos.y - 1);
            break;
        case Direction::Down:
            attackPos = Vector2(pos.x, pos.y + 1);
            break;
        case Direction::Left:
            attackPos = Vector2(pos.x - 1, pos.y);
            break;
        case Direction::Right:
            attackPos = Vector2(pos.x + 1, pos.y);
            break;
        default: break;
        }
    }
    
}

void Player::Draw()
{
}
