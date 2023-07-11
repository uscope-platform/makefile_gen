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
#include "Backend/Dependency_resolver.hpp"



class dep_resolver : public ::testing::Test {
protected:
    void SetUp() {
        d_store = std::make_shared<data_store>(true,"/tmp/test_data_store");
        HDL_instance d1("inst", "test_dep", module);
        HDL_instance d2("mem_init", "test_mem_init", memory_init);
        HDL_instance d3("exm", "excluded_module", module);
        std::vector<HDL_instance> deps = {d1, d2, d3};
        HDL_Resource mod_entity(module, "test_module", "test/mod.sv");
        mod_entity.add_dependencies(deps);
        d_store->store_hdl_entity(mod_entity);

        DataFile D("test_mem_init", "test/mem_init.mem");
        d_store->store_data_file(D);
        HDL_Resource expl_dep(module, "expl_dep", "test/explicit/dep.sv");
        d_store->store_hdl_entity(expl_dep);
        HDL_Resource dep_entity(module, "test_dep", "test/dep.sv");
        d_store->store_hdl_entity(dep_entity);
    }

    virtual void TearDown() {
    }
    std::shared_ptr<data_store> d_store;
};

TEST_F(dep_resolver , dependency_resolver) {
    Dependency_resolver res("test_module", d_store);
    res.set_excluded_modules({"excluded_module"});
    res.add_explicit_dependencies({"expl_dep"});
    res.resolve_dependencies();
    std::set<std::string> result = res.get_dependencies();
    std::set<std::string> check = {"test/mod.sv", "test/dep.sv", "test/mem_init.mem", "test/explicit/dep.sv"};
    ASSERT_EQ(result, check);
}