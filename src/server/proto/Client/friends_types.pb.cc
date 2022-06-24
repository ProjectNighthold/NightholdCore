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
#include "friends_types.pb.h"

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
namespace friends {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* Friend_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Friend_reflection_ = NULL;
const ::google::protobuf::Descriptor* FriendOfFriend_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendOfFriend_reflection_ = NULL;
const ::google::protobuf::Descriptor* FriendInvitation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendInvitation_reflection_ = NULL;
const ::google::protobuf::Descriptor* FriendInvitationParams_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendInvitationParams_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscribeResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscribeResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_friends_5ftypes_2eproto() {
  protobuf_AddDesc_friends_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "friends_types.proto");
  GOOGLE_CHECK(file != NULL);
  Friend_descriptor_ = file->message_type(0);
  static const int Friend_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, privileges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, attributes_epoch_),
  };
  Friend_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Friend_descriptor_,
      Friend::default_instance_,
      Friend_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Friend, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Friend));
  FriendOfFriend_descriptor_ = file->message_type(1);
  static const int FriendOfFriend_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, privileges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, attributes_epoch_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, battle_tag_),
  };
  FriendOfFriend_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendOfFriend_descriptor_,
      FriendOfFriend::default_instance_,
      FriendOfFriend_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendOfFriend, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendOfFriend));
  FriendInvitation_descriptor_ = file->message_type(2);
  static const int FriendInvitation_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitation, first_received_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitation, role_),
  };
  FriendInvitation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendInvitation_descriptor_,
      FriendInvitation::default_instance_,
      FriendInvitation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendInvitation));
  FriendInvitationParams_descriptor_ = file->message_type(3);
  static const int FriendInvitationParams_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, target_email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, target_battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, inviter_battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, inviter_full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, invitee_display_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, previous_role_deprecated_),
  };
  FriendInvitationParams_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendInvitationParams_descriptor_,
      FriendInvitationParams::default_instance_,
      FriendInvitationParams_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendInvitationParams, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendInvitationParams));
  SubscribeResponse_descriptor_ = file->message_type(4);
  static const int SubscribeResponse_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, max_friends_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, max_received_invitations_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, max_sent_invitations_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, friends_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, sent_invitations_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscribeResponse, received_invitations_),
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
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_friends_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Friend_descriptor_, &Friend::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendOfFriend_descriptor_, &FriendOfFriend::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendInvitation_descriptor_, &FriendInvitation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendInvitationParams_descriptor_, &FriendInvitationParams::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscribeResponse_descriptor_, &SubscribeResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_friends_5ftypes_2eproto() {
  delete Friend::default_instance_;
  delete Friend_reflection_;
  delete FriendOfFriend::default_instance_;
  delete FriendOfFriend_reflection_;
  delete FriendInvitation::default_instance_;
  delete FriendInvitation_reflection_;
  delete FriendInvitationParams::default_instance_;
  delete FriendInvitationParams_reflection_;
  delete SubscribeResponse::default_instance_;
  delete SubscribeResponse_reflection_;
}

