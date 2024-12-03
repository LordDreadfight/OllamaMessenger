#include "Label.h"
#include <iostream>

Label::Label(short int x, short int y, unsigned short int width, unsigned short int height, const std::string& text)
    : x(x), y(y), width(width), height(height), text(text)
{
    font = TTF_OpenFont("Ubuntu-Regular.ttf", 14);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

Label::~Label() {
    if (font) {
        TTF_CloseFont(font);
    }
}

void Label::draw(SDL_Renderer* renderer) {
    if (font) {
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        if (textSurface) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            unsigned short int textWidth = textSurface->w;
            unsigned short int textHeight = textSurface->h;
            SDL_FreeSurface(textSurface);

            SDL_Rect textRect = {x, y, textWidth, textHeight};
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_DestroyTexture(textTexture);
        }
    }
}

void Label::handleEvent(const SDL_Event& event) {
    // Labels are static elements. No event handling needed.
}
