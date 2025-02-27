//---------------------------------------------------------------
#pragma once
#include <SDL3/SDL.h>
//---------------------------------------------------------------

struct ControllableComponent
{
    bool userControlled;
};

struct RenderableComponent
{
    SDL_Texture* texture;
    bool shouldRender;
};

struct TransformComponent
{
    int X;
    int Y;
    int W;
    int H;
};

//---------------------------------------------------------------