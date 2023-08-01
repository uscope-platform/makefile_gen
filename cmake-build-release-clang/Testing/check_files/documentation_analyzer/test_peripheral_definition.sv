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


endmodule

    /**
       {
        "name": "Decoder",
        "type": "peripheral",
        "registers":[
            {
                "name": "simple_register_r",
                "offset": "0x0",
                "description": "Single word read only register",
                "direction": "R"
            },
            {
                "name": "simple_register_w",
                "offset": "4",
                "description": "Single word write only register",
                "direction": "W"
            },
            {
                "name": "field_registers",
                "offset": "0x20",
                "description": "register with multiple fields",
                "direction": "RW",
                "fields": [
                    {
                        "name":"field_1",
                        "description": "First field",
                        "start_position": 0,
                        "length": 8
                    },
                    {
                        "name":"field_2",
                        "description": "Second Field",
                        "start_position": 8,
                        "length": 8
                    }
                ]
            }
        ]
       }
    **/
