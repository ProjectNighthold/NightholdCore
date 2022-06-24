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
#include "channel_service.pb.h"

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
namespace channel {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* RemoveMemberRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RemoveMemberRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendMessageRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendMessageRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateChannelStateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateChannelStateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateMemberStateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateMemberStateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* DissolveRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DissolveRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* JoinNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  JoinNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* MemberAddedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemberAddedNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* LeaveNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LeaveNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* MemberRemovedNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemberRemovedNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendMessageNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendMessageNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateChannelStateNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateChannelStateNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateMemberStateNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateMemberStateNotification_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* ChannelService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* ChannelListener_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_channel_5fservice_2eproto() {
  protobuf_AddDesc_channel_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "channel_service.proto");
  GOOGLE_CHECK(file != NULL);
  RemoveMemberRequest_descriptor_ = file->message_type(0);
  static const int RemoveMemberRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RemoveMemberRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RemoveMemberRequest, member_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RemoveMemberRequest, reason_),
  };
  RemoveMemberRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RemoveMemberRequest_descriptor_,
      RemoveMemberRequest::default_instance_,
      RemoveMemberRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RemoveMemberRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RemoveMemberRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RemoveMemberRequest));
  SendMessageRequest_descriptor_ = file->message_type(1);
  static const int SendMessageRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageRequest, message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageRequest, required_privileges_),
  };
  SendMessageRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendMessageRequest_descriptor_,
      SendMessageRequest::default_instance_,
      SendMessageRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendMessageRequest));
  UpdateChannelStateRequest_descriptor_ = file->message_type(2);
  static const int UpdateChannelStateRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateRequest, state_change_),
  };
  UpdateChannelStateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateChannelStateRequest_descriptor_,
      UpdateChannelStateRequest::default_instance_,
      UpdateChannelStateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateChannelStateRequest));
  UpdateMemberStateRequest_descriptor_ = file->message_type(3);
  static const int UpdateMemberStateRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateRequest, state_change_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateRequest, removed_role_),
  };
  UpdateMemberStateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateMemberStateRequest_descriptor_,
      UpdateMemberStateRequest::default_instance_,
      UpdateMemberStateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateMemberStateRequest));
  DissolveRequest_descriptor_ = file->message_type(4);
  static const int DissolveRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DissolveRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DissolveRequest, reason_),
  };
  DissolveRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DissolveRequest_descriptor_,
      DissolveRequest::default_instance_,
      DissolveRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DissolveRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DissolveRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DissolveRequest));
  JoinNotification_descriptor_ = file->message_type(5);
  static const int JoinNotification_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, self_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, member_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, channel_state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, subscriber_),
  };
  JoinNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      JoinNotification_descriptor_,
      JoinNotification::default_instance_,
      JoinNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(JoinNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(JoinNotification));
  MemberAddedNotification_descriptor_ = file->message_type(6);
  static const int MemberAddedNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAddedNotification, member_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAddedNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAddedNotification, subscriber_),
  };
  MemberAddedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemberAddedNotification_descriptor_,
      MemberAddedNotification::default_instance_,
      MemberAddedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAddedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAddedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemberAddedNotification));
  LeaveNotification_descriptor_ = file->message_type(7);
  static const int LeaveNotification_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, member_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, reason_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, subscriber_),
  };
  LeaveNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LeaveNotification_descriptor_,
      LeaveNotification::default_instance_,
      LeaveNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LeaveNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LeaveNotification));
  MemberRemovedNotification_descriptor_ = file->message_type(8);
  static const int MemberRemovedNotification_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, member_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, reason_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, subscriber_),
  };
  MemberRemovedNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemberRemovedNotification_descriptor_,
      MemberRemovedNotification::default_instance_,
      MemberRemovedNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberRemovedNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemberRemovedNotification));
  SendMessageNotification_descriptor_ = file->message_type(9);
  static const int SendMessageNotification_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, required_privileges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, subscriber_),
  };
  SendMessageNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendMessageNotification_descriptor_,
      SendMessageNotification::default_instance_,
      SendMessageNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendMessageNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendMessageNotification));
  UpdateChannelStateNotification_descriptor_ = file->message_type(10);
  static const int UpdateChannelStateNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, state_change_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, subscriber_),
  };
  UpdateChannelStateNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateChannelStateNotification_descriptor_,
      UpdateChannelStateNotification::default_instance_,
      UpdateChannelStateNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateChannelStateNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateChannelStateNotification));
  UpdateMemberStateNotification_descriptor_ = file->message_type(11);
  static const int UpdateMemberStateNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, state_change_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, subscriber_),
  };
  UpdateMemberStateNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateMemberStateNotification_descriptor_,
      UpdateMemberStateNotification::default_instance_,
      UpdateMemberStateNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateMemberStateNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateMemberStateNotification));
  ChannelService_descriptor_ = file->service(0);
  ChannelListener_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_channel_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RemoveMemberRequest_descriptor_, &RemoveMemberRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendMessageRequest_descriptor_, &SendMessageRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateChannelStateRequest_descriptor_, &UpdateChannelStateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateMemberStateRequest_descriptor_, &UpdateMemberStateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DissolveRequest_descriptor_, &DissolveRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    JoinNotification_descriptor_, &JoinNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemberAddedNotification_descriptor_, &MemberAddedNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LeaveNotification_descriptor_, &LeaveNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemberRemovedNotification_descriptor_, &MemberRemovedNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendMessageNotification_descriptor_, &SendMessageNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateChannelStateNotification_descriptor_, &UpdateChannelStateNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateMemberStateNotification_descriptor_, &UpdateMemberStateNotification::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_channel_5fservice_2eproto() {
  delete RemoveMemberRequest::default_instance_;
  delete RemoveMemberRequest_reflection_;
  delete SendMessageRequest::default_instance_;
  delete SendMessageRequest_reflection_;
  delete UpdateChannelStateRequest::default_instance_;
  delete UpdateChannelStateRequest_reflection_;
  delete UpdateMemberStateRequest::default_instance_;
  delete UpdateMemberStateRequest_reflection_;
  delete DissolveRequest::default_instance_;
  delete DissolveRequest_reflection_;
  delete JoinNotification::default_instance_;
  delete JoinNotification_reflection_;
  delete MemberAddedNotification::default_instance_;
  delete MemberAddedNotification_reflection_;
  delete LeaveNotification::default_instance_;
  delete LeaveNotification_reflection_;
  delete MemberRemovedNotification::default_instance_;
  delete MemberRemovedNotification_reflection_;
  delete SendMessageNotification::default_instance_;
  delete SendMessageNotification_reflection_;
  delete UpdateChannelStateNotification::default_instance_;
  delete UpdateChannelStateNotification_reflection_;
  delete UpdateMemberStateNotification::default_instance_;
  delete UpdateMemberStateNotification_reflection_;
}

