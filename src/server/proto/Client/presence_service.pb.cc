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
#include "presence_service.pb.h"

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
namespace presence {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* SubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscribeNotificationRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeNotificationRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UnsubscribeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UnsubscribeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueryRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueryRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueryResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueryResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* OwnershipRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  OwnershipRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* MigrateOlympusCustomMessageRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MigrateOlympusCustomMessageRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* MigrateOlympusCustomMessageResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MigrateOlympusCustomMessageResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* PresenceService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_presence_5fservice_2eproto() {
  protobuf_AddDesc_presence_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "presence_service.proto");
  GOOGLE_CHECK(file != NULL);
  SubscribeRequest_descriptor_ = file->message_type(0);
  static const int SubscribeRequest_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, object_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeRequest, flag_public_),
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
  SubscribeNotificationRequest_descriptor_ = file->message_type(1);
  static const int SubscribeNotificationRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeNotificationRequest, entity_id_),
  };
  SubscribeNotificationRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscribeNotificationRequest_descriptor_,
      SubscribeNotificationRequest::default_instance_,
      SubscribeNotificationRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeNotificationRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeNotificationRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscribeNotificationRequest));
  UnsubscribeRequest_descriptor_ = file->message_type(2);
  static const int UnsubscribeRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UnsubscribeRequest, entity_id_),
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
  UpdateRequest_descriptor_ = file->message_type(3);
  static const int UpdateRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, field_operation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, no_create_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, agent_id_),
  };
  UpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateRequest_descriptor_,
      UpdateRequest::default_instance_,
      UpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateRequest));
  QueryRequest_descriptor_ = file->message_type(4);
  static const int QueryRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryRequest, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryRequest, agent_id_),
  };
  QueryRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueryRequest_descriptor_,
      QueryRequest::default_instance_,
      QueryRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QueryRequest));
  QueryResponse_descriptor_ = file->message_type(5);
  static const int QueryResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryResponse, field_),
  };
  QueryResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueryResponse_descriptor_,
      QueryResponse::default_instance_,
      QueryResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QueryResponse));
  OwnershipRequest_descriptor_ = file->message_type(6);
  static const int OwnershipRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(OwnershipRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(OwnershipRequest, release_ownership_),
  };
  OwnershipRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      OwnershipRequest_descriptor_,
      OwnershipRequest::default_instance_,
      OwnershipRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(OwnershipRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(OwnershipRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(OwnershipRequest));
  MigrateOlympusCustomMessageRequest_descriptor_ = file->message_type(7);
  static const int MigrateOlympusCustomMessageRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageRequest, account_),
  };
  MigrateOlympusCustomMessageRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MigrateOlympusCustomMessageRequest_descriptor_,
      MigrateOlympusCustomMessageRequest::default_instance_,
      MigrateOlympusCustomMessageRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MigrateOlympusCustomMessageRequest));
  MigrateOlympusCustomMessageResponse_descriptor_ = file->message_type(8);
  static const int MigrateOlympusCustomMessageResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageResponse, custom_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageResponse, custom_message_time_epoch_),
  };
  MigrateOlympusCustomMessageResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MigrateOlympusCustomMessageResponse_descriptor_,
      MigrateOlympusCustomMessageResponse::default_instance_,
      MigrateOlympusCustomMessageResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MigrateOlympusCustomMessageResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MigrateOlympusCustomMessageResponse));
  PresenceService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_presence_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeRequest_descriptor_, &SubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeNotificationRequest_descriptor_, &SubscribeNotificationRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UnsubscribeRequest_descriptor_, &UnsubscribeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateRequest_descriptor_, &UpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueryRequest_descriptor_, &QueryRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueryResponse_descriptor_, &QueryResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    OwnershipRequest_descriptor_, &OwnershipRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MigrateOlympusCustomMessageRequest_descriptor_, &MigrateOlympusCustomMessageRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MigrateOlympusCustomMessageResponse_descriptor_, &MigrateOlympusCustomMessageResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_presence_5fservice_2eproto() {
  delete SubscribeRequest::default_instance_;
  delete SubscribeRequest_reflection_;
  delete SubscribeNotificationRequest::default_instance_;
  delete SubscribeNotificationRequest_reflection_;
  delete UnsubscribeRequest::default_instance_;
  delete UnsubscribeRequest_reflection_;
  delete UpdateRequest::default_instance_;
  delete UpdateRequest_reflection_;
  delete QueryRequest::default_instance_;
  delete QueryRequest_reflection_;
  delete QueryResponse::default_instance_;
  delete QueryResponse_reflection_;
  delete OwnershipRequest::default_instance_;
  delete OwnershipRequest_reflection_;
  delete MigrateOlympusCustomMessageRequest::default_instance_;
  delete MigrateOlympusCustomMessageRequest_reflection_;
  delete MigrateOlympusCustomMessageResponse::default_instance_;
  delete MigrateOlympusCustomMessageResponse_reflection_;
}

