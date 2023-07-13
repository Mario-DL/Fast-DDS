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
 * @file TypeIdentifier.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _TYPEIDENTIFIER_H_
#define _TYPEIDENTIFIER_H_

#include <fastrtps/types/TypesBase.h>
#include <fastrtps/types/TypeIdentifierTypes.h>
#include <stdint.h>
#include <array>
#include <string>
#include <vector>

namespace eprosima {

namespace fastcdr {
class Cdr;
} // namespace fastcdr

namespace fastdds {
namespace dds {
class TypeConsistencyEnforcementQosPolicy;
} // namespace dds
} // namespace fastdds

namespace fastrtps {
namespace types {

typedef octet TypeIdentiferKind;
const octet TI_STRING8_SMALL = 0x70;
const octet TI_STRING8_LARGE = 0x71;
const octet TI_STRING16_SMALL = 0x72;
const octet TI_STRING16_LARGE = 0x73;
const octet TI_PLAIN_SEQUENCE_SMALL = 0x80;
const octet TI_PLAIN_SEQUENCE_LARGE = 0x81;
const octet TI_PLAIN_ARRAY_SMALL = 0x90;
const octet TI_PLAIN_ARRAY_LARGE = 0x91;
const octet TI_PLAIN_MAP_SMALL = 0xA0;
const octet TI_PLAIN_MAP_LARGE = 0xA1;
const octet TI_STRONGLY_CONNECTED_COMPONENT = 0xB0;

// The TypeIdentifier uniquely identifies a type (a set of equivalent
// types according to an equivalence relationship:  COMPLETE, MNIMAL).
//
// In some cases (primitive types, strings, plain types) the identifier
// is a explicit description of the type.
// In other cases the Identifier is a Hash of the type description
//
// In the case of primitive types and strings the implied equivalence
// relation is the identity.
//
// For Plain Types and Hash-defined TypeIdentifiers there are three
//  possibilities: MINIMAL, COMPLETE, and COMMON:
//   - MINIMAL indicates the TypeIdentifier identifies equivalent types
//     according to the MINIMAL equivalence relation
//   - COMPLETE indicates the TypeIdentifier identifies equivalent types
//     according to the COMPLETE equivalence relation
//   - COMMON indicates the TypeIdentifier identifies equivalent types
//     according to both the MINIMAL and the COMMON equivalence relation.
//     This means the TypeIdentifier is the same for both relationships
//
class TypeIdentifier
{
public:

    /*!
     * @brief Default constructor.
     */
    RTPS_DllAPI TypeIdentifier();

