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

#ifndef __SIGNAL_HANDLER_H__
#define __SIGNAL_HANDLER_H__

#include <ace/Event_Handler.h>

namespace Trinity
{

/// Handle termination signals
class SignalHandler : public ACE_Event_Handler
{
    public:
        int handle_signal(int SigNum, siginfo_t* = NULL, ucontext_t* = NULL)
        {
            HandleSignal(SigNum);
            return 0;
        }
        virtual void HandleSignal(int /*SigNum*/) {};
};

}

#endif /* __SIGNAL_HANDLER_H__ */
