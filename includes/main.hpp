//
// Created by fils on 27/05/2021.
//

#ifndef MAKEFILEGEN_V2_MAIN_HPP
#define MAKEFILEGEN_V2_MAIN_HPP

#include <string>

#include "third_party/CLI11.h"

#include "frontend/Repository_walker.h"
#include "data_model/data_store.h"
#include "data_model/settings_store.h"
#include "analysis/sv_analyzer.h"
#include "data_model/Depfile.h"
#include "Backend/Dependency_resolver.h"
#include "Backend/Xilinx/xilinx_project_generator.h"
#include "Backend/Auxiliary_resolver.h"
#include "Backend/Xilinx/Vivado_manager.h"
#include "Backend/Lattice/lattice_project_generator.h"
#include <Backend/Lattice/Radiant_manager.h>

#endif //MAKEFILEGEN_V2_MAIN_HPP
