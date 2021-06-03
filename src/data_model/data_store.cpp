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

std::shared_ptr<Script> data_store::get_script(const std::string &name) {
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

std::shared_ptr<Constraints> data_store::get_constraint(const std::string &name) {
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