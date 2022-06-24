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
#include "account_service.pb.h"

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
namespace account {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* GetAccountRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAccountRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAccountResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAccountResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* CreateGameAccountRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CreateGameAccountRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* CreateGameAccountResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CreateGameAccountResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* CacheExpireRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CacheExpireRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* CredentialUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CredentialUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* CredentialUpdateResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CredentialUpdateResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountFlagUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountFlagUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountFlagUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountFlagUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscriptionUpdateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscriptionUpdateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscriptionUpdateResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscriptionUpdateResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* IsIgrAddressRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  IsIgrAddressRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountServiceRegion_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountServiceRegion_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountServiceConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountServiceConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAccountStateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAccountStateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAccountStateResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAccountStateResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameAccountStateRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameAccountStateRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameAccountStateResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameAccountStateResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetLicensesRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetLicensesRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetLicensesResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetLicensesResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameSessionInfoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameSessionInfoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameSessionInfoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameSessionInfoResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameTimeRemainingInfoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameTimeRemainingInfoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameTimeRemainingInfoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameTimeRemainingInfoResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetCAISInfoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetCAISInfoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetCAISInfoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetCAISInfoResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ForwardCacheExpireRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ForwardCacheExpireRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAuthorizedDataRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAuthorizedDataRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetAuthorizedDataResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetAuthorizedDataResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* UpdateParentalControlsAndCAISRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateParentalControlsAndCAISRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueueDeductRecordRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueueDeductRecordRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameAccountRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameAccountRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetGameAccountResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetGameAccountResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountStateNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountStateNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountStateNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountStateNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountSessionNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountSessionNotification_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* AccountService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* AccountListener_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_account_5fservice_2eproto() {
  protobuf_AddDesc_account_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "account_service.proto");
  GOOGLE_CHECK(file != NULL);
  GetAccountRequest_descriptor_ = file->message_type(0);
  static const int GetAccountRequest_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, ref_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, reload_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_all_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_blob_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_links_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_parental_controls_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, fetch_cais_id_),
  };
  GetAccountRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAccountRequest_descriptor_,
      GetAccountRequest::default_instance_,
      GetAccountRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAccountRequest));
  GetAccountResponse_descriptor_ = file->message_type(1);
  static const int GetAccountResponse_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, blob_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, links_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, parental_control_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, cais_id_),
  };
  GetAccountResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAccountResponse_descriptor_,
      GetAccountResponse::default_instance_,
      GetAccountResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAccountResponse));
  CreateGameAccountRequest_descriptor_ = file->message_type(2);
  static const int CreateGameAccountRequest_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, realm_permissions_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, account_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, platform_),
  };
  CreateGameAccountRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CreateGameAccountRequest_descriptor_,
      CreateGameAccountRequest::default_instance_,
      CreateGameAccountRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CreateGameAccountRequest));
  CreateGameAccountResponse_descriptor_ = file->message_type(3);
  static const int CreateGameAccountResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountResponse, game_account_),
  };
  CreateGameAccountResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CreateGameAccountResponse_descriptor_,
      CreateGameAccountResponse::default_instance_,
      CreateGameAccountResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateGameAccountResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CreateGameAccountResponse));
  CacheExpireRequest_descriptor_ = file->message_type(4);
  static const int CacheExpireRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CacheExpireRequest, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CacheExpireRequest, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CacheExpireRequest, email_),
  };
  CacheExpireRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CacheExpireRequest_descriptor_,
      CacheExpireRequest::default_instance_,
      CacheExpireRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CacheExpireRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CacheExpireRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CacheExpireRequest));
  CredentialUpdateRequest_descriptor_ = file->message_type(5);
  static const int CredentialUpdateRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, old_credentials_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, new_credentials_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, region_),
  };
  CredentialUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CredentialUpdateRequest_descriptor_,
      CredentialUpdateRequest::default_instance_,
      CredentialUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CredentialUpdateRequest));
  CredentialUpdateResponse_descriptor_ = file->message_type(6);
  static const int CredentialUpdateResponse_offsets_[1] = {
  };
  CredentialUpdateResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CredentialUpdateResponse_descriptor_,
      CredentialUpdateResponse::default_instance_,
      CredentialUpdateResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CredentialUpdateResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CredentialUpdateResponse));
  AccountFlagUpdateRequest_descriptor_ = file->message_type(7);
  static const int AccountFlagUpdateRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, flag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, active_),
  };
  AccountFlagUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountFlagUpdateRequest_descriptor_,
      AccountFlagUpdateRequest::default_instance_,
      AccountFlagUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFlagUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountFlagUpdateRequest));
  GameAccountFlagUpdateRequest_descriptor_ = file->message_type(8);
  static const int GameAccountFlagUpdateRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFlagUpdateRequest, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFlagUpdateRequest, flag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFlagUpdateRequest, active_),
  };
  GameAccountFlagUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountFlagUpdateRequest_descriptor_,
      GameAccountFlagUpdateRequest::default_instance_,
      GameAccountFlagUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFlagUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFlagUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountFlagUpdateRequest));
  SubscriptionUpdateRequest_descriptor_ = file->message_type(9);
  static const int SubscriptionUpdateRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateRequest, ref_),
  };
  SubscriptionUpdateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscriptionUpdateRequest_descriptor_,
      SubscriptionUpdateRequest::default_instance_,
      SubscriptionUpdateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscriptionUpdateRequest));
  SubscriptionUpdateResponse_descriptor_ = file->message_type(10);
  static const int SubscriptionUpdateResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateResponse, ref_),
  };
  SubscriptionUpdateResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscriptionUpdateResponse_descriptor_,
      SubscriptionUpdateResponse::default_instance_,
      SubscriptionUpdateResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriptionUpdateResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscriptionUpdateResponse));
  IsIgrAddressRequest_descriptor_ = file->message_type(11);
  static const int IsIgrAddressRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IsIgrAddressRequest, client_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IsIgrAddressRequest, region_),
  };
  IsIgrAddressRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      IsIgrAddressRequest_descriptor_,
      IsIgrAddressRequest::default_instance_,
      IsIgrAddressRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IsIgrAddressRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IsIgrAddressRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(IsIgrAddressRequest));
  AccountServiceRegion_descriptor_ = file->message_type(12);
  static const int AccountServiceRegion_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceRegion, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceRegion, shard_),
  };
  AccountServiceRegion_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountServiceRegion_descriptor_,
      AccountServiceRegion::default_instance_,
      AccountServiceRegion_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceRegion, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceRegion, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountServiceRegion));
  AccountServiceConfig_descriptor_ = file->message_type(13);
  static const int AccountServiceConfig_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceConfig, region_),
  };
  AccountServiceConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountServiceConfig_descriptor_,
      AccountServiceConfig::default_instance_,
      AccountServiceConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountServiceConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountServiceConfig));
  GetAccountStateRequest_descriptor_ = file->message_type(14);
  static const int GetAccountStateRequest_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, tags_),
  };
  GetAccountStateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAccountStateRequest_descriptor_,
      GetAccountStateRequest::default_instance_,
      GetAccountStateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAccountStateRequest));
  GetAccountStateResponse_descriptor_ = file->message_type(15);
  static const int GetAccountStateResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateResponse, state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateResponse, tags_),
  };
  GetAccountStateResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAccountStateResponse_descriptor_,
      GetAccountStateResponse::default_instance_,
      GetAccountStateResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAccountStateResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAccountStateResponse));
  GetGameAccountStateRequest_descriptor_ = file->message_type(16);
  static const int GetGameAccountStateRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, tags_),
  };
  GetGameAccountStateRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameAccountStateRequest_descriptor_,
      GetGameAccountStateRequest::default_instance_,
      GetGameAccountStateRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameAccountStateRequest));
  GetGameAccountStateResponse_descriptor_ = file->message_type(17);
  static const int GetGameAccountStateResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateResponse, state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateResponse, tags_),
  };
  GetGameAccountStateResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameAccountStateResponse_descriptor_,
      GetGameAccountStateResponse::default_instance_,
      GetGameAccountStateResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountStateResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameAccountStateResponse));
  GetLicensesRequest_descriptor_ = file->message_type(18);
  static const int GetLicensesRequest_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, target_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, fetch_account_licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, fetch_game_account_licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, fetch_dynamic_account_licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, exclude_unknown_program_),
  };
  GetLicensesRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetLicensesRequest_descriptor_,
      GetLicensesRequest::default_instance_,
      GetLicensesRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetLicensesRequest));
  GetLicensesResponse_descriptor_ = file->message_type(19);
  static const int GetLicensesResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesResponse, licenses_),
  };
  GetLicensesResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetLicensesResponse_descriptor_,
      GetLicensesResponse::default_instance_,
      GetLicensesResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetLicensesResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetLicensesResponse));
  GetGameSessionInfoRequest_descriptor_ = file->message_type(20);
  static const int GetGameSessionInfoRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoRequest, entity_id_),
  };
  GetGameSessionInfoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameSessionInfoRequest_descriptor_,
      GetGameSessionInfoRequest::default_instance_,
      GetGameSessionInfoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameSessionInfoRequest));
  GetGameSessionInfoResponse_descriptor_ = file->message_type(21);
  static const int GetGameSessionInfoResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoResponse, session_info_),
  };
  GetGameSessionInfoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameSessionInfoResponse_descriptor_,
      GetGameSessionInfoResponse::default_instance_,
      GetGameSessionInfoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameSessionInfoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameSessionInfoResponse));
  GetGameTimeRemainingInfoRequest_descriptor_ = file->message_type(22);
  static const int GetGameTimeRemainingInfoRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoRequest, game_account_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoRequest, account_id_),
  };
  GetGameTimeRemainingInfoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameTimeRemainingInfoRequest_descriptor_,
      GetGameTimeRemainingInfoRequest::default_instance_,
      GetGameTimeRemainingInfoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameTimeRemainingInfoRequest));
  GetGameTimeRemainingInfoResponse_descriptor_ = file->message_type(23);
  static const int GetGameTimeRemainingInfoResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoResponse, game_time_remaining_info_),
  };
  GetGameTimeRemainingInfoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameTimeRemainingInfoResponse_descriptor_,
      GetGameTimeRemainingInfoResponse::default_instance_,
      GetGameTimeRemainingInfoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameTimeRemainingInfoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameTimeRemainingInfoResponse));
  GetCAISInfoRequest_descriptor_ = file->message_type(24);
  static const int GetCAISInfoRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoRequest, entity_id_),
  };
  GetCAISInfoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetCAISInfoRequest_descriptor_,
      GetCAISInfoRequest::default_instance_,
      GetCAISInfoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetCAISInfoRequest));
  GetCAISInfoResponse_descriptor_ = file->message_type(25);
  static const int GetCAISInfoResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoResponse, cais_info_),
  };
  GetCAISInfoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetCAISInfoResponse_descriptor_,
      GetCAISInfoResponse::default_instance_,
      GetCAISInfoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCAISInfoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetCAISInfoResponse));
  ForwardCacheExpireRequest_descriptor_ = file->message_type(26);
  static const int ForwardCacheExpireRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ForwardCacheExpireRequest, entity_id_),
  };
  ForwardCacheExpireRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ForwardCacheExpireRequest_descriptor_,
      ForwardCacheExpireRequest::default_instance_,
      ForwardCacheExpireRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ForwardCacheExpireRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ForwardCacheExpireRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ForwardCacheExpireRequest));
  GetAuthorizedDataRequest_descriptor_ = file->message_type(27);
  static const int GetAuthorizedDataRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataRequest, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataRequest, tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataRequest, privileged_network_),
  };
  GetAuthorizedDataRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAuthorizedDataRequest_descriptor_,
      GetAuthorizedDataRequest::default_instance_,
      GetAuthorizedDataRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAuthorizedDataRequest));
  GetAuthorizedDataResponse_descriptor_ = file->message_type(28);
  static const int GetAuthorizedDataResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataResponse, data_),
  };
  GetAuthorizedDataResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetAuthorizedDataResponse_descriptor_,
      GetAuthorizedDataResponse::default_instance_,
      GetAuthorizedDataResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetAuthorizedDataResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetAuthorizedDataResponse));
  UpdateParentalControlsAndCAISRequest_descriptor_ = file->message_type(29);
  static const int UpdateParentalControlsAndCAISRequest_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, parental_control_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, cais_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, session_start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, end_time_),
  };
  UpdateParentalControlsAndCAISRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UpdateParentalControlsAndCAISRequest_descriptor_,
      UpdateParentalControlsAndCAISRequest::default_instance_,
      UpdateParentalControlsAndCAISRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateParentalControlsAndCAISRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UpdateParentalControlsAndCAISRequest));
  QueueDeductRecordRequest_descriptor_ = file->message_type(30);
  static const int QueueDeductRecordRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueueDeductRecordRequest, deduct_record_),
  };
  QueueDeductRecordRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueueDeductRecordRequest_descriptor_,
      QueueDeductRecordRequest::default_instance_,
      QueueDeductRecordRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueueDeductRecordRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueueDeductRecordRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QueueDeductRecordRequest));
  GetGameAccountRequest_descriptor_ = file->message_type(31);
  static const int GetGameAccountRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountRequest, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountRequest, reload_),
  };
  GetGameAccountRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameAccountRequest_descriptor_,
      GetGameAccountRequest::default_instance_,
      GetGameAccountRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameAccountRequest));
  GetGameAccountResponse_descriptor_ = file->message_type(32);
  static const int GetGameAccountResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountResponse, blob_),
  };
  GetGameAccountResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetGameAccountResponse_descriptor_,
      GetGameAccountResponse::default_instance_,
      GetGameAccountResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetGameAccountResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetGameAccountResponse));
  AccountStateNotification_descriptor_ = file->message_type(33);
  static const int AccountStateNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, account_state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, subscriber_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, account_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, subscription_completed_),
  };
  AccountStateNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountStateNotification_descriptor_,
      AccountStateNotification::default_instance_,
      AccountStateNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountStateNotification));
  GameAccountStateNotification_descriptor_ = file->message_type(34);
  static const int GameAccountStateNotification_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, game_account_state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, subscriber_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, game_account_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, subscription_completed_),
  };
  GameAccountStateNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountStateNotification_descriptor_,
      GameAccountStateNotification::default_instance_,
      GameAccountStateNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountStateNotification));
  GameAccountNotification_descriptor_ = file->message_type(35);
  static const int GameAccountNotification_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountNotification, game_accounts_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountNotification, subscriber_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountNotification, account_tags_),
  };
  GameAccountNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountNotification_descriptor_,
      GameAccountNotification::default_instance_,
      GameAccountNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountNotification));
  GameAccountSessionNotification_descriptor_ = file->message_type(36);
  static const int GameAccountSessionNotification_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSessionNotification, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSessionNotification, session_info_),
  };
  GameAccountSessionNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountSessionNotification_descriptor_,
      GameAccountSessionNotification::default_instance_,
      GameAccountSessionNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSessionNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountSessionNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountSessionNotification));
  AccountService_descriptor_ = file->service(0);
  AccountListener_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_account_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAccountRequest_descriptor_, &GetAccountRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAccountResponse_descriptor_, &GetAccountResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CreateGameAccountRequest_descriptor_, &CreateGameAccountRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CreateGameAccountResponse_descriptor_, &CreateGameAccountResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CacheExpireRequest_descriptor_, &CacheExpireRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CredentialUpdateRequest_descriptor_, &CredentialUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CredentialUpdateResponse_descriptor_, &CredentialUpdateResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountFlagUpdateRequest_descriptor_, &AccountFlagUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountFlagUpdateRequest_descriptor_, &GameAccountFlagUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscriptionUpdateRequest_descriptor_, &SubscriptionUpdateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscriptionUpdateResponse_descriptor_, &SubscriptionUpdateResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    IsIgrAddressRequest_descriptor_, &IsIgrAddressRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountServiceRegion_descriptor_, &AccountServiceRegion::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountServiceConfig_descriptor_, &AccountServiceConfig::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAccountStateRequest_descriptor_, &GetAccountStateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAccountStateResponse_descriptor_, &GetAccountStateResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameAccountStateRequest_descriptor_, &GetGameAccountStateRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameAccountStateResponse_descriptor_, &GetGameAccountStateResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetLicensesRequest_descriptor_, &GetLicensesRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetLicensesResponse_descriptor_, &GetLicensesResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameSessionInfoRequest_descriptor_, &GetGameSessionInfoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameSessionInfoResponse_descriptor_, &GetGameSessionInfoResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameTimeRemainingInfoRequest_descriptor_, &GetGameTimeRemainingInfoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameTimeRemainingInfoResponse_descriptor_, &GetGameTimeRemainingInfoResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetCAISInfoRequest_descriptor_, &GetCAISInfoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetCAISInfoResponse_descriptor_, &GetCAISInfoResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ForwardCacheExpireRequest_descriptor_, &ForwardCacheExpireRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAuthorizedDataRequest_descriptor_, &GetAuthorizedDataRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetAuthorizedDataResponse_descriptor_, &GetAuthorizedDataResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UpdateParentalControlsAndCAISRequest_descriptor_, &UpdateParentalControlsAndCAISRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueueDeductRecordRequest_descriptor_, &QueueDeductRecordRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameAccountRequest_descriptor_, &GetGameAccountRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetGameAccountResponse_descriptor_, &GetGameAccountResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountStateNotification_descriptor_, &AccountStateNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountStateNotification_descriptor_, &GameAccountStateNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountNotification_descriptor_, &GameAccountNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountSessionNotification_descriptor_, &GameAccountSessionNotification::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_account_5fservice_2eproto() {
  delete GetAccountRequest::default_instance_;
  delete GetAccountRequest_reflection_;
  delete GetAccountResponse::default_instance_;
  delete GetAccountResponse_reflection_;
  delete CreateGameAccountRequest::default_instance_;
  delete CreateGameAccountRequest_reflection_;
  delete CreateGameAccountResponse::default_instance_;
  delete CreateGameAccountResponse_reflection_;
  delete CacheExpireRequest::default_instance_;
  delete CacheExpireRequest_reflection_;
  delete CredentialUpdateRequest::default_instance_;
  delete CredentialUpdateRequest_reflection_;
  delete CredentialUpdateResponse::default_instance_;
  delete CredentialUpdateResponse_reflection_;
  delete AccountFlagUpdateRequest::default_instance_;
  delete AccountFlagUpdateRequest_reflection_;
  delete GameAccountFlagUpdateRequest::default_instance_;
  delete GameAccountFlagUpdateRequest_reflection_;
  delete SubscriptionUpdateRequest::default_instance_;
  delete SubscriptionUpdateRequest_reflection_;
  delete SubscriptionUpdateResponse::default_instance_;
  delete SubscriptionUpdateResponse_reflection_;
  delete IsIgrAddressRequest::default_instance_;
  delete IsIgrAddressRequest_reflection_;
  delete AccountServiceRegion::default_instance_;
  delete AccountServiceRegion_reflection_;
  delete AccountServiceConfig::default_instance_;
  delete AccountServiceConfig_reflection_;
  delete GetAccountStateRequest::default_instance_;
  delete GetAccountStateRequest_reflection_;
  delete GetAccountStateResponse::default_instance_;
  delete GetAccountStateResponse_reflection_;
  delete GetGameAccountStateRequest::default_instance_;
  delete GetGameAccountStateRequest_reflection_;
  delete GetGameAccountStateResponse::default_instance_;
  delete GetGameAccountStateResponse_reflection_;
  delete GetLicensesRequest::default_instance_;
  delete GetLicensesRequest_reflection_;
  delete GetLicensesResponse::default_instance_;
  delete GetLicensesResponse_reflection_;
  delete GetGameSessionInfoRequest::default_instance_;
  delete GetGameSessionInfoRequest_reflection_;
  delete GetGameSessionInfoResponse::default_instance_;
  delete GetGameSessionInfoResponse_reflection_;
  delete GetGameTimeRemainingInfoRequest::default_instance_;
  delete GetGameTimeRemainingInfoRequest_reflection_;
  delete GetGameTimeRemainingInfoResponse::default_instance_;
  delete GetGameTimeRemainingInfoResponse_reflection_;
  delete GetCAISInfoRequest::default_instance_;
  delete GetCAISInfoRequest_reflection_;
  delete GetCAISInfoResponse::default_instance_;
  delete GetCAISInfoResponse_reflection_;
  delete ForwardCacheExpireRequest::default_instance_;
  delete ForwardCacheExpireRequest_reflection_;
  delete GetAuthorizedDataRequest::default_instance_;
  delete GetAuthorizedDataRequest_reflection_;
  delete GetAuthorizedDataResponse::default_instance_;
  delete GetAuthorizedDataResponse_reflection_;
  delete UpdateParentalControlsAndCAISRequest::default_instance_;
  delete UpdateParentalControlsAndCAISRequest_reflection_;
  delete QueueDeductRecordRequest::default_instance_;
  delete QueueDeductRecordRequest_reflection_;
  delete GetGameAccountRequest::default_instance_;
  delete GetGameAccountRequest_reflection_;
  delete GetGameAccountResponse::default_instance_;
  delete GetGameAccountResponse_reflection_;
  delete AccountStateNotification::default_instance_;
  delete AccountStateNotification_reflection_;
  delete GameAccountStateNotification::default_instance_;
  delete GameAccountStateNotification_reflection_;
  delete GameAccountNotification::default_instance_;
  delete GameAccountNotification_reflection_;
  delete GameAccountSessionNotification::default_instance_;
  delete GameAccountSessionNotification_reflection_;
}

