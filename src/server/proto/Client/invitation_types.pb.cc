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
#include "invitation_types.pb.h"

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
// @@protoc_insertion_point(includes)

// Fix stupid windows.h included from Log.h->Common.h
#ifdef SendMessage
#undef SendMessage
#endif

namespace bgs {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* Invitation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Invitation_reflection_ = NULL;
const ::google::protobuf::Descriptor* InvitationSuggestion_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InvitationSuggestion_reflection_ = NULL;
const ::google::protobuf::Descriptor* InvitationTarget_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InvitationTarget_reflection_ = NULL;
const ::google::protobuf::Descriptor* InvitationParams_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InvitationParams_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendInvitationRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendInvitationRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendInvitationResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendInvitationResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateInvitationRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateInvitationRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenericInvitationRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenericInvitationRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_invitation_5ftypes_2eproto() {
  protobuf_AddDesc_invitation_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "invitation_types.proto");
  GOOGLE_CHECK(file != NULL);
  Invitation_descriptor_ = file->message_type(0);
  static const int Invitation_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, inviter_identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, invitee_identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, inviter_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, invitee_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, invitation_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, creation_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, expiration_time_),
  };
  Invitation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Invitation_descriptor_,
      Invitation::default_instance_,
      Invitation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Invitation, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Invitation));
  InvitationSuggestion_descriptor_ = file->message_type(1);
  static const int InvitationSuggestion_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, suggester_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, suggestee_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, suggester_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, suggestee_name_),
  };
  InvitationSuggestion_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InvitationSuggestion_descriptor_,
      InvitationSuggestion::default_instance_,
      InvitationSuggestion_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationSuggestion, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InvitationSuggestion));
  InvitationTarget_descriptor_ = file->message_type(2);
  static const int InvitationTarget_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, battle_tag_),
  };
  InvitationTarget_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InvitationTarget_descriptor_,
      InvitationTarget::default_instance_,
      InvitationTarget_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationTarget, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InvitationTarget));
  InvitationParams_descriptor_ = file->message_type(3);
  static const int InvitationParams_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationParams, invitation_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationParams, expiration_time_),
  };
  InvitationParams_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InvitationParams_descriptor_,
      InvitationParams::default_instance_,
      InvitationParams_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationParams, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationParams, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InvitationParams, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InvitationParams));
  SendInvitationRequest_descriptor_ = file->message_type(4);
  static const int SendInvitationRequest_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, agent_identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, params_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, agent_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, target_),
  };
  SendInvitationRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendInvitationRequest_descriptor_,
      SendInvitationRequest::default_instance_,
      SendInvitationRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendInvitationRequest));
  SendInvitationResponse_descriptor_ = file->message_type(5);
  static const int SendInvitationResponse_offsets_[1] = {
  };
  SendInvitationResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendInvitationResponse_descriptor_,
      SendInvitationResponse::default_instance_,
      SendInvitationResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendInvitationResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendInvitationResponse));
  UpdateInvitationRequest_descriptor_ = file->message_type(6);
  static const int UpdateInvitationRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateInvitationRequest, agent_identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateInvitationRequest, invitation_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateInvitationRequest, params_),
  };
  UpdateInvitationRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateInvitationRequest_descriptor_,
      UpdateInvitationRequest::default_instance_,
      UpdateInvitationRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateInvitationRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateInvitationRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateInvitationRequest));
  GenericInvitationRequest_descriptor_ = file->message_type(7);
  static const int GenericInvitationRequest_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, agent_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, invitation_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, invitee_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, inviter_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, previous_role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, desired_role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, reason_),
  };
  GenericInvitationRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenericInvitationRequest_descriptor_,
      GenericInvitationRequest::default_instance_,
      GenericInvitationRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenericInvitationRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenericInvitationRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_invitation_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Invitation_descriptor_, &Invitation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InvitationSuggestion_descriptor_, &InvitationSuggestion::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InvitationTarget_descriptor_, &InvitationTarget::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InvitationParams_descriptor_, &InvitationParams::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendInvitationRequest_descriptor_, &SendInvitationRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendInvitationResponse_descriptor_, &SendInvitationResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateInvitationRequest_descriptor_, &UpdateInvitationRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenericInvitationRequest_descriptor_, &GenericInvitationRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_invitation_5ftypes_2eproto() {
  delete Invitation::default_instance_;
  delete Invitation_reflection_;
  delete InvitationSuggestion::default_instance_;
  delete InvitationSuggestion_reflection_;
  delete InvitationTarget::default_instance_;
  delete InvitationTarget_reflection_;
  delete InvitationParams::default_instance_;
  delete InvitationParams_reflection_;
  delete SendInvitationRequest::default_instance_;
  delete SendInvitationRequest_reflection_;
  delete SendInvitationResponse::default_instance_;
  delete SendInvitationResponse_reflection_;
  delete UpdateInvitationRequest::default_instance_;
  delete UpdateInvitationRequest_reflection_;
  delete GenericInvitationRequest::default_instance_;
  delete GenericInvitationRequest_reflection_;
}

