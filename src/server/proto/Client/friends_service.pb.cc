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
#include "friends_service.pb.h"

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
namespace friends {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* SubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UnsubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UnsubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenericFriendRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenericFriendRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenericFriendResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenericFriendResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* AssignRoleRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AssignRoleRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ViewFriendsRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ViewFriendsRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ViewFriendsResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ViewFriendsResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateFriendStateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateFriendStateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetFriendListRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetFriendListRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetFriendListResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetFriendListResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* CreateFriendshipRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CreateFriendshipRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* FriendNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateFriendStateNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateFriendStateNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* InvitationNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InvitationNotification_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* FriendsService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* FriendsListener_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_friends_5fservice_2eproto() {
  protobuf_AddDesc_friends_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "friends_service.proto");
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
  UnsubscribeRequest_descriptor_ = file->message_type(1);
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
  GenericFriendRequest_descriptor_ = file->message_type(2);
  static const int GenericFriendRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendRequest, target_id_),
  };
  GenericFriendRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenericFriendRequest_descriptor_,
      GenericFriendRequest::default_instance_,
      GenericFriendRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenericFriendRequest));
  GenericFriendResponse_descriptor_ = file->message_type(3);
  static const int GenericFriendResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendResponse, target_friend_),
  };
  GenericFriendResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenericFriendResponse_descriptor_,
      GenericFriendResponse::default_instance_,
      GenericFriendResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericFriendResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenericFriendResponse));
  AssignRoleRequest_descriptor_ = file->message_type(4);
  static const int AssignRoleRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AssignRoleRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AssignRoleRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AssignRoleRequest, role_),
  };
  AssignRoleRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AssignRoleRequest_descriptor_,
      AssignRoleRequest::default_instance_,
      AssignRoleRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AssignRoleRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AssignRoleRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AssignRoleRequest));
  ViewFriendsRequest_descriptor_ = file->message_type(5);
  static const int ViewFriendsRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsRequest, role_),
  };
  ViewFriendsRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ViewFriendsRequest_descriptor_,
      ViewFriendsRequest::default_instance_,
      ViewFriendsRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ViewFriendsRequest));
  ViewFriendsResponse_descriptor_ = file->message_type(6);
  static const int ViewFriendsResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsResponse, friends_),
  };
  ViewFriendsResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ViewFriendsResponse_descriptor_,
      ViewFriendsResponse::default_instance_,
      ViewFriendsResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewFriendsResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ViewFriendsResponse));
  UpdateFriendStateRequest_descriptor_ = file->message_type(7);
  static const int UpdateFriendStateRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, attributes_epoch_),
  };
  UpdateFriendStateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateFriendStateRequest_descriptor_,
      UpdateFriendStateRequest::default_instance_,
      UpdateFriendStateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateFriendStateRequest));
  GetFriendListRequest_descriptor_ = file->message_type(8);
  static const int GetFriendListRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListRequest, target_id_),
  };
  GetFriendListRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetFriendListRequest_descriptor_,
      GetFriendListRequest::default_instance_,
      GetFriendListRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetFriendListRequest));
  GetFriendListResponse_descriptor_ = file->message_type(9);
  static const int GetFriendListResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListResponse, friends_),
  };
  GetFriendListResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetFriendListResponse_descriptor_,
      GetFriendListResponse::default_instance_,
      GetFriendListResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetFriendListResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetFriendListResponse));
  CreateFriendshipRequest_descriptor_ = file->message_type(10);
  static const int CreateFriendshipRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateFriendshipRequest, inviter_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateFriendshipRequest, invitee_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateFriendshipRequest, role_),
  };
  CreateFriendshipRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CreateFriendshipRequest_descriptor_,
      CreateFriendshipRequest::default_instance_,
      CreateFriendshipRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateFriendshipRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateFriendshipRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CreateFriendshipRequest));
  FriendNotification_descriptor_ = file->message_type(11);
  static const int FriendNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, peer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, account_id_),
  };
  FriendNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendNotification_descriptor_,
      FriendNotification::default_instance_,
      FriendNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendNotification));
  UpdateFriendStateNotification_descriptor_ = file->message_type(12);
  static const int UpdateFriendStateNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, changed_friend_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, peer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, account_id_),
  };
  UpdateFriendStateNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateFriendStateNotification_descriptor_,
      UpdateFriendStateNotification::default_instance_,
      UpdateFriendStateNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateFriendStateNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateFriendStateNotification));
  InvitationNotification_descriptor_ = file->message_type(13);
  static const int InvitationNotification_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, invitation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, reason_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, peer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, account_id_),
  };
  InvitationNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InvitationNotification_descriptor_,
      InvitationNotification::default_instance_,
      InvitationNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InvitationNotification));
  FriendsService_descriptor_ = file->service(0);
  FriendsListener_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_friends_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeRequest_descriptor_, &SubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UnsubscribeRequest_descriptor_, &UnsubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenericFriendRequest_descriptor_, &GenericFriendRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenericFriendResponse_descriptor_, &GenericFriendResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AssignRoleRequest_descriptor_, &AssignRoleRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ViewFriendsRequest_descriptor_, &ViewFriendsRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ViewFriendsResponse_descriptor_, &ViewFriendsResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateFriendStateRequest_descriptor_, &UpdateFriendStateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetFriendListRequest_descriptor_, &GetFriendListRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetFriendListResponse_descriptor_, &GetFriendListResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CreateFriendshipRequest_descriptor_, &CreateFriendshipRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendNotification_descriptor_, &FriendNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateFriendStateNotification_descriptor_, &UpdateFriendStateNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InvitationNotification_descriptor_, &InvitationNotification::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_friends_5fservice_2eproto() {
  delete SubscribeRequest::default_instance_;
  delete SubscribeRequest_reflection_;
  delete UnsubscribeRequest::default_instance_;
  delete UnsubscribeRequest_reflection_;
  delete GenericFriendRequest::default_instance_;
  delete GenericFriendRequest_reflection_;
  delete GenericFriendResponse::default_instance_;
  delete GenericFriendResponse_reflection_;
  delete AssignRoleRequest::default_instance_;
  delete AssignRoleRequest_reflection_;
  delete ViewFriendsRequest::default_instance_;
  delete ViewFriendsRequest_reflection_;
  delete ViewFriendsResponse::default_instance_;
  delete ViewFriendsResponse_reflection_;
  delete UpdateFriendStateRequest::default_instance_;
  delete UpdateFriendStateRequest_reflection_;
  delete GetFriendListRequest::default_instance_;
  delete GetFriendListRequest_reflection_;
  delete GetFriendListResponse::default_instance_;
  delete GetFriendListResponse_reflection_;
  delete CreateFriendshipRequest::default_instance_;
  delete CreateFriendshipRequest_reflection_;
  delete FriendNotification::default_instance_;
  delete FriendNotification_reflection_;
  delete UpdateFriendStateNotification::default_instance_;
  delete UpdateFriendStateNotification_reflection_;
  delete InvitationNotification::default_instance_;
  delete InvitationNotification_reflection_;
}

