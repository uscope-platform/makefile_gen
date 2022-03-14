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

#include "data_model/Depfile.h"
#include "data_model/HDL_Resource.h"
#include "data_model/data_store.h"
#include "Backend/peripheral_definition_generator.h"


class periph_def_generation : public ::testing::Test {
protected:
    void SetUp() {
        d_store = std::make_shared<data_store>(true);


        module_documentation doc;
        doc.set_name("test_module");
        register_documentation reg_1("simple_register_r", 0, "Single word read only register", true, false);
        register_documentation reg_2("simple_register_w", 0x4, "Single word write only register", false, true);
        register_documentation reg_3("field_registers", 0x20, "register with multiple fields", true, true);
        field_documentation field_1("field_1", "First field",0,8);
        field_documentation field_2("field_2", "Second Field",8,8);
        reg_3.add_field(field_1);
        reg_3.add_field(field_2);
        doc.add_register(reg_1);
        doc.add_register(reg_2);
        doc.add_register(reg_3);


        HDL_Resource mod_entity(module, "test_module", "test/path.sv", hdl_deps_t(), verilog_entity);
        mod_entity.set_documentation(doc);
        d_store->store_hdl_entity(mod_entity);
    }

    virtual void TearDown() {
        d_store->evict_hdl_entity("register_type");
    }
    std::shared_ptr<data_store> d_store;
};

TEST_F( periph_def_generation , generate_periph_def) {
    Depfile file("check_files/Depfile_gs");


    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("test_module_address_param",  "test_module");
    mod->set_base_address(12);

    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>("top_level_address_param");
    xbar->add_child(mod);
    xbar->set_base_address(14);


    peripheral_definition_generator uut(file, xbar,d_store);
    auto result = uut.get_peripheral_definitions();

    nlohmann::json check;
    check["test_module"] = nlohmann::json();
    check["test_module"]["name"] = "test_module";
    check["test_module"]["version"] = "1.0";

    std::vector<nlohmann::json> check_vect;

    nlohmann::json reg_1;
    reg_1["ID"] = "simple_register_r";
    reg_1["register_name"] = "simple_register_r";
    reg_1["description"] = "Single word read only register";
    reg_1["direction"] = "R";
    reg_1["offset"] = "0x0";
    reg_1["register_format"] = "single";
    reg_1["fields"] = std::vector<nlohmann::json>();
    check_vect.push_back(reg_1);

    nlohmann::json reg_2;
    reg_2["ID"] = "simple_register_w";
    reg_2["register_name"] = "simple_register_w";
    reg_2["description"] = "Single word write only register";
    reg_2["direction"] = "W";
    reg_2["offset"] = "0x4";
    reg_2["register_format"] = "single";
    reg_2["fields"] = std::vector<nlohmann::json>();
    check_vect.push_back(reg_2);


    nlohmann::json reg_3;
    reg_3["ID"] = "field_registers";
    reg_3["register_name"] = "field_registers";
    reg_3["description"] = "register with multiple fields";
    reg_3["direction"] = "RW";
    reg_3["offset"] = "0x20";
    reg_3["register_format"] = "single";
    reg_3["fields"] = std::vector<nlohmann::json>();

    nlohmann::json field1;
    field1["name"] = "field_1";
    field1["description"] = "First field";
    field1["offset"] = 0;
    field1["length"] = 8;
    reg_3["fields"].push_back(field1);

    nlohmann::json field2;
    field2["name"] = "field_2";
    field2["description"] = "Second Field";
    field2["offset"] = 8;
    field2["length"] = 8;
    reg_3["fields"].push_back(field2);

    check_vect.push_back(reg_3);
    check["test_module"]["registers"] = check_vect;

    ASSERT_EQ(std::vector<nlohmann::json>({check}), result);
}
