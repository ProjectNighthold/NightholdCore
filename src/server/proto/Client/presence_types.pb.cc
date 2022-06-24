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
#include "presence_types.pb.h"

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
namespace presence {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* RichPresenceLocalizationKey_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RichPresenceLocalizationKey_reflection_ = NULL;
const ::google::protobuf::Descriptor* FieldKey_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FieldKey_reflection_ = NULL;
const ::google::protobuf::Descriptor* Field_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Field_reflection_ = NULL;
const ::google::protobuf::Descriptor* FieldOperation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FieldOperation_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* FieldOperation_OperationType_descriptor_ = NULL;
const ::google::protobuf::Descriptor* ChannelState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChannelState_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_presence_5ftypes_2eproto() {
  protobuf_AddDesc_presence_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "presence_types.proto");
  GOOGLE_CHECK(file != NULL);
  RichPresenceLocalizationKey_descriptor_ = file->message_type(0);
  static const int RichPresenceLocalizationKey_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RichPresenceLocalizationKey, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RichPresenceLocalizationKey, stream_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RichPresenceLocalizationKey, localization_id_),
  };
  RichPresenceLocalizationKey_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RichPresenceLocalizationKey_descriptor_,
      RichPresenceLocalizationKey::default_instance_,
      RichPresenceLocalizationKey_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RichPresenceLocalizationKey, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RichPresenceLocalizationKey, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RichPresenceLocalizationKey));
  FieldKey_descriptor_ = file->message_type(1);
  static const int FieldKey_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, group_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, field_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, unique_id_),
  };
  FieldKey_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FieldKey_descriptor_,
      FieldKey::default_instance_,
      FieldKey_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldKey, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FieldKey));
  Field_descriptor_ = file->message_type(2);
  static const int Field_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Field, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Field, value_),
  };
  Field_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Field_descriptor_,
      Field::default_instance_,
      Field_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Field, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Field, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Field));
  FieldOperation_descriptor_ = file->message_type(3);
  static const int FieldOperation_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldOperation, field_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldOperation, operation_),
  };
  FieldOperation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FieldOperation_descriptor_,
      FieldOperation::default_instance_,
      FieldOperation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldOperation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FieldOperation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FieldOperation));
  FieldOperation_OperationType_descriptor_ = FieldOperation_descriptor_->enum_type(0);
  ChannelState_descriptor_ = file->message_type(4);
  static const int ChannelState_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, field_operation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, healing_),
  };
  ChannelState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChannelState_descriptor_,
      ChannelState::default_instance_,
      ChannelState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChannelState));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_presence_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RichPresenceLocalizationKey_descriptor_, &RichPresenceLocalizationKey::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FieldKey_descriptor_, &FieldKey::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Field_descriptor_, &Field::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FieldOperation_descriptor_, &FieldOperation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChannelState_descriptor_, &ChannelState::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_presence_5ftypes_2eproto() {
  delete RichPresenceLocalizationKey::default_instance_;
  delete RichPresenceLocalizationKey_reflection_;
  delete FieldKey::default_instance_;
  delete FieldKey_reflection_;
  delete Field::default_instance_;
  delete Field_reflection_;
  delete FieldOperation::default_instance_;
  delete FieldOperation_reflection_;
  delete ChannelState::default_instance_;
  delete ChannelState_reflection_;
}

