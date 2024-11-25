#include "pbui/Button.h"
#include "pbui/UIElement.h"
#include "pbui/Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pbollama/OllamaFunction.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Window window("Ollama Messenger", 1280, 720);
    Button button(10, 10, 150, 50, "Click Me");
    button.setOnClick([]() {
        startOllamaService();
    });
    Button button2(10, 70, 150, 50, "me2");
    button2.setOnClick([]() {

    });

    window.addElement(&button);
    window.addElement(&button2);
    window.mainLoop();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
