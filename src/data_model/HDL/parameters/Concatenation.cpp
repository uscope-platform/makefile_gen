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


#include "data_model/HDL/parameters/Concatenation.hpp"

std::set<std::string> Concatenation::get_dependencies() const{
    std::set<std::string> result;
    for (auto &comp:components) {
        auto comp_deps = comp->get_dependencies();
        result.insert(comp_deps.begin(), comp_deps.end());
    }
    return result;
}

bool Concatenation::propagate_constant(const std::string &name, const resolved_parameter &value) {
   bool retval = true;
    for (auto &comp:components) {
        retval &= comp->propagate_constant(name, value);
    }
    return retval;
}

std::optional<resolved_parameter> Concatenation::evaluate(bool packed){
    if (packed) {
        return evaluate_packed();
    } else {
        return evaluate_unpacked();
    }
}

std::string Concatenation::print()  const{
    std::ostringstream oss;
    oss << "{";
    for (int i = 0; i< components.size(); i++) {
        oss << components[i]->print();
        if (components.size() == 1) break;
        if (i<components.size()-1) oss <<", ";
    }
    oss <<"}\n";
    auto dbg =  oss.str();
    return oss.str();
}

std::optional<resolved_parameter> Concatenation::evaluate_packed() {
    auto concat_size = components.size();
    std::vector<int64_t> sizes(concat_size);
    std::vector<int64_t> values(concat_size);
    for (int i = 0;i<concat_size; i++) {
        auto value_opt = components[concat_size-i-1].evaluate(&sizes[i]);
        if (!value_opt.has_value()) return std::nullopt;
        auto raw_value = value_opt.value();
        if (!std::holds_alternative<int64_t>(raw_value)) throw std::runtime_error("packing concatenations of arrays orare unsupported");
        values[i] = std::get<int64_t>(raw_value);
    }
    return pack_values(values, sizes);
}

std::optional<resolved_parameter> Concatenation::evaluate_unpacked() {
    auto concat_size = components.size();
    mdarray<int64_t> result;
    for (int64_t i = 0;i<concat_size; i++) {
        auto value_opt = components[concat_size-i-1].evaluate();
        if (!value_opt.has_value()) return std::nullopt;
        if (std::holds_alternative<int64_t>(value_opt.value())) {
            mdarray<int64_t> to_concat;
            to_concat.set_value(0,std::get<int64_t>(value_opt.value()));
            result = mdarray<int64_t>::concatenate(result, to_concat).value();
        } else {
            auto array_res = std::get<mdarray<int64_t>>(value_opt.value());
            result = mdarray<int64_t>::concatenate(result, array_res).value();
        }
    }
    return result;
}

int64_t Concatenation::pack_values(const std::vector<int64_t> &components, std::vector<int64_t> &sizes) {
    int64_t total_size = 0;
    for(auto &size:sizes){
        total_size += size;
    }
    std::vector<bool> result(total_size, false);

    uint64_t current_wp = 0;
    for(ssize_t i =0; i<components.size(); i++){
        std::bitset<64> data = components[i];
        auto size = sizes[i];
        for(int j = 0; j<size; j++){
            result[current_wp] = data[j];
            current_wp++;
        }
    }

    int64_t packed_result = 0;
    for(int i = 0; i<result.size(); i++){
        packed_result += result[i]*std::pow(2, i);
    }

    return packed_result;
}
