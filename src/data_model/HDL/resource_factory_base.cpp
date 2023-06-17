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

#include "data_model/HDL/resource_factory_base.hpp"
#include "data_model/HDL/HDL_Resource.hpp"

template<class T>
void resources_factory_base<T>::new_basic_resource() {
    valid_resource = true;
    push_resource();
    current_resource = T();
}


template<class T>
void resources_factory_base<T>::pop_resource() {
    if(!resource_stack.empty()){
        current_resource = resource_stack.top();
        resource_stack.pop();
    } else {
        valid_resource = false;
        current_resource = T();
    }
}

template<class T>
void resources_factory_base<T>::push_resource() {
    if(!current_resource.is_empty()){
        resource_stack.push(current_resource);
    }
}

template<class T>
T resources_factory_base<T>::get_resource() {
    T ret_val = current_resource;
    pop_resource();
    return ret_val;
}

template<class T>
void resources_factory_base<T>::set_name(const std::string &n) {
    current_resource.set_name(n);
}


template class resources_factory_base<HDL_Resource>;