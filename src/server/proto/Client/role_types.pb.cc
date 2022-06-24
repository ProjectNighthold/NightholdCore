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
#include "role_types.pb.h"

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

const ::google::protobuf::Descriptor* Role_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Role_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_role_5ftypes_2eproto() {
  protobuf_AddDesc_role_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "role_types.proto");
  GOOGLE_CHECK(file != NULL);
  Role_descriptor_ = file->message_type(0);
  static const int Role_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, privilege_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, assignable_role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, required_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, unique_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, relegation_role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, kickable_role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, removable_role_),
  };
  Role_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Role_descriptor_,
      Role::default_instance_,
      Role_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Role, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Role));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_role_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Role_descriptor_, &Role::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_role_5ftypes_2eproto() {
  delete Role::default_instance_;
  delete Role_reflection_;
}

void protobuf_AddDesc_role_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020role_types.proto\022\014bgs.protocol\032\025attrib"
    "ute_types.proto\"\374\001\n\004Role\022\n\n\002id\030\001 \002(\r\022\014\n\004"
    "name\030\002 \002(\t\022\021\n\tprivilege\030\003 \003(\t\022\033\n\017assigna"
    "ble_role\030\004 \003(\rB\002\020\001\022\027\n\010required\030\005 \001(\010:\005fa"
    "lse\022\025\n\006unique\030\006 \001(\010:\005false\022\027\n\017relegation"
    "_role\030\007 \001(\r\022*\n\tattribute\030\010 \003(\0132\027.bgs.pro"
    "tocol.Attribute\022\031\n\rkickable_role\030\t \003(\rB\002"
    "\020\001\022\032\n\016removable_role\030\n \003(\rB\002\020\001B\002H\001", 314);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "role_types.proto", &protobuf_RegisterTypes);
  Role::default_instance_ = new Role();
  Role::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_role_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_role_5ftypes_2eproto {
  StaticDescriptorInitializer_role_5ftypes_2eproto() {
    protobuf_AddDesc_role_5ftypes_2eproto();
  }
} static_descriptor_initializer_role_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Role::kIdFieldNumber;
const int Role::kNameFieldNumber;
const int Role::kPrivilegeFieldNumber;
const int Role::kAssignableRoleFieldNumber;
const int Role::kRequiredFieldNumber;
const int Role::kUniqueFieldNumber;
const int Role::kRelegationRoleFieldNumber;
const int Role::kAttributeFieldNumber;
const int Role::kKickableRoleFieldNumber;
const int Role::kRemovableRoleFieldNumber;
#endif  // !_MSC_VER

Role::Role()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Role)
}

void Role::InitAsDefaultInstance() {
}

Role::Role(const Role& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Role)
}

void Role::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _assignable_role_cached_byte_size_ = 0;
  required_ = false;
  unique_ = false;
  relegation_role_ = 0u;
  _kickable_role_cached_byte_size_ = 0;
  _removable_role_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Role::~Role() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Role)
  SharedDtor();
}

void Role::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void Role::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Role::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Role_descriptor_;
}

const Role& Role::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_role_5ftypes_2eproto();
  return *default_instance_;
}

Role* Role::default_instance_ = NULL;

Role* Role::New() const {
  return new Role;
}

void Role::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Role*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 115) {
    ZR_(id_, unique_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    relegation_role_ = 0u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  privilege_.Clear();
  assignable_role_.Clear();
  attribute_.Clear();
  kickable_role_.Clear();
  removable_role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Role::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Role)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // required string name = 2;
      case 2: {
        if (tag == 18) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_privilege;
        break;
      }

      // repeated string privilege = 3;
      case 3: {
        if (tag == 26) {
         parse_privilege:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_privilege()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->privilege(this->privilege_size() - 1).data(),
            this->privilege(this->privilege_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "privilege");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_privilege;
        if (input->ExpectTag(34)) goto parse_assignable_role;
        break;
      }

      // repeated uint32 assignable_role = 4 [packed = true];
      case 4: {
        if (tag == 34) {
         parse_assignable_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_assignable_role())));
        } else if (tag == 32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 34, input, this->mutable_assignable_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_required;
        break;
      }

      // optional bool required = 5 [default = false];
      case 5: {
        if (tag == 40) {
         parse_required:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &required_)));
          set_has_required();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_unique;
        break;
      }

      // optional bool unique = 6 [default = false];
      case 6: {
        if (tag == 48) {
         parse_unique:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &unique_)));
          set_has_unique();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_relegation_role;
        break;
      }

      // optional uint32 relegation_role = 7;
      case 7: {
        if (tag == 56) {
         parse_relegation_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &relegation_role_)));
          set_has_relegation_role();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 8;
      case 8: {
        if (tag == 66) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_attribute;
        if (input->ExpectTag(74)) goto parse_kickable_role;
        break;
      }

      // repeated uint32 kickable_role = 9 [packed = true];
      case 9: {
        if (tag == 74) {
         parse_kickable_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_kickable_role())));
        } else if (tag == 72) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 74, input, this->mutable_kickable_role())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_removable_role;
        break;
      }

      // repeated uint32 removable_role = 10 [packed = true];
      case 10: {
        if (tag == 82) {
         parse_removable_role:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_removable_role())));
        } else if (tag == 80) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 82, input, this->mutable_removable_role())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Role)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Role)
  return false;
