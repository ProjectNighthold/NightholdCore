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
#include "challenge_service.pb.h"

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
#include "BattlenetRpcErrorCodes.h"
// @@protoc_insertion_point(includes)

// Fix stupid windows.h included from Log.h->Common.h
#ifdef SendMessage
#undef SendMessage
#endif

namespace bgs {
namespace protocol {
namespace challenge {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* Challenge_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Challenge_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengePickedRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengePickedRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengePickedResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengePickedResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeAnsweredRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeAnsweredRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeAnsweredResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeAnsweredResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeCancelledRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeCancelledRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendChallengeToUserRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendChallengeToUserRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SendChallengeToUserResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SendChallengeToUserResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeUserRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeUserRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeResultRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeResultRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeExternalRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeExternalRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ChallengeExternalResult_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChallengeExternalResult_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* ChallengeService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* ChallengeListener_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_challenge_5fservice_2eproto() {
  protobuf_AddDesc_challenge_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "challenge_service.proto");
  GOOGLE_CHECK(file != NULL);
  Challenge_descriptor_ = file->message_type(0);
  static const int Challenge_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, answer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, retries_),
  };
  Challenge_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Challenge_descriptor_,
      Challenge::default_instance_,
      Challenge_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Challenge, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Challenge));
  ChallengePickedRequest_descriptor_ = file->message_type(1);
  static const int ChallengePickedRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedRequest, challenge_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedRequest, new_challenge_protocol_),
  };
  ChallengePickedRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengePickedRequest_descriptor_,
      ChallengePickedRequest::default_instance_,
      ChallengePickedRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengePickedRequest));
  ChallengePickedResponse_descriptor_ = file->message_type(2);
  static const int ChallengePickedResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedResponse, data_),
  };
  ChallengePickedResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengePickedResponse_descriptor_,
      ChallengePickedResponse::default_instance_,
      ChallengePickedResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengePickedResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengePickedResponse));
  ChallengeAnsweredRequest_descriptor_ = file->message_type(3);
  static const int ChallengeAnsweredRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredRequest, answer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredRequest, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredRequest, id_),
  };
  ChallengeAnsweredRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeAnsweredRequest_descriptor_,
      ChallengeAnsweredRequest::default_instance_,
      ChallengeAnsweredRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeAnsweredRequest));
  ChallengeAnsweredResponse_descriptor_ = file->message_type(4);
  static const int ChallengeAnsweredResponse_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredResponse, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredResponse, do_retry_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredResponse, record_not_found_),
  };
  ChallengeAnsweredResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeAnsweredResponse_descriptor_,
      ChallengeAnsweredResponse::default_instance_,
      ChallengeAnsweredResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeAnsweredResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeAnsweredResponse));
  ChallengeCancelledRequest_descriptor_ = file->message_type(5);
  static const int ChallengeCancelledRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeCancelledRequest, id_),
  };
  ChallengeCancelledRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeCancelledRequest_descriptor_,
      ChallengeCancelledRequest::default_instance_,
      ChallengeCancelledRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeCancelledRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeCancelledRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeCancelledRequest));
  SendChallengeToUserRequest_descriptor_ = file->message_type(6);
  static const int SendChallengeToUserRequest_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, peer_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, challenges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, context_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, timeout_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, attributes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, account_id_),
  };
  SendChallengeToUserRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendChallengeToUserRequest_descriptor_,
      SendChallengeToUserRequest::default_instance_,
      SendChallengeToUserRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendChallengeToUserRequest));
  SendChallengeToUserResponse_descriptor_ = file->message_type(7);
  static const int SendChallengeToUserResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserResponse, id_),
  };
  SendChallengeToUserResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SendChallengeToUserResponse_descriptor_,
      SendChallengeToUserResponse::default_instance_,
      SendChallengeToUserResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SendChallengeToUserResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SendChallengeToUserResponse));
  ChallengeUserRequest_descriptor_ = file->message_type(8);
  static const int ChallengeUserRequest_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, challenges_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, context_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, deadline_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, attributes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, game_account_id_),
  };
  ChallengeUserRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeUserRequest_descriptor_,
      ChallengeUserRequest::default_instance_,
      ChallengeUserRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeUserRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeUserRequest));
  ChallengeResultRequest_descriptor_ = file->message_type(9);
  static const int ChallengeResultRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, error_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, answer_),
  };
  ChallengeResultRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeResultRequest_descriptor_,
      ChallengeResultRequest::default_instance_,
      ChallengeResultRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeResultRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeResultRequest));
  ChallengeExternalRequest_descriptor_ = file->message_type(10);
  static const int ChallengeExternalRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalRequest, request_token_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalRequest, payload_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalRequest, payload_),
  };
  ChallengeExternalRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeExternalRequest_descriptor_,
      ChallengeExternalRequest::default_instance_,
      ChallengeExternalRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeExternalRequest));
  ChallengeExternalResult_descriptor_ = file->message_type(11);
  static const int ChallengeExternalResult_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalResult, request_token_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalResult, passed_),
  };
  ChallengeExternalResult_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChallengeExternalResult_descriptor_,
      ChallengeExternalResult::default_instance_,
      ChallengeExternalResult_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalResult, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChallengeExternalResult, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChallengeExternalResult));
  ChallengeService_descriptor_ = file->service(0);
  ChallengeListener_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_challenge_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Challenge_descriptor_, &Challenge::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengePickedRequest_descriptor_, &ChallengePickedRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengePickedResponse_descriptor_, &ChallengePickedResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeAnsweredRequest_descriptor_, &ChallengeAnsweredRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeAnsweredResponse_descriptor_, &ChallengeAnsweredResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeCancelledRequest_descriptor_, &ChallengeCancelledRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendChallengeToUserRequest_descriptor_, &SendChallengeToUserRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SendChallengeToUserResponse_descriptor_, &SendChallengeToUserResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeUserRequest_descriptor_, &ChallengeUserRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeResultRequest_descriptor_, &ChallengeResultRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeExternalRequest_descriptor_, &ChallengeExternalRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChallengeExternalResult_descriptor_, &ChallengeExternalResult::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_challenge_5fservice_2eproto() {
  delete Challenge::default_instance_;
  delete Challenge_reflection_;
  delete ChallengePickedRequest::default_instance_;
  delete ChallengePickedRequest_reflection_;
  delete ChallengePickedResponse::default_instance_;
  delete ChallengePickedResponse_reflection_;
  delete ChallengeAnsweredRequest::default_instance_;
  delete ChallengeAnsweredRequest_reflection_;
  delete ChallengeAnsweredResponse::default_instance_;
  delete ChallengeAnsweredResponse_reflection_;
  delete ChallengeCancelledRequest::default_instance_;
  delete ChallengeCancelledRequest_reflection_;
  delete SendChallengeToUserRequest::default_instance_;
  delete SendChallengeToUserRequest_reflection_;
  delete SendChallengeToUserResponse::default_instance_;
  delete SendChallengeToUserResponse_reflection_;
  delete ChallengeUserRequest::default_instance_;
  delete ChallengeUserRequest_reflection_;
  delete ChallengeResultRequest::default_instance_;
  delete ChallengeResultRequest_reflection_;
  delete ChallengeExternalRequest::default_instance_;
  delete ChallengeExternalRequest_reflection_;
  delete ChallengeExternalResult::default_instance_;
  delete ChallengeExternalResult_reflection_;
}