void protobuf_AddDesc_invitation_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026invitation_types.proto\022\014bgs.protocol\032\022"
    "entity_types.proto\"\373\001\n\nInvitation\022\n\n\002id\030"
    "\001 \002(\006\0220\n\020inviter_identity\030\002 \002(\0132\026.bgs.pr"
    "otocol.Identity\0220\n\020invitee_identity\030\003 \002("
    "\0132\026.bgs.protocol.Identity\022\024\n\014inviter_nam"
    "e\030\004 \001(\t\022\024\n\014invitee_name\030\005 \001(\t\022\032\n\022invitat"
    "ion_message\030\006 \001(\t\022\025\n\rcreation_time\030\007 \001(\004"
    "\022\027\n\017expiration_time\030\010 \001(\004*\005\010d\020\220N\"\316\001\n\024Inv"
    "itationSuggestion\022*\n\nchannel_id\030\001 \001(\0132\026."
    "bgs.protocol.EntityId\022,\n\014suggester_id\030\002 "
    "\002(\0132\026.bgs.protocol.EntityId\022,\n\014suggestee"
    "_id\030\003 \002(\0132\026.bgs.protocol.EntityId\022\026\n\016sug"
    "gester_name\030\004 \001(\t\022\026\n\016suggestee_name\030\005 \001("
    "\t\"f\n\020InvitationTarget\022(\n\010identity\030\001 \001(\0132"
    "\026.bgs.protocol.Identity\022\r\n\005email\030\002 \001(\t\022\022"
    "\n\nbattle_tag\030\003 \001(\t*\005\010d\020\220N\"Q\n\020InvitationP"
    "arams\022\032\n\022invitation_message\030\001 \001(\t\022\032\n\017exp"
    "iration_time\030\002 \001(\004:\0010*\005\010d\020\220N\"\205\002\n\025SendInv"
    "itationRequest\022.\n\016agent_identity\030\001 \001(\0132\026"
    ".bgs.protocol.Identity\022-\n\ttarget_id\030\002 \002("
    "\0132\026.bgs.protocol.EntityIdB\002\030\001\022.\n\006params\030"
    "\003 \002(\0132\036.bgs.protocol.InvitationParams\022-\n"
    "\nagent_info\030\004 \001(\0132\031.bgs.protocol.Account"
    "Info\022.\n\006target\030\005 \001(\0132\036.bgs.protocol.Invi"
    "tationTarget\"\030\n\026SendInvitationResponse\"\220"
    "\001\n\027UpdateInvitationRequest\022.\n\016agent_iden"
    "tity\030\001 \001(\0132\026.bgs.protocol.Identity\022\025\n\rin"
    "vitation_id\030\002 \002(\006\022.\n\006params\030\003 \002(\0132\036.bgs."
    "protocol.InvitationParams\"\367\001\n\030GenericInv"
    "itationRequest\022(\n\010agent_id\030\001 \001(\0132\026.bgs.p"
    "rotocol.EntityId\022)\n\ttarget_id\030\002 \001(\0132\026.bg"
    "s.protocol.EntityId\022\025\n\rinvitation_id\030\003 \002"
    "(\006\022\024\n\014invitee_name\030\004 \001(\t\022\024\n\014inviter_name"
    "\030\005 \001(\t\022\031\n\rprevious_role\030\006 \003(\rB\002\020\001\022\030\n\014des"
    "ired_role\030\007 \003(\rB\002\020\001\022\016\n\006reason\030\010 \001(\rB\'\n\rb"
    "net.protocolB\024InvitationTypesProtoH\001", 1436);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "invitation_types.proto", &protobuf_RegisterTypes);
  Invitation::default_instance_ = new Invitation();
  InvitationSuggestion::default_instance_ = new InvitationSuggestion();
  InvitationTarget::default_instance_ = new InvitationTarget();
  InvitationParams::default_instance_ = new InvitationParams();
  SendInvitationRequest::default_instance_ = new SendInvitationRequest();
  SendInvitationResponse::default_instance_ = new SendInvitationResponse();
  UpdateInvitationRequest::default_instance_ = new UpdateInvitationRequest();
  GenericInvitationRequest::default_instance_ = new GenericInvitationRequest();
  Invitation::default_instance_->InitAsDefaultInstance();
  InvitationSuggestion::default_instance_->InitAsDefaultInstance();
  InvitationTarget::default_instance_->InitAsDefaultInstance();
  InvitationParams::default_instance_->InitAsDefaultInstance();
  SendInvitationRequest::default_instance_->InitAsDefaultInstance();
  SendInvitationResponse::default_instance_->InitAsDefaultInstance();
  UpdateInvitationRequest::default_instance_->InitAsDefaultInstance();
  GenericInvitationRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_invitation_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_invitation_5ftypes_2eproto {
  StaticDescriptorInitializer_invitation_5ftypes_2eproto() {
    protobuf_AddDesc_invitation_5ftypes_2eproto();
  }
} static_descriptor_initializer_invitation_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Invitation::kIdFieldNumber;
const int Invitation::kInviterIdentityFieldNumber;
const int Invitation::kInviteeIdentityFieldNumber;
const int Invitation::kInviterNameFieldNumber;
const int Invitation::kInviteeNameFieldNumber;
const int Invitation::kInvitationMessageFieldNumber;
const int Invitation::kCreationTimeFieldNumber;
const int Invitation::kExpirationTimeFieldNumber;
#endif  // !_MSC_VER

Invitation::Invitation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Invitation)
}

void Invitation::InitAsDefaultInstance() {
  inviter_identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
  invitee_identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
}

Invitation::Invitation(const Invitation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Invitation)
}

void Invitation::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  inviter_identity_ = NULL;
  invitee_identity_ = NULL;
  inviter_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  invitee_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  invitation_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  creation_time_ = GOOGLE_ULONGLONG(0);
  expiration_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Invitation::~Invitation() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Invitation)
  SharedDtor();
}

void Invitation::SharedDtor() {
  if (inviter_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete inviter_name_;
  }
  if (invitee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete invitee_name_;
  }
  if (invitation_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete invitation_message_;
  }
  if (this != default_instance_) {
    delete inviter_identity_;
    delete invitee_identity_;
  }
}

void Invitation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Invitation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Invitation_descriptor_;
}

const Invitation& Invitation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

Invitation* Invitation::default_instance_ = NULL;

Invitation* Invitation::New() const {
  return new Invitation;
}