void protobuf_AddDesc_friends_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_invitation_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_role_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023friends_types.proto\022\027bgs.protocol.frie"
    "nds.v1\032\025attribute_types.proto\032\022entity_ty"
    "pes.proto\032\026invitation_types.proto\032\020role_"
    "types.proto\"\243\001\n\006Friend\022*\n\naccount_id\030\001 \002"
    "(\0132\026.bgs.protocol.EntityId\022*\n\tattribute\030"
    "\002 \003(\0132\027.bgs.protocol.Attribute\022\020\n\004role\030\003"
    " \003(\rB\002\020\001\022\025\n\nprivileges\030\004 \001(\004:\0010\022\030\n\020attri"
    "butes_epoch\030\005 \001(\004\"\322\001\n\016FriendOfFriend\022*\n\n"
    "account_id\030\001 \001(\0132\026.bgs.protocol.EntityId"
    "\022*\n\tattribute\030\002 \003(\0132\027.bgs.protocol.Attri"
    "bute\022\020\n\004role\030\003 \003(\rB\002\020\001\022\025\n\nprivileges\030\004 \001"
    "(\004:\0010\022\030\n\020attributes_epoch\030\005 \001(\004\022\021\n\tfull_"
    "name\030\006 \001(\t\022\022\n\nbattle_tag\030\007 \001(\t\"\243\001\n\020Frien"
    "dInvitation\022\035\n\016first_received\030\001 \001(\010:\005fal"
    "se\022\020\n\004role\030\002 \003(\rB\002\020\0012^\n\021friend_invitatio"
    "n\022\030.bgs.protocol.Invitation\030g \001(\0132).bgs."
    "protocol.friends.v1.FriendInvitation\"\300\002\n"
    "\026FriendInvitationParams\022\024\n\014target_email\030"
    "\001 \001(\t\022\031\n\021target_battle_tag\030\002 \001(\t\022\032\n\022invi"
    "ter_battle_tag\030\003 \001(\t\022\031\n\021inviter_full_nam"
    "e\030\004 \001(\t\022\034\n\024invitee_display_name\030\005 \001(\t\022\020\n"
    "\004role\030\006 \003(\rB\002\020\001\022&\n\030previous_role_depreca"
    "ted\030\007 \003(\rB\004\020\001\030\0012f\n\rfriend_params\022\036.bgs.p"
    "rotocol.InvitationParams\030g \001(\0132/.bgs.pro"
    "tocol.friends.v1.FriendInvitationParams\""
    "\250\002\n\021SubscribeResponse\022\023\n\013max_friends\030\001 \001"
    "(\r\022 \n\030max_received_invitations\030\002 \001(\r\022\034\n\024"
    "max_sent_invitations\030\003 \001(\r\022 \n\004role\030\004 \003(\013"
    "2\022.bgs.protocol.Role\0220\n\007friends\030\005 \003(\0132\037."
    "bgs.protocol.friends.v1.Friend\0222\n\020sent_i"
    "nvitations\030\006 \003(\0132\030.bgs.protocol.Invitati"
    "on\0226\n\024received_invitations\030\007 \003(\0132\030.bgs.p"
    "rotocol.InvitationB/\n\030bnet.protocol.frie"
    "nds.v1B\021FriendsTypesProtoH\001", 1347);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "friends_types.proto", &protobuf_RegisterTypes);
  Friend::default_instance_ = new Friend();
  FriendOfFriend::default_instance_ = new FriendOfFriend();
  FriendInvitation::default_instance_ = new FriendInvitation();
  FriendInvitationParams::default_instance_ = new FriendInvitationParams();
  SubscribeResponse::default_instance_ = new SubscribeResponse();
  Friend::default_instance_->InitAsDefaultInstance();
  FriendOfFriend::default_instance_->InitAsDefaultInstance();
  FriendInvitation::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
    &::bgs::protocol::Invitation::default_instance(),
    103, 11, false, false,
    &::bgs::protocol::friends::v1::FriendInvitation::default_instance());
  FriendInvitationParams::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
    &::bgs::protocol::InvitationParams::default_instance(),
    103, 11, false, false,
    &::bgs::protocol::friends::v1::FriendInvitationParams::default_instance());
  SubscribeResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_friends_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_friends_5ftypes_2eproto {
  StaticDescriptorInitializer_friends_5ftypes_2eproto() {
    protobuf_AddDesc_friends_5ftypes_2eproto();
  }
} static_descriptor_initializer_friends_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Friend::kAccountIdFieldNumber;
const int Friend::kAttributeFieldNumber;
const int Friend::kRoleFieldNumber;
const int Friend::kPrivilegesFieldNumber;
const int Friend::kAttributesEpochFieldNumber;
#endif  // !_MSC_VER

Friend::Friend()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.Friend)
}

void Friend::InitAsDefaultInstance() {
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

Friend::Friend(const Friend& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.Friend)
}

void Friend::SharedCtor() {
  _cached_size_ = 0;
  account_id_ = NULL;
  _role_cached_byte_size_ = 0;
  privileges_ = GOOGLE_ULONGLONG(0);
  attributes_epoch_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Friend::~Friend() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.Friend)
  SharedDtor();
}

void Friend::SharedDtor() {
  if (this != default_instance_) {
    delete account_id_;
  }
}

void Friend::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Friend::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Friend_descriptor_;
}

const Friend& Friend::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5ftypes_2eproto();
  return *default_instance_;
}

Friend* Friend::default_instance_ = NULL;

Friend* Friend::New() const {
  return new Friend;
}

void Friend::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Friend*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 25) {
    ZR_(privileges_, attributes_epoch_);
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  attribute_.Clear();
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Friend::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.Friend)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId account_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 2;
      case 2: {
        if (tag == 18) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_attribute;
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
        if (input->ExpectTag(32)) goto parse_privileges;
        break;
      }

      // optional uint64 privileges = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_privileges:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &privileges_)));
          set_has_privileges();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_attributes_epoch;
        break;
      }

      // optional uint64 attributes_epoch = 5;
      case 5: {
        if (tag == 40) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.Friend)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.Friend)
  return false;
