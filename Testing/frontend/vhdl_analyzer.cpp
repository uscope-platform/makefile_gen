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

#include <cmath>

#include "frontend/analysis/vhdl/vhdl_analyzer.hpp"
#include "data_model/HDL/statement/hdl_statements.hpp"
#include "data_model/HDL/parameters/HDL_parameter.hpp"
#include "data_model/HDL/types/HDL_simple_type.hpp"
#include "data_model/HDL/parameters/components/Expression_v2.hpp"
#include "data_model/HDL/parameters/components/Concatenation.hpp"
#include "data_model/HDL/parameters/components/Cast.hpp"
#include "data_model/HDL/parameters/components/token/Numeric_token.hpp"
#include "data_model/HDL/parameters/components/token/Real_token.hpp"
#include "data_model/HDL/parameters/components/token/Identifier_token.hpp"
#include "data_model/HDL/parameters/common/resolved_parameter.hpp"
#include "data_model/HDL/parameters/common/qualified_identifier.hpp"

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

std::shared_ptr<HDL_parameter> make_integer_param(const std::string &name,
                                                  const std::shared_ptr<Expression_base> &value) {
    auto p = std::make_shared<HDL_parameter>(name);
    auto t = std::make_shared<HDL_simple_type>();
    t->set_type_name("integer");
    t->set_signed(true);
    p->set_type(t);
    p->set_raw_value(value);
    return p;
}

std::shared_ptr<Expression_v2> make_binary(Expression_v2::expression_operator op,
                                           const std::shared_ptr<Expression_base> &lhs,
                                           const std::shared_ptr<Expression_base> &rhs) {
    auto e = std::make_shared<Expression_v2>();
    e->set_lhs(lhs);
    e->set_rhs(rhs);
    e->set_operation(op);
    return e;
}

int64_t eval_generic(const std::string &decl_body, const std::string &gname) {
    std::string pattern = "entity top is\n    generic ( " + decl_body + " );\nend top;\n";
    auto res = parse_first_entity(pattern);
    auto param = res->get_parameters().get(gname);
    if (!param) return -999999;
    std::map<qualified_identifier, resolved_parameter> ctx;
    auto val = param->evaluate(ctx);
    if (!val.has_value() || !val->is_integer()) return -999999;
    return val->get_integer().get_value();
}

// Build a golden integer parameter whose default value is a concatenation
// (VHDL aggregate) of the given numeric literals.
std::shared_ptr<HDL_parameter> make_concat_param(const std::string &name,
                                                 std::initializer_list<std::string> values) {
    auto concat = std::make_shared<Concatenation>();
    for (const auto &v : values)
        concat->add_component(std::make_shared<Numeric_token>(v));
    return make_integer_param(name, concat);
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

TEST(vhdl_analyzer, generic_numeric_single) {
    auto test_pattern = R"(
entity top is
    generic (
        N : integer := 8
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("n", std::make_shared<Numeric_token>("8")));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, generic_math_expression) {
    auto test_pattern = R"(
entity top is
    generic (
        WIDTH : integer := 2**N-1
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    // 2**N-1 parses as (2**N) - 1
    auto pow = make_binary(Expression_v2::power,
                           std::make_shared<Numeric_token>("2"),
                           std::make_shared<Identifier_token>(qualified_identifier("n")));
    auto expr = make_binary(Expression_v2::subtract, pow, std::make_shared<Numeric_token>("1"));

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("width", expr));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, generic_multiple_and_multiply) {
    auto test_pattern = R"(
entity top is
    generic (
        A : integer := 4;
        B : integer := A * 8
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    auto b_expr = make_binary(Expression_v2::multiply,
                              std::make_shared<Identifier_token>(qualified_identifier("a")),
                              std::make_shared<Numeric_token>("8"));

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("a", std::make_shared<Numeric_token>("4")));
    golden.add_parameter(make_integer_param("b", b_expr));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, generic_identifier_reference) {
    auto test_pattern = R"(
entity top is
    generic (
        WIDTH : integer := DATA_WIDTH
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("width",
        std::make_shared<Identifier_token>(qualified_identifier("data_width"))));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, generic_expression_evaluates) {
    auto test_pattern = R"(
entity top is
    generic ( WIDTH : integer := 2**N-1 );
end top;
)";

    auto res = parse_first_entity(test_pattern);
    auto param = res->get_parameters().get("width");
    ASSERT_NE(param, nullptr);

    std::map<qualified_identifier, resolved_parameter> ctx;
    ctx[qualified_identifier("n")] = resolved_parameter(8);

    auto val = param->evaluate(ctx);
    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val->is_integer());
    EXPECT_EQ(val->get_integer().get_value(), 255);
}

