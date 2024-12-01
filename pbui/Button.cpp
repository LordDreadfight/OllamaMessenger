#include "Button.h"
#include <iostream>

Button::Button(short int x, short int y, unsigned short int width, unsigned short int height, const std::string& text)
    : x(x), y(y), width(width), height(height), text(text), isHovered(false)
{
    onClick = []() {};
    font = TTF_OpenFont("Ubuntu-Regular.ttf", 14);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

void Button::setOnClick(std::function<void()> callback) {
    onClick = callback;
}

void Button::setTooltip(const std::string& tooltipText) {
    this->tooltipText = tooltipText;
}

void Button::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = {x, y, width, height};
    SDL_Color buttonColor = isHovered ? SDL_Color{112, 220, 112, 255} : SDL_Color{47, 211, 71, 255};
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(renderer, &rect);
    if (font) {
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        if (textSurface) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            int textWidth = textSurface->w;
            int textHeight = textSurface->h;
            SDL_FreeSurface(textSurface);

            SDL_Rect textRect = {x + (width - textWidth) / 2, y + (height - textHeight) / 2, textWidth, textHeight};
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_DestroyTexture(textTexture);
        }
    }
    if (isHovered && !tooltipText.empty() && font) {
        SDL_Color tooltipColor = {255, 255, 255, 255};
        SDL_Surface* tooltipSurface = TTF_RenderText_Solid(font, tooltipText.c_str(), tooltipColor);
        if (tooltipSurface) {
            SDL_Texture* tooltipTexture = SDL_CreateTextureFromSurface(renderer, tooltipSurface);
            int tooltipWidth = tooltipSurface->w;
            int tooltipHeight = tooltipSurface->h;
            SDL_FreeSurface(tooltipSurface);
            SDL_Rect tooltipRect = {x + width + 10, y, tooltipWidth, tooltipHeight};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect bgRect = {tooltipRect.x - 5, tooltipRect.y - 5, tooltipWidth + 10, tooltipHeight + 10};
            SDL_RenderFillRect(renderer, &bgRect);
            SDL_RenderCopy(renderer, tooltipTexture, nullptr, &tooltipRect);
            SDL_DestroyTexture(tooltipTexture);
        }
    }
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