void protobuf_AddDesc_friends_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::friends::v1::protobuf_AddDesc_friends_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_invitation_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025friends_service.proto\022\027bgs.protocol.fr"
    "iends.v1\032\025attribute_types.proto\032\022entity_"
    "types.proto\032\023friends_types.proto\032\026invita"
    "tion_types.proto\032\017rpc_types.proto\"O\n\020Sub"
    "scribeRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.pr"
    "otocol.EntityId\022\021\n\tobject_id\030\002 \002(\004\"Q\n\022Un"
    "subscribeRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs"
    ".protocol.EntityId\022\021\n\tobject_id\030\002 \001(\004\"k\n"
    "\024GenericFriendRequest\022(\n\010agent_id\030\001 \001(\0132"
    "\026.bgs.protocol.EntityId\022)\n\ttarget_id\030\002 \002"
    "(\0132\026.bgs.protocol.EntityId\"O\n\025GenericFri"
    "endResponse\0226\n\rtarget_friend\030\001 \001(\0132\037.bgs"
    ".protocol.friends.v1.Friend\"v\n\021AssignRol"
    "eRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.protoco"
    "l.EntityId\022)\n\ttarget_id\030\002 \002(\0132\026.bgs.prot"
    "ocol.EntityId\022\014\n\004role\030\003 \003(\005\"{\n\022ViewFrien"
    "dsRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.protoc"
    "ol.EntityId\022)\n\ttarget_id\030\002 \002(\0132\026.bgs.pro"
    "tocol.EntityId\022\020\n\004role\030\003 \003(\rB\002\020\001\"O\n\023View"
    "FriendsResponse\0228\n\007friends\030\001 \003(\0132\'.bgs.p"
    "rotocol.friends.v1.FriendOfFriend\"\265\001\n\030Up"
    "dateFriendStateRequest\022(\n\010agent_id\030\001 \001(\013"
    "2\026.bgs.protocol.EntityId\022)\n\ttarget_id\030\002 "
    "\002(\0132\026.bgs.protocol.EntityId\022*\n\tattribute"
    "\030\003 \003(\0132\027.bgs.protocol.Attribute\022\030\n\020attri"
    "butes_epoch\030\004 \001(\004\"k\n\024GetFriendListReques"
    "t\022(\n\010agent_id\030\001 \001(\0132\026.bgs.protocol.Entit"
    "yId\022)\n\ttarget_id\030\002 \001(\0132\026.bgs.protocol.En"
    "tityId\"I\n\025GetFriendListResponse\0220\n\007frien"
    "ds\030\001 \003(\0132\037.bgs.protocol.friends.v1.Frien"
    "d\"\203\001\n\027CreateFriendshipRequest\022*\n\ninviter"
    "_id\030\001 \001(\0132\026.bgs.protocol.EntityId\022*\n\ninv"
    "itee_id\030\002 \001(\0132\026.bgs.protocol.EntityId\022\020\n"
    "\004role\030\003 \003(\rB\002\020\001\"\311\001\n\022FriendNotification\022/"
    "\n\006target\030\001 \002(\0132\037.bgs.protocol.friends.v1"
    ".Friend\022/\n\017game_account_id\030\002 \001(\0132\026.bgs.p"
    "rotocol.EntityId\022%\n\004peer\030\004 \001(\0132\027.bgs.pro"
    "tocol.ProcessId\022*\n\naccount_id\030\005 \001(\0132\026.bg"
    "s.protocol.EntityId\"\334\001\n\035UpdateFriendStat"
    "eNotification\0227\n\016changed_friend\030\001 \002(\0132\037."
    "bgs.protocol.friends.v1.Friend\022/\n\017game_a"
    "ccount_id\030\002 \001(\0132\026.bgs.protocol.EntityId\022"
    "%\n\004peer\030\004 \001(\0132\027.bgs.protocol.ProcessId\022*"
    "\n\naccount_id\030\005 \001(\0132\026.bgs.protocol.Entity"
    "Id\"\335\001\n\026InvitationNotification\022,\n\ninvitat"
    "ion\030\001 \002(\0132\030.bgs.protocol.Invitation\022/\n\017g"
    "ame_account_id\030\002 \001(\0132\026.bgs.protocol.Enti"
    "tyId\022\021\n\006reason\030\003 \001(\r:\0010\022%\n\004peer\030\004 \001(\0132\027."
    "bgs.protocol.ProcessId\022*\n\naccount_id\030\005 \001"
    "(\0132\026.bgs.protocol.EntityId2\214\013\n\016FriendsSe"
    "rvice\022h\n\tSubscribe\022).bgs.protocol.friend"
    "s.v1.SubscribeRequest\032*.bgs.protocol.fri"
    "ends.v1.SubscribeResponse\"\004\200\265\030\001\022Q\n\016SendI"
    "nvitation\022#.bgs.protocol.SendInvitationR"
    "equest\032\024.bgs.protocol.NoData\"\004\200\265\030\002\022V\n\020Ac"
    "ceptInvitation\022&.bgs.protocol.GenericInv"
    "itationRequest\032\024.bgs.protocol.NoData\"\004\200\265"
    "\030\003\022Y\n\020RevokeInvitation\022&.bgs.protocol.Ge"
    "nericInvitationRequest\032\024.bgs.protocol.No"
    "Data\"\007\210\002\001\200\265\030\004\022W\n\021DeclineInvitation\022&.bgs"
    ".protocol.GenericInvitationRequest\032\024.bgs"
    ".protocol.NoData\"\004\200\265\030\005\022V\n\020IgnoreInvitati"
    "on\022&.bgs.protocol.GenericInvitationReque"
    "st\032\024.bgs.protocol.NoData\"\004\200\265\030\006\022T\n\nAssign"
    "Role\022*.bgs.protocol.friends.v1.AssignRol"
    "eRequest\032\024.bgs.protocol.NoData\"\004\200\265\030\007\022s\n\014"
    "RemoveFriend\022-.bgs.protocol.friends.v1.G"
    "enericFriendRequest\032..bgs.protocol.frien"
    "ds.v1.GenericFriendResponse\"\004\200\265\030\010\022n\n\013Vie"
    "wFriends\022+.bgs.protocol.friends.v1.ViewF"
    "riendsRequest\032,.bgs.protocol.friends.v1."
    "ViewFriendsResponse\"\004\200\265\030\t\022b\n\021UpdateFrien"
    "dState\0221.bgs.protocol.friends.v1.UpdateF"
    "riendStateRequest\032\024.bgs.protocol.NoData\""
    "\004\200\265\030\n\022V\n\013Unsubscribe\022+.bgs.protocol.frie"
    "nds.v1.UnsubscribeRequest\032\024.bgs.protocol"
    ".NoData\"\004\200\265\030\013\022a\n\024RevokeAllInvitations\022-."
    "bgs.protocol.friends.v1.GenericFriendReq"
    "uest\032\024.bgs.protocol.NoData\"\004\200\265\030\014\022t\n\rGetF"
    "riendList\022-.bgs.protocol.friends.v1.GetF"
    "riendListRequest\032..bgs.protocol.friends."
    "v1.GetFriendListResponse\"\004\200\265\030\r\022`\n\020Create"
    "Friendship\0220.bgs.protocol.friends.v1.Cre"
    "ateFriendshipRequest\032\024.bgs.protocol.NoDa"
    "ta\"\004\200\265\030\016\032\'\312>$bnet.protocol.friends.Frien"
    "dsService2\247\006\n\017FriendsListener\022]\n\rOnFrien"
    "dAdded\022+.bgs.protocol.friends.v1.FriendN"
    "otification\032\031.bgs.protocol.NO_RESPONSE\"\004"
    "\200\265\030\001\022_\n\017OnFriendRemoved\022+.bgs.protocol.f"
    "riends.v1.FriendNotification\032\031.bgs.proto"
    "col.NO_RESPONSE\"\004\200\265\030\002\022m\n\031OnReceivedInvit"
    "ationAdded\022/.bgs.protocol.friends.v1.Inv"
    "itationNotification\032\031.bgs.protocol.NO_RE"
    "SPONSE\"\004\200\265\030\003\022o\n\033OnReceivedInvitationRemo"
    "ved\022/.bgs.protocol.friends.v1.Invitation"
    "Notification\032\031.bgs.protocol.NO_RESPONSE\""
    "\004\200\265\030\004\022l\n\025OnSentInvitationAdded\022/.bgs.pro"
    "tocol.friends.v1.InvitationNotification\032"
    "\031.bgs.protocol.NO_RESPONSE\"\007\210\002\001\200\265\030\005\022n\n\027O"
    "nSentInvitationRemoved\022/.bgs.protocol.fr"
    "iends.v1.InvitationNotification\032\031.bgs.pr"
    "otocol.NO_RESPONSE\"\007\210\002\001\200\265\030\006\022n\n\023OnUpdateF"
    "riendState\0226.bgs.protocol.friends.v1.Upd"
    "ateFriendStateNotification\032\031.bgs.protoco"
    "l.NO_RESPONSE\"\004\200\265\030\007\032&\312>#bnet.protocol.fr"
    "iends.FriendsNotifyB7\n\030bnet.protocol.fri"
    "ends.v1B\023FriendsServiceProtoH\001\200\001\000\210\001\001", 4276);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "friends_service.proto", &protobuf_RegisterTypes);
  SubscribeRequest::default_instance_ = new SubscribeRequest();
  UnsubscribeRequest::default_instance_ = new UnsubscribeRequest();
  GenericFriendRequest::default_instance_ = new GenericFriendRequest();
  GenericFriendResponse::default_instance_ = new GenericFriendResponse();
  AssignRoleRequest::default_instance_ = new AssignRoleRequest();
  ViewFriendsRequest::default_instance_ = new ViewFriendsRequest();
  ViewFriendsResponse::default_instance_ = new ViewFriendsResponse();
  UpdateFriendStateRequest::default_instance_ = new UpdateFriendStateRequest();
  GetFriendListRequest::default_instance_ = new GetFriendListRequest();
  GetFriendListResponse::default_instance_ = new GetFriendListResponse();
  CreateFriendshipRequest::default_instance_ = new CreateFriendshipRequest();
  FriendNotification::default_instance_ = new FriendNotification();
  UpdateFriendStateNotification::default_instance_ = new UpdateFriendStateNotification();
  InvitationNotification::default_instance_ = new InvitationNotification();
  SubscribeRequest::default_instance_->InitAsDefaultInstance();
  UnsubscribeRequest::default_instance_->InitAsDefaultInstance();
  GenericFriendRequest::default_instance_->InitAsDefaultInstance();
  GenericFriendResponse::default_instance_->InitAsDefaultInstance();
  AssignRoleRequest::default_instance_->InitAsDefaultInstance();
  ViewFriendsRequest::default_instance_->InitAsDefaultInstance();
  ViewFriendsResponse::default_instance_->InitAsDefaultInstance();
  UpdateFriendStateRequest::default_instance_->InitAsDefaultInstance();
  GetFriendListRequest::default_instance_->InitAsDefaultInstance();
  GetFriendListResponse::default_instance_->InitAsDefaultInstance();
  CreateFriendshipRequest::default_instance_->InitAsDefaultInstance();
  FriendNotification::default_instance_->InitAsDefaultInstance();
  UpdateFriendStateNotification::default_instance_->InitAsDefaultInstance();
  InvitationNotification::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_friends_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_friends_5fservice_2eproto {
  StaticDescriptorInitializer_friends_5fservice_2eproto() {
    protobuf_AddDesc_friends_5fservice_2eproto();
  }
} static_descriptor_initializer_friends_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SubscribeRequest::kAgentIdFieldNumber;
const int SubscribeRequest::kObjectIdFieldNumber;
#endif  // !_MSC_VER

