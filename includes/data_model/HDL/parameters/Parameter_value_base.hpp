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

#ifndef MAKEFILEGEN_V2_PARAMETER_VALUE_BASE_HPP
#define MAKEFILEGEN_V2_PARAMETER_VALUE_BASE_HPP



class Parameter_value_base {
public:
    enum param_value_type {
        concatenation,
        expression,
        replication
    };

    virtual ~Parameter_value_base() = default;

    virtual std::set<qualified_identifier> get_dependencies()const {return {};}
    virtual bool propagate_constant(const qualified_identifier &constant_id, const resolved_parameter &value) {return true;}
    virtual std::optional<resolved_parameter> evaluate(bool pack_result) {return std::nullopt;}
    virtual std::string print() const {return "";}
    virtual int64_t get_size() {return 0;}

    virtual int64_t get_depth() {return 0;}

    bool empty() const {return false;}

    bool is_expression(){return type == expression;}
    bool is_replication(){return type == replication;}
    bool is_concatenation(){return type == concatenation;}

    virtual std::shared_ptr<Parameter_value_base> clone_ptr() const = 0;

    template<typename T>
        T& as() { return static_cast<T&>(*this); }

    template<class Archive>
    void serialize( Archive & ar ) {
        ar(type);
    }
    // Public equality operator using the enum discriminator
    bool operator==(const Parameter_value_base& other) const {
        // Use your existing member variable instead of RTTI
        if (this->type != other.type) return false;

        // Delegate to the virtual implementation
        return isEqual(other);
    }

protected:
    param_value_type type = expression;
    virtual bool isEqual(const Parameter_value_base& other) const = 0;
};


#endif //MAKEFILEGEN_V2_PARAMETER_VALUE_BASE_HPP