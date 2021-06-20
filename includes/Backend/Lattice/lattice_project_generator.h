//
// Created by fils on 19/06/2021.
//

#ifndef MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H
#define MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H


#include "../project_generator_base.h"

class lattice_project_generator : public project_generator_base{
public:
    lattice_project_generator(): project_generator_base("make_project_lscc.j2") {};

};

#endif //MAKEFILEGEN_V2_LATTICE_PROJECT_GENERATOR_H