void protobuf_AddDesc_challenge_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027challenge_service.proto\022\031bgs.protocol."
    "challenge.v1\032\025attribute_types.proto\032\022ent"
    "ity_types.proto\032\017rpc_types.proto\"N\n\tChal"
    "lenge\022\014\n\004type\030\001 \002(\007\022\014\n\004info\030\002 \001(\t\022\024\n\006ans"
    "wer\030\003 \001(\tB\004\200\265\030\001\022\017\n\007retries\030\004 \001(\r\"^\n\026Chal"
    "lengePickedRequest\022\021\n\tchallenge\030\001 \002(\007\022\n\n"
    "\002id\030\002 \001(\r\022%\n\026new_challenge_protocol\030\003 \001("
    "\010:\005false\"-\n\027ChallengePickedResponse\022\022\n\004d"
    "ata\030\001 \001(\014B\004\200\265\030\001\"P\n\030ChallengeAnsweredRequ"
    "est\022\024\n\006answer\030\001 \002(\tB\004\200\265\030\001\022\022\n\004data\030\002 \001(\014B"
    "\004\200\265\030\001\022\n\n\002id\030\003 \001(\r\"[\n\031ChallengeAnsweredRe"
    "sponse\022\022\n\004data\030\001 \001(\014B\004\200\265\030\001\022\020\n\010do_retry\030\002"
    " \001(\010\022\030\n\020record_not_found\030\003 \001(\010\"\'\n\031Challe"
    "ngeCancelledRequest\022\n\n\002id\030\001 \001(\r\"\323\002\n\032Send"
    "ChallengeToUserRequest\022(\n\007peer_id\030\001 \001(\0132"
    "\027.bgs.protocol.ProcessId\022/\n\017game_account"
    "_id\030\002 \001(\0132\026.bgs.protocol.EntityId\0228\n\ncha"
    "llenges\030\003 \003(\0132$.bgs.protocol.challenge.v"
    "1.Challenge\022\017\n\007context\030\004 \002(\007\022\017\n\007timeout\030"
    "\005 \001(\004\022+\n\nattributes\030\006 \003(\0132\027.bgs.protocol"
    ".Attribute\022%\n\004host\030\007 \001(\0132\027.bgs.protocol."
    "ProcessId\022*\n\naccount_id\030\010 \001(\0132\026.bgs.prot"
    "ocol.EntityId\")\n\033SendChallengeToUserResp"
    "onse\022\n\n\002id\030\001 \001(\r\"\335\001\n\024ChallengeUserReques"
    "t\0228\n\nchallenges\030\001 \003(\0132$.bgs.protocol.cha"
    "llenge.v1.Challenge\022\017\n\007context\030\002 \002(\007\022\n\n\002"
    "id\030\003 \001(\r\022\020\n\010deadline\030\004 \001(\004\022+\n\nattributes"
    "\030\005 \003(\0132\027.bgs.protocol.Attribute\022/\n\017game_"
    "account_id\030\006 \001(\0132\026.bgs.protocol.EntityId"
    "\"Z\n\026ChallengeResultRequest\022\n\n\002id\030\001 \001(\r\022\014"
    "\n\004type\030\002 \001(\007\022\020\n\010error_id\030\003 \001(\r\022\024\n\006answer"
    "\030\004 \001(\014B\004\200\265\030\001\"X\n\030ChallengeExternalRequest"
    "\022\025\n\rrequest_token\030\001 \001(\t\022\024\n\014payload_type\030"
    "\002 \001(\t\022\017\n\007payload\030\003 \001(\014\"F\n\027ChallengeExter"
    "nalResult\022\025\n\rrequest_token\030\001 \001(\t\022\024\n\006pass"
    "ed\030\002 \001(\010:\004true2\273\004\n\020ChallengeService\022~\n\017C"
    "hallengePicked\0221.bgs.protocol.challenge."
    "v1.ChallengePickedRequest\0322.bgs.protocol"
    ".challenge.v1.ChallengePickedResponse\"\004\200"
    "\265\030\001\022\204\001\n\021ChallengeAnswered\0223.bgs.protocol"
    ".challenge.v1.ChallengeAnsweredRequest\0324"
    ".bgs.protocol.challenge.v1.ChallengeAnsw"
    "eredResponse\"\004\200\265\030\002\022f\n\022ChallengeCancelled"
    "\0224.bgs.protocol.challenge.v1.ChallengeCa"
    "ncelledRequest\032\024.bgs.protocol.NoData\"\004\200\265"
    "\030\003\022\212\001\n\023SendChallengeToUser\0225.bgs.protoco"
    "l.challenge.v1.SendChallengeToUserReques"
    "t\0326.bgs.protocol.challenge.v1.SendChalle"
    "ngeToUserResponse\"\004\200\265\030\004\032+\312>(bnet.protoco"
    "l.challenge.ChallengeService2\354\003\n\021Challen"
    "geListener\022c\n\017OnChallengeUser\022/.bgs.prot"
    "ocol.challenge.v1.ChallengeUserRequest\032\031"
    ".bgs.protocol.NO_RESPONSE\"\004\200\265\030\001\022g\n\021OnCha"
    "llengeResult\0221.bgs.protocol.challenge.v1"
    ".ChallengeResultRequest\032\031.bgs.protocol.N"
    "O_RESPONSE\"\004\200\265\030\002\022k\n\023OnExternalChallenge\022"
    "3.bgs.protocol.challenge.v1.ChallengeExt"
    "ernalRequest\032\031.bgs.protocol.NO_RESPONSE\""
    "\004\200\265\030\003\022p\n\031OnExternalChallengeResult\0222.bgs"
    ".protocol.challenge.v1.ChallengeExternal"
    "Result\032\031.bgs.protocol.NO_RESPONSE\"\004\200\265\030\004\032"
    "*\312>\'bnet.protocol.challenge.ChallengeNot"
    "ifyB\005H\001\200\001\000", 2490);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "challenge_service.proto", &protobuf_RegisterTypes);
  Challenge::default_instance_ = new Challenge();
  ChallengePickedRequest::default_instance_ = new ChallengePickedRequest();
  ChallengePickedResponse::default_instance_ = new ChallengePickedResponse();
  ChallengeAnsweredRequest::default_instance_ = new ChallengeAnsweredRequest();
  ChallengeAnsweredResponse::default_instance_ = new ChallengeAnsweredResponse();
  ChallengeCancelledRequest::default_instance_ = new ChallengeCancelledRequest();
  SendChallengeToUserRequest::default_instance_ = new SendChallengeToUserRequest();
  SendChallengeToUserResponse::default_instance_ = new SendChallengeToUserResponse();
  ChallengeUserRequest::default_instance_ = new ChallengeUserRequest();
  ChallengeResultRequest::default_instance_ = new ChallengeResultRequest();
  ChallengeExternalRequest::default_instance_ = new ChallengeExternalRequest();
  ChallengeExternalResult::default_instance_ = new ChallengeExternalResult();
  Challenge::default_instance_->InitAsDefaultInstance();
  ChallengePickedRequest::default_instance_->InitAsDefaultInstance();
  ChallengePickedResponse::default_instance_->InitAsDefaultInstance();
  ChallengeAnsweredRequest::default_instance_->InitAsDefaultInstance();
  ChallengeAnsweredResponse::default_instance_->InitAsDefaultInstance();
  ChallengeCancelledRequest::default_instance_->InitAsDefaultInstance();
  SendChallengeToUserRequest::default_instance_->InitAsDefaultInstance();
  SendChallengeToUserResponse::default_instance_->InitAsDefaultInstance();
  ChallengeUserRequest::default_instance_->InitAsDefaultInstance();
  ChallengeResultRequest::default_instance_->InitAsDefaultInstance();
  ChallengeExternalRequest::default_instance_->InitAsDefaultInstance();
  ChallengeExternalResult::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_challenge_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_challenge_5fservice_2eproto {
  StaticDescriptorInitializer_challenge_5fservice_2eproto() {
    protobuf_AddDesc_challenge_5fservice_2eproto();
  }
} static_descriptor_initializer_challenge_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Challenge::kTypeFieldNumber;
const int Challenge::kInfoFieldNumber;
const int Challenge::kAnswerFieldNumber;
const int Challenge::kRetriesFieldNumber;
#endif  // !_MSC_VER

