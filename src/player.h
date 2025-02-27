#pragma once
#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "player.h"
#include "events/inputs.h"

struct PlayerState {
    bool UP = false;
    bool DOWN = false;
    bool LEFT = false;
    bool RIGHT = false;
};

namespace Game { namespace Player {

    void initialize();
    void initListeners();
    void update_position();
    void reset_position();
    void set_position(float x, float y);
    SDL_FRect* get_player_rectangle();
    SDL_Texture* get_player_texture();

}}