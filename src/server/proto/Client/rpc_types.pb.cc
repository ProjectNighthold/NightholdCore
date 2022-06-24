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
#include "rpc_types.pb.h"

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

const ::google::protobuf::Descriptor* NO_RESPONSE_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NO_RESPONSE_reflection_ = NULL;
const ::google::protobuf::Descriptor* Address_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Address_reflection_ = NULL;
const ::google::protobuf::Descriptor* ProcessId_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ProcessId_reflection_ = NULL;
const ::google::protobuf::Descriptor* ObjectAddress_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ObjectAddress_reflection_ = NULL;
const ::google::protobuf::Descriptor* NoData_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NoData_reflection_ = NULL;
const ::google::protobuf::Descriptor* ErrorInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ErrorInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* TraceInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TraceInfo_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* TraceInfo_Sampling_descriptor_ = NULL;
const ::google::protobuf::Descriptor* Header_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Header_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_rpc_5ftypes_2eproto() {
  protobuf_AddDesc_rpc_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rpc_types.proto");
  GOOGLE_CHECK(file != NULL);
  NO_RESPONSE_descriptor_ = file->message_type(0);
  static const int NO_RESPONSE_offsets_[1] = {
  };
  NO_RESPONSE_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      NO_RESPONSE_descriptor_,
      NO_RESPONSE::default_instance_,
      NO_RESPONSE_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NO_RESPONSE, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NO_RESPONSE, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(NO_RESPONSE));
  Address_descriptor_ = file->message_type(1);
  static const int Address_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Address, address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Address, port_),
  };
  Address_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Address_descriptor_,
      Address::default_instance_,
      Address_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Address, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Address, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Address));
  ProcessId_descriptor_ = file->message_type(2);
  static const int ProcessId_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProcessId, label_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProcessId, epoch_),
  };
  ProcessId_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ProcessId_descriptor_,
      ProcessId::default_instance_,
      ProcessId_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProcessId, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProcessId, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ProcessId));
  ObjectAddress_descriptor_ = file->message_type(3);
  static const int ObjectAddress_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjectAddress, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjectAddress, object_id_),
  };
  ObjectAddress_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ObjectAddress_descriptor_,
      ObjectAddress::default_instance_,
      ObjectAddress_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjectAddress, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjectAddress, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ObjectAddress));
  NoData_descriptor_ = file->message_type(4);
  static const int NoData_offsets_[1] = {
  };
  NoData_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      NoData_descriptor_,
      NoData::default_instance_,
      NoData_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NoData, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NoData, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(NoData));
  ErrorInfo_descriptor_ = file->message_type(5);
  static const int ErrorInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, object_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, service_hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, method_id_),
  };
  ErrorInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ErrorInfo_descriptor_,
      ErrorInfo::default_instance_,
      ErrorInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ErrorInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ErrorInfo));
  TraceInfo_descriptor_ = file->message_type(6);
  static const int TraceInfo_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, trace_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, span_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, parent_span_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, sampling_),
  };
  TraceInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TraceInfo_descriptor_,
      TraceInfo::default_instance_,
      TraceInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TraceInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TraceInfo));
  TraceInfo_Sampling_descriptor_ = TraceInfo_descriptor_->enum_type(0);
  Header_descriptor_ = file->message_type(7);
  static const int Header_offsets_[12] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, service_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, method_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, token_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, object_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, error_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, timeout_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, is_response_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, forward_targets_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, service_hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, trace_info_),
  };
  Header_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Header_descriptor_,
      Header::default_instance_,
      Header_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Header, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Header));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rpc_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    NO_RESPONSE_descriptor_, &NO_RESPONSE::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Address_descriptor_, &Address::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ProcessId_descriptor_, &ProcessId::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ObjectAddress_descriptor_, &ObjectAddress::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    NoData_descriptor_, &NoData::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ErrorInfo_descriptor_, &ErrorInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TraceInfo_descriptor_, &TraceInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Header_descriptor_, &Header::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rpc_5ftypes_2eproto() {
  delete NO_RESPONSE::default_instance_;
  delete NO_RESPONSE_reflection_;
  delete Address::default_instance_;
  delete Address_reflection_;
  delete ProcessId::default_instance_;
  delete ProcessId_reflection_;
  delete ObjectAddress::default_instance_;
  delete ObjectAddress_reflection_;
  delete NoData::default_instance_;
  delete NoData_reflection_;
  delete ErrorInfo::default_instance_;
  delete ErrorInfo_reflection_;
  delete TraceInfo::default_instance_;
  delete TraceInfo_reflection_;
  delete Header::default_instance_;
  delete Header_reflection_;
}

