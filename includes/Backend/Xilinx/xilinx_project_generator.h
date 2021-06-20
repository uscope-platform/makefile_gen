//
// Created by fils on 05/06/2021.
//

#ifndef MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
#define MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H

#include "../project_generator_base.h"


class xilinx_project_generator: public project_generator_base{
public:
    xilinx_project_generator() : project_generator_base("make_project_xlnx.j2") {};

};


#endif //MAKEFILEGEN_V2_XILINX_PROJECT_GENERATOR_H
