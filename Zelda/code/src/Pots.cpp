#include "../include/Pots.h"

char Pots::Drop()
{
	srand(time(0));

	int randomNumber = rand() % 100 + 1;
	char print;
	if (randomNumber <= 50) { // 50% chance
		player->totalGems += greenGemValue;

		print = greenGem;
	}
	else if (randomNumber <= 85) { // 35% chance
		player->totalGems += blueGemValue;

		print = blueGem;
	}
	else { // 15% chance
		player->totalGems += redGemValue;

		print = redGem;
	}
	return print;
}
