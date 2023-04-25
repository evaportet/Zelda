#pragma once
#include "Map.h"
#include <iostream>
#include <fstream>

class MapLoader
{
private:
    std::string path;

public:
    MapLoader(std::string path);
    ~MapLoader();

    bool LoadMaps(Map *maps[]);
};