//
// Created by fils on 28/05/2021.
//

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
    std::istringstream ss(serialized_obj);
    std::vector<std::string> tokens;
    std::string tmp;
    while(std::getline(ss, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = tokens[0];
    hdl_type = sv_feature(std::stoi(tokens[1]));
    resource_type = resource_type_t(std::stoi(tokens[2]));
    path = tokens[3];
    tokens.erase(tokens.begin(), tokens.begin()+4);
    for(int i= 0; i<tokens.size(); i=i+2){
        dependencies[tokens[i]] = sv_feature(std::stoi(tokens[i+1]));
    }
}

const std::string &HDL_Resource::getName() const {
    return name;
}

HDL_Resource::operator std::string() {
    std::ostringstream tmp;
    tmp << name << "," << std::to_string(feature_to_integer(hdl_type)) << "," << std::to_string(resource_to_integer(resource_type)) << "," << path;
    std::string part_1 = tmp.str();
    tmp.str("");
    for (auto const& [key, val] : dependencies){
        tmp << ',' << key << ',' << std::to_string(feature_to_integer(val));
    }
    std::string part_2 = tmp.str();
    return part_1 + part_2;
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
