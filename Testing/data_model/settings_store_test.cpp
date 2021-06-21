//
// Created by fils on 21/06/2021.
//

#include <gtest/gtest.h>

#include "../includes/data_model/settings_store.h"

TEST( settings_store_test , get_set_setting) {
    settings_store store;
    store.set_setting("test_Setting", "test_123");
    std::string result = store.get_setting("test_Setting");
    store.remove_setting("test_setting");
    ASSERT_EQ(result, "test_123");
}

TEST( settings_store_test , ser_des) {
    auto *store_1 = new settings_store();
    store_1->set_setting("test_Setting", "test_123");
    delete store_1;
    auto *store_2 = new settings_store();
    std::string result = store_2->get_setting("test_Setting");
    store_2->remove_setting("test_setting");
    delete store_2;

    ASSERT_EQ(result, "test_123");
}