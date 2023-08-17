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
    nlohmann::json check_obj = nlohmann::json::parse(R"({"children":[{"children":[],"instance_name":"ENG","instance_type":"enable_generator_core","parameters":{"CLOCK_MODE":{"name":"CLOCK_MODE","type":"string_parameter","value":["FALSE"]},"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","enable_out":"internal_start","gen_enable_in":"start_generator_enable","period":"start_generator_period","reset":"reset"}},{"children":[],"instance_name":"CKG","instance_type":"ClockGen","parameters":{"S0":{"name":"S0","type":"numeric_parameter","value":[0]},"S1":{"name":"S1","type":"numeric_parameter","value":[1]},"S2":{"name":"S2","type":"numeric_parameter","value":[2]}},"ports_map":{"clockIn":"clock","dividerSetting":"divider_setting","enable":"enable_clockgen","polarity":"clock_polarity","reset":"reset","sync":"sync","timebaseOut":"clock_cont"}},{"children":[],"instance_name":"SHR","instance_type":"SpiRegister","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"serial_lsb_out_first":{"name":"serial_lsb_out_first","type":"numeric_parameter","value":[1]},"serial_msb_out_first":{"name":"serial_msb_out_first","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","enable":"register_enable","latching_edge":"latching_edge","parallel_in":"parallel_reg_in[i]","parallel_out":"parallel_reg_out[i]","parallel_out_valid":"parallel_reg_valid[i]","register_direction":"spi_direction","register_load":"register_load","reset":"reset","serial_in":"MISO[i]","serial_out":"MOSI[i]","shift_clock":"generated_sclk","spi_transfer_length":"chosen_spi_transfer_length"}},{"children":[],"instance_name":"STE","instance_type":"TransferEngine","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]}},"ports_map":{"clock":"clock","cu_data_in":"cu_in","cu_data_out":"cu_out","divider_setting":"divider_setting","enable_clockgen":"enable_clockgen","reg_data_in":"parallel_reg_in","reg_data_out":"parallel_reg_out","reg_data_out_valid":"parallel_reg_valid[0]","register_enable":"register_enable","register_load":"register_load","reset":"reset","spi_delay":"spi_delay","spi_start_transfer":"transfer_start","spi_transfer_length":"chosen_spi_transfer_length","ss_blanking":"ss_blanking","ss_deassert_delay_enable":"ss_deassert_delay_enable","sync":"sync","transfer_done":"transfer_done"}},{"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"axi_if","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[63]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[7]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[7]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]}},"ports_map":{"axil":"axi_in","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset","trigger_out":"trigger_transfer"}}],"instance_name":"SCU","instance_type":"SpiControlUnit","parameters":{"FIXED_REGISTER_VALUES":{"name":"FIXED_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0]]]},"INITIAL_REGISTER_VALUES":{"name":"INITIAL_REGISTER_VALUES","type":"array_parameter","value":[[[224,1,0,0,0,0,0]]]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"N_REGISTERS":{"name":"N_REGISTERS","type":"numeric_parameter","value":[7]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[3]]]},"VARIABLE_INITIAL_VALUES":{"name":"VARIABLE_INITIAL_VALUES","type":"array_parameter","value":[[[0,0,0]]]}},"ports_map":{"axi_in":"axi_in","clock":"clock","clock_polarity":"clock_polarity","divider_setting":"divider_setting","external_spi_transfer":"external_spi_transfer","latching_edge":"latching_edge","period":"start_generator_period","reset":"reset","spi_data_in":"cu_in","spi_data_out":"cu_out","spi_delay":"spi_delay","spi_direction":"spi_direction","spi_mode":"spi_mode","spi_start_transfer":"int_transfer_start","spi_transfer_length":"bus_transfer_length","ss_deassert_delay_enable":"ss_deassert_delay_enable","ss_polarity":"ss_polarity","start_generator_enable":"start_generator_enable","transfer_done":"transfer_done","transfer_length_choice":"transfer_length_choice"}}],"instance_name":"TL","instance_type":"SPI","parameters":{"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[3]},"OUTPUT_WIDTH":{"name":"OUTPUT_WIDTH","type":"numeric_parameter","value":[32]},"SS_POLARITY_DEFAULT":{"name":"SS_POLARITY_DEFAULT","type":"numeric_parameter","value":[0]}},"ports_map":{}})");

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

    std::string res_str = R"lit({"children":[{"children":[],"instance_name":"internal_bus","instance_type":"axi_lite","parameters":{},"ports_map":{}},{"children":[{"children":[{"children":[],"instance_name":"awskid","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{S_AXI_AWADDR[N*ADDR_WIDTH+:ADDR_WIDTH],S_AXI_AWPROT[N*3+:3]}","in_ready":"S_AXI_AWREADY[N]","in_valid":"S_AXI_AWVALID[N]","out_data":"{skd_awaddr[N],skd_awprot[N]}","out_ready":"!skd_awstall[N]","out_valid":"skd_awvalid[N]","reset":"reset"}},{"children":[],"instance_name":"wraddr","instance_type":"address_decoder","parameters":{"ACCESS_ALLOWED":{"name":"ACCESS_ALLOWED","type":"numeric_parameter","value":[-1]},"AW":{"name":"AW","type":"numeric_parameter","value":[32]},"DW":{"name":"DW","type":"numeric_parameter","value":[3]},"NS":{"name":"NS","type":"numeric_parameter","value":[3]},"OPT_LOWPOWER":{"name":"OPT_LOWPOWER","type":"numeric_parameter","value":[0]},"OPT_NONESEL":{"name":"OPT_NONESEL","type":"numeric_parameter","value":[0]},"OPT_REGISTERED":{"name":"OPT_REGISTERED","type":"numeric_parameter","value":[1]},"SLAVE_ADDR":{"name":"SLAVE_ADDR","type":"array_parameter","value":[]},"SLAVE_MASK":{"name":"SLAVE_MASK","type":"array_parameter","value":[[[3840,3840,3840]]]}},"ports_map":{"clock":"clock","i_addr":"skd_awaddr[N]","i_data":"skd_awprot[N]","i_stall":"!dcd_awvalid[N]||!slave_awaccepts[N]","i_valid":"skd_awvalid[N]","o_addr":"m_awaddr[N]","o_data":"m_awprot[N]","o_decode":"wdecode","o_stall":"skd_awstall[N]","o_valid":"dcd_awvalid[N]","reset":"!reset"}},{"children":[],"instance_name":"wskid","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{S_AXI_WDATA[N*DATA_WIDTH+:DATA_WIDTH],S_AXI_WSTRB[N*DATA_WIDTH/8+:DATA_WIDTH/8]}","in_ready":"S_AXI_WREADY[N]","in_valid":"S_AXI_WVALID[N]","out_data":"{m_wdata[N],m_wstrb[N]}","out_ready":"(m_wvalid[N]&&slave_waccepts[N])","out_valid":"skd_wvalid[N]","reset":"reset"}},{"children":[],"instance_name":"awskid","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{S_AXI_ARADDR[N*ADDR_WIDTH+:ADDR_WIDTH],S_AXI_ARPROT[N*3+:3]}","in_ready":"S_AXI_ARREADY[N]","in_valid":"S_AXI_ARVALID[N]","out_data":"{skd_araddr[N],skd_arprot[N]}","out_ready":"!skd_arstall[N]","out_valid":"skd_arvalid[N]","reset":"reset"}},{"children":[],"instance_name":"rdaddr","instance_type":"address_decoder","parameters":{"ACCESS_ALLOWED":{"name":"ACCESS_ALLOWED","type":"numeric_parameter","value":[-1]},"AW":{"name":"AW","type":"numeric_parameter","value":[32]},"DW":{"name":"DW","type":"numeric_parameter","value":[3]},"NS":{"name":"NS","type":"numeric_parameter","value":[3]},"OPT_LOWPOWER":{"name":"OPT_LOWPOWER","type":"numeric_parameter","value":[0]},"OPT_NONESEL":{"name":"OPT_NONESEL","type":"numeric_parameter","value":[0]},"OPT_REGISTERED":{"name":"OPT_REGISTERED","type":"numeric_parameter","value":[1]},"SLAVE_ADDR":{"name":"SLAVE_ADDR","type":"array_parameter","value":[]},"SLAVE_MASK":{"name":"SLAVE_MASK","type":"array_parameter","value":[[[3840,3840,3840]]]}},"ports_map":{"clock":"clock","i_addr":"skd_araddr[N]","i_data":"skd_arprot[N]","i_stall":"!m_arvalid[N]||!slave_raccepts[N]","i_valid":"skd_arvalid[N]","o_addr":"m_araddr[N]","o_data":"m_arprot[N]","o_decode":"rdecode","o_stall":"skd_arstall[N]","o_valid":"dcd_arvalid[N]","reset":"!reset"}}],"instance_name":"inner_crossbar","instance_type":"axilxbar","parameters":{"ADDR_WIDTH":{"name":"ADDR_WIDTH","type":"numeric_parameter","value":[32]},"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"INTERCONNECT_ERROR":{"name":"INTERCONNECT_ERROR","type":"numeric_parameter","value":[3]},"LGLINGER":{"name":"LGLINGER","type":"numeric_parameter","value":[0]},"LGMAXBURST":{"name":"LGMAXBURST","type":"numeric_parameter","value":[5]},"LGNM":{"name":"LGNM","type":"numeric_parameter","value":[0]},"LGNS":{"name":"LGNS","type":"numeric_parameter","value":[0]},"NM":{"name":"NM","type":"numeric_parameter","value":[1]},"NMFULL":{"name":"NMFULL","type":"numeric_parameter","value":[1]},"NS":{"name":"NS","type":"numeric_parameter","value":[3]},"NSFULL":{"name":"NSFULL","type":"numeric_parameter","value":[2]},"OPT_BUFFER_DECODER":{"name":"OPT_BUFFER_DECODER","type":"numeric_parameter","value":[1]},"OPT_LINGER":{"name":"OPT_LINGER","type":"numeric_parameter","value":[4]},"OPT_LOWPOWER":{"name":"OPT_LOWPOWER","type":"numeric_parameter","value":[1]},"OPT_SKID_INPUT":{"name":"OPT_SKID_INPUT","type":"numeric_parameter","value":[0]},"SLAVE_ADDR":{"name":"SLAVE_ADDR","type":"array_parameter","value":[]},"SLAVE_MASK":{"name":"SLAVE_MASK","type":"array_parameter","value":[[[3840,3840,3840]]]}},"ports_map":{"M_AXI_ARADDR":"M_AXI_ARADDR","M_AXI_ARPROT":"M_AXI_ARPROT","M_AXI_ARREADY":"M_AXI_ARREADY","M_AXI_ARVALID":"M_AXI_ARVALID","M_AXI_AWADDR":"M_AXI_AWADDR","M_AXI_AWPROT":"M_AXI_AWPROT","M_AXI_AWREADY":"M_AXI_AWREADY","M_AXI_AWVALID":"M_AXI_AWVALID","M_AXI_BREADY":"M_AXI_BREADY","M_AXI_BRESP":"M_AXI_BRESP","M_AXI_BVALID":"M_AXI_BVALID","M_AXI_RDATA":"M_AXI_RDATA","M_AXI_RREADY":"M_AXI_RREADY","M_AXI_RRESP":"M_AXI_RRESP","M_AXI_RVALID":"M_AXI_RVALID","M_AXI_WDATA":"M_AXI_WDATA","M_AXI_WREADY":"M_AXI_WREADY","M_AXI_WSTRB":"M_AXI_WSTRB","M_AXI_WVALID":"M_AXI_WVALID","S_AXI_ARADDR":"S_AXI_ARADDR","S_AXI_ARPROT":"S_AXI_ARPROT","S_AXI_ARREADY":"S_AXI_ARREADY","S_AXI_ARVALID":"S_AXI_ARVALID","S_AXI_AWADDR":"S_AXI_AWADDR","S_AXI_AWPROT":"S_AXI_AWPROT","S_AXI_AWREADY":"S_AXI_AWREADY","S_AXI_AWVALID":"S_AXI_AWVALID","S_AXI_BREADY":"S_AXI_BREADY","S_AXI_BRESP":"S_AXI_BRESP","S_AXI_BVALID":"S_AXI_BVALID","S_AXI_RDATA":"S_AXI_RDATA","S_AXI_RREADY":"S_AXI_RREADY","S_AXI_RRESP":"S_AXI_RRESP","S_AXI_RVALID":"S_AXI_RVALID","S_AXI_WDATA":"S_AXI_WDATA","S_AXI_WREADY":"S_AXI_WREADY","S_AXI_WSTRB":"S_AXI_WSTRB","S_AXI_WVALID":"S_AXI_WVALID","clock":"clock","reset":"reset"}}],"instance_name":"axi_xbar","instance_type":"axil_crossbar_interface","parameters":{"ADDR_WIDTH":{"name":"ADDR_WIDTH","type":"numeric_parameter","value":[32]},"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"LGMAXBURST":{"name":"LGMAXBURST","type":"numeric_parameter","value":[5]},"NM":{"name":"NM","type":"numeric_parameter","value":[1]},"NS":{"name":"NS","type":"numeric_parameter","value":[3]},"OPT_LINGER":{"name":"OPT_LINGER","type":"numeric_parameter","value":[4]},"OPT_LOWPOWER":{"name":"OPT_LOWPOWER","type":"numeric_parameter","value":[1]},"SLAVE_ADDR":{"name":"SLAVE_ADDR","type":"array_parameter","value":[]},"SLAVE_MASK":{"name":"SLAVE_MASK","type":"array_parameter","value":[[[3840,3840,3840]]]},"STROBE_WIDTH":{"name":"STROBE_WIDTH","type":"numeric_parameter","value":[4]}},"ports_map":{"clock":"clock","masters":"internal_bus","reset":"reset","slaves":"'{axi_in}"}},{"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"CU","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[15]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[0]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[1]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[1]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[0]]]}},"ports_map":{"axil":"axi_in","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset"}}],"instance_name":"pwm_cu","instance_type":"PwmControlUnit","parameters":{"INITIAL_STOPPED_STATE":{"name":"INITIAL_STOPPED_STATE","type":"numeric_parameter","value":[0]},"N_PWM":{"name":"N_PWM","type":"numeric_parameter","value":[16]}},"ports_map":{"axi_in":"internal_bus[N_CHAINS]","clock":"clock","counter_run":"counter_run","counter_status":"counter_status","counter_stopped_state":"counter_stopped_state","reset":"reset","sync":"sync","timebase_enable":"timebase_enable","timebase_external_enable":"ext_timebase_enable","timebase_setting":"dividerSetting"}},{"children":[],"instance_name":"timebase_generator","instance_type":"TimebaseGenerator","parameters":{},"ports_map":{"clock":"clock","counter_status":"counter_run","dividerSetting":"dividerSetting","enable":"timebase_enable","fast_count":"fast_count","reset":"reset","timebaseOut":"internal_timebase"}},{"children":[{"children":[{"children":[{"children":[],"instance_name":"address_read_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.ARADDR","in_ready":"axil.ARREADY","in_valid":"axil.ARVALID","out_data":"read_address","out_ready":"read_ready","out_valid":"read_address_valid","reset":"reset"}},{"children":[],"instance_name":"address_write_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[32]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"axil.AWADDR","in_ready":"axil.AWREADY","in_valid":"axil.AWVALID","out_data":"write_address","out_ready":"write_ready","out_valid":"write_address_valid","reset":"reset"}},{"children":[],"instance_name":"write_data_buffer","instance_type":"axil_skid_buffer","parameters":{"DATA_WIDTH":{"name":"DATA_WIDTH","type":"numeric_parameter","value":[36]},"REGISTER_OUTPUT":{"name":"REGISTER_OUTPUT","type":"numeric_parameter","value":[0]}},"ports_map":{"clock":"clock","in_data":"{axil.WDATA,axil.WSTRB}","in_ready":"axil.WREADY","in_valid":"axil.WVALID","out_data":"{write_data,write_strobe}","out_ready":"write_ready","out_valid":"write_data_valid","reset":"reset"}}],"instance_name":"CU","instance_type":"axil_simple_register_cu","parameters":{"ADDRESS_MASK":{"name":"ADDRESS_MASK","type":"numeric_parameter","value":[255]},"INITIAL_OUTPUT_VALUES":{"name":"INITIAL_OUTPUT_VALUES","type":"array_parameter","value":[[[0,0,0,0,4294967295,4294967295,4294967295,4294967295,80,80,80,80,0,0,0,0,0,0]]]},"N_READ_REGISTERS":{"name":"N_READ_REGISTERS","type":"numeric_parameter","value":[18]},"N_TRIGGER_REGISTERS":{"name":"N_TRIGGER_REGISTERS","type":"numeric_parameter","value":[1]},"N_WRITE_REGISTERS":{"name":"N_WRITE_REGISTERS","type":"numeric_parameter","value":[18]},"REGISTERED_BUFFERS":{"name":"REGISTERED_BUFFERS","type":"numeric_parameter","value":[0]},"REGISTERS_WIDTH":{"name":"REGISTERS_WIDTH","type":"numeric_parameter","value":[32]},"TRIGGER_REGISTERS_IDX":{"name":"TRIGGER_REGISTERS_IDX","type":"array_parameter","value":[[[0]]]}},"ports_map":{"axil":"axi_in","clock":"clock","input_registers":"cu_read_registers","output_registers":"cu_write_registers","reset":"reset"}}],"instance_name":"ControlUnit","instance_type":"ChainControlUnit","parameters":{"BASE_ADDRESS":{"name":"BASE_ADDRESS","type":"numeric_parameter","value":[0]},"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]},"DT_IV":{"name":"DT_IV","type":"array_parameter","value":[[[80,80,80,80]]]},"INITIAL_REGISTER_VALUES":{"name":"INITIAL_REGISTER_VALUES","type":"array_parameter","value":[[[0,0,0,0,4294967295,4294967295,4294967295,4294967295,80,80,80,80,0,0,0,0,0,0]]]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[4]},"OTHER_IV":{"name":"OTHER_IV","type":"array_parameter","value":[[[0,0,0,0,0,0]]]},"THRESH_HIGH_IV":{"name":"THRESH_HIGH_IV","type":"array_parameter","value":[[[4294967295,4294967295,4294967295,4294967295]]]},"THRESH_LOW_IV":{"name":"THRESH_LOW_IV","type":"array_parameter","value":[[[0,0,0,0]]]}},"ports_map":{"axi_in":"axi_in","clock":"clock","comparator_tresholds":"compare_tresholds","counter_mode":"counter_mode","counter_running":"~counter_stopped","counter_start_data":"counter_start_data","counter_stop_data":"counter_stop_data","deadtime":"deadtime","deadtime_enable":"deadtime_enable","output_enable":"output_enable","reset":"reset","timebase_shift":"timebase_shift"}},{"children":[{"children":[],"instance_name":"core","instance_type":"counter_core","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]}},"ports_map":{"clock":"clock","count_out":"counter","direction":"direction","enable":"counter_enable","fast_count":"fast_count","inhibit_load":"~mode[1]","reload_value":"cnt_stopValue","reset":"reset&~sync","shift":"shift","timebase":"timebase"}}],"instance_name":"counter","instance_type":"Counter","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]}},"ports_map":{"clock":"clock","countOut":"counter_out","counter_start_data":"counter_start_data","counter_stop_data":"counter_stop_data","fast_count":"fast_count","mode":"counter_mode","reload_compare":"reload_compare","reset":"reset","run":"external_counter_run&~stop_request","shift":"timebase_shift","sync":"sync","timebase":"timebase"}},{"children":[],"instance_name":"compare","instance_type":"CompareUnit","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[4]}},"ports_map":{"clock":"clock","comparator_tresholds":"compare_tresholds","counterValue":"counter_out","counter_stopped":"counter_stopped","matchHigh":"compare_match_high","matchLow":"compare_match_low","reload_compare":"reload_compare","reset":"reset"}},{"children":[],"instance_name":"pinControl","instance_type":"PinControl","parameters":{},"ports_map":{"clock":"clock","counter_stopped":"counter_stopped","enableOutputs":"output_enable[i]","matchHigh":"compare_match_high[i]","matchLow":"compare_match_low[i]","outA":"pin_out_a[i]","outB":"pin_out_b[i]","reset":"reset"}},{"children":[{"children":[],"instance_name":"deadTime_a","instance_type":"timebase_shifter_core","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]}},"ports_map":{"clockIn":"clock","count_in":"deadTime-1","count_out":"counter","enable":"counter_enable","load":"load_counter","reset":"reset"}}],"instance_name":"deadtime","instance_type":"DeadTimeGenerator","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]},"FIRST_DEADTIME_STATE":{"name":"FIRST_DEADTIME_STATE","type":"numeric_parameter","value":[1]},"FIRST_OUT":{"name":"FIRST_OUT","type":"numeric_parameter","value":[2]},"IDLE_STATE":{"name":"IDLE_STATE","type":"numeric_parameter","value":[0]},"SECOND_DEADTIME_STATE":{"name":"SECOND_DEADTIME_STATE","type":"numeric_parameter","value":[3]}},"ports_map":{"clock":"clock","deadTime":"deadtime[i]","enable":"deadtime_enable[i]","in_a":"pin_out_a[i]","in_b":"pin_out_b[i]","out_a":"dt_out_a[i]","out_b":"dt_out_b[i]","reset":"reset"}},{"children":[],"instance_name":"res_enhancer_a","instance_type":"ResolutionEnhancer","parameters":{"ENABLE":{"name":"ENABLE","type":"string_parameter","value":["FALSE"]},"ENANCING_MODE":{"name":"ENANCING_MODE","type":"string_parameter","value":["DUTY"]}},"ports_map":{"clock":"clock","count":"timebase_shift[2:0]","high_resolution_clock":"high_resolution_clock","in":"dt_out_a[i]","out":"out_a[i]","reset":"reset"}},{"children":[],"instance_name":"res_enhancer_b","instance_type":"ResolutionEnhancer","parameters":{"ENABLE":{"name":"ENABLE","type":"string_parameter","value":["FALSE"]},"ENANCING_MODE":{"name":"ENANCING_MODE","type":"string_parameter","value":["DUTY"]}},"ports_map":{"clock":"clock","count":"timebase_shift[2:0]","high_resolution_clock":"high_resolution_clock","in":"dt_out_b[i]","out":"out_b[i]","reset":"reset"}}],"instance_name":"chain","instance_type":"pwmChain","parameters":{"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]},"ENANCING_MODE":{"name":"ENANCING_MODE","type":"string_parameter","value":["DUTY"]},"HR_ENABLE":{"name":"HR_ENABLE","type":"string_parameter","value":["FALSE"]},"N_CHAINS":{"name":"N_CHAINS","type":"numeric_parameter","value":[2]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[4]}},"ports_map":{"axi_in":"internal_bus[i]","clock":"clock","counter_status":"counter_status[i]","external_counter_run":"counter_run","fast_count":"fast_count","high_resolution_clock":"high_resolution_clock","out_a":"partial_pwm_out_a[i]","out_b":"partial_pwm_out_b[i]","reset":"reset","stop_request":"stop_chain[i]","sync":"sync","timebase":"selected_timebase"}}],"instance_name":"TL","instance_type":"PwmGenerator","parameters":{"AXI_ADDRESSES":{"name":"AXI_ADDRESSES","type":"string_parameter","value":["ADDR_CALC"]},"BASE_ADDRESS":{"name":"BASE_ADDRESS","type":"numeric_parameter","value":[1136656384]},"COUNTER_WIDTH":{"name":"COUNTER_WIDTH","type":"numeric_parameter","value":[16]},"ENANCING_MODE":{"name":"ENANCING_MODE","type":"string_parameter","value":["DUTY"]},"HR_ENABLE":{"name":"HR_ENABLE","type":"string_parameter","value":["FALSE"]},"INITIAL_STOPPED_STATE":{"name":"INITIAL_STOPPED_STATE","type":"numeric_parameter","value":[0]},"N_CHAINS":{"name":"N_CHAINS","type":"numeric_parameter","value":[2]},"N_CHANNELS":{"name":"N_CHANNELS","type":"numeric_parameter","value":[4]},"N_PWM":{"name":"N_PWM","type":"numeric_parameter","value":[16]},"PRAGMA_MKFG_BUS_ARRAY":{"name":"PRAGMA_MKFG_BUS_ARRAY","type":"string_parameter","value":["internal_bus"]},"PRAGMA_MKFG_BUS_LAYOUT":{"name":"PRAGMA_MKFG_BUS_LAYOUT","type":"string_parameter","value":["[{\\name\\: \\axi_xbar\\,\\base\\: \\BASE_ADDRESS\\,\\offset\\: \\0x100\\,\\map\\: [{\\len\\:\\N_CHAINS\\, \\mod\\:\\pwmChain\\},{\\len\\:\\1\\, \\mod\\:\\PwmControlUnit\\}]}]"]},"PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT":{"name":"PRAGMA_MKFG_PARAMETRIZED_INTERCONNECT","type":"string_parameter","value":["axi_xbar"]}},"ports_map":{}})lit";
    nlohmann::json check_obj = nlohmann::json::parse(res_str);

    ASSERT_EQ(ast_dump, check_obj);
}


TEST( hdl_ast_builder, adc_ast_build) {


    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(true, "/tmp/test_data_store");
    std::shared_ptr<settings_store> s_store = std::make_shared<settings_store>(true, "/tmp/test_data_store");

    std::vector<std::string> paths = {
            "Components/Common",
            "Components/signal_chain/AdcProcessing/rtl",
            "Components/signal_chain/decimator/standard_decimator",
            "Components/signal_chain/fir_filter/rtl",
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
    auto synth_ast = b.build_ast("AdcProcessing", {});


    auto ast_dump = synth_ast.dump();

    std::string res_str = R"lit({})lit";
    nlohmann::json check_obj = nlohmann::json::parse(res_str);

    ASSERT_EQ(ast_dump, check_obj);
}