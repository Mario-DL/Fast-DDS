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
 * @file SimpleLarge.cpp
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

#include "SimpleLarge.h"
#include "SimpleLargeTypeObject.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

SimpleLarge_TypeIntrospectionExample::SimpleLarge_TypeIntrospectionExample()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@281e3708
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@35a50a4c
    m_message ="";
    // m_points com.eprosima.idl.parser.typecode.ArrayTypeCode@1f021e6c
    memset(&m_points, 0, (3) * 4);
    // m_second_message com.eprosima.idl.parser.typecode.StringTypeCode@103f852
    m_second_message ="";
    // m_some_values com.eprosima.idl.parser.typecode.SequenceTypeCode@587c290d

    // m_is_it_not_true_that_true_is_not_true com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4516af24
    m_is_it_not_true_that_true_is_not_true = false;

    // Just to register all known types
    registerSimpleLargeTypes();
}

SimpleLarge_TypeIntrospectionExample::~SimpleLarge_TypeIntrospectionExample()
{






}

SimpleLarge_TypeIntrospectionExample::SimpleLarge_TypeIntrospectionExample(
        const SimpleLarge_TypeIntrospectionExample& x)
{
    m_index = x.m_index;
    m_message = x.m_message;
    m_points = x.m_points;
    m_second_message = x.m_second_message;
    m_some_values = x.m_some_values;
    m_is_it_not_true_that_true_is_not_true = x.m_is_it_not_true_that_true_is_not_true;
}

SimpleLarge_TypeIntrospectionExample::SimpleLarge_TypeIntrospectionExample(
        SimpleLarge_TypeIntrospectionExample&& x) noexcept 
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_points = std::move(x.m_points);
    m_second_message = std::move(x.m_second_message);
    m_some_values = std::move(x.m_some_values);
    m_is_it_not_true_that_true_is_not_true = x.m_is_it_not_true_that_true_is_not_true;
}

SimpleLarge_TypeIntrospectionExample& SimpleLarge_TypeIntrospectionExample::operator =(
        const SimpleLarge_TypeIntrospectionExample& x)
{

    m_index = x.m_index;
    m_message = x.m_message;
    m_points = x.m_points;
    m_second_message = x.m_second_message;
    m_some_values = x.m_some_values;
    m_is_it_not_true_that_true_is_not_true = x.m_is_it_not_true_that_true_is_not_true;

    return *this;
}

SimpleLarge_TypeIntrospectionExample& SimpleLarge_TypeIntrospectionExample::operator =(
        SimpleLarge_TypeIntrospectionExample&& x) noexcept
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_points = std::move(x.m_points);
    m_second_message = std::move(x.m_second_message);
    m_some_values = std::move(x.m_some_values);
    m_is_it_not_true_that_true_is_not_true = x.m_is_it_not_true_that_true_is_not_true;

    return *this;
}

bool SimpleLarge_TypeIntrospectionExample::operator ==(
        const SimpleLarge_TypeIntrospectionExample& x) const
{

    return (m_index == x.m_index && m_message == x.m_message && m_points == x.m_points && m_second_message == x.m_second_message && m_some_values == x.m_some_values && m_is_it_not_true_that_true_is_not_true == x.m_is_it_not_true_that_true_is_not_true);
}

bool SimpleLarge_TypeIntrospectionExample::operator !=(
        const SimpleLarge_TypeIntrospectionExample& x) const
{
    return !(*this == x);
}

