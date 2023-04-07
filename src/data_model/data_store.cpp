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

#include "data_model/data_store.hpp"


data_store::data_store(bool e) {
    ephemeral = e;
    store_path = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    std::filesystem::create_directory(store_path);

    unified_cache = store_path + "/unified_cache";

    if(std::filesystem::exists(unified_cache) & !ephemeral){
        load_cache();
    }
    clean_up_caches();
}

HDL_Resource data_store::get_HDL_resource(const std::string& name) {
    return cache.hdl[name];
}

void data_store::store_hdl_entity(const HDL_Resource& entity) {
    cache.hdl[entity.getName()] = entity;
}

void data_store::store_hdl_entity(const std::vector<HDL_Resource>& vect) {
    for(auto &item: vect){
        store_hdl_entity(item);
    }
}

Script data_store::get_script(std::string &name) {
    return cache.scripts[name];
}

void data_store::store_script(Script entity) {
    cache.scripts[entity.get_name()] = entity;
}

void data_store::store_script(const std::vector<Script> &vect) {
    for(auto &item: vect){
        store_script(item);
    }
}

Constraints data_store::get_constraint(std::string &name) {

    return cache.constraints[name];
}

void data_store::store_constraint(Constraints entity) {
    cache.constraints[entity.get_name()] = entity;
}

void data_store::store_constraint(const std::vector<Constraints> &vect) {
    for(auto &item: vect){
        store_constraint(item);
    }
}

DataFile data_store::get_data_file(const std::string &name) {
    return cache.data[name];
}

void data_store::store_data_file(DataFile entity) {
    cache.data[entity.get_name()] = entity;
}

void data_store::store_data_file(const std::vector<DataFile> &vect) {
    for(auto &item: vect){
        store_data_file(item);
    }
}


bool data_store::is_primitive(const std::string &name) {
    return xilinx_primitives.find(name) != xilinx_primitives.end();
}

data_store::~data_store() {
    if(!ephemeral){
        store_cache();
    }
}


void data_store::load_cache() {
    std::ifstream is(unified_cache, std::ios_base::binary);

    cereal::BinaryInputArchive archive_in(is);
    archive_in(cache);

}


void data_store::store_cache() {
    std::filesystem::remove(unified_cache);
    std::ofstream os(unified_cache, std::ios_base::binary);
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(cache);
    }

}

void data_store::clean_up_caches() {
    std::vector<std::string> evicted_items;
    for (auto  [key, val] : cache.hdl){
        if(!std::filesystem::exists(val.get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.hdl.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : cache.scripts){
        if(!std::filesystem::exists(val.get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.scripts.erase(item);
    }
    evicted_items.clear();


    for (auto  [key, val] : cache.constraints){
        if(!std::filesystem::exists(val.get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.constraints.erase(item);
    }
}

void data_store::remove_stale_info(const std::filesystem::path& p) {
    std::vector<std::string> evicted_items;

    for (auto  [key, val] : cache.hdl){
        if(val.get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.hdl.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : cache.scripts){
        if(val.get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.scripts.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : cache.constraints){
        if(val.get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.constraints.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : cache.data){
        if(val.get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        cache.data.erase(item);
    }

}

void data_store::evict_hdl_entity(const std::string &name) {
    cache.hdl.erase(name);
}

void data_store::evict_script(const std::string &name) {
    cache.scripts.erase(name);
}

void data_store::evict_constraint(const std::string &name) {
    cache.constraints.erase(name);
}


void data_store::evict_data_file(const std::string &name) {
    cache.data.erase(name);
}
