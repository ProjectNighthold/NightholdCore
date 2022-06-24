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

#ifndef __FunctionProcessor_H
#define __FunctionProcessor_H

#include "Define.h"
#include <map>

typedef std::multimap<uint64, std::function<void()>> FunctionList;

class FunctionProcessor
{
    public:
        FunctionProcessor();
        ~FunctionProcessor();

        void Update(uint32 p_time);
        void KillAllFunctions();
        void AddFunction(std::function<void()> && Function, uint64 e_time);
        void AddFunctionsFromQueue();
        uint64 CalculateTime(uint64 t_offset) const;
        bool Empty() const;
        uint32 Size() const;
        uint32 SizeQueue() const;
        void AddDelayedEvent(uint64 t_offset, std::function<void()>&& function);

    protected:
        std::atomic<uint64> m_time;
        FunctionList m_functions;
        FunctionList m_functions_queue;
        std::recursive_mutex m_queue_lock;
        bool clean;
};
#endif