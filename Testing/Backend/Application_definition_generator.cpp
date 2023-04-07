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

#include "data_model/Depfile.hpp"
#include "Backend/uplatform/application_definition_generator.hpp"
#include "data_model/documentation/bus_structure/bus_module.hpp"
#include "data_model/documentation/bus_structure/bus_crossbar.hpp"




class app_def_generation : public ::testing::Test {
protected:
    void SetUp() {
        d_store = std::make_shared<data_store>(true);

        HDL_Resource mod_res(module, "module_type", "test/path.sv");

        bus_submodule sc;
        sc.set_name("SC");
        sc.set_module_type("SyndromeCalculator");
        sc.set_offset(0);

        bus_submodule tm2;
        tm2.set_name("Decoder");
        tm2.set_module_type("Decoder");
        tm2.set_offset(10);

        mod_res.set_submodules({sc, tm2});

        d_store->store_hdl_entity(mod_res);

        HDL_Resource mod_res_2(module, "register_type", "test/path.sv");
        d_store->store_hdl_entity(mod_res_2);
    }

    virtual void TearDown() {
        d_store->evict_hdl_entity("module_type");
        d_store->evict_hdl_entity("register_type");
    }
    std::shared_ptr<data_store> d_store;
};

TEST_F( app_def_generation , generate_app_def) {

    Depfile file("check_files/Depfile_gs");


    std::shared_ptr<bus_module> reg = std::make_shared<bus_module>("register_instance",  "register_type");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type");
    mod->set_base_address(13);

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>("crossbar_address_param");
    xbar->add_child(reg);
    xbar->add_child(mod);
    xbar->set_base_address(14);


    application_definition_generator gen(file, xbar, d_store);
    gen.construct_application();
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
    p1["base_address"] = "0xc";
    p1["name"] = "register_instance";
    p1["peripheral_id"] = "register_instance";
    p1["proxied"] = false;
    p1["proxy_address"] = "0";
    p1["spec_id"] = "register_type";
    check_peripherals.push_back(p1);

    nlohmann::json p3;
    p3["base_address"] = "0xd";
    p3["name"] = "module_instance.SC";
    p3["peripheral_id"] = "module_instance.SC";
    p3["proxied"] = false;
    p3["proxy_address"] = "0";
    p3["spec_id"] = "SyndromeCalculator";
    check_peripherals.push_back(p3);

    nlohmann::json p4;
    p4["base_address"] = "0x17";
    p4["name"] = "module_instance.Decoder";
    p4["peripheral_id"] = "module_instance.Decoder";
    p4["proxied"] = false;
    p4["proxy_address"] = "0";
    p4["spec_id"] = "Decoder";
    check_peripherals.push_back(p4);

    ref_app["peripherals"] = check_peripherals;
    ref_app["soft_cores"] = std::vector<nlohmann::json>();

    std::filesystem::remove("test.json");

    ASSERT_EQ(ref_app, result);
}
