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
#include "channel_types.pb.h"

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

const ::google::protobuf::Descriptor* Message_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Message_reflection_ = NULL;
const ::google::protobuf::Descriptor* ListChannelsOptions_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ListChannelsOptions_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChannelDescription_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChannelDescription_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChannelInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChannelInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChannelState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChannelState_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* ChannelState_PrivacyLevel_descriptor_ = NULL;
const ::google::protobuf::Descriptor* MemberAccountInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemberAccountInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* MemberState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemberState_reflection_ = NULL;
const ::google::protobuf::Descriptor* Member_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Member_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_channel_5ftypes_2eproto() {
  protobuf_AddDesc_channel_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "channel_types.proto");
  GOOGLE_CHECK(file != NULL);
  Message_descriptor_ = file->message_type(0);
  static const int Message_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, attribute_),
  };
  Message_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Message_descriptor_,
      Message::default_instance_,
      Message_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Message));
  ListChannelsOptions_descriptor_ = file->message_type(1);
  static const int ListChannelsOptions_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, start_index_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, max_results_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, locale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, capacity_full_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, attribute_filter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, channel_type_),
  };
  ListChannelsOptions_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ListChannelsOptions_descriptor_,
      ListChannelsOptions::default_instance_,
      ListChannelsOptions_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ListChannelsOptions, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ListChannelsOptions));
  ChannelDescription_descriptor_ = file->message_type(2);
  static const int ChannelDescription_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelDescription, channel_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelDescription, current_members_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelDescription, state_),
  };
  ChannelDescription_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChannelDescription_descriptor_,
      ChannelDescription::default_instance_,
      ChannelDescription_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelDescription, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelDescription, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChannelDescription));
  ChannelInfo_descriptor_ = file->message_type(3);
  static const int ChannelInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelInfo, description_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelInfo, member_),
  };
  ChannelInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChannelInfo_descriptor_,
      ChannelInfo::default_instance_,
      ChannelInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChannelInfo));
  ChannelState_descriptor_ = file->message_type(4);
  static const int ChannelState_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, max_members_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, min_members_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, invitation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, reason_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, privacy_level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, channel_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, subscribe_to_presence_),
  };
  ChannelState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChannelState_descriptor_,
      ChannelState::default_instance_,
      ChannelState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChannelState, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChannelState));
  ChannelState_PrivacyLevel_descriptor_ = ChannelState_descriptor_->enum_type(0);
  MemberAccountInfo_descriptor_ = file->message_type(5);
  static const int MemberAccountInfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAccountInfo, battle_tag_),
  };
  MemberAccountInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemberAccountInfo_descriptor_,
      MemberAccountInfo::default_instance_,
      MemberAccountInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAccountInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberAccountInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemberAccountInfo));
  MemberState_descriptor_ = file->message_type(6);
  static const int MemberState_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, privileges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, info_),
  };
  MemberState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemberState_descriptor_,
      MemberState::default_instance_,
      MemberState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemberState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemberState));
  Member_descriptor_ = file->message_type(7);
  static const int Member_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Member, identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Member, state_),
  };
  Member_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Member_descriptor_,
      Member::default_instance_,
      Member_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Member, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Member, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Member));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_channel_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Message_descriptor_, &Message::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ListChannelsOptions_descriptor_, &ListChannelsOptions::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChannelDescription_descriptor_, &ChannelDescription::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChannelInfo_descriptor_, &ChannelInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChannelState_descriptor_, &ChannelState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemberAccountInfo_descriptor_, &MemberAccountInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemberState_descriptor_, &MemberState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Member_descriptor_, &Member::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_channel_5ftypes_2eproto() {
  delete Message::default_instance_;
  delete Message_reflection_;
  delete ListChannelsOptions::default_instance_;
  delete ListChannelsOptions_reflection_;
  delete ChannelDescription::default_instance_;
  delete ChannelDescription_reflection_;
  delete ChannelInfo::default_instance_;
  delete ChannelInfo_reflection_;
  delete ChannelState::default_instance_;
  delete ChannelState_reflection_;
  delete ChannelState::_default_channel_type_;
  delete MemberAccountInfo::default_instance_;
  delete MemberAccountInfo_reflection_;
  delete MemberState::default_instance_;
  delete MemberState_reflection_;
  delete Member::default_instance_;
  delete Member_reflection_;
}

