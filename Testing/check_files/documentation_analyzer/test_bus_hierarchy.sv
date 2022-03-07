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


package test_package;


    parameter bus_base = 32'h43c00000;

    parameter timebase = 351;

    parameter gpio =  32'h1000;

    parameter delay_emulator = 168;
    /**
    {
        "name": "bus_base",
        "type": "bus_hierarchy",
        "target": "test_package",
        "children": [
            {
                "name": "timebase",
                "type": "crossbar",
                "children": [
                     {
                        "name": "gpio",
                        "type": "module",
                        "target": {
                                "type": "gpio",
                                "name": "general_ctrls"
                            }
                    }
                ]
            }
        ]
    }
    **/
endpackage