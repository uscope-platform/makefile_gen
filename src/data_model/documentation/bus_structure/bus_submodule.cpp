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

#include "data_model/documentation/bus_structure/bus_submodule.hpp"



bool operator==(const bus_submodule &lhs, const bus_submodule &rhs) {
    bool ret = true;

    ret &= lhs.name == rhs.name;
    ret &= lhs.instance_type == rhs.instance_type;
    ret &= lhs.offset == rhs.offset;

    ret &= lhs.children.size() == rhs.children.size();

    if(ret){
        for(int i = 0; i< lhs.children.size(); ++i){
            ret &= lhs.children[i] == rhs.children[i];
        }
    }

    return ret;
}

void bus_submodule::set_module_type(const std::string t) {
    instance_type = t;
}
