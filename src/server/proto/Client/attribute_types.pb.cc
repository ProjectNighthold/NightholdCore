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
#include "attribute_types.pb.h"

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

const ::google::protobuf::Descriptor* Variant_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Variant_reflection_ = NULL;
const ::google::protobuf::Descriptor* Attribute_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Attribute_reflection_ = NULL;
const ::google::protobuf::Descriptor* AttributeFilter_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AttributeFilter_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* AttributeFilter_Operation_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_attribute_5ftypes_2eproto() {
  protobuf_AddDesc_attribute_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "attribute_types.proto");
  GOOGLE_CHECK(file != NULL);
  Variant_descriptor_ = file->message_type(0);
  static const int Variant_offsets_[9] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, bool_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, int_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, float_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, string_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, blob_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, message_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, fourcc_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, uint_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, entity_id_value_),
  };
  Variant_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Variant_descriptor_,
      Variant::default_instance_,
      Variant_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Variant, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Variant));
  Attribute_descriptor_ = file->message_type(1);
  static const int Attribute_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Attribute, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Attribute, value_),
  };
  Attribute_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Attribute_descriptor_,
      Attribute::default_instance_,
      Attribute_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Attribute, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Attribute, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Attribute));
  AttributeFilter_descriptor_ = file->message_type(2);
  static const int AttributeFilter_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttributeFilter, op_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttributeFilter, attribute_),
  };
  AttributeFilter_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AttributeFilter_descriptor_,
      AttributeFilter::default_instance_,
      AttributeFilter_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttributeFilter, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttributeFilter, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AttributeFilter));
  AttributeFilter_Operation_descriptor_ = AttributeFilter_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_attribute_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Variant_descriptor_, &Variant::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Attribute_descriptor_, &Attribute::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AttributeFilter_descriptor_, &AttributeFilter::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_attribute_5ftypes_2eproto() {
  delete Variant::default_instance_;
  delete Variant_reflection_;
  delete Attribute::default_instance_;
  delete Attribute_reflection_;
  delete AttributeFilter::default_instance_;
  delete AttributeFilter_reflection_;
}

void protobuf_AddDesc_attribute_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025attribute_types.proto\022\014bgs.protocol\032\022e"
    "ntity_types.proto\"\341\001\n\007Variant\022\022\n\nbool_va"
    "lue\030\002 \001(\010\022\021\n\tint_value\030\003 \001(\003\022\023\n\013float_va"
    "lue\030\004 \001(\001\022\024\n\014string_value\030\005 \001(\t\022\022\n\nblob_"
    "value\030\006 \001(\014\022\025\n\rmessage_value\030\007 \001(\014\022\024\n\014fo"
    "urcc_value\030\010 \001(\t\022\022\n\nuint_value\030\t \001(\004\022/\n\017"
    "entity_id_value\030\n \001(\0132\026.bgs.protocol.Ent"
    "ityId\"\?\n\tAttribute\022\014\n\004name\030\001 \002(\t\022$\n\005valu"
    "e\030\002 \002(\0132\025.bgs.protocol.Variant\"\312\001\n\017Attri"
    "buteFilter\0223\n\002op\030\001 \002(\0162\'.bgs.protocol.At"
    "tributeFilter.Operation\022*\n\tattribute\030\002 \003"
    "(\0132\027.bgs.protocol.Attribute\"V\n\tOperation"
    "\022\016\n\nMATCH_NONE\020\000\022\r\n\tMATCH_ANY\020\001\022\r\n\tMATCH"
    "_ALL\020\002\022\033\n\027MATCH_ALL_MOST_SPECIFIC\020\003B!\n\rb"
    "net.protocolB\016AttributeProtoH\001", 590);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "attribute_types.proto", &protobuf_RegisterTypes);
  Variant::default_instance_ = new Variant();
  Attribute::default_instance_ = new Attribute();
  AttributeFilter::default_instance_ = new AttributeFilter();
  Variant::default_instance_->InitAsDefaultInstance();
  Attribute::default_instance_->InitAsDefaultInstance();
  AttributeFilter::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_attribute_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_attribute_5ftypes_2eproto {
  StaticDescriptorInitializer_attribute_5ftypes_2eproto() {
    protobuf_AddDesc_attribute_5ftypes_2eproto();
  }
} static_descriptor_initializer_attribute_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Variant::kBoolValueFieldNumber;
const int Variant::kIntValueFieldNumber;
const int Variant::kFloatValueFieldNumber;
const int Variant::kStringValueFieldNumber;
const int Variant::kBlobValueFieldNumber;
const int Variant::kMessageValueFieldNumber;
const int Variant::kFourccValueFieldNumber;
const int Variant::kUintValueFieldNumber;
const int Variant::kEntityIdValueFieldNumber;
#endif  // !_MSC_VER