SubscribeRequest::SubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.SubscribeRequest)
}

void SubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SubscribeRequest::SubscribeRequest(const SubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.SubscribeRequest)
}

void SubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeRequest::~SubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.SubscribeRequest)
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
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
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
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.SubscribeRequest)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.SubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.SubscribeRequest)
  return false;
#undef DO_
}

void SubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.SubscribeRequest)
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.SubscribeRequest)
}

::google::protobuf::uint8* SubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.SubscribeRequest)
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.SubscribeRequest)
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
const int UnsubscribeRequest::kAgentIdFieldNumber;
const int UnsubscribeRequest::kObjectIdFieldNumber;
#endif  // !_MSC_VER

UnsubscribeRequest::UnsubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UnsubscribeRequest::UnsubscribeRequest(const UnsubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UnsubscribeRequest::~UnsubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.UnsubscribeRequest)
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
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
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
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.UnsubscribeRequest)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.UnsubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.UnsubscribeRequest)
  return false;
#undef DO_
}

void UnsubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.UnsubscribeRequest)
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.UnsubscribeRequest)
}

::google::protobuf::uint8* UnsubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.UnsubscribeRequest)
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.UnsubscribeRequest)
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
const int GenericFriendRequest::kAgentIdFieldNumber;
const int GenericFriendRequest::kTargetIdFieldNumber;
#endif  // !_MSC_VER

GenericFriendRequest::GenericFriendRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.GenericFriendRequest)
}

void GenericFriendRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GenericFriendRequest::GenericFriendRequest(const GenericFriendRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.GenericFriendRequest)
}

void GenericFriendRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenericFriendRequest::~GenericFriendRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.GenericFriendRequest)
  SharedDtor();
}

void GenericFriendRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void GenericFriendRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenericFriendRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenericFriendRequest_descriptor_;
}

const GenericFriendRequest& GenericFriendRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

GenericFriendRequest* GenericFriendRequest::default_instance_ = NULL;

GenericFriendRequest* GenericFriendRequest::New() const {
  return new GenericFriendRequest;
}

void GenericFriendRequest::Clear() {
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

bool GenericFriendRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.GenericFriendRequest)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.GenericFriendRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.GenericFriendRequest)
  return false;
#undef DO_
}

void GenericFriendRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.GenericFriendRequest)
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.GenericFriendRequest)
}

::google::protobuf::uint8* GenericFriendRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.GenericFriendRequest)
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.GenericFriendRequest)
  return target;
}

int GenericFriendRequest::ByteSize() const {
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

void GenericFriendRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenericFriendRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenericFriendRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenericFriendRequest::MergeFrom(const GenericFriendRequest& from) {
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

void GenericFriendRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenericFriendRequest::CopyFrom(const GenericFriendRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenericFriendRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void GenericFriendRequest::Swap(GenericFriendRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenericFriendRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenericFriendRequest_descriptor_;
  metadata.reflection = GenericFriendRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenericFriendResponse::kTargetFriendFieldNumber;
#endif  // !_MSC_VER

GenericFriendResponse::GenericFriendResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.GenericFriendResponse)
}

void GenericFriendResponse::InitAsDefaultInstance() {
  target_friend_ = const_cast< ::bgs::protocol::friends::v1::Friend*>(&::bgs::protocol::friends::v1::Friend::default_instance());
}

GenericFriendResponse::GenericFriendResponse(const GenericFriendResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.GenericFriendResponse)
}

void GenericFriendResponse::SharedCtor() {
  _cached_size_ = 0;
  target_friend_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenericFriendResponse::~GenericFriendResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.GenericFriendResponse)
  SharedDtor();
}

void GenericFriendResponse::SharedDtor() {
  if (this != default_instance_) {
    delete target_friend_;
  }
}

void GenericFriendResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenericFriendResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenericFriendResponse_descriptor_;
}

const GenericFriendResponse& GenericFriendResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

GenericFriendResponse* GenericFriendResponse::default_instance_ = NULL;

GenericFriendResponse* GenericFriendResponse::New() const {
  return new GenericFriendResponse;
}

void GenericFriendResponse::Clear() {
  if (has_target_friend()) {
    if (target_friend_ != NULL) target_friend_->::bgs::protocol::friends::v1::Friend::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenericFriendResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.GenericFriendResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.friends.v1.Friend target_friend = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_friend()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.GenericFriendResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.GenericFriendResponse)
  return false;
#undef DO_
}

void GenericFriendResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.GenericFriendResponse)
  // optional .bgs.protocol.friends.v1.Friend target_friend = 1;
  if (has_target_friend()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target_friend(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.GenericFriendResponse)
}

::google::protobuf::uint8* GenericFriendResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.GenericFriendResponse)
  // optional .bgs.protocol.friends.v1.Friend target_friend = 1;
  if (has_target_friend()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target_friend(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.GenericFriendResponse)
  return target;
}

int GenericFriendResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.friends.v1.Friend target_friend = 1;
    if (has_target_friend()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_friend());
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

void GenericFriendResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenericFriendResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenericFriendResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenericFriendResponse::MergeFrom(const GenericFriendResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target_friend()) {
      mutable_target_friend()->::bgs::protocol::friends::v1::Friend::MergeFrom(from.target_friend());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenericFriendResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenericFriendResponse::CopyFrom(const GenericFriendResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenericFriendResponse::IsInitialized() const {

  if (has_target_friend()) {
    if (!this->target_friend().IsInitialized()) return false;
  }
  return true;
}

void GenericFriendResponse::Swap(GenericFriendResponse* other) {
  if (other != this) {
    std::swap(target_friend_, other->target_friend_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenericFriendResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenericFriendResponse_descriptor_;
  metadata.reflection = GenericFriendResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AssignRoleRequest::kAgentIdFieldNumber;
const int AssignRoleRequest::kTargetIdFieldNumber;
const int AssignRoleRequest::kRoleFieldNumber;
#endif  // !_MSC_VER

AssignRoleRequest::AssignRoleRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.AssignRoleRequest)
}

void AssignRoleRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

AssignRoleRequest::AssignRoleRequest(const AssignRoleRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.AssignRoleRequest)
}

void AssignRoleRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AssignRoleRequest::~AssignRoleRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.AssignRoleRequest)
  SharedDtor();
}

void AssignRoleRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void AssignRoleRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AssignRoleRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AssignRoleRequest_descriptor_;
}

const AssignRoleRequest& AssignRoleRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

AssignRoleRequest* AssignRoleRequest::default_instance_ = NULL;

AssignRoleRequest* AssignRoleRequest::New() const {
  return new AssignRoleRequest;
}

void AssignRoleRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AssignRoleRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.AssignRoleRequest)
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

      // repeated int32 role = 3;
      case 3: {
        if (tag == 24) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 24, input, this->mutable_role())));
        } else if (tag == 26) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_role;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.AssignRoleRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.AssignRoleRequest)
  return false;
#undef DO_
}

void AssignRoleRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.AssignRoleRequest)
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

  // repeated int32 role = 3;
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      3, this->role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.AssignRoleRequest)
}

::google::protobuf::uint8* AssignRoleRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.AssignRoleRequest)
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

  // repeated int32 role = 3;
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(3, this->role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.AssignRoleRequest)
  return target;
}

int AssignRoleRequest::ByteSize() const {
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
  // repeated int32 role = 3;
  {
    int data_size = 0;
    for (int i = 0; i < this->role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->role(i));
    }
    total_size += 1 * this->role_size() + data_size;
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

void AssignRoleRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AssignRoleRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AssignRoleRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AssignRoleRequest::MergeFrom(const AssignRoleRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  role_.MergeFrom(from.role_);
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

void AssignRoleRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AssignRoleRequest::CopyFrom(const AssignRoleRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AssignRoleRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void AssignRoleRequest::Swap(AssignRoleRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    role_.Swap(&other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AssignRoleRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AssignRoleRequest_descriptor_;
  metadata.reflection = AssignRoleRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ViewFriendsRequest::kAgentIdFieldNumber;
const int ViewFriendsRequest::kTargetIdFieldNumber;
const int ViewFriendsRequest::kRoleFieldNumber;
#endif  // !_MSC_VER

ViewFriendsRequest::ViewFriendsRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.ViewFriendsRequest)
}

void ViewFriendsRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

ViewFriendsRequest::ViewFriendsRequest(const ViewFriendsRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.ViewFriendsRequest)
}

void ViewFriendsRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  _role_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ViewFriendsRequest::~ViewFriendsRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.ViewFriendsRequest)
  SharedDtor();
}

void ViewFriendsRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void ViewFriendsRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ViewFriendsRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ViewFriendsRequest_descriptor_;
}

const ViewFriendsRequest& ViewFriendsRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

ViewFriendsRequest* ViewFriendsRequest::default_instance_ = NULL;

ViewFriendsRequest* ViewFriendsRequest::New() const {
  return new ViewFriendsRequest;
}

void ViewFriendsRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ViewFriendsRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.ViewFriendsRequest)
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
        if (input->ExpectTag(26)) goto parse_role;
        break;
      }

      // repeated uint32 role = 3 [packed = true];
      case 3: {
        if (tag == 26) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_role())));
        } else if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 26, input, this->mutable_role())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.ViewFriendsRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.ViewFriendsRequest)
  return false;
#undef DO_
}

void ViewFriendsRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.ViewFriendsRequest)
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

  // repeated uint32 role = 3 [packed = true];
  if (this->role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_role_cached_byte_size_);
  }
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.ViewFriendsRequest)
}

::google::protobuf::uint8* ViewFriendsRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.ViewFriendsRequest)
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

  // repeated uint32 role = 3 [packed = true];
  if (this->role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.ViewFriendsRequest)
  return target;
}

int ViewFriendsRequest::ByteSize() const {
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
  // repeated uint32 role = 3 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _role_cached_byte_size_ = data_size;
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

void ViewFriendsRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ViewFriendsRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ViewFriendsRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ViewFriendsRequest::MergeFrom(const ViewFriendsRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  role_.MergeFrom(from.role_);
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

void ViewFriendsRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ViewFriendsRequest::CopyFrom(const ViewFriendsRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ViewFriendsRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void ViewFriendsRequest::Swap(ViewFriendsRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    role_.Swap(&other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ViewFriendsRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ViewFriendsRequest_descriptor_;
  metadata.reflection = ViewFriendsRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ViewFriendsResponse::kFriendsFieldNumber;
#endif  // !_MSC_VER

ViewFriendsResponse::ViewFriendsResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.ViewFriendsResponse)
}

void ViewFriendsResponse::InitAsDefaultInstance() {
}

ViewFriendsResponse::ViewFriendsResponse(const ViewFriendsResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.ViewFriendsResponse)
}

void ViewFriendsResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ViewFriendsResponse::~ViewFriendsResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.ViewFriendsResponse)
  SharedDtor();
}

void ViewFriendsResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ViewFriendsResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ViewFriendsResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ViewFriendsResponse_descriptor_;
}

const ViewFriendsResponse& ViewFriendsResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

ViewFriendsResponse* ViewFriendsResponse::default_instance_ = NULL;

ViewFriendsResponse* ViewFriendsResponse::New() const {
  return new ViewFriendsResponse;
}

void ViewFriendsResponse::Clear() {
  friends_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ViewFriendsResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.ViewFriendsResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.friends.v1.FriendOfFriend friends = 1;
      case 1: {
        if (tag == 10) {
         parse_friends:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_friends()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_friends;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.ViewFriendsResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.ViewFriendsResponse)
  return false;
#undef DO_
}

void ViewFriendsResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.ViewFriendsResponse)
  // repeated .bgs.protocol.friends.v1.FriendOfFriend friends = 1;
  for (int i = 0; i < this->friends_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->friends(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.ViewFriendsResponse)
}

::google::protobuf::uint8* ViewFriendsResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.ViewFriendsResponse)
  // repeated .bgs.protocol.friends.v1.FriendOfFriend friends = 1;
  for (int i = 0; i < this->friends_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->friends(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.ViewFriendsResponse)
  return target;
}

int ViewFriendsResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.friends.v1.FriendOfFriend friends = 1;
  total_size += 1 * this->friends_size();
  for (int i = 0; i < this->friends_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->friends(i));
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

void ViewFriendsResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ViewFriendsResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ViewFriendsResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ViewFriendsResponse::MergeFrom(const ViewFriendsResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  friends_.MergeFrom(from.friends_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ViewFriendsResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ViewFriendsResponse::CopyFrom(const ViewFriendsResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ViewFriendsResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->friends())) return false;
  return true;
}

void ViewFriendsResponse::Swap(ViewFriendsResponse* other) {
  if (other != this) {
    friends_.Swap(&other->friends_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ViewFriendsResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ViewFriendsResponse_descriptor_;
  metadata.reflection = ViewFriendsResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateFriendStateRequest::kAgentIdFieldNumber;
const int UpdateFriendStateRequest::kTargetIdFieldNumber;
const int UpdateFriendStateRequest::kAttributeFieldNumber;
const int UpdateFriendStateRequest::kAttributesEpochFieldNumber;
#endif  // !_MSC_VER

UpdateFriendStateRequest::UpdateFriendStateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.UpdateFriendStateRequest)
}

void UpdateFriendStateRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UpdateFriendStateRequest::UpdateFriendStateRequest(const UpdateFriendStateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.UpdateFriendStateRequest)
}

void UpdateFriendStateRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  attributes_epoch_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateFriendStateRequest::~UpdateFriendStateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.UpdateFriendStateRequest)
  SharedDtor();
}

void UpdateFriendStateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void UpdateFriendStateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateFriendStateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateFriendStateRequest_descriptor_;
}

const UpdateFriendStateRequest& UpdateFriendStateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

UpdateFriendStateRequest* UpdateFriendStateRequest::default_instance_ = NULL;

UpdateFriendStateRequest* UpdateFriendStateRequest::New() const {
  return new UpdateFriendStateRequest;
}

