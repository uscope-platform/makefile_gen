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

#include "data_model/Depfile.hpp"

Depfile::Depfile(const std::string& filename) {
// read a JSON file
    std::ifstream dfstream(filename);
    dfstream >> content;
}

Depfile::Depfile(const Depfile &file) {
    content = file.get_content();
}

std::string Depfile::get_synth_tl() {
    return content["general"]["synth_tl"];
}

std::string Depfile::get_sim_tl() {
    return content["general"]["sim_tl"];
}

std::string Depfile::get_bus_defining_package() {
    return content["general"]["bus_defining_package"];
}

std::vector<std::string> Depfile::get_additional_synth_modules() {
    return content["general"]["synth_modules"];
}

std::vector<std::string> Depfile::get_additional_sim_modules() {
    return content["general"]["sim_modules"];
}

std::vector<std::string> Depfile::get_excluded_modules() {
    return content["excluded_modules"];
}

std::vector<Constraints> Depfile::get_constraints() {
    std::vector<Constraints> retval;
    for(const auto& item : content["constraints"]){
        Constraints constr(item);
        retval.push_back(constr);
    }
    return retval;

}

std::vector<Script> Depfile::get_scripts() {
    std::vector<Script> retval;
    for(auto item : content["scripts"]){
        Script scr(item["name"], item["type"]);
        scr.set_arguments( item["arguments"]);

        if(item.contains("product_include")) {
            scr.set_product(item["product_include"], item["product_type"]);
        }
        retval.push_back(scr);
    }
    return retval;
}

std::string Depfile::get_project_name() {
    return content["general"]["project_name"];
}

std::vector<std::string> Depfile::get_include_directories() {
    return content["general"]["include_paths"];
}

json Depfile::get_bus_section() {
    return content["bus"];
}

bool Depfile::is_module_excluded(const std::string &s) {
    bool ret = false;
    for(auto &item: content["excluded_modules"]){
        ret |= (std::string) item == s;
    }
    return ret;
}

void Depfile::add_excluded_module(const std::string &s) {
    std::vector<std::string> exm = content["excluded_modules"];
    exm.insert(exm.end(), s);
    content["excluded_modules"] = exm;
}

Depfile::Depfile() {
    content["excluded_modules"] = std::vector<std::string>();
}
