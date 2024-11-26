#include "OllamaFunction.h"
#include "ollama.hpp"
#include "../json.hpp"

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

int loadOllamaModel( std::string& modelname){
    std::string Model = loadSetting("settings.json", "modelname");
    if (modelname == "" && Model != "")
    {
        ollama::load_model(Model);
        return 0;
    }else if (modelname >= "")
    {
        ollama::load_model(modelname);
        return 0;
    }else if (modelname == "" && Model == "")
    {
        return 1;
    }
    return 1;
};

int stopOllamaService(){
    return system("killall ollama");
};

