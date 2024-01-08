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

#include "frontend/analysis/documentation_analyzer.hpp"


TEST( documentation_analyzer , simple_peripheral) {

    std::ifstream is("check_files/documentation_analyzer/test_peripheral_definition.sv");

    Parameters_map params;

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



TEST( documentation_analyzer , parametric_peripheral) {

    std::ifstream is("check_files/test_data/Components/controls/PwmGenerator/rtl/ChainControlUnit.sv");
    Parameters_map params;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::unordered_map<std::string, module_documentation> results = doc.get_modules_documentation();

    module_documentation check_doc;
    check_doc.set_name("ChainControlUnit");
    check_doc.set_parametric();

    check_doc.add_register(register_documentation("tresh_$L", "Comparator $ treshold low", true, true, {"N_CHANNELS"}));
    check_doc.add_register(register_documentation("tresh_$H", "Comparator $ treshold high", true, true, {"N_CHANNELS"}));
    check_doc.add_register(register_documentation("deadtime_$", "Length of deadtime automatically inserted in pair A (if enabled)", true, true, {"N_CHANNELS"}));
    check_doc.add_register(register_documentation("counter_start", "Start Value for the PWM generator", true, true, {"1"}));
    check_doc.add_register(register_documentation("counter_stop", "Stop Value for the PWM generator", true, true, {"1"}));
    check_doc.add_register(register_documentation("tb_shift", "Carrier phase shift", true, true, {"1"}));

    register_documentation reg("out_en", "Output enable register", true, true, {"1"});
    field_documentation f("out_$", "enable output pair $",0,2);
    f.set_n_fields({"N_CHANNELS"});
    reg.add_field(f);
    check_doc.add_register(reg);

    reg = register_documentation("dt_en", "Deadtime insertion enable register", true, true, {"1"});
    f = field_documentation("pair_$", "Enable deadtime insertion pair $",0,1);
    f.set_n_fields({"N_CHANNELS"});
    reg.add_field(f);
    check_doc.add_register(reg);

    reg = register_documentation("ctrl", "Chain control register", true, true, {"1"});
    f = field_documentation("mode", "Chain counter mode",0,3);
    reg.add_field(f);
    check_doc.add_register(reg);


    std::unordered_map<std::string, module_documentation> check_map;
    check_map["ChainControlUnit"] = check_doc;

    ASSERT_EQ(check_map, results);
}





TEST( documentation_analyzer , processor_doc) {

    std::ifstream is("check_files/documentation_analyzer/test_processor_doc.sv");

    Parameters_map params;

    documentation_analyzer doc(is);
    doc.process_documentation(params);
    std::unordered_map<std::string, processor_instance> results = doc.get_processors_documentation();

    processor_instance check_doc;
    check_doc.set_name("current_controller");
    check_doc.set_target("processor");
    check_doc.set_address("PROCESSOR_BASE_ADDRESS");
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
