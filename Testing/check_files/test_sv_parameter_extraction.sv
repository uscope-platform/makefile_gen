`timescale 10 ns / 1 ns
`include "interfaces.svh"

module test_mod #(
    parameter simple_numeric_p = 32,
    sv_numeric_p = 5'o10,
    dimensionless_sv_numeric_p  = 'h3F,
    string_p = "423",
    nested_p = string_parameter
)();

    parameter add_expr_p = simple_numeric_parameter + sv_numeric_parameter;
    parameter sub_expr_p = simple_numeric_parameter - sv_numeric_parameter;
    parameter mul_expr_p = simple_numeric_parameter * sv_numeric_parameter;
    parameter div_expr_p = simple_numeric_parameter / sv_numeric_parameter;
    parameter modulo_expr_p = simple_numeric_parameter % sv_numeric_parameter;
    parameter log_expr_p = $clog2(add_expr_p);
    localparam local_p = 74;

endmodule
