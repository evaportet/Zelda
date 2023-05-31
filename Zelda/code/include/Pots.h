#pragma once
#include <cstdlib> 
#include <ctime>
#include "Player.h"

class Pots
{
private:
	int totalPots; //se carga desde fichero

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
	void Drop();

};

