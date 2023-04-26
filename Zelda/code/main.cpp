#include <iostream>
#include "include/Game.h"

int main()
{
    Game game("res/settings.txt");
    game.Start();
    
    while(game.running){
        game.Update();
        game.Draw();
        game.FrameControl();
    }

}
