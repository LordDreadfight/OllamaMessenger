#include "OllamaFunction.h"
//#include "ollama.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

/*int saveSetting(const std::string &file, const std::string &key, const std::string &value)
{
    std::ifstream i(file);
    json j;
    i >> j;
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

std::string loadSetting(const std::string &file, const std::string &key)
{
    std::ifstream i(file);
    json j;
    i >> j;
    return j[key];
}
*/
int startOllamaService()
{
    return system("cd /home/beta/Desktop/aai && source myenv/bin/activate && python3 test.py");
}

/*int loadOllamaModel(string &modelname)
{
    string Model = loadSetting("settings.json", "modelname");
    if (modelname == "" && Model != "")
    {
        ollama::load_model(Model);
        return 0;
    }
    else if (modelname >= "")
    {
        ollama::load_model(modelname);
        return 0;
    }
    else if (modelname == "" && Model == "")
    {
        return 1;
    }
    return 1;
};*/

int stopOllamaService()
{
    return system("killall ollama");
};

int saveOllamaModel()
{
    // return saveSetting("settings.json", "modelname", "megamodel");
    return 1;
};

void jsonCreateFile(string &file)
{
    try
    {
        ofstream outfile(file);
        outfile << "";
        outfile.close();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
};

/*void SaveSetting(const std::string &key, const std::string &val)
{
    string filename = "settings.json";
    string path = filesystem::current_path().string();
    string file = path + "/" + filename;
    json json;

    if (access(file.c_str(), F_OK) != -1)
    {
        std::ifstream i(file);
        i >> json;
        json[key] = val;
        std::ofstream o(file);
        if (!o.is_open()){}
        o << json.dump(4);
        o.close();
    }
    else
    {
        jsonCreateFile(file);
    }
}*/