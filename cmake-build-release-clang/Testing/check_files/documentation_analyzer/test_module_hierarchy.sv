// Copyright 2021 Filippo Savi
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.



module Decoder (
    input wire clock,
    input wire reset,
    axi_stream.slave data_in,
    axi_stream.master data_out
);

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


    /**
        {
            "name": "Decoder",
            "type": "module_hierarchy",
            "children": [
                {
                    "type": "SyndromeCalculator",
                    "instance": "SC",
                    "offset": "0",
                    "children":[]
                },
                {
                    "type": "SPI",
                    "instance": "COMM",
                    "offset": "0x40",
                    "children":[
                        {
                            "type": "SPI1",
                            "instance": "ext_in12terface",
                            "offset": "0x420",
                            "children":[]
                        }
                    ]
                }
            ]
        }
    **/