Challenge::Challenge()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.Challenge)
}

void Challenge::InitAsDefaultInstance() {
}

Challenge::Challenge(const Challenge& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.Challenge)
}

void Challenge::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0u;
  info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  answer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  retries_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Challenge::~Challenge() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.Challenge)
  SharedDtor();
}

void Challenge::SharedDtor() {
  if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete info_;
  }
  if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete answer_;
  }
  if (this != default_instance_) {
  }
}

void Challenge::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Challenge::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Challenge_descriptor_;
}

const Challenge& Challenge::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

Challenge* Challenge::default_instance_ = NULL;

Challenge* Challenge::New() const {
  return new Challenge;
}

void Challenge::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Challenge*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(type_, retries_);
    if (has_info()) {
      if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        info_->clear();
      }
    }
    if (has_answer()) {
      if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        answer_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Challenge::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.Challenge)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 type = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_info;
        break;
      }

      // optional string info = 2;
      case 2: {
        if (tag == 18) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_info()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->info().data(), this->info().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "info");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_answer;
        break;
      }

      // optional string answer = 3;
      case 3: {
        if (tag == 26) {
         parse_answer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_answer()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->answer().data(), this->answer().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "answer");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_retries;
        break;
      }

      // optional uint32 retries = 4;
      case 4: {
        if (tag == 32) {
         parse_retries:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &retries_)));
          set_has_retries();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.Challenge)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.Challenge)
  return false;
#undef DO_
}

void Challenge::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.Challenge)
  // required fixed32 type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->type(), output);
  }

  // optional string info = 2;
  if (has_info()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->info().data(), this->info().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "info");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->info(), output);
  }

  // optional string answer = 3;
  if (has_answer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "answer");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->answer(), output);
  }

  // optional uint32 retries = 4;
  if (has_retries()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->retries(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.Challenge)
}

::google::protobuf::uint8* Challenge::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.Challenge)
  // required fixed32 type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->type(), target);
  }

  // optional string info = 2;
  if (has_info()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->info().data(), this->info().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "info");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->info(), target);
  }

  // optional string answer = 3;
  if (has_answer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "answer");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->answer(), target);
  }

  // optional uint32 retries = 4;
  if (has_retries()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->retries(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.Challenge)
  return target;
}

int Challenge::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 type = 1;
    if (has_type()) {
      total_size += 1 + 4;
    }

    // optional string info = 2;
    if (has_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->info());
    }

    // optional string answer = 3;
    if (has_answer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->answer());
    }

    // optional uint32 retries = 4;
    if (has_retries()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->retries());
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

void Challenge::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Challenge* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Challenge*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Challenge::MergeFrom(const Challenge& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_info()) {
      set_info(from.info());
    }
    if (from.has_answer()) {
      set_answer(from.answer());
    }
    if (from.has_retries()) {
      set_retries(from.retries());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Challenge::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Challenge::CopyFrom(const Challenge& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Challenge::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Challenge::Swap(Challenge* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(info_, other->info_);
    std::swap(answer_, other->answer_);
    std::swap(retries_, other->retries_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Challenge::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Challenge_descriptor_;
  metadata.reflection = Challenge_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengePickedRequest::kChallengeFieldNumber;
const int ChallengePickedRequest::kIdFieldNumber;
const int ChallengePickedRequest::kNewChallengeProtocolFieldNumber;
#endif  // !_MSC_VER

ChallengePickedRequest::ChallengePickedRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengePickedRequest)
}

void ChallengePickedRequest::InitAsDefaultInstance() {
}

ChallengePickedRequest::ChallengePickedRequest(const ChallengePickedRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengePickedRequest)
}

void ChallengePickedRequest::SharedCtor() {
  _cached_size_ = 0;
  challenge_ = 0u;
  id_ = 0u;
  new_challenge_protocol_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengePickedRequest::~ChallengePickedRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengePickedRequest)
  SharedDtor();
}

void ChallengePickedRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ChallengePickedRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengePickedRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengePickedRequest_descriptor_;
}

const ChallengePickedRequest& ChallengePickedRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengePickedRequest* ChallengePickedRequest::default_instance_ = NULL;

ChallengePickedRequest* ChallengePickedRequest::New() const {
  return new ChallengePickedRequest;
}

void ChallengePickedRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChallengePickedRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(challenge_, new_challenge_protocol_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengePickedRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengePickedRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 challenge = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &challenge_)));
          set_has_challenge();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // optional uint32 id = 2;
      case 2: {
        if (tag == 16) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_new_challenge_protocol;
        break;
      }

      // optional bool new_challenge_protocol = 3 [default = false];
      case 3: {
        if (tag == 24) {
         parse_new_challenge_protocol:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &new_challenge_protocol_)));
          set_has_new_challenge_protocol();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengePickedRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengePickedRequest)
  return false;
#undef DO_
}

void ChallengePickedRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengePickedRequest)
  // required fixed32 challenge = 1;
  if (has_challenge()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->challenge(), output);
  }

  // optional uint32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->id(), output);
  }

  // optional bool new_challenge_protocol = 3 [default = false];
  if (has_new_challenge_protocol()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->new_challenge_protocol(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengePickedRequest)
}

::google::protobuf::uint8* ChallengePickedRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengePickedRequest)
  // required fixed32 challenge = 1;
  if (has_challenge()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->challenge(), target);
  }

  // optional uint32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->id(), target);
  }

  // optional bool new_challenge_protocol = 3 [default = false];
  if (has_new_challenge_protocol()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->new_challenge_protocol(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengePickedRequest)
  return target;
}

int ChallengePickedRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 challenge = 1;
    if (has_challenge()) {
      total_size += 1 + 4;
    }

    // optional uint32 id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional bool new_challenge_protocol = 3 [default = false];
    if (has_new_challenge_protocol()) {
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

void ChallengePickedRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengePickedRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengePickedRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengePickedRequest::MergeFrom(const ChallengePickedRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_challenge()) {
      set_challenge(from.challenge());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_new_challenge_protocol()) {
      set_new_challenge_protocol(from.new_challenge_protocol());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengePickedRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengePickedRequest::CopyFrom(const ChallengePickedRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengePickedRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ChallengePickedRequest::Swap(ChallengePickedRequest* other) {
  if (other != this) {
    std::swap(challenge_, other->challenge_);
    std::swap(id_, other->id_);
    std::swap(new_challenge_protocol_, other->new_challenge_protocol_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengePickedRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengePickedRequest_descriptor_;
  metadata.reflection = ChallengePickedRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengePickedResponse::kDataFieldNumber;
#endif  // !_MSC_VER

ChallengePickedResponse::ChallengePickedResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengePickedResponse)
}

void ChallengePickedResponse::InitAsDefaultInstance() {
}

ChallengePickedResponse::ChallengePickedResponse(const ChallengePickedResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengePickedResponse)
}

void ChallengePickedResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengePickedResponse::~ChallengePickedResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengePickedResponse)
  SharedDtor();
}

void ChallengePickedResponse::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void ChallengePickedResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengePickedResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengePickedResponse_descriptor_;
}

const ChallengePickedResponse& ChallengePickedResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengePickedResponse* ChallengePickedResponse::default_instance_ = NULL;

ChallengePickedResponse* ChallengePickedResponse::New() const {
  return new ChallengePickedResponse;
}

void ChallengePickedResponse::Clear() {
  if (has_data()) {
    if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      data_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengePickedResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengePickedResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengePickedResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengePickedResponse)
  return false;
#undef DO_
}

void ChallengePickedResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengePickedResponse)
  // optional bytes data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengePickedResponse)
}

