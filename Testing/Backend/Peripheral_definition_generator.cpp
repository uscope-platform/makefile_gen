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

#include "data_model/Depfile.hpp"
#include "data_model/HDL/HDL_Resource.hpp"
#include "data_model/data_store.hpp"
#include "Backend/uplatform/peripheral_definition_generator.hpp"


class periph_def_generation : public ::testing::Test {
protected:
    void SetUp() {

    }

    virtual void TearDown() {
    }
};

TEST_F( periph_def_generation , generate_periph_def) {

    ASSERT_EQ(true, false);
}
