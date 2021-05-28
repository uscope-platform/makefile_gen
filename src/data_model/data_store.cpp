//
// Created by fils on 28/05/2021.
//

#include "data_model/data_store.h"

data_store::data_store() {
    store_path = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    std::filesystem::create_directory(store_path);

    settings_file = store_path + "/settings";
    data_file = store_path + "/data.json";

    if(std::filesystem::exists(settings_file)){
        load_settings_backend();
    }

    if(std::filesystem::exists(data_file)){
        std::ifstream i(data_file);
        i >> data_backend;
    }

}

void data_store::set_setting(const std::string& name, const std::string& value) {
    settings_backend[name] = value;
}

std::string data_store::get_setting(const std::string& setting) {
    return settings_backend[setting];
}

void data_store::load_settings_backend() {
    std::ifstream setting_stream(settings_file);
    std::string line;
    while (std::getline(setting_stream, line)){
        std::istringstream ss(line);
        std::string tokens[2];
        int i = 0;
        while(std::getline(ss, tokens[i], ',')) {
            i++;
        }
        settings_backend[tokens[0]] = tokens[1];
    }
}

void data_store::store_settings_backend() {
    std::filesystem::remove(settings_file);
    std::ofstream settings_stream(settings_file);
    for (auto const& [key, val] : settings_backend){
        settings_stream << key << ',' << val << std::endl;
    }
}

data_store::~data_store() {
    store_settings_backend();
}


