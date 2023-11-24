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
 * @file TypesTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_TYPES_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_TYPES_TYPE_OBJECT_H_


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
#if defined(Types_SOURCE)
#define Types_DllAPI __declspec( dllexport )
#else
#define Types_DllAPI __declspec( dllimport )
#endif // Types_SOURCE
#else
#define Types_DllAPI
#endif
#else
#define Types_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerTypesTypes();

eProsima_user_DllExport const TypeIdentifier* GetMyEnumIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyEnumObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyEnumObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyEnumObject();

eProsima_user_DllExport const TypeIdentifier* GetMyBadEnumIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyBadEnumObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyBadEnumObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyBadEnumObject();



eProsima_user_DllExport const TypeIdentifier* GetMyEnumStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyEnumStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyEnumStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyEnumStructObject();



eProsima_user_DllExport const TypeIdentifier* GetMyBadEnumStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyBadEnumStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyBadEnumStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyBadEnumStructObject();

eProsima_user_DllExport const TypeIdentifier* GetMyAliasEnumIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyAliasEnumObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyAliasEnumObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyAliasEnumObject();



eProsima_user_DllExport const TypeIdentifier* GetMyAliasEnumStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMyAliasEnumStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMyAliasEnumStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMyAliasEnumStructObject();



eProsima_user_DllExport const TypeIdentifier* GetBasicStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBasicStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBasicStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBasicStructObject();



eProsima_user_DllExport const TypeIdentifier* GetBasicNamesStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBasicNamesStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBasicNamesStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBasicNamesStructObject();



eProsima_user_DllExport const TypeIdentifier* GetBasicBadStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBasicBadStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBasicBadStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBasicBadStructObject();



eProsima_user_DllExport const TypeIdentifier* GetBasicWideStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBasicWideStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBasicWideStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBasicWideStructObject();



eProsima_user_DllExport const TypeIdentifier* GetBadBasicWideStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBadBasicWideStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBadBasicWideStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBadBasicWideStructObject();



eProsima_user_DllExport const TypeIdentifier* GetStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteStringStructObject();



eProsima_user_DllExport const TypeIdentifier* GetLargeStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetLargeStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalLargeStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteLargeStringStructObject();



eProsima_user_DllExport const TypeIdentifier* GetWStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetWStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalWStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteWStringStructObject();



eProsima_user_DllExport const TypeIdentifier* GetLargeWStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetLargeWStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalLargeWStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteLargeWStringStructObject();



eProsima_user_DllExport const TypeIdentifier* GetArrayStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetArrayStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalArrayStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteArrayStructObject();



eProsima_user_DllExport const TypeIdentifier* GetArrayStructEqualIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetArrayStructEqualObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalArrayStructEqualObject();
eProsima_user_DllExport const TypeObject* GetCompleteArrayStructEqualObject();



eProsima_user_DllExport const TypeIdentifier* GetArrayBadStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetArrayBadStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalArrayBadStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteArrayBadStructObject();



eProsima_user_DllExport const TypeIdentifier* GetArrayDimensionsStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetArrayDimensionsStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalArrayDimensionsStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteArrayDimensionsStructObject();



eProsima_user_DllExport const TypeIdentifier* GetArraySizeStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetArraySizeStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalArraySizeStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteArraySizeStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceStructEqualIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceStructEqualObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceStructEqualObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceStructEqualObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceBadStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceBadStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceBadStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceBadStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceBoundsStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceBoundsStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceBoundsStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceBoundsStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceSequenceStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceSequenceStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceSequenceStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceSequenceStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSequenceSequenceBoundsStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceSequenceBoundsStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceSequenceBoundsStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceSequenceBoundsStructObject();





eProsima_user_DllExport const TypeIdentifier* GetMapStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapStructObject();





eProsima_user_DllExport const TypeIdentifier* GetMapStructEqualIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapStructEqualObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapStructEqualObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapStructEqualObject();





eProsima_user_DllExport const TypeIdentifier* GetMapBadKeyStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapBadKeyStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapBadKeyStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapBadKeyStructObject();





eProsima_user_DllExport const TypeIdentifier* GetMapBadElemStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapBadElemStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapBadElemStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapBadElemStructObject();





eProsima_user_DllExport const TypeIdentifier* GetMapBoundsStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapBoundsStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapBoundsStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapBoundsStructObject();






eProsima_user_DllExport const TypeIdentifier* GetMapMapStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapMapStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapMapStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapMapStructObject();






eProsima_user_DllExport const TypeIdentifier* GetMapMapBoundsStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapMapBoundsStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapMapBoundsStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapMapBoundsStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleUnionIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleUnionObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleUnionObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleUnionObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleUnionNamesIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleUnionNamesObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleUnionNamesObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleUnionNamesObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleTypeUnionIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleTypeUnionObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleTypeUnionObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleTypeUnionObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleBadUnionIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleBadUnionObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleBadUnionObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleBadUnionObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleBadDiscUnionIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleBadDiscUnionObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleBadDiscUnionObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleBadDiscUnionObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleUnionStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleUnionStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleUnionStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleUnionStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleUnionStructEqualIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleUnionStructEqualObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleUnionStructEqualObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleUnionStructEqualObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleUnionNamesStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleUnionNamesStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleUnionNamesStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleUnionNamesStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleTypeUnionStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleTypeUnionStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleTypeUnionStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleTypeUnionStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSimpleBadUnionStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimpleBadUnionStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimpleBadUnionStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimpleBadUnionStructObject();



eProsima_user_DllExport const TypeIdentifier* GetSimplBadDiscUnionStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSimplBadDiscUnionStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSimplBadDiscUnionStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSimplBadDiscUnionStructObject();


#endif // _FAST_DDS_GENERATED_TYPES_TYPE_OBJECT_H_