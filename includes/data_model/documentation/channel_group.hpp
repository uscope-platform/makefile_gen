// Copyright 2023 Filippo Savi
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


#ifndef MAKEFILEGEN_V2_CHANNEL_GROUP_HPP
#define MAKEFILEGEN_V2_CHANNEL_GROUP_HPP

#include <string>
#include <utility>
#include <vector>

#include <cereal/types/vector.hpp>

class channel_group {
public:
    channel_group() = default;
    channel_group(const channel_group &inst);


    void set_name(const std::string &s) {name = s;}
    std::string get_name() const{return name;};

    void set_default(const bool &d){is_default = d;};
    bool get_default() const {return is_default;};

    void set_channels(const std::vector<std::string> &c){channels = c;};
    std::vector<std::string> get_channels() const {return channels;};

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, is_default, channels);
    }

    friend bool operator==(const channel_group&lhs, const channel_group&rhs);
private:
    std::string name;
    bool is_default = false;
    std::vector<std::string> channels;
};


#endif //MAKEFILEGEN_V2_CHANNEL_GROUP_HPP
