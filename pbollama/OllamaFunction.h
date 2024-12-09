#pragma once
#include <iostream>
#include <string>
#include <fstream>

int startOllamaService();
int loadOllamaModel( const std::string& modelname);
int stopOllamaService();
int saveOllamaModel();
void SaveSetting(const std::string& key,const std::string& val);