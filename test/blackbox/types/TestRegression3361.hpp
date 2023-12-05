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
 * @file TestRegression3361.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_TESTREGRESSION3361_HPP_
#define _FAST_DDS_GENERATED_TESTREGRESSION3361_HPP_

#include <cstdint>
#include <utility>
#include "TestIncludeRegression3361.hpp"

#include "TestRegression3361TypeObject.h"

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
#if defined(TESTREGRESSION3361_SOURCE)
#define TESTREGRESSION3361_DllAPI __declspec( dllexport )
#else
#define TESTREGRESSION3361_DllAPI __declspec( dllimport )
#endif // TESTREGRESSION3361_SOURCE
#else
#define TESTREGRESSION3361_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define TESTREGRESSION3361_DllAPI
#endif // _WIN32



/*!
 * @brief This class represents the structure TestRegression3361 defined by the user in the IDL file.
 * @ingroup TestRegression3361
 */
class TestRegression3361
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport TestRegression3361()
    {
        // Just to register all known types
        registerTestRegression3361Types();
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~TestRegression3361()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361(
            const TestRegression3361& x)
    {
                    m_uuid = x.m_uuid;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361(
            TestRegression3361&& x) noexcept
    {
        m_uuid = std::move(x.m_uuid);
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361& operator =(
            const TestRegression3361& x)
    {

                    m_uuid = x.m_uuid;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361& operator =(
            TestRegression3361&& x) noexcept
    {

        m_uuid = std::move(x.m_uuid);
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x TestRegression3361 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const TestRegression3361& x) const
    {
        return (m_uuid == x.m_uuid);
    }

    /*!
     * @brief Comparison operator.
     * @param x TestRegression3361 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const TestRegression3361& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function copies the value in member uuid
     * @param _uuid New value to be copied in member uuid
     */
    eProsima_user_DllExport void uuid(
            const TestModule::MACHINEID& _uuid)
    {
        m_uuid = _uuid;
    }

    /*!
     * @brief This function moves the value in member uuid
     * @param _uuid New value to be moved in member uuid
     */
    eProsima_user_DllExport void uuid(
            TestModule::MACHINEID&& _uuid)
    {
        m_uuid = std::move(_uuid);
    }

    /*!
     * @brief This function returns a constant reference to member uuid
     * @return Constant reference to member uuid
     */
    eProsima_user_DllExport const TestModule::MACHINEID& uuid() const
    {
        return m_uuid;
    }

    /*!
     * @brief This function returns a reference to member uuid
     * @return Reference to member uuid
     */
    eProsima_user_DllExport TestModule::MACHINEID& uuid()
    {
        return m_uuid;
    }



private:

    TestModule::MACHINEID m_uuid;

};

#endif // _FAST_DDS_GENERATED_TESTREGRESSION3361_HPP_