void protobuf_AddDesc_channel_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::channel::v1::protobuf_AddDesc_client_2fv1_2fchannel_5fid_2eproto();
  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_invitation_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023channel_types.proto\022\027bgs.protocol.chan"
    "nel.v1\032\032client/v1/channel_id.proto\032\025attr"
    "ibute_types.proto\032\022entity_types.proto\032\026i"
    "nvitation_types.proto\032\017rpc_types.proto\"<"
    "\n\007Message\022*\n\tattribute\030\001 \003(\0132\027.bgs.proto"
    "col.Attribute*\005\010d\020\220N\"\333\001\n\023ListChannelsOpt"
    "ions\022\026\n\013start_index\030\001 \001(\r:\0010\022\027\n\013max_resu"
    "lts\030\002 \001(\r:\00216\022\014\n\004name\030\003 \001(\t\022\017\n\007program\030\004"
    " \001(\007\022\016\n\006locale\030\005 \001(\007\022\025\n\rcapacity_full\030\006 "
    "\001(\r\0227\n\020attribute_filter\030\007 \002(\0132\035.bgs.prot"
    "ocol.AttributeFilter\022\024\n\014channel_type\030\010 \001"
    "(\t\"\217\001\n\022ChannelDescription\022*\n\nchannel_id\030"
    "\001 \002(\0132\026.bgs.protocol.EntityId\022\027\n\017current"
    "_members\030\002 \001(\r\0224\n\005state\030\003 \001(\0132%.bgs.prot"
    "ocol.channel.v1.ChannelState\"\200\001\n\013Channel"
    "Info\022@\n\013description\030\001 \002(\0132+.bgs.protocol"
    ".channel.v1.ChannelDescription\022/\n\006member"
    "\030\002 \003(\0132\037.bgs.protocol.channel.v1.Member\""
    "\202\004\n\014ChannelState\022\023\n\013max_members\030\001 \001(\r\022\023\n"
    "\013min_members\030\002 \001(\r\022*\n\tattribute\030\003 \003(\0132\027."
    "bgs.protocol.Attribute\022,\n\ninvitation\030\004 \003"
    "(\0132\030.bgs.protocol.Invitation\022\016\n\006reason\030\006"
    " \001(\r\022]\n\rprivacy_level\030\007 \001(\01622.bgs.protoc"
    "ol.channel.v1.ChannelState.PrivacyLevel:"
    "\022PRIVACY_LEVEL_OPEN\022\014\n\004name\030\010 \001(\t\022\035\n\014cha"
    "nnel_type\030\n \001(\t:\007default\022\022\n\007program\030\013 \001("
    "\007:\0010\022#\n\025subscribe_to_presence\030\r \001(\010:\004tru"
    "e\"\221\001\n\014PrivacyLevel\022\026\n\022PRIVACY_LEVEL_OPEN"
    "\020\001\022,\n(PRIVACY_LEVEL_OPEN_INVITATION_AND_"
    "FRIEND\020\002\022!\n\035PRIVACY_LEVEL_OPEN_INVITATIO"
    "N\020\003\022\030\n\024PRIVACY_LEVEL_CLOSED\020\004*\005\010d\020\220N\"\'\n\021"
    "MemberAccountInfo\022\022\n\nbattle_tag\030\003 \001(\t\"\234\001"
    "\n\013MemberState\022*\n\tattribute\030\001 \003(\0132\027.bgs.p"
    "rotocol.Attribute\022\020\n\004role\030\002 \003(\rB\002\020\001\022\025\n\np"
    "rivileges\030\003 \001(\004:\0010\0228\n\004info\030\004 \001(\0132*.bgs.p"
    "rotocol.channel.v1.MemberAccountInfo\"g\n\006"
    "Member\022(\n\010identity\030\001 \002(\0132\026.bgs.protocol."
    "Identity\0223\n\005state\030\002 \002(\0132$.bgs.protocol.c"
    "hannel.v1.MemberStateB\002H\001P\000", 1547);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "channel_types.proto", &protobuf_RegisterTypes);
  Message::default_instance_ = new Message();
  ListChannelsOptions::default_instance_ = new ListChannelsOptions();
  ChannelDescription::default_instance_ = new ChannelDescription();
  ChannelInfo::default_instance_ = new ChannelInfo();
  ChannelState::_default_channel_type_ =
      new ::std::string("default", 7);
  ChannelState::default_instance_ = new ChannelState();
  MemberAccountInfo::default_instance_ = new MemberAccountInfo();
  MemberState::default_instance_ = new MemberState();
  Member::default_instance_ = new Member();
  Message::default_instance_->InitAsDefaultInstance();
  ListChannelsOptions::default_instance_->InitAsDefaultInstance();
  ChannelDescription::default_instance_->InitAsDefaultInstance();
  ChannelInfo::default_instance_->InitAsDefaultInstance();
  ChannelState::default_instance_->InitAsDefaultInstance();
  MemberAccountInfo::default_instance_->InitAsDefaultInstance();
  MemberState::default_instance_->InitAsDefaultInstance();
  Member::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_channel_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_channel_5ftypes_2eproto {
  StaticDescriptorInitializer_channel_5ftypes_2eproto() {
    protobuf_AddDesc_channel_5ftypes_2eproto();
  }
} static_descriptor_initializer_channel_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Message::kAttributeFieldNumber;
#endif  // !_MSC_VER

Message::Message()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.Message)
}

void Message::InitAsDefaultInstance() {
}

Message::Message(const Message& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.Message)
}

void Message::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Message::~Message() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.Message)
  SharedDtor();
}

void Message::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Message::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Message::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Message_descriptor_;
}

const Message& Message::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

Message* Message::default_instance_ = NULL;

Message* Message::New() const {
  return new Message;
}

void Message::Clear() {
  _extensions_.Clear();
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Message::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.Message)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
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
        if ((800u <= tag && tag < 80000u)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.Message)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.Message)
  return false;
#undef DO_
}

void Message::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.Message)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
  }

  // Extension range [100, 10000)
  _extensions_.SerializeWithCachedSizes(
      100, 10000, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.Message)
}

::google::protobuf::uint8* Message::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.Message)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
  }

  // Extension range [100, 10000)
  target = _extensions_.SerializeWithCachedSizesToArray(
      100, 10000, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.Message)
  return target;
}

int Message::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  total_size += _extensions_.ByteSize();

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

