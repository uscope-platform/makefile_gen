//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_DATA_STORE_H
#define MAKEFILEGEN_V2_DATA_STORE_H

#include <unordered_map>
#include <filesystem>
#include <utility>
#include <fstream>

#include "Resource.h"

class data_store {
public:
     data_store();
     Resource get_entity(const std::string& name);
     void store_entity(Resource entity);
     void store_entity(const std::vector<Resource>& vect);
     ~data_store();
private:

    void load_entities_cache();
    void store_entities_cache();

    std::unordered_map<std::string, Resource> entities_cache;
    std::string  store_path;
    std::string entities_file;
};



#endif //MAKEFILEGEN_V2_DATA_STORE_H