TEST(vhdl_analyzer, generic_range_subtype_not_polluted) {
    // The range constraint expressions in the subtype must not leak into the
    // default-value expression.
    auto test_pattern = R"(
entity top is
    generic (
        N : integer range 0 to 7 := 4
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);
    auto param = res->get_parameters().get("n");
    ASSERT_NE(param, nullptr);

    std::map<qualified_identifier, resolved_parameter> ctx;
    auto val = param->evaluate(ctx);
    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val->is_integer());
    EXPECT_EQ(val->get_integer().get_value(), 4);
}

TEST(vhdl_analyzer, generic_multiple_names_shared_default) {
    auto test_pattern = R"(
entity top is
    generic (
        A, B, C : integer := 8
    );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("a", std::make_shared<Numeric_token>("8")));
    golden.add_parameter(make_integer_param("b", std::make_shared<Numeric_token>("8")));
    golden.add_parameter(make_integer_param("c", std::make_shared<Numeric_token>("8")));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, literal_bit_string) {
    EXPECT_EQ(eval_generic("V : integer := x\"FF\"", "v"), 255);
    EXPECT_EQ(eval_generic("V : integer := b\"1010\"", "v"), 10);
    EXPECT_EQ(eval_generic("V : integer := o\"17\"", "v"), 15);
    EXPECT_EQ(eval_generic("V : integer := 8x\"1F\"", "v"), 31);
}

TEST(vhdl_analyzer, literal_signed_bit_string) {
    // 8 bits of 0xFF interpreted as two's-complement signed -> -1.
    EXPECT_EQ(eval_generic("V : integer := 8sx\"FF\"", "v"), -1);
}

TEST(vhdl_analyzer, literal_character) {
    // Character literal 'a' maps to its ASCII value.
    EXPECT_EQ(eval_generic("C : integer := 'a'", "c"), 97);
}

TEST(vhdl_analyzer, operator_mod_rem) {
    // VHDL `mod` is floor modulo: 7 mod -3 = -2 (sign of divisor).
    EXPECT_EQ(eval_generic("M : integer := 7 mod -3", "m"), -2);
    // VHDL `rem` is truncated: 7 rem -3 = 1 (sign of dividend).
    EXPECT_EQ(eval_generic("R : integer := 7 rem -3", "r"), 1);
}

TEST(vhdl_analyzer, operator_rotate) {
    // Rotate operates on the default 32-bit container width, so small left
    // rotates are just left shifts: 6 rol 1 = 12.
    EXPECT_EQ(eval_generic("L : integer := 6 rol 1", "l"), 12);
    // Rotating right by 31 on a 32-bit container equals rotating left by 1:
    // 1 ror 31 = 2.
    EXPECT_EQ(eval_generic("R : integer := 1 ror 31", "r"), 2);
}

TEST(vhdl_analyzer, operator_condition_qq) {
    // VHDL `??` condition operator normalizes a condition to 0/1.
    // Note: `??` is a trigraph in C++, so the literal is split.
    EXPECT_EQ(eval_generic("V : integer := ?" "?5", "v"), 1);
    EXPECT_EQ(eval_generic("V : integer := ?" "?0", "v"), 0);
    EXPECT_EQ(eval_generic("V : integer := ?" "?(1<2)", "v"), 1);
}

TEST(vhdl_analyzer, aggregate_positional) {
    auto test_pattern = R"(
entity top is
    generic ( V : integer := (1, 2, 3) );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_concat_param("v", {"1", "2", "3"}));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, aggregate_with_choices) {
    auto test_pattern = R"(
entity top is
    generic ( V : integer := (0 => 7, 1 => 8) );
end top;
)";

    auto res = parse_first_entity(test_pattern);

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_concat_param("v", {"7", "8"}));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, aggregate_not_confused_with_parenthesized_expr) {
    // `(1<2)` is a parenthesized relational expression, not a single-element
    // aggregate; `??` of it must normalize the boolean to 1.
    EXPECT_EQ(eval_generic("V : integer := ?" "?(1<2)", "v"), 1);
    // A plain parenthesized expression is just the expression value.
    EXPECT_EQ(eval_generic("V : integer := (3)", "v"), 3);
}

