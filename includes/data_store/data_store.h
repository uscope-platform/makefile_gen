//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_DATA_STORE_H
#define MAKEFILEGEN_V2_DATA_STORE_H


#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

#include "third_party/json.hpp"

using json = nlohmann::json;

class data_store {
public:
    data_store();

    std::string get_setting(const std::string& setting);
    void set_setting(const std::string& name, const std::string& value);
    ~data_store();
private:

    void load_settings_backend();
    void store_settings_backend();
    std::map<std::string, std::string> settings_backend;

    json data_backend;
    std::string store_path;
    std::string settings_file;
    std::string data_file;
};


#endif //MAKEFILEGEN_V2_DATA_STORE_H
