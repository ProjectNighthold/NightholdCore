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
#include "user_manager_service.pb.h"

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
namespace user_manager {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* SubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscribeResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* UnsubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UnsubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* AddRecentPlayersRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AddRecentPlayersRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* AddRecentPlayersResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AddRecentPlayersResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ClearRecentPlayersRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClearRecentPlayersRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ClearRecentPlayersResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClearRecentPlayersResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* BlockPlayerRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BlockPlayerRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UnblockPlayerRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UnblockPlayerRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* BlockedPlayerAddedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BlockedPlayerAddedNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* BlockedPlayerRemovedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BlockedPlayerRemovedNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* RecentPlayersAddedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RecentPlayersAddedNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* RecentPlayersRemovedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RecentPlayersRemovedNotification_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* UserManagerService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* UserManagerListener_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_user_5fmanager_5fservice_2eproto() {
  protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "user_manager_service.proto");
  GOOGLE_CHECK(file != NULL);
  SubscribeRequest_descriptor_ = file->message_type(0);
  static const int SubscribeRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, object_id_),
  };
  SubscribeRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscribeRequest_descriptor_,
      SubscribeRequest::default_instance_,
      SubscribeRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscribeRequest));
  SubscribeResponse_descriptor_ = file->message_type(1);
  static const int SubscribeResponse_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, blocked_players_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, recent_players_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, role_),
  };
  SubscribeResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscribeResponse_descriptor_,
      SubscribeResponse::default_instance_,
      SubscribeResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscribeResponse));
  UnsubscribeRequest_descriptor_ = file->message_type(2);
  static const int UnsubscribeRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, object_id_),
  };
  UnsubscribeRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UnsubscribeRequest_descriptor_,
      UnsubscribeRequest::default_instance_,
      UnsubscribeRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UnsubscribeRequest));
  AddRecentPlayersRequest_descriptor_ = file->message_type(3);
  static const int AddRecentPlayersRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersRequest, players_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersRequest, program_),
  };
  AddRecentPlayersRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AddRecentPlayersRequest_descriptor_,
      AddRecentPlayersRequest::default_instance_,
      AddRecentPlayersRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AddRecentPlayersRequest));
  AddRecentPlayersResponse_descriptor_ = file->message_type(4);
  static const int AddRecentPlayersResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersResponse, players_added_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersResponse, players_removed_),
  };
  AddRecentPlayersResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AddRecentPlayersResponse_descriptor_,
      AddRecentPlayersResponse::default_instance_,
      AddRecentPlayersResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddRecentPlayersResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AddRecentPlayersResponse));
  ClearRecentPlayersRequest_descriptor_ = file->message_type(5);
  static const int ClearRecentPlayersRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersRequest, program_),
  };
  ClearRecentPlayersRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClearRecentPlayersRequest_descriptor_,
      ClearRecentPlayersRequest::default_instance_,
      ClearRecentPlayersRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClearRecentPlayersRequest));
  ClearRecentPlayersResponse_descriptor_ = file->message_type(6);
  static const int ClearRecentPlayersResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersResponse, players_removed_),
  };
  ClearRecentPlayersResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClearRecentPlayersResponse_descriptor_,
      ClearRecentPlayersResponse::default_instance_,
      ClearRecentPlayersResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClearRecentPlayersResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClearRecentPlayersResponse));
  BlockPlayerRequest_descriptor_ = file->message_type(7);
  static const int BlockPlayerRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockPlayerRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockPlayerRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockPlayerRequest, role_),
  };
  BlockPlayerRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BlockPlayerRequest_descriptor_,
      BlockPlayerRequest::default_instance_,
      BlockPlayerRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockPlayerRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockPlayerRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BlockPlayerRequest));
  UnblockPlayerRequest_descriptor_ = file->message_type(8);
  static const int UnblockPlayerRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnblockPlayerRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnblockPlayerRequest, target_id_),
  };
  UnblockPlayerRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UnblockPlayerRequest_descriptor_,
      UnblockPlayerRequest::default_instance_,
      UnblockPlayerRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnblockPlayerRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnblockPlayerRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UnblockPlayerRequest));
  BlockedPlayerAddedNotification_descriptor_ = file->message_type(9);
  static const int BlockedPlayerAddedNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerAddedNotification, player_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerAddedNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerAddedNotification, account_id_),
  };
  BlockedPlayerAddedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BlockedPlayerAddedNotification_descriptor_,
      BlockedPlayerAddedNotification::default_instance_,
      BlockedPlayerAddedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerAddedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerAddedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BlockedPlayerAddedNotification));
  BlockedPlayerRemovedNotification_descriptor_ = file->message_type(10);
  static const int BlockedPlayerRemovedNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerRemovedNotification, player_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerRemovedNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerRemovedNotification, account_id_),
  };
  BlockedPlayerRemovedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BlockedPlayerRemovedNotification_descriptor_,
      BlockedPlayerRemovedNotification::default_instance_,
      BlockedPlayerRemovedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerRemovedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BlockedPlayerRemovedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BlockedPlayerRemovedNotification));
  RecentPlayersAddedNotification_descriptor_ = file->message_type(11);
  static const int RecentPlayersAddedNotification_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersAddedNotification, player_),
  };
  RecentPlayersAddedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RecentPlayersAddedNotification_descriptor_,
      RecentPlayersAddedNotification::default_instance_,
      RecentPlayersAddedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersAddedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersAddedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RecentPlayersAddedNotification));
  RecentPlayersRemovedNotification_descriptor_ = file->message_type(12);
  static const int RecentPlayersRemovedNotification_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersRemovedNotification, player_),
  };
  RecentPlayersRemovedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RecentPlayersRemovedNotification_descriptor_,
      RecentPlayersRemovedNotification::default_instance_,
      RecentPlayersRemovedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersRemovedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RecentPlayersRemovedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RecentPlayersRemovedNotification));
  UserManagerService_descriptor_ = file->service(0);
  UserManagerListener_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_user_5fmanager_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeRequest_descriptor_, &SubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeResponse_descriptor_, &SubscribeResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UnsubscribeRequest_descriptor_, &UnsubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AddRecentPlayersRequest_descriptor_, &AddRecentPlayersRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AddRecentPlayersResponse_descriptor_, &AddRecentPlayersResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClearRecentPlayersRequest_descriptor_, &ClearRecentPlayersRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClearRecentPlayersResponse_descriptor_, &ClearRecentPlayersResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BlockPlayerRequest_descriptor_, &BlockPlayerRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UnblockPlayerRequest_descriptor_, &UnblockPlayerRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BlockedPlayerAddedNotification_descriptor_, &BlockedPlayerAddedNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BlockedPlayerRemovedNotification_descriptor_, &BlockedPlayerRemovedNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RecentPlayersAddedNotification_descriptor_, &RecentPlayersAddedNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RecentPlayersRemovedNotification_descriptor_, &RecentPlayersRemovedNotification::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_user_5fmanager_5fservice_2eproto() {
  delete SubscribeRequest::default_instance_;
  delete SubscribeRequest_reflection_;
  delete SubscribeResponse::default_instance_;
  delete SubscribeResponse_reflection_;
  delete UnsubscribeRequest::default_instance_;
  delete UnsubscribeRequest_reflection_;
  delete AddRecentPlayersRequest::default_instance_;
  delete AddRecentPlayersRequest_reflection_;
  delete AddRecentPlayersResponse::default_instance_;
  delete AddRecentPlayersResponse_reflection_;
  delete ClearRecentPlayersRequest::default_instance_;
  delete ClearRecentPlayersRequest_reflection_;
  delete ClearRecentPlayersResponse::default_instance_;
  delete ClearRecentPlayersResponse_reflection_;
  delete BlockPlayerRequest::default_instance_;
  delete BlockPlayerRequest_reflection_;
  delete UnblockPlayerRequest::default_instance_;
  delete UnblockPlayerRequest_reflection_;
  delete BlockedPlayerAddedNotification::default_instance_;
  delete BlockedPlayerAddedNotification_reflection_;
  delete BlockedPlayerRemovedNotification::default_instance_;
  delete BlockedPlayerRemovedNotification_reflection_;
  delete RecentPlayersAddedNotification::default_instance_;
  delete RecentPlayersAddedNotification_reflection_;
  delete RecentPlayersRemovedNotification::default_instance_;
  delete RecentPlayersRemovedNotification_reflection_;
}