double eval_generic_double(const std::string &decl_body, const std::string &gname) {
    std::string pattern = "entity top is\n    generic ( " + decl_body + " );\nend top;\n";
    auto res = parse_first_entity(pattern);
    auto param = res->get_parameters().get(gname);
    if (!param) return -999999.0;
    std::map<qualified_identifier, resolved_parameter> ctx;
    auto val = param->evaluate(ctx);
    if (!val.has_value()) return -999999.0;
    if (val->is_real()) return val->get_real();
    if (val->is_integer()) return static_cast<double>(val->get_integer().get_value());
    return -999999.0;
}

TEST(vhdl_analyzer, builtin_function_integer) {
    EXPECT_EQ(eval_generic("V : integer := ceil(3)", "v"), 3);
    EXPECT_EQ(eval_generic("V : integer := floor(3)", "v"), 3);
    EXPECT_EQ(eval_generic("V : integer := minimum(3, 7)", "v"), 3);
    EXPECT_EQ(eval_generic("V : integer := maximum(3, 7)", "v"), 7);
    EXPECT_EQ(eval_generic("V : integer := countones(7)", "v"), 3);
}

TEST(vhdl_analyzer, builtin_function_real) {
    EXPECT_EQ(eval_generic_double("V : real := log2(8)", "v"), std::log2(8));
    EXPECT_EQ(eval_generic_double("V : real := sqrt(16)", "v"), 4.0);
    EXPECT_EQ(eval_generic_double("V : real := ceil(2.5)", "v"), 3.0);
    EXPECT_EQ(eval_generic_double("V : real := floor(2.5)", "v"), 2.0);
}

TEST(vhdl_analyzer, builtin_function_nested) {
    // ceil(log2(N)) evaluates with N from the context.
    auto test_pattern = R"(
entity top is
    generic ( N : integer := 8;
              W : real := ceil(log2(N)) );
end top;
)";
    auto res = parse_first_entity(test_pattern);
    auto param = res->get_parameters().get("w");
    ASSERT_NE(param, nullptr);
    std::map<qualified_identifier, resolved_parameter> ctx;
    ctx[qualified_identifier("n")] = resolved_parameter(8);
    auto val = param->evaluate(ctx);
    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val->is_real());
    EXPECT_EQ(val->get_real(), 3.0);
}

TEST(vhdl_analyzer, builtin_function_unknown_does_not_crash) {
    auto res = parse_first_entity("entity top is\n    generic ( V : integer := foo(3) );\nend top;\n");
    auto param = res->get_parameters().get("v");
    ASSERT_NE(param, nullptr);
}

TEST(vhdl_analyzer, qualified_expression_cast) {
    // `integer'(...)`/`natural'(...)` convert to an integer (real→int rounds).
    EXPECT_EQ(eval_generic("V : integer := integer'(5)", "v"), 5);
    EXPECT_EQ(eval_generic("V : integer := natural'(2)", "v"), 2);
    // `real'(...)` converts to real.
    EXPECT_EQ(eval_generic_double("V : real := real'(5)", "v"), 5.0);
    EXPECT_EQ(eval_generic_double("V : real := real'(2.5)", "v"), 2.5);
    // `boolean'(...)` normalizes to 0/1.
    EXPECT_EQ(eval_generic("V : integer := boolean'(0)", "v"), 0);
    EXPECT_EQ(eval_generic("V : integer := boolean'(3)", "v"), 1);
}

TEST(vhdl_analyzer, qualified_expression_cast_golden) {
    auto test_pattern = R"(
entity top is
    generic ( V : integer := integer'(7) );
end top;
)";
    auto res = parse_first_entity(test_pattern);

    auto cast = std::make_shared<Cast>();
    cast->set_type_cast();
    cast->set_target_type("integer");
    cast->set_content(std::make_shared<Numeric_token>("7"));

    hdl_resource_statement golden;
    golden.set_name("top");
    golden.set_type(module);
    golden.set_line_n(2);
    golden.add_parameter(make_integer_param("v", cast));

    ASSERT_EQ(*res, golden);
}

