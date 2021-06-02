//
// Created by fils on 02/06/2021.
//

#ifndef MAKEFILEGEN_V2_DEPFILE_H
#define MAKEFILEGEN_V2_DEPFILE_H

#include <string>
#include <fstream>
#include <iostream>

#include "third_party/json.hpp"

using json = nlohmann::json;

class Depfile {
public:
    explicit Depfile(const std::string& filename);
    std::string get_synth_tl();
    std::string get_sim_tl();
    std::vector<std::string> get_additional_synth_modules();
    std::vector<std::string> get_additional_sim_modules();
    std::vector<std::string> get_excluded_modules();

private:
    json content;
};


#endif //MAKEFILEGEN_V2_DEPFILE_H
