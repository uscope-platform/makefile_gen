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
    nlohmann::json check_obj = nlohmann::json::parse(R"({"children":[{"children":[],"instance_name":"ENG","instance_type":"enable_generator_core","parameters":{"CLOCK_MODE":{"name":"CLOCK_MODE","type":"expression_parameter"},"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","enable_out":"internal_start","gen_enable_in":"start_generator_enable","period":"start_generator_period","reset":"reset"}},{"children":[],"instance_name":"CKG","instance_type":"ClockGen","parameters":{"S0":{"name":"S0","type":"numeric_parameter","value":[0]},"S1":{"name":"S1","type":"numeric_parameter","value":[1]},"S2":{"name":"S2","type":"numeric_parameter","value":[2]}},"ports_map":{"clockIn":"clock","dividerSetting":"divider_setting","enable":"enable_clockgen","polarity":"clock_polarity","reset":"reset","sync":"sync","timebaseOut":"clock_cont"}},{"children":[],"instance_name":"SHR","instance_type":"SpiRegister","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"serial_lsb_out_first":{"name":"serial_lsb_out_first","type":"numeric_parameter","value":[1]},"serial_msb_out_first":{"name":"serial_msb_out_first","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","enable":"register_enable","latching_edge":"latching_edge","parallel_in":"parallel_reg_in[i]","parallel_out":"parallel_reg_out[i]","parallel_out_valid":"parallel_reg_valid[i]","register_direction":"spi_direction","register_load":"register_load","reset":"reset","serial_in":"MISO[i]","serial_out":"MOSI[i]","shift_clock":"generated_sclk","spi_transfer_length":"chosen_spi_transfer_length"}},{"children":[],"instance_name":"STE","instance_type":"TransferEngine","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","cu_data_in":"cu_in","cu_data_out":"cu_out","divider_setting":"divider_setting","enable_clockgen":"enable_clockgen","reg_data_in":"parallel_reg_in","reg_data_out":"parallel_reg_out","reg_data_out_valid":"parallel_reg_valid[0]","register_enable":"register_enable","register_load":"register_load","reset":"reset","spi_delay":"spi_delay","spi_start_transfer":"transfer_start","spi_transfer_length":"chosen_spi_transfer_length","ss_blanking":"ss_blanking","ss_deassert_delay_enable":"ss_deassert_delay_enable","sync":"sync","transfer_done":"transfer_done"}},{"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"axi_if","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[63]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[7]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[7]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]}},"ports_map":{"axil":"axi_in","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset","trigger_out":"trigger_transfer"}}],"instance_name":"SCU","instance_type":"SpiControlUnit","parameters":{"FIXED_REGISTER_VALUES":{"name":"FIXED_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0]]]},"INITIAL_REGISTER_VALUES":{"name":"INITIAL_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"N_REGISTERS":{"name":"N_REGISTERS","type":"numeric_parameter","value":[7]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]},"VARIABLE_INITIAL_VALUES":{"name":"VARIABLE_INITIAL_VALUES","type":"array_parameter","value":[[[0,0,0]]]}},"ports_map":{"axi_in":"axi_in","clock":"clock","clock_polarity":"clock_polarity","divider_setting":"divider_setting","external_spi_transfer":"external_spi_transfer","latching_edge":"latching_edge","period":"start_generator_period","reset":"reset","spi_data_in":"cu_in","spi_data_out":"cu_out","spi_delay":"spi_delay","spi_direction":"spi_direction","spi_mode":"spi_mode","spi_start_transfer":"int_transfer_start","spi_transfer_length":"bus_transfer_length","ss_deassert_delay_enable":"ss_deassert_delay_enable","ss_polarity":"ss_polarity","start_generator_enable":"start_generator_enable","transfer_done":"transfer_done","transfer_length_choice":"transfer_length_choice"}}],"instance_name":"TL","instance_type":"SPI","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]}},"ports_map":{}})");

    ASSERT_EQ(ast_dump, check_obj);
}