void UpdateFriendStateRequest::Clear() {
  if (_has_bits_[0 / 32] & 11) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
    attributes_epoch_ = GOOGLE_ULONGLONG(0);
  }
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateFriendStateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.UpdateFriendStateRequest)
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
        if (input->ExpectTag(26)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 3;
      case 3: {
        if (tag == 26) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_attribute;
        if (input->ExpectTag(32)) goto parse_attributes_epoch;
        break;
      }

      // optional uint64 attributes_epoch = 4;
      case 4: {
        if (tag == 32) {
         parse_attributes_epoch:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &attributes_epoch_)));
          set_has_attributes_epoch();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.UpdateFriendStateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.UpdateFriendStateRequest)
  return false;
#undef DO_
}

void UpdateFriendStateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.UpdateFriendStateRequest)
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

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->attribute(i), output);
  }

  // optional uint64 attributes_epoch = 4;
  if (has_attributes_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->attributes_epoch(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.UpdateFriendStateRequest)
}

::google::protobuf::uint8* UpdateFriendStateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.UpdateFriendStateRequest)
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

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->attribute(i), target);
  }

  // optional uint64 attributes_epoch = 4;
  if (has_attributes_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->attributes_epoch(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.UpdateFriendStateRequest)
  return target;
}

int UpdateFriendStateRequest::ByteSize() const {
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

    // optional uint64 attributes_epoch = 4;
    if (has_attributes_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->attributes_epoch());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 3;
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

void UpdateFriendStateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateFriendStateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateFriendStateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateFriendStateRequest::MergeFrom(const UpdateFriendStateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_attributes_epoch()) {
      set_attributes_epoch(from.attributes_epoch());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateFriendStateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateFriendStateRequest::CopyFrom(const UpdateFriendStateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateFriendStateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void UpdateFriendStateRequest::Swap(UpdateFriendStateRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    attribute_.Swap(&other->attribute_);
    std::swap(attributes_epoch_, other->attributes_epoch_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateFriendStateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateFriendStateRequest_descriptor_;
  metadata.reflection = UpdateFriendStateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetFriendListRequest::kAgentIdFieldNumber;
const int GetFriendListRequest::kTargetIdFieldNumber;
#endif  // !_MSC_VER

GetFriendListRequest::GetFriendListRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.GetFriendListRequest)
}

void GetFriendListRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetFriendListRequest::GetFriendListRequest(const GetFriendListRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.GetFriendListRequest)
}

void GetFriendListRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetFriendListRequest::~GetFriendListRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.GetFriendListRequest)
  SharedDtor();
}

void GetFriendListRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void GetFriendListRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetFriendListRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetFriendListRequest_descriptor_;
}

const GetFriendListRequest& GetFriendListRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

GetFriendListRequest* GetFriendListRequest::default_instance_ = NULL;

GetFriendListRequest* GetFriendListRequest::New() const {
  return new GetFriendListRequest;
}

void GetFriendListRequest::Clear() {
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

bool GetFriendListRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.GetFriendListRequest)
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

      // optional .bgs.protocol.EntityId target_id = 2;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.GetFriendListRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.GetFriendListRequest)
  return false;
#undef DO_
}

void GetFriendListRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.GetFriendListRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // optional .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->target_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.GetFriendListRequest)
}

::google::protobuf::uint8* GetFriendListRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.GetFriendListRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // optional .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->target_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.GetFriendListRequest)
  return target;
}

int GetFriendListRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId agent_id = 1;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

    // optional .bgs.protocol.EntityId target_id = 2;
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

void GetFriendListRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetFriendListRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetFriendListRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetFriendListRequest::MergeFrom(const GetFriendListRequest& from) {
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

void GetFriendListRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetFriendListRequest::CopyFrom(const GetFriendListRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendListRequest::IsInitialized() const {

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void GetFriendListRequest::Swap(GetFriendListRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetFriendListRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetFriendListRequest_descriptor_;
  metadata.reflection = GetFriendListRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetFriendListResponse::kFriendsFieldNumber;
#endif  // !_MSC_VER

GetFriendListResponse::GetFriendListResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.GetFriendListResponse)
}

void GetFriendListResponse::InitAsDefaultInstance() {
}

GetFriendListResponse::GetFriendListResponse(const GetFriendListResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.GetFriendListResponse)
}

void GetFriendListResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetFriendListResponse::~GetFriendListResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.GetFriendListResponse)
  SharedDtor();
}

void GetFriendListResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetFriendListResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetFriendListResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetFriendListResponse_descriptor_;
}

const GetFriendListResponse& GetFriendListResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

GetFriendListResponse* GetFriendListResponse::default_instance_ = NULL;

GetFriendListResponse* GetFriendListResponse::New() const {
  return new GetFriendListResponse;
}

void GetFriendListResponse::Clear() {
  friends_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetFriendListResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.GetFriendListResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.friends.v1.Friend friends = 1;
      case 1: {
        if (tag == 10) {
         parse_friends:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_friends()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_friends;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.GetFriendListResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.GetFriendListResponse)
  return false;
#undef DO_
}

void GetFriendListResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.GetFriendListResponse)
  // repeated .bgs.protocol.friends.v1.Friend friends = 1;
  for (int i = 0; i < this->friends_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->friends(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.GetFriendListResponse)
}

::google::protobuf::uint8* GetFriendListResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.GetFriendListResponse)
  // repeated .bgs.protocol.friends.v1.Friend friends = 1;
  for (int i = 0; i < this->friends_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->friends(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.GetFriendListResponse)
  return target;
}

int GetFriendListResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.friends.v1.Friend friends = 1;
  total_size += 1 * this->friends_size();
  for (int i = 0; i < this->friends_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->friends(i));
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

void GetFriendListResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetFriendListResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetFriendListResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetFriendListResponse::MergeFrom(const GetFriendListResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  friends_.MergeFrom(from.friends_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetFriendListResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetFriendListResponse::CopyFrom(const GetFriendListResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendListResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->friends())) return false;
  return true;
}

void GetFriendListResponse::Swap(GetFriendListResponse* other) {
  if (other != this) {
    friends_.Swap(&other->friends_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetFriendListResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetFriendListResponse_descriptor_;
  metadata.reflection = GetFriendListResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CreateFriendshipRequest::kInviterIdFieldNumber;
const int CreateFriendshipRequest::kInviteeIdFieldNumber;
const int CreateFriendshipRequest::kRoleFieldNumber;
#endif  // !_MSC_VER

CreateFriendshipRequest::CreateFriendshipRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.CreateFriendshipRequest)
}

void CreateFriendshipRequest::InitAsDefaultInstance() {
  inviter_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  invitee_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

CreateFriendshipRequest::CreateFriendshipRequest(const CreateFriendshipRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.CreateFriendshipRequest)
}

void CreateFriendshipRequest::SharedCtor() {
  _cached_size_ = 0;
  inviter_id_ = NULL;
  invitee_id_ = NULL;
  _role_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CreateFriendshipRequest::~CreateFriendshipRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.CreateFriendshipRequest)
  SharedDtor();
}

void CreateFriendshipRequest::SharedDtor() {
  if (this != default_instance_) {
    delete inviter_id_;
    delete invitee_id_;
  }
}

void CreateFriendshipRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreateFriendshipRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CreateFriendshipRequest_descriptor_;
}

const CreateFriendshipRequest& CreateFriendshipRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

CreateFriendshipRequest* CreateFriendshipRequest::default_instance_ = NULL;

CreateFriendshipRequest* CreateFriendshipRequest::New() const {
  return new CreateFriendshipRequest;
}

void CreateFriendshipRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_inviter_id()) {
      if (inviter_id_ != NULL) inviter_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_invitee_id()) {
      if (invitee_id_ != NULL) invitee_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CreateFriendshipRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.CreateFriendshipRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId inviter_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_inviter_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_invitee_id;
        break;
      }

      // optional .bgs.protocol.EntityId invitee_id = 2;
      case 2: {
        if (tag == 18) {
         parse_invitee_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_invitee_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_role;
        break;
      }

      // repeated uint32 role = 3 [packed = true];
      case 3: {
        if (tag == 26) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_role())));
        } else if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 26, input, this->mutable_role())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.CreateFriendshipRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.CreateFriendshipRequest)
  return false;
#undef DO_
}

void CreateFriendshipRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.CreateFriendshipRequest)
  // optional .bgs.protocol.EntityId inviter_id = 1;
  if (has_inviter_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->inviter_id(), output);
  }

  // optional .bgs.protocol.EntityId invitee_id = 2;
  if (has_invitee_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->invitee_id(), output);
  }

  // repeated uint32 role = 3 [packed = true];
  if (this->role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_role_cached_byte_size_);
  }
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.CreateFriendshipRequest)
}

