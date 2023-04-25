#pragma once
#include "Player.h"
#include <string>

enum class ROOMTYPE {CLASS, HALL, CAFETERIA};

class Map{
private:
    std::string path;
    ROOMTYPE type;

    int height;
    int width;
    int numEnemies;

    Player* player;

    bool LoadFromTXT();

public:
    Map(std::string path);
    ~Map();

    void Draw();

};