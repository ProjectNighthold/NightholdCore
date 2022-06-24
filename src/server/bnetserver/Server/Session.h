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

#ifndef Session_h__
#define Session_h__

#include "Realm.h"
#include "SslContext.h"
#include "SslSocket.h"
#include "Socket.h"
#include "BigNumber.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl.hpp>
#include <google/protobuf/message.h>
#include <memory>
#include "DatabaseEnvFwd.h"

using boost::asio::ip::tcp;

namespace pb = google::protobuf;

namespace bgs
{
    namespace protocol
    {
        class Variant;

        namespace account
        {
            namespace v1
            {
                class GetAccountStateRequest;
                class GetAccountStateResponse;
                class GetGameAccountStateRequest;
                class GetGameAccountStateResponse;
            }
        }

        namespace authentication
        {
            namespace v1
            {
                class LogonRequest;
                class VerifyWebCredentialsRequest;
            }
        }

        namespace game_utilities
        {
            namespace v1
            {
                class ClientRequest;
                class ClientResponse;
                class GetAllValuesForAttributeRequest;
                class GetAllValuesForAttributeResponse;
            }
        }
    }
}

using namespace bgs::protocol;

namespace Battlenet
{
    class Session : public Socket<Session, SslSocket<SslContext>>
    {
        typedef Socket<Session, SslSocket<SslContext>> BattlenetSocket;

    public:
        struct LastPlayedCharacterInfo
        {
            Battlenet::RealmHandle RealmId;
            std::string CharacterName;
            uint64 CharacterGUID;
            uint32 LastPlayedTime;
        };

        struct GameAccountInfo
        {
            void LoadResult(Field* fields);

            uint32 Id;
            std::string Name;
            std::string DisplayName;
            uint32 UnbanDate;
            bool IsSuspended;
            bool IsBanned;
            AccountTypes SecurityLevel;

            std::unordered_map<uint32 /*realmAddress*/, uint8> CharacterCounts;
            std::unordered_map<std::string /*subRegion*/, LastPlayedCharacterInfo> LastPlayedCharacters;
        };

        struct AccountInfo
        {
            void LoadResult(PreparedQueryResult result);

            uint32 Id;
            std::string Login;
            bool IsLockedToIP;
            std::string LockCountry;
            std::string LastIP;
            uint32 FailedLogins;
            bool IsSuspended;
            bool IsBanned;
            uint8 IsActivated;
            uint32 Pid;

            std::unordered_map<uint32, GameAccountInfo> GameAccounts;
        };

        explicit Session(tcp::socket&& socket);
        ~Session();

        void Start() override;
        bool Update() override;

        uint32 GetAccountId() const;
        uint32 GetGameAccountId() const;

        void SendResponse(uint32 token, pb::Message const* response);
        void SendResponse(uint32 token, uint32 status);

        void SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request, std::function<void(MessageBuffer)> callback);
        void SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request);

        uint32 HandleLogon(authentication::v1::LogonRequest const* logonRequest);
        uint32 HandleVerifyWebCredentials(authentication::v1::VerifyWebCredentialsRequest const* verifyWebCredentialsRequest);
        uint32 HandleGetAccountState(account::v1::GetAccountStateRequest const* request, account::v1::GetAccountStateResponse* response);
        uint32 HandleGetGameAccountState(account::v1::GetGameAccountStateRequest const* request, account::v1::GetGameAccountStateResponse* response);
        uint32 HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response);
        uint32 HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response);

        std::string GetClientInfo() const;

    protected:
        void HandshakeHandler(boost::system::error_code const& error);
        void ReadHandler() override;
        bool ReadHeaderLengthHandler();
        bool ReadHeaderHandler();
        bool ReadDataHandler();

    private:
        void AsyncWrite(MessageBuffer* packet);

        void AsyncHandshake();

        typedef uint32(Session::*ClientRequestHandler)(std::unordered_map<std::string, Variant const*> const&, game_utilities::v1::ClientResponse*);
        static std::unordered_map<std::string, ClientRequestHandler> const ClientRequestHandlers;

        uint32 GetRealmListTicket(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);
        uint32 GetLastCharPlayed(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);
        uint32 GetRealmList(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);
        uint32 JoinRealm(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);

        MessageBuffer _headerLengthBuffer;
        MessageBuffer _headerBuffer;
        MessageBuffer _packetBuffer;

        std::unique_ptr<AccountInfo> _accountInfo;
        GameAccountInfo* _gameAccountInfo;          // Points at selected game account (inside _gameAccounts)

        std::string _locale;
        std::string _os;
        uint32 _build;

        std::string _ipCountry;

        std::array<uint8, 32> _clientSecret{};

        bool _authed;

        std::unordered_map<uint32, std::function<void(MessageBuffer)>> _responseCallbacks;
        uint32 _requestToken;
    };
}

#endif // Session_h__