::google::protobuf::uint8* CreateFriendshipRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.CreateFriendshipRequest)
  // optional .bgs.protocol.EntityId inviter_id = 1;
  if (has_inviter_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->inviter_id(), target);
  }

  // optional .bgs.protocol.EntityId invitee_id = 2;
  if (has_invitee_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->invitee_id(), target);
  }

  // repeated uint32 role = 3 [packed = true];
  if (this->role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.CreateFriendshipRequest)
  return target;
}

int CreateFriendshipRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId inviter_id = 1;
    if (has_inviter_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->inviter_id());
    }

    // optional .bgs.protocol.EntityId invitee_id = 2;
    if (has_invitee_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->invitee_id());
    }

  }
  // repeated uint32 role = 3 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _role_cached_byte_size_ = data_size;
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

void CreateFriendshipRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CreateFriendshipRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CreateFriendshipRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CreateFriendshipRequest::MergeFrom(const CreateFriendshipRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  role_.MergeFrom(from.role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_inviter_id()) {
      mutable_inviter_id()->::bgs::protocol::EntityId::MergeFrom(from.inviter_id());
    }
    if (from.has_invitee_id()) {
      mutable_invitee_id()->::bgs::protocol::EntityId::MergeFrom(from.invitee_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CreateFriendshipRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreateFriendshipRequest::CopyFrom(const CreateFriendshipRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateFriendshipRequest::IsInitialized() const {

  if (has_inviter_id()) {
    if (!this->inviter_id().IsInitialized()) return false;
  }
  if (has_invitee_id()) {
    if (!this->invitee_id().IsInitialized()) return false;
  }
  return true;
}

void CreateFriendshipRequest::Swap(CreateFriendshipRequest* other) {
  if (other != this) {
    std::swap(inviter_id_, other->inviter_id_);
    std::swap(invitee_id_, other->invitee_id_);
    role_.Swap(&other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CreateFriendshipRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CreateFriendshipRequest_descriptor_;
  metadata.reflection = CreateFriendshipRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FriendNotification::kTargetFieldNumber;
const int FriendNotification::kGameAccountIdFieldNumber;
const int FriendNotification::kPeerFieldNumber;
const int FriendNotification::kAccountIdFieldNumber;
#endif  // !_MSC_VER

FriendNotification::FriendNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.FriendNotification)
}

void FriendNotification::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::friends::v1::Friend*>(&::bgs::protocol::friends::v1::Friend::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  peer_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

FriendNotification::FriendNotification(const FriendNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.FriendNotification)
}

void FriendNotification::SharedCtor() {
  _cached_size_ = 0;
  target_ = NULL;
  game_account_id_ = NULL;
  peer_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendNotification::~FriendNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.FriendNotification)
  SharedDtor();
}

void FriendNotification::SharedDtor() {
  if (this != default_instance_) {
    delete target_;
    delete game_account_id_;
    delete peer_;
    delete account_id_;
  }
}

void FriendNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendNotification_descriptor_;
}

const FriendNotification& FriendNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

FriendNotification* FriendNotification::default_instance_ = NULL;

FriendNotification* FriendNotification::New() const {
  return new FriendNotification;
}

void FriendNotification::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::friends::v1::Friend::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_peer()) {
      if (peer_ != NULL) peer_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.FriendNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.friends.v1.Friend target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
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
        if (input->ExpectTag(34)) goto parse_peer;
        break;
      }

      // optional .bgs.protocol.ProcessId peer = 4;
      case 4: {
        if (tag == 34) {
         parse_peer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 5;
      case 5: {
        if (tag == 42) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.FriendNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.FriendNotification)
  return false;
#undef DO_
}

void FriendNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.FriendNotification)
  // required .bgs.protocol.friends.v1.Friend target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->peer(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.FriendNotification)
}

::google::protobuf::uint8* FriendNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.FriendNotification)
  // required .bgs.protocol.friends.v1.Friend target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->peer(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.FriendNotification)
  return target;
}

int FriendNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.friends.v1.Friend target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.ProcessId peer = 4;
    if (has_peer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peer());
    }

    // optional .bgs.protocol.EntityId account_id = 5;
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

void FriendNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendNotification::MergeFrom(const FriendNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::friends::v1::Friend::MergeFrom(from.target());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_peer()) {
      mutable_peer()->::bgs::protocol::ProcessId::MergeFrom(from.peer());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendNotification::CopyFrom(const FriendNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_peer()) {
    if (!this->peer().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void FriendNotification::Swap(FriendNotification* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(peer_, other->peer_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendNotification_descriptor_;
  metadata.reflection = FriendNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateFriendStateNotification::kChangedFriendFieldNumber;
const int UpdateFriendStateNotification::kGameAccountIdFieldNumber;
const int UpdateFriendStateNotification::kPeerFieldNumber;
const int UpdateFriendStateNotification::kAccountIdFieldNumber;
#endif  // !_MSC_VER

UpdateFriendStateNotification::UpdateFriendStateNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.UpdateFriendStateNotification)
}

void UpdateFriendStateNotification::InitAsDefaultInstance() {
  changed_friend_ = const_cast< ::bgs::protocol::friends::v1::Friend*>(&::bgs::protocol::friends::v1::Friend::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  peer_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UpdateFriendStateNotification::UpdateFriendStateNotification(const UpdateFriendStateNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.UpdateFriendStateNotification)
}

void UpdateFriendStateNotification::SharedCtor() {
  _cached_size_ = 0;
  changed_friend_ = NULL;
  game_account_id_ = NULL;
  peer_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateFriendStateNotification::~UpdateFriendStateNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  SharedDtor();
}

void UpdateFriendStateNotification::SharedDtor() {
  if (this != default_instance_) {
    delete changed_friend_;
    delete game_account_id_;
    delete peer_;
    delete account_id_;
  }
}

void UpdateFriendStateNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateFriendStateNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateFriendStateNotification_descriptor_;
}

const UpdateFriendStateNotification& UpdateFriendStateNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

UpdateFriendStateNotification* UpdateFriendStateNotification::default_instance_ = NULL;

UpdateFriendStateNotification* UpdateFriendStateNotification::New() const {
  return new UpdateFriendStateNotification;
}

void UpdateFriendStateNotification::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_changed_friend()) {
      if (changed_friend_ != NULL) changed_friend_->::bgs::protocol::friends::v1::Friend::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_peer()) {
      if (peer_ != NULL) peer_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateFriendStateNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.friends.v1.Friend changed_friend = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_changed_friend()));
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
        if (input->ExpectTag(34)) goto parse_peer;
        break;
      }

      // optional .bgs.protocol.ProcessId peer = 4;
      case 4: {
        if (tag == 34) {
         parse_peer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 5;
      case 5: {
        if (tag == 42) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  return false;
#undef DO_
}

void UpdateFriendStateNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  // required .bgs.protocol.friends.v1.Friend changed_friend = 1;
  if (has_changed_friend()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->changed_friend(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->peer(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.UpdateFriendStateNotification)
}

::google::protobuf::uint8* UpdateFriendStateNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  // required .bgs.protocol.friends.v1.Friend changed_friend = 1;
  if (has_changed_friend()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->changed_friend(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->peer(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.UpdateFriendStateNotification)
  return target;
}

int UpdateFriendStateNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.friends.v1.Friend changed_friend = 1;
    if (has_changed_friend()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->changed_friend());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.ProcessId peer = 4;
    if (has_peer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peer());
    }

    // optional .bgs.protocol.EntityId account_id = 5;
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

void UpdateFriendStateNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateFriendStateNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateFriendStateNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateFriendStateNotification::MergeFrom(const UpdateFriendStateNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_changed_friend()) {
      mutable_changed_friend()->::bgs::protocol::friends::v1::Friend::MergeFrom(from.changed_friend());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_peer()) {
      mutable_peer()->::bgs::protocol::ProcessId::MergeFrom(from.peer());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateFriendStateNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateFriendStateNotification::CopyFrom(const UpdateFriendStateNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateFriendStateNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_changed_friend()) {
    if (!this->changed_friend().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_peer()) {
    if (!this->peer().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void UpdateFriendStateNotification::Swap(UpdateFriendStateNotification* other) {
  if (other != this) {
    std::swap(changed_friend_, other->changed_friend_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(peer_, other->peer_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateFriendStateNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateFriendStateNotification_descriptor_;
  metadata.reflection = UpdateFriendStateNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InvitationNotification::kInvitationFieldNumber;
const int InvitationNotification::kGameAccountIdFieldNumber;
const int InvitationNotification::kReasonFieldNumber;
const int InvitationNotification::kPeerFieldNumber;
const int InvitationNotification::kAccountIdFieldNumber;
#endif  // !_MSC_VER

InvitationNotification::InvitationNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.InvitationNotification)
}

void InvitationNotification::InitAsDefaultInstance() {
  invitation_ = const_cast< ::bgs::protocol::Invitation*>(&::bgs::protocol::Invitation::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  peer_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

InvitationNotification::InvitationNotification(const InvitationNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.InvitationNotification)
}

void InvitationNotification::SharedCtor() {
  _cached_size_ = 0;
  invitation_ = NULL;
  game_account_id_ = NULL;
  reason_ = 0u;
  peer_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InvitationNotification::~InvitationNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.InvitationNotification)
  SharedDtor();
}

void InvitationNotification::SharedDtor() {
  if (this != default_instance_) {
    delete invitation_;
    delete game_account_id_;
    delete peer_;
    delete account_id_;
  }
}

void InvitationNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InvitationNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InvitationNotification_descriptor_;
}

const InvitationNotification& InvitationNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5fservice_2eproto();
  return *default_instance_;
}

InvitationNotification* InvitationNotification::default_instance_ = NULL;

InvitationNotification* InvitationNotification::New() const {
  return new InvitationNotification;
}

void InvitationNotification::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_invitation()) {
      if (invitation_ != NULL) invitation_->::bgs::protocol::Invitation::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    reason_ = 0u;
    if (has_peer()) {
      if (peer_ != NULL) peer_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InvitationNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.InvitationNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.Invitation invitation = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_invitation()));
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
        if (input->ExpectTag(24)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 3 [default = 0];
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
        if (input->ExpectTag(34)) goto parse_peer;
        break;
      }

      // optional .bgs.protocol.ProcessId peer = 4;
      case 4: {
        if (tag == 34) {
         parse_peer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 5;
      case 5: {
        if (tag == 42) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.InvitationNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.InvitationNotification)
  return false;
#undef DO_
}

void InvitationNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.InvitationNotification)
  // required .bgs.protocol.Invitation invitation = 1;
  if (has_invitation()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->invitation(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional uint32 reason = 3 [default = 0];
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->reason(), output);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->peer(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.InvitationNotification)
}

::google::protobuf::uint8* InvitationNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.InvitationNotification)
  // required .bgs.protocol.Invitation invitation = 1;
  if (has_invitation()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->invitation(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional uint32 reason = 3 [default = 0];
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->reason(), target);
  }

  // optional .bgs.protocol.ProcessId peer = 4;
  if (has_peer()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->peer(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 5;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.InvitationNotification)
  return target;
}

int InvitationNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.Invitation invitation = 1;
    if (has_invitation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->invitation());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional uint32 reason = 3 [default = 0];
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
    }

    // optional .bgs.protocol.ProcessId peer = 4;
    if (has_peer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peer());
    }

    // optional .bgs.protocol.EntityId account_id = 5;
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

void InvitationNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InvitationNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InvitationNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InvitationNotification::MergeFrom(const InvitationNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_invitation()) {
      mutable_invitation()->::bgs::protocol::Invitation::MergeFrom(from.invitation());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
    if (from.has_peer()) {
      mutable_peer()->::bgs::protocol::ProcessId::MergeFrom(from.peer());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InvitationNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InvitationNotification::CopyFrom(const InvitationNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InvitationNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_invitation()) {
    if (!this->invitation().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_peer()) {
    if (!this->peer().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void InvitationNotification::Swap(InvitationNotification* other) {
  if (other != this) {
    std::swap(invitation_, other->invitation_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(reason_, other->reason_);
    std::swap(peer_, other->peer_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata InvitationNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InvitationNotification_descriptor_;
  metadata.reflection = InvitationNotification_reflection_;
  return metadata;
}


// ===================================================================

FriendsService::FriendsService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

FriendsService::~FriendsService() {
}

google::protobuf::ServiceDescriptor const* FriendsService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendsService_descriptor_;
}

void FriendsService::Subscribe(::bgs::protocol::friends::v1::SubscribeRequest const* request, std::function<void(::bgs::protocol::friends::v1::SubscribeResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.Subscribe(bgs.protocol.friends.v1.SubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::friends::v1::SubscribeResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void FriendsService::SendInvitation(::bgs::protocol::SendInvitationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.SendInvitation(bgs.protocol.SendInvitationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void FriendsService::AcceptInvitation(::bgs::protocol::GenericInvitationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.AcceptInvitation(bgs.protocol.GenericInvitationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void FriendsService::RevokeInvitation(::bgs::protocol::GenericInvitationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.RevokeInvitation(bgs.protocol.GenericInvitationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 4, request, std::move(callback));
}

void FriendsService::DeclineInvitation(::bgs::protocol::GenericInvitationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.DeclineInvitation(bgs.protocol.GenericInvitationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 5, request, std::move(callback));
}

void FriendsService::IgnoreInvitation(::bgs::protocol::GenericInvitationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.IgnoreInvitation(bgs.protocol.GenericInvitationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void FriendsService::AssignRole(::bgs::protocol::friends::v1::AssignRoleRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.AssignRole(bgs.protocol.friends.v1.AssignRoleRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 7, request, std::move(callback));
}

void FriendsService::RemoveFriend(::bgs::protocol::friends::v1::GenericFriendRequest const* request, std::function<void(::bgs::protocol::friends::v1::GenericFriendResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.RemoveFriend(bgs.protocol.friends.v1.GenericFriendRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::friends::v1::GenericFriendResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 8, request, std::move(callback));
}

void FriendsService::ViewFriends(::bgs::protocol::friends::v1::ViewFriendsRequest const* request, std::function<void(::bgs::protocol::friends::v1::ViewFriendsResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.ViewFriends(bgs.protocol.friends.v1.ViewFriendsRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::friends::v1::ViewFriendsResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 9, request, std::move(callback));
}

void FriendsService::UpdateFriendState(::bgs::protocol::friends::v1::UpdateFriendStateRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.UpdateFriendState(bgs.protocol.friends.v1.UpdateFriendStateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 10, request, std::move(callback));
}

void FriendsService::Unsubscribe(::bgs::protocol::friends::v1::UnsubscribeRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.Unsubscribe(bgs.protocol.friends.v1.UnsubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 11, request, std::move(callback));
}

void FriendsService::RevokeAllInvitations(::bgs::protocol::friends::v1::GenericFriendRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.RevokeAllInvitations(bgs.protocol.friends.v1.GenericFriendRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 12, request, std::move(callback));
}

void FriendsService::GetFriendList(::bgs::protocol::friends::v1::GetFriendListRequest const* request, std::function<void(::bgs::protocol::friends::v1::GetFriendListResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.GetFriendList(bgs.protocol.friends.v1.GetFriendListRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::friends::v1::GetFriendListResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 13, request, std::move(callback));
}

void FriendsService::CreateFriendship(::bgs::protocol::friends::v1::CreateFriendshipRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsService.CreateFriendship(bgs.protocol.friends.v1.CreateFriendshipRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 14, request, std::move(callback));
}

void FriendsService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::friends::v1::SubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.Subscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::friends::v1::SubscribeResponse response;
      uint32 status = HandleSubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.Subscribe(bgs.protocol.friends.v1.SubscribeRequest{ %s }) returned bgs.protocol.friends.v1.SubscribeResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::SendInvitationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.SendInvitation server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSendInvitation(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.SendInvitation(bgs.protocol.SendInvitationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::GenericInvitationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.AcceptInvitation server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleAcceptInvitation(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.AcceptInvitation(bgs.protocol.GenericInvitationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::GenericInvitationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.RevokeInvitation server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleRevokeInvitation(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.RevokeInvitation(bgs.protocol.GenericInvitationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 4, token, &response);
      else
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::GenericInvitationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.DeclineInvitation server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleDeclineInvitation(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.DeclineInvitation(bgs.protocol.GenericInvitationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 5, token, &response);
      else
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::GenericInvitationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.IgnoreInvitation server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleIgnoreInvitation(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.IgnoreInvitation(bgs.protocol.GenericInvitationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::friends::v1::AssignRoleRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.AssignRole server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleAssignRole(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.AssignRole(bgs.protocol.friends.v1.AssignRoleRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 7, token, &response);
      else
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    case 8: {
      ::bgs::protocol::friends::v1::GenericFriendRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.RemoveFriend server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 8, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::friends::v1::GenericFriendResponse response;
      uint32 status = HandleRemoveFriend(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.RemoveFriend(bgs.protocol.friends.v1.GenericFriendRequest{ %s }) returned bgs.protocol.friends.v1.GenericFriendResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 8, token, &response);
      else
        SendResponse(service_hash_, 8, token, status);
      break;
    }
    case 9: {
      ::bgs::protocol::friends::v1::ViewFriendsRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.ViewFriends server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 9, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::friends::v1::ViewFriendsResponse response;
      uint32 status = HandleViewFriends(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.ViewFriends(bgs.protocol.friends.v1.ViewFriendsRequest{ %s }) returned bgs.protocol.friends.v1.ViewFriendsResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 9, token, &response);
      else
        SendResponse(service_hash_, 9, token, status);
      break;
    }
    case 10: {
      ::bgs::protocol::friends::v1::UpdateFriendStateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.UpdateFriendState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 10, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUpdateFriendState(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.UpdateFriendState(bgs.protocol.friends.v1.UpdateFriendStateRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 10, token, &response);
      else
        SendResponse(service_hash_, 10, token, status);
      break;
    }
    case 11: {
      ::bgs::protocol::friends::v1::UnsubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.Unsubscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 11, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUnsubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.Unsubscribe(bgs.protocol.friends.v1.UnsubscribeRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 11, token, &response);
      else
        SendResponse(service_hash_, 11, token, status);
      break;
    }
    case 12: {
      ::bgs::protocol::friends::v1::GenericFriendRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.RevokeAllInvitations server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 12, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleRevokeAllInvitations(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.RevokeAllInvitations(bgs.protocol.friends.v1.GenericFriendRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 12, token, &response);
      else
        SendResponse(service_hash_, 12, token, status);
      break;
    }
    case 13: {
      ::bgs::protocol::friends::v1::GetFriendListRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.GetFriendList server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 13, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::friends::v1::GetFriendListResponse response;
      uint32 status = HandleGetFriendList(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.GetFriendList(bgs.protocol.friends.v1.GetFriendListRequest{ %s }) returned bgs.protocol.friends.v1.GetFriendListResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 13, token, &response);
      else
        SendResponse(service_hash_, 13, token, status);
      break;
    }
    case 14: {
      ::bgs::protocol::friends::v1::CreateFriendshipRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsService.CreateFriendship server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 14, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleCreateFriendship(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsService.CreateFriendship(bgs.protocol.friends.v1.CreateFriendshipRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 14, token, &response);
      else
        SendResponse(service_hash_, 14, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 FriendsService::HandleSubscribe(::bgs::protocol::friends::v1::SubscribeRequest const* request, ::bgs::protocol::friends::v1::SubscribeResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.Subscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleSendInvitation(::bgs::protocol::SendInvitationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.SendInvitation({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleAcceptInvitation(::bgs::protocol::GenericInvitationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.AcceptInvitation({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleRevokeInvitation(::bgs::protocol::GenericInvitationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.RevokeInvitation({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleDeclineInvitation(::bgs::protocol::GenericInvitationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.DeclineInvitation({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleIgnoreInvitation(::bgs::protocol::GenericInvitationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.IgnoreInvitation({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleAssignRole(::bgs::protocol::friends::v1::AssignRoleRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.AssignRole({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleRemoveFriend(::bgs::protocol::friends::v1::GenericFriendRequest const* request, ::bgs::protocol::friends::v1::GenericFriendResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.RemoveFriend({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleViewFriends(::bgs::protocol::friends::v1::ViewFriendsRequest const* request, ::bgs::protocol::friends::v1::ViewFriendsResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.ViewFriends({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleUpdateFriendState(::bgs::protocol::friends::v1::UpdateFriendStateRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.UpdateFriendState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleUnsubscribe(::bgs::protocol::friends::v1::UnsubscribeRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.Unsubscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleRevokeAllInvitations(::bgs::protocol::friends::v1::GenericFriendRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.RevokeAllInvitations({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleGetFriendList(::bgs::protocol::friends::v1::GetFriendListRequest const* request, ::bgs::protocol::friends::v1::GetFriendListResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.GetFriendList({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsService::HandleCreateFriendship(::bgs::protocol::friends::v1::CreateFriendshipRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsService.CreateFriendship({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

FriendsListener::FriendsListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

FriendsListener::~FriendsListener() {
}

google::protobuf::ServiceDescriptor const* FriendsListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendsListener_descriptor_;
}

void FriendsListener::OnFriendAdded(::bgs::protocol::friends::v1::FriendNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnFriendAdded(bgs.protocol.friends.v1.FriendNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void FriendsListener::OnFriendRemoved(::bgs::protocol::friends::v1::FriendNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnFriendRemoved(bgs.protocol.friends.v1.FriendNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 2, request);
}

void FriendsListener::OnReceivedInvitationAdded(::bgs::protocol::friends::v1::InvitationNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnReceivedInvitationAdded(bgs.protocol.friends.v1.InvitationNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 3, request);
}

void FriendsListener::OnReceivedInvitationRemoved(::bgs::protocol::friends::v1::InvitationNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnReceivedInvitationRemoved(bgs.protocol.friends.v1.InvitationNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void FriendsListener::OnSentInvitationAdded(::bgs::protocol::friends::v1::InvitationNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnSentInvitationAdded(bgs.protocol.friends.v1.InvitationNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 5, request);
}

void FriendsListener::OnSentInvitationRemoved(::bgs::protocol::friends::v1::InvitationNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnSentInvitationRemoved(bgs.protocol.friends.v1.InvitationNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 6, request);
}

void FriendsListener::OnUpdateFriendState(::bgs::protocol::friends::v1::UpdateFriendStateNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method FriendsListener.OnUpdateFriendState(bgs.protocol.friends.v1.UpdateFriendStateNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 7, request);
}

void FriendsListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::friends::v1::FriendNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnFriendAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnFriendAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnFriendAdded(bgs.protocol.friends.v1.FriendNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::friends::v1::FriendNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnFriendRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnFriendRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnFriendRemoved(bgs.protocol.friends.v1.FriendNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::friends::v1::InvitationNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnReceivedInvitationAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnReceivedInvitationAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnReceivedInvitationAdded(bgs.protocol.friends.v1.InvitationNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::friends::v1::InvitationNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnReceivedInvitationRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnReceivedInvitationRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnReceivedInvitationRemoved(bgs.protocol.friends.v1.InvitationNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::friends::v1::InvitationNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnSentInvitationAdded server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnSentInvitationAdded(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnSentInvitationAdded(bgs.protocol.friends.v1.InvitationNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::friends::v1::InvitationNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnSentInvitationRemoved server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnSentInvitationRemoved(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnSentInvitationRemoved(bgs.protocol.friends.v1.InvitationNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::friends::v1::UpdateFriendStateNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for FriendsListener.OnUpdateFriendState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnUpdateFriendState(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method FriendsListener.OnUpdateFriendState(bgs.protocol.friends.v1.UpdateFriendStateNotification{ %s }) status %u.",
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

uint32 FriendsListener::HandleOnFriendAdded(::bgs::protocol::friends::v1::FriendNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnFriendAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnFriendRemoved(::bgs::protocol::friends::v1::FriendNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnFriendRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnReceivedInvitationAdded(::bgs::protocol::friends::v1::InvitationNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnReceivedInvitationAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnReceivedInvitationRemoved(::bgs::protocol::friends::v1::InvitationNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnReceivedInvitationRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnSentInvitationAdded(::bgs::protocol::friends::v1::InvitationNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnSentInvitationAdded({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnSentInvitationRemoved(::bgs::protocol::friends::v1::InvitationNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnSentInvitationRemoved({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 FriendsListener::HandleOnUpdateFriendState(::bgs::protocol::friends::v1::UpdateFriendStateNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method FriendsListener.OnUpdateFriendState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace friends
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
