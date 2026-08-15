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


#include "data_model/mm_file.hpp"


mm_file::mm_file(const std::string &file) {
    fd = open(file.c_str(), O_RDONLY);
    if (fd == -1) {
        return;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        close(fd);
        fd = -1;
        return;
    }
    file_size = sb.st_size;

    if (file_size == 0) {
        addr = nullptr;
        return;
    }
    addr = mmap(nullptr, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        close(fd);
        fd = -1;
        addr = MAP_FAILED;
        return;
    }
}

std::optional<mm_file> mm_file::try_open(const std::string &file) {
    mm_file f(file);
    if (!f.is_valid()) return std::nullopt;
    return f;
}

mm_file::mm_file(mm_file &&other) noexcept
    : fd(other.fd), file_size(other.file_size), addr(other.addr) {
    other.fd = -1;
    other.file_size = 0;
    other.addr = MAP_FAILED;
}

mm_file& mm_file::operator=(mm_file &&other) noexcept {
    if (this != &other) {
        if (addr != nullptr && addr != MAP_FAILED) munmap(addr, file_size);
        if (fd != -1) close(fd);
        fd = other.fd;
        file_size = other.file_size;
        addr = other.addr;
        other.fd = -1;
        other.file_size = 0;
        other.addr = MAP_FAILED;
    }
    return *this;
}

mm_file::~mm_file() {
    if (addr != nullptr && addr != MAP_FAILED) munmap(addr, file_size);
    if (fd != -1) close(fd);
}

std::string_view mm_file::view() {
    if (fd == -1 || addr == nullptr) return "";
    return {static_cast<const char*>(addr), file_size};
}
