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


#ifndef MAKEFILEGEN_V2_PROCESSOR_INSTANCE_HPP
#define MAKEFILEGEN_V2_PROCESSOR_INSTANCE_HPP

#include <string>
#include <utility>
#include <vector>

#include "third_party/cereal/types/vector.hpp"

typedef enum {
  input=1,
  output=2,
  memory=3
} io_type;

class io {
public:
    std::string name;
    io_type type;
    uint32_t address;

    std::string get_type() const;

    friend bool operator==(const io&lhs, const io&rhs);

    template <class Archive>
    void serialize( Archive & ar )
    {
        ar( name, type, address);
    }
} ;

class processor_instance {
public:
    processor_instance() = default;
    void set_name(const std::string &s) {name = s;}
    processor_instance(const processor_instance &inst);
    explicit processor_instance(const std::string &name);

    void add_io(const io &i);
    void set_target(std::string t) {target = std::move(t);}

    void set_address(std::string a) {address = a;};
    std::string get_address() {return address;};

    template<class Archive>
    void serialize(Archive & archive) {
        archive(name, dma_io, target, address);
    }

    std::string get_name() {return name;};
    std::string get_target() {return target;};
    std::vector<io> get_dma_io() {return dma_io;};

    friend bool operator==(const processor_instance&lhs, const processor_instance&rhs);
private:
    std::vector<io> dma_io;
    std::string target;
    std::string address;
    std::string name;
};


#endif //MAKEFILEGEN_V2_PROCESSOR_INSTANCE_HPP
