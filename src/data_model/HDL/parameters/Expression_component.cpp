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

#include "data_model/HDL/parameters/Expression.hpp"
#include "data_model/HDL/parameters/Expression_component.hpp"

const std::regex Expression_component::sv_constant_regex(R"(^\d*'(s)?(h|d|o|b)([0-9a-fA-F]+))");
const std::regex Expression_component::number_regex("^\\d+$");
const std::regex Expression_component::size_regex(R"(^(\d*)'[0-9a-zA-Z]+)");


Expression_component::Expression_component(const Expression_component &c) {
    value = c.value;
    array_index = c.array_index;
    package_prefix = c.package_prefix;
    binary_size = c.binary_size;
    type = c.type;
}


Expression_component::Expression_component() {
    value = 0;
}

Expression_component::Expression_component(const std::string &s, const component_type &t) {
    value =  s;
    type = t;
    if(t == number) {
        auto ret_val = process_number(s);
        value = ret_val.first;
        binary_size = ret_val.second;
    }
}

Expression_component::Expression_component(int64_t n, int64_t b_s) {
    value = n;
    binary_size = b_s;
    type = number;
}

std::set<qualified_identifier> Expression_component::get_dependencies()const {
    std::set<qualified_identifier> result;
    if (is_identifier()){
        result.insert({package_prefix, std::get<std::string>(value)});
    }
    for (const auto &idx:array_index) {
        auto idx_deps = idx.get_dependencies();
        result.insert(idx_deps.begin(), idx_deps.end());
    }
    return result;
}

bool Expression_component::propagate_constant(const std::string &const_name, const resolved_parameter &const_value) {
    bool retval = true;

    bool index_need_rewrite = false;
    std::vector<int64_t> indices;
    for (auto &component:array_index) {
        retval &= component.propagate_constant(const_name, const_value);
        auto idx_val = component.evaluate(false);
        if (idx_val.has_value()) {
            index_need_rewrite = true;
            if (!std::holds_alternative<int64_t>(idx_val.value())) return false;
            indices.push_back(std::get<int64_t>(idx_val.value()));
        }
    }
    if(array_index.size() != indices.size()) return false;
    if(index_need_rewrite) {
        for(int i = 0; i<array_index.size(); i++) {
            array_index[i] = {Expression_component(indices[i], 0)};
        }
        int i = 0;
    }
    if (std::holds_alternative<std::string>(value)) {
        if (std::get<std::string>(value) == const_name) {
            if (!array_index.empty()) {
                if(std::holds_alternative<mdarray<int64_t>>(const_value)) {
                    auto values = std::get<mdarray<int64_t>>(const_value);
                    auto array_val = values.get_value(indices);
                    if (array_val.has_value()) {
                        type = number;
                        value = array_val.value();
                    }
                    else {
                        type = number;
                        value = 0; // if the array value is not found (because of some dimensional issue) substitute with a 0 rather than crashing
                    }
                } else {
                    std::bitset<64> bits(std::get<int64_t>(const_value));
                    type = number;
                    value = bits[indices[0]];
                }

            } else {
                type = number;
                value = const_value;
            }
        }
        return retval;
    }
    return true;
}


bool operator==(const Expression_component &lhs, const Expression_component &rhs) {
     bool ret_val = true;
    ret_val &= lhs.value == rhs.value;
    ret_val &= lhs.array_index == rhs.array_index;
    ret_val &= lhs.package_prefix == rhs.package_prefix;
    ret_val &= lhs.binary_size == rhs.binary_size;
    return ret_val;
}

