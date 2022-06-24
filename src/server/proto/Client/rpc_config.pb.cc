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
#include "rpc_config.pb.h"

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
namespace config {

namespace {

const ::google::protobuf::Descriptor* RPCMethodConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RPCMethodConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* RPCMeterConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RPCMeterConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* ProtocolAlias_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ProtocolAlias_reflection_ = NULL;
const ::google::protobuf::Descriptor* ServiceAliases_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServiceAliases_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_rpc_5fconfig_2eproto() {
  protobuf_AddDesc_rpc_5fconfig_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rpc_config.proto");
  GOOGLE_CHECK(file != NULL);
  RPCMethodConfig_descriptor_ = file->message_type(0);
  static const int RPCMethodConfig_offsets_[15] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, service_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, method_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, fixed_call_cost_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, fixed_packet_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, variable_multiplier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, multiplier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, rate_limit_count_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, rate_limit_seconds_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, max_packet_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, max_encoded_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, timeout_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, cap_balance_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, income_per_second_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, service_hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, method_id_),
  };
  RPCMethodConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RPCMethodConfig_descriptor_,
      RPCMethodConfig::default_instance_,
      RPCMethodConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMethodConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RPCMethodConfig));
  RPCMeterConfig_descriptor_ = file->message_type(1);
  static const int RPCMeterConfig_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, method_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, income_per_second_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, initial_balance_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, cap_balance_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, startup_period_),
  };
  RPCMeterConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RPCMeterConfig_descriptor_,
      RPCMeterConfig::default_instance_,
      RPCMeterConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RPCMeterConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RPCMeterConfig));
  ProtocolAlias_descriptor_ = file->message_type(2);
  static const int ProtocolAlias_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtocolAlias, server_service_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtocolAlias, client_service_name_),
  };
  ProtocolAlias_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ProtocolAlias_descriptor_,
      ProtocolAlias::default_instance_,
      ProtocolAlias_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtocolAlias, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtocolAlias, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ProtocolAlias));
  ServiceAliases_descriptor_ = file->message_type(3);
  static const int ServiceAliases_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceAliases, protocol_alias_),
  };
  ServiceAliases_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ServiceAliases_descriptor_,
      ServiceAliases::default_instance_,
      ServiceAliases_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceAliases, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceAliases, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ServiceAliases));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rpc_5fconfig_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RPCMethodConfig_descriptor_, &RPCMethodConfig::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RPCMeterConfig_descriptor_, &RPCMeterConfig::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ProtocolAlias_descriptor_, &ProtocolAlias::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ServiceAliases_descriptor_, &ServiceAliases::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rpc_5fconfig_2eproto() {
  delete RPCMethodConfig::default_instance_;
  delete RPCMethodConfig_reflection_;
  delete RPCMeterConfig::default_instance_;
  delete RPCMeterConfig_reflection_;
  delete ProtocolAlias::default_instance_;
  delete ProtocolAlias_reflection_;
  delete ServiceAliases::default_instance_;
  delete ServiceAliases_reflection_;
}

