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

#ifndef ANANKE_INCLUDE_DEPENDENCY_HPP
#define ANANKE_INCLUDE_DEPENDENCY_HPP

#include <cstdint>
#include <string>

// How an `include target was resolved.
enum class include_resolution : uint8_t {
    regular,         // relative to the including file or an explicit include directory
    auto_discovered  // located through the repository index fallback
};

struct include_dependency {
    std::string path;
    include_resolution resolution;

    template<class Archive> void serialize(Archive & ar) {
        ar(path, resolution);
    }

    bool operator==(const include_dependency &other) const = default;
    bool operator<(const include_dependency &other) const { return path < other.path; }
};

#endif //ANANKE_INCLUDE_DEPENDENCY_HPP