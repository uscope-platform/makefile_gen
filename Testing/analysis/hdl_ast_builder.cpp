//  Copyright 2023 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.



#include <gtest/gtest.h>
#include <filesystem>


#include "frontend/analysis/sv_analyzer.hpp"
#include "analysis/HDL_ast_builder.hpp"
#include "data_model/HDL/parameters/Parameter_processor.hpp"

TEST( hdl_ast_builder, pid_ast_build) {


    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    std::vector<std::string> paths = {
            "Components/controls/PID/rtl",
            "Components/controls/integrator/rtl",
            "Components/Common",
            "Components/system/axi_lite/simple_register_cu/rtl",
            "Components/system/axi_lite/skid_buffer/rtl"
    };

    auto prefix = "check_files/test_data/";
    for(auto &p:paths){
        for(auto &f:std::filesystem::directory_iterator(prefix + p)){
            if(f.path().extension() == ".v" || f.path().extension() == ".sv"){
                sv_analyzer analyzer(f.path());
                analyzer.cleanup_content("`(.*)");

                for(auto &entity:analyzer.analyze()){
                    d_store->store_hdl_entity(entity);
                }
            }
        }
    }



    HDL_ast_builder b(s_store, d_store);
    auto synth_ast = b.build_ast("PID", {});


    auto ast_dump = synth_ast.dump();
    nlohmann::json check_obj = nlohmann::json::parse(R"({"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"CU","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[63]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[0,0,0,0,32767,-32767,32767,-32767,65793]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[9]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[9]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[0]]]}},"ports_map":{"axil":"axil","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset"}},{"children":[],"instance_name":"pid_int","instance_type":"Integrator","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[16]}},"ports_map":{"clock":"clock","error_in":"integrator_in","input_valid":"integrator_in_valid","limit_int_down":"limit_int_down","limit_int_up":"limit_int_up","out":"integral_out","reset":"reset"}}],"instance_name":"TL","instance_type":"PID","parameters":{"ADDITIONAL_BITS":{"name":"ADDITIONAL_BITS","type":"numeric_parameter","value":[16]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[0,0,0,0,32767,-32767,32767,-32767,65793]]]},"INPUT_DATA_WIDTH":{"name":"INPUT_DATA_WIDTH","type":"numeric_parameter","value":[12]},"OUTPUT_DATA_WIDTH":{"name":"OUTPUT_DATA_WIDTH","type":"numeric_parameter","value":[16]}},"ports_map":{}})");

    ASSERT_EQ(ast_dump, check_obj);
}



TEST( hdl_ast_builder, spi_ast_build) {


    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    std::vector<std::string> paths = {
            "Components/comms/SPI/rtl",
            "Components/system/EnableGenerator/rtl/",
            "Components/Common",
            "Components/system/axi_lite/simple_register_cu/rtl",
            "Components/system/axi_lite/skid_buffer/rtl"
    };

    auto prefix = "check_files/test_data/";
    for(auto &p:paths){
        for(auto &f:std::filesystem::directory_iterator(prefix + p)){
            if(f.path().extension() == ".v" || f.path().extension() == ".sv"){
                sv_analyzer analyzer(f.path());
                analyzer.cleanup_content("`(.*)");

                for(auto &entity:analyzer.analyze()){
                    d_store->store_hdl_entity(entity);
                }
            }
        }
    }



    HDL_ast_builder b(s_store, d_store);
    auto synth_ast = b.build_ast("SPI", {});


    auto ast_dump = synth_ast.dump();
    nlohmann::json check_obj = nlohmann::json::parse(R"({"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","numeric_value":[32],"string_value":[""],"type":"numeric_parameter"},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","numeric_value":[32],"string_value":[""],"type":"numeric_parameter"},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","numeric_value":[36],"string_value":[""],"type":"numeric_parameter"},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"CU","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","numeric_value":[63],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_0":{"name":"INITIAL_OUTPUT_VALUES_0","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_1":{"name":"INITIAL_OUTPUT_VALUES_1","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_2":{"name":"INITIAL_OUTPUT_VALUES_2","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_3":{"name":"INITIAL_OUTPUT_VALUES_3","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_4":{"name":"INITIAL_OUTPUT_VALUES_4","numeric_value":[32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_5":{"name":"INITIAL_OUTPUT_VALUES_5","numeric_value":[-32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_6":{"name":"INITIAL_OUTPUT_VALUES_6","numeric_value":[32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_7":{"name":"INITIAL_OUTPUT_VALUES_7","numeric_value":[-32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_8":{"name":"INITIAL_OUTPUT_VALUES_8","numeric_value":[65793],"string_value":[""],"type":"numeric_parameter"},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","numeric_value":[9],"string_value":[""],"type":"numeric_parameter"},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","numeric_value":[1],"string_value":[""],"type":"numeric_parameter"},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","numeric_value":[9],"string_value":[""],"type":"numeric_parameter"},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","numeric_value":[32],"string_value":[""],"type":"numeric_parameter"},"TRIGGER_REGISTERS_IDX_0":{"name":"TRIGGER_REGISTERS_IDX_0","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{"axil":"axil","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset"}},{"children":[],"instance_name":"pid_int","instance_type":"Integrator","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","numeric_value":[16],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{"clock":"clock","error_in":"integrator_in","input_valid":"integrator_in_valid","limit_int_down":"limit_int_down","limit_int_up":"limit_int_up","out":"integral_out","reset":"reset"}}],"instance_name":"TL","instance_type":"PID","parameters":{"ADDITIONAL_BITS":{"name":"ADDITIONAL_BITS","numeric_value":[16],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_0":{"name":"INITIAL_OUTPUT_VALUES_0","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_1":{"name":"INITIAL_OUTPUT_VALUES_1","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_2":{"name":"INITIAL_OUTPUT_VALUES_2","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_3":{"name":"INITIAL_OUTPUT_VALUES_3","numeric_value":[0],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_4":{"name":"INITIAL_OUTPUT_VALUES_4","numeric_value":[32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_5":{"name":"INITIAL_OUTPUT_VALUES_5","numeric_value":[-32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_6":{"name":"INITIAL_OUTPUT_VALUES_6","numeric_value":[32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_7":{"name":"INITIAL_OUTPUT_VALUES_7","numeric_value":[-32767],"string_value":[""],"type":"numeric_parameter"},"INITIAL_OUTPUT_VALUES_8":{"name":"INITIAL_OUTPUT_VALUES_8","numeric_value":[65793],"string_value":[""],"type":"numeric_parameter"},"INPUT_DATA_WIDTH":{"name":"INPUT_DATA_WIDTH","numeric_value":[12],"string_value":[""],"type":"numeric_parameter"},"OUTPUT_DATA_WIDTH":{"name":"OUTPUT_DATA_WIDTH","numeric_value":[16],"string_value":[""],"type":"numeric_parameter"}},"ports_map":{}})");

    ASSERT_EQ(ast_dump, check_obj);
    ASSERT_TRUE(false); // FIXED_REGISTER_VALUES[0] in spi control unit is not correctly parsed as a mixed packed/unpacked parameter and the calculated value is wrong
}
