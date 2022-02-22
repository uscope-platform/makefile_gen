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

#include <data_model/HDL_Resource.h>

#include <utility>

HDL_Resource::HDL_Resource() {
    name = "";
    path = "";
    hdl_type = null_feature;
    resource_type = null_resource;
}

///  Resource object creator
/// \param t HDL entity feature
/// \param n Name of the feature
/// \param p Path of the file
/// \param deps Dependencies of the file
/// \param r_type type of resource
HDL_Resource::HDL_Resource(sv_feature t, std::string n, std::string p, hdl_deps_t deps, resource_type_t r_type) {
    hdl_type = t;
    name = std::move(n);
    path = std::move(p);
    dependencies = std::move(deps);
    resource_type = r_type;
}

HDL_Resource::HDL_Resource(const std::string& serialized_obj) {
    std::vector<std::string> tokens = tokenize(serialized_obj, ',');
    name = std::string(tokens[0]);
    hdl_type = sv_feature(std::stoi(tokens[1]));
    resource_type = resource_type_t(std::stoi(tokens[2]));
    path = std::string(tokens[3]);
    int dep_array_size = std::stoi(tokens[4]);
    for(int i= 5; i<5+dep_array_size*2; i=i+2){
        dependencies[tokens[i]] = sv_feature(std::stoi(tokens[i+1]));
    }
    int param_array_size = std::stoi(tokens[5+dep_array_size*2]);
    for(int i= 6+dep_array_size*2; i<6+dep_array_size*2+param_array_size*2; i=i+2){
        parameters[tokens[i]] = std::stoi(tokens[i+1]);
    }
    std::string bus_root_string;

    int bus_token_start = 6+dep_array_size*2+param_array_size*2;

    for(int i=bus_token_start; i<tokens.size(); ++i){
        bus_root_string += tokens[i];
        if(i != tokens.size()-1)
            bus_root_string += ",";
    }

    if(!bus_root_string.empty()){
        deserialize_bus_vector(bus_root_string);
    }

}

void HDL_Resource::deserialize_bus_vector(const std::string& ser) {

    std::vector<std::string> bus_vect = tokenize(ser, '-');
    for(auto &item:bus_vect){
        bus_roots.push_back(std::make_shared<bus_crossbar>(item));
    }
}

std::vector<std::string> HDL_Resource::tokenize(const std::string& str, char token) {
    std::istringstream ss(str);
    std::vector<std::string> tokens;
    std::string tmp;
    while(std::getline(ss, tmp, token)) {
        tokens.push_back(tmp);
    }
    return  tokens;
}


const std::string &HDL_Resource::getName() const {
    return name;
}

HDL_Resource::operator std::string() {
    std::ostringstream tmp;
    tmp << name << "," << std::to_string(feature_to_integer(hdl_type)) << "," << std::to_string(resource_to_integer(resource_type)) << "," << path;

    tmp << "," << std::to_string(dependencies.size());

    for (auto const& [key, val] : dependencies){
        tmp << ',' << key << ',' << std::to_string(feature_to_integer(val));
    }

    tmp << "," << std::to_string(parameters.size());

    for (auto const& [key, val] : parameters){
        tmp << ',' << key << ',' << std::to_string(val);
    }
    if(!bus_roots.empty()){
        tmp << ",";
        // THE CROSSBAR SERIALIZATION ALREADY USES COMMA AND SLASH AS SEPARATORS, THUS HERE A DASH IS USED
        for(int i = 0; i < bus_roots.size(); ++i){
            std::string serialized_bus = *bus_roots[i];
            tmp << serialized_bus;
            if(i != bus_roots.size() - 1) tmp << "-";
        }

    }

    return tmp.str();
}

hdl_deps_t HDL_Resource::get_dependencies() {
    return dependencies;
}

bool HDL_Resource::is_interface() {
    return hdl_type == interface;
}

std::string HDL_Resource::get_path() {
    return path;
}

bool operator==(const HDL_Resource &lhs, const HDL_Resource &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.path == rhs.path;
    ret &= lhs.resource_type == rhs.resource_type;
    ret &= lhs.hdl_type == rhs.hdl_type;
    ret &= lhs.dependencies == rhs.dependencies;
    ret &= lhs.parameters == rhs.parameters;

    if(lhs.bus_roots.size() != rhs.bus_roots.size()){
        return false;
    } else {
        for(int i = 0; i<lhs.bus_roots.size(); ++i){
            if(lhs.bus_roots[i] == nullptr && rhs.bus_roots[i] == nullptr)
                ret &= true;

            if(lhs.bus_roots[i] != nullptr ^ rhs.bus_roots[i] != nullptr){
                ret &= false;
            }

            ret &= *lhs.bus_roots[i] == *rhs.bus_roots[i];
        }
    }



    return ret;
}

void HDL_Resource::add_dependencies(hdl_deps_t deps) {
    dependencies.insert( deps.begin(), deps.end());
}