void protobuf_AddDesc_presence_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::channel::v1::protobuf_AddDesc_channel_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024presence_types.proto\022\030bgs.protocol.pre"
    "sence.v1\032\025attribute_types.proto\032\022entity_"
    "types.proto\032\023channel_types.proto\"W\n\033Rich"
    "PresenceLocalizationKey\022\017\n\007program\030\001 \002(\007"
    "\022\016\n\006stream\030\002 \002(\007\022\027\n\017localization_id\030\003 \002("
    "\r\"O\n\010FieldKey\022\017\n\007program\030\001 \002(\r\022\r\n\005group\030"
    "\002 \002(\r\022\r\n\005field\030\003 \002(\r\022\024\n\tunique_id\030\004 \001(\004:"
    "\0010\"^\n\005Field\022/\n\003key\030\001 \002(\0132\".bgs.protocol."
    "presence.v1.FieldKey\022$\n\005value\030\002 \002(\0132\025.bg"
    "s.protocol.Variant\"\265\001\n\016FieldOperation\022.\n"
    "\005field\030\001 \002(\0132\037.bgs.protocol.presence.v1."
    "Field\022N\n\toperation\030\002 \001(\01626.bgs.protocol."
    "presence.v1.FieldOperation.OperationType"
    ":\003SET\"#\n\rOperationType\022\007\n\003SET\020\000\022\t\n\005CLEAR"
    "\020\001\"\365\001\n\014ChannelState\022)\n\tentity_id\030\001 \001(\0132\026"
    ".bgs.protocol.EntityId\022A\n\017field_operatio"
    "n\030\002 \003(\0132(.bgs.protocol.presence.v1.Field"
    "Operation\022\026\n\007healing\030\003 \001(\010:\005false2_\n\010pre"
    "sence\022%.bgs.protocol.channel.v1.ChannelS"
    "tate\030e \001(\0132&.bgs.protocol.presence.v1.Ch"
    "annelStateB\002H\001", 814);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "presence_types.proto", &protobuf_RegisterTypes);
  RichPresenceLocalizationKey::default_instance_ = new RichPresenceLocalizationKey();
  FieldKey::default_instance_ = new FieldKey();
  Field::default_instance_ = new Field();
  FieldOperation::default_instance_ = new FieldOperation();
  ChannelState::default_instance_ = new ChannelState();
  RichPresenceLocalizationKey::default_instance_->InitAsDefaultInstance();
  FieldKey::default_instance_->InitAsDefaultInstance();
  Field::default_instance_->InitAsDefaultInstance();
  FieldOperation::default_instance_->InitAsDefaultInstance();
  ChannelState::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
    &::bgs::protocol::channel::v1::ChannelState::default_instance(),
    101, 11, false, false,
    &::bgs::protocol::presence::v1::ChannelState::default_instance());
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_presence_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_presence_5ftypes_2eproto {
  StaticDescriptorInitializer_presence_5ftypes_2eproto() {
    protobuf_AddDesc_presence_5ftypes_2eproto();
  }
} static_descriptor_initializer_presence_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RichPresenceLocalizationKey::kProgramFieldNumber;
const int RichPresenceLocalizationKey::kStreamFieldNumber;
const int RichPresenceLocalizationKey::kLocalizationIdFieldNumber;
#endif  // !_MSC_VER

RichPresenceLocalizationKey::RichPresenceLocalizationKey()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
}

void RichPresenceLocalizationKey::InitAsDefaultInstance() {
}

RichPresenceLocalizationKey::RichPresenceLocalizationKey(const RichPresenceLocalizationKey& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
}

void RichPresenceLocalizationKey::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  stream_ = 0u;
  localization_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RichPresenceLocalizationKey::~RichPresenceLocalizationKey() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  SharedDtor();
}

void RichPresenceLocalizationKey::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RichPresenceLocalizationKey::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RichPresenceLocalizationKey::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RichPresenceLocalizationKey_descriptor_;
}

const RichPresenceLocalizationKey& RichPresenceLocalizationKey::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5ftypes_2eproto();
  return *default_instance_;
}

RichPresenceLocalizationKey* RichPresenceLocalizationKey::default_instance_ = NULL;

RichPresenceLocalizationKey* RichPresenceLocalizationKey::New() const {
  return new RichPresenceLocalizationKey;
}

void RichPresenceLocalizationKey::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RichPresenceLocalizationKey*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(program_, localization_id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RichPresenceLocalizationKey::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 program = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_stream;
        break;
      }

      // required fixed32 stream = 2;
      case 2: {
        if (tag == 21) {
         parse_stream:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &stream_)));
          set_has_stream();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_localization_id;
        break;
      }

      // required uint32 localization_id = 3;
      case 3: {
        if (tag == 24) {
         parse_localization_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &localization_id_)));
          set_has_localization_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  return false;
#undef DO_
}

void RichPresenceLocalizationKey::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  // required fixed32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->program(), output);
  }

  // required fixed32 stream = 2;
  if (has_stream()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->stream(), output);
  }

  // required uint32 localization_id = 3;
  if (has_localization_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->localization_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
}

::google::protobuf::uint8* RichPresenceLocalizationKey::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  // required fixed32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->program(), target);
  }

  // required fixed32 stream = 2;
  if (has_stream()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->stream(), target);
  }

  // required uint32 localization_id = 3;
  if (has_localization_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->localization_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.RichPresenceLocalizationKey)
  return target;
}

int RichPresenceLocalizationKey::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 program = 1;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // required fixed32 stream = 2;
    if (has_stream()) {
      total_size += 1 + 4;
    }

    // required uint32 localization_id = 3;
    if (has_localization_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->localization_id());
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

