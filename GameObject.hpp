#pragma once
//#include "Game.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include "Map.hpp"

class GameObject : public Game
{
public:
    
    GameObject(const char *texturesheet, int x, int y);
    ~GameObject();
    void Update();
    void heartUpdate();
    void livesUpdate();
    void Render();
    void move();
    void moveBallDown();
    // SDL_Rect brick_coords[500];
    // static void brickCoords(SDL_Rect brickDest, int i);
    
private:
    int ver_move;
    int hor_move;
    int lives_xpos, lives_ypos;
    int xpos;
    int ypos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};