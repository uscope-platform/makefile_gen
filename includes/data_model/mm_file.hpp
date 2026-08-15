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


#ifndef ANANKE_MM_FILE_HPP
#define ANANKE_MM_FILE_HPP

#include <string>
#include <optional>
#include <string_view>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

class mm_file {
public:
    static std::optional<mm_file> try_open(const std::string &file);
    explicit mm_file(const std::string &file);
    ~mm_file();
    mm_file(const mm_file&) = delete;
    mm_file& operator=(const mm_file&) = delete;
    mm_file(mm_file &&other) noexcept;
    mm_file& operator=(mm_file &&other) noexcept;

    [[nodiscard]] bool is_valid() const { return fd != -1; }
    std::string_view view();
private:
    int fd = -1;
    size_t file_size = 0;
    void* addr = MAP_FAILED;
};


#endif //ANANKE_MM_FILE_HPP
