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
#include "notification_types.pb.h"

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
namespace notification {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* Target_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Target_reflection_ = NULL;
const ::google::protobuf::Descriptor* Subscription_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Subscription_reflection_ = NULL;
const ::google::protobuf::Descriptor* Notification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Notification_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_notification_5ftypes_2eproto() {
  protobuf_AddDesc_notification_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "notification_types.proto");
  GOOGLE_CHECK(file != NULL);
  Target_descriptor_ = file->message_type(0);
  static const int Target_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Target, identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Target, type_),
  };
  Target_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Target_descriptor_,
      Target::default_instance_,
      Target_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Target, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Target, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Target));
  Subscription_descriptor_ = file->message_type(1);
  static const int Subscription_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Subscription, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Subscription, subscriber_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Subscription, delivery_required_),
  };
  Subscription_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Subscription_descriptor_,
      Subscription::default_instance_,
      Subscription_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Subscription, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Subscription, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Subscription));
  Notification_descriptor_ = file->message_type(2);
  static const int Notification_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, sender_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, sender_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, target_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, sender_battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, target_battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, peer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, forwarding_identity_),
  };
  Notification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Notification_descriptor_,
      Notification::default_instance_,
      Notification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Notification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Notification));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_notification_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Target_descriptor_, &Target::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Subscription_descriptor_, &Subscription::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Notification_descriptor_, &Notification::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_notification_5ftypes_2eproto() {
  delete Target::default_instance_;
  delete Target_reflection_;
  delete Subscription::default_instance_;
  delete Subscription_reflection_;
  delete Notification::default_instance_;
  delete Notification_reflection_;
}

void protobuf_AddDesc_notification_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::account::v1::protobuf_AddDesc_account_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030notification_types.proto\022\034bgs.protocol"
    ".notification.v1\032\023account_types.proto\032\025a"
    "ttribute_types.proto\032\022entity_types.proto"
    "\032\017rpc_types.proto\"K\n\006Target\0223\n\010identity\030"
    "\001 \001(\0132!.bgs.protocol.account.v1.Identity"
    "\022\014\n\004type\030\002 \001(\t\"\235\001\n\014Subscription\0224\n\006targe"
    "t\030\001 \003(\0132$.bgs.protocol.notification.v1.T"
    "arget\0225\n\nsubscriber\030\002 \001(\0132!.bgs.protocol"
    ".account.v1.Identity\022 \n\021delivery_require"
    "d\030\003 \001(\010:\005false\"\241\003\n\014Notification\022)\n\tsende"
    "r_id\030\001 \001(\0132\026.bgs.protocol.EntityId\022)\n\tta"
    "rget_id\030\002 \002(\0132\026.bgs.protocol.EntityId\022\014\n"
    "\004type\030\003 \002(\t\022*\n\tattribute\030\004 \003(\0132\027.bgs.pro"
    "tocol.Attribute\0221\n\021sender_account_id\030\005 \001"
    "(\0132\026.bgs.protocol.EntityId\0221\n\021target_acc"
    "ount_id\030\006 \001(\0132\026.bgs.protocol.EntityId\022\031\n"
    "\021sender_battle_tag\030\007 \001(\t\022\031\n\021target_battl"
    "e_tag\030\010 \001(\t\022%\n\004peer\030\t \001(\0132\027.bgs.protocol"
    ".ProcessId\022>\n\023forwarding_identity\030\n \001(\0132"
    "!.bgs.protocol.account.v1.IdentityB\002H\001", 798);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "notification_types.proto", &protobuf_RegisterTypes);
  Target::default_instance_ = new Target();
  Subscription::default_instance_ = new Subscription();
  Notification::default_instance_ = new Notification();
  Target::default_instance_->InitAsDefaultInstance();
  Subscription::default_instance_->InitAsDefaultInstance();
  Notification::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_notification_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_notification_5ftypes_2eproto {
  StaticDescriptorInitializer_notification_5ftypes_2eproto() {
    protobuf_AddDesc_notification_5ftypes_2eproto();
  }
} static_descriptor_initializer_notification_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Target::kIdentityFieldNumber;
const int Target::kTypeFieldNumber;
#endif  // !_MSC_VER