void protobuf_AddDesc_user_5fmanager_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::user_manager::v1::protobuf_AddDesc_user_5fmanager_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_role_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\032user_manager_service.proto\022\034bgs.protoc"
    "ol.user_manager.v1\032\030user_manager_types.p"
    "roto\032\022entity_types.proto\032\020role_types.pro"
    "to\032\017rpc_types.proto\"O\n\020SubscribeRequest\022"
    "(\n\010agent_id\030\001 \001(\0132\026.bgs.protocol.EntityI"
    "d\022\021\n\tobject_id\030\002 \002(\004\"\277\001\n\021SubscribeRespon"
    "se\022D\n\017blocked_players\030\001 \003(\0132+.bgs.protoc"
    "ol.user_manager.v1.BlockedPlayer\022B\n\016rece"
    "nt_players\030\002 \003(\0132*.bgs.protocol.user_man"
    "ager.v1.RecentPlayer\022 \n\004role\030\003 \003(\0132\022.bgs"
    ".protocol.Role\"Q\n\022UnsubscribeRequest\022(\n\010"
    "agent_id\030\001 \001(\0132\026.bgs.protocol.EntityId\022\021"
    "\n\tobject_id\030\002 \001(\004\"\221\001\n\027AddRecentPlayersRe"
    "quest\022;\n\007players\030\001 \003(\0132*.bgs.protocol.us"
    "er_manager.v1.RecentPlayer\022(\n\010agent_id\030\002"
    " \001(\0132\026.bgs.protocol.EntityId\022\017\n\007program\030"
    "\003 \001(\r\"v\n\030AddRecentPlayersResponse\022A\n\rpla"
    "yers_added\030\001 \003(\0132*.bgs.protocol.user_man"
    "ager.v1.RecentPlayer\022\027\n\017players_removed\030"
    "\003 \003(\007\"V\n\031ClearRecentPlayersRequest\022(\n\010ag"
    "ent_id\030\001 \001(\0132\026.bgs.protocol.EntityId\022\017\n\007"
    "program\030\002 \001(\r\"5\n\032ClearRecentPlayersRespo"
    "nse\022\027\n\017players_removed\030\001 \003(\007\"w\n\022BlockPla"
    "yerRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.proto"
    "col.EntityId\022)\n\ttarget_id\030\002 \002(\0132\026.bgs.pr"
    "otocol.EntityId\022\014\n\004role\030\003 \001(\r\"k\n\024Unblock"
    "PlayerRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.pr"
    "otocol.EntityId\022)\n\ttarget_id\030\002 \002(\0132\026.bgs"
    ".protocol.EntityId\"\272\001\n\036BlockedPlayerAdde"
    "dNotification\022;\n\006player\030\001 \002(\0132+.bgs.prot"
    "ocol.user_manager.v1.BlockedPlayer\022/\n\017ga"
    "me_account_id\030\002 \001(\0132\026.bgs.protocol.Entit"
    "yId\022*\n\naccount_id\030\003 \001(\0132\026.bgs.protocol.E"
    "ntityId\"\274\001\n BlockedPlayerRemovedNotifica"
    "tion\022;\n\006player\030\001 \002(\0132+.bgs.protocol.user"
    "_manager.v1.BlockedPlayer\022/\n\017game_accoun"
    "t_id\030\002 \001(\0132\026.bgs.protocol.EntityId\022*\n\nac"
    "count_id\030\003 \001(\0132\026.bgs.protocol.EntityId\"\\"
    "\n\036RecentPlayersAddedNotification\022:\n\006play"
    "er\030\001 \003(\0132*.bgs.protocol.user_manager.v1."
    "RecentPlayer\"^\n RecentPlayersRemovedNoti"
    "fication\022:\n\006player\030\001 \003(\0132*.bgs.protocol."
    "user_manager.v1.RecentPlayer2\233\007\n\022UserMan"
    "agerService\022r\n\tSubscribe\022..bgs.protocol."
    "user_manager.v1.SubscribeRequest\032/.bgs.p"
    "rotocol.user_manager.v1.SubscribeRespons"
    "e\"\004\200\265\030\001\022\207\001\n\020AddRecentPlayers\0225.bgs.proto"
    "col.user_manager.v1.AddRecentPlayersRequ"
    "est\0326.bgs.protocol.user_manager.v1.AddRe"
    "centPlayersResponse\"\004\200\265\030\n\022\215\001\n\022ClearRecen"
    "tPlayers\0227.bgs.protocol.user_manager.v1."
    "ClearRecentPlayersRequest\0328.bgs.protocol"
    ".user_manager.v1.ClearRecentPlayersRespo"
    "nse\"\004\200\265\030\013\022[\n\013BlockPlayer\0220.bgs.protocol."
    "user_manager.v1.BlockPlayerRequest\032\024.bgs"
    ".protocol.NoData\"\004\200\265\030\024\022_\n\rUnblockPlayer\022"
    "2.bgs.protocol.user_manager.v1.UnblockPl"
    "ayerRequest\032\024.bgs.protocol.NoData\"\004\200\265\030\025\022"
    "e\n\025BlockPlayerForSession\0220.bgs.protocol."
    "user_manager.v1.BlockPlayerRequest\032\024.bgs"
    ".protocol.NoData\"\004\200\265\030(\022C\n\rLoadBlockList\022"
    "\026.bgs.protocol.EntityId\032\024.bgs.protocol.N"
    "oData\"\004\200\265\0302\022[\n\013Unsubscribe\0220.bgs.protoco"
    "l.user_manager.v1.UnsubscribeRequest\032\024.b"
    "gs.protocol.NoData\"\004\200\265\0303\0320\312>-bnet.protoc"
    "ol.user_manager.UserManagerService2\252\004\n\023U"
    "serManagerListener\022u\n\024OnBlockedPlayerAdd"
    "ed\022<.bgs.protocol.user_manager.v1.Blocke"
    "dPlayerAddedNotification\032\031.bgs.protocol."
    "NO_RESPONSE\"\004\200\265\030\001\022y\n\026OnBlockedPlayerRemo"
    "ved\022>.bgs.protocol.user_manager.v1.Block"
    "edPlayerRemovedNotification\032\031.bgs.protoc"
    "ol.NO_RESPONSE\"\004\200\265\030\002\022u\n\024OnRecentPlayersA"
    "dded\022<.bgs.protocol.user_manager.v1.Rece"
    "ntPlayersAddedNotification\032\031.bgs.protoco"
    "l.NO_RESPONSE\"\004\200\265\030\013\022y\n\026OnRecentPlayersRe"
    "moved\022>.bgs.protocol.user_manager.v1.Rec"
    "entPlayersRemovedNotification\032\031.bgs.prot"
    "ocol.NO_RESPONSE\"\004\200\265\030\014\032/\312>,bnet.protocol"
    ".user_manager.UserManagerNotifyB\005H\001\200\001\000", 3198);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "user_manager_service.proto", &protobuf_RegisterTypes);
  SubscribeRequest::default_instance_ = new SubscribeRequest();
  SubscribeResponse::default_instance_ = new SubscribeResponse();
  UnsubscribeRequest::default_instance_ = new UnsubscribeRequest();
  AddRecentPlayersRequest::default_instance_ = new AddRecentPlayersRequest();
  AddRecentPlayersResponse::default_instance_ = new AddRecentPlayersResponse();
  ClearRecentPlayersRequest::default_instance_ = new ClearRecentPlayersRequest();
  ClearRecentPlayersResponse::default_instance_ = new ClearRecentPlayersResponse();
  BlockPlayerRequest::default_instance_ = new BlockPlayerRequest();
  UnblockPlayerRequest::default_instance_ = new UnblockPlayerRequest();
  BlockedPlayerAddedNotification::default_instance_ = new BlockedPlayerAddedNotification();
  BlockedPlayerRemovedNotification::default_instance_ = new BlockedPlayerRemovedNotification();
  RecentPlayersAddedNotification::default_instance_ = new RecentPlayersAddedNotification();
  RecentPlayersRemovedNotification::default_instance_ = new RecentPlayersRemovedNotification();
  SubscribeRequest::default_instance_->InitAsDefaultInstance();
  SubscribeResponse::default_instance_->InitAsDefaultInstance();
  UnsubscribeRequest::default_instance_->InitAsDefaultInstance();
  AddRecentPlayersRequest::default_instance_->InitAsDefaultInstance();
  AddRecentPlayersResponse::default_instance_->InitAsDefaultInstance();
  ClearRecentPlayersRequest::default_instance_->InitAsDefaultInstance();
  ClearRecentPlayersResponse::default_instance_->InitAsDefaultInstance();
  BlockPlayerRequest::default_instance_->InitAsDefaultInstance();
  UnblockPlayerRequest::default_instance_->InitAsDefaultInstance();
  BlockedPlayerAddedNotification::default_instance_->InitAsDefaultInstance();
  BlockedPlayerRemovedNotification::default_instance_->InitAsDefaultInstance();
  RecentPlayersAddedNotification::default_instance_->InitAsDefaultInstance();
  RecentPlayersRemovedNotification::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_user_5fmanager_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_user_5fmanager_5fservice_2eproto {
  StaticDescriptorInitializer_user_5fmanager_5fservice_2eproto() {
    protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  }
} static_descriptor_initializer_user_5fmanager_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SubscribeRequest::kAgentIdFieldNumber;
const int SubscribeRequest::kObjectIdFieldNumber;
#endif  // !_MSC_VER

