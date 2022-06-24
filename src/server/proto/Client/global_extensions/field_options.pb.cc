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
#include "global_extensions/field_options.pb.h"

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

const ::google::protobuf::EnumDescriptor* LogOption_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_global_5fextensions_2ffield_5foptions_2eproto() {
  protobuf_AddDesc_global_5fextensions_2ffield_5foptions_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "global_extensions/field_options.proto");
  GOOGLE_CHECK(file != NULL);
  LogOption_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_global_5fextensions_2ffield_5foptions_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_global_5fextensions_2ffield_5foptions_2eproto() {
}

void protobuf_AddDesc_global_5fextensions_2ffield_5foptions_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2fdescriptor_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n%global_extensions/field_options.proto\022"
    "\014bgs.protocol\032 google/protobuf/descripto"
    "r.proto* \n\tLogOption\022\n\n\006HIDDEN\020\001\022\007\n\003HEX\020"
    "\002:E\n\003log\022\035.google.protobuf.FieldOptions\030"
    "\320\206\003 \001(\0162\027.bgs.protocol.LogOptionB$\n\rbnet"
    ".protocolB\021FieldOptionsProtoH\001", 230);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "global_extensions/field_options.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::ExtensionSet::RegisterEnumExtension(
    &::google::protobuf::FieldOptions::default_instance(),
    50000, 14, false, false,
    &::bgs::protocol::LogOption_IsValid);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_global_5fextensions_2ffield_5foptions_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_global_5fextensions_2ffield_5foptions_2eproto {
  StaticDescriptorInitializer_global_5fextensions_2ffield_5foptions_2eproto() {
    protobuf_AddDesc_global_5fextensions_2ffield_5foptions_2eproto();
  }
} static_descriptor_initializer_global_5fextensions_2ffield_5foptions_2eproto_;
const ::google::protobuf::EnumDescriptor* LogOption_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogOption_descriptor_;
}
bool LogOption_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::google::protobuf::internal::EnumTypeTraits< ::bgs::protocol::LogOption, ::bgs::protocol::LogOption_IsValid>, 14, false >
  log(kLogFieldNumber, static_cast< ::bgs::protocol::LogOption >(1));

// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
