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

#include <gtest/gtest.h>

#include "frontend/analysis/vhdl/vhdl_analyzer.hpp"
#include "data_model/HDL/statement/hdl_statements.hpp"

namespace {

    std::shared_ptr<hdl_resource_statement> parse_first_entity(const std::string &content) {
        vhdl_analyzer analyzer("test.vhd");
        auto result = analyzer.analyze_content(content, "test.vhd");
        auto &first = result.get_content()[0];
        EXPECT_TRUE(first->is<hdl_resource_statement>());
        return std::make_shared<hdl_resource_statement>(first->as<hdl_resource_statement>());
    }

    std::shared_ptr<hdl_instance_statement> make_instance(const std::string &name, const std::string &type) {
        auto inst = std::make_shared<hdl_instance_statement>();
        inst->set_name(name);
        inst->set_type(type);
        inst->set_dependency_class(module);
        return inst;
    }

}

TEST(vhdl_analyzer, entity_name_extraction) {
    auto test_pattern = R"(
entity test_mod is
end test_mod;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("test_mod");
    golden.set_type(module);
    golden.set_line_n(2);

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, architecture_statement_binding) {
    auto test_pattern = R"(
entity top is
end top;

architecture rtl of top is
    component ANDGATE is
        port (
            I1 : in std_logic;
            O  : out std_logic
        );
    end component ANDGATE;
begin
    and1 : ANDGATE
        port map (
            I1 => a,
            O  => b
        );
end rtl;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_statement(make_instance("and1", "andgate"));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, case_insensitive_entity_and_architecture_binding) {
    auto test_pattern = R"(
ENTITY HALF_ADDER IS
END HALF_ADDER;

ARCHITECTURE RTL OF HALF_ADDER IS
    COMPONENT ANDGATE IS
        PORT (
            I1 : IN STD_LOGIC;
            O  : OUT STD_LOGIC
        );
    END COMPONENT ANDGATE;
BEGIN
    AND1 : ANDGATE
        PORT MAP (
            I1 => A,
            O  => B
        );
END RTL;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("half_adder");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_statement(make_instance("and1", "andgate"));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, fixture_regression) {
    // Mirrors the test data stored in Testing/check_files/test_vhdl_module.vhd,
    // which the repository walker and the analysis suite rely on.
    auto test_pattern = R"(
library ieee;
use IEEE.std_logic_1164.all;

entity half_adder is
  port (
    i_bit1  : in std_logic;
    i_bit2  : in std_logic;
    --
    o_sum   : out std_logic;
    o_carry : out std_logic
    );
end half_adder;

architecture rtl of half_adder is

    component ANDGATE is
      port (
        I1 : in std_logic;
        I2 : in std_logic;
        O  : out std_logic);
    end component ANDGATE;

begin
    o_sum   <= i_bit1 xor i_bit2;
    and_component : ANDGATE
    port map (
      I1  => i_bit1,
      I2  => i_bit2,
      O => o_carry
    );

end rtl;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("half_adder");
    golden.set_type(module);
    golden.set_line_n(5);
    golden.add_statement(make_instance("and_component", "andgate"));

    ASSERT_EQ(*res, golden);
}
