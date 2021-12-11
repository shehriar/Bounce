#include "Game.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"


#include "ECS.hpp"
#include "Components.hpp"

using namespace std;

// GameObject *SizeBuff;
// GameObject *SpeedBuff;
// GameObject *spike;
// GameObject *ring;
GameObject *ball;
GameObject *heart;
GameObject *zero;
GameObject *one;
GameObject *two;
// GameObject *spike;

Map *map;
Map *brick;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
auto &newBall(manager.addEntity());

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            //cout << "Renderer created" << endl;
        }

        isRunning = true;
    }

    ball = new GameObject("textures/ball.png", 0, 0);
    heart = new GameObject("textures/heart w bg.png", 0, 0);
    zero = new GameObject("textures/zero.png", 0, 0);
    one = new GameObject("textures/one.png", 0, 0);
    two = new GameObject("textures/two.png", 0, 0);
    // spike = new GameObject("textures/spike.png", 200, 200);
    map = new Map();
    newBall.addComponent<PositionComponent>();
    //newBall.getComponent<PositionComponent>().x
    /*SDL_Surface *tempSurface = IMG_Load("Assets/ball.png"); // fetches the ball asset from assets folder
    ball = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_Surface *tmpsurface = IMG_Load("Assets/map1_altered.png");
    map1 = SDL_CreateTextureFromSurface(renderer, tmpsurface);
    SDL_FreeSurface(tmpsurface);*/
}

void Game::handleevents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

// void Game::Lives()
// {
//     lives--;
// }

void Game::update()
{
    // zero -> numberUpdate();
    // one -> numberUpdate();
    // two-> numberUpdate();
    heart->heartUpdate();
    zero->livesUpdate();
    one->livesUpdate();
    two->livesUpdate();

    if((ball->dead) == true || (ball->ringcollected) == true)
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    ball->move();
    ball->Update();
    ball->moveBallDown();
    ball->Update();
    // spike->spikeUpdate();
    manager.update();
    // cout << newBall.getComponent<PositionComponent>().x() << "," << newBall.getComponent<PositionComponent>().y() << endl;



    //map->LoadMap();

    /*ballmover.y = ball_y;
    ballmover.x = ball_x;
    ballmover.w = 350;
    ballmover.h = 200;
    */
    //while(!quit){
    //     if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
    //     {
    //         quit = true;
    //     }
    //     else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d){
    //         ballmover.x +=5;
    //     }
    // }
    // destR.x = cnt;
    // cout<<cnt<<endl;
}

void Game::render()
{

    SDL_RenderClear(renderer);
    /*SDL_RenderCopy(renderer, map1, NULL, NULL);
    SDL_RenderCopy(renderer, ball, NULL, &ballmover);
*/
    
    map->DrawMap();
    ball->Render();
    heart->Render();
    if((ball->lives)==2)
    {
        two->Render();
    }
    else if((ball->lives)==1)
    {
        one->Render();
    }
    else if((ball->lives)==0)
    {
        zero->Render();
    }
    // heart->Render();
    // if(lives == 0)
    // {
    //     two->Render();
    // }
    // else if(lives == -1)
    // {
    //     one->Render();
    // }
    // else
    // {
    //     zero->Render();
    // }
    // spike->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    //cout << "Cleaned" << endl;
}

// void Game::run()
// {
//     bool quit = false;
//     SDL_Event e;

//     while (!quit)
//     {
//         //Handle events on queue
//         while (SDL_PollEvent(&e) != 0)
//         {
//             //User requests quit
//             if (e.type == SDL_QUIT)
//             {
//                 quit = true;
//             }

//             if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
//             {
//                 DestR.x += 50;
//                 cout << "ball moved right" << endl;
//             }
//             if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_w)
//             {
//                 DestR.y -= 50;
//                 cout << "ball moved up" << endl;
//             }
//         }
//     }
//     ball->moveBallDown();
// }
