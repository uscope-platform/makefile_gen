// Copyright 2023 Filippo Savi
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

#include "data_model/documentation/processor_instance.hpp"


processor_instance::processor_instance(const std::string &n) {
    name = n;
}


void processor_instance::add_io(const io &i) {
    dma_io.push_back(i);
}

processor_instance::processor_instance(const processor_instance &old) {
    name = old.name;
    dma_io = old.dma_io;
    target = old.target;
    address_param = old.address_param;
    address_index = old.address_index;
    address_value = old.address_value;
}

bool operator==(const processor_instance &lhs, const processor_instance &rhs) {
    bool res = true;
    res &= lhs.name == rhs.name;
    res &= lhs.target == rhs.target;
    res &= lhs.address_param == rhs.address_param;
    res &= lhs.address_index == rhs.address_index;
    res &= lhs.address_value == rhs.address_value;

    if(lhs.dma_io.size() != rhs.dma_io.size()){
        return false;
    }
    for(int i=0; i<lhs.dma_io.size(); i++){
        res &= lhs.dma_io[i] == rhs.dma_io[i];
    }
    return res;
}

bool operator==(const io &lhs, const io &rhs) {
    bool res = true;
    res &= lhs.name == rhs.name;
    res &= lhs.address == rhs.address;
    res &= lhs.type == rhs.type;
    return res;
}

std::string io::get_type() const {
    switch (type) {
        case input:
            return "input";
        case output:
            return "output";
        case memory:
            return "memory";
        default:
            return "";
    }
}
