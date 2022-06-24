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
#include "authentication_service.pb.h"

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
namespace authentication {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ModuleLoadRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ModuleLoadRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ModuleNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ModuleNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* ModuleMessageRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ModuleMessageRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* LogonRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogonRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* LogonResult_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogonResult_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenerateSSOTokenRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenerateSSOTokenRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenerateSSOTokenResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenerateSSOTokenResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* LogonUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogonUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* LogonQueueUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogonQueueUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountSettingsNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountSettingsNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* ServerStateChangeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServerStateChangeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* VersionInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VersionInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* VersionInfoNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VersionInfoNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* MemModuleLoadRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemModuleLoadRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* MemModuleLoadResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MemModuleLoadResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* SelectGameAccountRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SelectGameAccountRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountSelectedRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountSelectedRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenerateWebCredentialsRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenerateWebCredentialsRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GenerateWebCredentialsResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GenerateWebCredentialsResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* VerifyWebCredentialsRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VerifyWebCredentialsRequest_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* AuthenticationListener_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* AuthenticationService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_authentication_5fservice_2eproto() {
  protobuf_AddDesc_authentication_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "authentication_service.proto");
  GOOGLE_CHECK(file != NULL);
  ModuleLoadRequest_descriptor_ = file->message_type(0);
  static const int ModuleLoadRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleLoadRequest, module_handle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleLoadRequest, message_),
  };
  ModuleLoadRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ModuleLoadRequest_descriptor_,
      ModuleLoadRequest::default_instance_,
      ModuleLoadRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleLoadRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleLoadRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ModuleLoadRequest));
  ModuleNotification_descriptor_ = file->message_type(1);
  static const int ModuleNotification_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleNotification, module_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleNotification, result_),
  };
  ModuleNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ModuleNotification_descriptor_,
      ModuleNotification::default_instance_,
      ModuleNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ModuleNotification));
  ModuleMessageRequest_descriptor_ = file->message_type(2);
  static const int ModuleMessageRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleMessageRequest, module_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleMessageRequest, message_),
  };
  ModuleMessageRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ModuleMessageRequest_descriptor_,
      ModuleMessageRequest::default_instance_,
      ModuleMessageRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleMessageRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModuleMessageRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ModuleMessageRequest));
  LogonRequest_descriptor_ = file->message_type(3);
  static const int LogonRequest_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, platform_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, locale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, application_version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, public_computer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, sso_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, disconnect_on_cookie_fail_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, allow_logon_queue_notifications_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, web_client_verification_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, cached_web_credentials_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, user_agent_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, device_id_),
  };
  LogonRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogonRequest_descriptor_,
      LogonRequest::default_instance_,
      LogonRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogonRequest));
  LogonResult_descriptor_ = file->message_type(4);
  static const int LogonResult_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, error_code_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, available_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, connected_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, geoip_country_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, session_key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, restricted_mode_),
  };
  LogonResult_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogonResult_descriptor_,
      LogonResult::default_instance_,
      LogonResult_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonResult, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogonResult));
  GenerateSSOTokenRequest_descriptor_ = file->message_type(5);
  static const int GenerateSSOTokenRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenRequest, program_),
  };
  GenerateSSOTokenRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenerateSSOTokenRequest_descriptor_,
      GenerateSSOTokenRequest::default_instance_,
      GenerateSSOTokenRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenerateSSOTokenRequest));
  GenerateSSOTokenResponse_descriptor_ = file->message_type(6);
  static const int GenerateSSOTokenResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenResponse, sso_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenResponse, sso_secret_),
  };
  GenerateSSOTokenResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenerateSSOTokenResponse_descriptor_,
      GenerateSSOTokenResponse::default_instance_,
      GenerateSSOTokenResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateSSOTokenResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenerateSSOTokenResponse));
  LogonUpdateRequest_descriptor_ = file->message_type(7);
  static const int LogonUpdateRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonUpdateRequest, error_code_),
  };
  LogonUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogonUpdateRequest_descriptor_,
      LogonUpdateRequest::default_instance_,
      LogonUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogonUpdateRequest));
  LogonQueueUpdateRequest_descriptor_ = file->message_type(8);
  static const int LogonQueueUpdateRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonQueueUpdateRequest, position_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonQueueUpdateRequest, estimated_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonQueueUpdateRequest, eta_deviation_in_sec_),
  };
  LogonQueueUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogonQueueUpdateRequest_descriptor_,
      LogonQueueUpdateRequest::default_instance_,
      LogonQueueUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonQueueUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogonQueueUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogonQueueUpdateRequest));
  AccountSettingsNotification_descriptor_ = file->message_type(9);
  static const int AccountSettingsNotification_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, is_using_rid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, is_playing_from_igr_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, can_receive_voice_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, can_send_voice_),
  };
  AccountSettingsNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountSettingsNotification_descriptor_,
      AccountSettingsNotification::default_instance_,
      AccountSettingsNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountSettingsNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountSettingsNotification));
  ServerStateChangeRequest_descriptor_ = file->message_type(10);
  static const int ServerStateChangeRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerStateChangeRequest, state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerStateChangeRequest, event_time_),
  };
  ServerStateChangeRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ServerStateChangeRequest_descriptor_,
      ServerStateChangeRequest::default_instance_,
      ServerStateChangeRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerStateChangeRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerStateChangeRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ServerStateChangeRequest));
  VersionInfo_descriptor_ = file->message_type(11);
  static const int VersionInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, number_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, patch_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, is_optional_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, kick_time_),
  };
  VersionInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VersionInfo_descriptor_,
      VersionInfo::default_instance_,
      VersionInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(VersionInfo));
  VersionInfoNotification_descriptor_ = file->message_type(12);
  static const int VersionInfoNotification_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfoNotification, version_info_),
  };
  VersionInfoNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VersionInfoNotification_descriptor_,
      VersionInfoNotification::default_instance_,
      VersionInfoNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfoNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VersionInfoNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(VersionInfoNotification));
  MemModuleLoadRequest_descriptor_ = file->message_type(13);
  static const int MemModuleLoadRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadRequest, handle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadRequest, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadRequest, input_),
  };
  MemModuleLoadRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemModuleLoadRequest_descriptor_,
      MemModuleLoadRequest::default_instance_,
      MemModuleLoadRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemModuleLoadRequest));
  MemModuleLoadResponse_descriptor_ = file->message_type(14);
  static const int MemModuleLoadResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadResponse, data_),
  };
  MemModuleLoadResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MemModuleLoadResponse_descriptor_,
      MemModuleLoadResponse::default_instance_,
      MemModuleLoadResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MemModuleLoadResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MemModuleLoadResponse));
  SelectGameAccountRequest_descriptor_ = file->message_type(15);
  static const int SelectGameAccountRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SelectGameAccountRequest, game_account_id_),
  };
  SelectGameAccountRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SelectGameAccountRequest_descriptor_,
      SelectGameAccountRequest::default_instance_,
      SelectGameAccountRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SelectGameAccountRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SelectGameAccountRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SelectGameAccountRequest));
  GameAccountSelectedRequest_descriptor_ = file->message_type(16);
  static const int GameAccountSelectedRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSelectedRequest, result_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSelectedRequest, game_account_id_),
  };
  GameAccountSelectedRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountSelectedRequest_descriptor_,
      GameAccountSelectedRequest::default_instance_,
      GameAccountSelectedRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSelectedRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSelectedRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountSelectedRequest));
  GenerateWebCredentialsRequest_descriptor_ = file->message_type(17);
  static const int GenerateWebCredentialsRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsRequest, program_),
  };
  GenerateWebCredentialsRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenerateWebCredentialsRequest_descriptor_,
      GenerateWebCredentialsRequest::default_instance_,
      GenerateWebCredentialsRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenerateWebCredentialsRequest));
  GenerateWebCredentialsResponse_descriptor_ = file->message_type(18);
  static const int GenerateWebCredentialsResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsResponse, web_credentials_),
  };
  GenerateWebCredentialsResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GenerateWebCredentialsResponse_descriptor_,
      GenerateWebCredentialsResponse::default_instance_,
      GenerateWebCredentialsResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GenerateWebCredentialsResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GenerateWebCredentialsResponse));
  VerifyWebCredentialsRequest_descriptor_ = file->message_type(19);
  static const int VerifyWebCredentialsRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VerifyWebCredentialsRequest, web_credentials_),
  };
  VerifyWebCredentialsRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VerifyWebCredentialsRequest_descriptor_,
      VerifyWebCredentialsRequest::default_instance_,
      VerifyWebCredentialsRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VerifyWebCredentialsRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VerifyWebCredentialsRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(VerifyWebCredentialsRequest));
  AuthenticationListener_descriptor_ = file->service(0);
  AuthenticationService_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_authentication_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ModuleLoadRequest_descriptor_, &ModuleLoadRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ModuleNotification_descriptor_, &ModuleNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ModuleMessageRequest_descriptor_, &ModuleMessageRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogonRequest_descriptor_, &LogonRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogonResult_descriptor_, &LogonResult::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenerateSSOTokenRequest_descriptor_, &GenerateSSOTokenRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenerateSSOTokenResponse_descriptor_, &GenerateSSOTokenResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogonUpdateRequest_descriptor_, &LogonUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogonQueueUpdateRequest_descriptor_, &LogonQueueUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountSettingsNotification_descriptor_, &AccountSettingsNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ServerStateChangeRequest_descriptor_, &ServerStateChangeRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VersionInfo_descriptor_, &VersionInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VersionInfoNotification_descriptor_, &VersionInfoNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemModuleLoadRequest_descriptor_, &MemModuleLoadRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MemModuleLoadResponse_descriptor_, &MemModuleLoadResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SelectGameAccountRequest_descriptor_, &SelectGameAccountRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountSelectedRequest_descriptor_, &GameAccountSelectedRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenerateWebCredentialsRequest_descriptor_, &GenerateWebCredentialsRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GenerateWebCredentialsResponse_descriptor_, &GenerateWebCredentialsResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VerifyWebCredentialsRequest_descriptor_, &VerifyWebCredentialsRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_authentication_5fservice_2eproto() {
  delete ModuleLoadRequest::default_instance_;
  delete ModuleLoadRequest_reflection_;
  delete ModuleNotification::default_instance_;
  delete ModuleNotification_reflection_;
  delete ModuleMessageRequest::default_instance_;
  delete ModuleMessageRequest_reflection_;
  delete LogonRequest::default_instance_;
  delete LogonRequest_reflection_;
  delete LogonResult::default_instance_;
  delete LogonResult_reflection_;
  delete GenerateSSOTokenRequest::default_instance_;
  delete GenerateSSOTokenRequest_reflection_;
  delete GenerateSSOTokenResponse::default_instance_;
  delete GenerateSSOTokenResponse_reflection_;
  delete LogonUpdateRequest::default_instance_;
  delete LogonUpdateRequest_reflection_;
  delete LogonQueueUpdateRequest::default_instance_;
  delete LogonQueueUpdateRequest_reflection_;
  delete AccountSettingsNotification::default_instance_;
  delete AccountSettingsNotification_reflection_;
  delete ServerStateChangeRequest::default_instance_;
  delete ServerStateChangeRequest_reflection_;
  delete VersionInfo::default_instance_;
  delete VersionInfo_reflection_;
  delete VersionInfoNotification::default_instance_;
  delete VersionInfoNotification_reflection_;
  delete MemModuleLoadRequest::default_instance_;
  delete MemModuleLoadRequest_reflection_;
  delete MemModuleLoadResponse::default_instance_;
  delete MemModuleLoadResponse_reflection_;
  delete SelectGameAccountRequest::default_instance_;
  delete SelectGameAccountRequest_reflection_;
  delete GameAccountSelectedRequest::default_instance_;
  delete GameAccountSelectedRequest_reflection_;
  delete GenerateWebCredentialsRequest::default_instance_;
  delete GenerateWebCredentialsRequest_reflection_;
  delete GenerateWebCredentialsResponse::default_instance_;
  delete GenerateWebCredentialsResponse_reflection_;
  delete VerifyWebCredentialsRequest::default_instance_;
  delete VerifyWebCredentialsRequest_reflection_;
}

