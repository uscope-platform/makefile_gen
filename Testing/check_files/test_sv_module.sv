`timescale 10 ns / 1 ns
`include "interfaces.svh"

module Decoder (
    input wire clock,
    input wire reset,
    axi_stream.slave data_in,
    axi_stream.master data_out
);


    SyndromeCalculator SC (
        .clock(clock),
        .reset(reset),
        .data_in(data_in),
        .syndrome(data_out)
    );

endmodule