void Message::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Message* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Message*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Message::MergeFrom(const Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  _extensions_.MergeFrom(from._extensions_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Message::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Message::CopyFrom(const Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;

  if (!_extensions_.IsInitialized()) return false;  return true;
}

void Message::Swap(Message* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata Message::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Message_descriptor_;
  metadata.reflection = Message_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ListChannelsOptions::kStartIndexFieldNumber;
const int ListChannelsOptions::kMaxResultsFieldNumber;
const int ListChannelsOptions::kNameFieldNumber;
const int ListChannelsOptions::kProgramFieldNumber;
const int ListChannelsOptions::kLocaleFieldNumber;
const int ListChannelsOptions::kCapacityFullFieldNumber;
const int ListChannelsOptions::kAttributeFilterFieldNumber;
const int ListChannelsOptions::kChannelTypeFieldNumber;
#endif  // !_MSC_VER

ListChannelsOptions::ListChannelsOptions()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ListChannelsOptions)
}

void ListChannelsOptions::InitAsDefaultInstance() {
  attribute_filter_ = const_cast< ::bgs::protocol::AttributeFilter*>(&::bgs::protocol::AttributeFilter::default_instance());
}

ListChannelsOptions::ListChannelsOptions(const ListChannelsOptions& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ListChannelsOptions)
}

void ListChannelsOptions::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  start_index_ = 0u;
  max_results_ = 16u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  program_ = 0u;
  locale_ = 0u;
  capacity_full_ = 0u;
  attribute_filter_ = NULL;
  channel_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ListChannelsOptions::~ListChannelsOptions() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ListChannelsOptions)
  SharedDtor();
}

void ListChannelsOptions::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (channel_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete channel_type_;
  }
  if (this != default_instance_) {
    delete attribute_filter_;
  }
}

void ListChannelsOptions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ListChannelsOptions::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ListChannelsOptions_descriptor_;
}

const ListChannelsOptions& ListChannelsOptions::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

ListChannelsOptions* ListChannelsOptions::default_instance_ = NULL;

ListChannelsOptions* ListChannelsOptions::New() const {
  return new ListChannelsOptions;
}

void ListChannelsOptions::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ListChannelsOptions*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(program_, locale_);
    start_index_ = 0u;
    max_results_ = 16u;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    capacity_full_ = 0u;
    if (has_attribute_filter()) {
      if (attribute_filter_ != NULL) attribute_filter_->::bgs::protocol::AttributeFilter::Clear();
    }
    if (has_channel_type()) {
      if (channel_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        channel_type_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ListChannelsOptions::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.ListChannelsOptions)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 start_index = 1 [default = 0];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &start_index_)));
          set_has_start_index();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_max_results;
        break;
      }

      // optional uint32 max_results = 2 [default = 16];
      case 2: {
        if (tag == 16) {
         parse_max_results:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_results_)));
          set_has_max_results();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_name;
        break;
      }

      // optional string name = 3;
      case 3: {
        if (tag == 26) {
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
        if (input->ExpectTag(37)) goto parse_program;
        break;
      }

      // optional fixed32 program = 4;
      case 4: {
        if (tag == 37) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_locale;
        break;
      }

      // optional fixed32 locale = 5;
      case 5: {
        if (tag == 45) {
         parse_locale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &locale_)));
          set_has_locale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_capacity_full;
        break;
      }

      // optional uint32 capacity_full = 6;
      case 6: {
        if (tag == 48) {
         parse_capacity_full:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &capacity_full_)));
          set_has_capacity_full();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_attribute_filter;
        break;
      }

      // required .bgs.protocol.AttributeFilter attribute_filter = 7;
      case 7: {
        if (tag == 58) {
         parse_attribute_filter:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_attribute_filter()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_channel_type;
        break;
      }

      // optional string channel_type = 8;
      case 8: {
        if (tag == 66) {
         parse_channel_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_channel_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->channel_type().data(), this->channel_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "channel_type");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.ListChannelsOptions)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.ListChannelsOptions)
  return false;
#undef DO_
}

void ListChannelsOptions::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.ListChannelsOptions)
  // optional uint32 start_index = 1 [default = 0];
  if (has_start_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->start_index(), output);
  }

  // optional uint32 max_results = 2 [default = 16];
  if (has_max_results()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->max_results(), output);
  }

  // optional string name = 3;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // optional fixed32 program = 4;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(4, this->program(), output);
  }

  // optional fixed32 locale = 5;
  if (has_locale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(5, this->locale(), output);
  }

  // optional uint32 capacity_full = 6;
  if (has_capacity_full()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->capacity_full(), output);
  }

  // required .bgs.protocol.AttributeFilter attribute_filter = 7;
  if (has_attribute_filter()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->attribute_filter(), output);
  }

  // optional string channel_type = 8;
  if (has_channel_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->channel_type().data(), this->channel_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "channel_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->channel_type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.ListChannelsOptions)
}

::google::protobuf::uint8* ListChannelsOptions::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ListChannelsOptions)
  // optional uint32 start_index = 1 [default = 0];
  if (has_start_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->start_index(), target);
  }

  // optional uint32 max_results = 2 [default = 16];
  if (has_max_results()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->max_results(), target);
  }

  // optional string name = 3;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name(), target);
  }

  // optional fixed32 program = 4;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(4, this->program(), target);
  }

  // optional fixed32 locale = 5;
  if (has_locale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(5, this->locale(), target);
  }

  // optional uint32 capacity_full = 6;
  if (has_capacity_full()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->capacity_full(), target);
  }

  // required .bgs.protocol.AttributeFilter attribute_filter = 7;
  if (has_attribute_filter()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->attribute_filter(), target);
  }

  // optional string channel_type = 8;
  if (has_channel_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->channel_type().data(), this->channel_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "channel_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->channel_type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ListChannelsOptions)
  return target;
}

int ListChannelsOptions::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 start_index = 1 [default = 0];
    if (has_start_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->start_index());
    }

    // optional uint32 max_results = 2 [default = 16];
    if (has_max_results()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_results());
    }

    // optional string name = 3;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional fixed32 program = 4;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional fixed32 locale = 5;
    if (has_locale()) {
      total_size += 1 + 4;
    }

    // optional uint32 capacity_full = 6;
    if (has_capacity_full()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->capacity_full());
    }

    // required .bgs.protocol.AttributeFilter attribute_filter = 7;
    if (has_attribute_filter()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->attribute_filter());
    }

    // optional string channel_type = 8;
    if (has_channel_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->channel_type());
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

