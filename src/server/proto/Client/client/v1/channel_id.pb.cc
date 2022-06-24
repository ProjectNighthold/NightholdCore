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
#include "client/v1/channel_id.pb.h"

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
namespace channel {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ChannelId_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChannelId_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_client_2fv1_2fchannel_5fid_2eproto() {
  protobuf_AddDesc_client_2fv1_2fchannel_5fid_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "client/v1/channel_id.proto");
  GOOGLE_CHECK(file != NULL);
  ChannelId_descriptor_ = file->message_type(0);
  static const int ChannelId_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelId, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelId, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelId, id_),
  };
  ChannelId_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChannelId_descriptor_,
      ChannelId::default_instance_,
      ChannelId_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelId, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelId, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChannelId));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_client_2fv1_2fchannel_5fid_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChannelId_descriptor_, &ChannelId::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_client_2fv1_2fchannel_5fid_2eproto() {
  delete ChannelId::default_instance_;
  delete ChannelId_reflection_;
}

void protobuf_AddDesc_client_2fv1_2fchannel_5fid_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\032client/v1/channel_id.proto\022\027bgs.protoc"
    "ol.channel.v1\032\017rpc_types.proto\"L\n\tChanne"
    "lId\022\014\n\004type\030\001 \001(\r\022%\n\004host\030\002 \001(\0132\027.bgs.pr"
    "otocol.ProcessId\022\n\n\002id\030\003 \001(\007B\002H\001", 152);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "client/v1/channel_id.proto", &protobuf_RegisterTypes);
  ChannelId::default_instance_ = new ChannelId();
  ChannelId::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_client_2fv1_2fchannel_5fid_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_client_2fv1_2fchannel_5fid_2eproto {
  StaticDescriptorInitializer_client_2fv1_2fchannel_5fid_2eproto() {
    protobuf_AddDesc_client_2fv1_2fchannel_5fid_2eproto();
  }
} static_descriptor_initializer_client_2fv1_2fchannel_5fid_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ChannelId::kTypeFieldNumber;
const int ChannelId::kHostFieldNumber;
const int ChannelId::kIdFieldNumber;
#endif  // !_MSC_VER

ChannelId::ChannelId()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ChannelId)
}

void ChannelId::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

ChannelId::ChannelId(const ChannelId& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ChannelId)
}

void ChannelId::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0u;
  host_ = NULL;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChannelId::~ChannelId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ChannelId)
  SharedDtor();
}

void ChannelId::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
  }
}

void ChannelId::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChannelId::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelId_descriptor_;
}

const ChannelId& ChannelId::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_client_2fv1_2fchannel_5fid_2eproto();
  return *default_instance_;
}

ChannelId* ChannelId::default_instance_ = NULL;

ChannelId* ChannelId::New() const {
  return new ChannelId;
}

void ChannelId::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChannelId*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(type_, id_);
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChannelId::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.ChannelId)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 type = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &type_)));
          set_has_type();
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
        if (input->ExpectTag(29)) goto parse_id;
        break;
      }

      // optional fixed32 id = 3;
      case 3: {
        if (tag == 29) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &id_)));
          set_has_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.ChannelId)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.ChannelId)
  return false;
#undef DO_
}

void ChannelId::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.ChannelId)
  // optional uint32 type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->type(), output);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->host(), output);
  }

  // optional fixed32 id = 3;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.ChannelId)
}

::google::protobuf::uint8* ChannelId::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ChannelId)
  // optional uint32 type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->type(), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->host(), target);
  }

  // optional fixed32 id = 3;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ChannelId)
  return target;
}

int ChannelId::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->type());
    }

    // optional .bgs.protocol.ProcessId host = 2;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional fixed32 id = 3;
    if (has_id()) {
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

void ChannelId::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChannelId* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChannelId*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChannelId::MergeFrom(const ChannelId& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChannelId::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChannelId::CopyFrom(const ChannelId& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChannelId::IsInitialized() const {

  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void ChannelId::Swap(ChannelId* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(host_, other->host_);
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChannelId::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChannelId_descriptor_;
  metadata.reflection = ChannelId_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