::google::protobuf::uint8* ChallengePickedResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengePickedResponse)
  // optional bytes data = 1;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengePickedResponse)
  return target;
}

int ChallengePickedResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes data = 1;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->data());
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

void ChallengePickedResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengePickedResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengePickedResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengePickedResponse::MergeFrom(const ChallengePickedResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengePickedResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengePickedResponse::CopyFrom(const ChallengePickedResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengePickedResponse::IsInitialized() const {

  return true;
}

void ChallengePickedResponse::Swap(ChallengePickedResponse* other) {
  if (other != this) {
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengePickedResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengePickedResponse_descriptor_;
  metadata.reflection = ChallengePickedResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeAnsweredRequest::kAnswerFieldNumber;
const int ChallengeAnsweredRequest::kDataFieldNumber;
const int ChallengeAnsweredRequest::kIdFieldNumber;
#endif  // !_MSC_VER

ChallengeAnsweredRequest::ChallengeAnsweredRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
}

void ChallengeAnsweredRequest::InitAsDefaultInstance() {
}

ChallengeAnsweredRequest::ChallengeAnsweredRequest(const ChallengeAnsweredRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
}

void ChallengeAnsweredRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  answer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeAnsweredRequest::~ChallengeAnsweredRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  SharedDtor();
}

void ChallengeAnsweredRequest::SharedDtor() {
  if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete answer_;
  }
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void ChallengeAnsweredRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeAnsweredRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeAnsweredRequest_descriptor_;
}

const ChallengeAnsweredRequest& ChallengeAnsweredRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeAnsweredRequest* ChallengeAnsweredRequest::default_instance_ = NULL;

ChallengeAnsweredRequest* ChallengeAnsweredRequest::New() const {
  return new ChallengeAnsweredRequest;
}

void ChallengeAnsweredRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_answer()) {
      if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        answer_->clear();
      }
    }
    if (has_data()) {
      if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        data_->clear();
      }
    }
    id_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeAnsweredRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string answer = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_answer()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->answer().data(), this->answer().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "answer");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_data;
        break;
      }

      // optional bytes data = 2;
      case 2: {
        if (tag == 18) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_id;
        break;
      }

      // optional uint32 id = 3;
      case 3: {
        if (tag == 24) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  return false;
#undef DO_
}

void ChallengeAnsweredRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  // required string answer = 1;
  if (has_answer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "answer");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->answer(), output);
  }

  // optional bytes data = 2;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->data(), output);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
}

::google::protobuf::uint8* ChallengeAnsweredRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  // required string answer = 1;
  if (has_answer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "answer");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->answer(), target);
  }

  // optional bytes data = 2;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->data(), target);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeAnsweredRequest)
  return target;
}

int ChallengeAnsweredRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string answer = 1;
    if (has_answer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->answer());
    }

    // optional bytes data = 2;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->data());
    }

    // optional uint32 id = 3;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
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

void ChallengeAnsweredRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeAnsweredRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeAnsweredRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeAnsweredRequest::MergeFrom(const ChallengeAnsweredRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_answer()) {
      set_answer(from.answer());
    }
    if (from.has_data()) {
      set_data(from.data());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeAnsweredRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeAnsweredRequest::CopyFrom(const ChallengeAnsweredRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeAnsweredRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ChallengeAnsweredRequest::Swap(ChallengeAnsweredRequest* other) {
  if (other != this) {
    std::swap(answer_, other->answer_);
    std::swap(data_, other->data_);
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeAnsweredRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeAnsweredRequest_descriptor_;
  metadata.reflection = ChallengeAnsweredRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeAnsweredResponse::kDataFieldNumber;
const int ChallengeAnsweredResponse::kDoRetryFieldNumber;
const int ChallengeAnsweredResponse::kRecordNotFoundFieldNumber;
#endif  // !_MSC_VER

ChallengeAnsweredResponse::ChallengeAnsweredResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
}

void ChallengeAnsweredResponse::InitAsDefaultInstance() {
}

ChallengeAnsweredResponse::ChallengeAnsweredResponse(const ChallengeAnsweredResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
}

void ChallengeAnsweredResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  do_retry_ = false;
  record_not_found_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeAnsweredResponse::~ChallengeAnsweredResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  SharedDtor();
}

void ChallengeAnsweredResponse::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void ChallengeAnsweredResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeAnsweredResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeAnsweredResponse_descriptor_;
}

const ChallengeAnsweredResponse& ChallengeAnsweredResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeAnsweredResponse* ChallengeAnsweredResponse::default_instance_ = NULL;

ChallengeAnsweredResponse* ChallengeAnsweredResponse::New() const {
  return new ChallengeAnsweredResponse;
}

void ChallengeAnsweredResponse::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChallengeAnsweredResponse*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(do_retry_, record_not_found_);
    if (has_data()) {
      if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        data_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeAnsweredResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_do_retry;
        break;
      }

      // optional bool do_retry = 2;
      case 2: {
        if (tag == 16) {
         parse_do_retry:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &do_retry_)));
          set_has_do_retry();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_record_not_found;
        break;
      }

      // optional bool record_not_found = 3;
      case 3: {
        if (tag == 24) {
         parse_record_not_found:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &record_not_found_)));
          set_has_record_not_found();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  return false;
#undef DO_
}

void ChallengeAnsweredResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  // optional bytes data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->data(), output);
  }

  // optional bool do_retry = 2;
  if (has_do_retry()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->do_retry(), output);
  }

  // optional bool record_not_found = 3;
  if (has_record_not_found()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->record_not_found(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
}

::google::protobuf::uint8* ChallengeAnsweredResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  // optional bytes data = 1;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->data(), target);
  }

  // optional bool do_retry = 2;
  if (has_do_retry()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->do_retry(), target);
  }

  // optional bool record_not_found = 3;
  if (has_record_not_found()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->record_not_found(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeAnsweredResponse)
  return target;
}

int ChallengeAnsweredResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes data = 1;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->data());
    }

    // optional bool do_retry = 2;
    if (has_do_retry()) {
      total_size += 1 + 1;
    }

    // optional bool record_not_found = 3;
    if (has_record_not_found()) {
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

void ChallengeAnsweredResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeAnsweredResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeAnsweredResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeAnsweredResponse::MergeFrom(const ChallengeAnsweredResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_data(from.data());
    }
    if (from.has_do_retry()) {
      set_do_retry(from.do_retry());
    }
    if (from.has_record_not_found()) {
      set_record_not_found(from.record_not_found());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeAnsweredResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeAnsweredResponse::CopyFrom(const ChallengeAnsweredResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeAnsweredResponse::IsInitialized() const {

  return true;
}

void ChallengeAnsweredResponse::Swap(ChallengeAnsweredResponse* other) {
  if (other != this) {
    std::swap(data_, other->data_);
    std::swap(do_retry_, other->do_retry_);
    std::swap(record_not_found_, other->record_not_found_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeAnsweredResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeAnsweredResponse_descriptor_;
  metadata.reflection = ChallengeAnsweredResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeCancelledRequest::kIdFieldNumber;
#endif  // !_MSC_VER

ChallengeCancelledRequest::ChallengeCancelledRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
}

void ChallengeCancelledRequest::InitAsDefaultInstance() {
}

ChallengeCancelledRequest::ChallengeCancelledRequest(const ChallengeCancelledRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
}

void ChallengeCancelledRequest::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeCancelledRequest::~ChallengeCancelledRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  SharedDtor();
}

void ChallengeCancelledRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ChallengeCancelledRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeCancelledRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeCancelledRequest_descriptor_;
}

const ChallengeCancelledRequest& ChallengeCancelledRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeCancelledRequest* ChallengeCancelledRequest::default_instance_ = NULL;

ChallengeCancelledRequest* ChallengeCancelledRequest::New() const {
  return new ChallengeCancelledRequest;
}

void ChallengeCancelledRequest::Clear() {
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeCancelledRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  return false;
#undef DO_
}

void ChallengeCancelledRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  // optional uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
}

::google::protobuf::uint8* ChallengeCancelledRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  // optional uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeCancelledRequest)
  return target;
}

int ChallengeCancelledRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
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

void ChallengeCancelledRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeCancelledRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeCancelledRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeCancelledRequest::MergeFrom(const ChallengeCancelledRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeCancelledRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeCancelledRequest::CopyFrom(const ChallengeCancelledRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeCancelledRequest::IsInitialized() const {

  return true;
}

void ChallengeCancelledRequest::Swap(ChallengeCancelledRequest* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeCancelledRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeCancelledRequest_descriptor_;
  metadata.reflection = ChallengeCancelledRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendChallengeToUserRequest::kPeerIdFieldNumber;
const int SendChallengeToUserRequest::kGameAccountIdFieldNumber;
const int SendChallengeToUserRequest::kChallengesFieldNumber;
const int SendChallengeToUserRequest::kContextFieldNumber;
const int SendChallengeToUserRequest::kTimeoutFieldNumber;
const int SendChallengeToUserRequest::kAttributesFieldNumber;
const int SendChallengeToUserRequest::kHostFieldNumber;
const int SendChallengeToUserRequest::kAccountIdFieldNumber;
#endif  // !_MSC_VER

SendChallengeToUserRequest::SendChallengeToUserRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
}

void SendChallengeToUserRequest::InitAsDefaultInstance() {
  peer_id_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  host_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SendChallengeToUserRequest::SendChallengeToUserRequest(const SendChallengeToUserRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
}

void SendChallengeToUserRequest::SharedCtor() {
  _cached_size_ = 0;
  peer_id_ = NULL;
  game_account_id_ = NULL;
  context_ = 0u;
  timeout_ = GOOGLE_ULONGLONG(0);
  host_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendChallengeToUserRequest::~SendChallengeToUserRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  SharedDtor();
}

void SendChallengeToUserRequest::SharedDtor() {
  if (this != default_instance_) {
    delete peer_id_;
    delete game_account_id_;
    delete host_;
    delete account_id_;
  }
}

void SendChallengeToUserRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendChallengeToUserRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendChallengeToUserRequest_descriptor_;
}

const SendChallengeToUserRequest& SendChallengeToUserRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

SendChallengeToUserRequest* SendChallengeToUserRequest::default_instance_ = NULL;

SendChallengeToUserRequest* SendChallengeToUserRequest::New() const {
  return new SendChallengeToUserRequest;
}

void SendChallengeToUserRequest::Clear() {
  if (_has_bits_[0 / 32] & 219) {
    if (has_peer_id()) {
      if (peer_id_ != NULL) peer_id_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    context_ = 0u;
    timeout_ = GOOGLE_ULONGLONG(0);
    if (has_host()) {
      if (host_ != NULL) host_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  challenges_.Clear();
  attributes_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendChallengeToUserRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.ProcessId peer_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peer_id()));
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
        if (input->ExpectTag(26)) goto parse_challenges;
        break;
      }

      // repeated .bgs.protocol.challenge.v1.Challenge challenges = 3;
      case 3: {
        if (tag == 26) {
         parse_challenges:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_challenges()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_challenges;
        if (input->ExpectTag(37)) goto parse_context;
        break;
      }

      // required fixed32 context = 4;
      case 4: {
        if (tag == 37) {
         parse_context:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &context_)));
          set_has_context();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_timeout;
        break;
      }

      // optional uint64 timeout = 5;
      case 5: {
        if (tag == 40) {
         parse_timeout:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &timeout_)));
          set_has_timeout();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_attributes;
        break;
      }

      // repeated .bgs.protocol.Attribute attributes = 6;
      case 6: {
        if (tag == 50) {
         parse_attributes:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attributes()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_attributes;
        if (input->ExpectTag(58)) goto parse_host;
        break;
      }

      // optional .bgs.protocol.ProcessId host = 7;
      case 7: {
        if (tag == 58) {
         parse_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_host()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 8;
      case 8: {
        if (tag == 66) {
         parse_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  return false;
#undef DO_
}

void SendChallengeToUserRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  // optional .bgs.protocol.ProcessId peer_id = 1;
  if (has_peer_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->peer_id(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 3;
  for (int i = 0; i < this->challenges_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->challenges(i), output);
  }

  // required fixed32 context = 4;
  if (has_context()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(4, this->context(), output);
  }

  // optional uint64 timeout = 5;
  if (has_timeout()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->timeout(), output);
  }

  // repeated .bgs.protocol.Attribute attributes = 6;
  for (int i = 0; i < this->attributes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->attributes(i), output);
  }

  // optional .bgs.protocol.ProcessId host = 7;
  if (has_host()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->host(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 8;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
}

::google::protobuf::uint8* SendChallengeToUserRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  // optional .bgs.protocol.ProcessId peer_id = 1;
  if (has_peer_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->peer_id(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 3;
  for (int i = 0; i < this->challenges_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->challenges(i), target);
  }

  // required fixed32 context = 4;
  if (has_context()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(4, this->context(), target);
  }

  // optional uint64 timeout = 5;
  if (has_timeout()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->timeout(), target);
  }

  // repeated .bgs.protocol.Attribute attributes = 6;
  for (int i = 0; i < this->attributes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->attributes(i), target);
  }

  // optional .bgs.protocol.ProcessId host = 7;
  if (has_host()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->host(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 8;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.SendChallengeToUserRequest)
  return target;
}

int SendChallengeToUserRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.ProcessId peer_id = 1;
    if (has_peer_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peer_id());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // required fixed32 context = 4;
    if (has_context()) {
      total_size += 1 + 4;
    }

    // optional uint64 timeout = 5;
    if (has_timeout()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->timeout());
    }

    // optional .bgs.protocol.ProcessId host = 7;
    if (has_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->host());
    }

    // optional .bgs.protocol.EntityId account_id = 8;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

  }
  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 3;
  total_size += 1 * this->challenges_size();
  for (int i = 0; i < this->challenges_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->challenges(i));
  }

  // repeated .bgs.protocol.Attribute attributes = 6;
  total_size += 1 * this->attributes_size();
  for (int i = 0; i < this->attributes_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attributes(i));
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

void SendChallengeToUserRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendChallengeToUserRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendChallengeToUserRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendChallengeToUserRequest::MergeFrom(const SendChallengeToUserRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  challenges_.MergeFrom(from.challenges_);
  attributes_.MergeFrom(from.attributes_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_peer_id()) {
      mutable_peer_id()->::bgs::protocol::ProcessId::MergeFrom(from.peer_id());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_context()) {
      set_context(from.context());
    }
    if (from.has_timeout()) {
      set_timeout(from.timeout());
    }
    if (from.has_host()) {
      mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from.host());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendChallengeToUserRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendChallengeToUserRequest::CopyFrom(const SendChallengeToUserRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendChallengeToUserRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000008) != 0x00000008) return false;

  if (has_peer_id()) {
    if (!this->peer_id().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->challenges())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->attributes())) return false;
  if (has_host()) {
    if (!this->host().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void SendChallengeToUserRequest::Swap(SendChallengeToUserRequest* other) {
  if (other != this) {
    std::swap(peer_id_, other->peer_id_);
    std::swap(game_account_id_, other->game_account_id_);
    challenges_.Swap(&other->challenges_);
    std::swap(context_, other->context_);
    std::swap(timeout_, other->timeout_);
    attributes_.Swap(&other->attributes_);
    std::swap(host_, other->host_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendChallengeToUserRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendChallengeToUserRequest_descriptor_;
  metadata.reflection = SendChallengeToUserRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SendChallengeToUserResponse::kIdFieldNumber;
#endif  // !_MSC_VER

SendChallengeToUserResponse::SendChallengeToUserResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
}

void SendChallengeToUserResponse::InitAsDefaultInstance() {
}

SendChallengeToUserResponse::SendChallengeToUserResponse(const SendChallengeToUserResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
}

void SendChallengeToUserResponse::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SendChallengeToUserResponse::~SendChallengeToUserResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  SharedDtor();
}

void SendChallengeToUserResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SendChallengeToUserResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendChallengeToUserResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SendChallengeToUserResponse_descriptor_;
}

const SendChallengeToUserResponse& SendChallengeToUserResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

SendChallengeToUserResponse* SendChallengeToUserResponse::default_instance_ = NULL;

SendChallengeToUserResponse* SendChallengeToUserResponse::New() const {
  return new SendChallengeToUserResponse;
}

void SendChallengeToUserResponse::Clear() {
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SendChallengeToUserResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  return false;
#undef DO_
}

void SendChallengeToUserResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  // optional uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
}

::google::protobuf::uint8* SendChallengeToUserResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  // optional uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.SendChallengeToUserResponse)
  return target;
}

int SendChallengeToUserResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
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

void SendChallengeToUserResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SendChallengeToUserResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SendChallengeToUserResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SendChallengeToUserResponse::MergeFrom(const SendChallengeToUserResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SendChallengeToUserResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendChallengeToUserResponse::CopyFrom(const SendChallengeToUserResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendChallengeToUserResponse::IsInitialized() const {

  return true;
}

void SendChallengeToUserResponse::Swap(SendChallengeToUserResponse* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SendChallengeToUserResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SendChallengeToUserResponse_descriptor_;
  metadata.reflection = SendChallengeToUserResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeUserRequest::kChallengesFieldNumber;
const int ChallengeUserRequest::kContextFieldNumber;
const int ChallengeUserRequest::kIdFieldNumber;
const int ChallengeUserRequest::kDeadlineFieldNumber;
const int ChallengeUserRequest::kAttributesFieldNumber;
const int ChallengeUserRequest::kGameAccountIdFieldNumber;
#endif  // !_MSC_VER

ChallengeUserRequest::ChallengeUserRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeUserRequest)
}

void ChallengeUserRequest::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

ChallengeUserRequest::ChallengeUserRequest(const ChallengeUserRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeUserRequest)
}

void ChallengeUserRequest::SharedCtor() {
  _cached_size_ = 0;
  context_ = 0u;
  id_ = 0u;
  deadline_ = GOOGLE_ULONGLONG(0);
  game_account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeUserRequest::~ChallengeUserRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeUserRequest)
  SharedDtor();
}

void ChallengeUserRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_id_;
  }
}

void ChallengeUserRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeUserRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeUserRequest_descriptor_;
}

const ChallengeUserRequest& ChallengeUserRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeUserRequest* ChallengeUserRequest::default_instance_ = NULL;

ChallengeUserRequest* ChallengeUserRequest::New() const {
  return new ChallengeUserRequest;
}

void ChallengeUserRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChallengeUserRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 46) {
    ZR_(context_, deadline_);
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  challenges_.Clear();
  attributes_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeUserRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeUserRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.challenge.v1.Challenge challenges = 1;
      case 1: {
        if (tag == 10) {
         parse_challenges:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_challenges()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_challenges;
        if (input->ExpectTag(21)) goto parse_context;
        break;
      }

      // required fixed32 context = 2;
      case 2: {
        if (tag == 21) {
         parse_context:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &context_)));
          set_has_context();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_id;
        break;
      }

      // optional uint32 id = 3;
      case 3: {
        if (tag == 24) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_deadline;
        break;
      }

      // optional uint64 deadline = 4;
      case 4: {
        if (tag == 32) {
         parse_deadline:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &deadline_)));
          set_has_deadline();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_attributes;
        break;
      }

      // repeated .bgs.protocol.Attribute attributes = 5;
      case 5: {
        if (tag == 42) {
         parse_attributes:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attributes()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_attributes;
        if (input->ExpectTag(50)) goto parse_game_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId game_account_id = 6;
      case 6: {
        if (tag == 50) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeUserRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeUserRequest)
  return false;
#undef DO_
}

void ChallengeUserRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeUserRequest)
  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 1;
  for (int i = 0; i < this->challenges_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->challenges(i), output);
  }

  // required fixed32 context = 2;
  if (has_context()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->context(), output);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->id(), output);
  }

  // optional uint64 deadline = 4;
  if (has_deadline()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->deadline(), output);
  }

  // repeated .bgs.protocol.Attribute attributes = 5;
  for (int i = 0; i < this->attributes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->attributes(i), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 6;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->game_account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeUserRequest)
}

::google::protobuf::uint8* ChallengeUserRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeUserRequest)
  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 1;
  for (int i = 0; i < this->challenges_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->challenges(i), target);
  }

  // required fixed32 context = 2;
  if (has_context()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->context(), target);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->id(), target);
  }

  // optional uint64 deadline = 4;
  if (has_deadline()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->deadline(), target);
  }

  // repeated .bgs.protocol.Attribute attributes = 5;
  for (int i = 0; i < this->attributes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->attributes(i), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 6;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->game_account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeUserRequest)
  return target;
}

int ChallengeUserRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // required fixed32 context = 2;
    if (has_context()) {
      total_size += 1 + 4;
    }

    // optional uint32 id = 3;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional uint64 deadline = 4;
    if (has_deadline()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->deadline());
    }

    // optional .bgs.protocol.EntityId game_account_id = 6;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

  }
  // repeated .bgs.protocol.challenge.v1.Challenge challenges = 1;
  total_size += 1 * this->challenges_size();
  for (int i = 0; i < this->challenges_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->challenges(i));
  }

  // repeated .bgs.protocol.Attribute attributes = 5;
  total_size += 1 * this->attributes_size();
  for (int i = 0; i < this->attributes_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attributes(i));
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

void ChallengeUserRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeUserRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeUserRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeUserRequest::MergeFrom(const ChallengeUserRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  challenges_.MergeFrom(from.challenges_);
  attributes_.MergeFrom(from.attributes_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_context()) {
      set_context(from.context());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_deadline()) {
      set_deadline(from.deadline());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeUserRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeUserRequest::CopyFrom(const ChallengeUserRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeUserRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->challenges())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->attributes())) return false;
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void ChallengeUserRequest::Swap(ChallengeUserRequest* other) {
  if (other != this) {
    challenges_.Swap(&other->challenges_);
    std::swap(context_, other->context_);
    std::swap(id_, other->id_);
    std::swap(deadline_, other->deadline_);
    attributes_.Swap(&other->attributes_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeUserRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeUserRequest_descriptor_;
  metadata.reflection = ChallengeUserRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeResultRequest::kIdFieldNumber;
const int ChallengeResultRequest::kTypeFieldNumber;
const int ChallengeResultRequest::kErrorIdFieldNumber;
const int ChallengeResultRequest::kAnswerFieldNumber;
#endif  // !_MSC_VER

ChallengeResultRequest::ChallengeResultRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeResultRequest)
}

void ChallengeResultRequest::InitAsDefaultInstance() {
}

ChallengeResultRequest::ChallengeResultRequest(const ChallengeResultRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeResultRequest)
}

void ChallengeResultRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  type_ = 0u;
  error_id_ = 0u;
  answer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeResultRequest::~ChallengeResultRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeResultRequest)
  SharedDtor();
}

void ChallengeResultRequest::SharedDtor() {
  if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete answer_;
  }
  if (this != default_instance_) {
  }
}

void ChallengeResultRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeResultRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeResultRequest_descriptor_;
}

