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

#include "ThreadPoolMgr.hpp"

namespace Trinity {

ThreadPoolMgr::ThreadPoolMgr()
    : requestCount_(0)
{ }

void ThreadPoolMgr::start(std::size_t numThreads)
{
    threads_.reserve(numThreads);
    for (std::size_t i = 0; i < numThreads; ++i)
        threads_.emplace_back(&ThreadPoolMgr::threadFunc, this);
}

void ThreadPoolMgr::stop()
{
    if (!queue_.frozen()) {
        queue_.freeze();
        for (auto &t : threads_)
            t.join();
    }
}

void ThreadPoolMgr::wait()
{
    GuardType guard(lock_);
    waitCond_.wait(guard, [this] { return requestCount_ == 0; });
}

void ThreadPoolMgr::threadFunc()
{
    cds::threading::Manager::attachThread();
    FunctorType f;
    while (queue_.pop(f)) {
        f();
        GuardType g(lock_);
        if (--requestCount_ == 0)
            waitCond_.notify_all();
    }
    cds::threading::Manager::detachThread();
}

} // namespace Trinity