void protobuf_AddDesc_rpc_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_global_5fextensions_2fmethod_5foptions_2eproto();
  ::bgs::protocol::protobuf_AddDesc_global_5fextensions_2fservice_5foptions_2eproto();
  ::bgs::protocol::protobuf_AddDesc_global_5fextensions_2ffield_5foptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017rpc_types.proto\022\014bgs.protocol\032&global_"
    "extensions/method_options.proto\032\'global_"
    "extensions/service_options.proto\032%global"
    "_extensions/field_options.proto\"\r\n\013NO_RE"
    "SPONSE\"(\n\007Address\022\017\n\007address\030\001 \002(\t\022\014\n\004po"
    "rt\030\002 \001(\r\")\n\tProcessId\022\r\n\005label\030\001 \002(\r\022\r\n\005"
    "epoch\030\002 \002(\r\"L\n\rObjectAddress\022%\n\004host\030\001 \002"
    "(\0132\027.bgs.protocol.ProcessId\022\024\n\tobject_id"
    "\030\002 \001(\004:\0010\"\010\n\006NoData\"y\n\tErrorInfo\0223\n\016obje"
    "ct_address\030\001 \002(\0132\033.bgs.protocol.ObjectAd"
    "dress\022\016\n\006status\030\002 \002(\r\022\024\n\014service_hash\030\003 "
    "\002(\r\022\021\n\tmethod_id\030\004 \002(\r\"\275\001\n\tTraceInfo\022\022\n\n"
    "session_id\030\001 \001(\t\022\020\n\010trace_id\030\002 \001(\t\022\017\n\007sp"
    "an_id\030\003 \001(\t\022\026\n\016parent_span_id\030\004 \001(\t\0229\n\010s"
    "ampling\030\005 \001(\0162 .bgs.protocol.TraceInfo.S"
    "ampling:\005DEFER\"&\n\010Sampling\022\007\n\003YES\020\000\022\006\n\002N"
    "O\020\001\022\t\n\005DEFER\020\002\"\273\002\n\006Header\022\022\n\nservice_id\030"
    "\001 \002(\r\022\021\n\tmethod_id\030\002 \001(\r\022\r\n\005token\030\003 \002(\r\022"
    "\024\n\tobject_id\030\004 \001(\004:\0010\022\017\n\004size\030\005 \001(\r:\0010\022\021"
    "\n\006status\030\006 \001(\r:\0010\022&\n\005error\030\007 \003(\0132\027.bgs.p"
    "rotocol.ErrorInfo\022\017\n\007timeout\030\010 \001(\004\022\023\n\013is"
    "_response\030\t \001(\010\0220\n\017forward_targets\030\n \003(\013"
    "2\027.bgs.protocol.ProcessId\022\024\n\014service_has"
    "h\030\013 \001(\007\022+\n\ntrace_info\030\014 \001(\0132\027.bgs.protoc"
    "ol.TraceInfoB\033\n\rbnet.protocolB\010RpcProtoH"
    "\001P\000P\001P\002", 1007);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rpc_types.proto", &protobuf_RegisterTypes);
  NO_RESPONSE::default_instance_ = new NO_RESPONSE();
  Address::default_instance_ = new Address();
  ProcessId::default_instance_ = new ProcessId();
  ObjectAddress::default_instance_ = new ObjectAddress();
  NoData::default_instance_ = new NoData();
  ErrorInfo::default_instance_ = new ErrorInfo();
  TraceInfo::default_instance_ = new TraceInfo();
  Header::default_instance_ = new Header();
  NO_RESPONSE::default_instance_->InitAsDefaultInstance();
  Address::default_instance_->InitAsDefaultInstance();
  ProcessId::default_instance_->InitAsDefaultInstance();
  ObjectAddress::default_instance_->InitAsDefaultInstance();
  NoData::default_instance_->InitAsDefaultInstance();
  ErrorInfo::default_instance_->InitAsDefaultInstance();
  TraceInfo::default_instance_->InitAsDefaultInstance();
  Header::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rpc_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rpc_5ftypes_2eproto {
  StaticDescriptorInitializer_rpc_5ftypes_2eproto() {
    protobuf_AddDesc_rpc_5ftypes_2eproto();
  }
} static_descriptor_initializer_rpc_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

NO_RESPONSE::NO_RESPONSE()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.NO_RESPONSE)
}

void NO_RESPONSE::InitAsDefaultInstance() {
}

NO_RESPONSE::NO_RESPONSE(const NO_RESPONSE& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.NO_RESPONSE)
}

void NO_RESPONSE::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NO_RESPONSE::~NO_RESPONSE() {
  // @@protoc_insertion_point(destructor:bgs.protocol.NO_RESPONSE)
  SharedDtor();
}

void NO_RESPONSE::SharedDtor() {
  if (this != default_instance_) {
  }
}

void NO_RESPONSE::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NO_RESPONSE::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NO_RESPONSE_descriptor_;
}

const NO_RESPONSE& NO_RESPONSE::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