void ListChannelsOptions::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ListChannelsOptions* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ListChannelsOptions*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ListChannelsOptions::MergeFrom(const ListChannelsOptions& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_start_index()) {
      set_start_index(from.start_index());
    }
    if (from.has_max_results()) {
      set_max_results(from.max_results());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_locale()) {
      set_locale(from.locale());
    }
    if (from.has_capacity_full()) {
      set_capacity_full(from.capacity_full());
    }
    if (from.has_attribute_filter()) {
      mutable_attribute_filter()->::bgs::protocol::AttributeFilter::MergeFrom(from.attribute_filter());
    }
    if (from.has_channel_type()) {
      set_channel_type(from.channel_type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ListChannelsOptions::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ListChannelsOptions::CopyFrom(const ListChannelsOptions& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ListChannelsOptions::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000040) != 0x00000040) return false;

  if (has_attribute_filter()) {
    if (!this->attribute_filter().IsInitialized()) return false;
  }
  return true;
}

void ListChannelsOptions::Swap(ListChannelsOptions* other) {
  if (other != this) {
    std::swap(start_index_, other->start_index_);
    std::swap(max_results_, other->max_results_);
    std::swap(name_, other->name_);
    std::swap(program_, other->program_);
    std::swap(locale_, other->locale_);
    std::swap(capacity_full_, other->capacity_full_);
    std::swap(attribute_filter_, other->attribute_filter_);
    std::swap(channel_type_, other->channel_type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ListChannelsOptions::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ListChannelsOptions_descriptor_;
  metadata.reflection = ListChannelsOptions_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChannelDescription::kChannelIdFieldNumber;
const int ChannelDescription::kCurrentMembersFieldNumber;
const int ChannelDescription::kStateFieldNumber;
#endif  // !_MSC_VER

ChannelDescription::ChannelDescription()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ChannelDescription)
}

void ChannelDescription::InitAsDefaultInstance() {
  channel_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  state_ = const_cast< ::bgs::protocol::channel::v1::ChannelState*>(&::bgs::protocol::channel::v1::ChannelState::default_instance());
}

ChannelDescription::ChannelDescription(const ChannelDescription& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ChannelDescription)
}

void ChannelDescription::SharedCtor() {
  _cached_size_ = 0;
  channel_id_ = NULL;
  current_members_ = 0u;
  state_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChannelDescription::~ChannelDescription() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ChannelDescription)
  SharedDtor();
}

void ChannelDescription::SharedDtor() {
  if (this != default_instance_) {
    delete channel_id_;
    delete state_;
  }
}

void ChannelDescription::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChannelDescription::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelDescription_descriptor_;
}

const ChannelDescription& ChannelDescription::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

ChannelDescription* ChannelDescription::default_instance_ = NULL;

ChannelDescription* ChannelDescription::New() const {
  return new ChannelDescription;
}

void ChannelDescription::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_channel_id()) {
      if (channel_id_ != NULL) channel_id_->::bgs::protocol::EntityId::Clear();
    }
    current_members_ = 0u;
    if (has_state()) {
      if (state_ != NULL) state_->::bgs::protocol::channel::v1::ChannelState::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChannelDescription::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.ChannelDescription)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId channel_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_current_members;
        break;
      }

      // optional uint32 current_members = 2;
      case 2: {
        if (tag == 16) {
         parse_current_members:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &current_members_)));
          set_has_current_members();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_state;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelState state = 3;
      case 3: {
        if (tag == 26) {
         parse_state:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.ChannelDescription)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.ChannelDescription)
  return false;
#undef DO_
}

void ChannelDescription::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.ChannelDescription)
  // required .bgs.protocol.EntityId channel_id = 1;
  if (has_channel_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->channel_id(), output);
  }

  // optional uint32 current_members = 2;
  if (has_current_members()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->current_members(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelState state = 3;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->state(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.ChannelDescription)
}

::google::protobuf::uint8* ChannelDescription::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ChannelDescription)
  // required .bgs.protocol.EntityId channel_id = 1;
  if (has_channel_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->channel_id(), target);
  }

  // optional uint32 current_members = 2;
  if (has_current_members()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->current_members(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelState state = 3;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->state(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ChannelDescription)
  return target;
}

int ChannelDescription::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId channel_id = 1;
    if (has_channel_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->channel_id());
    }

    // optional uint32 current_members = 2;
    if (has_current_members()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->current_members());
    }

    // optional .bgs.protocol.channel.v1.ChannelState state = 3;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state());
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

void ChannelDescription::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChannelDescription* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChannelDescription*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChannelDescription::MergeFrom(const ChannelDescription& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_channel_id()) {
      mutable_channel_id()->::bgs::protocol::EntityId::MergeFrom(from.channel_id());
    }
    if (from.has_current_members()) {
      set_current_members(from.current_members());
    }
    if (from.has_state()) {
      mutable_state()->::bgs::protocol::channel::v1::ChannelState::MergeFrom(from.state());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChannelDescription::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChannelDescription::CopyFrom(const ChannelDescription& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChannelDescription::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_channel_id()) {
    if (!this->channel_id().IsInitialized()) return false;
  }
  if (has_state()) {
    if (!this->state().IsInitialized()) return false;
  }
  return true;
}

