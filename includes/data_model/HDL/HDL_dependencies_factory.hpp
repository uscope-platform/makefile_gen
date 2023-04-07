// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// Unless required by applicable law or agreed to in writing, software

#ifndef MAKEFILEGEN_V2_HDL_DEPENDENCIES_FACTORY_HPP
#define MAKEFILEGEN_V2_HDL_DEPENDENCIES_FACTORY_HPP

#include "data_model/HDL/HDL_dependency.hpp"

class HDL_dependencies_factory {
public:
    void new_dependency(const std::string &n, const std::string &p, dependency_class dc);
    void add_parameter(const std::string &name, const std::string &value);
    void add_port(const std::string &name, const std::string &value);
    HDL_dependency get_dependency();
    bool is_valid_dependency(){return valid_dependency;};
private:
    HDL_dependency current_dependency;
    bool valid_dependency;
};




#endif //MAKEFILEGEN_V2_HDL_DEPENDENCIES_FACTORY_HPP