void Invitation::Clear() {
  _extensions_.Clear();
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Invitation*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(creation_time_, expiration_time_);
    id_ = GOOGLE_ULONGLONG(0);
    if (has_inviter_identity()) {
      if (inviter_identity_ != NULL) inviter_identity_->::bgs::protocol::Identity::Clear();
    }
    if (has_invitee_identity()) {
      if (invitee_identity_ != NULL) invitee_identity_->::bgs::protocol::Identity::Clear();
    }
    if (has_inviter_name()) {
      if (inviter_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        inviter_name_->clear();
      }
    }
    if (has_invitee_name()) {
      if (invitee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        invitee_name_->clear();
      }
    }
    if (has_invitation_message()) {
      if (invitation_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        invitation_message_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Invitation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Invitation)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed64 id = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_inviter_identity;
        break;
      }

      // required .bgs.protocol.Identity inviter_identity = 2;
      case 2: {
        if (tag == 18) {
         parse_inviter_identity:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_inviter_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_invitee_identity;
        break;
      }

      // required .bgs.protocol.Identity invitee_identity = 3;
      case 3: {
        if (tag == 26) {
         parse_invitee_identity:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_invitee_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_inviter_name;
        break;
      }

      // optional string inviter_name = 4;
      case 4: {
        if (tag == 34) {
         parse_inviter_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_inviter_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->inviter_name().data(), this->inviter_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "inviter_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_invitee_name;
        break;
      }

      // optional string invitee_name = 5;
      case 5: {
        if (tag == 42) {
         parse_invitee_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_invitee_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->invitee_name().data(), this->invitee_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "invitee_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_invitation_message;
        break;
      }

      // optional string invitation_message = 6;
      case 6: {
        if (tag == 50) {
         parse_invitation_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_invitation_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->invitation_message().data(), this->invitation_message().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "invitation_message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_creation_time;
        break;
      }

      // optional uint64 creation_time = 7;
      case 7: {
        if (tag == 56) {
         parse_creation_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &creation_time_)));
          set_has_creation_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_expiration_time;
        break;
      }

      // optional uint64 expiration_time = 8;
      case 8: {
        if (tag == 64) {
         parse_expiration_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &expiration_time_)));
          set_has_expiration_time();
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
        if ((800u <= tag && tag < 80000u)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.Invitation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Invitation)
  return false;
#undef DO_
}

void Invitation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Invitation)
  // required fixed64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->id(), output);
  }

  // required .bgs.protocol.Identity inviter_identity = 2;
  if (has_inviter_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->inviter_identity(), output);
  }

  // required .bgs.protocol.Identity invitee_identity = 3;
  if (has_invitee_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->invitee_identity(), output);
  }

  // optional string inviter_name = 4;
  if (has_inviter_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_name().data(), this->inviter_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->inviter_name(), output);
  }

  // optional string invitee_name = 5;
  if (has_invitee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_name().data(), this->invitee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->invitee_name(), output);
  }

  // optional string invitation_message = 6;
  if (has_invitation_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitation_message().data(), this->invitation_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitation_message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->invitation_message(), output);
  }

  // optional uint64 creation_time = 7;
  if (has_creation_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(7, this->creation_time(), output);
  }

  // optional uint64 expiration_time = 8;
  if (has_expiration_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(8, this->expiration_time(), output);
  }

  // Extension range [100, 10000)
  _extensions_.SerializeWithCachedSizes(
      100, 10000, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Invitation)
}

::google::protobuf::uint8* Invitation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Invitation)
  // required fixed64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->id(), target);
  }

  // required .bgs.protocol.Identity inviter_identity = 2;
  if (has_inviter_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->inviter_identity(), target);
  }

  // required .bgs.protocol.Identity invitee_identity = 3;
  if (has_invitee_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->invitee_identity(), target);
  }

  // optional string inviter_name = 4;
  if (has_inviter_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_name().data(), this->inviter_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->inviter_name(), target);
  }

  // optional string invitee_name = 5;
  if (has_invitee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_name().data(), this->invitee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->invitee_name(), target);
  }

  // optional string invitation_message = 6;
  if (has_invitation_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitation_message().data(), this->invitation_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitation_message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->invitation_message(), target);
  }

  // optional uint64 creation_time = 7;
  if (has_creation_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(7, this->creation_time(), target);
  }

  // optional uint64 expiration_time = 8;
  if (has_expiration_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(8, this->expiration_time(), target);
  }

  // Extension range [100, 10000)
  target = _extensions_.SerializeWithCachedSizesToArray(
      100, 10000, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Invitation)
  return target;
}

int Invitation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed64 id = 1;
    if (has_id()) {
      total_size += 1 + 8;
    }

    // required .bgs.protocol.Identity inviter_identity = 2;
    if (has_inviter_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->inviter_identity());
    }

    // required .bgs.protocol.Identity invitee_identity = 3;
    if (has_invitee_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->invitee_identity());
    }

    // optional string inviter_name = 4;
    if (has_inviter_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->inviter_name());
    }

    // optional string invitee_name = 5;
    if (has_invitee_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->invitee_name());
    }

    // optional string invitation_message = 6;
    if (has_invitation_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->invitation_message());
    }

    // optional uint64 creation_time = 7;
    if (has_creation_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->creation_time());
    }

    // optional uint64 expiration_time = 8;
    if (has_expiration_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->expiration_time());
    }

  }
  total_size += _extensions_.ByteSize();

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

void Invitation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Invitation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Invitation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Invitation::MergeFrom(const Invitation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_inviter_identity()) {
      mutable_inviter_identity()->::bgs::protocol::Identity::MergeFrom(from.inviter_identity());
    }
    if (from.has_invitee_identity()) {
      mutable_invitee_identity()->::bgs::protocol::Identity::MergeFrom(from.invitee_identity());
    }
    if (from.has_inviter_name()) {
      set_inviter_name(from.inviter_name());
    }
    if (from.has_invitee_name()) {
      set_invitee_name(from.invitee_name());
    }
    if (from.has_invitation_message()) {
      set_invitation_message(from.invitation_message());
    }
    if (from.has_creation_time()) {
      set_creation_time(from.creation_time());
    }
    if (from.has_expiration_time()) {
      set_expiration_time(from.expiration_time());
    }
  }
  _extensions_.MergeFrom(from._extensions_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Invitation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Invitation::CopyFrom(const Invitation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Invitation::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  if (has_inviter_identity()) {
    if (!this->inviter_identity().IsInitialized()) return false;
  }
  if (has_invitee_identity()) {
    if (!this->invitee_identity().IsInitialized()) return false;
  }

  if (!_extensions_.IsInitialized()) return false;  return true;
}

void Invitation::Swap(Invitation* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(inviter_identity_, other->inviter_identity_);
    std::swap(invitee_identity_, other->invitee_identity_);
    std::swap(inviter_name_, other->inviter_name_);
    std::swap(invitee_name_, other->invitee_name_);
    std::swap(invitation_message_, other->invitation_message_);
    std::swap(creation_time_, other->creation_time_);
    std::swap(expiration_time_, other->expiration_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata Invitation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Invitation_descriptor_;
  metadata.reflection = Invitation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InvitationSuggestion::kChannelIdFieldNumber;
const int InvitationSuggestion::kSuggesterIdFieldNumber;
const int InvitationSuggestion::kSuggesteeIdFieldNumber;
const int InvitationSuggestion::kSuggesterNameFieldNumber;
const int InvitationSuggestion::kSuggesteeNameFieldNumber;
#endif  // !_MSC_VER

InvitationSuggestion::InvitationSuggestion()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.InvitationSuggestion)
}

void InvitationSuggestion::InitAsDefaultInstance() {
  channel_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  suggester_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  suggestee_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

InvitationSuggestion::InvitationSuggestion(const InvitationSuggestion& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.InvitationSuggestion)
}

void InvitationSuggestion::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  channel_id_ = NULL;
  suggester_id_ = NULL;
  suggestee_id_ = NULL;
  suggester_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  suggestee_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InvitationSuggestion::~InvitationSuggestion() {
  // @@protoc_insertion_point(destructor:bgs.protocol.InvitationSuggestion)
  SharedDtor();
}

void InvitationSuggestion::SharedDtor() {
  if (suggester_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete suggester_name_;
  }
  if (suggestee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete suggestee_name_;
  }
  if (this != default_instance_) {
    delete channel_id_;
    delete suggester_id_;
    delete suggestee_id_;
  }
}

void InvitationSuggestion::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InvitationSuggestion::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InvitationSuggestion_descriptor_;
}

