//
// Created by fils on 20/06/2021.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "data_model/Script.h"



TEST( Script_test , get_name) {
    Script cnstr("test","py");
    ASSERT_EQ(cnstr.get_name(), "test");
}

TEST( Script_test , path) {
    Script cnstr("test", "python");
    cnstr.set_path("test_path");
    ASSERT_EQ(cnstr.get_path(), "test_path");
}

TEST( Script_test , deserialization) {
    Script test_script("FPalu,/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl,0,");
    Script checker("FPalu", "tcl");
    checker.set_path("/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl");

    ASSERT_EQ(test_script, checker);
}

TEST( Script_test , serialization) {
    Script test_script("FPalu", "tcl");
    test_script.set_path("/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl");
    test_script.set_arguments({"test_arg_1","test_arg_2"});
    std::string result = test_script;
    ASSERT_EQ(result, "FPalu,/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl,0,test_arg_1,test_arg_2,");
}


TEST( Script_test , arguments) {
    Script test_script("FPalu,/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl,0,test_arg_1,test_arg_2,");
    std::vector<std::string> args = test_script.get_arguments();
    std::vector<std::string> results = {"test_arg_1", "test_arg_2"};

    ASSERT_THAT(args, testing::ContainerEq(results));
}


TEST( Script_test , get_type) {
    Script test_script("FPalu,/home/fils/git/uscope_hdl/Components/system/fcore/FPalu.tcl,0,test_arg_1,test_arg_2,");
    script_type_t type = test_script.get_type();

    ASSERT_EQ(type, tcl_script);
}


TEST( Script_test , uninit_script) {
    Script test_script("Test", "unknown");
    script_type_t type = test_script.get_type();

    ASSERT_EQ(type, uninit_script);
}


