//
// Created by fils on 10/06/2021.
//

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


class cache_manager {
public:
    explicit cache_manager(std::shared_ptr<settings_store> settings);
    void add_file(std::filesystem::path &file);
    bool is_changed(std::filesystem::path &file);
    bool is_cached(std::filesystem::path &file);
    ~cache_manager();
private:
    static std::string hash_file(std::filesystem::path &file);
    void load_cache_backend();
    void store_cache_backend();

    std::shared_ptr<settings_store> store;
    std::unordered_map<std::string, std::string> cache;
};


#endif //MAKEFILEGEN_V2_CACHE_MANAGER_H
