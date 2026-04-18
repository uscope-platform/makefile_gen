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

#ifndef MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP
#define MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP

#include <ctre.hpp>
#include <filesystem>
#include <fstream>

class sv_preprocessor {
public:
    sv_preprocessor(const std::filesystem::path &in);
    std::string preprocess(const std::filesystem::path &in);
    std::string preprocess(std::istream& in);
private:
    std::string path;
};



#endif //MAKEFILEGEN_V2_SV_PREPROCESSOR_HPP
