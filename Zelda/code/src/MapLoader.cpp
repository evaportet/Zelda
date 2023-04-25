#include "../include/MapLoader.h"

bool MapLoader::LoadMaps(std::string path, Map *maps[])
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