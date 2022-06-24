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
#include "entity_types.pb.h"

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

const ::google::protobuf::Descriptor* EntityId_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EntityId_reflection_ = NULL;
const ::google::protobuf::Descriptor* Identity_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Identity_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_entity_5ftypes_2eproto() {
  protobuf_AddDesc_entity_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "entity_types.proto");
  GOOGLE_CHECK(file != NULL);
  EntityId_descriptor_ = file->message_type(0);
  static const int EntityId_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityId, high_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityId, low_),
  };
  EntityId_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EntityId_descriptor_,
      EntityId::default_instance_,
      EntityId_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityId, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EntityId, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EntityId));
  Identity_descriptor_ = file->message_type(1);
  static const int Identity_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, game_account_id_),
  };
  Identity_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Identity_descriptor_,
      Identity::default_instance_,
      Identity_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Identity));
  AccountInfo_descriptor_ = file->message_type(2);
  static const int AccountInfo_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, account_paid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, country_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, manual_review_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, account_muted_),
  };
  AccountInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountInfo_descriptor_,
      AccountInfo::default_instance_,
      AccountInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_entity_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EntityId_descriptor_, &EntityId::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Identity_descriptor_, &Identity::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountInfo_descriptor_, &AccountInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_entity_5ftypes_2eproto() {
  delete EntityId::default_instance_;
  delete EntityId_reflection_;
  delete Identity::default_instance_;
  delete Identity_reflection_;
  delete AccountInfo::default_instance_;
  delete AccountInfo_reflection_;
}

void protobuf_AddDesc_entity_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_global_5fextensions_2ffield_5foptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022entity_types.proto\022\014bgs.protocol\032%glob"
    "al_extensions/field_options.proto\"1\n\010Ent"
    "ityId\022\022\n\004high\030\001 \002(\006B\004\200\265\030\002\022\021\n\003low\030\002 \002(\006B\004"
    "\200\265\030\002\"g\n\010Identity\022*\n\naccount_id\030\001 \001(\0132\026.b"
    "gs.protocol.EntityId\022/\n\017game_account_id\030"
    "\002 \001(\0132\026.bgs.protocol.EntityId\"\273\001\n\013Accoun"
    "tInfo\022\033\n\014account_paid\030\001 \001(\010:\005false\022\025\n\nco"
    "untry_id\030\002 \001(\007:\0010\022\022\n\nbattle_tag\030\003 \001(\t\022\034\n"
    "\rmanual_review\030\004 \001(\010:\005false\022(\n\010identity\030"
    "\005 \001(\0132\026.bgs.protocol.Identity\022\034\n\raccount"
    "_muted\030\006 \001(\010:\005falseB\036\n\rbnet.protocolB\013En"
    "tityProtoH\001", 451);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "entity_types.proto", &protobuf_RegisterTypes);
  EntityId::default_instance_ = new EntityId();
  Identity::default_instance_ = new Identity();
  AccountInfo::default_instance_ = new AccountInfo();
  EntityId::default_instance_->InitAsDefaultInstance();
  Identity::default_instance_->InitAsDefaultInstance();
  AccountInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_entity_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_entity_5ftypes_2eproto {
  StaticDescriptorInitializer_entity_5ftypes_2eproto() {
    protobuf_AddDesc_entity_5ftypes_2eproto();
  }
} static_descriptor_initializer_entity_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int EntityId::kHighFieldNumber;
const int EntityId::kLowFieldNumber;
#endif  // !_MSC_VER

EntityId::EntityId()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.EntityId)
}

void EntityId::InitAsDefaultInstance() {
}

EntityId::EntityId(const EntityId& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.EntityId)
}

void EntityId::SharedCtor() {
  _cached_size_ = 0;
  high_ = GOOGLE_ULONGLONG(0);
  low_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EntityId::~EntityId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.EntityId)
  SharedDtor();
}

void EntityId::SharedDtor() {
  if (this != default_instance_) {
  }
}

void EntityId::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EntityId::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EntityId_descriptor_;
}

const EntityId& EntityId::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_entity_5ftypes_2eproto();
  return *default_instance_;
}

EntityId* EntityId::default_instance_ = NULL;

