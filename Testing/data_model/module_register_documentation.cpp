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

#include "data_model/documentation/module_documentation.h"
#include "data_model/documentation/register_documentation.h"
#include "data_model/documentation/field_documentation.h"

TEST( register_tests , serdes) {

    register_documentation doc_out("register_name", 0x14, "register description", true, true);
    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(doc_out);
    }

    std::string json_str = os.str();

    std::stringstream is(json_str);

    register_documentation doc_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(doc_in);
    ASSERT_EQ(doc_out, doc_in);
}

TEST( register_tests , comparison_succeed) {

    register_documentation doc_out("register_name", 0x14, "register description", true, true);

    ASSERT_EQ(doc_out, doc_out);
}


TEST( register_tests , comparison_fail) {

    register_documentation doc_1("register_name", 0x14, "register description", true, true);
    register_documentation doc_2("register_name", 0x14, "register fail", true, true);
    ASSERT_NE(doc_1, doc_2);
}


TEST( module_tests , serdes) {

    register_documentation reg_doc1("register_name", 0x14, "register description", true, true);
    field_documentation fd1("field_name", "field description", 28, 7);
    reg_doc1.add_field(fd1);
    register_documentation reg_doc2("register_name", 0x15, "register description", true, true);
    field_documentation fd2("field_name", "field description", 28, 7);
    reg_doc2.add_field(fd2);

    std::vector<std::string> children = {"reg", "mod"};
    bus_crossbar xbar_out("crossbar_address_param");

    module_documentation mod_doc_out;
    mod_doc_out.set_name("test_module");
    mod_doc_out.add_register(reg_doc1);
    mod_doc_out.add_register(reg_doc2);
    mod_doc_out.add_internal_bus(xbar_out);
    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(mod_doc_out);
    }

    std::string json_str = os.str();

    std::stringstream is(json_str);

    module_documentation mod_doc_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(mod_doc_in);
    ASSERT_EQ(mod_doc_out, mod_doc_in);
}

TEST( module_tests , comparison_succeed) {

    register_documentation reg_doc1("register_name", 0x14, "register description", true, true);
    field_documentation fd1("field_name", "field description", 28, 7);
    reg_doc1.add_field(fd1);
    register_documentation reg_doc2("register_name", 0x15, "register description", true, true);
    field_documentation fd2("field_name", "field description", 28, 7);
    reg_doc2.add_field(fd2);

    module_documentation mod_doc;
    mod_doc.set_name("test_module");
    mod_doc.add_register(reg_doc1);
    mod_doc.add_register(reg_doc2);

    std::vector<std::string> children = {"reg", "mod"};
    bus_crossbar xbar_out("crossbar_address_param");
    mod_doc.add_internal_bus(xbar_out);

    module_documentation mod_doc_2;
    mod_doc_2.set_name("test_module");
    mod_doc_2.add_register(reg_doc1);
    mod_doc_2.add_register(reg_doc2);

    std::vector<std::string> children2 = {"reg", "mod"};
    bus_crossbar xbar_out2("crossbar_address_param");
    mod_doc_2.add_internal_bus(xbar_out2);


    ASSERT_EQ(mod_doc, mod_doc_2);
}


TEST( module_tests , comparison_fail) {

    register_documentation reg_doc1("register_name", 0x14, "register description", true, true);
    field_documentation fd1("field_name", "field description", 28, 7);
    reg_doc1.add_field(fd1);
    register_documentation reg_doc2("register_name", 0x15, "register description", true, true);
    field_documentation fd2("field_name", "field description", 28, 7);
    reg_doc2.add_field(fd2);
    module_documentation mod_doc;
    mod_doc.set_name("test_module");
    mod_doc.add_register(reg_doc1);
    mod_doc.add_register(reg_doc2);

    std::vector<std::string> children = {"reg", "mod"};
    bus_crossbar xbar_out("crossbar_address_param");
    mod_doc.add_internal_bus(xbar_out);


    module_documentation mod_doc_2;
    mod_doc_2.set_name("test_module");
    mod_doc_2.add_register(reg_doc1);
    mod_doc_2.add_register(reg_doc1);
    mod_doc_2.add_internal_bus(xbar_out);

    ASSERT_NE(mod_doc, mod_doc_2);
}




TEST( field_tests , serdes) {

    field_documentation fd_out("field_name", "field description", 28, 7);

    std::stringstream os;
    {
        cereal::BinaryOutputArchive archive_out(os);
        archive_out(fd_out);
    }

    std::string json_str = os.str();

    std::stringstream is(json_str);

    field_documentation fd_in;
    cereal::BinaryInputArchive archive_in(is);
    archive_in(fd_in);
    ASSERT_EQ(fd_out, fd_in);
}

TEST( field_tests , comparison_succeed) {

    field_documentation fd_out1("field_name", "field description", 28, 7);
    field_documentation fd_out2("field_name", "field description", 28, 7);

    ASSERT_EQ(fd_out1, fd_out2);
}


TEST( field_tests , comparison_fail) {


    field_documentation fd_out1("field_name", "field description", 28, 7);
    field_documentation fd_out2("field_name", "field description", 24, 7);


    ASSERT_NE(fd_out1, fd_out2);
}