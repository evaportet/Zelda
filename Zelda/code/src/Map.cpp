#include "../include/Map.h"

Map::Map(std::string path, ROOMTYPE type, Player* player) : this->path(path), this->type(type), this->player(player)
{
    // Load map settings from txt

    // Declare 2d dynamic array
    map = new char *[height] for (int i = 0; i < height; i++)
    {
        map[i] = new char *[width];
    }

    // Set all walls
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y == 0 || x == 0 || y = height - 1 || x = width - 1)
                map[y][x] = WALL;
            else
                map[y][x] = EMPTY;
            switch (this->type)
            {
            case ROOMTYPE::HALL {
                if (width % 2 == 0) {
                    map[0][width / 2] = DOOR;
                    map[height - 1][width / 2] = DOOR;
                } else {
                    map[0][(width / 2) + 1] = DOOR;
                    map[height - 1][(width / 2) + 1] = DOOR;
                } break;
            } case ROOMTYPE::CAFETERIA {
                if (width % 2 == 0) {
                    map[height - 1][width / 2] = DOOR;
                } else {
                    map[height - 1][(width / 2) + 1] = DOOR;
                } break;
            } case ROOMTYPE::CLASS {
                if (width % 2 == 0) {
                    map[0][width / 2] = DOOR;
                } else {
                    map[0][(width / 2) + 1] = DOOR;
                } break;
            } 
            }
            map[player.getY()][player.getx()]=PLAYERUP;
        }
    }
}

Map::~Map()
{
    delete player;

    // Delete 2D dynamic array
    for (int i = 0; i < height; i++)
    {
        delete[] map[i];
    }
    delete[] map;
}

void Map::Update()
{

}

void Map::Draw()
{
    for (int i=0;i<height;i++){
        for (int j=0;i<width;j++){
            std::cout<<map[i][j];
        }
        std::endl;
    }
}

bool LoadFromTXT()
{
}