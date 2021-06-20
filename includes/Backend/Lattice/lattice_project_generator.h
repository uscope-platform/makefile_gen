//
// Created by fils on 19/06/2021.
//

#ifndef MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H
#define MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H

#include <ios>
#include <set>
#include <iostream>
#include <fstream>
#include <regex>

#include "data_model/Depfile.h"
#include "../project_generator_base.h"

#include "third_party/inja.hpp"
#include "third_party/json.hpp"

using json = nlohmann::json;

class lattice_project_generator : public project_generator_base{
public:
    lattice_project_generator(): project_generator_base("make_project_lscc.j2") {};

};

#endif //MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H
