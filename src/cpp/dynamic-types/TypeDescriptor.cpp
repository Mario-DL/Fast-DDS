// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include <fastrtps/types/DynamicType.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/TypeDescriptor.h>
#include <fastrtps/types/AnnotationDescriptor.h>
#include <fastdds/dds/log/Log.hpp>
#include <fastrtps/types/TypesBase.h>

using namespace eprosima::fastrtps::types;

enum FSM_INPUTS
{
    LETTER = 1,
    NUMBER,
    UNDERSCORE,
    COLON,
    OTHER
};

enum FSM_STATES
{
    INVALID = 0,
    SINGLECOLON,
    DOUBLECOLON,
    VALID
};

static const int stateTable[4][6] =
{
    /* Input:     letter,  number,  underscore, colon,       other */
    {INVALID,     VALID,   INVALID, INVALID,    INVALID,     INVALID},
    {SINGLECOLON, INVALID, INVALID, INVALID,    DOUBLECOLON, INVALID},
    {DOUBLECOLON, VALID,   INVALID, INVALID,    INVALID,     INVALID},
    {VALID,       VALID,   VALID,   VALID,      SINGLECOLON, INVALID}
};

TypeDescriptor::TypeDescriptor(
        const std::string& name,
        TypeKind kind)
    : kind_(kind)
    , name_(name)
{
}

TypeDescriptor::~TypeDescriptor()
{
    clean();
}

void TypeDescriptor::clean()
{
    annotation_.clear();

    base_type_.reset();
    discriminator_type_.reset();
    element_type_.reset();
    key_element_type_.reset();
}

ReturnCode_t TypeDescriptor::copy_from(
        const TypeDescriptor& descriptor)
{
    *this = descriptor;
}

bool TypeDescriptor::operator==(const TypeDescriptor& descriptor) const
{
    return name_ == descriptor.name_ &&
           kind_ == descriptor.kind_ &&
           base_type_ == descriptor.base_type_ &&
           discriminator_type_ == descriptor.discriminator_type_ &&
           bound_ == descriptor.bound_ &&
           element_type_ == descriptor.element_type_ &&
           key_element_type_ == descriptor.key_element_type_ &&
           annotation_ == descriptor.annotation_ &&
           member_by_id_ == descriptor.member_by_id_ &&
           member_by_name_ == descriptor.member_by_name_;
}

bool TypeDescriptor::equals(
        const TypeDescriptor& descriptor) const
{
    return *this == descriptor;
}

DynamicType_ptr TypeDescriptor::get_base_type() const
{
    return base_type_;
}

uint32_t TypeDescriptor::get_bounds(
        uint32_t index /*=0*/) const
{
    if (index < bound_.size())
    {
        return bound_[index];
    }
    else
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error getting bounds value. Index out of range.");
        return BOUND_UNLIMITED;
    }
}

uint32_t TypeDescriptor::get_bounds_size() const
{
    return static_cast<uint32_t>(bound_.size());
}

DynamicType_ptr TypeDescriptor::get_discriminator_type() const
{
    return discriminator_type_;
}

DynamicType_ptr TypeDescriptor::get_element_type() const
{
    return element_type_;
}

DynamicType_ptr TypeDescriptor::get_key_element_type() const
{
    return key_element_type_;
}

TypeKind TypeDescriptor::get_kind() const
{
    return kind_;
}

std::string TypeDescriptor::get_name() const
{
    return name_;
}

uint32_t TypeDescriptor::get_total_bounds() const
{
    if (bound_.size() >= 1)
    {
        uint32_t bounds = 1;
        for (uint32_t i = 0; i < bound_.size(); ++i)
        {
            bounds *= bound_[i];
        }
        return bounds;
    }
    return BOUND_UNLIMITED;
}

