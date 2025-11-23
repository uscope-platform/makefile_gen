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

#include "data_model/Script.hpp"

#include <utility>


Script::Script(const Script &S) {
    name = S.name;
    type = S.type;
    path = S.path;
    arguments = S.arguments;
    product_type = S.product_type;
    product_include = S.product_include;
}

Script::Script(std::string n, const std::string& t) {
    name = std::move(n);
    if(t=="tcl") type = tcl_script;
    else if (t=="python" || t == "py") type = python_script;
    else type = uninit_script;
    product_include = false;
}

std::string Script::get_name() {
    return name;
}

script_type_t Script::get_type() {
    return type;
}

std::vector<std::pair<std::string,std::string>> Script::get_arguments() {
    return arguments;
}

void Script::set_arguments(std::vector<std::string> args) {
    for(auto &item: args) {
        arguments.push_back({item, ""});
    }
}

void Script::set_arguments(std::vector<nlohmann::json> args) {
    for(auto &item: args) {
        arguments.push_back({item["name"], item["value"]});
    }
}

void Script::set_arguments(std::vector<std::pair<std::string, std::string>> args) {
    arguments = std::move(args);
}


void Script::set_path(std::string p) {
    path = std::move(p);
}

std::string Script::get_path() {
    return path;
}

bool operator==(const Script &lhs, const Script &rhs) {

    bool ret = true;
    ret &= lhs.name == rhs.name;
    ret &= lhs.path == rhs.path;
    ret &= lhs.type == rhs.type;
    ret &= lhs.arguments == rhs.arguments;
    ret &= lhs.product_type == rhs.product_type;
    ret &= lhs.product_include == rhs.product_include;

    return ret;
}

void Script::set_product(bool gen, std::string t) {
    product_include = gen;
    product_type = std::move(t);
}

bool Script::get_product_include() const {
    return product_include;
}

std::string Script::get_product_type() const {
    return product_type;
}