    /*!
     * @brief Default destructor.
     */
    RTPS_DllAPI ~TypeIdentifier();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object TypeIdentifier that will be copied.
     */
    RTPS_DllAPI TypeIdentifier(
            const TypeIdentifier& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object TypeIdentifier that will be copied.
     */
    RTPS_DllAPI TypeIdentifier(
            TypeIdentifier&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object TypeIdentifier that will be copied.
     */
    RTPS_DllAPI TypeIdentifier& operator =(
            const TypeIdentifier& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object TypeIdentifier that will be copied.
     */
    RTPS_DllAPI TypeIdentifier& operator =(
            TypeIdentifier&& x);

    /*!
     * @brief This function sets the discriminator value.
     * @param __d New value for the discriminator.
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the new value doesn't correspond to the selected union member.
     */
    RTPS_DllAPI void _d(
            octet __d);

    /*!
     * @brief This function returns the value of the discriminator.
     * @return Value of the discriminator
     */
    RTPS_DllAPI octet _d() const;

    /*!
     * @brief This function returns a reference to the discriminator.
     * @return Reference to the discriminator.
     */
    RTPS_DllAPI octet& _d();

    /*!
     * @brief This function sets a value in member string_sdefn
     * @param _string_sdefn New value for member string_sdefn
     */
    RTPS_DllAPI void string_sdefn(
            StringSTypeDefn _string_sdefn);

    /*!
     * @brief This function returns the value of member string_sdefn
     * @return Value of member string_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const StringSTypeDefn& string_sdefn() const;

    /*!
     * @brief This function returns a reference to member string_sdefn
     * @return Reference to member string_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI StringSTypeDefn& string_sdefn();
    /*!
     * @brief This function sets a value in member string_ldefn
     * @param _string_ldefn New value for member string_ldefn
     */
    RTPS_DllAPI void string_ldefn(
            StringLTypeDefn _string_ldefn);

    /*!
     * @brief This function returns the value of member string_ldefn
     * @return Value of member string_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const StringLTypeDefn& string_ldefn() const;

    /*!
     * @brief This function returns a reference to member string_ldefn
     * @return Reference to member string_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI StringLTypeDefn& string_ldefn();
    /*!
     * @brief This function sets a value in member seq_sdefn
     * @param _seq_sdefn New value for member seq_sdefn
     */
    RTPS_DllAPI void seq_sdefn(
            PlainSequenceSElemDefn _seq_sdefn);

    /*!
     * @brief This function returns the value of member seq_sdefn
     * @return Value of member seq_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainSequenceSElemDefn& seq_sdefn() const;

    /*!
     * @brief This function returns a reference to member seq_sdefn
     * @return Reference to member seq_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainSequenceSElemDefn& seq_sdefn();
    /*!
     * @brief This function sets a value in member seq_ldefn
     * @param _seq_ldefn New value for member seq_ldefn
     */
    RTPS_DllAPI void seq_ldefn(
            PlainSequenceLElemDefn _seq_ldefn);

    /*!
     * @brief This function returns the value of member seq_ldefn
     * @return Value of member seq_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainSequenceLElemDefn& seq_ldefn() const;

    /*!
     * @brief This function returns a reference to member seq_ldefn
     * @return Reference to member seq_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainSequenceLElemDefn& seq_ldefn();
    /*!
     * @brief This function sets a value in member array_sdefn
     * @param _array_sdefn New value for member array_sdefn
     */
    RTPS_DllAPI void array_sdefn(
            PlainArraySElemDefn _array_sdefn);

    /*!
     * @brief This function returns the value of member array_sdefn
     * @return Value of member array_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainArraySElemDefn& array_sdefn() const;

    /*!
     * @brief This function returns a reference to member array_sdefn
     * @return Reference to member array_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainArraySElemDefn& array_sdefn();
    /*!
     * @brief This function sets a value in member array_ldefn
     * @param _array_ldefn New value for member array_ldefn
     */
    RTPS_DllAPI void array_ldefn(
            PlainArrayLElemDefn _array_ldefn);

    /*!
     * @brief This function returns the value of member array_ldefn
     * @return Value of member array_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainArrayLElemDefn& array_ldefn() const;

    /*!
     * @brief This function returns a reference to member array_ldefn
     * @return Reference to member array_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainArrayLElemDefn& array_ldefn();
    /*!
     * @brief This function sets a value in member map_sdefn
     * @param _map_sdefn New value for member map_sdefn
     */
    RTPS_DllAPI void map_sdefn(
            PlainMapSTypeDefn _map_sdefn);

    /*!
     * @brief This function returns the value of member map_sdefn
     * @return Value of member map_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainMapSTypeDefn& map_sdefn() const;

    /*!
     * @brief This function returns a reference to member map_sdefn
     * @return Reference to member map_sdefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainMapSTypeDefn& map_sdefn();
    /*!
     * @brief This function sets a value in member map_ldefn
     * @param _map_ldefn New value for member map_ldefn
     */
    RTPS_DllAPI void map_ldefn(
            PlainMapLTypeDefn _map_ldefn);

    /*!
     * @brief This function returns the value of member map_ldefn
     * @return Value of member map_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const PlainMapLTypeDefn& map_ldefn() const;

    /*!
     * @brief This function returns a reference to member map_ldefn
     * @return Reference to member map_ldefn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI PlainMapLTypeDefn& map_ldefn();
    /*!
     * @brief This function sets a value in member sc_component_id
     * @param _sc_component_id New value for member sc_component_id
     */
    RTPS_DllAPI void sc_component_id(
            StronglyConnectedComponentId _sc_component_id);

    /*!
     * @brief This function returns the value of member sc_component_id
     * @return Value of member sc_component_id
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI StronglyConnectedComponentId sc_component_id() const;

    /*!
     * @brief This function returns a reference to member sc_component_id
     * @return Reference to member sc_component_id
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI StronglyConnectedComponentId& sc_component_id();
    /*!
     * @brief This function sets a value in member equivalence_hash
     * @param _equivalence_hash New value for member equivalence_hash
     */
    RTPS_DllAPI void equivalence_hash(
            EquivalenceHash _equivalence_hash);

    /*!
     * @brief This function returns the value of member equivalence_hash
     * @return Value of member equivalence_hash
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const octet* equivalence_hash() const;

    /*!
     * @brief This function returns a reference to member equivalence_hash
     * @return Reference to member equivalence_hash
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI octet* equivalence_hash();
    /*!
     * @brief This function sets a value in member extended_defn
     * @param _extended_defn New value for member extended_defn
     */
    RTPS_DllAPI void extended_defn(
            ExtendedTypeDefn _extended_defn);

    /*!
     * @brief This function returns the value of member extended_defn
     * @return Value of member extended_defn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI const ExtendedTypeDefn& extended_defn() const;

    /*!
     * @brief This function returns a reference to member extended_defn
     * @return Reference to member extended_defn
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    RTPS_DllAPI ExtendedTypeDefn& extended_defn();

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    RTPS_DllAPI void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    RTPS_DllAPI void deserialize(
            eprosima::fastcdr::Cdr& cdr);

    /**
     * Equals
     * */
    bool operator ==(
            const TypeIdentifier& other) const;

    RTPS_DllAPI bool consistent(
            const TypeIdentifier& x,
            const fastdds::dds::TypeConsistencyEnforcementQosPolicy& consistency) const;

    /**
     * @brief equivalence_hash_to_string
     * @return string representation of the equivalence hash
     */
    RTPS_DllAPI std::string equivalence_hash_to_string() const;

private:

    octet m__d;

    StringSTypeDefn m_string_sdefn;
    StringLTypeDefn m_string_ldefn;
    PlainSequenceSElemDefn m_seq_sdefn;
    PlainSequenceLElemDefn m_seq_ldefn;
    PlainArraySElemDefn m_array_sdefn;
    PlainArrayLElemDefn m_array_ldefn;
    PlainMapSTypeDefn m_map_sdefn;
    PlainMapLTypeDefn m_map_ldefn;
    StronglyConnectedComponentId m_sc_component_id;
    EquivalenceHash m_equivalence_hash;
    ExtendedTypeDefn m_extended_defn;
};

typedef std::vector<TypeIdentifier> TypeIdentifierSeq;

} // namespace types
} // namespace fastrtps
} // namespace eprosima

#endif // _TYPEIDENTIFIER_H_
