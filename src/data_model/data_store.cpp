//
// Created by fils on 28/05/2021.
//

#include "data_model/data_store.h"


data_store::data_store() {
    store_path = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    std::filesystem::create_directory(store_path);

    entities_file = store_path + "/entities";

    if(std::filesystem::exists(entities_file)){
        load_entities_cache();
    }
}

HDL_entity data_store::get_entity(const std::string& name) {
    return entities_cache[name];
}

void data_store::store_entity(HDL_entity entity, const std::string& name) {
    entities_cache[name] = std::move(entity);
}

data_store::~data_store() {
    store_entities_cache();
}

void data_store::load_entities_cache() {
    std::ifstream setting_stream(entities_file);
    std::string line;
    while (std::getline(setting_stream, line)){
        HDL_entity tmp(line);
        entities_cache[tmp.getName()]  = tmp;
    }
}

void data_store::store_entities_cache() {
    std::filesystem::remove(entities_file);
    std::ofstream entities_stream(entities_file);
    for (auto  [key, val] : entities_cache){
        std::string serialized_entity = val;
        entities_stream << serialized_entity << std::endl;
    }
}
