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
#include <fstream>

#include "analysis/documentation_analyzer.hpp"

TEST( documentation_analyzer , package_bus_hierarchy) {

    std::ifstream is("check_files/documentation_analyzer/test_bus_hierarchy.sv");

    std::unordered_map<std::string, uint32_t> params;
    params["bus_base"] = 1136656384;
    params["timebase"] = 351;
    params["gpio"] = 4096;
    params["delay_emulator"] = 168;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::vector<std::shared_ptr<bus_crossbar>> results = doc.get_bus_roots();


    std::shared_ptr<bus_crossbar> root = std::make_shared<bus_crossbar>();
    root->set_parameter("bus_base");
    root->set_target("test_package");
    root->set_base_address(1136656384);

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>();
    xbar->set_parameter("timebase");
    xbar->set_base_address(351);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("general_ctrls", "gpio");
    mod->set_base_address(4096);
    xbar->add_child(mod);

    root->add_child(xbar);

    std::vector<std::shared_ptr<bus_crossbar>> check_vect({root});

    ASSERT_EQ(check_vect.size(), results.size());
    ASSERT_EQ(*check_vect[0], *results[0]);
}


TEST( documentation_analyzer , module_bus_hierarchy) {

    std::ifstream is("check_files/documentation_analyzer/test_module_hierarchy.sv");

    std::unordered_map<std::string, uint32_t> params;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::unordered_map<std::string, std::vector<bus_submodule>> results = doc.get_bus_submodules();

    bus_submodule sc;
    sc.set_name("SC");
    sc.set_module_type("SyndromeCalculator");
    sc.set_offset(0);

    bus_submodule sp;
    sp.set_name("COMM");
    sp.set_module_type("SPI");
    sp.set_offset(64);


    bus_submodule ei;
    ei.set_name("ext_in12terface");
    ei.set_offset(1056);
    ei.set_module_type("SPI1");
    sp.add_child(ei);

    std::unordered_map<std::string, std::vector<bus_submodule>> check_map;
    check_map["Decoder"] = {sc, sp};

    ASSERT_EQ(check_map, results);
}


TEST( documentation_analyzer , peripheral) {

    std::ifstream is("check_files/documentation_analyzer/test_peripheral_definition.sv");

    std::unordered_map<std::string, uint32_t> params;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::unordered_map<std::string, module_documentation> results = doc.get_modules_documentation();

    module_documentation check_doc;
    check_doc.set_name("Decoder");
    register_documentation reg_1("simple_register_r", 0, "Single word read only register", true, false);
    register_documentation reg_2("simple_register_w", 0x4, "Single word write only register", false, true);
    register_documentation reg_3("field_registers", 0x20, "register with multiple fields", true, true);
    field_documentation field_1("field_1", "First field",0,8);
    field_documentation field_2("field_2", "Second Field",8,8);
    reg_3.add_field(field_1);
    reg_3.add_field(field_2);
    check_doc.add_register(reg_1);
    check_doc.add_register(reg_2);
    check_doc.add_register(reg_3);

    std::unordered_map<std::string, module_documentation> check_map;
    check_map["Decoder"] = check_doc;

    ASSERT_EQ(check_map, results);
}


TEST( documentation_analyzer , processor_doc) {

    std::ifstream is("check_files/documentation_analyzer/test_processor_doc.sv");

    std::unordered_map<std::string, uint32_t> params;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::unordered_map<std::string, processor_instance> results = doc.get_processors_documentation();

    processor_instance check_doc;
    check_doc.set_name("current_controller");
    check_doc.set_target("processor");
    check_doc.set_address("0x83c00000");
    io a;
    a.name = "Current";
    a.type = input;
    a.address = 1;
    check_doc.add_io(a);

    a.name = "Speed";
    a.type = input;
    a.address = 2;
    check_doc.add_io(a);

    a.name = "duty";
    a.type = output;
    a.address = 15;
    check_doc.add_io(a);

    std::unordered_map<std::string, processor_instance> check_map;
    check_map["SicDriveMasterCurrentControl"] = check_doc;

    ASSERT_EQ(check_map, results);
}
