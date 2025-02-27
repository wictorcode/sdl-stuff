#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "events/inputs.h"
#include "player.h"
#include "graphics/renderer.h"

namespace Game {namespace Player {

    SDL_FRect playerRectangle = {0.0, 0.0, 20.0, 20.0};
    SDL_Texture* playerTexture;
    PlayerState playerState = {false, false, false, false};

    void initialize() {
        SDL_Surface* playerSurface = SDL_LoadBMP("assets/club_penguin.bmp");
        playerTexture = SDL_CreateTextureFromSurface(Engine::Graphics::GetRenderer(), playerSurface);
        SDL_DestroySurface(playerSurface); // Surfaces are handled by the CPU so we destory that shit and keep GPU handle the texture
        playerSurface = nullptr;
    }


    SDL_FRect* get_player_rectangle()
    {
        return &playerRectangle;
    }

    SDL_Texture* get_player_texture()
    {
        return playerTexture;
    }

    void initListeners()
    {
        Engine::InputManager::bindActionToFunction(ACTION_MOVE_UP, [](bool isDown) {
            playerState.UP = isDown;
        });

        Engine::InputManager::remapKey(SDLK_UP, SDLK_Z);
      
      
        Engine::InputManager::bindActionToFunction(ACTION_MOVE_DOWN, [](bool isDown) {
            playerState.DOWN = isDown;
        });
      
        Engine::InputManager::bindActionToFunction(ACTION_MOVE_LEFT, [](bool isDown) {
            playerState.LEFT = isDown;
        });
      
        Engine::InputManager::bindActionToFunction(ACTION_MOVE_RIGHT, [](bool isDown) {
            playerState.RIGHT = isDown;
        });
    }

    void reset_position()
    {
        playerRectangle.y = 0;
        playerRectangle.x = 0;
    }

    void set_position(float x, float y)
    {
        playerRectangle.y = y;
        playerRectangle.x = x;
    }


    void update_position()
    {
        if (playerState.UP) {
            playerRectangle.y -= 1;
        }
  
        if (playerState.DOWN) {
            playerRectangle.y += 1;
        }

        if (playerState.RIGHT) {
            playerRectangle.x += 1;
        }

        if (playerState.LEFT) {
            playerRectangle.x -= 1;
        }
    }

}}