TEST( hdl_ast_builder, pwm_ast_build) {


    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    std::vector<std::string> paths = {
            "Components/Common",
            "Components/controls/PwmGenerator/rtl",
            "Components/system/axi_lite/crossbar/rtl/",
            "Components/system/axi_lite/simple_register_cu/rtl",
            "Components/system/axi_lite/skid_buffer/rtl"
    };

    auto prefix = "check_files/test_data/";
    for(auto &p:paths){
        for(auto &f:std::filesystem::directory_iterator(prefix + p)){
            if(f.path().extension() == ".v" || f.path().extension() == ".sv" || f.path().extension() == ".svh"){
                sv_analyzer analyzer(f.path());
                analyzer.cleanup_content("`(.*)");

                for(auto &entity:analyzer.analyze()){
                    d_store->store_hdl_entity(entity);
                }
            }
        }
    }


    HDL_ast_builder b(s_store, d_store);
    auto synth_ast = b.build_ast("PwmGenerator", {});


    auto ast_dump = synth_ast.dump();
    nlohmann::json check_obj = nlohmann::json::parse(R"({"children":[{"children":[],"instance_name":"ENG","instance_type":"enable_generator_core","parameters":{"CLOCK_MODE":{"name":"CLOCK_MODE","type":"expression_parameter"},"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","enable_out":"internal_start","gen_enable_in":"start_generator_enable","period":"start_generator_period","reset":"reset"}},{"children":[],"instance_name":"CKG","instance_type":"ClockGen","parameters":{"S0":{"name":"S0","type":"numeric_parameter","value":[0]},"S1":{"name":"S1","type":"numeric_parameter","value":[1]},"S2":{"name":"S2","type":"numeric_parameter","value":[2]}},"ports_map":{"clockIn":"clock","dividerSetting":"divider_setting","enable":"enable_clockgen","polarity":"clock_polarity","reset":"reset","sync":"sync","timebaseOut":"clock_cont"}},{"children":[],"instance_name":"SHR","instance_type":"SpiRegister","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"serial_lsb_out_first":{"name":"serial_lsb_out_first","type":"numeric_parameter","value":[1]},"serial_msb_out_first":{"name":"serial_msb_out_first","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","enable":"register_enable","latching_edge":"latching_edge","parallel_in":"parallel_reg_in[i]","parallel_out":"parallel_reg_out[i]","parallel_out_valid":"parallel_reg_valid[i]","register_direction":"spi_direction","register_load":"register_load","reset":"reset","serial_in":"MISO[i]","serial_out":"MOSI[i]","shift_clock":"generated_sclk","spi_transfer_length":"chosen_spi_transfer_length"}},{"children":[],"instance_name":"STE","instance_type":"TransferEngine","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","cu_data_in":"cu_in","cu_data_out":"cu_out","divider_setting":"divider_setting","enable_clockgen":"enable_clockgen","reg_data_in":"parallel_reg_in","reg_data_out":"parallel_reg_out","reg_data_out_valid":"parallel_reg_valid[0]","register_enable":"register_enable","register_load":"register_load","reset":"reset","spi_delay":"spi_delay","spi_start_transfer":"transfer_start","spi_transfer_length":"chosen_spi_transfer_length","ss_blanking":"ss_blanking","ss_deassert_delay_enable":"ss_deassert_delay_enable","sync":"sync","transfer_done":"transfer_done"}},{"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"axi_if","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[63]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[7]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[7]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]}},"ports_map":{"axil":"axi_in","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset","trigger_out":"trigger_transfer"}}],"instance_name":"SCU","instance_type":"SpiControlUnit","parameters":{"FIXED_REGISTER_VALUES":{"name":"FIXED_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0]]]},"INITIAL_REGISTER_VALUES":{"name":"INITIAL_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"N_REGISTERS":{"name":"N_REGISTERS","type":"numeric_parameter","value":[7]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]},"VARIABLE_INITIAL_VALUES":{"name":"VARIABLE_INITIAL_VALUES","type":"array_parameter","value":[[[0,0,0]]]}},"ports_map":{"axi_in":"axi_in","clock":"clock","clock_polarity":"clock_polarity","divider_setting":"divider_setting","external_spi_transfer":"external_spi_transfer","latching_edge":"latching_edge","period":"start_generator_period","reset":"reset","spi_data_in":"cu_in","spi_data_out":"cu_out","spi_delay":"spi_delay","spi_direction":"spi_direction","spi_mode":"spi_mode","spi_start_transfer":"int_transfer_start","spi_transfer_length":"bus_transfer_length","ss_deassert_delay_enable":"ss_deassert_delay_enable","ss_polarity":"ss_polarity","start_generator_enable":"start_generator_enable","transfer_done":"transfer_done","transfer_length_choice":"transfer_length_choice"}}],"instance_name":"TL","instance_type":"SPI","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]}},"ports_map":{}})");

    ASSERT_EQ(ast_dump, check_obj);
}