NO_RESPONSE* NO_RESPONSE::default_instance_ = NULL;

NO_RESPONSE* NO_RESPONSE::New() const {
  return new NO_RESPONSE;
}

void NO_RESPONSE::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool NO_RESPONSE::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.NO_RESPONSE)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.NO_RESPONSE)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.NO_RESPONSE)
  return false;
#undef DO_
}

void NO_RESPONSE::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.NO_RESPONSE)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.NO_RESPONSE)
}

::google::protobuf::uint8* NO_RESPONSE::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.NO_RESPONSE)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.NO_RESPONSE)
  return target;
}

int NO_RESPONSE::ByteSize() const {
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

void NO_RESPONSE::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const NO_RESPONSE* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const NO_RESPONSE*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NO_RESPONSE::MergeFrom(const NO_RESPONSE& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void NO_RESPONSE::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NO_RESPONSE::CopyFrom(const NO_RESPONSE& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NO_RESPONSE::IsInitialized() const {

  return true;
}

void NO_RESPONSE::Swap(NO_RESPONSE* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata NO_RESPONSE::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NO_RESPONSE_descriptor_;
  metadata.reflection = NO_RESPONSE_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Address::kAddressFieldNumber;
const int Address::kPortFieldNumber;
#endif  // !_MSC_VER

Address::Address()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Address)
}

void Address::InitAsDefaultInstance() {
}

Address::Address(const Address& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Address)
}

void Address::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Address::~Address() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Address)
  SharedDtor();
}

void Address::SharedDtor() {
  if (address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete address_;
  }
  if (this != default_instance_) {
  }
}

void Address::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Address::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Address_descriptor_;
}

const Address& Address::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

Address* Address::default_instance_ = NULL;

Address* Address::New() const {
  return new Address;
}

void Address::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_address()) {
      if (address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        address_->clear();
      }
    }
    port_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Address::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Address)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string address = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->address().data(), this->address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "address");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_port;
        break;
      }

      // optional uint32 port = 2;
      case 2: {
        if (tag == 16) {
         parse_port:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &port_)));
          set_has_port();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Address)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Address)
  return false;
#undef DO_
}

void Address::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Address)
  // required string address = 1;
  if (has_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->address().data(), this->address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->address(), output);
  }

  // optional uint32 port = 2;
  if (has_port()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->port(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Address)
}

::google::protobuf::uint8* Address::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Address)
  // required string address = 1;
  if (has_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->address().data(), this->address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->address(), target);
  }

  // optional uint32 port = 2;
  if (has_port()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->port(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Address)
  return target;
}

int Address::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string address = 1;
    if (has_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->address());
    }

    // optional uint32 port = 2;
    if (has_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->port());
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

void Address::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Address* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Address*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Address::MergeFrom(const Address& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_address()) {
      set_address(from.address());
    }
    if (from.has_port()) {
      set_port(from.port());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Address::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Address::CopyFrom(const Address& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Address::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Address::Swap(Address* other) {
  if (other != this) {
    std::swap(address_, other->address_);
    std::swap(port_, other->port_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Address::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Address_descriptor_;
  metadata.reflection = Address_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ProcessId::kLabelFieldNumber;
const int ProcessId::kEpochFieldNumber;
#endif  // !_MSC_VER

ProcessId::ProcessId()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.ProcessId)
}

void ProcessId::InitAsDefaultInstance() {
}

ProcessId::ProcessId(const ProcessId& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.ProcessId)
}

void ProcessId::SharedCtor() {
  _cached_size_ = 0;
  label_ = 0u;
  epoch_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ProcessId::~ProcessId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.ProcessId)
  SharedDtor();
}

void ProcessId::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ProcessId::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ProcessId::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ProcessId_descriptor_;
}

const ProcessId& ProcessId::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

ProcessId* ProcessId::default_instance_ = NULL;

ProcessId* ProcessId::New() const {
  return new ProcessId;
}

void ProcessId::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ProcessId*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(label_, epoch_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ProcessId::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.ProcessId)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 label = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &label_)));
          set_has_label();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_epoch;
        break;
      }

      // required uint32 epoch = 2;
      case 2: {
        if (tag == 16) {
         parse_epoch:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &epoch_)));
          set_has_epoch();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.ProcessId)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.ProcessId)
  return false;
#undef DO_
}

void ProcessId::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.ProcessId)
  // required uint32 label = 1;
  if (has_label()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->label(), output);
  }

  // required uint32 epoch = 2;
  if (has_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->epoch(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.ProcessId)
}

::google::protobuf::uint8* ProcessId::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.ProcessId)
  // required uint32 label = 1;
  if (has_label()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->label(), target);
  }

  // required uint32 epoch = 2;
  if (has_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->epoch(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.ProcessId)
  return target;
}

int ProcessId::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 label = 1;
    if (has_label()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->label());
    }

    // required uint32 epoch = 2;
    if (has_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->epoch());
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