void protobuf_AddDesc_channel_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::account::v1::protobuf_AddDesc_account_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::channel::v1::protobuf_AddDesc_channel_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025channel_service.proto\022\027bgs.protocol.ch"
    "annel.v1\032\023account_types.proto\032\022entity_ty"
    "pes.proto\032\023channel_types.proto\032\017rpc_type"
    "s.proto\"z\n\023RemoveMemberRequest\022(\n\010agent_"
    "id\030\001 \001(\0132\026.bgs.protocol.EntityId\022)\n\tmemb"
    "er_id\030\002 \002(\0132\026.bgs.protocol.EntityId\022\016\n\006r"
    "eason\030\003 \001(\r\"\221\001\n\022SendMessageRequest\022(\n\010ag"
    "ent_id\030\001 \001(\0132\026.bgs.protocol.EntityId\0221\n\007"
    "message\030\002 \002(\0132 .bgs.protocol.channel.v1."
    "Message\022\036\n\023required_privileges\030\003 \001(\004:\0010\""
    "\202\001\n\031UpdateChannelStateRequest\022(\n\010agent_i"
    "d\030\001 \001(\0132\026.bgs.protocol.EntityId\022;\n\014state"
    "_change\030\002 \002(\0132%.bgs.protocol.channel.v1."
    "ChannelState\"\225\001\n\030UpdateMemberStateReques"
    "t\022(\n\010agent_id\030\001 \001(\0132\026.bgs.protocol.Entit"
    "yId\0225\n\014state_change\030\002 \003(\0132\037.bgs.protocol"
    ".channel.v1.Member\022\030\n\014removed_role\030\003 \003(\r"
    "B\002\020\001\"K\n\017DissolveRequest\022(\n\010agent_id\030\001 \001("
    "\0132\026.bgs.protocol.EntityId\022\016\n\006reason\030\002 \001("
    "\r\"\237\002\n\020JoinNotification\022-\n\004self\030\001 \001(\0132\037.b"
    "gs.protocol.channel.v1.Member\022/\n\006member\030"
    "\002 \003(\0132\037.bgs.protocol.channel.v1.Member\022<"
    "\n\rchannel_state\030\003 \002(\0132%.bgs.protocol.cha"
    "nnel.v1.ChannelState\0226\n\nchannel_id\030\004 \001(\013"
    "2\".bgs.protocol.channel.v1.ChannelId\0225\n\n"
    "subscriber\030\005 \001(\0132!.bgs.protocol.account."
    "v1.Identity\"\271\001\n\027MemberAddedNotification\022"
    "/\n\006member\030\001 \002(\0132\037.bgs.protocol.channel.v"
    "1.Member\0226\n\nchannel_id\030\002 \001(\0132\".bgs.proto"
    "col.channel.v1.ChannelId\0225\n\nsubscriber\030\003"
    " \001(\0132!.bgs.protocol.account.v1.Identity\""
    "\353\001\n\021LeaveNotification\022(\n\010agent_id\030\001 \001(\0132"
    "\026.bgs.protocol.EntityId\022-\n\tmember_id\030\002 \002"
    "(\0132\026.bgs.protocol.EntityIdB\002\030\001\022\016\n\006reason"
    "\030\003 \001(\r\0226\n\nchannel_id\030\004 \001(\0132\".bgs.protoco"
    "l.channel.v1.ChannelId\0225\n\nsubscriber\030\005 \001"
    "(\0132!.bgs.protocol.account.v1.Identity\"\357\001"
    "\n\031MemberRemovedNotification\022(\n\010agent_id\030"
    "\001 \001(\0132\026.bgs.protocol.EntityId\022)\n\tmember_"
    "id\030\002 \002(\0132\026.bgs.protocol.EntityId\022\016\n\006reas"
    "on\030\003 \001(\r\0226\n\nchannel_id\030\004 \001(\0132\".bgs.proto"
    "col.channel.v1.ChannelId\0225\n\nsubscriber\030\005"
    " \001(\0132!.bgs.protocol.account.v1.Identity\""
    "\231\002\n\027SendMessageNotification\022(\n\010agent_id\030"
    "\001 \001(\0132\026.bgs.protocol.EntityId\0221\n\007message"
    "\030\002 \002(\0132 .bgs.protocol.channel.v1.Message"
    "\022\036\n\023required_privileges\030\003 \001(\004:\0010\022\022\n\nbatt"
    "le_tag\030\004 \001(\t\0226\n\nchannel_id\030\005 \001(\0132\".bgs.p"
    "rotocol.channel.v1.ChannelId\0225\n\nsubscrib"
    "er\030\006 \001(\0132!.bgs.protocol.account.v1.Ident"
    "ity\"\366\001\n\036UpdateChannelStateNotification\022("
    "\n\010agent_id\030\001 \001(\0132\026.bgs.protocol.EntityId"
    "\022;\n\014state_change\030\002 \002(\0132%.bgs.protocol.ch"
    "annel.v1.ChannelState\0226\n\nchannel_id\030\003 \001("
    "\0132\".bgs.protocol.channel.v1.ChannelId\0225\n"
    "\nsubscriber\030\004 \001(\0132!.bgs.protocol.account"
    ".v1.Identity\"\357\001\n\035UpdateMemberStateNotifi"
    "cation\022(\n\010agent_id\030\001 \001(\0132\026.bgs.protocol."
    "EntityId\0225\n\014state_change\030\002 \003(\0132\037.bgs.pro"
    "tocol.channel.v1.Member\0226\n\nchannel_id\030\004 "
    "\001(\0132\".bgs.protocol.channel.v1.ChannelId\022"
    "5\n\nsubscriber\030\005 \001(\0132!.bgs.protocol.accou"
    "nt.v1.Identity2\200\004\n\016ChannelService\022X\n\014Rem"
    "oveMember\022,.bgs.protocol.channel.v1.Remo"
    "veMemberRequest\032\024.bgs.protocol.NoData\"\004\200"
    "\265\030\002\022V\n\013SendMessage\022+.bgs.protocol.channe"
    "l.v1.SendMessageRequest\032\024.bgs.protocol.N"
    "oData\"\004\200\265\030\003\022d\n\022UpdateChannelState\0222.bgs."
    "protocol.channel.v1.UpdateChannelStateRe"
    "quest\032\024.bgs.protocol.NoData\"\004\200\265\030\004\022b\n\021Upd"
    "ateMemberState\0221.bgs.protocol.channel.v1"
    ".UpdateMemberStateRequest\032\024.bgs.protocol"
    ".NoData\"\004\200\265\030\005\022P\n\010Dissolve\022(.bgs.protocol"
    ".channel.v1.DissolveRequest\032\024.bgs.protoc"
    "ol.NoData\"\004\200\265\030\006\032 \312>\035bnet.protocol.channe"
    "l.Channel2\375\005\n\017ChannelListener\022T\n\006OnJoin\022"
    ").bgs.protocol.channel.v1.JoinNotificati"
    "on\032\031.bgs.protocol.NO_RESPONSE\"\004\200\265\030\001\022b\n\rO"
    "nMemberAdded\0220.bgs.protocol.channel.v1.M"
    "emberAddedNotification\032\031.bgs.protocol.NO"
    "_RESPONSE\"\004\200\265\030\002\022V\n\007OnLeave\022*.bgs.protoco"
    "l.channel.v1.LeaveNotification\032\031.bgs.pro"
    "tocol.NO_RESPONSE\"\004\200\265\030\003\022f\n\017OnMemberRemov"
    "ed\0222.bgs.protocol.channel.v1.MemberRemov"
    "edNotification\032\031.bgs.protocol.NO_RESPONS"
    "E\"\004\200\265\030\004\022b\n\rOnSendMessage\0220.bgs.protocol."
    "channel.v1.SendMessageNotification\032\031.bgs"
    ".protocol.NO_RESPONSE\"\004\200\265\030\005\022p\n\024OnUpdateC"
    "hannelState\0227.bgs.protocol.channel.v1.Up"
    "dateChannelStateNotification\032\031.bgs.proto"
    "col.NO_RESPONSE\"\004\200\265\030\006\022n\n\023OnUpdateMemberS"
    "tate\0226.bgs.protocol.channel.v1.UpdateMem"
    "berStateNotification\032\031.bgs.protocol.NO_R"
    "ESPONSE\"\004\200\265\030\007\032*\312>\'bnet.protocol.channel."
    "ChannelSubscriberB\005H\001\200\001\000", 3784);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "channel_service.proto", &protobuf_RegisterTypes);
  RemoveMemberRequest::default_instance_ = new RemoveMemberRequest();
  SendMessageRequest::default_instance_ = new SendMessageRequest();
  UpdateChannelStateRequest::default_instance_ = new UpdateChannelStateRequest();
  UpdateMemberStateRequest::default_instance_ = new UpdateMemberStateRequest();
  DissolveRequest::default_instance_ = new DissolveRequest();
  JoinNotification::default_instance_ = new JoinNotification();
  MemberAddedNotification::default_instance_ = new MemberAddedNotification();
  LeaveNotification::default_instance_ = new LeaveNotification();
  MemberRemovedNotification::default_instance_ = new MemberRemovedNotification();
  SendMessageNotification::default_instance_ = new SendMessageNotification();
  UpdateChannelStateNotification::default_instance_ = new UpdateChannelStateNotification();
  UpdateMemberStateNotification::default_instance_ = new UpdateMemberStateNotification();
  RemoveMemberRequest::default_instance_->InitAsDefaultInstance();
  SendMessageRequest::default_instance_->InitAsDefaultInstance();
  UpdateChannelStateRequest::default_instance_->InitAsDefaultInstance();
  UpdateMemberStateRequest::default_instance_->InitAsDefaultInstance();
  DissolveRequest::default_instance_->InitAsDefaultInstance();
  JoinNotification::default_instance_->InitAsDefaultInstance();
  MemberAddedNotification::default_instance_->InitAsDefaultInstance();
  LeaveNotification::default_instance_->InitAsDefaultInstance();
  MemberRemovedNotification::default_instance_->InitAsDefaultInstance();
  SendMessageNotification::default_instance_->InitAsDefaultInstance();
  UpdateChannelStateNotification::default_instance_->InitAsDefaultInstance();
  UpdateMemberStateNotification::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_channel_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_channel_5fservice_2eproto {
  StaticDescriptorInitializer_channel_5fservice_2eproto() {
    protobuf_AddDesc_channel_5fservice_2eproto();
  }
} static_descriptor_initializer_channel_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RemoveMemberRequest::kAgentIdFieldNumber;
const int RemoveMemberRequest::kMemberIdFieldNumber;
const int RemoveMemberRequest::kReasonFieldNumber;
#endif  // !_MSC_VER

