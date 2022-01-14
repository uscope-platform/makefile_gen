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

#include "data_model/data_store.h"


data_store::data_store() {
    store_path = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    std::filesystem::create_directory(store_path);

    entities_file = store_path + "/entities";
    scripts_file = store_path + "/scripts";
    constraints_file = store_path + "/constraints";
    data_file = store_path + "/data_files";

    if(std::filesystem::exists(entities_file)){
        load_entities_cache();
    }
    if(std::filesystem::exists(scripts_file)){
        load_scripts_cache();
    }
    if(std::filesystem::exists(constraints_file)){
        load_constraints_cache();
    }
    if(std::filesystem::exists(data_file)){
        load_data_file_cache();
    }
    clean_up_caches();
}

std::shared_ptr<HDL_Resource> data_store::get_HDL_resource(const std::string& name) {
    return hdl_resources_cache[name];
}

void data_store::store_hdl_entity(const std::shared_ptr<HDL_Resource>& entity) {
    hdl_resources_cache[entity->getName()] = entity;
}

void data_store::store_hdl_entity(const std::vector<std::shared_ptr<HDL_Resource>>& vect) {
    for(auto &item: vect){
        store_hdl_entity(item);
    }
}

std::shared_ptr<Script> data_store::get_script(std::string &name) {
    return scripts_cache[name];
}

void data_store::store_script(const std::shared_ptr<Script> &entity) {
    scripts_cache[entity->get_name()] = entity;
}

void data_store::store_script(const std::vector<std::shared_ptr<Script>> &vect) {
    for(auto &item: vect){
        store_script(item);
    }
}

std::shared_ptr<Constraints> data_store::get_constraint(std::string &name) {
    return constraints_cache[name];
}

void data_store::store_constraint(const std::shared_ptr<Constraints> &entity) {
    constraints_cache[entity->get_name()] = entity;
}

void data_store::store_constraint(const std::vector<std::shared_ptr<Constraints>> &vect) {
    for(auto &item: vect){
        store_constraint(item);
    }
}

bool data_store::is_primitive(const std::string &name) {
    return xilinx_primitives.find(name) != xilinx_primitives.end();
}

data_store::~data_store() {
    store_entities_cache();
    store_scripts_cache();
    store_constraints_cache();
    store_data_file_cache();
}

void data_store::load_entities_cache() {
    std::ifstream entities(entities_file);
    std::string line;
    while (std::getline(entities, line)){
        std::shared_ptr<HDL_Resource> tmp = std::make_shared<HDL_Resource>(line);
        hdl_resources_cache[tmp->getName()]  = tmp;
    }
}

void data_store::store_entities_cache() {
    std::filesystem::remove(entities_file);
    std::ofstream entities_stream(entities_file);
    for (auto  [key, val] : hdl_resources_cache){
        if(this->is_primitive(key) || val == nullptr) continue;
        std::string serialized_entity = *val;
        entities_stream << serialized_entity << std::endl;
    }
}


void data_store::load_scripts_cache() {
    std::ifstream scripts_stream(scripts_file);
    std::string line;
    while (std::getline(scripts_stream, line)){
        std::shared_ptr<Script> tmp = std::make_shared<Script>(line);
        scripts_cache[tmp->get_name()]  = tmp;
    }
}

void data_store::store_scripts_cache() {
    std::filesystem::remove(scripts_file);
    std::ofstream itemss_stream(scripts_file);
    for (auto  [key, val] : scripts_cache){
        if(val == nullptr) continue;
        std::string serialized_item = *val;
        itemss_stream << serialized_item << std::endl;
    }
}

void data_store::load_constraints_cache() {
    std::ifstream stream(constraints_file);
    std::string line;
    while (std::getline(stream, line)){
        std::shared_ptr<Constraints> tmp = std::make_shared<Constraints>(line, true);
        constraints_cache[tmp->get_name()] = tmp;
    }
}

void data_store::store_constraints_cache() {
    std::filesystem::remove(constraints_file);
    std::ofstream items_stream(constraints_file);
    for (auto  [key, val] : constraints_cache){
        if(val == nullptr) continue;
        std::string serialized_item = *val;
        items_stream << serialized_item << std::endl;
    }
}

void data_store::clean_up_caches() {
    std::vector<std::string> evicted_items;
    for (auto  [key, val] : hdl_resources_cache){
        if(val== nullptr) continue;
        if(!std::filesystem::exists(val->get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        hdl_resources_cache.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : scripts_cache){
        if(!std::filesystem::exists(val->get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        scripts_cache.erase(item);
    }
    evicted_items.clear();


    for (auto  [key, val] : constraints_cache){
        if(!std::filesystem::exists(val->get_path())){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        constraints_cache.erase(item);
    }
}

void data_store::remove_stale_info(const std::filesystem::path& p) {
    std::vector<std::string> evicted_items;

    for (auto  [key, val] : hdl_resources_cache){
        if(val== nullptr) continue;
        if(val->get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        hdl_resources_cache.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : scripts_cache){
        if(val->get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        scripts_cache.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : constraints_cache){
        if(val->get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        constraints_cache.erase(item);
    }
    evicted_items.clear();

    for (auto  [key, val] : data_cache){
        if(val->get_path()==p.string()){
            evicted_items.push_back(key);
        }
    }
    for (const auto &item : evicted_items){
        data_cache.erase(item);
    }

}

void data_store::evict_hdl_entity(const std::string &name) {
    hdl_resources_cache.erase(name);
}

void data_store::evict_script(const std::string &name) {
    scripts_cache.erase(name);
}

void data_store::evict_constraint(const std::string &name) {
    constraints_cache.erase(name);
}

std::shared_ptr<DataFile> data_store::get_data_file(const std::string &name) {
    return data_cache[name];
}

void data_store::store_data_file(const std::shared_ptr<DataFile> &entity) {
    data_cache[entity->get_name()] = entity;
}

void data_store::store_data_file(const std::vector<std::shared_ptr<DataFile>> &vect) {
    for(auto &item: vect){
        store_data_file(item);
    }
}

void data_store::evict_data_file(const std::string &name) {
    data_cache.erase(name);
}

void data_store::load_data_file_cache() {
    std::ifstream data_files_stream(data_file);
    std::string line;
    while (std::getline(data_files_stream, line)){
        std::shared_ptr<DataFile> tmp = std::make_shared<DataFile>(line);
        data_cache[tmp->get_name()] = tmp;
    }
}

void data_store::store_data_file_cache() {
    std::filesystem::remove(data_file);
    std::ofstream items_stream(data_file);
    for (auto  [key, val] : data_cache){
        if(val == nullptr) continue;
        std::string serialized_item = *val;
        items_stream << serialized_item << std::endl;
    }
}