void protobuf_AddDesc_authentication_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::account::v1::protobuf_AddDesc_account_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034authentication_service.proto\022\036bgs.prot"
    "ocol.authentication.v1\032\023account_types.pr"
    "oto\032\032content_handle_types.proto\032\022entity_"
    "types.proto\032\017rpc_types.proto\"X\n\021ModuleLo"
    "adRequest\0222\n\rmodule_handle\030\001 \002(\0132\033.bgs.p"
    "rotocol.ContentHandle\022\017\n\007message\030\002 \001(\014\"7"
    "\n\022ModuleNotification\022\021\n\tmodule_id\030\002 \001(\005\022"
    "\016\n\006result\030\003 \001(\r\":\n\024ModuleMessageRequest\022"
    "\021\n\tmodule_id\030\001 \002(\005\022\017\n\007message\030\002 \001(\014\"\360\002\n\014"
    "LogonRequest\022\017\n\007program\030\001 \001(\t\022\020\n\010platfor"
    "m\030\002 \001(\t\022\016\n\006locale\030\003 \001(\t\022\r\n\005email\030\004 \001(\t\022\017"
    "\n\007version\030\005 \001(\t\022\033\n\023application_version\030\006"
    " \001(\005\022\027\n\017public_computer\030\007 \001(\010\022\016\n\006sso_id\030"
    "\010 \001(\014\022(\n\031disconnect_on_cookie_fail\030\t \001(\010"
    ":\005false\022.\n\037allow_logon_queue_notificatio"
    "ns\030\n \001(\010:\005false\022&\n\027web_client_verificati"
    "on\030\013 \001(\010:\005false\022\036\n\026cached_web_credential"
    "s\030\014 \001(\014\022\022\n\nuser_agent\030\016 \001(\t\022\021\n\tdevice_id"
    "\030\017 \001(\t\"\232\002\n\013LogonResult\022\022\n\nerror_code\030\001 \002"
    "(\r\022*\n\naccount_id\030\002 \001(\0132\026.bgs.protocol.En"
    "tityId\022/\n\017game_account_id\030\003 \003(\0132\026.bgs.pr"
    "otocol.EntityId\022\r\n\005email\030\004 \001(\t\022\030\n\020availa"
    "ble_region\030\005 \003(\r\022\030\n\020connected_region\030\006 \001"
    "(\r\022\022\n\nbattle_tag\030\007 \001(\t\022\025\n\rgeoip_country\030"
    "\010 \001(\t\022\023\n\013session_key\030\t \001(\014\022\027\n\017restricted"
    "_mode\030\n \001(\010\"*\n\027GenerateSSOTokenRequest\022\017"
    "\n\007program\030\001 \001(\007\">\n\030GenerateSSOTokenRespo"
    "nse\022\016\n\006sso_id\030\001 \001(\014\022\022\n\nsso_secret\030\002 \001(\014\""
    "(\n\022LogonUpdateRequest\022\022\n\nerror_code\030\001 \002("
    "\r\"a\n\027LogonQueueUpdateRequest\022\020\n\010position"
    "\030\001 \002(\r\022\026\n\016estimated_time\030\002 \002(\004\022\034\n\024eta_de"
    "viation_in_sec\030\003 \002(\004\"\276\001\n\033AccountSettings"
    "Notification\0229\n\010licenses\030\001 \003(\0132\'.bgs.pro"
    "tocol.account.v1.AccountLicense\022\024\n\014is_us"
    "ing_rid\030\002 \001(\010\022\033\n\023is_playing_from_igr\030\003 \001"
    "(\010\022\031\n\021can_receive_voice\030\004 \001(\010\022\026\n\016can_sen"
    "d_voice\030\005 \001(\010\"=\n\030ServerStateChangeReques"
    "t\022\r\n\005state\030\001 \002(\r\022\022\n\nevent_time\030\002 \002(\004\"T\n\013"
    "VersionInfo\022\016\n\006number\030\001 \001(\r\022\r\n\005patch\030\002 \001"
    "(\t\022\023\n\013is_optional\030\003 \001(\010\022\021\n\tkick_time\030\004 \001"
    "(\004\"\\\n\027VersionInfoNotification\022A\n\014version"
    "_info\030\001 \001(\0132+.bgs.protocol.authenticatio"
    "n.v1.VersionInfo\"_\n\024MemModuleLoadRequest"
    "\022+\n\006handle\030\001 \002(\0132\033.bgs.protocol.ContentH"
    "andle\022\013\n\003key\030\002 \002(\014\022\r\n\005input\030\003 \002(\014\"%\n\025Mem"
    "ModuleLoadResponse\022\014\n\004data\030\001 \002(\014\"K\n\030Sele"
    "ctGameAccountRequest\022/\n\017game_account_id\030"
    "\001 \002(\0132\026.bgs.protocol.EntityId\"]\n\032GameAcc"
    "ountSelectedRequest\022\016\n\006result\030\001 \002(\r\022/\n\017g"
    "ame_account_id\030\002 \001(\0132\026.bgs.protocol.Enti"
    "tyId\"0\n\035GenerateWebCredentialsRequest\022\017\n"
    "\007program\030\001 \001(\007\"9\n\036GenerateWebCredentials"
    "Response\022\027\n\017web_credentials\030\001 \001(\014\"6\n\033Ver"
    "ifyWebCredentialsRequest\022\027\n\017web_credenti"
    "als\030\001 \001(\0142\202\t\n\026AuthenticationListener\022e\n\014"
    "OnModuleLoad\0221.bgs.protocol.authenticati"
    "on.v1.ModuleLoadRequest\032\031.bgs.protocol.N"
    "O_RESPONSE\"\007\210\002\001\200\265\030\001\022f\n\017OnModuleMessage\0224"
    ".bgs.protocol.authentication.v1.ModuleMe"
    "ssageRequest\032\024.bgs.protocol.NoData\"\007\210\002\001\200"
    "\265\030\002\022p\n\023OnServerStateChange\0228.bgs.protoco"
    "l.authentication.v1.ServerStateChangeReq"
    "uest\032\031.bgs.protocol.NO_RESPONSE\"\004\200\265\030\004\022_\n"
    "\017OnLogonComplete\022+.bgs.protocol.authenti"
    "cation.v1.LogonResult\032\031.bgs.protocol.NO_"
    "RESPONSE\"\004\200\265\030\005\022\204\001\n\017OnMemModuleLoad\0224.bgs"
    ".protocol.authentication.v1.MemModuleLoa"
    "dRequest\0325.bgs.protocol.authentication.v"
    "1.MemModuleLoadResponse\"\004\200\265\030\006\022d\n\rOnLogon"
    "Update\0222.bgs.protocol.authentication.v1."
    "LogonUpdateRequest\032\031.bgs.protocol.NO_RES"
    "PONSE\"\004\200\265\030\n\022p\n\024OnVersionInfoUpdated\0227.bg"
    "s.protocol.authentication.v1.VersionInfo"
    "Notification\032\031.bgs.protocol.NO_RESPONSE\""
    "\004\200\265\030\013\022n\n\022OnLogonQueueUpdate\0227.bgs.protoc"
    "ol.authentication.v1.LogonQueueUpdateReq"
    "uest\032\031.bgs.protocol.NO_RESPONSE\"\004\200\265\030\014\022H\n"
    "\017OnLogonQueueEnd\022\024.bgs.protocol.NoData\032\031"
    ".bgs.protocol.NO_RESPONSE\"\004\200\265\030\r\022w\n\025OnGam"
    "eAccountSelected\022:.bgs.protocol.authenti"
    "cation.v1.GameAccountSelectedRequest\032\031.b"
    "gs.protocol.NO_RESPONSE\"\007\210\002\001\200\265\030\016\0324\312>1bne"
    "t.protocol.authentication.Authentication"
    "Client2\315\007\n\025AuthenticationService\022Q\n\005Logo"
    "n\022,.bgs.protocol.authentication.v1.Logon"
    "Request\032\024.bgs.protocol.NoData\"\004\200\265\030\001\022a\n\014M"
    "oduleNotify\0222.bgs.protocol.authenticatio"
    "n.v1.ModuleNotification\032\024.bgs.protocol.N"
    "oData\"\007\210\002\001\200\265\030\002\022d\n\rModuleMessage\0224.bgs.pr"
    "otocol.authentication.v1.ModuleMessageRe"
    "quest\032\024.bgs.protocol.NoData\"\007\210\002\001\200\265\030\003\022U\n\034"
    "SelectGameAccount_DEPRECATED\022\026.bgs.proto"
    "col.EntityId\032\024.bgs.protocol.NoData\"\007\210\002\001\200"
    "\265\030\004\022\213\001\n\020GenerateSSOToken\0227.bgs.protocol."
    "authentication.v1.GenerateSSOTokenReques"
    "t\0328.bgs.protocol.authentication.v1.Gener"
    "ateSSOTokenResponse\"\004\200\265\030\005\022l\n\021SelectGameA"
    "ccount\0228.bgs.protocol.authentication.v1."
    "SelectGameAccountRequest\032\024.bgs.protocol."
    "NoData\"\007\210\002\001\200\265\030\006\022o\n\024VerifyWebCredentials\022"
    ";.bgs.protocol.authentication.v1.VerifyW"
    "ebCredentialsRequest\032\024.bgs.protocol.NoDa"
    "ta\"\004\200\265\030\007\022\235\001\n\026GenerateWebCredentials\022=.bg"
    "s.protocol.authentication.v1.GenerateWeb"
    "CredentialsRequest\032>.bgs.protocol.authen"
    "tication.v1.GenerateWebCredentialsRespon"
    "se\"\004\200\265\030\010\0324\312>1bnet.protocol.authenticatio"
    "n.AuthenticationServerB\005H\001\200\001\000", 4309);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "authentication_service.proto", &protobuf_RegisterTypes);
  ModuleLoadRequest::default_instance_ = new ModuleLoadRequest();
  ModuleNotification::default_instance_ = new ModuleNotification();
  ModuleMessageRequest::default_instance_ = new ModuleMessageRequest();
  LogonRequest::default_instance_ = new LogonRequest();
  LogonResult::default_instance_ = new LogonResult();
  GenerateSSOTokenRequest::default_instance_ = new GenerateSSOTokenRequest();
  GenerateSSOTokenResponse::default_instance_ = new GenerateSSOTokenResponse();
  LogonUpdateRequest::default_instance_ = new LogonUpdateRequest();
  LogonQueueUpdateRequest::default_instance_ = new LogonQueueUpdateRequest();
  AccountSettingsNotification::default_instance_ = new AccountSettingsNotification();
  ServerStateChangeRequest::default_instance_ = new ServerStateChangeRequest();
  VersionInfo::default_instance_ = new VersionInfo();
  VersionInfoNotification::default_instance_ = new VersionInfoNotification();
  MemModuleLoadRequest::default_instance_ = new MemModuleLoadRequest();
  MemModuleLoadResponse::default_instance_ = new MemModuleLoadResponse();
  SelectGameAccountRequest::default_instance_ = new SelectGameAccountRequest();
  GameAccountSelectedRequest::default_instance_ = new GameAccountSelectedRequest();
  GenerateWebCredentialsRequest::default_instance_ = new GenerateWebCredentialsRequest();
  GenerateWebCredentialsResponse::default_instance_ = new GenerateWebCredentialsResponse();
  VerifyWebCredentialsRequest::default_instance_ = new VerifyWebCredentialsRequest();
  ModuleLoadRequest::default_instance_->InitAsDefaultInstance();
  ModuleNotification::default_instance_->InitAsDefaultInstance();
  ModuleMessageRequest::default_instance_->InitAsDefaultInstance();
  LogonRequest::default_instance_->InitAsDefaultInstance();
  LogonResult::default_instance_->InitAsDefaultInstance();
  GenerateSSOTokenRequest::default_instance_->InitAsDefaultInstance();
  GenerateSSOTokenResponse::default_instance_->InitAsDefaultInstance();
  LogonUpdateRequest::default_instance_->InitAsDefaultInstance();
  LogonQueueUpdateRequest::default_instance_->InitAsDefaultInstance();
  AccountSettingsNotification::default_instance_->InitAsDefaultInstance();
  ServerStateChangeRequest::default_instance_->InitAsDefaultInstance();
  VersionInfo::default_instance_->InitAsDefaultInstance();
  VersionInfoNotification::default_instance_->InitAsDefaultInstance();
  MemModuleLoadRequest::default_instance_->InitAsDefaultInstance();
  MemModuleLoadResponse::default_instance_->InitAsDefaultInstance();
  SelectGameAccountRequest::default_instance_->InitAsDefaultInstance();
  GameAccountSelectedRequest::default_instance_->InitAsDefaultInstance();
  GenerateWebCredentialsRequest::default_instance_->InitAsDefaultInstance();
  GenerateWebCredentialsResponse::default_instance_->InitAsDefaultInstance();
  VerifyWebCredentialsRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_authentication_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_authentication_5fservice_2eproto {
  StaticDescriptorInitializer_authentication_5fservice_2eproto() {
    protobuf_AddDesc_authentication_5fservice_2eproto();
  }
} static_descriptor_initializer_authentication_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ModuleLoadRequest::kModuleHandleFieldNumber;
const int ModuleLoadRequest::kMessageFieldNumber;
#endif  // !_MSC_VER

ModuleLoadRequest::ModuleLoadRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.ModuleLoadRequest)
}

void ModuleLoadRequest::InitAsDefaultInstance() {
  module_handle_ = const_cast< ::bgs::protocol::ContentHandle*>(&::bgs::protocol::ContentHandle::default_instance());
}

ModuleLoadRequest::ModuleLoadRequest(const ModuleLoadRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.ModuleLoadRequest)
}

void ModuleLoadRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  module_handle_ = NULL;
  message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ModuleLoadRequest::~ModuleLoadRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.ModuleLoadRequest)
  SharedDtor();
}

void ModuleLoadRequest::SharedDtor() {
  if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete message_;
  }
  if (this != default_instance_) {
    delete module_handle_;
  }
}

void ModuleLoadRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ModuleLoadRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ModuleLoadRequest_descriptor_;
}

const ModuleLoadRequest& ModuleLoadRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

ModuleLoadRequest* ModuleLoadRequest::default_instance_ = NULL;

ModuleLoadRequest* ModuleLoadRequest::New() const {
  return new ModuleLoadRequest;
}

void ModuleLoadRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_module_handle()) {
      if (module_handle_ != NULL) module_handle_->::bgs::protocol::ContentHandle::Clear();
    }
    if (has_message()) {
      if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        message_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ModuleLoadRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.ModuleLoadRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.ContentHandle module_handle = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_module_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_message;
        break;
      }

      // optional bytes message = 2;
      case 2: {
        if (tag == 18) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_message()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.ModuleLoadRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.ModuleLoadRequest)
  return false;
#undef DO_
}

void ModuleLoadRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.ModuleLoadRequest)
  // required .bgs.protocol.ContentHandle module_handle = 1;
  if (has_module_handle()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->module_handle(), output);
  }

  // optional bytes message = 2;
  if (has_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->message(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.ModuleLoadRequest)
}

::google::protobuf::uint8* ModuleLoadRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.ModuleLoadRequest)
  // required .bgs.protocol.ContentHandle module_handle = 1;
  if (has_module_handle()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->module_handle(), target);
  }

  // optional bytes message = 2;
  if (has_message()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->message(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.ModuleLoadRequest)
  return target;
}

int ModuleLoadRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.ContentHandle module_handle = 1;
    if (has_module_handle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->module_handle());
    }

    // optional bytes message = 2;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->message());
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

void ModuleLoadRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ModuleLoadRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ModuleLoadRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ModuleLoadRequest::MergeFrom(const ModuleLoadRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_module_handle()) {
      mutable_module_handle()->::bgs::protocol::ContentHandle::MergeFrom(from.module_handle());
    }
    if (from.has_message()) {
      set_message(from.message());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ModuleLoadRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModuleLoadRequest::CopyFrom(const ModuleLoadRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModuleLoadRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_module_handle()) {
    if (!this->module_handle().IsInitialized()) return false;
  }
  return true;
}

void ModuleLoadRequest::Swap(ModuleLoadRequest* other) {
  if (other != this) {
    std::swap(module_handle_, other->module_handle_);
    std::swap(message_, other->message_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ModuleLoadRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ModuleLoadRequest_descriptor_;
  metadata.reflection = ModuleLoadRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ModuleNotification::kModuleIdFieldNumber;
const int ModuleNotification::kResultFieldNumber;
#endif  // !_MSC_VER

ModuleNotification::ModuleNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.ModuleNotification)
}

void ModuleNotification::InitAsDefaultInstance() {
}

ModuleNotification::ModuleNotification(const ModuleNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.ModuleNotification)
}

void ModuleNotification::SharedCtor() {
  _cached_size_ = 0;
  module_id_ = 0;
  result_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ModuleNotification::~ModuleNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.ModuleNotification)
  SharedDtor();
}

void ModuleNotification::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ModuleNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ModuleNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ModuleNotification_descriptor_;
}

const ModuleNotification& ModuleNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

ModuleNotification* ModuleNotification::default_instance_ = NULL;

ModuleNotification* ModuleNotification::New() const {
  return new ModuleNotification;
}

void ModuleNotification::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ModuleNotification*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(module_id_, result_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ModuleNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.ModuleNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 module_id = 2;
      case 2: {
        if (tag == 16) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &module_id_)));
          set_has_module_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_result;
        break;
      }

      // optional uint32 result = 3;
      case 3: {
        if (tag == 24) {
         parse_result:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &result_)));
          set_has_result();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.ModuleNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.ModuleNotification)
  return false;
#undef DO_
}

void ModuleNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.ModuleNotification)
  // optional int32 module_id = 2;
  if (has_module_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->module_id(), output);
  }

  // optional uint32 result = 3;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->result(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.ModuleNotification)
}

::google::protobuf::uint8* ModuleNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.ModuleNotification)
  // optional int32 module_id = 2;
  if (has_module_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->module_id(), target);
  }

  // optional uint32 result = 3;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->result(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.ModuleNotification)
  return target;
}

int ModuleNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 module_id = 2;
    if (has_module_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->module_id());
    }

    // optional uint32 result = 3;
    if (has_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->result());
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

void ModuleNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ModuleNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ModuleNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ModuleNotification::MergeFrom(const ModuleNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_module_id()) {
      set_module_id(from.module_id());
    }
    if (from.has_result()) {
      set_result(from.result());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ModuleNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModuleNotification::CopyFrom(const ModuleNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModuleNotification::IsInitialized() const {

  return true;
}

void ModuleNotification::Swap(ModuleNotification* other) {
  if (other != this) {
    std::swap(module_id_, other->module_id_);
    std::swap(result_, other->result_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ModuleNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ModuleNotification_descriptor_;
  metadata.reflection = ModuleNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ModuleMessageRequest::kModuleIdFieldNumber;
const int ModuleMessageRequest::kMessageFieldNumber;
#endif  // !_MSC_VER

ModuleMessageRequest::ModuleMessageRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.ModuleMessageRequest)
}

void ModuleMessageRequest::InitAsDefaultInstance() {
}

ModuleMessageRequest::ModuleMessageRequest(const ModuleMessageRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.ModuleMessageRequest)
}

void ModuleMessageRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  module_id_ = 0;
  message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ModuleMessageRequest::~ModuleMessageRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.ModuleMessageRequest)
  SharedDtor();
}

void ModuleMessageRequest::SharedDtor() {
  if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete message_;
  }
  if (this != default_instance_) {
  }
}

void ModuleMessageRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ModuleMessageRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ModuleMessageRequest_descriptor_;
}

const ModuleMessageRequest& ModuleMessageRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

ModuleMessageRequest* ModuleMessageRequest::default_instance_ = NULL;

ModuleMessageRequest* ModuleMessageRequest::New() const {
  return new ModuleMessageRequest;
}

void ModuleMessageRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    module_id_ = 0;
    if (has_message()) {
      if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        message_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ModuleMessageRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.ModuleMessageRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 module_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &module_id_)));
          set_has_module_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_message;
        break;
      }

      // optional bytes message = 2;
      case 2: {
        if (tag == 18) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_message()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.ModuleMessageRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.ModuleMessageRequest)
  return false;
#undef DO_
}

void ModuleMessageRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.ModuleMessageRequest)
  // required int32 module_id = 1;
  if (has_module_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->module_id(), output);
  }

  // optional bytes message = 2;
  if (has_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->message(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.ModuleMessageRequest)
}

::google::protobuf::uint8* ModuleMessageRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.ModuleMessageRequest)
  // required int32 module_id = 1;
  if (has_module_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->module_id(), target);
  }

  // optional bytes message = 2;
  if (has_message()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->message(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.ModuleMessageRequest)
  return target;
}

int ModuleMessageRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 module_id = 1;
    if (has_module_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->module_id());
    }

    // optional bytes message = 2;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->message());
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

void ModuleMessageRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ModuleMessageRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ModuleMessageRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ModuleMessageRequest::MergeFrom(const ModuleMessageRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_module_id()) {
      set_module_id(from.module_id());
    }
    if (from.has_message()) {
      set_message(from.message());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ModuleMessageRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModuleMessageRequest::CopyFrom(const ModuleMessageRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModuleMessageRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ModuleMessageRequest::Swap(ModuleMessageRequest* other) {
  if (other != this) {
    std::swap(module_id_, other->module_id_);
    std::swap(message_, other->message_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ModuleMessageRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ModuleMessageRequest_descriptor_;
  metadata.reflection = ModuleMessageRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int LogonRequest::kProgramFieldNumber;
const int LogonRequest::kPlatformFieldNumber;
const int LogonRequest::kLocaleFieldNumber;
const int LogonRequest::kEmailFieldNumber;
const int LogonRequest::kVersionFieldNumber;
const int LogonRequest::kApplicationVersionFieldNumber;
const int LogonRequest::kPublicComputerFieldNumber;
const int LogonRequest::kSsoIdFieldNumber;
const int LogonRequest::kDisconnectOnCookieFailFieldNumber;
const int LogonRequest::kAllowLogonQueueNotificationsFieldNumber;
const int LogonRequest::kWebClientVerificationFieldNumber;
const int LogonRequest::kCachedWebCredentialsFieldNumber;
const int LogonRequest::kUserAgentFieldNumber;
const int LogonRequest::kDeviceIdFieldNumber;
#endif  // !_MSC_VER

LogonRequest::LogonRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.LogonRequest)
}

void LogonRequest::InitAsDefaultInstance() {
}

LogonRequest::LogonRequest(const LogonRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.LogonRequest)
}

void LogonRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  program_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  platform_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  locale_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  version_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  application_version_ = 0;
  public_computer_ = false;
  sso_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  disconnect_on_cookie_fail_ = false;
  allow_logon_queue_notifications_ = false;
  web_client_verification_ = false;
  cached_web_credentials_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  user_agent_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  device_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogonRequest::~LogonRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.LogonRequest)
  SharedDtor();
}

void LogonRequest::SharedDtor() {
  if (program_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete program_;
  }
  if (platform_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete platform_;
  }
  if (locale_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete locale_;
  }
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete version_;
  }
  if (sso_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sso_id_;
  }
  if (cached_web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete cached_web_credentials_;
  }
  if (user_agent_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete user_agent_;
  }
  if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete device_id_;
  }
  if (this != default_instance_) {
  }
}

void LogonRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogonRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogonRequest_descriptor_;
}

const LogonRequest& LogonRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

LogonRequest* LogonRequest::default_instance_ = NULL;

LogonRequest* LogonRequest::New() const {
  return new LogonRequest;
}

void LogonRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<LogonRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(application_version_, public_computer_);
    if (has_program()) {
      if (program_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        program_->clear();
      }
    }
    if (has_platform()) {
      if (platform_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        platform_->clear();
      }
    }
    if (has_locale()) {
      if (locale_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        locale_->clear();
      }
    }
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
    if (has_version()) {
      if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        version_->clear();
      }
    }
    if (has_sso_id()) {
      if (sso_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sso_id_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 16128) {
    ZR_(disconnect_on_cookie_fail_, web_client_verification_);
    if (has_cached_web_credentials()) {
      if (cached_web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        cached_web_credentials_->clear();
      }
    }
    if (has_user_agent()) {
      if (user_agent_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        user_agent_->clear();
      }
    }
    if (has_device_id()) {
      if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        device_id_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogonRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.LogonRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string program = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_program()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->program().data(), this->program().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "program");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_platform;
        break;
      }

      // optional string platform = 2;
      case 2: {
        if (tag == 18) {
         parse_platform:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_platform()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->platform().data(), this->platform().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "platform");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_locale;
        break;
      }

      // optional string locale = 3;
      case 3: {
        if (tag == 26) {
         parse_locale:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_locale()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->locale().data(), this->locale().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "locale");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_email;
        break;
      }

      // optional string email = 4;
      case 4: {
        if (tag == 34) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email().data(), this->email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_version;
        break;
      }

      // optional string version = 5;
      case 5: {
        if (tag == 42) {
         parse_version:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->version().data(), this->version().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "version");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_application_version;
        break;
      }

      // optional int32 application_version = 6;
      case 6: {
        if (tag == 48) {
         parse_application_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &application_version_)));
          set_has_application_version();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_public_computer;
        break;
      }

      // optional bool public_computer = 7;
      case 7: {
        if (tag == 56) {
         parse_public_computer:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &public_computer_)));
          set_has_public_computer();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_sso_id;
        break;
      }

      // optional bytes sso_id = 8;
      case 8: {
        if (tag == 66) {
         parse_sso_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_sso_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_disconnect_on_cookie_fail;
        break;
      }

      // optional bool disconnect_on_cookie_fail = 9 [default = false];
      case 9: {
        if (tag == 72) {
         parse_disconnect_on_cookie_fail:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &disconnect_on_cookie_fail_)));
          set_has_disconnect_on_cookie_fail();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_allow_logon_queue_notifications;
        break;
      }

      // optional bool allow_logon_queue_notifications = 10 [default = false];
      case 10: {
        if (tag == 80) {
         parse_allow_logon_queue_notifications:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allow_logon_queue_notifications_)));
          set_has_allow_logon_queue_notifications();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_web_client_verification;
        break;
      }

      // optional bool web_client_verification = 11 [default = false];
      case 11: {
        if (tag == 88) {
         parse_web_client_verification:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &web_client_verification_)));
          set_has_web_client_verification();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_cached_web_credentials;
        break;
      }

      // optional bytes cached_web_credentials = 12;
      case 12: {
        if (tag == 98) {
         parse_cached_web_credentials:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_cached_web_credentials()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(114)) goto parse_user_agent;
        break;
      }

      // optional string user_agent = 14;
      case 14: {
        if (tag == 114) {
         parse_user_agent:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_user_agent()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->user_agent().data(), this->user_agent().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "user_agent");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(122)) goto parse_device_id;
        break;
      }

      // optional string device_id = 15;
      case 15: {
        if (tag == 122) {
         parse_device_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_device_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->device_id().data(), this->device_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "device_id");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.LogonRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.LogonRequest)
  return false;
#undef DO_
}

void LogonRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.LogonRequest)
  // optional string program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->program().data(), this->program().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "program");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->program(), output);
  }

  // optional string platform = 2;
  if (has_platform()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->platform().data(), this->platform().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "platform");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->platform(), output);
  }

  // optional string locale = 3;
  if (has_locale()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->locale().data(), this->locale().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "locale");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->locale(), output);
  }

  // optional string email = 4;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->email(), output);
  }

  // optional string version = 5;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->version(), output);
  }

  // optional int32 application_version = 6;
  if (has_application_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->application_version(), output);
  }

  // optional bool public_computer = 7;
  if (has_public_computer()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->public_computer(), output);
  }

  // optional bytes sso_id = 8;
  if (has_sso_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      8, this->sso_id(), output);
  }

  // optional bool disconnect_on_cookie_fail = 9 [default = false];
  if (has_disconnect_on_cookie_fail()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->disconnect_on_cookie_fail(), output);
  }

  // optional bool allow_logon_queue_notifications = 10 [default = false];
  if (has_allow_logon_queue_notifications()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(10, this->allow_logon_queue_notifications(), output);
  }

  // optional bool web_client_verification = 11 [default = false];
  if (has_web_client_verification()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(11, this->web_client_verification(), output);
  }

  // optional bytes cached_web_credentials = 12;
  if (has_cached_web_credentials()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      12, this->cached_web_credentials(), output);
  }

  // optional string user_agent = 14;
  if (has_user_agent()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_agent().data(), this->user_agent().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_agent");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      14, this->user_agent(), output);
  }

  // optional string device_id = 15;
  if (has_device_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->device_id().data(), this->device_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "device_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      15, this->device_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.LogonRequest)
}

