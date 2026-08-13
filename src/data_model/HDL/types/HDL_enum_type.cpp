//  Copyright 2026 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include <cereal/archives/binary.hpp>
#include <cereal/types/polymorphic.hpp>

#include "data_model/HDL/types/HDL_enum_type.hpp"

CEREAL_REGISTER_TYPE(HDL_enum_type)
CEREAL_REGISTER_POLYMORPHIC_RELATION(hdl_type, HDL_enum_type)

parameter_deps_t HDL_enum_type::get_dependencies(){
    parameter_deps_t result;
    if (base_type) result.merge(base_type->get_dependencies());
    return result;
}

std::string HDL_enum_type::to_print() const{
    std::string result = "enum {";
    for (size_t i = 0; i < members.size(); ++i) {
        if (i > 0) result += ", ";
        result += members[i].name;
    }
    result += "}";
    if (base_type) {
        result += " (base: " + base_type->to_print() + ")";
    }
    return result;
}