RemoveMemberRequest::RemoveMemberRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.RemoveMemberRequest)
}

void RemoveMemberRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  member_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

RemoveMemberRequest::RemoveMemberRequest(const RemoveMemberRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.RemoveMemberRequest)
}

void RemoveMemberRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  member_id_ = NULL;
  reason_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RemoveMemberRequest::~RemoveMemberRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.RemoveMemberRequest)
  SharedDtor();
}

void RemoveMemberRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete member_id_;
  }
}

void RemoveMemberRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RemoveMemberRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RemoveMemberRequest_descriptor_;
}

const RemoveMemberRequest& RemoveMemberRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

RemoveMemberRequest* RemoveMemberRequest::default_instance_ = NULL;

RemoveMemberRequest* RemoveMemberRequest::New() const {
  return new RemoveMemberRequest;
}

void RemoveMemberRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_member_id()) {
      if (member_id_ != NULL) member_id_->::bgs::protocol::EntityId::Clear();
    }
    reason_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RemoveMemberRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.RemoveMemberRequest)
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
        if (input->ExpectTag(18)) goto parse_member_id;
        break;
      }

      // required .bgs.protocol.EntityId member_id = 2;
      case 2: {
        if (tag == 18) {
         parse_member_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_member_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 3;
      case 3: {
        if (tag == 24) {
         parse_reason:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &reason_)));
          set_has_reason();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.RemoveMemberRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.RemoveMemberRequest)
  return false;
#undef DO_
}

void RemoveMemberRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.RemoveMemberRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId member_id = 2;
  if (has_member_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->member_id(), output);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->reason(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.RemoveMemberRequest)
}

::google::protobuf::uint8* RemoveMemberRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.RemoveMemberRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId member_id = 2;
  if (has_member_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->member_id(), target);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->reason(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.RemoveMemberRequest)
  return target;
}

int RemoveMemberRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.EntityId member_id = 2;
    if (has_member_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->member_id());
    }

    // optional uint32 reason = 3;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
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

void RemoveMemberRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RemoveMemberRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RemoveMemberRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RemoveMemberRequest::MergeFrom(const RemoveMemberRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_member_id()) {
      mutable_member_id()->::bgs::protocol::EntityId::MergeFrom(from.member_id());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RemoveMemberRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RemoveMemberRequest::CopyFrom(const RemoveMemberRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RemoveMemberRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_member_id()) {
    if (!this->member_id().IsInitialized()) return false;
  }
  return true;
}

void RemoveMemberRequest::Swap(RemoveMemberRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(member_id_, other->member_id_);
    std::swap(reason_, other->reason_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RemoveMemberRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RemoveMemberRequest_descriptor_;
  metadata.reflection = RemoveMemberRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendMessageRequest::kAgentIdFieldNumber;
const int SendMessageRequest::kMessageFieldNumber;
const int SendMessageRequest::kRequiredPrivilegesFieldNumber;
#endif  // !_MSC_VER

SendMessageRequest::SendMessageRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.SendMessageRequest)
}

void SendMessageRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  message_ = const_cast< ::bgs::protocol::channel::v1::Message*>(&::bgs::protocol::channel::v1::Message::default_instance());
}

SendMessageRequest::SendMessageRequest(const SendMessageRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.SendMessageRequest)
}

void SendMessageRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  message_ = NULL;
  required_privileges_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendMessageRequest::~SendMessageRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.SendMessageRequest)
  SharedDtor();
}

void SendMessageRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete message_;
  }
}

void SendMessageRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendMessageRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendMessageRequest_descriptor_;
}

const SendMessageRequest& SendMessageRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

SendMessageRequest* SendMessageRequest::default_instance_ = NULL;

SendMessageRequest* SendMessageRequest::New() const {
  return new SendMessageRequest;
}

void SendMessageRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_message()) {
      if (message_ != NULL) message_->::bgs::protocol::channel::v1::Message::Clear();
    }
    required_privileges_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendMessageRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.SendMessageRequest)
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
        if (input->ExpectTag(18)) goto parse_message;
        break;
      }

      // required .bgs.protocol.channel.v1.Message message = 2;
      case 2: {
        if (tag == 18) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_required_privileges;
        break;
      }

      // optional uint64 required_privileges = 3 [default = 0];
      case 3: {
        if (tag == 24) {
         parse_required_privileges:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &required_privileges_)));
          set_has_required_privileges();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.SendMessageRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.SendMessageRequest)
  return false;
#undef DO_
}

void SendMessageRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.SendMessageRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.channel.v1.Message message = 2;
  if (has_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->message(), output);
  }

  // optional uint64 required_privileges = 3 [default = 0];
  if (has_required_privileges()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->required_privileges(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.SendMessageRequest)
}

::google::protobuf::uint8* SendMessageRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.SendMessageRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.channel.v1.Message message = 2;
  if (has_message()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->message(), target);
  }

  // optional uint64 required_privileges = 3 [default = 0];
  if (has_required_privileges()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->required_privileges(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.SendMessageRequest)
  return target;
}

int SendMessageRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.channel.v1.Message message = 2;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->message());
    }

    // optional uint64 required_privileges = 3 [default = 0];
    if (has_required_privileges()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->required_privileges());
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

void SendMessageRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendMessageRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendMessageRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendMessageRequest::MergeFrom(const SendMessageRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_message()) {
      mutable_message()->::bgs::protocol::channel::v1::Message::MergeFrom(from.message());
    }
    if (from.has_required_privileges()) {
      set_required_privileges(from.required_privileges());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendMessageRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendMessageRequest::CopyFrom(const SendMessageRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendMessageRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_message()) {
    if (!this->message().IsInitialized()) return false;
  }
  return true;
}

void SendMessageRequest::Swap(SendMessageRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(message_, other->message_);
    std::swap(required_privileges_, other->required_privileges_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendMessageRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendMessageRequest_descriptor_;
  metadata.reflection = SendMessageRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateChannelStateRequest::kAgentIdFieldNumber;
const int UpdateChannelStateRequest::kStateChangeFieldNumber;
#endif  // !_MSC_VER

UpdateChannelStateRequest::UpdateChannelStateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.UpdateChannelStateRequest)
}

void UpdateChannelStateRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  state_change_ = const_cast< ::bgs::protocol::channel::v1::ChannelState*>(&::bgs::protocol::channel::v1::ChannelState::default_instance());
}

UpdateChannelStateRequest::UpdateChannelStateRequest(const UpdateChannelStateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.UpdateChannelStateRequest)
}

void UpdateChannelStateRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  state_change_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateChannelStateRequest::~UpdateChannelStateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  SharedDtor();
}

void UpdateChannelStateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete state_change_;
  }
}

void UpdateChannelStateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateChannelStateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateChannelStateRequest_descriptor_;
}

const UpdateChannelStateRequest& UpdateChannelStateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

UpdateChannelStateRequest* UpdateChannelStateRequest::default_instance_ = NULL;

UpdateChannelStateRequest* UpdateChannelStateRequest::New() const {
  return new UpdateChannelStateRequest;
}

void UpdateChannelStateRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_state_change()) {
      if (state_change_ != NULL) state_change_->::bgs::protocol::channel::v1::ChannelState::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateChannelStateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.UpdateChannelStateRequest)
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
        if (input->ExpectTag(18)) goto parse_state_change;
        break;
      }

      // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
      case 2: {
        if (tag == 18) {
         parse_state_change:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state_change()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  return false;
#undef DO_
}

void UpdateChannelStateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
  if (has_state_change()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->state_change(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.UpdateChannelStateRequest)
}

::google::protobuf::uint8* UpdateChannelStateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
  if (has_state_change()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->state_change(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.UpdateChannelStateRequest)
  return target;
}

int UpdateChannelStateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
    if (has_state_change()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state_change());
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

void UpdateChannelStateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateChannelStateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateChannelStateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateChannelStateRequest::MergeFrom(const UpdateChannelStateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_state_change()) {
      mutable_state_change()->::bgs::protocol::channel::v1::ChannelState::MergeFrom(from.state_change());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateChannelStateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateChannelStateRequest::CopyFrom(const UpdateChannelStateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateChannelStateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_state_change()) {
    if (!this->state_change().IsInitialized()) return false;
  }
  return true;
}

void UpdateChannelStateRequest::Swap(UpdateChannelStateRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(state_change_, other->state_change_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateChannelStateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateChannelStateRequest_descriptor_;
  metadata.reflection = UpdateChannelStateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateMemberStateRequest::kAgentIdFieldNumber;
const int UpdateMemberStateRequest::kStateChangeFieldNumber;
const int UpdateMemberStateRequest::kRemovedRoleFieldNumber;
#endif  // !_MSC_VER

UpdateMemberStateRequest::UpdateMemberStateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.UpdateMemberStateRequest)
}

void UpdateMemberStateRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UpdateMemberStateRequest::UpdateMemberStateRequest(const UpdateMemberStateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.UpdateMemberStateRequest)
}

void UpdateMemberStateRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  _removed_role_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateMemberStateRequest::~UpdateMemberStateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  SharedDtor();
}

void UpdateMemberStateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void UpdateMemberStateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateMemberStateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateMemberStateRequest_descriptor_;
}

const UpdateMemberStateRequest& UpdateMemberStateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

UpdateMemberStateRequest* UpdateMemberStateRequest::default_instance_ = NULL;

UpdateMemberStateRequest* UpdateMemberStateRequest::New() const {
  return new UpdateMemberStateRequest;
}

void UpdateMemberStateRequest::Clear() {
  if (has_agent_id()) {
    if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
  }
  state_change_.Clear();
  removed_role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateMemberStateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.UpdateMemberStateRequest)
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
        if (input->ExpectTag(18)) goto parse_state_change;
        break;
      }

      // repeated .bgs.protocol.channel.v1.Member state_change = 2;
      case 2: {
        if (tag == 18) {
         parse_state_change:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_state_change()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_state_change;
        if (input->ExpectTag(26)) goto parse_removed_role;
        break;
      }

      // repeated uint32 removed_role = 3 [packed = true];
      case 3: {
        if (tag == 26) {
         parse_removed_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_removed_role())));
        } else if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 26, input, this->mutable_removed_role())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  return false;
#undef DO_
}

void UpdateMemberStateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  for (int i = 0; i < this->state_change_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->state_change(i), output);
  }

  // repeated uint32 removed_role = 3 [packed = true];
  if (this->removed_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_removed_role_cached_byte_size_);
  }
  for (int i = 0; i < this->removed_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->removed_role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.UpdateMemberStateRequest)
}

::google::protobuf::uint8* UpdateMemberStateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  for (int i = 0; i < this->state_change_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->state_change(i), target);
  }

  // repeated uint32 removed_role = 3 [packed = true];
  if (this->removed_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _removed_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->removed_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->removed_role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.UpdateMemberStateRequest)
  return target;
}

int UpdateMemberStateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

  }
  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  total_size += 1 * this->state_change_size();
  for (int i = 0; i < this->state_change_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->state_change(i));
  }

  // repeated uint32 removed_role = 3 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->removed_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->removed_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _removed_role_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
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

void UpdateMemberStateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateMemberStateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateMemberStateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateMemberStateRequest::MergeFrom(const UpdateMemberStateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  state_change_.MergeFrom(from.state_change_);
  removed_role_.MergeFrom(from.removed_role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateMemberStateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateMemberStateRequest::CopyFrom(const UpdateMemberStateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateMemberStateRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->state_change())) return false;
  return true;
}

void UpdateMemberStateRequest::Swap(UpdateMemberStateRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    state_change_.Swap(&other->state_change_);
    removed_role_.Swap(&other->removed_role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateMemberStateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateMemberStateRequest_descriptor_;
  metadata.reflection = UpdateMemberStateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DissolveRequest::kAgentIdFieldNumber;
const int DissolveRequest::kReasonFieldNumber;
#endif  // !_MSC_VER

DissolveRequest::DissolveRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.DissolveRequest)
}

void DissolveRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

DissolveRequest::DissolveRequest(const DissolveRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.DissolveRequest)
}

void DissolveRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  reason_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DissolveRequest::~DissolveRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.DissolveRequest)
  SharedDtor();
}

void DissolveRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
  }
}

void DissolveRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DissolveRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DissolveRequest_descriptor_;
}

const DissolveRequest& DissolveRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

DissolveRequest* DissolveRequest::default_instance_ = NULL;

DissolveRequest* DissolveRequest::New() const {
  return new DissolveRequest;
}

void DissolveRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    reason_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DissolveRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.DissolveRequest)
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
        if (input->ExpectTag(16)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 2;
      case 2: {
        if (tag == 16) {
         parse_reason:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &reason_)));
          set_has_reason();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.DissolveRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.DissolveRequest)
  return false;
#undef DO_
}

void DissolveRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.DissolveRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // optional uint32 reason = 2;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->reason(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.DissolveRequest)
}

::google::protobuf::uint8* DissolveRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.DissolveRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // optional uint32 reason = 2;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->reason(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.DissolveRequest)
  return target;
}

int DissolveRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional uint32 reason = 2;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
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

void DissolveRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DissolveRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DissolveRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DissolveRequest::MergeFrom(const DissolveRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DissolveRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DissolveRequest::CopyFrom(const DissolveRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DissolveRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void DissolveRequest::Swap(DissolveRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(reason_, other->reason_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DissolveRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DissolveRequest_descriptor_;
  metadata.reflection = DissolveRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int JoinNotification::kSelfFieldNumber;
const int JoinNotification::kMemberFieldNumber;
const int JoinNotification::kChannelStateFieldNumber;
const int JoinNotification::kChannelIdFieldNumber;
const int JoinNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

JoinNotification::JoinNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.JoinNotification)
}

void JoinNotification::InitAsDefaultInstance() {
  self_ = const_cast< ::bgs::protocol::channel::v1::Member*>(&::bgs::protocol::channel::v1::Member::default_instance());
  channel_state_ = const_cast< ::bgs::protocol::channel::v1::ChannelState*>(&::bgs::protocol::channel::v1::ChannelState::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

JoinNotification::JoinNotification(const JoinNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.JoinNotification)
}

void JoinNotification::SharedCtor() {
  _cached_size_ = 0;
  self_ = NULL;
  channel_state_ = NULL;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

JoinNotification::~JoinNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.JoinNotification)
  SharedDtor();
}

void JoinNotification::SharedDtor() {
  if (this != default_instance_) {
    delete self_;
    delete channel_state_;
    delete channel_id_;
    delete subscriber_;
  }
}

void JoinNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* JoinNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return JoinNotification_descriptor_;
}

const JoinNotification& JoinNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

JoinNotification* JoinNotification::default_instance_ = NULL;

JoinNotification* JoinNotification::New() const {
  return new JoinNotification;
}

void JoinNotification::Clear() {
  if (_has_bits_[0 / 32] & 29) {
    if (has_self()) {
      if (self_ != NULL) self_->::bgs::protocol::channel::v1::Member::Clear();
    }
    if (has_channel_state()) {
      if (channel_state_ != NULL) channel_state_->::bgs::protocol::channel::v1::ChannelState::Clear();
    }
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  member_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool JoinNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.JoinNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.channel.v1.Member self = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_self()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_member;
        break;
      }

      // repeated .bgs.protocol.channel.v1.Member member = 2;
      case 2: {
        if (tag == 18) {
         parse_member:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_member()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_member;
        if (input->ExpectTag(26)) goto parse_channel_state;
        break;
      }

      // required .bgs.protocol.channel.v1.ChannelState channel_state = 3;
      case 3: {
        if (tag == 26) {
         parse_channel_state:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_state()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
      case 4: {
        if (tag == 34) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 5;
      case 5: {
        if (tag == 42) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.JoinNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.JoinNotification)
  return false;
#undef DO_
}

void JoinNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.JoinNotification)
  // optional .bgs.protocol.channel.v1.Member self = 1;
  if (has_self()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->self(), output);
  }

  // repeated .bgs.protocol.channel.v1.Member member = 2;
  for (int i = 0; i < this->member_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->member(i), output);
  }

  // required .bgs.protocol.channel.v1.ChannelState channel_state = 3;
  if (has_channel_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->channel_state(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.JoinNotification)
}

::google::protobuf::uint8* JoinNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.JoinNotification)
  // optional .bgs.protocol.channel.v1.Member self = 1;
  if (has_self()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->self(), target);
  }

  // repeated .bgs.protocol.channel.v1.Member member = 2;
  for (int i = 0; i < this->member_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->member(i), target);
  }

  // required .bgs.protocol.channel.v1.ChannelState channel_state = 3;
  if (has_channel_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->channel_state(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.JoinNotification)
  return target;
}

int JoinNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.channel.v1.Member self = 1;
    if (has_self()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->self());
    }

    // required .bgs.protocol.channel.v1.ChannelState channel_state = 3;
    if (has_channel_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_state());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 5;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
    }

  }
  // repeated .bgs.protocol.channel.v1.Member member = 2;
  total_size += 1 * this->member_size();
  for (int i = 0; i < this->member_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->member(i));
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

void JoinNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const JoinNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const JoinNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void JoinNotification::MergeFrom(const JoinNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  member_.MergeFrom(from.member_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_self()) {
      mutable_self()->::bgs::protocol::channel::v1::Member::MergeFrom(from.self());
    }
    if (from.has_channel_state()) {
      mutable_channel_state()->::bgs::protocol::channel::v1::ChannelState::MergeFrom(from.channel_state());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void JoinNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void JoinNotification::CopyFrom(const JoinNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool JoinNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000004) != 0x00000004) return false;

  if (has_self()) {
    if (!this->self().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->member())) return false;
  if (has_channel_state()) {
    if (!this->channel_state().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void JoinNotification::Swap(JoinNotification* other) {
  if (other != this) {
    std::swap(self_, other->self_);
    member_.Swap(&other->member_);
    std::swap(channel_state_, other->channel_state_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata JoinNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = JoinNotification_descriptor_;
  metadata.reflection = JoinNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemberAddedNotification::kMemberFieldNumber;
const int MemberAddedNotification::kChannelIdFieldNumber;
const int MemberAddedNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

MemberAddedNotification::MemberAddedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.MemberAddedNotification)
}

void MemberAddedNotification::InitAsDefaultInstance() {
  member_ = const_cast< ::bgs::protocol::channel::v1::Member*>(&::bgs::protocol::channel::v1::Member::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

MemberAddedNotification::MemberAddedNotification(const MemberAddedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.MemberAddedNotification)
}

void MemberAddedNotification::SharedCtor() {
  _cached_size_ = 0;
  member_ = NULL;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemberAddedNotification::~MemberAddedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.MemberAddedNotification)
  SharedDtor();
}

void MemberAddedNotification::SharedDtor() {
  if (this != default_instance_) {
    delete member_;
    delete channel_id_;
    delete subscriber_;
  }
}

void MemberAddedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemberAddedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemberAddedNotification_descriptor_;
}

const MemberAddedNotification& MemberAddedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

MemberAddedNotification* MemberAddedNotification::default_instance_ = NULL;

MemberAddedNotification* MemberAddedNotification::New() const {
  return new MemberAddedNotification;
}

void MemberAddedNotification::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_member()) {
      if (member_ != NULL) member_->::bgs::protocol::channel::v1::Member::Clear();
    }
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemberAddedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.MemberAddedNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.channel.v1.Member member = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_member()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 2;
      case 2: {
        if (tag == 18) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 3;
      case 3: {
        if (tag == 26) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.MemberAddedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.MemberAddedNotification)
  return false;
#undef DO_
}

void MemberAddedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.MemberAddedNotification)
  // required .bgs.protocol.channel.v1.Member member = 1;
  if (has_member()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->member(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 2;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 3;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.MemberAddedNotification)
}

::google::protobuf::uint8* MemberAddedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.MemberAddedNotification)
  // required .bgs.protocol.channel.v1.Member member = 1;
  if (has_member()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->member(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 2;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 3;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.MemberAddedNotification)
  return target;
}

int MemberAddedNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.channel.v1.Member member = 1;
    if (has_member()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->member());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 2;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 3;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
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

void MemberAddedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemberAddedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemberAddedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemberAddedNotification::MergeFrom(const MemberAddedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_member()) {
      mutable_member()->::bgs::protocol::channel::v1::Member::MergeFrom(from.member());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemberAddedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemberAddedNotification::CopyFrom(const MemberAddedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemberAddedNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_member()) {
    if (!this->member().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void MemberAddedNotification::Swap(MemberAddedNotification* other) {
  if (other != this) {
    std::swap(member_, other->member_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemberAddedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemberAddedNotification_descriptor_;
  metadata.reflection = MemberAddedNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int LeaveNotification::kAgentIdFieldNumber;
const int LeaveNotification::kMemberIdFieldNumber;
const int LeaveNotification::kReasonFieldNumber;
const int LeaveNotification::kChannelIdFieldNumber;
const int LeaveNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

LeaveNotification::LeaveNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.LeaveNotification)
}

void LeaveNotification::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  member_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

LeaveNotification::LeaveNotification(const LeaveNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.LeaveNotification)
}

void LeaveNotification::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  member_id_ = NULL;
  reason_ = 0u;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LeaveNotification::~LeaveNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.LeaveNotification)
  SharedDtor();
}

void LeaveNotification::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete member_id_;
    delete channel_id_;
    delete subscriber_;
  }
}

void LeaveNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LeaveNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LeaveNotification_descriptor_;
}

const LeaveNotification& LeaveNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

LeaveNotification* LeaveNotification::default_instance_ = NULL;

LeaveNotification* LeaveNotification::New() const {
  return new LeaveNotification;
}

void LeaveNotification::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_member_id()) {
      if (member_id_ != NULL) member_id_->::bgs::protocol::EntityId::Clear();
    }
    reason_ = 0u;
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LeaveNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.LeaveNotification)
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
        if (input->ExpectTag(18)) goto parse_member_id;
        break;
      }

      // required .bgs.protocol.EntityId member_id = 2 [deprecated = true];
      case 2: {
        if (tag == 18) {
         parse_member_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_member_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 3;
      case 3: {
        if (tag == 24) {
         parse_reason:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &reason_)));
          set_has_reason();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
      case 4: {
        if (tag == 34) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 5;
      case 5: {
        if (tag == 42) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.LeaveNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.LeaveNotification)
  return false;
#undef DO_
}

void LeaveNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.LeaveNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId member_id = 2 [deprecated = true];
  if (has_member_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->member_id(), output);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->reason(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.LeaveNotification)
}

::google::protobuf::uint8* LeaveNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.LeaveNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId member_id = 2 [deprecated = true];
  if (has_member_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->member_id(), target);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->reason(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.LeaveNotification)
  return target;
}

int LeaveNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.EntityId member_id = 2 [deprecated = true];
    if (has_member_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->member_id());
    }

    // optional uint32 reason = 3;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 5;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
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

void LeaveNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LeaveNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LeaveNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LeaveNotification::MergeFrom(const LeaveNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_member_id()) {
      mutable_member_id()->::bgs::protocol::EntityId::MergeFrom(from.member_id());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LeaveNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LeaveNotification::CopyFrom(const LeaveNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LeaveNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_member_id()) {
    if (!this->member_id().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void LeaveNotification::Swap(LeaveNotification* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(member_id_, other->member_id_);
    std::swap(reason_, other->reason_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LeaveNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LeaveNotification_descriptor_;
  metadata.reflection = LeaveNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemberRemovedNotification::kAgentIdFieldNumber;
const int MemberRemovedNotification::kMemberIdFieldNumber;
const int MemberRemovedNotification::kReasonFieldNumber;
const int MemberRemovedNotification::kChannelIdFieldNumber;
const int MemberRemovedNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

MemberRemovedNotification::MemberRemovedNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.MemberRemovedNotification)
}

void MemberRemovedNotification::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  member_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

MemberRemovedNotification::MemberRemovedNotification(const MemberRemovedNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.MemberRemovedNotification)
}

void MemberRemovedNotification::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  member_id_ = NULL;
  reason_ = 0u;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemberRemovedNotification::~MemberRemovedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.MemberRemovedNotification)
  SharedDtor();
}

void MemberRemovedNotification::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete member_id_;
    delete channel_id_;
    delete subscriber_;
  }
}

void MemberRemovedNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemberRemovedNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemberRemovedNotification_descriptor_;
}

const MemberRemovedNotification& MemberRemovedNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

MemberRemovedNotification* MemberRemovedNotification::default_instance_ = NULL;

MemberRemovedNotification* MemberRemovedNotification::New() const {
  return new MemberRemovedNotification;
}

void MemberRemovedNotification::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_member_id()) {
      if (member_id_ != NULL) member_id_->::bgs::protocol::EntityId::Clear();
    }
    reason_ = 0u;
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemberRemovedNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.MemberRemovedNotification)
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
        if (input->ExpectTag(18)) goto parse_member_id;
        break;
      }

      // required .bgs.protocol.EntityId member_id = 2;
      case 2: {
        if (tag == 18) {
         parse_member_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_member_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 3;
      case 3: {
        if (tag == 24) {
         parse_reason:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &reason_)));
          set_has_reason();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
      case 4: {
        if (tag == 34) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 5;
      case 5: {
        if (tag == 42) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.MemberRemovedNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.MemberRemovedNotification)
  return false;
#undef DO_
}

void MemberRemovedNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.MemberRemovedNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId member_id = 2;
  if (has_member_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->member_id(), output);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->reason(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.MemberRemovedNotification)
}

::google::protobuf::uint8* MemberRemovedNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.MemberRemovedNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId member_id = 2;
  if (has_member_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->member_id(), target);
  }

  // optional uint32 reason = 3;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->reason(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.MemberRemovedNotification)
  return target;
}

int MemberRemovedNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.EntityId member_id = 2;
    if (has_member_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->member_id());
    }

    // optional uint32 reason = 3;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 5;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
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

void MemberRemovedNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemberRemovedNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemberRemovedNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemberRemovedNotification::MergeFrom(const MemberRemovedNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_member_id()) {
      mutable_member_id()->::bgs::protocol::EntityId::MergeFrom(from.member_id());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemberRemovedNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemberRemovedNotification::CopyFrom(const MemberRemovedNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemberRemovedNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_member_id()) {
    if (!this->member_id().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void MemberRemovedNotification::Swap(MemberRemovedNotification* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(member_id_, other->member_id_);
    std::swap(reason_, other->reason_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemberRemovedNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemberRemovedNotification_descriptor_;
  metadata.reflection = MemberRemovedNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendMessageNotification::kAgentIdFieldNumber;
const int SendMessageNotification::kMessageFieldNumber;
const int SendMessageNotification::kRequiredPrivilegesFieldNumber;
const int SendMessageNotification::kBattleTagFieldNumber;
const int SendMessageNotification::kChannelIdFieldNumber;
const int SendMessageNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

SendMessageNotification::SendMessageNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.SendMessageNotification)
}

void SendMessageNotification::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  message_ = const_cast< ::bgs::protocol::channel::v1::Message*>(&::bgs::protocol::channel::v1::Message::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

SendMessageNotification::SendMessageNotification(const SendMessageNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.SendMessageNotification)
}

void SendMessageNotification::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  agent_id_ = NULL;
  message_ = NULL;
  required_privileges_ = GOOGLE_ULONGLONG(0);
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendMessageNotification::~SendMessageNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.SendMessageNotification)
  SharedDtor();
}

void SendMessageNotification::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete agent_id_;
    delete message_;
    delete channel_id_;
    delete subscriber_;
  }
}

void SendMessageNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendMessageNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendMessageNotification_descriptor_;
}

const SendMessageNotification& SendMessageNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

SendMessageNotification* SendMessageNotification::default_instance_ = NULL;

SendMessageNotification* SendMessageNotification::New() const {
  return new SendMessageNotification;
}

