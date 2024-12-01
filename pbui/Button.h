#pragma once
#include "UIElement.h"
#include <functional>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct Button : public UIElement {
    Button(short int x, short int y, unsigned short int width, unsigned short int height, const std::string& text);
    void setOnClick(std::function<void()> callback);
    void setTooltip(const std::string& tooltipText);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;

    short int x, y;
    unsigned short int width, height;
    std::string text;
    std::function<void()> onClick;
    bool isHovered;
    TTF_Font* font;
    std::string tooltipText;
};
