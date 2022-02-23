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


`define MKF_GEN_ANALYZE_BUS

package test_package;

    /**
        {
            "name": "bus_base",
            "type": "package_parameter",
            "class": "bus_root",
            "children": [
                "timebase", "gpio", "fcore",
                "uscope", "sensor", "speed",
                "rtcu", "delay_emulator"
            ]
        }
    **/
    parameter bus_base = 32'h43c00000;

    /**
        {
            "name": "timebase",
            "type": "package_parameter",
            "class": "crossbar",
            "children": [
                "current_timebase",
                "angle_timebase",
                "speed_timebase"
            ]
        }
    **/
    parameter timebase = bus_base;

    /**
        {
            "name": "gpio",
            "type": "package_parameter",
            "class": "module",
            "target": {
                    "module_type": "gpio",
                    "instance_name": "general_ctrls"
                }
        }
    **/
    parameter gpio = timebase + 32'h1000 * 2 / 2 + 1;

    /**
        {
            "name": "scope_mux",
            "type": "package_parameter",
            "class": "registers",
            "target": "SicDriveMasterScope"
        }
    **/
    parameter scope_mux = gpio;

    /**
        {
            "name": "modulo_parameter",
            "type": "package_parameter",
            "class": "registers",
            "target": "SicDriveMasterScope"
        }
    **/
    parameter modulo_parameter = 3 % 2;

    /**
        {
            "name": "subtraction_parameter",
            "type": "package_parameter",
            "class": "registers",
            "target": "SicDriveMasterScope"
        }
    **/
    parameter subtraction_parameter = 'o4 - 'b10;

endpackage