void ProcessId::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ProcessId* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ProcessId*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ProcessId::MergeFrom(const ProcessId& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_label()) {
      set_label(from.label());
    }
    if (from.has_epoch()) {
      set_epoch(from.epoch());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ProcessId::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ProcessId::CopyFrom(const ProcessId& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProcessId::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void ProcessId::Swap(ProcessId* other) {
  if (other != this) {
    std::swap(label_, other->label_);
    std::swap(epoch_, other->epoch_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ProcessId::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ProcessId_descriptor_;
  metadata.reflection = ProcessId_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ObjectAddress::kHostFieldNumber;
const int ObjectAddress::kObjectIdFieldNumber;
#endif  // !_MSC_VER

ObjectAddress::ObjectAddress()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.ObjectAddress)
}

void ObjectAddress::InitAsDefaultInstance() {
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

ObjectAddress::ObjectAddress(const ObjectAddress& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.ObjectAddress)
}

void ObjectAddress::SharedCtor() {
  _cached_size_ = 0;
  host_ = NULL;
  object_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ObjectAddress::~ObjectAddress() {
  // @@protoc_insertion_point(destructor:bgs.protocol.ObjectAddress)
  SharedDtor();
}

void ObjectAddress::SharedDtor() {
  if (this != default_instance_) {
    delete host_;
  }
}

void ObjectAddress::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ObjectAddress::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ObjectAddress_descriptor_;
}

const ObjectAddress& ObjectAddress::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

ObjectAddress* ObjectAddress::default_instance_ = NULL;

ObjectAddress* ObjectAddress::New() const {
  return new ObjectAddress;
}

void ObjectAddress::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
    object_id_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ObjectAddress::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.ObjectAddress)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.ProcessId host = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_object_id;
        break;
      }

      // optional uint64 object_id = 2 [default = 0];
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.ObjectAddress)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.ObjectAddress)
  return false;
#undef DO_
}

void ObjectAddress::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.ObjectAddress)
  // required .bgs.protocol.ProcessId host = 1;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->host(), output);
  }

  // optional uint64 object_id = 2 [default = 0];
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->object_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.ObjectAddress)
}

::google::protobuf::uint8* ObjectAddress::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.ObjectAddress)
  // required .bgs.protocol.ProcessId host = 1;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->host(), target);
  }

  // optional uint64 object_id = 2 [default = 0];
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->object_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.ObjectAddress)
  return target;
}

int ObjectAddress::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.ProcessId host = 1;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional uint64 object_id = 2 [default = 0];
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

void ObjectAddress::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ObjectAddress* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ObjectAddress*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ObjectAddress::MergeFrom(const ObjectAddress& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ObjectAddress::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ObjectAddress::CopyFrom(const ObjectAddress& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObjectAddress::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  return true;
}

void ObjectAddress::Swap(ObjectAddress* other) {
  if (other != this) {
    std::swap(host_, other->host_);
    std::swap(object_id_, other->object_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ObjectAddress::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ObjectAddress_descriptor_;
  metadata.reflection = ObjectAddress_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

NoData::NoData()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.NoData)
}

void NoData::InitAsDefaultInstance() {
}

NoData::NoData(const NoData& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.NoData)
}

void NoData::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NoData::~NoData() {
  // @@protoc_insertion_point(destructor:bgs.protocol.NoData)
  SharedDtor();
}

void NoData::SharedDtor() {
  if (this != default_instance_) {
  }
}

void NoData::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NoData::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NoData_descriptor_;
}

const NoData& NoData::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

NoData* NoData::default_instance_ = NULL;

NoData* NoData::New() const {
  return new NoData;
}

void NoData::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool NoData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.NoData)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.NoData)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.NoData)
  return false;
#undef DO_
}

void NoData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.NoData)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.NoData)
}

::google::protobuf::uint8* NoData::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.NoData)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.NoData)
  return target;
}

int NoData::ByteSize() const {
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

void NoData::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const NoData* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const NoData*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NoData::MergeFrom(const NoData& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void NoData::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NoData::CopyFrom(const NoData& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NoData::IsInitialized() const {

  return true;
}

void NoData::Swap(NoData* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata NoData::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NoData_descriptor_;
  metadata.reflection = NoData_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ErrorInfo::kObjectAddressFieldNumber;
const int ErrorInfo::kStatusFieldNumber;
const int ErrorInfo::kServiceHashFieldNumber;
const int ErrorInfo::kMethodIdFieldNumber;
#endif  // !_MSC_VER

ErrorInfo::ErrorInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.ErrorInfo)
}

void ErrorInfo::InitAsDefaultInstance() {
  object_address_ = const_cast< ::bgs::protocol::ObjectAddress*>(&::bgs::protocol::ObjectAddress::default_instance());
}

ErrorInfo::ErrorInfo(const ErrorInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.ErrorInfo)
}

void ErrorInfo::SharedCtor() {
  _cached_size_ = 0;
  object_address_ = NULL;
  status_ = 0u;
  service_hash_ = 0u;
  method_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ErrorInfo::~ErrorInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.ErrorInfo)
  SharedDtor();
}

