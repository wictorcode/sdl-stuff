#include <SDL3/SDL.h>
#include <functional>
#include <vector>
#include <unordered_map>
#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

namespace Engine {namespace Events  {
    //== EVENT CALLBACKS ==//
    // basically a dictionnary where the key is the event type and the value is a list of functions to call
    // it's so simple that I struggled to get that right
    std::unordered_map<uint32_t, std::vector<std::function<void(const SDL_Event&)>>> listeners;
    
    //== KEY CALLBACKS ==//
    std::unordered_map<SDL_Keycode, std::vector<std::function<void(bool isDown)>>> keyListeners;
    
    void addEventListener(uint32_t type, std::function<void(const SDL_Event&)> callback) {
        listeners[type].push_back(callback);
    }

    void addKeyListener(SDL_Keycode key, std::function<void(bool isDown)> callback) {
        keyListeners[key].push_back(callback);
    }

    void removeKeyListener(SDL_Keycode key) {
        keyListeners.erase(key);
    }

    /* Example usage

    engine::events::addKeyListener(SDLK_SPACE, []() {
        printf("I clicked on the space key!\n");
    });

    */

    void triggerAssociatedCallbacks(SDL_Keycode &key, SDL_Event &event)
    {
        if (keyListeners.count(key) > 0) {
            for (auto& callback : keyListeners[key]) {
                if (event.type == SDL_EVENT_KEY_DOWN) 
                    callback(true);
                if (event.type == SDL_EVENT_KEY_UP) 
                    callback(false);
            }
        }
    }
    
    void processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {


            ImGui_ImplSDL3_ProcessEvent(&event);
        
            // Only process the event with your handlers if ImGui isn't using it
            if (!ImGui::GetIO().WantCaptureMouse && !ImGui::GetIO().WantCaptureKeyboard) {
                // Your existing event processing code
            }


            // key events
            if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP) {
                SDL_Keycode key = event.key.key;
                triggerAssociatedCallbacks(key, event);
            }
            
            // other events
            if (listeners.count(event.type) > 0) {
                for (auto& callback : listeners[event.type]) {
                    callback(event);
                }
            }
        }
    }
}}