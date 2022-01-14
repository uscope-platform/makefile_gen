// Copyright 2022 Filippo Savi
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

#include "data_model/DataFile.h"



DataFile::DataFile(const std::string& ser) {
    std::istringstream stream(ser);
    std::vector<std::string> tokens;
    std::string tmp;
    tokens.reserve(2);
    while(std::getline(stream, tmp, ',')) {
        tokens.push_back(tmp);
    }
    name = std::string(tokens[0]);
    path = std::string(tokens[1]);
}

DataFile::DataFile(std::string n, std::string p ) {
    name = std::move(n);
    path = std::move(p);
}

void DataFile::set_path(std::string p) {
 path = std::move(p);
}

std::string DataFile::get_path() {
    return path;
}

std::string DataFile::get_name() {
    return name;
}

DataFile::operator std::string() {
    std::ostringstream ret_val;
    ret_val << name << "," << path;

    return ret_val.str();
}

bool operator==(const DataFile &lhs, const DataFile &rhs) {
    bool ret_val = true;
    ret_val &= lhs.path == rhs.path;
    ret_val &= lhs.name == rhs.name;
    return  ret_val;
}