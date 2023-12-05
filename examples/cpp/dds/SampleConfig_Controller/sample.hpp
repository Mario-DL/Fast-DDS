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
 * @file sample.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_SAMPLE_HPP_
#define _FAST_DDS_GENERATED_SAMPLE_HPP_

#include <cstdint>
#include <utility>

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
#if defined(SAMPLE_SOURCE)
#define SAMPLE_DllAPI __declspec( dllexport )
#else
#define SAMPLE_DllAPI __declspec( dllimport )
#endif // SAMPLE_SOURCE
#else
#define SAMPLE_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define SAMPLE_DllAPI
#endif // _WIN32



/*!
 * @brief This class represents the structure sample defined by the user in the IDL file.
 * @ingroup sample
 */
class sample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport sample()
    {
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~sample()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object sample that will be copied.
     */
    eProsima_user_DllExport sample(
            const sample& x)
    {
                    m_index = x.m_index;

                    m_key_value = x.m_key_value;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object sample that will be copied.
     */
    eProsima_user_DllExport sample(
            sample&& x) noexcept
    {
        m_index = x.m_index;
        m_key_value = x.m_key_value;
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object sample that will be copied.
     */
    eProsima_user_DllExport sample& operator =(
            const sample& x)
    {

                    m_index = x.m_index;

                    m_key_value = x.m_key_value;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object sample that will be copied.
     */
    eProsima_user_DllExport sample& operator =(
            sample&& x) noexcept
    {

        m_index = x.m_index;
        m_key_value = x.m_key_value;
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x sample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const sample& x) const
    {
        return (m_index == x.m_index &&
           m_key_value == x.m_key_value);
    }

    /*!
     * @brief Comparison operator.
     * @param x sample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const sample& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint8_t _index)
    {
        m_index = _index;
    }

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint8_t index() const
    {
        return m_index;
    }

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint8_t& index()
    {
        return m_index;
    }


    /*!
     * @brief This function sets a value in member key_value
     * @param _key_value New value for member key_value
     */
    eProsima_user_DllExport void key_value(
            uint8_t _key_value)
    {
        m_key_value = _key_value;
    }

    /*!
     * @brief This function returns the value of member key_value
     * @return Value of member key_value
     */
    eProsima_user_DllExport uint8_t key_value() const
    {
        return m_key_value;
    }

    /*!
     * @brief This function returns a reference to member key_value
     * @return Reference to member key_value
     */
    eProsima_user_DllExport uint8_t& key_value()
    {
        return m_key_value;
    }



private:

    uint8_t m_index{0};
    uint8_t m_key_value{0};

};

#endif // _FAST_DDS_GENERATED_SAMPLE_HPP_


