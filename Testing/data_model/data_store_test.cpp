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

#include "../includes/data_model/data_store.h"
#include "../includes/data_model/Constraints.h"


TEST( data_store_test , evict_constr) {

    auto *store_1 = new data_store();
    Constraints test_constr("test");

    std::shared_ptr<Constraints> test_constr_ptr = std::make_shared<Constraints>(test_constr);
    store_1->store_constraint(test_constr_ptr);
    store_1->evict_constraint(test_constr_ptr->get_name());
    std::string n = "test";
    std::shared_ptr<Constraints> test_item = store_1->get_constraint(n);

    ASSERT_EQ(test_item, nullptr);

}


TEST( data_store_test , evict_script) {

    auto *store_1 = new data_store();
    Script test_scr("test","py");

    std::shared_ptr<Script> test_scr_ptr = std::make_shared<Script>(test_scr);
    store_1->store_script(test_scr_ptr);
    store_1->evict_script(test_scr_ptr->get_name());
    std::string n = "test";
    std::shared_ptr<Script> test_item = store_1->get_script(n);

    ASSERT_EQ(test_item, nullptr);

}


TEST( data_store_test , evict_hdl_entity) {

    auto *store_1 = new data_store();
    hdl_deps_t deps;
    HDL_Resource test_entity(module, "test", "/test/path", deps, verilog_entity);

    std::shared_ptr<HDL_Resource> test_entity_ptr = std::make_shared<HDL_Resource>(test_entity);
    store_1->store_hdl_entity(test_entity_ptr);
    store_1->evict_hdl_entity(test_entity_ptr->getName());
    std::string n = "test";
    std::shared_ptr<HDL_Resource> test_item = store_1->get_HDL_resource(n);

    ASSERT_EQ(test_item, nullptr);

}


