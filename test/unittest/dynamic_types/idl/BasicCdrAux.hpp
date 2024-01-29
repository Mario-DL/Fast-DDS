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
 * @file BasicCdrAux.hpp
 * This source file contains some definitions of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_BASICCDRAUX_HPP_
#define _FAST_DDS_GENERATED_BASICCDRAUX_HPP_

#include "Basic.hpp"

constexpr uint32_t ArraytStruct_max_cdr_typesize {36UL};
constexpr uint32_t ArraytStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t SimpleUnionStruct_max_cdr_typesize {24UL};
constexpr uint32_t SimpleUnionStruct_max_key_cdr_typesize {0UL};


constexpr uint32_t WCharUnionStruct_max_cdr_typesize {24UL};
constexpr uint32_t WCharUnionStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t OctetStruct_max_cdr_typesize {5UL};
constexpr uint32_t OctetStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t LongStruct_max_cdr_typesize {8UL};
constexpr uint32_t LongStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t EnumStruct_max_cdr_typesize {8UL};
constexpr uint32_t EnumStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t BitsetStruct_max_cdr_typesize {8UL};
constexpr uint32_t BitsetStruct_max_key_cdr_typesize {0UL};



constexpr uint32_t DoubleStruct_max_cdr_typesize {16UL};
constexpr uint32_t DoubleStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t LargeWStringStruct_max_cdr_typesize {83858UL};
constexpr uint32_t LargeWStringStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t WCharStruct_max_cdr_typesize {6UL};
constexpr uint32_t WCharStruct_max_key_cdr_typesize {0UL};


constexpr uint32_t WStringStruct_max_cdr_typesize {518UL};
constexpr uint32_t WStringStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t SequenceStruct_max_cdr_typesize {16UL};
constexpr uint32_t SequenceStruct_max_key_cdr_typesize {0UL};


constexpr uint32_t ULongStruct_max_cdr_typesize {8UL};
constexpr uint32_t ULongStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t SequenceSequenceStruct_max_cdr_typesize {48UL};
constexpr uint32_t SequenceSequenceStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t FloatStruct_max_cdr_typesize {8UL};
constexpr uint32_t FloatStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t LongDoubleStruct_max_cdr_typesize {24UL};
constexpr uint32_t LongDoubleStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t StructStructStruct_max_cdr_typesize {32UL};
constexpr uint32_t StructStructStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t UnionUnionUnionStruct_max_cdr_typesize {32UL};
constexpr uint32_t UnionUnionUnionStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t BoolStruct_max_cdr_typesize {5UL};
constexpr uint32_t BoolStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t MapMapStruct_max_cdr_typesize {60UL};
constexpr uint32_t MapMapStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t AliasAliasStruct_max_cdr_typesize {8UL};
constexpr uint32_t AliasAliasStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t ArrayArrayStruct_max_cdr_typesize {72UL};
constexpr uint32_t ArrayArrayStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t ShortStruct_max_cdr_typesize {6UL};
constexpr uint32_t ShortStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t MapStruct_max_cdr_typesize {24UL};
constexpr uint32_t MapStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t UShortStruct_max_cdr_typesize {6UL};
constexpr uint32_t UShortStruct_max_key_cdr_typesize {0UL};



constexpr uint32_t ULongLongStruct_max_cdr_typesize {16UL};
constexpr uint32_t ULongLongStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t AliasStruct_max_cdr_typesize {8UL};
constexpr uint32_t AliasStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t LargeStringStruct_max_cdr_typesize {41934UL};
constexpr uint32_t LargeStringStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t CharStruct_max_cdr_typesize {5UL};
constexpr uint32_t CharStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t LongLongStruct_max_cdr_typesize {16UL};
constexpr uint32_t LongLongStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t StringStruct_max_cdr_typesize {264UL};
constexpr uint32_t StringStruct_max_key_cdr_typesize {0UL};

constexpr uint32_t StructStruct_max_cdr_typesize {16UL};
constexpr uint32_t StructStruct_max_key_cdr_typesize {0UL};



namespace eprosima {
namespace fastcdr {

class Cdr;
class CdrSizeCalculator;

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const EnumStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AliasStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AliasAliasStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const BoolStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const OctetStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ShortStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const LongStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const LongLongStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const UShortStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ULongStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ULongLongStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const FloatStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const DoubleStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const LongDoubleStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const CharStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const WCharStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const StringStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const WStringStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const LargeStringStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const LargeWStringStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ArraytStruct& data);


eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const ArrayArrayStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const SequenceStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const SequenceSequenceStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const MapStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const MapMapStruct& data);


eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const BitsetStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const StructStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const StructStructStruct& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const SimpleUnionStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const UnionUnionUnionStruct& data);

eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const WCharUnionStruct& data);


} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_BASICCDRAUX_HPP_

