// Copyright 2023 Filippo Savi
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

module SicDriveMasterCurrentControl (
    input wire clock,
    input wire reset
);


    fCore processor (
        .clock(clock),
        .reset(reset)
    );

endmodule

    /**
        {
            "name": "current_controller",
            "type": "processor_instance",
            "target": "processor",
            "parent": "SicDriveMasterCurrentControl",
            "dma_io": [
                {
                    "name": "Current",
                    "type": "input",
                    "address": "1"
                },
                {
                    "name": "Speed",
                    "type": "input",
                    "address": "2"
                },
                {
                    "name": "duty",
                    "type": "output",
                    "address": "15"
                }
            ]
        }
    **/