#undef DO_
}

void Role::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Role)
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // repeated string privilege = 3;
  for (int i = 0; i < this->privilege_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->privilege(i).data(), this->privilege(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "privilege");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->privilege(i), output);
  }

  // repeated uint32 assignable_role = 4 [packed = true];
  if (this->assignable_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(4, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_assignable_role_cached_byte_size_);
  }
  for (int i = 0; i < this->assignable_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->assignable_role(i), output);
  }

  // optional bool required = 5 [default = false];
  if (has_required()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->required(), output);
  }

  // optional bool unique = 6 [default = false];
  if (has_unique()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->unique(), output);
  }

  // optional uint32 relegation_role = 7;
  if (has_relegation_role()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->relegation_role(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 8;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->attribute(i), output);
  }

  // repeated uint32 kickable_role = 9 [packed = true];
  if (this->kickable_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(9, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_kickable_role_cached_byte_size_);
  }
  for (int i = 0; i < this->kickable_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->kickable_role(i), output);
  }

  // repeated uint32 removable_role = 10 [packed = true];
  if (this->removable_role_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(10, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_removable_role_cached_byte_size_);
  }
  for (int i = 0; i < this->removable_role_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->removable_role(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Role)
}

::google::protobuf::uint8* Role::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Role)
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // repeated string privilege = 3;
  for (int i = 0; i < this->privilege_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->privilege(i).data(), this->privilege(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "privilege");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->privilege(i), target);
  }

  // repeated uint32 assignable_role = 4 [packed = true];
  if (this->assignable_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _assignable_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->assignable_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->assignable_role(i), target);
  }

  // optional bool required = 5 [default = false];
  if (has_required()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->required(), target);
  }

  // optional bool unique = 6 [default = false];
  if (has_unique()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->unique(), target);
  }

  // optional uint32 relegation_role = 7;
  if (has_relegation_role()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->relegation_role(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 8;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->attribute(i), target);
  }

  // repeated uint32 kickable_role = 9 [packed = true];
  if (this->kickable_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      9,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _kickable_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->kickable_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->kickable_role(i), target);
  }

  // repeated uint32 removable_role = 10 [packed = true];
  if (this->removable_role_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      10,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _removable_role_cached_byte_size_, target);
  }
  for (int i = 0; i < this->removable_role_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->removable_role(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Role)
  return target;
}

int Role::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional bool required = 5 [default = false];
    if (has_required()) {
      total_size += 1 + 1;
    }

    // optional bool unique = 6 [default = false];
    if (has_unique()) {
      total_size += 1 + 1;
    }

    // optional uint32 relegation_role = 7;
    if (has_relegation_role()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->relegation_role());
    }

  }
  // repeated string privilege = 3;
  total_size += 1 * this->privilege_size();
  for (int i = 0; i < this->privilege_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->privilege(i));
  }

  // repeated uint32 assignable_role = 4 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->assignable_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->assignable_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _assignable_role_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated .bgs.protocol.Attribute attribute = 8;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  // repeated uint32 kickable_role = 9 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->kickable_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->kickable_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _kickable_role_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated uint32 removable_role = 10 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->removable_role_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->removable_role(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _removable_role_cached_byte_size_ = data_size;
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

void Role::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Role* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Role*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Role::MergeFrom(const Role& from) {
  GOOGLE_CHECK_NE(&from, this);
  privilege_.MergeFrom(from.privilege_);
  assignable_role_.MergeFrom(from.assignable_role_);
  attribute_.MergeFrom(from.attribute_);
  kickable_role_.MergeFrom(from.kickable_role_);
  removable_role_.MergeFrom(from.removable_role_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_required()) {
      set_required(from.required());
    }
    if (from.has_unique()) {
      set_unique(from.unique());
    }
    if (from.has_relegation_role()) {
      set_relegation_role(from.relegation_role());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Role::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Role::CopyFrom(const Role& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Role::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void Role::Swap(Role* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    privilege_.Swap(&other->privilege_);
    assignable_role_.Swap(&other->assignable_role_);
    std::swap(required_, other->required_);
    std::swap(unique_, other->unique_);
    std::swap(relegation_role_, other->relegation_role_);
    attribute_.Swap(&other->attribute_);
    kickable_role_.Swap(&other->kickable_role_);
    removable_role_.Swap(&other->removable_role_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Role::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Role_descriptor_;
  metadata.reflection = Role_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
