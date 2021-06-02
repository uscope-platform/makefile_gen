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

std::shared_ptr<Resource_base> data_store::get_HDL_resource(const std::string& name) {
    return hdl_resources_cache[name];
}

void data_store::store_entity(const std::shared_ptr<Resource_base>& entity) {
    std::shared_ptr<HDL_Resource> inner_entity = std::static_pointer_cast<HDL_Resource>(entity);
    hdl_resources_cache[inner_entity->getName()] = inner_entity;
}
void data_store::store_entity(const std::vector<std::shared_ptr<Resource_base>>& vect) {
    for(auto &item: vect){
        std::shared_ptr<HDL_Resource> i = std::static_pointer_cast<HDL_Resource>(item);
        hdl_resources_cache[i->getName()] = i;
    }
}

data_store::~data_store() {
    store_entities_cache();
}

void data_store::load_entities_cache() {
    std::ifstream setting_stream(entities_file);
    std::string line;
    while (std::getline(setting_stream, line)){
        std::shared_ptr<HDL_Resource> tmp = std::make_shared<HDL_Resource>(line);
        hdl_resources_cache[tmp->getName()]  = tmp;
    }
}

void data_store::store_entities_cache() {
    std::filesystem::remove(entities_file);
    std::ofstream entities_stream(entities_file);
    for (auto  [key, val] : hdl_resources_cache){
        std::string serialized_entity = *val;
        entities_stream << serialized_entity << std::endl;
    }
}