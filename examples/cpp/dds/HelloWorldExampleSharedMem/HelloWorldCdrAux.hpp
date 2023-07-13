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
 * @file HelloWorldCdrAux.hpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "HelloWorld.h"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const HelloWorld& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.index(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.message(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.data(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

} // namespace fastcdr
} // namespace eprosima