#undef DO_
}

void Friend::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.Friend)
  // required .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_id(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->attribute(i), output);
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

  // optional uint64 privileges = 4 [default = 0];
  if (has_privileges()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->privileges(), output);
  }

  // optional uint64 attributes_epoch = 5;
  if (has_attributes_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->attributes_epoch(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.Friend)
}

::google::protobuf::uint8* Friend::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.Friend)
  // required .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_id(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->attribute(i), target);
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

  // optional uint64 privileges = 4 [default = 0];
  if (has_privileges()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->privileges(), target);
  }

  // optional uint64 attributes_epoch = 5;
  if (has_attributes_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->attributes_epoch(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.Friend)
  return target;
}

int Friend::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId account_id = 1;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional uint64 privileges = 4 [default = 0];
    if (has_privileges()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->privileges());
    }

    // optional uint64 attributes_epoch = 5;
    if (has_attributes_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->attributes_epoch());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 2;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
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

void Friend::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Friend* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Friend*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Friend::MergeFrom(const Friend& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  role_.MergeFrom(from.role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_privileges()) {
      set_privileges(from.privileges());
    }
    if (from.has_attributes_epoch()) {
      set_attributes_epoch(from.attributes_epoch());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Friend::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Friend::CopyFrom(const Friend& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Friend::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void Friend::Swap(Friend* other) {
  if (other != this) {
    std::swap(account_id_, other->account_id_);
    attribute_.Swap(&other->attribute_);
    role_.Swap(&other->role_);
    std::swap(privileges_, other->privileges_);
    std::swap(attributes_epoch_, other->attributes_epoch_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Friend::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Friend_descriptor_;
  metadata.reflection = Friend_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FriendOfFriend::kAccountIdFieldNumber;
const int FriendOfFriend::kAttributeFieldNumber;
const int FriendOfFriend::kRoleFieldNumber;
const int FriendOfFriend::kPrivilegesFieldNumber;
const int FriendOfFriend::kAttributesEpochFieldNumber;
const int FriendOfFriend::kFullNameFieldNumber;
const int FriendOfFriend::kBattleTagFieldNumber;
#endif  // !_MSC_VER

FriendOfFriend::FriendOfFriend()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.FriendOfFriend)
}

void FriendOfFriend::InitAsDefaultInstance() {
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

FriendOfFriend::FriendOfFriend(const FriendOfFriend& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.FriendOfFriend)
}

void FriendOfFriend::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  account_id_ = NULL;
  _role_cached_byte_size_ = 0;
  privileges_ = GOOGLE_ULONGLONG(0);
  attributes_epoch_ = GOOGLE_ULONGLONG(0);
  full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendOfFriend::~FriendOfFriend() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.FriendOfFriend)
  SharedDtor();
}

void FriendOfFriend::SharedDtor() {
  if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete full_name_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete account_id_;
  }
}

void FriendOfFriend::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendOfFriend::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendOfFriend_descriptor_;
}

const FriendOfFriend& FriendOfFriend::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5ftypes_2eproto();
  return *default_instance_;
}

FriendOfFriend* FriendOfFriend::default_instance_ = NULL;

FriendOfFriend* FriendOfFriend::New() const {
  return new FriendOfFriend;
}

void FriendOfFriend::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<FriendOfFriend*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 121) {
    ZR_(privileges_, attributes_epoch_);
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_full_name()) {
      if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        full_name_->clear();
      }
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  attribute_.Clear();
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendOfFriend::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.FriendOfFriend)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId account_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 2;
      case 2: {
        if (tag == 18) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_attribute;
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
        if (input->ExpectTag(32)) goto parse_privileges;
        break;
      }

      // optional uint64 privileges = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_privileges:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &privileges_)));
          set_has_privileges();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_attributes_epoch;
        break;
      }

      // optional uint64 attributes_epoch = 5;
      case 5: {
        if (tag == 40) {
         parse_attributes_epoch:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &attributes_epoch_)));
          set_has_attributes_epoch();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_full_name;
        break;
      }

      // optional string full_name = 6;
      case 6: {
        if (tag == 50) {
         parse_full_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_full_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->full_name().data(), this->full_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "full_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 7;
      case 7: {
        if (tag == 58) {
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.FriendOfFriend)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.FriendOfFriend)
  return false;
#undef DO_
}

void FriendOfFriend::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.FriendOfFriend)
  // optional .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_id(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->attribute(i), output);
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

  // optional uint64 privileges = 4 [default = 0];
  if (has_privileges()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->privileges(), output);
  }

  // optional uint64 attributes_epoch = 5;
  if (has_attributes_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->attributes_epoch(), output);
  }

  // optional string full_name = 6;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->full_name(), output);
  }

  // optional string battle_tag = 7;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->battle_tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.FriendOfFriend)
}