Variant::Variant()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Variant)
}

void Variant::InitAsDefaultInstance() {
  entity_id_value_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

Variant::Variant(const Variant& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Variant)
}

void Variant::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  bool_value_ = false;
  int_value_ = GOOGLE_LONGLONG(0);
  float_value_ = 0;
  string_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  blob_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  fourcc_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  uint_value_ = GOOGLE_ULONGLONG(0);
  entity_id_value_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Variant::~Variant() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Variant)
  SharedDtor();
}

void Variant::SharedDtor() {
  if (string_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete string_value_;
  }
  if (blob_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete blob_value_;
  }
  if (message_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete message_value_;
  }
  if (fourcc_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete fourcc_value_;
  }
  if (this != default_instance_) {
    delete entity_id_value_;
  }
}

void Variant::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Variant::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Variant_descriptor_;
}

const Variant& Variant::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_attribute_5ftypes_2eproto();
  return *default_instance_;
}

Variant* Variant::default_instance_ = NULL;

Variant* Variant::New() const {
  return new Variant;
}

void Variant::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Variant*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(int_value_, float_value_);
    bool_value_ = false;
    if (has_string_value()) {
      if (string_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        string_value_->clear();
      }
    }
    if (has_blob_value()) {
      if (blob_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        blob_value_->clear();
      }
    }
    if (has_message_value()) {
      if (message_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        message_value_->clear();
      }
    }
    if (has_fourcc_value()) {
      if (fourcc_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        fourcc_value_->clear();
      }
    }
    uint_value_ = GOOGLE_ULONGLONG(0);
  }
  if (has_entity_id_value()) {
    if (entity_id_value_ != NULL) entity_id_value_->::bgs::protocol::EntityId::Clear();
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Variant::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Variant)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool bool_value = 2;
      case 2: {
        if (tag == 16) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &bool_value_)));
          set_has_bool_value();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_int_value;
        break;
      }

      // optional int64 int_value = 3;
      case 3: {
        if (tag == 24) {
         parse_int_value:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &int_value_)));
          set_has_int_value();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(33)) goto parse_float_value;
        break;
      }

      // optional double float_value = 4;
      case 4: {
        if (tag == 33) {
         parse_float_value:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &float_value_)));
          set_has_float_value();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_string_value;
        break;
      }

      // optional string string_value = 5;
      case 5: {
        if (tag == 42) {
         parse_string_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_string_value()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->string_value().data(), this->string_value().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "string_value");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_blob_value;
        break;
      }

      // optional bytes blob_value = 6;
      case 6: {
        if (tag == 50) {
         parse_blob_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_blob_value()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_message_value;
        break;
      }

      // optional bytes message_value = 7;
      case 7: {
        if (tag == 58) {
         parse_message_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_message_value()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_fourcc_value;
        break;
      }

      // optional string fourcc_value = 8;
      case 8: {
        if (tag == 66) {
         parse_fourcc_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_fourcc_value()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->fourcc_value().data(), this->fourcc_value().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "fourcc_value");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_uint_value;
        break;
      }

      // optional uint64 uint_value = 9;
      case 9: {
        if (tag == 72) {
         parse_uint_value:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &uint_value_)));
          set_has_uint_value();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_entity_id_value;
        break;
      }

      // optional .bgs.protocol.EntityId entity_id_value = 10;
      case 10: {
        if (tag == 82) {
         parse_entity_id_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id_value()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Variant)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Variant)
  return false;
#undef DO_
}

void Variant::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Variant)
  // optional bool bool_value = 2;
  if (has_bool_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->bool_value(), output);
  }

  // optional int64 int_value = 3;
  if (has_int_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->int_value(), output);
  }

  // optional double float_value = 4;
  if (has_float_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->float_value(), output);
  }

  // optional string string_value = 5;
  if (has_string_value()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->string_value().data(), this->string_value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "string_value");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->string_value(), output);
  }

  // optional bytes blob_value = 6;
  if (has_blob_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      6, this->blob_value(), output);
  }

  // optional bytes message_value = 7;
  if (has_message_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      7, this->message_value(), output);
  }

  // optional string fourcc_value = 8;
  if (has_fourcc_value()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->fourcc_value().data(), this->fourcc_value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "fourcc_value");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->fourcc_value(), output);
  }

  // optional uint64 uint_value = 9;
  if (has_uint_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(9, this->uint_value(), output);
  }

  // optional .bgs.protocol.EntityId entity_id_value = 10;
  if (has_entity_id_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->entity_id_value(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Variant)
}

