#include "pbui/Button.h"
#include "pbui/UIElement.h"
#include "pbui/Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pbollama/OllamaFunction.h"
#include "pbui/Combobox.h"
#include "pbui/Label.h"
#include "pbui/TextInput.h"
#include "pbui/Listview.h"
#include <vector>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    Window window("Ollama Messenger", 1280, 720);
    Button startBtn(10, 10, 150, 40, "Start ollama Server");
    startBtn.setOnClick([]() {});
    std::vector<std::string> itemslist = {"test","stest","test3"};
    Combobox combi(170, 10, 250, 40, itemslist);
    TextInput textinput(200, 670, 350, 40);
    textinput.setPlaceholder("Type message here....");
    

    ListView listview(10, 130, 250, 200, 20);
    listview.addItem("test");
    listview.addItem("stest");
    listview.addItem("test3");

    window.addElement(&combi);
    window.addElement(&textinput);
    window.addElement(&startBtn);
    window.addElement(&listview);
    window.mainLoop();
    TTF_Quit();
    SDL_Quit();
    return 0;
}