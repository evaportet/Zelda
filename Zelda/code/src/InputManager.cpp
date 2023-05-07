#include "../include/InputManager.h"

bool InputManager::isKeyPressed()
{  
        return _kbhit() != 0;
}

char InputManager::getKey()
{
    return _getch();
}