void protobuf_AddDesc_account_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::account::v1::protobuf_AddDesc_account_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025account_service.proto\022\027bgs.protocol.ac"
    "count.v1\032\023account_types.proto\032\022entity_ty"
    "pes.proto\032\017rpc_types.proto\"\357\002\n\021GetAccoun"
    "tRequest\0226\n\003ref\030\001 \001(\0132).bgs.protocol.acc"
    "ount.v1.AccountReference\022\025\n\006reload\030\002 \001(\010"
    ":\005false\022\030\n\tfetch_all\030\n \001(\010:\005false\022\031\n\nfet"
    "ch_blob\030\013 \001(\010:\005false\022\027\n\010fetch_id\030\014 \001(\010:\005"
    "false\022\032\n\013fetch_email\030\r \001(\010:\005false\022\037\n\020fet"
    "ch_battle_tag\030\016 \001(\010:\005false\022\036\n\017fetch_full"
    "_name\030\017 \001(\010:\005false\022\032\n\013fetch_links\030\020 \001(\010:"
    "\005false\022&\n\027fetch_parental_controls\030\021 \001(\010:"
    "\005false\022\034\n\rfetch_cais_id\030\022 \001(\010:\005false\"\305\002\n"
    "\022GetAccountResponse\0222\n\004blob\030\013 \001(\0132$.bgs."
    "protocol.account.v1.AccountBlob\022.\n\002id\030\014 "
    "\001(\0132\".bgs.protocol.account.v1.AccountId\022"
    "\r\n\005email\030\r \003(\t\022\022\n\nbattle_tag\030\016 \001(\t\022\021\n\tfu"
    "ll_name\030\017 \001(\t\0227\n\005links\030\020 \003(\0132(.bgs.proto"
    "col.account.v1.GameAccountLink\022K\n\025parent"
    "al_control_info\030\021 \001(\0132,.bgs.protocol.acc"
    "ount.v1.ParentalControlInfo\022\017\n\007cais_id\030\022"
    " \001(\t\"\270\001\n\030CreateGameAccountRequest\0223\n\007acc"
    "ount\030\001 \001(\0132\".bgs.protocol.account.v1.Acc"
    "ountId\022\016\n\006region\030\002 \001(\r\022\017\n\007program\030\003 \001(\007\022"
    "\034\n\021realm_permissions\030\004 \001(\r:\0010\022\026\n\016account"
    "_region\030\005 \001(\r\022\020\n\010platform\030\006 \001(\007\"]\n\031Creat"
    "eGameAccountResponse\022@\n\014game_account\030\001 \001"
    "(\0132*.bgs.protocol.account.v1.GameAccount"
    "Handle\"\232\001\n\022CacheExpireRequest\0223\n\007account"
    "\030\001 \003(\0132\".bgs.protocol.account.v1.Account"
    "Id\022@\n\014game_account\030\002 \003(\0132*.bgs.protocol."
    "account.v1.GameAccountHandle\022\r\n\005email\030\003 "
    "\003(\t\"\350\001\n\027CredentialUpdateRequest\0223\n\007accou"
    "nt\030\001 \002(\0132\".bgs.protocol.account.v1.Accou"
    "ntId\022C\n\017old_credentials\030\002 \003(\0132*.bgs.prot"
    "ocol.account.v1.AccountCredential\022C\n\017new"
    "_credentials\030\003 \003(\0132*.bgs.protocol.accoun"
    "t.v1.AccountCredential\022\016\n\006region\030\004 \001(\r\"\032"
    "\n\030CredentialUpdateResponse\"}\n\030AccountFla"
    "gUpdateRequest\0223\n\007account\030\001 \001(\0132\".bgs.pr"
    "otocol.account.v1.AccountId\022\016\n\006region\030\002 "
    "\001(\r\022\014\n\004flag\030\003 \001(\004\022\016\n\006active\030\004 \001(\010\"~\n\034Gam"
    "eAccountFlagUpdateRequest\022@\n\014game_accoun"
    "t\030\001 \001(\0132*.bgs.protocol.account.v1.GameAc"
    "countHandle\022\014\n\004flag\030\002 \001(\004\022\016\n\006active\030\003 \001("
    "\010\"V\n\031SubscriptionUpdateRequest\0229\n\003ref\030\002 "
    "\003(\0132,.bgs.protocol.account.v1.Subscriber"
    "Reference\"W\n\032SubscriptionUpdateResponse\022"
    "9\n\003ref\030\001 \003(\0132,.bgs.protocol.account.v1.S"
    "ubscriberReference\"=\n\023IsIgrAddressReques"
    "t\022\026\n\016client_address\030\001 \001(\t\022\016\n\006region\030\002 \001("
    "\r\"1\n\024AccountServiceRegion\022\n\n\002id\030\001 \002(\r\022\r\n"
    "\005shard\030\002 \002(\t\"U\n\024AccountServiceConfig\022=\n\006"
    "region\030\001 \003(\0132-.bgs.protocol.account.v1.A"
    "ccountServiceRegion\"\334\001\n\026GetAccountStateR"
    "equest\022)\n\tentity_id\030\001 \001(\0132\026.bgs.protocol"
    ".EntityId\022\017\n\007program\030\002 \001(\r\022\016\n\006region\030\003 \001"
    "(\r\022=\n\007options\030\n \001(\0132,.bgs.protocol.accou"
    "nt.v1.AccountFieldOptions\0227\n\004tags\030\013 \001(\0132"
    ").bgs.protocol.account.v1.AccountFieldTa"
    "gs\"\210\001\n\027GetAccountStateResponse\0224\n\005state\030"
    "\001 \001(\0132%.bgs.protocol.account.v1.AccountS"
    "tate\0227\n\004tags\030\002 \001(\0132).bgs.protocol.accoun"
    "t.v1.AccountFieldTags\"\375\001\n\032GetGameAccount"
    "StateRequest\022.\n\naccount_id\030\001 \001(\0132\026.bgs.p"
    "rotocol.EntityIdB\002\030\001\022/\n\017game_account_id\030"
    "\002 \001(\0132\026.bgs.protocol.EntityId\022A\n\007options"
    "\030\n \001(\01320.bgs.protocol.account.v1.GameAcc"
    "ountFieldOptions\022;\n\004tags\030\013 \001(\0132-.bgs.pro"
    "tocol.account.v1.GameAccountFieldTags\"\224\001"
    "\n\033GetGameAccountStateResponse\0228\n\005state\030\001"
    " \001(\0132).bgs.protocol.account.v1.GameAccou"
    "ntState\022;\n\004tags\030\002 \001(\0132-.bgs.protocol.acc"
    "ount.v1.GameAccountFieldTags\"\345\001\n\022GetLice"
    "nsesRequest\022)\n\ttarget_id\030\001 \001(\0132\026.bgs.pro"
    "tocol.EntityId\022\036\n\026fetch_account_licenses"
    "\030\002 \001(\010\022#\n\033fetch_game_account_licenses\030\003 "
    "\001(\010\022&\n\036fetch_dynamic_account_licenses\030\004 "
    "\001(\010\022\017\n\007program\030\005 \001(\007\022&\n\027exclude_unknown_"
    "program\030\006 \001(\010:\005false\"P\n\023GetLicensesRespo"
    "nse\0229\n\010licenses\030\001 \003(\0132\'.bgs.protocol.acc"
    "ount.v1.AccountLicense\"F\n\031GetGameSession"
    "InfoRequest\022)\n\tentity_id\030\001 \001(\0132\026.bgs.pro"
    "tocol.EntityId\"\\\n\032GetGameSessionInfoResp"
    "onse\022>\n\014session_info\030\002 \001(\0132(.bgs.protoco"
    "l.account.v1.GameSessionInfo\"~\n\037GetGameT"
    "imeRemainingInfoRequest\022/\n\017game_account_"
    "id\030\001 \001(\0132\026.bgs.protocol.EntityId\022*\n\nacco"
    "unt_id\030\002 \001(\0132\026.bgs.protocol.EntityId\"t\n "
    "GetGameTimeRemainingInfoResponse\022P\n\030game"
    "_time_remaining_info\030\001 \001(\0132..bgs.protoco"
    "l.account.v1.GameTimeRemainingInfo\"\?\n\022Ge"
    "tCAISInfoRequest\022)\n\tentity_id\030\001 \001(\0132\026.bg"
    "s.protocol.EntityId\"G\n\023GetCAISInfoRespon"
    "se\0220\n\tcais_info\030\001 \001(\0132\035.bgs.protocol.acc"
    "ount.v1.CAIS\"F\n\031ForwardCacheExpireReques"
    "t\022)\n\tentity_id\030\001 \001(\0132\026.bgs.protocol.Enti"
    "tyId\"n\n\030GetAuthorizedDataRequest\022)\n\tenti"
    "ty_id\030\001 \001(\0132\026.bgs.protocol.EntityId\022\013\n\003t"
    "ag\030\002 \003(\t\022\032\n\022privileged_network\030\003 \001(\010\"R\n\031"
    "GetAuthorizedDataResponse\0225\n\004data\030\001 \003(\0132"
    "\'.bgs.protocol.account.v1.AuthorizedData"
    "\"\373\001\n$UpdateParentalControlsAndCAISReques"
    "t\0223\n\007account\030\001 \001(\0132\".bgs.protocol.accoun"
    "t.v1.AccountId\022K\n\025parental_control_info\030"
    "\002 \001(\0132,.bgs.protocol.account.v1.Parental"
    "ControlInfo\022\017\n\007cais_id\030\003 \001(\t\022\032\n\022session_"
    "start_time\030\004 \001(\004\022\022\n\nstart_time\030\005 \001(\004\022\020\n\010"
    "end_time\030\006 \001(\004\"X\n\030QueueDeductRecordReque"
    "st\022<\n\rdeduct_record\030\001 \001(\0132%.bgs.protocol"
    ".account.v1.DeductRecord\"p\n\025GetGameAccou"
    "ntRequest\022@\n\014game_account\030\001 \001(\0132*.bgs.pr"
    "otocol.account.v1.GameAccountHandle\022\025\n\006r"
    "eload\030\002 \001(\010:\005false\"P\n\026GetGameAccountResp"
    "onse\0226\n\004blob\030\001 \001(\0132(.bgs.protocol.accoun"
    "t.v1.GameAccountBlob\"\320\001\n\030AccountStateNot"
    "ification\022<\n\raccount_state\030\001 \001(\0132%.bgs.p"
    "rotocol.account.v1.AccountState\022\025\n\rsubsc"
    "riber_id\030\002 \001(\004\022\?\n\014account_tags\030\003 \001(\0132).b"
    "gs.protocol.account.v1.AccountFieldTags\022"
    "\036\n\026subscription_completed\030\004 \001(\010\"\346\001\n\034Game"
    "AccountStateNotification\022E\n\022game_account"
    "_state\030\001 \001(\0132).bgs.protocol.account.v1.G"
    "ameAccountState\022\025\n\rsubscriber_id\030\002 \001(\004\022H"
    "\n\021game_account_tags\030\003 \001(\0132-.bgs.protocol"
    ".account.v1.GameAccountFieldTags\022\036\n\026subs"
    "cription_completed\030\004 \001(\010\"\262\001\n\027GameAccount"
    "Notification\022\?\n\rgame_accounts\030\001 \003(\0132(.bg"
    "s.protocol.account.v1.GameAccountList\022\025\n"
    "\rsubscriber_id\030\002 \001(\004\022\?\n\014account_tags\030\003 \001"
    "(\0132).bgs.protocol.account.v1.AccountFiel"
    "dTags\"\250\001\n\036GameAccountSessionNotification"
    "\022@\n\014game_account\030\001 \001(\0132*.bgs.protocol.ac"
    "count.v1.GameAccountHandle\022D\n\014session_in"
    "fo\030\002 \001(\0132..bgs.protocol.account.v1.GameS"
    "essionUpdateInfo2\312\024\n\016AccountService\022p\n\022G"
    "etGameAccountBlob\022*.bgs.protocol.account"
    ".v1.GameAccountHandle\032(.bgs.protocol.acc"
    "ount.v1.GameAccountBlob\"\004\200\265\030\014\022k\n\nGetAcco"
    "unt\022*.bgs.protocol.account.v1.GetAccount"
    "Request\032+.bgs.protocol.account.v1.GetAcc"
    "ountResponse\"\004\200\265\030\r\022x\n\021CreateGameAccount\022"
    "1.bgs.protocol.account.v1.CreateGameAcco"
    "untRequest\032*.bgs.protocol.account.v1.Gam"
    "eAccountHandle\"\004\200\265\030\016\022X\n\014IsIgrAddress\022,.b"
    "gs.protocol.account.v1.IsIgrAddressReque"
    "st\032\024.bgs.protocol.NoData\"\004\200\265\030\017\022[\n\013CacheE"
    "xpire\022+.bgs.protocol.account.v1.CacheExp"
    "ireRequest\032\031.bgs.protocol.NO_RESPONSE\"\004\200"
    "\265\030\024\022\200\001\n\020CredentialUpdate\0220.bgs.protocol."
    "account.v1.CredentialUpdateRequest\0321.bgs"
    ".protocol.account.v1.CredentialUpdateRes"
    "ponse\"\007\210\002\001\200\265\030\025\022z\n\tSubscribe\0222.bgs.protoc"
    "ol.account.v1.SubscriptionUpdateRequest\032"
    "3.bgs.protocol.account.v1.SubscriptionUp"
    "dateResponse\"\004\200\265\030\031\022]\n\013Unsubscribe\0222.bgs."
    "protocol.account.v1.SubscriptionUpdateRe"
    "quest\032\024.bgs.protocol.NoData\"\004\200\265\030\032\022z\n\017Get"
    "AccountState\022/.bgs.protocol.account.v1.G"
    "etAccountStateRequest\0320.bgs.protocol.acc"
    "ount.v1.GetAccountStateResponse\"\004\200\265\030\036\022\206\001"
    "\n\023GetGameAccountState\0223.bgs.protocol.acc"
    "ount.v1.GetGameAccountStateRequest\0324.bgs"
    ".protocol.account.v1.GetGameAccountState"
    "Response\"\004\200\265\030\037\022n\n\013GetLicenses\022+.bgs.prot"
    "ocol.account.v1.GetLicensesRequest\032,.bgs"
    ".protocol.account.v1.GetLicensesResponse"
    "\"\004\200\265\030 \022\225\001\n\030GetGameTimeRemainingInfo\0228.bg"
    "s.protocol.account.v1.GetGameTimeRemaini"
    "ngInfoRequest\0329.bgs.protocol.account.v1."
    "GetGameTimeRemainingInfoResponse\"\004\200\265\030!\022\203"
    "\001\n\022GetGameSessionInfo\0222.bgs.protocol.acc"
    "ount.v1.GetGameSessionInfoRequest\0323.bgs."
    "protocol.account.v1.GetGameSessionInfoRe"
    "sponse\"\004\200\265\030\"\022n\n\013GetCAISInfo\022+.bgs.protoc"
    "ol.account.v1.GetCAISInfoRequest\032,.bgs.p"
    "rotocol.account.v1.GetCAISInfoResponse\"\004"
    "\200\265\030#\022d\n\022ForwardCacheExpire\0222.bgs.protoco"
    "l.account.v1.ForwardCacheExpireRequest\032\024"
    ".bgs.protocol.NoData\"\004\200\265\030$\022\200\001\n\021GetAuthor"
    "izedData\0221.bgs.protocol.account.v1.GetAu"
    "thorizedDataRequest\0322.bgs.protocol.accou"
    "nt.v1.GetAuthorizedDataResponse\"\004\200\265\030%\022g\n"
    "\021AccountFlagUpdate\0221.bgs.protocol.accoun"
    "t.v1.AccountFlagUpdateRequest\032\031.bgs.prot"
    "ocol.NO_RESPONSE\"\004\200\265\030&\022o\n\025GameAccountFla"
    "gUpdate\0225.bgs.protocol.account.v1.GameAc"
    "countFlagUpdateRequest\032\031.bgs.protocol.NO"
    "_RESPONSE\"\004\200\265\030\'\022z\n\035UpdateParentalControl"
    "sAndCAIS\022=.bgs.protocol.account.v1.Updat"
    "eParentalControlsAndCAISRequest\032\024.bgs.pr"
    "otocol.NoData\"\004\200\265\030(\022\201\001\n\022CreateGameAccoun"
    "t2\0221.bgs.protocol.account.v1.CreateGameA"
    "ccountRequest\0322.bgs.protocol.account.v1."
    "CreateGameAccountResponse\"\004\200\265\030)\022w\n\016GetGa"
    "meAccount\022..bgs.protocol.account.v1.GetG"
    "ameAccountRequest\032/.bgs.protocol.account"
    ".v1.GetGameAccountResponse\"\004\200\265\030*\022b\n\021Queu"
    "eDeductRecord\0221.bgs.protocol.account.v1."
    "QueueDeductRecordRequest\032\024.bgs.protocol."
    "NoData\"\004\200\265\030+\032\'\312>$bnet.protocol.account.A"
    "ccountService2\377\003\n\017AccountListener\022k\n\025OnA"
    "ccountStateUpdated\0221.bgs.protocol.accoun"
    "t.v1.AccountStateNotification\032\031.bgs.prot"
    "ocol.NO_RESPONSE\"\004\200\265\030\001\022s\n\031OnGameAccountS"
    "tateUpdated\0225.bgs.protocol.account.v1.Ga"
    "meAccountStateNotification\032\031.bgs.protoco"
    "l.NO_RESPONSE\"\004\200\265\030\002\022m\n\025OnGameAccountsUpd"
    "ated\0220.bgs.protocol.account.v1.GameAccou"
    "ntNotification\032\031.bgs.protocol.NO_RESPONS"
    "E\"\007\210\002\001\200\265\030\003\022s\n\024OnGameSessionUpdated\0227.bgs"
    ".protocol.account.v1.GameAccountSessionN"
    "otification\032\031.bgs.protocol.NO_RESPONSE\"\007"
    "\210\002\001\200\265\030\004\032&\312>#bnet.protocol.account.Accoun"
    "tNotifyB\005H\001\200\001\000", 8534);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "account_service.proto", &protobuf_RegisterTypes);
  GetAccountRequest::default_instance_ = new GetAccountRequest();
  GetAccountResponse::default_instance_ = new GetAccountResponse();
  CreateGameAccountRequest::default_instance_ = new CreateGameAccountRequest();
  CreateGameAccountResponse::default_instance_ = new CreateGameAccountResponse();
  CacheExpireRequest::default_instance_ = new CacheExpireRequest();
  CredentialUpdateRequest::default_instance_ = new CredentialUpdateRequest();
  CredentialUpdateResponse::default_instance_ = new CredentialUpdateResponse();
  AccountFlagUpdateRequest::default_instance_ = new AccountFlagUpdateRequest();
  GameAccountFlagUpdateRequest::default_instance_ = new GameAccountFlagUpdateRequest();
  SubscriptionUpdateRequest::default_instance_ = new SubscriptionUpdateRequest();
  SubscriptionUpdateResponse::default_instance_ = new SubscriptionUpdateResponse();
  IsIgrAddressRequest::default_instance_ = new IsIgrAddressRequest();
  AccountServiceRegion::default_instance_ = new AccountServiceRegion();
  AccountServiceConfig::default_instance_ = new AccountServiceConfig();
  GetAccountStateRequest::default_instance_ = new GetAccountStateRequest();
  GetAccountStateResponse::default_instance_ = new GetAccountStateResponse();
  GetGameAccountStateRequest::default_instance_ = new GetGameAccountStateRequest();
  GetGameAccountStateResponse::default_instance_ = new GetGameAccountStateResponse();
  GetLicensesRequest::default_instance_ = new GetLicensesRequest();
  GetLicensesResponse::default_instance_ = new GetLicensesResponse();
  GetGameSessionInfoRequest::default_instance_ = new GetGameSessionInfoRequest();
  GetGameSessionInfoResponse::default_instance_ = new GetGameSessionInfoResponse();
  GetGameTimeRemainingInfoRequest::default_instance_ = new GetGameTimeRemainingInfoRequest();
  GetGameTimeRemainingInfoResponse::default_instance_ = new GetGameTimeRemainingInfoResponse();
  GetCAISInfoRequest::default_instance_ = new GetCAISInfoRequest();
  GetCAISInfoResponse::default_instance_ = new GetCAISInfoResponse();
  ForwardCacheExpireRequest::default_instance_ = new ForwardCacheExpireRequest();
  GetAuthorizedDataRequest::default_instance_ = new GetAuthorizedDataRequest();
  GetAuthorizedDataResponse::default_instance_ = new GetAuthorizedDataResponse();
  UpdateParentalControlsAndCAISRequest::default_instance_ = new UpdateParentalControlsAndCAISRequest();
  QueueDeductRecordRequest::default_instance_ = new QueueDeductRecordRequest();
  GetGameAccountRequest::default_instance_ = new GetGameAccountRequest();
  GetGameAccountResponse::default_instance_ = new GetGameAccountResponse();
  AccountStateNotification::default_instance_ = new AccountStateNotification();
  GameAccountStateNotification::default_instance_ = new GameAccountStateNotification();
  GameAccountNotification::default_instance_ = new GameAccountNotification();
  GameAccountSessionNotification::default_instance_ = new GameAccountSessionNotification();
  GetAccountRequest::default_instance_->InitAsDefaultInstance();
  GetAccountResponse::default_instance_->InitAsDefaultInstance();
  CreateGameAccountRequest::default_instance_->InitAsDefaultInstance();
  CreateGameAccountResponse::default_instance_->InitAsDefaultInstance();
  CacheExpireRequest::default_instance_->InitAsDefaultInstance();
  CredentialUpdateRequest::default_instance_->InitAsDefaultInstance();
  CredentialUpdateResponse::default_instance_->InitAsDefaultInstance();
  AccountFlagUpdateRequest::default_instance_->InitAsDefaultInstance();
  GameAccountFlagUpdateRequest::default_instance_->InitAsDefaultInstance();
  SubscriptionUpdateRequest::default_instance_->InitAsDefaultInstance();
  SubscriptionUpdateResponse::default_instance_->InitAsDefaultInstance();
  IsIgrAddressRequest::default_instance_->InitAsDefaultInstance();
  AccountServiceRegion::default_instance_->InitAsDefaultInstance();
  AccountServiceConfig::default_instance_->InitAsDefaultInstance();
  GetAccountStateRequest::default_instance_->InitAsDefaultInstance();
  GetAccountStateResponse::default_instance_->InitAsDefaultInstance();
  GetGameAccountStateRequest::default_instance_->InitAsDefaultInstance();
  GetGameAccountStateResponse::default_instance_->InitAsDefaultInstance();
  GetLicensesRequest::default_instance_->InitAsDefaultInstance();
  GetLicensesResponse::default_instance_->InitAsDefaultInstance();
  GetGameSessionInfoRequest::default_instance_->InitAsDefaultInstance();
  GetGameSessionInfoResponse::default_instance_->InitAsDefaultInstance();
  GetGameTimeRemainingInfoRequest::default_instance_->InitAsDefaultInstance();
  GetGameTimeRemainingInfoResponse::default_instance_->InitAsDefaultInstance();
  GetCAISInfoRequest::default_instance_->InitAsDefaultInstance();
  GetCAISInfoResponse::default_instance_->InitAsDefaultInstance();
  ForwardCacheExpireRequest::default_instance_->InitAsDefaultInstance();
  GetAuthorizedDataRequest::default_instance_->InitAsDefaultInstance();
  GetAuthorizedDataResponse::default_instance_->InitAsDefaultInstance();
  UpdateParentalControlsAndCAISRequest::default_instance_->InitAsDefaultInstance();
  QueueDeductRecordRequest::default_instance_->InitAsDefaultInstance();
  GetGameAccountRequest::default_instance_->InitAsDefaultInstance();
  GetGameAccountResponse::default_instance_->InitAsDefaultInstance();
  AccountStateNotification::default_instance_->InitAsDefaultInstance();
  GameAccountStateNotification::default_instance_->InitAsDefaultInstance();
  GameAccountNotification::default_instance_->InitAsDefaultInstance();
  GameAccountSessionNotification::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_account_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_account_5fservice_2eproto {
  StaticDescriptorInitializer_account_5fservice_2eproto() {
    protobuf_AddDesc_account_5fservice_2eproto();
  }
} static_descriptor_initializer_account_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int GetAccountRequest::kRefFieldNumber;
const int GetAccountRequest::kReloadFieldNumber;
const int GetAccountRequest::kFetchAllFieldNumber;
const int GetAccountRequest::kFetchBlobFieldNumber;
const int GetAccountRequest::kFetchIdFieldNumber;
const int GetAccountRequest::kFetchEmailFieldNumber;
const int GetAccountRequest::kFetchBattleTagFieldNumber;
const int GetAccountRequest::kFetchFullNameFieldNumber;
const int GetAccountRequest::kFetchLinksFieldNumber;
const int GetAccountRequest::kFetchParentalControlsFieldNumber;
const int GetAccountRequest::kFetchCaisIdFieldNumber;
#endif  // !_MSC_VER

GetAccountRequest::GetAccountRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAccountRequest)
}

void GetAccountRequest::InitAsDefaultInstance() {
  ref_ = const_cast< ::bgs::protocol::account::v1::AccountReference*>(&::bgs::protocol::account::v1::AccountReference::default_instance());
}

GetAccountRequest::GetAccountRequest(const GetAccountRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAccountRequest)
}

void GetAccountRequest::SharedCtor() {
  _cached_size_ = 0;
  ref_ = NULL;
  reload_ = false;
  fetch_all_ = false;
  fetch_blob_ = false;
  fetch_id_ = false;
  fetch_email_ = false;
  fetch_battle_tag_ = false;
  fetch_full_name_ = false;
  fetch_links_ = false;
  fetch_parental_controls_ = false;
  fetch_cais_id_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAccountRequest::~GetAccountRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAccountRequest)
  SharedDtor();
}

void GetAccountRequest::SharedDtor() {
  if (this != default_instance_) {
    delete ref_;
  }
}

void GetAccountRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAccountRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAccountRequest_descriptor_;
}

const GetAccountRequest& GetAccountRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAccountRequest* GetAccountRequest::default_instance_ = NULL;

GetAccountRequest* GetAccountRequest::New() const {
  return new GetAccountRequest;
}

void GetAccountRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GetAccountRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(reload_, fetch_full_name_);
    if (has_ref()) {
      if (ref_ != NULL) ref_->::bgs::protocol::account::v1::AccountReference::Clear();
    }
  }
  ZR_(fetch_links_, fetch_cais_id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAccountRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAccountRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountReference ref = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_ref()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_reload;
        break;
      }

      // optional bool reload = 2 [default = false];
      case 2: {
        if (tag == 16) {
         parse_reload:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &reload_)));
          set_has_reload();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_fetch_all;
        break;
      }

      // optional bool fetch_all = 10 [default = false];
      case 10: {
        if (tag == 80) {
         parse_fetch_all:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_all_)));
          set_has_fetch_all();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_fetch_blob;
        break;
      }

      // optional bool fetch_blob = 11 [default = false];
      case 11: {
        if (tag == 88) {
         parse_fetch_blob:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_blob_)));
          set_has_fetch_blob();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_fetch_id;
        break;
      }

      // optional bool fetch_id = 12 [default = false];
      case 12: {
        if (tag == 96) {
         parse_fetch_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_id_)));
          set_has_fetch_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(104)) goto parse_fetch_email;
        break;
      }

      // optional bool fetch_email = 13 [default = false];
      case 13: {
        if (tag == 104) {
         parse_fetch_email:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_email_)));
          set_has_fetch_email();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(112)) goto parse_fetch_battle_tag;
        break;
      }

      // optional bool fetch_battle_tag = 14 [default = false];
      case 14: {
        if (tag == 112) {
         parse_fetch_battle_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_battle_tag_)));
          set_has_fetch_battle_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(120)) goto parse_fetch_full_name;
        break;
      }

      // optional bool fetch_full_name = 15 [default = false];
      case 15: {
        if (tag == 120) {
         parse_fetch_full_name:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_full_name_)));
          set_has_fetch_full_name();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(128)) goto parse_fetch_links;
        break;
      }

      // optional bool fetch_links = 16 [default = false];
      case 16: {
        if (tag == 128) {
         parse_fetch_links:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_links_)));
          set_has_fetch_links();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(136)) goto parse_fetch_parental_controls;
        break;
      }

      // optional bool fetch_parental_controls = 17 [default = false];
      case 17: {
        if (tag == 136) {
         parse_fetch_parental_controls:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_parental_controls_)));
          set_has_fetch_parental_controls();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(144)) goto parse_fetch_cais_id;
        break;
      }

      // optional bool fetch_cais_id = 18 [default = false];
      case 18: {
        if (tag == 144) {
         parse_fetch_cais_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_cais_id_)));
          set_has_fetch_cais_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAccountRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAccountRequest)
  return false;
#undef DO_
}

void GetAccountRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAccountRequest)
  // optional .bgs.protocol.account.v1.AccountReference ref = 1;
  if (has_ref()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->ref(), output);
  }

  // optional bool reload = 2 [default = false];
  if (has_reload()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->reload(), output);
  }

  // optional bool fetch_all = 10 [default = false];
  if (has_fetch_all()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(10, this->fetch_all(), output);
  }

  // optional bool fetch_blob = 11 [default = false];
  if (has_fetch_blob()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(11, this->fetch_blob(), output);
  }

  // optional bool fetch_id = 12 [default = false];
  if (has_fetch_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(12, this->fetch_id(), output);
  }

  // optional bool fetch_email = 13 [default = false];
  if (has_fetch_email()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(13, this->fetch_email(), output);
  }

  // optional bool fetch_battle_tag = 14 [default = false];
  if (has_fetch_battle_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(14, this->fetch_battle_tag(), output);
  }

  // optional bool fetch_full_name = 15 [default = false];
  if (has_fetch_full_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(15, this->fetch_full_name(), output);
  }

  // optional bool fetch_links = 16 [default = false];
  if (has_fetch_links()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(16, this->fetch_links(), output);
  }

  // optional bool fetch_parental_controls = 17 [default = false];
  if (has_fetch_parental_controls()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(17, this->fetch_parental_controls(), output);
  }

  // optional bool fetch_cais_id = 18 [default = false];
  if (has_fetch_cais_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(18, this->fetch_cais_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAccountRequest)
}

::google::protobuf::uint8* GetAccountRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAccountRequest)
  // optional .bgs.protocol.account.v1.AccountReference ref = 1;
  if (has_ref()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->ref(), target);
  }

  // optional bool reload = 2 [default = false];
  if (has_reload()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->reload(), target);
  }

  // optional bool fetch_all = 10 [default = false];
  if (has_fetch_all()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(10, this->fetch_all(), target);
  }

  // optional bool fetch_blob = 11 [default = false];
  if (has_fetch_blob()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(11, this->fetch_blob(), target);
  }

  // optional bool fetch_id = 12 [default = false];
  if (has_fetch_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(12, this->fetch_id(), target);
  }

  // optional bool fetch_email = 13 [default = false];
  if (has_fetch_email()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(13, this->fetch_email(), target);
  }

  // optional bool fetch_battle_tag = 14 [default = false];
  if (has_fetch_battle_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(14, this->fetch_battle_tag(), target);
  }

  // optional bool fetch_full_name = 15 [default = false];
  if (has_fetch_full_name()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(15, this->fetch_full_name(), target);
  }

  // optional bool fetch_links = 16 [default = false];
  if (has_fetch_links()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(16, this->fetch_links(), target);
  }

  // optional bool fetch_parental_controls = 17 [default = false];
  if (has_fetch_parental_controls()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(17, this->fetch_parental_controls(), target);
  }

  // optional bool fetch_cais_id = 18 [default = false];
  if (has_fetch_cais_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(18, this->fetch_cais_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAccountRequest)
  return target;
}

int GetAccountRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountReference ref = 1;
    if (has_ref()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->ref());
    }

    // optional bool reload = 2 [default = false];
    if (has_reload()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_all = 10 [default = false];
    if (has_fetch_all()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_blob = 11 [default = false];
    if (has_fetch_blob()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_id = 12 [default = false];
    if (has_fetch_id()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_email = 13 [default = false];
    if (has_fetch_email()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_battle_tag = 14 [default = false];
    if (has_fetch_battle_tag()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_full_name = 15 [default = false];
    if (has_fetch_full_name()) {
      total_size += 1 + 1;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool fetch_links = 16 [default = false];
    if (has_fetch_links()) {
      total_size += 2 + 1;
    }

    // optional bool fetch_parental_controls = 17 [default = false];
    if (has_fetch_parental_controls()) {
      total_size += 2 + 1;
    }

    // optional bool fetch_cais_id = 18 [default = false];
    if (has_fetch_cais_id()) {
      total_size += 2 + 1;
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

void GetAccountRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAccountRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAccountRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAccountRequest::MergeFrom(const GetAccountRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_ref()) {
      mutable_ref()->::bgs::protocol::account::v1::AccountReference::MergeFrom(from.ref());
    }
    if (from.has_reload()) {
      set_reload(from.reload());
    }
    if (from.has_fetch_all()) {
      set_fetch_all(from.fetch_all());
    }
    if (from.has_fetch_blob()) {
      set_fetch_blob(from.fetch_blob());
    }
    if (from.has_fetch_id()) {
      set_fetch_id(from.fetch_id());
    }
    if (from.has_fetch_email()) {
      set_fetch_email(from.fetch_email());
    }
    if (from.has_fetch_battle_tag()) {
      set_fetch_battle_tag(from.fetch_battle_tag());
    }
    if (from.has_fetch_full_name()) {
      set_fetch_full_name(from.fetch_full_name());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_fetch_links()) {
      set_fetch_links(from.fetch_links());
    }
    if (from.has_fetch_parental_controls()) {
      set_fetch_parental_controls(from.fetch_parental_controls());
    }
    if (from.has_fetch_cais_id()) {
      set_fetch_cais_id(from.fetch_cais_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAccountRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAccountRequest::CopyFrom(const GetAccountRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAccountRequest::IsInitialized() const {

  if (has_ref()) {
    if (!this->ref().IsInitialized()) return false;
  }
  return true;
}

void GetAccountRequest::Swap(GetAccountRequest* other) {
  if (other != this) {
    std::swap(ref_, other->ref_);
    std::swap(reload_, other->reload_);
    std::swap(fetch_all_, other->fetch_all_);
    std::swap(fetch_blob_, other->fetch_blob_);
    std::swap(fetch_id_, other->fetch_id_);
    std::swap(fetch_email_, other->fetch_email_);
    std::swap(fetch_battle_tag_, other->fetch_battle_tag_);
    std::swap(fetch_full_name_, other->fetch_full_name_);
    std::swap(fetch_links_, other->fetch_links_);
    std::swap(fetch_parental_controls_, other->fetch_parental_controls_);
    std::swap(fetch_cais_id_, other->fetch_cais_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAccountRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAccountRequest_descriptor_;
  metadata.reflection = GetAccountRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAccountResponse::kBlobFieldNumber;
const int GetAccountResponse::kIdFieldNumber;
const int GetAccountResponse::kEmailFieldNumber;
const int GetAccountResponse::kBattleTagFieldNumber;
const int GetAccountResponse::kFullNameFieldNumber;
const int GetAccountResponse::kLinksFieldNumber;
const int GetAccountResponse::kParentalControlInfoFieldNumber;
const int GetAccountResponse::kCaisIdFieldNumber;
#endif  // !_MSC_VER

GetAccountResponse::GetAccountResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAccountResponse)
}

void GetAccountResponse::InitAsDefaultInstance() {
  blob_ = const_cast< ::bgs::protocol::account::v1::AccountBlob*>(&::bgs::protocol::account::v1::AccountBlob::default_instance());
  id_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
  parental_control_info_ = const_cast< ::bgs::protocol::account::v1::ParentalControlInfo*>(&::bgs::protocol::account::v1::ParentalControlInfo::default_instance());
}

GetAccountResponse::GetAccountResponse(const GetAccountResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAccountResponse)
}

void GetAccountResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  blob_ = NULL;
  id_ = NULL;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  parental_control_info_ = NULL;
  cais_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAccountResponse::~GetAccountResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAccountResponse)
  SharedDtor();
}

void GetAccountResponse::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete full_name_;
  }
  if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete cais_id_;
  }
  if (this != default_instance_) {
    delete blob_;
    delete id_;
    delete parental_control_info_;
  }
}

void GetAccountResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAccountResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAccountResponse_descriptor_;
}

const GetAccountResponse& GetAccountResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAccountResponse* GetAccountResponse::default_instance_ = NULL;

GetAccountResponse* GetAccountResponse::New() const {
  return new GetAccountResponse;
}

void GetAccountResponse::Clear() {
  if (_has_bits_[0 / 32] & 219) {
    if (has_blob()) {
      if (blob_ != NULL) blob_->::bgs::protocol::account::v1::AccountBlob::Clear();
    }
    if (has_id()) {
      if (id_ != NULL) id_->::bgs::protocol::account::v1::AccountId::Clear();
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    if (has_full_name()) {
      if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        full_name_->clear();
      }
    }
    if (has_parental_control_info()) {
      if (parental_control_info_ != NULL) parental_control_info_->::bgs::protocol::account::v1::ParentalControlInfo::Clear();
    }
    if (has_cais_id()) {
      if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        cais_id_->clear();
      }
    }
  }
  email_.Clear();
  links_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAccountResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAccountResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountBlob blob = 11;
      case 11: {
        if (tag == 90) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_blob()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_id;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountId id = 12;
      case 12: {
        if (tag == 98) {
         parse_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_email;
        break;
      }

      // repeated string email = 13;
      case 13: {
        if (tag == 106) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email(this->email_size() - 1).data(),
            this->email(this->email_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_email;
        if (input->ExpectTag(114)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 14;
      case 14: {
        if (tag == 114) {
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
        if (input->ExpectTag(122)) goto parse_full_name;
        break;
      }

      // optional string full_name = 15;
      case 15: {
        if (tag == 122) {
         parse_full_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_full_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->full_name().data(), this->full_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "full_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(130)) goto parse_links;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameAccountLink links = 16;
      case 16: {
        if (tag == 130) {
         parse_links:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_links()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(130)) goto parse_links;
        if (input->ExpectTag(138)) goto parse_parental_control_info;
        break;
      }

      // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 17;
      case 17: {
        if (tag == 138) {
         parse_parental_control_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_parental_control_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(146)) goto parse_cais_id;
        break;
      }

      // optional string cais_id = 18;
      case 18: {
        if (tag == 146) {
         parse_cais_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_cais_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->cais_id().data(), this->cais_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "cais_id");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAccountResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAccountResponse)
  return false;
#undef DO_
}

void GetAccountResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAccountResponse)
  // optional .bgs.protocol.account.v1.AccountBlob blob = 11;
  if (has_blob()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->blob(), output);
  }

  // optional .bgs.protocol.account.v1.AccountId id = 12;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->id(), output);
  }

  // repeated string email = 13;
  for (int i = 0; i < this->email_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->email(i).data(), this->email(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "email");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      13, this->email(i), output);
  }

  // optional string battle_tag = 14;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      14, this->battle_tag(), output);
  }

  // optional string full_name = 15;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      15, this->full_name(), output);
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink links = 16;
  for (int i = 0; i < this->links_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      16, this->links(i), output);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 17;
  if (has_parental_control_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      17, this->parental_control_info(), output);
  }

  // optional string cais_id = 18;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      18, this->cais_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAccountResponse)
}

::google::protobuf::uint8* GetAccountResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAccountResponse)
  // optional .bgs.protocol.account.v1.AccountBlob blob = 11;
  if (has_blob()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->blob(), target);
  }

  // optional .bgs.protocol.account.v1.AccountId id = 12;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->id(), target);
  }

  // repeated string email = 13;
  for (int i = 0; i < this->email_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email(i).data(), this->email(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(13, this->email(i), target);
  }

  // optional string battle_tag = 14;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        14, this->battle_tag(), target);
  }

  // optional string full_name = 15;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        15, this->full_name(), target);
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink links = 16;
  for (int i = 0; i < this->links_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        16, this->links(i), target);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 17;
  if (has_parental_control_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        17, this->parental_control_info(), target);
  }

  // optional string cais_id = 18;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        18, this->cais_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAccountResponse)
  return target;
}

int GetAccountResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountBlob blob = 11;
    if (has_blob()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->blob());
    }

    // optional .bgs.protocol.account.v1.AccountId id = 12;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // optional string battle_tag = 14;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional string full_name = 15;
    if (has_full_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->full_name());
    }

    // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 17;
    if (has_parental_control_info()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->parental_control_info());
    }

    // optional string cais_id = 18;
    if (has_cais_id()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->cais_id());
    }

  }
  // repeated string email = 13;
  total_size += 1 * this->email_size();
  for (int i = 0; i < this->email_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->email(i));
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink links = 16;
  total_size += 2 * this->links_size();
  for (int i = 0; i < this->links_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->links(i));
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

void GetAccountResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAccountResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAccountResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAccountResponse::MergeFrom(const GetAccountResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  email_.MergeFrom(from.email_);
  links_.MergeFrom(from.links_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_blob()) {
      mutable_blob()->::bgs::protocol::account::v1::AccountBlob::MergeFrom(from.blob());
    }
    if (from.has_id()) {
      mutable_id()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.id());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_full_name()) {
      set_full_name(from.full_name());
    }
    if (from.has_parental_control_info()) {
      mutable_parental_control_info()->::bgs::protocol::account::v1::ParentalControlInfo::MergeFrom(from.parental_control_info());
    }
    if (from.has_cais_id()) {
      set_cais_id(from.cais_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAccountResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAccountResponse::CopyFrom(const GetAccountResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAccountResponse::IsInitialized() const {

  if (has_blob()) {
    if (!this->blob().IsInitialized()) return false;
  }
  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->links())) return false;
  return true;
}

void GetAccountResponse::Swap(GetAccountResponse* other) {
  if (other != this) {
    std::swap(blob_, other->blob_);
    std::swap(id_, other->id_);
    email_.Swap(&other->email_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(full_name_, other->full_name_);
    links_.Swap(&other->links_);
    std::swap(parental_control_info_, other->parental_control_info_);
    std::swap(cais_id_, other->cais_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAccountResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAccountResponse_descriptor_;
  metadata.reflection = GetAccountResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CreateGameAccountRequest::kAccountFieldNumber;
const int CreateGameAccountRequest::kRegionFieldNumber;
const int CreateGameAccountRequest::kProgramFieldNumber;
const int CreateGameAccountRequest::kRealmPermissionsFieldNumber;
const int CreateGameAccountRequest::kAccountRegionFieldNumber;
const int CreateGameAccountRequest::kPlatformFieldNumber;
#endif  // !_MSC_VER

CreateGameAccountRequest::CreateGameAccountRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CreateGameAccountRequest)
}

void CreateGameAccountRequest::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
}

CreateGameAccountRequest::CreateGameAccountRequest(const CreateGameAccountRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CreateGameAccountRequest)
}

void CreateGameAccountRequest::SharedCtor() {
  _cached_size_ = 0;
  account_ = NULL;
  region_ = 0u;
  program_ = 0u;
  realm_permissions_ = 0u;
  account_region_ = 0u;
  platform_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CreateGameAccountRequest::~CreateGameAccountRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CreateGameAccountRequest)
  SharedDtor();
}

void CreateGameAccountRequest::SharedDtor() {
  if (this != default_instance_) {
    delete account_;
  }
}

void CreateGameAccountRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreateGameAccountRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CreateGameAccountRequest_descriptor_;
}

const CreateGameAccountRequest& CreateGameAccountRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

CreateGameAccountRequest* CreateGameAccountRequest::default_instance_ = NULL;

CreateGameAccountRequest* CreateGameAccountRequest::New() const {
  return new CreateGameAccountRequest;
}

void CreateGameAccountRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<CreateGameAccountRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(region_, platform_);
    if (has_account()) {
      if (account_ != NULL) account_->::bgs::protocol::account::v1::AccountId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CreateGameAccountRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CreateGameAccountRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountId account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_region;
        break;
      }

      // optional uint32 region = 2;
      case 2: {
        if (tag == 16) {
         parse_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_program;
        break;
      }

      // optional fixed32 program = 3;
      case 3: {
        if (tag == 29) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_realm_permissions;
        break;
      }

      // optional uint32 realm_permissions = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_realm_permissions:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &realm_permissions_)));
          set_has_realm_permissions();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_account_region;
        break;
      }

      // optional uint32 account_region = 5;
      case 5: {
        if (tag == 40) {
         parse_account_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &account_region_)));
          set_has_account_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(53)) goto parse_platform;
        break;
      }

      // optional fixed32 platform = 6;
      case 6: {
        if (tag == 53) {
         parse_platform:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &platform_)));
          set_has_platform();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CreateGameAccountRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CreateGameAccountRequest)
  return false;
#undef DO_
}

void CreateGameAccountRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CreateGameAccountRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->region(), output);
  }

  // optional fixed32 program = 3;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->program(), output);
  }

  // optional uint32 realm_permissions = 4 [default = 0];
  if (has_realm_permissions()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->realm_permissions(), output);
  }

  // optional uint32 account_region = 5;
  if (has_account_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->account_region(), output);
  }

  // optional fixed32 platform = 6;
  if (has_platform()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(6, this->platform(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CreateGameAccountRequest)
}

::google::protobuf::uint8* CreateGameAccountRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CreateGameAccountRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->region(), target);
  }

  // optional fixed32 program = 3;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->program(), target);
  }

  // optional uint32 realm_permissions = 4 [default = 0];
  if (has_realm_permissions()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->realm_permissions(), target);
  }

  // optional uint32 account_region = 5;
  if (has_account_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->account_region(), target);
  }

  // optional fixed32 platform = 6;
  if (has_platform()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(6, this->platform(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CreateGameAccountRequest)
  return target;
}

int CreateGameAccountRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
    }

    // optional uint32 region = 2;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

    // optional fixed32 program = 3;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional uint32 realm_permissions = 4 [default = 0];
    if (has_realm_permissions()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->realm_permissions());
    }

    // optional uint32 account_region = 5;
    if (has_account_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->account_region());
    }

    // optional fixed32 platform = 6;
    if (has_platform()) {
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

void CreateGameAccountRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CreateGameAccountRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CreateGameAccountRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CreateGameAccountRequest::MergeFrom(const CreateGameAccountRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.account());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_realm_permissions()) {
      set_realm_permissions(from.realm_permissions());
    }
    if (from.has_account_region()) {
      set_account_region(from.account_region());
    }
    if (from.has_platform()) {
      set_platform(from.platform());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CreateGameAccountRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreateGameAccountRequest::CopyFrom(const CreateGameAccountRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateGameAccountRequest::IsInitialized() const {

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  return true;
}

void CreateGameAccountRequest::Swap(CreateGameAccountRequest* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(region_, other->region_);
    std::swap(program_, other->program_);
    std::swap(realm_permissions_, other->realm_permissions_);
    std::swap(account_region_, other->account_region_);
    std::swap(platform_, other->platform_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CreateGameAccountRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CreateGameAccountRequest_descriptor_;
  metadata.reflection = CreateGameAccountRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CreateGameAccountResponse::kGameAccountFieldNumber;
#endif  // !_MSC_VER

CreateGameAccountResponse::CreateGameAccountResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CreateGameAccountResponse)
}

void CreateGameAccountResponse::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

CreateGameAccountResponse::CreateGameAccountResponse(const CreateGameAccountResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CreateGameAccountResponse)
}

void CreateGameAccountResponse::SharedCtor() {
  _cached_size_ = 0;
  game_account_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CreateGameAccountResponse::~CreateGameAccountResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CreateGameAccountResponse)
  SharedDtor();
}

void CreateGameAccountResponse::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_;
  }
}

void CreateGameAccountResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreateGameAccountResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CreateGameAccountResponse_descriptor_;
}

const CreateGameAccountResponse& CreateGameAccountResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

CreateGameAccountResponse* CreateGameAccountResponse::default_instance_ = NULL;

CreateGameAccountResponse* CreateGameAccountResponse::New() const {
  return new CreateGameAccountResponse;
}

void CreateGameAccountResponse::Clear() {
  if (has_game_account()) {
    if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CreateGameAccountResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CreateGameAccountResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CreateGameAccountResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CreateGameAccountResponse)
  return false;
#undef DO_
}

void CreateGameAccountResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CreateGameAccountResponse)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CreateGameAccountResponse)
}

::google::protobuf::uint8* CreateGameAccountResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CreateGameAccountResponse)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CreateGameAccountResponse)
  return target;
}

int CreateGameAccountResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
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

void CreateGameAccountResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CreateGameAccountResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CreateGameAccountResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CreateGameAccountResponse::MergeFrom(const CreateGameAccountResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CreateGameAccountResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreateGameAccountResponse::CopyFrom(const CreateGameAccountResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateGameAccountResponse::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void CreateGameAccountResponse::Swap(CreateGameAccountResponse* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CreateGameAccountResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CreateGameAccountResponse_descriptor_;
  metadata.reflection = CreateGameAccountResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CacheExpireRequest::kAccountFieldNumber;
const int CacheExpireRequest::kGameAccountFieldNumber;
const int CacheExpireRequest::kEmailFieldNumber;
#endif  // !_MSC_VER

CacheExpireRequest::CacheExpireRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CacheExpireRequest)
}

void CacheExpireRequest::InitAsDefaultInstance() {
}

CacheExpireRequest::CacheExpireRequest(const CacheExpireRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CacheExpireRequest)
}

void CacheExpireRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CacheExpireRequest::~CacheExpireRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CacheExpireRequest)
  SharedDtor();
}

void CacheExpireRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CacheExpireRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CacheExpireRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CacheExpireRequest_descriptor_;
}

const CacheExpireRequest& CacheExpireRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

CacheExpireRequest* CacheExpireRequest::default_instance_ = NULL;

CacheExpireRequest* CacheExpireRequest::New() const {
  return new CacheExpireRequest;
}

void CacheExpireRequest::Clear() {
  account_.Clear();
  game_account_.Clear();
  email_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CacheExpireRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CacheExpireRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AccountId account = 1;
      case 1: {
        if (tag == 10) {
         parse_account:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_account;
        if (input->ExpectTag(18)) goto parse_game_account;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
      case 2: {
        if (tag == 18) {
         parse_game_account:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_game_account;
        if (input->ExpectTag(26)) goto parse_email;
        break;
      }

      // repeated string email = 3;
      case 3: {
        if (tag == 26) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email(this->email_size() - 1).data(),
            this->email(this->email_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_email;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CacheExpireRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CacheExpireRequest)
  return false;
#undef DO_
}

void CacheExpireRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CacheExpireRequest)
  // repeated .bgs.protocol.account.v1.AccountId account = 1;
  for (int i = 0; i < this->account_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(i), output);
  }

  // repeated .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
  for (int i = 0; i < this->game_account_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account(i), output);
  }

  // repeated string email = 3;
  for (int i = 0; i < this->email_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->email(i).data(), this->email(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "email");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->email(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CacheExpireRequest)
}

::google::protobuf::uint8* CacheExpireRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CacheExpireRequest)
  // repeated .bgs.protocol.account.v1.AccountId account = 1;
  for (int i = 0; i < this->account_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(i), target);
  }

  // repeated .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
  for (int i = 0; i < this->game_account_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account(i), target);
  }

  // repeated string email = 3;
  for (int i = 0; i < this->email_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email(i).data(), this->email(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->email(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CacheExpireRequest)
  return target;
}

int CacheExpireRequest::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.AccountId account = 1;
  total_size += 1 * this->account_size();
  for (int i = 0; i < this->account_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->account(i));
  }

  // repeated .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
  total_size += 1 * this->game_account_size();
  for (int i = 0; i < this->game_account_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_account(i));
  }

  // repeated string email = 3;
  total_size += 1 * this->email_size();
  for (int i = 0; i < this->email_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->email(i));
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

void CacheExpireRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CacheExpireRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CacheExpireRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CacheExpireRequest::MergeFrom(const CacheExpireRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  account_.MergeFrom(from.account_);
  game_account_.MergeFrom(from.game_account_);
  email_.MergeFrom(from.email_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CacheExpireRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CacheExpireRequest::CopyFrom(const CacheExpireRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CacheExpireRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->account())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->game_account())) return false;
  return true;
}

void CacheExpireRequest::Swap(CacheExpireRequest* other) {
  if (other != this) {
    account_.Swap(&other->account_);
    game_account_.Swap(&other->game_account_);
    email_.Swap(&other->email_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CacheExpireRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CacheExpireRequest_descriptor_;
  metadata.reflection = CacheExpireRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CredentialUpdateRequest::kAccountFieldNumber;
const int CredentialUpdateRequest::kOldCredentialsFieldNumber;
const int CredentialUpdateRequest::kNewCredentialsFieldNumber;
const int CredentialUpdateRequest::kRegionFieldNumber;
#endif  // !_MSC_VER

CredentialUpdateRequest::CredentialUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CredentialUpdateRequest)
}

void CredentialUpdateRequest::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
}

CredentialUpdateRequest::CredentialUpdateRequest(const CredentialUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CredentialUpdateRequest)
}

void CredentialUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  account_ = NULL;
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CredentialUpdateRequest::~CredentialUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CredentialUpdateRequest)
  SharedDtor();
}

void CredentialUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete account_;
  }
}

void CredentialUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CredentialUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CredentialUpdateRequest_descriptor_;
}

const CredentialUpdateRequest& CredentialUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

CredentialUpdateRequest* CredentialUpdateRequest::default_instance_ = NULL;

CredentialUpdateRequest* CredentialUpdateRequest::New() const {
  return new CredentialUpdateRequest;
}

void CredentialUpdateRequest::Clear() {
  if (_has_bits_[0 / 32] & 9) {
    if (has_account()) {
      if (account_ != NULL) account_->::bgs::protocol::account::v1::AccountId::Clear();
    }
    region_ = 0u;
  }
  old_credentials_.Clear();
  new_credentials_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CredentialUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CredentialUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.account.v1.AccountId account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_old_credentials;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountCredential old_credentials = 2;
      case 2: {
        if (tag == 18) {
         parse_old_credentials:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_old_credentials()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_old_credentials;
        if (input->ExpectTag(26)) goto parse_new_credentials;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountCredential new_credentials = 3;
      case 3: {
        if (tag == 26) {
         parse_new_credentials:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_new_credentials()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_new_credentials;
        if (input->ExpectTag(32)) goto parse_region;
        break;
      }

      // optional uint32 region = 4;
      case 4: {
        if (tag == 32) {
         parse_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CredentialUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CredentialUpdateRequest)
  return false;
#undef DO_
}

void CredentialUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CredentialUpdateRequest)
  // required .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential old_credentials = 2;
  for (int i = 0; i < this->old_credentials_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->old_credentials(i), output);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential new_credentials = 3;
  for (int i = 0; i < this->new_credentials_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->new_credentials(i), output);
  }

  // optional uint32 region = 4;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CredentialUpdateRequest)
}

::google::protobuf::uint8* CredentialUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CredentialUpdateRequest)
  // required .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential old_credentials = 2;
  for (int i = 0; i < this->old_credentials_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->old_credentials(i), target);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential new_credentials = 3;
  for (int i = 0; i < this->new_credentials_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->new_credentials(i), target);
  }

  // optional uint32 region = 4;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CredentialUpdateRequest)
  return target;
}

int CredentialUpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.account.v1.AccountId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
    }

    // optional uint32 region = 4;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

  }
  // repeated .bgs.protocol.account.v1.AccountCredential old_credentials = 2;
  total_size += 1 * this->old_credentials_size();
  for (int i = 0; i < this->old_credentials_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->old_credentials(i));
  }

  // repeated .bgs.protocol.account.v1.AccountCredential new_credentials = 3;
  total_size += 1 * this->new_credentials_size();
  for (int i = 0; i < this->new_credentials_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->new_credentials(i));
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

void CredentialUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CredentialUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CredentialUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CredentialUpdateRequest::MergeFrom(const CredentialUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  old_credentials_.MergeFrom(from.old_credentials_);
  new_credentials_.MergeFrom(from.new_credentials_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.account());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CredentialUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CredentialUpdateRequest::CopyFrom(const CredentialUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CredentialUpdateRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->old_credentials())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->new_credentials())) return false;
  return true;
}

void CredentialUpdateRequest::Swap(CredentialUpdateRequest* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    old_credentials_.Swap(&other->old_credentials_);
    new_credentials_.Swap(&other->new_credentials_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CredentialUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CredentialUpdateRequest_descriptor_;
  metadata.reflection = CredentialUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

CredentialUpdateResponse::CredentialUpdateResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CredentialUpdateResponse)
}

void CredentialUpdateResponse::InitAsDefaultInstance() {
}

CredentialUpdateResponse::CredentialUpdateResponse(const CredentialUpdateResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CredentialUpdateResponse)
}

void CredentialUpdateResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CredentialUpdateResponse::~CredentialUpdateResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CredentialUpdateResponse)
  SharedDtor();
}

void CredentialUpdateResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CredentialUpdateResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CredentialUpdateResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CredentialUpdateResponse_descriptor_;
}

const CredentialUpdateResponse& CredentialUpdateResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

CredentialUpdateResponse* CredentialUpdateResponse::default_instance_ = NULL;

CredentialUpdateResponse* CredentialUpdateResponse::New() const {
  return new CredentialUpdateResponse;
}

void CredentialUpdateResponse::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CredentialUpdateResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CredentialUpdateResponse)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CredentialUpdateResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CredentialUpdateResponse)
  return false;
#undef DO_
}

void CredentialUpdateResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CredentialUpdateResponse)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CredentialUpdateResponse)
}

::google::protobuf::uint8* CredentialUpdateResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CredentialUpdateResponse)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CredentialUpdateResponse)
  return target;
}

int CredentialUpdateResponse::ByteSize() const {
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

void CredentialUpdateResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CredentialUpdateResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CredentialUpdateResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CredentialUpdateResponse::MergeFrom(const CredentialUpdateResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CredentialUpdateResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CredentialUpdateResponse::CopyFrom(const CredentialUpdateResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CredentialUpdateResponse::IsInitialized() const {

  return true;
}

void CredentialUpdateResponse::Swap(CredentialUpdateResponse* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CredentialUpdateResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CredentialUpdateResponse_descriptor_;
  metadata.reflection = CredentialUpdateResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountFlagUpdateRequest::kAccountFieldNumber;
const int AccountFlagUpdateRequest::kRegionFieldNumber;
const int AccountFlagUpdateRequest::kFlagFieldNumber;
const int AccountFlagUpdateRequest::kActiveFieldNumber;
#endif  // !_MSC_VER

AccountFlagUpdateRequest::AccountFlagUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountFlagUpdateRequest)
}

void AccountFlagUpdateRequest::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
}

AccountFlagUpdateRequest::AccountFlagUpdateRequest(const AccountFlagUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountFlagUpdateRequest)
}

void AccountFlagUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  account_ = NULL;
  region_ = 0u;
  flag_ = GOOGLE_ULONGLONG(0);
  active_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountFlagUpdateRequest::~AccountFlagUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  SharedDtor();
}

void AccountFlagUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete account_;
  }
}

void AccountFlagUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountFlagUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountFlagUpdateRequest_descriptor_;
}

const AccountFlagUpdateRequest& AccountFlagUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

AccountFlagUpdateRequest* AccountFlagUpdateRequest::default_instance_ = NULL;

AccountFlagUpdateRequest* AccountFlagUpdateRequest::New() const {
  return new AccountFlagUpdateRequest;
}

void AccountFlagUpdateRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountFlagUpdateRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(flag_, active_);
    if (has_account()) {
      if (account_ != NULL) account_->::bgs::protocol::account::v1::AccountId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountFlagUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountId account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_region;
        break;
      }

      // optional uint32 region = 2;
      case 2: {
        if (tag == 16) {
         parse_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_flag;
        break;
      }

      // optional uint64 flag = 3;
      case 3: {
        if (tag == 24) {
         parse_flag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &flag_)));
          set_has_flag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_active;
        break;
      }

      // optional bool active = 4;
      case 4: {
        if (tag == 32) {
         parse_active:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &active_)));
          set_has_active();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  return false;
#undef DO_
}

void AccountFlagUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->region(), output);
  }

  // optional uint64 flag = 3;
  if (has_flag()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->flag(), output);
  }

  // optional bool active = 4;
  if (has_active()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->active(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountFlagUpdateRequest)
}

::google::protobuf::uint8* AccountFlagUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->region(), target);
  }

  // optional uint64 flag = 3;
  if (has_flag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->flag(), target);
  }

  // optional bool active = 4;
  if (has_active()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->active(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountFlagUpdateRequest)
  return target;
}

int AccountFlagUpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
    }

    // optional uint32 region = 2;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

    // optional uint64 flag = 3;
    if (has_flag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->flag());
    }

    // optional bool active = 4;
    if (has_active()) {
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

void AccountFlagUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountFlagUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountFlagUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountFlagUpdateRequest::MergeFrom(const AccountFlagUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.account());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_flag()) {
      set_flag(from.flag());
    }
    if (from.has_active()) {
      set_active(from.active());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountFlagUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountFlagUpdateRequest::CopyFrom(const AccountFlagUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountFlagUpdateRequest::IsInitialized() const {

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  return true;
}

void AccountFlagUpdateRequest::Swap(AccountFlagUpdateRequest* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(region_, other->region_);
    std::swap(flag_, other->flag_);
    std::swap(active_, other->active_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountFlagUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountFlagUpdateRequest_descriptor_;
  metadata.reflection = AccountFlagUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountFlagUpdateRequest::kGameAccountFieldNumber;
const int GameAccountFlagUpdateRequest::kFlagFieldNumber;
const int GameAccountFlagUpdateRequest::kActiveFieldNumber;
#endif  // !_MSC_VER

GameAccountFlagUpdateRequest::GameAccountFlagUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
}

void GameAccountFlagUpdateRequest::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

GameAccountFlagUpdateRequest::GameAccountFlagUpdateRequest(const GameAccountFlagUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
}

void GameAccountFlagUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  game_account_ = NULL;
  flag_ = GOOGLE_ULONGLONG(0);
  active_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountFlagUpdateRequest::~GameAccountFlagUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  SharedDtor();
}

void GameAccountFlagUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_;
  }
}

void GameAccountFlagUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountFlagUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountFlagUpdateRequest_descriptor_;
}

const GameAccountFlagUpdateRequest& GameAccountFlagUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GameAccountFlagUpdateRequest* GameAccountFlagUpdateRequest::default_instance_ = NULL;

GameAccountFlagUpdateRequest* GameAccountFlagUpdateRequest::New() const {
  return new GameAccountFlagUpdateRequest;
}

void GameAccountFlagUpdateRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameAccountFlagUpdateRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(flag_, active_);
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountFlagUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_flag;
        break;
      }

      // optional uint64 flag = 2;
      case 2: {
        if (tag == 16) {
         parse_flag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &flag_)));
          set_has_flag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_active;
        break;
      }

      // optional bool active = 3;
      case 3: {
        if (tag == 24) {
         parse_active:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &active_)));
          set_has_active();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  return false;
#undef DO_
}

void GameAccountFlagUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional uint64 flag = 2;
  if (has_flag()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->flag(), output);
  }

  // optional bool active = 3;
  if (has_active()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->active(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
}

::google::protobuf::uint8* GameAccountFlagUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional uint64 flag = 2;
  if (has_flag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->flag(), target);
  }

  // optional bool active = 3;
  if (has_active()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->active(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountFlagUpdateRequest)
  return target;
}

int GameAccountFlagUpdateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional uint64 flag = 2;
    if (has_flag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->flag());
    }

    // optional bool active = 3;
    if (has_active()) {
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

void GameAccountFlagUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountFlagUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountFlagUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountFlagUpdateRequest::MergeFrom(const GameAccountFlagUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_flag()) {
      set_flag(from.flag());
    }
    if (from.has_active()) {
      set_active(from.active());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountFlagUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountFlagUpdateRequest::CopyFrom(const GameAccountFlagUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountFlagUpdateRequest::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void GameAccountFlagUpdateRequest::Swap(GameAccountFlagUpdateRequest* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(flag_, other->flag_);
    std::swap(active_, other->active_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountFlagUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountFlagUpdateRequest_descriptor_;
  metadata.reflection = GameAccountFlagUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SubscriptionUpdateRequest::kRefFieldNumber;
#endif  // !_MSC_VER

SubscriptionUpdateRequest::SubscriptionUpdateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.SubscriptionUpdateRequest)
}

void SubscriptionUpdateRequest::InitAsDefaultInstance() {
}

SubscriptionUpdateRequest::SubscriptionUpdateRequest(const SubscriptionUpdateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.SubscriptionUpdateRequest)
}

void SubscriptionUpdateRequest::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscriptionUpdateRequest::~SubscriptionUpdateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  SharedDtor();
}

void SubscriptionUpdateRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SubscriptionUpdateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscriptionUpdateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscriptionUpdateRequest_descriptor_;
}

const SubscriptionUpdateRequest& SubscriptionUpdateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

SubscriptionUpdateRequest* SubscriptionUpdateRequest::default_instance_ = NULL;

SubscriptionUpdateRequest* SubscriptionUpdateRequest::New() const {
  return new SubscriptionUpdateRequest;
}

void SubscriptionUpdateRequest::Clear() {
  ref_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscriptionUpdateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.SubscriberReference ref = 2;
      case 2: {
        if (tag == 18) {
         parse_ref:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_ref()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_ref;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  return false;
#undef DO_
}

void SubscriptionUpdateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 2;
  for (int i = 0; i < this->ref_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->ref(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.SubscriptionUpdateRequest)
}

::google::protobuf::uint8* SubscriptionUpdateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 2;
  for (int i = 0; i < this->ref_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->ref(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.SubscriptionUpdateRequest)
  return target;
}

int SubscriptionUpdateRequest::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 2;
  total_size += 1 * this->ref_size();
  for (int i = 0; i < this->ref_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->ref(i));
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

void SubscriptionUpdateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscriptionUpdateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscriptionUpdateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscriptionUpdateRequest::MergeFrom(const SubscriptionUpdateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  ref_.MergeFrom(from.ref_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscriptionUpdateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscriptionUpdateRequest::CopyFrom(const SubscriptionUpdateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscriptionUpdateRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->ref())) return false;
  return true;
}

void SubscriptionUpdateRequest::Swap(SubscriptionUpdateRequest* other) {
  if (other != this) {
    ref_.Swap(&other->ref_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscriptionUpdateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscriptionUpdateRequest_descriptor_;
  metadata.reflection = SubscriptionUpdateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SubscriptionUpdateResponse::kRefFieldNumber;
#endif  // !_MSC_VER

SubscriptionUpdateResponse::SubscriptionUpdateResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.SubscriptionUpdateResponse)
}

void SubscriptionUpdateResponse::InitAsDefaultInstance() {
}

SubscriptionUpdateResponse::SubscriptionUpdateResponse(const SubscriptionUpdateResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.SubscriptionUpdateResponse)
}

void SubscriptionUpdateResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscriptionUpdateResponse::~SubscriptionUpdateResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  SharedDtor();
}

void SubscriptionUpdateResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SubscriptionUpdateResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscriptionUpdateResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscriptionUpdateResponse_descriptor_;
}

const SubscriptionUpdateResponse& SubscriptionUpdateResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

SubscriptionUpdateResponse* SubscriptionUpdateResponse::default_instance_ = NULL;

SubscriptionUpdateResponse* SubscriptionUpdateResponse::New() const {
  return new SubscriptionUpdateResponse;
}

void SubscriptionUpdateResponse::Clear() {
  ref_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscriptionUpdateResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.SubscriberReference ref = 1;
      case 1: {
        if (tag == 10) {
         parse_ref:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_ref()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_ref;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  return false;
#undef DO_
}

void SubscriptionUpdateResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 1;
  for (int i = 0; i < this->ref_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->ref(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.SubscriptionUpdateResponse)
}

::google::protobuf::uint8* SubscriptionUpdateResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 1;
  for (int i = 0; i < this->ref_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->ref(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.SubscriptionUpdateResponse)
  return target;
}

int SubscriptionUpdateResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.SubscriberReference ref = 1;
  total_size += 1 * this->ref_size();
  for (int i = 0; i < this->ref_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->ref(i));
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

void SubscriptionUpdateResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscriptionUpdateResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscriptionUpdateResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscriptionUpdateResponse::MergeFrom(const SubscriptionUpdateResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  ref_.MergeFrom(from.ref_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscriptionUpdateResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscriptionUpdateResponse::CopyFrom(const SubscriptionUpdateResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscriptionUpdateResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->ref())) return false;
  return true;
}

void SubscriptionUpdateResponse::Swap(SubscriptionUpdateResponse* other) {
  if (other != this) {
    ref_.Swap(&other->ref_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscriptionUpdateResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscriptionUpdateResponse_descriptor_;
  metadata.reflection = SubscriptionUpdateResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int IsIgrAddressRequest::kClientAddressFieldNumber;
const int IsIgrAddressRequest::kRegionFieldNumber;
#endif  // !_MSC_VER

IsIgrAddressRequest::IsIgrAddressRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.IsIgrAddressRequest)
}

void IsIgrAddressRequest::InitAsDefaultInstance() {
}

IsIgrAddressRequest::IsIgrAddressRequest(const IsIgrAddressRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.IsIgrAddressRequest)
}

void IsIgrAddressRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  client_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

IsIgrAddressRequest::~IsIgrAddressRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.IsIgrAddressRequest)
  SharedDtor();
}

void IsIgrAddressRequest::SharedDtor() {
  if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete client_address_;
  }
  if (this != default_instance_) {
  }
}

void IsIgrAddressRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* IsIgrAddressRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IsIgrAddressRequest_descriptor_;
}

const IsIgrAddressRequest& IsIgrAddressRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

IsIgrAddressRequest* IsIgrAddressRequest::default_instance_ = NULL;

IsIgrAddressRequest* IsIgrAddressRequest::New() const {
  return new IsIgrAddressRequest;
}

void IsIgrAddressRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_client_address()) {
      if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        client_address_->clear();
      }
    }
    region_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool IsIgrAddressRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.IsIgrAddressRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string client_address = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->client_address().data(), this->client_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "client_address");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_region;
        break;
      }

      // optional uint32 region = 2;
      case 2: {
        if (tag == 16) {
         parse_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.IsIgrAddressRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.IsIgrAddressRequest)
  return false;
#undef DO_
}

void IsIgrAddressRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.IsIgrAddressRequest)
  // optional string client_address = 1;
  if (has_client_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_address().data(), this->client_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->client_address(), output);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.IsIgrAddressRequest)
}

::google::protobuf::uint8* IsIgrAddressRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.IsIgrAddressRequest)
  // optional string client_address = 1;
  if (has_client_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_address().data(), this->client_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->client_address(), target);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.IsIgrAddressRequest)
  return target;
}

int IsIgrAddressRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string client_address = 1;
    if (has_client_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_address());
    }

    // optional uint32 region = 2;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
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

void IsIgrAddressRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const IsIgrAddressRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const IsIgrAddressRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void IsIgrAddressRequest::MergeFrom(const IsIgrAddressRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_client_address()) {
      set_client_address(from.client_address());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void IsIgrAddressRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void IsIgrAddressRequest::CopyFrom(const IsIgrAddressRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool IsIgrAddressRequest::IsInitialized() const {

  return true;
}

void IsIgrAddressRequest::Swap(IsIgrAddressRequest* other) {
  if (other != this) {
    std::swap(client_address_, other->client_address_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata IsIgrAddressRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = IsIgrAddressRequest_descriptor_;
  metadata.reflection = IsIgrAddressRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountServiceRegion::kIdFieldNumber;
const int AccountServiceRegion::kShardFieldNumber;
#endif  // !_MSC_VER

AccountServiceRegion::AccountServiceRegion()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountServiceRegion)
}

void AccountServiceRegion::InitAsDefaultInstance() {
}

AccountServiceRegion::AccountServiceRegion(const AccountServiceRegion& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountServiceRegion)
}

void AccountServiceRegion::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  shard_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountServiceRegion::~AccountServiceRegion() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountServiceRegion)
  SharedDtor();
}

void AccountServiceRegion::SharedDtor() {
  if (shard_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete shard_;
  }
  if (this != default_instance_) {
  }
}

void AccountServiceRegion::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountServiceRegion::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountServiceRegion_descriptor_;
}

const AccountServiceRegion& AccountServiceRegion::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

AccountServiceRegion* AccountServiceRegion::default_instance_ = NULL;

AccountServiceRegion* AccountServiceRegion::New() const {
  return new AccountServiceRegion;
}

void AccountServiceRegion::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    id_ = 0u;
    if (has_shard()) {
      if (shard_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        shard_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountServiceRegion::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountServiceRegion)
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
        if (input->ExpectTag(18)) goto parse_shard;
        break;
      }

      // required string shard = 2;
      case 2: {
        if (tag == 18) {
         parse_shard:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_shard()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->shard().data(), this->shard().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "shard");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountServiceRegion)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountServiceRegion)
  return false;
#undef DO_
}

void AccountServiceRegion::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountServiceRegion)
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required string shard = 2;
  if (has_shard()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->shard().data(), this->shard().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "shard");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->shard(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountServiceRegion)
}

::google::protobuf::uint8* AccountServiceRegion::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountServiceRegion)
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // required string shard = 2;
  if (has_shard()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->shard().data(), this->shard().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "shard");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->shard(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountServiceRegion)
  return target;
}

int AccountServiceRegion::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required string shard = 2;
    if (has_shard()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->shard());
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

void AccountServiceRegion::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountServiceRegion* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountServiceRegion*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountServiceRegion::MergeFrom(const AccountServiceRegion& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_shard()) {
      set_shard(from.shard());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountServiceRegion::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountServiceRegion::CopyFrom(const AccountServiceRegion& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountServiceRegion::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void AccountServiceRegion::Swap(AccountServiceRegion* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(shard_, other->shard_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountServiceRegion::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountServiceRegion_descriptor_;
  metadata.reflection = AccountServiceRegion_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountServiceConfig::kRegionFieldNumber;
#endif  // !_MSC_VER

AccountServiceConfig::AccountServiceConfig()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountServiceConfig)
}

void AccountServiceConfig::InitAsDefaultInstance() {
}

AccountServiceConfig::AccountServiceConfig(const AccountServiceConfig& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountServiceConfig)
}

void AccountServiceConfig::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountServiceConfig::~AccountServiceConfig() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountServiceConfig)
  SharedDtor();
}

void AccountServiceConfig::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountServiceConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountServiceConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountServiceConfig_descriptor_;
}

const AccountServiceConfig& AccountServiceConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

AccountServiceConfig* AccountServiceConfig::default_instance_ = NULL;

AccountServiceConfig* AccountServiceConfig::New() const {
  return new AccountServiceConfig;
}

void AccountServiceConfig::Clear() {
  region_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountServiceConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountServiceConfig)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AccountServiceRegion region = 1;
      case 1: {
        if (tag == 10) {
         parse_region:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_region()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_region;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountServiceConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountServiceConfig)
  return false;
#undef DO_
}

void AccountServiceConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountServiceConfig)
  // repeated .bgs.protocol.account.v1.AccountServiceRegion region = 1;
  for (int i = 0; i < this->region_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->region(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountServiceConfig)
}

::google::protobuf::uint8* AccountServiceConfig::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountServiceConfig)
  // repeated .bgs.protocol.account.v1.AccountServiceRegion region = 1;
  for (int i = 0; i < this->region_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->region(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountServiceConfig)
  return target;
}

int AccountServiceConfig::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.AccountServiceRegion region = 1;
  total_size += 1 * this->region_size();
  for (int i = 0; i < this->region_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->region(i));
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