void protobuf_AddDesc_rpc_5fconfig_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020rpc_config.proto\022\023bgs.protocol.config\""
    "\213\003\n\017RPCMethodConfig\022\030\n\014service_name\030\001 \001("
    "\tB\002\030\001\022\027\n\013method_name\030\002 \001(\tB\002\030\001\022\032\n\017fixed_"
    "call_cost\030\003 \001(\r:\0011\022\034\n\021fixed_packet_size\030"
    "\004 \001(\r:\0010\022\036\n\023variable_multiplier\030\005 \001(\002:\0010"
    "\022\025\n\nmultiplier\030\006 \001(\002:\0011\022\030\n\020rate_limit_co"
    "unt\030\007 \001(\r\022\032\n\022rate_limit_seconds\030\010 \001(\r\022\027\n"
    "\017max_packet_size\030\t \001(\r\022\030\n\020max_encoded_si"
    "ze\030\n \001(\r\022\017\n\007timeout\030\013 \001(\002\022\023\n\013cap_balance"
    "\030\014 \001(\r\022\034\n\021income_per_second\030\r \001(\002:\0010\022\024\n\014"
    "service_hash\030\016 \001(\r\022\021\n\tmethod_id\030\017 \001(\r\"\255\001"
    "\n\016RPCMeterConfig\0224\n\006method\030\001 \003(\0132$.bgs.p"
    "rotocol.config.RPCMethodConfig\022\034\n\021income"
    "_per_second\030\002 \001(\r:\0011\022\027\n\017initial_balance\030"
    "\003 \001(\r\022\023\n\013cap_balance\030\004 \001(\r\022\031\n\016startup_pe"
    "riod\030\005 \001(\002:\0010\"I\n\rProtocolAlias\022\033\n\023server"
    "_service_name\030\001 \002(\t\022\033\n\023client_service_na"
    "me\030\002 \002(\t\"L\n\016ServiceAliases\022:\n\016protocol_a"
    "lias\030\001 \003(\0132\".bgs.protocol.config.Protoco"
    "lAliasB\002H\001", 770);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rpc_config.proto", &protobuf_RegisterTypes);
  RPCMethodConfig::default_instance_ = new RPCMethodConfig();
  RPCMeterConfig::default_instance_ = new RPCMeterConfig();
  ProtocolAlias::default_instance_ = new ProtocolAlias();
  ServiceAliases::default_instance_ = new ServiceAliases();
  RPCMethodConfig::default_instance_->InitAsDefaultInstance();
  RPCMeterConfig::default_instance_->InitAsDefaultInstance();
  ProtocolAlias::default_instance_->InitAsDefaultInstance();
  ServiceAliases::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rpc_5fconfig_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rpc_5fconfig_2eproto {
  StaticDescriptorInitializer_rpc_5fconfig_2eproto() {
    protobuf_AddDesc_rpc_5fconfig_2eproto();
  }
} static_descriptor_initializer_rpc_5fconfig_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RPCMethodConfig::kServiceNameFieldNumber;
const int RPCMethodConfig::kMethodNameFieldNumber;
const int RPCMethodConfig::kFixedCallCostFieldNumber;
const int RPCMethodConfig::kFixedPacketSizeFieldNumber;
const int RPCMethodConfig::kVariableMultiplierFieldNumber;
const int RPCMethodConfig::kMultiplierFieldNumber;
const int RPCMethodConfig::kRateLimitCountFieldNumber;
const int RPCMethodConfig::kRateLimitSecondsFieldNumber;
const int RPCMethodConfig::kMaxPacketSizeFieldNumber;
const int RPCMethodConfig::kMaxEncodedSizeFieldNumber;
const int RPCMethodConfig::kTimeoutFieldNumber;
const int RPCMethodConfig::kCapBalanceFieldNumber;
const int RPCMethodConfig::kIncomePerSecondFieldNumber;
const int RPCMethodConfig::kServiceHashFieldNumber;
const int RPCMethodConfig::kMethodIdFieldNumber;
#endif  // !_MSC_VER

RPCMethodConfig::RPCMethodConfig()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.config.RPCMethodConfig)
}

void RPCMethodConfig::InitAsDefaultInstance() {
}

RPCMethodConfig::RPCMethodConfig(const RPCMethodConfig& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.config.RPCMethodConfig)
}

void RPCMethodConfig::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  fixed_call_cost_ = 1u;
  fixed_packet_size_ = 0u;
  variable_multiplier_ = 0;
  multiplier_ = 1;
  rate_limit_count_ = 0u;
  rate_limit_seconds_ = 0u;
  max_packet_size_ = 0u;
  max_encoded_size_ = 0u;
  timeout_ = 0;
  cap_balance_ = 0u;
  income_per_second_ = 0;
  service_hash_ = 0u;
  method_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RPCMethodConfig::~RPCMethodConfig() {
  // @@protoc_insertion_point(destructor:bgs.protocol.config.RPCMethodConfig)
  SharedDtor();
}

void RPCMethodConfig::SharedDtor() {
  if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete service_name_;
  }
  if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete method_name_;
  }
  if (this != default_instance_) {
  }
}

void RPCMethodConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RPCMethodConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RPCMethodConfig_descriptor_;
}

