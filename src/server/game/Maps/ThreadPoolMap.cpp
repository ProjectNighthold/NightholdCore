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

#include "ThreadPoolMap.hpp"

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <signal.h>
#endif

ThreadPoolMap::ThreadPoolMap()
    : requestCount_(0)
{ }

void ThreadPoolMap::start(std::size_t numThreads)
{
    threads_.resize(numThreads, nullptr);
    for (std::size_t i = 0; i < numThreads; ++i)
        threads_[i] = new std::thread(&ThreadPoolMap::threadFunc, this);
}

void ThreadPoolMap::stop()
{
    if (!queue_.frozen()) {
        queue_.freeze();
        for (auto* t : threads_)
        {
            t->join();
            delete t;
        }
    }
}

void ThreadPoolMap::terminate()
{
    if (!queue_.frozen()) {
        queue_.freeze();
        for (auto* t : threads_)
        {
            t->detach();
            #ifndef WIN32
            pthread_cancel(t->native_handle());
            #else
            TerminateThread(t->native_handle(), 0);
            #endif
            delete t;
        }
    }
}

void ThreadPoolMap::wait()
{
    GuardType guard(lock_);
    waitCond_.wait(guard, [this] { return requestCount_ == 0; });
}

void ThreadPoolMap::threadFunc()
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