::google::protobuf::uint8* LogonRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.LogonRequest)
  // optional string program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->program().data(), this->program().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "program");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->program(), target);
  }

  // optional string platform = 2;
  if (has_platform()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->platform().data(), this->platform().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "platform");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->platform(), target);
  }

  // optional string locale = 3;
  if (has_locale()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->locale().data(), this->locale().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "locale");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->locale(), target);
  }

  // optional string email = 4;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->email(), target);
  }

  // optional string version = 5;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->version(), target);
  }

  // optional int32 application_version = 6;
  if (has_application_version()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->application_version(), target);
  }

  // optional bool public_computer = 7;
  if (has_public_computer()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->public_computer(), target);
  }

  // optional bytes sso_id = 8;
  if (has_sso_id()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        8, this->sso_id(), target);
  }

  // optional bool disconnect_on_cookie_fail = 9 [default = false];
  if (has_disconnect_on_cookie_fail()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->disconnect_on_cookie_fail(), target);
  }

  // optional bool allow_logon_queue_notifications = 10 [default = false];
  if (has_allow_logon_queue_notifications()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(10, this->allow_logon_queue_notifications(), target);
  }

  // optional bool web_client_verification = 11 [default = false];
  if (has_web_client_verification()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(11, this->web_client_verification(), target);
  }

  // optional bytes cached_web_credentials = 12;
  if (has_cached_web_credentials()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        12, this->cached_web_credentials(), target);
  }

  // optional string user_agent = 14;
  if (has_user_agent()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_agent().data(), this->user_agent().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_agent");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        14, this->user_agent(), target);
  }

  // optional string device_id = 15;
  if (has_device_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->device_id().data(), this->device_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "device_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        15, this->device_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.LogonRequest)
  return target;
}

int LogonRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string program = 1;
    if (has_program()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->program());
    }

    // optional string platform = 2;
    if (has_platform()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->platform());
    }

    // optional string locale = 3;
    if (has_locale()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->locale());
    }

    // optional string email = 4;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

    // optional string version = 5;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->version());
    }

    // optional int32 application_version = 6;
    if (has_application_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->application_version());
    }

    // optional bool public_computer = 7;
    if (has_public_computer()) {
      total_size += 1 + 1;
    }

    // optional bytes sso_id = 8;
    if (has_sso_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->sso_id());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool disconnect_on_cookie_fail = 9 [default = false];
    if (has_disconnect_on_cookie_fail()) {
      total_size += 1 + 1;
    }

    // optional bool allow_logon_queue_notifications = 10 [default = false];
    if (has_allow_logon_queue_notifications()) {
      total_size += 1 + 1;
    }

    // optional bool web_client_verification = 11 [default = false];
    if (has_web_client_verification()) {
      total_size += 1 + 1;
    }

    // optional bytes cached_web_credentials = 12;
    if (has_cached_web_credentials()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->cached_web_credentials());
    }

    // optional string user_agent = 14;
    if (has_user_agent()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->user_agent());
    }

    // optional string device_id = 15;
    if (has_device_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->device_id());
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

void LogonRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogonRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogonRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogonRequest::MergeFrom(const LogonRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_platform()) {
      set_platform(from.platform());
    }
    if (from.has_locale()) {
      set_locale(from.locale());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
    if (from.has_version()) {
      set_version(from.version());
    }
    if (from.has_application_version()) {
      set_application_version(from.application_version());
    }
    if (from.has_public_computer()) {
      set_public_computer(from.public_computer());
    }
    if (from.has_sso_id()) {
      set_sso_id(from.sso_id());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_disconnect_on_cookie_fail()) {
      set_disconnect_on_cookie_fail(from.disconnect_on_cookie_fail());
    }
    if (from.has_allow_logon_queue_notifications()) {
      set_allow_logon_queue_notifications(from.allow_logon_queue_notifications());
    }
    if (from.has_web_client_verification()) {
      set_web_client_verification(from.web_client_verification());
    }
    if (from.has_cached_web_credentials()) {
      set_cached_web_credentials(from.cached_web_credentials());
    }
    if (from.has_user_agent()) {
      set_user_agent(from.user_agent());
    }
    if (from.has_device_id()) {
      set_device_id(from.device_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogonRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogonRequest::CopyFrom(const LogonRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogonRequest::IsInitialized() const {

  return true;
}

void LogonRequest::Swap(LogonRequest* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(platform_, other->platform_);
    std::swap(locale_, other->locale_);
    std::swap(email_, other->email_);
    std::swap(version_, other->version_);
    std::swap(application_version_, other->application_version_);
    std::swap(public_computer_, other->public_computer_);
    std::swap(sso_id_, other->sso_id_);
    std::swap(disconnect_on_cookie_fail_, other->disconnect_on_cookie_fail_);
    std::swap(allow_logon_queue_notifications_, other->allow_logon_queue_notifications_);
    std::swap(web_client_verification_, other->web_client_verification_);
    std::swap(cached_web_credentials_, other->cached_web_credentials_);
    std::swap(user_agent_, other->user_agent_);
    std::swap(device_id_, other->device_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogonRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogonRequest_descriptor_;
  metadata.reflection = LogonRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int LogonResult::kErrorCodeFieldNumber;
const int LogonResult::kAccountIdFieldNumber;
const int LogonResult::kGameAccountIdFieldNumber;
const int LogonResult::kEmailFieldNumber;
const int LogonResult::kAvailableRegionFieldNumber;
const int LogonResult::kConnectedRegionFieldNumber;
const int LogonResult::kBattleTagFieldNumber;
const int LogonResult::kGeoipCountryFieldNumber;
const int LogonResult::kSessionKeyFieldNumber;
const int LogonResult::kRestrictedModeFieldNumber;
#endif  // !_MSC_VER

LogonResult::LogonResult()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.LogonResult)
}

void LogonResult::InitAsDefaultInstance() {
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

LogonResult::LogonResult(const LogonResult& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.LogonResult)
}

void LogonResult::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  error_code_ = 0u;
  account_id_ = NULL;
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  connected_region_ = 0u;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  geoip_country_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  session_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  restricted_mode_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogonResult::~LogonResult() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.LogonResult)
  SharedDtor();
}

void LogonResult::SharedDtor() {
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (geoip_country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete geoip_country_;
  }
  if (session_key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_key_;
  }
  if (this != default_instance_) {
    delete account_id_;
  }
}

void LogonResult::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogonResult::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogonResult_descriptor_;
}

const LogonResult& LogonResult::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

LogonResult* LogonResult::default_instance_ = NULL;

LogonResult* LogonResult::New() const {
  return new LogonResult;
}

void LogonResult::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<LogonResult*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 235) {
    ZR_(error_code_, connected_region_);
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    if (has_geoip_country()) {
      if (geoip_country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        geoip_country_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 768) {
    if (has_session_key()) {
      if (session_key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        session_key_->clear();
      }
    }
    restricted_mode_ = false;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  game_account_id_.Clear();
  available_region_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogonResult::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.LogonResult)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 error_code = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &error_code_)));
          set_has_error_code();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_account_id;
        break;
      }

      // optional .bgs.protocol.EntityId account_id = 2;
      case 2: {
        if (tag == 18) {
         parse_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_game_account_id;
        break;
      }

      // repeated .bgs.protocol.EntityId game_account_id = 3;
      case 3: {
        if (tag == 26) {
         parse_game_account_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_account_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_game_account_id;
        if (input->ExpectTag(34)) goto parse_email;
        break;
      }

      // optional string email = 4;
      case 4: {
        if (tag == 34) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email().data(), this->email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_available_region;
        break;
      }

      // repeated uint32 available_region = 5;
      case 5: {
        if (tag == 40) {
         parse_available_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 40, input, this->mutable_available_region())));
        } else if (tag == 42) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_available_region())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_available_region;
        if (input->ExpectTag(48)) goto parse_connected_region;
        break;
      }

      // optional uint32 connected_region = 6;
      case 6: {
        if (tag == 48) {
         parse_connected_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &connected_region_)));
          set_has_connected_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 7;
      case 7: {
        if (tag == 58) {
         parse_battle_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_battle_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->battle_tag().data(), this->battle_tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "battle_tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_geoip_country;
        break;
      }

      // optional string geoip_country = 8;
      case 8: {
        if (tag == 66) {
         parse_geoip_country:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_geoip_country()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->geoip_country().data(), this->geoip_country().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "geoip_country");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_session_key;
        break;
      }

      // optional bytes session_key = 9;
      case 9: {
        if (tag == 74) {
         parse_session_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_session_key()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_restricted_mode;
        break;
      }

      // optional bool restricted_mode = 10;
      case 10: {
        if (tag == 80) {
         parse_restricted_mode:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &restricted_mode_)));
          set_has_restricted_mode();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.LogonResult)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.LogonResult)
  return false;
#undef DO_
}

void LogonResult::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.LogonResult)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->error_code(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 2;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->account_id(), output);
  }

  // repeated .bgs.protocol.EntityId game_account_id = 3;
  for (int i = 0; i < this->game_account_id_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->game_account_id(i), output);
  }

  // optional string email = 4;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->email(), output);
  }

  // repeated uint32 available_region = 5;
  for (int i = 0; i < this->available_region_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(
      5, this->available_region(i), output);
  }

  // optional uint32 connected_region = 6;
  if (has_connected_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->connected_region(), output);
  }

  // optional string battle_tag = 7;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->battle_tag(), output);
  }

  // optional string geoip_country = 8;
  if (has_geoip_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->geoip_country().data(), this->geoip_country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "geoip_country");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->geoip_country(), output);
  }

  // optional bytes session_key = 9;
  if (has_session_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      9, this->session_key(), output);
  }

  // optional bool restricted_mode = 10;
  if (has_restricted_mode()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(10, this->restricted_mode(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.LogonResult)
}

::google::protobuf::uint8* LogonResult::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.LogonResult)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->error_code(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 2;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->account_id(), target);
  }

  // repeated .bgs.protocol.EntityId game_account_id = 3;
  for (int i = 0; i < this->game_account_id_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->game_account_id(i), target);
  }

  // optional string email = 4;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->email(), target);
  }

  // repeated uint32 available_region = 5;
  for (int i = 0; i < this->available_region_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32ToArray(5, this->available_region(i), target);
  }

  // optional uint32 connected_region = 6;
  if (has_connected_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->connected_region(), target);
  }

  // optional string battle_tag = 7;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->battle_tag(), target);
  }

  // optional string geoip_country = 8;
  if (has_geoip_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->geoip_country().data(), this->geoip_country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "geoip_country");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->geoip_country(), target);
  }

  // optional bytes session_key = 9;
  if (has_session_key()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        9, this->session_key(), target);
  }

  // optional bool restricted_mode = 10;
  if (has_restricted_mode()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(10, this->restricted_mode(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.LogonResult)
  return target;
}

int LogonResult::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 error_code = 1;
    if (has_error_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->error_code());
    }

    // optional .bgs.protocol.EntityId account_id = 2;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional string email = 4;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

    // optional uint32 connected_region = 6;
    if (has_connected_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->connected_region());
    }

    // optional string battle_tag = 7;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional string geoip_country = 8;
    if (has_geoip_country()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->geoip_country());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bytes session_key = 9;
    if (has_session_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->session_key());
    }

    // optional bool restricted_mode = 10;
    if (has_restricted_mode()) {
      total_size += 1 + 1;
    }

  }
  // repeated .bgs.protocol.EntityId game_account_id = 3;
  total_size += 1 * this->game_account_id_size();
  for (int i = 0; i < this->game_account_id_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_account_id(i));
  }

  // repeated uint32 available_region = 5;
  {
    int data_size = 0;
    for (int i = 0; i < this->available_region_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->available_region(i));
    }
    total_size += 1 * this->available_region_size() + data_size;
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

