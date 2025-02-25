#include <stdio.h>
#include <SDL3/SDL.h>
#include "graphics/renderer.h"
#include "events/event_manager.h"
#include "init.h"
#include "player.h"

#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = Engine::Graphics::CreateWindow("Game name here", 500, 500);
    SDL_Renderer* renderer = Engine::Graphics::CreateRenderer(); // the renderer is automatically associated to the window


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);
 
    init_all();

    // Main loop
    bool quit = false;
    SDL_Event event;

    Engine::Events::addEventListener(SDL_EVENT_QUIT, [&quit](const SDL_Event&) {
      quit = true;
    });

    Game::Player::initListeners();

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
        Engine::Events::processEvents();
        //printf("%d, %d, %d, %d\n", playerState.UP, playerState.DOWN, playerState.LEFT, playerState.RIGHT);
        Game::Player::update_position();

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Debug Window");
          bool sliderX = ImGui::SliderFloat("X", &Game::Player::get_player_rectangle()->x, 0.0f, 1000.0f, "%.1f");
          bool sliderY = ImGui::SliderFloat("Y", &Game::Player::get_player_rectangle()->y, 0.0f, 1000.0f, "%.1f");
          bool sliderW = ImGui::SliderFloat("Width", &Game::Player::get_player_rectangle()->w, 0.0f, 1000.0f, "%.1f");
          bool sliderH = ImGui::SliderFloat("Height", &Game::Player::get_player_rectangle()->h, 0.0f, 1000.0f, "%.1f");
          if (ImGui::Button("Reset Position"))
          {
              Game::Player::reset_position();
          }
          ImGui::Separator();
          ImGui::Text("Keybinds");
          ImGui::Text("TODO");
        ImGui::End();
        
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

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, Game::Player::get_player_rectangle());

        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

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

    SDL_DestroyRenderer(Engine::Graphics::GetRenderer());
    SDL_DestroyWindow(Engine::Graphics::GetWindow());
    SDL_Quit();
    
    return 0;
}