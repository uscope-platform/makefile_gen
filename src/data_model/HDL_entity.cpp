//
// Created by fils on 28/05/2021.
//

#include <data_model/HDL_entity.h>

HDL_entity::HDL_entity(std::string t, std::string n, std::string p) {
    type = std::move(t);
    name = std::move(n);
    path = std::move(p);
}

HDL_entity::operator std::string() {
    std::ostringstream tmp;
    tmp<<name<<","<<type<<","<<path;
    return tmp.str();
}
