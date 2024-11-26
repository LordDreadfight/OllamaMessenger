#include "Button.h"
#include <iostream>


Button::Button(int x, int y, int width, int height, const std::string& text)
    : x(x), y(y), width(width), height(height), text(text), isHovered(false)
{
    onClick = []() {}; // Default empty callback
    font = TTF_OpenFont("Ubuntu-Regular.ttf", 14);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

void Button::setOnClick(std::function<void()> callback)
{
    onClick = callback;
}

void Button::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect = { x, y, width, height };
    SDL_Color buttonColor = isHovered ? SDL_Color{ 112, 220, 112, 255 } : SDL_Color{ 47, 211, 71, 255 }; // #47d247 and #32cd32
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(renderer, &rect);

    // Render text
    if (font) {
        SDL_Color textColor = { 255, 255, 255, 255 }; // White color for the text
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        if (textSurface != nullptr) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            int textWidth = textSurface->w;
            int textHeight = textSurface->h;
            SDL_FreeSurface(textSurface);

            // Center the text within the button
            SDL_Rect textRect = { x + (width - textWidth) / 2, y + (height - textHeight) / 2, textWidth, textHeight };
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_DestroyTexture(textTexture);
        }
    }
}

void Button::handleEvent(const SDL_Event& event)
{
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