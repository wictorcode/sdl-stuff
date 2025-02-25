#pragma once
#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "player.h"

struct PlayerState {
    bool UP = false;
    bool DOWN = false;
    bool LEFT = false;
    bool RIGHT = false;
};

namespace game { namespace player {

    void initListeners();
    void update_position();
    SDL_FRect* get_player_rectangle();

}}