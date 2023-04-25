#pragma once
#include "Map.h"
#include <iostream>
#include <fstream>


class MapLoader{
public:
    MapLoader();
    ~MapLoader();

    bool LoadMaps(std::string path, Map* maps[]);
};