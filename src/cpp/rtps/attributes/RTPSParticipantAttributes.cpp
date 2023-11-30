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

#include <fastdds/rtps/attributes/RTPSParticipantAttributes.h>

#include <algorithm>
#include <memory>

#include <fastdds/dds/log/Log.hpp>
#include <fastdds/rtps/attributes/BuiltinTransports.hpp>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>
#include <fastrtps/xmlparser/XMLProfileManager.h>

namespace eprosima {
namespace fastrtps {
namespace rtps {

static bool is_intraprocess_only(
        const RTPSParticipantAttributes& att)
{
    return
        xmlparser::XMLProfileManager::library_settings().intraprocess_delivery == INTRAPROCESS_FULL &&
        att.builtin.discovery_config.ignoreParticipantFlags ==
        (ParticipantFilteringFlags::FILTER_DIFFERENT_HOST | ParticipantFilteringFlags::FILTER_DIFFERENT_PROCESS);
}

static void setup_transports_default(
        RTPSParticipantAttributes& att,
        bool intraprocess_only)
{
    auto descriptor = std::make_shared<fastdds::rtps::UDPv4TransportDescriptor>();
    descriptor->sendBufferSize = att.sendSocketBufferSize;
    descriptor->receiveBufferSize = att.listenSocketBufferSize;
    descriptor->default_reception_threads(att.builtin_transports_reception_threads);
    if (intraprocess_only)
    {
        // Avoid multicast leaving the host for intraprocess-only participants
        descriptor->TTL = 0;
    }
    att.userTransports.push_back(descriptor);

#ifdef SHM_TRANSPORT_BUILTIN
    if (!intraprocess_only)
    {
        auto shm_transport = std::make_shared<fastdds::rtps::SharedMemTransportDescriptor>();

        // We assume (Linux) UDP doubles the user socket buffer size in kernel, so
        // the equivalent segment size in SHM would be socket buffer size x 2
        auto segment_size_udp_equivalent =
                std::max(att.sendSocketBufferSize, att.listenSocketBufferSize) * 2;
        shm_transport->segment_size(segment_size_udp_equivalent);
        // Use same default max_message_size on both UDP and SHM
        shm_transport->max_message_size(descriptor->max_message_size());
        shm_transport->default_reception_threads(att.builtin_transports_reception_threads);
        att.userTransports.push_back(shm_transport);
    }
#endif // ifdef SHM_TRANSPORT_BUILTIN
}

void RTPSParticipantAttributes::setup_transports(
        fastdds::rtps::BuiltinTransports transports)
{
    bool intraprocess_only = is_intraprocess_only(*this);

    switch (transports)
    {
        case fastdds::rtps::BuiltinTransports::NONE:
            break;

        case fastdds::rtps::BuiltinTransports::DEFAULT:
            setup_transports_default(*this, intraprocess_only);
            break;

        default:
            EPROSIMA_LOG_ERROR(RTPS_PARTICIPANT,
                    "Setup for '" << transports << "' transport configuration not yet supported.");
            return;
    }

    useBuiltinTransports = false;
}

} // namespace rtps
} // namespace fastdds
} // namespace eprosima
