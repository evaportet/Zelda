#pragma once
#include <cstdlib> 
#include <ctime>
#include "Player.h"
#include "Vector2.h"

class Pots
{
private:
	//////GEMS
	//draw
	char greenGem = '$';
	char blueGem = '#';
	char redGem = '&';

	//value
	int greenGemValue = 1;
	int blueGemValue = 5;
	int redGemValue = 20;

	//player
	Player* player;

public:
	char Drop();
	
	Vector2 pos;
};

