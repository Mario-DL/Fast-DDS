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
 * @file typesCdrAux.hpp
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

#include "types.h"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::EntityId_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.value(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::GuidPrefix_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.value(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::GUID_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.guidPrefix(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.entityId(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::SequenceNumber_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.high(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.low(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::SampleIdentity_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.writer_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.sequence_number(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::detail::Locator_s& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.kind(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.port(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.address(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::DiscoveryTime& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.local_participant_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.remote_entity_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.time(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3), data.host(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4), data.user(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(5), data.process(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::EntityCount& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.count(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::SampleIdentityCount& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.sample_id(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.count(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::Entity2LocatorTraffic& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.src_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.dst_locator(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.packet_count(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3), data.byte_count(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4), data.byte_magnitude_order(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::WriterReaderData& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.writer_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.reader_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.data(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::Locator2LocatorData& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.src_locator(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.dst_locator(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.data(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::EntityData& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.data(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::PhysicalData& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.participant_guid(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.host(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2), data.user(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3), data.process(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::Data& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);

    // TODO Member id del discriminador
    current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
            current_alignment);

    switch(data._d())
    {
                        case eprosima::fastdds::statistics::HISTORY2HISTORY_LATENCY:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.writer_reader_data(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::NETWORK_LATENCY:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.locator2locator_data(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::PUBLICATION_THROUGHPUT:
                        case eprosima::fastdds::statistics::SUBSCRIPTION_THROUGHPUT:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.entity_data(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::RTPS_SENT:
                        case eprosima::fastdds::statistics::RTPS_LOST:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4),
                                data.entity2locator_traffic(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::RESENT_DATAS:
                        case eprosima::fastdds::statistics::HEARTBEAT_COUNT:
                        case eprosima::fastdds::statistics::ACKNACK_COUNT:
                        case eprosima::fastdds::statistics::NACKFRAG_COUNT:
                        case eprosima::fastdds::statistics::GAP_COUNT:
                        case eprosima::fastdds::statistics::DATA_COUNT:
                        case eprosima::fastdds::statistics::PDP_PACKETS:
                        case eprosima::fastdds::statistics::EDP_PACKETS:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(5),
                                data.entity_count(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::DISCOVERED_ENTITY:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(6),
                                data.discovery_time(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::SAMPLE_DATAS:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(7),
                                data.sample_identity_count(), current_alignment);
                        break;
                
                        case eprosima::fastdds::statistics::PHYSICAL_DATA:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(8),
                                data.physical_data(), current_alignment);
                        break;
                
    }

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}





} // namespace fastcdr
} // namespace eprosima