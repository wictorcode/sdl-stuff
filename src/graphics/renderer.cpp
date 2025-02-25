#include <SDL3/SDL.h>

namespace engine { namespace graphics {

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Window* CreateWindow(const char* windowTitle, int width, int height)
    {
        window = SDL_CreateWindow(windowTitle, width, height, NULL);
        return window;
    }

    SDL_Renderer* CreateRenderer()
    {
        if(window)
        {
            renderer = SDL_CreateRenderer(window, NULL);
        }

        return renderer;
    }

    SDL_Window* GetWindow()
    {
        if (!window)
        {
            return CreateWindow("Default Window", 500, 500);
        }

        return window;
    }

    SDL_Renderer* GetRenderer()
    {
        return SDL_GetRenderer(window);
    }

}}