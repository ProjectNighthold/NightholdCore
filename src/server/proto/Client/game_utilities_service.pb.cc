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

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "game_utilities_service.pb.h"

#include <algorithm>
#include <utility>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
#include "Log.h"
#include "BattlenetRpcErrorCodes.h"
// @@protoc_insertion_point(includes)

// Fix stupid windows.h included from Log.h->Common.h
#ifdef SendMessage
#undef SendMessage
#endif

namespace bgs {
namespace protocol {
namespace game_utilities {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ClientRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClientRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ClientResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClientResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ServerRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServerRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ServerResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServerResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* PresenceChannelCreatedRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PresenceChannelCreatedRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetPlayerVariablesRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetPlayerVariablesRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetPlayerVariablesResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetPlayerVariablesResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountOnlineNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountOnlineNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountOfflineNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountOfflineNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAchievementsFileRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAchievementsFileRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAchievementsFileResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAchievementsFileResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAllValuesForAttributeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAllValuesForAttributeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAllValuesForAttributeResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAllValuesForAttributeResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* GameUtilitiesService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_game_5futilities_5fservice_2eproto() {
  protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "game_utilities_service.proto");
  GOOGLE_CHECK(file != NULL);
  ClientRequest_descriptor_ = file->message_type(0);
  static const int ClientRequest_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, client_info_),
  };
  ClientRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClientRequest_descriptor_,
      ClientRequest::default_instance_,
      ClientRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClientRequest));
  ClientResponse_descriptor_ = file->message_type(1);
  static const int ClientResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientResponse, attribute_),
  };
  ClientResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClientResponse_descriptor_,
      ClientResponse::default_instance_,
      ClientResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClientResponse));
  ServerRequest_descriptor_ = file->message_type(2);
  static const int ServerRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerRequest, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerRequest, host_),
  };
  ServerRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ServerRequest_descriptor_,
      ServerRequest::default_instance_,
      ServerRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ServerRequest));
  ServerResponse_descriptor_ = file->message_type(3);
  static const int ServerResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerResponse, attribute_),
  };
  ServerResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ServerResponse_descriptor_,
      ServerResponse::default_instance_,
      ServerResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ServerResponse));
  PresenceChannelCreatedRequest_descriptor_ = file->message_type(4);
  static const int PresenceChannelCreatedRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, host_),
  };
  PresenceChannelCreatedRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PresenceChannelCreatedRequest_descriptor_,
      PresenceChannelCreatedRequest::default_instance_,
      PresenceChannelCreatedRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PresenceChannelCreatedRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PresenceChannelCreatedRequest));
  GetPlayerVariablesRequest_descriptor_ = file->message_type(5);
  static const int GetPlayerVariablesRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesRequest, player_variables_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesRequest, host_),
  };
  GetPlayerVariablesRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetPlayerVariablesRequest_descriptor_,
      GetPlayerVariablesRequest::default_instance_,
      GetPlayerVariablesRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetPlayerVariablesRequest));
  GetPlayerVariablesResponse_descriptor_ = file->message_type(6);
  static const int GetPlayerVariablesResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesResponse, player_variables_),
  };
  GetPlayerVariablesResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetPlayerVariablesResponse_descriptor_,
      GetPlayerVariablesResponse::default_instance_,
      GetPlayerVariablesResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetPlayerVariablesResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetPlayerVariablesResponse));
  GameAccountOnlineNotification_descriptor_ = file->message_type(7);
  static const int GameAccountOnlineNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOnlineNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOnlineNotification, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOnlineNotification, session_id_),
  };
  GameAccountOnlineNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountOnlineNotification_descriptor_,
      GameAccountOnlineNotification::default_instance_,
      GameAccountOnlineNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOnlineNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOnlineNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountOnlineNotification));
  GameAccountOfflineNotification_descriptor_ = file->message_type(8);
  static const int GameAccountOfflineNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOfflineNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOfflineNotification, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOfflineNotification, session_id_),
  };
  GameAccountOfflineNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountOfflineNotification_descriptor_,
      GameAccountOfflineNotification::default_instance_,
      GameAccountOfflineNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOfflineNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountOfflineNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountOfflineNotification));
  GetAchievementsFileRequest_descriptor_ = file->message_type(9);
  static const int GetAchievementsFileRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileRequest, host_),
  };
  GetAchievementsFileRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAchievementsFileRequest_descriptor_,
      GetAchievementsFileRequest::default_instance_,
      GetAchievementsFileRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAchievementsFileRequest));
  GetAchievementsFileResponse_descriptor_ = file->message_type(10);
  static const int GetAchievementsFileResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileResponse, content_handle_),
  };
  GetAchievementsFileResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAchievementsFileResponse_descriptor_,
      GetAchievementsFileResponse::default_instance_,
      GetAchievementsFileResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAchievementsFileResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAchievementsFileResponse));
  GetAllValuesForAttributeRequest_descriptor_ = file->message_type(11);
  static const int GetAllValuesForAttributeRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeRequest, attribute_key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeRequest, program_),
  };
  GetAllValuesForAttributeRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAllValuesForAttributeRequest_descriptor_,
      GetAllValuesForAttributeRequest::default_instance_,
      GetAllValuesForAttributeRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAllValuesForAttributeRequest));
  GetAllValuesForAttributeResponse_descriptor_ = file->message_type(12);
  static const int GetAllValuesForAttributeResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeResponse, attribute_value_),
  };
  GetAllValuesForAttributeResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAllValuesForAttributeResponse_descriptor_,
      GetAllValuesForAttributeResponse::default_instance_,
      GetAllValuesForAttributeResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAllValuesForAttributeResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAllValuesForAttributeResponse));
  GameUtilitiesService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_game_5futilities_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClientRequest_descriptor_, &ClientRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClientResponse_descriptor_, &ClientResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ServerRequest_descriptor_, &ServerRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ServerResponse_descriptor_, &ServerResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PresenceChannelCreatedRequest_descriptor_, &PresenceChannelCreatedRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetPlayerVariablesRequest_descriptor_, &GetPlayerVariablesRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetPlayerVariablesResponse_descriptor_, &GetPlayerVariablesResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountOnlineNotification_descriptor_, &GameAccountOnlineNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountOfflineNotification_descriptor_, &GameAccountOfflineNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAchievementsFileRequest_descriptor_, &GetAchievementsFileRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAchievementsFileResponse_descriptor_, &GetAchievementsFileResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAllValuesForAttributeRequest_descriptor_, &GetAllValuesForAttributeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAllValuesForAttributeResponse_descriptor_, &GetAllValuesForAttributeResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_game_5futilities_5fservice_2eproto() {
  delete ClientRequest::default_instance_;
  delete ClientRequest_reflection_;
  delete ClientResponse::default_instance_;
  delete ClientResponse_reflection_;
  delete ServerRequest::default_instance_;
  delete ServerRequest_reflection_;
  delete ServerResponse::default_instance_;
  delete ServerResponse_reflection_;
  delete PresenceChannelCreatedRequest::default_instance_;
  delete PresenceChannelCreatedRequest_reflection_;
  delete GetPlayerVariablesRequest::default_instance_;
  delete GetPlayerVariablesRequest_reflection_;
  delete GetPlayerVariablesResponse::default_instance_;
  delete GetPlayerVariablesResponse_reflection_;
  delete GameAccountOnlineNotification::default_instance_;
  delete GameAccountOnlineNotification_reflection_;
  delete GameAccountOfflineNotification::default_instance_;
  delete GameAccountOfflineNotification_reflection_;
  delete GetAchievementsFileRequest::default_instance_;
  delete GetAchievementsFileRequest_reflection_;
  delete GetAchievementsFileResponse::default_instance_;
  delete GetAchievementsFileResponse_reflection_;
  delete GetAllValuesForAttributeRequest::default_instance_;
  delete GetAllValuesForAttributeRequest_reflection_;
  delete GetAllValuesForAttributeResponse::default_instance_;
  delete GetAllValuesForAttributeResponse_reflection_;
}

