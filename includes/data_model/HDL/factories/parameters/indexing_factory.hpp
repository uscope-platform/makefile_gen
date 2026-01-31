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

#ifndef MAKEFILEGEN_V2_INDEXING_FACTORY_HPP
#define MAKEFILEGEN_V2_INDEXING_FACTORY_HPP

#include "data_model/HDL/parameters/Expression.hpp"
#include "data_model/HDL/parameters/dimension.hpp"

class indexing_factory {
public:
    void start_index(bool r);
    Expression get_index() {return index;}
    void stop_index();
    [[nodiscard]] bool is_active() const {return active;}
    [[nodiscard]] bool is_range() const {return active && range;}
    void add_expression(const Expression &e);
    void add_component(const Expression_component &c){index.push_back(c);}
    dimension_t get_dimension(bool p);
private:
    bool active = false;
    bool range = false;
    Expression index;
    bool first_bound = true;
    dimension_t dim = {};
};


#endif //MAKEFILEGEN_V2_INDEXING_FACTORY_HPP