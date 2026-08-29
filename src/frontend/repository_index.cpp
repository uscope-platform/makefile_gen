//  Copyright 2026 Filippo Savi
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

#include "frontend/repository_index.hpp"

void repository_index::add_file(const std::filesystem::path &file) {
    index[file.filename().string()].push_back(file);
}

std::vector<std::filesystem::path> repository_index::lookup(const std::string &name) const {
    std::filesystem::path name_path(name);
    std::string basename = name_path.filename().string();
    auto it = index.find(basename);
    if (it == index.end()) return {};
    bool has_subpath = name.find('/') != std::string::npos || name.find('\\') != std::string::npos;
    if (!has_subpath) return it->second;
    std::vector<std::filesystem::path> result;
    std::string normalized = name_path.generic_string();
    for (auto &p: it->second) {
        if (p.generic_string().ends_with(normalized)) result.push_back(p);
    }
    return result;
}