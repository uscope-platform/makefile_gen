//
// Created by fils on 20/06/2021.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../includes/data_model/Constraints.h"
#include "../includes/data_model/Script.h"
#include "../includes/data_model/Depfile.h"


class DepfileTest : public ::testing::Test {
protected:
    void SetUp(const std::string &filename) {
        file = new Depfile(filename);
    }

    virtual void TearDown() {
        delete file;
    }

    Depfile *file;
};

TEST_F( DepfileTest , Depfile_project_name) {
    SetUp("Depfile");

    ASSERT_EQ(file->get_project_name(), "test_project_name");

}

TEST_F( DepfileTest , Depfile_additional_synth_modules) {
    SetUp("Depfile");

    ASSERT_THAT(file->get_additional_synth_modules(), testing::ElementsAre("test_synth_module_add_1", "test_synth_module_add_2"));

}

TEST_F( DepfileTest , Depfile_additional_sim_modules) {
    SetUp("Depfile");

    ASSERT_THAT(file->get_additional_sim_modules(), testing::ElementsAre("test_sim_module_add_1", "test_sim_module_add_2"));

}


TEST_F( DepfileTest , Depfile_synth_top) {
    SetUp("Depfile");

    ASSERT_EQ(file->get_synth_tl(), "test_synth_tl");

}

TEST_F( DepfileTest , Depfile_sim_top) {
    SetUp("Depfile");
    ASSERT_EQ(file->get_sim_tl(), "test_sim_tl");

}



TEST_F( DepfileTest , Depfile_excluded_modules) {
    SetUp("Depfile");

    ASSERT_THAT(file->get_excluded_modules(),
                testing::ElementsAre( "test_excluded_module_1", "test_excluded_module_2"));

}

TEST_F( DepfileTest , Depfile_include_paths) {
    SetUp("Depfile");

    ASSERT_THAT(file->get_include_directories(),
                testing::ElementsAre("test_include_1","test_include_2"));

}

TEST_F( DepfileTest , Depfile_constraints) {
    SetUp("Depfile");
    std::vector<Constraints> correct_answer;
    correct_answer.emplace_back("test_constraints_1");
    correct_answer.emplace_back("test_constraints_2");
    ASSERT_THAT(file->get_constraints(), testing::ContainerEq(correct_answer));
}


TEST_F( DepfileTest , Depfile_scripts) {
    SetUp("Depfile");
    std::vector<Script> correct_answer;
    correct_answer.emplace_back("test_script.tcl", "tcl");
    correct_answer.emplace_back("test_script.py", "py");
    ASSERT_THAT(file->get_scripts(), testing::ContainerEq(correct_answer));
}