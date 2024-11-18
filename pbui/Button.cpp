#include "Button.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Button::Button(int x, int y, int width, int height, const std::string& text)
    : x(x), y(y), width(width), height(height), text(text), isHovered(false) {
    onClick = []() {}; // Default empty callback
}

void Button::setOnClick(std::function<void()> callback) {
    onClick = callback;
}

void Button::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, isHovered ? 100 : 50, 50, 150, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Button::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event.motion.x;
        int mouseY = event.motion.y;
        bool inside = (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height);

        if (inside) {
            isHovered = true;
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                onClick();
            }
        } else {
            isHovered = false;
        }
    }
}
