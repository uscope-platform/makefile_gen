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

#ifndef MAKEFILEGEN_V2_MAIN_HPP
#define MAKEFILEGEN_V2_MAIN_HPP

#include <string>


#include <CLI/CLI.hpp>

#include "frontend/Repository_walker.hpp"
#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "analysis/sv_analyzer.hpp"
#include "data_model/Depfile.hpp"
#include "Backend/Dependency_resolver.hpp"
#include "Backend/Xilinx/xilinx_project_generator.hpp"
#include "Backend/python_script_runner.hpp"
#include "Backend/Auxiliary_resolver.hpp"
#include "Backend/Xilinx/Vivado_manager.hpp"
#include "Backend/Lattice/lattice_project_generator.hpp"
#include "Backend/Lattice/Radiant_manager.hpp"
#include "Backend/new_app_generator.hpp"
#include "Backend/uplatform/application_definition_generator.hpp"
#include "Backend/uplatform/peripheral_definition_generator.hpp"
#include "data_model/bus_mapping/bus_mapper.hpp"

#endif //MAKEFILEGEN_V2_MAIN_HPP