void ErrorInfo::SharedDtor() {
  if (this != default_instance_) {
    delete object_address_;
  }
}

void ErrorInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ErrorInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ErrorInfo_descriptor_;
}

const ErrorInfo& ErrorInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

ErrorInfo* ErrorInfo::default_instance_ = NULL;

ErrorInfo* ErrorInfo::New() const {
  return new ErrorInfo;
}

void ErrorInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ErrorInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(status_, method_id_);
    if (has_object_address()) {
      if (object_address_ != NULL) object_address_->::bgs::protocol::ObjectAddress::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ErrorInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.ErrorInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.ObjectAddress object_address = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_object_address()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_status;
        break;
      }

      // required uint32 status = 2;
      case 2: {
        if (tag == 16) {
         parse_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_service_hash;
        break;
      }

      // required uint32 service_hash = 3;
      case 3: {
        if (tag == 24) {
         parse_service_hash:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &service_hash_)));
          set_has_service_hash();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_method_id;
        break;
      }

      // required uint32 method_id = 4;
      case 4: {
        if (tag == 32) {
         parse_method_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &method_id_)));
          set_has_method_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.ErrorInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.ErrorInfo)
  return false;
#undef DO_
}

void ErrorInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.ErrorInfo)
  // required .bgs.protocol.ObjectAddress object_address = 1;
  if (has_object_address()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->object_address(), output);
  }

  // required uint32 status = 2;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->status(), output);
  }

  // required uint32 service_hash = 3;
  if (has_service_hash()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->service_hash(), output);
  }

  // required uint32 method_id = 4;
  if (has_method_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->method_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.ErrorInfo)
}

::google::protobuf::uint8* ErrorInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.ErrorInfo)
  // required .bgs.protocol.ObjectAddress object_address = 1;
  if (has_object_address()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->object_address(), target);
  }

  // required uint32 status = 2;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->status(), target);
  }

  // required uint32 service_hash = 3;
  if (has_service_hash()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->service_hash(), target);
  }

  // required uint32 method_id = 4;
  if (has_method_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->method_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.ErrorInfo)
  return target;
}

int ErrorInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.ObjectAddress object_address = 1;
    if (has_object_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->object_address());
    }

    // required uint32 status = 2;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->status());
    }

    // required uint32 service_hash = 3;
    if (has_service_hash()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->service_hash());
    }

    // required uint32 method_id = 4;
    if (has_method_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->method_id());
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

void ErrorInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ErrorInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ErrorInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ErrorInfo::MergeFrom(const ErrorInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_object_address()) {
      mutable_object_address()->::bgs::protocol::ObjectAddress::MergeFrom(from.object_address());
    }
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_service_hash()) {
      set_service_hash(from.service_hash());
    }
    if (from.has_method_id()) {
      set_method_id(from.method_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ErrorInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ErrorInfo::CopyFrom(const ErrorInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  if (has_object_address()) {
    if (!this->object_address().IsInitialized()) return false;
  }
  return true;
}

void ErrorInfo::Swap(ErrorInfo* other) {
  if (other != this) {
    std::swap(object_address_, other->object_address_);
    std::swap(status_, other->status_);
    std::swap(service_hash_, other->service_hash_);
    std::swap(method_id_, other->method_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ErrorInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ErrorInfo_descriptor_;
  metadata.reflection = ErrorInfo_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* TraceInfo_Sampling_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TraceInfo_Sampling_descriptor_;
}
bool TraceInfo_Sampling_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const TraceInfo_Sampling TraceInfo::YES;
const TraceInfo_Sampling TraceInfo::NO;
const TraceInfo_Sampling TraceInfo::DEFER;
const TraceInfo_Sampling TraceInfo::Sampling_MIN;
const TraceInfo_Sampling TraceInfo::Sampling_MAX;
const int TraceInfo::Sampling_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int TraceInfo::kSessionIdFieldNumber;
const int TraceInfo::kTraceIdFieldNumber;
const int TraceInfo::kSpanIdFieldNumber;
const int TraceInfo::kParentSpanIdFieldNumber;
const int TraceInfo::kSamplingFieldNumber;
#endif  // !_MSC_VER

TraceInfo::TraceInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.TraceInfo)
}

void TraceInfo::InitAsDefaultInstance() {
}

TraceInfo::TraceInfo(const TraceInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.TraceInfo)
}

void TraceInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  trace_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  span_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  parent_span_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sampling_ = 2;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TraceInfo::~TraceInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.TraceInfo)
  SharedDtor();
}

