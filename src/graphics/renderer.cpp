#include <SDL3/SDL.h>

namespace Engine { namespace Graphics {

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Window* CreateWindow(const char* windowTitle, int width, int height)
    {
        window = SDL_CreateWindow(windowTitle, width, height, SDL_WINDOW_RESIZABLE);
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

    SDL_Surface* load_bmp_as_texture(const char* filePath)
    {
        SDL_LoadBMP(filePath);
    }

    void destroy_surface(SDL_Surface* surface)
    {
        SDL_DestroySurface(surface);
    }

}}