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
#include "content_handle_types.pb.h"

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

const ::google::protobuf::Descriptor* ContentHandle_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ContentHandle_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_content_5fhandle_5ftypes_2eproto() {
  protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "content_handle_types.proto");
  GOOGLE_CHECK(file != NULL);
  ContentHandle_descriptor_ = file->message_type(0);
  static const int ContentHandle_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, usage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, proto_url_),
  };
  ContentHandle_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ContentHandle_descriptor_,
      ContentHandle::default_instance_,
      ContentHandle_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ContentHandle));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_content_5fhandle_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ContentHandle_descriptor_, &ContentHandle::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_content_5fhandle_5ftypes_2eproto() {
  delete ContentHandle::default_instance_;
  delete ContentHandle_reflection_;
}

void protobuf_AddDesc_content_5fhandle_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\032content_handle_types.proto\022\014bgs.protoc"
    "ol\"O\n\rContentHandle\022\016\n\006region\030\001 \002(\007\022\r\n\005u"
    "sage\030\002 \002(\007\022\014\n\004hash\030\003 \002(\014\022\021\n\tproto_url\030\004 "
    "\001(\tB%\n\rbnet.protocolB\022ContentHandleProto"
    "H\001", 162);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "content_handle_types.proto", &protobuf_RegisterTypes);
  ContentHandle::default_instance_ = new ContentHandle();
  ContentHandle::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_content_5fhandle_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_content_5fhandle_5ftypes_2eproto {
  StaticDescriptorInitializer_content_5fhandle_5ftypes_2eproto() {
    protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  }
} static_descriptor_initializer_content_5fhandle_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ContentHandle::kRegionFieldNumber;
const int ContentHandle::kUsageFieldNumber;
const int ContentHandle::kHashFieldNumber;
const int ContentHandle::kProtoUrlFieldNumber;
#endif  // !_MSC_VER

ContentHandle::ContentHandle()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.ContentHandle)
}

void ContentHandle::InitAsDefaultInstance() {
}

ContentHandle::ContentHandle(const ContentHandle& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.ContentHandle)
}

void ContentHandle::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  region_ = 0u;
  usage_ = 0u;
  hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proto_url_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ContentHandle::~ContentHandle() {
  // @@protoc_insertion_point(destructor:bgs.protocol.ContentHandle)
  SharedDtor();
}

void ContentHandle::SharedDtor() {
  if (hash_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete hash_;
  }
  if (proto_url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete proto_url_;
  }
  if (this != default_instance_) {
  }
}

void ContentHandle::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ContentHandle::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ContentHandle_descriptor_;
}

const ContentHandle& ContentHandle::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  return *default_instance_;
}

ContentHandle* ContentHandle::default_instance_ = NULL;

ContentHandle* ContentHandle::New() const {
  return new ContentHandle;
}

void ContentHandle::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ContentHandle*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(region_, usage_);
    if (has_hash()) {
      if (hash_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        hash_->clear();
      }
    }
    if (has_proto_url()) {
      if (proto_url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        proto_url_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ContentHandle::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.ContentHandle)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 region = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_usage;
        break;
      }

      // required fixed32 usage = 2;
      case 2: {
        if (tag == 21) {
         parse_usage:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &usage_)));
          set_has_usage();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_hash;
        break;
      }

      // required bytes hash = 3;
      case 3: {
        if (tag == 26) {
         parse_hash:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_hash()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_proto_url;
        break;
      }

      // optional string proto_url = 4;
      case 4: {
        if (tag == 34) {
         parse_proto_url:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proto_url()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->proto_url().data(), this->proto_url().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "proto_url");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.ContentHandle)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.ContentHandle)
  return false;
#undef DO_
}

void ContentHandle::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.ContentHandle)
  // required fixed32 region = 1;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->region(), output);
  }

  // required fixed32 usage = 2;
  if (has_usage()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->usage(), output);
  }

  // required bytes hash = 3;
  if (has_hash()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->hash(), output);
  }

  // optional string proto_url = 4;
  if (has_proto_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_url().data(), this->proto_url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_url");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->proto_url(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.ContentHandle)
}

::google::protobuf::uint8* ContentHandle::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.ContentHandle)
  // required fixed32 region = 1;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->region(), target);
  }

  // required fixed32 usage = 2;
  if (has_usage()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->usage(), target);
  }

  // required bytes hash = 3;
  if (has_hash()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->hash(), target);
  }

  // optional string proto_url = 4;
  if (has_proto_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_url().data(), this->proto_url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_url");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->proto_url(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.ContentHandle)
  return target;
}

int ContentHandle::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 region = 1;
    if (has_region()) {
      total_size += 1 + 4;
    }

    // required fixed32 usage = 2;
    if (has_usage()) {
      total_size += 1 + 4;
    }

    // required bytes hash = 3;
    if (has_hash()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->hash());
    }

    // optional string proto_url = 4;
    if (has_proto_url()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->proto_url());
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

void ContentHandle::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ContentHandle* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ContentHandle*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ContentHandle::MergeFrom(const ContentHandle& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_usage()) {
      set_usage(from.usage());
    }
    if (from.has_hash()) {
      set_hash(from.hash());
    }
    if (from.has_proto_url()) {
      set_proto_url(from.proto_url());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ContentHandle::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ContentHandle::CopyFrom(const ContentHandle& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContentHandle::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void ContentHandle::Swap(ContentHandle* other) {
  if (other != this) {
    std::swap(region_, other->region_);
    std::swap(usage_, other->usage_);
    std::swap(hash_, other->hash_);
    std::swap(proto_url_, other->proto_url_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ContentHandle::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ContentHandle_descriptor_;
  metadata.reflection = ContentHandle_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
