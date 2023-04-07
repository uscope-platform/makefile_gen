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

#include "data_model/HDL/HDL_Resource.h"




TEST( HDL_resource_test , is_interface) {
    HDL_Resource resource;

    ASSERT_FALSE(resource.is_interface());
}


TEST( HDL_resource_test , ser_des_hdl_resource) {


    HDL_Resource hdl_out(module, "test", "/bin/sh");
    bus_submodule bsm;
    bsm.set_name("test");
    bsm.set_offset(21);
    hdl_out.set_submodules({bsm});

    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(hdl_out);
    }

    std::string json_str = os.str();
    std::stringstream is(json_str);
    HDL_Resource hdl_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(hdl_in);

    ASSERT_EQ(hdl_out, hdl_in);

    std::shared_ptr<HDL_Resource> hdl_out_ptr = std::make_shared<HDL_Resource>(hdl_out);

    std::stringstream os_ptr;
    {
        cereal::BinaryOutputArchive archive_out(os_ptr);
        archive_out(*hdl_out_ptr);
    }

    std::string json_str_ptr = os.str();
    std::stringstream is_ptr(json_str_ptr);

    cereal::BinaryInputArchive archive_in_ptr(is_ptr);

    HDL_Resource hdl_in_inner;
    archive_in_ptr(hdl_in_inner);

    std::shared_ptr<HDL_Resource> hdl_in_ptr = std::make_shared<HDL_Resource>(hdl_in_inner);

    ASSERT_EQ(*hdl_out_ptr, *hdl_in_ptr);


}

TEST( HDL_resource_test , get_path) {

    HDL_Resource res(module, "test_module","/test_path/test.sv");

    ASSERT_EQ(res.get_path(), "/test_path/test.sv");
}

TEST( HDL_resource_test , get_dependencies) {
    HDL_Resource test_item;
    HDL_dependency d("inst", "test_module_1", module);
    test_item.add_dependency(d);
    HDL_dependency d2("inst", "test_module_2", module);
    test_item.add_dependency(d2);

    std::vector<HDL_dependency> check = {d, d2};

    ASSERT_EQ(test_item.get_dependencies(), check);
}

TEST( HDL_resource_test , get_name) {

    HDL_Resource test_item(module, "test","/test/test.sv");

    ASSERT_EQ(test_item.getName(), "test");
}