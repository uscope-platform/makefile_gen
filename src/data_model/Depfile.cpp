//
// Created by fils on 02/06/2021.
//

#include "data_model/Depfile.h"

Depfile::Depfile(const std::string& filename) {
// read a JSON file
    std::ifstream dfstream(filename);
    dfstream >> content;
}

std::string Depfile::get_synth_tl() {
    return content["general"]["synth_tl"];
}

std::string Depfile::get_sim_tl() {
    return content["general"]["sim_tl"];
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

        if(item.contains("include_product")) {
            scr.set_include_products(item["include_product"]);
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
