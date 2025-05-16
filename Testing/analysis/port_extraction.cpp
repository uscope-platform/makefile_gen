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


#include <gtest/gtest.h>

#include "frontend/analysis/sv_analyzer.hpp"

TEST(port_extraction, regular_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in(buck_merged)
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("buck_merged")};

    ASSERT_EQ(ports, check_ports);
}

TEST(port_extraction, concat_port) {
std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({buck_merged, dab_merged})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("buck_merged"), HDL_net("dab_merged")};

    ASSERT_EQ(ports, check_ports);
}



TEST(port_extraction, array_range_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in(S_AXI_AWADDR[3+:1])
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("S_AXI_AWADDR")};
    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.set_expression_components({
        Expression_component("3"),
    });
    check_ports["stream_in"][0].array_range.set_type(expression_parameter);
    check_ports["stream_in"][0].array_range.set_expression_components({
    Expression_component("1"),
    });
    check_ports["stream_in"][0].range_type = HDL_net::increasing_range;
    ASSERT_EQ(ports, check_ports);
}



TEST(port_extraction, concat_range) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({S_AXI_AWADDR[N+:3],S_AXI_AWPROT[C-:1]})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("S_AXI_AWADDR"), HDL_net("S_AXI_AWPROT")};
    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.set_expression_components({
        Expression_component("N")
    });

    check_ports["stream_in"][0].array_range.set_type(expression_parameter);
    check_ports["stream_in"][0].array_range.set_expression_components({
    Expression_component("3")
    });
    check_ports["stream_in"][0].range_type = HDL_net::increasing_range;

    check_ports["stream_in"][1].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][1].array_accessor.set_expression_components({
        Expression_component("C")
    });

    check_ports["stream_in"][1].array_range.set_type(expression_parameter);
    check_ports["stream_in"][1].array_range.set_expression_components({Expression_component("1")});
    check_ports["stream_in"][1].range_type = HDL_net::decreasing_range;
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, concat_simple_slicing) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({m_wdata[N],m_wstrb[N]})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("m_wdata"), HDL_net("m_wstrb")};
    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.add_component(Expression_component("N"));
    check_ports["stream_in"][1].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][1].array_accessor.add_component(Expression_component("N"));
    ASSERT_EQ(ports, check_ports);
}



TEST(port_extraction, concat_complex_slicing) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({S_AXI_AWADDR[N*ADDR_WIDTH+:ADDR_WIDTH],S_AXI_AWPROT[N*3+:3]})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("S_AXI_AWADDR"), HDL_net("S_AXI_AWPROT")};
    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.set_expression_components({
        Expression_component("N"),
        Expression_component("*"),
        Expression_component("ADDR_WIDTH"),
    });

    check_ports["stream_in"][0].array_range.set_type(expression_parameter);
    check_ports["stream_in"][0].array_range.set_expression_components({Expression_component("ADDR_WIDTH")});
    check_ports["stream_in"][0].range_type = HDL_net::increasing_range;

    check_ports["stream_in"][1].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][1].array_accessor.set_expression_components({
        Expression_component("N"),
        Expression_component("*"),
        Expression_component("3")
    });

    check_ports["stream_in"][1].array_range.set_type(expression_parameter);
    check_ports["stream_in"][1].array_range.set_expression_components({Expression_component("3")});
    check_ports["stream_in"][1].range_type = HDL_net::increasing_range;
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, concat_interface_component) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({axil.WDATA,axil.WSTRB})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("axil.WDATA"), HDL_net("axil.WSTRB")};
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, repetition_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({5{1'b1}})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("")};
    check_ports["stream_in"][0].replication_size.set_type(expression_parameter);
    check_ports["stream_in"][0].replication_size.set_expression_components({
        Expression_component("5")
    });
    check_ports["stream_in"][0].replication_target.set_type(expression_parameter);
    check_ports["stream_in"][0].replication_target.set_expression_components({
        Expression_component("1'b1")
    });
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, complex_nested_concat_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({OUTPUT_SIGNED[data_in.dest],{DATA_PATH_WIDTH-1{1'b0}}, test})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("OUTPUT_SIGNED"), HDL_net(""), HDL_net("test")};

    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.set_expression_components({Expression_component("data_in.dest")});

    check_ports["stream_in"][1].replication_size.set_type(expression_parameter);
    check_ports["stream_in"][1].replication_size.set_expression_components({
        Expression_component("DATA_PATH_WIDTH"),
        Expression_component("-"),
        Expression_component("1")
    });
    check_ports["stream_in"][1].replication_target.set_type(expression_parameter);
    check_ports["stream_in"][1].replication_target.set_expression_components({
        Expression_component("1'b0")
    });
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, concat_literal) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({1'b0,test})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("1'b0"), HDL_net("test")};

    ASSERT_EQ(ports, check_ports);
}




TEST(port_extraction, array_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in(stream[5])
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["stream_in"] = {HDL_net("stream")};
    check_ports["stream_in"][0].array_accessor.set_type(expression_parameter);
    check_ports["stream_in"][0].array_accessor.add_component(Expression_component("5"));
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, port_extraction_with_declarations) {
    std::string test_pattern = R"(

        module test_mod #()();

        reg [31:0] memory [5:0];

        SyndromeCalculator #(
            .TEST_PARAM(test_package::param)
        ) SC (
            .clock(clock),
            .reset(reset),
            .data_in(data_in),
            .syndrome(data_out)
        );

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto res = analyzer.analyze()[0];
    auto inst = res.get_dependencies()[1];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["reset"] = {HDL_net("reset")};
    check_ports["data_in"] = {HDL_net("data_in")};
    check_ports["syndrome"] = {HDL_net("data_out")};
    ASSERT_EQ(ports, check_ports);
}

TEST(port_extraction, other_port_concat) {
    std::string test_pattern = R"(
        module test_mod #()();

        axil_crossbar_interface  axi_xbar (
            .clock(clock),
            .slaves('{axi_in}),
            .masters('{timebase_axi, gpio_axi, fcore_axi})
        );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["slaves"] = {HDL_net("axi_in")};
    check_ports["masters"] = {HDL_net("timebase_axi"), HDL_net("gpio_axi"), HDL_net("fcore_axi")};
    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, replication_with_parameter) {
    std::string test_pattern = R"(
        module test_mod #()();

            axil_crossbar_interface #(
                .DATA_WIDTH(32),
                .ADDR_WIDTH(32),
                .NM(1),
                .NS(2),
                .SLAVE_ADDR('{CONTROLLER_ADDRESS, SPI_ADDRESS}),
                .SLAVE_MASK('{2{32'h040}})
            ) axi_xbar (
                .clock(clock),
                .reset(reset),
                .slaves('{axi_in}),
                .masters('{controller_axi, spi_axi})
            );

        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<HDL_net>> check_ports;
    check_ports["clock"] = {HDL_net("clock")};
    check_ports["reset"] = {HDL_net("reset")};
    check_ports["slaves"] = {HDL_net("axi_in")};
    check_ports["masters"] = {HDL_net("controller_axi"), HDL_net("spi_axi")};
    ASSERT_EQ(ports, check_ports);
}