size_t SimpleLarge_TypeIntrospectionExample::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    current_alignment += (100 * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);



    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t SimpleLarge_TypeIntrospectionExample::getCdrSerializedSize(
        const SimpleLarge_TypeIntrospectionExample& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.message().size() + 1;

    if ((3) > 0)
    {
        current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.second_message().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.some_values().size() > 0)
    {
        current_alignment += (data.some_values().size() * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
    }



    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void SimpleLarge_TypeIntrospectionExample::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_index;
    scdr << m_message.c_str();
    scdr << m_points;

    scdr << m_second_message.c_str();
    scdr << m_some_values;
    scdr << m_is_it_not_true_that_true_is_not_true;

}

void SimpleLarge_TypeIntrospectionExample::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;
    dcdr >> m_points;

    dcdr >> m_second_message;
    dcdr >> m_some_values;
    dcdr >> m_is_it_not_true_that_true_is_not_true;
}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void SimpleLarge_TypeIntrospectionExample::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t SimpleLarge_TypeIntrospectionExample::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& SimpleLarge_TypeIntrospectionExample::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void SimpleLarge_TypeIntrospectionExample::message(
        const std::string& _message)
{
    m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void SimpleLarge_TypeIntrospectionExample::message(
        std::string&& _message)
{
    m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::string& SimpleLarge_TypeIntrospectionExample::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::string& SimpleLarge_TypeIntrospectionExample::message()
{
    return m_message;
}
/*!
 * @brief This function copies the value in member points
 * @param _points New value to be copied in member points
 */
void SimpleLarge_TypeIntrospectionExample::points(
        const std::array<int32_t, 3>& _points)
{
    m_points = _points;
}

/*!
 * @brief This function moves the value in member points
 * @param _points New value to be moved in member points
 */
void SimpleLarge_TypeIntrospectionExample::points(
        std::array<int32_t, 3>&& _points)
{
    m_points = std::move(_points);
}

/*!
 * @brief This function returns a constant reference to member points
 * @return Constant reference to member points
 */
const std::array<int32_t, 3>& SimpleLarge_TypeIntrospectionExample::points() const
{
    return m_points;
}

/*!
 * @brief This function returns a reference to member points
 * @return Reference to member points
 */
std::array<int32_t, 3>& SimpleLarge_TypeIntrospectionExample::points()
{
    return m_points;
}
/*!
 * @brief This function copies the value in member second_message
 * @param _second_message New value to be copied in member second_message
 */
void SimpleLarge_TypeIntrospectionExample::second_message(
        const std::string& _second_message)
{
    m_second_message = _second_message;
}

/*!
 * @brief This function moves the value in member second_message
 * @param _second_message New value to be moved in member second_message
 */
void SimpleLarge_TypeIntrospectionExample::second_message(
        std::string&& _second_message)
{
    m_second_message = std::move(_second_message);
}

/*!
 * @brief This function returns a constant reference to member second_message
 * @return Constant reference to member second_message
 */
const std::string& SimpleLarge_TypeIntrospectionExample::second_message() const
{
    return m_second_message;
}

/*!
 * @brief This function returns a reference to member second_message
 * @return Reference to member second_message
 */
std::string& SimpleLarge_TypeIntrospectionExample::second_message()
{
    return m_second_message;
}
/*!
 * @brief This function copies the value in member some_values
 * @param _some_values New value to be copied in member some_values
 */
void SimpleLarge_TypeIntrospectionExample::some_values(
        const std::vector<int16_t>& _some_values)
{
    m_some_values = _some_values;
}

/*!
 * @brief This function moves the value in member some_values
 * @param _some_values New value to be moved in member some_values
 */
void SimpleLarge_TypeIntrospectionExample::some_values(
        std::vector<int16_t>&& _some_values)
{
    m_some_values = std::move(_some_values);
}

/*!
 * @brief This function returns a constant reference to member some_values
 * @return Constant reference to member some_values
 */
const std::vector<int16_t>& SimpleLarge_TypeIntrospectionExample::some_values() const
{
    return m_some_values;
}

/*!
 * @brief This function returns a reference to member some_values
 * @return Reference to member some_values
 */
std::vector<int16_t>& SimpleLarge_TypeIntrospectionExample::some_values()
{
    return m_some_values;
}
/*!
 * @brief This function sets a value in member is_it_not_true_that_true_is_not_true
 * @param _is_it_not_true_that_true_is_not_true New value for member is_it_not_true_that_true_is_not_true
 */
void SimpleLarge_TypeIntrospectionExample::is_it_not_true_that_true_is_not_true(
        bool _is_it_not_true_that_true_is_not_true)
{
    m_is_it_not_true_that_true_is_not_true = _is_it_not_true_that_true_is_not_true;
}

/*!
 * @brief This function returns the value of member is_it_not_true_that_true_is_not_true
 * @return Value of member is_it_not_true_that_true_is_not_true
 */
bool SimpleLarge_TypeIntrospectionExample::is_it_not_true_that_true_is_not_true() const
{
    return m_is_it_not_true_that_true_is_not_true;
}

/*!
 * @brief This function returns a reference to member is_it_not_true_that_true_is_not_true
 * @return Reference to member is_it_not_true_that_true_is_not_true
 */
bool& SimpleLarge_TypeIntrospectionExample::is_it_not_true_that_true_is_not_true()
{
    return m_is_it_not_true_that_true_is_not_true;
}


size_t SimpleLarge_TypeIntrospectionExample::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;









    return current_align;
}

bool SimpleLarge_TypeIntrospectionExample::isKeyDefined()
{
    return false;
}

void SimpleLarge_TypeIntrospectionExample::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
          
}