void LogonResult::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogonResult* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogonResult*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogonResult::MergeFrom(const LogonResult& from) {
  GOOGLE_CHECK_NE(&from, this);
  game_account_id_.MergeFrom(from.game_account_id_);
  available_region_.MergeFrom(from.available_region_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error_code()) {
      set_error_code(from.error_code());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
    if (from.has_connected_region()) {
      set_connected_region(from.connected_region());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_geoip_country()) {
      set_geoip_country(from.geoip_country());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_session_key()) {
      set_session_key(from.session_key());
    }
    if (from.has_restricted_mode()) {
      set_restricted_mode(from.restricted_mode());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogonResult::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogonResult::CopyFrom(const LogonResult& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogonResult::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->game_account_id())) return false;
  return true;
}

void LogonResult::Swap(LogonResult* other) {
  if (other != this) {
    std::swap(error_code_, other->error_code_);
    std::swap(account_id_, other->account_id_);
    game_account_id_.Swap(&other->game_account_id_);
    std::swap(email_, other->email_);
    available_region_.Swap(&other->available_region_);
    std::swap(connected_region_, other->connected_region_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(geoip_country_, other->geoip_country_);
    std::swap(session_key_, other->session_key_);
    std::swap(restricted_mode_, other->restricted_mode_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogonResult::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogonResult_descriptor_;
  metadata.reflection = LogonResult_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenerateSSOTokenRequest::kProgramFieldNumber;
#endif  // !_MSC_VER

GenerateSSOTokenRequest::GenerateSSOTokenRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
}

void GenerateSSOTokenRequest::InitAsDefaultInstance() {
}

GenerateSSOTokenRequest::GenerateSSOTokenRequest(const GenerateSSOTokenRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
}

void GenerateSSOTokenRequest::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenerateSSOTokenRequest::~GenerateSSOTokenRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  SharedDtor();
}

void GenerateSSOTokenRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GenerateSSOTokenRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenerateSSOTokenRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenerateSSOTokenRequest_descriptor_;
}

const GenerateSSOTokenRequest& GenerateSSOTokenRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

GenerateSSOTokenRequest* GenerateSSOTokenRequest::default_instance_ = NULL;

GenerateSSOTokenRequest* GenerateSSOTokenRequest::New() const {
  return new GenerateSSOTokenRequest;
}

void GenerateSSOTokenRequest::Clear() {
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenerateSSOTokenRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 program = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  return false;
#undef DO_
}

void GenerateSSOTokenRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  // optional fixed32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
}

::google::protobuf::uint8* GenerateSSOTokenRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  // optional fixed32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.GenerateSSOTokenRequest)
  return target;
}

int GenerateSSOTokenRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 program = 1;
    if (has_program()) {
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

void GenerateSSOTokenRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenerateSSOTokenRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenerateSSOTokenRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenerateSSOTokenRequest::MergeFrom(const GenerateSSOTokenRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenerateSSOTokenRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenerateSSOTokenRequest::CopyFrom(const GenerateSSOTokenRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenerateSSOTokenRequest::IsInitialized() const {

  return true;
}

void GenerateSSOTokenRequest::Swap(GenerateSSOTokenRequest* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenerateSSOTokenRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenerateSSOTokenRequest_descriptor_;
  metadata.reflection = GenerateSSOTokenRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenerateSSOTokenResponse::kSsoIdFieldNumber;
const int GenerateSSOTokenResponse::kSsoSecretFieldNumber;
#endif  // !_MSC_VER

GenerateSSOTokenResponse::GenerateSSOTokenResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
}

void GenerateSSOTokenResponse::InitAsDefaultInstance() {
}

GenerateSSOTokenResponse::GenerateSSOTokenResponse(const GenerateSSOTokenResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
}

void GenerateSSOTokenResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  sso_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sso_secret_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenerateSSOTokenResponse::~GenerateSSOTokenResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  SharedDtor();
}

void GenerateSSOTokenResponse::SharedDtor() {
  if (sso_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sso_id_;
  }
  if (sso_secret_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sso_secret_;
  }
  if (this != default_instance_) {
  }
}

void GenerateSSOTokenResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenerateSSOTokenResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenerateSSOTokenResponse_descriptor_;
}

const GenerateSSOTokenResponse& GenerateSSOTokenResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

GenerateSSOTokenResponse* GenerateSSOTokenResponse::default_instance_ = NULL;

GenerateSSOTokenResponse* GenerateSSOTokenResponse::New() const {
  return new GenerateSSOTokenResponse;
}

void GenerateSSOTokenResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_sso_id()) {
      if (sso_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sso_id_->clear();
      }
    }
    if (has_sso_secret()) {
      if (sso_secret_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sso_secret_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenerateSSOTokenResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes sso_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_sso_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_sso_secret;
        break;
      }

      // optional bytes sso_secret = 2;
      case 2: {
        if (tag == 18) {
         parse_sso_secret:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_sso_secret()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  return false;
#undef DO_
}

void GenerateSSOTokenResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  // optional bytes sso_id = 1;
  if (has_sso_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->sso_id(), output);
  }

  // optional bytes sso_secret = 2;
  if (has_sso_secret()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->sso_secret(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
}

::google::protobuf::uint8* GenerateSSOTokenResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  // optional bytes sso_id = 1;
  if (has_sso_id()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->sso_id(), target);
  }

  // optional bytes sso_secret = 2;
  if (has_sso_secret()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->sso_secret(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.GenerateSSOTokenResponse)
  return target;
}

int GenerateSSOTokenResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes sso_id = 1;
    if (has_sso_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->sso_id());
    }

    // optional bytes sso_secret = 2;
    if (has_sso_secret()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->sso_secret());
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

void GenerateSSOTokenResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenerateSSOTokenResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenerateSSOTokenResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenerateSSOTokenResponse::MergeFrom(const GenerateSSOTokenResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sso_id()) {
      set_sso_id(from.sso_id());
    }
    if (from.has_sso_secret()) {
      set_sso_secret(from.sso_secret());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenerateSSOTokenResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenerateSSOTokenResponse::CopyFrom(const GenerateSSOTokenResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenerateSSOTokenResponse::IsInitialized() const {

  return true;
}

void GenerateSSOTokenResponse::Swap(GenerateSSOTokenResponse* other) {
  if (other != this) {
    std::swap(sso_id_, other->sso_id_);
    std::swap(sso_secret_, other->sso_secret_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenerateSSOTokenResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenerateSSOTokenResponse_descriptor_;
  metadata.reflection = GenerateSSOTokenResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int LogonUpdateRequest::kErrorCodeFieldNumber;
#endif  // !_MSC_VER

LogonUpdateRequest::LogonUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.LogonUpdateRequest)
}

void LogonUpdateRequest::InitAsDefaultInstance() {
}

LogonUpdateRequest::LogonUpdateRequest(const LogonUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.LogonUpdateRequest)
}

void LogonUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  error_code_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogonUpdateRequest::~LogonUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.LogonUpdateRequest)
  SharedDtor();
}

void LogonUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void LogonUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogonUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogonUpdateRequest_descriptor_;
}

const LogonUpdateRequest& LogonUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

LogonUpdateRequest* LogonUpdateRequest::default_instance_ = NULL;

LogonUpdateRequest* LogonUpdateRequest::New() const {
  return new LogonUpdateRequest;
}

void LogonUpdateRequest::Clear() {
  error_code_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogonUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.LogonUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 error_code = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &error_code_)));
          set_has_error_code();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.LogonUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.LogonUpdateRequest)
  return false;
#undef DO_
}

void LogonUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.LogonUpdateRequest)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->error_code(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.LogonUpdateRequest)
}

::google::protobuf::uint8* LogonUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.LogonUpdateRequest)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->error_code(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.LogonUpdateRequest)
  return target;
}

int LogonUpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 error_code = 1;
    if (has_error_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->error_code());
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

void LogonUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogonUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogonUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogonUpdateRequest::MergeFrom(const LogonUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error_code()) {
      set_error_code(from.error_code());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogonUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogonUpdateRequest::CopyFrom(const LogonUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogonUpdateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void LogonUpdateRequest::Swap(LogonUpdateRequest* other) {
  if (other != this) {
    std::swap(error_code_, other->error_code_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogonUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogonUpdateRequest_descriptor_;
  metadata.reflection = LogonUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int LogonQueueUpdateRequest::kPositionFieldNumber;
const int LogonQueueUpdateRequest::kEstimatedTimeFieldNumber;
const int LogonQueueUpdateRequest::kEtaDeviationInSecFieldNumber;
#endif  // !_MSC_VER

LogonQueueUpdateRequest::LogonQueueUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
}

void LogonQueueUpdateRequest::InitAsDefaultInstance() {
}

LogonQueueUpdateRequest::LogonQueueUpdateRequest(const LogonQueueUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
}

void LogonQueueUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  position_ = 0u;
  estimated_time_ = GOOGLE_ULONGLONG(0);
  eta_deviation_in_sec_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogonQueueUpdateRequest::~LogonQueueUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  SharedDtor();
}

void LogonQueueUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void LogonQueueUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogonQueueUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogonQueueUpdateRequest_descriptor_;
}

const LogonQueueUpdateRequest& LogonQueueUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

LogonQueueUpdateRequest* LogonQueueUpdateRequest::default_instance_ = NULL;

LogonQueueUpdateRequest* LogonQueueUpdateRequest::New() const {
  return new LogonQueueUpdateRequest;
}

void LogonQueueUpdateRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<LogonQueueUpdateRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(estimated_time_, position_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogonQueueUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 position = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &position_)));
          set_has_position();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_estimated_time;
        break;
      }

      // required uint64 estimated_time = 2;
      case 2: {
        if (tag == 16) {
         parse_estimated_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &estimated_time_)));
          set_has_estimated_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_eta_deviation_in_sec;
        break;
      }

      // required uint64 eta_deviation_in_sec = 3;
      case 3: {
        if (tag == 24) {
         parse_eta_deviation_in_sec:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &eta_deviation_in_sec_)));
          set_has_eta_deviation_in_sec();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  return false;
#undef DO_
}

void LogonQueueUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  // required uint32 position = 1;
  if (has_position()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->position(), output);
  }

  // required uint64 estimated_time = 2;
  if (has_estimated_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->estimated_time(), output);
  }

  // required uint64 eta_deviation_in_sec = 3;
  if (has_eta_deviation_in_sec()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->eta_deviation_in_sec(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
}

::google::protobuf::uint8* LogonQueueUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  // required uint32 position = 1;
  if (has_position()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->position(), target);
  }

  // required uint64 estimated_time = 2;
  if (has_estimated_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->estimated_time(), target);
  }

  // required uint64 eta_deviation_in_sec = 3;
  if (has_eta_deviation_in_sec()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->eta_deviation_in_sec(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.LogonQueueUpdateRequest)
  return target;
}

int LogonQueueUpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 position = 1;
    if (has_position()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->position());
    }

    // required uint64 estimated_time = 2;
    if (has_estimated_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->estimated_time());
    }

    // required uint64 eta_deviation_in_sec = 3;
    if (has_eta_deviation_in_sec()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->eta_deviation_in_sec());
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

void LogonQueueUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogonQueueUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogonQueueUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogonQueueUpdateRequest::MergeFrom(const LogonQueueUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_position()) {
      set_position(from.position());
    }
    if (from.has_estimated_time()) {
      set_estimated_time(from.estimated_time());
    }
    if (from.has_eta_deviation_in_sec()) {
      set_eta_deviation_in_sec(from.eta_deviation_in_sec());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogonQueueUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogonQueueUpdateRequest::CopyFrom(const LogonQueueUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogonQueueUpdateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void LogonQueueUpdateRequest::Swap(LogonQueueUpdateRequest* other) {
  if (other != this) {
    std::swap(position_, other->position_);
    std::swap(estimated_time_, other->estimated_time_);
    std::swap(eta_deviation_in_sec_, other->eta_deviation_in_sec_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogonQueueUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogonQueueUpdateRequest_descriptor_;
  metadata.reflection = LogonQueueUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountSettingsNotification::kLicensesFieldNumber;
const int AccountSettingsNotification::kIsUsingRidFieldNumber;
const int AccountSettingsNotification::kIsPlayingFromIgrFieldNumber;
const int AccountSettingsNotification::kCanReceiveVoiceFieldNumber;
const int AccountSettingsNotification::kCanSendVoiceFieldNumber;
#endif  // !_MSC_VER

AccountSettingsNotification::AccountSettingsNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.AccountSettingsNotification)
}

void AccountSettingsNotification::InitAsDefaultInstance() {
}

AccountSettingsNotification::AccountSettingsNotification(const AccountSettingsNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.AccountSettingsNotification)
}

void AccountSettingsNotification::SharedCtor() {
  _cached_size_ = 0;
  is_using_rid_ = false;
  is_playing_from_igr_ = false;
  can_receive_voice_ = false;
  can_send_voice_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountSettingsNotification::~AccountSettingsNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.AccountSettingsNotification)
  SharedDtor();
}

void AccountSettingsNotification::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountSettingsNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountSettingsNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountSettingsNotification_descriptor_;
}

const AccountSettingsNotification& AccountSettingsNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

AccountSettingsNotification* AccountSettingsNotification::default_instance_ = NULL;

AccountSettingsNotification* AccountSettingsNotification::New() const {
  return new AccountSettingsNotification;
}

void AccountSettingsNotification::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountSettingsNotification*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(is_using_rid_, can_send_voice_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  licenses_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountSettingsNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.AccountSettingsNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
      case 1: {
        if (tag == 10) {
         parse_licenses:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_licenses()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_licenses;
        if (input->ExpectTag(16)) goto parse_is_using_rid;
        break;
      }

      // optional bool is_using_rid = 2;
      case 2: {
        if (tag == 16) {
         parse_is_using_rid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_using_rid_)));
          set_has_is_using_rid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_is_playing_from_igr;
        break;
      }

      // optional bool is_playing_from_igr = 3;
      case 3: {
        if (tag == 24) {
         parse_is_playing_from_igr:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_playing_from_igr_)));
          set_has_is_playing_from_igr();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_can_receive_voice;
        break;
      }

      // optional bool can_receive_voice = 4;
      case 4: {
        if (tag == 32) {
         parse_can_receive_voice:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &can_receive_voice_)));
          set_has_can_receive_voice();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_can_send_voice;
        break;
      }

      // optional bool can_send_voice = 5;
      case 5: {
        if (tag == 40) {
         parse_can_send_voice:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &can_send_voice_)));
          set_has_can_send_voice();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.AccountSettingsNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.AccountSettingsNotification)
  return false;
#undef DO_
}

void AccountSettingsNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.AccountSettingsNotification)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->licenses(i), output);
  }

  // optional bool is_using_rid = 2;
  if (has_is_using_rid()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->is_using_rid(), output);
  }

  // optional bool is_playing_from_igr = 3;
  if (has_is_playing_from_igr()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->is_playing_from_igr(), output);
  }

  // optional bool can_receive_voice = 4;
  if (has_can_receive_voice()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->can_receive_voice(), output);
  }

  // optional bool can_send_voice = 5;
  if (has_can_send_voice()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->can_send_voice(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.AccountSettingsNotification)
}

::google::protobuf::uint8* AccountSettingsNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.AccountSettingsNotification)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->licenses(i), target);
  }

  // optional bool is_using_rid = 2;
  if (has_is_using_rid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->is_using_rid(), target);
  }

  // optional bool is_playing_from_igr = 3;
  if (has_is_playing_from_igr()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->is_playing_from_igr(), target);
  }

  // optional bool can_receive_voice = 4;
  if (has_can_receive_voice()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->can_receive_voice(), target);
  }

  // optional bool can_send_voice = 5;
  if (has_can_send_voice()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->can_send_voice(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.AccountSettingsNotification)
  return target;
}

int AccountSettingsNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional bool is_using_rid = 2;
    if (has_is_using_rid()) {
      total_size += 1 + 1;
    }

    // optional bool is_playing_from_igr = 3;
    if (has_is_playing_from_igr()) {
      total_size += 1 + 1;
    }

    // optional bool can_receive_voice = 4;
    if (has_can_receive_voice()) {
      total_size += 1 + 1;
    }

    // optional bool can_send_voice = 5;
    if (has_can_send_voice()) {
      total_size += 1 + 1;
    }

  }
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
  total_size += 1 * this->licenses_size();
  for (int i = 0; i < this->licenses_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->licenses(i));
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

void AccountSettingsNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountSettingsNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountSettingsNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountSettingsNotification::MergeFrom(const AccountSettingsNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  licenses_.MergeFrom(from.licenses_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_is_using_rid()) {
      set_is_using_rid(from.is_using_rid());
    }
    if (from.has_is_playing_from_igr()) {
      set_is_playing_from_igr(from.is_playing_from_igr());
    }
    if (from.has_can_receive_voice()) {
      set_can_receive_voice(from.can_receive_voice());
    }
    if (from.has_can_send_voice()) {
      set_can_send_voice(from.can_send_voice());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountSettingsNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountSettingsNotification::CopyFrom(const AccountSettingsNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountSettingsNotification::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  return true;
}

void AccountSettingsNotification::Swap(AccountSettingsNotification* other) {
  if (other != this) {
    licenses_.Swap(&other->licenses_);
    std::swap(is_using_rid_, other->is_using_rid_);
    std::swap(is_playing_from_igr_, other->is_playing_from_igr_);
    std::swap(can_receive_voice_, other->can_receive_voice_);
    std::swap(can_send_voice_, other->can_send_voice_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountSettingsNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountSettingsNotification_descriptor_;
  metadata.reflection = AccountSettingsNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ServerStateChangeRequest::kStateFieldNumber;
const int ServerStateChangeRequest::kEventTimeFieldNumber;
#endif  // !_MSC_VER

ServerStateChangeRequest::ServerStateChangeRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.ServerStateChangeRequest)
}

void ServerStateChangeRequest::InitAsDefaultInstance() {
}

ServerStateChangeRequest::ServerStateChangeRequest(const ServerStateChangeRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.ServerStateChangeRequest)
}

void ServerStateChangeRequest::SharedCtor() {
  _cached_size_ = 0;
  state_ = 0u;
  event_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ServerStateChangeRequest::~ServerStateChangeRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  SharedDtor();
}

void ServerStateChangeRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ServerStateChangeRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServerStateChangeRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerStateChangeRequest_descriptor_;
}

const ServerStateChangeRequest& ServerStateChangeRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

ServerStateChangeRequest* ServerStateChangeRequest::default_instance_ = NULL;

ServerStateChangeRequest* ServerStateChangeRequest::New() const {
  return new ServerStateChangeRequest;
}

void ServerStateChangeRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ServerStateChangeRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(event_time_, state_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ServerStateChangeRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 state = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &state_)));
          set_has_state();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_event_time;
        break;
      }

      // required uint64 event_time = 2;
      case 2: {
        if (tag == 16) {
         parse_event_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &event_time_)));
          set_has_event_time();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  return false;
#undef DO_
}

void ServerStateChangeRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  // required uint32 state = 1;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->state(), output);
  }

  // required uint64 event_time = 2;
  if (has_event_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->event_time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.ServerStateChangeRequest)
}

::google::protobuf::uint8* ServerStateChangeRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  // required uint32 state = 1;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->state(), target);
  }

  // required uint64 event_time = 2;
  if (has_event_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->event_time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.ServerStateChangeRequest)
  return target;
}

int ServerStateChangeRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 state = 1;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->state());
    }

    // required uint64 event_time = 2;
    if (has_event_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->event_time());
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

void ServerStateChangeRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ServerStateChangeRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ServerStateChangeRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ServerStateChangeRequest::MergeFrom(const ServerStateChangeRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_state()) {
      set_state(from.state());
    }
    if (from.has_event_time()) {
      set_event_time(from.event_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ServerStateChangeRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServerStateChangeRequest::CopyFrom(const ServerStateChangeRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ServerStateChangeRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void ServerStateChangeRequest::Swap(ServerStateChangeRequest* other) {
  if (other != this) {
    std::swap(state_, other->state_);
    std::swap(event_time_, other->event_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ServerStateChangeRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServerStateChangeRequest_descriptor_;
  metadata.reflection = ServerStateChangeRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int VersionInfo::kNumberFieldNumber;
const int VersionInfo::kPatchFieldNumber;
const int VersionInfo::kIsOptionalFieldNumber;
const int VersionInfo::kKickTimeFieldNumber;
#endif  // !_MSC_VER

VersionInfo::VersionInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.VersionInfo)
}

void VersionInfo::InitAsDefaultInstance() {
}

VersionInfo::VersionInfo(const VersionInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.VersionInfo)
}

void VersionInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  number_ = 0u;
  patch_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  is_optional_ = false;
  kick_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

VersionInfo::~VersionInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.VersionInfo)
  SharedDtor();
}

void VersionInfo::SharedDtor() {
  if (patch_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete patch_;
  }
  if (this != default_instance_) {
  }
}

void VersionInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VersionInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VersionInfo_descriptor_;
}

const VersionInfo& VersionInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

VersionInfo* VersionInfo::default_instance_ = NULL;

VersionInfo* VersionInfo::New() const {
  return new VersionInfo;
}

void VersionInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<VersionInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(number_, kick_time_);
    if (has_patch()) {
      if (patch_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        patch_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool VersionInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.VersionInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 number = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &number_)));
          set_has_number();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_patch;
        break;
      }

      // optional string patch = 2;
      case 2: {
        if (tag == 18) {
         parse_patch:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_patch()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->patch().data(), this->patch().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "patch");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_is_optional;
        break;
      }

      // optional bool is_optional = 3;
      case 3: {
        if (tag == 24) {
         parse_is_optional:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_optional_)));
          set_has_is_optional();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_kick_time;
        break;
      }

      // optional uint64 kick_time = 4;
      case 4: {
        if (tag == 32) {
         parse_kick_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &kick_time_)));
          set_has_kick_time();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.VersionInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.VersionInfo)
  return false;
#undef DO_
}

void VersionInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.VersionInfo)
  // optional uint32 number = 1;
  if (has_number()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->number(), output);
  }

  // optional string patch = 2;
  if (has_patch()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->patch().data(), this->patch().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "patch");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->patch(), output);
  }

  // optional bool is_optional = 3;
  if (has_is_optional()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->is_optional(), output);
  }

  // optional uint64 kick_time = 4;
  if (has_kick_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->kick_time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.VersionInfo)
}

::google::protobuf::uint8* VersionInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.VersionInfo)
  // optional uint32 number = 1;
  if (has_number()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->number(), target);
  }

  // optional string patch = 2;
  if (has_patch()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->patch().data(), this->patch().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "patch");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->patch(), target);
  }

  // optional bool is_optional = 3;
  if (has_is_optional()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->is_optional(), target);
  }

  // optional uint64 kick_time = 4;
  if (has_kick_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->kick_time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.VersionInfo)
  return target;
}

int VersionInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 number = 1;
    if (has_number()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->number());
    }

    // optional string patch = 2;
    if (has_patch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->patch());
    }

    // optional bool is_optional = 3;
    if (has_is_optional()) {
      total_size += 1 + 1;
    }

    // optional uint64 kick_time = 4;
    if (has_kick_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->kick_time());
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

void VersionInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const VersionInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const VersionInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VersionInfo::MergeFrom(const VersionInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_number()) {
      set_number(from.number());
    }
    if (from.has_patch()) {
      set_patch(from.patch());
    }
    if (from.has_is_optional()) {
      set_is_optional(from.is_optional());
    }
    if (from.has_kick_time()) {
      set_kick_time(from.kick_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void VersionInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VersionInfo::CopyFrom(const VersionInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VersionInfo::IsInitialized() const {

  return true;
}

void VersionInfo::Swap(VersionInfo* other) {
  if (other != this) {
    std::swap(number_, other->number_);
    std::swap(patch_, other->patch_);
    std::swap(is_optional_, other->is_optional_);
    std::swap(kick_time_, other->kick_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata VersionInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VersionInfo_descriptor_;
  metadata.reflection = VersionInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int VersionInfoNotification::kVersionInfoFieldNumber;
#endif  // !_MSC_VER

VersionInfoNotification::VersionInfoNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.VersionInfoNotification)
}

void VersionInfoNotification::InitAsDefaultInstance() {
  version_info_ = const_cast< ::bgs::protocol::authentication::v1::VersionInfo*>(&::bgs::protocol::authentication::v1::VersionInfo::default_instance());
}

VersionInfoNotification::VersionInfoNotification(const VersionInfoNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.VersionInfoNotification)
}

void VersionInfoNotification::SharedCtor() {
  _cached_size_ = 0;
  version_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

VersionInfoNotification::~VersionInfoNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.VersionInfoNotification)
  SharedDtor();
}

void VersionInfoNotification::SharedDtor() {
  if (this != default_instance_) {
    delete version_info_;
  }
}

void VersionInfoNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VersionInfoNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VersionInfoNotification_descriptor_;
}

const VersionInfoNotification& VersionInfoNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

VersionInfoNotification* VersionInfoNotification::default_instance_ = NULL;

VersionInfoNotification* VersionInfoNotification::New() const {
  return new VersionInfoNotification;
}

void VersionInfoNotification::Clear() {
  if (has_version_info()) {
    if (version_info_ != NULL) version_info_->::bgs::protocol::authentication::v1::VersionInfo::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool VersionInfoNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.VersionInfoNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.authentication.v1.VersionInfo version_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_version_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.VersionInfoNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.VersionInfoNotification)
  return false;
#undef DO_
}

void VersionInfoNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.VersionInfoNotification)
  // optional .bgs.protocol.authentication.v1.VersionInfo version_info = 1;
  if (has_version_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->version_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.VersionInfoNotification)
}

::google::protobuf::uint8* VersionInfoNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.VersionInfoNotification)
  // optional .bgs.protocol.authentication.v1.VersionInfo version_info = 1;
  if (has_version_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->version_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.VersionInfoNotification)
  return target;
}

int VersionInfoNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.authentication.v1.VersionInfo version_info = 1;
    if (has_version_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->version_info());
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

void VersionInfoNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const VersionInfoNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const VersionInfoNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VersionInfoNotification::MergeFrom(const VersionInfoNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_version_info()) {
      mutable_version_info()->::bgs::protocol::authentication::v1::VersionInfo::MergeFrom(from.version_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void VersionInfoNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VersionInfoNotification::CopyFrom(const VersionInfoNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VersionInfoNotification::IsInitialized() const {

  return true;
}

void VersionInfoNotification::Swap(VersionInfoNotification* other) {
  if (other != this) {
    std::swap(version_info_, other->version_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata VersionInfoNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VersionInfoNotification_descriptor_;
  metadata.reflection = VersionInfoNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemModuleLoadRequest::kHandleFieldNumber;
const int MemModuleLoadRequest::kKeyFieldNumber;
const int MemModuleLoadRequest::kInputFieldNumber;
#endif  // !_MSC_VER

MemModuleLoadRequest::MemModuleLoadRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.MemModuleLoadRequest)
}

void MemModuleLoadRequest::InitAsDefaultInstance() {
  handle_ = const_cast< ::bgs::protocol::ContentHandle*>(&::bgs::protocol::ContentHandle::default_instance());
}

MemModuleLoadRequest::MemModuleLoadRequest(const MemModuleLoadRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.MemModuleLoadRequest)
}

void MemModuleLoadRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  handle_ = NULL;
  key_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  input_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemModuleLoadRequest::~MemModuleLoadRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  SharedDtor();
}

void MemModuleLoadRequest::SharedDtor() {
  if (key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete key_;
  }
  if (input_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete input_;
  }
  if (this != default_instance_) {
    delete handle_;
  }
}

void MemModuleLoadRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemModuleLoadRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemModuleLoadRequest_descriptor_;
}

const MemModuleLoadRequest& MemModuleLoadRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

MemModuleLoadRequest* MemModuleLoadRequest::default_instance_ = NULL;

MemModuleLoadRequest* MemModuleLoadRequest::New() const {
  return new MemModuleLoadRequest;
}

void MemModuleLoadRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_handle()) {
      if (handle_ != NULL) handle_->::bgs::protocol::ContentHandle::Clear();
    }
    if (has_key()) {
      if (key_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        key_->clear();
      }
    }
    if (has_input()) {
      if (input_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        input_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemModuleLoadRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.ContentHandle handle = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_key;
        break;
      }

      // required bytes key = 2;
      case 2: {
        if (tag == 18) {
         parse_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_key()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_input;
        break;
      }

      // required bytes input = 3;
      case 3: {
        if (tag == 26) {
         parse_input:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_input()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  return false;
#undef DO_
}

void MemModuleLoadRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  // required .bgs.protocol.ContentHandle handle = 1;
  if (has_handle()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->handle(), output);
  }

  // required bytes key = 2;
  if (has_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->key(), output);
  }

  // required bytes input = 3;
  if (has_input()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->input(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.MemModuleLoadRequest)
}

::google::protobuf::uint8* MemModuleLoadRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  // required .bgs.protocol.ContentHandle handle = 1;
  if (has_handle()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->handle(), target);
  }

  // required bytes key = 2;
  if (has_key()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->key(), target);
  }

  // required bytes input = 3;
  if (has_input()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->input(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.MemModuleLoadRequest)
  return target;
}

int MemModuleLoadRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.ContentHandle handle = 1;
    if (has_handle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->handle());
    }

    // required bytes key = 2;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->key());
    }

    // required bytes input = 3;
    if (has_input()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->input());
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

void MemModuleLoadRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemModuleLoadRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemModuleLoadRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemModuleLoadRequest::MergeFrom(const MemModuleLoadRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_handle()) {
      mutable_handle()->::bgs::protocol::ContentHandle::MergeFrom(from.handle());
    }
    if (from.has_key()) {
      set_key(from.key());
    }
    if (from.has_input()) {
      set_input(from.input());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemModuleLoadRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemModuleLoadRequest::CopyFrom(const MemModuleLoadRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemModuleLoadRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  if (has_handle()) {
    if (!this->handle().IsInitialized()) return false;
  }
  return true;
}

void MemModuleLoadRequest::Swap(MemModuleLoadRequest* other) {
  if (other != this) {
    std::swap(handle_, other->handle_);
    std::swap(key_, other->key_);
    std::swap(input_, other->input_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemModuleLoadRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemModuleLoadRequest_descriptor_;
  metadata.reflection = MemModuleLoadRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MemModuleLoadResponse::kDataFieldNumber;
#endif  // !_MSC_VER

MemModuleLoadResponse::MemModuleLoadResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.MemModuleLoadResponse)
}

void MemModuleLoadResponse::InitAsDefaultInstance() {
}

MemModuleLoadResponse::MemModuleLoadResponse(const MemModuleLoadResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.MemModuleLoadResponse)
}

void MemModuleLoadResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MemModuleLoadResponse::~MemModuleLoadResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  SharedDtor();
}

void MemModuleLoadResponse::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void MemModuleLoadResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MemModuleLoadResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MemModuleLoadResponse_descriptor_;
}

const MemModuleLoadResponse& MemModuleLoadResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

MemModuleLoadResponse* MemModuleLoadResponse::default_instance_ = NULL;

MemModuleLoadResponse* MemModuleLoadResponse::New() const {
  return new MemModuleLoadResponse;
}

void MemModuleLoadResponse::Clear() {
  if (has_data()) {
    if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      data_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MemModuleLoadResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes data = 1;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  return false;
#undef DO_
}

void MemModuleLoadResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  // required bytes data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.MemModuleLoadResponse)
}

::google::protobuf::uint8* MemModuleLoadResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  // required bytes data = 1;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.MemModuleLoadResponse)
  return target;
}

int MemModuleLoadResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes data = 1;
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

void MemModuleLoadResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MemModuleLoadResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MemModuleLoadResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MemModuleLoadResponse::MergeFrom(const MemModuleLoadResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MemModuleLoadResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemModuleLoadResponse::CopyFrom(const MemModuleLoadResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemModuleLoadResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void MemModuleLoadResponse::Swap(MemModuleLoadResponse* other) {
  if (other != this) {
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MemModuleLoadResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MemModuleLoadResponse_descriptor_;
  metadata.reflection = MemModuleLoadResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SelectGameAccountRequest::kGameAccountIdFieldNumber;
#endif  // !_MSC_VER

SelectGameAccountRequest::SelectGameAccountRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.SelectGameAccountRequest)
}

void SelectGameAccountRequest::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

SelectGameAccountRequest::SelectGameAccountRequest(const SelectGameAccountRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.SelectGameAccountRequest)
}

void SelectGameAccountRequest::SharedCtor() {
  _cached_size_ = 0;
  game_account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SelectGameAccountRequest::~SelectGameAccountRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  SharedDtor();
}

void SelectGameAccountRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_id_;
  }
}

void SelectGameAccountRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SelectGameAccountRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SelectGameAccountRequest_descriptor_;
}

const SelectGameAccountRequest& SelectGameAccountRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

SelectGameAccountRequest* SelectGameAccountRequest::default_instance_ = NULL;

SelectGameAccountRequest* SelectGameAccountRequest::New() const {
  return new SelectGameAccountRequest;
}

void SelectGameAccountRequest::Clear() {
  if (has_game_account_id()) {
    if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SelectGameAccountRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.EntityId game_account_id = 1;
      case 1: {
        if (tag == 10) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  return false;
#undef DO_
}

void SelectGameAccountRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.SelectGameAccountRequest)
}

::google::protobuf::uint8* SelectGameAccountRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  // required .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.SelectGameAccountRequest)
  return target;
}

int SelectGameAccountRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.EntityId game_account_id = 1;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
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

void SelectGameAccountRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SelectGameAccountRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SelectGameAccountRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SelectGameAccountRequest::MergeFrom(const SelectGameAccountRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SelectGameAccountRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SelectGameAccountRequest::CopyFrom(const SelectGameAccountRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SelectGameAccountRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void SelectGameAccountRequest::Swap(SelectGameAccountRequest* other) {
  if (other != this) {
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SelectGameAccountRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SelectGameAccountRequest_descriptor_;
  metadata.reflection = SelectGameAccountRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountSelectedRequest::kResultFieldNumber;
const int GameAccountSelectedRequest::kGameAccountIdFieldNumber;
#endif  // !_MSC_VER

GameAccountSelectedRequest::GameAccountSelectedRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
}

void GameAccountSelectedRequest::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GameAccountSelectedRequest::GameAccountSelectedRequest(const GameAccountSelectedRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
}

void GameAccountSelectedRequest::SharedCtor() {
  _cached_size_ = 0;
  result_ = 0u;
  game_account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountSelectedRequest::~GameAccountSelectedRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  SharedDtor();
}

void GameAccountSelectedRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_id_;
  }
}

void GameAccountSelectedRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountSelectedRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountSelectedRequest_descriptor_;
}

const GameAccountSelectedRequest& GameAccountSelectedRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

GameAccountSelectedRequest* GameAccountSelectedRequest::default_instance_ = NULL;

GameAccountSelectedRequest* GameAccountSelectedRequest::New() const {
  return new GameAccountSelectedRequest;
}

void GameAccountSelectedRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    result_ = 0u;
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountSelectedRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 result = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &result_)));
          set_has_result();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  return false;
#undef DO_
}

void GameAccountSelectedRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  // required uint32 result = 1;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->result(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
}

::google::protobuf::uint8* GameAccountSelectedRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  // required uint32 result = 1;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->result(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.GameAccountSelectedRequest)
  return target;
}

int GameAccountSelectedRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 result = 1;
    if (has_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->result());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
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

void GameAccountSelectedRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountSelectedRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountSelectedRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountSelectedRequest::MergeFrom(const GameAccountSelectedRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_result()) {
      set_result(from.result());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountSelectedRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountSelectedRequest::CopyFrom(const GameAccountSelectedRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountSelectedRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void GameAccountSelectedRequest::Swap(GameAccountSelectedRequest* other) {
  if (other != this) {
    std::swap(result_, other->result_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountSelectedRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountSelectedRequest_descriptor_;
  metadata.reflection = GameAccountSelectedRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenerateWebCredentialsRequest::kProgramFieldNumber;
#endif  // !_MSC_VER

GenerateWebCredentialsRequest::GenerateWebCredentialsRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
}

void GenerateWebCredentialsRequest::InitAsDefaultInstance() {
}

GenerateWebCredentialsRequest::GenerateWebCredentialsRequest(const GenerateWebCredentialsRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
}

void GenerateWebCredentialsRequest::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenerateWebCredentialsRequest::~GenerateWebCredentialsRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  SharedDtor();
}

void GenerateWebCredentialsRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GenerateWebCredentialsRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenerateWebCredentialsRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenerateWebCredentialsRequest_descriptor_;
}

const GenerateWebCredentialsRequest& GenerateWebCredentialsRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

GenerateWebCredentialsRequest* GenerateWebCredentialsRequest::default_instance_ = NULL;

GenerateWebCredentialsRequest* GenerateWebCredentialsRequest::New() const {
  return new GenerateWebCredentialsRequest;
}

void GenerateWebCredentialsRequest::Clear() {
  program_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenerateWebCredentialsRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 program = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  return false;
#undef DO_
}

void GenerateWebCredentialsRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  // optional fixed32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
}

::google::protobuf::uint8* GenerateWebCredentialsRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  // optional fixed32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.GenerateWebCredentialsRequest)
  return target;
}

int GenerateWebCredentialsRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 program = 1;
    if (has_program()) {
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

void GenerateWebCredentialsRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenerateWebCredentialsRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenerateWebCredentialsRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenerateWebCredentialsRequest::MergeFrom(const GenerateWebCredentialsRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenerateWebCredentialsRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenerateWebCredentialsRequest::CopyFrom(const GenerateWebCredentialsRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenerateWebCredentialsRequest::IsInitialized() const {

  return true;
}

void GenerateWebCredentialsRequest::Swap(GenerateWebCredentialsRequest* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenerateWebCredentialsRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenerateWebCredentialsRequest_descriptor_;
  metadata.reflection = GenerateWebCredentialsRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GenerateWebCredentialsResponse::kWebCredentialsFieldNumber;
#endif  // !_MSC_VER

GenerateWebCredentialsResponse::GenerateWebCredentialsResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
}

void GenerateWebCredentialsResponse::InitAsDefaultInstance() {
}

GenerateWebCredentialsResponse::GenerateWebCredentialsResponse(const GenerateWebCredentialsResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
}

void GenerateWebCredentialsResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  web_credentials_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GenerateWebCredentialsResponse::~GenerateWebCredentialsResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  SharedDtor();
}

void GenerateWebCredentialsResponse::SharedDtor() {
  if (web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete web_credentials_;
  }
  if (this != default_instance_) {
  }
}

void GenerateWebCredentialsResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GenerateWebCredentialsResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GenerateWebCredentialsResponse_descriptor_;
}

const GenerateWebCredentialsResponse& GenerateWebCredentialsResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

GenerateWebCredentialsResponse* GenerateWebCredentialsResponse::default_instance_ = NULL;

GenerateWebCredentialsResponse* GenerateWebCredentialsResponse::New() const {
  return new GenerateWebCredentialsResponse;
}

void GenerateWebCredentialsResponse::Clear() {
  if (has_web_credentials()) {
    if (web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      web_credentials_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GenerateWebCredentialsResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes web_credentials = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_web_credentials()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  return false;
#undef DO_
}

void GenerateWebCredentialsResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  // optional bytes web_credentials = 1;
  if (has_web_credentials()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->web_credentials(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
}

::google::protobuf::uint8* GenerateWebCredentialsResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  // optional bytes web_credentials = 1;
  if (has_web_credentials()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->web_credentials(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.GenerateWebCredentialsResponse)
  return target;
}

int GenerateWebCredentialsResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes web_credentials = 1;
    if (has_web_credentials()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->web_credentials());
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

void GenerateWebCredentialsResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GenerateWebCredentialsResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GenerateWebCredentialsResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GenerateWebCredentialsResponse::MergeFrom(const GenerateWebCredentialsResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_web_credentials()) {
      set_web_credentials(from.web_credentials());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GenerateWebCredentialsResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GenerateWebCredentialsResponse::CopyFrom(const GenerateWebCredentialsResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenerateWebCredentialsResponse::IsInitialized() const {

  return true;
}

void GenerateWebCredentialsResponse::Swap(GenerateWebCredentialsResponse* other) {
  if (other != this) {
    std::swap(web_credentials_, other->web_credentials_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GenerateWebCredentialsResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GenerateWebCredentialsResponse_descriptor_;
  metadata.reflection = GenerateWebCredentialsResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int VerifyWebCredentialsRequest::kWebCredentialsFieldNumber;
#endif  // !_MSC_VER

VerifyWebCredentialsRequest::VerifyWebCredentialsRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
}

void VerifyWebCredentialsRequest::InitAsDefaultInstance() {
}

VerifyWebCredentialsRequest::VerifyWebCredentialsRequest(const VerifyWebCredentialsRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
}

void VerifyWebCredentialsRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  web_credentials_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

VerifyWebCredentialsRequest::~VerifyWebCredentialsRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  SharedDtor();
}

void VerifyWebCredentialsRequest::SharedDtor() {
  if (web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete web_credentials_;
  }
  if (this != default_instance_) {
  }
}

void VerifyWebCredentialsRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VerifyWebCredentialsRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VerifyWebCredentialsRequest_descriptor_;
}

const VerifyWebCredentialsRequest& VerifyWebCredentialsRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_authentication_5fservice_2eproto();
  return *default_instance_;
}

VerifyWebCredentialsRequest* VerifyWebCredentialsRequest::default_instance_ = NULL;

VerifyWebCredentialsRequest* VerifyWebCredentialsRequest::New() const {
  return new VerifyWebCredentialsRequest;
}

void VerifyWebCredentialsRequest::Clear() {
  if (has_web_credentials()) {
    if (web_credentials_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      web_credentials_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool VerifyWebCredentialsRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes web_credentials = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_web_credentials()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  return false;
#undef DO_
}

void VerifyWebCredentialsRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  // optional bytes web_credentials = 1;
  if (has_web_credentials()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->web_credentials(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
}

::google::protobuf::uint8* VerifyWebCredentialsRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  // optional bytes web_credentials = 1;
  if (has_web_credentials()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->web_credentials(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.authentication.v1.VerifyWebCredentialsRequest)
  return target;
}

int VerifyWebCredentialsRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes web_credentials = 1;
    if (has_web_credentials()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->web_credentials());
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

void VerifyWebCredentialsRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const VerifyWebCredentialsRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const VerifyWebCredentialsRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VerifyWebCredentialsRequest::MergeFrom(const VerifyWebCredentialsRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_web_credentials()) {
      set_web_credentials(from.web_credentials());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void VerifyWebCredentialsRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VerifyWebCredentialsRequest::CopyFrom(const VerifyWebCredentialsRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VerifyWebCredentialsRequest::IsInitialized() const {

  return true;
}

void VerifyWebCredentialsRequest::Swap(VerifyWebCredentialsRequest* other) {
  if (other != this) {
    std::swap(web_credentials_, other->web_credentials_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata VerifyWebCredentialsRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VerifyWebCredentialsRequest_descriptor_;
  metadata.reflection = VerifyWebCredentialsRequest_reflection_;
  return metadata;
}


// ===================================================================

AuthenticationListener::AuthenticationListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

AuthenticationListener::~AuthenticationListener() {
}

google::protobuf::ServiceDescriptor const* AuthenticationListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AuthenticationListener_descriptor_;
}

void AuthenticationListener::OnModuleLoad(::bgs::protocol::authentication::v1::ModuleLoadRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnModuleLoad(bgs.protocol.authentication.v1.ModuleLoadRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void AuthenticationListener::OnModuleMessage(::bgs::protocol::authentication::v1::ModuleMessageRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnModuleMessage(bgs.protocol.authentication.v1.ModuleMessageRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void AuthenticationListener::OnServerStateChange(::bgs::protocol::authentication::v1::ServerStateChangeRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnServerStateChange(bgs.protocol.authentication.v1.ServerStateChangeRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void AuthenticationListener::OnLogonComplete(::bgs::protocol::authentication::v1::LogonResult const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnLogonComplete(bgs.protocol.authentication.v1.LogonResult{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 5, request);
}

void AuthenticationListener::OnMemModuleLoad(::bgs::protocol::authentication::v1::MemModuleLoadRequest const* request, std::function<void(::bgs::protocol::authentication::v1::MemModuleLoadResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnMemModuleLoad(bgs.protocol.authentication.v1.MemModuleLoadRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::authentication::v1::MemModuleLoadResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void AuthenticationListener::OnLogonUpdate(::bgs::protocol::authentication::v1::LogonUpdateRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnLogonUpdate(bgs.protocol.authentication.v1.LogonUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 10, request);
}

void AuthenticationListener::OnVersionInfoUpdated(::bgs::protocol::authentication::v1::VersionInfoNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnVersionInfoUpdated(bgs.protocol.authentication.v1.VersionInfoNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 11, request);
}

void AuthenticationListener::OnLogonQueueUpdate(::bgs::protocol::authentication::v1::LogonQueueUpdateRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnLogonQueueUpdate(bgs.protocol.authentication.v1.LogonQueueUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 12, request);
}

void AuthenticationListener::OnLogonQueueEnd(::bgs::protocol::NoData const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnLogonQueueEnd(bgs.protocol.NoData{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 13, request);
}

void AuthenticationListener::OnGameAccountSelected(::bgs::protocol::authentication::v1::GameAccountSelectedRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationListener.OnGameAccountSelected(bgs.protocol.authentication.v1.GameAccountSelectedRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 14, request);
}

void AuthenticationListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::authentication::v1::ModuleLoadRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnModuleLoad server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnModuleLoad(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnModuleLoad(bgs.protocol.authentication.v1.ModuleLoadRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::authentication::v1::ModuleMessageRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnModuleMessage server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleOnModuleMessage(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnModuleMessage(bgs.protocol.authentication.v1.ModuleMessageRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::authentication::v1::ServerStateChangeRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnServerStateChange server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnServerStateChange(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnServerStateChange(bgs.protocol.authentication.v1.ServerStateChangeRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::authentication::v1::LogonResult request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnLogonComplete server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnLogonComplete(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnLogonComplete(bgs.protocol.authentication.v1.LogonResult{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::authentication::v1::MemModuleLoadRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnMemModuleLoad server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::authentication::v1::MemModuleLoadResponse response;
      uint32 status = HandleOnMemModuleLoad(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnMemModuleLoad(bgs.protocol.authentication.v1.MemModuleLoadRequest{ %s }) returned bgs.protocol.authentication.v1.MemModuleLoadResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 10: {
      ::bgs::protocol::authentication::v1::LogonUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnLogonUpdate server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 10, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnLogonUpdate(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnLogonUpdate(bgs.protocol.authentication.v1.LogonUpdateRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 10, token, status);
      break;
    }
    case 11: {
      ::bgs::protocol::authentication::v1::VersionInfoNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnVersionInfoUpdated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 11, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnVersionInfoUpdated(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnVersionInfoUpdated(bgs.protocol.authentication.v1.VersionInfoNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 11, token, status);
      break;
    }
    case 12: {
      ::bgs::protocol::authentication::v1::LogonQueueUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnLogonQueueUpdate server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 12, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnLogonQueueUpdate(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnLogonQueueUpdate(bgs.protocol.authentication.v1.LogonQueueUpdateRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 12, token, status);
      break;
    }
    case 13: {
      ::bgs::protocol::NoData request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnLogonQueueEnd server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 13, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnLogonQueueEnd(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnLogonQueueEnd(bgs.protocol.NoData{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 13, token, status);
      break;
    }
    case 14: {
      ::bgs::protocol::authentication::v1::GameAccountSelectedRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationListener.OnGameAccountSelected server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 14, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameAccountSelected(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationListener.OnGameAccountSelected(bgs.protocol.authentication.v1.GameAccountSelectedRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 14, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 AuthenticationListener::HandleOnModuleLoad(::bgs::protocol::authentication::v1::ModuleLoadRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnModuleLoad({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnModuleMessage(::bgs::protocol::authentication::v1::ModuleMessageRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnModuleMessage({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnServerStateChange(::bgs::protocol::authentication::v1::ServerStateChangeRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnServerStateChange({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnLogonComplete(::bgs::protocol::authentication::v1::LogonResult const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnLogonComplete({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnMemModuleLoad(::bgs::protocol::authentication::v1::MemModuleLoadRequest const* request, ::bgs::protocol::authentication::v1::MemModuleLoadResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnMemModuleLoad({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnLogonUpdate(::bgs::protocol::authentication::v1::LogonUpdateRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnLogonUpdate({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnVersionInfoUpdated(::bgs::protocol::authentication::v1::VersionInfoNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnVersionInfoUpdated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnLogonQueueUpdate(::bgs::protocol::authentication::v1::LogonQueueUpdateRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnLogonQueueUpdate({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnLogonQueueEnd(::bgs::protocol::NoData const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnLogonQueueEnd({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationListener::HandleOnGameAccountSelected(::bgs::protocol::authentication::v1::GameAccountSelectedRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationListener.OnGameAccountSelected({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

AuthenticationService::AuthenticationService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

AuthenticationService::~AuthenticationService() {
}

google::protobuf::ServiceDescriptor const* AuthenticationService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AuthenticationService_descriptor_;
}

void AuthenticationService::Logon(::bgs::protocol::authentication::v1::LogonRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.Logon(bgs.protocol.authentication.v1.LogonRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void AuthenticationService::ModuleNotify(::bgs::protocol::authentication::v1::ModuleNotification const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.ModuleNotify(bgs.protocol.authentication.v1.ModuleNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void AuthenticationService::ModuleMessage(::bgs::protocol::authentication::v1::ModuleMessageRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.ModuleMessage(bgs.protocol.authentication.v1.ModuleMessageRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void AuthenticationService::SelectGameAccount_DEPRECATED(::bgs::protocol::EntityId const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.SelectGameAccount_DEPRECATED(bgs.protocol.EntityId{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 4, request, std::move(callback));
}

void AuthenticationService::GenerateSSOToken(::bgs::protocol::authentication::v1::GenerateSSOTokenRequest const* request, std::function<void(::bgs::protocol::authentication::v1::GenerateSSOTokenResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.GenerateSSOToken(bgs.protocol.authentication.v1.GenerateSSOTokenRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::authentication::v1::GenerateSSOTokenResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 5, request, std::move(callback));
}

void AuthenticationService::SelectGameAccount(::bgs::protocol::authentication::v1::SelectGameAccountRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.SelectGameAccount(bgs.protocol.authentication.v1.SelectGameAccountRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void AuthenticationService::VerifyWebCredentials(::bgs::protocol::authentication::v1::VerifyWebCredentialsRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.VerifyWebCredentials(bgs.protocol.authentication.v1.VerifyWebCredentialsRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 7, request, std::move(callback));
}

void AuthenticationService::GenerateWebCredentials(::bgs::protocol::authentication::v1::GenerateWebCredentialsRequest const* request, std::function<void(::bgs::protocol::authentication::v1::GenerateWebCredentialsResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AuthenticationService.GenerateWebCredentials(bgs.protocol.authentication.v1.GenerateWebCredentialsRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::authentication::v1::GenerateWebCredentialsResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 8, request, std::move(callback));
}

void AuthenticationService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::authentication::v1::LogonRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.Logon server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleLogon(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.Logon(bgs.protocol.authentication.v1.LogonRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::authentication::v1::ModuleNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.ModuleNotify server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleModuleNotify(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.ModuleNotify(bgs.protocol.authentication.v1.ModuleNotification{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::authentication::v1::ModuleMessageRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.ModuleMessage server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleModuleMessage(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.ModuleMessage(bgs.protocol.authentication.v1.ModuleMessageRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::EntityId request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.SelectGameAccount_DEPRECATED server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSelectGameAccount_DEPRECATED(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.SelectGameAccount_DEPRECATED(bgs.protocol.EntityId{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 4, token, &response);
      else
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::authentication::v1::GenerateSSOTokenRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.GenerateSSOToken server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::authentication::v1::GenerateSSOTokenResponse response;
      uint32 status = HandleGenerateSSOToken(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.GenerateSSOToken(bgs.protocol.authentication.v1.GenerateSSOTokenRequest{ %s }) returned bgs.protocol.authentication.v1.GenerateSSOTokenResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 5, token, &response);
      else
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::authentication::v1::SelectGameAccountRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.SelectGameAccount server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleSelectGameAccount(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.SelectGameAccount(bgs.protocol.authentication.v1.SelectGameAccountRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::authentication::v1::VerifyWebCredentialsRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.VerifyWebCredentials server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleVerifyWebCredentials(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.VerifyWebCredentials(bgs.protocol.authentication.v1.VerifyWebCredentialsRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 7, token, &response);
      else
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    case 8: {
      ::bgs::protocol::authentication::v1::GenerateWebCredentialsRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AuthenticationService.GenerateWebCredentials server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 8, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::authentication::v1::GenerateWebCredentialsResponse response;
      uint32 status = HandleGenerateWebCredentials(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AuthenticationService.GenerateWebCredentials(bgs.protocol.authentication.v1.GenerateWebCredentialsRequest{ %s }) returned bgs.protocol.authentication.v1.GenerateWebCredentialsResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 8, token, &response);
      else
        SendResponse(service_hash_, 8, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 AuthenticationService::HandleLogon(::bgs::protocol::authentication::v1::LogonRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.Logon({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleModuleNotify(::bgs::protocol::authentication::v1::ModuleNotification const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.ModuleNotify({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleModuleMessage(::bgs::protocol::authentication::v1::ModuleMessageRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.ModuleMessage({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleSelectGameAccount_DEPRECATED(::bgs::protocol::EntityId const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.SelectGameAccount_DEPRECATED({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleGenerateSSOToken(::bgs::protocol::authentication::v1::GenerateSSOTokenRequest const* request, ::bgs::protocol::authentication::v1::GenerateSSOTokenResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.GenerateSSOToken({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleSelectGameAccount(::bgs::protocol::authentication::v1::SelectGameAccountRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.SelectGameAccount({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleVerifyWebCredentials(::bgs::protocol::authentication::v1::VerifyWebCredentialsRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.VerifyWebCredentials({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AuthenticationService::HandleGenerateWebCredentials(::bgs::protocol::authentication::v1::GenerateWebCredentialsRequest const* request, ::bgs::protocol::authentication::v1::GenerateWebCredentialsResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AuthenticationService.GenerateWebCredentials({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace authentication
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
