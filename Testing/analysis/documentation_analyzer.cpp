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

#include "analysis/documentation_analyzer.h"

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