SubscribeRequest::SubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.SubscribeRequest)
}

void SubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SubscribeRequest::SubscribeRequest(const SubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.SubscribeRequest)
}

void SubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeRequest::~SubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.SubscribeRequest)
  SharedDtor();
}

void SubscribeRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void SubscribeRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscribeRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscribeRequest_descriptor_;
}

const SubscribeRequest& SubscribeRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

SubscribeRequest* SubscribeRequest::default_instance_ = NULL;

SubscribeRequest* SubscribeRequest::New() const {
  return new SubscribeRequest;
}

void SubscribeRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    object_id_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscribeRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.SubscribeRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId agent_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_object_id;
        break;
      }

      // required uint64 object_id = 2;
      case 2: {
        if (tag == 16) {
         parse_object_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &object_id_)));
          set_has_object_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.SubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.SubscribeRequest)
  return false;
#undef DO_
}

void SubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.SubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required uint64 object_id = 2;
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->object_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.SubscribeRequest)
}

::google::protobuf::uint8* SubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.SubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required uint64 object_id = 2;
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->object_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.SubscribeRequest)
  return target;
}

int SubscribeRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required uint64 object_id = 2;
    if (has_object_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->object_id());
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

void SubscribeRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscribeRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscribeRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscribeRequest::MergeFrom(const SubscribeRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscribeRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscribeRequest::CopyFrom(const SubscribeRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscribeRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void SubscribeRequest::Swap(SubscribeRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(object_id_, other->object_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscribeRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscribeRequest_descriptor_;
  metadata.reflection = SubscribeRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SubscribeResponse::kBlockedPlayersFieldNumber;
const int SubscribeResponse::kRecentPlayersFieldNumber;
const int SubscribeResponse::kRoleFieldNumber;
#endif  // !_MSC_VER

SubscribeResponse::SubscribeResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.SubscribeResponse)
}

void SubscribeResponse::InitAsDefaultInstance() {
}

SubscribeResponse::SubscribeResponse(const SubscribeResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.SubscribeResponse)
}

void SubscribeResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeResponse::~SubscribeResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.SubscribeResponse)
  SharedDtor();
}

void SubscribeResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SubscribeResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscribeResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscribeResponse_descriptor_;
}

const SubscribeResponse& SubscribeResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

SubscribeResponse* SubscribeResponse::default_instance_ = NULL;

SubscribeResponse* SubscribeResponse::New() const {
  return new SubscribeResponse;
}

void SubscribeResponse::Clear() {
  blocked_players_.Clear();
  recent_players_.Clear();
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscribeResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.SubscribeResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.user_manager.v1.BlockedPlayer blocked_players = 1;
      case 1: {
        if (tag == 10) {
         parse_blocked_players:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_blocked_players()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_blocked_players;
        if (input->ExpectTag(18)) goto parse_recent_players;
        break;
      }

      // repeated .bgs.protocol.user_manager.v1.RecentPlayer recent_players = 2;
      case 2: {
        if (tag == 18) {
         parse_recent_players:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_recent_players()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_recent_players;
        if (input->ExpectTag(26)) goto parse_role;
        break;
      }

      // repeated .bgs.protocol.Role role = 3;
      case 3: {
        if (tag == 26) {
         parse_role:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_role()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_role;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.SubscribeResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.SubscribeResponse)
  return false;
#undef DO_
}

void SubscribeResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.SubscribeResponse)
  // repeated .bgs.protocol.user_manager.v1.BlockedPlayer blocked_players = 1;
  for (int i = 0; i < this->blocked_players_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->blocked_players(i), output);
  }

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer recent_players = 2;
  for (int i = 0; i < this->recent_players_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->recent_players(i), output);
  }

  // repeated .bgs.protocol.Role role = 3;
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.SubscribeResponse)
}

::google::protobuf::uint8* SubscribeResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.SubscribeResponse)
  // repeated .bgs.protocol.user_manager.v1.BlockedPlayer blocked_players = 1;
  for (int i = 0; i < this->blocked_players_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->blocked_players(i), target);
  }

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer recent_players = 2;
  for (int i = 0; i < this->recent_players_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->recent_players(i), target);
  }

  // repeated .bgs.protocol.Role role = 3;
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.SubscribeResponse)
  return target;
}

int SubscribeResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.user_manager.v1.BlockedPlayer blocked_players = 1;
  total_size += 1 * this->blocked_players_size();
  for (int i = 0; i < this->blocked_players_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->blocked_players(i));
  }

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer recent_players = 2;
  total_size += 1 * this->recent_players_size();
  for (int i = 0; i < this->recent_players_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->recent_players(i));
  }

  // repeated .bgs.protocol.Role role = 3;
  total_size += 1 * this->role_size();
  for (int i = 0; i < this->role_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->role(i));
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

void SubscribeResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscribeResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscribeResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscribeResponse::MergeFrom(const SubscribeResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  blocked_players_.MergeFrom(from.blocked_players_);
  recent_players_.MergeFrom(from.recent_players_);
  role_.MergeFrom(from.role_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscribeResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscribeResponse::CopyFrom(const SubscribeResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscribeResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->blocked_players())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->recent_players())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->role())) return false;
  return true;
}

void SubscribeResponse::Swap(SubscribeResponse* other) {
  if (other != this) {
    blocked_players_.Swap(&other->blocked_players_);
    recent_players_.Swap(&other->recent_players_);
    role_.Swap(&other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscribeResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscribeResponse_descriptor_;
  metadata.reflection = SubscribeResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UnsubscribeRequest::kAgentIdFieldNumber;
const int UnsubscribeRequest::kObjectIdFieldNumber;
#endif  // !_MSC_VER

UnsubscribeRequest::UnsubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UnsubscribeRequest::UnsubscribeRequest(const UnsubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UnsubscribeRequest::~UnsubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  SharedDtor();
}

void UnsubscribeRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void UnsubscribeRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UnsubscribeRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UnsubscribeRequest_descriptor_;
}

const UnsubscribeRequest& UnsubscribeRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

UnsubscribeRequest* UnsubscribeRequest::default_instance_ = NULL;

UnsubscribeRequest* UnsubscribeRequest::New() const {
  return new UnsubscribeRequest;
}

void UnsubscribeRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    object_id_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UnsubscribeRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId agent_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_object_id;
        break;
      }

      // optional uint64 object_id = 2;
      case 2: {
        if (tag == 16) {
         parse_object_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &object_id_)));
          set_has_object_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  return false;
#undef DO_
}

void UnsubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // optional uint64 object_id = 2;
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->object_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.UnsubscribeRequest)
}

::google::protobuf::uint8* UnsubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // optional uint64 object_id = 2;
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->object_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.UnsubscribeRequest)
  return target;
}

int UnsubscribeRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional uint64 object_id = 2;
    if (has_object_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->object_id());
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

void UnsubscribeRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UnsubscribeRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UnsubscribeRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UnsubscribeRequest::MergeFrom(const UnsubscribeRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UnsubscribeRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UnsubscribeRequest::CopyFrom(const UnsubscribeRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UnsubscribeRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void UnsubscribeRequest::Swap(UnsubscribeRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(object_id_, other->object_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UnsubscribeRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UnsubscribeRequest_descriptor_;
  metadata.reflection = UnsubscribeRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AddRecentPlayersRequest::kPlayersFieldNumber;
const int AddRecentPlayersRequest::kAgentIdFieldNumber;
const int AddRecentPlayersRequest::kProgramFieldNumber;
#endif  // !_MSC_VER

AddRecentPlayersRequest::AddRecentPlayersRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
}

void AddRecentPlayersRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

AddRecentPlayersRequest::AddRecentPlayersRequest(const AddRecentPlayersRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
}

void AddRecentPlayersRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AddRecentPlayersRequest::~AddRecentPlayersRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  SharedDtor();
}

void AddRecentPlayersRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void AddRecentPlayersRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddRecentPlayersRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AddRecentPlayersRequest_descriptor_;
}

const AddRecentPlayersRequest& AddRecentPlayersRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

AddRecentPlayersRequest* AddRecentPlayersRequest::default_instance_ = NULL;

AddRecentPlayersRequest* AddRecentPlayersRequest::New() const {
  return new AddRecentPlayersRequest;
}

void AddRecentPlayersRequest::Clear() {
  if (_has_bits_[0 / 32] & 6) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    program_ = 0u;
  }
  players_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AddRecentPlayersRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.user_manager.v1.RecentPlayer players = 1;
      case 1: {
        if (tag == 10) {
         parse_players:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_players()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_players;
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
        if (input->ExpectTag(24)) goto parse_program;
        break;
      }

      // optional uint32 program = 3;
      case 3: {
        if (tag == 24) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  return false;
#undef DO_
}

void AddRecentPlayersRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players = 1;
  for (int i = 0; i < this->players_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->players(i), output);
  }

  // optional .bgs.protocol.EntityId agent_id = 2;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->agent_id(), output);
  }

  // optional uint32 program = 3;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
}

::google::protobuf::uint8* AddRecentPlayersRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players = 1;
  for (int i = 0; i < this->players_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->players(i), target);
  }

  // optional .bgs.protocol.EntityId agent_id = 2;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->agent_id(), target);
  }

  // optional uint32 program = 3;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.AddRecentPlayersRequest)
  return target;
}

int AddRecentPlayersRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 2;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional uint32 program = 3;
    if (has_program()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->program());
    }

  }
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players = 1;
  total_size += 1 * this->players_size();
  for (int i = 0; i < this->players_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->players(i));
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

void AddRecentPlayersRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AddRecentPlayersRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AddRecentPlayersRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AddRecentPlayersRequest::MergeFrom(const AddRecentPlayersRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  players_.MergeFrom(from.players_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AddRecentPlayersRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddRecentPlayersRequest::CopyFrom(const AddRecentPlayersRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddRecentPlayersRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->players())) return false;
  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void AddRecentPlayersRequest::Swap(AddRecentPlayersRequest* other) {
  if (other != this) {
    players_.Swap(&other->players_);
    std::swap(agent_id_, other->agent_id_);
    std::swap(program_, other->program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AddRecentPlayersRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AddRecentPlayersRequest_descriptor_;
  metadata.reflection = AddRecentPlayersRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AddRecentPlayersResponse::kPlayersAddedFieldNumber;
const int AddRecentPlayersResponse::kPlayersRemovedFieldNumber;
#endif  // !_MSC_VER

AddRecentPlayersResponse::AddRecentPlayersResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
}

void AddRecentPlayersResponse::InitAsDefaultInstance() {
}

AddRecentPlayersResponse::AddRecentPlayersResponse(const AddRecentPlayersResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
}

void AddRecentPlayersResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AddRecentPlayersResponse::~AddRecentPlayersResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  SharedDtor();
}

void AddRecentPlayersResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AddRecentPlayersResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddRecentPlayersResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AddRecentPlayersResponse_descriptor_;
}

const AddRecentPlayersResponse& AddRecentPlayersResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

AddRecentPlayersResponse* AddRecentPlayersResponse::default_instance_ = NULL;

AddRecentPlayersResponse* AddRecentPlayersResponse::New() const {
  return new AddRecentPlayersResponse;
}

void AddRecentPlayersResponse::Clear() {
  players_added_.Clear();
  players_removed_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AddRecentPlayersResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.user_manager.v1.RecentPlayer players_added = 1;
      case 1: {
        if (tag == 10) {
         parse_players_added:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_players_added()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_players_added;
        if (input->ExpectTag(29)) goto parse_players_removed;
        break;
      }

      // repeated fixed32 players_removed = 3;
      case 3: {
        if (tag == 29) {
         parse_players_removed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 1, 29, input, this->mutable_players_removed())));
        } else if (tag == 26) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, this->mutable_players_removed())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_players_removed;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  return false;
#undef DO_
}

void AddRecentPlayersResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players_added = 1;
  for (int i = 0; i < this->players_added_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->players_added(i), output);
  }

  // repeated fixed32 players_removed = 3;
  for (int i = 0; i < this->players_removed_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(
      3, this->players_removed(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
}

::google::protobuf::uint8* AddRecentPlayersResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players_added = 1;
  for (int i = 0; i < this->players_added_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->players_added(i), target);
  }

  // repeated fixed32 players_removed = 3;
  for (int i = 0; i < this->players_removed_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFixed32ToArray(3, this->players_removed(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.AddRecentPlayersResponse)
  return target;
}

int AddRecentPlayersResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer players_added = 1;
  total_size += 1 * this->players_added_size();
  for (int i = 0; i < this->players_added_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->players_added(i));
  }

  // repeated fixed32 players_removed = 3;
  {
    int data_size = 0;
    data_size = 4 * this->players_removed_size();
    total_size += 1 * this->players_removed_size() + data_size;
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

void AddRecentPlayersResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AddRecentPlayersResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AddRecentPlayersResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AddRecentPlayersResponse::MergeFrom(const AddRecentPlayersResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  players_added_.MergeFrom(from.players_added_);
  players_removed_.MergeFrom(from.players_removed_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AddRecentPlayersResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddRecentPlayersResponse::CopyFrom(const AddRecentPlayersResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddRecentPlayersResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->players_added())) return false;
  return true;
}

void AddRecentPlayersResponse::Swap(AddRecentPlayersResponse* other) {
  if (other != this) {
    players_added_.Swap(&other->players_added_);
    players_removed_.Swap(&other->players_removed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AddRecentPlayersResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AddRecentPlayersResponse_descriptor_;
  metadata.reflection = AddRecentPlayersResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ClearRecentPlayersRequest::kAgentIdFieldNumber;
const int ClearRecentPlayersRequest::kProgramFieldNumber;
#endif  // !_MSC_VER

ClearRecentPlayersRequest::ClearRecentPlayersRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
}

void ClearRecentPlayersRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

ClearRecentPlayersRequest::ClearRecentPlayersRequest(const ClearRecentPlayersRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
}

void ClearRecentPlayersRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClearRecentPlayersRequest::~ClearRecentPlayersRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  SharedDtor();
}

void ClearRecentPlayersRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void ClearRecentPlayersRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClearRecentPlayersRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClearRecentPlayersRequest_descriptor_;
}

const ClearRecentPlayersRequest& ClearRecentPlayersRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

ClearRecentPlayersRequest* ClearRecentPlayersRequest::default_instance_ = NULL;

ClearRecentPlayersRequest* ClearRecentPlayersRequest::New() const {
  return new ClearRecentPlayersRequest;
}

void ClearRecentPlayersRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    program_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ClearRecentPlayersRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId agent_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_program;
        break;
      }

      // optional uint32 program = 2;
      case 2: {
        if (tag == 16) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  return false;
#undef DO_
}

void ClearRecentPlayersRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // optional uint32 program = 2;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
}

::google::protobuf::uint8* ClearRecentPlayersRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // optional uint32 program = 2;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.ClearRecentPlayersRequest)
  return target;
}

int ClearRecentPlayersRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional uint32 program = 2;
    if (has_program()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->program());
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

void ClearRecentPlayersRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ClearRecentPlayersRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ClearRecentPlayersRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ClearRecentPlayersRequest::MergeFrom(const ClearRecentPlayersRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ClearRecentPlayersRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClearRecentPlayersRequest::CopyFrom(const ClearRecentPlayersRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClearRecentPlayersRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void ClearRecentPlayersRequest::Swap(ClearRecentPlayersRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(program_, other->program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ClearRecentPlayersRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClearRecentPlayersRequest_descriptor_;
  metadata.reflection = ClearRecentPlayersRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ClearRecentPlayersResponse::kPlayersRemovedFieldNumber;
#endif  // !_MSC_VER

ClearRecentPlayersResponse::ClearRecentPlayersResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
}

void ClearRecentPlayersResponse::InitAsDefaultInstance() {
}

ClearRecentPlayersResponse::ClearRecentPlayersResponse(const ClearRecentPlayersResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
}

void ClearRecentPlayersResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClearRecentPlayersResponse::~ClearRecentPlayersResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  SharedDtor();
}

void ClearRecentPlayersResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ClearRecentPlayersResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClearRecentPlayersResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClearRecentPlayersResponse_descriptor_;
}

const ClearRecentPlayersResponse& ClearRecentPlayersResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

ClearRecentPlayersResponse* ClearRecentPlayersResponse::default_instance_ = NULL;

ClearRecentPlayersResponse* ClearRecentPlayersResponse::New() const {
  return new ClearRecentPlayersResponse;
}

void ClearRecentPlayersResponse::Clear() {
  players_removed_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ClearRecentPlayersResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated fixed32 players_removed = 1;
      case 1: {
        if (tag == 13) {
         parse_players_removed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 1, 13, input, this->mutable_players_removed())));
        } else if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, this->mutable_players_removed())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(13)) goto parse_players_removed;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  return false;
#undef DO_
}

void ClearRecentPlayersResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  // repeated fixed32 players_removed = 1;
  for (int i = 0; i < this->players_removed_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(
      1, this->players_removed(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
}

::google::protobuf::uint8* ClearRecentPlayersResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  // repeated fixed32 players_removed = 1;
  for (int i = 0; i < this->players_removed_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFixed32ToArray(1, this->players_removed(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.ClearRecentPlayersResponse)
  return target;
}

int ClearRecentPlayersResponse::ByteSize() const {
  int total_size = 0;

  // repeated fixed32 players_removed = 1;
  {
    int data_size = 0;
    data_size = 4 * this->players_removed_size();
    total_size += 1 * this->players_removed_size() + data_size;
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

void ClearRecentPlayersResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ClearRecentPlayersResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ClearRecentPlayersResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ClearRecentPlayersResponse::MergeFrom(const ClearRecentPlayersResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  players_removed_.MergeFrom(from.players_removed_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ClearRecentPlayersResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClearRecentPlayersResponse::CopyFrom(const ClearRecentPlayersResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClearRecentPlayersResponse::IsInitialized() const {

  return true;
}

void ClearRecentPlayersResponse::Swap(ClearRecentPlayersResponse* other) {
  if (other != this) {
    players_removed_.Swap(&other->players_removed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ClearRecentPlayersResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClearRecentPlayersResponse_descriptor_;
  metadata.reflection = ClearRecentPlayersResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BlockPlayerRequest::kAgentIdFieldNumber;
const int BlockPlayerRequest::kTargetIdFieldNumber;
const int BlockPlayerRequest::kRoleFieldNumber;
#endif  // !_MSC_VER

BlockPlayerRequest::BlockPlayerRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.BlockPlayerRequest)
}

void BlockPlayerRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

BlockPlayerRequest::BlockPlayerRequest(const BlockPlayerRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.BlockPlayerRequest)
}

void BlockPlayerRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  role_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BlockPlayerRequest::~BlockPlayerRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  SharedDtor();
}

void BlockPlayerRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void BlockPlayerRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BlockPlayerRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BlockPlayerRequest_descriptor_;
}

const BlockPlayerRequest& BlockPlayerRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

BlockPlayerRequest* BlockPlayerRequest::default_instance_ = NULL;

BlockPlayerRequest* BlockPlayerRequest::New() const {
  return new BlockPlayerRequest;
}

void BlockPlayerRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
    role_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BlockPlayerRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId agent_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_target_id;
        break;
      }

      // required .bgs.protocol.EntityId target_id = 2;
      case 2: {
        if (tag == 18) {
         parse_target_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_role;
        break;
      }

      // optional uint32 role = 3;
      case 3: {
        if (tag == 24) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &role_)));
          set_has_role();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  return false;
#undef DO_
}

void BlockPlayerRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->target_id(), output);
  }

  // optional uint32 role = 3;
  if (has_role()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->role(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.BlockPlayerRequest)
}

::google::protobuf::uint8* BlockPlayerRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->target_id(), target);
  }

  // optional uint32 role = 3;
  if (has_role()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->role(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.BlockPlayerRequest)
  return target;
}

int BlockPlayerRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.EntityId target_id = 2;
    if (has_target_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_id());
    }

    // optional uint32 role = 3;
    if (has_role()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->role());
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

void BlockPlayerRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BlockPlayerRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BlockPlayerRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BlockPlayerRequest::MergeFrom(const BlockPlayerRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_role()) {
      set_role(from.role());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BlockPlayerRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BlockPlayerRequest::CopyFrom(const BlockPlayerRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockPlayerRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void BlockPlayerRequest::Swap(BlockPlayerRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(role_, other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BlockPlayerRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BlockPlayerRequest_descriptor_;
  metadata.reflection = BlockPlayerRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UnblockPlayerRequest::kAgentIdFieldNumber;
const int UnblockPlayerRequest::kTargetIdFieldNumber;
#endif  // !_MSC_VER

UnblockPlayerRequest::UnblockPlayerRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
}

void UnblockPlayerRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UnblockPlayerRequest::UnblockPlayerRequest(const UnblockPlayerRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
}

void UnblockPlayerRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UnblockPlayerRequest::~UnblockPlayerRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  SharedDtor();
}

void UnblockPlayerRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void UnblockPlayerRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UnblockPlayerRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UnblockPlayerRequest_descriptor_;
}

const UnblockPlayerRequest& UnblockPlayerRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

UnblockPlayerRequest* UnblockPlayerRequest::default_instance_ = NULL;

UnblockPlayerRequest* UnblockPlayerRequest::New() const {
  return new UnblockPlayerRequest;
}

void UnblockPlayerRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UnblockPlayerRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId agent_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_target_id;
        break;
      }

      // required .bgs.protocol.EntityId target_id = 2;
      case 2: {
        if (tag == 18) {
         parse_target_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  return false;
#undef DO_
}

void UnblockPlayerRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->target_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
}

::google::protobuf::uint8* UnblockPlayerRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->target_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.UnblockPlayerRequest)
  return target;
}

int UnblockPlayerRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.EntityId target_id = 2;
    if (has_target_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_id());
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

void UnblockPlayerRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UnblockPlayerRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UnblockPlayerRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UnblockPlayerRequest::MergeFrom(const UnblockPlayerRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UnblockPlayerRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UnblockPlayerRequest::CopyFrom(const UnblockPlayerRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UnblockPlayerRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void UnblockPlayerRequest::Swap(UnblockPlayerRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UnblockPlayerRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UnblockPlayerRequest_descriptor_;
  metadata.reflection = UnblockPlayerRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BlockedPlayerAddedNotification::kPlayerFieldNumber;
const int BlockedPlayerAddedNotification::kGameAccountIdFieldNumber;
const int BlockedPlayerAddedNotification::kAccountIdFieldNumber;
#endif  // !_MSC_VER

BlockedPlayerAddedNotification::BlockedPlayerAddedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
}

void BlockedPlayerAddedNotification::InitAsDefaultInstance() {
  player_ = const_cast< ::bgs::protocol::user_manager::v1::BlockedPlayer*>(&::bgs::protocol::user_manager::v1::BlockedPlayer::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

BlockedPlayerAddedNotification::BlockedPlayerAddedNotification(const BlockedPlayerAddedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
}

void BlockedPlayerAddedNotification::SharedCtor() {
  _cached_size_ = 0;
  player_ = NULL;
  game_account_id_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BlockedPlayerAddedNotification::~BlockedPlayerAddedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  SharedDtor();
}

void BlockedPlayerAddedNotification::SharedDtor() {
  if (this != default_instance_) {
    delete player_;
    delete game_account_id_;
    delete account_id_;
  }
}

void BlockedPlayerAddedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BlockedPlayerAddedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BlockedPlayerAddedNotification_descriptor_;
}

const BlockedPlayerAddedNotification& BlockedPlayerAddedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

BlockedPlayerAddedNotification* BlockedPlayerAddedNotification::default_instance_ = NULL;

BlockedPlayerAddedNotification* BlockedPlayerAddedNotification::New() const {
  return new BlockedPlayerAddedNotification;
}

void BlockedPlayerAddedNotification::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_player()) {
      if (player_ != NULL) player_->::bgs::protocol::user_manager::v1::BlockedPlayer::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BlockedPlayerAddedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_player()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_game_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId game_account_id = 2;
      case 2: {
        if (tag == 18) {
         parse_game_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  return false;
#undef DO_
}

void BlockedPlayerAddedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
  if (has_player()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
}

::google::protobuf::uint8* BlockedPlayerAddedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
  if (has_player()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification)
  return target;
}

int BlockedPlayerAddedNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
    if (has_player()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->player());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.EntityId account_id = 3;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
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

void BlockedPlayerAddedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BlockedPlayerAddedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BlockedPlayerAddedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BlockedPlayerAddedNotification::MergeFrom(const BlockedPlayerAddedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_player()) {
      mutable_player()->::bgs::protocol::user_manager::v1::BlockedPlayer::MergeFrom(from.player());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BlockedPlayerAddedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BlockedPlayerAddedNotification::CopyFrom(const BlockedPlayerAddedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockedPlayerAddedNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_player()) {
    if (!this->player().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void BlockedPlayerAddedNotification::Swap(BlockedPlayerAddedNotification* other) {
  if (other != this) {
    std::swap(player_, other->player_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BlockedPlayerAddedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BlockedPlayerAddedNotification_descriptor_;
  metadata.reflection = BlockedPlayerAddedNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BlockedPlayerRemovedNotification::kPlayerFieldNumber;
const int BlockedPlayerRemovedNotification::kGameAccountIdFieldNumber;
const int BlockedPlayerRemovedNotification::kAccountIdFieldNumber;
#endif  // !_MSC_VER

BlockedPlayerRemovedNotification::BlockedPlayerRemovedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
}

void BlockedPlayerRemovedNotification::InitAsDefaultInstance() {
  player_ = const_cast< ::bgs::protocol::user_manager::v1::BlockedPlayer*>(&::bgs::protocol::user_manager::v1::BlockedPlayer::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

BlockedPlayerRemovedNotification::BlockedPlayerRemovedNotification(const BlockedPlayerRemovedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
}

void BlockedPlayerRemovedNotification::SharedCtor() {
  _cached_size_ = 0;
  player_ = NULL;
  game_account_id_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BlockedPlayerRemovedNotification::~BlockedPlayerRemovedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  SharedDtor();
}

void BlockedPlayerRemovedNotification::SharedDtor() {
  if (this != default_instance_) {
    delete player_;
    delete game_account_id_;
    delete account_id_;
  }
}

void BlockedPlayerRemovedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BlockedPlayerRemovedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BlockedPlayerRemovedNotification_descriptor_;
}

const BlockedPlayerRemovedNotification& BlockedPlayerRemovedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

BlockedPlayerRemovedNotification* BlockedPlayerRemovedNotification::default_instance_ = NULL;

BlockedPlayerRemovedNotification* BlockedPlayerRemovedNotification::New() const {
  return new BlockedPlayerRemovedNotification;
}

void BlockedPlayerRemovedNotification::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_player()) {
      if (player_ != NULL) player_->::bgs::protocol::user_manager::v1::BlockedPlayer::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BlockedPlayerRemovedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_player()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_game_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId game_account_id = 2;
      case 2: {
        if (tag == 18) {
         parse_game_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  return false;
#undef DO_
}

void BlockedPlayerRemovedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
  if (has_player()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
}

::google::protobuf::uint8* BlockedPlayerRemovedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
  if (has_player()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 3;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification)
  return target;
}

int BlockedPlayerRemovedNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.user_manager.v1.BlockedPlayer player = 1;
    if (has_player()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->player());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.EntityId account_id = 3;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
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

void BlockedPlayerRemovedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BlockedPlayerRemovedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BlockedPlayerRemovedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BlockedPlayerRemovedNotification::MergeFrom(const BlockedPlayerRemovedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_player()) {
      mutable_player()->::bgs::protocol::user_manager::v1::BlockedPlayer::MergeFrom(from.player());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BlockedPlayerRemovedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BlockedPlayerRemovedNotification::CopyFrom(const BlockedPlayerRemovedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockedPlayerRemovedNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_player()) {
    if (!this->player().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void BlockedPlayerRemovedNotification::Swap(BlockedPlayerRemovedNotification* other) {
  if (other != this) {
    std::swap(player_, other->player_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BlockedPlayerRemovedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BlockedPlayerRemovedNotification_descriptor_;
  metadata.reflection = BlockedPlayerRemovedNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RecentPlayersAddedNotification::kPlayerFieldNumber;
#endif  // !_MSC_VER

RecentPlayersAddedNotification::RecentPlayersAddedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
}

void RecentPlayersAddedNotification::InitAsDefaultInstance() {
}

RecentPlayersAddedNotification::RecentPlayersAddedNotification(const RecentPlayersAddedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
}

void RecentPlayersAddedNotification::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RecentPlayersAddedNotification::~RecentPlayersAddedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  SharedDtor();
}

void RecentPlayersAddedNotification::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RecentPlayersAddedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RecentPlayersAddedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RecentPlayersAddedNotification_descriptor_;
}

const RecentPlayersAddedNotification& RecentPlayersAddedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

RecentPlayersAddedNotification* RecentPlayersAddedNotification::default_instance_ = NULL;

RecentPlayersAddedNotification* RecentPlayersAddedNotification::New() const {
  return new RecentPlayersAddedNotification;
}

void RecentPlayersAddedNotification::Clear() {
  player_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RecentPlayersAddedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
      case 1: {
        if (tag == 10) {
         parse_player:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_player;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  return false;
#undef DO_
}

void RecentPlayersAddedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
}

::google::protobuf::uint8* RecentPlayersAddedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.RecentPlayersAddedNotification)
  return target;
}

int RecentPlayersAddedNotification::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  total_size += 1 * this->player_size();
  for (int i = 0; i < this->player_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player(i));
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

void RecentPlayersAddedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RecentPlayersAddedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RecentPlayersAddedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RecentPlayersAddedNotification::MergeFrom(const RecentPlayersAddedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_.MergeFrom(from.player_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RecentPlayersAddedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RecentPlayersAddedNotification::CopyFrom(const RecentPlayersAddedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RecentPlayersAddedNotification::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->player())) return false;
  return true;
}

void RecentPlayersAddedNotification::Swap(RecentPlayersAddedNotification* other) {
  if (other != this) {
    player_.Swap(&other->player_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RecentPlayersAddedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RecentPlayersAddedNotification_descriptor_;
  metadata.reflection = RecentPlayersAddedNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RecentPlayersRemovedNotification::kPlayerFieldNumber;
#endif  // !_MSC_VER

RecentPlayersRemovedNotification::RecentPlayersRemovedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
}

void RecentPlayersRemovedNotification::InitAsDefaultInstance() {
}

RecentPlayersRemovedNotification::RecentPlayersRemovedNotification(const RecentPlayersRemovedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
}

void RecentPlayersRemovedNotification::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RecentPlayersRemovedNotification::~RecentPlayersRemovedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  SharedDtor();
}

void RecentPlayersRemovedNotification::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RecentPlayersRemovedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RecentPlayersRemovedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RecentPlayersRemovedNotification_descriptor_;
}

const RecentPlayersRemovedNotification& RecentPlayersRemovedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_5fmanager_5fservice_2eproto();
  return *default_instance_;
}

RecentPlayersRemovedNotification* RecentPlayersRemovedNotification::default_instance_ = NULL;

RecentPlayersRemovedNotification* RecentPlayersRemovedNotification::New() const {
  return new RecentPlayersRemovedNotification;
}

void RecentPlayersRemovedNotification::Clear() {
  player_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RecentPlayersRemovedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
      case 1: {
        if (tag == 10) {
         parse_player:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_player;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  return false;
#undef DO_
}

void RecentPlayersRemovedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
}

::google::protobuf::uint8* RecentPlayersRemovedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification)
  return target;
}

int RecentPlayersRemovedNotification::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.user_manager.v1.RecentPlayer player = 1;
  total_size += 1 * this->player_size();
  for (int i = 0; i < this->player_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player(i));
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

void RecentPlayersRemovedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RecentPlayersRemovedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RecentPlayersRemovedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RecentPlayersRemovedNotification::MergeFrom(const RecentPlayersRemovedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_.MergeFrom(from.player_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RecentPlayersRemovedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RecentPlayersRemovedNotification::CopyFrom(const RecentPlayersRemovedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RecentPlayersRemovedNotification::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->player())) return false;
  return true;
}

void RecentPlayersRemovedNotification::Swap(RecentPlayersRemovedNotification* other) {
  if (other != this) {
    player_.Swap(&other->player_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RecentPlayersRemovedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RecentPlayersRemovedNotification_descriptor_;
  metadata.reflection = RecentPlayersRemovedNotification_reflection_;
  return metadata;
}


// ===================================================================

UserManagerService::UserManagerService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

UserManagerService::~UserManagerService() {
}

google::protobuf::ServiceDescriptor const* UserManagerService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserManagerService_descriptor_;
}

void UserManagerService::Subscribe(::bgs::protocol::user_manager::v1::SubscribeRequest const* request, std::function<void(::bgs::protocol::user_manager::v1::SubscribeResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.Subscribe(bgs.protocol.user_manager.v1.SubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::user_manager::v1::SubscribeResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void UserManagerService::AddRecentPlayers(::bgs::protocol::user_manager::v1::AddRecentPlayersRequest const* request, std::function<void(::bgs::protocol::user_manager::v1::AddRecentPlayersResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.AddRecentPlayers(bgs.protocol.user_manager.v1.AddRecentPlayersRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::user_manager::v1::AddRecentPlayersResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 10, request, std::move(callback));
}

void UserManagerService::ClearRecentPlayers(::bgs::protocol::user_manager::v1::ClearRecentPlayersRequest const* request, std::function<void(::bgs::protocol::user_manager::v1::ClearRecentPlayersResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.ClearRecentPlayers(bgs.protocol.user_manager.v1.ClearRecentPlayersRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::user_manager::v1::ClearRecentPlayersResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 11, request, std::move(callback));
}

void UserManagerService::BlockPlayer(::bgs::protocol::user_manager::v1::BlockPlayerRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.BlockPlayer(bgs.protocol.user_manager.v1.BlockPlayerRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 20, request, std::move(callback));
}

void UserManagerService::UnblockPlayer(::bgs::protocol::user_manager::v1::UnblockPlayerRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.UnblockPlayer(bgs.protocol.user_manager.v1.UnblockPlayerRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 21, request, std::move(callback));
}

void UserManagerService::BlockPlayerForSession(::bgs::protocol::user_manager::v1::BlockPlayerRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.BlockPlayerForSession(bgs.protocol.user_manager.v1.BlockPlayerRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 40, request, std::move(callback));
}

void UserManagerService::LoadBlockList(::bgs::protocol::EntityId const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.LoadBlockList(bgs.protocol.EntityId{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 50, request, std::move(callback));
}

void UserManagerService::Unsubscribe(::bgs::protocol::user_manager::v1::UnsubscribeRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerService.Unsubscribe(bgs.protocol.user_manager.v1.UnsubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 51, request, std::move(callback));
}

void UserManagerService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::user_manager::v1::SubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.Subscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::user_manager::v1::SubscribeResponse response;
      uint32 status = HandleSubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.Subscribe(bgs.protocol.user_manager.v1.SubscribeRequest{ %s }) returned bgs.protocol.user_manager.v1.SubscribeResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 10: {
      ::bgs::protocol::user_manager::v1::AddRecentPlayersRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.AddRecentPlayers server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 10, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::user_manager::v1::AddRecentPlayersResponse response;
      uint32 status = HandleAddRecentPlayers(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.AddRecentPlayers(bgs.protocol.user_manager.v1.AddRecentPlayersRequest{ %s }) returned bgs.protocol.user_manager.v1.AddRecentPlayersResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 10, token, &response);
      else
        SendResponse(service_hash_, 10, token, status);
      break;
    }
    case 11: {
      ::bgs::protocol::user_manager::v1::ClearRecentPlayersRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.ClearRecentPlayers server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 11, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::user_manager::v1::ClearRecentPlayersResponse response;
      uint32 status = HandleClearRecentPlayers(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.ClearRecentPlayers(bgs.protocol.user_manager.v1.ClearRecentPlayersRequest{ %s }) returned bgs.protocol.user_manager.v1.ClearRecentPlayersResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 11, token, &response);
      else
        SendResponse(service_hash_, 11, token, status);
      break;
    }
    case 20: {
      ::bgs::protocol::user_manager::v1::BlockPlayerRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.BlockPlayer server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 20, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleBlockPlayer(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.BlockPlayer(bgs.protocol.user_manager.v1.BlockPlayerRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 20, token, &response);
      else
        SendResponse(service_hash_, 20, token, status);
      break;
    }
    case 21: {
      ::bgs::protocol::user_manager::v1::UnblockPlayerRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.UnblockPlayer server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 21, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUnblockPlayer(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.UnblockPlayer(bgs.protocol.user_manager.v1.UnblockPlayerRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 21, token, &response);
      else
        SendResponse(service_hash_, 21, token, status);
      break;
    }
    case 40: {
      ::bgs::protocol::user_manager::v1::BlockPlayerRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.BlockPlayerForSession server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 40, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleBlockPlayerForSession(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.BlockPlayerForSession(bgs.protocol.user_manager.v1.BlockPlayerRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 40, token, &response);
      else
        SendResponse(service_hash_, 40, token, status);
      break;
    }
    case 50: {
      ::bgs::protocol::EntityId request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.LoadBlockList server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 50, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleLoadBlockList(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.LoadBlockList(bgs.protocol.EntityId{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 50, token, &response);
      else
        SendResponse(service_hash_, 50, token, status);
      break;
    }
    case 51: {
      ::bgs::protocol::user_manager::v1::UnsubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerService.Unsubscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 51, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUnsubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerService.Unsubscribe(bgs.protocol.user_manager.v1.UnsubscribeRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 51, token, &response);
      else
        SendResponse(service_hash_, 51, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 UserManagerService::HandleSubscribe(::bgs::protocol::user_manager::v1::SubscribeRequest const* request, ::bgs::protocol::user_manager::v1::SubscribeResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.Subscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleAddRecentPlayers(::bgs::protocol::user_manager::v1::AddRecentPlayersRequest const* request, ::bgs::protocol::user_manager::v1::AddRecentPlayersResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.AddRecentPlayers({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleClearRecentPlayers(::bgs::protocol::user_manager::v1::ClearRecentPlayersRequest const* request, ::bgs::protocol::user_manager::v1::ClearRecentPlayersResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.ClearRecentPlayers({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleBlockPlayer(::bgs::protocol::user_manager::v1::BlockPlayerRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.BlockPlayer({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleUnblockPlayer(::bgs::protocol::user_manager::v1::UnblockPlayerRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.UnblockPlayer({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleBlockPlayerForSession(::bgs::protocol::user_manager::v1::BlockPlayerRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.BlockPlayerForSession({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleLoadBlockList(::bgs::protocol::EntityId const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.LoadBlockList({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerService::HandleUnsubscribe(::bgs::protocol::user_manager::v1::UnsubscribeRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerService.Unsubscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

UserManagerListener::UserManagerListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

UserManagerListener::~UserManagerListener() {
}

google::protobuf::ServiceDescriptor const* UserManagerListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserManagerListener_descriptor_;
}

void UserManagerListener::OnBlockedPlayerAdded(::bgs::protocol::user_manager::v1::BlockedPlayerAddedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerListener.OnBlockedPlayerAdded(bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void UserManagerListener::OnBlockedPlayerRemoved(::bgs::protocol::user_manager::v1::BlockedPlayerRemovedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerListener.OnBlockedPlayerRemoved(bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 2, request);
}

void UserManagerListener::OnRecentPlayersAdded(::bgs::protocol::user_manager::v1::RecentPlayersAddedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerListener.OnRecentPlayersAdded(bgs.protocol.user_manager.v1.RecentPlayersAddedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 11, request);
}

void UserManagerListener::OnRecentPlayersRemoved(::bgs::protocol::user_manager::v1::RecentPlayersRemovedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method UserManagerListener.OnRecentPlayersRemoved(bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 12, request);
}

void UserManagerListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::user_manager::v1::BlockedPlayerAddedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerListener.OnBlockedPlayerAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnBlockedPlayerAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerListener.OnBlockedPlayerAdded(bgs.protocol.user_manager.v1.BlockedPlayerAddedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::user_manager::v1::BlockedPlayerRemovedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerListener.OnBlockedPlayerRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnBlockedPlayerRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerListener.OnBlockedPlayerRemoved(bgs.protocol.user_manager.v1.BlockedPlayerRemovedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 11: {
      ::bgs::protocol::user_manager::v1::RecentPlayersAddedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerListener.OnRecentPlayersAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 11, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnRecentPlayersAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerListener.OnRecentPlayersAdded(bgs.protocol.user_manager.v1.RecentPlayersAddedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 11, token, status);
      break;
    }
    case 12: {
      ::bgs::protocol::user_manager::v1::RecentPlayersRemovedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for UserManagerListener.OnRecentPlayersRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 12, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnRecentPlayersRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method UserManagerListener.OnRecentPlayersRemoved(bgs.protocol.user_manager.v1.RecentPlayersRemovedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 12, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 UserManagerListener::HandleOnBlockedPlayerAdded(::bgs::protocol::user_manager::v1::BlockedPlayerAddedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerListener.OnBlockedPlayerAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerListener::HandleOnBlockedPlayerRemoved(::bgs::protocol::user_manager::v1::BlockedPlayerRemovedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerListener.OnBlockedPlayerRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerListener::HandleOnRecentPlayersAdded(::bgs::protocol::user_manager::v1::RecentPlayersAddedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerListener.OnRecentPlayersAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 UserManagerListener::HandleOnRecentPlayersRemoved(::bgs::protocol::user_manager::v1::RecentPlayersRemovedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method UserManagerListener.OnRecentPlayersRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace user_manager
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