void RichPresenceLocalizationKey::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RichPresenceLocalizationKey* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RichPresenceLocalizationKey*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RichPresenceLocalizationKey::MergeFrom(const RichPresenceLocalizationKey& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_stream()) {
      set_stream(from.stream());
    }
    if (from.has_localization_id()) {
      set_localization_id(from.localization_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RichPresenceLocalizationKey::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RichPresenceLocalizationKey::CopyFrom(const RichPresenceLocalizationKey& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RichPresenceLocalizationKey::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void RichPresenceLocalizationKey::Swap(RichPresenceLocalizationKey* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(stream_, other->stream_);
    std::swap(localization_id_, other->localization_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RichPresenceLocalizationKey::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RichPresenceLocalizationKey_descriptor_;
  metadata.reflection = RichPresenceLocalizationKey_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FieldKey::kProgramFieldNumber;
const int FieldKey::kGroupFieldNumber;
const int FieldKey::kFieldFieldNumber;
const int FieldKey::kUniqueIdFieldNumber;
#endif  // !_MSC_VER

FieldKey::FieldKey()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.FieldKey)
}

void FieldKey::InitAsDefaultInstance() {
}

FieldKey::FieldKey(const FieldKey& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.FieldKey)
}

void FieldKey::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  group_ = 0u;
  field_ = 0u;
  unique_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FieldKey::~FieldKey() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.FieldKey)
  SharedDtor();
}

void FieldKey::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FieldKey::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FieldKey::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FieldKey_descriptor_;
}

const FieldKey& FieldKey::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5ftypes_2eproto();
  return *default_instance_;
}

FieldKey* FieldKey::default_instance_ = NULL;

FieldKey* FieldKey::New() const {
  return new FieldKey;
}

void FieldKey::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<FieldKey*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(program_, field_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FieldKey::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.FieldKey)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 program = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_group;
        break;
      }

      // required uint32 group = 2;
      case 2: {
        if (tag == 16) {
         parse_group:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &group_)));
          set_has_group();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_field;
        break;
      }

      // required uint32 field = 3;
      case 3: {
        if (tag == 24) {
         parse_field:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &field_)));
          set_has_field();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_unique_id;
        break;
      }

      // optional uint64 unique_id = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_unique_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &unique_id_)));
          set_has_unique_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.FieldKey)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.FieldKey)
  return false;
#undef DO_
}

void FieldKey::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.FieldKey)
  // required uint32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->program(), output);
  }

  // required uint32 group = 2;
  if (has_group()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->group(), output);
  }

  // required uint32 field = 3;
  if (has_field()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->field(), output);
  }

  // optional uint64 unique_id = 4 [default = 0];
  if (has_unique_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->unique_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.FieldKey)
}

::google::protobuf::uint8* FieldKey::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.FieldKey)
  // required uint32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->program(), target);
  }

  // required uint32 group = 2;
  if (has_group()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->group(), target);
  }

  // required uint32 field = 3;
  if (has_field()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->field(), target);
  }

  // optional uint64 unique_id = 4 [default = 0];
  if (has_unique_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->unique_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.FieldKey)
  return target;
}

int FieldKey::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 program = 1;
    if (has_program()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->program());
    }

    // required uint32 group = 2;
    if (has_group()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->group());
    }

    // required uint32 field = 3;
    if (has_field()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->field());
    }

    // optional uint64 unique_id = 4 [default = 0];
    if (has_unique_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->unique_id());
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

void FieldKey::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FieldKey* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FieldKey*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FieldKey::MergeFrom(const FieldKey& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_group()) {
      set_group(from.group());
    }
    if (from.has_field()) {
      set_field(from.field());
    }
    if (from.has_unique_id()) {
      set_unique_id(from.unique_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FieldKey::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FieldKey::CopyFrom(const FieldKey& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FieldKey::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void FieldKey::Swap(FieldKey* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(group_, other->group_);
    std::swap(field_, other->field_);
    std::swap(unique_id_, other->unique_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FieldKey::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FieldKey_descriptor_;
  metadata.reflection = FieldKey_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Field::kKeyFieldNumber;
const int Field::kValueFieldNumber;
#endif  // !_MSC_VER

Field::Field()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.Field)
}

void Field::InitAsDefaultInstance() {
  key_ = const_cast< ::bgs::protocol::presence::v1::FieldKey*>(&::bgs::protocol::presence::v1::FieldKey::default_instance());
  value_ = const_cast< ::bgs::protocol::Variant*>(&::bgs::protocol::Variant::default_instance());
}

Field::Field(const Field& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.Field)
}

void Field::SharedCtor() {
  _cached_size_ = 0;
  key_ = NULL;
  value_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Field::~Field() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.Field)
  SharedDtor();
}

void Field::SharedDtor() {
  if (this != default_instance_) {
    delete key_;
    delete value_;
  }
}

void Field::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Field::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Field_descriptor_;
}

