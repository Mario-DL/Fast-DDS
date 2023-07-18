// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef TYPES_1_3_DYNAMIC_DATA_IMPL_HPP
#define TYPES_1_3_DYNAMIC_DATA_IMPL_HPP

#include <fastrtps/types/TypesBase.h>
#include <fastrtps/types/v1_3/MemberId.hpp>
#include <fastrtps/types/v1_3/DynamicData.hpp>
#include <fastrtps/utils/custom_allocators.hpp>

//#define DYNAMIC_TYPES_CHECKING

namespace eprosima {
namespace fastdds {
namespace dds {
namespace DDSSQLFilter {

class DDSFilterExpression;

}  // namespace DDSSQLFilter
}  // namespace dds
}  // namespace fastdds
}  // namespace eprosima

namespace eprosima {
namespace fastrtps {
namespace types {

class DynamicDataHelper;

namespace v1_3 {

class DynamicTypeImpl;
class DynamicDataImpl;
class MemberDescriptorImpl;
class DynamicPubSubType;

struct DataState
{
#ifdef DYNAMIC_TYPES_CHECKING
    int32_t int32_value_ = 0;
    uint32_t uint32_value_ = 0;
    int16_t int16_value_ = 0;
    uint16_t uint16_value_ = 0;
    int64_t int64_value_ = 0;
    uint64_t uint64_value_ = 0;
    float float32_value_ = 0.0f;
    double float64_value_ = 0.0;
    long double float128_value_ = 0.0;
    char char8_value_ = 0;
    wchar_t char16_value_ = 0;
    octet byte_value_ = 0;
    bool bool_value_ = false;
    std::string string_value_;
    std::wstring wstring_value_;
    std::map<MemberId, std::shared_ptr<DynamicDataImpl>> complex_values_;
#else
    std::map<MemberId, std::shared_ptr<void>> values_;
#endif // ifdef DYNAMIC_TYPES_CHECKING
    std::vector<MemberId> loaned_values_;
    bool key_element_ = false;
    std::shared_ptr<DynamicDataImpl> default_array_value_;
    MemberId union_id_ = MEMBER_ID_INVALID;
};

class DynamicDataImpl
    : protected DataState
    , public eprosima::detail::external_reference_counting<DynamicDataImpl>
{
    // Only create objects from the associated factory
    struct use_the_create_method
    {
        explicit use_the_create_method() = default;
    };

    DynamicData interface_;

public:

    DynamicDataImpl(
            use_the_create_method) noexcept;

    DynamicDataImpl(
            use_the_create_method,
            const DynamicTypeImpl& type) noexcept;

    DynamicDataImpl(
            use_the_create_method,
            const DynamicDataImpl& type) noexcept;

    DynamicDataImpl(
            use_the_create_method,
            DynamicDataImpl&& data) noexcept;

    ~DynamicDataImpl() noexcept;

    static const DynamicDataImpl& get_implementation(const DynamicData& t)
    {
        return *(DynamicDataImpl*)((const char*)&t -
                (::size_t)&reinterpret_cast<char const volatile&>((((DynamicDataImpl*)0)->interface_)));
    }

    static DynamicDataImpl& get_implementation(DynamicData& t)
    {
        const DynamicData& ct = t;
        return const_cast<DynamicDataImpl&>(get_implementation(ct));
    }

    DynamicData& get_interface() noexcept
    {
       return interface_;
    }

    const DynamicData& get_interface() const noexcept
    {
       return interface_;
    }

    static ReturnCode_t delete_data(
            const DynamicDataImpl& data) noexcept
    {
        data.release();
        return ReturnCode_t::RETCODE_OK;
    }

protected:

    void add_value(
            TypeKind kind,
            MemberId id);

    void create_members(
            const DynamicTypeImpl& type);

    void clean();

    void clean_members();

    std::shared_ptr<void> clone_value(
            MemberId id,
            TypeKind kind) const;

    bool compare_values(
            TypeKind kind,
            void* left,
            void* right) const;

    bool compare_values(
            TypeKind kind,
            std::shared_ptr<void> left,
            std::shared_ptr<void> right) const;

    ReturnCode_t insert_array_data(
            MemberId indexId);

    void set_default_value(
            MemberId id);

    std::string get_value(
            MemberId id = MEMBER_ID_INVALID) const;

    void set_value(
            const std::string& sValue,
            MemberId id = MEMBER_ID_INVALID);

    MemberId get_union_id() const;

    ReturnCode_t set_union_id(
            MemberId id);

    bool has_children() const;

    std::shared_ptr<const DynamicTypeImpl> type_;

    friend class DynamicTypeImpl;
    friend class DynamicDataFactoryImpl;
    friend class DynamicPubSubType;
    friend class types::DynamicDataHelper;
    friend class eprosima::fastdds::dds::DDSSQLFilter::DDSFilterExpression;

public:

    bool operator ==(
            const DynamicDataImpl& data) const noexcept;

    bool operator !=(
            const DynamicDataImpl& data) const noexcept;

    /**
     * Retrieve the @ref MemberDescriptor associated to a member
     * @param [out] value @ref MemberDescriptor object to populate
     * @param [in] id identifier of the member to retrieve
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_descriptor(
            MemberDescriptor& value,
            MemberId id) const noexcept;

    /**
     * Clear all memory associated to the object
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t clear_all_values();

    /**
     * Clear all memory not associated to the key
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t clear_nonkey_values();

    /**
     * Clear all memory associated to a specific member
     * @param [in] id identifier of the member to purge
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t clear_value(
            MemberId id);

    TypeKind get_kind() const;

    /**
     * Provides the @b item @b count of the data and depends on the type of object:
     * @li If the object is of a collection type, returns the number of elements currently in the collection.
     *     In the case of an array type, this value will always be equal to the product of the bounds of all array
     *     dimensions.
     * @li If the object is of a bitmask type, return the number of named flags that are currently set in the bitmask.
     * @li If the object is of a structure or annotation type, return the number of members in the object.
     *     This value may be different than the number of members in the corresponding @ref DynamicType (some optional
     *     members may be omitted.
     * @li If the object is of a union type, return the number of members in the object. This number will be two if the
     *     discriminator value selects a member and one otherwise.
     * @li if the object is of a primitive or enumerated type, it is atomic: return one.
     * @li if the object is of an alias type, return the value appropriate for the alias base type.
     * @return count as defined above
     */
    uint32_t get_item_count() const;

    std::string get_name();

    /**
     * Queries members by name
     * @param[in] name string
     * @return MemberId or MEMBER_ID_INVALID on failure
     */
    MemberId get_member_id_by_name(
            const std::string& name) const;

    /**
     * Queries members by index
     * @param[in] index uint32_t
     * @return MemberId or MEMBER_ID_INVALID on failure
     */
    MemberId get_member_id_at_index(
            uint32_t index) const;

    /**
     * \b Loans a @ref DynamicDataImpl object within the sample
     * @remarks This operation allows applications to visit values without allocating additional
     *         @ref DynamicDataImpl objects or copying values.
     * @remarks This loan shall be returned by the @ref DynamicDataImpl::return_loaned_value operation
     * @param [in] id identifier of the object to retrieve
     * @return @ref DynamicDataImpl object loaned or \b nil on outstanding loaned data
     */
    std::shared_ptr<DynamicDataImpl> loan_value(
            MemberId id);

    /**
     * Returns a loaned retrieved using @ref DynamicDataImpl::return_loaned_value
     * @param [in] value @ref DynamicDataImpl previously loaned
     */
    ReturnCode_t return_loaned_value(
            std::shared_ptr<DynamicDataImpl> value);

    MemberId get_array_index(
            const std::vector<uint32_t>& position);

    ReturnCode_t insert_sequence_data(
            MemberId& outId);

    ReturnCode_t insert_int32_value(
            int32_t value,
            MemberId& outId);

    ReturnCode_t insert_uint32_value(
            uint32_t value,
            MemberId& outId);

    ReturnCode_t insert_int16_value(
            int16_t value,
            MemberId& outId);

    ReturnCode_t insert_uint16_value(
            uint16_t value,
            MemberId& outId);

    ReturnCode_t insert_int64_value(
            int64_t value,
            MemberId& outId);

    ReturnCode_t insert_uint64_value(
            uint64_t value,
            MemberId& outId);

    ReturnCode_t insert_float32_value(
            float value,
            MemberId& outId);

    ReturnCode_t insert_float64_value(
            double value,
            MemberId& outId);

    ReturnCode_t insert_float128_value(
            long double value,
            MemberId& outId);

    ReturnCode_t insert_char8_value(
            char value,
            MemberId& outId);

    ReturnCode_t insert_char16_value(
            wchar_t value,
            MemberId& outId);

    ReturnCode_t insert_byte_value(
            octet value,
            MemberId& outId);

    ReturnCode_t insert_bool_value(
            bool value,
            MemberId& outId);

    ReturnCode_t insert_string_value(
            const std::string& value,
            MemberId& outId);

    ReturnCode_t insert_wstring_value(
            const std::wstring& value,
            MemberId& outId);

    ReturnCode_t insert_enum_value(
            const std::string& value,
            MemberId& outId);

    ReturnCode_t insert_complex_value(
            const DynamicDataImpl& value,
            MemberId& outId);

    ReturnCode_t remove_sequence_data(
            MemberId id);

    ReturnCode_t clear_data();

    ReturnCode_t clear_array_data(
            MemberId indexId);

    ReturnCode_t insert_map_data(
            const DynamicDataImpl& key,
            MemberId& outKeyId,
            MemberId& outValueId);

    ReturnCode_t insert_map_data(
            const DynamicDataImpl& key,
            const DynamicDataImpl& value,
            MemberId& outKey,
            MemberId& outValue);

    ReturnCode_t remove_map_data(
            MemberId keyId);

    /*
     * Retrieve an \b int32 value associated to an identifier
     * @param [out] value \b int32 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_int32_value(
            int32_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b int32 value associated to an identifier
     * @param [in] value \b int32 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_int32_value(
            int32_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b uint32 value associated to an identifier
     * @param [out] value \b uint32 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_uint32_value(
            uint32_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b uint32 value associated to an identifier
     * @param [in] value \b uint32 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_uint32_value(
            uint32_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b int16 value associated to an identifier
     * @param [out] value \b int16 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_int16_value(
            int16_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b int16 value associated to an identifier
     * @param [in] value \b int16 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_int16_value(
            int16_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b uint16 value associated to an identifier
     * @param [out] value \b uint16 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_uint16_value(
            uint16_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b uint16 value associated to an identifier
     * @param [in] value \b uint16 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_uint16_value(
            uint16_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b int64 value associated to an identifier
     * @param [out] value \b int64 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_int64_value(
            int64_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b int64 value associated to an identifier
     * @param [in] value \b int64 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_int64_value(
            int64_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b uint64 value associated to an identifier
     * @param [out] value \b uint64 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_uint64_value(
            uint64_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b uint64 value associated to an identifier
     * @param [in] value \b uint64 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_uint64_value(
            uint64_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b float32 value associated to an identifier
     * @param [out] value \b float32 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_float32_value(
            float& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b float32 value associated to an identifier
     * @param [in] value \b float32 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_float32_value(
            float value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b float64 value associated to an identifier
     * @param [out] value \b float64 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_float64_value(
            double& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b float64 value associated to an identifier
     * @param [in] value \b float64 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_float64_value(
            double value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b float128 value associated to an identifier
     * @param [out] value \b float128 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @remarks Only available on platforms supporting long double
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_float128_value(
            long double& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b float128 value associated to an identifier
     * @param [in] value \b float128 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_float128_value(
            long double value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b char8 value associated to an identifier
     * @param [out] value \b char8 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_char8_value(
            char& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b char8 value associated to an identifier
     * @param [in] value \b char8 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_char8_value(
            char value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b char16 value associated to an identifier
     * @param [out] value \b char16 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_char16_value(
            wchar_t& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b char16 value associated to an identifier
     * @param [in] value \b char16 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_char16_value(
            wchar_t value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b byte value associated to an identifier
     * @param [out] value \b byte to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_byte_value(
            octet& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b byte value associated to an identifier
     * @param [in] value \b byte to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_byte_value(
            octet value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b int8 value associated to an identifier
     * @param [out] value \b int8 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_int8_value(
            int8_t& value,
            MemberId id = MEMBER_ID_INVALID) const
    {
        octet aux;
        ReturnCode_t result = get_byte_value(aux, id);
        value = static_cast<int8_t>(aux);
        return result;
    }

    /*
     * Set an \b int8 value associated to an identifier
     * @param [in] value \b int8 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_int8_value(
            int8_t value,
            MemberId id = MEMBER_ID_INVALID)
    {
        return set_byte_value(static_cast<octet>(value), id);
    }

    /*
     * Retrieve an \b uint8 value associated to an identifier
     * @param [out] value \b uint8 to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_uint8_value(
            uint8_t& value,
            MemberId id = MEMBER_ID_INVALID) const
    {
        octet aux;
        ReturnCode_t result = get_byte_value(aux, id);
        value = static_cast<uint8_t>(aux);
        return result;
    }

    /*
     * Set an \b uint8 value associated to an identifier
     * @param [in] value \b uint8 to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_uint8_value(
            uint8_t value,
            MemberId id = MEMBER_ID_INVALID)
    {
        return set_byte_value(static_cast<octet>(value), id);
    }

    /*
     * Retrieve an \b bool value associated to an identifier
     * @param [out] value \b bool to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_bool_value(
            bool& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b bool value associated to an identifier
     * @param [in] value \b bool to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_bool_value(
            bool value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Set an \b bool value associated to an identifier
     * @param [in] value \b bool to set
     * @param [in] name bitmask flags can be addressed by name
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_bool_value(
            bool value,
            const std::string& name)
    {
        MemberId id = get_member_id_by_name(name);
        if (id != MEMBER_ID_INVALID)
        {
            return set_bool_value(value, id);
        }
        return ReturnCode_t::RETCODE_BAD_PARAMETER;
    }

    /*
     * Retrieve an \b string value associated to an identifier
     * @param [out] value \b string to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_string_value(
            std::string& value,
            MemberId id = MEMBER_ID_INVALID) const;

    ReturnCode_t get_string_value(
            const char*& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b string value associated to an identifier
     * @param [in] value \b string to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_string_value(
            const std::string& value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b wstring value associated to an identifier
     * @param [out] value \b wstring to populate
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_wstring_value(
            std::wstring& value,
            MemberId id = MEMBER_ID_INVALID) const;

    ReturnCode_t get_wstring_value(
            const wchar_t*& value,
            MemberId id = MEMBER_ID_INVALID) const;


    /*
     * Set an \b wstring value associated to an identifier
     * @param [in] value \b wstring to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_wstring_value(
            const std::wstring& value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b enum value associated to an identifier
     * @param [out] value string because enumerations can be addressed by name
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_enum_value(
            std::string& value,
            MemberId id = MEMBER_ID_INVALID) const;

    ReturnCode_t get_enum_value(
            const char*& value,
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set an \b enum value associated to an identifier
     * @param [in] value string because enumerations can be addressed by name
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_enum_value(
            const std::string& value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve an \b enum value associated to an identifier
     * @param [out] value uin32_t because enums are kept as \b DWORDs.
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_enum_value(
            uint32_t& value,
            MemberId id = MEMBER_ID_INVALID) const;
    /*
     * Set an \b enum value associated to an identifier
     * @param [in] value \b enum to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_enum_value(
            const uint32_t& value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Retrieve a bitmask object \b mask
     * @param [out] value uin64_t because bitmasks are kept as \b QWORDs.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t get_bitmask_value(
            uint64_t& value) const;

    /*
     * Convenient override to retrieve a bitmask object \b mask
     * @throws \@ref ReturnCode_t on failure
     * @return uint64 representing bitmask mask
     */
    uint64_t get_bitmask_value() const
    {
        uint64_t value;
        if (get_bitmask_value(value) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Set a \b mask value on a bitmask
     * @param [in] value \b mask to set
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_bitmask_value(
            uint64_t value);

    /*
     * Retrieve a \b complex value associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @return value @ref DynamicDataImpl reference to populate
     * @throws standard DDS @ref ReturnCode_t
     */
    std::shared_ptr<const DynamicDataImpl> get_complex_value(
            MemberId id = MEMBER_ID_INVALID) const;

    /*
     * Set a \b complex value associated to an identifier
     * @param [in] value @ref DynamicDataImpl to set
     * @param [in] id identifier of the member to set. \b MEMBER_ID_INVALID for primitives.
     * @return standard DDS @ref ReturnCode_t
     */
    ReturnCode_t set_complex_value(
            const DynamicDataImpl& value,
            MemberId id = MEMBER_ID_INVALID);

    /*
     * Convenient override to retrieve an \b int32 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b int32 queried
     */
    int32_t get_int32_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        int32_t value;
        if (get_int32_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b uint32 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b uint32 queried
     */
    uint32_t get_uint32_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        uint32_t value;
        if (get_uint32_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b int16 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b int16 queried
     */
    int16_t get_int16_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        int16_t value;
        if (get_int16_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b uint16 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b uint16 queried
     */
    uint16_t get_uint16_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        uint16_t value;
        if (get_uint16_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b int64 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b int64 queried
     */
    int64_t get_int64_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        int64_t value;
        if (get_int64_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b uint64 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b uint64 queried
     */
    uint64_t get_uint64_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        uint64_t value;
        if (get_uint64_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b float32 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b float32 queried
     */
    float get_float32_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        float value;
        if (get_float32_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b float64 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b float64 queried
     */
    double get_float64_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        double value;
        if (get_float64_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b float128 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b float128 queried
     */
    long double get_float128_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        long double value;
        if (get_float128_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b char8 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b char8 queried
     */
    char get_char8_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        char value;
        if (get_char8_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b char16 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b char16 queried
     */
    wchar_t get_char16_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        wchar_t value;
        if (get_char16_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b byte associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b byte queried
     */
    octet get_byte_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        octet value;
        if (get_byte_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b int8 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b int8 queried
     */
    int8_t get_int8_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        int8_t value;
        if (get_int8_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b uint8 associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b uint8 queried
     */
    uint8_t get_uint8_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        uint8_t value;
        if (get_uint8_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b bool associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b bool queried
     */
    bool get_bool_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        bool value;
        if (get_bool_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b bool associated to an identifier
     * @param [in] name string because \b bitmask can be addressed by name
     * @throws \@ref ReturnCode_t on failure
     * @return \b bool queried
     */
    bool get_bool_value(
            const std::string& name) const
    {
        MemberId id = get_member_id_by_name(name);
        bool value;
        if (get_bool_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b string associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b string queried
     */
    std::string get_string_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        std::string value;
        if (get_string_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b wstring associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b wstring queried
     */
    std::wstring get_wstring_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        std::wstring value;
        if (get_wstring_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    /*
     * Convenient override to retrieve an \b enum associated to an identifier
     * @param [in] id identifier of the member to query. \b MEMBER_ID_INVALID for primitives.
     * @throws \@ref ReturnCode_t on failure
     * @return \b enum queried
     */
    std::string get_enum_value(
            MemberId id = MEMBER_ID_INVALID) const
    {
        std::string value;
        if (get_enum_value(value, id) != ReturnCode_t::RETCODE_OK)
        {
            throw ReturnCode_t::RETCODE_BAD_PARAMETER;
        }
        return value;
    }

    ReturnCode_t get_union_label(
            uint64_t& value) const;

    uint64_t get_union_label() const;

    MemberId get_discriminator_value() const;

    ReturnCode_t get_discriminator_value(
            MemberId& id) const noexcept;

    ReturnCode_t set_discriminator_value(
            MemberId value) noexcept;

    // Serializes and deserializes the Dynamic Data.
    void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    bool deserialize(
            eprosima::fastcdr::Cdr& cdr);

    static size_t getCdrSerializedSize(
            const DynamicDataImpl& data,
            size_t current_alignment = 0);

    static size_t getEmptyCdrSerializedSize(
            const DynamicTypeImpl& type,
            size_t current_alignment = 0);

    static size_t getKeyMaxCdrSerializedSize(
            const DynamicTypeImpl& type,
            size_t current_alignment = 0);

    static size_t getMaxCdrSerializedSize(
            const DynamicTypeImpl& type,
            size_t current_alignment = 0);

    const DynamicTypeImpl& get_type() const noexcept;

    void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;
};


} // namespace v1_3
} // namespace types
} // namespace fastrtps
} // namespace eprosima

#endif // TYPES_1_3_DYNAMIC_DATA_IMPL_HPP