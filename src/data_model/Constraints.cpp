//
// Created by fils on 03/06/2021.
//

#include "data_model/Constraints.h"

#include <utility>



Constraints::Constraints(std::string n) {
    name = std::move(n);
}
Constraints::Constraints(const std::string &serialized_constraints, bool serialized) {
    std::istringstream stream(serialized_constraints);
    std::vector<std::string> tokens;
    std::string tmp;
    tokens.reserve(2);
    while(std::getline(stream, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = std::string(tokens[0]);
    path = std::string(tokens[1]);
}


std::string Constraints::get_name() {
    return name;
}

void Constraints::set_path(std::string p) {
    path = std::move(p);
}

std::string Constraints::get_path() {
    return path;
}

Constraints::operator std::string() {
    std::ostringstream ret_val;
    ret_val << name << "," << path;
    return ret_val.str();
}

bool operator==(const Constraints &lhs, const Constraints &rhs) {
    return lhs.name == rhs.name && lhs.path == rhs.path;
}