bool TypeDescriptor::is_consistent() const
{
    // Alias Types need the base type to indicate what type has been aliased.
    if (kind_ == TK_ALIAS && base_type_ == nullptr)
    {
        return false;
    }

    // Alias must have base type, and structures and bitsets optionally can have it.
    if (base_type_ != nullptr && kind_ != TK_ALIAS && kind_ != TK_STRUCTURE && kind_ != TK_BITSET)
    {
        return false;
    }

    // Arrays need one or more bound fields with the lenghts of each dimension.
    if (kind_ == TK_ARRAY && bound_.size() == 0)
    {
        return false;
    }

    // These types need one bound with the length of the field.
    if (bound_.size() != 1 && (kind_ == TK_SEQUENCE || kind_ == TK_MAP || kind_ == TK_BITMASK ||
            kind_ == TK_STRING8 || kind_ == TK_STRING16))
    {
        return false;
    }

    // Only union types need the discriminator of the union
    if ((discriminator_type_ == nullptr) == (kind_ == TK_UNION))
    {
        return false;
    }

    // ElementType is used by these types to set the "value" type of the element, otherwise it should be null.
    if ((element_type_ == nullptr) == (kind_ == TK_ARRAY || kind_ == TK_SEQUENCE || kind_ == TK_STRING8 ||
            kind_ == TK_STRING16 || kind_ == TK_MAP || kind_ == TK_BITMASK))
    {
        return false;
    }

    // For Bitmask types is mandatory that this element is boolean.
    if (kind_ == TK_BITMASK && (element_type_->get_kind() != TK_BOOLEAN))
    {
        return false;
    }

    // Only map types need the keyElementType to store the "Key" type of the pair.
    if ((key_element_type_ == nullptr) == (kind_ == TK_MAP))
    {
        return false;
    }

    if (!is_type_name_consistent(name_))
    {
        return false;
    }

    return true;
}

bool TypeDescriptor::is_type_name_consistent(
        const std::string& sName)
{
    // Implement an FSM string parser to deal with both a plain type name
    // and a fully qualified name. According to the DDS xtypes standard,
    // type's fully qualified name is a concatenation of module names with
    // the name of a type inside of those modules.
    int currState = INVALID;
    for (uint32_t i = 0; i < sName.length(); ++i)
    {
        int col = 0;
        if (std::isalpha(sName[i]))
        {
            col = LETTER;
        }
        else if (std::isdigit(sName[i]))
        {
            col = NUMBER;
        }
        else if (sName[i] == '_')
        {
            col = UNDERSCORE;
        }
        else if (sName[i] == ':')
        {
            col = COLON;
        }
        else
        {
            col = OTHER;
        }
        currState = stateTable[currState][col];
        if (currState == INVALID)
        {
            return false;
        }
    }
    return true;
}

void TypeDescriptor::set_kind(
        TypeKind kind)
{
    kind_ = kind;
}

void TypeDescriptor::set_name(
        std::string name)
{
    name_ = name;
}

const AnnotationDescriptor* TypeDescriptor::get_annotation(
        const std::string& name) const
{
    auto it = annotation_.begin();

    for (; it != annotation_.end(); ++it)
    {
        const AnnotationDescriptor& ann = *it;
        if ( ann.type()
             && ann.type()->kind_ > 0
             && !ann.type()->get_name().empty()
             && ann.type()->get_name().compare(name) == 0)
        {
            return &ann;
        }
    }
    return nullptr;
}

// Annotations application
bool TypeDescriptor::annotation_is_extensibility() const
{
    return get_annotation(ANNOTATION_EXTENSIBILITY_ID) != nullptr;
}

bool TypeDescriptor::annotation_is_mutable() const
{
    if (get_annotation(ANNOTATION_MUTABLE_ID) != nullptr)
    {
        return true;
    }
    else
    {
        const AnnotationDescriptor* ann = get_annotation(ANNOTATION_EXTENSIBILITY_ID);
        if (ann != nullptr)
        {
            std::string value;
            if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
            {
                return value.compare(EXTENSIBILITY_MUTABLE) == 0;
            }
        }
    }
    return false;
}

bool TypeDescriptor::annotation_is_final() const
{
    if (get_annotation(ANNOTATION_FINAL_ID) != nullptr)
    {
        return true;
    }
    else
    {
        const AnnotationDescriptor* ann = get_annotation(ANNOTATION_EXTENSIBILITY_ID);
        if (ann != nullptr)
        {
            std::string value;
            if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
            {
                return value.compare(EXTENSIBILITY_FINAL) == 0;
            }
        }
    }
    return false;
}

bool TypeDescriptor::annotation_is_appendable() const
{
    if (get_annotation(ANNOTATION_APPENDABLE_ID) != nullptr)
    {
        return true;
    }
    else
    {
        const AnnotationDescriptor* ann = get_annotation(ANNOTATION_EXTENSIBILITY_ID);
        if (ann != nullptr)
        {
            std::string value;
            if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
            {
                return value.compare(EXTENSIBILITY_APPENDABLE) == 0;
            }
        }
    }
    return false;
}

bool TypeDescriptor::annotation_is_nested() const
{
    return get_annotation(ANNOTATION_NESTED_ID) != nullptr;
}

