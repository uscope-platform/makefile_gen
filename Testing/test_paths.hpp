// Copyright 2026 Filippo Savi
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

#ifndef ANANKE_TEST_PATHS_HPP
#define ANANKE_TEST_PATHS_HPP

#include <filesystem>
#include <string>

#ifndef TEST_DATA_DIR
#define TEST_DATA_DIR "."
#endif

// Root of the test data directory. Set at configure time by
// -DTEST_DATA_DIR=<build>/Testing so that the test suite is independent of
// the working directory it is launched from.
inline std::filesystem::path td_root() {
    return std::filesystem::absolute(TEST_DATA_DIR);
}

inline std::string td_file(const std::string &relative) {
    return (td_root() / relative).string();
}

inline std::filesystem::path td_path(const std::string &relative) {
    return td_root() / relative;
}

// Replace the relative "check_files/test_data/" occurrences embedded in
// expected-output strings with the absolute fixture root, so that generated
// scripts (which echo source file paths verbatim) can be compared regardless
// of the working directory the suite runs from.
inline std::string td_absolutize(std::string text) {
    const std::string needle = "check_files/test_data/";
    const std::string replacement = td_file("check_files/test_data/");
    size_t pos = 0;
    while ((pos = text.find(needle, pos)) != std::string::npos) {
        text.replace(pos, needle.size(), replacement);
        pos += replacement.size();
    }
    return text;
}

#endif