const InvitationSuggestion& InvitationSuggestion::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

InvitationSuggestion* InvitationSuggestion::default_instance_ = NULL;

InvitationSuggestion* InvitationSuggestion::New() const {
  return new InvitationSuggestion;
}

void InvitationSuggestion::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_suggester_id()) {
      if (suggester_id_ != NULL) suggester_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_suggestee_id()) {
      if (suggestee_id_ != NULL) suggestee_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_suggester_name()) {
      if (suggester_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        suggester_name_->clear();
      }
    }
    if (has_suggestee_name()) {
      if (suggestee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        suggestee_name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InvitationSuggestion::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.InvitationSuggestion)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId channel_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_suggester_id;
        break;
      }

      // required .bgs.protocol.EntityId suggester_id = 2;
      case 2: {
        if (tag == 18) {
         parse_suggester_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_suggester_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_suggestee_id;
        break;
      }

      // required .bgs.protocol.EntityId suggestee_id = 3;
      case 3: {
        if (tag == 26) {
         parse_suggestee_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_suggestee_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_suggester_name;
        break;
      }

      // optional string suggester_name = 4;
      case 4: {
        if (tag == 34) {
         parse_suggester_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_suggester_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->suggester_name().data(), this->suggester_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "suggester_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_suggestee_name;
        break;
      }

      // optional string suggestee_name = 5;
      case 5: {
        if (tag == 42) {
         parse_suggestee_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_suggestee_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->suggestee_name().data(), this->suggestee_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "suggestee_name");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.InvitationSuggestion)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.InvitationSuggestion)
  return false;
#undef DO_
}

void InvitationSuggestion::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.InvitationSuggestion)
  // optional .bgs.protocol.EntityId channel_id = 1;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->channel_id(), output);
  }

  // required .bgs.protocol.EntityId suggester_id = 2;
  if (has_suggester_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->suggester_id(), output);
  }

  // required .bgs.protocol.EntityId suggestee_id = 3;
  if (has_suggestee_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->suggestee_id(), output);
  }

  // optional string suggester_name = 4;
  if (has_suggester_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->suggester_name().data(), this->suggester_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "suggester_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->suggester_name(), output);
  }

  // optional string suggestee_name = 5;
  if (has_suggestee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->suggestee_name().data(), this->suggestee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "suggestee_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->suggestee_name(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.InvitationSuggestion)
}

::google::protobuf::uint8* InvitationSuggestion::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.InvitationSuggestion)
  // optional .bgs.protocol.EntityId channel_id = 1;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->channel_id(), target);
  }

  // required .bgs.protocol.EntityId suggester_id = 2;
  if (has_suggester_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->suggester_id(), target);
  }

  // required .bgs.protocol.EntityId suggestee_id = 3;
  if (has_suggestee_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->suggestee_id(), target);
  }

  // optional string suggester_name = 4;
  if (has_suggester_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->suggester_name().data(), this->suggester_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "suggester_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->suggester_name(), target);
  }

  // optional string suggestee_name = 5;
  if (has_suggestee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->suggestee_name().data(), this->suggestee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "suggestee_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->suggestee_name(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.InvitationSuggestion)
  return target;
}

int InvitationSuggestion::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId channel_id = 1;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // required .bgs.protocol.EntityId suggester_id = 2;
    if (has_suggester_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->suggester_id());
    }

    // required .bgs.protocol.EntityId suggestee_id = 3;
    if (has_suggestee_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->suggestee_id());
    }

    // optional string suggester_name = 4;
    if (has_suggester_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->suggester_name());
    }

    // optional string suggestee_name = 5;
    if (has_suggestee_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->suggestee_name());
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

void InvitationSuggestion::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InvitationSuggestion* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InvitationSuggestion*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InvitationSuggestion::MergeFrom(const InvitationSuggestion& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::EntityId::MergeFrom(from.channel_id());
    }
    if (from.has_suggester_id()) {
      mutable_suggester_id()->::bgs::protocol::EntityId::MergeFrom(from.suggester_id());
    }
    if (from.has_suggestee_id()) {
      mutable_suggestee_id()->::bgs::protocol::EntityId::MergeFrom(from.suggestee_id());
    }
    if (from.has_suggester_name()) {
      set_suggester_name(from.suggester_name());
    }
    if (from.has_suggestee_name()) {
      set_suggestee_name(from.suggestee_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InvitationSuggestion::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InvitationSuggestion::CopyFrom(const InvitationSuggestion& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InvitationSuggestion::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;

  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_suggester_id()) {
    if (!this->suggester_id().IsInitialized()) return false;
  }
  if (has_suggestee_id()) {
    if (!this->suggestee_id().IsInitialized()) return false;
  }
  return true;
}

void InvitationSuggestion::Swap(InvitationSuggestion* other) {
  if (other != this) {
    std::swap(channel_id_, other->channel_id_);
    std::swap(suggester_id_, other->suggester_id_);
    std::swap(suggestee_id_, other->suggestee_id_);
    std::swap(suggester_name_, other->suggester_name_);
    std::swap(suggestee_name_, other->suggestee_name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata InvitationSuggestion::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InvitationSuggestion_descriptor_;
  metadata.reflection = InvitationSuggestion_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InvitationTarget::kIdentityFieldNumber;
const int InvitationTarget::kEmailFieldNumber;
const int InvitationTarget::kBattleTagFieldNumber;
#endif  // !_MSC_VER

InvitationTarget::InvitationTarget()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.InvitationTarget)
}

void InvitationTarget::InitAsDefaultInstance() {
  identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
}

InvitationTarget::InvitationTarget(const InvitationTarget& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.InvitationTarget)
}

void InvitationTarget::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  identity_ = NULL;
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InvitationTarget::~InvitationTarget() {
  // @@protoc_insertion_point(destructor:bgs.protocol.InvitationTarget)
  SharedDtor();
}

void InvitationTarget::SharedDtor() {
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete identity_;
  }
}

void InvitationTarget::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InvitationTarget::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InvitationTarget_descriptor_;
}

const InvitationTarget& InvitationTarget::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

InvitationTarget* InvitationTarget::default_instance_ = NULL;

InvitationTarget* InvitationTarget::New() const {
  return new InvitationTarget;
}

