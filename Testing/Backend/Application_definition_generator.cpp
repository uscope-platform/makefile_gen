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
#include <filesystem>

#include "data_model/Depfile.h"
#include "Backend/application_definition_generator.h"
#include "data_model/bus_structure/bus_registers.h"
#include "data_model/bus_structure/bus_module.h"
#include "data_model/bus_structure/bus_crossbar.h"

TEST( app_def_generation , generate_app_def) {
    Depfile file("check_files/Depfile_gs");


    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(children,"crossbar_address_param");
    xbar->add_child(reg);
    xbar->add_child(mod);
    xbar->set_base_address(14);
    application_definition_generator gen(file, xbar);
    gen.write_definition_file("test.json");

    nlohmann::json result;
    std::ifstream res_str("test.json");
    res_str >> result;

    nlohmann::json ref_app;
    ref_app["application_name"] = "test_app";
    ref_app["bitstream"] = "";
    ref_app["channels"] = std::vector<nlohmann::json>();
    ref_app["channel_groups"] = std::vector<nlohmann::json>();
    ref_app["clock_frequency"] = 100000000;
    ref_app["initial_registers_values"] = std::vector<nlohmann::json>();
    ref_app["macro"] = std::vector<nlohmann::json>();
    ref_app["n_enables"] = 0;
    ref_app["parameters"] = std::vector<nlohmann::json>();
    ref_app["timebase_address"] = "";

    std::vector<nlohmann::json> check_peripherals;

    nlohmann::json p1;
    p1["base_address"] = "12";
    p1["name"] = "register_instance";
    p1["peripheral_id"] = "register_instance";
    p1["proxied"] = false;
    p1["proxy_address"] = "0";
    p1["spec_id"] = "register_instance";
    p1["type"] = "Registers";
    p1["user_accessible"] = false;
    check_peripherals.push_back(p1);

    nlohmann::json p2;
    p2["base_address"] = "13";
    p2["name"] = "module_instance";
    p2["peripheral_id"] = "module_instance";
    p2["proxied"] = false;
    p2["proxy_address"] = "0";
    p2["spec_id"] = "module_type";
    p2["type"] = "Registers";
    p2["user_accessible"] = false;
    check_peripherals.push_back(p2);

    ref_app["peripherals"] = check_peripherals;

    std::filesystem::remove("test.json");

    ASSERT_EQ(ref_app, result);
}

