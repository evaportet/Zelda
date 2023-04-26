#include "../include/MapLoader.h"

MapLoader::MapLoader(std::string _path, int _rooms): path(_path), rooms(_rooms) 
{
}

bool MapLoader::LoadMaps(Map *maps)
{
    bool success = false;

    std::ifstream file;
    file.open(path);
    if (file.is_open())
    {
        success = true;
        int num;
        char dump;
        for (int i = 0;i<rooms;i++){
            int height, width, numEnemies;
            file >> height;
            file >> dump;
            file >> width;
            file >> dump;
            file >> numEnemies;
            file >> dump;
            //std::cout<<height<<"," << width <<"," << numEnemies;
            maps[i].SetMap(height, width, numEnemies, );
        }
    }
    return success;
}