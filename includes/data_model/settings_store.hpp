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

#ifndef MAKEFILEGEN_V2_SETTINGS_STORE_HPP
#define MAKEFILEGEN_V2_SETTINGS_STORE_HPP


#include <filesystem>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

class settings_store {
public:
    settings_store(bool e, std::string cache_dir_path);

    std::string get_setting(const std::string& setting);
    void set_setting(const std::string& name, const std::string& value);
    void remove_setting(const std::string& setting);
    void flush();
    ~settings_store();
private:

    void load_settings_backend();
    void store_settings_backend();

    std::map<std::string, std::string> settings_backend;

    bool ephemeral;
    std::string store_path;
    std::string settings_file;
};


#endif //MAKEFILEGEN_V2_SETTINGS_STORE_HPP
