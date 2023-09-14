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
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"buck_merged", "dab_merged"};

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
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"m_wdata[N]", "m_wstrb[N]"};

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
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"S_AXI_AWADDR[N*ADDR_WIDTH+:ADDR_WIDTH]", "S_AXI_AWPROT[N*3+:3]"};

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
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"axil.WDATA", "axil.WSTRB"};

    ASSERT_EQ(ports, check_ports);
}


TEST(port_extraction, nested_concat_port) {
    std::string test_pattern = R"(
        module test_mod #()();

            axi_stream_combiner #(
            ) scope_combinator (
                .clock(clock),
                .stream_in({OUTPUT_SIGNED[data_in.dest],{DATA_PATH_WIDTH-1{1'b0}}})
            );
        endmodule
    )";

    sv_analyzer analyzer(std::make_shared<std::istringstream>(test_pattern));
    analyzer.cleanup_content("`(.*)");
    auto inst = analyzer.analyze()[0].get_dependencies()[0];
    auto ports = inst.get_ports();
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"OUTPUT_SIGNED[data_in.dest]", "{DATA_PATH_WIDTH-1{1'b0}}"};

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
    std::unordered_map<std::string, std::vector<std::string>> check_ports;
    check_ports["clock"] = {"clock"};
    check_ports["stream_in"] = {"1'b0", "test"};

    ASSERT_EQ(ports, check_ports);
}