void InvitationTarget::Clear() {
  _extensions_.Clear();
  if (_has_bits_[0 / 32] & 7) {
    if (has_identity()) {
      if (identity_ != NULL) identity_->::bgs::protocol::Identity::Clear();
    }
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InvitationTarget::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.InvitationTarget)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.Identity identity = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_email;
        break;
      }

      // optional string email = 2;
      case 2: {
        if (tag == 18) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email().data(), this->email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 3;
      case 3: {
        if (tag == 26) {
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
        if ((800u <= tag && tag < 80000u)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.InvitationTarget)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.InvitationTarget)
  return false;
#undef DO_
}

void InvitationTarget::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.InvitationTarget)
  // optional .bgs.protocol.Identity identity = 1;
  if (has_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->identity(), output);
  }

  // optional string email = 2;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->email(), output);
  }

  // optional string battle_tag = 3;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->battle_tag(), output);
  }

  // Extension range [100, 10000)
  _extensions_.SerializeWithCachedSizes(
      100, 10000, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.InvitationTarget)
}

::google::protobuf::uint8* InvitationTarget::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.InvitationTarget)
  // optional .bgs.protocol.Identity identity = 1;
  if (has_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->identity(), target);
  }

  // optional string email = 2;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->email(), target);
  }

  // optional string battle_tag = 3;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->battle_tag(), target);
  }

  // Extension range [100, 10000)
  target = _extensions_.SerializeWithCachedSizesToArray(
      100, 10000, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.InvitationTarget)
  return target;
}

int InvitationTarget::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.Identity identity = 1;
    if (has_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->identity());
    }

    // optional string email = 2;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

    // optional string battle_tag = 3;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

  }
  total_size += _extensions_.ByteSize();

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

void InvitationTarget::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InvitationTarget* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InvitationTarget*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InvitationTarget::MergeFrom(const InvitationTarget& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_identity()) {
      mutable_identity()->::bgs::protocol::Identity::MergeFrom(from.identity());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
  }
  _extensions_.MergeFrom(from._extensions_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InvitationTarget::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InvitationTarget::CopyFrom(const InvitationTarget& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InvitationTarget::IsInitialized() const {

  if (has_identity()) {
    if (!this->identity().IsInitialized()) return false;
  }

  if (!_extensions_.IsInitialized()) return false;  return true;
}

void InvitationTarget::Swap(InvitationTarget* other) {
  if (other != this) {
    std::swap(identity_, other->identity_);
    std::swap(email_, other->email_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata InvitationTarget::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InvitationTarget_descriptor_;
  metadata.reflection = InvitationTarget_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InvitationParams::kInvitationMessageFieldNumber;
const int InvitationParams::kExpirationTimeFieldNumber;
#endif  // !_MSC_VER

InvitationParams::InvitationParams()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.InvitationParams)
}

void InvitationParams::InitAsDefaultInstance() {
}

InvitationParams::InvitationParams(const InvitationParams& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.InvitationParams)
}

void InvitationParams::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  invitation_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  expiration_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InvitationParams::~InvitationParams() {
  // @@protoc_insertion_point(destructor:bgs.protocol.InvitationParams)
  SharedDtor();
}

void InvitationParams::SharedDtor() {
  if (invitation_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete invitation_message_;
  }
  if (this != default_instance_) {
  }
}

void InvitationParams::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InvitationParams::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InvitationParams_descriptor_;
}

const InvitationParams& InvitationParams::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

InvitationParams* InvitationParams::default_instance_ = NULL;

InvitationParams* InvitationParams::New() const {
  return new InvitationParams;
}

void InvitationParams::Clear() {
  _extensions_.Clear();
  if (_has_bits_[0 / 32] & 3) {
    if (has_invitation_message()) {
      if (invitation_message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        invitation_message_->clear();
      }
    }
    expiration_time_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InvitationParams::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.InvitationParams)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string invitation_message = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_invitation_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->invitation_message().data(), this->invitation_message().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "invitation_message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_expiration_time;
        break;
      }

      // optional uint64 expiration_time = 2 [default = 0];
      case 2: {
        if (tag == 16) {
         parse_expiration_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &expiration_time_)));
          set_has_expiration_time();
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
        if ((800u <= tag && tag < 80000u)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.InvitationParams)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.InvitationParams)
  return false;
#undef DO_
}

void InvitationParams::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.InvitationParams)
  // optional string invitation_message = 1;
  if (has_invitation_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitation_message().data(), this->invitation_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitation_message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->invitation_message(), output);
  }

  // optional uint64 expiration_time = 2 [default = 0];
  if (has_expiration_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->expiration_time(), output);
  }

  // Extension range [100, 10000)
  _extensions_.SerializeWithCachedSizes(
      100, 10000, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.InvitationParams)
}

::google::protobuf::uint8* InvitationParams::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.InvitationParams)
  // optional string invitation_message = 1;
  if (has_invitation_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitation_message().data(), this->invitation_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitation_message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->invitation_message(), target);
  }

  // optional uint64 expiration_time = 2 [default = 0];
  if (has_expiration_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->expiration_time(), target);
  }

  // Extension range [100, 10000)
  target = _extensions_.SerializeWithCachedSizesToArray(
      100, 10000, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.InvitationParams)
  return target;
}

int InvitationParams::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string invitation_message = 1;
    if (has_invitation_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->invitation_message());
    }

    // optional uint64 expiration_time = 2 [default = 0];
    if (has_expiration_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->expiration_time());
    }

  }
  total_size += _extensions_.ByteSize();

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

void InvitationParams::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InvitationParams* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InvitationParams*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InvitationParams::MergeFrom(const InvitationParams& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_invitation_message()) {
      set_invitation_message(from.invitation_message());
    }
    if (from.has_expiration_time()) {
      set_expiration_time(from.expiration_time());
    }
  }
  _extensions_.MergeFrom(from._extensions_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InvitationParams::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InvitationParams::CopyFrom(const InvitationParams& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InvitationParams::IsInitialized() const {


  if (!_extensions_.IsInitialized()) return false;  return true;
}

void InvitationParams::Swap(InvitationParams* other) {
  if (other != this) {
    std::swap(invitation_message_, other->invitation_message_);
    std::swap(expiration_time_, other->expiration_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata InvitationParams::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InvitationParams_descriptor_;
  metadata.reflection = InvitationParams_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendInvitationRequest::kAgentIdentityFieldNumber;
const int SendInvitationRequest::kTargetIdFieldNumber;
const int SendInvitationRequest::kParamsFieldNumber;
const int SendInvitationRequest::kAgentInfoFieldNumber;
const int SendInvitationRequest::kTargetFieldNumber;
#endif  // !_MSC_VER

SendInvitationRequest::SendInvitationRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.SendInvitationRequest)
}

void SendInvitationRequest::InitAsDefaultInstance() {
  agent_identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  params_ = const_cast< ::bgs::protocol::InvitationParams*>(&::bgs::protocol::InvitationParams::default_instance());
  agent_info_ = const_cast< ::bgs::protocol::AccountInfo*>(&::bgs::protocol::AccountInfo::default_instance());
  target_ = const_cast< ::bgs::protocol::InvitationTarget*>(&::bgs::protocol::InvitationTarget::default_instance());
}

SendInvitationRequest::SendInvitationRequest(const SendInvitationRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.SendInvitationRequest)
}

void SendInvitationRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_identity_ = NULL;
  target_id_ = NULL;
  params_ = NULL;
  agent_info_ = NULL;
  target_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendInvitationRequest::~SendInvitationRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.SendInvitationRequest)
  SharedDtor();
}

void SendInvitationRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_identity_;
    delete target_id_;
    delete params_;
    delete agent_info_;
    delete target_;
  }
}

void SendInvitationRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendInvitationRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendInvitationRequest_descriptor_;
}

const SendInvitationRequest& SendInvitationRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

SendInvitationRequest* SendInvitationRequest::default_instance_ = NULL;

SendInvitationRequest* SendInvitationRequest::New() const {
  return new SendInvitationRequest;
}

void SendInvitationRequest::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_agent_identity()) {
      if (agent_identity_ != NULL) agent_identity_->::bgs::protocol::Identity::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_params()) {
      if (params_ != NULL) params_->::bgs::protocol::InvitationParams::Clear();
    }
    if (has_agent_info()) {
      if (agent_info_ != NULL) agent_info_->::bgs::protocol::AccountInfo::Clear();
    }
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::InvitationTarget::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendInvitationRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.SendInvitationRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.Identity agent_identity = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_target_id;
        break;
      }

      // required .bgs.protocol.EntityId target_id = 2 [deprecated = true];
      case 2: {
        if (tag == 18) {
         parse_target_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_params;
        break;
      }

      // required .bgs.protocol.InvitationParams params = 3;
      case 3: {
        if (tag == 26) {
         parse_params:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_params()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_agent_info;
        break;
      }

      // optional .bgs.protocol.AccountInfo agent_info = 4;
      case 4: {
        if (tag == 34) {
         parse_agent_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_target;
        break;
      }

      // optional .bgs.protocol.InvitationTarget target = 5;
      case 5: {
        if (tag == 42) {
         parse_target:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.SendInvitationRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.SendInvitationRequest)
  return false;
#undef DO_
}

void SendInvitationRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.SendInvitationRequest)
  // optional .bgs.protocol.Identity agent_identity = 1;
  if (has_agent_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_identity(), output);
  }

  // required .bgs.protocol.EntityId target_id = 2 [deprecated = true];
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->target_id(), output);
  }

  // required .bgs.protocol.InvitationParams params = 3;
  if (has_params()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->params(), output);
  }

  // optional .bgs.protocol.AccountInfo agent_info = 4;
  if (has_agent_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->agent_info(), output);
  }

  // optional .bgs.protocol.InvitationTarget target = 5;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->target(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.SendInvitationRequest)
}

::google::protobuf::uint8* SendInvitationRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.SendInvitationRequest)
  // optional .bgs.protocol.Identity agent_identity = 1;
  if (has_agent_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_identity(), target);
  }

  // required .bgs.protocol.EntityId target_id = 2 [deprecated = true];
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->target_id(), target);
  }

  // required .bgs.protocol.InvitationParams params = 3;
  if (has_params()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->params(), target);
  }

  // optional .bgs.protocol.AccountInfo agent_info = 4;
  if (has_agent_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->agent_info(), target);
  }

  // optional .bgs.protocol.InvitationTarget target = 5;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->target(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.SendInvitationRequest)
  return target;
}

int SendInvitationRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.Identity agent_identity = 1;
    if (has_agent_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_identity());
    }

    // required .bgs.protocol.EntityId target_id = 2 [deprecated = true];
    if (has_target_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_id());
    }

    // required .bgs.protocol.InvitationParams params = 3;
    if (has_params()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->params());
    }

    // optional .bgs.protocol.AccountInfo agent_info = 4;
    if (has_agent_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_info());
    }

    // optional .bgs.protocol.InvitationTarget target = 5;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
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

void SendInvitationRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendInvitationRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendInvitationRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendInvitationRequest::MergeFrom(const SendInvitationRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_identity()) {
      mutable_agent_identity()->::bgs::protocol::Identity::MergeFrom(from.agent_identity());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_params()) {
      mutable_params()->::bgs::protocol::InvitationParams::MergeFrom(from.params());
    }
    if (from.has_agent_info()) {
      mutable_agent_info()->::bgs::protocol::AccountInfo::MergeFrom(from.agent_info());
    }
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::InvitationTarget::MergeFrom(from.target());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendInvitationRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendInvitationRequest::CopyFrom(const SendInvitationRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendInvitationRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;

  if (has_agent_identity()) {
    if (!this->agent_identity().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  if (has_params()) {
    if (!this->params().IsInitialized()) return false;
  }
  if (has_agent_info()) {
    if (!this->agent_info().IsInitialized()) return false;
  }
  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void SendInvitationRequest::Swap(SendInvitationRequest* other) {
  if (other != this) {
    std::swap(agent_identity_, other->agent_identity_);
    std::swap(target_id_, other->target_id_);
    std::swap(params_, other->params_);
    std::swap(agent_info_, other->agent_info_);
    std::swap(target_, other->target_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendInvitationRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendInvitationRequest_descriptor_;
  metadata.reflection = SendInvitationRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

SendInvitationResponse::SendInvitationResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.SendInvitationResponse)
}

void SendInvitationResponse::InitAsDefaultInstance() {
}

SendInvitationResponse::SendInvitationResponse(const SendInvitationResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.SendInvitationResponse)
}

void SendInvitationResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendInvitationResponse::~SendInvitationResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.SendInvitationResponse)
  SharedDtor();
}

void SendInvitationResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SendInvitationResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendInvitationResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendInvitationResponse_descriptor_;
}

const SendInvitationResponse& SendInvitationResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

SendInvitationResponse* SendInvitationResponse::default_instance_ = NULL;

SendInvitationResponse* SendInvitationResponse::New() const {
  return new SendInvitationResponse;
}

void SendInvitationResponse::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendInvitationResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.SendInvitationResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.SendInvitationResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.SendInvitationResponse)
  return false;
