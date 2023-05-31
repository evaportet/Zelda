#include "../include/Pots.h"

void Pots::Drop()
{
    srand(time(0)); 

    int randomNumber = rand() % 100 + 1;

    if (randomNumber <= 50) { // 50% chance
        player->totalGems += greenGemValue;

        //falta el print, con "greenGem"

        
    }
    else if (randomNumber <= 85) { // 35% chance
        player->totalGems += blueGemValue;

        //falta el print, con "blueGem"
        
    }
    else { // 15% chance
        player->totalGems += redGemValue;

        //falta el print, con "redGem"
        
    }
	
}
