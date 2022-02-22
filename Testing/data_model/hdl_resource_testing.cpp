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


TEST( HDL_resource_test , serialization) {
    hdl_deps_t  dependencies;
    dependencies["axi_stream"] = module;
    dependencies["multiphase_reference_generator_CU"] = module;
    dependencies["enable_generator_counter"] = module;
    dependencies["multiphase_sinusoid_generator"] = module;
    HDL_Resource resource(module, "multiphase_reference_generator","/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv", dependencies,verilog_entity);

    std::unordered_map<std::string, uint32_t>  parameters = {{"parameter_1", 12}, {"parameter_2", 14}};
    resource.set_parameters(parameters);

    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(children,"crossbar_address_param");
    xbar->add_child(reg);
    xbar->add_child(mod);
    xbar->set_base_address(14);
    std::vector<std::shared_ptr<bus_crossbar>> crossb_vect({xbar, xbar});
    resource.add_bus_roots(crossb_vect);

    std::string result = resource;
    ASSERT_EQ(result,"multiphase_reference_generator,0,0,/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv,4,multiphase_sinusoid_generator,0,enable_generator_counter,0,multiphase_reference_generator_CU,0,axi_stream,0,2,parameter_2,14,parameter_1,12,14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2-14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2");
}


TEST( HDL_resource_test , deserialization) {
    HDL_Resource res("multiphase_reference_generator,0,0,/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv,4,multiphase_sinusoid_generator,0,enable_generator_counter,0,multiphase_reference_generator_CU,0,axi_stream,0,2,parameter_2,14,parameter_1,12,14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2-14,crossbar_address_param,0,1register_instance,register_address_param,12,1/2module_instance,module_type,module_address_param,13,2");
    hdl_deps_t  dependencies;
    dependencies["axi_stream"] = module;
    dependencies["multiphase_reference_generator_CU"] = module;
    dependencies["enable_generator_counter"] = module;
    dependencies["multiphase_sinusoid_generator"] = module;
    HDL_Resource checker(module, "multiphase_reference_generator","/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv", dependencies,verilog_entity);

    std::unordered_map<std::string, uint32_t>  parameters = {{"parameter_1", 12}, {"parameter_2", 14}};
    checker.set_parameters(parameters);

    std::shared_ptr<bus_registers> reg = std::make_shared<bus_registers>("register_instance", "register_address_param");
    reg->set_base_address(12);

    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type", "module_address_param");
    mod->set_base_address(13);

    std::vector<std::string> children = {"reg", "mod"};
    std::shared_ptr<bus_crossbar> xbar = std::make_shared<bus_crossbar>(children,"crossbar_address_param");
    xbar->add_child(reg);
    xbar->add_child(mod);
    xbar->set_base_address(14);
    std::vector<std::shared_ptr<bus_crossbar>> bus_vect({xbar, xbar});
    checker.add_bus_roots(bus_vect);

    ASSERT_EQ(res, checker);
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