bool TypeDescriptor::annotation_is_bit_bound() const
{
    return get_annotation(ANNOTATION_BIT_BOUND_ID) != nullptr;
}

bool TypeDescriptor::annotation_is_key() const
{
    return get_annotation(ANNOTATION_KEY_ID) != nullptr || get_annotation(ANNOTATION_EPKEY_ID) != nullptr;
}

bool TypeDescriptor::annotation_is_non_serialized() const
{
    const AnnotationDescriptor* ann = get_annotation(ANNOTATION_NON_SERIALIZED_ID);
    if (ann != nullptr)
    {
        std::string value;
        if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
        {
            return value == CONST_TRUE;
        }
    }
    return false;
}

// Annotation getters
std::string TypeDescriptor::annotation_get_extensibility() const
{
    const AnnotationDescriptor* ann = get_annotation(ANNOTATION_EXTENSIBILITY_ID);
    if (ann != nullptr)
    {
        std::string value;
        if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
        {
            return value;
        }
    }
    return "";
}

bool TypeDescriptor::annotation_get_nested() const
{
    const AnnotationDescriptor* ann = get_annotation(ANNOTATION_NESTED_ID);
    if (ann != nullptr)
    {
        std::string value;
        if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
        {
            return value == CONST_TRUE;
        }
    }
    return false;
}

bool TypeDescriptor::annotation_get_key() const
{
    const AnnotationDescriptor* ann = get_annotation(ANNOTATION_KEY_ID);
    if (ann == nullptr)
    {
        ann = get_annotation(ANNOTATION_EPKEY_ID);
    }
    if (ann != nullptr)
    {
        std::string value;
        if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
        {
            return value == CONST_TRUE;
        }
    }
    return false;
}

uint16_t TypeDescriptor::annotation_get_bit_bound() const
{
    const AnnotationDescriptor* ann = get_annotation(ANNOTATION_BIT_BOUND_ID);
    if (ann != nullptr)
    {
        std::string value;
        if (ann->get_value(value) == ReturnCode_t::RETCODE_OK)
        {
            return static_cast<uint16_t>(std::stoi(value));
        }
    }
    return 32; // Default value
}

uint32_t TypeDescriptor::get_annotation_count() const
{
    return static_cast<uint32_t>(annotation_.size());
}

ReturnCode_t TypeDescriptor::get_annotation(
        AnnotationDescriptor& descriptor,
        uint32_t idx) const
{
    if (idx < annotation_.size())
    {
        descriptor = annotation_[idx];
        return ReturnCode_t::RETCODE_OK;
    }
    else
    {
        EPROSIMA_LOG_WARNING(DYN_TYPES, "Error getting annotation, annotation not found.");
        return ReturnCode_t::RETCODE_ERROR;
    }
}

bool TypeDescriptor::key_annotation() const
{
    for (auto anIt = annotation_.begin(); anIt != annotation_.end(); ++anIt)
    {
        if ((*anIt).key_annotation())
        {
            return true;
        }
    }
    return false;
}

ReturnCode_t TypeDescriptor::get_all_members_by_name(
        std::map<std::string, DynamicTypeMember*>& members) const
{
    members = member_by_name_;
    return ReturnCode_t::RETCODE_OK;
}

ReturnCode_t TypeDescriptor::get_all_members(
        std::map<MemberId, DynamicTypeMember*>& members) const
{
    members = member_by_id_;
    return ReturnCode_t::RETCODE_OK;
}

ReturnCode_t TypeDescriptor::get_member_by_name(
        DynamicTypeMember& member,
        const std::string& name) const
{
    auto it = member_by_name_.find(name);
    if (it != member_by_name_.end())
    {
        member = it->second;
        return ReturnCode_t::RETCODE_OK;
    }
    else
    {
        EPROSIMA_LOG_WARNING(DYN_TYPES, "Error getting member by name, member not found.");
        return ReturnCode_t::RETCODE_ERROR;
    }
}

ReturnCode_t TypeDescriptor::get_member(
        DynamicTypeMember& member,
        MemberId id) const
{
    auto it = member_by_id_.find(id);
    if (it != member_by_id_.end())
    {
        member = it->second;
        return ReturnCode_t::RETCODE_OK;
    }
    else
    {
        EPROSIMA_LOG_WARNING(DYN_TYPES, "Error getting member, member not found.");
        return ReturnCode_t::RETCODE_ERROR;
    }
}

MemberId TypeDescriptor::get_members_count() const
{
    return static_cast<MemberId>(member_by_id_.size());
}
