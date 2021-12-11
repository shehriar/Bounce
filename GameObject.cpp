#include "GameObject.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
using namespace std;
GameObject::GameObject(const char *texturesheet, int x, int y)
{

    //texture manager insert texture sheet
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = 0; //0
    ypos = 515; //515
    lives_xpos = 0;
    lives_ypos = 50;
    ver_move = 220;
    hor_move = 47;
}

void GameObject::move()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_KEYUP || event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                xpos+=hor_move;
                break;
            }
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                xpos-=hor_move;
                break;
            }
            // if (event.key.keysym.sym == SDLK_e)
            // {
            //     ypos-=120;
            //     break;
            // }
            if (event.key.keysym.sym == SDLK_UP)
            {
                ypos-=ver_move;
                break;
            }
            // if (event.key.keysym.sym == SDLK_s)
            // {
            //     ypos+=110;
            //     break;
            // }
        }
    }
    moveBallDown();
}

void GameObject::Update()
{
    // if(ypos<515)
    // {
    //     ypos+=10;
    // }

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;
}

// void bricksCoords(int *brickarr)
// {}

void GameObject::moveBallDown()
{
    if(ypos<515 && xpos<47)
    {
        ypos+=15;
        
    }
    else if(ypos<515 && xpos>100 && xpos<200) //between pre_diamond and first platform
    {
        ypos+=15;
        
    }
    else if(xpos>-10 && xpos<60 && ypos<200) // diamond platform
    {
        ypos+=15;
        ver_move =260;
    }
    else if(xpos>70 && xpos<100 && ypos<320) //pre_diamond platform
    {
        ypos+=15;
    }
    else if(xpos>200 && xpos<300 && ypos<385) // first platform
    { 
        ypos+=15;
    }
    // else if(xpos>200 && xpos<300 && ypos>385 && ypos<515) // first platform underneath
    // { 
    //     ypos+=15;
    // }
    else if(xpos>=300 && xpos<=325 && ypos<515) //between first and second
    {
        ypos+=15;
    }
    else if(xpos>325 && xpos<445 && ypos<=220) //second platform
    {
        ypos+=15;
    }
    else if(xpos>325 && xpos<445 && ypos>350 && ypos<515) //second platform underneath
    {
        ypos+=15;
    }
    else if(xpos>445 && xpos<450 && ypos<515) // between second and third
    {
        ypos+=15;
    }
    else if(xpos>450 && xpos<520 && ypos<385) // third platform
    {
        ypos+=15;
    }
    else if(xpos>520 && xpos<600 && ypos<335) //between third and fourth
    {
        ypos+=15;
    }
    else if(xpos>600 && xpos<650 && ypos<335) // fourth platform
    {
        ypos+=15;
    }
    else if(xpos>600 && xpos<650 && ypos>335 && ypos<515) // fourth platform underneath
    {
        ypos+=15;
    }
    else if(xpos>650 && xpos<670 && ypos<335) //between fourth and platform
    {
        ypos+=15;
    }
    else if(xpos>670 && ypos<260) // ring platform
    {
        
        ypos+=15;
        ringcollected = true;
        Render();
    }
    
    while(ypos<0)
    {
        ypos++;
        Render();
    }

    while(ypos>515) //making sure you stay on the ground
    {
        ypos--;
        Render();
    }
    while(xpos<0)
    {
        xpos++;
        Render();
    }
    if(xpos>200 && ypos > 505)
    {
        if(lives==0)
        {
            dead = true;
        }
        ypos = 515;
        xpos = 0;
        lives--;
        Render();
    }
    // while(ypos<)
}

void GameObject::heartUpdate()
{
    // if(ypos<515)
    // {
    //     ypos+=10;
    // }

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = lives_xpos;
    destRect.y = lives_ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void GameObject::livesUpdate()
{
    // if(ypos<515)
    // {
    //     ypos+=10;
    // }

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = lives_xpos+40;
    destRect.y = lives_ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}


void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

// void brickCoords(SDL_Rect brickDest, int i)
// {
//     brick_coords[i] = (brickDest.x, brickDest.y);
// }

// void GameObject::quit()
// {
    
//     isRunning = false;
// }

