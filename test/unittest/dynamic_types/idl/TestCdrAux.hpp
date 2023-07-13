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
 * @file TestCdrAux.hpp
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

#include "Test.h"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {





size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const BasicStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.my_bool(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.my_octet(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.my_int16(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3), data.my_int32(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4), data.my_int64(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(5), data.my_uint16(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(6), data.my_uint32(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(7), data.my_uint64(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(8), data.my_float32(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(9), data.my_float64(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(10), data.my_float128(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(11), data.my_char(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(12), data.my_wchar(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(13), data.my_string(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(14), data.my_wstring(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}





size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const ComplexStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.my_octet(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.my_basic_struct(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.my_alias_enum(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3), data.my_enum(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4), data.my_sequence_octet(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(5), data.my_sequence_struct(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(6), data.my_array_octet(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(7), data.my_octet_array_500(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(8), data.my_array_struct(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(9), data.my_map_octet_short(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(10), data.my_map_long_struct(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(11), data.my_map_long_seq_octet(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(12), data.my_map_long_octet_array_500(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(13), data.my_map_long_lol_type(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(14), data.my_small_string_8(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(15), data.my_small_string_16(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(16), data.my_large_string_8(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(17), data.my_large_string_16(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(18), data.my_array_string(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(19), data.multi_alias_array_42(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(20), data.my_array_arrays(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(21), data.my_sequences_array(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const MyUnion& data,
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

    // TODO Member id del discriminador
    current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
            current_alignment);

    switch(data._d())
    {
                        case ::A:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.basic(), current_alignment);
                        break;
                
                        case ::B:
                        case ::C:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.complex(), current_alignment);
                        break;
                
    }

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const MyUnion2& data,
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

    // TODO Member id del discriminador
    current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
            current_alignment);

    switch(data._d())
    {
                        case A:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.uno(), current_alignment);
                        break;
                
                        case B:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.imString(), current_alignment);
                        break;
                
                        case C:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.tres(), current_alignment);
                        break;
                
    }

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const CompleteStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.my_union(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.my_union_2(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const KeyedStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.key(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.basic(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

} // namespace fastcdr
} // namespace eprosima