void protobuf_AddDesc_game_5futilities_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::game_utilities::v1::protobuf_AddDesc_game_5futilities_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034game_utilities_service.proto\022\036bgs.prot"
    "ocol.game_utilities.v1\032\025attribute_types."
    "proto\032\032content_handle_types.proto\032\022entit"
    "y_types.proto\032\032game_utilities_types.prot"
    "o\032\017rpc_types.proto\"\221\002\n\rClientRequest\022*\n\t"
    "attribute\030\001 \003(\0132\027.bgs.protocol.Attribute"
    "\022%\n\004host\030\002 \001(\0132\027.bgs.protocol.ProcessId\022"
    "*\n\naccount_id\030\003 \001(\0132\026.bgs.protocol.Entit"
    "yId\022/\n\017game_account_id\030\004 \001(\0132\026.bgs.proto"
    "col.EntityId\022\017\n\007program\030\005 \001(\007\022\?\n\013client_"
    "info\030\006 \001(\0132*.bgs.protocol.game_utilities"
    ".v1.ClientInfo\"<\n\016ClientResponse\022*\n\tattr"
    "ibute\030\001 \003(\0132\027.bgs.protocol.Attribute\"s\n\r"
    "ServerRequest\022*\n\tattribute\030\001 \003(\0132\027.bgs.p"
    "rotocol.Attribute\022\017\n\007program\030\002 \002(\007\022%\n\004ho"
    "st\030\003 \001(\0132\027.bgs.protocol.ProcessId\"<\n\016Ser"
    "verResponse\022*\n\tattribute\030\001 \003(\0132\027.bgs.pro"
    "tocol.Attribute\"\307\001\n\035PresenceChannelCreat"
    "edRequest\022\"\n\002id\030\001 \002(\0132\026.bgs.protocol.Ent"
    "ityId\022/\n\017game_account_id\030\003 \001(\0132\026.bgs.pro"
    "tocol.EntityId\022*\n\naccount_id\030\004 \001(\0132\026.bgs"
    ".protocol.EntityId\022%\n\004host\030\005 \001(\0132\027.bgs.p"
    "rotocol.ProcessId\"\215\001\n\031GetPlayerVariables"
    "Request\022I\n\020player_variables\030\001 \003(\0132/.bgs."
    "protocol.game_utilities.v1.PlayerVariabl"
    "es\022%\n\004host\030\002 \001(\0132\027.bgs.protocol.ProcessI"
    "d\"g\n\032GetPlayerVariablesResponse\022I\n\020playe"
    "r_variables\030\001 \003(\0132/.bgs.protocol.game_ut"
    "ilities.v1.PlayerVariables\"\213\001\n\035GameAccou"
    "ntOnlineNotification\022/\n\017game_account_id\030"
    "\001 \002(\0132\026.bgs.protocol.EntityId\022%\n\004host\030\002 "
    "\001(\0132\027.bgs.protocol.ProcessId\022\022\n\nsession_"
    "id\030\003 \001(\t\"\214\001\n\036GameAccountOfflineNotificat"
    "ion\022/\n\017game_account_id\030\001 \002(\0132\026.bgs.proto"
    "col.EntityId\022%\n\004host\030\002 \001(\0132\027.bgs.protoco"
    "l.ProcessId\022\022\n\nsession_id\030\003 \001(\t\"C\n\032GetAc"
    "hievementsFileRequest\022%\n\004host\030\001 \001(\0132\027.bg"
    "s.protocol.ProcessId\"R\n\033GetAchievementsF"
    "ileResponse\0223\n\016content_handle\030\001 \001(\0132\033.bg"
    "s.protocol.ContentHandle\"s\n\037GetAllValues"
    "ForAttributeRequest\022\025\n\rattribute_key\030\001 \001"
    "(\t\022(\n\010agent_id\030\002 \001(\0132\026.bgs.protocol.Enti"
    "tyId\022\017\n\007program\030\005 \001(\007\"R\n GetAllValuesFor"
    "AttributeResponse\022.\n\017attribute_value\030\001 \003"
    "(\0132\025.bgs.protocol.Variant2\365\010\n\024GameUtilit"
    "iesService\022{\n\024ProcessClientRequest\022-.bgs"
    ".protocol.game_utilities.v1.ClientReques"
    "t\032..bgs.protocol.game_utilities.v1.Clien"
    "tResponse\"\004\200\265\030\001\022s\n\026PresenceChannelCreate"
    "d\022=.bgs.protocol.game_utilities.v1.Prese"
    "nceChannelCreatedRequest\032\024.bgs.protocol."
    "NoData\"\004\200\265\030\002\022\221\001\n\022GetPlayerVariables\0229.bg"
    "s.protocol.game_utilities.v1.GetPlayerVa"
    "riablesRequest\032:.bgs.protocol.game_utili"
    "ties.v1.GetPlayerVariablesResponse\"\004\200\265\030\003"
    "\022{\n\024ProcessServerRequest\022-.bgs.protocol."
    "game_utilities.v1.ServerRequest\032..bgs.pr"
    "otocol.game_utilities.v1.ServerResponse\""
    "\004\200\265\030\006\022u\n\023OnGameAccountOnline\022=.bgs.proto"
    "col.game_utilities.v1.GameAccountOnlineN"
    "otification\032\031.bgs.protocol.NO_RESPONSE\"\004"
    "\200\265\030\007\022w\n\024OnGameAccountOffline\022>.bgs.proto"
    "col.game_utilities.v1.GameAccountOffline"
    "Notification\032\031.bgs.protocol.NO_RESPONSE\""
    "\004\200\265\030\010\022\224\001\n\023GetAchievementsFile\022:.bgs.prot"
    "ocol.game_utilities.v1.GetAchievementsFi"
    "leRequest\032;.bgs.protocol.game_utilities."
    "v1.GetAchievementsFileResponse\"\004\200\265\030\t\022\243\001\n"
    "\030GetAllValuesForAttribute\022\?.bgs.protocol"
    ".game_utilities.v1.GetAllValuesForAttrib"
    "uteRequest\032@.bgs.protocol.game_utilities"
    ".v1.GetAllValuesForAttributeResponse\"\004\200\265"
    "\030\n\032-\312>*bnet.protocol.game_utilities.Game"
    "UtilitiesBD\n\037bnet.protocol.game_utilitie"
    "s.v1B\031GameUtilitiesServiceProtoH\001\200\001\000\210\001\001", 2999);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "game_utilities_service.proto", &protobuf_RegisterTypes);
  ClientRequest::default_instance_ = new ClientRequest();
  ClientResponse::default_instance_ = new ClientResponse();
  ServerRequest::default_instance_ = new ServerRequest();
  ServerResponse::default_instance_ = new ServerResponse();
  PresenceChannelCreatedRequest::default_instance_ = new PresenceChannelCreatedRequest();
  GetPlayerVariablesRequest::default_instance_ = new GetPlayerVariablesRequest();
  GetPlayerVariablesResponse::default_instance_ = new GetPlayerVariablesResponse();
  GameAccountOnlineNotification::default_instance_ = new GameAccountOnlineNotification();
  GameAccountOfflineNotification::default_instance_ = new GameAccountOfflineNotification();
  GetAchievementsFileRequest::default_instance_ = new GetAchievementsFileRequest();
  GetAchievementsFileResponse::default_instance_ = new GetAchievementsFileResponse();
  GetAllValuesForAttributeRequest::default_instance_ = new GetAllValuesForAttributeRequest();
  GetAllValuesForAttributeResponse::default_instance_ = new GetAllValuesForAttributeResponse();
  ClientRequest::default_instance_->InitAsDefaultInstance();
  ClientResponse::default_instance_->InitAsDefaultInstance();
  ServerRequest::default_instance_->InitAsDefaultInstance();
  ServerResponse::default_instance_->InitAsDefaultInstance();
  PresenceChannelCreatedRequest::default_instance_->InitAsDefaultInstance();
  GetPlayerVariablesRequest::default_instance_->InitAsDefaultInstance();
  GetPlayerVariablesResponse::default_instance_->InitAsDefaultInstance();
  GameAccountOnlineNotification::default_instance_->InitAsDefaultInstance();
  GameAccountOfflineNotification::default_instance_->InitAsDefaultInstance();
  GetAchievementsFileRequest::default_instance_->InitAsDefaultInstance();
  GetAchievementsFileResponse::default_instance_->InitAsDefaultInstance();
  GetAllValuesForAttributeRequest::default_instance_->InitAsDefaultInstance();
  GetAllValuesForAttributeResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_game_5futilities_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_game_5futilities_5fservice_2eproto {
  StaticDescriptorInitializer_game_5futilities_5fservice_2eproto() {
    protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  }
} static_descriptor_initializer_game_5futilities_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ClientRequest::kAttributeFieldNumber;
const int ClientRequest::kHostFieldNumber;
const int ClientRequest::kAccountIdFieldNumber;
const int ClientRequest::kGameAccountIdFieldNumber;
const int ClientRequest::kProgramFieldNumber;
const int ClientRequest::kClientInfoFieldNumber;
#endif  // !_MSC_VER

