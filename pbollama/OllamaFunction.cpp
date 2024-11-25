#include "OllamaFunction.h"
#include "ollama.hpp"
#include "json.hpp"
#include <fstream>


using json = nlohmann::json;


int saveSetting(const std::string& file, const std::string& key, const std::string& value)
{
    std::ifstream i(file);
    json j;
    i>> j;
    j[key] = value;
    std::ofstream o(file);
    if (!o.is_open())
    {
        return 1;
    }
    o << j.dump(4);
    o.close();
    return 0;
}


std::string loadSetting(const std::string& file, const std::string& key)
{
    std::ifstream i(file);
    json j;
    i >> j;
    return j[key];
}

int startOllamaService(){
    return system("/home/beta/Desktop/aai/run.sh"); 
};