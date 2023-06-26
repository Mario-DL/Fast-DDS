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

#include <fastrtps/types/v1_3/MemberDescriptor.hpp>

using namespace eprosima::fastrtps::types::v1_3;

MemberDescriptor::MemberDescriptor()
    : name_(new(std::nothrow) std::string)
    , default_value_(new(std::nothrow) std::string)
    , labels_(new(std::nothrow) std::vector<uint32_t>) noexcept
{}

MemberDescriptor::~MemberDescriptor() noexcept
{
    if (type_ != nullptr)
    {
        DynamicTypeBuilderFactory::get_instance().delete_type(type_);
    }

    delete name_;
    delete default_value_;
    delete labels_;
}

MemberDescriptor::MemberDescriptor(const MemberDescriptor& type) noexcept
    : name_(new(std::nothrow) std::string)
    , id_(type.id_)
    , default_value_(new(std::nothrow) std::string)
    , index_(type.index_)
    , labels_(new(std::nothrow) std::vector<uint32_t>)
    , default_label_(type.default_label_)
{
    if (type.type_ != nullptr)
    {
        type_ = DynamicTypeBuilderFactory::get_instance().create_copy(*type.type_);
    }

    if (name_ != nullptr && type.name_ != nullptr)
    {
        *name_ = *type.name_;
    }

    if (default_value_ != nullptr && type.default_value_ != nullptr)
    {
        *default_value_ = *type.default_value_;
    }

    if (labels_ != nullptr && type.labels != nullptr)
    {
        *labels_ = *type.labels;
    }
}

MemberDescriptor::MemberDescriptor(MemberDescriptor&& type) noexcept
    : name_(type.name_)
    , id_(type.id_)
    , type_(type.type_)
    , default_value_(type.default_value_)
    , index_(type.index_)
    , labels_(type.labels_)
    , default_label_(type.default_label_)
{
}

MemberDescriptor::MemberDescriptor& operator=(const MemberDescriptor& type) noexcept
{
    name_ = new(std::nothrow) std::string;
    id_ = type.id_;
    default_value_ = new(std::nothrow) std::string;
    index_ = type.index_;
    labels_ = new(std::nothrow) std::vector<uint32_t>;
    default_label_ = type.default_label_;

    if (type.type_ != nullptr)
    {
        type_ = DynamicTypeBuilderFactory::get_instance().create_copy(*type.type_);
    }

    if (name_ != nullptr && type.name_ != nullptr)
    {
        *name_ = *type.name_;
    }

    if (default_value_ != nullptr && type.default_value_ != nullptr)
    {
        *default_value_ = *type.default_value_;
    }

    if (labels_ != nullptr && type.labels != nullptr)
    {
        *labels_ = *type.labels;
    }
}

MemberDescriptor& MemberDescriptor::operator=(MemberDescriptor&& type) noexcept
{
    name_ = type.name_;
    id_ = type.id_;
    type_ = type.type_;
    default_value_ = type.default_value_;
    index_ = type.index_;
    labels_ = type.labels_;
    default_label_ = type.default_label_;

    return *this;
}

bool MemberDescriptor::operator==(
        const MemberDescriptor& d) const noexcept
{
    return (name_ == type.name_ || (name_ != nullptr && d.name_ != nullptr && *name_ == *d.name_))
        && id_ == type.id_
        && (type_ == type.type_ || (type_ != nullptr && d.type_ != nullptr && *type_ == *d.type_ ))
        && (default_value_ == type.default_value_ || (default_value_ != nullptr && d.default_value_ != nullptr && *default_value_ == *d.default_value_))
        && index_ == type.index_
        && (labels_ == type.labels_ || (labels_ != nullptr && d.labels_ != nullptr && *labels_ == *d.labels_))
        && default_label_ == type.default_label_;
}

bool MemberDescriptor::operator !=(
        const MemberDescriptor& descriptor) const noexcept
{
    return !this->operator==(d);
}

const char* MemberDescriptor::get_name() const noexcept
{
    if (name_ != nullptr)
    {
        return name_->c_str();
    }

    return nullptr;
}

void MemberDescriptor::set_name(
        const char* name) noexcept
{
    if (nullptr == name)
    {
        return;
    }

    if (nullptr == name_)
    {
        name_ = new(std::nothrow) std::string;
        if (nullptr == name_)
        {
            return;
        }
    }

    *name_ = name;
}

const DynamicType* MemberDescriptor::get_type() const noexcept
{
    if (type_ != nullptr)
    {
        type_ = DynamicTypeBuilderFactory::get_instance().create_copy(*type.type_);
    }

    return nullptr;
}

void MemberDescriptor::set_type(
            const DynamicType& type) noexcept
{
    reset_type();
    type_ = DynamicTypeBuilderFactory::get_instance().create_copy(type);
}

void MemberDescriptor::reset_type() noexcept
{
    if (type_ != nullptr)
    {
        DynamicTypeBuilderFactory::get_instance().delete_type(type_);
    }

    type_ = nullptr;
}

const char* MemberDescriptor::get_default_value() const noexcept
{
    if (default_value_ != nullptr)
    {
        return default_value_->c_str();
    }

    return nullptr;
}

void MemberDescriptor::set_default_value(
        const char* value) noexcept
{
    if (nullptr == value)
    {
        return;
    }

    if (nullptr == default_value_)
    {
        default_value_ = new(std::nothrow) std::string;
        if (nullptr == default_value_)
        {
            return;
        }
    }

    *default_value_ = value;
}

const uint32_t* MemberDescriptor::get_labels(
        uint32_t& count) const noexcept
{
    if (labels_ != nullptr)
    {
        count = static_cast<uint32_t>(labels_->size());
        return labels_->data();
    }

    count = 0;
    return nullptr;
}

void MemberDescriptor::set_labels(
            const uint32_t* labels,
            uint32_t count) noexcept
{
    if (nullptr == labels_ )
    {
        labels_ = new(std::nowthrow) std::vector<uint32_t>(labels, labels + count);
    }
    else
    {
        *labels.assign(labels, labels + count);
    }
}

ReturnCode_t MemberDescriptor::copy_from(
    const MemberDescriptor& descriptor) noexcept
{
    this->operator=(descriptor);
    return ReturnCode_t::RETCODE_OK;
}

bool MemberDescriptor::equals(
        const MemberDescriptor& descriptor) const noexcept
{
    return this->operator==(descriptor);
}


bool MemberDescriptor::is_consistent() const noexcept
{
    // TODO: rely on implementation definition
}