::google::protobuf::uint8* FriendOfFriend::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.FriendOfFriend)
  // optional .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_id(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->attribute(i), target);
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

  // optional uint64 privileges = 4 [default = 0];
  if (has_privileges()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->privileges(), target);
  }

  // optional uint64 attributes_epoch = 5;
  if (has_attributes_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->attributes_epoch(), target);
  }

  // optional string full_name = 6;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->full_name(), target);
  }

  // optional string battle_tag = 7;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->battle_tag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.FriendOfFriend)
  return target;
}

int FriendOfFriend::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId account_id = 1;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional uint64 privileges = 4 [default = 0];
    if (has_privileges()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->privileges());
    }

    // optional uint64 attributes_epoch = 5;
    if (has_attributes_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->attributes_epoch());
    }

    // optional string full_name = 6;
    if (has_full_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->full_name());
    }

    // optional string battle_tag = 7;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 2;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
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

void FriendOfFriend::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendOfFriend* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendOfFriend*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendOfFriend::MergeFrom(const FriendOfFriend& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  role_.MergeFrom(from.role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_privileges()) {
      set_privileges(from.privileges());
    }
    if (from.has_attributes_epoch()) {
      set_attributes_epoch(from.attributes_epoch());
    }
    if (from.has_full_name()) {
      set_full_name(from.full_name());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendOfFriend::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendOfFriend::CopyFrom(const FriendOfFriend& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendOfFriend::IsInitialized() const {

  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void FriendOfFriend::Swap(FriendOfFriend* other) {
  if (other != this) {
    std::swap(account_id_, other->account_id_);
    attribute_.Swap(&other->attribute_);
    role_.Swap(&other->role_);
    std::swap(privileges_, other->privileges_);
    std::swap(attributes_epoch_, other->attributes_epoch_);
    std::swap(full_name_, other->full_name_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendOfFriend::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendOfFriend_descriptor_;
  metadata.reflection = FriendOfFriend_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FriendInvitation::kFirstReceivedFieldNumber;
const int FriendInvitation::kRoleFieldNumber;
#endif  // !_MSC_VER

#ifndef _MSC_VER
const int FriendInvitation::kFriendInvitationFieldNumber;
#endif
::google::protobuf::internal::ExtensionIdentifier< ::bgs::protocol::Invitation,
    ::google::protobuf::internal::MessageTypeTraits< ::bgs::protocol::friends::v1::FriendInvitation >, 11, false >
  FriendInvitation::friend_invitation(kFriendInvitationFieldNumber, ::bgs::protocol::friends::v1::FriendInvitation::default_instance());
FriendInvitation::FriendInvitation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.FriendInvitation)
}

void FriendInvitation::InitAsDefaultInstance() {
}

FriendInvitation::FriendInvitation(const FriendInvitation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.FriendInvitation)
}

void FriendInvitation::SharedCtor() {
  _cached_size_ = 0;
  first_received_ = false;
  _role_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendInvitation::~FriendInvitation() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.FriendInvitation)
  SharedDtor();
}

void FriendInvitation::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FriendInvitation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendInvitation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendInvitation_descriptor_;
}

const FriendInvitation& FriendInvitation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5ftypes_2eproto();
  return *default_instance_;
}

FriendInvitation* FriendInvitation::default_instance_ = NULL;

FriendInvitation* FriendInvitation::New() const {
  return new FriendInvitation;
}

void FriendInvitation::Clear() {
  first_received_ = false;
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendInvitation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.FriendInvitation)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool first_received = 1 [default = false];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &first_received_)));
          set_has_first_received();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_role;
        break;
      }

      // repeated uint32 role = 2 [packed = true];
      case 2: {
        if (tag == 18) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_role())));
        } else if (tag == 16) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 18, input, this->mutable_role())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.FriendInvitation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.FriendInvitation)
  return false;
#undef DO_
}

void FriendInvitation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.FriendInvitation)
  // optional bool first_received = 1 [default = false];
  if (has_first_received()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->first_received(), output);
  }

  // repeated uint32 role = 2 [packed = true];
  if (this->role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.FriendInvitation)
}

::google::protobuf::uint8* FriendInvitation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.FriendInvitation)
  // optional bool first_received = 1 [default = false];
  if (has_first_received()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->first_received(), target);
  }

  // repeated uint32 role = 2 [packed = true];
  if (this->role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.FriendInvitation)
  return target;
}

