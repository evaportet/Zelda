#pragma once
#include "Map.h"
#include "Game.h"
#include <iostream>
#include <fstream>

//this is now a singleton
class MapLoader
{
private:
    int rooms = 3;

    MapLoader();
    static MapLoader* instance;

public:
    ~MapLoader() = default;

    bool LoadMaps(Map *maps, std::string path, Player* player);
	
    static MapLoader* GetInstance();
};