void ChannelDescription::Swap(ChannelDescription* other) {
  if (other != this) {
    std::swap(channel_id_, other->channel_id_);
    std::swap(current_members_, other->current_members_);
    std::swap(state_, other->state_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChannelDescription::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChannelDescription_descriptor_;
  metadata.reflection = ChannelDescription_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChannelInfo::kDescriptionFieldNumber;
const int ChannelInfo::kMemberFieldNumber;
#endif  // !_MSC_VER

ChannelInfo::ChannelInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ChannelInfo)
}

void ChannelInfo::InitAsDefaultInstance() {
  description_ = const_cast< ::bgs::protocol::channel::v1::ChannelDescription*>(&::bgs::protocol::channel::v1::ChannelDescription::default_instance());
}

ChannelInfo::ChannelInfo(const ChannelInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ChannelInfo)
}

void ChannelInfo::SharedCtor() {
  _cached_size_ = 0;
  description_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChannelInfo::~ChannelInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ChannelInfo)
  SharedDtor();
}

void ChannelInfo::SharedDtor() {
  if (this != default_instance_) {
    delete description_;
  }
}

void ChannelInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChannelInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelInfo_descriptor_;
}

const ChannelInfo& ChannelInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

ChannelInfo* ChannelInfo::default_instance_ = NULL;

ChannelInfo* ChannelInfo::New() const {
  return new ChannelInfo;
}

void ChannelInfo::Clear() {
  if (has_description()) {
    if (description_ != NULL) description_->::bgs::protocol::channel::v1::ChannelDescription::Clear();
  }
  member_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChannelInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.ChannelInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.channel.v1.ChannelDescription description = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_description()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_member;
        break;
      }

      // repeated .bgs.protocol.channel.v1.Member member = 2;
      case 2: {
        if (tag == 18) {
         parse_member:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_member()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_member;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.ChannelInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.ChannelInfo)
  return false;
#undef DO_
}

void ChannelInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.ChannelInfo)
  // required .bgs.protocol.channel.v1.ChannelDescription description = 1;
  if (has_description()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->description(), output);
  }

  // repeated .bgs.protocol.channel.v1.Member member = 2;
  for (int i = 0; i < this->member_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->member(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.ChannelInfo)
}

::google::protobuf::uint8* ChannelInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ChannelInfo)
  // required .bgs.protocol.channel.v1.ChannelDescription description = 1;
  if (has_description()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->description(), target);
  }

  // repeated .bgs.protocol.channel.v1.Member member = 2;
  for (int i = 0; i < this->member_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->member(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ChannelInfo)
  return target;
}

int ChannelInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.channel.v1.ChannelDescription description = 1;
    if (has_description()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->description());
    }

  }
  // repeated .bgs.protocol.channel.v1.Member member = 2;
  total_size += 1 * this->member_size();
  for (int i = 0; i < this->member_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->member(i));
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

void ChannelInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChannelInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChannelInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChannelInfo::MergeFrom(const ChannelInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  member_.MergeFrom(from.member_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_description()) {
      mutable_description()->::bgs::protocol::channel::v1::ChannelDescription::MergeFrom(from.description());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChannelInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChannelInfo::CopyFrom(const ChannelInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChannelInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_description()) {
    if (!this->description().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->member())) return false;
  return true;
}

void ChannelInfo::Swap(ChannelInfo* other) {
  if (other != this) {
    std::swap(description_, other->description_);
    member_.Swap(&other->member_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChannelInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChannelInfo_descriptor_;
  metadata.reflection = ChannelInfo_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* ChannelState_PrivacyLevel_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChannelState_PrivacyLevel_descriptor_;
}
bool ChannelState_PrivacyLevel_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const ChannelState_PrivacyLevel ChannelState::PRIVACY_LEVEL_OPEN;
const ChannelState_PrivacyLevel ChannelState::PRIVACY_LEVEL_OPEN_INVITATION_AND_FRIEND;
const ChannelState_PrivacyLevel ChannelState::PRIVACY_LEVEL_OPEN_INVITATION;
const ChannelState_PrivacyLevel ChannelState::PRIVACY_LEVEL_CLOSED;
const ChannelState_PrivacyLevel ChannelState::PrivacyLevel_MIN;
const ChannelState_PrivacyLevel ChannelState::PrivacyLevel_MAX;
const int ChannelState::PrivacyLevel_ARRAYSIZE;
#endif  // _MSC_VER
::std::string* ChannelState::_default_channel_type_ = NULL;
#ifndef _MSC_VER
const int ChannelState::kMaxMembersFieldNumber;
const int ChannelState::kMinMembersFieldNumber;
const int ChannelState::kAttributeFieldNumber;
const int ChannelState::kInvitationFieldNumber;
const int ChannelState::kReasonFieldNumber;
const int ChannelState::kPrivacyLevelFieldNumber;
const int ChannelState::kNameFieldNumber;
const int ChannelState::kChannelTypeFieldNumber;
const int ChannelState::kProgramFieldNumber;
const int ChannelState::kSubscribeToPresenceFieldNumber;
#endif  // !_MSC_VER

ChannelState::ChannelState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ChannelState)
}

void ChannelState::InitAsDefaultInstance() {
}

ChannelState::ChannelState(const ChannelState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ChannelState)
}

void ChannelState::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  max_members_ = 0u;
  min_members_ = 0u;
  reason_ = 0u;
  privacy_level_ = 1;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  channel_type_ = const_cast< ::std::string*>(_default_channel_type_);
  program_ = 0u;
  subscribe_to_presence_ = true;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChannelState::~ChannelState() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ChannelState)
  SharedDtor();
}