::google::protobuf::uint8* Variant::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Variant)
  // optional bool bool_value = 2;
  if (has_bool_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->bool_value(), target);
  }

  // optional int64 int_value = 3;
  if (has_int_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->int_value(), target);
  }

  // optional double float_value = 4;
  if (has_float_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->float_value(), target);
  }

  // optional string string_value = 5;
  if (has_string_value()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->string_value().data(), this->string_value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "string_value");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->string_value(), target);
  }

  // optional bytes blob_value = 6;
  if (has_blob_value()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->blob_value(), target);
  }

  // optional bytes message_value = 7;
  if (has_message_value()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->message_value(), target);
  }

  // optional string fourcc_value = 8;
  if (has_fourcc_value()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->fourcc_value().data(), this->fourcc_value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "fourcc_value");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->fourcc_value(), target);
  }

  // optional uint64 uint_value = 9;
  if (has_uint_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(9, this->uint_value(), target);
  }

  // optional .bgs.protocol.EntityId entity_id_value = 10;
  if (has_entity_id_value()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->entity_id_value(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Variant)
  return target;
}

int Variant::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool bool_value = 2;
    if (has_bool_value()) {
      total_size += 1 + 1;
    }

    // optional int64 int_value = 3;
    if (has_int_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->int_value());
    }

    // optional double float_value = 4;
    if (has_float_value()) {
      total_size += 1 + 8;
    }

    // optional string string_value = 5;
    if (has_string_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->string_value());
    }

    // optional bytes blob_value = 6;
    if (has_blob_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->blob_value());
    }

    // optional bytes message_value = 7;
    if (has_message_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->message_value());
    }

    // optional string fourcc_value = 8;
    if (has_fourcc_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->fourcc_value());
    }

    // optional uint64 uint_value = 9;
    if (has_uint_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->uint_value());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional .bgs.protocol.EntityId entity_id_value = 10;
    if (has_entity_id_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id_value());
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

void Variant::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Variant* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Variant*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Variant::MergeFrom(const Variant& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_bool_value()) {
      set_bool_value(from.bool_value());
    }
    if (from.has_int_value()) {
      set_int_value(from.int_value());
    }
    if (from.has_float_value()) {
      set_float_value(from.float_value());
    }
    if (from.has_string_value()) {
      set_string_value(from.string_value());
    }
    if (from.has_blob_value()) {
      set_blob_value(from.blob_value());
    }
    if (from.has_message_value()) {
      set_message_value(from.message_value());
    }
    if (from.has_fourcc_value()) {
      set_fourcc_value(from.fourcc_value());
    }
    if (from.has_uint_value()) {
      set_uint_value(from.uint_value());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_entity_id_value()) {
      mutable_entity_id_value()->::bgs::protocol::EntityId::MergeFrom(from.entity_id_value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Variant::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Variant::CopyFrom(const Variant& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Variant::IsInitialized() const {

  if (has_entity_id_value()) {
    if (!this->entity_id_value().IsInitialized()) return false;
  }
  return true;
}

void Variant::Swap(Variant* other) {
  if (other != this) {
    std::swap(bool_value_, other->bool_value_);
    std::swap(int_value_, other->int_value_);
    std::swap(float_value_, other->float_value_);
    std::swap(string_value_, other->string_value_);
    std::swap(blob_value_, other->blob_value_);
    std::swap(message_value_, other->message_value_);
    std::swap(fourcc_value_, other->fourcc_value_);
    std::swap(uint_value_, other->uint_value_);
    std::swap(entity_id_value_, other->entity_id_value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Variant::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Variant_descriptor_;
  metadata.reflection = Variant_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Attribute::kNameFieldNumber;
const int Attribute::kValueFieldNumber;
#endif  // !_MSC_VER

Attribute::Attribute()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Attribute)
}

void Attribute::InitAsDefaultInstance() {
  value_ = const_cast< ::bgs::protocol::Variant*>(&::bgs::protocol::Variant::default_instance());
}

Attribute::Attribute(const Attribute& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Attribute)
}

void Attribute::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Attribute::~Attribute() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Attribute)
  SharedDtor();
}

void Attribute::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
    delete value_;
  }
}

