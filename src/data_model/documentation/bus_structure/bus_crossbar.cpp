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


#include "data_model/documentation/bus_structure/bus_crossbar.h"


bus_crossbar::bus_crossbar(std::string p) {
     parameter_name = std::move(p);
     base_address = 0;
}

void bus_crossbar::add_child(const std::shared_ptr<bus_component>& c) {
    children.push_back(c);
}


bool operator==(const bus_crossbar &lhs, const bus_crossbar &rhs) {
    bool ret = true;

    ret &= lhs.base_address == rhs.base_address;
    ret &= lhs.parameter_name == rhs.parameter_name;
    ret &= lhs.target == rhs.target;
    ret &= lhs.children.size() == rhs.children.size();

    if(ret){
        for(int i = 0; i< lhs.children.size(); ++i){
            ret &= bus_component::compare(lhs.children[i], rhs.children[i]);
        }
    }
    // THE RAW CHILDREN LIST IS NOT INCLUDED AS IT IS A VERY TEMPORARY HACK
    return ret;
}
