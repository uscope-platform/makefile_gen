//  Copyright 2025 Filippo Savi
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

#ifndef MAKEFILEGEN_V2_BACKEND_TYPES_HPP
#define MAKEFILEGEN_V2_BACKEND_TYPES_HPP

#include <map>
#include <string>
#include <vector>
#include <unordered_set>

struct script_source {
    std::string path;
    std::map<std::string, std::string> variables;

    bool operator==(const script_source& other) const {
        return path == other.path && variables == other.variables;
    }
};

struct project_data {
    std::string name;
    std::string base_dir;
    std::vector<std::string> commons_dir;
    std::vector<std::string> synth_sources;
    std::vector<std::string> sim_sources;
    std::string synth_tl;
    std::string board_part;
    std::string tb_tl;
    std::unordered_set<std::string> constraints_sources;
    std::vector<script_source> scripts;
};

#endif //MAKEFILEGEN_V2_BACKEND_TYPES_HPP