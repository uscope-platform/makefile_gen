

//  Copyright  2026 University of Nottingham
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

#ifndef ANANKE_SOLVER_ERRORS_HPP
#define ANANKE_SOLVER_ERRORS_HPP
enum solver_errors {
    missing_value,
    wrong_type,
    empty_body,
    missing_arguments,
    unsupported
};

inline const char* solver_error_name(solver_errors e) {
    switch (e) {
        case missing_value: return "missing value";
        case wrong_type: return "wrong type";
        case empty_body: return "empty body";
        case missing_arguments: return "missing arguments";
        case unsupported: return "unsupported construct";
    }
    return "unknown error";
}
#endif //ANANKE_SOLVER_ERRORS_HPP
