#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "events/inputs.h"
#include "player.h"

namespace Game {namespace Player {

    SDL_FRect playerRectangle = {0, 0, 10, 10};
    PlayerState playerState = {false, false, false, false};

    SDL_FRect* get_player_rectangle()
    {
        return &playerRectangle;
    }

    void initListeners()
    {
        Engine::InputManager::bindActionToFunction(ACTION_MOVE_UP, [](bool isDown) {
            playerState.UP = isDown;
        });
      
      
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