const Field& Field::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5ftypes_2eproto();
  return *default_instance_;
}

Field* Field::default_instance_ = NULL;

Field* Field::New() const {
  return new Field;
}

void Field::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_key()) {
      if (key_ != NULL) key_->::bgs::protocol::presence::v1::FieldKey::Clear();
    }
    if (has_value()) {
      if (value_ != NULL) value_->::bgs::protocol::Variant::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Field::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.Field)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.presence.v1.FieldKey key = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_key()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_value;
        break;
      }

      // required .bgs.protocol.Variant value = 2;
      case 2: {
        if (tag == 18) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_value()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.Field)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.Field)
  return false;
#undef DO_
}

void Field::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.Field)
  // required .bgs.protocol.presence.v1.FieldKey key = 1;
  if (has_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->key(), output);
  }

  // required .bgs.protocol.Variant value = 2;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->value(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.Field)
}

::google::protobuf::uint8* Field::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.Field)
  // required .bgs.protocol.presence.v1.FieldKey key = 1;
  if (has_key()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->key(), target);
  }

  // required .bgs.protocol.Variant value = 2;
  if (has_value()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->value(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.Field)
  return target;
}

int Field::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.presence.v1.FieldKey key = 1;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->key());
    }

    // required .bgs.protocol.Variant value = 2;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->value());
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

void Field::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Field* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Field*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Field::MergeFrom(const Field& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_key()) {
      mutable_key()->::bgs::protocol::presence::v1::FieldKey::MergeFrom(from.key());
    }
    if (from.has_value()) {
      mutable_value()->::bgs::protocol::Variant::MergeFrom(from.value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Field::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Field::CopyFrom(const Field& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Field::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_key()) {
    if (!this->key().IsInitialized()) return false;
  }
  if (has_value()) {
    if (!this->value().IsInitialized()) return false;
  }
  return true;
}

void Field::Swap(Field* other) {
  if (other != this) {
    std::swap(key_, other->key_);
    std::swap(value_, other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Field::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Field_descriptor_;
  metadata.reflection = Field_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* FieldOperation_OperationType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FieldOperation_OperationType_descriptor_;
}
bool FieldOperation_OperationType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const FieldOperation_OperationType FieldOperation::SET;
const FieldOperation_OperationType FieldOperation::CLEAR;
const FieldOperation_OperationType FieldOperation::OperationType_MIN;
const FieldOperation_OperationType FieldOperation::OperationType_MAX;
const int FieldOperation::OperationType_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int FieldOperation::kFieldFieldNumber;
const int FieldOperation::kOperationFieldNumber;
#endif  // !_MSC_VER

FieldOperation::FieldOperation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.FieldOperation)
}

void FieldOperation::InitAsDefaultInstance() {
  field_ = const_cast< ::bgs::protocol::presence::v1::Field*>(&::bgs::protocol::presence::v1::Field::default_instance());
}

FieldOperation::FieldOperation(const FieldOperation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.FieldOperation)
}

void FieldOperation::SharedCtor() {
  _cached_size_ = 0;
  field_ = NULL;
  operation_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FieldOperation::~FieldOperation() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.FieldOperation)
  SharedDtor();
}

void FieldOperation::SharedDtor() {
  if (this != default_instance_) {
    delete field_;
  }
}

void FieldOperation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FieldOperation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FieldOperation_descriptor_;
}

const FieldOperation& FieldOperation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5ftypes_2eproto();
  return *default_instance_;
}

FieldOperation* FieldOperation::default_instance_ = NULL;

FieldOperation* FieldOperation::New() const {
  return new FieldOperation;
}

void FieldOperation::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_field()) {
      if (field_ != NULL) field_->::bgs::protocol::presence::v1::Field::Clear();
    }
    operation_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FieldOperation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.FieldOperation)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.presence.v1.Field field = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_field()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_operation;
        break;
      }

      // optional .bgs.protocol.presence.v1.FieldOperation.OperationType operation = 2 [default = SET];
      case 2: {
        if (tag == 16) {
         parse_operation:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::presence::v1::FieldOperation_OperationType_IsValid(value)) {
            set_operation(static_cast< ::bgs::protocol::presence::v1::FieldOperation_OperationType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.FieldOperation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.FieldOperation)
  return false;
#undef DO_
}

void FieldOperation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.FieldOperation)
  // required .bgs.protocol.presence.v1.Field field = 1;
  if (has_field()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->field(), output);
  }

  // optional .bgs.protocol.presence.v1.FieldOperation.OperationType operation = 2 [default = SET];
  if (has_operation()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->operation(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.FieldOperation)
}