void AccountServiceConfig::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountServiceConfig* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountServiceConfig*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountServiceConfig::MergeFrom(const AccountServiceConfig& from) {
  GOOGLE_CHECK_NE(&from, this);
  region_.MergeFrom(from.region_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountServiceConfig::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountServiceConfig::CopyFrom(const AccountServiceConfig& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountServiceConfig::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->region())) return false;
  return true;
}

void AccountServiceConfig::Swap(AccountServiceConfig* other) {
  if (other != this) {
    region_.Swap(&other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountServiceConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountServiceConfig_descriptor_;
  metadata.reflection = AccountServiceConfig_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAccountStateRequest::kEntityIdFieldNumber;
const int GetAccountStateRequest::kProgramFieldNumber;
const int GetAccountStateRequest::kRegionFieldNumber;
const int GetAccountStateRequest::kOptionsFieldNumber;
const int GetAccountStateRequest::kTagsFieldNumber;
#endif  // !_MSC_VER

GetAccountStateRequest::GetAccountStateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAccountStateRequest)
}

void GetAccountStateRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  options_ = const_cast< ::bgs::protocol::account::v1::AccountFieldOptions*>(&::bgs::protocol::account::v1::AccountFieldOptions::default_instance());
  tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
}

GetAccountStateRequest::GetAccountStateRequest(const GetAccountStateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAccountStateRequest)
}

void GetAccountStateRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  program_ = 0u;
  region_ = 0u;
  options_ = NULL;
  tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAccountStateRequest::~GetAccountStateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAccountStateRequest)
  SharedDtor();
}

void GetAccountStateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
    delete options_;
    delete tags_;
  }
}

void GetAccountStateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAccountStateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAccountStateRequest_descriptor_;
}

const GetAccountStateRequest& GetAccountStateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAccountStateRequest* GetAccountStateRequest::default_instance_ = NULL;

GetAccountStateRequest* GetAccountStateRequest::New() const {
  return new GetAccountStateRequest;
}

void GetAccountStateRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GetAccountStateRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(program_, region_);
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_options()) {
      if (options_ != NULL) options_->::bgs::protocol::account::v1::AccountFieldOptions::Clear();
    }
    if (has_tags()) {
      if (tags_ != NULL) tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAccountStateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAccountStateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_program;
        break;
      }

      // optional uint32 program = 2;
      case 2: {
        if (tag == 16) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_region;
        break;
      }

      // optional uint32 region = 3;
      case 3: {
        if (tag == 24) {
         parse_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_options;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldOptions options = 10;
      case 10: {
        if (tag == 82) {
         parse_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags tags = 11;
      case 11: {
        if (tag == 90) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAccountStateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAccountStateRequest)
  return false;
#undef DO_
}

void GetAccountStateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAccountStateRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // optional uint32 program = 2;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->program(), output);
  }

  // optional uint32 region = 3;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->region(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldOptions options = 10;
  if (has_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->options(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags tags = 11;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAccountStateRequest)
}

::google::protobuf::uint8* GetAccountStateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAccountStateRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  // optional uint32 program = 2;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->program(), target);
  }

  // optional uint32 region = 3;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->region(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldOptions options = 10;
  if (has_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->options(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags tags = 11;
  if (has_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAccountStateRequest)
  return target;
}

int GetAccountStateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional uint32 program = 2;
    if (has_program()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->program());
    }

    // optional uint32 region = 3;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

    // optional .bgs.protocol.account.v1.AccountFieldOptions options = 10;
    if (has_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->options());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags tags = 11;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tags());
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

void GetAccountStateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAccountStateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAccountStateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAccountStateRequest::MergeFrom(const GetAccountStateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_options()) {
      mutable_options()->::bgs::protocol::account::v1::AccountFieldOptions::MergeFrom(from.options());
    }
    if (from.has_tags()) {
      mutable_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAccountStateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAccountStateRequest::CopyFrom(const GetAccountStateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAccountStateRequest::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void GetAccountStateRequest::Swap(GetAccountStateRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(program_, other->program_);
    std::swap(region_, other->region_);
    std::swap(options_, other->options_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAccountStateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAccountStateRequest_descriptor_;
  metadata.reflection = GetAccountStateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAccountStateResponse::kStateFieldNumber;
const int GetAccountStateResponse::kTagsFieldNumber;
#endif  // !_MSC_VER

GetAccountStateResponse::GetAccountStateResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAccountStateResponse)
}

void GetAccountStateResponse::InitAsDefaultInstance() {
  state_ = const_cast< ::bgs::protocol::account::v1::AccountState*>(&::bgs::protocol::account::v1::AccountState::default_instance());
  tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
}

GetAccountStateResponse::GetAccountStateResponse(const GetAccountStateResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAccountStateResponse)
}

void GetAccountStateResponse::SharedCtor() {
  _cached_size_ = 0;
  state_ = NULL;
  tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAccountStateResponse::~GetAccountStateResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAccountStateResponse)
  SharedDtor();
}

void GetAccountStateResponse::SharedDtor() {
  if (this != default_instance_) {
    delete state_;
    delete tags_;
  }
}

void GetAccountStateResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAccountStateResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAccountStateResponse_descriptor_;
}

const GetAccountStateResponse& GetAccountStateResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAccountStateResponse* GetAccountStateResponse::default_instance_ = NULL;

GetAccountStateResponse* GetAccountStateResponse::New() const {
  return new GetAccountStateResponse;
}

void GetAccountStateResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_state()) {
      if (state_ != NULL) state_->::bgs::protocol::account::v1::AccountState::Clear();
    }
    if (has_tags()) {
      if (tags_ != NULL) tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAccountStateResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAccountStateResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountState state = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags tags = 2;
      case 2: {
        if (tag == 18) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAccountStateResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAccountStateResponse)
  return false;
#undef DO_
}

void GetAccountStateResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAccountStateResponse)
  // optional .bgs.protocol.account.v1.AccountState state = 1;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->state(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags tags = 2;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAccountStateResponse)
}

::google::protobuf::uint8* GetAccountStateResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAccountStateResponse)
  // optional .bgs.protocol.account.v1.AccountState state = 1;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->state(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags tags = 2;
  if (has_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAccountStateResponse)
  return target;
}

int GetAccountStateResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountState state = 1;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags tags = 2;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tags());
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

void GetAccountStateResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAccountStateResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAccountStateResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAccountStateResponse::MergeFrom(const GetAccountStateResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_state()) {
      mutable_state()->::bgs::protocol::account::v1::AccountState::MergeFrom(from.state());
    }
    if (from.has_tags()) {
      mutable_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAccountStateResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAccountStateResponse::CopyFrom(const GetAccountStateResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAccountStateResponse::IsInitialized() const {

  if (has_state()) {
    if (!this->state().IsInitialized()) return false;
  }
  return true;
}

void GetAccountStateResponse::Swap(GetAccountStateResponse* other) {
  if (other != this) {
    std::swap(state_, other->state_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAccountStateResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAccountStateResponse_descriptor_;
  metadata.reflection = GetAccountStateResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameAccountStateRequest::kAccountIdFieldNumber;
const int GetGameAccountStateRequest::kGameAccountIdFieldNumber;
const int GetGameAccountStateRequest::kOptionsFieldNumber;
const int GetGameAccountStateRequest::kTagsFieldNumber;
#endif  // !_MSC_VER

GetGameAccountStateRequest::GetGameAccountStateRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameAccountStateRequest)
}

void GetGameAccountStateRequest::InitAsDefaultInstance() {
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  options_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldOptions*>(&::bgs::protocol::account::v1::GameAccountFieldOptions::default_instance());
  tags_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldTags*>(&::bgs::protocol::account::v1::GameAccountFieldTags::default_instance());
}

GetGameAccountStateRequest::GetGameAccountStateRequest(const GetGameAccountStateRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameAccountStateRequest)
}

void GetGameAccountStateRequest::SharedCtor() {
  _cached_size_ = 0;
  account_id_ = NULL;
  game_account_id_ = NULL;
  options_ = NULL;
  tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameAccountStateRequest::~GetGameAccountStateRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameAccountStateRequest)
  SharedDtor();
}

void GetGameAccountStateRequest::SharedDtor() {
  if (this != default_instance_) {
    delete account_id_;
    delete game_account_id_;
    delete options_;
    delete tags_;
  }
}

void GetGameAccountStateRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameAccountStateRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameAccountStateRequest_descriptor_;
}

const GetGameAccountStateRequest& GetGameAccountStateRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameAccountStateRequest* GetGameAccountStateRequest::default_instance_ = NULL;

GetGameAccountStateRequest* GetGameAccountStateRequest::New() const {
  return new GetGameAccountStateRequest;
}

void GetGameAccountStateRequest::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_options()) {
      if (options_ != NULL) options_->::bgs::protocol::account::v1::GameAccountFieldOptions::Clear();
    }
    if (has_tags()) {
      if (tags_ != NULL) tags_->::bgs::protocol::account::v1::GameAccountFieldTags::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameAccountStateRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameAccountStateRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId account_id = 1 [deprecated = true];
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_id()));
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
        if (input->ExpectTag(82)) goto parse_options;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldOptions options = 10;
      case 10: {
        if (tag == 82) {
         parse_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 11;
      case 11: {
        if (tag == 90) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameAccountStateRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameAccountStateRequest)
  return false;
#undef DO_
}

void GetGameAccountStateRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameAccountStateRequest)
  // optional .bgs.protocol.EntityId account_id = 1 [deprecated = true];
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_id(), output);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_id(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldOptions options = 10;
  if (has_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->options(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 11;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameAccountStateRequest)
}

::google::protobuf::uint8* GetGameAccountStateRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameAccountStateRequest)
  // optional .bgs.protocol.EntityId account_id = 1 [deprecated = true];
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_id(), target);
  }

  // optional .bgs.protocol.EntityId game_account_id = 2;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_id(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldOptions options = 10;
  if (has_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->options(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 11;
  if (has_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameAccountStateRequest)
  return target;
}

int GetGameAccountStateRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId account_id = 1 [deprecated = true];
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
    }

    // optional .bgs.protocol.EntityId game_account_id = 2;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldOptions options = 10;
    if (has_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->options());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 11;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tags());
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

void GetGameAccountStateRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameAccountStateRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameAccountStateRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameAccountStateRequest::MergeFrom(const GetGameAccountStateRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_options()) {
      mutable_options()->::bgs::protocol::account::v1::GameAccountFieldOptions::MergeFrom(from.options());
    }
    if (from.has_tags()) {
      mutable_tags()->::bgs::protocol::account::v1::GameAccountFieldTags::MergeFrom(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameAccountStateRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameAccountStateRequest::CopyFrom(const GetGameAccountStateRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameAccountStateRequest::IsInitialized() const {

  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  return true;
}

void GetGameAccountStateRequest::Swap(GetGameAccountStateRequest* other) {
  if (other != this) {
    std::swap(account_id_, other->account_id_);
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(options_, other->options_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameAccountStateRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameAccountStateRequest_descriptor_;
  metadata.reflection = GetGameAccountStateRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameAccountStateResponse::kStateFieldNumber;
const int GetGameAccountStateResponse::kTagsFieldNumber;
#endif  // !_MSC_VER

GetGameAccountStateResponse::GetGameAccountStateResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameAccountStateResponse)
}

void GetGameAccountStateResponse::InitAsDefaultInstance() {
  state_ = const_cast< ::bgs::protocol::account::v1::GameAccountState*>(&::bgs::protocol::account::v1::GameAccountState::default_instance());
  tags_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldTags*>(&::bgs::protocol::account::v1::GameAccountFieldTags::default_instance());
}

GetGameAccountStateResponse::GetGameAccountStateResponse(const GetGameAccountStateResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameAccountStateResponse)
}

void GetGameAccountStateResponse::SharedCtor() {
  _cached_size_ = 0;
  state_ = NULL;
  tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameAccountStateResponse::~GetGameAccountStateResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameAccountStateResponse)
  SharedDtor();
}

void GetGameAccountStateResponse::SharedDtor() {
  if (this != default_instance_) {
    delete state_;
    delete tags_;
  }
}

void GetGameAccountStateResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameAccountStateResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameAccountStateResponse_descriptor_;
}

const GetGameAccountStateResponse& GetGameAccountStateResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameAccountStateResponse* GetGameAccountStateResponse::default_instance_ = NULL;

GetGameAccountStateResponse* GetGameAccountStateResponse::New() const {
  return new GetGameAccountStateResponse;
}

void GetGameAccountStateResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_state()) {
      if (state_ != NULL) state_->::bgs::protocol::account::v1::GameAccountState::Clear();
    }
    if (has_tags()) {
      if (tags_ != NULL) tags_->::bgs::protocol::account::v1::GameAccountFieldTags::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameAccountStateResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameAccountStateResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountState state = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_state()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 2;
      case 2: {
        if (tag == 18) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameAccountStateResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameAccountStateResponse)
  return false;
#undef DO_
}

void GetGameAccountStateResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameAccountStateResponse)
  // optional .bgs.protocol.account.v1.GameAccountState state = 1;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->state(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 2;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameAccountStateResponse)
}

::google::protobuf::uint8* GetGameAccountStateResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameAccountStateResponse)
  // optional .bgs.protocol.account.v1.GameAccountState state = 1;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->state(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 2;
  if (has_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameAccountStateResponse)
  return target;
}

int GetGameAccountStateResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountState state = 1;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->state());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldTags tags = 2;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tags());
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

void GetGameAccountStateResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameAccountStateResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameAccountStateResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameAccountStateResponse::MergeFrom(const GetGameAccountStateResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_state()) {
      mutable_state()->::bgs::protocol::account::v1::GameAccountState::MergeFrom(from.state());
    }
    if (from.has_tags()) {
      mutable_tags()->::bgs::protocol::account::v1::GameAccountFieldTags::MergeFrom(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameAccountStateResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameAccountStateResponse::CopyFrom(const GetGameAccountStateResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameAccountStateResponse::IsInitialized() const {

  if (has_state()) {
    if (!this->state().IsInitialized()) return false;
  }
  return true;
}

void GetGameAccountStateResponse::Swap(GetGameAccountStateResponse* other) {
  if (other != this) {
    std::swap(state_, other->state_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameAccountStateResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameAccountStateResponse_descriptor_;
  metadata.reflection = GetGameAccountStateResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetLicensesRequest::kTargetIdFieldNumber;
const int GetLicensesRequest::kFetchAccountLicensesFieldNumber;
const int GetLicensesRequest::kFetchGameAccountLicensesFieldNumber;
const int GetLicensesRequest::kFetchDynamicAccountLicensesFieldNumber;
const int GetLicensesRequest::kProgramFieldNumber;
const int GetLicensesRequest::kExcludeUnknownProgramFieldNumber;
#endif  // !_MSC_VER

GetLicensesRequest::GetLicensesRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetLicensesRequest)
}

void GetLicensesRequest::InitAsDefaultInstance() {
  target_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetLicensesRequest::GetLicensesRequest(const GetLicensesRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetLicensesRequest)
}

void GetLicensesRequest::SharedCtor() {
  _cached_size_ = 0;
  target_id_ = NULL;
  fetch_account_licenses_ = false;
  fetch_game_account_licenses_ = false;
  fetch_dynamic_account_licenses_ = false;
  program_ = 0u;
  exclude_unknown_program_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetLicensesRequest::~GetLicensesRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetLicensesRequest)
  SharedDtor();
}

void GetLicensesRequest::SharedDtor() {
  if (this != default_instance_) {
    delete target_id_;
  }
}

void GetLicensesRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetLicensesRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetLicensesRequest_descriptor_;
}

const GetLicensesRequest& GetLicensesRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetLicensesRequest* GetLicensesRequest::default_instance_ = NULL;

GetLicensesRequest* GetLicensesRequest::New() const {
  return new GetLicensesRequest;
}

void GetLicensesRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GetLicensesRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(fetch_account_licenses_, program_);
    if (has_target_id()) {
      if (target_id_ != NULL) target_id_->::bgs::protocol::EntityId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetLicensesRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetLicensesRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId target_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_fetch_account_licenses;
        break;
      }

      // optional bool fetch_account_licenses = 2;
      case 2: {
        if (tag == 16) {
         parse_fetch_account_licenses:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_account_licenses_)));
          set_has_fetch_account_licenses();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_fetch_game_account_licenses;
        break;
      }

      // optional bool fetch_game_account_licenses = 3;
      case 3: {
        if (tag == 24) {
         parse_fetch_game_account_licenses:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_game_account_licenses_)));
          set_has_fetch_game_account_licenses();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_fetch_dynamic_account_licenses;
        break;
      }

      // optional bool fetch_dynamic_account_licenses = 4;
      case 4: {
        if (tag == 32) {
         parse_fetch_dynamic_account_licenses:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &fetch_dynamic_account_licenses_)));
          set_has_fetch_dynamic_account_licenses();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_program;
        break;
      }

      // optional fixed32 program = 5;
      case 5: {
        if (tag == 45) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_exclude_unknown_program;
        break;
      }

      // optional bool exclude_unknown_program = 6 [default = false];
      case 6: {
        if (tag == 48) {
         parse_exclude_unknown_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &exclude_unknown_program_)));
          set_has_exclude_unknown_program();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetLicensesRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetLicensesRequest)
  return false;
#undef DO_
}

void GetLicensesRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetLicensesRequest)
  // optional .bgs.protocol.EntityId target_id = 1;
  if (has_target_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target_id(), output);
  }

  // optional bool fetch_account_licenses = 2;
  if (has_fetch_account_licenses()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->fetch_account_licenses(), output);
  }

  // optional bool fetch_game_account_licenses = 3;
  if (has_fetch_game_account_licenses()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->fetch_game_account_licenses(), output);
  }

  // optional bool fetch_dynamic_account_licenses = 4;
  if (has_fetch_dynamic_account_licenses()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->fetch_dynamic_account_licenses(), output);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(5, this->program(), output);
  }

  // optional bool exclude_unknown_program = 6 [default = false];
  if (has_exclude_unknown_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->exclude_unknown_program(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetLicensesRequest)
}

::google::protobuf::uint8* GetLicensesRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetLicensesRequest)
  // optional .bgs.protocol.EntityId target_id = 1;
  if (has_target_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target_id(), target);
  }

  // optional bool fetch_account_licenses = 2;
  if (has_fetch_account_licenses()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->fetch_account_licenses(), target);
  }

  // optional bool fetch_game_account_licenses = 3;
  if (has_fetch_game_account_licenses()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->fetch_game_account_licenses(), target);
  }

  // optional bool fetch_dynamic_account_licenses = 4;
  if (has_fetch_dynamic_account_licenses()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->fetch_dynamic_account_licenses(), target);
  }

  // optional fixed32 program = 5;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(5, this->program(), target);
  }

  // optional bool exclude_unknown_program = 6 [default = false];
  if (has_exclude_unknown_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->exclude_unknown_program(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetLicensesRequest)
  return target;
}

int GetLicensesRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId target_id = 1;
    if (has_target_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target_id());
    }

    // optional bool fetch_account_licenses = 2;
    if (has_fetch_account_licenses()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_game_account_licenses = 3;
    if (has_fetch_game_account_licenses()) {
      total_size += 1 + 1;
    }

    // optional bool fetch_dynamic_account_licenses = 4;
    if (has_fetch_dynamic_account_licenses()) {
      total_size += 1 + 1;
    }

    // optional fixed32 program = 5;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional bool exclude_unknown_program = 6 [default = false];
    if (has_exclude_unknown_program()) {
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

void GetLicensesRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetLicensesRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetLicensesRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetLicensesRequest::MergeFrom(const GetLicensesRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target_id()) {
      mutable_target_id()->::bgs::protocol::EntityId::MergeFrom(from.target_id());
    }
    if (from.has_fetch_account_licenses()) {
      set_fetch_account_licenses(from.fetch_account_licenses());
    }
    if (from.has_fetch_game_account_licenses()) {
      set_fetch_game_account_licenses(from.fetch_game_account_licenses());
    }
    if (from.has_fetch_dynamic_account_licenses()) {
      set_fetch_dynamic_account_licenses(from.fetch_dynamic_account_licenses());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_exclude_unknown_program()) {
      set_exclude_unknown_program(from.exclude_unknown_program());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetLicensesRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetLicensesRequest::CopyFrom(const GetLicensesRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetLicensesRequest::IsInitialized() const {

  if (has_target_id()) {
    if (!this->target_id().IsInitialized()) return false;
  }
  return true;
}

void GetLicensesRequest::Swap(GetLicensesRequest* other) {
  if (other != this) {
    std::swap(target_id_, other->target_id_);
    std::swap(fetch_account_licenses_, other->fetch_account_licenses_);
    std::swap(fetch_game_account_licenses_, other->fetch_game_account_licenses_);
    std::swap(fetch_dynamic_account_licenses_, other->fetch_dynamic_account_licenses_);
    std::swap(program_, other->program_);
    std::swap(exclude_unknown_program_, other->exclude_unknown_program_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetLicensesRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetLicensesRequest_descriptor_;
  metadata.reflection = GetLicensesRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetLicensesResponse::kLicensesFieldNumber;
#endif  // !_MSC_VER

GetLicensesResponse::GetLicensesResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetLicensesResponse)
}

void GetLicensesResponse::InitAsDefaultInstance() {
}

GetLicensesResponse::GetLicensesResponse(const GetLicensesResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetLicensesResponse)
}

void GetLicensesResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetLicensesResponse::~GetLicensesResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetLicensesResponse)
  SharedDtor();
}

void GetLicensesResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetLicensesResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetLicensesResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetLicensesResponse_descriptor_;
}

const GetLicensesResponse& GetLicensesResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetLicensesResponse* GetLicensesResponse::default_instance_ = NULL;

GetLicensesResponse* GetLicensesResponse::New() const {
  return new GetLicensesResponse;
}

void GetLicensesResponse::Clear() {
  licenses_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetLicensesResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetLicensesResponse)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetLicensesResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetLicensesResponse)
  return false;
#undef DO_
}

void GetLicensesResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetLicensesResponse)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->licenses(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetLicensesResponse)
}

::google::protobuf::uint8* GetLicensesResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetLicensesResponse)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 1;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->licenses(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetLicensesResponse)
  return target;
}

int GetLicensesResponse::ByteSize() const {
  int total_size = 0;

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

void GetLicensesResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetLicensesResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetLicensesResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetLicensesResponse::MergeFrom(const GetLicensesResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  licenses_.MergeFrom(from.licenses_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetLicensesResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetLicensesResponse::CopyFrom(const GetLicensesResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetLicensesResponse::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  return true;
}

void GetLicensesResponse::Swap(GetLicensesResponse* other) {
  if (other != this) {
    licenses_.Swap(&other->licenses_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetLicensesResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetLicensesResponse_descriptor_;
  metadata.reflection = GetLicensesResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameSessionInfoRequest::kEntityIdFieldNumber;
#endif  // !_MSC_VER

GetGameSessionInfoRequest::GetGameSessionInfoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameSessionInfoRequest)
}

void GetGameSessionInfoRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetGameSessionInfoRequest::GetGameSessionInfoRequest(const GetGameSessionInfoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameSessionInfoRequest)
}

void GetGameSessionInfoRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameSessionInfoRequest::~GetGameSessionInfoRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  SharedDtor();
}

void GetGameSessionInfoRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void GetGameSessionInfoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameSessionInfoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameSessionInfoRequest_descriptor_;
}

const GetGameSessionInfoRequest& GetGameSessionInfoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameSessionInfoRequest* GetGameSessionInfoRequest::default_instance_ = NULL;

GetGameSessionInfoRequest* GetGameSessionInfoRequest::New() const {
  return new GetGameSessionInfoRequest;
}

void GetGameSessionInfoRequest::Clear() {
  if (has_entity_id()) {
    if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameSessionInfoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  return false;
#undef DO_
}

void GetGameSessionInfoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameSessionInfoRequest)
}

::google::protobuf::uint8* GetGameSessionInfoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameSessionInfoRequest)
  return target;
}

int GetGameSessionInfoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
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

void GetGameSessionInfoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameSessionInfoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameSessionInfoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameSessionInfoRequest::MergeFrom(const GetGameSessionInfoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameSessionInfoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameSessionInfoRequest::CopyFrom(const GetGameSessionInfoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameSessionInfoRequest::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void GetGameSessionInfoRequest::Swap(GetGameSessionInfoRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameSessionInfoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameSessionInfoRequest_descriptor_;
  metadata.reflection = GetGameSessionInfoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameSessionInfoResponse::kSessionInfoFieldNumber;
#endif  // !_MSC_VER

GetGameSessionInfoResponse::GetGameSessionInfoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameSessionInfoResponse)
}

void GetGameSessionInfoResponse::InitAsDefaultInstance() {
  session_info_ = const_cast< ::bgs::protocol::account::v1::GameSessionInfo*>(&::bgs::protocol::account::v1::GameSessionInfo::default_instance());
}

GetGameSessionInfoResponse::GetGameSessionInfoResponse(const GetGameSessionInfoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameSessionInfoResponse)
}

void GetGameSessionInfoResponse::SharedCtor() {
  _cached_size_ = 0;
  session_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameSessionInfoResponse::~GetGameSessionInfoResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  SharedDtor();
}

void GetGameSessionInfoResponse::SharedDtor() {
  if (this != default_instance_) {
    delete session_info_;
  }
}

void GetGameSessionInfoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameSessionInfoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameSessionInfoResponse_descriptor_;
}

const GetGameSessionInfoResponse& GetGameSessionInfoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameSessionInfoResponse* GetGameSessionInfoResponse::default_instance_ = NULL;

GetGameSessionInfoResponse* GetGameSessionInfoResponse::New() const {
  return new GetGameSessionInfoResponse;
}

void GetGameSessionInfoResponse::Clear() {
  if (has_session_info()) {
    if (session_info_ != NULL) session_info_->::bgs::protocol::account::v1::GameSessionInfo::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameSessionInfoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameSessionInfo session_info = 2;
      case 2: {
        if (tag == 18) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_session_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  return false;
#undef DO_
}

void GetGameSessionInfoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  // optional .bgs.protocol.account.v1.GameSessionInfo session_info = 2;
  if (has_session_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->session_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameSessionInfoResponse)
}

::google::protobuf::uint8* GetGameSessionInfoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  // optional .bgs.protocol.account.v1.GameSessionInfo session_info = 2;
  if (has_session_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->session_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameSessionInfoResponse)
  return target;
}

int GetGameSessionInfoResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameSessionInfo session_info = 2;
    if (has_session_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->session_info());
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

void GetGameSessionInfoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameSessionInfoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameSessionInfoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameSessionInfoResponse::MergeFrom(const GetGameSessionInfoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_session_info()) {
      mutable_session_info()->::bgs::protocol::account::v1::GameSessionInfo::MergeFrom(from.session_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameSessionInfoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameSessionInfoResponse::CopyFrom(const GetGameSessionInfoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameSessionInfoResponse::IsInitialized() const {

  if (has_session_info()) {
    if (!this->session_info().IsInitialized()) return false;
  }
  return true;
}

void GetGameSessionInfoResponse::Swap(GetGameSessionInfoResponse* other) {
  if (other != this) {
    std::swap(session_info_, other->session_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameSessionInfoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameSessionInfoResponse_descriptor_;
  metadata.reflection = GetGameSessionInfoResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameTimeRemainingInfoRequest::kGameAccountIdFieldNumber;
const int GetGameTimeRemainingInfoRequest::kAccountIdFieldNumber;
#endif  // !_MSC_VER

GetGameTimeRemainingInfoRequest::GetGameTimeRemainingInfoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
}

void GetGameTimeRemainingInfoRequest::InitAsDefaultInstance() {
  game_account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  account_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetGameTimeRemainingInfoRequest::GetGameTimeRemainingInfoRequest(const GetGameTimeRemainingInfoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
}

void GetGameTimeRemainingInfoRequest::SharedCtor() {
  _cached_size_ = 0;
  game_account_id_ = NULL;
  account_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameTimeRemainingInfoRequest::~GetGameTimeRemainingInfoRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  SharedDtor();
}

void GetGameTimeRemainingInfoRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_id_;
    delete account_id_;
  }
}

void GetGameTimeRemainingInfoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameTimeRemainingInfoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameTimeRemainingInfoRequest_descriptor_;
}

const GetGameTimeRemainingInfoRequest& GetGameTimeRemainingInfoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameTimeRemainingInfoRequest* GetGameTimeRemainingInfoRequest::default_instance_ = NULL;

GetGameTimeRemainingInfoRequest* GetGameTimeRemainingInfoRequest::New() const {
  return new GetGameTimeRemainingInfoRequest;
}

void GetGameTimeRemainingInfoRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_game_account_id()) {
      if (game_account_id_ != NULL) game_account_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_account_id()) {
      if (account_id_ != NULL) account_id_->::bgs::protocol::EntityId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameTimeRemainingInfoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId game_account_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  return false;
#undef DO_
}

void GetGameTimeRemainingInfoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  // optional .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_id(), output);
  }

  // optional .bgs.protocol.EntityId account_id = 2;
  if (has_account_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->account_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
}

::google::protobuf::uint8* GetGameTimeRemainingInfoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  // optional .bgs.protocol.EntityId game_account_id = 1;
  if (has_game_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_id(), target);
  }

  // optional .bgs.protocol.EntityId account_id = 2;
  if (has_account_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->account_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest)
  return target;
}

int GetGameTimeRemainingInfoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId game_account_id = 1;
    if (has_game_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_id());
    }

    // optional .bgs.protocol.EntityId account_id = 2;
    if (has_account_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_id());
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

void GetGameTimeRemainingInfoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameTimeRemainingInfoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameTimeRemainingInfoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameTimeRemainingInfoRequest::MergeFrom(const GetGameTimeRemainingInfoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_id()) {
      mutable_game_account_id()->::bgs::protocol::EntityId::MergeFrom(from.game_account_id());
    }
    if (from.has_account_id()) {
      mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from.account_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameTimeRemainingInfoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameTimeRemainingInfoRequest::CopyFrom(const GetGameTimeRemainingInfoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameTimeRemainingInfoRequest::IsInitialized() const {

  if (has_game_account_id()) {
    if (!this->game_account_id().IsInitialized()) return false;
  }
  if (has_account_id()) {
    if (!this->account_id().IsInitialized()) return false;
  }
  return true;
}

void GetGameTimeRemainingInfoRequest::Swap(GetGameTimeRemainingInfoRequest* other) {
  if (other != this) {
    std::swap(game_account_id_, other->game_account_id_);
    std::swap(account_id_, other->account_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameTimeRemainingInfoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameTimeRemainingInfoRequest_descriptor_;
  metadata.reflection = GetGameTimeRemainingInfoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameTimeRemainingInfoResponse::kGameTimeRemainingInfoFieldNumber;
#endif  // !_MSC_VER

GetGameTimeRemainingInfoResponse::GetGameTimeRemainingInfoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
}

void GetGameTimeRemainingInfoResponse::InitAsDefaultInstance() {
  game_time_remaining_info_ = const_cast< ::bgs::protocol::account::v1::GameTimeRemainingInfo*>(&::bgs::protocol::account::v1::GameTimeRemainingInfo::default_instance());
}

GetGameTimeRemainingInfoResponse::GetGameTimeRemainingInfoResponse(const GetGameTimeRemainingInfoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
}

void GetGameTimeRemainingInfoResponse::SharedCtor() {
  _cached_size_ = 0;
  game_time_remaining_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameTimeRemainingInfoResponse::~GetGameTimeRemainingInfoResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  SharedDtor();
}

void GetGameTimeRemainingInfoResponse::SharedDtor() {
  if (this != default_instance_) {
    delete game_time_remaining_info_;
  }
}

void GetGameTimeRemainingInfoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameTimeRemainingInfoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameTimeRemainingInfoResponse_descriptor_;
}

const GetGameTimeRemainingInfoResponse& GetGameTimeRemainingInfoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameTimeRemainingInfoResponse* GetGameTimeRemainingInfoResponse::default_instance_ = NULL;

GetGameTimeRemainingInfoResponse* GetGameTimeRemainingInfoResponse::New() const {
  return new GetGameTimeRemainingInfoResponse;
}

void GetGameTimeRemainingInfoResponse::Clear() {
  if (has_game_time_remaining_info()) {
    if (game_time_remaining_info_ != NULL) game_time_remaining_info_->::bgs::protocol::account::v1::GameTimeRemainingInfo::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameTimeRemainingInfoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameTimeRemainingInfo game_time_remaining_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_time_remaining_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  return false;
#undef DO_
}

void GetGameTimeRemainingInfoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  // optional .bgs.protocol.account.v1.GameTimeRemainingInfo game_time_remaining_info = 1;
  if (has_game_time_remaining_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_time_remaining_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
}

::google::protobuf::uint8* GetGameTimeRemainingInfoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  // optional .bgs.protocol.account.v1.GameTimeRemainingInfo game_time_remaining_info = 1;
  if (has_game_time_remaining_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_time_remaining_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse)
  return target;
}

int GetGameTimeRemainingInfoResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameTimeRemainingInfo game_time_remaining_info = 1;
    if (has_game_time_remaining_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_time_remaining_info());
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

void GetGameTimeRemainingInfoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameTimeRemainingInfoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameTimeRemainingInfoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameTimeRemainingInfoResponse::MergeFrom(const GetGameTimeRemainingInfoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_time_remaining_info()) {
      mutable_game_time_remaining_info()->::bgs::protocol::account::v1::GameTimeRemainingInfo::MergeFrom(from.game_time_remaining_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameTimeRemainingInfoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameTimeRemainingInfoResponse::CopyFrom(const GetGameTimeRemainingInfoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameTimeRemainingInfoResponse::IsInitialized() const {

  return true;
}

void GetGameTimeRemainingInfoResponse::Swap(GetGameTimeRemainingInfoResponse* other) {
  if (other != this) {
    std::swap(game_time_remaining_info_, other->game_time_remaining_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameTimeRemainingInfoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameTimeRemainingInfoResponse_descriptor_;
  metadata.reflection = GetGameTimeRemainingInfoResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetCAISInfoRequest::kEntityIdFieldNumber;
#endif  // !_MSC_VER

GetCAISInfoRequest::GetCAISInfoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetCAISInfoRequest)
}

void GetCAISInfoRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetCAISInfoRequest::GetCAISInfoRequest(const GetCAISInfoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetCAISInfoRequest)
}

void GetCAISInfoRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetCAISInfoRequest::~GetCAISInfoRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetCAISInfoRequest)
  SharedDtor();
}

void GetCAISInfoRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void GetCAISInfoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetCAISInfoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetCAISInfoRequest_descriptor_;
}

const GetCAISInfoRequest& GetCAISInfoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetCAISInfoRequest* GetCAISInfoRequest::default_instance_ = NULL;

GetCAISInfoRequest* GetCAISInfoRequest::New() const {
  return new GetCAISInfoRequest;
}

void GetCAISInfoRequest::Clear() {
  if (has_entity_id()) {
    if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetCAISInfoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetCAISInfoRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetCAISInfoRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetCAISInfoRequest)
  return false;
#undef DO_
}

void GetCAISInfoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetCAISInfoRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetCAISInfoRequest)
}

::google::protobuf::uint8* GetCAISInfoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetCAISInfoRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetCAISInfoRequest)
  return target;
}

int GetCAISInfoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
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

void GetCAISInfoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetCAISInfoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetCAISInfoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetCAISInfoRequest::MergeFrom(const GetCAISInfoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetCAISInfoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetCAISInfoRequest::CopyFrom(const GetCAISInfoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetCAISInfoRequest::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void GetCAISInfoRequest::Swap(GetCAISInfoRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetCAISInfoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetCAISInfoRequest_descriptor_;
  metadata.reflection = GetCAISInfoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetCAISInfoResponse::kCaisInfoFieldNumber;
#endif  // !_MSC_VER

GetCAISInfoResponse::GetCAISInfoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetCAISInfoResponse)
}

void GetCAISInfoResponse::InitAsDefaultInstance() {
  cais_info_ = const_cast< ::bgs::protocol::account::v1::CAIS*>(&::bgs::protocol::account::v1::CAIS::default_instance());
}

GetCAISInfoResponse::GetCAISInfoResponse(const GetCAISInfoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetCAISInfoResponse)
}

void GetCAISInfoResponse::SharedCtor() {
  _cached_size_ = 0;
  cais_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetCAISInfoResponse::~GetCAISInfoResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetCAISInfoResponse)
  SharedDtor();
}

void GetCAISInfoResponse::SharedDtor() {
  if (this != default_instance_) {
    delete cais_info_;
  }
}

void GetCAISInfoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetCAISInfoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetCAISInfoResponse_descriptor_;
}

const GetCAISInfoResponse& GetCAISInfoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetCAISInfoResponse* GetCAISInfoResponse::default_instance_ = NULL;

GetCAISInfoResponse* GetCAISInfoResponse::New() const {
  return new GetCAISInfoResponse;
}

void GetCAISInfoResponse::Clear() {
  if (has_cais_info()) {
    if (cais_info_ != NULL) cais_info_->::bgs::protocol::account::v1::CAIS::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetCAISInfoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetCAISInfoResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.CAIS cais_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_cais_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetCAISInfoResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetCAISInfoResponse)
  return false;
#undef DO_
}

void GetCAISInfoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetCAISInfoResponse)
  // optional .bgs.protocol.account.v1.CAIS cais_info = 1;
  if (has_cais_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->cais_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetCAISInfoResponse)
}

::google::protobuf::uint8* GetCAISInfoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetCAISInfoResponse)
  // optional .bgs.protocol.account.v1.CAIS cais_info = 1;
  if (has_cais_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->cais_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetCAISInfoResponse)
  return target;
}

int GetCAISInfoResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.CAIS cais_info = 1;
    if (has_cais_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->cais_info());
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

void GetCAISInfoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetCAISInfoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetCAISInfoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetCAISInfoResponse::MergeFrom(const GetCAISInfoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_cais_info()) {
      mutable_cais_info()->::bgs::protocol::account::v1::CAIS::MergeFrom(from.cais_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetCAISInfoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetCAISInfoResponse::CopyFrom(const GetCAISInfoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetCAISInfoResponse::IsInitialized() const {

  return true;
}

void GetCAISInfoResponse::Swap(GetCAISInfoResponse* other) {
  if (other != this) {
    std::swap(cais_info_, other->cais_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetCAISInfoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetCAISInfoResponse_descriptor_;
  metadata.reflection = GetCAISInfoResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ForwardCacheExpireRequest::kEntityIdFieldNumber;
#endif  // !_MSC_VER

ForwardCacheExpireRequest::ForwardCacheExpireRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.ForwardCacheExpireRequest)
}

void ForwardCacheExpireRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

ForwardCacheExpireRequest::ForwardCacheExpireRequest(const ForwardCacheExpireRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.ForwardCacheExpireRequest)
}

void ForwardCacheExpireRequest::SharedCtor() {
  _cached_size_ = 0;
  entity_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ForwardCacheExpireRequest::~ForwardCacheExpireRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  SharedDtor();
}

void ForwardCacheExpireRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void ForwardCacheExpireRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ForwardCacheExpireRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ForwardCacheExpireRequest_descriptor_;
}

const ForwardCacheExpireRequest& ForwardCacheExpireRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

ForwardCacheExpireRequest* ForwardCacheExpireRequest::default_instance_ = NULL;

ForwardCacheExpireRequest* ForwardCacheExpireRequest::New() const {
  return new ForwardCacheExpireRequest;
}

void ForwardCacheExpireRequest::Clear() {
  if (has_entity_id()) {
    if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ForwardCacheExpireRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  return false;
#undef DO_
}

void ForwardCacheExpireRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.ForwardCacheExpireRequest)
}

::google::protobuf::uint8* ForwardCacheExpireRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.ForwardCacheExpireRequest)
  return target;
}

int ForwardCacheExpireRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
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

void ForwardCacheExpireRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ForwardCacheExpireRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ForwardCacheExpireRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ForwardCacheExpireRequest::MergeFrom(const ForwardCacheExpireRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ForwardCacheExpireRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ForwardCacheExpireRequest::CopyFrom(const ForwardCacheExpireRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ForwardCacheExpireRequest::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void ForwardCacheExpireRequest::Swap(ForwardCacheExpireRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ForwardCacheExpireRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ForwardCacheExpireRequest_descriptor_;
  metadata.reflection = ForwardCacheExpireRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAuthorizedDataRequest::kEntityIdFieldNumber;
const int GetAuthorizedDataRequest::kTagFieldNumber;
const int GetAuthorizedDataRequest::kPrivilegedNetworkFieldNumber;
#endif  // !_MSC_VER

GetAuthorizedDataRequest::GetAuthorizedDataRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAuthorizedDataRequest)
}

void GetAuthorizedDataRequest::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

GetAuthorizedDataRequest::GetAuthorizedDataRequest(const GetAuthorizedDataRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAuthorizedDataRequest)
}

void GetAuthorizedDataRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  entity_id_ = NULL;
  privileged_network_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAuthorizedDataRequest::~GetAuthorizedDataRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  SharedDtor();
}

void GetAuthorizedDataRequest::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
  }
}

void GetAuthorizedDataRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAuthorizedDataRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAuthorizedDataRequest_descriptor_;
}

const GetAuthorizedDataRequest& GetAuthorizedDataRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAuthorizedDataRequest* GetAuthorizedDataRequest::default_instance_ = NULL;

GetAuthorizedDataRequest* GetAuthorizedDataRequest::New() const {
  return new GetAuthorizedDataRequest;
}

void GetAuthorizedDataRequest::Clear() {
  if (_has_bits_[0 / 32] & 5) {
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    privileged_network_ = false;
  }
  tag_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAuthorizedDataRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.EntityId entity_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tag;
        break;
      }

      // repeated string tag = 2;
      case 2: {
        if (tag == 18) {
         parse_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->tag(this->tag_size() - 1).data(),
            this->tag(this->tag_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "tag");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tag;
        if (input->ExpectTag(24)) goto parse_privileged_network;
        break;
      }

      // optional bool privileged_network = 3;
      case 3: {
        if (tag == 24) {
         parse_privileged_network:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &privileged_network_)));
          set_has_privileged_network();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  return false;
#undef DO_
}

void GetAuthorizedDataRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->entity_id(), output);
  }

  // repeated string tag = 2;
  for (int i = 0; i < this->tag_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->tag(i).data(), this->tag(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "tag");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->tag(i), output);
  }

  // optional bool privileged_network = 3;
  if (has_privileged_network()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->privileged_network(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAuthorizedDataRequest)
}

::google::protobuf::uint8* GetAuthorizedDataRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  // optional .bgs.protocol.EntityId entity_id = 1;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->entity_id(), target);
  }

  // repeated string tag = 2;
  for (int i = 0; i < this->tag_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->tag(i).data(), this->tag(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "tag");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->tag(i), target);
  }

  // optional bool privileged_network = 3;
  if (has_privileged_network()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->privileged_network(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAuthorizedDataRequest)
  return target;
}

int GetAuthorizedDataRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.EntityId entity_id = 1;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional bool privileged_network = 3;
    if (has_privileged_network()) {
      total_size += 1 + 1;
    }

  }
  // repeated string tag = 2;
  total_size += 1 * this->tag_size();
  for (int i = 0; i < this->tag_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->tag(i));
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

void GetAuthorizedDataRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAuthorizedDataRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAuthorizedDataRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAuthorizedDataRequest::MergeFrom(const GetAuthorizedDataRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  tag_.MergeFrom(from.tag_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_privileged_network()) {
      set_privileged_network(from.privileged_network());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAuthorizedDataRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAuthorizedDataRequest::CopyFrom(const GetAuthorizedDataRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAuthorizedDataRequest::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void GetAuthorizedDataRequest::Swap(GetAuthorizedDataRequest* other) {
  if (other != this) {
    std::swap(entity_id_, other->entity_id_);
    tag_.Swap(&other->tag_);
    std::swap(privileged_network_, other->privileged_network_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAuthorizedDataRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAuthorizedDataRequest_descriptor_;
  metadata.reflection = GetAuthorizedDataRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetAuthorizedDataResponse::kDataFieldNumber;
#endif  // !_MSC_VER

GetAuthorizedDataResponse::GetAuthorizedDataResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetAuthorizedDataResponse)
}

void GetAuthorizedDataResponse::InitAsDefaultInstance() {
}

GetAuthorizedDataResponse::GetAuthorizedDataResponse(const GetAuthorizedDataResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetAuthorizedDataResponse)
}

void GetAuthorizedDataResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetAuthorizedDataResponse::~GetAuthorizedDataResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  SharedDtor();
}

void GetAuthorizedDataResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetAuthorizedDataResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetAuthorizedDataResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetAuthorizedDataResponse_descriptor_;
}

const GetAuthorizedDataResponse& GetAuthorizedDataResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetAuthorizedDataResponse* GetAuthorizedDataResponse::default_instance_ = NULL;

GetAuthorizedDataResponse* GetAuthorizedDataResponse::New() const {
  return new GetAuthorizedDataResponse;
}

void GetAuthorizedDataResponse::Clear() {
  data_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetAuthorizedDataResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AuthorizedData data = 1;
      case 1: {
        if (tag == 10) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_data;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  return false;
#undef DO_
}

void GetAuthorizedDataResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  // repeated .bgs.protocol.account.v1.AuthorizedData data = 1;
  for (int i = 0; i < this->data_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->data(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetAuthorizedDataResponse)
}

::google::protobuf::uint8* GetAuthorizedDataResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  // repeated .bgs.protocol.account.v1.AuthorizedData data = 1;
  for (int i = 0; i < this->data_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->data(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetAuthorizedDataResponse)
  return target;
}

int GetAuthorizedDataResponse::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.AuthorizedData data = 1;
  total_size += 1 * this->data_size();
  for (int i = 0; i < this->data_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->data(i));
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

void GetAuthorizedDataResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetAuthorizedDataResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetAuthorizedDataResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetAuthorizedDataResponse::MergeFrom(const GetAuthorizedDataResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  data_.MergeFrom(from.data_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetAuthorizedDataResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetAuthorizedDataResponse::CopyFrom(const GetAuthorizedDataResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetAuthorizedDataResponse::IsInitialized() const {

  return true;
}

void GetAuthorizedDataResponse::Swap(GetAuthorizedDataResponse* other) {
  if (other != this) {
    data_.Swap(&other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetAuthorizedDataResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetAuthorizedDataResponse_descriptor_;
  metadata.reflection = GetAuthorizedDataResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int UpdateParentalControlsAndCAISRequest::kAccountFieldNumber;
const int UpdateParentalControlsAndCAISRequest::kParentalControlInfoFieldNumber;
const int UpdateParentalControlsAndCAISRequest::kCaisIdFieldNumber;
const int UpdateParentalControlsAndCAISRequest::kSessionStartTimeFieldNumber;
const int UpdateParentalControlsAndCAISRequest::kStartTimeFieldNumber;
const int UpdateParentalControlsAndCAISRequest::kEndTimeFieldNumber;
#endif  // !_MSC_VER

UpdateParentalControlsAndCAISRequest::UpdateParentalControlsAndCAISRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
}

void UpdateParentalControlsAndCAISRequest::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
  parental_control_info_ = const_cast< ::bgs::protocol::account::v1::ParentalControlInfo*>(&::bgs::protocol::account::v1::ParentalControlInfo::default_instance());
}

UpdateParentalControlsAndCAISRequest::UpdateParentalControlsAndCAISRequest(const UpdateParentalControlsAndCAISRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
}

void UpdateParentalControlsAndCAISRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  account_ = NULL;
  parental_control_info_ = NULL;
  cais_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  session_start_time_ = GOOGLE_ULONGLONG(0);
  start_time_ = GOOGLE_ULONGLONG(0);
  end_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UpdateParentalControlsAndCAISRequest::~UpdateParentalControlsAndCAISRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  SharedDtor();
}

void UpdateParentalControlsAndCAISRequest::SharedDtor() {
  if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete cais_id_;
  }
  if (this != default_instance_) {
    delete account_;
    delete parental_control_info_;
  }
}

void UpdateParentalControlsAndCAISRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateParentalControlsAndCAISRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateParentalControlsAndCAISRequest_descriptor_;
}

const UpdateParentalControlsAndCAISRequest& UpdateParentalControlsAndCAISRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

UpdateParentalControlsAndCAISRequest* UpdateParentalControlsAndCAISRequest::default_instance_ = NULL;

UpdateParentalControlsAndCAISRequest* UpdateParentalControlsAndCAISRequest::New() const {
  return new UpdateParentalControlsAndCAISRequest;
}

void UpdateParentalControlsAndCAISRequest::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<UpdateParentalControlsAndCAISRequest*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(session_start_time_, end_time_);
    if (has_account()) {
      if (account_ != NULL) account_->::bgs::protocol::account::v1::AccountId::Clear();
    }
    if (has_parental_control_info()) {
      if (parental_control_info_ != NULL) parental_control_info_->::bgs::protocol::account::v1::ParentalControlInfo::Clear();
    }
    if (has_cais_id()) {
      if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        cais_id_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UpdateParentalControlsAndCAISRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountId account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_parental_control_info;
        break;
      }

      // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 2;
      case 2: {
        if (tag == 18) {
         parse_parental_control_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_parental_control_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_cais_id;
        break;
      }

      // optional string cais_id = 3;
      case 3: {
        if (tag == 26) {
         parse_cais_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_cais_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->cais_id().data(), this->cais_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "cais_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_session_start_time;
        break;
      }

      // optional uint64 session_start_time = 4;
      case 4: {
        if (tag == 32) {
         parse_session_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &session_start_time_)));
          set_has_session_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_start_time;
        break;
      }

      // optional uint64 start_time = 5;
      case 5: {
        if (tag == 40) {
         parse_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &start_time_)));
          set_has_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_end_time;
        break;
      }

      // optional uint64 end_time = 6;
      case 6: {
        if (tag == 48) {
         parse_end_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &end_time_)));
          set_has_end_time();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  return false;
