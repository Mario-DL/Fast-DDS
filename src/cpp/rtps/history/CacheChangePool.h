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

/**
 * @file CacheChangePool.h
 */

#ifndef RTPS_HISTORY_CACHECHANGEPOOL_H_
#define RTPS_HISTORY_CACHECHANGEPOOL_H_

#include <fastdds/rtps/common/CacheChange.h>
#include <fastdds/rtps/history/IChangePool.h>
#include <fastdds/rtps/resources/ResourceManagement.h>

#include <rtps/history/PoolConfig.h>
#include <rtps/history/paris/PerformancePool.hpp>

#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstddef>

namespace eprosima {
namespace fastrtps {
namespace rtps {

/**
 * Class CacheChangePool, used by the HistoryCache to pre-reserve a number of CacheChange_t to avoid dynamically
 * reserving memory in the middle of execution loops.
 * @ingroup COMMON_MODULE
 */
class CacheChangePool : public IChangePool
{
public:

    virtual ~CacheChangePool()
    {

    }

    /**
     * Construct and initialize a CacheChangePool.
     *
     * @param config   Pool configuration (member @c payload_initial_size is not being used).
     * @param f        Functor to be called on all preallocated elements.
     */
    template<class UnaryFunction>
    CacheChangePool(
            const PoolConfig& config,
            UnaryFunction )
    {
        pool_ = eprosima::ddsrouter::utils::create_cache_change_pool(config);
    }

    /**
     * Construct and initialize a CacheChangePool.
     *
     * @param config   Pool configuration (member @c payload_initial_size is not being used).
     */
    CacheChangePool(
            const PoolConfig& config)
    {
        pool_ = eprosima::ddsrouter::utils::create_cache_change_pool(config);
    }

    bool reserve_cache(
            CacheChange_t*& cache_change) override
    {
        pool_->loan(cache_change);
        return true;
    }

    bool release_cache(
            CacheChange_t* cache_change) override
    {
        pool_->return_loan(cache_change);
        return true;
    }

private:

    std::unique_ptr<eprosima::ddsrouter::utils::PerformancePool> pool_;

};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif /* RTPS_HISTORY_CACHECHANGEPOOL_H_ */