const RPCMethodConfig& RPCMethodConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5fconfig_2eproto();
  return *default_instance_;
}

RPCMethodConfig* RPCMethodConfig::default_instance_ = NULL;

RPCMethodConfig* RPCMethodConfig::New() const {
  return new RPCMethodConfig;
}

void RPCMethodConfig::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RPCMethodConfig*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(fixed_packet_size_, variable_multiplier_);
    ZR_(rate_limit_count_, rate_limit_seconds_);
    if (has_service_name()) {
      if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        service_name_->clear();
      }
    }
    if (has_method_name()) {
      if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        method_name_->clear();
      }
    }
    fixed_call_cost_ = 1u;
    multiplier_ = 1;
  }
  if (_has_bits_[8 / 32] & 32512) {
    ZR_(max_packet_size_, method_id_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RPCMethodConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.config.RPCMethodConfig)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string service_name = 1 [deprecated = true];
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_service_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->service_name().data(), this->service_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "service_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_method_name;
        break;
      }

      // optional string method_name = 2 [deprecated = true];
      case 2: {
        if (tag == 18) {
         parse_method_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->method_name().data(), this->method_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "method_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_fixed_call_cost;
        break;
      }

      // optional uint32 fixed_call_cost = 3 [default = 1];
      case 3: {
        if (tag == 24) {
         parse_fixed_call_cost:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fixed_call_cost_)));
          set_has_fixed_call_cost();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_fixed_packet_size;
        break;
      }

      // optional uint32 fixed_packet_size = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_fixed_packet_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fixed_packet_size_)));
          set_has_fixed_packet_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_variable_multiplier;
        break;
      }

      // optional float variable_multiplier = 5 [default = 0];
      case 5: {
        if (tag == 45) {
         parse_variable_multiplier:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &variable_multiplier_)));
          set_has_variable_multiplier();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(53)) goto parse_multiplier;
        break;
      }

      // optional float multiplier = 6 [default = 1];
      case 6: {
        if (tag == 53) {
         parse_multiplier:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &multiplier_)));
          set_has_multiplier();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_rate_limit_count;
        break;
      }

      // optional uint32 rate_limit_count = 7;
      case 7: {
        if (tag == 56) {
         parse_rate_limit_count:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &rate_limit_count_)));
          set_has_rate_limit_count();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_rate_limit_seconds;
        break;
      }

      // optional uint32 rate_limit_seconds = 8;
      case 8: {
        if (tag == 64) {
         parse_rate_limit_seconds:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &rate_limit_seconds_)));
          set_has_rate_limit_seconds();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_max_packet_size;
        break;
      }

      // optional uint32 max_packet_size = 9;
      case 9: {
        if (tag == 72) {
         parse_max_packet_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_packet_size_)));
          set_has_max_packet_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_max_encoded_size;
        break;
      }

      // optional uint32 max_encoded_size = 10;
      case 10: {
        if (tag == 80) {
         parse_max_encoded_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &max_encoded_size_)));
          set_has_max_encoded_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(93)) goto parse_timeout;
        break;
      }

      // optional float timeout = 11;
      case 11: {
        if (tag == 93) {
         parse_timeout:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &timeout_)));
          set_has_timeout();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_cap_balance;
        break;
      }

      // optional uint32 cap_balance = 12;
      case 12: {
        if (tag == 96) {
         parse_cap_balance:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &cap_balance_)));
          set_has_cap_balance();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(109)) goto parse_income_per_second;
        break;
      }

      // optional float income_per_second = 13 [default = 0];
      case 13: {
        if (tag == 109) {
         parse_income_per_second:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &income_per_second_)));
          set_has_income_per_second();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(112)) goto parse_service_hash;
        break;
      }

      // optional uint32 service_hash = 14;
      case 14: {
        if (tag == 112) {
         parse_service_hash:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &service_hash_)));
          set_has_service_hash();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(120)) goto parse_method_id;
        break;
      }

      // optional uint32 method_id = 15;
      case 15: {
        if (tag == 120) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.config.RPCMethodConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.config.RPCMethodConfig)
  return false;
#undef DO_
}

void RPCMethodConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.config.RPCMethodConfig)
  // optional string service_name = 1 [deprecated = true];
  if (has_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->service_name().data(), this->service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "service_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->service_name(), output);
  }

  // optional string method_name = 2 [deprecated = true];
  if (has_method_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->method_name().data(), this->method_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "method_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->method_name(), output);
  }

  // optional uint32 fixed_call_cost = 3 [default = 1];
  if (has_fixed_call_cost()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->fixed_call_cost(), output);
  }

  // optional uint32 fixed_packet_size = 4 [default = 0];
  if (has_fixed_packet_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->fixed_packet_size(), output);
  }

  // optional float variable_multiplier = 5 [default = 0];
  if (has_variable_multiplier()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->variable_multiplier(), output);
  }

  // optional float multiplier = 6 [default = 1];
  if (has_multiplier()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->multiplier(), output);
  }

  // optional uint32 rate_limit_count = 7;
  if (has_rate_limit_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->rate_limit_count(), output);
  }

  // optional uint32 rate_limit_seconds = 8;
  if (has_rate_limit_seconds()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->rate_limit_seconds(), output);
  }

  // optional uint32 max_packet_size = 9;
  if (has_max_packet_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->max_packet_size(), output);
  }

  // optional uint32 max_encoded_size = 10;
  if (has_max_encoded_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->max_encoded_size(), output);
  }

  // optional float timeout = 11;
  if (has_timeout()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(11, this->timeout(), output);
  }

  // optional uint32 cap_balance = 12;
  if (has_cap_balance()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->cap_balance(), output);
  }

  // optional float income_per_second = 13 [default = 0];
  if (has_income_per_second()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(13, this->income_per_second(), output);
  }

  // optional uint32 service_hash = 14;
  if (has_service_hash()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(14, this->service_hash(), output);
  }

  // optional uint32 method_id = 15;
  if (has_method_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(15, this->method_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.config.RPCMethodConfig)
}

::google::protobuf::uint8* RPCMethodConfig::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.config.RPCMethodConfig)
  // optional string service_name = 1 [deprecated = true];
  if (has_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->service_name().data(), this->service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "service_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->service_name(), target);
  }

  // optional string method_name = 2 [deprecated = true];
  if (has_method_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->method_name().data(), this->method_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "method_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->method_name(), target);
  }

  // optional uint32 fixed_call_cost = 3 [default = 1];
  if (has_fixed_call_cost()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->fixed_call_cost(), target);
  }

  // optional uint32 fixed_packet_size = 4 [default = 0];
  if (has_fixed_packet_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->fixed_packet_size(), target);
  }

  // optional float variable_multiplier = 5 [default = 0];
  if (has_variable_multiplier()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->variable_multiplier(), target);
  }

  // optional float multiplier = 6 [default = 1];
  if (has_multiplier()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->multiplier(), target);
  }

  // optional uint32 rate_limit_count = 7;
  if (has_rate_limit_count()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->rate_limit_count(), target);
  }

  // optional uint32 rate_limit_seconds = 8;
  if (has_rate_limit_seconds()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->rate_limit_seconds(), target);
  }

  // optional uint32 max_packet_size = 9;
  if (has_max_packet_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(9, this->max_packet_size(), target);
  }

  // optional uint32 max_encoded_size = 10;
  if (has_max_encoded_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->max_encoded_size(), target);
  }

  // optional float timeout = 11;
  if (has_timeout()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(11, this->timeout(), target);
  }

  // optional uint32 cap_balance = 12;
  if (has_cap_balance()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->cap_balance(), target);
  }

  // optional float income_per_second = 13 [default = 0];
  if (has_income_per_second()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(13, this->income_per_second(), target);
  }

  // optional uint32 service_hash = 14;
  if (has_service_hash()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(14, this->service_hash(), target);
  }

  // optional uint32 method_id = 15;
  if (has_method_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(15, this->method_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.config.RPCMethodConfig)
  return target;
}

