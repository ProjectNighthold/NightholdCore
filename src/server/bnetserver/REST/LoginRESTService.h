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

#ifndef LoginRESTService_h__
#define LoginRESTService_h__

#include "Session.h"
#include "Define.h"
#include "Login.pb.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <atomic>
#include <mutex>
#include <thread>

struct soap;
struct soap_plugin;

class LoginRESTService
{
public:
    LoginRESTService() : _stopped(false), _port(0), _loginTicketCleanupTimer(nullptr) { }

    static LoginRESTService& Instance();

    bool Start(boost::asio::io_service& ioService);
    void Stop();

    boost::asio::ip::tcp::endpoint const& GetAddressForClient(boost::asio::ip::address const& address) const;

    std::unique_ptr<Battlenet::Session::AccountInfo> VerifyLoginTicket(std::string const& id);

private:
    void Run();

    friend int32 handle_get_plugin(soap* soapClient);
    int32 HandleGet(soap* soapClient);

    friend int32 handle_post_plugin(soap* soapClient);
    int32 HandlePost(soap* soapClient);

    int32 SendResponse(soap* soapClient, google::protobuf::Message const& response);

    std::string CalculateShaPassHash(std::string const& name, std::string const& password);

    void AddLoginTicket(std::string const& id, std::unique_ptr<Battlenet::Session::AccountInfo> accountInfo);
    void CleanupLoginTickets(boost::system::error_code const& error);

    struct LoginTicket
    {
        // LoginTicket(std::string const& _id, std::unique_ptr<Battlenet::Session::AccountInfo> _accountInfo, std::time_t _ExpiryTime)
        // {
            // Id = std::move(_id);
            // Account = std::move(_accountInfo);
            // ExpiryTime = _ExpiryTime;
        // }

        std::string Id;
        std::unique_ptr<Battlenet::Session::AccountInfo> Account;
        std::time_t ExpiryTime;
    };

    struct ResponseCodePlugin
    {
        static char const* const PluginId;
        static int32 Init(soap* s, soap_plugin*, void*);
        static void Destroy(soap* s, soap_plugin* p);
        static int32 ChangeResponse(soap* s, int32 originalResponse, size_t contentLength);

        int32(*fresponse)(soap* s, int32 status, size_t length);
        int32 ErrorCode;
    };

    struct ContentTypePlugin
    {
        static char const* const PluginId;
        static int32 Init(soap* s, soap_plugin* p, void*);
        static void Destroy(soap* s, soap_plugin* p);
        static int32 OnSetHeader(soap* s, char const* key, char const* value);

        int32(*fposthdr)(soap* s, char const* key, char const* value);
        char const* ContentType;
    };

    std::thread _thread;
    std::atomic<bool> _stopped;
    Battlenet::JSON::Login::FormInputs _formInputs;
    std::string _bindIP;
    int32 _port;
    int32 _waitTime;
    boost::asio::ip::tcp::endpoint _externalAddress;
    boost::asio::ip::tcp::endpoint _localAddress;
    std::mutex _loginTicketMutex;
    std::unordered_map<std::string, LoginTicket> _validLoginTickets;
    boost::asio::deadline_timer* _loginTicketCleanupTimer;
};

#define sLoginService LoginRESTService::Instance()

#endif // LoginRESTService_h__