ClientRequest::ClientRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.ClientRequest)
}

void ClientRequest::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  client_info_ = const_cast< ::bgs::protocol::game_utilities::v1::ClientInfo*>(&::bgs::protocol::game_utilities::v1::ClientInfo::default_instance());
}

ClientRequest::ClientRequest(const ClientRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.ClientRequest)
}

void ClientRequest::SharedCtor() {
  _cached_size_ = 0;
  host_ = NULL;
  account_id_ = NULL;
  game_account_id_ = NULL;
  program_ = 0u;
  client_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClientRequest::~ClientRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.ClientRequest)
  SharedDtor();
}

void ClientRequest::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
    delete account_id_;
    delete game_account_id_;
    delete client_info_;
  }
}

void ClientRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClientRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientRequest_descriptor_;
}

const ClientRequest& ClientRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

ClientRequest* ClientRequest::default_instance_ = NULL;

ClientRequest* ClientRequest::New() const {
  return new ClientRequest;
}

void ClientRequest::Clear() {
  if (_has_bits_[0 / 32] & 62) {
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    program_ = 0u;
    if (has_client_info()) {
      if (client_info_ != NULL) client_info_->::bgs::protocol::game_utilities::v1::ClientInfo::Clear();
    }
  }
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ClientRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.ClientRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
        if (input->ExpectTag(18)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 2;
      case 2: {
        if (tag == 18) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 3;
      case 3: {
        if (tag == 26) {
         parse_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_game_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId game_account_id = 4;
      case 4: {
        if (tag == 34) {
         parse_game_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_program;
        break;
      }

      // optional fixed32 program = 5;
      case 5: {
        if (tag == 45) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_client_info;
        break;
      }

      // optional .bgs.protocol.game_utilities.v1.ClientInfo client_info = 6;
      case 6: {
        if (tag == 50) {
         parse_client_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_client_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.ClientRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.ClientRequest)
  return false;
#undef DO_
}

void ClientRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.ClientRequest)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->host(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_id(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 4;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->game_account_id(), output);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(5, this->program(), output);
  }

  // optional .bgs.protocol.game_utilities.v1.ClientInfo client_info = 6;
  if (has_client_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->client_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.ClientRequest)
}

::google::protobuf::uint8* ClientRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.ClientRequest)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->host(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_id(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 4;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->game_account_id(), target);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(5, this->program(), target);
  }

  // optional .bgs.protocol.game_utilities.v1.ClientInfo client_info = 6;
  if (has_client_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->client_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.ClientRequest)
  return target;
}

int ClientRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional .bgs.protocol.ProcessId host = 2;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional .bgs.protocol.EntityId account_id = 3;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional .bgs.protocol.EntityId game_account_id = 4;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional fixed32 program = 5;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional .bgs.protocol.game_utilities.v1.ClientInfo client_info = 6;
    if (has_client_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->client_info());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ClientRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ClientRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ClientRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ClientRequest::MergeFrom(const ClientRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_client_info()) {
      mutable_client_info()->::bgs::protocol::game_utilities::v1::ClientInfo::MergeFrom(from.client_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ClientRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClientRequest::CopyFrom(const ClientRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void ClientRequest::Swap(ClientRequest* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    std::swap(host_, other->host_);
    std::swap(account_id_, other->account_id_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(program_, other->program_);
    std::swap(client_info_, other->client_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ClientRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClientRequest_descriptor_;
  metadata.reflection = ClientRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ClientResponse::kAttributeFieldNumber;
#endif  // !_MSC_VER

ClientResponse::ClientResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.ClientResponse)
}

void ClientResponse::InitAsDefaultInstance() {
}

ClientResponse::ClientResponse(const ClientResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.ClientResponse)
}

void ClientResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClientResponse::~ClientResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.ClientResponse)
  SharedDtor();
}

void ClientResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ClientResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClientResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientResponse_descriptor_;
}

const ClientResponse& ClientResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

ClientResponse* ClientResponse::default_instance_ = NULL;

ClientResponse* ClientResponse::New() const {
  return new ClientResponse;
}

void ClientResponse::Clear() {
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ClientResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.ClientResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.ClientResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.ClientResponse)
  return false;
#undef DO_
}

void ClientResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.ClientResponse)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.ClientResponse)
}