int FriendInvitation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool first_received = 1 [default = false];
    if (has_first_received()) {
      total_size += 1 + 1;
    }

  }
  // repeated uint32 role = 2 [packed = true];
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

void FriendInvitation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendInvitation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendInvitation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendInvitation::MergeFrom(const FriendInvitation& from) {
  GOOGLE_CHECK_NE(&from, this);
  role_.MergeFrom(from.role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_first_received()) {
      set_first_received(from.first_received());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendInvitation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendInvitation::CopyFrom(const FriendInvitation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendInvitation::IsInitialized() const {

  return true;
}

void FriendInvitation::Swap(FriendInvitation* other) {
  if (other != this) {
    std::swap(first_received_, other->first_received_);
    role_.Swap(&other->role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendInvitation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendInvitation_descriptor_;
  metadata.reflection = FriendInvitation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FriendInvitationParams::kTargetEmailFieldNumber;
const int FriendInvitationParams::kTargetBattleTagFieldNumber;
const int FriendInvitationParams::kInviterBattleTagFieldNumber;
const int FriendInvitationParams::kInviterFullNameFieldNumber;
const int FriendInvitationParams::kInviteeDisplayNameFieldNumber;
const int FriendInvitationParams::kRoleFieldNumber;
const int FriendInvitationParams::kPreviousRoleDeprecatedFieldNumber;
#endif  // !_MSC_VER

#ifndef _MSC_VER
const int FriendInvitationParams::kFriendParamsFieldNumber;
#endif
::google::protobuf::internal::ExtensionIdentifier< ::bgs::protocol::InvitationParams,
    ::google::protobuf::internal::MessageTypeTraits< ::bgs::protocol::friends::v1::FriendInvitationParams >, 11, false >
  FriendInvitationParams::friend_params(kFriendParamsFieldNumber, ::bgs::protocol::friends::v1::FriendInvitationParams::default_instance());
FriendInvitationParams::FriendInvitationParams()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.FriendInvitationParams)
}

void FriendInvitationParams::InitAsDefaultInstance() {
}

FriendInvitationParams::FriendInvitationParams(const FriendInvitationParams& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.FriendInvitationParams)
}

void FriendInvitationParams::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  target_email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  target_battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  inviter_battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  inviter_full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  invitee_display_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _role_cached_byte_size_ = 0;
  _previous_role_deprecated_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendInvitationParams::~FriendInvitationParams() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.FriendInvitationParams)
  SharedDtor();
}

void FriendInvitationParams::SharedDtor() {
  if (target_email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete target_email_;
  }
  if (target_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete target_battle_tag_;
  }
  if (inviter_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete inviter_battle_tag_;
  }
  if (inviter_full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete inviter_full_name_;
  }
  if (invitee_display_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete invitee_display_name_;
  }
  if (this != default_instance_) {
  }
}

void FriendInvitationParams::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendInvitationParams::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendInvitationParams_descriptor_;
}

const FriendInvitationParams& FriendInvitationParams::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5ftypes_2eproto();
  return *default_instance_;
}

FriendInvitationParams* FriendInvitationParams::default_instance_ = NULL;

FriendInvitationParams* FriendInvitationParams::New() const {
  return new FriendInvitationParams;
}

void FriendInvitationParams::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_target_email()) {
      if (target_email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        target_email_->clear();
      }
    }
    if (has_target_battle_tag()) {
      if (target_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        target_battle_tag_->clear();
      }
    }
    if (has_inviter_battle_tag()) {
      if (inviter_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        inviter_battle_tag_->clear();
      }
    }
    if (has_inviter_full_name()) {
      if (inviter_full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        inviter_full_name_->clear();
      }
    }
    if (has_invitee_display_name()) {
      if (invitee_display_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        invitee_display_name_->clear();
      }
    }
  }
  role_.Clear();
  previous_role_deprecated_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendInvitationParams::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.FriendInvitationParams)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string target_email = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_target_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->target_email().data(), this->target_email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "target_email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_target_battle_tag;
        break;
      }

      // optional string target_battle_tag = 2;
      case 2: {
        if (tag == 18) {
         parse_target_battle_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_target_battle_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->target_battle_tag().data(), this->target_battle_tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "target_battle_tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_inviter_battle_tag;
        break;
      }

      // optional string inviter_battle_tag = 3;
      case 3: {
        if (tag == 26) {
         parse_inviter_battle_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_inviter_battle_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->inviter_battle_tag().data(), this->inviter_battle_tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "inviter_battle_tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_inviter_full_name;
        break;
      }

      // optional string inviter_full_name = 4;
      case 4: {
        if (tag == 34) {
         parse_inviter_full_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_inviter_full_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->inviter_full_name().data(), this->inviter_full_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "inviter_full_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_invitee_display_name;
        break;
      }

      // optional string invitee_display_name = 5;
      case 5: {
        if (tag == 42) {
         parse_invitee_display_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_invitee_display_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->invitee_display_name().data(), this->invitee_display_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "invitee_display_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_role;
        break;
      }

      // repeated uint32 role = 6 [packed = true];
      case 6: {
        if (tag == 50) {
         parse_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_role())));
        } else if (tag == 48) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 50, input, this->mutable_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_previous_role_deprecated;
        break;
      }

      // repeated uint32 previous_role_deprecated = 7 [packed = true, deprecated = true];
      case 7: {
        if (tag == 58) {
         parse_previous_role_deprecated:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_previous_role_deprecated())));
        } else if (tag == 56) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 58, input, this->mutable_previous_role_deprecated())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.FriendInvitationParams)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.FriendInvitationParams)
  return false;
