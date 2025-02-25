#pragma
#include <SDL3/SDL.h>

namespace engine { namespace graphics {
    SDL_Window* CreateWindow(const char* windowTitle, int width, int height);
    SDL_Renderer* CreateRenderer();
    SDL_Window* GetWindow();
    SDL_Renderer* GetRenderer();
}}