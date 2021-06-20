//
// Created by fils on 20/06/2021.
//


#include <gtest/gtest.h>

#include "../includes/data_model/Constraints.h"



TEST( Constraints_test , get_name) {
    Constraints cnstr("test");
    ASSERT_EQ(cnstr.get_name(), "test");
}

TEST( Constraints_test , path) {
    Constraints cnstr("test");
    cnstr.set_path("test_path");
    ASSERT_EQ(cnstr.get_path(), "test_path");
}

TEST( Constraints_test , serialization) {
    Constraints cnstr("test");
    cnstr.set_path("test_path");
    std::string result = cnstr;
    ASSERT_EQ(result, "test,test_path");
}

TEST( Constraints_test , deserialization) {
    Constraints cnstr("test,test_path", true);
    Constraints result("test");
    result.set_path("test_path");
    ASSERT_EQ(cnstr, result);
}