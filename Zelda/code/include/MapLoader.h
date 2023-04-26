#pragma once
#include "Map.h"
#include <iostream>
#include <fstream>

class MapLoader
{
private:
    std::string path;
    int rooms;

public:
    MapLoader(std::string _path, int _rooms);
    ~MapLoader()=default;

    //TODO loadmap
    bool LoadMaps(Map *maps);
};