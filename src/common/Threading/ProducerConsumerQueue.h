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

#ifndef _PCQ_H
#define _PCQ_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <atomic>
#include <type_traits>

template <typename T>
class ProducerConsumerQueue
{
    std::mutex _queueLock;
    std::queue<T> _queue;
    std::condition_variable _condition;
    std::atomic<bool> _shutdown;

public:

    ProducerConsumerQueue<T>() : _shutdown(false) { }

    void Push(const T& value)
    {
        std::lock_guard<std::mutex> lock(_queueLock);
        _queue.push(std::move(value));

        _condition.notify_one();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> lock(_queueLock);

        return _queue.empty();
    }

    bool Pop(T& value)
    {
        std::lock_guard<std::mutex> lock(_queueLock);

        if (_queue.empty() || _shutdown)
            return false;

        value = _queue.front();

        _queue.pop();

        return true;
    }

    void WaitAndPop(T& value)
    {
        std::unique_lock<std::mutex> lock(_queueLock);

        while (_queue.empty() && !_shutdown)
            _condition.wait(lock);

        if (_queue.empty() || _shutdown)
            return;

        value = _queue.front();

        _queue.pop();
    }

    void Cancel()
    {
        std::unique_lock<std::mutex> lock(_queueLock);

        while (!_queue.empty())
        {
            T& value = _queue.front();

            DeleteQueuedObject(value);

            _queue.pop();
        }

        _shutdown = true;

        _condition.notify_all();
    }

private:
    template<typename E = T>
    typename std::enable_if<std::is_pointer<E>::value>::type DeleteQueuedObject(E& obj) { delete obj; }

    template<typename E = T>
    typename std::enable_if<!std::is_pointer<E>::value>::type DeleteQueuedObject(E const& /*packet*/) { }
};

#endif
