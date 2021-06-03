//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_DATA_STORE_H
#define MAKEFILEGEN_V2_DATA_STORE_H

#include <unordered_map>
#include <filesystem>
#include <utility>
#include <fstream>

#include "HDL_Resource.h"
#include "Script.h"
#include "Constraints.h"

class data_store {
public:
     data_store();
     std::shared_ptr<HDL_Resource> get_HDL_resource(const std::string& name);
     void store_hdl_entity(const std::shared_ptr<HDL_Resource>& entity);
     void store_hdl_entity(const std::vector<std::shared_ptr<HDL_Resource>> & vect);

    std::shared_ptr<Script> get_script(const std::string& name);
    void store_script(const std::shared_ptr<Script>& entity);
    void store_script(const std::vector<std::shared_ptr<Script>> & vect);

    std::shared_ptr<Constraints> get_constraint(const std::string& name);
    void store_constraint(const std::shared_ptr<Constraints>& entity);
    void store_constraint(const std::vector<std::shared_ptr<Constraints>> & vect);

    ~data_store();
private:

    void load_entities_cache();
    void store_entities_cache();

    std::unordered_map<std::string, std::shared_ptr<HDL_Resource>> hdl_resources_cache;
    std::unordered_map<std::string, std::shared_ptr<Script>> scripts_cache;
    std::unordered_map<std::string, std::shared_ptr<Constraints>> constraints_cache;
    std::string  store_path;
    std::string entities_file;
};



#endif //MAKEFILEGEN_V2_DATA_STORE_H
