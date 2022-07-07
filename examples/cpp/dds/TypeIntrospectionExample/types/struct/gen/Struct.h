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
 * @file Struct.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_STRUCT_H_
#define _FAST_DDS_GENERATED_STRUCT_H_


#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

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
#if defined(Struct_SOURCE)
#define Struct_DllAPI __declspec( dllexport )
#else
#define Struct_DllAPI __declspec( dllimport )
#endif // Struct_SOURCE
#else
#define Struct_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define Struct_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure InternalStruct_TypeIntrospectionExample defined by the user in the IDL file.
 * @ingroup STRUCT
 */
class InternalStruct_TypeIntrospectionExample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~InternalStruct_TypeIntrospectionExample();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object InternalStruct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample(
            const InternalStruct_TypeIntrospectionExample& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object InternalStruct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample(
            InternalStruct_TypeIntrospectionExample&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object InternalStruct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample& operator =(
            const InternalStruct_TypeIntrospectionExample& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object InternalStruct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample& operator =(
            InternalStruct_TypeIntrospectionExample&& x);

    /*!
     * @brief Comparison operator.
     * @param x InternalStruct_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const InternalStruct_TypeIntrospectionExample& x) const;

    /*!
     * @brief Comparison operator.
     * @param x InternalStruct_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const InternalStruct_TypeIntrospectionExample& x) const;

    /*!
     * @brief This function sets a value in member x_member
     * @param _x_member New value for member x_member
     */
    eProsima_user_DllExport void x_member(
            int32_t _x_member);

    /*!
     * @brief This function returns the value of member x_member
     * @return Value of member x_member
     */
    eProsima_user_DllExport int32_t x_member() const;

    /*!
     * @brief This function returns a reference to member x_member
     * @return Reference to member x_member
     */
    eProsima_user_DllExport int32_t& x_member();

    /*!
     * @brief This function sets a value in member y_member
     * @param _y_member New value for member y_member
     */
    eProsima_user_DllExport void y_member(
            int32_t _y_member);

    /*!
     * @brief This function returns the value of member y_member
     * @return Value of member y_member
     */
    eProsima_user_DllExport int32_t y_member() const;

    /*!
     * @brief This function returns a reference to member y_member
     * @return Reference to member y_member
     */
    eProsima_user_DllExport int32_t& y_member();

    /*!
     * @brief This function sets a value in member z_member
     * @param _z_member New value for member z_member
     */
    eProsima_user_DllExport void z_member(
            int32_t _z_member);

    /*!
     * @brief This function returns the value of member z_member
     * @return Value of member z_member
     */
    eProsima_user_DllExport int32_t z_member() const;

    /*!
     * @brief This function returns a reference to member z_member
     * @return Reference to member z_member
     */
    eProsima_user_DllExport int32_t& z_member();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const InternalStruct_TypeIntrospectionExample& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    int32_t m_x_member;
    int32_t m_y_member;
    int32_t m_z_member;
};
/*!
 * @brief This class represents the structure Struct_TypeIntrospectionExample defined by the user in the IDL file.
 * @ingroup STRUCT
 */
class Struct_TypeIntrospectionExample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Struct_TypeIntrospectionExample();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Struct_TypeIntrospectionExample();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Struct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Struct_TypeIntrospectionExample(
            const Struct_TypeIntrospectionExample& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Struct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Struct_TypeIntrospectionExample(
            Struct_TypeIntrospectionExample&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Struct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Struct_TypeIntrospectionExample& operator =(
            const Struct_TypeIntrospectionExample& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Struct_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Struct_TypeIntrospectionExample& operator =(
            Struct_TypeIntrospectionExample&& x);

    /*!
     * @brief Comparison operator.
     * @param x Struct_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Struct_TypeIntrospectionExample& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Struct_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Struct_TypeIntrospectionExample& x) const;

    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint32_t _index);

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint32_t index() const;

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint32_t& index();

    /*!
     * @brief This function copies the value in member internal_data
     * @param _internal_data New value to be copied in member internal_data
     */
    eProsima_user_DllExport void internal_data(
            const InternalStruct_TypeIntrospectionExample& _internal_data);

    /*!
     * @brief This function moves the value in member internal_data
     * @param _internal_data New value to be moved in member internal_data
     */
    eProsima_user_DllExport void internal_data(
            InternalStruct_TypeIntrospectionExample&& _internal_data);

    /*!
     * @brief This function returns a constant reference to member internal_data
     * @return Constant reference to member internal_data
     */
    eProsima_user_DllExport const InternalStruct_TypeIntrospectionExample& internal_data() const;

    /*!
     * @brief This function returns a reference to member internal_data
     * @return Reference to member internal_data
     */
    eProsima_user_DllExport InternalStruct_TypeIntrospectionExample& internal_data();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Struct_TypeIntrospectionExample& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    uint32_t m_index;
    InternalStruct_TypeIntrospectionExample m_internal_data;
};

#endif // _FAST_DDS_GENERATED_STRUCT_H_