int RPCMethodConfig::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string service_name = 1 [deprecated = true];
    if (has_service_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->service_name());
    }

    // optional string method_name = 2 [deprecated = true];
    if (has_method_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->method_name());
    }

    // optional uint32 fixed_call_cost = 3 [default = 1];
    if (has_fixed_call_cost()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fixed_call_cost());
    }

    // optional uint32 fixed_packet_size = 4 [default = 0];
    if (has_fixed_packet_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fixed_packet_size());
    }

    // optional float variable_multiplier = 5 [default = 0];
    if (has_variable_multiplier()) {
      total_size += 1 + 4;
    }

    // optional float multiplier = 6 [default = 1];
    if (has_multiplier()) {
      total_size += 1 + 4;
    }

    // optional uint32 rate_limit_count = 7;
    if (has_rate_limit_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->rate_limit_count());
    }

    // optional uint32 rate_limit_seconds = 8;
    if (has_rate_limit_seconds()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->rate_limit_seconds());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint32 max_packet_size = 9;
    if (has_max_packet_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_packet_size());
    }

    // optional uint32 max_encoded_size = 10;
    if (has_max_encoded_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->max_encoded_size());
    }

    // optional float timeout = 11;
    if (has_timeout()) {
      total_size += 1 + 4;
    }

    // optional uint32 cap_balance = 12;
    if (has_cap_balance()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->cap_balance());
    }

    // optional float income_per_second = 13 [default = 0];
    if (has_income_per_second()) {
      total_size += 1 + 4;
    }

    // optional uint32 service_hash = 14;
    if (has_service_hash()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->service_hash());
    }

    // optional uint32 method_id = 15;
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

