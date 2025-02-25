#include <stdio.h>
#include <SDL3/SDL.h>
#include "graphics/renderer.h"
#include "events/event_manager.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = engine::graphics::CreateWindow("Game name here", 500, 500);
    SDL_Renderer* renderer = engine::graphics::CreateRenderer(); // the renderer is automatically associated to the window
    
    // Main loop
    bool quit = false;
    SDL_Event event;

    engine::events::addEventListener(SDL_EVENT_QUIT, [&quit](const SDL_Event&) {
      quit = true;
    });

    engine::events::addKeyListener(SDLK_SPACE, []() {
      printf("Hello World");
    });

    while (!quit)
    {
/*
  _    _ _____  _____       _______ ______  __      __     _____  _____          ____  _      ______  _____ 
 | |  | |  __ \|  __ \   /\|__   __|  ____| \ \    / /\   |  __ \|_   _|   /\   |  _ \| |    |  ____|/ ____|
 | |  | | |__) | |  | | /  \  | |  | |__     \ \  / /  \  | |__) | | |    /  \  | |_) | |    | |__  | (___  
 | |  | |  ___/| |  | |/ /\ \ | |  |  __|     \ \/ / /\ \ |  _  /  | |   / /\ \ |  _ <| |    |  __|  \___ \ 
 | |__| | |    | |__| / ____ \| |  | |____     \  / ____ \| | \ \ _| |_ / ____ \| |_) | |____| |____ ____) |
  \____/|_|    |_____/_/    \_\_|  |______|     \/_/    \_\_|  \_\_____/_/    \_\____/|______|______|_____/                                                                                                                                                                                                                                                                                                                                                                                        
*/
        
        // PROCESS EVENTS HERE
        engine::events::processEvents();
        

/*
  _____  ______ _   _ _____  ______ _____  
 |  __ \|  ____| \ | |  __ \|  ____|  __ \ 
 | |__) | |__  |  \| | |  | | |__  | |__) |
 |  _  /|  __| | . ` | |  | |  __| |  _  / 
 | | \ \| |____| |\  | |__| | |____| | \ \ 
 |_|  \_\______|_| \_|_____/|______|_|  \_\                                                                                                                                                                                                                                                                                                                                                                                                                 
*/
        SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
/*
   _____ _      ______          _   _   _    _ _____  
  / ____| |    |  ____|   /\   | \ | | | |  | |  __ \ 
 | |    | |    | |__     /  \  |  \| | | |  | | |__) |
 | |    | |    |  __|   / /\ \ | . ` | | |  | |  ___/ 
 | |____| |____| |____ / ____ \| |\  | | |__| | |     
  \_____|______|______/_/    \_\_| \_|  \____/|_|                                                  
*/

    SDL_DestroyRenderer(engine::graphics::GetRenderer());
    SDL_DestroyWindow(engine::graphics::GetWindow());
    SDL_Quit();
    
    return 0;
}