void protobuf_AddDesc_presence_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::presence::v1::protobuf_AddDesc_presence_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026presence_service.proto\022\030bgs.protocol.p"
    "resence.v1\032\022entity_types.proto\032\024presence"
    "_types.proto\032\017rpc_types.proto\"\252\001\n\020Subscr"
    "ibeRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.proto"
    "col.EntityId\022)\n\tentity_id\030\002 \002(\0132\026.bgs.pr"
    "otocol.EntityId\022\021\n\tobject_id\030\003 \002(\004\022\017\n\007pr"
    "ogram\030\004 \003(\007\022\035\n\013flag_public\030\005 \001(\010:\004trueB\002"
    "\030\001\"I\n\034SubscribeNotificationRequest\022)\n\ten"
    "tity_id\030\001 \002(\0132\026.bgs.protocol.EntityId\"|\n"
    "\022UnsubscribeRequest\022(\n\010agent_id\030\001 \001(\0132\026."
    "bgs.protocol.EntityId\022)\n\tentity_id\030\002 \002(\013"
    "2\026.bgs.protocol.EntityId\022\021\n\tobject_id\030\003 "
    "\001(\004\"\301\001\n\rUpdateRequest\022)\n\tentity_id\030\001 \002(\013"
    "2\026.bgs.protocol.EntityId\022A\n\017field_operat"
    "ion\030\002 \003(\0132(.bgs.protocol.presence.v1.Fie"
    "ldOperation\022\030\n\tno_create\030\003 \001(\010:\005false\022(\n"
    "\010agent_id\030\004 \001(\0132\026.bgs.protocol.EntityId\""
    "\224\001\n\014QueryRequest\022)\n\tentity_id\030\001 \002(\0132\026.bg"
    "s.protocol.EntityId\022/\n\003key\030\002 \003(\0132\".bgs.p"
    "rotocol.presence.v1.FieldKey\022(\n\010agent_id"
    "\030\003 \001(\0132\026.bgs.protocol.EntityId\"\?\n\rQueryR"
    "esponse\022.\n\005field\030\002 \003(\0132\037.bgs.protocol.pr"
    "esence.v1.Field\"_\n\020OwnershipRequest\022)\n\te"
    "ntity_id\030\001 \002(\0132\026.bgs.protocol.EntityId\022 "
    "\n\021release_ownership\030\002 \001(\010:\005false\"M\n\"Migr"
    "ateOlympusCustomMessageRequest\022\'\n\007accoun"
    "t\030\001 \002(\0132\026.bgs.protocol.EntityId\"`\n#Migra"
    "teOlympusCustomMessageResponse\022\026\n\016custom"
    "_message\030\001 \001(\t\022!\n\031custom_message_time_ep"
    "och\030\002 \001(\r2\376\005\n\017PresenceService\022S\n\tSubscri"
    "be\022*.bgs.protocol.presence.v1.SubscribeR"
    "equest\032\024.bgs.protocol.NoData\"\004\200\265\030\001\022W\n\013Un"
    "subscribe\022,.bgs.protocol.presence.v1.Uns"
    "ubscribeRequest\032\024.bgs.protocol.NoData\"\004\200"
    "\265\030\002\022M\n\006Update\022\'.bgs.protocol.presence.v1"
    ".UpdateRequest\032\024.bgs.protocol.NoData\"\004\200\265"
    "\030\003\022^\n\005Query\022&.bgs.protocol.presence.v1.Q"
    "ueryRequest\032\'.bgs.protocol.presence.v1.Q"
    "ueryResponse\"\004\200\265\030\004\022S\n\tOwnership\022*.bgs.pr"
    "otocol.presence.v1.OwnershipRequest\032\024.bg"
    "s.protocol.NoData\"\004\200\265\030\005\022k\n\025SubscribeNoti"
    "fication\0226.bgs.protocol.presence.v1.Subs"
    "cribeNotificationRequest\032\024.bgs.protocol."
    "NoData\"\004\200\265\030\007\022\240\001\n\033MigrateOlympusCustomMes"
    "sage\022<.bgs.protocol.presence.v1.MigrateO"
    "lympusCustomMessageRequest\032=.bgs.protoco"
    "l.presence.v1.MigrateOlympusCustomMessag"
    "eResponse\"\004\200\265\030\010\032)\312>&bnet.protocol.presen"
    "ce.PresenceServiceB\005H\001\200\001\000", 1945);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "presence_service.proto", &protobuf_RegisterTypes);
  SubscribeRequest::default_instance_ = new SubscribeRequest();
  SubscribeNotificationRequest::default_instance_ = new SubscribeNotificationRequest();
  UnsubscribeRequest::default_instance_ = new UnsubscribeRequest();
  UpdateRequest::default_instance_ = new UpdateRequest();
  QueryRequest::default_instance_ = new QueryRequest();
  QueryResponse::default_instance_ = new QueryResponse();
  OwnershipRequest::default_instance_ = new OwnershipRequest();
  MigrateOlympusCustomMessageRequest::default_instance_ = new MigrateOlympusCustomMessageRequest();
  MigrateOlympusCustomMessageResponse::default_instance_ = new MigrateOlympusCustomMessageResponse();
  SubscribeRequest::default_instance_->InitAsDefaultInstance();
  SubscribeNotificationRequest::default_instance_->InitAsDefaultInstance();
  UnsubscribeRequest::default_instance_->InitAsDefaultInstance();
  UpdateRequest::default_instance_->InitAsDefaultInstance();
  QueryRequest::default_instance_->InitAsDefaultInstance();
  QueryResponse::default_instance_->InitAsDefaultInstance();
  OwnershipRequest::default_instance_->InitAsDefaultInstance();
  MigrateOlympusCustomMessageRequest::default_instance_->InitAsDefaultInstance();
  MigrateOlympusCustomMessageResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_presence_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_presence_5fservice_2eproto {
  StaticDescriptorInitializer_presence_5fservice_2eproto() {
    protobuf_AddDesc_presence_5fservice_2eproto();
  }
} static_descriptor_initializer_presence_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SubscribeRequest::kAgentIdFieldNumber;
const int SubscribeRequest::kEntityIdFieldNumber;
const int SubscribeRequest::kObjectIdFieldNumber;
const int SubscribeRequest::kProgramFieldNumber;
const int SubscribeRequest::kFlagPublicFieldNumber;
#endif  // !_MSC_VER

