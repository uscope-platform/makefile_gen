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

#ifndef ANANKE_REPOSITORY_INDEX_HPP
#define ANANKE_REPOSITORY_INDEX_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>

class repository_index {
public:
    void add_file(const std::filesystem::path &file);
    std::vector<std::filesystem::path> lookup(const std::string &name) const;
    [[nodiscard]] bool empty() const { return index.empty(); }
private:
    std::unordered_map<std::string, std::vector<std::filesystem::path>> index;
};


#endif //ANANKE_REPOSITORY_INDEX_HPP