Target::Target()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.notification.v1.Target)
}

void Target::InitAsDefaultInstance() {
  identity_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

Target::Target(const Target& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.notification.v1.Target)
}

void Target::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  identity_ = NULL;
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Target::~Target() {
  // @@protoc_insertion_point(destructor:bgs.protocol.notification.v1.Target)
  SharedDtor();
}

void Target::SharedDtor() {
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (this != default_instance_) {
    delete identity_;
  }
}

void Target::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Target::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Target_descriptor_;
}

const Target& Target::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_notification_5ftypes_2eproto();
  return *default_instance_;
}

Target* Target::default_instance_ = NULL;

Target* Target::New() const {
  return new Target;
}

void Target::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_identity()) {
      if (identity_ != NULL) identity_->::bgs::protocol::account::v1::Identity::Clear();
    }
    if (has_type()) {
      if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        type_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Target::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.notification.v1.Target)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.Identity identity = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_type;
        break;
      }

      // optional string type = 2;
      case 2: {
        if (tag == 18) {
         parse_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->type().data(), this->type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "type");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.notification.v1.Target)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.notification.v1.Target)
  return false;
#undef DO_
}

void Target::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.notification.v1.Target)
  // optional .bgs.protocol.account.v1.Identity identity = 1;
  if (has_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->identity(), output);
  }

  // optional string type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.notification.v1.Target)
}

::google::protobuf::uint8* Target::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.notification.v1.Target)
  // optional .bgs.protocol.account.v1.Identity identity = 1;
  if (has_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->identity(), target);
  }

  // optional string type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.notification.v1.Target)
  return target;
}

int Target::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.Identity identity = 1;
    if (has_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->identity());
    }

    // optional string type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
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

void Target::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Target* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Target*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Target::MergeFrom(const Target& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_identity()) {
      mutable_identity()->::bgs::protocol::account::v1::Identity::MergeFrom(from.identity());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Target::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Target::CopyFrom(const Target& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Target::IsInitialized() const {

  if (has_identity()) {
    if (!this->identity().IsInitialized()) return false;
  }
  return true;
}

void Target::Swap(Target* other) {
  if (other != this) {
    std::swap(identity_, other->identity_);
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Target::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Target_descriptor_;
  metadata.reflection = Target_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Subscription::kTargetFieldNumber;
const int Subscription::kSubscriberFieldNumber;
const int Subscription::kDeliveryRequiredFieldNumber;
#endif  // !_MSC_VER

Subscription::Subscription()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.notification.v1.Subscription)
}

void Subscription::InitAsDefaultInstance() {
  subscriber_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

Subscription::Subscription(const Subscription& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.notification.v1.Subscription)
}

void Subscription::SharedCtor() {
  _cached_size_ = 0;
  subscriber_ = NULL;
  delivery_required_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Subscription::~Subscription() {
  // @@protoc_insertion_point(destructor:bgs.protocol.notification.v1.Subscription)
  SharedDtor();
}

void Subscription::SharedDtor() {
  if (this != default_instance_) {
    delete subscriber_;
  }
}

void Subscription::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Subscription::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Subscription_descriptor_;
}

const Subscription& Subscription::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_notification_5ftypes_2eproto();
  return *default_instance_;
}

Subscription* Subscription::default_instance_ = NULL;

Subscription* Subscription::New() const {
  return new Subscription;
}

void Subscription::Clear() {
  if (_has_bits_[0 / 32] & 6) {
    if (has_subscriber()) {
      if (subscriber_ != NULL) subscriber_->::bgs::protocol::account::v1::Identity::Clear();
    }
    delivery_required_ = false;
  }
  target_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Subscription::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.notification.v1.Subscription)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.notification.v1.Target target = 1;
      case 1: {
        if (tag == 10) {
         parse_target:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_target()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_target;
        if (input->ExpectTag(18)) goto parse_subscriber;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity subscriber = 2;
      case 2: {
        if (tag == 18) {
         parse_subscriber:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_subscriber()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_delivery_required;
        break;
      }

      // optional bool delivery_required = 3 [default = false];
      case 3: {
        if (tag == 24) {
         parse_delivery_required:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &delivery_required_)));
          set_has_delivery_required();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.notification.v1.Subscription)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.notification.v1.Subscription)
  return false;
#undef DO_
}

