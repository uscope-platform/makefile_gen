//
// Created by fils on 28/05/2021.
//

#include <data_model/HDL_entity.h>

#include <utility>

HDL_entity::HDL_entity(sv_feature t, std::string n, std::string p, hdl_deps_t deps, std::string lang) {
    type = t;
    name = std::move(n);
    path = std::move(p);
    dependencies = std::move(deps);
    language = std::move(lang);
}

HDL_entity::HDL_entity(const std::string& serialized_obj) {
    std::istringstream ss(serialized_obj);
    std::vector<std::string> tokens;
    std::string tmp;
    while(std::getline(ss, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = tokens[0];
    type = sv_feature(std::stoi(tokens[1]));
    path = tokens[2];
    language = tokens[3];
    tokens.erase(tokens.begin(), tokens.begin()+4);
    for(int i= 0; i<tokens.size(); i=i+2){
        dependencies[tokens[i]] = sv_feature(std::stoi(tokens[i+1]));
    }
}

HDL_entity::operator std::string() {
    std::ostringstream tmp;
    tmp<<name<<"," << std::to_string(as_integer(type))  <<","<<path<<","<< language;
    std::string part_1 = tmp.str();
    tmp.str("");
    for (auto const& [key, val] : dependencies){
        tmp << ',' << key << ',' << std::to_string(as_integer(val));
    }
    return part_1 + tmp.str();
}
