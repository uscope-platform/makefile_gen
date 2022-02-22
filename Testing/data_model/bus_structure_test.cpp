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

TEST( bus_structure , bus_registers_serialize) {
    bus_module mod("module_instance", "module_type", "module_address_param");
    mod.set_base_address(13);

    std::string result = mod;
    ASSERT_EQ(result,"module_instance,module_type,module_address_param,13,2");
}

TEST( bus_structure , bus_module_deserialize) {
    bus_module res("module_instance,module_type,module_address_param,13,2");

    bus_module checker("module_instance", "module_type", "module_address_param");
    checker.set_base_address(13);

    ASSERT_EQ(res, checker);
}


TEST( bus_structure , bus_module_serialize) {
    bus_registers mod("register_instance", "register_address_param");
    mod.set_base_address(12);

    std::string result = mod;
    ASSERT_EQ(result,"register_instance,register_address_param,12,1");
}

TEST( bus_structure , bus_registers_deserialize) {
    bus_registers res("register_instance,register_address_param,12,1");

    bus_registers checker("register_instance", "register_address_param");
    checker.set_base_address(12);

    ASSERT_EQ(res, checker);
}

TEST( bus_structure , bus_crossbar_serialize) {

    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    bus_crossbar xbar(children,"crossbar_address_param");
    xbar.add_child(reg);
    xbar.add_child(mod);
    xbar.set_base_address(14);

    std::string result = xbar;
    ASSERT_EQ(result,"14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2");
}

TEST( bus_structure , bus_crossbar_deserialize) {
    bus_crossbar res("14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2");

    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    bus_crossbar checker(children,"crossbar_address_param");
    checker.add_child(reg);
    checker.add_child(mod);
    checker.set_base_address(14);

    ASSERT_EQ(res, checker);
}

