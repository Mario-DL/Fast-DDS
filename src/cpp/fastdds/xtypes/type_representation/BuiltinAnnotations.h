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
 * @file BuiltinAnnotations.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_BUILTINANNOTATIONS_H_
#define _FAST_DDS_GENERATED_BUILTINANNOTATIONS_H_

#include <array>
#include <bitset>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>



#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(BUILTINANNOTATIONS_SOURCE)
#define BUILTINANNOTATIONS_DllAPI __declspec( dllexport )
#else
#define BUILTINANNOTATIONS_DllAPI __declspec( dllimport )
#endif // BUILTINANNOTATIONS_SOURCE
#else
#define BUILTINANNOTATIONS_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define BUILTINANNOTATIONS_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;
} // namespace fastcdr
} // namespace eprosima



namespace id {



} // namespace id
namespace autoid {
    /*!
     * @brief This class represents the enumeration AutoidKind defined by the user in the IDL file.
     * @ingroup BuiltinAnnotations
     */
    enum AutoidKind : uint32_t
    {
        SEQUENTIAL,
        HASH
    };



} // namespace autoid
namespace optional {



} // namespace optional
namespace position {



} // namespace position
namespace extensibility {
    /*!
     * @brief This class represents the enumeration ExtensibilityKind defined by the user in the IDL file.
     * @ingroup BuiltinAnnotations
     */
    enum ExtensibilityKind : uint32_t
    {
        FINAL,
        APPENDABLE,
        MUTABLE
    };



} // namespace extensibility
namespace final {



} // namespace final
namespace appendable {



} // namespace appendable
/* TODO(jlbueno)
namespace mutable {



} // namespace mutable
*/
namespace key {



} // namespace key
namespace must_understand {



} // namespace must_understand
namespace default_literal {



} // namespace default_literal
namespace unit {



} // namespace unit
namespace bit_bound {



} // namespace bit_bound
namespace external {



} // namespace external
namespace nested {



} // namespace nested
namespace verbatim {
    /*!
     * @brief This class represents the enumeration PlacementKind defined by the user in the IDL file.
     * @ingroup BuiltinAnnotations
     */
    enum PlacementKind : uint32_t
    {
        BEGIN_FILE,
        BEFORE_DECLARATION,
        BEGIN_DECLARATION,
        END_DECLARATION,
        AFTER_DECLARATION,
        END_FILE
    };



} // namespace verbatim
namespace service {



} // namespace service
namespace oneway {



} // namespace oneway
namespace ami {



} // namespace ami
namespace hashid {



} // namespace hashid
namespace default_nested {



} // namespace default_nested
namespace ignore_literal_names {



} // namespace ignore_literal_names
/*!
 * @brief This class represents the enumeration TryConstructFailAction defined by the user in the IDL file.
 * @ingroup BuiltinAnnotations
 */
enum TryConstructFailAction : uint32_t
{
    DISCARD,
    USE_DEFAULT,
    TRIM
};
namespace try_construct {



} // namespace try_construct
namespace non_serialized {



} // namespace non_serialized
/*!
 * @brief This enumeration represents the DataRepresentationMask bitflags defined by the user in the IDL file.
 * @ingroup BuiltinAnnotations
 */
enum DataRepresentationMaskBits : uint32_t
{
    XCDR1 = 0x01ull << 0,
    XML = 0x01ull << 1,
    XCDR2 = 0x01ull << 2
};
typedef uint32_t DataRepresentationMask;
namespace data_representation {



} // namespace data_representation
namespace topic {



} // namespace topic

#endif // _FAST_DDS_GENERATED_BUILTINANNOTATIONS_H_

