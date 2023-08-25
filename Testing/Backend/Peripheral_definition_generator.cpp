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

#include "data_model/Depfile.hpp"
#include "data_model/data_store.hpp"
#include "data_model/settings_store.hpp"
#include "frontend/analysis/sv_analyzer.hpp"
#include "analysis/HDL_ast_builder.hpp"
#include "analysis/bus_analysis.hpp"
#include "Backend/uplatform/peripheral_definition_generator.hpp"

TEST( periph_def_generation , generate_periph_def) {

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


    nlohmann::json df_content;
    df_content["bus"] = nlohmann::json();
    df_content["bus"]["control"] = nlohmann::json();
    df_content["bus"]["control"]["bus_interface"] = "axil";
    df_content["bus"]["control"]["starting_module"] = "PID";
    df_content["bus"]["control"]["type"] = "axi_lite";

    Depfile df;
    df.set_content(df_content);

    HDL_ast_builder b(s_store, d_store, df);
    auto synth_ast = b.build_ast("PID", {});


    bus_analysis bus_analyzer(s_store, d_store, df);
    bus_analyzer.analyze_bus(synth_ast);


    peripheral_definition_generator periph_def_gen(d_store, synth_ast);

    auto res = periph_def_gen.get_definition_string();
    std::string check_string = "{\"PID\":{\"parametric\":false,\"peripheral_name\":\"PID\",\"registers\":[{\"ID\":\"control\",\"description\":\"Control register\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x0\",\"register_name\":\"control\"},{\"ID\":\"kp\",\"description\":\"Proportional action gain\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x4\",\"register_name\":\"kp\"},{\"ID\":\"ki\",\"description\":\"Integral action gain\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x8\",\"register_name\":\"ki\"},{\"ID\":\"kd\",\"description\":\"Derivative action gain\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0xc\",\"register_name\":\"kd\"},{\"ID\":\"limit_out_p\",\"description\":\"Upper output saturation limit\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x10\",\"register_name\":\"limit_out_p\"},{\"ID\":\"limit_out_n\",\"description\":\"Lower output saturation limit\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x14\",\"register_name\":\"limit_out_n\"},{\"ID\":\"limit_int_p\",\"description\":\"Upper integrator saturation limit\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x18\",\"register_name\":\"limit_int_p\"},{\"ID\":\"limit_int_n\",\"description\":\"Lower integrator saturation limit\",\"direction\":\"RW\",\"fields\":[],\"offset\":\"0x1c\",\"register_name\":\"limit_int_n\"},{\"ID\":\"gain_scaling\",\"description\":\"Gain scaling factor\",\"direction\":\"RW\",\"fields\":[{\"description\":\"Proportional action scaling factor\",\"length\":8,\"name\":\"kp_den\",\"offset\":0},{\"description\":\"Integral action scaling factor\",\"length\":8,\"name\":\"ki_den\",\"offset\":8},{\"description\":\"derivative action scaling factor\",\"length\":8,\"name\":\"kd_den\",\"offset\":16}],\"offset\":\"0x20\",\"register_name\":\"gain_scaling\"}],\"version\":\"1.0\"}}";
    ASSERT_EQ(res, check_string);
}