::google::protobuf::uint8* FieldOperation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.FieldOperation)
  // required .bgs.protocol.presence.v1.Field field = 1;
  if (has_field()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->field(), target);
  }

  // optional .bgs.protocol.presence.v1.FieldOperation.OperationType operation = 2 [default = SET];
  if (has_operation()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->operation(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.FieldOperation)
  return target;
}

int FieldOperation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.presence.v1.Field field = 1;
    if (has_field()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->field());
    }

    // optional .bgs.protocol.presence.v1.FieldOperation.OperationType operation = 2 [default = SET];
    if (has_operation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->operation());
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

void FieldOperation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FieldOperation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FieldOperation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FieldOperation::MergeFrom(const FieldOperation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_field()) {
      mutable_field()->::bgs::protocol::presence::v1::Field::MergeFrom(from.field());
    }
    if (from.has_operation()) {
      set_operation(from.operation());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FieldOperation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FieldOperation::CopyFrom(const FieldOperation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FieldOperation::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_field()) {
    if (!this->field().IsInitialized()) return false;
  }
  return true;
}

void FieldOperation::Swap(FieldOperation* other) {
  if (other != this) {
    std::swap(field_, other->field_);
    std::swap(operation_, other->operation_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FieldOperation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FieldOperation_descriptor_;
  metadata.reflection = FieldOperation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChannelState::kEntityIdFieldNumber;
const int ChannelState::kFieldOperationFieldNumber;
const int ChannelState::kHealingFieldNumber;
#endif  // !_MSC_VER

#ifndef _MSC_VER
const int ChannelState::kPresenceFieldNumber;
#endif
::google::protobuf::internal::ExtensionIdentifier< ::bgs::protocol::channel::v1::ChannelState,
    ::google::protobuf::internal::MessageTypeTraits< ::bgs::protocol::presence::v1::ChannelState >, 11, false >
  ChannelState::presence(kPresenceFieldNumber, ::bgs::protocol::presence::v1::ChannelState::default_instance());
ChannelState::ChannelState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.ChannelState)
}

void ChannelState::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

ChannelState::ChannelState(const ChannelState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.ChannelState)
}

void ChannelState::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  healing_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChannelState::~ChannelState() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.ChannelState)
  SharedDtor();
}

void ChannelState::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void ChannelState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChannelState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelState_descriptor_;
}

const ChannelState& ChannelState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_presence_5ftypes_2eproto();
  return *default_instance_;
}

ChannelState* ChannelState::default_instance_ = NULL;

ChannelState* ChannelState::New() const {
  return new ChannelState;
}

void ChannelState::Clear() {
  if (_has_bits_[0 / 32] & 5) {
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    healing_ = false;
  }
  field_operation_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChannelState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.presence.v1.ChannelState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
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
        if (input->ExpectTag(24)) goto parse_healing;
        break;
      }

      // optional bool healing = 3 [default = false];
      case 3: {
        if (tag == 24) {
         parse_healing:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &healing_)));
          set_has_healing();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.presence.v1.ChannelState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.presence.v1.ChannelState)
  return false;
#undef DO_
}

void ChannelState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.presence.v1.ChannelState)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // repeated .bgs.protocol.presence.v1.FieldOperation field_operation = 2;
  for (int i = 0; i < this->field_operation_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->field_operation(i), output);
  }

  // optional bool healing = 3 [default = false];
  if (has_healing()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->healing(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.presence.v1.ChannelState)
}

::google::protobuf::uint8* ChannelState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.ChannelState)
  // optional .bgs.protocol.EntityId entity_id = 1;
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

  // optional bool healing = 3 [default = false];
  if (has_healing()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->healing(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.ChannelState)
  return target;
}

int ChannelState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional bool healing = 3 [default = false];
    if (has_healing()) {
      total_size += 1 + 1;
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

void ChannelState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChannelState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChannelState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChannelState::MergeFrom(const ChannelState& from) {
  GOOGLE_CHECK_NE(&from, this);
  field_operation_.MergeFrom(from.field_operation_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_healing()) {
      set_healing(from.healing());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChannelState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChannelState::CopyFrom(const ChannelState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChannelState::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->field_operation())) return false;
  return true;
}

void ChannelState::Swap(ChannelState* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    field_operation_.Swap(&other->field_operation_);
    std::swap(healing_, other->healing_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChannelState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChannelState_descriptor_;
  metadata.reflection = ChannelState_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace presence
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
