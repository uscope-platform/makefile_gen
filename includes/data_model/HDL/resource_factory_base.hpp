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

#ifndef MAKEFILEGEN_V2_RESOURCES_FACTORY_BASE_HPP
#define MAKEFILEGEN_V2_RESOURCES_FACTORY_BASE_HPP

#include <string>
#include <stack>
#include "HDL_Resource.h"

template <class T>
class resources_factory_base {

protected:
    void new_resource(std::string &p);
    T get_resource();
    void set_name(const std::string &n);

    T current_resource;
    void push_resource();
    void pop_resource();
    std::stack<T> resource_stack;
};



#endif //MAKEFILEGEN_V2_RESOURCES_FACTORY_BASE_HPP
