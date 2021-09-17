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