#undef DO_
}

void FriendInvitationParams::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.FriendInvitationParams)
  // optional string target_email = 1;
  if (has_target_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_email().data(), this->target_email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->target_email(), output);
  }

  // optional string target_battle_tag = 2;
  if (has_target_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_battle_tag().data(), this->target_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->target_battle_tag(), output);
  }

  // optional string inviter_battle_tag = 3;
  if (has_inviter_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_battle_tag().data(), this->inviter_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->inviter_battle_tag(), output);
  }

  // optional string inviter_full_name = 4;
  if (has_inviter_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_full_name().data(), this->inviter_full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_full_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->inviter_full_name(), output);
  }

  // optional string invitee_display_name = 5;
  if (has_invitee_display_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_display_name().data(), this->invitee_display_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_display_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->invitee_display_name(), output);
  }

  // repeated uint32 role = 6 [packed = true];
  if (this->role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(6, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_role_cached_byte_size_);
  }
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->role(i), output);
  }

  // repeated uint32 previous_role_deprecated = 7 [packed = true, deprecated = true];
  if (this->previous_role_deprecated_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(7, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_previous_role_deprecated_cached_byte_size_);
  }
  for (int i = 0; i < this->previous_role_deprecated_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->previous_role_deprecated(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.FriendInvitationParams)
}

::google::protobuf::uint8* FriendInvitationParams::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.FriendInvitationParams)
  // optional string target_email = 1;
  if (has_target_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_email().data(), this->target_email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->target_email(), target);
  }

  // optional string target_battle_tag = 2;
  if (has_target_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_battle_tag().data(), this->target_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->target_battle_tag(), target);
  }

  // optional string inviter_battle_tag = 3;
  if (has_inviter_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_battle_tag().data(), this->inviter_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->inviter_battle_tag(), target);
  }

  // optional string inviter_full_name = 4;
  if (has_inviter_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->inviter_full_name().data(), this->inviter_full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "inviter_full_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->inviter_full_name(), target);
  }

  // optional string invitee_display_name = 5;
  if (has_invitee_display_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->invitee_display_name().data(), this->invitee_display_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "invitee_display_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->invitee_display_name(), target);
  }

  // repeated uint32 role = 6 [packed = true];
  if (this->role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      6,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->role(i), target);
  }

  // repeated uint32 previous_role_deprecated = 7 [packed = true, deprecated = true];
  if (this->previous_role_deprecated_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      7,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _previous_role_deprecated_cached_byte_size_, target);
  }
  for (int i = 0; i < this->previous_role_deprecated_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->previous_role_deprecated(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.FriendInvitationParams)
  return target;
}

int FriendInvitationParams::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string target_email = 1;
    if (has_target_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->target_email());
    }

    // optional string target_battle_tag = 2;
    if (has_target_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->target_battle_tag());
    }

    // optional string inviter_battle_tag = 3;
    if (has_inviter_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->inviter_battle_tag());
    }

    // optional string inviter_full_name = 4;
    if (has_inviter_full_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->inviter_full_name());
    }

    // optional string invitee_display_name = 5;
    if (has_invitee_display_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->invitee_display_name());
    }

  }
  // repeated uint32 role = 6 [packed = true];
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

  // repeated uint32 previous_role_deprecated = 7 [packed = true, deprecated = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->previous_role_deprecated_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->previous_role_deprecated(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _previous_role_deprecated_cached_byte_size_ = data_size;
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

