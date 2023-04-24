// Copyright 2021 Filippo Savi
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


#ifndef MAKEFILEGEN_V2_BUS_COMPONENT_HPP
#define MAKEFILEGEN_V2_BUS_COMPONENT_HPP

#include <string>
#include <utility>
#include <memory>

#include <cereal/types/polymorphic.hpp>
#include <cereal/types/base_class.hpp>



class bus_component {
public:
    bus_component() = default;
    virtual ~bus_component() = default; // virtual destructor to make class polymorphic
    static bool compare(std::shared_ptr<bus_component> &lhs, std::shared_ptr<bus_component> &rhs);
    static bool compare(const std::shared_ptr<bus_component> &lhs, const std::shared_ptr<bus_component> &rhs);

    template <class Archive>
    void serialize( Archive & ar )
    {
        ar( cereal::base_class<bus_component>(this));
    }
};


#endif //MAKEFILEGEN_V2_BUS_COMPONENT_HPP