void SendMessageNotification::Clear() {
  if (_has_bits_[0 / 32] & 63) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_message()) {
      if (message_ != NULL) message_->::bgs::protocol::channel::v1::Message::Clear();
    }
    required_privileges_ = GOOGLE_ULONGLONG(0);
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendMessageNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.SendMessageNotification)
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
        if (input->ExpectTag(18)) goto parse_message;
        break;
      }

      // required .bgs.protocol.channel.v1.Message message = 2;
      case 2: {
        if (tag == 18) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_required_privileges;
        break;
      }

      // optional uint64 required_privileges = 3 [default = 0];
      case 3: {
        if (tag == 24) {
         parse_required_privileges:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &required_privileges_)));
          set_has_required_privileges();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 4;
      case 4: {
        if (tag == 34) {
         parse_battle_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_battle_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->battle_tag().data(), this->battle_tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "battle_tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 5;
      case 5: {
        if (tag == 42) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 6;
      case 6: {
        if (tag == 50) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.SendMessageNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.SendMessageNotification)
  return false;
#undef DO_
}

void SendMessageNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.SendMessageNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.channel.v1.Message message = 2;
  if (has_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->message(), output);
  }

  // optional uint64 required_privileges = 3 [default = 0];
  if (has_required_privileges()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->required_privileges(), output);
  }

  // optional string battle_tag = 4;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->battle_tag(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 5;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 6;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.SendMessageNotification)
}

::google::protobuf::uint8* SendMessageNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.SendMessageNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.channel.v1.Message message = 2;
  if (has_message()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->message(), target);
  }

  // optional uint64 required_privileges = 3 [default = 0];
  if (has_required_privileges()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->required_privileges(), target);
  }

  // optional string battle_tag = 4;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->battle_tag(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 5;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 6;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.SendMessageNotification)
  return target;
}

int SendMessageNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.channel.v1.Message message = 2;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->message());
    }

    // optional uint64 required_privileges = 3 [default = 0];
    if (has_required_privileges()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->required_privileges());
    }

    // optional string battle_tag = 4;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 5;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 6;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
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

void SendMessageNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendMessageNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendMessageNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendMessageNotification::MergeFrom(const SendMessageNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_message()) {
      mutable_message()->::bgs::protocol::channel::v1::Message::MergeFrom(from.message());
    }
    if (from.has_required_privileges()) {
      set_required_privileges(from.required_privileges());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendMessageNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendMessageNotification::CopyFrom(const SendMessageNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendMessageNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_message()) {
    if (!this->message().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void SendMessageNotification::Swap(SendMessageNotification* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(message_, other->message_);
    std::swap(required_privileges_, other->required_privileges_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendMessageNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendMessageNotification_descriptor_;
  metadata.reflection = SendMessageNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateChannelStateNotification::kAgentIdFieldNumber;
const int UpdateChannelStateNotification::kStateChangeFieldNumber;
const int UpdateChannelStateNotification::kChannelIdFieldNumber;
const int UpdateChannelStateNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

UpdateChannelStateNotification::UpdateChannelStateNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.UpdateChannelStateNotification)
}

void UpdateChannelStateNotification::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  state_change_ = const_cast< ::bgs::protocol::channel::v1::ChannelState*>(&::bgs::protocol::channel::v1::ChannelState::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

UpdateChannelStateNotification::UpdateChannelStateNotification(const UpdateChannelStateNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.UpdateChannelStateNotification)
}

void UpdateChannelStateNotification::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  state_change_ = NULL;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateChannelStateNotification::~UpdateChannelStateNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  SharedDtor();
}

void UpdateChannelStateNotification::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete state_change_;
    delete channel_id_;
    delete subscriber_;
  }
}

void UpdateChannelStateNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateChannelStateNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateChannelStateNotification_descriptor_;
}

const UpdateChannelStateNotification& UpdateChannelStateNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

UpdateChannelStateNotification* UpdateChannelStateNotification::default_instance_ = NULL;

UpdateChannelStateNotification* UpdateChannelStateNotification::New() const {
  return new UpdateChannelStateNotification;
}

void UpdateChannelStateNotification::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_state_change()) {
      if (state_change_ != NULL) state_change_->::bgs::protocol::channel::v1::ChannelState::Clear();
    }
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateChannelStateNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.UpdateChannelStateNotification)
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
        if (input->ExpectTag(18)) goto parse_state_change;
        break;
      }

      // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
      case 2: {
        if (tag == 18) {
         parse_state_change:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state_change()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 3;
      case 3: {
        if (tag == 26) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 4;
      case 4: {
        if (tag == 34) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  return false;
#undef DO_
}

void UpdateChannelStateNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
  if (has_state_change()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->state_change(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 3;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 4;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.UpdateChannelStateNotification)
}

::google::protobuf::uint8* UpdateChannelStateNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
  if (has_state_change()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->state_change(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 3;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 4;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.UpdateChannelStateNotification)
  return target;
}

int UpdateChannelStateNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // required .bgs.protocol.channel.v1.ChannelState state_change = 2;
    if (has_state_change()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state_change());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 3;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 4;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
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

void UpdateChannelStateNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateChannelStateNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateChannelStateNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateChannelStateNotification::MergeFrom(const UpdateChannelStateNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_state_change()) {
      mutable_state_change()->::bgs::protocol::channel::v1::ChannelState::MergeFrom(from.state_change());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateChannelStateNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateChannelStateNotification::CopyFrom(const UpdateChannelStateNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateChannelStateNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_state_change()) {
    if (!this->state_change().IsInitialized()) return false;
  }
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void UpdateChannelStateNotification::Swap(UpdateChannelStateNotification* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(state_change_, other->state_change_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateChannelStateNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateChannelStateNotification_descriptor_;
  metadata.reflection = UpdateChannelStateNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateMemberStateNotification::kAgentIdFieldNumber;
const int UpdateMemberStateNotification::kStateChangeFieldNumber;
const int UpdateMemberStateNotification::kChannelIdFieldNumber;
const int UpdateMemberStateNotification::kSubscriberFieldNumber;
#endif  // !_MSC_VER

UpdateMemberStateNotification::UpdateMemberStateNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.UpdateMemberStateNotification)
}

void UpdateMemberStateNotification::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  channel_id_ = const_cast< ::bgs::protocol::channel::v1::ChannelId*>(&::bgs::protocol::channel::v1::ChannelId::default_instance());
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

UpdateMemberStateNotification::UpdateMemberStateNotification(const UpdateMemberStateNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.UpdateMemberStateNotification)
}

void UpdateMemberStateNotification::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  channel_id_ = NULL;
  subscriber_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateMemberStateNotification::~UpdateMemberStateNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  SharedDtor();
}

void UpdateMemberStateNotification::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete channel_id_;
    delete subscriber_;
  }
}

void UpdateMemberStateNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateMemberStateNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateMemberStateNotification_descriptor_;
}

const UpdateMemberStateNotification& UpdateMemberStateNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5fservice_2eproto();
  return *default_instance_;
}

UpdateMemberStateNotification* UpdateMemberStateNotification::default_instance_ = NULL;

UpdateMemberStateNotification* UpdateMemberStateNotification::New() const {
  return new UpdateMemberStateNotification;
}

