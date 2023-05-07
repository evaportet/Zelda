#include <iostream>
#include "include/Game.h"

int main()
{
    Game* game= new Game("res/settings.txt");
    game->Start();
    
    while(game->running){
        game->Update();
        game->Draw();
        game->FrameControl();
    }

    delete game;
}
