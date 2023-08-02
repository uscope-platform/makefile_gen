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

#ifndef MAKEFILEGEN_V2_BUS_MAPPING_EXPRESSION_HPP
#define MAKEFILEGEN_V2_BUS_MAPPING_EXPRESSION_HPP


#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <memory>
#include <regex>
#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>

class bus_mapping_expression {
public:
    bus_mapping_expression()=default;
    explicit bus_mapping_expression(std::string text);
    bus_mapping_expression(const bus_mapping_expression &e );
    bus_mapping_expression(std::string n, uint32_t a);
    bus_mapping_expression(std::string n, std::vector<std::string> e);
    void set_name(const std::string &n){ name = n;};
    std::string get_name() {return name;};
    [[nodiscard]] std::vector<std::string> get_expression() const {return expression_components;};
    void update_expression(const std::string& n, uint32_t value);

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, expression_components);
    }

    friend bool operator==(const bus_mapping_expression &lhs, const bus_mapping_expression&rhs);
private:
    std::string name;
    std::vector<std::string> expression_components;
};


#endif //MAKEFILEGEN_V2_BUS_MAPPING_EXPRESSION_HPP