#undef DO_
}

void UpdateParentalControlsAndCAISRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 2;
  if (has_parental_control_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->parental_control_info(), output);
  }

  // optional string cais_id = 3;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->cais_id(), output);
  }

  // optional uint64 session_start_time = 4;
  if (has_session_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->session_start_time(), output);
  }

  // optional uint64 start_time = 5;
  if (has_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->start_time(), output);
  }

  // optional uint64 end_time = 6;
  if (has_end_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(6, this->end_time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
}

::google::protobuf::uint8* UpdateParentalControlsAndCAISRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 2;
  if (has_parental_control_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->parental_control_info(), target);
  }

  // optional string cais_id = 3;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->cais_id(), target);
  }

  // optional uint64 session_start_time = 4;
  if (has_session_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->session_start_time(), target);
  }

  // optional uint64 start_time = 5;
  if (has_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->start_time(), target);
  }

  // optional uint64 end_time = 6;
  if (has_end_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(6, this->end_time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest)
  return target;
}

int UpdateParentalControlsAndCAISRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
    }

    // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 2;
    if (has_parental_control_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->parental_control_info());
    }

    // optional string cais_id = 3;
    if (has_cais_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->cais_id());
    }

    // optional uint64 session_start_time = 4;
    if (has_session_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->session_start_time());
    }

    // optional uint64 start_time = 5;
    if (has_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->start_time());
    }

    // optional uint64 end_time = 6;
    if (has_end_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->end_time());
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

void UpdateParentalControlsAndCAISRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UpdateParentalControlsAndCAISRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UpdateParentalControlsAndCAISRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateParentalControlsAndCAISRequest::MergeFrom(const UpdateParentalControlsAndCAISRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.account());
    }
    if (from.has_parental_control_info()) {
      mutable_parental_control_info()->::bgs::protocol::account::v1::ParentalControlInfo::MergeFrom(from.parental_control_info());
    }
    if (from.has_cais_id()) {
      set_cais_id(from.cais_id());
    }
    if (from.has_session_start_time()) {
      set_session_start_time(from.session_start_time());
    }
    if (from.has_start_time()) {
      set_start_time(from.start_time());
    }
    if (from.has_end_time()) {
      set_end_time(from.end_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UpdateParentalControlsAndCAISRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateParentalControlsAndCAISRequest::CopyFrom(const UpdateParentalControlsAndCAISRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateParentalControlsAndCAISRequest::IsInitialized() const {

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  return true;
}

void UpdateParentalControlsAndCAISRequest::Swap(UpdateParentalControlsAndCAISRequest* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(parental_control_info_, other->parental_control_info_);
    std::swap(cais_id_, other->cais_id_);
    std::swap(session_start_time_, other->session_start_time_);
    std::swap(start_time_, other->start_time_);
    std::swap(end_time_, other->end_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UpdateParentalControlsAndCAISRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateParentalControlsAndCAISRequest_descriptor_;
  metadata.reflection = UpdateParentalControlsAndCAISRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int QueueDeductRecordRequest::kDeductRecordFieldNumber;
#endif  // !_MSC_VER

QueueDeductRecordRequest::QueueDeductRecordRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.QueueDeductRecordRequest)
}

void QueueDeductRecordRequest::InitAsDefaultInstance() {
  deduct_record_ = const_cast< ::bgs::protocol::account::v1::DeductRecord*>(&::bgs::protocol::account::v1::DeductRecord::default_instance());
}

QueueDeductRecordRequest::QueueDeductRecordRequest(const QueueDeductRecordRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.QueueDeductRecordRequest)
}

void QueueDeductRecordRequest::SharedCtor() {
  _cached_size_ = 0;
  deduct_record_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QueueDeductRecordRequest::~QueueDeductRecordRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.QueueDeductRecordRequest)
  SharedDtor();
}

void QueueDeductRecordRequest::SharedDtor() {
  if (this != default_instance_) {
    delete deduct_record_;
  }
}

void QueueDeductRecordRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QueueDeductRecordRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueueDeductRecordRequest_descriptor_;
}

const QueueDeductRecordRequest& QueueDeductRecordRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

QueueDeductRecordRequest* QueueDeductRecordRequest::default_instance_ = NULL;

QueueDeductRecordRequest* QueueDeductRecordRequest::New() const {
  return new QueueDeductRecordRequest;
}

void QueueDeductRecordRequest::Clear() {
  if (has_deduct_record()) {
    if (deduct_record_ != NULL) deduct_record_->::bgs::protocol::account::v1::DeductRecord::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QueueDeductRecordRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.QueueDeductRecordRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.DeductRecord deduct_record = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_deduct_record()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.QueueDeductRecordRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.QueueDeductRecordRequest)
  return false;
#undef DO_
}

void QueueDeductRecordRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.QueueDeductRecordRequest)
  // optional .bgs.protocol.account.v1.DeductRecord deduct_record = 1;
  if (has_deduct_record()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->deduct_record(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.QueueDeductRecordRequest)
}

::google::protobuf::uint8* QueueDeductRecordRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.QueueDeductRecordRequest)
  // optional .bgs.protocol.account.v1.DeductRecord deduct_record = 1;
  if (has_deduct_record()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->deduct_record(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.QueueDeductRecordRequest)
  return target;
}

int QueueDeductRecordRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.DeductRecord deduct_record = 1;
    if (has_deduct_record()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->deduct_record());
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

void QueueDeductRecordRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QueueDeductRecordRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QueueDeductRecordRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QueueDeductRecordRequest::MergeFrom(const QueueDeductRecordRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_deduct_record()) {
      mutable_deduct_record()->::bgs::protocol::account::v1::DeductRecord::MergeFrom(from.deduct_record());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QueueDeductRecordRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QueueDeductRecordRequest::CopyFrom(const QueueDeductRecordRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QueueDeductRecordRequest::IsInitialized() const {

  if (has_deduct_record()) {
    if (!this->deduct_record().IsInitialized()) return false;
  }
  return true;
}

void QueueDeductRecordRequest::Swap(QueueDeductRecordRequest* other) {
  if (other != this) {
    std::swap(deduct_record_, other->deduct_record_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QueueDeductRecordRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QueueDeductRecordRequest_descriptor_;
  metadata.reflection = QueueDeductRecordRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameAccountRequest::kGameAccountFieldNumber;
const int GetGameAccountRequest::kReloadFieldNumber;
#endif  // !_MSC_VER

GetGameAccountRequest::GetGameAccountRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameAccountRequest)
}

void GetGameAccountRequest::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

GetGameAccountRequest::GetGameAccountRequest(const GetGameAccountRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameAccountRequest)
}

void GetGameAccountRequest::SharedCtor() {
  _cached_size_ = 0;
  game_account_ = NULL;
  reload_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameAccountRequest::~GetGameAccountRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameAccountRequest)
  SharedDtor();
}

void GetGameAccountRequest::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_;
  }
}

void GetGameAccountRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameAccountRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameAccountRequest_descriptor_;
}

const GetGameAccountRequest& GetGameAccountRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameAccountRequest* GetGameAccountRequest::default_instance_ = NULL;

GetGameAccountRequest* GetGameAccountRequest::New() const {
  return new GetGameAccountRequest;
}

void GetGameAccountRequest::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    reload_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameAccountRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameAccountRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_reload;
        break;
      }

      // optional bool reload = 2 [default = false];
      case 2: {
        if (tag == 16) {
         parse_reload:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &reload_)));
          set_has_reload();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameAccountRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameAccountRequest)
  return false;
#undef DO_
}

void GetGameAccountRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameAccountRequest)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional bool reload = 2 [default = false];
  if (has_reload()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->reload(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameAccountRequest)
}

::google::protobuf::uint8* GetGameAccountRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameAccountRequest)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional bool reload = 2 [default = false];
  if (has_reload()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->reload(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameAccountRequest)
  return target;
}

int GetGameAccountRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional bool reload = 2 [default = false];
    if (has_reload()) {
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

void GetGameAccountRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameAccountRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameAccountRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameAccountRequest::MergeFrom(const GetGameAccountRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_reload()) {
      set_reload(from.reload());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameAccountRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameAccountRequest::CopyFrom(const GetGameAccountRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameAccountRequest::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void GetGameAccountRequest::Swap(GetGameAccountRequest* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(reload_, other->reload_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameAccountRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameAccountRequest_descriptor_;
  metadata.reflection = GetGameAccountRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GetGameAccountResponse::kBlobFieldNumber;
#endif  // !_MSC_VER

GetGameAccountResponse::GetGameAccountResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GetGameAccountResponse)
}

void GetGameAccountResponse::InitAsDefaultInstance() {
  blob_ = const_cast< ::bgs::protocol::account::v1::GameAccountBlob*>(&::bgs::protocol::account::v1::GameAccountBlob::default_instance());
}

GetGameAccountResponse::GetGameAccountResponse(const GetGameAccountResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GetGameAccountResponse)
}

void GetGameAccountResponse::SharedCtor() {
  _cached_size_ = 0;
  blob_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetGameAccountResponse::~GetGameAccountResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GetGameAccountResponse)
  SharedDtor();
}

void GetGameAccountResponse::SharedDtor() {
  if (this != default_instance_) {
    delete blob_;
  }
}

void GetGameAccountResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetGameAccountResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetGameAccountResponse_descriptor_;
}

const GetGameAccountResponse& GetGameAccountResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GetGameAccountResponse* GetGameAccountResponse::default_instance_ = NULL;

GetGameAccountResponse* GetGameAccountResponse::New() const {
  return new GetGameAccountResponse;
}

void GetGameAccountResponse::Clear() {
  if (has_blob()) {
    if (blob_ != NULL) blob_->::bgs::protocol::account::v1::GameAccountBlob::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetGameAccountResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GetGameAccountResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountBlob blob = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_blob()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GetGameAccountResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GetGameAccountResponse)
  return false;
#undef DO_
}

void GetGameAccountResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GetGameAccountResponse)
  // optional .bgs.protocol.account.v1.GameAccountBlob blob = 1;
  if (has_blob()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->blob(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GetGameAccountResponse)
}

::google::protobuf::uint8* GetGameAccountResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GetGameAccountResponse)
  // optional .bgs.protocol.account.v1.GameAccountBlob blob = 1;
  if (has_blob()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->blob(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GetGameAccountResponse)
  return target;
}

int GetGameAccountResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountBlob blob = 1;
    if (has_blob()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->blob());
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

void GetGameAccountResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetGameAccountResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetGameAccountResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetGameAccountResponse::MergeFrom(const GetGameAccountResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_blob()) {
      mutable_blob()->::bgs::protocol::account::v1::GameAccountBlob::MergeFrom(from.blob());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetGameAccountResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGameAccountResponse::CopyFrom(const GetGameAccountResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGameAccountResponse::IsInitialized() const {

  if (has_blob()) {
    if (!this->blob().IsInitialized()) return false;
  }
  return true;
}

void GetGameAccountResponse::Swap(GetGameAccountResponse* other) {
  if (other != this) {
    std::swap(blob_, other->blob_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetGameAccountResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetGameAccountResponse_descriptor_;
  metadata.reflection = GetGameAccountResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountStateNotification::kAccountStateFieldNumber;
const int AccountStateNotification::kSubscriberIdFieldNumber;
const int AccountStateNotification::kAccountTagsFieldNumber;
const int AccountStateNotification::kSubscriptionCompletedFieldNumber;
#endif  // !_MSC_VER

AccountStateNotification::AccountStateNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountStateNotification)
}

void AccountStateNotification::InitAsDefaultInstance() {
  account_state_ = const_cast< ::bgs::protocol::account::v1::AccountState*>(&::bgs::protocol::account::v1::AccountState::default_instance());
  account_tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
}

AccountStateNotification::AccountStateNotification(const AccountStateNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountStateNotification)
}

void AccountStateNotification::SharedCtor() {
  _cached_size_ = 0;
  account_state_ = NULL;
  subscriber_id_ = GOOGLE_ULONGLONG(0);
  account_tags_ = NULL;
  subscription_completed_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountStateNotification::~AccountStateNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountStateNotification)
  SharedDtor();
}

void AccountStateNotification::SharedDtor() {
  if (this != default_instance_) {
    delete account_state_;
    delete account_tags_;
  }
}

void AccountStateNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountStateNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountStateNotification_descriptor_;
}

const AccountStateNotification& AccountStateNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

AccountStateNotification* AccountStateNotification::default_instance_ = NULL;

AccountStateNotification* AccountStateNotification::New() const {
  return new AccountStateNotification;
}

void AccountStateNotification::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_account_state()) {
      if (account_state_ != NULL) account_state_->::bgs::protocol::account::v1::AccountState::Clear();
    }
    subscriber_id_ = GOOGLE_ULONGLONG(0);
    if (has_account_tags()) {
      if (account_tags_ != NULL) account_tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
    subscription_completed_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountStateNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountStateNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountState account_state = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_state()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_subscriber_id;
        break;
      }

      // optional uint64 subscriber_id = 2;
      case 2: {
        if (tag == 16) {
         parse_subscriber_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &subscriber_id_)));
          set_has_subscriber_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
      case 3: {
        if (tag == 26) {
         parse_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_subscription_completed;
        break;
      }

      // optional bool subscription_completed = 4;
      case 4: {
        if (tag == 32) {
         parse_subscription_completed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &subscription_completed_)));
          set_has_subscription_completed();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountStateNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountStateNotification)
  return false;
#undef DO_
}

void AccountStateNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountStateNotification)
  // optional .bgs.protocol.account.v1.AccountState account_state = 1;
  if (has_account_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_state(), output);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->subscriber_id(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
  if (has_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_tags(), output);
  }

  // optional bool subscription_completed = 4;
  if (has_subscription_completed()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->subscription_completed(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountStateNotification)
}

::google::protobuf::uint8* AccountStateNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountStateNotification)
  // optional .bgs.protocol.account.v1.AccountState account_state = 1;
  if (has_account_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_state(), target);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->subscriber_id(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
  if (has_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_tags(), target);
  }

  // optional bool subscription_completed = 4;
  if (has_subscription_completed()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->subscription_completed(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountStateNotification)
  return target;
}

int AccountStateNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountState account_state = 1;
    if (has_account_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_state());
    }

    // optional uint64 subscriber_id = 2;
    if (has_subscriber_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->subscriber_id());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
    if (has_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_tags());
    }

    // optional bool subscription_completed = 4;
    if (has_subscription_completed()) {
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

void AccountStateNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountStateNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountStateNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountStateNotification::MergeFrom(const AccountStateNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_state()) {
      mutable_account_state()->::bgs::protocol::account::v1::AccountState::MergeFrom(from.account_state());
    }
    if (from.has_subscriber_id()) {
      set_subscriber_id(from.subscriber_id());
    }
    if (from.has_account_tags()) {
      mutable_account_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.account_tags());
    }
    if (from.has_subscription_completed()) {
      set_subscription_completed(from.subscription_completed());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountStateNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountStateNotification::CopyFrom(const AccountStateNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountStateNotification::IsInitialized() const {

  if (has_account_state()) {
    if (!this->account_state().IsInitialized()) return false;
  }
  return true;
}

void AccountStateNotification::Swap(AccountStateNotification* other) {
  if (other != this) {
    std::swap(account_state_, other->account_state_);
    std::swap(subscriber_id_, other->subscriber_id_);
    std::swap(account_tags_, other->account_tags_);
    std::swap(subscription_completed_, other->subscription_completed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountStateNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountStateNotification_descriptor_;
  metadata.reflection = AccountStateNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountStateNotification::kGameAccountStateFieldNumber;
const int GameAccountStateNotification::kSubscriberIdFieldNumber;
const int GameAccountStateNotification::kGameAccountTagsFieldNumber;
const int GameAccountStateNotification::kSubscriptionCompletedFieldNumber;
#endif  // !_MSC_VER

GameAccountStateNotification::GameAccountStateNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountStateNotification)
}

void GameAccountStateNotification::InitAsDefaultInstance() {
  game_account_state_ = const_cast< ::bgs::protocol::account::v1::GameAccountState*>(&::bgs::protocol::account::v1::GameAccountState::default_instance());
  game_account_tags_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldTags*>(&::bgs::protocol::account::v1::GameAccountFieldTags::default_instance());
}

GameAccountStateNotification::GameAccountStateNotification(const GameAccountStateNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountStateNotification)
}

void GameAccountStateNotification::SharedCtor() {
  _cached_size_ = 0;
  game_account_state_ = NULL;
  subscriber_id_ = GOOGLE_ULONGLONG(0);
  game_account_tags_ = NULL;
  subscription_completed_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountStateNotification::~GameAccountStateNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountStateNotification)
  SharedDtor();
}

void GameAccountStateNotification::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_state_;
    delete game_account_tags_;
  }
}

void GameAccountStateNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountStateNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountStateNotification_descriptor_;
}

const GameAccountStateNotification& GameAccountStateNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GameAccountStateNotification* GameAccountStateNotification::default_instance_ = NULL;

GameAccountStateNotification* GameAccountStateNotification::New() const {
  return new GameAccountStateNotification;
}

void GameAccountStateNotification::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_game_account_state()) {
      if (game_account_state_ != NULL) game_account_state_->::bgs::protocol::account::v1::GameAccountState::Clear();
    }
    subscriber_id_ = GOOGLE_ULONGLONG(0);
    if (has_game_account_tags()) {
      if (game_account_tags_ != NULL) game_account_tags_->::bgs::protocol::account::v1::GameAccountFieldTags::Clear();
    }
    subscription_completed_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountStateNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountStateNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_state()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_subscriber_id;
        break;
      }

      // optional uint64 subscriber_id = 2;
      case 2: {
        if (tag == 16) {
         parse_subscriber_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &subscriber_id_)));
          set_has_subscriber_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_game_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 3;
      case 3: {
        if (tag == 26) {
         parse_game_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_subscription_completed;
        break;
      }

      // optional bool subscription_completed = 4;
      case 4: {
        if (tag == 32) {
         parse_subscription_completed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &subscription_completed_)));
          set_has_subscription_completed();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountStateNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountStateNotification)
  return false;
#undef DO_
}

void GameAccountStateNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountStateNotification)
  // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
  if (has_game_account_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_state(), output);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->subscriber_id(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 3;
  if (has_game_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->game_account_tags(), output);
  }

  // optional bool subscription_completed = 4;
  if (has_subscription_completed()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->subscription_completed(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountStateNotification)
}

::google::protobuf::uint8* GameAccountStateNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountStateNotification)
  // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
  if (has_game_account_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_state(), target);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->subscriber_id(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 3;
  if (has_game_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->game_account_tags(), target);
  }

  // optional bool subscription_completed = 4;
  if (has_subscription_completed()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->subscription_completed(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountStateNotification)
  return target;
}

int GameAccountStateNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
    if (has_game_account_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_state());
    }

    // optional uint64 subscriber_id = 2;
    if (has_subscriber_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->subscriber_id());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 3;
    if (has_game_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_tags());
    }

    // optional bool subscription_completed = 4;
    if (has_subscription_completed()) {
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

void GameAccountStateNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountStateNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountStateNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountStateNotification::MergeFrom(const GameAccountStateNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_state()) {
      mutable_game_account_state()->::bgs::protocol::account::v1::GameAccountState::MergeFrom(from.game_account_state());
    }
    if (from.has_subscriber_id()) {
      set_subscriber_id(from.subscriber_id());
    }
    if (from.has_game_account_tags()) {
      mutable_game_account_tags()->::bgs::protocol::account::v1::GameAccountFieldTags::MergeFrom(from.game_account_tags());
    }
    if (from.has_subscription_completed()) {
      set_subscription_completed(from.subscription_completed());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountStateNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountStateNotification::CopyFrom(const GameAccountStateNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountStateNotification::IsInitialized() const {

  if (has_game_account_state()) {
    if (!this->game_account_state().IsInitialized()) return false;
  }
  return true;
}

void GameAccountStateNotification::Swap(GameAccountStateNotification* other) {
  if (other != this) {
    std::swap(game_account_state_, other->game_account_state_);
    std::swap(subscriber_id_, other->subscriber_id_);
    std::swap(game_account_tags_, other->game_account_tags_);
    std::swap(subscription_completed_, other->subscription_completed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountStateNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountStateNotification_descriptor_;
  metadata.reflection = GameAccountStateNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountNotification::kGameAccountsFieldNumber;
const int GameAccountNotification::kSubscriberIdFieldNumber;
const int GameAccountNotification::kAccountTagsFieldNumber;
#endif  // !_MSC_VER

GameAccountNotification::GameAccountNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountNotification)
}

void GameAccountNotification::InitAsDefaultInstance() {
  account_tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
}

GameAccountNotification::GameAccountNotification(const GameAccountNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountNotification)
}

void GameAccountNotification::SharedCtor() {
  _cached_size_ = 0;
  subscriber_id_ = GOOGLE_ULONGLONG(0);
  account_tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountNotification::~GameAccountNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountNotification)
  SharedDtor();
}

void GameAccountNotification::SharedDtor() {
  if (this != default_instance_) {
    delete account_tags_;
  }
}

void GameAccountNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountNotification_descriptor_;
}

const GameAccountNotification& GameAccountNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GameAccountNotification* GameAccountNotification::default_instance_ = NULL;

GameAccountNotification* GameAccountNotification::New() const {
  return new GameAccountNotification;
}

void GameAccountNotification::Clear() {
  if (_has_bits_[0 / 32] & 6) {
    subscriber_id_ = GOOGLE_ULONGLONG(0);
    if (has_account_tags()) {
      if (account_tags_ != NULL) account_tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
  }
  game_accounts_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 1;
      case 1: {
        if (tag == 10) {
         parse_game_accounts:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_accounts()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_game_accounts;
        if (input->ExpectTag(16)) goto parse_subscriber_id;
        break;
      }

      // optional uint64 subscriber_id = 2;
      case 2: {
        if (tag == 16) {
         parse_subscriber_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &subscriber_id_)));
          set_has_subscriber_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
      case 3: {
        if (tag == 26) {
         parse_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountNotification)
  return false;
#undef DO_
}

void GameAccountNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountNotification)
  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 1;
  for (int i = 0; i < this->game_accounts_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_accounts(i), output);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->subscriber_id(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
  if (has_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountNotification)
}

::google::protobuf::uint8* GameAccountNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountNotification)
  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 1;
  for (int i = 0; i < this->game_accounts_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_accounts(i), target);
  }

  // optional uint64 subscriber_id = 2;
  if (has_subscriber_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->subscriber_id(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
  if (has_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountNotification)
  return target;
}

int GameAccountNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional uint64 subscriber_id = 2;
    if (has_subscriber_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->subscriber_id());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 3;
    if (has_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_tags());
    }

  }
  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 1;
  total_size += 1 * this->game_accounts_size();
  for (int i = 0; i < this->game_accounts_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_accounts(i));
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

void GameAccountNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountNotification::MergeFrom(const GameAccountNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  game_accounts_.MergeFrom(from.game_accounts_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_subscriber_id()) {
      set_subscriber_id(from.subscriber_id());
    }
    if (from.has_account_tags()) {
      mutable_account_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.account_tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountNotification::CopyFrom(const GameAccountNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountNotification::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->game_accounts())) return false;
  return true;
}