void RPCMethodConfig::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RPCMethodConfig* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RPCMethodConfig*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RPCMethodConfig::MergeFrom(const RPCMethodConfig& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_service_name()) {
      set_service_name(from.service_name());
    }
    if (from.has_method_name()) {
      set_method_name(from.method_name());
    }
    if (from.has_fixed_call_cost()) {
      set_fixed_call_cost(from.fixed_call_cost());
    }
    if (from.has_fixed_packet_size()) {
      set_fixed_packet_size(from.fixed_packet_size());
    }
    if (from.has_variable_multiplier()) {
      set_variable_multiplier(from.variable_multiplier());
    }
    if (from.has_multiplier()) {
      set_multiplier(from.multiplier());
    }
    if (from.has_rate_limit_count()) {
      set_rate_limit_count(from.rate_limit_count());
    }
    if (from.has_rate_limit_seconds()) {
      set_rate_limit_seconds(from.rate_limit_seconds());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_max_packet_size()) {
      set_max_packet_size(from.max_packet_size());
    }
    if (from.has_max_encoded_size()) {
      set_max_encoded_size(from.max_encoded_size());
    }
    if (from.has_timeout()) {
      set_timeout(from.timeout());
    }
    if (from.has_cap_balance()) {
      set_cap_balance(from.cap_balance());
    }
    if (from.has_income_per_second()) {
      set_income_per_second(from.income_per_second());
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

void RPCMethodConfig::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RPCMethodConfig::CopyFrom(const RPCMethodConfig& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RPCMethodConfig::IsInitialized() const {

  return true;
}

void RPCMethodConfig::Swap(RPCMethodConfig* other) {
  if (other != this) {
    std::swap(service_name_, other->service_name_);
    std::swap(method_name_, other->method_name_);
    std::swap(fixed_call_cost_, other->fixed_call_cost_);
    std::swap(fixed_packet_size_, other->fixed_packet_size_);
    std::swap(variable_multiplier_, other->variable_multiplier_);
    std::swap(multiplier_, other->multiplier_);
    std::swap(rate_limit_count_, other->rate_limit_count_);
    std::swap(rate_limit_seconds_, other->rate_limit_seconds_);
    std::swap(max_packet_size_, other->max_packet_size_);
    std::swap(max_encoded_size_, other->max_encoded_size_);
    std::swap(timeout_, other->timeout_);
    std::swap(cap_balance_, other->cap_balance_);
    std::swap(income_per_second_, other->income_per_second_);
    std::swap(service_hash_, other->service_hash_);
    std::swap(method_id_, other->method_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RPCMethodConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RPCMethodConfig_descriptor_;
  metadata.reflection = RPCMethodConfig_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RPCMeterConfig::kMethodFieldNumber;
const int RPCMeterConfig::kIncomePerSecondFieldNumber;
const int RPCMeterConfig::kInitialBalanceFieldNumber;
const int RPCMeterConfig::kCapBalanceFieldNumber;
const int RPCMeterConfig::kStartupPeriodFieldNumber;
#endif  // !_MSC_VER

RPCMeterConfig::RPCMeterConfig()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.config.RPCMeterConfig)
}

void RPCMeterConfig::InitAsDefaultInstance() {
}

RPCMeterConfig::RPCMeterConfig(const RPCMeterConfig& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.config.RPCMeterConfig)
}

void RPCMeterConfig::SharedCtor() {
  _cached_size_ = 0;
  income_per_second_ = 1u;
  initial_balance_ = 0u;
  cap_balance_ = 0u;
  startup_period_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RPCMeterConfig::~RPCMeterConfig() {
  // @@protoc_insertion_point(destructor:bgs.protocol.config.RPCMeterConfig)
  SharedDtor();
}

void RPCMeterConfig::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RPCMeterConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RPCMeterConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RPCMeterConfig_descriptor_;
}

const RPCMeterConfig& RPCMeterConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5fconfig_2eproto();
  return *default_instance_;
}

RPCMeterConfig* RPCMeterConfig::default_instance_ = NULL;

RPCMeterConfig* RPCMeterConfig::New() const {
  return new RPCMeterConfig;
}

void RPCMeterConfig::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RPCMeterConfig*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 30) {
    ZR_(initial_balance_, startup_period_);
    income_per_second_ = 1u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  method_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RPCMeterConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.config.RPCMeterConfig)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.config.RPCMethodConfig method = 1;
      case 1: {
        if (tag == 10) {
         parse_method:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_method()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_method;
        if (input->ExpectTag(16)) goto parse_income_per_second;
        break;
      }

      // optional uint32 income_per_second = 2 [default = 1];
      case 2: {
        if (tag == 16) {
         parse_income_per_second:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &income_per_second_)));
          set_has_income_per_second();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_initial_balance;
        break;
      }

      // optional uint32 initial_balance = 3;
      case 3: {
        if (tag == 24) {
         parse_initial_balance:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &initial_balance_)));
          set_has_initial_balance();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_cap_balance;
        break;
      }

      // optional uint32 cap_balance = 4;
      case 4: {
        if (tag == 32) {
         parse_cap_balance:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &cap_balance_)));
          set_has_cap_balance();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_startup_period;
        break;
      }

      // optional float startup_period = 5 [default = 0];
      case 5: {
        if (tag == 45) {
         parse_startup_period:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &startup_period_)));
          set_has_startup_period();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.config.RPCMeterConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.config.RPCMeterConfig)
  return false;
#undef DO_
}

void RPCMeterConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.config.RPCMeterConfig)
  // repeated .bgs.protocol.config.RPCMethodConfig method = 1;
  for (int i = 0; i < this->method_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->method(i), output);
  }

  // optional uint32 income_per_second = 2 [default = 1];
  if (has_income_per_second()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->income_per_second(), output);
  }

  // optional uint32 initial_balance = 3;
  if (has_initial_balance()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->initial_balance(), output);
  }

  // optional uint32 cap_balance = 4;
  if (has_cap_balance()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->cap_balance(), output);
  }

  // optional float startup_period = 5 [default = 0];
  if (has_startup_period()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->startup_period(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.config.RPCMeterConfig)
}

::google::protobuf::uint8* RPCMeterConfig::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.config.RPCMeterConfig)
  // repeated .bgs.protocol.config.RPCMethodConfig method = 1;
  for (int i = 0; i < this->method_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->method(i), target);
  }

  // optional uint32 income_per_second = 2 [default = 1];
  if (has_income_per_second()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->income_per_second(), target);
  }

  // optional uint32 initial_balance = 3;
  if (has_initial_balance()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->initial_balance(), target);
  }

  // optional uint32 cap_balance = 4;
  if (has_cap_balance()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->cap_balance(), target);
  }

  // optional float startup_period = 5 [default = 0];
  if (has_startup_period()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->startup_period(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.config.RPCMeterConfig)
  return target;
}

