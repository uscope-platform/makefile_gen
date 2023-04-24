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

#ifndef MAKEFILEGEN_V2_EXPRESSION_HPP
#define MAKEFILEGEN_V2_EXPRESSION_HPP


#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <memory>

#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>

class expression {
public:
    expression()=default;
    expression( const expression &e );
    expression(std::string n, uint32_t a);
    expression(std::string n, std::vector<std::string> e);
    void set_name(const std::string &n){ name = n;};
    std::string get_name() {return name;};
    [[nodiscard]] std::vector<std::string> get_expression() const {return expression_components;};
    void update_expression(const std::string& n, uint32_t value);

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(name, expression_components);
    }

    friend bool operator==(const expression &lhs, const expression&rhs);
private:
    std::string name;
    std::vector<std::string> expression_components;
};


#endif //MAKEFILEGEN_V2_EXPRESSION_HPP