TEST(vhdl_analyzer, cast_transforms_value) {
    // real -> integer rounds.
    EXPECT_EQ(eval_generic("V : integer := integer'(2.9)", "v"), 3);
    EXPECT_EQ(eval_generic("V : integer := integer'(2.2)", "v"), 2);
    // integer -> real widens the representation.
    EXPECT_EQ(eval_generic_double("V : real := real'(7)", "v"), 7.0);
    // boolean'(non-zero) -> 1 collapses to a 1-bit truth value.
    EXPECT_EQ(eval_generic("V : integer := boolean'(5)", "v"), 1);
}

namespace {
    // Parse a generic default and return the resolved type of the parameter.
    std::shared_ptr<hdl_type> generic_type(const std::string &decl_body, const std::string &gname) {
        std::string pattern = "entity top is\n    generic ( " + decl_body + " );\nend top;\n";
        auto res = parse_first_entity(pattern);
        auto param = res->get_parameters().get(gname);
        if (!param) return nullptr;
        return param->get_type();
    }

    dimension_t make_packed_dim(const std::string &first, const std::string &second) {
        dimension_t d;
        d.first_bound = std::make_shared<Numeric_token>(first);
        d.second_bound = std::make_shared<Numeric_token>(second);
        d.packed = true;
        return d;
    }

    // Golden HDL_simple_type check object.
    HDL_simple_type make_simple_type(const std::string &name, bool is_signed, bool is_real,
                                     std::vector<dimension_t> packed = {}) {
        HDL_simple_type t;
        t.set_type_name(name);
        t.set_signed(is_signed);
        t.set_real(is_real);
        t.set_packed_dimensions(packed);
        return t;
    }
}

TEST(vhdl_analyzer, type_vector_range) {
    ASSERT_EQ(generic_type("V : std_logic_vector(7 downto 0)", "v")->as<HDL_simple_type>(),
        make_simple_type("std_logic_vector", false, false, {make_packed_dim("7", "0")}));
    ASSERT_EQ(generic_type("W : std_logic_vector(31 downto 0)", "w")->as<HDL_simple_type>(),
        make_simple_type("std_logic_vector", false, false, {make_packed_dim("31", "0")}));
    ASSERT_EQ(generic_type("U : unsigned(3 downto 0)", "u")->as<HDL_simple_type>(),
        make_simple_type("unsigned", false, false, {make_packed_dim("3", "0")}));
    ASSERT_EQ(generic_type("S : signed(7 downto 0)", "s")->as<HDL_simple_type>(),
        make_simple_type("signed", true, false, {make_packed_dim("7", "0")}));
}

TEST(vhdl_analyzer, type_ascending_range) {
    // `0 to 7` ascending produces the same width as `7 downto 0`.
    ASSERT_EQ(generic_type("V : std_logic_vector(0 to 7)", "v")->as<HDL_simple_type>(),
        make_simple_type("std_logic_vector", false, false, {make_packed_dim("0", "7")}));
}

TEST(vhdl_analyzer, type_scalar_builtins) {
    ASSERT_EQ(generic_type("N : integer", "n")->as<HDL_simple_type>(),
        make_simple_type("integer", true, false));
    ASSERT_EQ(generic_type("X : real", "x")->as<HDL_simple_type>(),
        make_simple_type("real", false, true));
    ASSERT_EQ(generic_type("B : std_logic", "b")->as<HDL_simple_type>(),
        make_simple_type("std_logic", false, false));
}

TEST(vhdl_analyzer, type_compound_range_bound) {
    // A symbolic/compound bound like (N-1) downto 0 builds an expression bound.
    auto test_pattern = R"(
entity top is
    generic ( N : integer := 8;
              V : std_logic_vector(N-1 downto 0) );
end top;
)";
    auto res = parse_first_entity(test_pattern);
    auto param = res->get_parameters().get("v");
    ASSERT_NE(param, nullptr);

    auto bound = make_binary(Expression_v2::subtract,
                             std::make_shared<Identifier_token>(qualified_identifier("n")),
                             std::make_shared<Numeric_token>("1"));
    dimension_t dim;
    dim.first_bound = bound;
    dim.second_bound = std::make_shared<Numeric_token>("0");
    dim.packed = true;
    ASSERT_EQ(param->get_type()->as<HDL_simple_type>(),
        make_simple_type("std_logic_vector", false, false, {dim}));
}