void Subscription::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.notification.v1.Subscription)
  // repeated .bgs.protocol.notification.v1.Target target = 1;
  for (int i = 0; i < this->target_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(i), output);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 2;
  if (has_subscriber()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->subscriber(), output);
  }

  // optional bool delivery_required = 3 [default = false];
  if (has_delivery_required()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->delivery_required(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.notification.v1.Subscription)
}

::google::protobuf::uint8* Subscription::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.notification.v1.Subscription)
  // repeated .bgs.protocol.notification.v1.Target target = 1;
  for (int i = 0; i < this->target_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(i), target);
  }

  // optional .bgs.protocol.account.v1.Identity subscriber = 2;
  if (has_subscriber()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->subscriber(), target);
  }

  // optional bool delivery_required = 3 [default = false];
  if (has_delivery_required()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->delivery_required(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.notification.v1.Subscription)
  return target;
}

int Subscription::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional .bgs.protocol.account.v1.Identity subscriber = 2;
    if (has_subscriber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->subscriber());
    }

    // optional bool delivery_required = 3 [default = false];
    if (has_delivery_required()) {
      total_size += 1 + 1;
    }

  }
  // repeated .bgs.protocol.notification.v1.Target target = 1;
  total_size += 1 * this->target_size();
  for (int i = 0; i < this->target_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->target(i));
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

void Subscription::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Subscription* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Subscription*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Subscription::MergeFrom(const Subscription& from) {
  GOOGLE_CHECK_NE(&from, this);
  target_.MergeFrom(from.target_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_subscriber()) {
      mutable_subscriber()->::bgs::protocol::account::v1::Identity::MergeFrom(from.subscriber());
    }
    if (from.has_delivery_required()) {
      set_delivery_required(from.delivery_required());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Subscription::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Subscription::CopyFrom(const Subscription& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Subscription::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->target())) return false;
  if (has_subscriber()) {
    if (!this->subscriber().IsInitialized()) return false;
  }
  return true;
}

void Subscription::Swap(Subscription* other) {
  if (other != this) {
    target_.Swap(&other->target_);
    std::swap(subscriber_, other->subscriber_);
    std::swap(delivery_required_, other->delivery_required_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Subscription::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Subscription_descriptor_;
  metadata.reflection = Subscription_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Notification::kSenderIdFieldNumber;
const int Notification::kTargetIdFieldNumber;
const int Notification::kTypeFieldNumber;
const int Notification::kAttributeFieldNumber;
const int Notification::kSenderAccountIdFieldNumber;
const int Notification::kTargetAccountIdFieldNumber;
const int Notification::kSenderBattleTagFieldNumber;
const int Notification::kTargetBattleTagFieldNumber;
const int Notification::kPeerFieldNumber;
const int Notification::kForwardingIdentityFieldNumber;
#endif  // !_MSC_VER

Notification::Notification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.notification.v1.Notification)
}

void Notification::InitAsDefaultInstance() {
  sender_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  sender_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  target_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  peer_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  forwarding_identity_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

Notification::Notification(const Notification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.notification.v1.Notification)
}

void Notification::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  sender_id_ = NULL;
  target_id_ = NULL;
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sender_account_id_ = NULL;
  target_account_id_ = NULL;
  sender_battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  target_battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  peer_ = NULL;
  forwarding_identity_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Notification::~Notification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.notification.v1.Notification)
  SharedDtor();
}

void Notification::SharedDtor() {
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (sender_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sender_battle_tag_;
  }
  if (target_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete target_battle_tag_;
  }
  if (this != default_instance_) {
    delete sender_id_;
    delete target_id_;
    delete sender_account_id_;
    delete target_account_id_;
    delete peer_;
    delete forwarding_identity_;
  }
}