void UpdateMemberStateNotification::Clear() {
  if (_has_bits_[0 / 32] & 13) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::channel::v1::ChannelId::Clear();
    }
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  state_change_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateMemberStateNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.UpdateMemberStateNotification)
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
        if (input->ExpectTag(18)) goto parse_state_change;
        break;
      }

      // repeated .bgs.protocol.channel.v1.Member state_change = 2;
      case 2: {
        if (tag == 18) {
         parse_state_change:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_state_change()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_state_change;
        if (input->ExpectTag(34)) goto parse_channel_id;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
      case 4: {
        if (tag == 34) {
         parse_channel_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 5;
      case 5: {
        if (tag == 42) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  return false;
#undef DO_
}

void UpdateMemberStateNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  for (int i = 0; i < this->state_change_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->state_change(i), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->channel_id(), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->subscriber(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.UpdateMemberStateNotification)
}

::google::protobuf::uint8* UpdateMemberStateNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  for (int i = 0; i < this->state_change_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->state_change(i), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->channel_id(), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 5;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->subscriber(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.UpdateMemberStateNotification)
  return target;
}

int UpdateMemberStateNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional .bgs.protocol.channel.v1.ChannelId channel_id = 4;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional .bgs.protocol.account.v1.Identity subscriber = 5;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
    }

  }
  // repeated .bgs.protocol.channel.v1.Member state_change = 2;
  total_size += 1 * this->state_change_size();
  for (int i = 0; i < this->state_change_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->state_change(i));
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

void UpdateMemberStateNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateMemberStateNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateMemberStateNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateMemberStateNotification::MergeFrom(const UpdateMemberStateNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  state_change_.MergeFrom(from.state_change_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::channel::v1::ChannelId::MergeFrom(from.channel_id());
    }
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateMemberStateNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateMemberStateNotification::CopyFrom(const UpdateMemberStateNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateMemberStateNotification::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->state_change())) return false;
  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void UpdateMemberStateNotification::Swap(UpdateMemberStateNotification* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    state_change_.Swap(&other->state_change_);
    std::swap(channel_id_, other->channel_id_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateMemberStateNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateMemberStateNotification_descriptor_;
  metadata.reflection = UpdateMemberStateNotification_reflection_;
  return metadata;
}


// ===================================================================

ChannelService::ChannelService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ChannelService::~ChannelService() {
}

google::protobuf::ServiceDescriptor const* ChannelService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelService_descriptor_;
}

void ChannelService::RemoveMember(::bgs::protocol::channel::v1::RemoveMemberRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelService.RemoveMember(bgs.protocol.channel.v1.RemoveMemberRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void ChannelService::SendMessage(::bgs::protocol::channel::v1::SendMessageRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelService.SendMessage(bgs.protocol.channel.v1.SendMessageRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void ChannelService::UpdateChannelState(::bgs::protocol::channel::v1::UpdateChannelStateRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelService.UpdateChannelState(bgs.protocol.channel.v1.UpdateChannelStateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 4, request, std::move(callback));
}

void ChannelService::UpdateMemberState(::bgs::protocol::channel::v1::UpdateMemberStateRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelService.UpdateMemberState(bgs.protocol.channel.v1.UpdateMemberStateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 5, request, std::move(callback));
}

void ChannelService::Dissolve(::bgs::protocol::channel::v1::DissolveRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelService.Dissolve(bgs.protocol.channel.v1.DissolveRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void ChannelService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 2: {
      ::bgs::protocol::channel::v1::RemoveMemberRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelService.RemoveMember server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleRemoveMember(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelService.RemoveMember(bgs.protocol.channel.v1.RemoveMemberRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::channel::v1::SendMessageRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelService.SendMessage server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSendMessage(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelService.SendMessage(bgs.protocol.channel.v1.SendMessageRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::channel::v1::UpdateChannelStateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelService.UpdateChannelState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUpdateChannelState(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelService.UpdateChannelState(bgs.protocol.channel.v1.UpdateChannelStateRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 4, token, &response);
      else
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::channel::v1::UpdateMemberStateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelService.UpdateMemberState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUpdateMemberState(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelService.UpdateMemberState(bgs.protocol.channel.v1.UpdateMemberStateRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 5, token, &response);
      else
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::channel::v1::DissolveRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelService.Dissolve server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleDissolve(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelService.Dissolve(bgs.protocol.channel.v1.DissolveRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ChannelService::HandleRemoveMember(::bgs::protocol::channel::v1::RemoveMemberRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelService.RemoveMember({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelService::HandleSendMessage(::bgs::protocol::channel::v1::SendMessageRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelService.SendMessage({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelService::HandleUpdateChannelState(::bgs::protocol::channel::v1::UpdateChannelStateRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelService.UpdateChannelState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelService::HandleUpdateMemberState(::bgs::protocol::channel::v1::UpdateMemberStateRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelService.UpdateMemberState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelService::HandleDissolve(::bgs::protocol::channel::v1::DissolveRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelService.Dissolve({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

ChannelListener::ChannelListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ChannelListener::~ChannelListener() {
}

google::protobuf::ServiceDescriptor const* ChannelListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelListener_descriptor_;
}

void ChannelListener::OnJoin(::bgs::protocol::channel::v1::JoinNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnJoin(bgs.protocol.channel.v1.JoinNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void ChannelListener::OnMemberAdded(::bgs::protocol::channel::v1::MemberAddedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnMemberAdded(bgs.protocol.channel.v1.MemberAddedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 2, request);
}

void ChannelListener::OnLeave(::bgs::protocol::channel::v1::LeaveNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnLeave(bgs.protocol.channel.v1.LeaveNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 3, request);
}

void ChannelListener::OnMemberRemoved(::bgs::protocol::channel::v1::MemberRemovedNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnMemberRemoved(bgs.protocol.channel.v1.MemberRemovedNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void ChannelListener::OnSendMessage(::bgs::protocol::channel::v1::SendMessageNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnSendMessage(bgs.protocol.channel.v1.SendMessageNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 5, request);
}

void ChannelListener::OnUpdateChannelState(::bgs::protocol::channel::v1::UpdateChannelStateNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnUpdateChannelState(bgs.protocol.channel.v1.UpdateChannelStateNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 6, request);
}

void ChannelListener::OnUpdateMemberState(::bgs::protocol::channel::v1::UpdateMemberStateNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChannelListener.OnUpdateMemberState(bgs.protocol.channel.v1.UpdateMemberStateNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 7, request);
}

void ChannelListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::channel::v1::JoinNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnJoin server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnJoin(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnJoin(bgs.protocol.channel.v1.JoinNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::channel::v1::MemberAddedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnMemberAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnMemberAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnMemberAdded(bgs.protocol.channel.v1.MemberAddedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::channel::v1::LeaveNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnLeave server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnLeave(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnLeave(bgs.protocol.channel.v1.LeaveNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::channel::v1::MemberRemovedNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnMemberRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnMemberRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnMemberRemoved(bgs.protocol.channel.v1.MemberRemovedNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::channel::v1::SendMessageNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnSendMessage server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnSendMessage(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnSendMessage(bgs.protocol.channel.v1.SendMessageNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::channel::v1::UpdateChannelStateNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnUpdateChannelState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnUpdateChannelState(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnUpdateChannelState(bgs.protocol.channel.v1.UpdateChannelStateNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::channel::v1::UpdateMemberStateNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChannelListener.OnUpdateMemberState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnUpdateMemberState(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChannelListener.OnUpdateMemberState(bgs.protocol.channel.v1.UpdateMemberStateNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ChannelListener::HandleOnJoin(::bgs::protocol::channel::v1::JoinNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnJoin({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnMemberAdded(::bgs::protocol::channel::v1::MemberAddedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnMemberAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnLeave(::bgs::protocol::channel::v1::LeaveNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnLeave({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnMemberRemoved(::bgs::protocol::channel::v1::MemberRemovedNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnMemberRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnSendMessage(::bgs::protocol::channel::v1::SendMessageNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnSendMessage({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnUpdateChannelState(::bgs::protocol::channel::v1::UpdateChannelStateNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnUpdateChannelState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChannelListener::HandleOnUpdateMemberState(::bgs::protocol::channel::v1::UpdateMemberStateNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChannelListener.OnUpdateMemberState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