::google::protobuf::uint8* ClientResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.ClientResponse)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.ClientResponse)
  return target;
}

int ClientResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ClientResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ClientResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ClientResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ClientResponse::MergeFrom(const ClientResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ClientResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClientResponse::CopyFrom(const ClientResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void ClientResponse::Swap(ClientResponse* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ClientResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClientResponse_descriptor_;
  metadata.reflection = ClientResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ServerRequest::kAttributeFieldNumber;
const int ServerRequest::kProgramFieldNumber;
const int ServerRequest::kHostFieldNumber;
#endif  // !_MSC_VER

ServerRequest::ServerRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.ServerRequest)
}

void ServerRequest::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

ServerRequest::ServerRequest(const ServerRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.ServerRequest)
}

void ServerRequest::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  host_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ServerRequest::~ServerRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.ServerRequest)
  SharedDtor();
}

void ServerRequest::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
  }
}

void ServerRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServerRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerRequest_descriptor_;
}

const ServerRequest& ServerRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

ServerRequest* ServerRequest::default_instance_ = NULL;

ServerRequest* ServerRequest::New() const {
  return new ServerRequest;
}

void ServerRequest::Clear() {
  if (_has_bits_[0 / 32] & 6) {
    program_ = 0u;
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
  }
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ServerRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.ServerRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
        if (input->ExpectTag(21)) goto parse_program;
        break;
      }

      // required fixed32 program = 2;
      case 2: {
        if (tag == 21) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 3;
      case 3: {
        if (tag == 26) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.ServerRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.ServerRequest)
  return false;
#undef DO_
}

void ServerRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.ServerRequest)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
  }

  // required fixed32 program = 2;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->program(), output);
  }

  // optional .bgs.protocol.ProcessId host = 3;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->host(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.ServerRequest)
}

::google::protobuf::uint8* ServerRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.ServerRequest)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
  }

  // required fixed32 program = 2;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->program(), target);
  }

  // optional .bgs.protocol.ProcessId host = 3;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->host(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.ServerRequest)
  return target;
}

int ServerRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // required fixed32 program = 2;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional .bgs.protocol.ProcessId host = 3;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ServerRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ServerRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ServerRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ServerRequest::MergeFrom(const ServerRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ServerRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServerRequest::CopyFrom(const ServerRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ServerRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void ServerRequest::Swap(ServerRequest* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    std::swap(program_, other->program_);
    std::swap(host_, other->host_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ServerRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServerRequest_descriptor_;
  metadata.reflection = ServerRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ServerResponse::kAttributeFieldNumber;
#endif  // !_MSC_VER

ServerResponse::ServerResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.ServerResponse)
}

void ServerResponse::InitAsDefaultInstance() {
}

ServerResponse::ServerResponse(const ServerResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.ServerResponse)
}

void ServerResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ServerResponse::~ServerResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.ServerResponse)
  SharedDtor();
}

void ServerResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ServerResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServerResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerResponse_descriptor_;
}

const ServerResponse& ServerResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

ServerResponse* ServerResponse::default_instance_ = NULL;

ServerResponse* ServerResponse::New() const {
  return new ServerResponse;
}

void ServerResponse::Clear() {
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ServerResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.ServerResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.ServerResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.ServerResponse)
  return false;
#undef DO_
}

void ServerResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.ServerResponse)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.ServerResponse)
}

::google::protobuf::uint8* ServerResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.ServerResponse)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.ServerResponse)
  return target;
}

int ServerResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ServerResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ServerResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ServerResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ServerResponse::MergeFrom(const ServerResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ServerResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServerResponse::CopyFrom(const ServerResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ServerResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void ServerResponse::Swap(ServerResponse* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ServerResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServerResponse_descriptor_;
  metadata.reflection = ServerResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int PresenceChannelCreatedRequest::kIdFieldNumber;
const int PresenceChannelCreatedRequest::kGameAccountIdFieldNumber;
const int PresenceChannelCreatedRequest::kAccountIdFieldNumber;
const int PresenceChannelCreatedRequest::kHostFieldNumber;
#endif  // !_MSC_VER

PresenceChannelCreatedRequest::PresenceChannelCreatedRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
}

void PresenceChannelCreatedRequest::InitAsDefaultInstance() {
  id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

PresenceChannelCreatedRequest::PresenceChannelCreatedRequest(const PresenceChannelCreatedRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
}

void PresenceChannelCreatedRequest::SharedCtor() {
  _cached_size_ = 0;
  id_ = NULL;
  game_account_id_ = NULL;
  account_id_ = NULL;
  host_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PresenceChannelCreatedRequest::~PresenceChannelCreatedRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  SharedDtor();
}

void PresenceChannelCreatedRequest::SharedDtor() {
  if (this != default_instance_) {
    delete id_;
    delete game_account_id_;
    delete account_id_;
    delete host_;
  }
}

void PresenceChannelCreatedRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PresenceChannelCreatedRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PresenceChannelCreatedRequest_descriptor_;
}

const PresenceChannelCreatedRequest& PresenceChannelCreatedRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

PresenceChannelCreatedRequest* PresenceChannelCreatedRequest::default_instance_ = NULL;

PresenceChannelCreatedRequest* PresenceChannelCreatedRequest::New() const {
  return new PresenceChannelCreatedRequest;
}

void PresenceChannelCreatedRequest::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_id()) {
      if (id_ != NULL) id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PresenceChannelCreatedRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_game_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId game_account_id = 3;
      case 3: {
        if (tag == 26) {
         parse_game_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 4;
      case 4: {
        if (tag == 34) {
         parse_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 5;
      case 5: {
        if (tag == 42) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  return false;
#undef DO_
}

void PresenceChannelCreatedRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  // required .bgs.protocol.EntityId id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->id(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 3;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->game_account_id(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 4;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->account_id(), output);
  }

  // optional .bgs.protocol.ProcessId host = 5;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->host(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
}

::google::protobuf::uint8* PresenceChannelCreatedRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  // required .bgs.protocol.EntityId id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->id(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 3;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->game_account_id(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 4;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->account_id(), target);
  }

  // optional .bgs.protocol.ProcessId host = 5;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->host(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest)
  return target;
}

int PresenceChannelCreatedRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // optional .bgs.protocol.EntityId game_account_id = 3;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.EntityId account_id = 4;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional .bgs.protocol.ProcessId host = 5;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PresenceChannelCreatedRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PresenceChannelCreatedRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PresenceChannelCreatedRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PresenceChannelCreatedRequest::MergeFrom(const PresenceChannelCreatedRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      mutable_id()->::bgs::protocol::EntityId::MergeFrom(from.id());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PresenceChannelCreatedRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PresenceChannelCreatedRequest::CopyFrom(const PresenceChannelCreatedRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PresenceChannelCreatedRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void PresenceChannelCreatedRequest::Swap(PresenceChannelCreatedRequest* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(account_id_, other->account_id_);
    std::swap(host_, other->host_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PresenceChannelCreatedRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PresenceChannelCreatedRequest_descriptor_;
  metadata.reflection = PresenceChannelCreatedRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetPlayerVariablesRequest::kPlayerVariablesFieldNumber;
const int GetPlayerVariablesRequest::kHostFieldNumber;
#endif  // !_MSC_VER

GetPlayerVariablesRequest::GetPlayerVariablesRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
}

void GetPlayerVariablesRequest::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

GetPlayerVariablesRequest::GetPlayerVariablesRequest(const GetPlayerVariablesRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
}

void GetPlayerVariablesRequest::SharedCtor() {
  _cached_size_ = 0;
  host_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetPlayerVariablesRequest::~GetPlayerVariablesRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  SharedDtor();
}

void GetPlayerVariablesRequest::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
  }
}

void GetPlayerVariablesRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetPlayerVariablesRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetPlayerVariablesRequest_descriptor_;
}

const GetPlayerVariablesRequest& GetPlayerVariablesRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetPlayerVariablesRequest* GetPlayerVariablesRequest::default_instance_ = NULL;

GetPlayerVariablesRequest* GetPlayerVariablesRequest::New() const {
  return new GetPlayerVariablesRequest;
}

void GetPlayerVariablesRequest::Clear() {
  if (has_host()) {
    if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
  }
  player_variables_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetPlayerVariablesRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
      case 1: {
        if (tag == 10) {
         parse_player_variables:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player_variables()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_player_variables;
        if (input->ExpectTag(18)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 2;
      case 2: {
        if (tag == 18) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  return false;
#undef DO_
}

void GetPlayerVariablesRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  for (int i = 0; i < this->player_variables_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player_variables(i), output);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->host(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
}

::google::protobuf::uint8* GetPlayerVariablesRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  for (int i = 0; i < this->player_variables_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player_variables(i), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->host(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest)
  return target;
}

int GetPlayerVariablesRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional .bgs.protocol.ProcessId host = 2;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

  }
  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  total_size += 1 * this->player_variables_size();
  for (int i = 0; i < this->player_variables_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player_variables(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetPlayerVariablesRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetPlayerVariablesRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetPlayerVariablesRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetPlayerVariablesRequest::MergeFrom(const GetPlayerVariablesRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_variables_.MergeFrom(from.player_variables_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetPlayerVariablesRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetPlayerVariablesRequest::CopyFrom(const GetPlayerVariablesRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetPlayerVariablesRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->player_variables())) return false;
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void GetPlayerVariablesRequest::Swap(GetPlayerVariablesRequest* other) {
  if (other != this) {
    player_variables_.Swap(&other->player_variables_);
    std::swap(host_, other->host_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetPlayerVariablesRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetPlayerVariablesRequest_descriptor_;
  metadata.reflection = GetPlayerVariablesRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetPlayerVariablesResponse::kPlayerVariablesFieldNumber;
#endif  // !_MSC_VER

GetPlayerVariablesResponse::GetPlayerVariablesResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
}

void GetPlayerVariablesResponse::InitAsDefaultInstance() {
}

GetPlayerVariablesResponse::GetPlayerVariablesResponse(const GetPlayerVariablesResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
}

void GetPlayerVariablesResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetPlayerVariablesResponse::~GetPlayerVariablesResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  SharedDtor();
}

void GetPlayerVariablesResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetPlayerVariablesResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetPlayerVariablesResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetPlayerVariablesResponse_descriptor_;
}

const GetPlayerVariablesResponse& GetPlayerVariablesResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetPlayerVariablesResponse* GetPlayerVariablesResponse::default_instance_ = NULL;

GetPlayerVariablesResponse* GetPlayerVariablesResponse::New() const {
  return new GetPlayerVariablesResponse;
}

void GetPlayerVariablesResponse::Clear() {
  player_variables_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetPlayerVariablesResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
      case 1: {
        if (tag == 10) {
         parse_player_variables:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player_variables()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_player_variables;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  return false;
#undef DO_
}

void GetPlayerVariablesResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  for (int i = 0; i < this->player_variables_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player_variables(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
}

::google::protobuf::uint8* GetPlayerVariablesResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  for (int i = 0; i < this->player_variables_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player_variables(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse)
  return target;
}

int GetPlayerVariablesResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.game_utilities.v1.PlayerVariables player_variables = 1;
  total_size += 1 * this->player_variables_size();
  for (int i = 0; i < this->player_variables_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player_variables(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetPlayerVariablesResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetPlayerVariablesResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetPlayerVariablesResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetPlayerVariablesResponse::MergeFrom(const GetPlayerVariablesResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_variables_.MergeFrom(from.player_variables_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetPlayerVariablesResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetPlayerVariablesResponse::CopyFrom(const GetPlayerVariablesResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetPlayerVariablesResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->player_variables())) return false;
  return true;
}

void GetPlayerVariablesResponse::Swap(GetPlayerVariablesResponse* other) {
  if (other != this) {
    player_variables_.Swap(&other->player_variables_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetPlayerVariablesResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetPlayerVariablesResponse_descriptor_;
  metadata.reflection = GetPlayerVariablesResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountOnlineNotification::kGameAccountIdFieldNumber;
const int GameAccountOnlineNotification::kHostFieldNumber;
const int GameAccountOnlineNotification::kSessionIdFieldNumber;
#endif  // !_MSC_VER

GameAccountOnlineNotification::GameAccountOnlineNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
}

void GameAccountOnlineNotification::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

GameAccountOnlineNotification::GameAccountOnlineNotification(const GameAccountOnlineNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
}

void GameAccountOnlineNotification::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  game_account_id_ = NULL;
  host_ = NULL;
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountOnlineNotification::~GameAccountOnlineNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  SharedDtor();
}

void GameAccountOnlineNotification::SharedDtor() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (this != default_instance_) {
    delete game_account_id_;
    delete host_;
  }
}

void GameAccountOnlineNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountOnlineNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountOnlineNotification_descriptor_;
}

const GameAccountOnlineNotification& GameAccountOnlineNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GameAccountOnlineNotification* GameAccountOnlineNotification::default_instance_ = NULL;

GameAccountOnlineNotification* GameAccountOnlineNotification::New() const {
  return new GameAccountOnlineNotification;
}

void GameAccountOnlineNotification::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_session_id()) {
      if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        session_id_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountOnlineNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId game_account_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 2;
      case 2: {
        if (tag == 18) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_session_id;
        break;
      }

      // optional string session_id = 3;
      case 3: {
        if (tag == 26) {
         parse_session_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  return false;
#undef DO_
}

void GameAccountOnlineNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_id(), output);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->host(), output);
  }

  // optional string session_id = 3;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->session_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
}

::google::protobuf::uint8* GameAccountOnlineNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_id(), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->host(), target);
  }

  // optional string session_id = 3;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->session_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GameAccountOnlineNotification)
  return target;
}

int GameAccountOnlineNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId game_account_id = 1;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.ProcessId host = 2;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional string session_id = 3;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameAccountOnlineNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountOnlineNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountOnlineNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountOnlineNotification::MergeFrom(const GameAccountOnlineNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountOnlineNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountOnlineNotification::CopyFrom(const GameAccountOnlineNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountOnlineNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void GameAccountOnlineNotification::Swap(GameAccountOnlineNotification* other) {
  if (other != this) {
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(host_, other->host_);
    std::swap(session_id_, other->session_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountOnlineNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountOnlineNotification_descriptor_;
  metadata.reflection = GameAccountOnlineNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountOfflineNotification::kGameAccountIdFieldNumber;
const int GameAccountOfflineNotification::kHostFieldNumber;
const int GameAccountOfflineNotification::kSessionIdFieldNumber;
#endif  // !_MSC_VER

GameAccountOfflineNotification::GameAccountOfflineNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
}

void GameAccountOfflineNotification::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

GameAccountOfflineNotification::GameAccountOfflineNotification(const GameAccountOfflineNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
}

void GameAccountOfflineNotification::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  game_account_id_ = NULL;
  host_ = NULL;
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountOfflineNotification::~GameAccountOfflineNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  SharedDtor();
}

void GameAccountOfflineNotification::SharedDtor() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (this != default_instance_) {
    delete game_account_id_;
    delete host_;
  }
}

void GameAccountOfflineNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountOfflineNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountOfflineNotification_descriptor_;
}

const GameAccountOfflineNotification& GameAccountOfflineNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GameAccountOfflineNotification* GameAccountOfflineNotification::default_instance_ = NULL;

GameAccountOfflineNotification* GameAccountOfflineNotification::New() const {
  return new GameAccountOfflineNotification;
}

void GameAccountOfflineNotification::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_session_id()) {
      if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        session_id_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountOfflineNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId game_account_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 2;
      case 2: {
        if (tag == 18) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_session_id;
        break;
      }

      // optional string session_id = 3;
      case 3: {
        if (tag == 26) {
         parse_session_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  return false;
#undef DO_
}

void GameAccountOfflineNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_id(), output);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->host(), output);
  }

  // optional string session_id = 3;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->session_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
}

::google::protobuf::uint8* GameAccountOfflineNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_id(), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->host(), target);
  }

  // optional string session_id = 3;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->session_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GameAccountOfflineNotification)
  return target;
}

int GameAccountOfflineNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId game_account_id = 1;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.ProcessId host = 2;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional string session_id = 3;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameAccountOfflineNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountOfflineNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountOfflineNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountOfflineNotification::MergeFrom(const GameAccountOfflineNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountOfflineNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountOfflineNotification::CopyFrom(const GameAccountOfflineNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountOfflineNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void GameAccountOfflineNotification::Swap(GameAccountOfflineNotification* other) {
  if (other != this) {
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(host_, other->host_);
    std::swap(session_id_, other->session_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountOfflineNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountOfflineNotification_descriptor_;
  metadata.reflection = GameAccountOfflineNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAchievementsFileRequest::kHostFieldNumber;
#endif  // !_MSC_VER

GetAchievementsFileRequest::GetAchievementsFileRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
}

void GetAchievementsFileRequest::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

GetAchievementsFileRequest::GetAchievementsFileRequest(const GetAchievementsFileRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
}

void GetAchievementsFileRequest::SharedCtor() {
  _cached_size_ = 0;
  host_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAchievementsFileRequest::~GetAchievementsFileRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  SharedDtor();
}

void GetAchievementsFileRequest::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
  }
}

void GetAchievementsFileRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAchievementsFileRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAchievementsFileRequest_descriptor_;
}

const GetAchievementsFileRequest& GetAchievementsFileRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetAchievementsFileRequest* GetAchievementsFileRequest::default_instance_ = NULL;

GetAchievementsFileRequest* GetAchievementsFileRequest::New() const {
  return new GetAchievementsFileRequest;
}

void GetAchievementsFileRequest::Clear() {
  if (has_host()) {
    if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAchievementsFileRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.ProcessId host = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  return false;
#undef DO_
}

void GetAchievementsFileRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  // optional .bgs.protocol.ProcessId host = 1;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->host(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
}

::google::protobuf::uint8* GetAchievementsFileRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  // optional .bgs.protocol.ProcessId host = 1;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->host(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetAchievementsFileRequest)
  return target;
}

int GetAchievementsFileRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.ProcessId host = 1;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetAchievementsFileRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAchievementsFileRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAchievementsFileRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAchievementsFileRequest::MergeFrom(const GetAchievementsFileRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAchievementsFileRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAchievementsFileRequest::CopyFrom(const GetAchievementsFileRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAchievementsFileRequest::IsInitialized() const {

  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void GetAchievementsFileRequest::Swap(GetAchievementsFileRequest* other) {
  if (other != this) {
    std::swap(host_, other->host_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAchievementsFileRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAchievementsFileRequest_descriptor_;
  metadata.reflection = GetAchievementsFileRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAchievementsFileResponse::kContentHandleFieldNumber;
#endif  // !_MSC_VER

GetAchievementsFileResponse::GetAchievementsFileResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
}

void GetAchievementsFileResponse::InitAsDefaultInstance() {
  content_handle_ = const_cast< ::bgs::protocol::ContentHandle*>(&::bgs::protocol::ContentHandle::default_instance());
}

GetAchievementsFileResponse::GetAchievementsFileResponse(const GetAchievementsFileResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
}

void GetAchievementsFileResponse::SharedCtor() {
  _cached_size_ = 0;
  content_handle_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAchievementsFileResponse::~GetAchievementsFileResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  SharedDtor();
}

void GetAchievementsFileResponse::SharedDtor() {
  if (this != default_instance_) {
    delete content_handle_;
  }
}

void GetAchievementsFileResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAchievementsFileResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAchievementsFileResponse_descriptor_;
}

const GetAchievementsFileResponse& GetAchievementsFileResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetAchievementsFileResponse* GetAchievementsFileResponse::default_instance_ = NULL;

GetAchievementsFileResponse* GetAchievementsFileResponse::New() const {
  return new GetAchievementsFileResponse;
}

void GetAchievementsFileResponse::Clear() {
  if (has_content_handle()) {
    if (content_handle_ != NULL) content_handle_->::bgs::protocol::ContentHandle::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAchievementsFileResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.ContentHandle content_handle = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_content_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  return false;
#undef DO_
}

void GetAchievementsFileResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  // optional .bgs.protocol.ContentHandle content_handle = 1;
  if (has_content_handle()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->content_handle(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
}

::google::protobuf::uint8* GetAchievementsFileResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  // optional .bgs.protocol.ContentHandle content_handle = 1;
  if (has_content_handle()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->content_handle(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetAchievementsFileResponse)
  return target;
}

int GetAchievementsFileResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.ContentHandle content_handle = 1;
    if (has_content_handle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->content_handle());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetAchievementsFileResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAchievementsFileResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAchievementsFileResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAchievementsFileResponse::MergeFrom(const GetAchievementsFileResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_content_handle()) {
      mutable_content_handle()->::bgs::protocol::ContentHandle::MergeFrom(from.content_handle());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAchievementsFileResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAchievementsFileResponse::CopyFrom(const GetAchievementsFileResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAchievementsFileResponse::IsInitialized() const {

  if (has_content_handle()) {
    if (!this->content_handle().IsInitialized()) return false;
  }
  return true;
}

void GetAchievementsFileResponse::Swap(GetAchievementsFileResponse* other) {
  if (other != this) {
    std::swap(content_handle_, other->content_handle_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAchievementsFileResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAchievementsFileResponse_descriptor_;
  metadata.reflection = GetAchievementsFileResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAllValuesForAttributeRequest::kAttributeKeyFieldNumber;
const int GetAllValuesForAttributeRequest::kAgentIdFieldNumber;
const int GetAllValuesForAttributeRequest::kProgramFieldNumber;
#endif  // !_MSC_VER

GetAllValuesForAttributeRequest::GetAllValuesForAttributeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
}

void GetAllValuesForAttributeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetAllValuesForAttributeRequest::GetAllValuesForAttributeRequest(const GetAllValuesForAttributeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
}

void GetAllValuesForAttributeRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  attribute_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  agent_id_ = NULL;
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAllValuesForAttributeRequest::~GetAllValuesForAttributeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  SharedDtor();
}

void GetAllValuesForAttributeRequest::SharedDtor() {
  if (attribute_key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete attribute_key_;
  }
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void GetAllValuesForAttributeRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAllValuesForAttributeRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAllValuesForAttributeRequest_descriptor_;
}

const GetAllValuesForAttributeRequest& GetAllValuesForAttributeRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetAllValuesForAttributeRequest* GetAllValuesForAttributeRequest::default_instance_ = NULL;

GetAllValuesForAttributeRequest* GetAllValuesForAttributeRequest::New() const {
  return new GetAllValuesForAttributeRequest;
}

void GetAllValuesForAttributeRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_attribute_key()) {
      if (attribute_key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        attribute_key_->clear();
      }
    }
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    program_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAllValuesForAttributeRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string attribute_key = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_attribute_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->attribute_key().data(), this->attribute_key().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "attribute_key");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_agent_id;
        break;
      }

      // optional .bgs.protocol.EntityId agent_id = 2;
      case 2: {
        if (tag == 18) {
         parse_agent_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_program;
        break;
      }

      // optional fixed32 program = 5;
      case 5: {
        if (tag == 45) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  return false;
#undef DO_
}

void GetAllValuesForAttributeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  // optional string attribute_key = 1;
  if (has_attribute_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->attribute_key().data(), this->attribute_key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "attribute_key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->attribute_key(), output);
  }

  // optional .bgs.protocol.EntityId agent_id = 2;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->agent_id(), output);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(5, this->program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
}

::google::protobuf::uint8* GetAllValuesForAttributeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  // optional string attribute_key = 1;
  if (has_attribute_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->attribute_key().data(), this->attribute_key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "attribute_key");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->attribute_key(), target);
  }

  // optional .bgs.protocol.EntityId agent_id = 2;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->agent_id(), target);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(5, this->program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest)
  return target;
}

int GetAllValuesForAttributeRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string attribute_key = 1;
    if (has_attribute_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->attribute_key());
    }

    // optional .bgs.protocol.EntityId agent_id = 2;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional fixed32 program = 5;
    if (has_program()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetAllValuesForAttributeRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAllValuesForAttributeRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAllValuesForAttributeRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAllValuesForAttributeRequest::MergeFrom(const GetAllValuesForAttributeRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_attribute_key()) {
      set_attribute_key(from.attribute_key());
    }
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAllValuesForAttributeRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAllValuesForAttributeRequest::CopyFrom(const GetAllValuesForAttributeRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAllValuesForAttributeRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void GetAllValuesForAttributeRequest::Swap(GetAllValuesForAttributeRequest* other) {
  if (other != this) {
    std::swap(attribute_key_, other->attribute_key_);
    std::swap(agent_id_, other->agent_id_);
    std::swap(program_, other->program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAllValuesForAttributeRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAllValuesForAttributeRequest_descriptor_;
  metadata.reflection = GetAllValuesForAttributeRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAllValuesForAttributeResponse::kAttributeValueFieldNumber;
#endif  // !_MSC_VER

GetAllValuesForAttributeResponse::GetAllValuesForAttributeResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
}

void GetAllValuesForAttributeResponse::InitAsDefaultInstance() {
}

GetAllValuesForAttributeResponse::GetAllValuesForAttributeResponse(const GetAllValuesForAttributeResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
}

void GetAllValuesForAttributeResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAllValuesForAttributeResponse::~GetAllValuesForAttributeResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  SharedDtor();
}

void GetAllValuesForAttributeResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetAllValuesForAttributeResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAllValuesForAttributeResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAllValuesForAttributeResponse_descriptor_;
}

const GetAllValuesForAttributeResponse& GetAllValuesForAttributeResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5futilities_5fservice_2eproto();
  return *default_instance_;
}

GetAllValuesForAttributeResponse* GetAllValuesForAttributeResponse::default_instance_ = NULL;

GetAllValuesForAttributeResponse* GetAllValuesForAttributeResponse::New() const {
  return new GetAllValuesForAttributeResponse;
}

void GetAllValuesForAttributeResponse::Clear() {
  attribute_value_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAllValuesForAttributeResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Variant attribute_value = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute_value()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute_value;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  return false;
#undef DO_
}

void GetAllValuesForAttributeResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  // repeated .bgs.protocol.Variant attribute_value = 1;
  for (int i = 0; i < this->attribute_value_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute_value(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
}

::google::protobuf::uint8* GetAllValuesForAttributeResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  // repeated .bgs.protocol.Variant attribute_value = 1;
  for (int i = 0; i < this->attribute_value_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute_value(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse)
  return target;
}

int GetAllValuesForAttributeResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.Variant attribute_value = 1;
  total_size += 1 * this->attribute_value_size();
  for (int i = 0; i < this->attribute_value_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute_value(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetAllValuesForAttributeResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAllValuesForAttributeResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAllValuesForAttributeResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAllValuesForAttributeResponse::MergeFrom(const GetAllValuesForAttributeResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_value_.MergeFrom(from.attribute_value_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAllValuesForAttributeResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAllValuesForAttributeResponse::CopyFrom(const GetAllValuesForAttributeResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAllValuesForAttributeResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute_value())) return false;
  return true;
}

void GetAllValuesForAttributeResponse::Swap(GetAllValuesForAttributeResponse* other) {
  if (other != this) {
    attribute_value_.Swap(&other->attribute_value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAllValuesForAttributeResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAllValuesForAttributeResponse_descriptor_;
  metadata.reflection = GetAllValuesForAttributeResponse_reflection_;
  return metadata;
}


// ===================================================================

GameUtilitiesService::GameUtilitiesService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

GameUtilitiesService::~GameUtilitiesService() {
}

google::protobuf::ServiceDescriptor const* GameUtilitiesService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameUtilitiesService_descriptor_;
}

void GameUtilitiesService::ProcessClientRequest(::bgs::protocol::game_utilities::v1::ClientRequest const* request, std::function<void(::bgs::protocol::game_utilities::v1::ClientResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.ProcessClientRequest(bgs.protocol.game_utilities.v1.ClientRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::game_utilities::v1::ClientResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void GameUtilitiesService::PresenceChannelCreated(::bgs::protocol::game_utilities::v1::PresenceChannelCreatedRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.PresenceChannelCreated(bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void GameUtilitiesService::GetPlayerVariables(::bgs::protocol::game_utilities::v1::GetPlayerVariablesRequest const* request, std::function<void(::bgs::protocol::game_utilities::v1::GetPlayerVariablesResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.GetPlayerVariables(bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::game_utilities::v1::GetPlayerVariablesResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void GameUtilitiesService::ProcessServerRequest(::bgs::protocol::game_utilities::v1::ServerRequest const* request, std::function<void(::bgs::protocol::game_utilities::v1::ServerResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.ProcessServerRequest(bgs.protocol.game_utilities.v1.ServerRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::game_utilities::v1::ServerResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void GameUtilitiesService::OnGameAccountOnline(::bgs::protocol::game_utilities::v1::GameAccountOnlineNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.OnGameAccountOnline(bgs.protocol.game_utilities.v1.GameAccountOnlineNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 7, request);
}

void GameUtilitiesService::OnGameAccountOffline(::bgs::protocol::game_utilities::v1::GameAccountOfflineNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.OnGameAccountOffline(bgs.protocol.game_utilities.v1.GameAccountOfflineNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 8, request);
}

void GameUtilitiesService::GetAchievementsFile(::bgs::protocol::game_utilities::v1::GetAchievementsFileRequest const* request, std::function<void(::bgs::protocol::game_utilities::v1::GetAchievementsFileResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.GetAchievementsFile(bgs.protocol.game_utilities.v1.GetAchievementsFileRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::game_utilities::v1::GetAchievementsFileResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 9, request, std::move(callback));
}

void GameUtilitiesService::GetAllValuesForAttribute(::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeRequest const* request, std::function<void(::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method GameUtilitiesService.GetAllValuesForAttribute(bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 10, request, std::move(callback));
}

void GameUtilitiesService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::game_utilities::v1::ClientRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.ProcessClientRequest server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::game_utilities::v1::ClientResponse response;
      uint32 status = HandleProcessClientRequest(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.ProcessClientRequest(bgs.protocol.game_utilities.v1.ClientRequest{ %s }) returned bgs.protocol.game_utilities.v1.ClientResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::game_utilities::v1::PresenceChannelCreatedRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.PresenceChannelCreated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandlePresenceChannelCreated(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.PresenceChannelCreated(bgs.protocol.game_utilities.v1.PresenceChannelCreatedRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::game_utilities::v1::GetPlayerVariablesRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.GetPlayerVariables server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::game_utilities::v1::GetPlayerVariablesResponse response;
      uint32 status = HandleGetPlayerVariables(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.GetPlayerVariables(bgs.protocol.game_utilities.v1.GetPlayerVariablesRequest{ %s }) returned bgs.protocol.game_utilities.v1.GetPlayerVariablesResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::game_utilities::v1::ServerRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.ProcessServerRequest server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::game_utilities::v1::ServerResponse response;
      uint32 status = HandleProcessServerRequest(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.ProcessServerRequest(bgs.protocol.game_utilities.v1.ServerRequest{ %s }) returned bgs.protocol.game_utilities.v1.ServerResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::game_utilities::v1::GameAccountOnlineNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.OnGameAccountOnline server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameAccountOnline(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.OnGameAccountOnline(bgs.protocol.game_utilities.v1.GameAccountOnlineNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    case 8: {
      ::bgs::protocol::game_utilities::v1::GameAccountOfflineNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.OnGameAccountOffline server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 8, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameAccountOffline(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.OnGameAccountOffline(bgs.protocol.game_utilities.v1.GameAccountOfflineNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 8, token, status);
      break;
    }
    case 9: {
      ::bgs::protocol::game_utilities::v1::GetAchievementsFileRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.GetAchievementsFile server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 9, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::game_utilities::v1::GetAchievementsFileResponse response;
      uint32 status = HandleGetAchievementsFile(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.GetAchievementsFile(bgs.protocol.game_utilities.v1.GetAchievementsFileRequest{ %s }) returned bgs.protocol.game_utilities.v1.GetAchievementsFileResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 9, token, &response);
      else
        SendResponse(service_hash_, 9, token, status);
      break;
    }
    case 10: {
      ::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for GameUtilitiesService.GetAllValuesForAttribute server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 10, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse response;
      uint32 status = HandleGetAllValuesForAttribute(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method GameUtilitiesService.GetAllValuesForAttribute(bgs.protocol.game_utilities.v1.GetAllValuesForAttributeRequest{ %s }) returned bgs.protocol.game_utilities.v1.GetAllValuesForAttributeResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 10, token, &response);
      else
        SendResponse(service_hash_, 10, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 GameUtilitiesService::HandleProcessClientRequest(::bgs::protocol::game_utilities::v1::ClientRequest const* request, ::bgs::protocol::game_utilities::v1::ClientResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.ProcessClientRequest({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandlePresenceChannelCreated(::bgs::protocol::game_utilities::v1::PresenceChannelCreatedRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.PresenceChannelCreated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleGetPlayerVariables(::bgs::protocol::game_utilities::v1::GetPlayerVariablesRequest const* request, ::bgs::protocol::game_utilities::v1::GetPlayerVariablesResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.GetPlayerVariables({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleProcessServerRequest(::bgs::protocol::game_utilities::v1::ServerRequest const* request, ::bgs::protocol::game_utilities::v1::ServerResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.ProcessServerRequest({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleOnGameAccountOnline(::bgs::protocol::game_utilities::v1::GameAccountOnlineNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.OnGameAccountOnline({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleOnGameAccountOffline(::bgs::protocol::game_utilities::v1::GameAccountOfflineNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.OnGameAccountOffline({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleGetAchievementsFile(::bgs::protocol::game_utilities::v1::GetAchievementsFileRequest const* request, ::bgs::protocol::game_utilities::v1::GetAchievementsFileResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.GetAchievementsFile({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilitiesService::HandleGetAllValuesForAttribute(::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeRequest const* request, ::bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method GameUtilitiesService.GetAllValuesForAttribute({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace game_utilities
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