EntityId* EntityId::New() const {
  return new EntityId;
}

void EntityId::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<EntityId*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(high_, low_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EntityId::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.EntityId)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed64 high = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &high_)));
          set_has_high();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_low;
        break;
      }

      // required fixed64 low = 2;
      case 2: {
        if (tag == 17) {
         parse_low:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &low_)));
          set_has_low();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.EntityId)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.EntityId)
  return false;
#undef DO_
}

void EntityId::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.EntityId)
  // required fixed64 high = 1;
  if (has_high()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->high(), output);
  }

  // required fixed64 low = 2;
  if (has_low()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(2, this->low(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.EntityId)
}

::google::protobuf::uint8* EntityId::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.EntityId)
  // required fixed64 high = 1;
  if (has_high()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->high(), target);
  }

  // required fixed64 low = 2;
  if (has_low()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(2, this->low(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.EntityId)
  return target;
}

int EntityId::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed64 high = 1;
    if (has_high()) {
      total_size += 1 + 8;
    }

    // required fixed64 low = 2;
    if (has_low()) {
      total_size += 1 + 8;
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

void EntityId::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EntityId* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EntityId*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EntityId::MergeFrom(const EntityId& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_high()) {
      set_high(from.high());
    }
    if (from.has_low()) {
      set_low(from.low());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EntityId::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EntityId::CopyFrom(const EntityId& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EntityId::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void EntityId::Swap(EntityId* other) {
  if (other != this) {
    std::swap(high_, other->high_);
    std::swap(low_, other->low_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EntityId::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EntityId_descriptor_;
  metadata.reflection = EntityId_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Identity::kAccountIdFieldNumber;
const int Identity::kGameAccountIdFieldNumber;
#endif  // !_MSC_VER

Identity::Identity()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Identity)
}

void Identity::InitAsDefaultInstance() {
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

Identity::Identity(const Identity& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Identity)
}

void Identity::SharedCtor() {
  _cached_size_ = 0;
  account_id_ = NULL;
  game_account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Identity::~Identity() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Identity)
  SharedDtor();
}

void Identity::SharedDtor() {
  if (this != default_instance_) {
    delete account_id_;
    delete game_account_id_;
  }
}

void Identity::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Identity::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Identity_descriptor_;
}

const Identity& Identity::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_entity_5ftypes_2eproto();
  return *default_instance_;
}

Identity* Identity::default_instance_ = NULL;

Identity* Identity::New() const {
  return new Identity;
}

void Identity::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Identity::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Identity)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Identity)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Identity)
  return false;
#undef DO_
}

void Identity::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Identity)
  // optional .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_id(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Identity)
}

::google::protobuf::uint8* Identity::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Identity)
  // optional .bgs.protocol.EntityId account_id = 1;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_id(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Identity)
  return target;
}

int Identity::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId account_id = 1;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
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

void Identity::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Identity* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Identity*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Identity::MergeFrom(const Identity& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Identity::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Identity::CopyFrom(const Identity& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Identity::IsInitialized() const {

  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void Identity::Swap(Identity* other) {
  if (other != this) {
    std::swap(account_id_, other->account_id_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Identity::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Identity_descriptor_;
  metadata.reflection = Identity_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountInfo::kAccountPaidFieldNumber;
const int AccountInfo::kCountryIdFieldNumber;
const int AccountInfo::kBattleTagFieldNumber;
const int AccountInfo::kManualReviewFieldNumber;
const int AccountInfo::kIdentityFieldNumber;
const int AccountInfo::kAccountMutedFieldNumber;
#endif  // !_MSC_VER

AccountInfo::AccountInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.AccountInfo)
}

void AccountInfo::InitAsDefaultInstance() {
  identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
}

AccountInfo::AccountInfo(const AccountInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.AccountInfo)
}

void AccountInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  account_paid_ = false;
  country_id_ = 0u;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  manual_review_ = false;
  identity_ = NULL;
  account_muted_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountInfo::~AccountInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.AccountInfo)
  SharedDtor();
}

void AccountInfo::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete identity_;
  }
}

void AccountInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountInfo_descriptor_;
}