int RPCMeterConfig::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional uint32 income_per_second = 2 [default = 1];
    if (has_income_per_second()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->income_per_second());
    }

    // optional uint32 initial_balance = 3;
    if (has_initial_balance()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->initial_balance());
    }

    // optional uint32 cap_balance = 4;
    if (has_cap_balance()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->cap_balance());
    }

    // optional float startup_period = 5 [default = 0];
    if (has_startup_period()) {
      total_size += 1 + 4;
    }

  }
  // repeated .bgs.protocol.config.RPCMethodConfig method = 1;
  total_size += 1 * this->method_size();
  for (int i = 0; i < this->method_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->method(i));
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

void RPCMeterConfig::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RPCMeterConfig* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RPCMeterConfig*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RPCMeterConfig::MergeFrom(const RPCMeterConfig& from) {
  GOOGLE_CHECK_NE(&from, this);
  method_.MergeFrom(from.method_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_income_per_second()) {
      set_income_per_second(from.income_per_second());
    }
    if (from.has_initial_balance()) {
      set_initial_balance(from.initial_balance());
    }
    if (from.has_cap_balance()) {
      set_cap_balance(from.cap_balance());
    }
    if (from.has_startup_period()) {
      set_startup_period(from.startup_period());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RPCMeterConfig::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RPCMeterConfig::CopyFrom(const RPCMeterConfig& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RPCMeterConfig::IsInitialized() const {

  return true;
}

void RPCMeterConfig::Swap(RPCMeterConfig* other) {
  if (other != this) {
    method_.Swap(&other->method_);
    std::swap(income_per_second_, other->income_per_second_);
    std::swap(initial_balance_, other->initial_balance_);
    std::swap(cap_balance_, other->cap_balance_);
    std::swap(startup_period_, other->startup_period_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RPCMeterConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RPCMeterConfig_descriptor_;
  metadata.reflection = RPCMeterConfig_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ProtocolAlias::kServerServiceNameFieldNumber;
const int ProtocolAlias::kClientServiceNameFieldNumber;
#endif  // !_MSC_VER

ProtocolAlias::ProtocolAlias()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.config.ProtocolAlias)
}

void ProtocolAlias::InitAsDefaultInstance() {
}

ProtocolAlias::ProtocolAlias(const ProtocolAlias& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.config.ProtocolAlias)
}

void ProtocolAlias::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  server_service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  client_service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ProtocolAlias::~ProtocolAlias() {
  // @@protoc_insertion_point(destructor:bgs.protocol.config.ProtocolAlias)
  SharedDtor();
}

void ProtocolAlias::SharedDtor() {
  if (server_service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete server_service_name_;
  }
  if (client_service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete client_service_name_;
  }
  if (this != default_instance_) {
  }
}

void ProtocolAlias::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ProtocolAlias::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ProtocolAlias_descriptor_;
}

const ProtocolAlias& ProtocolAlias::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5fconfig_2eproto();
  return *default_instance_;
}

ProtocolAlias* ProtocolAlias::default_instance_ = NULL;

ProtocolAlias* ProtocolAlias::New() const {
  return new ProtocolAlias;
}

void ProtocolAlias::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_server_service_name()) {
      if (server_service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        server_service_name_->clear();
      }
    }
    if (has_client_service_name()) {
      if (client_service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        client_service_name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ProtocolAlias::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.config.ProtocolAlias)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string server_service_name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_server_service_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->server_service_name().data(), this->server_service_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "server_service_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_client_service_name;
        break;
      }

      // required string client_service_name = 2;
      case 2: {
        if (tag == 18) {
         parse_client_service_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_service_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->client_service_name().data(), this->client_service_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "client_service_name");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.config.ProtocolAlias)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.config.ProtocolAlias)
  return false;
#undef DO_
}

void ProtocolAlias::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.config.ProtocolAlias)
  // required string server_service_name = 1;
  if (has_server_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->server_service_name().data(), this->server_service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "server_service_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->server_service_name(), output);
  }

  // required string client_service_name = 2;
  if (has_client_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_service_name().data(), this->client_service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_service_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->client_service_name(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.config.ProtocolAlias)
}

