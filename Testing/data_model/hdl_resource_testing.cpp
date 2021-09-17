// Copyright 2021 University of Nottingham Ningbo China
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

#include "data_model/HDL_Resource.h"


TEST( HDL_resource_test , deserialization) {
    HDL_Resource res("multiphase_reference_generator,0,0,/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv,axi_stream,0,multiphase_reference_generator_CU,0,enable_generator_counter,0,multiphase_sinusoid_generator,0");
    hdl_deps_t  dependencies;
    dependencies["axi_stream"] = module;
    dependencies["multiphase_reference_generator_CU"] = module;
    dependencies["enable_generator_counter"] = module;
    dependencies["multiphase_sinusoid_generator"] = module;
    HDL_Resource checker(module, "multiphase_reference_generator","/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv", dependencies,verilog_entity);


    ASSERT_EQ(res, checker);
}

TEST( HDL_resource_test , serialization) {
    hdl_deps_t  dependencies;
    dependencies["axi_stream"] = module;
    HDL_Resource resource(module, "multiphase_reference_generator","/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv", dependencies,verilog_entity);

    std::string result = resource;
    ASSERT_EQ(result,"multiphase_reference_generator,0,0,/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv,axi_stream,0");
}


TEST( HDL_resource_test , is_interface) {
    HDL_Resource resource;

    ASSERT_FALSE(resource.is_interface());
}

TEST( HDL_resource_test , get_path) {
    hdl_deps_t  dependencies;
    HDL_Resource res(module, "test_module","/test_path/test.sv", dependencies,verilog_entity);

    ASSERT_EQ(res.get_path(), "/test_path/test.sv");
}

TEST( HDL_resource_test , get_dependencies) {
    hdl_deps_t  dependencies;
    dependencies["test_module_1"] = module;
    dependencies["test_module_2"] = module;
    HDL_Resource test_item(module, "test","/test/test.sv", dependencies,verilog_entity);

    ASSERT_EQ(test_item.get_dependencies(), dependencies);
}

TEST( HDL_resource_test , get_name) {
    hdl_deps_t  dependencies;

    HDL_Resource test_item(module, "test","/test/test.sv", dependencies,verilog_entity);

    ASSERT_EQ(test_item.getName(), "test");
}