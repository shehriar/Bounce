#pragma once
#include "Game.hpp"
#include "GameObject.hpp"

class Map
{
public:
    Map();
    ~Map();
    void LoadMap(int arr[20][26]);
    void DrawMap();
    void brickCoords();
    int brick_coords[500];
    // GameObject* brc;

private:
    SDL_Rect src, dest;
    SDL_Texture *sky;
    SDL_Texture *bricks;
    SDL_Texture *jumpbuff;
    SDL_Texture *speedbuff;
    SDL_Texture *gravitybuff;
    SDL_Texture *spike;
    SDL_Texture *ring;
    int map[20][25];

};