::google::protobuf::uint8* ProtocolAlias::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.config.ProtocolAlias)
  // required string server_service_name = 1;
  if (has_server_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->server_service_name().data(), this->server_service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "server_service_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->server_service_name(), target);
  }

  // required string client_service_name = 2;
  if (has_client_service_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_service_name().data(), this->client_service_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_service_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->client_service_name(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.config.ProtocolAlias)
  return target;
}

int ProtocolAlias::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string server_service_name = 1;
    if (has_server_service_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->server_service_name());
    }

    // required string client_service_name = 2;
    if (has_client_service_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_service_name());
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

void ProtocolAlias::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ProtocolAlias* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ProtocolAlias*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ProtocolAlias::MergeFrom(const ProtocolAlias& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_server_service_name()) {
      set_server_service_name(from.server_service_name());
    }
    if (from.has_client_service_name()) {
      set_client_service_name(from.client_service_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ProtocolAlias::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ProtocolAlias::CopyFrom(const ProtocolAlias& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProtocolAlias::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void ProtocolAlias::Swap(ProtocolAlias* other) {
  if (other != this) {
    std::swap(server_service_name_, other->server_service_name_);
    std::swap(client_service_name_, other->client_service_name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ProtocolAlias::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ProtocolAlias_descriptor_;
  metadata.reflection = ProtocolAlias_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ServiceAliases::kProtocolAliasFieldNumber;
#endif  // !_MSC_VER

ServiceAliases::ServiceAliases()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.config.ServiceAliases)
}

void ServiceAliases::InitAsDefaultInstance() {
}

ServiceAliases::ServiceAliases(const ServiceAliases& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.config.ServiceAliases)
}

void ServiceAliases::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ServiceAliases::~ServiceAliases() {
  // @@protoc_insertion_point(destructor:bgs.protocol.config.ServiceAliases)
  SharedDtor();
}

void ServiceAliases::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ServiceAliases::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServiceAliases::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServiceAliases_descriptor_;
}

const ServiceAliases& ServiceAliases::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpc_5fconfig_2eproto();
  return *default_instance_;
}

ServiceAliases* ServiceAliases::default_instance_ = NULL;

ServiceAliases* ServiceAliases::New() const {
  return new ServiceAliases;
}

void ServiceAliases::Clear() {
  protocol_alias_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ServiceAliases::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.config.ServiceAliases)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.config.ProtocolAlias protocol_alias = 1;
      case 1: {
        if (tag == 10) {
         parse_protocol_alias:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_protocol_alias()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_protocol_alias;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.config.ServiceAliases)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.config.ServiceAliases)
  return false;
#undef DO_
}

void ServiceAliases::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.config.ServiceAliases)
  // repeated .bgs.protocol.config.ProtocolAlias protocol_alias = 1;
  for (int i = 0; i < this->protocol_alias_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->protocol_alias(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.config.ServiceAliases)
}

::google::protobuf::uint8* ServiceAliases::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.config.ServiceAliases)
  // repeated .bgs.protocol.config.ProtocolAlias protocol_alias = 1;
  for (int i = 0; i < this->protocol_alias_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->protocol_alias(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.config.ServiceAliases)
  return target;
}

int ServiceAliases::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.config.ProtocolAlias protocol_alias = 1;
  total_size += 1 * this->protocol_alias_size();
  for (int i = 0; i < this->protocol_alias_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->protocol_alias(i));
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

void ServiceAliases::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ServiceAliases* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ServiceAliases*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ServiceAliases::MergeFrom(const ServiceAliases& from) {
  GOOGLE_CHECK_NE(&from, this);
  protocol_alias_.MergeFrom(from.protocol_alias_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ServiceAliases::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServiceAliases::CopyFrom(const ServiceAliases& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ServiceAliases::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->protocol_alias())) return false;
  return true;
}

void ServiceAliases::Swap(ServiceAliases* other) {
  if (other != this) {
    protocol_alias_.Swap(&other->protocol_alias_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ServiceAliases::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServiceAliases_descriptor_;
  metadata.reflection = ServiceAliases_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace config
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