void FriendInvitationParams::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendInvitationParams* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendInvitationParams*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendInvitationParams::MergeFrom(const FriendInvitationParams& from) {
  GOOGLE_CHECK_NE(&from, this);
  role_.MergeFrom(from.role_);
  previous_role_deprecated_.MergeFrom(from.previous_role_deprecated_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target_email()) {
      set_target_email(from.target_email());
    }
    if (from.has_target_battle_tag()) {
      set_target_battle_tag(from.target_battle_tag());
    }
    if (from.has_inviter_battle_tag()) {
      set_inviter_battle_tag(from.inviter_battle_tag());
    }
    if (from.has_inviter_full_name()) {
      set_inviter_full_name(from.inviter_full_name());
    }
    if (from.has_invitee_display_name()) {
      set_invitee_display_name(from.invitee_display_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendInvitationParams::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendInvitationParams::CopyFrom(const FriendInvitationParams& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendInvitationParams::IsInitialized() const {

  return true;
}

void FriendInvitationParams::Swap(FriendInvitationParams* other) {
  if (other != this) {
    std::swap(target_email_, other->target_email_);
    std::swap(target_battle_tag_, other->target_battle_tag_);
    std::swap(inviter_battle_tag_, other->inviter_battle_tag_);
    std::swap(inviter_full_name_, other->inviter_full_name_);
    std::swap(invitee_display_name_, other->invitee_display_name_);
    role_.Swap(&other->role_);
    previous_role_deprecated_.Swap(&other->previous_role_deprecated_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendInvitationParams::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendInvitationParams_descriptor_;
  metadata.reflection = FriendInvitationParams_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SubscribeResponse::kMaxFriendsFieldNumber;
const int SubscribeResponse::kMaxReceivedInvitationsFieldNumber;
const int SubscribeResponse::kMaxSentInvitationsFieldNumber;
const int SubscribeResponse::kRoleFieldNumber;
const int SubscribeResponse::kFriendsFieldNumber;
const int SubscribeResponse::kSentInvitationsFieldNumber;
const int SubscribeResponse::kReceivedInvitationsFieldNumber;
#endif  // !_MSC_VER

SubscribeResponse::SubscribeResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.friends.v1.SubscribeResponse)
}

void SubscribeResponse::InitAsDefaultInstance() {
}

SubscribeResponse::SubscribeResponse(const SubscribeResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.friends.v1.SubscribeResponse)
}

void SubscribeResponse::SharedCtor() {
  _cached_size_ = 0;
  max_friends_ = 0u;
  max_received_invitations_ = 0u;
  max_sent_invitations_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscribeResponse::~SubscribeResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.friends.v1.SubscribeResponse)
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
  if (default_instance_ == NULL) protobuf_AddDesc_friends_5ftypes_2eproto();
  return *default_instance_;
}

SubscribeResponse* SubscribeResponse::default_instance_ = NULL;

SubscribeResponse* SubscribeResponse::New() const {
  return new SubscribeResponse;
}

void SubscribeResponse::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<SubscribeResponse*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(max_friends_, max_received_invitations_);
    max_sent_invitations_ = 0u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  role_.Clear();
  friends_.Clear();
  sent_invitations_.Clear();
  received_invitations_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscribeResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.friends.v1.SubscribeResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 max_friends = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_friends_)));
          set_has_max_friends();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_max_received_invitations;
        break;
      }

      // optional uint32 max_received_invitations = 2;
      case 2: {
        if (tag == 16) {
         parse_max_received_invitations:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_received_invitations_)));
          set_has_max_received_invitations();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_max_sent_invitations;
        break;
      }

      // optional uint32 max_sent_invitations = 3;
      case 3: {
        if (tag == 24) {
         parse_max_sent_invitations:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_sent_invitations_)));
          set_has_max_sent_invitations();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_role;
        break;
      }

      // repeated .bgs.protocol.Role role = 4;
      case 4: {
        if (tag == 34) {
         parse_role:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_role()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_role;
        if (input->ExpectTag(42)) goto parse_friends;
        break;
      }

      // repeated .bgs.protocol.friends.v1.Friend friends = 5;
      case 5: {
        if (tag == 42) {
         parse_friends:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_friends()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_friends;
        if (input->ExpectTag(50)) goto parse_sent_invitations;
        break;
      }

      // repeated .bgs.protocol.Invitation sent_invitations = 6;
      case 6: {
        if (tag == 50) {
         parse_sent_invitations:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_sent_invitations()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_sent_invitations;
        if (input->ExpectTag(58)) goto parse_received_invitations;
        break;
      }

      // repeated .bgs.protocol.Invitation received_invitations = 7;
      case 7: {
        if (tag == 58) {
         parse_received_invitations:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_received_invitations()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_received_invitations;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.friends.v1.SubscribeResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.friends.v1.SubscribeResponse)
  return false;
#undef DO_
}

void SubscribeResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.friends.v1.SubscribeResponse)
  // optional uint32 max_friends = 1;
  if (has_max_friends()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->max_friends(), output);
  }

  // optional uint32 max_received_invitations = 2;
  if (has_max_received_invitations()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->max_received_invitations(), output);
  }

  // optional uint32 max_sent_invitations = 3;
  if (has_max_sent_invitations()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->max_sent_invitations(), output);
  }

  // repeated .bgs.protocol.Role role = 4;
  for (int i = 0; i < this->role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->role(i), output);
  }

  // repeated .bgs.protocol.friends.v1.Friend friends = 5;
  for (int i = 0; i < this->friends_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->friends(i), output);
  }

  // repeated .bgs.protocol.Invitation sent_invitations = 6;
  for (int i = 0; i < this->sent_invitations_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->sent_invitations(i), output);
  }

  // repeated .bgs.protocol.Invitation received_invitations = 7;
  for (int i = 0; i < this->received_invitations_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->received_invitations(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.friends.v1.SubscribeResponse)
}

