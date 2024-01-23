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
 * @file Calculator.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#include <fastcdr/config.h>

#if FASTCDR_VERSION_MAJOR == 1

#ifndef _FAST_DDS_GENERATED_CALCULATOR_H_
#define _FAST_DDS_GENERATED_CALCULATOR_H_


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
#if defined(CALCULATOR_SOURCE)
#define CALCULATOR_DllAPI __declspec( dllexport )
#else
#define CALCULATOR_DllAPI __declspec( dllimport )
#endif // CALCULATOR_SOURCE
#else
#define CALCULATOR_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define CALCULATOR_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima



/*!
 * @brief This class represents the enumeration OperationType defined by the user in the IDL file.
 * @ingroup Calculator
 */
enum OperationType : uint32_t
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};


/*!
 * @brief This class represents the structure RequestType defined by the user in the IDL file.
 * @ingroup Calculator
 */
class RequestType
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport RequestType();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~RequestType();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object RequestType that will be copied.
     */
    eProsima_user_DllExport RequestType(
            const RequestType& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object RequestType that will be copied.
     */
    eProsima_user_DllExport RequestType(
            RequestType&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object RequestType that will be copied.
     */
    eProsima_user_DllExport RequestType& operator =(
            const RequestType& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object RequestType that will be copied.
     */
    eProsima_user_DllExport RequestType& operator =(
            RequestType&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x RequestType object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const RequestType& x) const;

    /*!
     * @brief Comparison operator.
     * @param x RequestType object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const RequestType& x) const;

    /*!
     * @brief This function sets a value in member operation
     * @param _operation New value for member operation
     */
    eProsima_user_DllExport void operation(
            OperationType _operation);

    /*!
     * @brief This function returns the value of member operation
     * @return Value of member operation
     */
    eProsima_user_DllExport OperationType operation() const;

    /*!
     * @brief This function returns a reference to member operation
     * @return Reference to member operation
     */
    eProsima_user_DllExport OperationType& operation();


    /*!
     * @brief This function sets a value in member x
     * @param _x New value for member x
     */
    eProsima_user_DllExport void x(
            int32_t _x);

    /*!
     * @brief This function returns the value of member x
     * @return Value of member x
     */
    eProsima_user_DllExport int32_t x() const;

    /*!
     * @brief This function returns a reference to member x
     * @return Reference to member x
     */
    eProsima_user_DllExport int32_t& x();


    /*!
     * @brief This function sets a value in member y
     * @param _y New value for member y
     */
    eProsima_user_DllExport void y(
            int32_t _y);

    /*!
     * @brief This function returns the value of member y
     * @return Value of member y
     */
    eProsima_user_DllExport int32_t y() const;

    /*!
     * @brief This function returns a reference to member y
     * @return Reference to member y
     */
    eProsima_user_DllExport int32_t& y();


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
            const RequestType& data,
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

    OperationType m_operation;
    int32_t m_x;
    int32_t m_y;

};



/*!
 * @brief This class represents the structure ReplyType defined by the user in the IDL file.
 * @ingroup Calculator
 */
class ReplyType
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport ReplyType();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~ReplyType();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object ReplyType that will be copied.
     */
    eProsima_user_DllExport ReplyType(
            const ReplyType& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object ReplyType that will be copied.
     */
    eProsima_user_DllExport ReplyType(
            ReplyType&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object ReplyType that will be copied.
     */
    eProsima_user_DllExport ReplyType& operator =(
            const ReplyType& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object ReplyType that will be copied.
     */
    eProsima_user_DllExport ReplyType& operator =(
            ReplyType&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x ReplyType object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const ReplyType& x) const;

    /*!
     * @brief Comparison operator.
     * @param x ReplyType object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const ReplyType& x) const;

    /*!
     * @brief This function sets a value in member z
     * @param _z New value for member z
     */
    eProsima_user_DllExport void z(
            int64_t _z);

    /*!
     * @brief This function returns the value of member z
     * @return Value of member z
     */
    eProsima_user_DllExport int64_t z() const;

    /*!
     * @brief This function returns a reference to member z
     * @return Reference to member z
     */
    eProsima_user_DllExport int64_t& z();


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
            const ReplyType& data,
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

    int64_t m_z;

};


#endif // _FAST_DDS_GENERATED_CALCULATOR_H_



#endif // FASTCDR_VERSION_MAJOR == 1
