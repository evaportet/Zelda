#include "../include/MapLoader.h"

MapLoader::MapLoader(std::string path):this->path(path) 
{
}

bool MapLoader::LoadMaps(Map *maps[])
{
    bool success = false;

    std::ifstream file;
    file.open(path, ios::in);
    if (file.is_open)
    {
        success = true;
        int num;
        while (File >> num)
        {
        }
    }
    return success;
}