::google::protobuf::uint8* SubscribeResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.friends.v1.SubscribeResponse)
  // optional uint32 max_friends = 1;
  if (has_max_friends()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->max_friends(), target);
  }

  // optional uint32 max_received_invitations = 2;
  if (has_max_received_invitations()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->max_received_invitations(), target);
  }

  // optional uint32 max_sent_invitations = 3;
  if (has_max_sent_invitations()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->max_sent_invitations(), target);
  }

  // repeated .bgs.protocol.Role role = 4;
  for (int i = 0; i < this->role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->role(i), target);
  }

  // repeated .bgs.protocol.friends.v1.Friend friends = 5;
  for (int i = 0; i < this->friends_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->friends(i), target);
  }

  // repeated .bgs.protocol.Invitation sent_invitations = 6;
  for (int i = 0; i < this->sent_invitations_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->sent_invitations(i), target);
  }

  // repeated .bgs.protocol.Invitation received_invitations = 7;
  for (int i = 0; i < this->received_invitations_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->received_invitations(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.friends.v1.SubscribeResponse)
  return target;
}

int SubscribeResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 max_friends = 1;
    if (has_max_friends()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_friends());
    }

    // optional uint32 max_received_invitations = 2;
    if (has_max_received_invitations()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_received_invitations());
    }

    // optional uint32 max_sent_invitations = 3;
    if (has_max_sent_invitations()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_sent_invitations());
    }

  }
  // repeated .bgs.protocol.Role role = 4;
  total_size += 1 * this->role_size();
  for (int i = 0; i < this->role_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->role(i));
  }

  // repeated .bgs.protocol.friends.v1.Friend friends = 5;
  total_size += 1 * this->friends_size();
  for (int i = 0; i < this->friends_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->friends(i));
  }

  // repeated .bgs.protocol.Invitation sent_invitations = 6;
  total_size += 1 * this->sent_invitations_size();
  for (int i = 0; i < this->sent_invitations_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->sent_invitations(i));
  }

  // repeated .bgs.protocol.Invitation received_invitations = 7;
  total_size += 1 * this->received_invitations_size();
  for (int i = 0; i < this->received_invitations_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->received_invitations(i));
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
  role_.MergeFrom(from.role_);
  friends_.MergeFrom(from.friends_);
  sent_invitations_.MergeFrom(from.sent_invitations_);
  received_invitations_.MergeFrom(from.received_invitations_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_max_friends()) {
      set_max_friends(from.max_friends());
    }
    if (from.has_max_received_invitations()) {
      set_max_received_invitations(from.max_received_invitations());
    }
    if (from.has_max_sent_invitations()) {
      set_max_sent_invitations(from.max_sent_invitations());
    }
  }
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

  if (!::google::protobuf::internal::AllAreInitialized(this->role())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->friends())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->sent_invitations())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->received_invitations())) return false;
  return true;
}

void SubscribeResponse::Swap(SubscribeResponse* other) {
  if (other != this) {
    std::swap(max_friends_, other->max_friends_);
    std::swap(max_received_invitations_, other->max_received_invitations_);
    std::swap(max_sent_invitations_, other->max_sent_invitations_);
    role_.Swap(&other->role_);
    friends_.Swap(&other->friends_);
    sent_invitations_.Swap(&other->sent_invitations_);
    received_invitations_.Swap(&other->received_invitations_);
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


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace friends
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
