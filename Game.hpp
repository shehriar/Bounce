// #ifndef Game_hpp
#define Game_hpp
#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>

class Game
{
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    bool loadMedia();
    void handleevents();
    void update();
    void render();
    void clean();
    bool dead = false;
    bool ringcollected = false;
    int lives = 2;
    bool running() { return isRunning; };
    //void ballmoving();

    static SDL_Renderer *renderer;

    SDL_Texture *loadTexture(std::string path);

    void run();
    SDL_Rect DestR;
    static SDL_Event event;
    /*SDL_Texture *ball;
    SDL_Texture *map1;
    SDL_Rect srcR, ballmover;*/
    // int ball_x = -125;
    // int ball_y = 425;
    //SDL_Renderer *renderer;

private:
    bool isRunning;
    int cnt = 0;
    //SDL_Texture *gTexture = NULL;
    //SDL_Renderer *gRenderer = NULL;
    SDL_Window *window;
};

// #endif Game_hpp