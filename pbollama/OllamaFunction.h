#pragma once
#include <iostream>
#include <string>
#include <fstream>

int startOllamaService();
int loadOllamaModel(std::string& modelname);
int stopOllamaService();