void TraceInfo::SharedDtor() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (trace_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete trace_id_;
  }
  if (span_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete span_id_;
  }
  if (parent_span_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete parent_span_id_;
  }
  if (this != default_instance_) {
  }
}

void TraceInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TraceInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TraceInfo_descriptor_;
}

const TraceInfo& TraceInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

TraceInfo* TraceInfo::default_instance_ = NULL;

TraceInfo* TraceInfo::New() const {
  return new TraceInfo;
}

void TraceInfo::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_session_id()) {
      if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        session_id_->clear();
      }
    }
    if (has_trace_id()) {
      if (trace_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        trace_id_->clear();
      }
    }
    if (has_span_id()) {
      if (span_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        span_id_->clear();
      }
    }
    if (has_parent_span_id()) {
      if (parent_span_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        parent_span_id_->clear();
      }
    }
    sampling_ = 2;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TraceInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.TraceInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string session_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_trace_id;
        break;
      }

      // optional string trace_id = 2;
      case 2: {
        if (tag == 18) {
         parse_trace_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_trace_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->trace_id().data(), this->trace_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "trace_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_span_id;
        break;
      }

      // optional string span_id = 3;
      case 3: {
        if (tag == 26) {
         parse_span_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_span_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->span_id().data(), this->span_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "span_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_parent_span_id;
        break;
      }

      // optional string parent_span_id = 4;
      case 4: {
        if (tag == 34) {
         parse_parent_span_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_parent_span_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->parent_span_id().data(), this->parent_span_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "parent_span_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_sampling;
        break;
      }

      // optional .bgs.protocol.TraceInfo.Sampling sampling = 5 [default = DEFER];
      case 5: {
        if (tag == 40) {
         parse_sampling:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::TraceInfo_Sampling_IsValid(value)) {
            set_sampling(static_cast< ::bgs::protocol::TraceInfo_Sampling >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.TraceInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.TraceInfo)
  return false;
#undef DO_
}

void TraceInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.TraceInfo)
  // optional string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->session_id(), output);
  }

  // optional string trace_id = 2;
  if (has_trace_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->trace_id().data(), this->trace_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "trace_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->trace_id(), output);
  }

  // optional string span_id = 3;
  if (has_span_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->span_id().data(), this->span_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "span_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->span_id(), output);
  }

  // optional string parent_span_id = 4;
  if (has_parent_span_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->parent_span_id().data(), this->parent_span_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "parent_span_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->parent_span_id(), output);
  }

  // optional .bgs.protocol.TraceInfo.Sampling sampling = 5 [default = DEFER];
  if (has_sampling()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->sampling(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.TraceInfo)
}

::google::protobuf::uint8* TraceInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.TraceInfo)
  // optional string session_id = 1;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->session_id(), target);
  }

  // optional string trace_id = 2;
  if (has_trace_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->trace_id().data(), this->trace_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "trace_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->trace_id(), target);
  }

  // optional string span_id = 3;
  if (has_span_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->span_id().data(), this->span_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "span_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->span_id(), target);
  }

  // optional string parent_span_id = 4;
  if (has_parent_span_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->parent_span_id().data(), this->parent_span_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "parent_span_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->parent_span_id(), target);
  }

  // optional .bgs.protocol.TraceInfo.Sampling sampling = 5 [default = DEFER];
  if (has_sampling()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->sampling(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.TraceInfo)
  return target;
}

int TraceInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string session_id = 1;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

    // optional string trace_id = 2;
    if (has_trace_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->trace_id());
    }

    // optional string span_id = 3;
    if (has_span_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->span_id());
    }

    // optional string parent_span_id = 4;
    if (has_parent_span_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->parent_span_id());
    }

    // optional .bgs.protocol.TraceInfo.Sampling sampling = 5 [default = DEFER];
    if (has_sampling()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->sampling());
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

void TraceInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TraceInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TraceInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TraceInfo::MergeFrom(const TraceInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
    if (from.has_trace_id()) {
      set_trace_id(from.trace_id());
    }
    if (from.has_span_id()) {
      set_span_id(from.span_id());
    }
    if (from.has_parent_span_id()) {
      set_parent_span_id(from.parent_span_id());
    }
    if (from.has_sampling()) {
      set_sampling(from.sampling());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TraceInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TraceInfo::CopyFrom(const TraceInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TraceInfo::IsInitialized() const {

  return true;
}

void TraceInfo::Swap(TraceInfo* other) {
  if (other != this) {
    std::swap(session_id_, other->session_id_);
    std::swap(trace_id_, other->trace_id_);
    std::swap(span_id_, other->span_id_);
    std::swap(parent_span_id_, other->parent_span_id_);
    std::swap(sampling_, other->sampling_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TraceInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TraceInfo_descriptor_;
  metadata.reflection = TraceInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Header::kServiceIdFieldNumber;
const int Header::kMethodIdFieldNumber;
const int Header::kTokenFieldNumber;
const int Header::kObjectIdFieldNumber;
const int Header::kSizeFieldNumber;
const int Header::kStatusFieldNumber;
const int Header::kErrorFieldNumber;
const int Header::kTimeoutFieldNumber;
const int Header::kIsResponseFieldNumber;
const int Header::kForwardTargetsFieldNumber;
const int Header::kServiceHashFieldNumber;
const int Header::kTraceInfoFieldNumber;
#endif  // !_MSC_VER

Header::Header()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Header)
}

void Header::InitAsDefaultInstance() {
  trace_info_ = const_cast< ::bgs::protocol::TraceInfo*>(&::bgs::protocol::TraceInfo::default_instance());
}

Header::Header(const Header& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Header)
}

void Header::SharedCtor() {
  _cached_size_ = 0;
  service_id_ = 0u;
  method_id_ = 0u;
  token_ = 0u;
  object_id_ = GOOGLE_ULONGLONG(0);
  size_ = 0u;
  status_ = 0u;
  timeout_ = GOOGLE_ULONGLONG(0);
  is_response_ = false;
  service_hash_ = 0u;
  trace_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Header::~Header() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Header)
  SharedDtor();
}

void Header::SharedDtor() {
  if (this != default_instance_) {
    delete trace_info_;
  }
}

void Header::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Header::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Header_descriptor_;
}

const Header& Header::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5ftypes_2eproto();
  return *default_instance_;
}

Header* Header::default_instance_ = NULL;

Header* Header::New() const {
  return new Header;
}

void Header::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Header*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 191) {
    ZR_(service_id_, size_);
    status_ = 0u;
    timeout_ = GOOGLE_ULONGLONG(0);
  }
  if (_has_bits_[8 / 32] & 3328) {
    is_response_ = false;
    service_hash_ = 0u;
    if (has_trace_info()) {
      if (trace_info_ != NULL) trace_info_->::bgs::protocol::TraceInfo::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  error_.Clear();
  forward_targets_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Header::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Header)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 service_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &service_id_)));
          set_has_service_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_method_id;
        break;
      }

      // optional uint32 method_id = 2;
      case 2: {
        if (tag == 16) {
         parse_method_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &method_id_)));
          set_has_method_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_token;
        break;
      }

      // required uint32 token = 3;
      case 3: {
        if (tag == 24) {
         parse_token:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &token_)));
          set_has_token();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_object_id;
        break;
      }

      // optional uint64 object_id = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_object_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &object_id_)));
          set_has_object_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_size;
        break;
      }

      // optional uint32 size = 5 [default = 0];
      case 5: {
        if (tag == 40) {
         parse_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &size_)));
          set_has_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_status;
        break;
      }

      // optional uint32 status = 6 [default = 0];
      case 6: {
        if (tag == 48) {
         parse_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_error;
        break;
      }

      // repeated .bgs.protocol.ErrorInfo error = 7;
      case 7: {
        if (tag == 58) {
         parse_error:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_error()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_error;
        if (input->ExpectTag(64)) goto parse_timeout;
        break;
      }

      // optional uint64 timeout = 8;
      case 8: {
        if (tag == 64) {
         parse_timeout:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &timeout_)));
          set_has_timeout();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_is_response;
        break;
      }

      // optional bool is_response = 9;
      case 9: {
        if (tag == 72) {
         parse_is_response:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_response_)));
          set_has_is_response();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_forward_targets;
        break;
      }

      // repeated .bgs.protocol.ProcessId forward_targets = 10;
      case 10: {
        if (tag == 82) {
         parse_forward_targets:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_forward_targets()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_forward_targets;
        if (input->ExpectTag(93)) goto parse_service_hash;
        break;
      }

      // optional fixed32 service_hash = 11;
      case 11: {
        if (tag == 93) {
         parse_service_hash:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &service_hash_)));
          set_has_service_hash();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_trace_info;
        break;
      }

      // optional .bgs.protocol.TraceInfo trace_info = 12;
      case 12: {
        if (tag == 98) {
         parse_trace_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_trace_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Header)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Header)
  return false;
#undef DO_
}

