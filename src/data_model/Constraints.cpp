//
// Created by fils on 03/06/2021.
//

#include "data_model/Constraints.h"

#include <utility>



Constraints::Constraints(std::string n) {
    name = std::move(n);
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