#undef DO_
}

void SendInvitationResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.SendInvitationResponse)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.SendInvitationResponse)
}

::google::protobuf::uint8* SendInvitationResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.SendInvitationResponse)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.SendInvitationResponse)
  return target;
}

int SendInvitationResponse::ByteSize() const {
  int total_size = 0;

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

void SendInvitationResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendInvitationResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendInvitationResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendInvitationResponse::MergeFrom(const SendInvitationResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendInvitationResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendInvitationResponse::CopyFrom(const SendInvitationResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendInvitationResponse::IsInitialized() const {

  return true;
}

void SendInvitationResponse::Swap(SendInvitationResponse* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendInvitationResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendInvitationResponse_descriptor_;
  metadata.reflection = SendInvitationResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateInvitationRequest::kAgentIdentityFieldNumber;
const int UpdateInvitationRequest::kInvitationIdFieldNumber;
const int UpdateInvitationRequest::kParamsFieldNumber;
#endif  // !_MSC_VER

UpdateInvitationRequest::UpdateInvitationRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.UpdateInvitationRequest)
}

void UpdateInvitationRequest::InitAsDefaultInstance() {
  agent_identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
  params_ = const_cast< ::bgs::protocol::InvitationParams*>(&::bgs::protocol::InvitationParams::default_instance());
}

UpdateInvitationRequest::UpdateInvitationRequest(const UpdateInvitationRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.UpdateInvitationRequest)
}

void UpdateInvitationRequest::SharedCtor() {
  _cached_size_ = 0;
  agent_identity_ = NULL;
  invitation_id_ = GOOGLE_ULONGLONG(0);
  params_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateInvitationRequest::~UpdateInvitationRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.UpdateInvitationRequest)
  SharedDtor();
}

void UpdateInvitationRequest::SharedDtor() {
  if (this != default_instance_) {
    delete agent_identity_;
    delete params_;
  }
}

void UpdateInvitationRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateInvitationRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateInvitationRequest_descriptor_;
}

const UpdateInvitationRequest& UpdateInvitationRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

UpdateInvitationRequest* UpdateInvitationRequest::default_instance_ = NULL;

UpdateInvitationRequest* UpdateInvitationRequest::New() const {
  return new UpdateInvitationRequest;
}

void UpdateInvitationRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_agent_identity()) {
      if (agent_identity_ != NULL) agent_identity_->::bgs::protocol::Identity::Clear();
    }
    invitation_id_ = GOOGLE_ULONGLONG(0);
    if (has_params()) {
      if (params_ != NULL) params_->::bgs::protocol::InvitationParams::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateInvitationRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.UpdateInvitationRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.Identity agent_identity = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_agent_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_invitation_id;
        break;
      }

      // required fixed64 invitation_id = 2;
      case 2: {
        if (tag == 17) {
         parse_invitation_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &invitation_id_)));
          set_has_invitation_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_params;
        break;
      }

      // required .bgs.protocol.InvitationParams params = 3;
      case 3: {
        if (tag == 26) {
         parse_params:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_params()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.UpdateInvitationRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.UpdateInvitationRequest)
  return false;
#undef DO_
}

void UpdateInvitationRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.UpdateInvitationRequest)
  // optional .bgs.protocol.Identity agent_identity = 1;
  if (has_agent_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->agent_identity(), output);
  }

  // required fixed64 invitation_id = 2;
  if (has_invitation_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(2, this->invitation_id(), output);
  }

  // required .bgs.protocol.InvitationParams params = 3;
  if (has_params()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->params(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.UpdateInvitationRequest)
}

::google::protobuf::uint8* UpdateInvitationRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.UpdateInvitationRequest)
  // optional .bgs.protocol.Identity agent_identity = 1;
  if (has_agent_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->agent_identity(), target);
  }

  // required fixed64 invitation_id = 2;
  if (has_invitation_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(2, this->invitation_id(), target);
  }

  // required .bgs.protocol.InvitationParams params = 3;
  if (has_params()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->params(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.UpdateInvitationRequest)
  return target;
}

int UpdateInvitationRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.Identity agent_identity = 1;
    if (has_agent_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->agent_identity());
    }

    // required fixed64 invitation_id = 2;
    if (has_invitation_id()) {
      total_size += 1 + 8;
    }

    // required .bgs.protocol.InvitationParams params = 3;
    if (has_params()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->params());
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

void UpdateInvitationRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateInvitationRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateInvitationRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateInvitationRequest::MergeFrom(const UpdateInvitationRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_identity()) {
      mutable_agent_identity()->::bgs::protocol::Identity::MergeFrom(from.agent_identity());
    }
    if (from.has_invitation_id()) {
      set_invitation_id(from.invitation_id());
    }
    if (from.has_params()) {
      mutable_params()->::bgs::protocol::InvitationParams::MergeFrom(from.params());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateInvitationRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateInvitationRequest::CopyFrom(const UpdateInvitationRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateInvitationRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;

  if (has_agent_identity()) {
    if (!this->agent_identity().IsInitialized()) return false;
  }
  if (has_params()) {
    if (!this->params().IsInitialized()) return false;
  }
  return true;
}

void UpdateInvitationRequest::Swap(UpdateInvitationRequest* other) {
  if (other != this) {
    std::swap(agent_identity_, other->agent_identity_);
    std::swap(invitation_id_, other->invitation_id_);
    std::swap(params_, other->params_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateInvitationRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateInvitationRequest_descriptor_;
  metadata.reflection = UpdateInvitationRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenericInvitationRequest::kAgentIdFieldNumber;
const int GenericInvitationRequest::kTargetIdFieldNumber;
const int GenericInvitationRequest::kInvitationIdFieldNumber;
const int GenericInvitationRequest::kInviteeNameFieldNumber;
const int GenericInvitationRequest::kInviterNameFieldNumber;
const int GenericInvitationRequest::kPreviousRoleFieldNumber;
const int GenericInvitationRequest::kDesiredRoleFieldNumber;
const int GenericInvitationRequest::kReasonFieldNumber;
#endif  // !_MSC_VER

GenericInvitationRequest::GenericInvitationRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.GenericInvitationRequest)
}

void GenericInvitationRequest::InitAsDefaultInstance() {
  agent_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GenericInvitationRequest::GenericInvitationRequest(const GenericInvitationRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.GenericInvitationRequest)
}

void GenericInvitationRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  agent_id_ = NULL;
  target_id_ = NULL;
  invitation_id_ = GOOGLE_ULONGLONG(0);
  invitee_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  inviter_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _previous_role_cached_byte_size_ = 0;
  _desired_role_cached_byte_size_ = 0;
  reason_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenericInvitationRequest::~GenericInvitationRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.GenericInvitationRequest)
  SharedDtor();
}

