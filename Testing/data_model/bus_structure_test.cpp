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

#include "third_party/cereal/archives/binary.hpp"
#include "third_party/cereal/types/polymorphic.hpp"

#include "data_model/documentation/bus_structure/bus_crossbar.hpp"
#include "data_model/documentation/bus_structure/bus_module.hpp"

TEST( bus_structure, module_serdes) {
    bus_module mod_out("module_instance", "module_type");
    mod_out.set_base_address(13);

    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(mod_out);
    }

    std::string json_str = os.str();

    std::stringstream is(json_str);

    bus_module mod_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(mod_in);

    ASSERT_EQ(mod_out, mod_in);
}

TEST( bus_structure , crossbar_serdes) {



    std::shared_ptr<bus_module> mod = std::make_shared<bus_module>("module_instance", "module_type");
    mod->set_base_address(13);

    std::vector<std::string> children = {"mod"};
    bus_crossbar xbar_out("crossbar_address_param");
    xbar_out.add_child(mod);
    xbar_out.set_base_address(14);

    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(xbar_out);
    }

    std::string json_str = os.str();

    std::stringstream is(json_str);

    bus_crossbar xbar_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(xbar_in);

    ASSERT_EQ(xbar_out, xbar_in);
}