void Attribute::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Attribute::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Attribute_descriptor_;
}

const Attribute& Attribute::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_attribute_5ftypes_2eproto();
  return *default_instance_;
}

Attribute* Attribute::default_instance_ = NULL;

Attribute* Attribute::New() const {
  return new Attribute;
}

void Attribute::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    if (has_value()) {
      if (value_ != NULL) value_->::bgs::protocol::Variant::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Attribute::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.Attribute)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.Attribute)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.Attribute)
  return false;
#undef DO_
}

void Attribute::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.Attribute)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.Attribute)
}

::google::protobuf::uint8* Attribute::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.Attribute)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.Attribute)
  return target;
}

int Attribute::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
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

void Attribute::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Attribute* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Attribute*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Attribute::MergeFrom(const Attribute& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_value()) {
      mutable_value()->::bgs::protocol::Variant::MergeFrom(from.value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Attribute::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Attribute::CopyFrom(const Attribute& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Attribute::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_value()) {
    if (!this->value().IsInitialized()) return false;
  }
  return true;
}

void Attribute::Swap(Attribute* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(value_, other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Attribute::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Attribute_descriptor_;
  metadata.reflection = Attribute_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* AttributeFilter_Operation_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AttributeFilter_Operation_descriptor_;
}
bool AttributeFilter_Operation_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const AttributeFilter_Operation AttributeFilter::MATCH_NONE;
const AttributeFilter_Operation AttributeFilter::MATCH_ANY;
const AttributeFilter_Operation AttributeFilter::MATCH_ALL;
const AttributeFilter_Operation AttributeFilter::MATCH_ALL_MOST_SPECIFIC;
const AttributeFilter_Operation AttributeFilter::Operation_MIN;
const AttributeFilter_Operation AttributeFilter::Operation_MAX;
const int AttributeFilter::Operation_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int AttributeFilter::kOpFieldNumber;
const int AttributeFilter::kAttributeFieldNumber;
#endif  // !_MSC_VER

AttributeFilter::AttributeFilter()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.AttributeFilter)
}

void AttributeFilter::InitAsDefaultInstance() {
}

AttributeFilter::AttributeFilter(const AttributeFilter& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.AttributeFilter)
}

void AttributeFilter::SharedCtor() {
  _cached_size_ = 0;
  op_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AttributeFilter::~AttributeFilter() {
  // @@protoc_insertion_point(destructor:bgs.protocol.AttributeFilter)
  SharedDtor();
}

void AttributeFilter::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AttributeFilter::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AttributeFilter::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AttributeFilter_descriptor_;
}

const AttributeFilter& AttributeFilter::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_attribute_5ftypes_2eproto();
  return *default_instance_;
}

AttributeFilter* AttributeFilter::default_instance_ = NULL;

AttributeFilter* AttributeFilter::New() const {
  return new AttributeFilter;
}

void AttributeFilter::Clear() {
  op_ = 0;
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AttributeFilter::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.AttributeFilter)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.AttributeFilter.Operation op = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::AttributeFilter_Operation_IsValid(value)) {
            set_op(static_cast< ::bgs::protocol::AttributeFilter_Operation >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.AttributeFilter)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.AttributeFilter)
  return false;
#undef DO_
}

void AttributeFilter::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.AttributeFilter)
  // required .bgs.protocol.AttributeFilter.Operation op = 1;
  if (has_op()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->op(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->attribute(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.AttributeFilter)
}

::google::protobuf::uint8* AttributeFilter::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.AttributeFilter)
  // required .bgs.protocol.AttributeFilter.Operation op = 1;
  if (has_op()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->op(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->attribute(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.AttributeFilter)
  return target;
}

int AttributeFilter::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.AttributeFilter.Operation op = 1;
    if (has_op()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->op());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 2;
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

void AttributeFilter::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AttributeFilter* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AttributeFilter*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AttributeFilter::MergeFrom(const AttributeFilter& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_op()) {
      set_op(from.op());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AttributeFilter::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AttributeFilter::CopyFrom(const AttributeFilter& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AttributeFilter::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void AttributeFilter::Swap(AttributeFilter* other) {
  if (other != this) {
    std::swap(op_, other->op_);
    attribute_.Swap(&other->attribute_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AttributeFilter::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AttributeFilter_descriptor_;
  metadata.reflection = AttributeFilter_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