void Notification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Notification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Notification_descriptor_;
}

const Notification& Notification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_notification_5ftypes_2eproto();
  return *default_instance_;
}

Notification* Notification::default_instance_ = NULL;

Notification* Notification::New() const {
  return new Notification;
}

void Notification::Clear() {
  if (_has_bits_[0 / 32] & 247) {
    if (has_sender_id()) {
      if (sender_id_ != NULL) sender_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_type()) {
      if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        type_->clear();
      }
    }
    if (has_sender_account_id()) {
      if (sender_account_id_ != NULL) sender_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_target_account_id()) {
      if (target_account_id_ != NULL) target_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_sender_battle_tag()) {
      if (sender_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sender_battle_tag_->clear();
      }
    }
    if (has_target_battle_tag()) {
      if (target_battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        target_battle_tag_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 768) {
    if (has_peer()) {
      if (peer_ != NULL) peer_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_forwarding_identity()) {
      if (forwarding_identity_ != NULL) forwarding_identity_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Notification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.notification.v1.Notification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId sender_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_sender_id()));
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
        if (input->ExpectTag(26)) goto parse_type;
        break;
      }

      // required string type = 3;
      case 3: {
        if (tag == 26) {
         parse_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->type().data(), this->type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 4;
      case 4: {
        if (tag == 34) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_attribute;
        if (input->ExpectTag(42)) goto parse_sender_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId sender_account_id = 5;
      case 5: {
        if (tag == 42) {
         parse_sender_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_sender_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_target_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId target_account_id = 6;
      case 6: {
        if (tag == 50) {
         parse_target_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_sender_battle_tag;
        break;
      }

      // optional string sender_battle_tag = 7;
      case 7: {
        if (tag == 58) {
         parse_sender_battle_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sender_battle_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->sender_battle_tag().data(), this->sender_battle_tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "sender_battle_tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_target_battle_tag;
        break;
      }

      // optional string target_battle_tag = 8;
      case 8: {
        if (tag == 66) {
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
        if (input->ExpectTag(74)) goto parse_peer;
        break;
      }

      // optional .bgs.protocol.ProcessId peer = 9;
      case 9: {
        if (tag == 74) {
         parse_peer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_forwarding_identity;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity forwarding_identity = 10;
      case 10: {
        if (tag == 82) {
         parse_forwarding_identity:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_forwarding_identity()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.notification.v1.Notification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.notification.v1.Notification)
  return false;
#undef DO_
}

void Notification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.notification.v1.Notification)
  // optional .bgs.protocol.EntityId sender_id = 1;
  if (has_sender_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->sender_id(), output);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->target_id(), output);
  }

  // required string type = 3;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->type(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 4;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->attribute(i), output);
  }

  // optional .bgs.protocol.EntityId sender_account_id = 5;
  if (has_sender_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->sender_account_id(), output);
  }

  // optional .bgs.protocol.EntityId target_account_id = 6;
  if (has_target_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->target_account_id(), output);
  }

  // optional string sender_battle_tag = 7;
  if (has_sender_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_battle_tag().data(), this->sender_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sender_battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->sender_battle_tag(), output);
  }

  // optional string target_battle_tag = 8;
  if (has_target_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_battle_tag().data(), this->target_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->target_battle_tag(), output);
  }

  // optional .bgs.protocol.ProcessId peer = 9;
  if (has_peer()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->peer(), output);
  }

  // optional .bgs.protocol.account.v1.Identity forwarding_identity = 10;
  if (has_forwarding_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->forwarding_identity(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.notification.v1.Notification)
}

::google::protobuf::uint8* Notification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.notification.v1.Notification)
  // optional .bgs.protocol.EntityId sender_id = 1;
  if (has_sender_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->sender_id(), target);
  }

  // required .bgs.protocol.EntityId target_id = 2;
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->target_id(), target);
  }

  // required string type = 3;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->type(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 4;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->attribute(i), target);
  }

  // optional .bgs.protocol.EntityId sender_account_id = 5;
  if (has_sender_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->sender_account_id(), target);
  }

  // optional .bgs.protocol.EntityId target_account_id = 6;
  if (has_target_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->target_account_id(), target);
  }

  // optional string sender_battle_tag = 7;
  if (has_sender_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_battle_tag().data(), this->sender_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sender_battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->sender_battle_tag(), target);
  }

  // optional string target_battle_tag = 8;
  if (has_target_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->target_battle_tag().data(), this->target_battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "target_battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->target_battle_tag(), target);
  }

  // optional .bgs.protocol.ProcessId peer = 9;
  if (has_peer()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->peer(), target);
  }

  // optional .bgs.protocol.account.v1.Identity forwarding_identity = 10;
  if (has_forwarding_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->forwarding_identity(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.notification.v1.Notification)
  return target;
}

