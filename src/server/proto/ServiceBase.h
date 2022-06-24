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

#ifndef ServiceBase_h__
#define ServiceBase_h__

#include "MessageBuffer.h"
#include "Define.h"
#include <functional>
#include <string>

namespace google
{
    namespace protobuf
    {
        class Message;
    }
}

class ServiceBase
{
public:
    virtual ~ServiceBase() { }

    virtual void CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) = 0;

protected:
    virtual void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) = 0;
    virtual void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) = 0;
    virtual void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status) = 0;
    virtual void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, google::protobuf::Message const* response) = 0;
    virtual std::string GetCallerInfo() const = 0;
};

#endif // ServiceBase_h__
