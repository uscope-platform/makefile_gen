`timescale 10 ns / 1 ns
`include "interfaces.svh"

module Decoder (
    input wire clock,
    input wire reset,
    axi_stream.slave data_in,
    axi_stream.master data_out
);

    parameter module_parameter_1 = 56;
    localparam module_parameter_2 = 74;

    reg [31:0] memory [5:0];
    initial memory = $readmemh("mem/init/file.dat");

    SyndromeCalculator #(
        .TEST_PARAM(test_package::param)
    ) SC (
        .clock(clock),
        .reset(reset),
        .data_in(data_in),
        .syndrome(data_out)
    );

endmodule


interface test_if;

    logic signal_1;
    logic signal_2;
endinterface