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

#ifndef _TCSOAP_H
#define _TCSOAP_H

#include "Define.h"
#include <mutex>
#include <future>
#include <string>

void process_message(struct soap* soap_message);
void TCSoapThread(const std::string& host, uint16 port);

class SOAPCommand
{
public:
    SOAPCommand();
    ~SOAPCommand() = default;

    void appendToPrintBuffer(const char* msg);
    void setCommandSuccess(bool val);
    bool hasCommandSucceeded() const;
    static void print(void* callbackArg, const char* msg);
    static void commandFinished(void* callbackArg, bool success);

    bool m_success;
    std::string m_printBuffer;
    std::promise<void> finishedPromise;
};

#endif