const ChallengeResultRequest& ChallengeResultRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeResultRequest* ChallengeResultRequest::default_instance_ = NULL;

ChallengeResultRequest* ChallengeResultRequest::New() const {
  return new ChallengeResultRequest;
}

void ChallengeResultRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ChallengeResultRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(id_, type_);
    error_id_ = 0u;
    if (has_answer()) {
      if (answer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        answer_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeResultRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeResultRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_type;
        break;
      }

      // optional fixed32 type = 2;
      case 2: {
        if (tag == 21) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_error_id;
        break;
      }

      // optional uint32 error_id = 3;
      case 3: {
        if (tag == 24) {
         parse_error_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &error_id_)));
          set_has_error_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_answer;
        break;
      }

      // optional bytes answer = 4;
      case 4: {
        if (tag == 34) {
         parse_answer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_answer()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeResultRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeResultRequest)
  return false;
#undef DO_
}

void ChallengeResultRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeResultRequest)
  // optional uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // optional fixed32 type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->type(), output);
  }

  // optional uint32 error_id = 3;
  if (has_error_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->error_id(), output);
  }

  // optional bytes answer = 4;
  if (has_answer()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->answer(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeResultRequest)
}

::google::protobuf::uint8* ChallengeResultRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeResultRequest)
  // optional uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // optional fixed32 type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->type(), target);
  }

  // optional uint32 error_id = 3;
  if (has_error_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->error_id(), target);
  }

  // optional bytes answer = 4;
  if (has_answer()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->answer(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeResultRequest)
  return target;
}

int ChallengeResultRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional fixed32 type = 2;
    if (has_type()) {
      total_size += 1 + 4;
    }

    // optional uint32 error_id = 3;
    if (has_error_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->error_id());
    }

    // optional bytes answer = 4;
    if (has_answer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->answer());
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

void ChallengeResultRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeResultRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeResultRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeResultRequest::MergeFrom(const ChallengeResultRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_error_id()) {
      set_error_id(from.error_id());
    }
    if (from.has_answer()) {
      set_answer(from.answer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeResultRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeResultRequest::CopyFrom(const ChallengeResultRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeResultRequest::IsInitialized() const {

  return true;
}

void ChallengeResultRequest::Swap(ChallengeResultRequest* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(type_, other->type_);
    std::swap(error_id_, other->error_id_);
    std::swap(answer_, other->answer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeResultRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeResultRequest_descriptor_;
  metadata.reflection = ChallengeResultRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeExternalRequest::kRequestTokenFieldNumber;
const int ChallengeExternalRequest::kPayloadTypeFieldNumber;
const int ChallengeExternalRequest::kPayloadFieldNumber;
#endif  // !_MSC_VER

ChallengeExternalRequest::ChallengeExternalRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
}

void ChallengeExternalRequest::InitAsDefaultInstance() {
}

ChallengeExternalRequest::ChallengeExternalRequest(const ChallengeExternalRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
}

void ChallengeExternalRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  request_token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  payload_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeExternalRequest::~ChallengeExternalRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  SharedDtor();
}

void ChallengeExternalRequest::SharedDtor() {
  if (request_token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_token_;
  }
  if (payload_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete payload_type_;
  }
  if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete payload_;
  }
  if (this != default_instance_) {
  }
}

void ChallengeExternalRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeExternalRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeExternalRequest_descriptor_;
}

const ChallengeExternalRequest& ChallengeExternalRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeExternalRequest* ChallengeExternalRequest::default_instance_ = NULL;

ChallengeExternalRequest* ChallengeExternalRequest::New() const {
  return new ChallengeExternalRequest;
}

void ChallengeExternalRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_request_token()) {
      if (request_token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        request_token_->clear();
      }
    }
    if (has_payload_type()) {
      if (payload_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        payload_type_->clear();
      }
    }
    if (has_payload()) {
      if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        payload_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeExternalRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string request_token = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_request_token()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->request_token().data(), this->request_token().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "request_token");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_payload_type;
        break;
      }

      // optional string payload_type = 2;
      case 2: {
        if (tag == 18) {
         parse_payload_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_payload_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->payload_type().data(), this->payload_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "payload_type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_payload;
        break;
      }

      // optional bytes payload = 3;
      case 3: {
        if (tag == 26) {
         parse_payload:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_payload()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  return false;
#undef DO_
}

void ChallengeExternalRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  // optional string request_token = 1;
  if (has_request_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_token().data(), this->request_token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_token");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->request_token(), output);
  }

  // optional string payload_type = 2;
  if (has_payload_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->payload_type().data(), this->payload_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "payload_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->payload_type(), output);
  }

  // optional bytes payload = 3;
  if (has_payload()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->payload(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeExternalRequest)
}

::google::protobuf::uint8* ChallengeExternalRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  // optional string request_token = 1;
  if (has_request_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_token().data(), this->request_token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_token");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->request_token(), target);
  }

  // optional string payload_type = 2;
  if (has_payload_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->payload_type().data(), this->payload_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "payload_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->payload_type(), target);
  }

  // optional bytes payload = 3;
  if (has_payload()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->payload(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  return target;
}

int ChallengeExternalRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string request_token = 1;
    if (has_request_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->request_token());
    }

    // optional string payload_type = 2;
    if (has_payload_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->payload_type());
    }

    // optional bytes payload = 3;
    if (has_payload()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->payload());
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

void ChallengeExternalRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeExternalRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeExternalRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeExternalRequest::MergeFrom(const ChallengeExternalRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_request_token()) {
      set_request_token(from.request_token());
    }
    if (from.has_payload_type()) {
      set_payload_type(from.payload_type());
    }
    if (from.has_payload()) {
      set_payload(from.payload());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeExternalRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeExternalRequest::CopyFrom(const ChallengeExternalRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeExternalRequest::IsInitialized() const {

  return true;
}

void ChallengeExternalRequest::Swap(ChallengeExternalRequest* other) {
  if (other != this) {
    std::swap(request_token_, other->request_token_);
    std::swap(payload_type_, other->payload_type_);
    std::swap(payload_, other->payload_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeExternalRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeExternalRequest_descriptor_;
  metadata.reflection = ChallengeExternalRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ChallengeExternalResult::kRequestTokenFieldNumber;
const int ChallengeExternalResult::kPassedFieldNumber;
#endif  // !_MSC_VER

ChallengeExternalResult::ChallengeExternalResult()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
}

void ChallengeExternalResult::InitAsDefaultInstance() {
}

ChallengeExternalResult::ChallengeExternalResult(const ChallengeExternalResult& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
}

void ChallengeExternalResult::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  request_token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  passed_ = true;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChallengeExternalResult::~ChallengeExternalResult() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
  SharedDtor();
}

void ChallengeExternalResult::SharedDtor() {
  if (request_token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_token_;
  }
  if (this != default_instance_) {
  }
}

void ChallengeExternalResult::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChallengeExternalResult::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeExternalResult_descriptor_;
}

const ChallengeExternalResult& ChallengeExternalResult::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_challenge_5fservice_2eproto();
  return *default_instance_;
}

ChallengeExternalResult* ChallengeExternalResult::default_instance_ = NULL;

ChallengeExternalResult* ChallengeExternalResult::New() const {
  return new ChallengeExternalResult;
}

void ChallengeExternalResult::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_request_token()) {
      if (request_token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        request_token_->clear();
      }
    }
    passed_ = true;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChallengeExternalResult::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string request_token = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_request_token()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->request_token().data(), this->request_token().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "request_token");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_passed;
        break;
      }

      // optional bool passed = 2 [default = true];
      case 2: {
        if (tag == 16) {
         parse_passed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &passed_)));
          set_has_passed();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.challenge.v1.ChallengeExternalResult)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.challenge.v1.ChallengeExternalResult)
  return false;
#undef DO_
}

