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

#ifndef Service_h__
#define Service_h__

#include "Session.h"

namespace bgs { namespace protocol { } }
using namespace bgs::protocol;

namespace Battlenet
{
    template<class T>
    class Service : public T
    {
    public:
        Service(Session* session) : T(true), _session(session) { }

    protected:
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) override { _session->SendRequest(serviceHash, methodId, request, std::move(callback)); }
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) override { _session->SendRequest(serviceHash, methodId, request); }
        void SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, uint32 status) override { _session->SendResponse(token, status); }
        void SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, google::protobuf::Message const* response) override { _session->SendResponse(token, response); }
        std::string GetCallerInfo() const override { return _session->GetClientInfo(); }

        Session* _session;
    };
}

#endif // Service_h__
