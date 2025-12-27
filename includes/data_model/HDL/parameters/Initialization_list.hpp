//  Copyright 2023 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP
#define MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP


#include <vector>
#include <utility>
#include <cereal/types/vector.hpp>

#include "data_model/HDL/parameters/Expression_component.hpp"
#include "data_model/mdarray.hpp"


// FORWARD DECLARATIONS
class HDL_parameter;
class Parameter_processor;
class data_store;
class Parameters_map;

typedef struct dims_struct{
    Expression first_bound;
    Expression second_bound;
    bool packed;

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(first_bound, second_bound, packed);
    }

} dimension_t;

class Initialization_list {

public:
    Initialization_list() = default;
    Initialization_list( const Initialization_list &i);
    explicit Initialization_list(const Expression &e);
    void add_dimension(const dimension_t &d, bool packed);
    void add_item(const Expression &e);
    void open_level();
    void close_level();
    bool empty() const;
    bool is_packed() const{return unpacked_dimensions.empty() && !packed_dimensions.empty();};
    void link_processor(
                        const std::shared_ptr<Parameters_map> &ep,
                        const std::shared_ptr<Parameters_map> &cs,
                        const std::shared_ptr<data_store> &ds);
    int64_t get_value_at(std::vector<uint64_t> idx);
    mdarray<int64_t> get_values();

    void set_packed_dimensions(const std::vector<dimension_t>  &d) {packed_dimensions = d;};
    void set_unpacked_dimensions(const std::vector<dimension_t>  &d) {unpacked_dimensions = d;};
    std::vector<dimension_t> get_packed_dimensions(){return  packed_dimensions;};
    std::vector<dimension_t> get_unpacked_dimensions(){return  unpacked_dimensions;};

    mdarray<int64_t> process_default_initialization();

    static bool is_repetition(Expression &e){
        if(!e.empty()){
            return e[0].get_string_value() == "$repeat_init";
        }
        return false;
    }

    void set_default() { default_initialization = true;};

    friend bool operator==(const Initialization_list&lhs, const Initialization_list&rhs);
    friend void PrintTo(const Initialization_list& res, std::ostream* os);

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(unpacked_dimensions, packed_dimensions, last_dimension, expression_leaves,
           lower_dimension_leaves, default_initialization);
    }


private:

    std::vector<int64_t> expand_repetition(Expression &e, Parameter_processor &p, std::vector<int64_t> *sizes);

    Parameter_processor get_parameter_processor();
    mdarray<int64_t> get_packed_1d_list_values();
    mdarray<int64_t> get_1d_list_values();
    std::pair<mdarray<int64_t>::md_1d_array, mdarray<int64_t>::md_1d_array> get_sized_1d_list_values(bool &already_packed);
    mdarray<int64_t> get_2d_list_values();
    mdarray<int64_t> get_3d_list_values();

    int64_t pack_values(const std::pair<mdarray<int64_t>::md_1d_array, mdarray<int64_t>::md_1d_array> &components);

    std::shared_ptr<Parameters_map> external_parameters;
    std::shared_ptr<Parameters_map> completed_set;
    std::shared_ptr<data_store> d_store;

    std::vector<dimension_t> unpacked_dimensions;
    std::vector<dimension_t> packed_dimensions;

    bool last_dimension = true;
    std::vector<Expression> expression_leaves;
    std::vector<Initialization_list> lower_dimension_leaves;
    bool default_initialization = false;
};


#endif //MAKEFILEGEN_V2_INITIALIZATION_LIST_HPP
