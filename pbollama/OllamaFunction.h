#pragma once
#include <iostream>
#include <string>


int startOllamaService();
int loadOllamaModel(std::string& modelname);
int stopOllamaService();