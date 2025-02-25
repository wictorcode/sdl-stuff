#include <SDL3/SDL.h>
#include <stdio.h>
#include <iostream>
#include "event_manager.h"
#include <unordered_map>
#include <vector>
#include <functional>
#include "inputs.h"

namespace Engine { namespace InputManager {

    using ActionCallback = std::function<void(bool)>;

    std::unordered_map<EnumActions, std::vector<ActionCallback>> actionCallbacks;
    std::unordered_map<SDL_Keycode, EnumActions> keyMappings;

    void bindActionToFunction(EnumActions actionCode, ActionCallback callback)
    {
        actionCallbacks[actionCode].push_back(callback);
    }

    void mapKeyToAction(EnumActions actionCode, SDL_Keycode key)
    {
        keyMappings[key] = actionCode;
        Engine::Events::addKeyListener(key, [actionCode](bool isDown) {

            auto functionsBindedToAction = actionCallbacks.find(actionCode);
            if (functionsBindedToAction != actionCallbacks.end()) {
                for (auto &callback : functionsBindedToAction->second) {
                    callback(isDown);
                }
            }

        });
    }

    void remapKey(SDL_Keycode oldKey, SDL_Keycode newKey) {
        // Find what action the old key was mapped to
        auto it = keyMappings.find(oldKey);
        if (it != keyMappings.end()) {
            EnumActions action = it->second;
            
            // Remove the old mapping
            keyMappings.erase(oldKey);
            
            // Remove the old key listener
            Engine::Events::removeKeyListener(oldKey);
            
            // Add the new mapping
            mapKeyToAction(action, newKey);
        }
    }
    

    SDL_Keycode getKeyForAction(EnumActions& actionCode) {
        for (const auto& [key, action] : keyMappings) {
            if (action == actionCode) {
                return key;
            }
        }
        return SDLK_UNKNOWN;
    }

    void initialize()
    {

        mapKeyToAction(ACTION_JUMP, SDLK_SPACE);
        mapKeyToAction(ACTION_MOVE_UP, SDLK_UP);
        mapKeyToAction(ACTION_MOVE_DOWN, SDLK_DOWN);
        mapKeyToAction(ACTION_MOVE_LEFT, SDLK_LEFT);
        mapKeyToAction(ACTION_MOVE_RIGHT, SDLK_RIGHT);
        mapKeyToAction(ACTION_INTERACT, SDLK_E);
        
    }
}}