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

#include "data_model/HDL_instance.hpp"

#include <utility>

HDL_instance::HDL_instance(std::string s, std::string t, sv_feature f) {
    feature = f;
    name = std::move(s);
    type = std::move(t);
}

void HDL_instance::add_parameter(const std::string& parameter_name, std::string value) {
    parameters_map[parameter_name] = std::move(value);
}

void HDL_instance::add_port_connection(const std::string& port_name, std::string value) {
    ports_map[port_name] = std::move(value);
}

bool operator==(const HDL_instance &lhs, const HDL_instance &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.type == rhs.type;
    ret &= lhs.feature == rhs.feature;
    ret &= lhs.ports_map == rhs.ports_map;
    ret &= lhs.parameters_map == rhs.parameters_map;

    return ret;
}