void ChannelState::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (channel_type_ != _default_channel_type_) {
    delete channel_type_;
  }
  if (this != default_instance_) {
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
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

ChannelState* ChannelState::default_instance_ = NULL;

ChannelState* ChannelState::New() const {
  return new ChannelState;
}

void ChannelState::Clear() {
  _extensions_.Clear();
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChannelState*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 243) {
    ZR_(max_members_, min_members_);
    reason_ = 0u;
    privacy_level_ = 1;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    if (has_channel_type()) {
      if (channel_type_ != _default_channel_type_) {
        channel_type_->assign(*_default_channel_type_);
      }
    }
  }
  if (_has_bits_[8 / 32] & 768) {
    program_ = 0u;
    subscribe_to_presence_ = true;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  attribute_.Clear();
  invitation_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChannelState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.ChannelState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 max_members = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_members_)));
          set_has_max_members();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_min_members;
        break;
      }

      // optional uint32 min_members = 2;
      case 2: {
        if (tag == 16) {
         parse_min_members:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &min_members_)));
          set_has_min_members();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_attribute;
        break;
      }

      // repeated .bgs.protocol.Attribute attribute = 3;
      case 3: {
        if (tag == 26) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_attribute;
        if (input->ExpectTag(34)) goto parse_invitation;
        break;
      }

      // repeated .bgs.protocol.Invitation invitation = 4;
      case 4: {
        if (tag == 34) {
         parse_invitation:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_invitation()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_invitation;
        if (input->ExpectTag(48)) goto parse_reason;
        break;
      }

      // optional uint32 reason = 6;
      case 6: {
        if (tag == 48) {
         parse_reason:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &reason_)));
          set_has_reason();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_privacy_level;
        break;
      }

      // optional .bgs.protocol.channel.v1.ChannelState.PrivacyLevel privacy_level = 7 [default = PRIVACY_LEVEL_OPEN];
      case 7: {
        if (tag == 56) {
         parse_privacy_level:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::channel::v1::ChannelState_PrivacyLevel_IsValid(value)) {
            set_privacy_level(static_cast< ::bgs::protocol::channel::v1::ChannelState_PrivacyLevel >(value));
          } else {
            mutable_unknown_fields()->AddVarint(7, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_name;
        break;
      }

      // optional string name = 8;
      case 8: {
        if (tag == 66) {
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
        if (input->ExpectTag(82)) goto parse_channel_type;
        break;
      }

      // optional string channel_type = 10 [default = "default"];
      case 10: {
        if (tag == 82) {
         parse_channel_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_channel_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->channel_type().data(), this->channel_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "channel_type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(93)) goto parse_program;
        break;
      }

      // optional fixed32 program = 11 [default = 0];
      case 11: {
        if (tag == 93) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(104)) goto parse_subscribe_to_presence;
        break;
      }

      // optional bool subscribe_to_presence = 13 [default = true];
      case 13: {
        if (tag == 104) {
         parse_subscribe_to_presence:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &subscribe_to_presence_)));
          set_has_subscribe_to_presence();
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
        if ((800u <= tag && tag < 80000u)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.ChannelState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.ChannelState)
  return false;
#undef DO_
}

void ChannelState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.ChannelState)
  // optional uint32 max_members = 1;
  if (has_max_members()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->max_members(), output);
  }

  // optional uint32 min_members = 2;
  if (has_min_members()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->min_members(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->attribute(i), output);
  }

  // repeated .bgs.protocol.Invitation invitation = 4;
  for (int i = 0; i < this->invitation_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->invitation(i), output);
  }

  // optional uint32 reason = 6;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->reason(), output);
  }

  // optional .bgs.protocol.channel.v1.ChannelState.PrivacyLevel privacy_level = 7 [default = PRIVACY_LEVEL_OPEN];
  if (has_privacy_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      7, this->privacy_level(), output);
  }

  // optional string name = 8;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->name(), output);
  }

  // optional string channel_type = 10 [default = "default"];
  if (has_channel_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->channel_type().data(), this->channel_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "channel_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      10, this->channel_type(), output);
  }

  // optional fixed32 program = 11 [default = 0];
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(11, this->program(), output);
  }

  // optional bool subscribe_to_presence = 13 [default = true];
  if (has_subscribe_to_presence()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(13, this->subscribe_to_presence(), output);
  }

  // Extension range [100, 10000)
  _extensions_.SerializeWithCachedSizes(
      100, 10000, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.ChannelState)
}

::google::protobuf::uint8* ChannelState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ChannelState)
  // optional uint32 max_members = 1;
  if (has_max_members()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->max_members(), target);
  }

  // optional uint32 min_members = 2;
  if (has_min_members()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->min_members(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->attribute(i), target);
  }

  // repeated .bgs.protocol.Invitation invitation = 4;
  for (int i = 0; i < this->invitation_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->invitation(i), target);
  }

  // optional uint32 reason = 6;
  if (has_reason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->reason(), target);
  }

  // optional .bgs.protocol.channel.v1.ChannelState.PrivacyLevel privacy_level = 7 [default = PRIVACY_LEVEL_OPEN];
  if (has_privacy_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      7, this->privacy_level(), target);
  }

  // optional string name = 8;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->name(), target);
  }

  // optional string channel_type = 10 [default = "default"];
  if (has_channel_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->channel_type().data(), this->channel_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "channel_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->channel_type(), target);
  }

  // optional fixed32 program = 11 [default = 0];
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(11, this->program(), target);
  }

  // optional bool subscribe_to_presence = 13 [default = true];
  if (has_subscribe_to_presence()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(13, this->subscribe_to_presence(), target);
  }

  // Extension range [100, 10000)
  target = _extensions_.SerializeWithCachedSizesToArray(
      100, 10000, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ChannelState)
  return target;
}

