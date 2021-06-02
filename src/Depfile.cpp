//
// Created by fils on 02/06/2021.
//

#include "Depfile.h"

Depfile::Depfile(const std::string& filename) {
// read a JSON file
    std::ifstream dfstream(filename);
    dfstream >> content;
}

std::string Depfile::get_synth_tl() {
    return content["general"]["synth_tl"];
}

std::string Depfile::get_sim_tl() {
    return content["general"]["sym_tl"];
}

std::vector<std::string> Depfile::get_additional_synth_modules() {
    return content["general"]["synth_modules"];
}

std::vector<std::string> Depfile::get_additional_sim_modules() {
    return content["general"]["sym_modules"];
}

std::vector<std::string> Depfile::get_excluded_modules() {
    return content["sym_modules"];
}