void ChallengeExternalResult::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  // optional string request_token = 1;
  if (has_request_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_token().data(), this->request_token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_token");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->request_token(), output);
  }

  // optional bool passed = 2 [default = true];
  if (has_passed()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->passed(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.challenge.v1.ChallengeExternalResult)
}

::google::protobuf::uint8* ChallengeExternalResult::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  // optional string request_token = 1;
  if (has_request_token()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_token().data(), this->request_token().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_token");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->request_token(), target);
  }

  // optional bool passed = 2 [default = true];
  if (has_passed()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->passed(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeExternalResult)
  return target;
}

int ChallengeExternalResult::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string request_token = 1;
    if (has_request_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->request_token());
    }

    // optional bool passed = 2 [default = true];
    if (has_passed()) {
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

void ChallengeExternalResult::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChallengeExternalResult* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChallengeExternalResult*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChallengeExternalResult::MergeFrom(const ChallengeExternalResult& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_request_token()) {
      set_request_token(from.request_token());
    }
    if (from.has_passed()) {
      set_passed(from.passed());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChallengeExternalResult::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeExternalResult::CopyFrom(const ChallengeExternalResult& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeExternalResult::IsInitialized() const {

  return true;
}

void ChallengeExternalResult::Swap(ChallengeExternalResult* other) {
  if (other != this) {
    std::swap(request_token_, other->request_token_);
    std::swap(passed_, other->passed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChallengeExternalResult::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChallengeExternalResult_descriptor_;
  metadata.reflection = ChallengeExternalResult_reflection_;
  return metadata;
}


// ===================================================================

ChallengeService::ChallengeService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ChallengeService::~ChallengeService() {
}

google::protobuf::ServiceDescriptor const* ChallengeService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeService_descriptor_;
}

void ChallengeService::ChallengePicked(::bgs::protocol::challenge::v1::ChallengePickedRequest const* request, std::function<void(::bgs::protocol::challenge::v1::ChallengePickedResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeService.ChallengePicked(bgs.protocol.challenge.v1.ChallengePickedRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::challenge::v1::ChallengePickedResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void ChallengeService::ChallengeAnswered(::bgs::protocol::challenge::v1::ChallengeAnsweredRequest const* request, std::function<void(::bgs::protocol::challenge::v1::ChallengeAnsweredResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeService.ChallengeAnswered(bgs.protocol.challenge.v1.ChallengeAnsweredRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::challenge::v1::ChallengeAnsweredResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void ChallengeService::ChallengeCancelled(::bgs::protocol::challenge::v1::ChallengeCancelledRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeService.ChallengeCancelled(bgs.protocol.challenge.v1.ChallengeCancelledRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void ChallengeService::SendChallengeToUser(::bgs::protocol::challenge::v1::SendChallengeToUserRequest const* request, std::function<void(::bgs::protocol::challenge::v1::SendChallengeToUserResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeService.SendChallengeToUser(bgs.protocol.challenge.v1.SendChallengeToUserRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::challenge::v1::SendChallengeToUserResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 4, request, std::move(callback));
}

void ChallengeService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::challenge::v1::ChallengePickedRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeService.ChallengePicked server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::challenge::v1::ChallengePickedResponse response;
      uint32 status = HandleChallengePicked(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeService.ChallengePicked(bgs.protocol.challenge.v1.ChallengePickedRequest{ %s }) returned bgs.protocol.challenge.v1.ChallengePickedResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::challenge::v1::ChallengeAnsweredRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeService.ChallengeAnswered server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::challenge::v1::ChallengeAnsweredResponse response;
      uint32 status = HandleChallengeAnswered(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeService.ChallengeAnswered(bgs.protocol.challenge.v1.ChallengeAnsweredRequest{ %s }) returned bgs.protocol.challenge.v1.ChallengeAnsweredResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::challenge::v1::ChallengeCancelledRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeService.ChallengeCancelled server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleChallengeCancelled(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeService.ChallengeCancelled(bgs.protocol.challenge.v1.ChallengeCancelledRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::challenge::v1::SendChallengeToUserRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeService.SendChallengeToUser server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::challenge::v1::SendChallengeToUserResponse response;
      uint32 status = HandleSendChallengeToUser(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeService.SendChallengeToUser(bgs.protocol.challenge.v1.SendChallengeToUserRequest{ %s }) returned bgs.protocol.challenge.v1.SendChallengeToUserResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 4, token, &response);
      else
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ChallengeService::HandleChallengePicked(::bgs::protocol::challenge::v1::ChallengePickedRequest const* request, ::bgs::protocol::challenge::v1::ChallengePickedResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeService.ChallengePicked({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeService::HandleChallengeAnswered(::bgs::protocol::challenge::v1::ChallengeAnsweredRequest const* request, ::bgs::protocol::challenge::v1::ChallengeAnsweredResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeService.ChallengeAnswered({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeService::HandleChallengeCancelled(::bgs::protocol::challenge::v1::ChallengeCancelledRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeService.ChallengeCancelled({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeService::HandleSendChallengeToUser(::bgs::protocol::challenge::v1::SendChallengeToUserRequest const* request, ::bgs::protocol::challenge::v1::SendChallengeToUserResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeService.SendChallengeToUser({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

ChallengeListener::ChallengeListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ChallengeListener::~ChallengeListener() {
}

google::protobuf::ServiceDescriptor const* ChallengeListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChallengeListener_descriptor_;
}

void ChallengeListener::OnChallengeUser(::bgs::protocol::challenge::v1::ChallengeUserRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeListener.OnChallengeUser(bgs.protocol.challenge.v1.ChallengeUserRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void ChallengeListener::OnChallengeResult(::bgs::protocol::challenge::v1::ChallengeResultRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeListener.OnChallengeResult(bgs.protocol.challenge.v1.ChallengeResultRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 2, request);
}

void ChallengeListener::OnExternalChallenge(::bgs::protocol::challenge::v1::ChallengeExternalRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeListener.OnExternalChallenge(bgs.protocol.challenge.v1.ChallengeExternalRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 3, request);
}

void ChallengeListener::OnExternalChallengeResult(::bgs::protocol::challenge::v1::ChallengeExternalResult const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ChallengeListener.OnExternalChallengeResult(bgs.protocol.challenge.v1.ChallengeExternalResult{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void ChallengeListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::challenge::v1::ChallengeUserRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeListener.OnChallengeUser server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnChallengeUser(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeListener.OnChallengeUser(bgs.protocol.challenge.v1.ChallengeUserRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::challenge::v1::ChallengeResultRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeListener.OnChallengeResult server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnChallengeResult(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeListener.OnChallengeResult(bgs.protocol.challenge.v1.ChallengeResultRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::challenge::v1::ChallengeExternalRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeListener.OnExternalChallenge server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnExternalChallenge(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeListener.OnExternalChallenge(bgs.protocol.challenge.v1.ChallengeExternalRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::challenge::v1::ChallengeExternalResult request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ChallengeListener.OnExternalChallengeResult server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnExternalChallengeResult(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ChallengeListener.OnExternalChallengeResult(bgs.protocol.challenge.v1.ChallengeExternalResult{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ChallengeListener::HandleOnChallengeUser(::bgs::protocol::challenge::v1::ChallengeUserRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeListener.OnChallengeUser({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeListener::HandleOnChallengeResult(::bgs::protocol::challenge::v1::ChallengeResultRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeListener.OnChallengeResult({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeListener::HandleOnExternalChallenge(::bgs::protocol::challenge::v1::ChallengeExternalRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeListener.OnExternalChallenge({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ChallengeListener::HandleOnExternalChallengeResult(::bgs::protocol::challenge::v1::ChallengeExternalResult const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ChallengeListener.OnExternalChallengeResult({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace challenge
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