SubscribeRequest::SubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.SubscribeRequest)
}

void SubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SubscribeRequest::SubscribeRequest(const SubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.SubscribeRequest)
}

void SubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  entity_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  flag_public_ = true;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeRequest::~SubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.SubscribeRequest)
  SharedDtor();
}

void SubscribeRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete entity_id_;
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
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

SubscribeRequest* SubscribeRequest::default_instance_ = NULL;

SubscribeRequest* SubscribeRequest::New() const {
  return new SubscribeRequest;
}

void SubscribeRequest::Clear() {
  if (_has_bits_[0 / 32] & 23) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    object_id_ = GOOGLE_ULONGLONG(0);
    flag_public_ = true;
  }
  program_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscribeRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.SubscribeRequest)
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
        if (input->ExpectTag(18)) goto parse_entity_id;
        break;
      }

      // required .bgs.protocol.EntityId entity_id = 2;
      case 2: {
        if (tag == 18) {
         parse_entity_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_object_id;
        break;
      }

      // required uint64 object_id = 3;
      case 3: {
        if (tag == 24) {
         parse_object_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &object_id_)));
          set_has_object_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_program;
        break;
      }

      // repeated fixed32 program = 4;
      case 4: {
        if (tag == 37) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 1, 37, input, this->mutable_program())));
        } else if (tag == 34) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, this->mutable_program())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_program;
        if (input->ExpectTag(40)) goto parse_flag_public;
        break;
      }

      // optional bool flag_public = 5 [default = true, deprecated = true];
      case 5: {
        if (tag == 40) {
         parse_flag_public:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &flag_public_)));
          set_has_flag_public();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.SubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.SubscribeRequest)
  return false;
#undef DO_
}

void SubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.SubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->entity_id(), output);
  }

  // required uint64 object_id = 3;
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->object_id(), output);
  }

  // repeated fixed32 program = 4;
  for (int i = 0; i < this->program_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(
      4, this->program(i), output);
  }

  // optional bool flag_public = 5 [default = true, deprecated = true];
  if (has_flag_public()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->flag_public(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.SubscribeRequest)
}

::google::protobuf::uint8* SubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.SubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->entity_id(), target);
  }

  // required uint64 object_id = 3;
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->object_id(), target);
  }

  // repeated fixed32 program = 4;
  for (int i = 0; i < this->program_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFixed32ToArray(4, this->program(i), target);
  }

  // optional bool flag_public = 5 [default = true, deprecated = true];
  if (has_flag_public()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->flag_public(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.SubscribeRequest)
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

    // required .bgs.protocol.EntityId entity_id = 2;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // required uint64 object_id = 3;
    if (has_object_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->object_id());
    }

    // optional bool flag_public = 5 [default = true, deprecated = true];
    if (has_flag_public()) {
      total_size += 1 + 1;
    }

  }
  // repeated fixed32 program = 4;
  {
    int data_size = 0;
    data_size = 4 * this->program_size();
    total_size += 1 * this->program_size() + data_size;
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
  program_.MergeFrom(from.program_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
    if (from.has_flag_public()) {
      set_flag_public(from.flag_public());
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
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void SubscribeRequest::Swap(SubscribeRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(entity_id_, other->entity_id_);
    std::swap(object_id_, other->object_id_);
    program_.Swap(&other->program_);
    std::swap(flag_public_, other->flag_public_);
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
const int SubscribeNotificationRequest::kEntityIdFieldNumber;
#endif  // !_MSC_VER

SubscribeNotificationRequest::SubscribeNotificationRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.SubscribeNotificationRequest)
}

void SubscribeNotificationRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SubscribeNotificationRequest::SubscribeNotificationRequest(const SubscribeNotificationRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.SubscribeNotificationRequest)
}

void SubscribeNotificationRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeNotificationRequest::~SubscribeNotificationRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  SharedDtor();
}

void SubscribeNotificationRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void SubscribeNotificationRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscribeNotificationRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscribeNotificationRequest_descriptor_;
}

const SubscribeNotificationRequest& SubscribeNotificationRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

SubscribeNotificationRequest* SubscribeNotificationRequest::default_instance_ = NULL;

SubscribeNotificationRequest* SubscribeNotificationRequest::New() const {
  return new SubscribeNotificationRequest;
}

void SubscribeNotificationRequest::Clear() {
  if (has_entity_id()) {
    if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscribeNotificationRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  return false;
#undef DO_
}

void SubscribeNotificationRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.SubscribeNotificationRequest)
}

::google::protobuf::uint8* SubscribeNotificationRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.SubscribeNotificationRequest)
  return target;
}

int SubscribeNotificationRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
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

void SubscribeNotificationRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscribeNotificationRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscribeNotificationRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscribeNotificationRequest::MergeFrom(const SubscribeNotificationRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscribeNotificationRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscribeNotificationRequest::CopyFrom(const SubscribeNotificationRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscribeNotificationRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void SubscribeNotificationRequest::Swap(SubscribeNotificationRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscribeNotificationRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscribeNotificationRequest_descriptor_;
  metadata.reflection = SubscribeNotificationRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UnsubscribeRequest::kAgentIdFieldNumber;
const int UnsubscribeRequest::kEntityIdFieldNumber;
const int UnsubscribeRequest::kObjectIdFieldNumber;
#endif  // !_MSC_VER

UnsubscribeRequest::UnsubscribeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UnsubscribeRequest::UnsubscribeRequest(const UnsubscribeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.UnsubscribeRequest)
}

void UnsubscribeRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_id_ = NULL;
  entity_id_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UnsubscribeRequest::~UnsubscribeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.UnsubscribeRequest)
  SharedDtor();
}

void UnsubscribeRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_id_;
    delete entity_id_;
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
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

UnsubscribeRequest* UnsubscribeRequest::default_instance_ = NULL;

UnsubscribeRequest* UnsubscribeRequest::New() const {
  return new UnsubscribeRequest;
}

void UnsubscribeRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
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
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.UnsubscribeRequest)
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
        if (input->ExpectTag(18)) goto parse_entity_id;
        break;
      }

      // required .bgs.protocol.EntityId entity_id = 2;
      case 2: {
        if (tag == 18) {
         parse_entity_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_object_id;
        break;
      }

      // optional uint64 object_id = 3;
      case 3: {
        if (tag == 24) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.UnsubscribeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.UnsubscribeRequest)
  return false;
#undef DO_
}

void UnsubscribeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.UnsubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_id(), output);
  }

  // required .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->entity_id(), output);
  }

  // optional uint64 object_id = 3;
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->object_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.UnsubscribeRequest)
}

::google::protobuf::uint8* UnsubscribeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.UnsubscribeRequest)
  // optional .bgs.protocol.EntityId agent_id = 1;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_id(), target);
  }

  // required .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->entity_id(), target);
  }

  // optional uint64 object_id = 3;
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->object_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.UnsubscribeRequest)
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

    // required .bgs.protocol.EntityId entity_id = 2;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional uint64 object_id = 3;
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
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
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
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void UnsubscribeRequest::Swap(UnsubscribeRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(entity_id_, other->entity_id_);
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
const int UpdateRequest::kEntityIdFieldNumber;
const int UpdateRequest::kFieldOperationFieldNumber;
const int UpdateRequest::kNoCreateFieldNumber;
const int UpdateRequest::kAgentIdFieldNumber;
#endif  // !_MSC_VER

UpdateRequest::UpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.UpdateRequest)
}

void UpdateRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

UpdateRequest::UpdateRequest(const UpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.UpdateRequest)
}

void UpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  no_create_ = false;
  agent_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateRequest::~UpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.UpdateRequest)
  SharedDtor();
}

void UpdateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
    delete agent_id_;
  }
}

void UpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateRequest_descriptor_;
}

const UpdateRequest& UpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

UpdateRequest* UpdateRequest::default_instance_ = NULL;

UpdateRequest* UpdateRequest::New() const {
  return new UpdateRequest;
}

void UpdateRequest::Clear() {
  if (_has_bits_[0 / 32] & 13) {
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    no_create_ = false;
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  field_operation_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.UpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_field_operation;
        break;
      }

      // repeated .bgs.protocol.presence.v1.FieldOperation field_operation = 2;
      case 2: {
        if (tag == 18) {
         parse_field_operation:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_field_operation()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_field_operation;
        if (input->ExpectTag(24)) goto parse_no_create;
        break;
      }

      // optional bool no_create = 3 [default = false];
      case 3: {
        if (tag == 24) {
         parse_no_create:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &no_create_)));
          set_has_no_create();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_agent_id;
        break;
      }

      // optional .bgs.protocol.EntityId agent_id = 4;
      case 4: {
        if (tag == 34) {
         parse_agent_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.UpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.UpdateRequest)
  return false;
#undef DO_
}

void UpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.UpdateRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // repeated .bgs.protocol.presence.v1.FieldOperation field_operation = 2;
  for (int i = 0; i < this->field_operation_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->field_operation(i), output);
  }

  // optional bool no_create = 3 [default = false];
  if (has_no_create()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->no_create(), output);
  }

  // optional .bgs.protocol.EntityId agent_id = 4;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->agent_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.UpdateRequest)
}

::google::protobuf::uint8* UpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.UpdateRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  // repeated .bgs.protocol.presence.v1.FieldOperation field_operation = 2;
  for (int i = 0; i < this->field_operation_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->field_operation(i), target);
  }

  // optional bool no_create = 3 [default = false];
  if (has_no_create()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->no_create(), target);
  }

  // optional .bgs.protocol.EntityId agent_id = 4;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->agent_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.UpdateRequest)
  return target;
}

int UpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional bool no_create = 3 [default = false];
    if (has_no_create()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.EntityId agent_id = 4;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

  }
  // repeated .bgs.protocol.presence.v1.FieldOperation field_operation = 2;
  total_size += 1 * this->field_operation_size();
  for (int i = 0; i < this->field_operation_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->field_operation(i));
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

void UpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateRequest::MergeFrom(const UpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  field_operation_.MergeFrom(from.field_operation_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_no_create()) {
      set_no_create(from.no_create());
    }
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateRequest::CopyFrom(const UpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->field_operation())) return false;
  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void UpdateRequest::Swap(UpdateRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    field_operation_.Swap(&other->field_operation_);
    std::swap(no_create_, other->no_create_);
    std::swap(agent_id_, other->agent_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateRequest_descriptor_;
  metadata.reflection = UpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int QueryRequest::kEntityIdFieldNumber;
const int QueryRequest::kKeyFieldNumber;
const int QueryRequest::kAgentIdFieldNumber;
#endif  // !_MSC_VER

QueryRequest::QueryRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.QueryRequest)
}

void QueryRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

QueryRequest::QueryRequest(const QueryRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.QueryRequest)
}

void QueryRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  agent_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QueryRequest::~QueryRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.QueryRequest)
  SharedDtor();
}

void QueryRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
    delete agent_id_;
  }
}

void QueryRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QueryRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueryRequest_descriptor_;
}

const QueryRequest& QueryRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

QueryRequest* QueryRequest::default_instance_ = NULL;

QueryRequest* QueryRequest::New() const {
  return new QueryRequest;
}

void QueryRequest::Clear() {
  if (_has_bits_[0 / 32] & 5) {
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  key_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QueryRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.QueryRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_key;
        break;
      }

      // repeated .bgs.protocol.presence.v1.FieldKey key = 2;
      case 2: {
        if (tag == 18) {
         parse_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_key()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_key;
        if (input->ExpectTag(26)) goto parse_agent_id;
        break;
      }

      // optional .bgs.protocol.EntityId agent_id = 3;
      case 3: {
        if (tag == 26) {
         parse_agent_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.QueryRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.QueryRequest)
  return false;
#undef DO_
}

void QueryRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.QueryRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // repeated .bgs.protocol.presence.v1.FieldKey key = 2;
  for (int i = 0; i < this->key_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->key(i), output);
  }

  // optional .bgs.protocol.EntityId agent_id = 3;
  if (has_agent_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->agent_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.QueryRequest)
}

::google::protobuf::uint8* QueryRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.QueryRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  // repeated .bgs.protocol.presence.v1.FieldKey key = 2;
  for (int i = 0; i < this->key_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->key(i), target);
  }

  // optional .bgs.protocol.EntityId agent_id = 3;
  if (has_agent_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->agent_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.QueryRequest)
  return target;
}

int QueryRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional .bgs.protocol.EntityId agent_id = 3;
    if (has_agent_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_id());
    }

  }
  // repeated .bgs.protocol.presence.v1.FieldKey key = 2;
  total_size += 1 * this->key_size();
  for (int i = 0; i < this->key_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->key(i));
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

void QueryRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QueryRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QueryRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QueryRequest::MergeFrom(const QueryRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  key_.MergeFrom(from.key_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QueryRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QueryRequest::CopyFrom(const QueryRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QueryRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->key())) return false;
  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  return true;
}

void QueryRequest::Swap(QueryRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    key_.Swap(&other->key_);
    std::swap(agent_id_, other->agent_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QueryRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QueryRequest_descriptor_;
  metadata.reflection = QueryRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int QueryResponse::kFieldFieldNumber;
#endif  // !_MSC_VER

QueryResponse::QueryResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.QueryResponse)
}

void QueryResponse::InitAsDefaultInstance() {
}

QueryResponse::QueryResponse(const QueryResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.QueryResponse)
}

void QueryResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QueryResponse::~QueryResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.QueryResponse)
  SharedDtor();
}

void QueryResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void QueryResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QueryResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueryResponse_descriptor_;
}

const QueryResponse& QueryResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

QueryResponse* QueryResponse::default_instance_ = NULL;

QueryResponse* QueryResponse::New() const {
  return new QueryResponse;
}

void QueryResponse::Clear() {
  field_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QueryResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.QueryResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.presence.v1.Field field = 2;
      case 2: {
        if (tag == 18) {
         parse_field:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_field()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_field;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.QueryResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.QueryResponse)
  return false;
#undef DO_
}

void QueryResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.QueryResponse)
  // repeated .bgs.protocol.presence.v1.Field field = 2;
  for (int i = 0; i < this->field_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->field(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.QueryResponse)
}

::google::protobuf::uint8* QueryResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.QueryResponse)
  // repeated .bgs.protocol.presence.v1.Field field = 2;
  for (int i = 0; i < this->field_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->field(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.QueryResponse)
  return target;
}

int QueryResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.presence.v1.Field field = 2;
  total_size += 1 * this->field_size();
  for (int i = 0; i < this->field_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->field(i));
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

void QueryResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QueryResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QueryResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QueryResponse::MergeFrom(const QueryResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  field_.MergeFrom(from.field_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QueryResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QueryResponse::CopyFrom(const QueryResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QueryResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->field())) return false;
  return true;
}

void QueryResponse::Swap(QueryResponse* other) {
  if (other != this) {
    field_.Swap(&other->field_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QueryResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QueryResponse_descriptor_;
  metadata.reflection = QueryResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int OwnershipRequest::kEntityIdFieldNumber;
const int OwnershipRequest::kReleaseOwnershipFieldNumber;
#endif  // !_MSC_VER

OwnershipRequest::OwnershipRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.OwnershipRequest)
}

void OwnershipRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

OwnershipRequest::OwnershipRequest(const OwnershipRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.OwnershipRequest)
}

void OwnershipRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  release_ownership_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

OwnershipRequest::~OwnershipRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.OwnershipRequest)
  SharedDtor();
}

void OwnershipRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void OwnershipRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* OwnershipRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return OwnershipRequest_descriptor_;
}

const OwnershipRequest& OwnershipRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

OwnershipRequest* OwnershipRequest::default_instance_ = NULL;

OwnershipRequest* OwnershipRequest::New() const {
  return new OwnershipRequest;
}

void OwnershipRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    release_ownership_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool OwnershipRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.OwnershipRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_release_ownership;
        break;
      }

      // optional bool release_ownership = 2 [default = false];
      case 2: {
        if (tag == 16) {
         parse_release_ownership:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &release_ownership_)));
          set_has_release_ownership();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.OwnershipRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.OwnershipRequest)
  return false;
#undef DO_
}

void OwnershipRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.OwnershipRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // optional bool release_ownership = 2 [default = false];
  if (has_release_ownership()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->release_ownership(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.OwnershipRequest)
}

::google::protobuf::uint8* OwnershipRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.OwnershipRequest)
  // required .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  // optional bool release_ownership = 2 [default = false];
  if (has_release_ownership()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->release_ownership(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.OwnershipRequest)
  return target;
}

int OwnershipRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional bool release_ownership = 2 [default = false];
    if (has_release_ownership()) {
      total_size += 1 + 1;
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

void OwnershipRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const OwnershipRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const OwnershipRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void OwnershipRequest::MergeFrom(const OwnershipRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_release_ownership()) {
      set_release_ownership(from.release_ownership());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void OwnershipRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void OwnershipRequest::CopyFrom(const OwnershipRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OwnershipRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void OwnershipRequest::Swap(OwnershipRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(release_ownership_, other->release_ownership_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata OwnershipRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = OwnershipRequest_descriptor_;
  metadata.reflection = OwnershipRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MigrateOlympusCustomMessageRequest::kAccountFieldNumber;
#endif  // !_MSC_VER

MigrateOlympusCustomMessageRequest::MigrateOlympusCustomMessageRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
}

void MigrateOlympusCustomMessageRequest::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

MigrateOlympusCustomMessageRequest::MigrateOlympusCustomMessageRequest(const MigrateOlympusCustomMessageRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
}

void MigrateOlympusCustomMessageRequest::SharedCtor() {
  _cached_size_ = 0;
  account_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MigrateOlympusCustomMessageRequest::~MigrateOlympusCustomMessageRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  SharedDtor();
}

void MigrateOlympusCustomMessageRequest::SharedDtor() {
  if (this != default_instance_) {
    delete account_;
  }
}

void MigrateOlympusCustomMessageRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MigrateOlympusCustomMessageRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MigrateOlympusCustomMessageRequest_descriptor_;
}

const MigrateOlympusCustomMessageRequest& MigrateOlympusCustomMessageRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

MigrateOlympusCustomMessageRequest* MigrateOlympusCustomMessageRequest::default_instance_ = NULL;

MigrateOlympusCustomMessageRequest* MigrateOlympusCustomMessageRequest::New() const {
  return new MigrateOlympusCustomMessageRequest;
}

void MigrateOlympusCustomMessageRequest::Clear() {
  if (has_account()) {
    if (account_ != NULL) account_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MigrateOlympusCustomMessageRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  return false;
#undef DO_
}

void MigrateOlympusCustomMessageRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  // required .bgs.protocol.EntityId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
}

::google::protobuf::uint8* MigrateOlympusCustomMessageRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  // required .bgs.protocol.EntityId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest)
  return target;
}

int MigrateOlympusCustomMessageRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
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

void MigrateOlympusCustomMessageRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MigrateOlympusCustomMessageRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MigrateOlympusCustomMessageRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MigrateOlympusCustomMessageRequest::MergeFrom(const MigrateOlympusCustomMessageRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::EntityId::MergeFrom(from.account());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MigrateOlympusCustomMessageRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MigrateOlympusCustomMessageRequest::CopyFrom(const MigrateOlympusCustomMessageRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MigrateOlympusCustomMessageRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  return true;
}

void MigrateOlympusCustomMessageRequest::Swap(MigrateOlympusCustomMessageRequest* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MigrateOlympusCustomMessageRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MigrateOlympusCustomMessageRequest_descriptor_;
  metadata.reflection = MigrateOlympusCustomMessageRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MigrateOlympusCustomMessageResponse::kCustomMessageFieldNumber;
const int MigrateOlympusCustomMessageResponse::kCustomMessageTimeEpochFieldNumber;
#endif  // !_MSC_VER

MigrateOlympusCustomMessageResponse::MigrateOlympusCustomMessageResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
}

void MigrateOlympusCustomMessageResponse::InitAsDefaultInstance() {
}

MigrateOlympusCustomMessageResponse::MigrateOlympusCustomMessageResponse(const MigrateOlympusCustomMessageResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
}

void MigrateOlympusCustomMessageResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  custom_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  custom_message_time_epoch_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MigrateOlympusCustomMessageResponse::~MigrateOlympusCustomMessageResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  SharedDtor();
}

void MigrateOlympusCustomMessageResponse::SharedDtor() {
  if (custom_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete custom_message_;
  }
  if (this != default_instance_) {
  }
}

void MigrateOlympusCustomMessageResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MigrateOlympusCustomMessageResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MigrateOlympusCustomMessageResponse_descriptor_;
}

const MigrateOlympusCustomMessageResponse& MigrateOlympusCustomMessageResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5fservice_2eproto();
  return *default_instance_;
}

MigrateOlympusCustomMessageResponse* MigrateOlympusCustomMessageResponse::default_instance_ = NULL;

MigrateOlympusCustomMessageResponse* MigrateOlympusCustomMessageResponse::New() const {
  return new MigrateOlympusCustomMessageResponse;
}

void MigrateOlympusCustomMessageResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_custom_message()) {
      if (custom_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        custom_message_->clear();
      }
    }
    custom_message_time_epoch_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MigrateOlympusCustomMessageResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string custom_message = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_custom_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->custom_message().data(), this->custom_message().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "custom_message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_custom_message_time_epoch;
        break;
      }

      // optional uint32 custom_message_time_epoch = 2;
      case 2: {
        if (tag == 16) {
         parse_custom_message_time_epoch:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &custom_message_time_epoch_)));
          set_has_custom_message_time_epoch();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  return false;
#undef DO_
}

void MigrateOlympusCustomMessageResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  // optional string custom_message = 1;
  if (has_custom_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->custom_message().data(), this->custom_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "custom_message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->custom_message(), output);
  }

  // optional uint32 custom_message_time_epoch = 2;
  if (has_custom_message_time_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->custom_message_time_epoch(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
}

::google::protobuf::uint8* MigrateOlympusCustomMessageResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  // optional string custom_message = 1;
  if (has_custom_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->custom_message().data(), this->custom_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "custom_message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->custom_message(), target);
  }

  // optional uint32 custom_message_time_epoch = 2;
  if (has_custom_message_time_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->custom_message_time_epoch(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse)
  return target;
}

int MigrateOlympusCustomMessageResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string custom_message = 1;
    if (has_custom_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->custom_message());
    }

    // optional uint32 custom_message_time_epoch = 2;
    if (has_custom_message_time_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->custom_message_time_epoch());
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

void MigrateOlympusCustomMessageResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MigrateOlympusCustomMessageResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MigrateOlympusCustomMessageResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MigrateOlympusCustomMessageResponse::MergeFrom(const MigrateOlympusCustomMessageResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_custom_message()) {
      set_custom_message(from.custom_message());
    }
    if (from.has_custom_message_time_epoch()) {
      set_custom_message_time_epoch(from.custom_message_time_epoch());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MigrateOlympusCustomMessageResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MigrateOlympusCustomMessageResponse::CopyFrom(const MigrateOlympusCustomMessageResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MigrateOlympusCustomMessageResponse::IsInitialized() const {

  return true;
}

void MigrateOlympusCustomMessageResponse::Swap(MigrateOlympusCustomMessageResponse* other) {
  if (other != this) {
    std::swap(custom_message_, other->custom_message_);
    std::swap(custom_message_time_epoch_, other->custom_message_time_epoch_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MigrateOlympusCustomMessageResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MigrateOlympusCustomMessageResponse_descriptor_;
  metadata.reflection = MigrateOlympusCustomMessageResponse_reflection_;
  return metadata;
}


// ===================================================================

PresenceService::PresenceService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

PresenceService::~PresenceService() {
}

google::protobuf::ServiceDescriptor const* PresenceService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PresenceService_descriptor_;
}

void PresenceService::Subscribe(::bgs::protocol::presence::v1::SubscribeRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.Subscribe(bgs.protocol.presence.v1.SubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void PresenceService::Unsubscribe(::bgs::protocol::presence::v1::UnsubscribeRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.Unsubscribe(bgs.protocol.presence.v1.UnsubscribeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void PresenceService::Update(::bgs::protocol::presence::v1::UpdateRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.Update(bgs.protocol.presence.v1.UpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void PresenceService::Query(::bgs::protocol::presence::v1::QueryRequest const* request, std::function<void(::bgs::protocol::presence::v1::QueryResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.Query(bgs.protocol.presence.v1.QueryRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::presence::v1::QueryResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 4, request, std::move(callback));
}

void PresenceService::Ownership(::bgs::protocol::presence::v1::OwnershipRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.Ownership(bgs.protocol.presence.v1.OwnershipRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 5, request, std::move(callback));
}

void PresenceService::SubscribeNotification(::bgs::protocol::presence::v1::SubscribeNotificationRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.SubscribeNotification(bgs.protocol.presence.v1.SubscribeNotificationRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 7, request, std::move(callback));
}

void PresenceService::MigrateOlympusCustomMessage(::bgs::protocol::presence::v1::MigrateOlympusCustomMessageRequest const* request, std::function<void(::bgs::protocol::presence::v1::MigrateOlympusCustomMessageResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method PresenceService.MigrateOlympusCustomMessage(bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::presence::v1::MigrateOlympusCustomMessageResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 8, request, std::move(callback));
}

void PresenceService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::presence::v1::SubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.Subscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.Subscribe(bgs.protocol.presence.v1.SubscribeRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::presence::v1::UnsubscribeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.Unsubscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUnsubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.Unsubscribe(bgs.protocol.presence.v1.UnsubscribeRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::presence::v1::UpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.Update server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUpdate(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.Update(bgs.protocol.presence.v1.UpdateRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::presence::v1::QueryRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.Query server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::presence::v1::QueryResponse response;
      uint32 status = HandleQuery(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.Query(bgs.protocol.presence.v1.QueryRequest{ %s }) returned bgs.protocol.presence.v1.QueryResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 4, token, &response);
      else
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::presence::v1::OwnershipRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.Ownership server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleOwnership(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.Ownership(bgs.protocol.presence.v1.OwnershipRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 5, token, &response);
      else
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::presence::v1::SubscribeNotificationRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.SubscribeNotification server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSubscribeNotification(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.SubscribeNotification(bgs.protocol.presence.v1.SubscribeNotificationRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 7, token, &response);
      else
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    case 8: {
      ::bgs::protocol::presence::v1::MigrateOlympusCustomMessageRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for PresenceService.MigrateOlympusCustomMessage server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 8, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::presence::v1::MigrateOlympusCustomMessageResponse response;
      uint32 status = HandleMigrateOlympusCustomMessage(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method PresenceService.MigrateOlympusCustomMessage(bgs.protocol.presence.v1.MigrateOlympusCustomMessageRequest{ %s }) returned bgs.protocol.presence.v1.MigrateOlympusCustomMessageResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 8, token, &response);
      else
        SendResponse(service_hash_, 8, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 PresenceService::HandleSubscribe(::bgs::protocol::presence::v1::SubscribeRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.Subscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleUnsubscribe(::bgs::protocol::presence::v1::UnsubscribeRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.Unsubscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleUpdate(::bgs::protocol::presence::v1::UpdateRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.Update({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleQuery(::bgs::protocol::presence::v1::QueryRequest const* request, ::bgs::protocol::presence::v1::QueryResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.Query({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleOwnership(::bgs::protocol::presence::v1::OwnershipRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.Ownership({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleSubscribeNotification(::bgs::protocol::presence::v1::SubscribeNotificationRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.SubscribeNotification({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 PresenceService::HandleMigrateOlympusCustomMessage(::bgs::protocol::presence::v1::MigrateOlympusCustomMessageRequest const* request, ::bgs::protocol::presence::v1::MigrateOlympusCustomMessageResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method PresenceService.MigrateOlympusCustomMessage({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace presence
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
