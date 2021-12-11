#include <iostream>
#include "Game.hpp"
#include "GameObject.hpp"
using namespace std;
Game *game = nullptr;

int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000;
    unsigned int frameStart;
    int frameTime;

    game = new Game();
    game->init("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game -> handleevents();
        // game->run();
        game->update();
        game->render();

        // game->update();
        // game->render();


        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();

    return 0;
}