TEST( data_store_test , ser_des_constraints) {

    auto *store_1 = new data_store();
    Constraints test_constr("test");
    // The path is chosen to always exist as otherwise the Cache entry is removed  by the cache clearing
    // routine invoked by the constructor
    test_constr.set_path("/bin/sh");
    std::shared_ptr<Constraints> test_constr_ptr = std::make_shared<Constraints>(test_constr);
    store_1->store_constraint(test_constr_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<Constraints> result = store_2->get_constraint(name);
    ASSERT_EQ(*result, *test_constr_ptr);
    store_2->evict_constraint(test_constr_ptr->get_name());
    delete store_2;

}


TEST( data_store_test , ser_des_script) {

    auto *store_1 = new data_store();
    Script test_scr("test","py");
    // The path is chosen to always exist as otherwise the Cache entry is removed  by the cache clearing
    // routine invoked by the constructor
    test_scr.set_path("/bin/sh");
    std::shared_ptr<Script> test_scr_ptr = std::make_shared<Script>(test_scr);
    store_1->store_script(test_scr_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<Script> result = store_2->get_script(name);
    ASSERT_EQ(*result, *test_scr_ptr);
    store_2->evict_script(test_scr_ptr->get_name());
    delete store_2;

}

TEST( data_store_test , ser_des_hdl_resource) {

    auto *store_1 = new data_store();
    hdl_deps_t deps;
    // The path is chosen as to always exist as otherwise the Cache entry is removed  by the cache clearing
    // routine invoked by the constructor
    HDL_Resource test_entity(module, "test", "/bin/sh", deps, verilog_entity);

    std::shared_ptr<HDL_Resource> test_res_ptr = std::make_shared<HDL_Resource>(test_entity);
    store_1->store_hdl_entity(test_res_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<HDL_Resource> result = store_2->get_HDL_resource(name);
    ASSERT_EQ(*result, *test_res_ptr);
    store_2->evict_script(test_res_ptr->getName());
    delete store_2;

}


TEST( data_store_test , store_script_vect) {

    auto *store = new data_store();
    std::shared_ptr<Script> test_scr_1 = std::make_shared<Script>("test_1","py");
    std::shared_ptr<Script> test_scr_2 = std::make_shared<Script>("test_2","py");
    std::vector<std::shared_ptr<Script>> test_vect = {test_scr_1,test_scr_2};
    store->store_script(test_vect);
    std::string name = "test_1";
    std::shared_ptr<Script> test_res_1 = store->get_script(name);
    name = "test_2";
    std::shared_ptr<Script> test_res_2 = store->get_script(name);
    std::vector<std::shared_ptr<Script>> res_vect = {test_res_1, test_res_2};

    store->evict_script("test_1");
    store->evict_script("test_2");

    ASSERT_EQ(test_vect, res_vect);
}

TEST( data_store_test , store_hdl_vect) {

    auto *store = new data_store();
    hdl_deps_t deps;
    std::shared_ptr<HDL_Resource> test_res_1 = std::make_shared<HDL_Resource>(module, "test_1", "/bin/sh", deps, verilog_entity);
    std::shared_ptr<HDL_Resource> test_res_2= std::make_shared<HDL_Resource>(module, "test_2", "/bin/sh", deps, verilog_entity);
    std::vector<std::shared_ptr<HDL_Resource>> test_vect = {test_res_1,test_res_2};
    store->store_hdl_entity(test_vect);
    std::string name = "test_1";
    std::shared_ptr<HDL_Resource> test_result_1 = store->get_HDL_resource(name);
    name = "test_2";
    std::shared_ptr<HDL_Resource> test_result_2 = store->get_HDL_resource(name);
    std::vector<std::shared_ptr<HDL_Resource>> res_vect = {test_result_1, test_result_2};

    store->evict_hdl_entity("test_1");
    store->evict_hdl_entity("test_2");
    ASSERT_EQ(test_vect, res_vect);
}

TEST( data_store_test , store_const_vect) {

    auto *store = new data_store();
    hdl_deps_t deps;
    std::shared_ptr<Constraints> test_const_1 = std::make_shared<Constraints>( "test_1");
    std::shared_ptr<Constraints> test_const_2= std::make_shared<Constraints>("test_2");
    std::vector<std::shared_ptr<Constraints>> test_vect = {test_const_1,test_const_2};
    store->store_constraint(test_vect);
    std::string name = "test_1";
    std::shared_ptr<Constraints> test_result_1 = store->get_constraint(name);
    name = "test_2";
    std::shared_ptr<Constraints> test_result_2 = store->get_constraint(name);
    std::vector<std::shared_ptr<Constraints>> res_vect = {test_result_1, test_result_2};

    store->evict_constraint("test_1");
    store->evict_constraint("test_2");
    ASSERT_EQ(test_vect, res_vect);
}


TEST( data_store_test , constr_clean_up) {

    auto *store_1 = new data_store();
    Constraints test_constr("test");
    test_constr.set_path("/test");
    std::shared_ptr<Constraints> test_constr_ptr = std::make_shared<Constraints>(test_constr);
    store_1->store_constraint(test_constr_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<Constraints> result = store_2->get_constraint(name);
    ASSERT_EQ(result, nullptr);
    store_2->evict_constraint(test_constr_ptr->get_name());
    delete store_2;

}


TEST( data_store_test , script_clean_up) {

    auto *store_1 = new data_store();
    Script test_scr("test","py");
    test_scr.set_path("/test");
    std::shared_ptr<Script> test_scr_ptr = std::make_shared<Script>(test_scr);
    store_1->store_script(test_scr_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<Script> result = store_2->get_script(name);
    ASSERT_EQ(result, nullptr);
    store_2->evict_script(test_scr_ptr->get_name());
    delete store_2;

}

TEST( data_store_test , resource_clean_up) {

    auto *store_1 = new data_store();
    hdl_deps_t deps;

    HDL_Resource test_entity(module, "test", "/test", deps, verilog_entity);

    std::shared_ptr<HDL_Resource> test_res_ptr = std::make_shared<HDL_Resource>(test_entity);
    store_1->store_hdl_entity(test_res_ptr);
    delete store_1;
    auto *store_2 = new data_store();
    std::string name = "test";
    std::shared_ptr<HDL_Resource> result = store_2->get_HDL_resource(name);
    ASSERT_EQ(result, nullptr);
    store_2->evict_script(test_res_ptr->getName());
    delete store_2;

}

