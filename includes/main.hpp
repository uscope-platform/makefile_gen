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


#include "third_party/CLI11.h"

#include "frontend/Repository_walker.h"
#include "data_model/data_store.h"
#include "data_model/settings_store.h"
#include "analysis/sv_analyzer.h"
#include "data_model/Depfile.h"
#include "Backend/Dependency_resolver.h"
#include "Backend/Xilinx/xilinx_project_generator.h"
#include "Backend/python_script_runner.h"
#include "Backend/Auxiliary_resolver.h"
#include "Backend/Xilinx/Vivado_manager.h"
#include "Backend/Lattice/lattice_project_generator.h"
#include "Backend/Lattice/Radiant_manager.h"
#include "Backend/new_app_generator.h"
#include "Backend/application_definition_generator.h"
#include "Backend/peripheral_definition_generator.h"

#endif //MAKEFILEGEN_V2_MAIN_HPP
