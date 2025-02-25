#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "player.h"

namespace game {namespace player {

    SDL_FRect playerRectangle = {0, 0, 10, 10};
    PlayerState playerState = {false, false, false, false};

    SDL_FRect* get_player_rectangle()
    {
        return &playerRectangle;
    }

    void initListeners()
    {
        engine::events::addKeyListener(SDLK_UP, [](bool isDown) {
            if (isDown) {
              playerState.UP = true;
            } else {
              playerState.UP = false;
            }
          });
      
          engine::events::addKeyListener(SDLK_DOWN, [](bool isDown) {
            if (isDown) {
              playerState.DOWN = true;
            } else {
              playerState.DOWN = false;
            }
          });
      
          engine::events::addKeyListener(SDLK_LEFT, [](bool isDown) {
            if (isDown) {
              playerState.LEFT = true;
            } else {
              playerState.LEFT = false;
            }
          });
      
          engine::events::addKeyListener(SDLK_RIGHT, [](bool isDown) {
            if (isDown) {
              playerState.RIGHT = true;
            } else {
              playerState.RIGHT = false;
            }
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