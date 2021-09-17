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

#ifndef MAKEFILEGEN_V2_CACHE_MANAGER_H
#define MAKEFILEGEN_V2_CACHE_MANAGER_H

#include <filesystem>
#include <unordered_map>
#include <utility>
#include <fstream>
#include <vector>

#include <openssl/sha.h>
#include <openssl/crypto.h>

#include "data_model/settings_store.h"
#include "data_model/data_store.h"

class cache_manager {
public:
    explicit cache_manager(std::shared_ptr<settings_store> settings, std::shared_ptr<data_store> data);
    void add_file(std::filesystem::path &file);
    bool is_changed(std::filesystem::path &file);
    bool is_cached(std::filesystem::path &file);
    ~cache_manager();
private:
    static std::string hash_file(std::filesystem::path &file);
    void load_cache_backend();
    void store_cache_backend();

    std::shared_ptr<settings_store> s_store;
    std::shared_ptr<data_store> d_store;
    std::unordered_map<std::string, std::string> cache;
};


#endif //MAKEFILEGEN_V2_CACHE_MANAGER_H
