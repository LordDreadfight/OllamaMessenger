#pragma once
#include "UIElement.h"
#include <functional>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


struct Button : public UIElement {
    Button(int x, int y, int width, int height, const std::string& text);
    void setOnClick(std::function<void()> callback);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;
    int x, y, width, height;
    std::string text;
    std::function<void()> onClick;
    bool isHovered;
    TTF_Font* font;
};
