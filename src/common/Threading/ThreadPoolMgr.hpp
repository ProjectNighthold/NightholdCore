/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#ifndef TRINITY_SHARED_THREAD_POOL_MGR_HPP
#define TRINITY_SHARED_THREAD_POOL_MGR_HPP

#include "SynchronizedQueue.hpp"

#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

#include <cstddef>

#include <cds/init.h>
#include <cds/gc/hp.h>

namespace Trinity {

class ThreadPoolMgr final
{
    typedef std::mutex LockType;

    typedef std::unique_lock<LockType> GuardType;

    typedef std::function<void()> FunctorType;

    typedef Trinity::SynchronizedQueue<FunctorType> QueueType;

private:
    ThreadPoolMgr();

public:
    static ThreadPoolMgr * instance()
    {
        static ThreadPoolMgr mgr;
        return &mgr;
    }

    void start(std::size_t numThreads);

    void stop();

    template <typename RequestType>
    void schedule(RequestType request)
    {
        GuardType g(lock_);
        if (queue_.push(std::move(request)))
            ++requestCount_;
    }

    void wait();

private:
    void threadFunc();

    QueueType queue_;

    std::vector<std::thread> threads_;

    int requestCount_;

    LockType lock_;

    std::condition_variable waitCond_;
};

} // namespace Trinity

#define sThreadPoolMgr Trinity::ThreadPoolMgr::instance()

#endif // TRINITY_SHARED_THREAD_POOL_MGR_HPP