void GameAccountNotification::Swap(GameAccountNotification* other) {
  if (other != this) {
    game_accounts_.Swap(&other->game_accounts_);
    std::swap(subscriber_id_, other->subscriber_id_);
    std::swap(account_tags_, other->account_tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountNotification_descriptor_;
  metadata.reflection = GameAccountNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountSessionNotification::kGameAccountFieldNumber;
const int GameAccountSessionNotification::kSessionInfoFieldNumber;
#endif  // !_MSC_VER

GameAccountSessionNotification::GameAccountSessionNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountSessionNotification)
}

void GameAccountSessionNotification::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
  session_info_ = const_cast< ::bgs::protocol::account::v1::GameSessionUpdateInfo*>(&::bgs::protocol::account::v1::GameSessionUpdateInfo::default_instance());
}

GameAccountSessionNotification::GameAccountSessionNotification(const GameAccountSessionNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountSessionNotification)
}

void GameAccountSessionNotification::SharedCtor() {
  _cached_size_ = 0;
  game_account_ = NULL;
  session_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountSessionNotification::~GameAccountSessionNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountSessionNotification)
  SharedDtor();
}

void GameAccountSessionNotification::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_;
    delete session_info_;
  }
}

void GameAccountSessionNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountSessionNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountSessionNotification_descriptor_;
}

const GameAccountSessionNotification& GameAccountSessionNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5fservice_2eproto();
  return *default_instance_;
}

GameAccountSessionNotification* GameAccountSessionNotification::default_instance_ = NULL;

GameAccountSessionNotification* GameAccountSessionNotification::New() const {
  return new GameAccountSessionNotification;
}

void GameAccountSessionNotification::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_session_info()) {
      if (session_info_ != NULL) session_info_->::bgs::protocol::account::v1::GameSessionUpdateInfo::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountSessionNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountSessionNotification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_session_info;
        break;
      }

      // optional .bgs.protocol.account.v1.GameSessionUpdateInfo session_info = 2;
      case 2: {
        if (tag == 18) {
         parse_session_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_session_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountSessionNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountSessionNotification)
  return false;
#undef DO_
}

void GameAccountSessionNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountSessionNotification)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional .bgs.protocol.account.v1.GameSessionUpdateInfo session_info = 2;
  if (has_session_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->session_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountSessionNotification)
}

::google::protobuf::uint8* GameAccountSessionNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountSessionNotification)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional .bgs.protocol.account.v1.GameSessionUpdateInfo session_info = 2;
  if (has_session_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->session_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountSessionNotification)
  return target;
}

int GameAccountSessionNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional .bgs.protocol.account.v1.GameSessionUpdateInfo session_info = 2;
    if (has_session_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->session_info());
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

void GameAccountSessionNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountSessionNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountSessionNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountSessionNotification::MergeFrom(const GameAccountSessionNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_session_info()) {
      mutable_session_info()->::bgs::protocol::account::v1::GameSessionUpdateInfo::MergeFrom(from.session_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountSessionNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountSessionNotification::CopyFrom(const GameAccountSessionNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountSessionNotification::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void GameAccountSessionNotification::Swap(GameAccountSessionNotification* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(session_info_, other->session_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountSessionNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountSessionNotification_descriptor_;
  metadata.reflection = GameAccountSessionNotification_reflection_;
  return metadata;
}


// ===================================================================

AccountService::AccountService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

AccountService::~AccountService() {
}

google::protobuf::ServiceDescriptor const* AccountService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountService_descriptor_;
}

void AccountService::GetGameAccountBlob(::bgs::protocol::account::v1::GameAccountHandle const* request, std::function<void(::bgs::protocol::account::v1::GameAccountBlob const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetGameAccountBlob(bgs.protocol.account.v1.GameAccountHandle{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GameAccountBlob response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 12, request, std::move(callback));
}

void AccountService::GetAccount(::bgs::protocol::account::v1::GetAccountRequest const* request, std::function<void(::bgs::protocol::account::v1::GetAccountResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetAccount(bgs.protocol.account.v1.GetAccountRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetAccountResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 13, request, std::move(callback));
}

void AccountService::CreateGameAccount(::bgs::protocol::account::v1::CreateGameAccountRequest const* request, std::function<void(::bgs::protocol::account::v1::GameAccountHandle const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.CreateGameAccount(bgs.protocol.account.v1.CreateGameAccountRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GameAccountHandle response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 14, request, std::move(callback));
}

void AccountService::IsIgrAddress(::bgs::protocol::account::v1::IsIgrAddressRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.IsIgrAddress(bgs.protocol.account.v1.IsIgrAddressRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 15, request, std::move(callback));
}

void AccountService::CacheExpire(::bgs::protocol::account::v1::CacheExpireRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.CacheExpire(bgs.protocol.account.v1.CacheExpireRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 20, request);
}

void AccountService::CredentialUpdate(::bgs::protocol::account::v1::CredentialUpdateRequest const* request, std::function<void(::bgs::protocol::account::v1::CredentialUpdateResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.CredentialUpdate(bgs.protocol.account.v1.CredentialUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::CredentialUpdateResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 21, request, std::move(callback));
}

void AccountService::Subscribe(::bgs::protocol::account::v1::SubscriptionUpdateRequest const* request, std::function<void(::bgs::protocol::account::v1::SubscriptionUpdateResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.Subscribe(bgs.protocol.account.v1.SubscriptionUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::SubscriptionUpdateResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 25, request, std::move(callback));
}

void AccountService::Unsubscribe(::bgs::protocol::account::v1::SubscriptionUpdateRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.Unsubscribe(bgs.protocol.account.v1.SubscriptionUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 26, request, std::move(callback));
}

void AccountService::GetAccountState(::bgs::protocol::account::v1::GetAccountStateRequest const* request, std::function<void(::bgs::protocol::account::v1::GetAccountStateResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetAccountState(bgs.protocol.account.v1.GetAccountStateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetAccountStateResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 30, request, std::move(callback));
}

void AccountService::GetGameAccountState(::bgs::protocol::account::v1::GetGameAccountStateRequest const* request, std::function<void(::bgs::protocol::account::v1::GetGameAccountStateResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetGameAccountState(bgs.protocol.account.v1.GetGameAccountStateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetGameAccountStateResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 31, request, std::move(callback));
}

void AccountService::GetLicenses(::bgs::protocol::account::v1::GetLicensesRequest const* request, std::function<void(::bgs::protocol::account::v1::GetLicensesResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetLicenses(bgs.protocol.account.v1.GetLicensesRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetLicensesResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 32, request, std::move(callback));
}

void AccountService::GetGameTimeRemainingInfo(::bgs::protocol::account::v1::GetGameTimeRemainingInfoRequest const* request, std::function<void(::bgs::protocol::account::v1::GetGameTimeRemainingInfoResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetGameTimeRemainingInfo(bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetGameTimeRemainingInfoResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 33, request, std::move(callback));
}

void AccountService::GetGameSessionInfo(::bgs::protocol::account::v1::GetGameSessionInfoRequest const* request, std::function<void(::bgs::protocol::account::v1::GetGameSessionInfoResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetGameSessionInfo(bgs.protocol.account.v1.GetGameSessionInfoRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetGameSessionInfoResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 34, request, std::move(callback));
}

void AccountService::GetCAISInfo(::bgs::protocol::account::v1::GetCAISInfoRequest const* request, std::function<void(::bgs::protocol::account::v1::GetCAISInfoResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetCAISInfo(bgs.protocol.account.v1.GetCAISInfoRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetCAISInfoResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 35, request, std::move(callback));
}

void AccountService::ForwardCacheExpire(::bgs::protocol::account::v1::ForwardCacheExpireRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.ForwardCacheExpire(bgs.protocol.account.v1.ForwardCacheExpireRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 36, request, std::move(callback));
}

void AccountService::GetAuthorizedData(::bgs::protocol::account::v1::GetAuthorizedDataRequest const* request, std::function<void(::bgs::protocol::account::v1::GetAuthorizedDataResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetAuthorizedData(bgs.protocol.account.v1.GetAuthorizedDataRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetAuthorizedDataResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 37, request, std::move(callback));
}

void AccountService::AccountFlagUpdate(::bgs::protocol::account::v1::AccountFlagUpdateRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.AccountFlagUpdate(bgs.protocol.account.v1.AccountFlagUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 38, request);
}

void AccountService::GameAccountFlagUpdate(::bgs::protocol::account::v1::GameAccountFlagUpdateRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GameAccountFlagUpdate(bgs.protocol.account.v1.GameAccountFlagUpdateRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 39, request);
}

void AccountService::UpdateParentalControlsAndCAIS(::bgs::protocol::account::v1::UpdateParentalControlsAndCAISRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.UpdateParentalControlsAndCAIS(bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 40, request, std::move(callback));
}

void AccountService::CreateGameAccount2(::bgs::protocol::account::v1::CreateGameAccountRequest const* request, std::function<void(::bgs::protocol::account::v1::CreateGameAccountResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.CreateGameAccount2(bgs.protocol.account.v1.CreateGameAccountRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::CreateGameAccountResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 41, request, std::move(callback));
}

void AccountService::GetGameAccount(::bgs::protocol::account::v1::GetGameAccountRequest const* request, std::function<void(::bgs::protocol::account::v1::GetGameAccountResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.GetGameAccount(bgs.protocol.account.v1.GetGameAccountRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::account::v1::GetGameAccountResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 42, request, std::move(callback));
}

void AccountService::QueueDeductRecord(::bgs::protocol::account::v1::QueueDeductRecordRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountService.QueueDeductRecord(bgs.protocol.account.v1.QueueDeductRecordRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 43, request, std::move(callback));
}

void AccountService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 12: {
      ::bgs::protocol::account::v1::GameAccountHandle request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetGameAccountBlob server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 12, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GameAccountBlob response;
      uint32 status = HandleGetGameAccountBlob(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetGameAccountBlob(bgs.protocol.account.v1.GameAccountHandle{ %s }) returned bgs.protocol.account.v1.GameAccountBlob{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 12, token, &response);
      else
        SendResponse(service_hash_, 12, token, status);
      break;
    }
    case 13: {
      ::bgs::protocol::account::v1::GetAccountRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetAccount server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 13, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetAccountResponse response;
      uint32 status = HandleGetAccount(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetAccount(bgs.protocol.account.v1.GetAccountRequest{ %s }) returned bgs.protocol.account.v1.GetAccountResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 13, token, &response);
      else
        SendResponse(service_hash_, 13, token, status);
      break;
    }
    case 14: {
      ::bgs::protocol::account::v1::CreateGameAccountRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.CreateGameAccount server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 14, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GameAccountHandle response;
      uint32 status = HandleCreateGameAccount(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.CreateGameAccount(bgs.protocol.account.v1.CreateGameAccountRequest{ %s }) returned bgs.protocol.account.v1.GameAccountHandle{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 14, token, &response);
      else
        SendResponse(service_hash_, 14, token, status);
      break;
    }
    case 15: {
      ::bgs::protocol::account::v1::IsIgrAddressRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.IsIgrAddress server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 15, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleIsIgrAddress(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.IsIgrAddress(bgs.protocol.account.v1.IsIgrAddressRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 15, token, &response);
      else
        SendResponse(service_hash_, 15, token, status);
      break;
    }
    case 20: {
      ::bgs::protocol::account::v1::CacheExpireRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.CacheExpire server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 20, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleCacheExpire(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.CacheExpire(bgs.protocol.account.v1.CacheExpireRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 20, token, status);
      break;
    }
    case 21: {
      ::bgs::protocol::account::v1::CredentialUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.CredentialUpdate server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 21, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::CredentialUpdateResponse response;
      uint32 status = HandleCredentialUpdate(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.CredentialUpdate(bgs.protocol.account.v1.CredentialUpdateRequest{ %s }) returned bgs.protocol.account.v1.CredentialUpdateResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 21, token, &response);
      else
        SendResponse(service_hash_, 21, token, status);
      break;
    }
    case 25: {
      ::bgs::protocol::account::v1::SubscriptionUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.Subscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 25, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::SubscriptionUpdateResponse response;
      uint32 status = HandleSubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.Subscribe(bgs.protocol.account.v1.SubscriptionUpdateRequest{ %s }) returned bgs.protocol.account.v1.SubscriptionUpdateResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 25, token, &response);
      else
        SendResponse(service_hash_, 25, token, status);
      break;
    }
    case 26: {
      ::bgs::protocol::account::v1::SubscriptionUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.Unsubscribe server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 26, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUnsubscribe(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.Unsubscribe(bgs.protocol.account.v1.SubscriptionUpdateRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 26, token, &response);
      else
        SendResponse(service_hash_, 26, token, status);
      break;
    }
    case 30: {
      ::bgs::protocol::account::v1::GetAccountStateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetAccountState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 30, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetAccountStateResponse response;
      uint32 status = HandleGetAccountState(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetAccountState(bgs.protocol.account.v1.GetAccountStateRequest{ %s }) returned bgs.protocol.account.v1.GetAccountStateResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 30, token, &response);
      else
        SendResponse(service_hash_, 30, token, status);
      break;
    }
    case 31: {
      ::bgs::protocol::account::v1::GetGameAccountStateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetGameAccountState server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 31, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetGameAccountStateResponse response;
      uint32 status = HandleGetGameAccountState(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetGameAccountState(bgs.protocol.account.v1.GetGameAccountStateRequest{ %s }) returned bgs.protocol.account.v1.GetGameAccountStateResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 31, token, &response);
      else
        SendResponse(service_hash_, 31, token, status);
      break;
    }
    case 32: {
      ::bgs::protocol::account::v1::GetLicensesRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetLicenses server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 32, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetLicensesResponse response;
      uint32 status = HandleGetLicenses(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetLicenses(bgs.protocol.account.v1.GetLicensesRequest{ %s }) returned bgs.protocol.account.v1.GetLicensesResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 32, token, &response);
      else
        SendResponse(service_hash_, 32, token, status);
      break;
    }
    case 33: {
      ::bgs::protocol::account::v1::GetGameTimeRemainingInfoRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetGameTimeRemainingInfo server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 33, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetGameTimeRemainingInfoResponse response;
      uint32 status = HandleGetGameTimeRemainingInfo(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetGameTimeRemainingInfo(bgs.protocol.account.v1.GetGameTimeRemainingInfoRequest{ %s }) returned bgs.protocol.account.v1.GetGameTimeRemainingInfoResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 33, token, &response);
      else
        SendResponse(service_hash_, 33, token, status);
      break;
    }
    case 34: {
      ::bgs::protocol::account::v1::GetGameSessionInfoRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetGameSessionInfo server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 34, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetGameSessionInfoResponse response;
      uint32 status = HandleGetGameSessionInfo(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetGameSessionInfo(bgs.protocol.account.v1.GetGameSessionInfoRequest{ %s }) returned bgs.protocol.account.v1.GetGameSessionInfoResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 34, token, &response);
      else
        SendResponse(service_hash_, 34, token, status);
      break;
    }
    case 35: {
      ::bgs::protocol::account::v1::GetCAISInfoRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetCAISInfo server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 35, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetCAISInfoResponse response;
      uint32 status = HandleGetCAISInfo(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetCAISInfo(bgs.protocol.account.v1.GetCAISInfoRequest{ %s }) returned bgs.protocol.account.v1.GetCAISInfoResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 35, token, &response);
      else
        SendResponse(service_hash_, 35, token, status);
      break;
    }
    case 36: {
      ::bgs::protocol::account::v1::ForwardCacheExpireRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.ForwardCacheExpire server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 36, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleForwardCacheExpire(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.ForwardCacheExpire(bgs.protocol.account.v1.ForwardCacheExpireRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 36, token, &response);
      else
        SendResponse(service_hash_, 36, token, status);
      break;
    }
    case 37: {
      ::bgs::protocol::account::v1::GetAuthorizedDataRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetAuthorizedData server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 37, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetAuthorizedDataResponse response;
      uint32 status = HandleGetAuthorizedData(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetAuthorizedData(bgs.protocol.account.v1.GetAuthorizedDataRequest{ %s }) returned bgs.protocol.account.v1.GetAuthorizedDataResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 37, token, &response);
      else
        SendResponse(service_hash_, 37, token, status);
      break;
    }
    case 38: {
      ::bgs::protocol::account::v1::AccountFlagUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.AccountFlagUpdate server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 38, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleAccountFlagUpdate(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.AccountFlagUpdate(bgs.protocol.account.v1.AccountFlagUpdateRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 38, token, status);
      break;
    }
    case 39: {
      ::bgs::protocol::account::v1::GameAccountFlagUpdateRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GameAccountFlagUpdate server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 39, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleGameAccountFlagUpdate(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GameAccountFlagUpdate(bgs.protocol.account.v1.GameAccountFlagUpdateRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 39, token, status);
      break;
    }
    case 40: {
      ::bgs::protocol::account::v1::UpdateParentalControlsAndCAISRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.UpdateParentalControlsAndCAIS server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 40, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleUpdateParentalControlsAndCAIS(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.UpdateParentalControlsAndCAIS(bgs.protocol.account.v1.UpdateParentalControlsAndCAISRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 40, token, &response);
      else
        SendResponse(service_hash_, 40, token, status);
      break;
    }
    case 41: {
      ::bgs::protocol::account::v1::CreateGameAccountRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.CreateGameAccount2 server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 41, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::CreateGameAccountResponse response;
      uint32 status = HandleCreateGameAccount2(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.CreateGameAccount2(bgs.protocol.account.v1.CreateGameAccountRequest{ %s }) returned bgs.protocol.account.v1.CreateGameAccountResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 41, token, &response);
      else
        SendResponse(service_hash_, 41, token, status);
      break;
    }
    case 42: {
      ::bgs::protocol::account::v1::GetGameAccountRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.GetGameAccount server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 42, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::account::v1::GetGameAccountResponse response;
      uint32 status = HandleGetGameAccount(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.GetGameAccount(bgs.protocol.account.v1.GetGameAccountRequest{ %s }) returned bgs.protocol.account.v1.GetGameAccountResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 42, token, &response);
      else
        SendResponse(service_hash_, 42, token, status);
      break;
    }
    case 43: {
      ::bgs::protocol::account::v1::QueueDeductRecordRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountService.QueueDeductRecord server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 43, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleQueueDeductRecord(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountService.QueueDeductRecord(bgs.protocol.account.v1.QueueDeductRecordRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 43, token, &response);
      else
        SendResponse(service_hash_, 43, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 AccountService::HandleGetGameAccountBlob(::bgs::protocol::account::v1::GameAccountHandle const* request, ::bgs::protocol::account::v1::GameAccountBlob* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetGameAccountBlob({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetAccount(::bgs::protocol::account::v1::GetAccountRequest const* request, ::bgs::protocol::account::v1::GetAccountResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetAccount({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleCreateGameAccount(::bgs::protocol::account::v1::CreateGameAccountRequest const* request, ::bgs::protocol::account::v1::GameAccountHandle* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.CreateGameAccount({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleIsIgrAddress(::bgs::protocol::account::v1::IsIgrAddressRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.IsIgrAddress({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleCacheExpire(::bgs::protocol::account::v1::CacheExpireRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.CacheExpire({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleCredentialUpdate(::bgs::protocol::account::v1::CredentialUpdateRequest const* request, ::bgs::protocol::account::v1::CredentialUpdateResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.CredentialUpdate({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleSubscribe(::bgs::protocol::account::v1::SubscriptionUpdateRequest const* request, ::bgs::protocol::account::v1::SubscriptionUpdateResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.Subscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleUnsubscribe(::bgs::protocol::account::v1::SubscriptionUpdateRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.Unsubscribe({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetAccountState(::bgs::protocol::account::v1::GetAccountStateRequest const* request, ::bgs::protocol::account::v1::GetAccountStateResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetAccountState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetGameAccountState(::bgs::protocol::account::v1::GetGameAccountStateRequest const* request, ::bgs::protocol::account::v1::GetGameAccountStateResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetGameAccountState({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetLicenses(::bgs::protocol::account::v1::GetLicensesRequest const* request, ::bgs::protocol::account::v1::GetLicensesResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetLicenses({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetGameTimeRemainingInfo(::bgs::protocol::account::v1::GetGameTimeRemainingInfoRequest const* request, ::bgs::protocol::account::v1::GetGameTimeRemainingInfoResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetGameTimeRemainingInfo({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetGameSessionInfo(::bgs::protocol::account::v1::GetGameSessionInfoRequest const* request, ::bgs::protocol::account::v1::GetGameSessionInfoResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetGameSessionInfo({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetCAISInfo(::bgs::protocol::account::v1::GetCAISInfoRequest const* request, ::bgs::protocol::account::v1::GetCAISInfoResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetCAISInfo({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleForwardCacheExpire(::bgs::protocol::account::v1::ForwardCacheExpireRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.ForwardCacheExpire({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetAuthorizedData(::bgs::protocol::account::v1::GetAuthorizedDataRequest const* request, ::bgs::protocol::account::v1::GetAuthorizedDataResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetAuthorizedData({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleAccountFlagUpdate(::bgs::protocol::account::v1::AccountFlagUpdateRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.AccountFlagUpdate({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGameAccountFlagUpdate(::bgs::protocol::account::v1::GameAccountFlagUpdateRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GameAccountFlagUpdate({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleUpdateParentalControlsAndCAIS(::bgs::protocol::account::v1::UpdateParentalControlsAndCAISRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.UpdateParentalControlsAndCAIS({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleCreateGameAccount2(::bgs::protocol::account::v1::CreateGameAccountRequest const* request, ::bgs::protocol::account::v1::CreateGameAccountResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.CreateGameAccount2({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleGetGameAccount(::bgs::protocol::account::v1::GetGameAccountRequest const* request, ::bgs::protocol::account::v1::GetGameAccountResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.GetGameAccount({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountService::HandleQueueDeductRecord(::bgs::protocol::account::v1::QueueDeductRecordRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountService.QueueDeductRecord({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

// ===================================================================

AccountListener::AccountListener(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

AccountListener::~AccountListener() {
}

google::protobuf::ServiceDescriptor const* AccountListener::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountListener_descriptor_;
}

void AccountListener::OnAccountStateUpdated(::bgs::protocol::account::v1::AccountStateNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountListener.OnAccountStateUpdated(bgs.protocol.account.v1.AccountStateNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 1, request);
}

void AccountListener::OnGameAccountStateUpdated(::bgs::protocol::account::v1::GameAccountStateNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountListener.OnGameAccountStateUpdated(bgs.protocol.account.v1.GameAccountStateNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 2, request);
}

void AccountListener::OnGameAccountsUpdated(::bgs::protocol::account::v1::GameAccountNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountListener.OnGameAccountsUpdated(bgs.protocol.account.v1.GameAccountNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 3, request);
}

void AccountListener::OnGameSessionUpdated(::bgs::protocol::account::v1::GameAccountSessionNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method AccountListener.OnGameSessionUpdated(bgs.protocol.account.v1.GameAccountSessionNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void AccountListener::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::account::v1::AccountStateNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountListener.OnAccountStateUpdated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnAccountStateUpdated(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountListener.OnAccountStateUpdated(bgs.protocol.account.v1.AccountStateNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::account::v1::GameAccountStateNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountListener.OnGameAccountStateUpdated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameAccountStateUpdated(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountListener.OnGameAccountStateUpdated(bgs.protocol.account.v1.GameAccountStateNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::account::v1::GameAccountNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountListener.OnGameAccountsUpdated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameAccountsUpdated(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountListener.OnGameAccountsUpdated(bgs.protocol.account.v1.GameAccountNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::account::v1::GameAccountSessionNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for AccountListener.OnGameSessionUpdated server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleOnGameSessionUpdated(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method AccountListener.OnGameSessionUpdated(bgs.protocol.account.v1.GameAccountSessionNotification{ %s }) status %u.",
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

uint32 AccountListener::HandleOnAccountStateUpdated(::bgs::protocol::account::v1::AccountStateNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountListener.OnAccountStateUpdated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountListener::HandleOnGameAccountStateUpdated(::bgs::protocol::account::v1::GameAccountStateNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountListener.OnGameAccountStateUpdated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountListener::HandleOnGameAccountsUpdated(::bgs::protocol::account::v1::GameAccountNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountListener.OnGameAccountsUpdated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 AccountListener::HandleOnGameSessionUpdated(::bgs::protocol::account::v1::GameAccountSessionNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method AccountListener.OnGameSessionUpdated({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace account
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
