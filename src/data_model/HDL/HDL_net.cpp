//  Copyright 2025 Filippo Savi
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

#include "data_model/HDL/HDL_net.hpp"

std::string HDL_net::get_full_name() const {
    if(array_accessor.get_type() == numeric_parameter) {
        return name + std::to_string(array_accessor.get_numeric_value());
    } else {
        return name + array_accessor.get_string_value();
    }

}

nlohmann::json HDL_net::dump() {
    nlohmann::json ret;
    ret["name"] = name;
    if(!array_accessor.is_empty()) ret["index"] = array_accessor.dump();
    return ret;
}
