#!/bin/bash

# Set the source files and output binary names
g++ main.cpp pbui/Button.cpp pbui/Window.cpp pbollama/OllamaFunction.cpp -o OllamaMessenger -lSDL2 -lSDL2_ttf