void Header::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Header)
  // required uint32 service_id = 1;
  if (has_service_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->service_id(), output);
  }

  // optional uint32 method_id = 2;
  if (has_method_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->method_id(), output);
  }

  // required uint32 token = 3;
  if (has_token()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->token(), output);
  }

  // optional uint64 object_id = 4 [default = 0];
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->object_id(), output);
  }

  // optional uint32 size = 5 [default = 0];
  if (has_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->size(), output);
  }

  // optional uint32 status = 6 [default = 0];
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->status(), output);
  }

  // repeated .bgs.protocol.ErrorInfo error = 7;
  for (int i = 0; i < this->error_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->error(i), output);
  }

  // optional uint64 timeout = 8;
  if (has_timeout()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(8, this->timeout(), output);
  }

  // optional bool is_response = 9;
  if (has_is_response()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->is_response(), output);
  }

  // repeated .bgs.protocol.ProcessId forward_targets = 10;
  for (int i = 0; i < this->forward_targets_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->forward_targets(i), output);
  }

  // optional fixed32 service_hash = 11;
  if (has_service_hash()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(11, this->service_hash(), output);
  }

  // optional .bgs.protocol.TraceInfo trace_info = 12;
  if (has_trace_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->trace_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Header)
}

::google::protobuf::uint8* Header::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Header)
  // required uint32 service_id = 1;
  if (has_service_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->service_id(), target);
  }

  // optional uint32 method_id = 2;
  if (has_method_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->method_id(), target);
  }

  // required uint32 token = 3;
  if (has_token()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->token(), target);
  }

  // optional uint64 object_id = 4 [default = 0];
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->object_id(), target);
  }

  // optional uint32 size = 5 [default = 0];
  if (has_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->size(), target);
  }

  // optional uint32 status = 6 [default = 0];
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->status(), target);
  }

  // repeated .bgs.protocol.ErrorInfo error = 7;
  for (int i = 0; i < this->error_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->error(i), target);
  }

  // optional uint64 timeout = 8;
  if (has_timeout()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(8, this->timeout(), target);
  }

  // optional bool is_response = 9;
  if (has_is_response()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->is_response(), target);
  }

  // repeated .bgs.protocol.ProcessId forward_targets = 10;
  for (int i = 0; i < this->forward_targets_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->forward_targets(i), target);
  }

  // optional fixed32 service_hash = 11;
  if (has_service_hash()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(11, this->service_hash(), target);
  }

  // optional .bgs.protocol.TraceInfo trace_info = 12;
  if (has_trace_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->trace_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Header)
  return target;
}

int Header::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 service_id = 1;
    if (has_service_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->service_id());
    }

    // optional uint32 method_id = 2;
    if (has_method_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->method_id());
    }

    // required uint32 token = 3;
    if (has_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->token());
    }

    // optional uint64 object_id = 4 [default = 0];
    if (has_object_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->object_id());
    }

    // optional uint32 size = 5 [default = 0];
    if (has_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->size());
    }

    // optional uint32 status = 6 [default = 0];
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->status());
    }

    // optional uint64 timeout = 8;
    if (has_timeout()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->timeout());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool is_response = 9;
    if (has_is_response()) {
      total_size += 1 + 1;
    }

    // optional fixed32 service_hash = 11;
    if (has_service_hash()) {
      total_size += 1 + 4;
    }

    // optional .bgs.protocol.TraceInfo trace_info = 12;
    if (has_trace_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->trace_info());
    }

  }
  // repeated .bgs.protocol.ErrorInfo error = 7;
  total_size += 1 * this->error_size();
  for (int i = 0; i < this->error_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->error(i));
  }

  // repeated .bgs.protocol.ProcessId forward_targets = 10;
  total_size += 1 * this->forward_targets_size();
  for (int i = 0; i < this->forward_targets_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->forward_targets(i));
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

void Header::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Header* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Header*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Header::MergeFrom(const Header& from) {
  GOOGLE_CHECK_NE(&from, this);
  error_.MergeFrom(from.error_);
  forward_targets_.MergeFrom(from.forward_targets_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_service_id()) {
      set_service_id(from.service_id());
    }
    if (from.has_method_id()) {
      set_method_id(from.method_id());
    }
    if (from.has_token()) {
      set_token(from.token());
    }
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
    if (from.has_size()) {
      set_size(from.size());
    }
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_timeout()) {
      set_timeout(from.timeout());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_is_response()) {
      set_is_response(from.is_response());
    }
    if (from.has_service_hash()) {
      set_service_hash(from.service_hash());
    }
    if (from.has_trace_info()) {
      mutable_trace_info()->::bgs::protocol::TraceInfo::MergeFrom(from.trace_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Header::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Header::CopyFrom(const Header& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Header::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->error())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->forward_targets())) return false;
  return true;
}

void Header::Swap(Header* other) {
  if (other != this) {
    std::swap(service_id_, other->service_id_);
    std::swap(method_id_, other->method_id_);
    std::swap(token_, other->token_);
    std::swap(object_id_, other->object_id_);
    std::swap(size_, other->size_);
    std::swap(status_, other->status_);
    error_.Swap(&other->error_);
    std::swap(timeout_, other->timeout_);
    std::swap(is_response_, other->is_response_);
    forward_targets_.Swap(&other->forward_targets_);
    std::swap(service_hash_, other->service_hash_);
    std::swap(trace_info_, other->trace_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Header::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Header_descriptor_;
  metadata.reflection = Header_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
