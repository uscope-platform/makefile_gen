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

TEST( hdl_ast_builder, pwm_gen_build) {


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
    //auto synth_ast = b.build_ast("PID", {});


   // auto ast_dump = synth_ast.dump();
    nlohmann::json check_obj;

    check_obj["instance_name"] = "TL";
    check_obj["instance_type"] = "PID";
    check_obj["ports_map"] = {};
    check_obj["children"] = {};
    check_obj["parameters"] = {};

    //ASSERT_EQ(ast_dump, check_obj);
}
