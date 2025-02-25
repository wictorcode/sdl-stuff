#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "event_manager.h"
#include <functional>

enum EnumActions {
    ACTION_JUMP,
    ACTION_MOVE_UP,
    ACTION_MOVE_DOWN,
    ACTION_MOVE_LEFT,
    ACTION_MOVE_RIGHT,
    ACTION_INTERACT,
};

namespace Engine { namespace InputManager {
    using ActionCallback = std::function<void(bool)>;
    void bindActionToFunction(EnumActions actionName, ActionCallback callback);
    void mapKeyToAction(EnumActions actionName, SDL_Keycode key);
    void remapKey(SDL_Keycode oldKey, SDL_Keycode newKey);
    SDL_Keycode getKeyForAction(EnumActions actionName);
    void initialize();
}}