int Notification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId sender_id = 1;
    if (has_sender_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->sender_id());
    }

    // required .bgs.protocol.EntityId target_id = 2;
    if (has_target_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_id());
    }

    // required string type = 3;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
    }

    // optional .bgs.protocol.EntityId sender_account_id = 5;
    if (has_sender_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->sender_account_id());
    }

    // optional .bgs.protocol.EntityId target_account_id = 6;
    if (has_target_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_account_id());
    }

    // optional string sender_battle_tag = 7;
    if (has_sender_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sender_battle_tag());
    }

    // optional string target_battle_tag = 8;
    if (has_target_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->target_battle_tag());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional .bgs.protocol.ProcessId peer = 9;
    if (has_peer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peer());
    }

    // optional .bgs.protocol.account.v1.Identity forwarding_identity = 10;
    if (has_forwarding_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->forwarding_identity());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 4;
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

void Notification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Notification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Notification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Notification::MergeFrom(const Notification& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sender_id()) {
      mutable_sender_id()->::bgs::protocol::EntityId::MergeFrom(from.sender_id());
    }
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_sender_account_id()) {
      mutable_sender_account_id()->::bgs::protocol::EntityId::MergeFrom(from.sender_account_id());
    }
    if (from.has_target_account_id()) {
      mutable_target_account_id()->::bgs::protocol::EntityId::MergeFrom(from.target_account_id());
    }
    if (from.has_sender_battle_tag()) {
      set_sender_battle_tag(from.sender_battle_tag());
    }
    if (from.has_target_battle_tag()) {
      set_target_battle_tag(from.target_battle_tag());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_peer()) {
      mutable_peer()->::bgs::protocol::ProcessId::MergeFrom(from.peer());
    }
    if (from.has_forwarding_identity()) {
      mutable_forwarding_identity()->::bgs::protocol::account::v1::Identity::MergeFrom(from.forwarding_identity());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Notification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Notification::CopyFrom(const Notification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Notification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;

  if (has_sender_id()) {
    if (!this->sender_id().IsInitialized()) return false;
  }
  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  if (has_sender_account_id()) {
    if (!this->sender_account_id().IsInitialized()) return false;
  }
  if (has_target_account_id()) {
    if (!this->target_account_id().IsInitialized()) return false;
  }
  if (has_peer()) {
    if (!this->peer().IsInitialized()) return false;
  }
  if (has_forwarding_identity()) {
    if (!this->forwarding_identity().IsInitialized()) return false;
  }
  return true;
}

void Notification::Swap(Notification* other) {
  if (other != this) {
    std::swap(sender_id_, other->sender_id_);
    std::swap(target_id_, other->target_id_);
    std::swap(type_, other->type_);
    attribute_.Swap(&other->attribute_);
    std::swap(sender_account_id_, other->sender_account_id_);
    std::swap(target_account_id_, other->target_account_id_);
    std::swap(sender_battle_tag_, other->sender_battle_tag_);
    std::swap(target_battle_tag_, other->target_battle_tag_);
    std::swap(peer_, other->peer_);
    std::swap(forwarding_identity_, other->forwarding_identity_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Notification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Notification_descriptor_;
  metadata.reflection = Notification_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace notification
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
