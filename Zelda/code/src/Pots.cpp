#include "../include/Pots.h"

char Pots::Drop()
{
	int randomNumber = rand() % 100;
	char print;
	if (randomNumber <= 50) { // 50% chance
		print = greenGem;
	}
	else if (randomNumber > 50 && randomNumber <= 85) { // 35% chance
		print = blueGem;
	}
	else { // 15% chance
		print = redGem;
	}
	return print;
}
