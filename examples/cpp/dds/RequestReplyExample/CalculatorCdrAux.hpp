// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file CalculatorCdrAux.hpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_CALCULATORCDRAUX_HPP_
#define _FAST_DDS_GENERATED_CALCULATORCDRAUX_HPP_

#include "Calculator.h"


            constexpr uint32_t ReplyType_max_cdr_typesize {16UL};
            constexpr uint32_t ReplyType_max_key_cdr_typesize {0UL};

            constexpr uint32_t RequestType_max_cdr_typesize {16UL};
            constexpr uint32_t RequestType_max_key_cdr_typesize {0UL};

namespace eprosima {
namespace fastcdr {

class Cdr;
class CdrSizeCalculator;


eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const RequestType& data,
        size_t current_alignment);
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const RequestType& data);

eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        RequestType& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const RequestType& data);

eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const ReplyType& data,
        size_t current_alignment);
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const ReplyType& data);

eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        ReplyType& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ReplyType& data);


} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_CALCULATORCDRAUX_HPP_