const AccountInfo& AccountInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_entity_5ftypes_2eproto();
  return *default_instance_;
}

AccountInfo* AccountInfo::default_instance_ = NULL;

AccountInfo* AccountInfo::New() const {
  return new AccountInfo;
}

void AccountInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(country_id_, account_muted_);
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    if (has_identity()) {
      if (identity_ != NULL) identity_->::bgs::protocol::Identity::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.AccountInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool account_paid = 1 [default = false];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &account_paid_)));
          set_has_account_paid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_country_id;
        break;
      }

      // optional fixed32 country_id = 2 [default = 0];
      case 2: {
        if (tag == 21) {
         parse_country_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &country_id_)));
          set_has_country_id();
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
        if (input->ExpectTag(32)) goto parse_manual_review;
        break;
      }

      // optional bool manual_review = 4 [default = false];
      case 4: {
        if (tag == 32) {
         parse_manual_review:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &manual_review_)));
          set_has_manual_review();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_identity;
        break;
      }

      // optional .bgs.protocol.Identity identity = 5;
      case 5: {
        if (tag == 42) {
         parse_identity:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_account_muted;
        break;
      }

      // optional bool account_muted = 6 [default = false];
      case 6: {
        if (tag == 48) {
         parse_account_muted:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &account_muted_)));
          set_has_account_muted();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.AccountInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.AccountInfo)
  return false;
#undef DO_
}

void AccountInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.AccountInfo)
  // optional bool account_paid = 1 [default = false];
  if (has_account_paid()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->account_paid(), output);
  }

  // optional fixed32 country_id = 2 [default = 0];
  if (has_country_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->country_id(), output);
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

  // optional bool manual_review = 4 [default = false];
  if (has_manual_review()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->manual_review(), output);
  }

  // optional .bgs.protocol.Identity identity = 5;
  if (has_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->identity(), output);
  }

  // optional bool account_muted = 6 [default = false];
  if (has_account_muted()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->account_muted(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.AccountInfo)
}

::google::protobuf::uint8* AccountInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.AccountInfo)
  // optional bool account_paid = 1 [default = false];
  if (has_account_paid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->account_paid(), target);
  }

  // optional fixed32 country_id = 2 [default = 0];
  if (has_country_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->country_id(), target);
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

  // optional bool manual_review = 4 [default = false];
  if (has_manual_review()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->manual_review(), target);
  }

  // optional .bgs.protocol.Identity identity = 5;
  if (has_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->identity(), target);
  }

  // optional bool account_muted = 6 [default = false];
  if (has_account_muted()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->account_muted(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.AccountInfo)
  return target;
}

int AccountInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool account_paid = 1 [default = false];
    if (has_account_paid()) {
      total_size += 1 + 1;
    }

    // optional fixed32 country_id = 2 [default = 0];
    if (has_country_id()) {
      total_size += 1 + 4;
    }

    // optional string battle_tag = 3;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional bool manual_review = 4 [default = false];
    if (has_manual_review()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.Identity identity = 5;
    if (has_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->identity());
    }

    // optional bool account_muted = 6 [default = false];
    if (has_account_muted()) {
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

void AccountInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountInfo::MergeFrom(const AccountInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_paid()) {
      set_account_paid(from.account_paid());
    }
    if (from.has_country_id()) {
      set_country_id(from.country_id());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_manual_review()) {
      set_manual_review(from.manual_review());
    }
    if (from.has_identity()) {
      mutable_identity()->::bgs::protocol::Identity::MergeFrom(from.identity());
    }
    if (from.has_account_muted()) {
      set_account_muted(from.account_muted());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountInfo::CopyFrom(const AccountInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountInfo::IsInitialized() const {

  if (has_identity()) {
    if (!this->identity().IsInitialized()) return false;
  }
  return true;
}

void AccountInfo::Swap(AccountInfo* other) {
  if (other != this) {
    std::swap(account_paid_, other->account_paid_);
    std::swap(country_id_, other->country_id_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(manual_review_, other->manual_review_);
    std::swap(identity_, other->identity_);
    std::swap(account_muted_, other->account_muted_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountInfo_descriptor_;
  metadata.reflection = AccountInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