void GenericInvitationRequest::SharedDtor() {
  if (invitee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete invitee_name_;
  }
  if (inviter_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete inviter_name_;
  }
  if (this != default_instance_) {
    delete agent_id_;
    delete target_id_;
  }
}

void GenericInvitationRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenericInvitationRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenericInvitationRequest_descriptor_;
}

const GenericInvitationRequest& GenericInvitationRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_invitation_5ftypes_2eproto();
  return *default_instance_;
}

GenericInvitationRequest* GenericInvitationRequest::default_instance_ = NULL;

GenericInvitationRequest* GenericInvitationRequest::New() const {
  return new GenericInvitationRequest;
}

void GenericInvitationRequest::Clear() {
  if (_has_bits_[0 / 32] & 159) {
    if (has_agent_id()) {
      if (agent_id_ != NULL) agent_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
    invitation_id_ = GOOGLE_ULONGLONG(0);
    if (has_invitee_name()) {
      if (invitee_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        invitee_name_->clear();
      }
    }
    if (has_inviter_name()) {
      if (inviter_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        inviter_name_->clear();
      }
    }
    reason_ = 0u;
  }
  previous_role_.Clear();
  desired_role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenericInvitationRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.GenericInvitationRequest)
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
        if (input->ExpectTag(25)) goto parse_invitation_id;
        break;
      }

      // required fixed64 invitation_id = 3;
      case 3: {
        if (tag == 25) {
         parse_invitation_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &invitation_id_)));
          set_has_invitation_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_invitee_name;
        break;
      }

      // optional string invitee_name = 4;
      case 4: {
        if (tag == 34) {
         parse_invitee_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_invitee_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->invitee_name().data(), this->invitee_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "invitee_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_inviter_name;
        break;
      }

      // optional string inviter_name = 5;
      case 5: {
        if (tag == 42) {
         parse_inviter_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_inviter_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->inviter_name().data(), this->inviter_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "inviter_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_previous_role;
        break;
      }

      // repeated uint32 previous_role = 6 [packed = true];
      case 6: {
        if (tag == 50) {
         parse_previous_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_previous_role())));
        } else if (tag == 48) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 50, input, this->mutable_previous_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_desired_role;
        break;
      }

      // repeated uint32 desired_role = 7 [packed = true];
      case 7: {
        if (tag == 58) {
         parse_desired_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_desired_role())));
        } else if (tag == 56) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 58, input, this->mutable_desired_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 8;
      case 8: {
        if (tag == 64) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.GenericInvitationRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.GenericInvitationRequest)
  return false;
#undef DO_
}

void GenericInvitationRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.GenericInvitationRequest)
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

  // required fixed64 invitation_id = 3;
  if (has_invitation_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(3, this->invitation_id(), output);
  }

  // optional string invitee_name = 4;
  if (has_invitee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_name().data(), this->invitee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->invitee_name(), output);
  }

  // optional string inviter_name = 5;
  if (has_inviter_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_name().data(), this->inviter_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->inviter_name(), output);
  }

  // repeated uint32 previous_role = 6 [packed = true];
  if (this->previous_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(6, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_previous_role_cached_byte_size_);
  }
  for (int i = 0; i < this->previous_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->previous_role(i), output);
  }

  // repeated uint32 desired_role = 7 [packed = true];
  if (this->desired_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(7, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_desired_role_cached_byte_size_);
  }
  for (int i = 0; i < this->desired_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->desired_role(i), output);
  }

  // optional uint32 reason = 8;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->reason(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.GenericInvitationRequest)
}

::google::protobuf::uint8* GenericInvitationRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.GenericInvitationRequest)
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

  // required fixed64 invitation_id = 3;
  if (has_invitation_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(3, this->invitation_id(), target);
  }

  // optional string invitee_name = 4;
  if (has_invitee_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_name().data(), this->invitee_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->invitee_name(), target);
  }

  // optional string inviter_name = 5;
  if (has_inviter_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_name().data(), this->inviter_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->inviter_name(), target);
  }

  // repeated uint32 previous_role = 6 [packed = true];
  if (this->previous_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      6,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _previous_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->previous_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->previous_role(i), target);
  }

  // repeated uint32 desired_role = 7 [packed = true];
  if (this->desired_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      7,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _desired_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->desired_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->desired_role(i), target);
  }

  // optional uint32 reason = 8;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->reason(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.GenericInvitationRequest)
  return target;
}

int GenericInvitationRequest::ByteSize() const {
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

    // required fixed64 invitation_id = 3;
    if (has_invitation_id()) {
      total_size += 1 + 8;
    }

    // optional string invitee_name = 4;
    if (has_invitee_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->invitee_name());
    }

    // optional string inviter_name = 5;
    if (has_inviter_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->inviter_name());
    }

    // optional uint32 reason = 8;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
    }

  }
  // repeated uint32 previous_role = 6 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->previous_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->previous_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _previous_role_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated uint32 desired_role = 7 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->desired_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->desired_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _desired_role_cached_byte_size_ = data_size;
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

void GenericInvitationRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenericInvitationRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenericInvitationRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenericInvitationRequest::MergeFrom(const GenericInvitationRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  previous_role_.MergeFrom(from.previous_role_);
  desired_role_.MergeFrom(from.desired_role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_agent_id()) {
      mutable_agent_id()->::bgs::protocol::EntityId::MergeFrom(from.agent_id());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_invitation_id()) {
      set_invitation_id(from.invitation_id());
    }
    if (from.has_invitee_name()) {
      set_invitee_name(from.invitee_name());
    }
    if (from.has_inviter_name()) {
      set_inviter_name(from.inviter_name());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenericInvitationRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenericInvitationRequest::CopyFrom(const GenericInvitationRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenericInvitationRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000004) != 0x00000004) return false;

  if (has_agent_id()) {
    if (!this->agent_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void GenericInvitationRequest::Swap(GenericInvitationRequest* other) {
  if (other != this) {
    std::swap(agent_id_, other->agent_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(invitation_id_, other->invitation_id_);
    std::swap(invitee_name_, other->invitee_name_);
    std::swap(inviter_name_, other->inviter_name_);
    previous_role_.Swap(&other->previous_role_);
    desired_role_.Swap(&other->desired_role_);
    std::swap(reason_, other->reason_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenericInvitationRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenericInvitationRequest_descriptor_;
  metadata.reflection = GenericInvitationRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
