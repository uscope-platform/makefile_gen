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

#include "data_model/settings_store.hpp"

namespace {
std::string store_settings_path = "/tmp/ananke_settings_test";
auto store_settings_file = store_settings_path + "/settings";
}

TEST(settings_store, include_auto_discovery_default_on) {
    std::filesystem::create_directories(store_settings_path);
    std::ofstream ofs(store_settings_file);
    ofs << "{\"profiles\": {\"test_profile\": {\"hdl_store\":\"/tmp/repo\"}}}";
    ofs.flush();
    ofs.close();

    settings_store s(false, store_settings_path, "test_profile");
    EXPECT_TRUE(s.get_include_auto_discovery());

    std::filesystem::remove_all(store_settings_path);
}

TEST(settings_store, include_auto_discovery_explicit_off) {
    std::filesystem::create_directories(store_settings_path);
    std::ofstream ofs(store_settings_file);
    ofs << "{\"profiles\": {\"test_profile\": {\"hdl_store\":\"/tmp/repo\","
           "\"include_auto_discovery\":false}}}";
    ofs.flush();
    ofs.close();

    settings_store s(false, store_settings_path, "test_profile");
    EXPECT_FALSE(s.get_include_auto_discovery());

    std::filesystem::remove_all(store_settings_path);
}

TEST(settings_store, include_auto_discovery_persisted) {
    std::filesystem::create_directories(store_settings_path);
    std::ofstream ofs(store_settings_file);
    ofs << "{\"profiles\": {\"test_profile\": {\"hdl_store\":\"/tmp/repo\","
           "\"include_auto_discovery\":false}}}";
    ofs.flush();
    ofs.close();

    {
        settings_store s(false, store_settings_path, "test_profile");
        EXPECT_FALSE(s.get_include_auto_discovery());
        s.flush();
    }

    settings_store s2(false, store_settings_path, "test_profile");
    EXPECT_FALSE(s2.get_include_auto_discovery());

    std::filesystem::remove_all(store_settings_path);
}