int ChannelState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 max_members = 1;
    if (has_max_members()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_members());
    }

    // optional uint32 min_members = 2;
    if (has_min_members()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->min_members());
    }

    // optional uint32 reason = 6;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->reason());
    }

    // optional .bgs.protocol.channel.v1.ChannelState.PrivacyLevel privacy_level = 7 [default = PRIVACY_LEVEL_OPEN];
    if (has_privacy_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->privacy_level());
    }

    // optional string name = 8;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional string channel_type = 10 [default = "default"];
    if (has_channel_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->channel_type());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional fixed32 program = 11 [default = 0];
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional bool subscribe_to_presence = 13 [default = true];
    if (has_subscribe_to_presence()) {
      total_size += 1 + 1;
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 3;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
  }

  // repeated .bgs.protocol.Invitation invitation = 4;
  total_size += 1 * this->invitation_size();
  for (int i = 0; i < this->invitation_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->invitation(i));
  }

  total_size += _extensions_.ByteSize();

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
  attribute_.MergeFrom(from.attribute_);
  invitation_.MergeFrom(from.invitation_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_max_members()) {
      set_max_members(from.max_members());
    }
    if (from.has_min_members()) {
      set_min_members(from.min_members());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
    if (from.has_privacy_level()) {
      set_privacy_level(from.privacy_level());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_channel_type()) {
      set_channel_type(from.channel_type());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_subscribe_to_presence()) {
      set_subscribe_to_presence(from.subscribe_to_presence());
    }
  }
  _extensions_.MergeFrom(from._extensions_);
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

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->invitation())) return false;

  if (!_extensions_.IsInitialized()) return false;  return true;
}

void ChannelState::Swap(ChannelState* other) {
  if (other != this) {
    std::swap(max_members_, other->max_members_);
    std::swap(min_members_, other->min_members_);
    attribute_.Swap(&other->attribute_);
    invitation_.Swap(&other->invitation_);
    std::swap(reason_, other->reason_);
    std::swap(privacy_level_, other->privacy_level_);
    std::swap(name_, other->name_);
    std::swap(channel_type_, other->channel_type_);
    std::swap(program_, other->program_);
    std::swap(subscribe_to_presence_, other->subscribe_to_presence_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata ChannelState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChannelState_descriptor_;
  metadata.reflection = ChannelState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemberAccountInfo::kBattleTagFieldNumber;
#endif  // !_MSC_VER

MemberAccountInfo::MemberAccountInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.MemberAccountInfo)
}

void MemberAccountInfo::InitAsDefaultInstance() {
}

MemberAccountInfo::MemberAccountInfo(const MemberAccountInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.MemberAccountInfo)
}

void MemberAccountInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemberAccountInfo::~MemberAccountInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.MemberAccountInfo)
  SharedDtor();
}

void MemberAccountInfo::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
  }
}

void MemberAccountInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemberAccountInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemberAccountInfo_descriptor_;
}

const MemberAccountInfo& MemberAccountInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

MemberAccountInfo* MemberAccountInfo::default_instance_ = NULL;

MemberAccountInfo* MemberAccountInfo::New() const {
  return new MemberAccountInfo;
}

void MemberAccountInfo::Clear() {
  if (has_battle_tag()) {
    if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      battle_tag_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemberAccountInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.MemberAccountInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string battle_tag = 3;
      case 3: {
        if (tag == 26) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.MemberAccountInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.MemberAccountInfo)
  return false;
#undef DO_
}

void MemberAccountInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.MemberAccountInfo)
  // optional string battle_tag = 3;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->battle_tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.MemberAccountInfo)
}

::google::protobuf::uint8* MemberAccountInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.MemberAccountInfo)
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

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.MemberAccountInfo)
  return target;
}

int MemberAccountInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string battle_tag = 3;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
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

void MemberAccountInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemberAccountInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemberAccountInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemberAccountInfo::MergeFrom(const MemberAccountInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemberAccountInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemberAccountInfo::CopyFrom(const MemberAccountInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemberAccountInfo::IsInitialized() const {

  return true;
}

void MemberAccountInfo::Swap(MemberAccountInfo* other) {
  if (other != this) {
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemberAccountInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemberAccountInfo_descriptor_;
  metadata.reflection = MemberAccountInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemberState::kAttributeFieldNumber;
const int MemberState::kRoleFieldNumber;
const int MemberState::kPrivilegesFieldNumber;
const int MemberState::kInfoFieldNumber;
#endif  // !_MSC_VER

MemberState::MemberState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.MemberState)
}

void MemberState::InitAsDefaultInstance() {
  info_ = const_cast< ::bgs::protocol::channel::v1::MemberAccountInfo*>(&::bgs::protocol::channel::v1::MemberAccountInfo::default_instance());
}

MemberState::MemberState(const MemberState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.MemberState)
}

void MemberState::SharedCtor() {
  _cached_size_ = 0;
  _role_cached_byte_size_ = 0;
  privileges_ = GOOGLE_ULONGLONG(0);
  info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemberState::~MemberState() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.MemberState)
  SharedDtor();
}

void MemberState::SharedDtor() {
  if (this != default_instance_) {
    delete info_;
  }
}

void MemberState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemberState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemberState_descriptor_;
}

const MemberState& MemberState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

MemberState* MemberState::default_instance_ = NULL;

MemberState* MemberState::New() const {
  return new MemberState;
}

