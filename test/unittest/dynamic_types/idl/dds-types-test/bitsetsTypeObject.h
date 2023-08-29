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
 * @file bitsetsTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_BITSETS_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_BITSETS_TYPE_OBJECT_H_

#include "helpers/basic_inner_typesTypeObject.h"

#include <fastrtps/types/TypeObject.h>
#include <map>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(bitsets_SOURCE)
#define bitsets_DllAPI __declspec( dllexport )
#else
#define bitsets_DllAPI __declspec( dllimport )
#endif // bitsets_SOURCE
#else
#define bitsets_DllAPI
#endif
#else
#define bitsets_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerbitsetsTypes();

eProsima_user_DllExport const TypeIdentifier* GetInnerAliasHelperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInnerAliasHelperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInnerAliasHelperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInnerAliasHelperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_bounded_string_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_bounded_string_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_bounded_string_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_bounded_string_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_bounded_wstring_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_bounded_wstring_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_bounded_wstring_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_bounded_wstring_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_array_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_array_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_array_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_array_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_sequence_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_sequence_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_sequence_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_sequence_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_map_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_map_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_map_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_map_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetBitsetStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBitsetStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBitsetStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBitsetStructObject();


#endif // _FAST_DDS_GENERATED_BITSETS_TYPE_OBJECT_H_