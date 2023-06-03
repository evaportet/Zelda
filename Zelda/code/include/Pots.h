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

public:
	char Drop();
};

