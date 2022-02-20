// Copyright 2021 Filippo Savi
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

#include <gtest/gtest.h>

#include "analysis/sv_analyzer.h"

#include "data_model/bus_structure/bus_crossbar.h"
#include "data_model/bus_structure/bus_module.h"
#include "data_model/bus_structure/bus_registers.h"
#include "data_model/bus_structure/bus_component.h"

TEST( bus_structure , bus_structure_printing) {

    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(children,"crossbar_address_param");
    xbar->add_child(reg);
    xbar->add_child(mod);
    xbar->set_base_address(14);
    std::string test_string = "CROSSBAR -- crossbar_address_param -- 14\n  register_instance [registers] -- register_address_param -- 12\n  module_instance [module_type] -- module_address_param -- 13";
    std::string structure_string = xbar->to_string("");
    ASSERT_EQ(test_string, structure_string);
}

