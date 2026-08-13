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


#include "data_model/HDL/factories/parameters/streaming_factory.hpp"

void streaming_factory::start_streaming() {
    new_streaming = Streaming();
    factory_active = true;
}

void streaming_factory::set_direction(Streaming::stream_direction d) {
    new_streaming.set_direction(d);
}

void streaming_factory::set_slice_size(const std::shared_ptr<Expression_base> &s) {
    new_streaming.set_slice_size(s);
}

void streaming_factory::consume(const std::shared_ptr<Expression_base> &expr) {
    new_streaming.add_component(expr);
}

bool streaming_factory::active() const {
    return factory_active;
}

std::shared_ptr<Expression_base> streaming_factory::result() {
    return std::make_shared<Streaming>(new_streaming);
}