void MemberState::Clear() {
  if (_has_bits_[0 / 32] & 12) {
    privileges_ = GOOGLE_ULONGLONG(0);
    if (has_info()) {
      if (info_ != NULL) info_->::bgs::protocol::channel::v1::MemberAccountInfo::Clear();
    }
  }
  attribute_.Clear();
  role_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemberState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.MemberState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.Attribute attribute = 1;
      case 1: {
        if (tag == 10) {
         parse_attribute:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attribute()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_attribute;
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
        if (input->ExpectTag(24)) goto parse_privileges;
        break;
      }

      // optional uint64 privileges = 3 [default = 0];
      case 3: {
        if (tag == 24) {
         parse_privileges:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &privileges_)));
          set_has_privileges();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_info;
        break;
      }

      // optional .bgs.protocol.channel.v1.MemberAccountInfo info = 4;
      case 4: {
        if (tag == 34) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.MemberState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.MemberState)
  return false;
#undef DO_
}

void MemberState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.MemberState)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attribute(i), output);
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

  // optional uint64 privileges = 3 [default = 0];
  if (has_privileges()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->privileges(), output);
  }

  // optional .bgs.protocol.channel.v1.MemberAccountInfo info = 4;
  if (has_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.MemberState)
}

::google::protobuf::uint8* MemberState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.MemberState)
  // repeated .bgs.protocol.Attribute attribute = 1;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attribute(i), target);
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

  // optional uint64 privileges = 3 [default = 0];
  if (has_privileges()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->privileges(), target);
  }

  // optional .bgs.protocol.channel.v1.MemberAccountInfo info = 4;
  if (has_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.MemberState)
  return target;
}

int MemberState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    // optional uint64 privileges = 3 [default = 0];
    if (has_privileges()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->privileges());
    }

    // optional .bgs.protocol.channel.v1.MemberAccountInfo info = 4;
    if (has_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->info());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 1;
  total_size += 1 * this->attribute_size();
  for (int i = 0; i < this->attribute_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attribute(i));
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

void MemberState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemberState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemberState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemberState::MergeFrom(const MemberState& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  role_.MergeFrom(from.role_);
  if (from._has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    if (from.has_privileges()) {
      set_privileges(from.privileges());
    }
    if (from.has_info()) {
      mutable_info()->::bgs::protocol::channel::v1::MemberAccountInfo::MergeFrom(from.info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemberState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemberState::CopyFrom(const MemberState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemberState::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void MemberState::Swap(MemberState* other) {
  if (other != this) {
    attribute_.Swap(&other->attribute_);
    role_.Swap(&other->role_);
    std::swap(privileges_, other->privileges_);
    std::swap(info_, other->info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemberState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemberState_descriptor_;
  metadata.reflection = MemberState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Member::kIdentityFieldNumber;
const int Member::kStateFieldNumber;
#endif  // !_MSC_VER

Member::Member()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.Member)
}

void Member::InitAsDefaultInstance() {
  identity_ = const_cast< ::bgs::protocol::Identity*>(&::bgs::protocol::Identity::default_instance());
  state_ = const_cast< ::bgs::protocol::channel::v1::MemberState*>(&::bgs::protocol::channel::v1::MemberState::default_instance());
}

Member::Member(const Member& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.Member)
}

void Member::SharedCtor() {
  _cached_size_ = 0;
  identity_ = NULL;
  state_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Member::~Member() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.Member)
  SharedDtor();
}

void Member::SharedDtor() {
  if (this != default_instance_) {
    delete identity_;
    delete state_;
  }
}

void Member::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Member::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Member_descriptor_;
}

const Member& Member::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_channel_5ftypes_2eproto();
  return *default_instance_;
}

Member* Member::default_instance_ = NULL;

Member* Member::New() const {
  return new Member;
}

void Member::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_identity()) {
      if (identity_ != NULL) identity_->::bgs::protocol::Identity::Clear();
    }
    if (has_state()) {
      if (state_ != NULL) state_->::bgs::protocol::channel::v1::MemberState::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Member::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.channel.v1.Member)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.Identity identity = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_state;
        break;
      }

      // required .bgs.protocol.channel.v1.MemberState state = 2;
      case 2: {
        if (tag == 18) {
         parse_state:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.channel.v1.Member)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.channel.v1.Member)
  return false;
#undef DO_
}

void Member::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.channel.v1.Member)
  // required .bgs.protocol.Identity identity = 1;
  if (has_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->identity(), output);
  }

  // required .bgs.protocol.channel.v1.MemberState state = 2;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->state(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.channel.v1.Member)
}

::google::protobuf::uint8* Member::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.Member)
  // required .bgs.protocol.Identity identity = 1;
  if (has_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->identity(), target);
  }

  // required .bgs.protocol.channel.v1.MemberState state = 2;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->state(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.Member)
  return target;
}

int Member::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.Identity identity = 1;
    if (has_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->identity());
    }

    // required .bgs.protocol.channel.v1.MemberState state = 2;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state());
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

void Member::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Member* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Member*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Member::MergeFrom(const Member& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_identity()) {
      mutable_identity()->::bgs::protocol::Identity::MergeFrom(from.identity());
    }
    if (from.has_state()) {
      mutable_state()->::bgs::protocol::channel::v1::MemberState::MergeFrom(from.state());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Member::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Member::CopyFrom(const Member& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Member::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_identity()) {
    if (!this->identity().IsInitialized()) return false;
  }
  if (has_state()) {
    if (!this->state().IsInitialized()) return false;
  }
  return true;
}

void Member::Swap(Member* other) {
  if (other != this) {
    std::swap(identity_, other->identity_);
    std::swap(state_, other->state_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Member::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Member_descriptor_;
  metadata.reflection = Member_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
