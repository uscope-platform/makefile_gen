// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "data_model/settings_store.hpp"

settings_store::settings_store(bool e, std::string cache_dir_path) {
    store_path = cache_dir_path;
    std::filesystem::create_directory(store_path);
    ephemeral = e;
    settings_file = store_path + "/settings";

    if(std::filesystem::exists(settings_file) && !ephemeral){
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
    if(!ephemeral){
        store_settings_backend();
    }

}

void settings_store::remove_setting(const std::string &setting) {
    settings_backend.erase(setting);
}

void settings_store::flush() {
    store_settings_backend();
}



