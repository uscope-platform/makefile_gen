//
// Created by fils on 28/05/2021.
//

#include "data_model/settings_store.h"

settings_store::settings_store() {
    store_path = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    std::filesystem::create_directory(store_path);

    settings_file = store_path + "/settings";

    if(std::filesystem::exists(settings_file)){
        load_settings_backend();
    }
}

void settings_store::set_setting(const std::string& name, const std::string& value) {
    settings_backend[name] = value;
}

std::string settings_store::get_setting(const std::string& setting) {
    return settings_backend[setting];
}

void settings_store::load_settings_backend() {
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

void settings_store::store_settings_backend() {
    std::filesystem::remove(settings_file);
    std::ofstream settings_stream(settings_file);
    for (auto const& [key, val] : settings_backend){
        settings_stream << key << ',' << val << std::endl;
    }
}

settings_store::~settings_store() {
    store_settings_backend();
}