std::string Expression_component::print_value() {
    std::string ret_val;
     if(is_numeric()){
        ret_val = std::to_string(std::get<int64_t>(value));
    } else {
        if(!array_index.empty()){
            ret_val = std::get<std::string>(value) + print_index(array_index);
        } else {
            ret_val = std::get<std::string>(value);
        }
    }


    return ret_val;
}

 std::pair<int64_t, int64_t>  Expression_component::process_number(const std::string &s) {
    std::pair<int64_t, int64_t> ret_val;

    if(test_parameter_type(number_regex, s)) {
        ret_val.first = static_cast<int64_t>(std::stoul(s));
        ret_val.second = calculate_binary_size(ret_val.first);
    } else if(test_parameter_type(sv_constant_regex, s)){
        std::smatch base_match;
        if(std::regex_search(s, base_match, sv_constant_regex)){
            // Process value
            std::string base;
            std::string str_value;
            switch (base_match.size()) {
                case 3:
                    base = base_match[1].str();
                    str_value = base_match[2].str();
                    break;
                case 4:
                    base = base_match[2].str();
                    str_value = base_match[3].str();
                    break;
            }
            if(base =="h"){
                ret_val.first = static_cast<int64_t>(std::stoul(str_value, nullptr, 16));
            } else if(base =="d") {
                ret_val.first = static_cast<int64_t>(std::stoul(str_value, nullptr, 10));
            } else if(base =="o") {
                ret_val.first = static_cast<int64_t>(std::stoul(str_value, nullptr, 8));
            } else if(base =="b") {
                ret_val.first = static_cast<int64_t>(std::stoul(str_value, nullptr, 2));
            }
            // Process size

            if(std::regex_search(s, base_match, size_regex)){
                if(!base_match[1].str().empty()) {
                    ret_val.second = std::stoll(base_match[1].str());
                } else {
                    ret_val.second = calculate_binary_size(ret_val.first);
                }
            }
        }
    }
    return ret_val;
}

bool Expression_component::test_parameter_type(const std::regex &r, const std::string &s) {

    std::smatch base_match;
    if(std::regex_search(s, base_match, r)){
        return true;
    } else{
        return false;
    }
}

Expression_component::operator_type_t Expression_component::get_operator_type() {
    if(!operators_types.contains(std::get<std::string>(value))){
        throw std::runtime_error("Error: attempted to get the type of a non operator/function expression component");
    }
    return operators_types[std::get<std::string>(value)];
}

int64_t Expression_component::get_operator_precedence() {
    if (std::holds_alternative<int64_t>(value))  throw std::runtime_error("Error: attempted to get the precedence of a number");
    auto string_value = std::get<std::string>(value);
    if(!operators_precedence.contains(string_value)){
        throw std::runtime_error("Error: attempted to get the precedence of a non operator/function expression component");
    }
    return operators_precedence[string_value];
}

bool Expression_component::is_right_associative() {
    if (std::holds_alternative<int64_t>(value))  throw std::runtime_error("Error: attempted to get the associativity of a number");
    auto string_value = std::get<std::string>(value);
    if((type != operation) && (type != function)){
        throw std::runtime_error("Error: attempted to get the right associativity of a non operator/function expression component");
    }
    return right_associative_set.contains(std::get<std::string>(value));
}

std::string Expression_component::print_index(const std::vector<Expression> &index) const {
    std::string ret_val;
    for(const auto &item:index){
        ret_val += "[" + item.print() + "]";
    }
    return ret_val;
}

nlohmann::json Expression_component::dump() {
    nlohmann::json ret;

    return ret;
}

int64_t Expression_component::calculate_binary_size(int64_t in) {
    auto n_bits = std::log2(in);
    if(std::isinf(n_bits) || n_bits == 0) {
        return 1;
    }else{
        return  std::ceil(n_bits);
    }
}

void Expression_component::set_array_index(const std::vector<Expression> &v) {
    array_index = v;
}

void Expression_component::add_array_index(const Expression &c) {
    array_index.push_back(c);
}

Expression_component::component_type Expression_component::get_type(const std::string &s) {
    if(test_parameter_type(number_regex, s) || test_parameter_type(sv_constant_regex, s)) return number;
    if(is_string_operator(s)) return operation;
    if(is_string_function(s)) return function;
    if(is_string_parenthesis(s)) return parenthesis;
    if(s.starts_with("\"")) return string;
    return identifier;
}