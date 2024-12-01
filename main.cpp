#include "pbui/Button.h"
#include "pbui/UIElement.h"
#include "pbui/Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pbollama/OllamaFunction.h"
#include "pbui/Combobox.h"
#include <vector>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Window window("Ollama Messenger", 1280, 720);
    Button button(10, 10, 150, 50, "Start ollama Server");
    button.setOnClick([]() {
        startOllamaService();
    });
    button.setTooltip("Starts the ollama service");

    Button button2(10, 70, 150, 50, "me2");
    button2.setOnClick([]() {

    });
    button2.setTooltip("Starts nothing currently");

    std::vector<std::string> itemslist = {"test","stest","test3"};
    Combobox combi(170, 10, 250, 50, itemslist);

    window.addElement(&button);
    window.addElement(&button2);
    window.addElement(&combi);
    window.mainLoop();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
