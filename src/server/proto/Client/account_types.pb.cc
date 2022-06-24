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
#include "account_types.pb.h"

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
namespace account {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* AccountId_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountId_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountLicense_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountLicense_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountCredential_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountCredential_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountBlob_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountBlob_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountBlobList_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountBlobList_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountHandle_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountHandle_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountLink_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountLink_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountBlob_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountBlob_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountBlobList_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountBlobList_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountReference_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountReference_reflection_ = NULL;
const ::google::protobuf::Descriptor* Identity_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Identity_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* ProgramTag_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ProgramTag_reflection_ = NULL;
const ::google::protobuf::Descriptor* RegionTag_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RegionTag_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountFieldTags_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountFieldTags_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountFieldTags_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountFieldTags_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountFieldOptions_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountFieldOptions_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountFieldOptions_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountFieldOptions_reflection_ = NULL;
const ::google::protobuf::Descriptor* SubscriberReference_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SubscriberReference_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountLevelInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountLevelInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* PrivacyInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PrivacyInfo_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* PrivacyInfo_GameInfoPrivacy_descriptor_ = NULL;
const ::google::protobuf::Descriptor* ParentalControlInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ParentalControlInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameLevelInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameLevelInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameTimeInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameTimeInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameTimeRemainingInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameTimeRemainingInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameStatus_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameStatus_reflection_ = NULL;
const ::google::protobuf::Descriptor* RAFInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RAFInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameSessionInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameSessionInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameSessionUpdateInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameSessionUpdateInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameSessionLocation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameSessionLocation_reflection_ = NULL;
const ::google::protobuf::Descriptor* CAIS_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CAIS_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountList_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountList_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountState_reflection_ = NULL;
const ::google::protobuf::Descriptor* AccountStateTagged_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AccountStateTagged_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountState_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameAccountStateTagged_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameAccountStateTagged_reflection_ = NULL;
const ::google::protobuf::Descriptor* AuthorizedData_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AuthorizedData_reflection_ = NULL;
const ::google::protobuf::Descriptor* BenefactorAddress_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BenefactorAddress_reflection_ = NULL;
const ::google::protobuf::Descriptor* ExternalBenefactorLookup_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ExternalBenefactorLookup_reflection_ = NULL;
const ::google::protobuf::Descriptor* AuthBenefactor_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AuthBenefactor_reflection_ = NULL;
const ::google::protobuf::Descriptor* ApplicationInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ApplicationInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* DeductRecord_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DeductRecord_reflection_ = NULL;
const ::google::protobuf::Descriptor* IgrId_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  IgrId_reflection_ = NULL;
struct IgrIdOneofInstance {
  const ::bgs::protocol::account::v1::GameAccountHandle* game_account_;
  ::google::protobuf::uint32 external_id_;
}* IgrId_default_oneof_instance_ = NULL;
const ::google::protobuf::EnumDescriptor* IdentityVerificationStatus_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_account_5ftypes_2eproto() {
  protobuf_AddDesc_account_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "account_types.proto");
  GOOGLE_CHECK(file != NULL);
  AccountId_descriptor_ = file->message_type(0);
  static const int AccountId_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountId, id_),
  };
  AccountId_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountId_descriptor_,
      AccountId::default_instance_,
      AccountId_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountId, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountId, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountId));
  AccountLicense_descriptor_ = file->message_type(1);
  static const int AccountLicense_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLicense, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLicense, expires_),
  };
  AccountLicense_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountLicense_descriptor_,
      AccountLicense::default_instance_,
      AccountLicense_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLicense, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLicense, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountLicense));
  AccountCredential_descriptor_ = file->message_type(2);
  static const int AccountCredential_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountCredential, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountCredential, data_),
  };
  AccountCredential_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountCredential_descriptor_,
      AccountCredential::default_instance_,
      AccountCredential_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountCredential, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountCredential, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountCredential));
  AccountBlob_descriptor_ = file->message_type(3);
  static const int AccountBlob_offsets_[21] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, flags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, secure_release_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, whitelist_start_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, whitelist_end_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, credentials_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, account_links_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, default_currency_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, legal_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, legal_locale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, cache_expiration_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, parental_control_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, country_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, preferred_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, identity_check_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, cais_id_),
  };
  AccountBlob_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountBlob_descriptor_,
      AccountBlob::default_instance_,
      AccountBlob_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlob, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountBlob));
  AccountBlobList_descriptor_ = file->message_type(4);
  static const int AccountBlobList_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlobList, blob_),
  };
  AccountBlobList_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountBlobList_descriptor_,
      AccountBlobList::default_instance_,
      AccountBlobList_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlobList, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountBlobList, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountBlobList));
  GameAccountHandle_descriptor_ = file->message_type(5);
  static const int GameAccountHandle_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountHandle, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountHandle, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountHandle, region_),
  };
  GameAccountHandle_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountHandle_descriptor_,
      GameAccountHandle::default_instance_,
      GameAccountHandle_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountHandle, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountHandle, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountHandle));
  GameAccountLink_descriptor_ = file->message_type(6);
  static const int GameAccountLink_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountLink, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountLink, name_),
  };
  GameAccountLink_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountLink_descriptor_,
      GameAccountLink::default_instance_,
      GameAccountLink_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountLink, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountLink, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountLink));
  GameAccountBlob_descriptor_ = file->message_type(7);
  static const int GameAccountBlob_offsets_[16] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, realm_permissions_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, flags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, billing_flags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, cache_expiration_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, subscription_expiration_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, units_remaining_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, status_expiration_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, box_level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, box_level_expiration_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, raf_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, raf_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, raf_expiration_),
  };
  GameAccountBlob_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountBlob_descriptor_,
      GameAccountBlob::default_instance_,
      GameAccountBlob_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlob, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountBlob));
  GameAccountBlobList_descriptor_ = file->message_type(8);
  static const int GameAccountBlobList_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlobList, blob_),
  };
  GameAccountBlobList_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountBlobList_descriptor_,
      GameAccountBlobList::default_instance_,
      GameAccountBlobList_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlobList, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountBlobList, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountBlobList));
  AccountReference_descriptor_ = file->message_type(9);
  static const int AccountReference_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, handle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, region_),
  };
  AccountReference_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountReference_descriptor_,
      AccountReference::default_instance_,
      AccountReference_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountReference, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountReference));
  Identity_descriptor_ = file->message_type(10);
  static const int Identity_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, process_),
  };
  Identity_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Identity_descriptor_,
      Identity::default_instance_,
      Identity_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Identity, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Identity));
  AccountInfo_descriptor_ = file->message_type(11);
  static const int AccountInfo_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, account_paid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, country_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, manual_review_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, identity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, account_muted_),
  };
  AccountInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountInfo_descriptor_,
      AccountInfo::default_instance_,
      AccountInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountInfo));
  ProgramTag_descriptor_ = file->message_type(12);
  static const int ProgramTag_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProgramTag, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProgramTag, tag_),
  };
  ProgramTag_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ProgramTag_descriptor_,
      ProgramTag::default_instance_,
      ProgramTag_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProgramTag, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProgramTag, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ProgramTag));
  RegionTag_descriptor_ = file->message_type(13);
  static const int RegionTag_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RegionTag, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RegionTag, tag_),
  };
  RegionTag_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RegionTag_descriptor_,
      RegionTag::default_instance_,
      RegionTag_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RegionTag, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RegionTag, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RegionTag));
  AccountFieldTags_descriptor_ = file->message_type(14);
  static const int AccountFieldTags_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, account_level_info_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, privacy_info_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, parental_control_info_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, game_level_info_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, game_status_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, game_account_tags_),
  };
  AccountFieldTags_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountFieldTags_descriptor_,
      AccountFieldTags::default_instance_,
      AccountFieldTags_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldTags, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountFieldTags));
  GameAccountFieldTags_descriptor_ = file->message_type(15);
  static const int GameAccountFieldTags_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, game_level_info_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, game_time_info_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, game_status_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, raf_info_tag_),
  };
  GameAccountFieldTags_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountFieldTags_descriptor_,
      GameAccountFieldTags::default_instance_,
      GameAccountFieldTags_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldTags, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountFieldTags));
  AccountFieldOptions_descriptor_ = file->message_type(16);
  static const int AccountFieldOptions_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, all_fields_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_account_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_privacy_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_parental_control_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_game_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_game_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, field_game_accounts_),
  };
  AccountFieldOptions_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountFieldOptions_descriptor_,
      AccountFieldOptions::default_instance_,
      AccountFieldOptions_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountFieldOptions, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountFieldOptions));
  GameAccountFieldOptions_descriptor_ = file->message_type(17);
  static const int GameAccountFieldOptions_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, all_fields_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, field_game_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, field_game_time_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, field_game_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, field_raf_info_),
  };
  GameAccountFieldOptions_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountFieldOptions_descriptor_,
      GameAccountFieldOptions::default_instance_,
      GameAccountFieldOptions_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountFieldOptions, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountFieldOptions));
  SubscriberReference_descriptor_ = file->message_type(18);
  static const int SubscriberReference_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, object_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, entity_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, account_options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, account_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, game_account_options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, game_account_tags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, subscriber_id_),
  };
  SubscriberReference_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SubscriberReference_descriptor_,
      SubscriberReference::default_instance_,
      SubscriberReference_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SubscriberReference, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SubscriberReference));
  AccountLevelInfo_descriptor_ = file->message_type(19);
  static const int AccountLevelInfo_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, default_currency_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, country_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, preferred_region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, full_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, battle_tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, muted_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, manual_review_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, account_paid_any_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, identity_check_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, email_),
  };
  AccountLevelInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountLevelInfo_descriptor_,
      AccountLevelInfo::default_instance_,
      AccountLevelInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountLevelInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountLevelInfo));
  PrivacyInfo_descriptor_ = file->message_type(20);
  static const int PrivacyInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, is_using_rid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, is_real_id_visible_for_view_friends_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, is_hidden_from_friend_finder_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, game_info_privacy_),
  };
  PrivacyInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PrivacyInfo_descriptor_,
      PrivacyInfo::default_instance_,
      PrivacyInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PrivacyInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PrivacyInfo));
  PrivacyInfo_GameInfoPrivacy_descriptor_ = PrivacyInfo_descriptor_->enum_type(0);
  ParentalControlInfo_descriptor_ = file->message_type(21);
  static const int ParentalControlInfo_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, timezone_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, minutes_per_day_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, minutes_per_week_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, can_receive_voice_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, can_send_voice_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, play_schedule_),
  };
  ParentalControlInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ParentalControlInfo_descriptor_,
      ParentalControlInfo::default_instance_,
      ParentalControlInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ParentalControlInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ParentalControlInfo));
  GameLevelInfo_descriptor_ = file->message_type(22);
  static const int GameLevelInfo_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, is_trial_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, is_lifetime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, is_restricted_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, is_beta_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, licenses_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, realm_permissions_),
  };
  GameLevelInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameLevelInfo_descriptor_,
      GameLevelInfo::default_instance_,
      GameLevelInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameLevelInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameLevelInfo));
  GameTimeInfo_descriptor_ = file->message_type(23);
  static const int GameTimeInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, is_unlimited_play_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, play_time_expires_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, is_subscription_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, is_recurring_subscription_),
  };
  GameTimeInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameTimeInfo_descriptor_,
      GameTimeInfo::default_instance_,
      GameTimeInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameTimeInfo));
  GameTimeRemainingInfo_descriptor_ = file->message_type(24);
  static const int GameTimeRemainingInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, minutes_remaining_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, parental_daily_minutes_remaining_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, parental_weekly_minutes_remaining_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, seconds_remaining_until_kick_),
  };
  GameTimeRemainingInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameTimeRemainingInfo_descriptor_,
      GameTimeRemainingInfo::default_instance_,
      GameTimeRemainingInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameTimeRemainingInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameTimeRemainingInfo));
  GameStatus_descriptor_ = file->message_type(25);
  static const int GameStatus_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, is_suspended_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, is_banned_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, suspension_expires_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, program_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, is_locked_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, is_bam_unlockable_),
  };
  GameStatus_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameStatus_descriptor_,
      GameStatus::default_instance_,
      GameStatus_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStatus, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameStatus));
  RAFInfo_descriptor_ = file->message_type(26);
  static const int RAFInfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RAFInfo, raf_info_),
  };
  RAFInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RAFInfo_descriptor_,
      RAFInfo::default_instance_,
      RAFInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RAFInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RAFInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RAFInfo));
  GameSessionInfo_descriptor_ = file->message_type(27);
  static const int GameSessionInfo_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, location_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, has_benefactor_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, is_using_igr_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, parental_controls_active_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, start_time_sec_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, igr_id_),
  };
  GameSessionInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameSessionInfo_descriptor_,
      GameSessionInfo::default_instance_,
      GameSessionInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameSessionInfo));
  GameSessionUpdateInfo_descriptor_ = file->message_type(28);
  static const int GameSessionUpdateInfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionUpdateInfo, cais_),
  };
  GameSessionUpdateInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameSessionUpdateInfo_descriptor_,
      GameSessionUpdateInfo::default_instance_,
      GameSessionUpdateInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionUpdateInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionUpdateInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameSessionUpdateInfo));
  GameSessionLocation_descriptor_ = file->message_type(29);
  static const int GameSessionLocation_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionLocation, ip_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionLocation, country_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionLocation, city_),
  };
  GameSessionLocation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameSessionLocation_descriptor_,
      GameSessionLocation::default_instance_,
      GameSessionLocation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionLocation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameSessionLocation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameSessionLocation));
  CAIS_descriptor_ = file->message_type(30);
  static const int CAIS_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAIS, played_minutes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAIS, rested_minutes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAIS, last_heard_time_),
  };
  CAIS_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CAIS_descriptor_,
      CAIS::default_instance_,
      CAIS_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAIS, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAIS, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CAIS));
  GameAccountList_descriptor_ = file->message_type(31);
  static const int GameAccountList_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountList, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountList, handle_),
  };
  GameAccountList_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountList_descriptor_,
      GameAccountList::default_instance_,
      GameAccountList_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountList, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountList, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountList));
  AccountState_descriptor_ = file->message_type(32);
  static const int AccountState_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, account_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, privacy_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, parental_control_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, game_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, game_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, game_accounts_),
  };
  AccountState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountState_descriptor_,
      AccountState::default_instance_,
      AccountState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountState));
  AccountStateTagged_descriptor_ = file->message_type(33);
  static const int AccountStateTagged_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateTagged, account_state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateTagged, account_tags_),
  };
  AccountStateTagged_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AccountStateTagged_descriptor_,
      AccountStateTagged::default_instance_,
      AccountStateTagged_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateTagged, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AccountStateTagged, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AccountStateTagged));
  GameAccountState_descriptor_ = file->message_type(34);
  static const int GameAccountState_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, game_level_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, game_time_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, game_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, raf_info_),
  };
  GameAccountState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountState_descriptor_,
      GameAccountState::default_instance_,
      GameAccountState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountState));
  GameAccountStateTagged_descriptor_ = file->message_type(35);
  static const int GameAccountStateTagged_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateTagged, game_account_state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateTagged, game_account_tags_),
  };
  GameAccountStateTagged_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameAccountStateTagged_descriptor_,
      GameAccountStateTagged::default_instance_,
      GameAccountStateTagged_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateTagged, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameAccountStateTagged, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameAccountStateTagged));
  AuthorizedData_descriptor_ = file->message_type(36);
  static const int AuthorizedData_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthorizedData, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthorizedData, license_),
  };
  AuthorizedData_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AuthorizedData_descriptor_,
      AuthorizedData::default_instance_,
      AuthorizedData_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthorizedData, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthorizedData, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AuthorizedData));
  BenefactorAddress_descriptor_ = file->message_type(37);
  static const int BenefactorAddress_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BenefactorAddress, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BenefactorAddress, igr_address_),
  };
  BenefactorAddress_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BenefactorAddress_descriptor_,
      BenefactorAddress::default_instance_,
      BenefactorAddress_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BenefactorAddress, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BenefactorAddress, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BenefactorAddress));
  ExternalBenefactorLookup_descriptor_ = file->message_type(38);
  static const int ExternalBenefactorLookup_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExternalBenefactorLookup, benefactor_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExternalBenefactorLookup, region_),
  };
  ExternalBenefactorLookup_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ExternalBenefactorLookup_descriptor_,
      ExternalBenefactorLookup::default_instance_,
      ExternalBenefactorLookup_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExternalBenefactorLookup, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExternalBenefactorLookup, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ExternalBenefactorLookup));
  AuthBenefactor_descriptor_ = file->message_type(39);
  static const int AuthBenefactor_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, igr_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, benefactor_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, active_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, last_update_time_),
  };
  AuthBenefactor_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AuthBenefactor_descriptor_,
      AuthBenefactor::default_instance_,
      AuthBenefactor_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AuthBenefactor, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AuthBenefactor));
  ApplicationInfo_descriptor_ = file->message_type(40);
  static const int ApplicationInfo_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ApplicationInfo, platform_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ApplicationInfo, locale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ApplicationInfo, application_version_),
  };
  ApplicationInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ApplicationInfo_descriptor_,
      ApplicationInfo::default_instance_,
      ApplicationInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ApplicationInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ApplicationInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ApplicationInfo));
  DeductRecord_descriptor_ = file->message_type(41);
  static const int DeductRecord_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, benefactor_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, end_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, client_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, application_info_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, session_owner_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, free_session_),
  };
  DeductRecord_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DeductRecord_descriptor_,
      DeductRecord::default_instance_,
      DeductRecord_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeductRecord, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DeductRecord));
  IgrId_descriptor_ = file->message_type(42);
  static const int IgrId_offsets_[3] = {
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(IgrId_default_oneof_instance_, game_account_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(IgrId_default_oneof_instance_, external_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IgrId, type_),
  };
  IgrId_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      IgrId_descriptor_,
      IgrId::default_instance_,
      IgrId_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IgrId, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IgrId, _unknown_fields_),
      -1,
      IgrId_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IgrId, _oneof_case_[0]),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(IgrId));
  IdentityVerificationStatus_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_account_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountId_descriptor_, &AccountId::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountLicense_descriptor_, &AccountLicense::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountCredential_descriptor_, &AccountCredential::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountBlob_descriptor_, &AccountBlob::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountBlobList_descriptor_, &AccountBlobList::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountHandle_descriptor_, &GameAccountHandle::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountLink_descriptor_, &GameAccountLink::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountBlob_descriptor_, &GameAccountBlob::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountBlobList_descriptor_, &GameAccountBlobList::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountReference_descriptor_, &AccountReference::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Identity_descriptor_, &Identity::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountInfo_descriptor_, &AccountInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ProgramTag_descriptor_, &ProgramTag::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RegionTag_descriptor_, &RegionTag::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountFieldTags_descriptor_, &AccountFieldTags::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountFieldTags_descriptor_, &GameAccountFieldTags::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountFieldOptions_descriptor_, &AccountFieldOptions::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountFieldOptions_descriptor_, &GameAccountFieldOptions::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SubscriberReference_descriptor_, &SubscriberReference::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountLevelInfo_descriptor_, &AccountLevelInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PrivacyInfo_descriptor_, &PrivacyInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ParentalControlInfo_descriptor_, &ParentalControlInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameLevelInfo_descriptor_, &GameLevelInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameTimeInfo_descriptor_, &GameTimeInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameTimeRemainingInfo_descriptor_, &GameTimeRemainingInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameStatus_descriptor_, &GameStatus::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RAFInfo_descriptor_, &RAFInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameSessionInfo_descriptor_, &GameSessionInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameSessionUpdateInfo_descriptor_, &GameSessionUpdateInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameSessionLocation_descriptor_, &GameSessionLocation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CAIS_descriptor_, &CAIS::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountList_descriptor_, &GameAccountList::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountState_descriptor_, &AccountState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AccountStateTagged_descriptor_, &AccountStateTagged::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountState_descriptor_, &GameAccountState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameAccountStateTagged_descriptor_, &GameAccountStateTagged::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AuthorizedData_descriptor_, &AuthorizedData::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BenefactorAddress_descriptor_, &BenefactorAddress::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ExternalBenefactorLookup_descriptor_, &ExternalBenefactorLookup::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AuthBenefactor_descriptor_, &AuthBenefactor::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ApplicationInfo_descriptor_, &ApplicationInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DeductRecord_descriptor_, &DeductRecord::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    IgrId_descriptor_, &IgrId::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_account_5ftypes_2eproto() {
  delete AccountId::default_instance_;
  delete AccountId_reflection_;
  delete AccountLicense::default_instance_;
  delete AccountLicense_reflection_;
  delete AccountCredential::default_instance_;
  delete AccountCredential_reflection_;
  delete AccountBlob::default_instance_;
  delete AccountBlob_reflection_;
  delete AccountBlobList::default_instance_;
  delete AccountBlobList_reflection_;
  delete GameAccountHandle::default_instance_;
  delete GameAccountHandle_reflection_;
  delete GameAccountLink::default_instance_;
  delete GameAccountLink_reflection_;
  delete GameAccountBlob::default_instance_;
  delete GameAccountBlob_reflection_;
  delete GameAccountBlobList::default_instance_;
  delete GameAccountBlobList_reflection_;
  delete AccountReference::default_instance_;
  delete AccountReference_reflection_;
  delete Identity::default_instance_;
  delete Identity_reflection_;
  delete AccountInfo::default_instance_;
  delete AccountInfo_reflection_;
  delete ProgramTag::default_instance_;
  delete ProgramTag_reflection_;
  delete RegionTag::default_instance_;
  delete RegionTag_reflection_;
  delete AccountFieldTags::default_instance_;
  delete AccountFieldTags_reflection_;
  delete GameAccountFieldTags::default_instance_;
  delete GameAccountFieldTags_reflection_;
  delete AccountFieldOptions::default_instance_;
  delete AccountFieldOptions_reflection_;
  delete GameAccountFieldOptions::default_instance_;
  delete GameAccountFieldOptions_reflection_;
  delete SubscriberReference::default_instance_;
  delete SubscriberReference_reflection_;
  delete AccountLevelInfo::default_instance_;
  delete AccountLevelInfo_reflection_;
  delete PrivacyInfo::default_instance_;
  delete PrivacyInfo_reflection_;
  delete ParentalControlInfo::default_instance_;
  delete ParentalControlInfo_reflection_;
  delete GameLevelInfo::default_instance_;
  delete GameLevelInfo_reflection_;
  delete GameTimeInfo::default_instance_;
  delete GameTimeInfo_reflection_;
  delete GameTimeRemainingInfo::default_instance_;
  delete GameTimeRemainingInfo_reflection_;
  delete GameStatus::default_instance_;
  delete GameStatus_reflection_;
  delete RAFInfo::default_instance_;
  delete RAFInfo_reflection_;
  delete GameSessionInfo::default_instance_;
  delete GameSessionInfo_reflection_;
  delete GameSessionUpdateInfo::default_instance_;
  delete GameSessionUpdateInfo_reflection_;
  delete GameSessionLocation::default_instance_;
  delete GameSessionLocation_reflection_;
  delete CAIS::default_instance_;
  delete CAIS_reflection_;
  delete GameAccountList::default_instance_;
  delete GameAccountList_reflection_;
  delete AccountState::default_instance_;
  delete AccountState_reflection_;
  delete AccountStateTagged::default_instance_;
  delete AccountStateTagged_reflection_;
  delete GameAccountState::default_instance_;
  delete GameAccountState_reflection_;
  delete GameAccountStateTagged::default_instance_;
  delete GameAccountStateTagged_reflection_;
  delete AuthorizedData::default_instance_;
  delete AuthorizedData_reflection_;
  delete BenefactorAddress::default_instance_;
  delete BenefactorAddress_reflection_;
  delete ExternalBenefactorLookup::default_instance_;
  delete ExternalBenefactorLookup_reflection_;
  delete AuthBenefactor::default_instance_;
  delete AuthBenefactor_reflection_;
  delete ApplicationInfo::default_instance_;
  delete ApplicationInfo_reflection_;
  delete DeductRecord::default_instance_;
  delete DeductRecord_reflection_;
  delete IgrId::default_instance_;
  delete IgrId_default_oneof_instance_;
  delete IgrId_reflection_;
}

void protobuf_AddDesc_account_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023account_types.proto\022\027bgs.protocol.acco"
    "unt.v1\032\022entity_types.proto\032\017rpc_types.pr"
    "oto\"\027\n\tAccountId\022\n\n\002id\030\001 \002(\007\"-\n\016AccountL"
    "icense\022\n\n\002id\030\001 \002(\r\022\017\n\007expires\030\002 \001(\004\"-\n\021A"
    "ccountCredential\022\n\n\002id\030\001 \002(\r\022\014\n\004data\030\002 \001"
    "(\014\"\260\005\n\013AccountBlob\022\n\n\002id\030\002 \002(\007\022\016\n\006region"
    "\030\003 \002(\r\022\r\n\005email\030\004 \003(\t\022\r\n\005flags\030\005 \002(\004\022\026\n\016"
    "secure_release\030\006 \001(\004\022\027\n\017whitelist_start\030"
    "\007 \001(\004\022\025\n\rwhitelist_end\030\010 \001(\004\022\021\n\tfull_nam"
    "e\030\n \002(\t\0229\n\010licenses\030\024 \003(\0132\'.bgs.protocol"
    ".account.v1.AccountLicense\022\?\n\013credential"
    "s\030\025 \003(\0132*.bgs.protocol.account.v1.Accoun"
    "tCredential\022\?\n\raccount_links\030\026 \003(\0132(.bgs"
    ".protocol.account.v1.GameAccountLink\022\022\n\n"
    "battle_tag\030\027 \001(\t\022\030\n\020default_currency\030\031 \001"
    "(\007\022\024\n\014legal_region\030\032 \001(\r\022\024\n\014legal_locale"
    "\030\033 \001(\007\022\030\n\020cache_expiration\030\036 \002(\004\022K\n\025pare"
    "ntal_control_info\030\037 \001(\0132,.bgs.protocol.a"
    "ccount.v1.ParentalControlInfo\022\017\n\007country"
    "\030  \001(\t\022\030\n\020preferred_region\030! \001(\r\022R\n\025iden"
    "tity_check_status\030\" \001(\01623.bgs.protocol.a"
    "ccount.v1.IdentityVerificationStatus\022\017\n\007"
    "cais_id\030# \001(\t\"E\n\017AccountBlobList\0222\n\004blob"
    "\030\001 \003(\0132$.bgs.protocol.account.v1.Account"
    "Blob\"@\n\021GameAccountHandle\022\n\n\002id\030\001 \002(\007\022\017\n"
    "\007program\030\002 \002(\007\022\016\n\006region\030\003 \002(\r\"a\n\017GameAc"
    "countLink\022@\n\014game_account\030\001 \002(\0132*.bgs.pr"
    "otocol.account.v1.GameAccountHandle\022\014\n\004n"
    "ame\030\002 \002(\t\"\327\003\n\017GameAccountBlob\022@\n\014game_ac"
    "count\030\001 \002(\0132*.bgs.protocol.account.v1.Ga"
    "meAccountHandle\022\016\n\004name\030\002 \001(\t:\000\022\034\n\021realm"
    "_permissions\030\003 \001(\r:\0010\022\016\n\006status\030\004 \002(\r\022\020\n"
    "\005flags\030\005 \001(\004:\0010\022\030\n\rbilling_flags\030\006 \001(\r:\001"
    "0\022\030\n\020cache_expiration\030\007 \002(\004\022\037\n\027subscript"
    "ion_expiration\030\n \001(\004\022\027\n\017units_remaining\030"
    "\013 \001(\r\022\031\n\021status_expiration\030\014 \001(\004\022\021\n\tbox_"
    "level\030\r \001(\r\022\034\n\024box_level_expiration\030\016 \001("
    "\004\0229\n\010licenses\030\024 \003(\0132\'.bgs.protocol.accou"
    "nt.v1.AccountLicense\022\023\n\013raf_account\030\025 \001("
    "\007\022\020\n\010raf_info\030\026 \001(\014\022\026\n\016raf_expiration\030\027 "
    "\001(\004\"M\n\023GameAccountBlobList\0226\n\004blob\030\001 \003(\013"
    "2(.bgs.protocol.account.v1.GameAccountBl"
    "ob\"\220\001\n\020AccountReference\022\n\n\002id\030\001 \001(\007\022\r\n\005e"
    "mail\030\002 \001(\t\022:\n\006handle\030\003 \001(\0132*.bgs.protoco"
    "l.account.v1.GameAccountHandle\022\022\n\nbattle"
    "_tag\030\004 \001(\t\022\021\n\006region\030\n \001(\r:\0010\"\253\001\n\010Identi"
    "ty\0223\n\007account\030\001 \001(\0132\".bgs.protocol.accou"
    "nt.v1.AccountId\022@\n\014game_account\030\002 \001(\0132*."
    "bgs.protocol.account.v1.GameAccountHandl"
    "e\022(\n\007process\030\003 \001(\0132\027.bgs.protocol.Proces"
    "sId\"\306\001\n\013AccountInfo\022\033\n\014account_paid\030\001 \001("
    "\010:\005false\022\025\n\ncountry_id\030\002 \001(\007:\0010\022\022\n\nbattl"
    "e_tag\030\003 \001(\t\022\034\n\rmanual_review\030\004 \001(\010:\005fals"
    "e\0223\n\010identity\030\005 \001(\0132!.bgs.protocol.accou"
    "nt.v1.Identity\022\034\n\raccount_muted\030\006 \001(\010:\005f"
    "alse\"*\n\nProgramTag\022\017\n\007program\030\001 \001(\007\022\013\n\003t"
    "ag\030\002 \001(\007\"(\n\tRegionTag\022\016\n\006region\030\001 \001(\007\022\013\n"
    "\003tag\030\002 \001(\007\"\260\002\n\020AccountFieldTags\022\036\n\026accou"
    "nt_level_info_tag\030\002 \001(\007\022\030\n\020privacy_info_"
    "tag\030\003 \001(\007\022!\n\031parental_control_info_tag\030\004"
    " \001(\007\022A\n\024game_level_info_tags\030\007 \003(\0132#.bgs"
    ".protocol.account.v1.ProgramTag\022=\n\020game_"
    "status_tags\030\t \003(\0132#.bgs.protocol.account"
    ".v1.ProgramTag\022=\n\021game_account_tags\030\013 \003("
    "\0132\".bgs.protocol.account.v1.RegionTag\"~\n"
    "\024GameAccountFieldTags\022\033\n\023game_level_info"
    "_tag\030\002 \001(\007\022\032\n\022game_time_info_tag\030\003 \001(\007\022\027"
    "\n\017game_status_tag\030\004 \001(\007\022\024\n\014raf_info_tag\030"
    "\005 \001(\007\"\343\001\n\023AccountFieldOptions\022\022\n\nall_fie"
    "lds\030\001 \001(\010\022 \n\030field_account_level_info\030\002 "
    "\001(\010\022\032\n\022field_privacy_info\030\003 \001(\010\022#\n\033field"
    "_parental_control_info\030\004 \001(\010\022\035\n\025field_ga"
    "me_level_info\030\006 \001(\010\022\031\n\021field_game_status"
    "\030\007 \001(\010\022\033\n\023field_game_accounts\030\010 \001(\010\"\235\001\n\027"
    "GameAccountFieldOptions\022\022\n\nall_fields\030\001 "
    "\001(\010\022\035\n\025field_game_level_info\030\002 \001(\010\022\034\n\024fi"
    "eld_game_time_info\030\003 \001(\010\022\031\n\021field_game_s"
    "tatus\030\004 \001(\010\022\026\n\016field_raf_info\030\005 \001(\010\"\222\003\n\023"
    "SubscriberReference\022\024\n\tobject_id\030\001 \001(\004:\001"
    "0\022)\n\tentity_id\030\002 \001(\0132\026.bgs.protocol.Enti"
    "tyId\022E\n\017account_options\030\003 \001(\0132,.bgs.prot"
    "ocol.account.v1.AccountFieldOptions\022\?\n\014a"
    "ccount_tags\030\004 \001(\0132).bgs.protocol.account"
    ".v1.AccountFieldTags\022N\n\024game_account_opt"
    "ions\030\005 \001(\01320.bgs.protocol.account.v1.Gam"
    "eAccountFieldOptions\022H\n\021game_account_tag"
    "s\030\006 \001(\0132-.bgs.protocol.account.v1.GameAc"
    "countFieldTags\022\030\n\rsubscriber_id\030\007 \001(\004:\0010"
    "\"\334\002\n\020AccountLevelInfo\0229\n\010licenses\030\003 \003(\0132"
    "\'.bgs.protocol.account.v1.AccountLicense"
    "\022\030\n\020default_currency\030\004 \001(\007\022\017\n\007country\030\005 "
    "\001(\t\022\030\n\020preferred_region\030\006 \001(\r\022\021\n\tfull_na"
    "me\030\007 \001(\t\022\022\n\nbattle_tag\030\010 \001(\t\022\r\n\005muted\030\t "
    "\001(\010\022\025\n\rmanual_review\030\n \001(\010\022\030\n\020account_pa"
    "id_any\030\013 \001(\010\022R\n\025identity_check_status\030\014 "
    "\001(\01623.bgs.protocol.account.v1.IdentityVe"
    "rificationStatus\022\r\n\005email\030\r \001(\t\"\246\002\n\013Priv"
    "acyInfo\022\024\n\014is_using_rid\030\003 \001(\010\022+\n#is_real"
    "_id_visible_for_view_friends\030\004 \001(\010\022$\n\034is"
    "_hidden_from_friend_finder\030\005 \001(\010\022`\n\021game"
    "_info_privacy\030\006 \001(\01624.bgs.protocol.accou"
    "nt.v1.PrivacyInfo.GameInfoPrivacy:\017PRIVA"
    "CY_FRIENDS\"L\n\017GameInfoPrivacy\022\016\n\nPRIVACY"
    "_ME\020\000\022\023\n\017PRIVACY_FRIENDS\020\001\022\024\n\020PRIVACY_EV"
    "ERYONE\020\002\"\244\001\n\023ParentalControlInfo\022\020\n\010time"
    "zone\030\003 \001(\t\022\027\n\017minutes_per_day\030\004 \001(\r\022\030\n\020m"
    "inutes_per_week\030\005 \001(\r\022\031\n\021can_receive_voi"
    "ce\030\006 \001(\010\022\026\n\016can_send_voice\030\007 \001(\010\022\025\n\rplay"
    "_schedule\030\010 \003(\010\"\323\001\n\rGameLevelInfo\022\020\n\010is_"
    "trial\030\004 \001(\010\022\023\n\013is_lifetime\030\005 \001(\010\022\025\n\ris_r"
    "estricted\030\006 \001(\010\022\017\n\007is_beta\030\007 \001(\010\022\014\n\004name"
    "\030\010 \001(\t\022\017\n\007program\030\t \001(\007\0229\n\010licenses\030\n \003("
    "\0132\'.bgs.protocol.account.v1.AccountLicen"
    "se\022\031\n\021realm_permissions\030\013 \001(\r\"\205\001\n\014GameTi"
    "meInfo\022\036\n\026is_unlimited_play_time\030\003 \001(\010\022\031"
    "\n\021play_time_expires\030\005 \001(\004\022\027\n\017is_subscrip"
    "tion\030\006 \001(\010\022!\n\031is_recurring_subscription\030"
    "\007 \001(\010\"\255\001\n\025GameTimeRemainingInfo\022\031\n\021minut"
    "es_remaining\030\001 \001(\r\022(\n parental_daily_min"
    "utes_remaining\030\002 \001(\r\022)\n!parental_weekly_"
    "minutes_remaining\030\003 \001(\r\022$\n\034seconds_remai"
    "ning_until_kick\030\004 \001(\r\"\220\001\n\nGameStatus\022\024\n\014"
    "is_suspended\030\004 \001(\010\022\021\n\tis_banned\030\005 \001(\010\022\032\n"
    "\022suspension_expires\030\006 \001(\004\022\017\n\007program\030\007 \001"
    "(\007\022\021\n\tis_locked\030\010 \001(\010\022\031\n\021is_bam_unlockab"
    "le\030\t \001(\010\"\033\n\007RAFInfo\022\020\n\010raf_info\030\001 \001(\014\"\201\002"
    "\n\017GameSessionInfo\022\026\n\nstart_time\030\003 \001(\rB\002\030"
    "\001\022>\n\010location\030\004 \001(\0132,.bgs.protocol.accou"
    "nt.v1.GameSessionLocation\022\026\n\016has_benefac"
    "tor\030\005 \001(\010\022\024\n\014is_using_igr\030\006 \001(\010\022 \n\030paren"
    "tal_controls_active\030\007 \001(\010\022\026\n\016start_time_"
    "sec\030\010 \001(\004\022.\n\006igr_id\030\t \001(\0132\036.bgs.protocol"
    ".account.v1.IgrId\"D\n\025GameSessionUpdateIn"
    "fo\022+\n\004cais\030\010 \001(\0132\035.bgs.protocol.account."
    "v1.CAIS\"H\n\023GameSessionLocation\022\022\n\nip_add"
    "ress\030\001 \001(\t\022\017\n\007country\030\002 \001(\r\022\014\n\004city\030\003 \001("
    "\t\"O\n\004CAIS\022\026\n\016played_minutes\030\001 \001(\r\022\026\n\016res"
    "ted_minutes\030\002 \001(\r\022\027\n\017last_heard_time\030\003 \001"
    "(\004\"]\n\017GameAccountList\022\016\n\006region\030\003 \001(\r\022:\n"
    "\006handle\030\004 \003(\0132*.bgs.protocol.account.v1."
    "GameAccountHandle\"\232\003\n\014AccountState\022E\n\022ac"
    "count_level_info\030\001 \001(\0132).bgs.protocol.ac"
    "count.v1.AccountLevelInfo\022:\n\014privacy_inf"
    "o\030\002 \001(\0132$.bgs.protocol.account.v1.Privac"
    "yInfo\022K\n\025parental_control_info\030\003 \001(\0132,.b"
    "gs.protocol.account.v1.ParentalControlIn"
    "fo\022\?\n\017game_level_info\030\005 \003(\0132&.bgs.protoc"
    "ol.account.v1.GameLevelInfo\0228\n\013game_stat"
    "us\030\006 \003(\0132#.bgs.protocol.account.v1.GameS"
    "tatus\022\?\n\rgame_accounts\030\007 \003(\0132(.bgs.proto"
    "col.account.v1.GameAccountList\"\223\001\n\022Accou"
    "ntStateTagged\022<\n\raccount_state\030\001 \001(\0132%.b"
    "gs.protocol.account.v1.AccountState\022\?\n\014a"
    "ccount_tags\030\002 \001(\0132).bgs.protocol.account"
    ".v1.AccountFieldTags\"\200\002\n\020GameAccountStat"
    "e\022\?\n\017game_level_info\030\001 \001(\0132&.bgs.protoco"
    "l.account.v1.GameLevelInfo\022=\n\016game_time_"
    "info\030\002 \001(\0132%.bgs.protocol.account.v1.Gam"
    "eTimeInfo\0228\n\013game_status\030\003 \001(\0132#.bgs.pro"
    "tocol.account.v1.GameStatus\0222\n\010raf_info\030"
    "\004 \001(\0132 .bgs.protocol.account.v1.RAFInfo\""
    "\251\001\n\026GameAccountStateTagged\022E\n\022game_accou"
    "nt_state\030\001 \001(\0132).bgs.protocol.account.v1"
    ".GameAccountState\022H\n\021game_account_tags\030\002"
    " \001(\0132-.bgs.protocol.account.v1.GameAccou"
    "ntFieldTags\"/\n\016AuthorizedData\022\014\n\004data\030\001 "
    "\001(\t\022\017\n\007license\030\002 \003(\r\"8\n\021BenefactorAddres"
    "s\022\016\n\006region\030\001 \001(\r\022\023\n\013igr_address\030\002 \001(\t\"A"
    "\n\030ExternalBenefactorLookup\022\025\n\rbenefactor"
    "_id\030\001 \001(\007\022\016\n\006region\030\002 \001(\r\"f\n\016AuthBenefac"
    "tor\022\023\n\013igr_address\030\001 \001(\t\022\025\n\rbenefactor_i"
    "d\030\002 \001(\007\022\016\n\006active\030\003 \001(\010\022\030\n\020last_update_t"
    "ime\030\004 \001(\004\"S\n\017ApplicationInfo\022\023\n\013platform"
    "_id\030\001 \001(\007\022\016\n\006locale\030\002 \001(\007\022\033\n\023application"
    "_version\030\003 \001(\005\"\277\002\n\014DeductRecord\022@\n\014game_"
    "account\030\001 \001(\0132*.bgs.protocol.account.v1."
    "GameAccountHandle\022>\n\nbenefactor\030\002 \001(\0132*."
    "bgs.protocol.account.v1.GameAccountHandl"
    "e\022\022\n\nstart_time\030\003 \001(\004\022\020\n\010end_time\030\004 \001(\004\022"
    "\026\n\016client_address\030\005 \001(\t\022B\n\020application_i"
    "nfo\030\006 \001(\0132(.bgs.protocol.account.v1.Appl"
    "icationInfo\022\025\n\rsession_owner\030\007 \001(\t\022\024\n\014fr"
    "ee_session\030\010 \001(\010\"j\n\005IgrId\022B\n\014game_accoun"
    "t\030\001 \001(\0132*.bgs.protocol.account.v1.GameAc"
    "countHandleH\000\022\025\n\013external_id\030\002 \001(\007H\000B\006\n\004"
    "type*\216\001\n\032IdentityVerificationStatus\022\021\n\rI"
    "DENT_NO_DATA\020\000\022\021\n\rIDENT_PENDING\020\001\022\020\n\014IDE"
    "NT_FAILED\020\004\022\021\n\rIDENT_SUCCESS\020\005\022\022\n\016IDENT_"
    "SUCC_MNL\020\006\022\021\n\rIDENT_UNKNOWN\020\007B\002H\001", 7553);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "account_types.proto", &protobuf_RegisterTypes);
  AccountId::default_instance_ = new AccountId();
  AccountLicense::default_instance_ = new AccountLicense();
  AccountCredential::default_instance_ = new AccountCredential();
  AccountBlob::default_instance_ = new AccountBlob();
  AccountBlobList::default_instance_ = new AccountBlobList();
  GameAccountHandle::default_instance_ = new GameAccountHandle();
  GameAccountLink::default_instance_ = new GameAccountLink();
  GameAccountBlob::default_instance_ = new GameAccountBlob();
  GameAccountBlobList::default_instance_ = new GameAccountBlobList();
  AccountReference::default_instance_ = new AccountReference();
  Identity::default_instance_ = new Identity();
  AccountInfo::default_instance_ = new AccountInfo();
  ProgramTag::default_instance_ = new ProgramTag();
  RegionTag::default_instance_ = new RegionTag();
  AccountFieldTags::default_instance_ = new AccountFieldTags();
  GameAccountFieldTags::default_instance_ = new GameAccountFieldTags();
  AccountFieldOptions::default_instance_ = new AccountFieldOptions();
  GameAccountFieldOptions::default_instance_ = new GameAccountFieldOptions();
  SubscriberReference::default_instance_ = new SubscriberReference();
  AccountLevelInfo::default_instance_ = new AccountLevelInfo();
  PrivacyInfo::default_instance_ = new PrivacyInfo();
  ParentalControlInfo::default_instance_ = new ParentalControlInfo();
  GameLevelInfo::default_instance_ = new GameLevelInfo();
  GameTimeInfo::default_instance_ = new GameTimeInfo();
  GameTimeRemainingInfo::default_instance_ = new GameTimeRemainingInfo();
  GameStatus::default_instance_ = new GameStatus();
  RAFInfo::default_instance_ = new RAFInfo();
  GameSessionInfo::default_instance_ = new GameSessionInfo();
  GameSessionUpdateInfo::default_instance_ = new GameSessionUpdateInfo();
  GameSessionLocation::default_instance_ = new GameSessionLocation();
  CAIS::default_instance_ = new CAIS();
  GameAccountList::default_instance_ = new GameAccountList();
  AccountState::default_instance_ = new AccountState();
  AccountStateTagged::default_instance_ = new AccountStateTagged();
  GameAccountState::default_instance_ = new GameAccountState();
  GameAccountStateTagged::default_instance_ = new GameAccountStateTagged();
  AuthorizedData::default_instance_ = new AuthorizedData();
  BenefactorAddress::default_instance_ = new BenefactorAddress();
  ExternalBenefactorLookup::default_instance_ = new ExternalBenefactorLookup();
  AuthBenefactor::default_instance_ = new AuthBenefactor();
  ApplicationInfo::default_instance_ = new ApplicationInfo();
  DeductRecord::default_instance_ = new DeductRecord();
  IgrId::default_instance_ = new IgrId();
  IgrId_default_oneof_instance_ = new IgrIdOneofInstance;
  AccountId::default_instance_->InitAsDefaultInstance();
  AccountLicense::default_instance_->InitAsDefaultInstance();
  AccountCredential::default_instance_->InitAsDefaultInstance();
  AccountBlob::default_instance_->InitAsDefaultInstance();
  AccountBlobList::default_instance_->InitAsDefaultInstance();
  GameAccountHandle::default_instance_->InitAsDefaultInstance();
  GameAccountLink::default_instance_->InitAsDefaultInstance();
  GameAccountBlob::default_instance_->InitAsDefaultInstance();
  GameAccountBlobList::default_instance_->InitAsDefaultInstance();
  AccountReference::default_instance_->InitAsDefaultInstance();
  Identity::default_instance_->InitAsDefaultInstance();
  AccountInfo::default_instance_->InitAsDefaultInstance();
  ProgramTag::default_instance_->InitAsDefaultInstance();
  RegionTag::default_instance_->InitAsDefaultInstance();
  AccountFieldTags::default_instance_->InitAsDefaultInstance();
  GameAccountFieldTags::default_instance_->InitAsDefaultInstance();
  AccountFieldOptions::default_instance_->InitAsDefaultInstance();
  GameAccountFieldOptions::default_instance_->InitAsDefaultInstance();
  SubscriberReference::default_instance_->InitAsDefaultInstance();
  AccountLevelInfo::default_instance_->InitAsDefaultInstance();
  PrivacyInfo::default_instance_->InitAsDefaultInstance();
  ParentalControlInfo::default_instance_->InitAsDefaultInstance();
  GameLevelInfo::default_instance_->InitAsDefaultInstance();
  GameTimeInfo::default_instance_->InitAsDefaultInstance();
  GameTimeRemainingInfo::default_instance_->InitAsDefaultInstance();
  GameStatus::default_instance_->InitAsDefaultInstance();
  RAFInfo::default_instance_->InitAsDefaultInstance();
  GameSessionInfo::default_instance_->InitAsDefaultInstance();
  GameSessionUpdateInfo::default_instance_->InitAsDefaultInstance();
  GameSessionLocation::default_instance_->InitAsDefaultInstance();
  CAIS::default_instance_->InitAsDefaultInstance();
  GameAccountList::default_instance_->InitAsDefaultInstance();
  AccountState::default_instance_->InitAsDefaultInstance();
  AccountStateTagged::default_instance_->InitAsDefaultInstance();
  GameAccountState::default_instance_->InitAsDefaultInstance();
  GameAccountStateTagged::default_instance_->InitAsDefaultInstance();
  AuthorizedData::default_instance_->InitAsDefaultInstance();
  BenefactorAddress::default_instance_->InitAsDefaultInstance();
  ExternalBenefactorLookup::default_instance_->InitAsDefaultInstance();
  AuthBenefactor::default_instance_->InitAsDefaultInstance();
  ApplicationInfo::default_instance_->InitAsDefaultInstance();
  DeductRecord::default_instance_->InitAsDefaultInstance();
  IgrId::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_account_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_account_5ftypes_2eproto {
  StaticDescriptorInitializer_account_5ftypes_2eproto() {
    protobuf_AddDesc_account_5ftypes_2eproto();
  }
} static_descriptor_initializer_account_5ftypes_2eproto_;
const ::google::protobuf::EnumDescriptor* IdentityVerificationStatus_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IdentityVerificationStatus_descriptor_;
}
bool IdentityVerificationStatus_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int AccountId::kIdFieldNumber;
#endif  // !_MSC_VER

AccountId::AccountId()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountId)
}

void AccountId::InitAsDefaultInstance() {
}

AccountId::AccountId(const AccountId& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountId)
}

void AccountId::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountId::~AccountId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountId)
  SharedDtor();
}

void AccountId::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountId::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountId::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountId_descriptor_;
}

const AccountId& AccountId::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountId* AccountId::default_instance_ = NULL;

AccountId* AccountId::New() const {
  return new AccountId;
}

void AccountId::Clear() {
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountId::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountId)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 id = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountId)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountId)
  return false;
#undef DO_
}

void AccountId::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountId)
  // required fixed32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountId)
}

::google::protobuf::uint8* AccountId::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountId)
  // required fixed32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountId)
  return target;
}

int AccountId::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 id = 1;
    if (has_id()) {
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

void AccountId::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountId* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountId*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountId::MergeFrom(const AccountId& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountId::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountId::CopyFrom(const AccountId& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountId::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void AccountId::Swap(AccountId* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountId::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountId_descriptor_;
  metadata.reflection = AccountId_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountLicense::kIdFieldNumber;
const int AccountLicense::kExpiresFieldNumber;
#endif  // !_MSC_VER

AccountLicense::AccountLicense()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountLicense)
}

void AccountLicense::InitAsDefaultInstance() {
}

AccountLicense::AccountLicense(const AccountLicense& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountLicense)
}

void AccountLicense::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  expires_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountLicense::~AccountLicense() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountLicense)
  SharedDtor();
}

void AccountLicense::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountLicense::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountLicense::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountLicense_descriptor_;
}

const AccountLicense& AccountLicense::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountLicense* AccountLicense::default_instance_ = NULL;

AccountLicense* AccountLicense::New() const {
  return new AccountLicense;
}

void AccountLicense::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountLicense*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(expires_, id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountLicense::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountLicense)
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
        if (input->ExpectTag(16)) goto parse_expires;
        break;
      }

      // optional uint64 expires = 2;
      case 2: {
        if (tag == 16) {
         parse_expires:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &expires_)));
          set_has_expires();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountLicense)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountLicense)
  return false;
#undef DO_
}

void AccountLicense::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountLicense)
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // optional uint64 expires = 2;
  if (has_expires()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->expires(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountLicense)
}

::google::protobuf::uint8* AccountLicense::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountLicense)
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // optional uint64 expires = 2;
  if (has_expires()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->expires(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountLicense)
  return target;
}

int AccountLicense::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional uint64 expires = 2;
    if (has_expires()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->expires());
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

void AccountLicense::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountLicense* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountLicense*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountLicense::MergeFrom(const AccountLicense& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_expires()) {
      set_expires(from.expires());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountLicense::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountLicense::CopyFrom(const AccountLicense& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountLicense::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void AccountLicense::Swap(AccountLicense* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(expires_, other->expires_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountLicense::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountLicense_descriptor_;
  metadata.reflection = AccountLicense_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountCredential::kIdFieldNumber;
const int AccountCredential::kDataFieldNumber;
#endif  // !_MSC_VER

AccountCredential::AccountCredential()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountCredential)
}

void AccountCredential::InitAsDefaultInstance() {
}

AccountCredential::AccountCredential(const AccountCredential& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountCredential)
}

void AccountCredential::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountCredential::~AccountCredential() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountCredential)
  SharedDtor();
}

void AccountCredential::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void AccountCredential::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountCredential::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountCredential_descriptor_;
}

const AccountCredential& AccountCredential::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountCredential* AccountCredential::default_instance_ = NULL;

AccountCredential* AccountCredential::New() const {
  return new AccountCredential;
}

void AccountCredential::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    id_ = 0u;
    if (has_data()) {
      if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        data_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountCredential::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountCredential)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountCredential)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountCredential)
  return false;
#undef DO_
}

void AccountCredential::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountCredential)
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // optional bytes data = 2;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountCredential)
}

::google::protobuf::uint8* AccountCredential::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountCredential)
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // optional bytes data = 2;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountCredential)
  return target;
}

int AccountCredential::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional bytes data = 2;
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

void AccountCredential::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountCredential* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountCredential*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountCredential::MergeFrom(const AccountCredential& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountCredential::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountCredential::CopyFrom(const AccountCredential& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountCredential::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void AccountCredential::Swap(AccountCredential* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountCredential::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountCredential_descriptor_;
  metadata.reflection = AccountCredential_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountBlob::kIdFieldNumber;
const int AccountBlob::kRegionFieldNumber;
const int AccountBlob::kEmailFieldNumber;
const int AccountBlob::kFlagsFieldNumber;
const int AccountBlob::kSecureReleaseFieldNumber;
const int AccountBlob::kWhitelistStartFieldNumber;
const int AccountBlob::kWhitelistEndFieldNumber;
const int AccountBlob::kFullNameFieldNumber;
const int AccountBlob::kLicensesFieldNumber;
const int AccountBlob::kCredentialsFieldNumber;
const int AccountBlob::kAccountLinksFieldNumber;
const int AccountBlob::kBattleTagFieldNumber;
const int AccountBlob::kDefaultCurrencyFieldNumber;
const int AccountBlob::kLegalRegionFieldNumber;
const int AccountBlob::kLegalLocaleFieldNumber;
const int AccountBlob::kCacheExpirationFieldNumber;
const int AccountBlob::kParentalControlInfoFieldNumber;
const int AccountBlob::kCountryFieldNumber;
const int AccountBlob::kPreferredRegionFieldNumber;
const int AccountBlob::kIdentityCheckStatusFieldNumber;
const int AccountBlob::kCaisIdFieldNumber;
#endif  // !_MSC_VER

AccountBlob::AccountBlob()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountBlob)
}

void AccountBlob::InitAsDefaultInstance() {
  parental_control_info_ = const_cast< ::bgs::protocol::account::v1::ParentalControlInfo*>(&::bgs::protocol::account::v1::ParentalControlInfo::default_instance());
}

AccountBlob::AccountBlob(const AccountBlob& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountBlob)
}

void AccountBlob::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  region_ = 0u;
  flags_ = GOOGLE_ULONGLONG(0);
  secure_release_ = GOOGLE_ULONGLONG(0);
  whitelist_start_ = GOOGLE_ULONGLONG(0);
  whitelist_end_ = GOOGLE_ULONGLONG(0);
  full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  default_currency_ = 0u;
  legal_region_ = 0u;
  legal_locale_ = 0u;
  cache_expiration_ = GOOGLE_ULONGLONG(0);
  parental_control_info_ = NULL;
  country_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  preferred_region_ = 0u;
  identity_check_status_ = 0;
  cais_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountBlob::~AccountBlob() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountBlob)
  SharedDtor();
}

void AccountBlob::SharedDtor() {
  if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete full_name_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete country_;
  }
  if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete cais_id_;
  }
  if (this != default_instance_) {
    delete parental_control_info_;
  }
}

void AccountBlob::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountBlob::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountBlob_descriptor_;
}

const AccountBlob& AccountBlob::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountBlob* AccountBlob::default_instance_ = NULL;

AccountBlob* AccountBlob::New() const {
  return new AccountBlob;
}

void AccountBlob::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountBlob*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 251) {
    ZR_(id_, region_);
    ZR_(flags_, whitelist_end_);
    if (has_full_name()) {
      if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        full_name_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 63488) {
    ZR_(default_currency_, cache_expiration_);
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    legal_locale_ = 0u;
  }
  if (_has_bits_[16 / 32] & 2031616) {
    if (has_parental_control_info()) {
      if (parental_control_info_ != NULL) parental_control_info_->::bgs::protocol::account::v1::ParentalControlInfo::Clear();
    }
    if (has_country()) {
      if (country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        country_->clear();
      }
    }
    preferred_region_ = 0u;
    identity_check_status_ = 0;
    if (has_cais_id()) {
      if (cais_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        cais_id_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  email_.Clear();
  licenses_.Clear();
  credentials_.Clear();
  account_links_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountBlob::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountBlob)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 id = 2;
      case 2: {
        if (tag == 21) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_region;
        break;
      }

      // required uint32 region = 3;
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
        if (input->ExpectTag(34)) goto parse_email;
        break;
      }

      // repeated string email = 4;
      case 4: {
        if (tag == 34) {
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
        if (input->ExpectTag(34)) goto parse_email;
        if (input->ExpectTag(40)) goto parse_flags;
        break;
      }

      // required uint64 flags = 5;
      case 5: {
        if (tag == 40) {
         parse_flags:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &flags_)));
          set_has_flags();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_secure_release;
        break;
      }

      // optional uint64 secure_release = 6;
      case 6: {
        if (tag == 48) {
         parse_secure_release:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &secure_release_)));
          set_has_secure_release();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_whitelist_start;
        break;
      }

      // optional uint64 whitelist_start = 7;
      case 7: {
        if (tag == 56) {
         parse_whitelist_start:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &whitelist_start_)));
          set_has_whitelist_start();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_whitelist_end;
        break;
      }

      // optional uint64 whitelist_end = 8;
      case 8: {
        if (tag == 64) {
         parse_whitelist_end:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &whitelist_end_)));
          set_has_whitelist_end();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_full_name;
        break;
      }

      // required string full_name = 10;
      case 10: {
        if (tag == 82) {
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
        if (input->ExpectTag(162)) goto parse_licenses;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
      case 20: {
        if (tag == 162) {
         parse_licenses:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_licenses()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(162)) goto parse_licenses;
        if (input->ExpectTag(170)) goto parse_credentials;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountCredential credentials = 21;
      case 21: {
        if (tag == 170) {
         parse_credentials:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_credentials()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(170)) goto parse_credentials;
        if (input->ExpectTag(178)) goto parse_account_links;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameAccountLink account_links = 22;
      case 22: {
        if (tag == 178) {
         parse_account_links:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_account_links()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(178)) goto parse_account_links;
        if (input->ExpectTag(186)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 23;
      case 23: {
        if (tag == 186) {
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
        if (input->ExpectTag(205)) goto parse_default_currency;
        break;
      }

      // optional fixed32 default_currency = 25;
      case 25: {
        if (tag == 205) {
         parse_default_currency:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &default_currency_)));
          set_has_default_currency();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(208)) goto parse_legal_region;
        break;
      }

      // optional uint32 legal_region = 26;
      case 26: {
        if (tag == 208) {
         parse_legal_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &legal_region_)));
          set_has_legal_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(221)) goto parse_legal_locale;
        break;
      }

      // optional fixed32 legal_locale = 27;
      case 27: {
        if (tag == 221) {
         parse_legal_locale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &legal_locale_)));
          set_has_legal_locale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(240)) goto parse_cache_expiration;
        break;
      }

      // required uint64 cache_expiration = 30;
      case 30: {
        if (tag == 240) {
         parse_cache_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &cache_expiration_)));
          set_has_cache_expiration();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(250)) goto parse_parental_control_info;
        break;
      }

      // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 31;
      case 31: {
        if (tag == 250) {
         parse_parental_control_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_parental_control_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(258)) goto parse_country;
        break;
      }

      // optional string country = 32;
      case 32: {
        if (tag == 258) {
         parse_country:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_country()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->country().data(), this->country().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "country");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(264)) goto parse_preferred_region;
        break;
      }

      // optional uint32 preferred_region = 33;
      case 33: {
        if (tag == 264) {
         parse_preferred_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &preferred_region_)));
          set_has_preferred_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(272)) goto parse_identity_check_status;
        break;
      }

      // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 34;
      case 34: {
        if (tag == 272) {
         parse_identity_check_status:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::account::v1::IdentityVerificationStatus_IsValid(value)) {
            set_identity_check_status(static_cast< ::bgs::protocol::account::v1::IdentityVerificationStatus >(value));
          } else {
            mutable_unknown_fields()->AddVarint(34, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(282)) goto parse_cais_id;
        break;
      }

      // optional string cais_id = 35;
      case 35: {
        if (tag == 282) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountBlob)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountBlob)
  return false;
#undef DO_
}

void AccountBlob::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountBlob)
  // required fixed32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->id(), output);
  }

  // required uint32 region = 3;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->region(), output);
  }

  // repeated string email = 4;
  for (int i = 0; i < this->email_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->email(i).data(), this->email(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "email");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->email(i), output);
  }

  // required uint64 flags = 5;
  if (has_flags()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->flags(), output);
  }

  // optional uint64 secure_release = 6;
  if (has_secure_release()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(6, this->secure_release(), output);
  }

  // optional uint64 whitelist_start = 7;
  if (has_whitelist_start()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(7, this->whitelist_start(), output);
  }

  // optional uint64 whitelist_end = 8;
  if (has_whitelist_end()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(8, this->whitelist_end(), output);
  }

  // required string full_name = 10;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      10, this->full_name(), output);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      20, this->licenses(i), output);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential credentials = 21;
  for (int i = 0; i < this->credentials_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      21, this->credentials(i), output);
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink account_links = 22;
  for (int i = 0; i < this->account_links_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      22, this->account_links(i), output);
  }

  // optional string battle_tag = 23;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      23, this->battle_tag(), output);
  }

  // optional fixed32 default_currency = 25;
  if (has_default_currency()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(25, this->default_currency(), output);
  }

  // optional uint32 legal_region = 26;
  if (has_legal_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(26, this->legal_region(), output);
  }

  // optional fixed32 legal_locale = 27;
  if (has_legal_locale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(27, this->legal_locale(), output);
  }

  // required uint64 cache_expiration = 30;
  if (has_cache_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(30, this->cache_expiration(), output);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 31;
  if (has_parental_control_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      31, this->parental_control_info(), output);
  }

  // optional string country = 32;
  if (has_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->country().data(), this->country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "country");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      32, this->country(), output);
  }

  // optional uint32 preferred_region = 33;
  if (has_preferred_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(33, this->preferred_region(), output);
  }

  // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 34;
  if (has_identity_check_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      34, this->identity_check_status(), output);
  }

  // optional string cais_id = 35;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      35, this->cais_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountBlob)
}

::google::protobuf::uint8* AccountBlob::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountBlob)
  // required fixed32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->id(), target);
  }

  // required uint32 region = 3;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->region(), target);
  }

  // repeated string email = 4;
  for (int i = 0; i < this->email_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email(i).data(), this->email(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->email(i), target);
  }

  // required uint64 flags = 5;
  if (has_flags()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->flags(), target);
  }

  // optional uint64 secure_release = 6;
  if (has_secure_release()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(6, this->secure_release(), target);
  }

  // optional uint64 whitelist_start = 7;
  if (has_whitelist_start()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(7, this->whitelist_start(), target);
  }

  // optional uint64 whitelist_end = 8;
  if (has_whitelist_end()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(8, this->whitelist_end(), target);
  }

  // required string full_name = 10;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->full_name(), target);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        20, this->licenses(i), target);
  }

  // repeated .bgs.protocol.account.v1.AccountCredential credentials = 21;
  for (int i = 0; i < this->credentials_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        21, this->credentials(i), target);
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink account_links = 22;
  for (int i = 0; i < this->account_links_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        22, this->account_links(i), target);
  }

  // optional string battle_tag = 23;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        23, this->battle_tag(), target);
  }

  // optional fixed32 default_currency = 25;
  if (has_default_currency()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(25, this->default_currency(), target);
  }

  // optional uint32 legal_region = 26;
  if (has_legal_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(26, this->legal_region(), target);
  }

  // optional fixed32 legal_locale = 27;
  if (has_legal_locale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(27, this->legal_locale(), target);
  }

  // required uint64 cache_expiration = 30;
  if (has_cache_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(30, this->cache_expiration(), target);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 31;
  if (has_parental_control_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        31, this->parental_control_info(), target);
  }

  // optional string country = 32;
  if (has_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->country().data(), this->country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "country");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        32, this->country(), target);
  }

  // optional uint32 preferred_region = 33;
  if (has_preferred_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(33, this->preferred_region(), target);
  }

  // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 34;
  if (has_identity_check_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      34, this->identity_check_status(), target);
  }

  // optional string cais_id = 35;
  if (has_cais_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cais_id().data(), this->cais_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "cais_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        35, this->cais_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountBlob)
  return target;
}

int AccountBlob::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 id = 2;
    if (has_id()) {
      total_size += 1 + 4;
    }

    // required uint32 region = 3;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

    // required uint64 flags = 5;
    if (has_flags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->flags());
    }

    // optional uint64 secure_release = 6;
    if (has_secure_release()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->secure_release());
    }

    // optional uint64 whitelist_start = 7;
    if (has_whitelist_start()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->whitelist_start());
    }

    // optional uint64 whitelist_end = 8;
    if (has_whitelist_end()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->whitelist_end());
    }

    // required string full_name = 10;
    if (has_full_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->full_name());
    }

  }
  if (_has_bits_[11 / 32] & (0xffu << (11 % 32))) {
    // optional string battle_tag = 23;
    if (has_battle_tag()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional fixed32 default_currency = 25;
    if (has_default_currency()) {
      total_size += 2 + 4;
    }

    // optional uint32 legal_region = 26;
    if (has_legal_region()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->legal_region());
    }

    // optional fixed32 legal_locale = 27;
    if (has_legal_locale()) {
      total_size += 2 + 4;
    }

    // required uint64 cache_expiration = 30;
    if (has_cache_expiration()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->cache_expiration());
    }

  }
  if (_has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 31;
    if (has_parental_control_info()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->parental_control_info());
    }

    // optional string country = 32;
    if (has_country()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->country());
    }

    // optional uint32 preferred_region = 33;
    if (has_preferred_region()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->preferred_region());
    }

    // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 34;
    if (has_identity_check_status()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->identity_check_status());
    }

    // optional string cais_id = 35;
    if (has_cais_id()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->cais_id());
    }

  }
  // repeated string email = 4;
  total_size += 1 * this->email_size();
  for (int i = 0; i < this->email_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->email(i));
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  total_size += 2 * this->licenses_size();
  for (int i = 0; i < this->licenses_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->licenses(i));
  }

  // repeated .bgs.protocol.account.v1.AccountCredential credentials = 21;
  total_size += 2 * this->credentials_size();
  for (int i = 0; i < this->credentials_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->credentials(i));
  }

  // repeated .bgs.protocol.account.v1.GameAccountLink account_links = 22;
  total_size += 2 * this->account_links_size();
  for (int i = 0; i < this->account_links_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->account_links(i));
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

void AccountBlob::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountBlob* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountBlob*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountBlob::MergeFrom(const AccountBlob& from) {
  GOOGLE_CHECK_NE(&from, this);
  email_.MergeFrom(from.email_);
  licenses_.MergeFrom(from.licenses_);
  credentials_.MergeFrom(from.credentials_);
  account_links_.MergeFrom(from.account_links_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_flags()) {
      set_flags(from.flags());
    }
    if (from.has_secure_release()) {
      set_secure_release(from.secure_release());
    }
    if (from.has_whitelist_start()) {
      set_whitelist_start(from.whitelist_start());
    }
    if (from.has_whitelist_end()) {
      set_whitelist_end(from.whitelist_end());
    }
    if (from.has_full_name()) {
      set_full_name(from.full_name());
    }
  }
  if (from._has_bits_[11 / 32] & (0xffu << (11 % 32))) {
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_default_currency()) {
      set_default_currency(from.default_currency());
    }
    if (from.has_legal_region()) {
      set_legal_region(from.legal_region());
    }
    if (from.has_legal_locale()) {
      set_legal_locale(from.legal_locale());
    }
    if (from.has_cache_expiration()) {
      set_cache_expiration(from.cache_expiration());
    }
  }
  if (from._has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    if (from.has_parental_control_info()) {
      mutable_parental_control_info()->::bgs::protocol::account::v1::ParentalControlInfo::MergeFrom(from.parental_control_info());
    }
    if (from.has_country()) {
      set_country(from.country());
    }
    if (from.has_preferred_region()) {
      set_preferred_region(from.preferred_region());
    }
    if (from.has_identity_check_status()) {
      set_identity_check_status(from.identity_check_status());
    }
    if (from.has_cais_id()) {
      set_cais_id(from.cais_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountBlob::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountBlob::CopyFrom(const AccountBlob& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountBlob::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000808b) != 0x0000808b) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->credentials())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->account_links())) return false;
  return true;
}

void AccountBlob::Swap(AccountBlob* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(region_, other->region_);
    email_.Swap(&other->email_);
    std::swap(flags_, other->flags_);
    std::swap(secure_release_, other->secure_release_);
    std::swap(whitelist_start_, other->whitelist_start_);
    std::swap(whitelist_end_, other->whitelist_end_);
    std::swap(full_name_, other->full_name_);
    licenses_.Swap(&other->licenses_);
    credentials_.Swap(&other->credentials_);
    account_links_.Swap(&other->account_links_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(default_currency_, other->default_currency_);
    std::swap(legal_region_, other->legal_region_);
    std::swap(legal_locale_, other->legal_locale_);
    std::swap(cache_expiration_, other->cache_expiration_);
    std::swap(parental_control_info_, other->parental_control_info_);
    std::swap(country_, other->country_);
    std::swap(preferred_region_, other->preferred_region_);
    std::swap(identity_check_status_, other->identity_check_status_);
    std::swap(cais_id_, other->cais_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountBlob::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountBlob_descriptor_;
  metadata.reflection = AccountBlob_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountBlobList::kBlobFieldNumber;
#endif  // !_MSC_VER

AccountBlobList::AccountBlobList()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountBlobList)
}

void AccountBlobList::InitAsDefaultInstance() {
}

AccountBlobList::AccountBlobList(const AccountBlobList& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountBlobList)
}

void AccountBlobList::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountBlobList::~AccountBlobList() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountBlobList)
  SharedDtor();
}

void AccountBlobList::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountBlobList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountBlobList::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountBlobList_descriptor_;
}

const AccountBlobList& AccountBlobList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountBlobList* AccountBlobList::default_instance_ = NULL;

AccountBlobList* AccountBlobList::New() const {
  return new AccountBlobList;
}

void AccountBlobList::Clear() {
  blob_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountBlobList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountBlobList)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AccountBlob blob = 1;
      case 1: {
        if (tag == 10) {
         parse_blob:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_blob()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_blob;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountBlobList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountBlobList)
  return false;
#undef DO_
}

void AccountBlobList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountBlobList)
  // repeated .bgs.protocol.account.v1.AccountBlob blob = 1;
  for (int i = 0; i < this->blob_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->blob(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountBlobList)
}

::google::protobuf::uint8* AccountBlobList::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountBlobList)
  // repeated .bgs.protocol.account.v1.AccountBlob blob = 1;
  for (int i = 0; i < this->blob_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->blob(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountBlobList)
  return target;
}

int AccountBlobList::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.AccountBlob blob = 1;
  total_size += 1 * this->blob_size();
  for (int i = 0; i < this->blob_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->blob(i));
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

void AccountBlobList::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountBlobList* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountBlobList*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountBlobList::MergeFrom(const AccountBlobList& from) {
  GOOGLE_CHECK_NE(&from, this);
  blob_.MergeFrom(from.blob_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountBlobList::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountBlobList::CopyFrom(const AccountBlobList& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountBlobList::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->blob())) return false;
  return true;
}

void AccountBlobList::Swap(AccountBlobList* other) {
  if (other != this) {
    blob_.Swap(&other->blob_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountBlobList::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountBlobList_descriptor_;
  metadata.reflection = AccountBlobList_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountHandle::kIdFieldNumber;
const int GameAccountHandle::kProgramFieldNumber;
const int GameAccountHandle::kRegionFieldNumber;
#endif  // !_MSC_VER

GameAccountHandle::GameAccountHandle()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountHandle)
}

void GameAccountHandle::InitAsDefaultInstance() {
}

GameAccountHandle::GameAccountHandle(const GameAccountHandle& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountHandle)
}

void GameAccountHandle::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  program_ = 0u;
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountHandle::~GameAccountHandle() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountHandle)
  SharedDtor();
}

void GameAccountHandle::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameAccountHandle::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountHandle::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountHandle_descriptor_;
}

const GameAccountHandle& GameAccountHandle::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountHandle* GameAccountHandle::default_instance_ = NULL;

GameAccountHandle* GameAccountHandle::New() const {
  return new GameAccountHandle;
}

void GameAccountHandle::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameAccountHandle*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(id_, region_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountHandle::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountHandle)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 id = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_program;
        break;
      }

      // required fixed32 program = 2;
      case 2: {
        if (tag == 21) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_region;
        break;
      }

      // required uint32 region = 3;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountHandle)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountHandle)
  return false;
#undef DO_
}

void GameAccountHandle::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountHandle)
  // required fixed32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->id(), output);
  }

  // required fixed32 program = 2;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->program(), output);
  }

  // required uint32 region = 3;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountHandle)
}

::google::protobuf::uint8* GameAccountHandle::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountHandle)
  // required fixed32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->id(), target);
  }

  // required fixed32 program = 2;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->program(), target);
  }

  // required uint32 region = 3;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountHandle)
  return target;
}

int GameAccountHandle::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 id = 1;
    if (has_id()) {
      total_size += 1 + 4;
    }

    // required fixed32 program = 2;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // required uint32 region = 3;
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

void GameAccountHandle::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountHandle* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountHandle*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountHandle::MergeFrom(const GameAccountHandle& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountHandle::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountHandle::CopyFrom(const GameAccountHandle& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountHandle::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void GameAccountHandle::Swap(GameAccountHandle* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(program_, other->program_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountHandle::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountHandle_descriptor_;
  metadata.reflection = GameAccountHandle_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountLink::kGameAccountFieldNumber;
const int GameAccountLink::kNameFieldNumber;
#endif  // !_MSC_VER

GameAccountLink::GameAccountLink()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountLink)
}

void GameAccountLink::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

GameAccountLink::GameAccountLink(const GameAccountLink& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountLink)
}

void GameAccountLink::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  game_account_ = NULL;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountLink::~GameAccountLink() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountLink)
  SharedDtor();
}

void GameAccountLink::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
    delete game_account_;
  }
}

void GameAccountLink::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountLink::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountLink_descriptor_;
}

const GameAccountLink& GameAccountLink::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountLink* GameAccountLink::default_instance_ = NULL;

GameAccountLink* GameAccountLink::New() const {
  return new GameAccountLink;
}

void GameAccountLink::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountLink::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountLink)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountLink)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountLink)
  return false;
#undef DO_
}

void GameAccountLink::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountLink)
  // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
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

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountLink)
}

::google::protobuf::uint8* GameAccountLink::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountLink)
  // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
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

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountLink)
  return target;
}

int GameAccountLink::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
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

void GameAccountLink::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountLink* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountLink*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountLink::MergeFrom(const GameAccountLink& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountLink::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountLink::CopyFrom(const GameAccountLink& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountLink::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void GameAccountLink::Swap(GameAccountLink* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(name_, other->name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountLink::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountLink_descriptor_;
  metadata.reflection = GameAccountLink_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountBlob::kGameAccountFieldNumber;
const int GameAccountBlob::kNameFieldNumber;
const int GameAccountBlob::kRealmPermissionsFieldNumber;
const int GameAccountBlob::kStatusFieldNumber;
const int GameAccountBlob::kFlagsFieldNumber;
const int GameAccountBlob::kBillingFlagsFieldNumber;
const int GameAccountBlob::kCacheExpirationFieldNumber;
const int GameAccountBlob::kSubscriptionExpirationFieldNumber;
const int GameAccountBlob::kUnitsRemainingFieldNumber;
const int GameAccountBlob::kStatusExpirationFieldNumber;
const int GameAccountBlob::kBoxLevelFieldNumber;
const int GameAccountBlob::kBoxLevelExpirationFieldNumber;
const int GameAccountBlob::kLicensesFieldNumber;
const int GameAccountBlob::kRafAccountFieldNumber;
const int GameAccountBlob::kRafInfoFieldNumber;
const int GameAccountBlob::kRafExpirationFieldNumber;
#endif  // !_MSC_VER

GameAccountBlob::GameAccountBlob()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountBlob)
}

void GameAccountBlob::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

GameAccountBlob::GameAccountBlob(const GameAccountBlob& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountBlob)
}

void GameAccountBlob::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  game_account_ = NULL;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  realm_permissions_ = 0u;
  status_ = 0u;
  flags_ = GOOGLE_ULONGLONG(0);
  billing_flags_ = 0u;
  cache_expiration_ = GOOGLE_ULONGLONG(0);
  subscription_expiration_ = GOOGLE_ULONGLONG(0);
  units_remaining_ = 0u;
  status_expiration_ = GOOGLE_ULONGLONG(0);
  box_level_ = 0u;
  box_level_expiration_ = GOOGLE_ULONGLONG(0);
  raf_account_ = 0u;
  raf_info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  raf_expiration_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountBlob::~GameAccountBlob() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountBlob)
  SharedDtor();
}

void GameAccountBlob::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (raf_info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete raf_info_;
  }
  if (this != default_instance_) {
    delete game_account_;
  }
}

void GameAccountBlob::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountBlob::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountBlob_descriptor_;
}

const GameAccountBlob& GameAccountBlob::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountBlob* GameAccountBlob::default_instance_ = NULL;

GameAccountBlob* GameAccountBlob::New() const {
  return new GameAccountBlob;
}

void GameAccountBlob::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameAccountBlob*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(realm_permissions_, billing_flags_);
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    subscription_expiration_ = GOOGLE_ULONGLONG(0);
  }
  if (_has_bits_[8 / 32] & 61184) {
    ZR_(status_expiration_, raf_account_);
    units_remaining_ = 0u;
    if (has_raf_info()) {
      if (raf_info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        raf_info_->clear();
      }
    }
    raf_expiration_ = GOOGLE_ULONGLONG(0);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  licenses_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountBlob::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountBlob)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // optional string name = 2 [default = ""];
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
        if (input->ExpectTag(24)) goto parse_realm_permissions;
        break;
      }

      // optional uint32 realm_permissions = 3 [default = 0];
      case 3: {
        if (tag == 24) {
         parse_realm_permissions:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &realm_permissions_)));
          set_has_realm_permissions();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_status;
        break;
      }

      // required uint32 status = 4;
      case 4: {
        if (tag == 32) {
         parse_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_flags;
        break;
      }

      // optional uint64 flags = 5 [default = 0];
      case 5: {
        if (tag == 40) {
         parse_flags:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &flags_)));
          set_has_flags();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_billing_flags;
        break;
      }

      // optional uint32 billing_flags = 6 [default = 0];
      case 6: {
        if (tag == 48) {
         parse_billing_flags:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &billing_flags_)));
          set_has_billing_flags();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_cache_expiration;
        break;
      }

      // required uint64 cache_expiration = 7;
      case 7: {
        if (tag == 56) {
         parse_cache_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &cache_expiration_)));
          set_has_cache_expiration();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_subscription_expiration;
        break;
      }

      // optional uint64 subscription_expiration = 10;
      case 10: {
        if (tag == 80) {
         parse_subscription_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &subscription_expiration_)));
          set_has_subscription_expiration();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_units_remaining;
        break;
      }

      // optional uint32 units_remaining = 11;
      case 11: {
        if (tag == 88) {
         parse_units_remaining:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &units_remaining_)));
          set_has_units_remaining();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_status_expiration;
        break;
      }

      // optional uint64 status_expiration = 12;
      case 12: {
        if (tag == 96) {
         parse_status_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &status_expiration_)));
          set_has_status_expiration();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(104)) goto parse_box_level;
        break;
      }

      // optional uint32 box_level = 13;
      case 13: {
        if (tag == 104) {
         parse_box_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &box_level_)));
          set_has_box_level();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(112)) goto parse_box_level_expiration;
        break;
      }

      // optional uint64 box_level_expiration = 14;
      case 14: {
        if (tag == 112) {
         parse_box_level_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &box_level_expiration_)));
          set_has_box_level_expiration();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(162)) goto parse_licenses;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
      case 20: {
        if (tag == 162) {
         parse_licenses:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_licenses()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(162)) goto parse_licenses;
        if (input->ExpectTag(173)) goto parse_raf_account;
        break;
      }

      // optional fixed32 raf_account = 21;
      case 21: {
        if (tag == 173) {
         parse_raf_account:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &raf_account_)));
          set_has_raf_account();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(178)) goto parse_raf_info;
        break;
      }

      // optional bytes raf_info = 22;
      case 22: {
        if (tag == 178) {
         parse_raf_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_raf_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(184)) goto parse_raf_expiration;
        break;
      }

      // optional uint64 raf_expiration = 23;
      case 23: {
        if (tag == 184) {
         parse_raf_expiration:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &raf_expiration_)));
          set_has_raf_expiration();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountBlob)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountBlob)
  return false;
#undef DO_
}

void GameAccountBlob::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountBlob)
  // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional string name = 2 [default = ""];
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional uint32 realm_permissions = 3 [default = 0];
  if (has_realm_permissions()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->realm_permissions(), output);
  }

  // required uint32 status = 4;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->status(), output);
  }

  // optional uint64 flags = 5 [default = 0];
  if (has_flags()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->flags(), output);
  }

  // optional uint32 billing_flags = 6 [default = 0];
  if (has_billing_flags()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->billing_flags(), output);
  }

  // required uint64 cache_expiration = 7;
  if (has_cache_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(7, this->cache_expiration(), output);
  }

  // optional uint64 subscription_expiration = 10;
  if (has_subscription_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(10, this->subscription_expiration(), output);
  }

  // optional uint32 units_remaining = 11;
  if (has_units_remaining()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->units_remaining(), output);
  }

  // optional uint64 status_expiration = 12;
  if (has_status_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(12, this->status_expiration(), output);
  }

  // optional uint32 box_level = 13;
  if (has_box_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(13, this->box_level(), output);
  }

  // optional uint64 box_level_expiration = 14;
  if (has_box_level_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(14, this->box_level_expiration(), output);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      20, this->licenses(i), output);
  }

  // optional fixed32 raf_account = 21;
  if (has_raf_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(21, this->raf_account(), output);
  }

  // optional bytes raf_info = 22;
  if (has_raf_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      22, this->raf_info(), output);
  }

  // optional uint64 raf_expiration = 23;
  if (has_raf_expiration()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(23, this->raf_expiration(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountBlob)
}

::google::protobuf::uint8* GameAccountBlob::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountBlob)
  // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional string name = 2 [default = ""];
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional uint32 realm_permissions = 3 [default = 0];
  if (has_realm_permissions()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->realm_permissions(), target);
  }

  // required uint32 status = 4;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->status(), target);
  }

  // optional uint64 flags = 5 [default = 0];
  if (has_flags()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->flags(), target);
  }

  // optional uint32 billing_flags = 6 [default = 0];
  if (has_billing_flags()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->billing_flags(), target);
  }

  // required uint64 cache_expiration = 7;
  if (has_cache_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(7, this->cache_expiration(), target);
  }

  // optional uint64 subscription_expiration = 10;
  if (has_subscription_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(10, this->subscription_expiration(), target);
  }

  // optional uint32 units_remaining = 11;
  if (has_units_remaining()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->units_remaining(), target);
  }

  // optional uint64 status_expiration = 12;
  if (has_status_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(12, this->status_expiration(), target);
  }

  // optional uint32 box_level = 13;
  if (has_box_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(13, this->box_level(), target);
  }

  // optional uint64 box_level_expiration = 14;
  if (has_box_level_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(14, this->box_level_expiration(), target);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        20, this->licenses(i), target);
  }

  // optional fixed32 raf_account = 21;
  if (has_raf_account()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(21, this->raf_account(), target);
  }

  // optional bytes raf_info = 22;
  if (has_raf_info()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        22, this->raf_info(), target);
  }

  // optional uint64 raf_expiration = 23;
  if (has_raf_expiration()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(23, this->raf_expiration(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountBlob)
  return target;
}

int GameAccountBlob::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional string name = 2 [default = ""];
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional uint32 realm_permissions = 3 [default = 0];
    if (has_realm_permissions()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->realm_permissions());
    }

    // required uint32 status = 4;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->status());
    }

    // optional uint64 flags = 5 [default = 0];
    if (has_flags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->flags());
    }

    // optional uint32 billing_flags = 6 [default = 0];
    if (has_billing_flags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->billing_flags());
    }

    // required uint64 cache_expiration = 7;
    if (has_cache_expiration()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->cache_expiration());
    }

    // optional uint64 subscription_expiration = 10;
    if (has_subscription_expiration()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->subscription_expiration());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint32 units_remaining = 11;
    if (has_units_remaining()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->units_remaining());
    }

    // optional uint64 status_expiration = 12;
    if (has_status_expiration()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->status_expiration());
    }

    // optional uint32 box_level = 13;
    if (has_box_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->box_level());
    }

    // optional uint64 box_level_expiration = 14;
    if (has_box_level_expiration()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->box_level_expiration());
    }

    // optional fixed32 raf_account = 21;
    if (has_raf_account()) {
      total_size += 2 + 4;
    }

    // optional bytes raf_info = 22;
    if (has_raf_info()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->raf_info());
    }

    // optional uint64 raf_expiration = 23;
    if (has_raf_expiration()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->raf_expiration());
    }

  }
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 20;
  total_size += 2 * this->licenses_size();
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

void GameAccountBlob::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountBlob* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountBlob*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountBlob::MergeFrom(const GameAccountBlob& from) {
  GOOGLE_CHECK_NE(&from, this);
  licenses_.MergeFrom(from.licenses_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_realm_permissions()) {
      set_realm_permissions(from.realm_permissions());
    }
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_flags()) {
      set_flags(from.flags());
    }
    if (from.has_billing_flags()) {
      set_billing_flags(from.billing_flags());
    }
    if (from.has_cache_expiration()) {
      set_cache_expiration(from.cache_expiration());
    }
    if (from.has_subscription_expiration()) {
      set_subscription_expiration(from.subscription_expiration());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_units_remaining()) {
      set_units_remaining(from.units_remaining());
    }
    if (from.has_status_expiration()) {
      set_status_expiration(from.status_expiration());
    }
    if (from.has_box_level()) {
      set_box_level(from.box_level());
    }
    if (from.has_box_level_expiration()) {
      set_box_level_expiration(from.box_level_expiration());
    }
    if (from.has_raf_account()) {
      set_raf_account(from.raf_account());
    }
    if (from.has_raf_info()) {
      set_raf_info(from.raf_info());
    }
    if (from.has_raf_expiration()) {
      set_raf_expiration(from.raf_expiration());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountBlob::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountBlob::CopyFrom(const GameAccountBlob& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountBlob::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000049) != 0x00000049) return false;

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  return true;
}

void GameAccountBlob::Swap(GameAccountBlob* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(name_, other->name_);
    std::swap(realm_permissions_, other->realm_permissions_);
    std::swap(status_, other->status_);
    std::swap(flags_, other->flags_);
    std::swap(billing_flags_, other->billing_flags_);
    std::swap(cache_expiration_, other->cache_expiration_);
    std::swap(subscription_expiration_, other->subscription_expiration_);
    std::swap(units_remaining_, other->units_remaining_);
    std::swap(status_expiration_, other->status_expiration_);
    std::swap(box_level_, other->box_level_);
    std::swap(box_level_expiration_, other->box_level_expiration_);
    licenses_.Swap(&other->licenses_);
    std::swap(raf_account_, other->raf_account_);
    std::swap(raf_info_, other->raf_info_);
    std::swap(raf_expiration_, other->raf_expiration_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountBlob::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountBlob_descriptor_;
  metadata.reflection = GameAccountBlob_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountBlobList::kBlobFieldNumber;
#endif  // !_MSC_VER

GameAccountBlobList::GameAccountBlobList()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountBlobList)
}

void GameAccountBlobList::InitAsDefaultInstance() {
}

GameAccountBlobList::GameAccountBlobList(const GameAccountBlobList& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountBlobList)
}

void GameAccountBlobList::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountBlobList::~GameAccountBlobList() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountBlobList)
  SharedDtor();
}

void GameAccountBlobList::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameAccountBlobList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountBlobList::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountBlobList_descriptor_;
}

const GameAccountBlobList& GameAccountBlobList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountBlobList* GameAccountBlobList::default_instance_ = NULL;

GameAccountBlobList* GameAccountBlobList::New() const {
  return new GameAccountBlobList;
}

void GameAccountBlobList::Clear() {
  blob_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountBlobList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountBlobList)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.GameAccountBlob blob = 1;
      case 1: {
        if (tag == 10) {
         parse_blob:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_blob()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_blob;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountBlobList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountBlobList)
  return false;
#undef DO_
}

void GameAccountBlobList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountBlobList)
  // repeated .bgs.protocol.account.v1.GameAccountBlob blob = 1;
  for (int i = 0; i < this->blob_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->blob(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountBlobList)
}

::google::protobuf::uint8* GameAccountBlobList::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountBlobList)
  // repeated .bgs.protocol.account.v1.GameAccountBlob blob = 1;
  for (int i = 0; i < this->blob_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->blob(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountBlobList)
  return target;
}

int GameAccountBlobList::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.account.v1.GameAccountBlob blob = 1;
  total_size += 1 * this->blob_size();
  for (int i = 0; i < this->blob_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->blob(i));
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

void GameAccountBlobList::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountBlobList* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountBlobList*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountBlobList::MergeFrom(const GameAccountBlobList& from) {
  GOOGLE_CHECK_NE(&from, this);
  blob_.MergeFrom(from.blob_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountBlobList::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountBlobList::CopyFrom(const GameAccountBlobList& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountBlobList::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->blob())) return false;
  return true;
}

void GameAccountBlobList::Swap(GameAccountBlobList* other) {
  if (other != this) {
    blob_.Swap(&other->blob_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountBlobList::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountBlobList_descriptor_;
  metadata.reflection = GameAccountBlobList_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountReference::kIdFieldNumber;
const int AccountReference::kEmailFieldNumber;
const int AccountReference::kHandleFieldNumber;
const int AccountReference::kBattleTagFieldNumber;
const int AccountReference::kRegionFieldNumber;
#endif  // !_MSC_VER

AccountReference::AccountReference()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountReference)
}

void AccountReference::InitAsDefaultInstance() {
  handle_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

AccountReference::AccountReference(const AccountReference& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountReference)
}

void AccountReference::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0u;
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  handle_ = NULL;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountReference::~AccountReference() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountReference)
  SharedDtor();
}

void AccountReference::SharedDtor() {
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete handle_;
  }
}

void AccountReference::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountReference::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountReference_descriptor_;
}

const AccountReference& AccountReference::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountReference* AccountReference::default_instance_ = NULL;

AccountReference* AccountReference::New() const {
  return new AccountReference;
}

void AccountReference::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountReference*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(id_, region_);
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
    if (has_handle()) {
      if (handle_ != NULL) handle_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountReference::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountReference)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 id = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_email;
        break;
      }

      // optional string email = 2;
      case 2: {
        if (tag == 18) {
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
        if (input->ExpectTag(26)) goto parse_handle;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountHandle handle = 3;
      case 3: {
        if (tag == 26) {
         parse_handle:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 4;
      case 4: {
        if (tag == 34) {
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
        if (input->ExpectTag(80)) goto parse_region;
        break;
      }

      // optional uint32 region = 10 [default = 0];
      case 10: {
        if (tag == 80) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountReference)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountReference)
  return false;
#undef DO_
}

void AccountReference::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountReference)
  // optional fixed32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->id(), output);
  }

  // optional string email = 2;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->email(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle handle = 3;
  if (has_handle()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->handle(), output);
  }

  // optional string battle_tag = 4;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->battle_tag(), output);
  }

  // optional uint32 region = 10 [default = 0];
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountReference)
}

::google::protobuf::uint8* AccountReference::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountReference)
  // optional fixed32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->id(), target);
  }

  // optional string email = 2;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->email(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle handle = 3;
  if (has_handle()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->handle(), target);
  }

  // optional string battle_tag = 4;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->battle_tag(), target);
  }

  // optional uint32 region = 10 [default = 0];
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountReference)
  return target;
}

int AccountReference::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 id = 1;
    if (has_id()) {
      total_size += 1 + 4;
    }

    // optional string email = 2;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

    // optional .bgs.protocol.account.v1.GameAccountHandle handle = 3;
    if (has_handle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->handle());
    }

    // optional string battle_tag = 4;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional uint32 region = 10 [default = 0];
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

void AccountReference::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountReference* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountReference*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountReference::MergeFrom(const AccountReference& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
    if (from.has_handle()) {
      mutable_handle()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.handle());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountReference::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountReference::CopyFrom(const AccountReference& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountReference::IsInitialized() const {

  if (has_handle()) {
    if (!this->handle().IsInitialized()) return false;
  }
  return true;
}

void AccountReference::Swap(AccountReference* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(email_, other->email_);
    std::swap(handle_, other->handle_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountReference::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountReference_descriptor_;
  metadata.reflection = AccountReference_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Identity::kAccountFieldNumber;
const int Identity::kGameAccountFieldNumber;
const int Identity::kProcessFieldNumber;
#endif  // !_MSC_VER

Identity::Identity()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.Identity)
}

void Identity::InitAsDefaultInstance() {
  account_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(&::bgs::protocol::account::v1::AccountId::default_instance());
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
  process_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
}

Identity::Identity(const Identity& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.Identity)
}

void Identity::SharedCtor() {
  _cached_size_ = 0;
  account_ = NULL;
  game_account_ = NULL;
  process_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Identity::~Identity() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.Identity)
  SharedDtor();
}

void Identity::SharedDtor() {
  if (this != default_instance_) {
    delete account_;
    delete game_account_;
    delete process_;
  }
}

void Identity::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Identity::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Identity_descriptor_;
}

const Identity& Identity::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

Identity* Identity::default_instance_ = NULL;

Identity* Identity::New() const {
  return new Identity;
}

void Identity::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_account()) {
      if (account_ != NULL) account_->::bgs::protocol::account::v1::AccountId::Clear();
    }
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_process()) {
      if (process_ != NULL) process_->::bgs::protocol::ProcessId::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Identity::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.Identity)
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
        if (input->ExpectTag(18)) goto parse_game_account;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
      case 2: {
        if (tag == 18) {
         parse_game_account:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_process;
        break;
      }

      // optional .bgs.protocol.ProcessId process = 3;
      case 3: {
        if (tag == 26) {
         parse_process:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_process()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.Identity)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.Identity)
  return false;
#undef DO_
}

void Identity::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.Identity)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account(), output);
  }

  // optional .bgs.protocol.ProcessId process = 3;
  if (has_process()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->process(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.Identity)
}

::google::protobuf::uint8* Identity::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.Identity)
  // optional .bgs.protocol.account.v1.AccountId account = 1;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account(), target);
  }

  // optional .bgs.protocol.ProcessId process = 3;
  if (has_process()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->process(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.Identity)
  return target;
}

int Identity::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountId account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account());
    }

    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 2;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional .bgs.protocol.ProcessId process = 3;
    if (has_process()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->process());
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

void Identity::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Identity* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Identity*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Identity::MergeFrom(const Identity& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      mutable_account()->::bgs::protocol::account::v1::AccountId::MergeFrom(from.account());
    }
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_process()) {
      mutable_process()->::bgs::protocol::ProcessId::MergeFrom(from.process());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Identity::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Identity::CopyFrom(const Identity& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Identity::IsInitialized() const {

  if (has_account()) {
    if (!this->account().IsInitialized()) return false;
  }
  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  if (has_process()) {
    if (!this->process().IsInitialized()) return false;
  }
  return true;
}

void Identity::Swap(Identity* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(game_account_, other->game_account_);
    std::swap(process_, other->process_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Identity::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Identity_descriptor_;
  metadata.reflection = Identity_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountInfo::kAccountPaidFieldNumber;
const int AccountInfo::kCountryIdFieldNumber;
const int AccountInfo::kBattleTagFieldNumber;
const int AccountInfo::kManualReviewFieldNumber;
const int AccountInfo::kIdentityFieldNumber;
const int AccountInfo::kAccountMutedFieldNumber;
#endif  // !_MSC_VER

AccountInfo::AccountInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountInfo)
}

void AccountInfo::InitAsDefaultInstance() {
  identity_ = const_cast< ::bgs::protocol::account::v1::Identity*>(&::bgs::protocol::account::v1::Identity::default_instance());
}

AccountInfo::AccountInfo(const AccountInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountInfo)
}

void AccountInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  account_paid_ = false;
  country_id_ = 0u;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  manual_review_ = false;
  identity_ = NULL;
  account_muted_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountInfo::~AccountInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountInfo)
  SharedDtor();
}

void AccountInfo::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete identity_;
  }
}

void AccountInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountInfo_descriptor_;
}

const AccountInfo& AccountInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountInfo* AccountInfo::default_instance_ = NULL;

AccountInfo* AccountInfo::New() const {
  return new AccountInfo;
}

void AccountInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(country_id_, account_muted_);
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
    if (has_identity()) {
      if (identity_ != NULL) identity_->::bgs::protocol::account::v1::Identity::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool account_paid = 1 [default = false];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &account_paid_)));
          set_has_account_paid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_country_id;
        break;
      }

      // optional fixed32 country_id = 2 [default = 0];
      case 2: {
        if (tag == 21) {
         parse_country_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &country_id_)));
          set_has_country_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 3;
      case 3: {
        if (tag == 26) {
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
        if (input->ExpectTag(32)) goto parse_manual_review;
        break;
      }

      // optional bool manual_review = 4 [default = false];
      case 4: {
        if (tag == 32) {
         parse_manual_review:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &manual_review_)));
          set_has_manual_review();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_identity;
        break;
      }

      // optional .bgs.protocol.account.v1.Identity identity = 5;
      case 5: {
        if (tag == 42) {
         parse_identity:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_identity()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_account_muted;
        break;
      }

      // optional bool account_muted = 6 [default = false];
      case 6: {
        if (tag == 48) {
         parse_account_muted:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &account_muted_)));
          set_has_account_muted();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountInfo)
  return false;
#undef DO_
}

void AccountInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountInfo)
  // optional bool account_paid = 1 [default = false];
  if (has_account_paid()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->account_paid(), output);
  }

  // optional fixed32 country_id = 2 [default = 0];
  if (has_country_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->country_id(), output);
  }

  // optional string battle_tag = 3;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->battle_tag(), output);
  }

  // optional bool manual_review = 4 [default = false];
  if (has_manual_review()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->manual_review(), output);
  }

  // optional .bgs.protocol.account.v1.Identity identity = 5;
  if (has_identity()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->identity(), output);
  }

  // optional bool account_muted = 6 [default = false];
  if (has_account_muted()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->account_muted(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountInfo)
}

::google::protobuf::uint8* AccountInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountInfo)
  // optional bool account_paid = 1 [default = false];
  if (has_account_paid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->account_paid(), target);
  }

  // optional fixed32 country_id = 2 [default = 0];
  if (has_country_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->country_id(), target);
  }

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

  // optional bool manual_review = 4 [default = false];
  if (has_manual_review()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->manual_review(), target);
  }

  // optional .bgs.protocol.account.v1.Identity identity = 5;
  if (has_identity()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->identity(), target);
  }

  // optional bool account_muted = 6 [default = false];
  if (has_account_muted()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->account_muted(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountInfo)
  return target;
}

int AccountInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool account_paid = 1 [default = false];
    if (has_account_paid()) {
      total_size += 1 + 1;
    }

    // optional fixed32 country_id = 2 [default = 0];
    if (has_country_id()) {
      total_size += 1 + 4;
    }

    // optional string battle_tag = 3;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional bool manual_review = 4 [default = false];
    if (has_manual_review()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.account.v1.Identity identity = 5;
    if (has_identity()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->identity());
    }

    // optional bool account_muted = 6 [default = false];
    if (has_account_muted()) {
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

void AccountInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountInfo::MergeFrom(const AccountInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_paid()) {
      set_account_paid(from.account_paid());
    }
    if (from.has_country_id()) {
      set_country_id(from.country_id());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_manual_review()) {
      set_manual_review(from.manual_review());
    }
    if (from.has_identity()) {
      mutable_identity()->::bgs::protocol::account::v1::Identity::MergeFrom(from.identity());
    }
    if (from.has_account_muted()) {
      set_account_muted(from.account_muted());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountInfo::CopyFrom(const AccountInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountInfo::IsInitialized() const {

  if (has_identity()) {
    if (!this->identity().IsInitialized()) return false;
  }
  return true;
}

void AccountInfo::Swap(AccountInfo* other) {
  if (other != this) {
    std::swap(account_paid_, other->account_paid_);
    std::swap(country_id_, other->country_id_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(manual_review_, other->manual_review_);
    std::swap(identity_, other->identity_);
    std::swap(account_muted_, other->account_muted_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountInfo_descriptor_;
  metadata.reflection = AccountInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ProgramTag::kProgramFieldNumber;
const int ProgramTag::kTagFieldNumber;
#endif  // !_MSC_VER

ProgramTag::ProgramTag()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.ProgramTag)
}

void ProgramTag::InitAsDefaultInstance() {
}

ProgramTag::ProgramTag(const ProgramTag& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.ProgramTag)
}

void ProgramTag::SharedCtor() {
  _cached_size_ = 0;
  program_ = 0u;
  tag_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ProgramTag::~ProgramTag() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.ProgramTag)
  SharedDtor();
}

void ProgramTag::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ProgramTag::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ProgramTag::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ProgramTag_descriptor_;
}

const ProgramTag& ProgramTag::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

ProgramTag* ProgramTag::default_instance_ = NULL;

ProgramTag* ProgramTag::New() const {
  return new ProgramTag;
}

void ProgramTag::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ProgramTag*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(program_, tag_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ProgramTag::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.ProgramTag)
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
        if (input->ExpectTag(21)) goto parse_tag;
        break;
      }

      // optional fixed32 tag = 2;
      case 2: {
        if (tag == 21) {
         parse_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &tag_)));
          set_has_tag();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.ProgramTag)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.ProgramTag)
  return false;
#undef DO_
}

void ProgramTag::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.ProgramTag)
  // optional fixed32 program = 1;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->program(), output);
  }

  // optional fixed32 tag = 2;
  if (has_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.ProgramTag)
}

::google::protobuf::uint8* ProgramTag::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.ProgramTag)
  // optional fixed32 program = 1;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->program(), target);
  }

  // optional fixed32 tag = 2;
  if (has_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->tag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.ProgramTag)
  return target;
}

int ProgramTag::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 program = 1;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional fixed32 tag = 2;
    if (has_tag()) {
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

void ProgramTag::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ProgramTag* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ProgramTag*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ProgramTag::MergeFrom(const ProgramTag& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_tag()) {
      set_tag(from.tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ProgramTag::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ProgramTag::CopyFrom(const ProgramTag& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProgramTag::IsInitialized() const {

  return true;
}

void ProgramTag::Swap(ProgramTag* other) {
  if (other != this) {
    std::swap(program_, other->program_);
    std::swap(tag_, other->tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ProgramTag::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ProgramTag_descriptor_;
  metadata.reflection = ProgramTag_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RegionTag::kRegionFieldNumber;
const int RegionTag::kTagFieldNumber;
#endif  // !_MSC_VER

RegionTag::RegionTag()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.RegionTag)
}

void RegionTag::InitAsDefaultInstance() {
}

RegionTag::RegionTag(const RegionTag& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.RegionTag)
}

void RegionTag::SharedCtor() {
  _cached_size_ = 0;
  region_ = 0u;
  tag_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RegionTag::~RegionTag() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.RegionTag)
  SharedDtor();
}

void RegionTag::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RegionTag::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RegionTag::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RegionTag_descriptor_;
}

const RegionTag& RegionTag::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

RegionTag* RegionTag::default_instance_ = NULL;

RegionTag* RegionTag::New() const {
  return new RegionTag;
}

void RegionTag::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RegionTag*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(region_, tag_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RegionTag::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.RegionTag)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 region = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_tag;
        break;
      }

      // optional fixed32 tag = 2;
      case 2: {
        if (tag == 21) {
         parse_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &tag_)));
          set_has_tag();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.RegionTag)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.RegionTag)
  return false;
#undef DO_
}

void RegionTag::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.RegionTag)
  // optional fixed32 region = 1;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->region(), output);
  }

  // optional fixed32 tag = 2;
  if (has_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.RegionTag)
}

::google::protobuf::uint8* RegionTag::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.RegionTag)
  // optional fixed32 region = 1;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->region(), target);
  }

  // optional fixed32 tag = 2;
  if (has_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->tag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.RegionTag)
  return target;
}

int RegionTag::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 region = 1;
    if (has_region()) {
      total_size += 1 + 4;
    }

    // optional fixed32 tag = 2;
    if (has_tag()) {
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

void RegionTag::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RegionTag* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RegionTag*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RegionTag::MergeFrom(const RegionTag& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_tag()) {
      set_tag(from.tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RegionTag::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RegionTag::CopyFrom(const RegionTag& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RegionTag::IsInitialized() const {

  return true;
}

void RegionTag::Swap(RegionTag* other) {
  if (other != this) {
    std::swap(region_, other->region_);
    std::swap(tag_, other->tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RegionTag::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RegionTag_descriptor_;
  metadata.reflection = RegionTag_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountFieldTags::kAccountLevelInfoTagFieldNumber;
const int AccountFieldTags::kPrivacyInfoTagFieldNumber;
const int AccountFieldTags::kParentalControlInfoTagFieldNumber;
const int AccountFieldTags::kGameLevelInfoTagsFieldNumber;
const int AccountFieldTags::kGameStatusTagsFieldNumber;
const int AccountFieldTags::kGameAccountTagsFieldNumber;
#endif  // !_MSC_VER

AccountFieldTags::AccountFieldTags()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountFieldTags)
}

void AccountFieldTags::InitAsDefaultInstance() {
}

AccountFieldTags::AccountFieldTags(const AccountFieldTags& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountFieldTags)
}

void AccountFieldTags::SharedCtor() {
  _cached_size_ = 0;
  account_level_info_tag_ = 0u;
  privacy_info_tag_ = 0u;
  parental_control_info_tag_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountFieldTags::~AccountFieldTags() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountFieldTags)
  SharedDtor();
}

void AccountFieldTags::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountFieldTags::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountFieldTags::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountFieldTags_descriptor_;
}

const AccountFieldTags& AccountFieldTags::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountFieldTags* AccountFieldTags::default_instance_ = NULL;

AccountFieldTags* AccountFieldTags::New() const {
  return new AccountFieldTags;
}

void AccountFieldTags::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountFieldTags*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(account_level_info_tag_, privacy_info_tag_);
    parental_control_info_tag_ = 0u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  game_level_info_tags_.Clear();
  game_status_tags_.Clear();
  game_account_tags_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountFieldTags::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountFieldTags)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 account_level_info_tag = 2;
      case 2: {
        if (tag == 21) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &account_level_info_tag_)));
          set_has_account_level_info_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_privacy_info_tag;
        break;
      }

      // optional fixed32 privacy_info_tag = 3;
      case 3: {
        if (tag == 29) {
         parse_privacy_info_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &privacy_info_tag_)));
          set_has_privacy_info_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_parental_control_info_tag;
        break;
      }

      // optional fixed32 parental_control_info_tag = 4;
      case 4: {
        if (tag == 37) {
         parse_parental_control_info_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &parental_control_info_tag_)));
          set_has_parental_control_info_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_game_level_info_tags;
        break;
      }

      // repeated .bgs.protocol.account.v1.ProgramTag game_level_info_tags = 7;
      case 7: {
        if (tag == 58) {
         parse_game_level_info_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_level_info_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_game_level_info_tags;
        if (input->ExpectTag(74)) goto parse_game_status_tags;
        break;
      }

      // repeated .bgs.protocol.account.v1.ProgramTag game_status_tags = 9;
      case 9: {
        if (tag == 74) {
         parse_game_status_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_status_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_game_status_tags;
        if (input->ExpectTag(90)) goto parse_game_account_tags;
        break;
      }

      // repeated .bgs.protocol.account.v1.RegionTag game_account_tags = 11;
      case 11: {
        if (tag == 90) {
         parse_game_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_account_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_game_account_tags;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountFieldTags)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountFieldTags)
  return false;
#undef DO_
}

void AccountFieldTags::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountFieldTags)
  // optional fixed32 account_level_info_tag = 2;
  if (has_account_level_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->account_level_info_tag(), output);
  }

  // optional fixed32 privacy_info_tag = 3;
  if (has_privacy_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->privacy_info_tag(), output);
  }

  // optional fixed32 parental_control_info_tag = 4;
  if (has_parental_control_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(4, this->parental_control_info_tag(), output);
  }

  // repeated .bgs.protocol.account.v1.ProgramTag game_level_info_tags = 7;
  for (int i = 0; i < this->game_level_info_tags_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->game_level_info_tags(i), output);
  }

  // repeated .bgs.protocol.account.v1.ProgramTag game_status_tags = 9;
  for (int i = 0; i < this->game_status_tags_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->game_status_tags(i), output);
  }

  // repeated .bgs.protocol.account.v1.RegionTag game_account_tags = 11;
  for (int i = 0; i < this->game_account_tags_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->game_account_tags(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountFieldTags)
}

::google::protobuf::uint8* AccountFieldTags::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountFieldTags)
  // optional fixed32 account_level_info_tag = 2;
  if (has_account_level_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->account_level_info_tag(), target);
  }

  // optional fixed32 privacy_info_tag = 3;
  if (has_privacy_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->privacy_info_tag(), target);
  }

  // optional fixed32 parental_control_info_tag = 4;
  if (has_parental_control_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(4, this->parental_control_info_tag(), target);
  }

  // repeated .bgs.protocol.account.v1.ProgramTag game_level_info_tags = 7;
  for (int i = 0; i < this->game_level_info_tags_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->game_level_info_tags(i), target);
  }

  // repeated .bgs.protocol.account.v1.ProgramTag game_status_tags = 9;
  for (int i = 0; i < this->game_status_tags_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->game_status_tags(i), target);
  }

  // repeated .bgs.protocol.account.v1.RegionTag game_account_tags = 11;
  for (int i = 0; i < this->game_account_tags_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->game_account_tags(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountFieldTags)
  return target;
}

int AccountFieldTags::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 account_level_info_tag = 2;
    if (has_account_level_info_tag()) {
      total_size += 1 + 4;
    }

    // optional fixed32 privacy_info_tag = 3;
    if (has_privacy_info_tag()) {
      total_size += 1 + 4;
    }

    // optional fixed32 parental_control_info_tag = 4;
    if (has_parental_control_info_tag()) {
      total_size += 1 + 4;
    }

  }
  // repeated .bgs.protocol.account.v1.ProgramTag game_level_info_tags = 7;
  total_size += 1 * this->game_level_info_tags_size();
  for (int i = 0; i < this->game_level_info_tags_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_level_info_tags(i));
  }

  // repeated .bgs.protocol.account.v1.ProgramTag game_status_tags = 9;
  total_size += 1 * this->game_status_tags_size();
  for (int i = 0; i < this->game_status_tags_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_status_tags(i));
  }

  // repeated .bgs.protocol.account.v1.RegionTag game_account_tags = 11;
  total_size += 1 * this->game_account_tags_size();
  for (int i = 0; i < this->game_account_tags_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_account_tags(i));
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

void AccountFieldTags::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountFieldTags* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountFieldTags*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountFieldTags::MergeFrom(const AccountFieldTags& from) {
  GOOGLE_CHECK_NE(&from, this);
  game_level_info_tags_.MergeFrom(from.game_level_info_tags_);
  game_status_tags_.MergeFrom(from.game_status_tags_);
  game_account_tags_.MergeFrom(from.game_account_tags_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_level_info_tag()) {
      set_account_level_info_tag(from.account_level_info_tag());
    }
    if (from.has_privacy_info_tag()) {
      set_privacy_info_tag(from.privacy_info_tag());
    }
    if (from.has_parental_control_info_tag()) {
      set_parental_control_info_tag(from.parental_control_info_tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountFieldTags::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountFieldTags::CopyFrom(const AccountFieldTags& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountFieldTags::IsInitialized() const {

  return true;
}

void AccountFieldTags::Swap(AccountFieldTags* other) {
  if (other != this) {
    std::swap(account_level_info_tag_, other->account_level_info_tag_);
    std::swap(privacy_info_tag_, other->privacy_info_tag_);
    std::swap(parental_control_info_tag_, other->parental_control_info_tag_);
    game_level_info_tags_.Swap(&other->game_level_info_tags_);
    game_status_tags_.Swap(&other->game_status_tags_);
    game_account_tags_.Swap(&other->game_account_tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountFieldTags::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountFieldTags_descriptor_;
  metadata.reflection = AccountFieldTags_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountFieldTags::kGameLevelInfoTagFieldNumber;
const int GameAccountFieldTags::kGameTimeInfoTagFieldNumber;
const int GameAccountFieldTags::kGameStatusTagFieldNumber;
const int GameAccountFieldTags::kRafInfoTagFieldNumber;
#endif  // !_MSC_VER

GameAccountFieldTags::GameAccountFieldTags()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountFieldTags)
}

void GameAccountFieldTags::InitAsDefaultInstance() {
}

GameAccountFieldTags::GameAccountFieldTags(const GameAccountFieldTags& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountFieldTags)
}

void GameAccountFieldTags::SharedCtor() {
  _cached_size_ = 0;
  game_level_info_tag_ = 0u;
  game_time_info_tag_ = 0u;
  game_status_tag_ = 0u;
  raf_info_tag_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountFieldTags::~GameAccountFieldTags() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountFieldTags)
  SharedDtor();
}

void GameAccountFieldTags::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameAccountFieldTags::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountFieldTags::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountFieldTags_descriptor_;
}

const GameAccountFieldTags& GameAccountFieldTags::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountFieldTags* GameAccountFieldTags::default_instance_ = NULL;

GameAccountFieldTags* GameAccountFieldTags::New() const {
  return new GameAccountFieldTags;
}

void GameAccountFieldTags::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameAccountFieldTags*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(game_level_info_tag_, raf_info_tag_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountFieldTags::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountFieldTags)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 game_level_info_tag = 2;
      case 2: {
        if (tag == 21) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &game_level_info_tag_)));
          set_has_game_level_info_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_game_time_info_tag;
        break;
      }

      // optional fixed32 game_time_info_tag = 3;
      case 3: {
        if (tag == 29) {
         parse_game_time_info_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &game_time_info_tag_)));
          set_has_game_time_info_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_game_status_tag;
        break;
      }

      // optional fixed32 game_status_tag = 4;
      case 4: {
        if (tag == 37) {
         parse_game_status_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &game_status_tag_)));
          set_has_game_status_tag();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_raf_info_tag;
        break;
      }

      // optional fixed32 raf_info_tag = 5;
      case 5: {
        if (tag == 45) {
         parse_raf_info_tag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &raf_info_tag_)));
          set_has_raf_info_tag();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountFieldTags)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountFieldTags)
  return false;
#undef DO_
}

void GameAccountFieldTags::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountFieldTags)
  // optional fixed32 game_level_info_tag = 2;
  if (has_game_level_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->game_level_info_tag(), output);
  }

  // optional fixed32 game_time_info_tag = 3;
  if (has_game_time_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->game_time_info_tag(), output);
  }

  // optional fixed32 game_status_tag = 4;
  if (has_game_status_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(4, this->game_status_tag(), output);
  }

  // optional fixed32 raf_info_tag = 5;
  if (has_raf_info_tag()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(5, this->raf_info_tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountFieldTags)
}

::google::protobuf::uint8* GameAccountFieldTags::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountFieldTags)
  // optional fixed32 game_level_info_tag = 2;
  if (has_game_level_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->game_level_info_tag(), target);
  }

  // optional fixed32 game_time_info_tag = 3;
  if (has_game_time_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->game_time_info_tag(), target);
  }

  // optional fixed32 game_status_tag = 4;
  if (has_game_status_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(4, this->game_status_tag(), target);
  }

  // optional fixed32 raf_info_tag = 5;
  if (has_raf_info_tag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(5, this->raf_info_tag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountFieldTags)
  return target;
}

int GameAccountFieldTags::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 game_level_info_tag = 2;
    if (has_game_level_info_tag()) {
      total_size += 1 + 4;
    }

    // optional fixed32 game_time_info_tag = 3;
    if (has_game_time_info_tag()) {
      total_size += 1 + 4;
    }

    // optional fixed32 game_status_tag = 4;
    if (has_game_status_tag()) {
      total_size += 1 + 4;
    }

    // optional fixed32 raf_info_tag = 5;
    if (has_raf_info_tag()) {
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

void GameAccountFieldTags::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountFieldTags* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountFieldTags*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountFieldTags::MergeFrom(const GameAccountFieldTags& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_level_info_tag()) {
      set_game_level_info_tag(from.game_level_info_tag());
    }
    if (from.has_game_time_info_tag()) {
      set_game_time_info_tag(from.game_time_info_tag());
    }
    if (from.has_game_status_tag()) {
      set_game_status_tag(from.game_status_tag());
    }
    if (from.has_raf_info_tag()) {
      set_raf_info_tag(from.raf_info_tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountFieldTags::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountFieldTags::CopyFrom(const GameAccountFieldTags& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountFieldTags::IsInitialized() const {

  return true;
}

void GameAccountFieldTags::Swap(GameAccountFieldTags* other) {
  if (other != this) {
    std::swap(game_level_info_tag_, other->game_level_info_tag_);
    std::swap(game_time_info_tag_, other->game_time_info_tag_);
    std::swap(game_status_tag_, other->game_status_tag_);
    std::swap(raf_info_tag_, other->raf_info_tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountFieldTags::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountFieldTags_descriptor_;
  metadata.reflection = GameAccountFieldTags_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountFieldOptions::kAllFieldsFieldNumber;
const int AccountFieldOptions::kFieldAccountLevelInfoFieldNumber;
const int AccountFieldOptions::kFieldPrivacyInfoFieldNumber;
const int AccountFieldOptions::kFieldParentalControlInfoFieldNumber;
const int AccountFieldOptions::kFieldGameLevelInfoFieldNumber;
const int AccountFieldOptions::kFieldGameStatusFieldNumber;
const int AccountFieldOptions::kFieldGameAccountsFieldNumber;
#endif  // !_MSC_VER

AccountFieldOptions::AccountFieldOptions()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountFieldOptions)
}

void AccountFieldOptions::InitAsDefaultInstance() {
}

AccountFieldOptions::AccountFieldOptions(const AccountFieldOptions& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountFieldOptions)
}

void AccountFieldOptions::SharedCtor() {
  _cached_size_ = 0;
  all_fields_ = false;
  field_account_level_info_ = false;
  field_privacy_info_ = false;
  field_parental_control_info_ = false;
  field_game_level_info_ = false;
  field_game_status_ = false;
  field_game_accounts_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountFieldOptions::~AccountFieldOptions() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountFieldOptions)
  SharedDtor();
}

void AccountFieldOptions::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AccountFieldOptions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountFieldOptions::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountFieldOptions_descriptor_;
}

const AccountFieldOptions& AccountFieldOptions::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountFieldOptions* AccountFieldOptions::default_instance_ = NULL;

AccountFieldOptions* AccountFieldOptions::New() const {
  return new AccountFieldOptions;
}

void AccountFieldOptions::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountFieldOptions*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 127) {
    ZR_(all_fields_, field_game_accounts_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountFieldOptions::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountFieldOptions)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool all_fields = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &all_fields_)));
          set_has_all_fields();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_field_account_level_info;
        break;
      }

      // optional bool field_account_level_info = 2;
      case 2: {
        if (tag == 16) {
         parse_field_account_level_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_account_level_info_)));
          set_has_field_account_level_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_field_privacy_info;
        break;
      }

      // optional bool field_privacy_info = 3;
      case 3: {
        if (tag == 24) {
         parse_field_privacy_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_privacy_info_)));
          set_has_field_privacy_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_field_parental_control_info;
        break;
      }

      // optional bool field_parental_control_info = 4;
      case 4: {
        if (tag == 32) {
         parse_field_parental_control_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_parental_control_info_)));
          set_has_field_parental_control_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_field_game_level_info;
        break;
      }

      // optional bool field_game_level_info = 6;
      case 6: {
        if (tag == 48) {
         parse_field_game_level_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_level_info_)));
          set_has_field_game_level_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_field_game_status;
        break;
      }

      // optional bool field_game_status = 7;
      case 7: {
        if (tag == 56) {
         parse_field_game_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_status_)));
          set_has_field_game_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_field_game_accounts;
        break;
      }

      // optional bool field_game_accounts = 8;
      case 8: {
        if (tag == 64) {
         parse_field_game_accounts:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_accounts_)));
          set_has_field_game_accounts();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountFieldOptions)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountFieldOptions)
  return false;
#undef DO_
}

void AccountFieldOptions::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountFieldOptions)
  // optional bool all_fields = 1;
  if (has_all_fields()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->all_fields(), output);
  }

  // optional bool field_account_level_info = 2;
  if (has_field_account_level_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->field_account_level_info(), output);
  }

  // optional bool field_privacy_info = 3;
  if (has_field_privacy_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->field_privacy_info(), output);
  }

  // optional bool field_parental_control_info = 4;
  if (has_field_parental_control_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->field_parental_control_info(), output);
  }

  // optional bool field_game_level_info = 6;
  if (has_field_game_level_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->field_game_level_info(), output);
  }

  // optional bool field_game_status = 7;
  if (has_field_game_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->field_game_status(), output);
  }

  // optional bool field_game_accounts = 8;
  if (has_field_game_accounts()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->field_game_accounts(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountFieldOptions)
}

::google::protobuf::uint8* AccountFieldOptions::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountFieldOptions)
  // optional bool all_fields = 1;
  if (has_all_fields()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->all_fields(), target);
  }

  // optional bool field_account_level_info = 2;
  if (has_field_account_level_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->field_account_level_info(), target);
  }

  // optional bool field_privacy_info = 3;
  if (has_field_privacy_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->field_privacy_info(), target);
  }

  // optional bool field_parental_control_info = 4;
  if (has_field_parental_control_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->field_parental_control_info(), target);
  }

  // optional bool field_game_level_info = 6;
  if (has_field_game_level_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->field_game_level_info(), target);
  }

  // optional bool field_game_status = 7;
  if (has_field_game_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->field_game_status(), target);
  }

  // optional bool field_game_accounts = 8;
  if (has_field_game_accounts()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->field_game_accounts(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountFieldOptions)
  return target;
}

int AccountFieldOptions::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool all_fields = 1;
    if (has_all_fields()) {
      total_size += 1 + 1;
    }

    // optional bool field_account_level_info = 2;
    if (has_field_account_level_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_privacy_info = 3;
    if (has_field_privacy_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_parental_control_info = 4;
    if (has_field_parental_control_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_level_info = 6;
    if (has_field_game_level_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_status = 7;
    if (has_field_game_status()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_accounts = 8;
    if (has_field_game_accounts()) {
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

void AccountFieldOptions::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountFieldOptions* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountFieldOptions*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountFieldOptions::MergeFrom(const AccountFieldOptions& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_all_fields()) {
      set_all_fields(from.all_fields());
    }
    if (from.has_field_account_level_info()) {
      set_field_account_level_info(from.field_account_level_info());
    }
    if (from.has_field_privacy_info()) {
      set_field_privacy_info(from.field_privacy_info());
    }
    if (from.has_field_parental_control_info()) {
      set_field_parental_control_info(from.field_parental_control_info());
    }
    if (from.has_field_game_level_info()) {
      set_field_game_level_info(from.field_game_level_info());
    }
    if (from.has_field_game_status()) {
      set_field_game_status(from.field_game_status());
    }
    if (from.has_field_game_accounts()) {
      set_field_game_accounts(from.field_game_accounts());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountFieldOptions::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountFieldOptions::CopyFrom(const AccountFieldOptions& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountFieldOptions::IsInitialized() const {

  return true;
}

void AccountFieldOptions::Swap(AccountFieldOptions* other) {
  if (other != this) {
    std::swap(all_fields_, other->all_fields_);
    std::swap(field_account_level_info_, other->field_account_level_info_);
    std::swap(field_privacy_info_, other->field_privacy_info_);
    std::swap(field_parental_control_info_, other->field_parental_control_info_);
    std::swap(field_game_level_info_, other->field_game_level_info_);
    std::swap(field_game_status_, other->field_game_status_);
    std::swap(field_game_accounts_, other->field_game_accounts_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountFieldOptions::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountFieldOptions_descriptor_;
  metadata.reflection = AccountFieldOptions_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountFieldOptions::kAllFieldsFieldNumber;
const int GameAccountFieldOptions::kFieldGameLevelInfoFieldNumber;
const int GameAccountFieldOptions::kFieldGameTimeInfoFieldNumber;
const int GameAccountFieldOptions::kFieldGameStatusFieldNumber;
const int GameAccountFieldOptions::kFieldRafInfoFieldNumber;
#endif  // !_MSC_VER

GameAccountFieldOptions::GameAccountFieldOptions()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountFieldOptions)
}

void GameAccountFieldOptions::InitAsDefaultInstance() {
}

GameAccountFieldOptions::GameAccountFieldOptions(const GameAccountFieldOptions& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountFieldOptions)
}

void GameAccountFieldOptions::SharedCtor() {
  _cached_size_ = 0;
  all_fields_ = false;
  field_game_level_info_ = false;
  field_game_time_info_ = false;
  field_game_status_ = false;
  field_raf_info_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountFieldOptions::~GameAccountFieldOptions() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountFieldOptions)
  SharedDtor();
}

void GameAccountFieldOptions::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameAccountFieldOptions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountFieldOptions::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountFieldOptions_descriptor_;
}

const GameAccountFieldOptions& GameAccountFieldOptions::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountFieldOptions* GameAccountFieldOptions::default_instance_ = NULL;

GameAccountFieldOptions* GameAccountFieldOptions::New() const {
  return new GameAccountFieldOptions;
}

void GameAccountFieldOptions::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameAccountFieldOptions*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(all_fields_, field_raf_info_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountFieldOptions::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountFieldOptions)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool all_fields = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &all_fields_)));
          set_has_all_fields();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_field_game_level_info;
        break;
      }

      // optional bool field_game_level_info = 2;
      case 2: {
        if (tag == 16) {
         parse_field_game_level_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_level_info_)));
          set_has_field_game_level_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_field_game_time_info;
        break;
      }

      // optional bool field_game_time_info = 3;
      case 3: {
        if (tag == 24) {
         parse_field_game_time_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_time_info_)));
          set_has_field_game_time_info();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_field_game_status;
        break;
      }

      // optional bool field_game_status = 4;
      case 4: {
        if (tag == 32) {
         parse_field_game_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_game_status_)));
          set_has_field_game_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_field_raf_info;
        break;
      }

      // optional bool field_raf_info = 5;
      case 5: {
        if (tag == 40) {
         parse_field_raf_info:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &field_raf_info_)));
          set_has_field_raf_info();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountFieldOptions)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountFieldOptions)
  return false;
#undef DO_
}

void GameAccountFieldOptions::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountFieldOptions)
  // optional bool all_fields = 1;
  if (has_all_fields()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->all_fields(), output);
  }

  // optional bool field_game_level_info = 2;
  if (has_field_game_level_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->field_game_level_info(), output);
  }

  // optional bool field_game_time_info = 3;
  if (has_field_game_time_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->field_game_time_info(), output);
  }

  // optional bool field_game_status = 4;
  if (has_field_game_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->field_game_status(), output);
  }

  // optional bool field_raf_info = 5;
  if (has_field_raf_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->field_raf_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountFieldOptions)
}

::google::protobuf::uint8* GameAccountFieldOptions::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountFieldOptions)
  // optional bool all_fields = 1;
  if (has_all_fields()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->all_fields(), target);
  }

  // optional bool field_game_level_info = 2;
  if (has_field_game_level_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->field_game_level_info(), target);
  }

  // optional bool field_game_time_info = 3;
  if (has_field_game_time_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->field_game_time_info(), target);
  }

  // optional bool field_game_status = 4;
  if (has_field_game_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->field_game_status(), target);
  }

  // optional bool field_raf_info = 5;
  if (has_field_raf_info()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->field_raf_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountFieldOptions)
  return target;
}

int GameAccountFieldOptions::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool all_fields = 1;
    if (has_all_fields()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_level_info = 2;
    if (has_field_game_level_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_time_info = 3;
    if (has_field_game_time_info()) {
      total_size += 1 + 1;
    }

    // optional bool field_game_status = 4;
    if (has_field_game_status()) {
      total_size += 1 + 1;
    }

    // optional bool field_raf_info = 5;
    if (has_field_raf_info()) {
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

void GameAccountFieldOptions::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountFieldOptions* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountFieldOptions*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountFieldOptions::MergeFrom(const GameAccountFieldOptions& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_all_fields()) {
      set_all_fields(from.all_fields());
    }
    if (from.has_field_game_level_info()) {
      set_field_game_level_info(from.field_game_level_info());
    }
    if (from.has_field_game_time_info()) {
      set_field_game_time_info(from.field_game_time_info());
    }
    if (from.has_field_game_status()) {
      set_field_game_status(from.field_game_status());
    }
    if (from.has_field_raf_info()) {
      set_field_raf_info(from.field_raf_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountFieldOptions::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountFieldOptions::CopyFrom(const GameAccountFieldOptions& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountFieldOptions::IsInitialized() const {

  return true;
}

void GameAccountFieldOptions::Swap(GameAccountFieldOptions* other) {
  if (other != this) {
    std::swap(all_fields_, other->all_fields_);
    std::swap(field_game_level_info_, other->field_game_level_info_);
    std::swap(field_game_time_info_, other->field_game_time_info_);
    std::swap(field_game_status_, other->field_game_status_);
    std::swap(field_raf_info_, other->field_raf_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountFieldOptions::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountFieldOptions_descriptor_;
  metadata.reflection = GameAccountFieldOptions_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SubscriberReference::kObjectIdFieldNumber;
const int SubscriberReference::kEntityIdFieldNumber;
const int SubscriberReference::kAccountOptionsFieldNumber;
const int SubscriberReference::kAccountTagsFieldNumber;
const int SubscriberReference::kGameAccountOptionsFieldNumber;
const int SubscriberReference::kGameAccountTagsFieldNumber;
const int SubscriberReference::kSubscriberIdFieldNumber;
#endif  // !_MSC_VER

SubscriberReference::SubscriberReference()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.SubscriberReference)
}

void SubscriberReference::InitAsDefaultInstance() {
  entity_id_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  account_options_ = const_cast< ::bgs::protocol::account::v1::AccountFieldOptions*>(&::bgs::protocol::account::v1::AccountFieldOptions::default_instance());
  account_tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
  game_account_options_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldOptions*>(&::bgs::protocol::account::v1::GameAccountFieldOptions::default_instance());
  game_account_tags_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldTags*>(&::bgs::protocol::account::v1::GameAccountFieldTags::default_instance());
}

SubscriberReference::SubscriberReference(const SubscriberReference& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.SubscriberReference)
}

void SubscriberReference::SharedCtor() {
  _cached_size_ = 0;
  object_id_ = GOOGLE_ULONGLONG(0);
  entity_id_ = NULL;
  account_options_ = NULL;
  account_tags_ = NULL;
  game_account_options_ = NULL;
  game_account_tags_ = NULL;
  subscriber_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SubscriberReference::~SubscriberReference() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.SubscriberReference)
  SharedDtor();
}

void SubscriberReference::SharedDtor() {
  if (this != default_instance_) {
    delete entity_id_;
    delete account_options_;
    delete account_tags_;
    delete game_account_options_;
    delete game_account_tags_;
  }
}

void SubscriberReference::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SubscriberReference::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SubscriberReference_descriptor_;
}

const SubscriberReference& SubscriberReference::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

SubscriberReference* SubscriberReference::default_instance_ = NULL;

SubscriberReference* SubscriberReference::New() const {
  return new SubscriberReference;
}

void SubscriberReference::Clear() {
  if (_has_bits_[0 / 32] & 127) {
    object_id_ = GOOGLE_ULONGLONG(0);
    if (has_entity_id()) {
      if (entity_id_ != NULL) entity_id_->::bgs::protocol::EntityId::Clear();
    }
    if (has_account_options()) {
      if (account_options_ != NULL) account_options_->::bgs::protocol::account::v1::AccountFieldOptions::Clear();
    }
    if (has_account_tags()) {
      if (account_tags_ != NULL) account_tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
    if (has_game_account_options()) {
      if (game_account_options_ != NULL) game_account_options_->::bgs::protocol::account::v1::GameAccountFieldOptions::Clear();
    }
    if (has_game_account_tags()) {
      if (game_account_tags_ != NULL) game_account_tags_->::bgs::protocol::account::v1::GameAccountFieldTags::Clear();
    }
    subscriber_id_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SubscriberReference::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.SubscriberReference)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 object_id = 1 [default = 0];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &object_id_)));
          set_has_object_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_entity_id;
        break;
      }

      // optional .bgs.protocol.EntityId entity_id = 2;
      case 2: {
        if (tag == 18) {
         parse_entity_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_entity_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_account_options;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldOptions account_options = 3;
      case 3: {
        if (tag == 26) {
         parse_account_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 4;
      case 4: {
        if (tag == 34) {
         parse_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_game_account_options;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldOptions game_account_options = 5;
      case 5: {
        if (tag == 42) {
         parse_game_account_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_game_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 6;
      case 6: {
        if (tag == 50) {
         parse_game_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_tags()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_subscriber_id;
        break;
      }

      // optional uint64 subscriber_id = 7 [default = 0];
      case 7: {
        if (tag == 56) {
         parse_subscriber_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &subscriber_id_)));
          set_has_subscriber_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.SubscriberReference)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.SubscriberReference)
  return false;
#undef DO_
}

void SubscriberReference::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.SubscriberReference)
  // optional uint64 object_id = 1 [default = 0];
  if (has_object_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->object_id(), output);
  }

  // optional .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->entity_id(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldOptions account_options = 3;
  if (has_account_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->account_options(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 4;
  if (has_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->account_tags(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldOptions game_account_options = 5;
  if (has_game_account_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->game_account_options(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 6;
  if (has_game_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->game_account_tags(), output);
  }

  // optional uint64 subscriber_id = 7 [default = 0];
  if (has_subscriber_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(7, this->subscriber_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.SubscriberReference)
}

::google::protobuf::uint8* SubscriberReference::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.SubscriberReference)
  // optional uint64 object_id = 1 [default = 0];
  if (has_object_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->object_id(), target);
  }

  // optional .bgs.protocol.EntityId entity_id = 2;
  if (has_entity_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->entity_id(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldOptions account_options = 3;
  if (has_account_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->account_options(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 4;
  if (has_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->account_tags(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldOptions game_account_options = 5;
  if (has_game_account_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->game_account_options(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 6;
  if (has_game_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->game_account_tags(), target);
  }

  // optional uint64 subscriber_id = 7 [default = 0];
  if (has_subscriber_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(7, this->subscriber_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.SubscriberReference)
  return target;
}

int SubscriberReference::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint64 object_id = 1 [default = 0];
    if (has_object_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->object_id());
    }

    // optional .bgs.protocol.EntityId entity_id = 2;
    if (has_entity_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->entity_id());
    }

    // optional .bgs.protocol.account.v1.AccountFieldOptions account_options = 3;
    if (has_account_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_options());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 4;
    if (has_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_tags());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldOptions game_account_options = 5;
    if (has_game_account_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_options());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 6;
    if (has_game_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_tags());
    }

    // optional uint64 subscriber_id = 7 [default = 0];
    if (has_subscriber_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->subscriber_id());
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

void SubscriberReference::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SubscriberReference* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SubscriberReference*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SubscriberReference::MergeFrom(const SubscriberReference& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_object_id()) {
      set_object_id(from.object_id());
    }
    if (from.has_entity_id()) {
      mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from.entity_id());
    }
    if (from.has_account_options()) {
      mutable_account_options()->::bgs::protocol::account::v1::AccountFieldOptions::MergeFrom(from.account_options());
    }
    if (from.has_account_tags()) {
      mutable_account_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.account_tags());
    }
    if (from.has_game_account_options()) {
      mutable_game_account_options()->::bgs::protocol::account::v1::GameAccountFieldOptions::MergeFrom(from.game_account_options());
    }
    if (from.has_game_account_tags()) {
      mutable_game_account_tags()->::bgs::protocol::account::v1::GameAccountFieldTags::MergeFrom(from.game_account_tags());
    }
    if (from.has_subscriber_id()) {
      set_subscriber_id(from.subscriber_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SubscriberReference::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscriberReference::CopyFrom(const SubscriberReference& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscriberReference::IsInitialized() const {

  if (has_entity_id()) {
    if (!this->entity_id().IsInitialized()) return false;
  }
  return true;
}

void SubscriberReference::Swap(SubscriberReference* other) {
  if (other != this) {
    std::swap(object_id_, other->object_id_);
    std::swap(entity_id_, other->entity_id_);
    std::swap(account_options_, other->account_options_);
    std::swap(account_tags_, other->account_tags_);
    std::swap(game_account_options_, other->game_account_options_);
    std::swap(game_account_tags_, other->game_account_tags_);
    std::swap(subscriber_id_, other->subscriber_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SubscriberReference::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SubscriberReference_descriptor_;
  metadata.reflection = SubscriberReference_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountLevelInfo::kLicensesFieldNumber;
const int AccountLevelInfo::kDefaultCurrencyFieldNumber;
const int AccountLevelInfo::kCountryFieldNumber;
const int AccountLevelInfo::kPreferredRegionFieldNumber;
const int AccountLevelInfo::kFullNameFieldNumber;
const int AccountLevelInfo::kBattleTagFieldNumber;
const int AccountLevelInfo::kMutedFieldNumber;
const int AccountLevelInfo::kManualReviewFieldNumber;
const int AccountLevelInfo::kAccountPaidAnyFieldNumber;
const int AccountLevelInfo::kIdentityCheckStatusFieldNumber;
const int AccountLevelInfo::kEmailFieldNumber;
#endif  // !_MSC_VER

AccountLevelInfo::AccountLevelInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountLevelInfo)
}

void AccountLevelInfo::InitAsDefaultInstance() {
}

AccountLevelInfo::AccountLevelInfo(const AccountLevelInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountLevelInfo)
}

void AccountLevelInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  default_currency_ = 0u;
  country_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  preferred_region_ = 0u;
  full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  muted_ = false;
  manual_review_ = false;
  account_paid_any_ = false;
  identity_check_status_ = 0;
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountLevelInfo::~AccountLevelInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountLevelInfo)
  SharedDtor();
}

void AccountLevelInfo::SharedDtor() {
  if (country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete country_;
  }
  if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete full_name_;
  }
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (this != default_instance_) {
  }
}

void AccountLevelInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountLevelInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountLevelInfo_descriptor_;
}

const AccountLevelInfo& AccountLevelInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountLevelInfo* AccountLevelInfo::default_instance_ = NULL;

AccountLevelInfo* AccountLevelInfo::New() const {
  return new AccountLevelInfo;
}

void AccountLevelInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AccountLevelInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 254) {
    ZR_(default_currency_, preferred_region_);
    ZR_(muted_, manual_review_);
    if (has_country()) {
      if (country_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        country_->clear();
      }
    }
    if (has_full_name()) {
      if (full_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        full_name_->clear();
      }
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 1792) {
    ZR_(account_paid_any_, identity_check_status_);
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  licenses_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountLevelInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountLevelInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.account.v1.AccountLicense licenses = 3;
      case 3: {
        if (tag == 26) {
         parse_licenses:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_licenses()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_licenses;
        if (input->ExpectTag(37)) goto parse_default_currency;
        break;
      }

      // optional fixed32 default_currency = 4;
      case 4: {
        if (tag == 37) {
         parse_default_currency:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &default_currency_)));
          set_has_default_currency();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_country;
        break;
      }

      // optional string country = 5;
      case 5: {
        if (tag == 42) {
         parse_country:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_country()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->country().data(), this->country().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "country");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_preferred_region;
        break;
      }

      // optional uint32 preferred_region = 6;
      case 6: {
        if (tag == 48) {
         parse_preferred_region:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &preferred_region_)));
          set_has_preferred_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_full_name;
        break;
      }

      // optional string full_name = 7;
      case 7: {
        if (tag == 58) {
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
        if (input->ExpectTag(66)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 8;
      case 8: {
        if (tag == 66) {
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
        if (input->ExpectTag(72)) goto parse_muted;
        break;
      }

      // optional bool muted = 9;
      case 9: {
        if (tag == 72) {
         parse_muted:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &muted_)));
          set_has_muted();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_manual_review;
        break;
      }

      // optional bool manual_review = 10;
      case 10: {
        if (tag == 80) {
         parse_manual_review:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &manual_review_)));
          set_has_manual_review();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_account_paid_any;
        break;
      }

      // optional bool account_paid_any = 11;
      case 11: {
        if (tag == 88) {
         parse_account_paid_any:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &account_paid_any_)));
          set_has_account_paid_any();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_identity_check_status;
        break;
      }

      // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 12;
      case 12: {
        if (tag == 96) {
         parse_identity_check_status:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::account::v1::IdentityVerificationStatus_IsValid(value)) {
            set_identity_check_status(static_cast< ::bgs::protocol::account::v1::IdentityVerificationStatus >(value));
          } else {
            mutable_unknown_fields()->AddVarint(12, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_email;
        break;
      }

      // optional string email = 13;
      case 13: {
        if (tag == 106) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountLevelInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountLevelInfo)
  return false;
#undef DO_
}

void AccountLevelInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountLevelInfo)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 3;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->licenses(i), output);
  }

  // optional fixed32 default_currency = 4;
  if (has_default_currency()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(4, this->default_currency(), output);
  }

  // optional string country = 5;
  if (has_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->country().data(), this->country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "country");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->country(), output);
  }

  // optional uint32 preferred_region = 6;
  if (has_preferred_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->preferred_region(), output);
  }

  // optional string full_name = 7;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->full_name(), output);
  }

  // optional string battle_tag = 8;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->battle_tag(), output);
  }

  // optional bool muted = 9;
  if (has_muted()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->muted(), output);
  }

  // optional bool manual_review = 10;
  if (has_manual_review()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(10, this->manual_review(), output);
  }

  // optional bool account_paid_any = 11;
  if (has_account_paid_any()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(11, this->account_paid_any(), output);
  }

  // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 12;
  if (has_identity_check_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      12, this->identity_check_status(), output);
  }

  // optional string email = 13;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      13, this->email(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountLevelInfo)
}

::google::protobuf::uint8* AccountLevelInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountLevelInfo)
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 3;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->licenses(i), target);
  }

  // optional fixed32 default_currency = 4;
  if (has_default_currency()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(4, this->default_currency(), target);
  }

  // optional string country = 5;
  if (has_country()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->country().data(), this->country().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "country");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->country(), target);
  }

  // optional uint32 preferred_region = 6;
  if (has_preferred_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->preferred_region(), target);
  }

  // optional string full_name = 7;
  if (has_full_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_name().data(), this->full_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "full_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->full_name(), target);
  }

  // optional string battle_tag = 8;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->battle_tag(), target);
  }

  // optional bool muted = 9;
  if (has_muted()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->muted(), target);
  }

  // optional bool manual_review = 10;
  if (has_manual_review()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(10, this->manual_review(), target);
  }

  // optional bool account_paid_any = 11;
  if (has_account_paid_any()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(11, this->account_paid_any(), target);
  }

  // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 12;
  if (has_identity_check_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      12, this->identity_check_status(), target);
  }

  // optional string email = 13;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        13, this->email(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountLevelInfo)
  return target;
}

int AccountLevelInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional fixed32 default_currency = 4;
    if (has_default_currency()) {
      total_size += 1 + 4;
    }

    // optional string country = 5;
    if (has_country()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->country());
    }

    // optional uint32 preferred_region = 6;
    if (has_preferred_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->preferred_region());
    }

    // optional string full_name = 7;
    if (has_full_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->full_name());
    }

    // optional string battle_tag = 8;
    if (has_battle_tag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->battle_tag());
    }

    // optional bool muted = 9;
    if (has_muted()) {
      total_size += 1 + 1;
    }

    // optional bool manual_review = 10;
    if (has_manual_review()) {
      total_size += 1 + 1;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool account_paid_any = 11;
    if (has_account_paid_any()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.account.v1.IdentityVerificationStatus identity_check_status = 12;
    if (has_identity_check_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->identity_check_status());
    }

    // optional string email = 13;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

  }
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 3;
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

void AccountLevelInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountLevelInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountLevelInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountLevelInfo::MergeFrom(const AccountLevelInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  licenses_.MergeFrom(from.licenses_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_default_currency()) {
      set_default_currency(from.default_currency());
    }
    if (from.has_country()) {
      set_country(from.country());
    }
    if (from.has_preferred_region()) {
      set_preferred_region(from.preferred_region());
    }
    if (from.has_full_name()) {
      set_full_name(from.full_name());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
    if (from.has_muted()) {
      set_muted(from.muted());
    }
    if (from.has_manual_review()) {
      set_manual_review(from.manual_review());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_account_paid_any()) {
      set_account_paid_any(from.account_paid_any());
    }
    if (from.has_identity_check_status()) {
      set_identity_check_status(from.identity_check_status());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountLevelInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountLevelInfo::CopyFrom(const AccountLevelInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountLevelInfo::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  return true;
}

void AccountLevelInfo::Swap(AccountLevelInfo* other) {
  if (other != this) {
    licenses_.Swap(&other->licenses_);
    std::swap(default_currency_, other->default_currency_);
    std::swap(country_, other->country_);
    std::swap(preferred_region_, other->preferred_region_);
    std::swap(full_name_, other->full_name_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(muted_, other->muted_);
    std::swap(manual_review_, other->manual_review_);
    std::swap(account_paid_any_, other->account_paid_any_);
    std::swap(identity_check_status_, other->identity_check_status_);
    std::swap(email_, other->email_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountLevelInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountLevelInfo_descriptor_;
  metadata.reflection = AccountLevelInfo_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* PrivacyInfo_GameInfoPrivacy_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PrivacyInfo_GameInfoPrivacy_descriptor_;
}
bool PrivacyInfo_GameInfoPrivacy_IsValid(int value) {
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
const PrivacyInfo_GameInfoPrivacy PrivacyInfo::PRIVACY_ME;
const PrivacyInfo_GameInfoPrivacy PrivacyInfo::PRIVACY_FRIENDS;
const PrivacyInfo_GameInfoPrivacy PrivacyInfo::PRIVACY_EVERYONE;
const PrivacyInfo_GameInfoPrivacy PrivacyInfo::GameInfoPrivacy_MIN;
const PrivacyInfo_GameInfoPrivacy PrivacyInfo::GameInfoPrivacy_MAX;
const int PrivacyInfo::GameInfoPrivacy_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int PrivacyInfo::kIsUsingRidFieldNumber;
const int PrivacyInfo::kIsRealIdVisibleForViewFriendsFieldNumber;
const int PrivacyInfo::kIsHiddenFromFriendFinderFieldNumber;
const int PrivacyInfo::kGameInfoPrivacyFieldNumber;
#endif  // !_MSC_VER

PrivacyInfo::PrivacyInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.PrivacyInfo)
}

void PrivacyInfo::InitAsDefaultInstance() {
}

PrivacyInfo::PrivacyInfo(const PrivacyInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.PrivacyInfo)
}

void PrivacyInfo::SharedCtor() {
  _cached_size_ = 0;
  is_using_rid_ = false;
  is_real_id_visible_for_view_friends_ = false;
  is_hidden_from_friend_finder_ = false;
  game_info_privacy_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PrivacyInfo::~PrivacyInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.PrivacyInfo)
  SharedDtor();
}

void PrivacyInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PrivacyInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PrivacyInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PrivacyInfo_descriptor_;
}

const PrivacyInfo& PrivacyInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

PrivacyInfo* PrivacyInfo::default_instance_ = NULL;

PrivacyInfo* PrivacyInfo::New() const {
  return new PrivacyInfo;
}

void PrivacyInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<PrivacyInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(is_using_rid_, is_hidden_from_friend_finder_);
    game_info_privacy_ = 1;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PrivacyInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.PrivacyInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool is_using_rid = 3;
      case 3: {
        if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_using_rid_)));
          set_has_is_using_rid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_is_real_id_visible_for_view_friends;
        break;
      }

      // optional bool is_real_id_visible_for_view_friends = 4;
      case 4: {
        if (tag == 32) {
         parse_is_real_id_visible_for_view_friends:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_real_id_visible_for_view_friends_)));
          set_has_is_real_id_visible_for_view_friends();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_is_hidden_from_friend_finder;
        break;
      }

      // optional bool is_hidden_from_friend_finder = 5;
      case 5: {
        if (tag == 40) {
         parse_is_hidden_from_friend_finder:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_hidden_from_friend_finder_)));
          set_has_is_hidden_from_friend_finder();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_game_info_privacy;
        break;
      }

      // optional .bgs.protocol.account.v1.PrivacyInfo.GameInfoPrivacy game_info_privacy = 6 [default = PRIVACY_FRIENDS];
      case 6: {
        if (tag == 48) {
         parse_game_info_privacy:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::account::v1::PrivacyInfo_GameInfoPrivacy_IsValid(value)) {
            set_game_info_privacy(static_cast< ::bgs::protocol::account::v1::PrivacyInfo_GameInfoPrivacy >(value));
          } else {
            mutable_unknown_fields()->AddVarint(6, value);
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.PrivacyInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.PrivacyInfo)
  return false;
#undef DO_
}

void PrivacyInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.PrivacyInfo)
  // optional bool is_using_rid = 3;
  if (has_is_using_rid()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->is_using_rid(), output);
  }

  // optional bool is_real_id_visible_for_view_friends = 4;
  if (has_is_real_id_visible_for_view_friends()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->is_real_id_visible_for_view_friends(), output);
  }

  // optional bool is_hidden_from_friend_finder = 5;
  if (has_is_hidden_from_friend_finder()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->is_hidden_from_friend_finder(), output);
  }

  // optional .bgs.protocol.account.v1.PrivacyInfo.GameInfoPrivacy game_info_privacy = 6 [default = PRIVACY_FRIENDS];
  if (has_game_info_privacy()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->game_info_privacy(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.PrivacyInfo)
}

::google::protobuf::uint8* PrivacyInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.PrivacyInfo)
  // optional bool is_using_rid = 3;
  if (has_is_using_rid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->is_using_rid(), target);
  }

  // optional bool is_real_id_visible_for_view_friends = 4;
  if (has_is_real_id_visible_for_view_friends()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->is_real_id_visible_for_view_friends(), target);
  }

  // optional bool is_hidden_from_friend_finder = 5;
  if (has_is_hidden_from_friend_finder()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->is_hidden_from_friend_finder(), target);
  }

  // optional .bgs.protocol.account.v1.PrivacyInfo.GameInfoPrivacy game_info_privacy = 6 [default = PRIVACY_FRIENDS];
  if (has_game_info_privacy()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->game_info_privacy(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.PrivacyInfo)
  return target;
}

int PrivacyInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool is_using_rid = 3;
    if (has_is_using_rid()) {
      total_size += 1 + 1;
    }

    // optional bool is_real_id_visible_for_view_friends = 4;
    if (has_is_real_id_visible_for_view_friends()) {
      total_size += 1 + 1;
    }

    // optional bool is_hidden_from_friend_finder = 5;
    if (has_is_hidden_from_friend_finder()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.account.v1.PrivacyInfo.GameInfoPrivacy game_info_privacy = 6 [default = PRIVACY_FRIENDS];
    if (has_game_info_privacy()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->game_info_privacy());
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

void PrivacyInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PrivacyInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PrivacyInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PrivacyInfo::MergeFrom(const PrivacyInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_is_using_rid()) {
      set_is_using_rid(from.is_using_rid());
    }
    if (from.has_is_real_id_visible_for_view_friends()) {
      set_is_real_id_visible_for_view_friends(from.is_real_id_visible_for_view_friends());
    }
    if (from.has_is_hidden_from_friend_finder()) {
      set_is_hidden_from_friend_finder(from.is_hidden_from_friend_finder());
    }
    if (from.has_game_info_privacy()) {
      set_game_info_privacy(from.game_info_privacy());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PrivacyInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PrivacyInfo::CopyFrom(const PrivacyInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PrivacyInfo::IsInitialized() const {

  return true;
}

void PrivacyInfo::Swap(PrivacyInfo* other) {
  if (other != this) {
    std::swap(is_using_rid_, other->is_using_rid_);
    std::swap(is_real_id_visible_for_view_friends_, other->is_real_id_visible_for_view_friends_);
    std::swap(is_hidden_from_friend_finder_, other->is_hidden_from_friend_finder_);
    std::swap(game_info_privacy_, other->game_info_privacy_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PrivacyInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PrivacyInfo_descriptor_;
  metadata.reflection = PrivacyInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ParentalControlInfo::kTimezoneFieldNumber;
const int ParentalControlInfo::kMinutesPerDayFieldNumber;
const int ParentalControlInfo::kMinutesPerWeekFieldNumber;
const int ParentalControlInfo::kCanReceiveVoiceFieldNumber;
const int ParentalControlInfo::kCanSendVoiceFieldNumber;
const int ParentalControlInfo::kPlayScheduleFieldNumber;
#endif  // !_MSC_VER

ParentalControlInfo::ParentalControlInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.ParentalControlInfo)
}

void ParentalControlInfo::InitAsDefaultInstance() {
}

ParentalControlInfo::ParentalControlInfo(const ParentalControlInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.ParentalControlInfo)
}

void ParentalControlInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  timezone_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  minutes_per_day_ = 0u;
  minutes_per_week_ = 0u;
  can_receive_voice_ = false;
  can_send_voice_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ParentalControlInfo::~ParentalControlInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.ParentalControlInfo)
  SharedDtor();
}

void ParentalControlInfo::SharedDtor() {
  if (timezone_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete timezone_;
  }
  if (this != default_instance_) {
  }
}

void ParentalControlInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ParentalControlInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ParentalControlInfo_descriptor_;
}

const ParentalControlInfo& ParentalControlInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

ParentalControlInfo* ParentalControlInfo::default_instance_ = NULL;

ParentalControlInfo* ParentalControlInfo::New() const {
  return new ParentalControlInfo;
}

void ParentalControlInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ParentalControlInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(minutes_per_day_, minutes_per_week_);
    ZR_(can_receive_voice_, can_send_voice_);
    if (has_timezone()) {
      if (timezone_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        timezone_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  play_schedule_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ParentalControlInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.ParentalControlInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string timezone = 3;
      case 3: {
        if (tag == 26) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_timezone()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->timezone().data(), this->timezone().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "timezone");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_minutes_per_day;
        break;
      }

      // optional uint32 minutes_per_day = 4;
      case 4: {
        if (tag == 32) {
         parse_minutes_per_day:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &minutes_per_day_)));
          set_has_minutes_per_day();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_minutes_per_week;
        break;
      }

      // optional uint32 minutes_per_week = 5;
      case 5: {
        if (tag == 40) {
         parse_minutes_per_week:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &minutes_per_week_)));
          set_has_minutes_per_week();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_can_receive_voice;
        break;
      }

      // optional bool can_receive_voice = 6;
      case 6: {
        if (tag == 48) {
         parse_can_receive_voice:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &can_receive_voice_)));
          set_has_can_receive_voice();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_can_send_voice;
        break;
      }

      // optional bool can_send_voice = 7;
      case 7: {
        if (tag == 56) {
         parse_can_send_voice:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &can_send_voice_)));
          set_has_can_send_voice();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_play_schedule;
        break;
      }

      // repeated bool play_schedule = 8;
      case 8: {
        if (tag == 64) {
         parse_play_schedule:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 1, 64, input, this->mutable_play_schedule())));
        } else if (tag == 66) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, this->mutable_play_schedule())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_play_schedule;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.ParentalControlInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.ParentalControlInfo)
  return false;
#undef DO_
}

void ParentalControlInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.ParentalControlInfo)
  // optional string timezone = 3;
  if (has_timezone()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->timezone().data(), this->timezone().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "timezone");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->timezone(), output);
  }

  // optional uint32 minutes_per_day = 4;
  if (has_minutes_per_day()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->minutes_per_day(), output);
  }

  // optional uint32 minutes_per_week = 5;
  if (has_minutes_per_week()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->minutes_per_week(), output);
  }

  // optional bool can_receive_voice = 6;
  if (has_can_receive_voice()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->can_receive_voice(), output);
  }

  // optional bool can_send_voice = 7;
  if (has_can_send_voice()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->can_send_voice(), output);
  }

  // repeated bool play_schedule = 8;
  for (int i = 0; i < this->play_schedule_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(
      8, this->play_schedule(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.ParentalControlInfo)
}

::google::protobuf::uint8* ParentalControlInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.ParentalControlInfo)
  // optional string timezone = 3;
  if (has_timezone()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->timezone().data(), this->timezone().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "timezone");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->timezone(), target);
  }

  // optional uint32 minutes_per_day = 4;
  if (has_minutes_per_day()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->minutes_per_day(), target);
  }

  // optional uint32 minutes_per_week = 5;
  if (has_minutes_per_week()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->minutes_per_week(), target);
  }

  // optional bool can_receive_voice = 6;
  if (has_can_receive_voice()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->can_receive_voice(), target);
  }

  // optional bool can_send_voice = 7;
  if (has_can_send_voice()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->can_send_voice(), target);
  }

  // repeated bool play_schedule = 8;
  for (int i = 0; i < this->play_schedule_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBoolToArray(8, this->play_schedule(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.ParentalControlInfo)
  return target;
}

int ParentalControlInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string timezone = 3;
    if (has_timezone()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->timezone());
    }

    // optional uint32 minutes_per_day = 4;
    if (has_minutes_per_day()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->minutes_per_day());
    }

    // optional uint32 minutes_per_week = 5;
    if (has_minutes_per_week()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->minutes_per_week());
    }

    // optional bool can_receive_voice = 6;
    if (has_can_receive_voice()) {
      total_size += 1 + 1;
    }

    // optional bool can_send_voice = 7;
    if (has_can_send_voice()) {
      total_size += 1 + 1;
    }

  }
  // repeated bool play_schedule = 8;
  {
    int data_size = 0;
    data_size = 1 * this->play_schedule_size();
    total_size += 1 * this->play_schedule_size() + data_size;
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

void ParentalControlInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ParentalControlInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ParentalControlInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ParentalControlInfo::MergeFrom(const ParentalControlInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  play_schedule_.MergeFrom(from.play_schedule_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_timezone()) {
      set_timezone(from.timezone());
    }
    if (from.has_minutes_per_day()) {
      set_minutes_per_day(from.minutes_per_day());
    }
    if (from.has_minutes_per_week()) {
      set_minutes_per_week(from.minutes_per_week());
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

void ParentalControlInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ParentalControlInfo::CopyFrom(const ParentalControlInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ParentalControlInfo::IsInitialized() const {

  return true;
}

void ParentalControlInfo::Swap(ParentalControlInfo* other) {
  if (other != this) {
    std::swap(timezone_, other->timezone_);
    std::swap(minutes_per_day_, other->minutes_per_day_);
    std::swap(minutes_per_week_, other->minutes_per_week_);
    std::swap(can_receive_voice_, other->can_receive_voice_);
    std::swap(can_send_voice_, other->can_send_voice_);
    play_schedule_.Swap(&other->play_schedule_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ParentalControlInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ParentalControlInfo_descriptor_;
  metadata.reflection = ParentalControlInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameLevelInfo::kIsTrialFieldNumber;
const int GameLevelInfo::kIsLifetimeFieldNumber;
const int GameLevelInfo::kIsRestrictedFieldNumber;
const int GameLevelInfo::kIsBetaFieldNumber;
const int GameLevelInfo::kNameFieldNumber;
const int GameLevelInfo::kProgramFieldNumber;
const int GameLevelInfo::kLicensesFieldNumber;
const int GameLevelInfo::kRealmPermissionsFieldNumber;
#endif  // !_MSC_VER

GameLevelInfo::GameLevelInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameLevelInfo)
}

void GameLevelInfo::InitAsDefaultInstance() {
}

GameLevelInfo::GameLevelInfo(const GameLevelInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameLevelInfo)
}

void GameLevelInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  is_trial_ = false;
  is_lifetime_ = false;
  is_restricted_ = false;
  is_beta_ = false;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  program_ = 0u;
  realm_permissions_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameLevelInfo::~GameLevelInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameLevelInfo)
  SharedDtor();
}

void GameLevelInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void GameLevelInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameLevelInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameLevelInfo_descriptor_;
}

const GameLevelInfo& GameLevelInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameLevelInfo* GameLevelInfo::default_instance_ = NULL;

GameLevelInfo* GameLevelInfo::New() const {
  return new GameLevelInfo;
}

void GameLevelInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameLevelInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 191) {
    ZR_(is_trial_, program_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    realm_permissions_ = 0u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  licenses_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameLevelInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameLevelInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool is_trial = 4;
      case 4: {
        if (tag == 32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_trial_)));
          set_has_is_trial();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_is_lifetime;
        break;
      }

      // optional bool is_lifetime = 5;
      case 5: {
        if (tag == 40) {
         parse_is_lifetime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_lifetime_)));
          set_has_is_lifetime();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_is_restricted;
        break;
      }

      // optional bool is_restricted = 6;
      case 6: {
        if (tag == 48) {
         parse_is_restricted:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_restricted_)));
          set_has_is_restricted();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_is_beta;
        break;
      }

      // optional bool is_beta = 7;
      case 7: {
        if (tag == 56) {
         parse_is_beta:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_beta_)));
          set_has_is_beta();
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
        if (input->ExpectTag(77)) goto parse_program;
        break;
      }

      // optional fixed32 program = 9;
      case 9: {
        if (tag == 77) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_licenses;
        break;
      }

      // repeated .bgs.protocol.account.v1.AccountLicense licenses = 10;
      case 10: {
        if (tag == 82) {
         parse_licenses:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_licenses()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_licenses;
        if (input->ExpectTag(88)) goto parse_realm_permissions;
        break;
      }

      // optional uint32 realm_permissions = 11;
      case 11: {
        if (tag == 88) {
         parse_realm_permissions:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &realm_permissions_)));
          set_has_realm_permissions();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameLevelInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameLevelInfo)
  return false;
#undef DO_
}

void GameLevelInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameLevelInfo)
  // optional bool is_trial = 4;
  if (has_is_trial()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->is_trial(), output);
  }

  // optional bool is_lifetime = 5;
  if (has_is_lifetime()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->is_lifetime(), output);
  }

  // optional bool is_restricted = 6;
  if (has_is_restricted()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->is_restricted(), output);
  }

  // optional bool is_beta = 7;
  if (has_is_beta()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->is_beta(), output);
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

  // optional fixed32 program = 9;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(9, this->program(), output);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 10;
  for (int i = 0; i < this->licenses_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->licenses(i), output);
  }

  // optional uint32 realm_permissions = 11;
  if (has_realm_permissions()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->realm_permissions(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameLevelInfo)
}

::google::protobuf::uint8* GameLevelInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameLevelInfo)
  // optional bool is_trial = 4;
  if (has_is_trial()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->is_trial(), target);
  }

  // optional bool is_lifetime = 5;
  if (has_is_lifetime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->is_lifetime(), target);
  }

  // optional bool is_restricted = 6;
  if (has_is_restricted()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->is_restricted(), target);
  }

  // optional bool is_beta = 7;
  if (has_is_beta()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->is_beta(), target);
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

  // optional fixed32 program = 9;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(9, this->program(), target);
  }

  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 10;
  for (int i = 0; i < this->licenses_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->licenses(i), target);
  }

  // optional uint32 realm_permissions = 11;
  if (has_realm_permissions()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->realm_permissions(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameLevelInfo)
  return target;
}

int GameLevelInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool is_trial = 4;
    if (has_is_trial()) {
      total_size += 1 + 1;
    }

    // optional bool is_lifetime = 5;
    if (has_is_lifetime()) {
      total_size += 1 + 1;
    }

    // optional bool is_restricted = 6;
    if (has_is_restricted()) {
      total_size += 1 + 1;
    }

    // optional bool is_beta = 7;
    if (has_is_beta()) {
      total_size += 1 + 1;
    }

    // optional string name = 8;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional fixed32 program = 9;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional uint32 realm_permissions = 11;
    if (has_realm_permissions()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->realm_permissions());
    }

  }
  // repeated .bgs.protocol.account.v1.AccountLicense licenses = 10;
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

void GameLevelInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameLevelInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameLevelInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameLevelInfo::MergeFrom(const GameLevelInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  licenses_.MergeFrom(from.licenses_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_is_trial()) {
      set_is_trial(from.is_trial());
    }
    if (from.has_is_lifetime()) {
      set_is_lifetime(from.is_lifetime());
    }
    if (from.has_is_restricted()) {
      set_is_restricted(from.is_restricted());
    }
    if (from.has_is_beta()) {
      set_is_beta(from.is_beta());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_realm_permissions()) {
      set_realm_permissions(from.realm_permissions());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameLevelInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameLevelInfo::CopyFrom(const GameLevelInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameLevelInfo::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->licenses())) return false;
  return true;
}

void GameLevelInfo::Swap(GameLevelInfo* other) {
  if (other != this) {
    std::swap(is_trial_, other->is_trial_);
    std::swap(is_lifetime_, other->is_lifetime_);
    std::swap(is_restricted_, other->is_restricted_);
    std::swap(is_beta_, other->is_beta_);
    std::swap(name_, other->name_);
    std::swap(program_, other->program_);
    licenses_.Swap(&other->licenses_);
    std::swap(realm_permissions_, other->realm_permissions_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameLevelInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameLevelInfo_descriptor_;
  metadata.reflection = GameLevelInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameTimeInfo::kIsUnlimitedPlayTimeFieldNumber;
const int GameTimeInfo::kPlayTimeExpiresFieldNumber;
const int GameTimeInfo::kIsSubscriptionFieldNumber;
const int GameTimeInfo::kIsRecurringSubscriptionFieldNumber;
#endif  // !_MSC_VER

GameTimeInfo::GameTimeInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameTimeInfo)
}

void GameTimeInfo::InitAsDefaultInstance() {
}

GameTimeInfo::GameTimeInfo(const GameTimeInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameTimeInfo)
}

void GameTimeInfo::SharedCtor() {
  _cached_size_ = 0;
  is_unlimited_play_time_ = false;
  play_time_expires_ = GOOGLE_ULONGLONG(0);
  is_subscription_ = false;
  is_recurring_subscription_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameTimeInfo::~GameTimeInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameTimeInfo)
  SharedDtor();
}

void GameTimeInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameTimeInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameTimeInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameTimeInfo_descriptor_;
}

const GameTimeInfo& GameTimeInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameTimeInfo* GameTimeInfo::default_instance_ = NULL;

GameTimeInfo* GameTimeInfo::New() const {
  return new GameTimeInfo;
}

void GameTimeInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameTimeInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(play_time_expires_, is_recurring_subscription_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameTimeInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameTimeInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool is_unlimited_play_time = 3;
      case 3: {
        if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_unlimited_play_time_)));
          set_has_is_unlimited_play_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_play_time_expires;
        break;
      }

      // optional uint64 play_time_expires = 5;
      case 5: {
        if (tag == 40) {
         parse_play_time_expires:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &play_time_expires_)));
          set_has_play_time_expires();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_is_subscription;
        break;
      }

      // optional bool is_subscription = 6;
      case 6: {
        if (tag == 48) {
         parse_is_subscription:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_subscription_)));
          set_has_is_subscription();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_is_recurring_subscription;
        break;
      }

      // optional bool is_recurring_subscription = 7;
      case 7: {
        if (tag == 56) {
         parse_is_recurring_subscription:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_recurring_subscription_)));
          set_has_is_recurring_subscription();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameTimeInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameTimeInfo)
  return false;
#undef DO_
}

void GameTimeInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameTimeInfo)
  // optional bool is_unlimited_play_time = 3;
  if (has_is_unlimited_play_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->is_unlimited_play_time(), output);
  }

  // optional uint64 play_time_expires = 5;
  if (has_play_time_expires()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->play_time_expires(), output);
  }

  // optional bool is_subscription = 6;
  if (has_is_subscription()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->is_subscription(), output);
  }

  // optional bool is_recurring_subscription = 7;
  if (has_is_recurring_subscription()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->is_recurring_subscription(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameTimeInfo)
}

::google::protobuf::uint8* GameTimeInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameTimeInfo)
  // optional bool is_unlimited_play_time = 3;
  if (has_is_unlimited_play_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->is_unlimited_play_time(), target);
  }

  // optional uint64 play_time_expires = 5;
  if (has_play_time_expires()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->play_time_expires(), target);
  }

  // optional bool is_subscription = 6;
  if (has_is_subscription()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->is_subscription(), target);
  }

  // optional bool is_recurring_subscription = 7;
  if (has_is_recurring_subscription()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->is_recurring_subscription(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameTimeInfo)
  return target;
}

int GameTimeInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool is_unlimited_play_time = 3;
    if (has_is_unlimited_play_time()) {
      total_size += 1 + 1;
    }

    // optional uint64 play_time_expires = 5;
    if (has_play_time_expires()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->play_time_expires());
    }

    // optional bool is_subscription = 6;
    if (has_is_subscription()) {
      total_size += 1 + 1;
    }

    // optional bool is_recurring_subscription = 7;
    if (has_is_recurring_subscription()) {
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

void GameTimeInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameTimeInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameTimeInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameTimeInfo::MergeFrom(const GameTimeInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_is_unlimited_play_time()) {
      set_is_unlimited_play_time(from.is_unlimited_play_time());
    }
    if (from.has_play_time_expires()) {
      set_play_time_expires(from.play_time_expires());
    }
    if (from.has_is_subscription()) {
      set_is_subscription(from.is_subscription());
    }
    if (from.has_is_recurring_subscription()) {
      set_is_recurring_subscription(from.is_recurring_subscription());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameTimeInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameTimeInfo::CopyFrom(const GameTimeInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameTimeInfo::IsInitialized() const {

  return true;
}

void GameTimeInfo::Swap(GameTimeInfo* other) {
  if (other != this) {
    std::swap(is_unlimited_play_time_, other->is_unlimited_play_time_);
    std::swap(play_time_expires_, other->play_time_expires_);
    std::swap(is_subscription_, other->is_subscription_);
    std::swap(is_recurring_subscription_, other->is_recurring_subscription_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameTimeInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameTimeInfo_descriptor_;
  metadata.reflection = GameTimeInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameTimeRemainingInfo::kMinutesRemainingFieldNumber;
const int GameTimeRemainingInfo::kParentalDailyMinutesRemainingFieldNumber;
const int GameTimeRemainingInfo::kParentalWeeklyMinutesRemainingFieldNumber;
const int GameTimeRemainingInfo::kSecondsRemainingUntilKickFieldNumber;
#endif  // !_MSC_VER

GameTimeRemainingInfo::GameTimeRemainingInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameTimeRemainingInfo)
}

void GameTimeRemainingInfo::InitAsDefaultInstance() {
}

GameTimeRemainingInfo::GameTimeRemainingInfo(const GameTimeRemainingInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameTimeRemainingInfo)
}

void GameTimeRemainingInfo::SharedCtor() {
  _cached_size_ = 0;
  minutes_remaining_ = 0u;
  parental_daily_minutes_remaining_ = 0u;
  parental_weekly_minutes_remaining_ = 0u;
  seconds_remaining_until_kick_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameTimeRemainingInfo::~GameTimeRemainingInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameTimeRemainingInfo)
  SharedDtor();
}

void GameTimeRemainingInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameTimeRemainingInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameTimeRemainingInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameTimeRemainingInfo_descriptor_;
}

const GameTimeRemainingInfo& GameTimeRemainingInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameTimeRemainingInfo* GameTimeRemainingInfo::default_instance_ = NULL;

GameTimeRemainingInfo* GameTimeRemainingInfo::New() const {
  return new GameTimeRemainingInfo;
}

void GameTimeRemainingInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameTimeRemainingInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(minutes_remaining_, seconds_remaining_until_kick_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameTimeRemainingInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameTimeRemainingInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 minutes_remaining = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &minutes_remaining_)));
          set_has_minutes_remaining();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_parental_daily_minutes_remaining;
        break;
      }

      // optional uint32 parental_daily_minutes_remaining = 2;
      case 2: {
        if (tag == 16) {
         parse_parental_daily_minutes_remaining:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &parental_daily_minutes_remaining_)));
          set_has_parental_daily_minutes_remaining();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_parental_weekly_minutes_remaining;
        break;
      }

      // optional uint32 parental_weekly_minutes_remaining = 3;
      case 3: {
        if (tag == 24) {
         parse_parental_weekly_minutes_remaining:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &parental_weekly_minutes_remaining_)));
          set_has_parental_weekly_minutes_remaining();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_seconds_remaining_until_kick;
        break;
      }

      // optional uint32 seconds_remaining_until_kick = 4;
      case 4: {
        if (tag == 32) {
         parse_seconds_remaining_until_kick:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &seconds_remaining_until_kick_)));
          set_has_seconds_remaining_until_kick();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameTimeRemainingInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameTimeRemainingInfo)
  return false;
#undef DO_
}

void GameTimeRemainingInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameTimeRemainingInfo)
  // optional uint32 minutes_remaining = 1;
  if (has_minutes_remaining()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->minutes_remaining(), output);
  }

  // optional uint32 parental_daily_minutes_remaining = 2;
  if (has_parental_daily_minutes_remaining()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->parental_daily_minutes_remaining(), output);
  }

  // optional uint32 parental_weekly_minutes_remaining = 3;
  if (has_parental_weekly_minutes_remaining()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->parental_weekly_minutes_remaining(), output);
  }

  // optional uint32 seconds_remaining_until_kick = 4;
  if (has_seconds_remaining_until_kick()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->seconds_remaining_until_kick(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameTimeRemainingInfo)
}

::google::protobuf::uint8* GameTimeRemainingInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameTimeRemainingInfo)
  // optional uint32 minutes_remaining = 1;
  if (has_minutes_remaining()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->minutes_remaining(), target);
  }

  // optional uint32 parental_daily_minutes_remaining = 2;
  if (has_parental_daily_minutes_remaining()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->parental_daily_minutes_remaining(), target);
  }

  // optional uint32 parental_weekly_minutes_remaining = 3;
  if (has_parental_weekly_minutes_remaining()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->parental_weekly_minutes_remaining(), target);
  }

  // optional uint32 seconds_remaining_until_kick = 4;
  if (has_seconds_remaining_until_kick()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->seconds_remaining_until_kick(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameTimeRemainingInfo)
  return target;
}

int GameTimeRemainingInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 minutes_remaining = 1;
    if (has_minutes_remaining()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->minutes_remaining());
    }

    // optional uint32 parental_daily_minutes_remaining = 2;
    if (has_parental_daily_minutes_remaining()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->parental_daily_minutes_remaining());
    }

    // optional uint32 parental_weekly_minutes_remaining = 3;
    if (has_parental_weekly_minutes_remaining()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->parental_weekly_minutes_remaining());
    }

    // optional uint32 seconds_remaining_until_kick = 4;
    if (has_seconds_remaining_until_kick()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->seconds_remaining_until_kick());
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

void GameTimeRemainingInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameTimeRemainingInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameTimeRemainingInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameTimeRemainingInfo::MergeFrom(const GameTimeRemainingInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_minutes_remaining()) {
      set_minutes_remaining(from.minutes_remaining());
    }
    if (from.has_parental_daily_minutes_remaining()) {
      set_parental_daily_minutes_remaining(from.parental_daily_minutes_remaining());
    }
    if (from.has_parental_weekly_minutes_remaining()) {
      set_parental_weekly_minutes_remaining(from.parental_weekly_minutes_remaining());
    }
    if (from.has_seconds_remaining_until_kick()) {
      set_seconds_remaining_until_kick(from.seconds_remaining_until_kick());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameTimeRemainingInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameTimeRemainingInfo::CopyFrom(const GameTimeRemainingInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameTimeRemainingInfo::IsInitialized() const {

  return true;
}

void GameTimeRemainingInfo::Swap(GameTimeRemainingInfo* other) {
  if (other != this) {
    std::swap(minutes_remaining_, other->minutes_remaining_);
    std::swap(parental_daily_minutes_remaining_, other->parental_daily_minutes_remaining_);
    std::swap(parental_weekly_minutes_remaining_, other->parental_weekly_minutes_remaining_);
    std::swap(seconds_remaining_until_kick_, other->seconds_remaining_until_kick_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameTimeRemainingInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameTimeRemainingInfo_descriptor_;
  metadata.reflection = GameTimeRemainingInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameStatus::kIsSuspendedFieldNumber;
const int GameStatus::kIsBannedFieldNumber;
const int GameStatus::kSuspensionExpiresFieldNumber;
const int GameStatus::kProgramFieldNumber;
const int GameStatus::kIsLockedFieldNumber;
const int GameStatus::kIsBamUnlockableFieldNumber;
#endif  // !_MSC_VER

GameStatus::GameStatus()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameStatus)
}

void GameStatus::InitAsDefaultInstance() {
}

GameStatus::GameStatus(const GameStatus& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameStatus)
}

void GameStatus::SharedCtor() {
  _cached_size_ = 0;
  is_suspended_ = false;
  is_banned_ = false;
  suspension_expires_ = GOOGLE_ULONGLONG(0);
  program_ = 0u;
  is_locked_ = false;
  is_bam_unlockable_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameStatus::~GameStatus() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameStatus)
  SharedDtor();
}

void GameStatus::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameStatus::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameStatus::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameStatus_descriptor_;
}

const GameStatus& GameStatus::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameStatus* GameStatus::default_instance_ = NULL;

GameStatus* GameStatus::New() const {
  return new GameStatus;
}

void GameStatus::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameStatus*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(suspension_expires_, program_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameStatus::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameStatus)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool is_suspended = 4;
      case 4: {
        if (tag == 32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_suspended_)));
          set_has_is_suspended();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_is_banned;
        break;
      }

      // optional bool is_banned = 5;
      case 5: {
        if (tag == 40) {
         parse_is_banned:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_banned_)));
          set_has_is_banned();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_suspension_expires;
        break;
      }

      // optional uint64 suspension_expires = 6;
      case 6: {
        if (tag == 48) {
         parse_suspension_expires:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &suspension_expires_)));
          set_has_suspension_expires();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(61)) goto parse_program;
        break;
      }

      // optional fixed32 program = 7;
      case 7: {
        if (tag == 61) {
         parse_program:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &program_)));
          set_has_program();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_is_locked;
        break;
      }

      // optional bool is_locked = 8;
      case 8: {
        if (tag == 64) {
         parse_is_locked:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_locked_)));
          set_has_is_locked();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_is_bam_unlockable;
        break;
      }

      // optional bool is_bam_unlockable = 9;
      case 9: {
        if (tag == 72) {
         parse_is_bam_unlockable:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_bam_unlockable_)));
          set_has_is_bam_unlockable();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameStatus)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameStatus)
  return false;
#undef DO_
}

void GameStatus::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameStatus)
  // optional bool is_suspended = 4;
  if (has_is_suspended()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->is_suspended(), output);
  }

  // optional bool is_banned = 5;
  if (has_is_banned()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->is_banned(), output);
  }

  // optional uint64 suspension_expires = 6;
  if (has_suspension_expires()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(6, this->suspension_expires(), output);
  }

  // optional fixed32 program = 7;
  if (has_program()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(7, this->program(), output);
  }

  // optional bool is_locked = 8;
  if (has_is_locked()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->is_locked(), output);
  }

  // optional bool is_bam_unlockable = 9;
  if (has_is_bam_unlockable()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->is_bam_unlockable(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameStatus)
}

::google::protobuf::uint8* GameStatus::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameStatus)
  // optional bool is_suspended = 4;
  if (has_is_suspended()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->is_suspended(), target);
  }

  // optional bool is_banned = 5;
  if (has_is_banned()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->is_banned(), target);
  }

  // optional uint64 suspension_expires = 6;
  if (has_suspension_expires()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(6, this->suspension_expires(), target);
  }

  // optional fixed32 program = 7;
  if (has_program()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(7, this->program(), target);
  }

  // optional bool is_locked = 8;
  if (has_is_locked()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->is_locked(), target);
  }

  // optional bool is_bam_unlockable = 9;
  if (has_is_bam_unlockable()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->is_bam_unlockable(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameStatus)
  return target;
}

int GameStatus::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool is_suspended = 4;
    if (has_is_suspended()) {
      total_size += 1 + 1;
    }

    // optional bool is_banned = 5;
    if (has_is_banned()) {
      total_size += 1 + 1;
    }

    // optional uint64 suspension_expires = 6;
    if (has_suspension_expires()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->suspension_expires());
    }

    // optional fixed32 program = 7;
    if (has_program()) {
      total_size += 1 + 4;
    }

    // optional bool is_locked = 8;
    if (has_is_locked()) {
      total_size += 1 + 1;
    }

    // optional bool is_bam_unlockable = 9;
    if (has_is_bam_unlockable()) {
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

void GameStatus::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameStatus* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameStatus*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameStatus::MergeFrom(const GameStatus& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_is_suspended()) {
      set_is_suspended(from.is_suspended());
    }
    if (from.has_is_banned()) {
      set_is_banned(from.is_banned());
    }
    if (from.has_suspension_expires()) {
      set_suspension_expires(from.suspension_expires());
    }
    if (from.has_program()) {
      set_program(from.program());
    }
    if (from.has_is_locked()) {
      set_is_locked(from.is_locked());
    }
    if (from.has_is_bam_unlockable()) {
      set_is_bam_unlockable(from.is_bam_unlockable());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameStatus::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameStatus::CopyFrom(const GameStatus& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameStatus::IsInitialized() const {

  return true;
}

void GameStatus::Swap(GameStatus* other) {
  if (other != this) {
    std::swap(is_suspended_, other->is_suspended_);
    std::swap(is_banned_, other->is_banned_);
    std::swap(suspension_expires_, other->suspension_expires_);
    std::swap(program_, other->program_);
    std::swap(is_locked_, other->is_locked_);
    std::swap(is_bam_unlockable_, other->is_bam_unlockable_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameStatus::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameStatus_descriptor_;
  metadata.reflection = GameStatus_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RAFInfo::kRafInfoFieldNumber;
#endif  // !_MSC_VER

RAFInfo::RAFInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.RAFInfo)
}

void RAFInfo::InitAsDefaultInstance() {
}

RAFInfo::RAFInfo(const RAFInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.RAFInfo)
}

void RAFInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  raf_info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RAFInfo::~RAFInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.RAFInfo)
  SharedDtor();
}

void RAFInfo::SharedDtor() {
  if (raf_info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete raf_info_;
  }
  if (this != default_instance_) {
  }
}

void RAFInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RAFInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RAFInfo_descriptor_;
}

const RAFInfo& RAFInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

RAFInfo* RAFInfo::default_instance_ = NULL;

RAFInfo* RAFInfo::New() const {
  return new RAFInfo;
}

void RAFInfo::Clear() {
  if (has_raf_info()) {
    if (raf_info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      raf_info_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RAFInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.RAFInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes raf_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_raf_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.RAFInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.RAFInfo)
  return false;
#undef DO_
}

void RAFInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.RAFInfo)
  // optional bytes raf_info = 1;
  if (has_raf_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->raf_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.RAFInfo)
}

::google::protobuf::uint8* RAFInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.RAFInfo)
  // optional bytes raf_info = 1;
  if (has_raf_info()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->raf_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.RAFInfo)
  return target;
}

int RAFInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes raf_info = 1;
    if (has_raf_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->raf_info());
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

void RAFInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RAFInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RAFInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RAFInfo::MergeFrom(const RAFInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_raf_info()) {
      set_raf_info(from.raf_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RAFInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RAFInfo::CopyFrom(const RAFInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RAFInfo::IsInitialized() const {

  return true;
}

void RAFInfo::Swap(RAFInfo* other) {
  if (other != this) {
    std::swap(raf_info_, other->raf_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RAFInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RAFInfo_descriptor_;
  metadata.reflection = RAFInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameSessionInfo::kStartTimeFieldNumber;
const int GameSessionInfo::kLocationFieldNumber;
const int GameSessionInfo::kHasBenefactorFieldNumber;
const int GameSessionInfo::kIsUsingIgrFieldNumber;
const int GameSessionInfo::kParentalControlsActiveFieldNumber;
const int GameSessionInfo::kStartTimeSecFieldNumber;
const int GameSessionInfo::kIgrIdFieldNumber;
#endif  // !_MSC_VER

GameSessionInfo::GameSessionInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameSessionInfo)
}

void GameSessionInfo::InitAsDefaultInstance() {
  location_ = const_cast< ::bgs::protocol::account::v1::GameSessionLocation*>(&::bgs::protocol::account::v1::GameSessionLocation::default_instance());
  igr_id_ = const_cast< ::bgs::protocol::account::v1::IgrId*>(&::bgs::protocol::account::v1::IgrId::default_instance());
}

GameSessionInfo::GameSessionInfo(const GameSessionInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameSessionInfo)
}

void GameSessionInfo::SharedCtor() {
  _cached_size_ = 0;
  start_time_ = 0u;
  location_ = NULL;
  has_benefactor_ = false;
  is_using_igr_ = false;
  parental_controls_active_ = false;
  start_time_sec_ = GOOGLE_ULONGLONG(0);
  igr_id_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameSessionInfo::~GameSessionInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameSessionInfo)
  SharedDtor();
}

void GameSessionInfo::SharedDtor() {
  if (this != default_instance_) {
    delete location_;
    delete igr_id_;
  }
}

void GameSessionInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameSessionInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameSessionInfo_descriptor_;
}

const GameSessionInfo& GameSessionInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameSessionInfo* GameSessionInfo::default_instance_ = NULL;

GameSessionInfo* GameSessionInfo::New() const {
  return new GameSessionInfo;
}

void GameSessionInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameSessionInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 127) {
    ZR_(start_time_, start_time_sec_);
    if (has_location()) {
      if (location_ != NULL) location_->::bgs::protocol::account::v1::GameSessionLocation::Clear();
    }
    if (has_igr_id()) {
      if (igr_id_ != NULL) igr_id_->::bgs::protocol::account::v1::IgrId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameSessionInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameSessionInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 start_time = 3 [deprecated = true];
      case 3: {
        if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &start_time_)));
          set_has_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_location;
        break;
      }

      // optional .bgs.protocol.account.v1.GameSessionLocation location = 4;
      case 4: {
        if (tag == 34) {
         parse_location:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_location()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_has_benefactor;
        break;
      }

      // optional bool has_benefactor = 5;
      case 5: {
        if (tag == 40) {
         parse_has_benefactor:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &has_benefactor_)));
          set_has_has_benefactor();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_is_using_igr;
        break;
      }

      // optional bool is_using_igr = 6;
      case 6: {
        if (tag == 48) {
         parse_is_using_igr:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_using_igr_)));
          set_has_is_using_igr();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_parental_controls_active;
        break;
      }

      // optional bool parental_controls_active = 7;
      case 7: {
        if (tag == 56) {
         parse_parental_controls_active:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &parental_controls_active_)));
          set_has_parental_controls_active();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_start_time_sec;
        break;
      }

      // optional uint64 start_time_sec = 8;
      case 8: {
        if (tag == 64) {
         parse_start_time_sec:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &start_time_sec_)));
          set_has_start_time_sec();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_igr_id;
        break;
      }

      // optional .bgs.protocol.account.v1.IgrId igr_id = 9;
      case 9: {
        if (tag == 74) {
         parse_igr_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_igr_id()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameSessionInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameSessionInfo)
  return false;
#undef DO_
}

void GameSessionInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameSessionInfo)
  // optional uint32 start_time = 3 [deprecated = true];
  if (has_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->start_time(), output);
  }

  // optional .bgs.protocol.account.v1.GameSessionLocation location = 4;
  if (has_location()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->location(), output);
  }

  // optional bool has_benefactor = 5;
  if (has_has_benefactor()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->has_benefactor(), output);
  }

  // optional bool is_using_igr = 6;
  if (has_is_using_igr()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->is_using_igr(), output);
  }

  // optional bool parental_controls_active = 7;
  if (has_parental_controls_active()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->parental_controls_active(), output);
  }

  // optional uint64 start_time_sec = 8;
  if (has_start_time_sec()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(8, this->start_time_sec(), output);
  }

  // optional .bgs.protocol.account.v1.IgrId igr_id = 9;
  if (has_igr_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->igr_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameSessionInfo)
}

::google::protobuf::uint8* GameSessionInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameSessionInfo)
  // optional uint32 start_time = 3 [deprecated = true];
  if (has_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->start_time(), target);
  }

  // optional .bgs.protocol.account.v1.GameSessionLocation location = 4;
  if (has_location()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->location(), target);
  }

  // optional bool has_benefactor = 5;
  if (has_has_benefactor()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->has_benefactor(), target);
  }

  // optional bool is_using_igr = 6;
  if (has_is_using_igr()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->is_using_igr(), target);
  }

  // optional bool parental_controls_active = 7;
  if (has_parental_controls_active()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->parental_controls_active(), target);
  }

  // optional uint64 start_time_sec = 8;
  if (has_start_time_sec()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(8, this->start_time_sec(), target);
  }

  // optional .bgs.protocol.account.v1.IgrId igr_id = 9;
  if (has_igr_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->igr_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameSessionInfo)
  return target;
}

int GameSessionInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 start_time = 3 [deprecated = true];
    if (has_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->start_time());
    }

    // optional .bgs.protocol.account.v1.GameSessionLocation location = 4;
    if (has_location()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->location());
    }

    // optional bool has_benefactor = 5;
    if (has_has_benefactor()) {
      total_size += 1 + 1;
    }

    // optional bool is_using_igr = 6;
    if (has_is_using_igr()) {
      total_size += 1 + 1;
    }

    // optional bool parental_controls_active = 7;
    if (has_parental_controls_active()) {
      total_size += 1 + 1;
    }

    // optional uint64 start_time_sec = 8;
    if (has_start_time_sec()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->start_time_sec());
    }

    // optional .bgs.protocol.account.v1.IgrId igr_id = 9;
    if (has_igr_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->igr_id());
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

void GameSessionInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameSessionInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameSessionInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameSessionInfo::MergeFrom(const GameSessionInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_start_time()) {
      set_start_time(from.start_time());
    }
    if (from.has_location()) {
      mutable_location()->::bgs::protocol::account::v1::GameSessionLocation::MergeFrom(from.location());
    }
    if (from.has_has_benefactor()) {
      set_has_benefactor(from.has_benefactor());
    }
    if (from.has_is_using_igr()) {
      set_is_using_igr(from.is_using_igr());
    }
    if (from.has_parental_controls_active()) {
      set_parental_controls_active(from.parental_controls_active());
    }
    if (from.has_start_time_sec()) {
      set_start_time_sec(from.start_time_sec());
    }
    if (from.has_igr_id()) {
      mutable_igr_id()->::bgs::protocol::account::v1::IgrId::MergeFrom(from.igr_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameSessionInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameSessionInfo::CopyFrom(const GameSessionInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameSessionInfo::IsInitialized() const {

  if (has_igr_id()) {
    if (!this->igr_id().IsInitialized()) return false;
  }
  return true;
}

void GameSessionInfo::Swap(GameSessionInfo* other) {
  if (other != this) {
    std::swap(start_time_, other->start_time_);
    std::swap(location_, other->location_);
    std::swap(has_benefactor_, other->has_benefactor_);
    std::swap(is_using_igr_, other->is_using_igr_);
    std::swap(parental_controls_active_, other->parental_controls_active_);
    std::swap(start_time_sec_, other->start_time_sec_);
    std::swap(igr_id_, other->igr_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameSessionInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameSessionInfo_descriptor_;
  metadata.reflection = GameSessionInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameSessionUpdateInfo::kCaisFieldNumber;
#endif  // !_MSC_VER

GameSessionUpdateInfo::GameSessionUpdateInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameSessionUpdateInfo)
}

void GameSessionUpdateInfo::InitAsDefaultInstance() {
  cais_ = const_cast< ::bgs::protocol::account::v1::CAIS*>(&::bgs::protocol::account::v1::CAIS::default_instance());
}

GameSessionUpdateInfo::GameSessionUpdateInfo(const GameSessionUpdateInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameSessionUpdateInfo)
}

void GameSessionUpdateInfo::SharedCtor() {
  _cached_size_ = 0;
  cais_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameSessionUpdateInfo::~GameSessionUpdateInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameSessionUpdateInfo)
  SharedDtor();
}

void GameSessionUpdateInfo::SharedDtor() {
  if (this != default_instance_) {
    delete cais_;
  }
}

void GameSessionUpdateInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameSessionUpdateInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameSessionUpdateInfo_descriptor_;
}

const GameSessionUpdateInfo& GameSessionUpdateInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameSessionUpdateInfo* GameSessionUpdateInfo::default_instance_ = NULL;

GameSessionUpdateInfo* GameSessionUpdateInfo::New() const {
  return new GameSessionUpdateInfo;
}

void GameSessionUpdateInfo::Clear() {
  if (has_cais()) {
    if (cais_ != NULL) cais_->::bgs::protocol::account::v1::CAIS::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameSessionUpdateInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameSessionUpdateInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.CAIS cais = 8;
      case 8: {
        if (tag == 66) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_cais()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameSessionUpdateInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameSessionUpdateInfo)
  return false;
#undef DO_
}

void GameSessionUpdateInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameSessionUpdateInfo)
  // optional .bgs.protocol.account.v1.CAIS cais = 8;
  if (has_cais()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->cais(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameSessionUpdateInfo)
}

::google::protobuf::uint8* GameSessionUpdateInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameSessionUpdateInfo)
  // optional .bgs.protocol.account.v1.CAIS cais = 8;
  if (has_cais()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->cais(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameSessionUpdateInfo)
  return target;
}

int GameSessionUpdateInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.CAIS cais = 8;
    if (has_cais()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->cais());
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

void GameSessionUpdateInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameSessionUpdateInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameSessionUpdateInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameSessionUpdateInfo::MergeFrom(const GameSessionUpdateInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_cais()) {
      mutable_cais()->::bgs::protocol::account::v1::CAIS::MergeFrom(from.cais());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameSessionUpdateInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameSessionUpdateInfo::CopyFrom(const GameSessionUpdateInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameSessionUpdateInfo::IsInitialized() const {

  return true;
}

void GameSessionUpdateInfo::Swap(GameSessionUpdateInfo* other) {
  if (other != this) {
    std::swap(cais_, other->cais_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameSessionUpdateInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameSessionUpdateInfo_descriptor_;
  metadata.reflection = GameSessionUpdateInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameSessionLocation::kIpAddressFieldNumber;
const int GameSessionLocation::kCountryFieldNumber;
const int GameSessionLocation::kCityFieldNumber;
#endif  // !_MSC_VER

GameSessionLocation::GameSessionLocation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameSessionLocation)
}

void GameSessionLocation::InitAsDefaultInstance() {
}

GameSessionLocation::GameSessionLocation(const GameSessionLocation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameSessionLocation)
}

void GameSessionLocation::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  ip_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  country_ = 0u;
  city_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameSessionLocation::~GameSessionLocation() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameSessionLocation)
  SharedDtor();
}

void GameSessionLocation::SharedDtor() {
  if (ip_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete ip_address_;
  }
  if (city_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete city_;
  }
  if (this != default_instance_) {
  }
}

void GameSessionLocation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameSessionLocation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameSessionLocation_descriptor_;
}

const GameSessionLocation& GameSessionLocation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameSessionLocation* GameSessionLocation::default_instance_ = NULL;

GameSessionLocation* GameSessionLocation::New() const {
  return new GameSessionLocation;
}

void GameSessionLocation::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_ip_address()) {
      if (ip_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        ip_address_->clear();
      }
    }
    country_ = 0u;
    if (has_city()) {
      if (city_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        city_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameSessionLocation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameSessionLocation)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string ip_address = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ip_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->ip_address().data(), this->ip_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "ip_address");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_country;
        break;
      }

      // optional uint32 country = 2;
      case 2: {
        if (tag == 16) {
         parse_country:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &country_)));
          set_has_country();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_city;
        break;
      }

      // optional string city = 3;
      case 3: {
        if (tag == 26) {
         parse_city:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_city()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->city().data(), this->city().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "city");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameSessionLocation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameSessionLocation)
  return false;
#undef DO_
}

void GameSessionLocation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameSessionLocation)
  // optional string ip_address = 1;
  if (has_ip_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ip_address().data(), this->ip_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ip_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->ip_address(), output);
  }

  // optional uint32 country = 2;
  if (has_country()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->country(), output);
  }

  // optional string city = 3;
  if (has_city()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->city().data(), this->city().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "city");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->city(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameSessionLocation)
}

::google::protobuf::uint8* GameSessionLocation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameSessionLocation)
  // optional string ip_address = 1;
  if (has_ip_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ip_address().data(), this->ip_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ip_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->ip_address(), target);
  }

  // optional uint32 country = 2;
  if (has_country()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->country(), target);
  }

  // optional string city = 3;
  if (has_city()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->city().data(), this->city().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "city");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->city(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameSessionLocation)
  return target;
}

int GameSessionLocation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string ip_address = 1;
    if (has_ip_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->ip_address());
    }

    // optional uint32 country = 2;
    if (has_country()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->country());
    }

    // optional string city = 3;
    if (has_city()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->city());
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

void GameSessionLocation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameSessionLocation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameSessionLocation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameSessionLocation::MergeFrom(const GameSessionLocation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_ip_address()) {
      set_ip_address(from.ip_address());
    }
    if (from.has_country()) {
      set_country(from.country());
    }
    if (from.has_city()) {
      set_city(from.city());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameSessionLocation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameSessionLocation::CopyFrom(const GameSessionLocation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameSessionLocation::IsInitialized() const {

  return true;
}

void GameSessionLocation::Swap(GameSessionLocation* other) {
  if (other != this) {
    std::swap(ip_address_, other->ip_address_);
    std::swap(country_, other->country_);
    std::swap(city_, other->city_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameSessionLocation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameSessionLocation_descriptor_;
  metadata.reflection = GameSessionLocation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CAIS::kPlayedMinutesFieldNumber;
const int CAIS::kRestedMinutesFieldNumber;
const int CAIS::kLastHeardTimeFieldNumber;
#endif  // !_MSC_VER

CAIS::CAIS()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.CAIS)
}

void CAIS::InitAsDefaultInstance() {
}

CAIS::CAIS(const CAIS& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.CAIS)
}

void CAIS::SharedCtor() {
  _cached_size_ = 0;
  played_minutes_ = 0u;
  rested_minutes_ = 0u;
  last_heard_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CAIS::~CAIS() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.CAIS)
  SharedDtor();
}

void CAIS::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CAIS::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CAIS::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CAIS_descriptor_;
}

const CAIS& CAIS::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

CAIS* CAIS::default_instance_ = NULL;

CAIS* CAIS::New() const {
  return new CAIS;
}

void CAIS::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<CAIS*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(played_minutes_, last_heard_time_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CAIS::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.CAIS)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 played_minutes = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &played_minutes_)));
          set_has_played_minutes();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_rested_minutes;
        break;
      }

      // optional uint32 rested_minutes = 2;
      case 2: {
        if (tag == 16) {
         parse_rested_minutes:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &rested_minutes_)));
          set_has_rested_minutes();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_last_heard_time;
        break;
      }

      // optional uint64 last_heard_time = 3;
      case 3: {
        if (tag == 24) {
         parse_last_heard_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &last_heard_time_)));
          set_has_last_heard_time();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.CAIS)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.CAIS)
  return false;
#undef DO_
}

void CAIS::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.CAIS)
  // optional uint32 played_minutes = 1;
  if (has_played_minutes()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->played_minutes(), output);
  }

  // optional uint32 rested_minutes = 2;
  if (has_rested_minutes()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->rested_minutes(), output);
  }

  // optional uint64 last_heard_time = 3;
  if (has_last_heard_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->last_heard_time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.CAIS)
}

::google::protobuf::uint8* CAIS::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.CAIS)
  // optional uint32 played_minutes = 1;
  if (has_played_minutes()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->played_minutes(), target);
  }

  // optional uint32 rested_minutes = 2;
  if (has_rested_minutes()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->rested_minutes(), target);
  }

  // optional uint64 last_heard_time = 3;
  if (has_last_heard_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->last_heard_time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.CAIS)
  return target;
}

int CAIS::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 played_minutes = 1;
    if (has_played_minutes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->played_minutes());
    }

    // optional uint32 rested_minutes = 2;
    if (has_rested_minutes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->rested_minutes());
    }

    // optional uint64 last_heard_time = 3;
    if (has_last_heard_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->last_heard_time());
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

void CAIS::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CAIS* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CAIS*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CAIS::MergeFrom(const CAIS& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_played_minutes()) {
      set_played_minutes(from.played_minutes());
    }
    if (from.has_rested_minutes()) {
      set_rested_minutes(from.rested_minutes());
    }
    if (from.has_last_heard_time()) {
      set_last_heard_time(from.last_heard_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CAIS::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CAIS::CopyFrom(const CAIS& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CAIS::IsInitialized() const {

  return true;
}

void CAIS::Swap(CAIS* other) {
  if (other != this) {
    std::swap(played_minutes_, other->played_minutes_);
    std::swap(rested_minutes_, other->rested_minutes_);
    std::swap(last_heard_time_, other->last_heard_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CAIS::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CAIS_descriptor_;
  metadata.reflection = CAIS_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountList::kRegionFieldNumber;
const int GameAccountList::kHandleFieldNumber;
#endif  // !_MSC_VER

GameAccountList::GameAccountList()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountList)
}

void GameAccountList::InitAsDefaultInstance() {
}

GameAccountList::GameAccountList(const GameAccountList& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountList)
}

void GameAccountList::SharedCtor() {
  _cached_size_ = 0;
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountList::~GameAccountList() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountList)
  SharedDtor();
}

void GameAccountList::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameAccountList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountList::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountList_descriptor_;
}

const GameAccountList& GameAccountList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountList* GameAccountList::default_instance_ = NULL;

GameAccountList* GameAccountList::New() const {
  return new GameAccountList;
}

void GameAccountList::Clear() {
  region_ = 0u;
  handle_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountList)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 region = 3;
      case 3: {
        if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_handle;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameAccountHandle handle = 4;
      case 4: {
        if (tag == 34) {
         parse_handle:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_handle;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountList)
  return false;
#undef DO_
}

void GameAccountList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountList)
  // optional uint32 region = 3;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->region(), output);
  }

  // repeated .bgs.protocol.account.v1.GameAccountHandle handle = 4;
  for (int i = 0; i < this->handle_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->handle(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountList)
}

::google::protobuf::uint8* GameAccountList::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountList)
  // optional uint32 region = 3;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->region(), target);
  }

  // repeated .bgs.protocol.account.v1.GameAccountHandle handle = 4;
  for (int i = 0; i < this->handle_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->handle(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountList)
  return target;
}

int GameAccountList::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 region = 3;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

  }
  // repeated .bgs.protocol.account.v1.GameAccountHandle handle = 4;
  total_size += 1 * this->handle_size();
  for (int i = 0; i < this->handle_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->handle(i));
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

void GameAccountList::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountList* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountList*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountList::MergeFrom(const GameAccountList& from) {
  GOOGLE_CHECK_NE(&from, this);
  handle_.MergeFrom(from.handle_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountList::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountList::CopyFrom(const GameAccountList& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountList::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->handle())) return false;
  return true;
}

void GameAccountList::Swap(GameAccountList* other) {
  if (other != this) {
    std::swap(region_, other->region_);
    handle_.Swap(&other->handle_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountList::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountList_descriptor_;
  metadata.reflection = GameAccountList_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountState::kAccountLevelInfoFieldNumber;
const int AccountState::kPrivacyInfoFieldNumber;
const int AccountState::kParentalControlInfoFieldNumber;
const int AccountState::kGameLevelInfoFieldNumber;
const int AccountState::kGameStatusFieldNumber;
const int AccountState::kGameAccountsFieldNumber;
#endif  // !_MSC_VER

AccountState::AccountState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountState)
}

void AccountState::InitAsDefaultInstance() {
  account_level_info_ = const_cast< ::bgs::protocol::account::v1::AccountLevelInfo*>(&::bgs::protocol::account::v1::AccountLevelInfo::default_instance());
  privacy_info_ = const_cast< ::bgs::protocol::account::v1::PrivacyInfo*>(&::bgs::protocol::account::v1::PrivacyInfo::default_instance());
  parental_control_info_ = const_cast< ::bgs::protocol::account::v1::ParentalControlInfo*>(&::bgs::protocol::account::v1::ParentalControlInfo::default_instance());
}

AccountState::AccountState(const AccountState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountState)
}

void AccountState::SharedCtor() {
  _cached_size_ = 0;
  account_level_info_ = NULL;
  privacy_info_ = NULL;
  parental_control_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountState::~AccountState() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountState)
  SharedDtor();
}

void AccountState::SharedDtor() {
  if (this != default_instance_) {
    delete account_level_info_;
    delete privacy_info_;
    delete parental_control_info_;
  }
}

void AccountState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountState_descriptor_;
}

const AccountState& AccountState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountState* AccountState::default_instance_ = NULL;

AccountState* AccountState::New() const {
  return new AccountState;
}

void AccountState::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_account_level_info()) {
      if (account_level_info_ != NULL) account_level_info_->::bgs::protocol::account::v1::AccountLevelInfo::Clear();
    }
    if (has_privacy_info()) {
      if (privacy_info_ != NULL) privacy_info_->::bgs::protocol::account::v1::PrivacyInfo::Clear();
    }
    if (has_parental_control_info()) {
      if (parental_control_info_ != NULL) parental_control_info_->::bgs::protocol::account::v1::ParentalControlInfo::Clear();
    }
  }
  game_level_info_.Clear();
  game_status_.Clear();
  game_accounts_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.AccountLevelInfo account_level_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_account_level_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_privacy_info;
        break;
      }

      // optional .bgs.protocol.account.v1.PrivacyInfo privacy_info = 2;
      case 2: {
        if (tag == 18) {
         parse_privacy_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_privacy_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_parental_control_info;
        break;
      }

      // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 3;
      case 3: {
        if (tag == 26) {
         parse_parental_control_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_parental_control_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_game_level_info;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameLevelInfo game_level_info = 5;
      case 5: {
        if (tag == 42) {
         parse_game_level_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_level_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_game_level_info;
        if (input->ExpectTag(50)) goto parse_game_status;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameStatus game_status = 6;
      case 6: {
        if (tag == 50) {
         parse_game_status:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_status()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_game_status;
        if (input->ExpectTag(58)) goto parse_game_accounts;
        break;
      }

      // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 7;
      case 7: {
        if (tag == 58) {
         parse_game_accounts:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_accounts()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_game_accounts;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountState)
  return false;
#undef DO_
}

void AccountState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountState)
  // optional .bgs.protocol.account.v1.AccountLevelInfo account_level_info = 1;
  if (has_account_level_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_level_info(), output);
  }

  // optional .bgs.protocol.account.v1.PrivacyInfo privacy_info = 2;
  if (has_privacy_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->privacy_info(), output);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 3;
  if (has_parental_control_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->parental_control_info(), output);
  }

  // repeated .bgs.protocol.account.v1.GameLevelInfo game_level_info = 5;
  for (int i = 0; i < this->game_level_info_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->game_level_info(i), output);
  }

  // repeated .bgs.protocol.account.v1.GameStatus game_status = 6;
  for (int i = 0; i < this->game_status_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->game_status(i), output);
  }

  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 7;
  for (int i = 0; i < this->game_accounts_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->game_accounts(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountState)
}

::google::protobuf::uint8* AccountState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountState)
  // optional .bgs.protocol.account.v1.AccountLevelInfo account_level_info = 1;
  if (has_account_level_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_level_info(), target);
  }

  // optional .bgs.protocol.account.v1.PrivacyInfo privacy_info = 2;
  if (has_privacy_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->privacy_info(), target);
  }

  // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 3;
  if (has_parental_control_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->parental_control_info(), target);
  }

  // repeated .bgs.protocol.account.v1.GameLevelInfo game_level_info = 5;
  for (int i = 0; i < this->game_level_info_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->game_level_info(i), target);
  }

  // repeated .bgs.protocol.account.v1.GameStatus game_status = 6;
  for (int i = 0; i < this->game_status_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->game_status(i), target);
  }

  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 7;
  for (int i = 0; i < this->game_accounts_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->game_accounts(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountState)
  return target;
}

int AccountState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountLevelInfo account_level_info = 1;
    if (has_account_level_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_level_info());
    }

    // optional .bgs.protocol.account.v1.PrivacyInfo privacy_info = 2;
    if (has_privacy_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->privacy_info());
    }

    // optional .bgs.protocol.account.v1.ParentalControlInfo parental_control_info = 3;
    if (has_parental_control_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->parental_control_info());
    }

  }
  // repeated .bgs.protocol.account.v1.GameLevelInfo game_level_info = 5;
  total_size += 1 * this->game_level_info_size();
  for (int i = 0; i < this->game_level_info_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_level_info(i));
  }

  // repeated .bgs.protocol.account.v1.GameStatus game_status = 6;
  total_size += 1 * this->game_status_size();
  for (int i = 0; i < this->game_status_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->game_status(i));
  }

  // repeated .bgs.protocol.account.v1.GameAccountList game_accounts = 7;
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

void AccountState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountState::MergeFrom(const AccountState& from) {
  GOOGLE_CHECK_NE(&from, this);
  game_level_info_.MergeFrom(from.game_level_info_);
  game_status_.MergeFrom(from.game_status_);
  game_accounts_.MergeFrom(from.game_accounts_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_level_info()) {
      mutable_account_level_info()->::bgs::protocol::account::v1::AccountLevelInfo::MergeFrom(from.account_level_info());
    }
    if (from.has_privacy_info()) {
      mutable_privacy_info()->::bgs::protocol::account::v1::PrivacyInfo::MergeFrom(from.privacy_info());
    }
    if (from.has_parental_control_info()) {
      mutable_parental_control_info()->::bgs::protocol::account::v1::ParentalControlInfo::MergeFrom(from.parental_control_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountState::CopyFrom(const AccountState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountState::IsInitialized() const {

  if (has_account_level_info()) {
    if (!this->account_level_info().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->game_level_info())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->game_accounts())) return false;
  return true;
}

void AccountState::Swap(AccountState* other) {
  if (other != this) {
    std::swap(account_level_info_, other->account_level_info_);
    std::swap(privacy_info_, other->privacy_info_);
    std::swap(parental_control_info_, other->parental_control_info_);
    game_level_info_.Swap(&other->game_level_info_);
    game_status_.Swap(&other->game_status_);
    game_accounts_.Swap(&other->game_accounts_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountState_descriptor_;
  metadata.reflection = AccountState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AccountStateTagged::kAccountStateFieldNumber;
const int AccountStateTagged::kAccountTagsFieldNumber;
#endif  // !_MSC_VER

AccountStateTagged::AccountStateTagged()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AccountStateTagged)
}

void AccountStateTagged::InitAsDefaultInstance() {
  account_state_ = const_cast< ::bgs::protocol::account::v1::AccountState*>(&::bgs::protocol::account::v1::AccountState::default_instance());
  account_tags_ = const_cast< ::bgs::protocol::account::v1::AccountFieldTags*>(&::bgs::protocol::account::v1::AccountFieldTags::default_instance());
}

AccountStateTagged::AccountStateTagged(const AccountStateTagged& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AccountStateTagged)
}

void AccountStateTagged::SharedCtor() {
  _cached_size_ = 0;
  account_state_ = NULL;
  account_tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AccountStateTagged::~AccountStateTagged() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AccountStateTagged)
  SharedDtor();
}

void AccountStateTagged::SharedDtor() {
  if (this != default_instance_) {
    delete account_state_;
    delete account_tags_;
  }
}

void AccountStateTagged::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AccountStateTagged::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AccountStateTagged_descriptor_;
}

const AccountStateTagged& AccountStateTagged::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AccountStateTagged* AccountStateTagged::default_instance_ = NULL;

AccountStateTagged* AccountStateTagged::New() const {
  return new AccountStateTagged;
}

void AccountStateTagged::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_account_state()) {
      if (account_state_ != NULL) account_state_->::bgs::protocol::account::v1::AccountState::Clear();
    }
    if (has_account_tags()) {
      if (account_tags_ != NULL) account_tags_->::bgs::protocol::account::v1::AccountFieldTags::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AccountStateTagged::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AccountStateTagged)
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
        if (input->ExpectTag(18)) goto parse_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 2;
      case 2: {
        if (tag == 18) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AccountStateTagged)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AccountStateTagged)
  return false;
#undef DO_
}

void AccountStateTagged::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AccountStateTagged)
  // optional .bgs.protocol.account.v1.AccountState account_state = 1;
  if (has_account_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->account_state(), output);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 2;
  if (has_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->account_tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AccountStateTagged)
}

::google::protobuf::uint8* AccountStateTagged::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AccountStateTagged)
  // optional .bgs.protocol.account.v1.AccountState account_state = 1;
  if (has_account_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->account_state(), target);
  }

  // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 2;
  if (has_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->account_tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AccountStateTagged)
  return target;
}

int AccountStateTagged::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.AccountState account_state = 1;
    if (has_account_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_state());
    }

    // optional .bgs.protocol.account.v1.AccountFieldTags account_tags = 2;
    if (has_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->account_tags());
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

void AccountStateTagged::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AccountStateTagged* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AccountStateTagged*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AccountStateTagged::MergeFrom(const AccountStateTagged& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account_state()) {
      mutable_account_state()->::bgs::protocol::account::v1::AccountState::MergeFrom(from.account_state());
    }
    if (from.has_account_tags()) {
      mutable_account_tags()->::bgs::protocol::account::v1::AccountFieldTags::MergeFrom(from.account_tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AccountStateTagged::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AccountStateTagged::CopyFrom(const AccountStateTagged& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AccountStateTagged::IsInitialized() const {

  if (has_account_state()) {
    if (!this->account_state().IsInitialized()) return false;
  }
  return true;
}

void AccountStateTagged::Swap(AccountStateTagged* other) {
  if (other != this) {
    std::swap(account_state_, other->account_state_);
    std::swap(account_tags_, other->account_tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AccountStateTagged::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AccountStateTagged_descriptor_;
  metadata.reflection = AccountStateTagged_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountState::kGameLevelInfoFieldNumber;
const int GameAccountState::kGameTimeInfoFieldNumber;
const int GameAccountState::kGameStatusFieldNumber;
const int GameAccountState::kRafInfoFieldNumber;
#endif  // !_MSC_VER

GameAccountState::GameAccountState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountState)
}

void GameAccountState::InitAsDefaultInstance() {
  game_level_info_ = const_cast< ::bgs::protocol::account::v1::GameLevelInfo*>(&::bgs::protocol::account::v1::GameLevelInfo::default_instance());
  game_time_info_ = const_cast< ::bgs::protocol::account::v1::GameTimeInfo*>(&::bgs::protocol::account::v1::GameTimeInfo::default_instance());
  game_status_ = const_cast< ::bgs::protocol::account::v1::GameStatus*>(&::bgs::protocol::account::v1::GameStatus::default_instance());
  raf_info_ = const_cast< ::bgs::protocol::account::v1::RAFInfo*>(&::bgs::protocol::account::v1::RAFInfo::default_instance());
}

GameAccountState::GameAccountState(const GameAccountState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountState)
}

void GameAccountState::SharedCtor() {
  _cached_size_ = 0;
  game_level_info_ = NULL;
  game_time_info_ = NULL;
  game_status_ = NULL;
  raf_info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountState::~GameAccountState() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountState)
  SharedDtor();
}

void GameAccountState::SharedDtor() {
  if (this != default_instance_) {
    delete game_level_info_;
    delete game_time_info_;
    delete game_status_;
    delete raf_info_;
  }
}

void GameAccountState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountState_descriptor_;
}

const GameAccountState& GameAccountState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountState* GameAccountState::default_instance_ = NULL;

GameAccountState* GameAccountState::New() const {
  return new GameAccountState;
}

void GameAccountState::Clear() {
  if (_has_bits_[0 / 32] & 15) {
    if (has_game_level_info()) {
      if (game_level_info_ != NULL) game_level_info_->::bgs::protocol::account::v1::GameLevelInfo::Clear();
    }
    if (has_game_time_info()) {
      if (game_time_info_ != NULL) game_time_info_->::bgs::protocol::account::v1::GameTimeInfo::Clear();
    }
    if (has_game_status()) {
      if (game_status_ != NULL) game_status_->::bgs::protocol::account::v1::GameStatus::Clear();
    }
    if (has_raf_info()) {
      if (raf_info_ != NULL) raf_info_->::bgs::protocol::account::v1::RAFInfo::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountState)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameLevelInfo game_level_info = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_level_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_game_time_info;
        break;
      }

      // optional .bgs.protocol.account.v1.GameTimeInfo game_time_info = 2;
      case 2: {
        if (tag == 18) {
         parse_game_time_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_time_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_game_status;
        break;
      }

      // optional .bgs.protocol.account.v1.GameStatus game_status = 3;
      case 3: {
        if (tag == 26) {
         parse_game_status:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_status()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_raf_info;
        break;
      }

      // optional .bgs.protocol.account.v1.RAFInfo raf_info = 4;
      case 4: {
        if (tag == 34) {
         parse_raf_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_raf_info()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountState)
  return false;
#undef DO_
}

void GameAccountState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountState)
  // optional .bgs.protocol.account.v1.GameLevelInfo game_level_info = 1;
  if (has_game_level_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_level_info(), output);
  }

  // optional .bgs.protocol.account.v1.GameTimeInfo game_time_info = 2;
  if (has_game_time_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_time_info(), output);
  }

  // optional .bgs.protocol.account.v1.GameStatus game_status = 3;
  if (has_game_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->game_status(), output);
  }

  // optional .bgs.protocol.account.v1.RAFInfo raf_info = 4;
  if (has_raf_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->raf_info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountState)
}

::google::protobuf::uint8* GameAccountState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountState)
  // optional .bgs.protocol.account.v1.GameLevelInfo game_level_info = 1;
  if (has_game_level_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_level_info(), target);
  }

  // optional .bgs.protocol.account.v1.GameTimeInfo game_time_info = 2;
  if (has_game_time_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_time_info(), target);
  }

  // optional .bgs.protocol.account.v1.GameStatus game_status = 3;
  if (has_game_status()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->game_status(), target);
  }

  // optional .bgs.protocol.account.v1.RAFInfo raf_info = 4;
  if (has_raf_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->raf_info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountState)
  return target;
}

int GameAccountState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameLevelInfo game_level_info = 1;
    if (has_game_level_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_level_info());
    }

    // optional .bgs.protocol.account.v1.GameTimeInfo game_time_info = 2;
    if (has_game_time_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_time_info());
    }

    // optional .bgs.protocol.account.v1.GameStatus game_status = 3;
    if (has_game_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_status());
    }

    // optional .bgs.protocol.account.v1.RAFInfo raf_info = 4;
    if (has_raf_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->raf_info());
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

void GameAccountState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountState::MergeFrom(const GameAccountState& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_level_info()) {
      mutable_game_level_info()->::bgs::protocol::account::v1::GameLevelInfo::MergeFrom(from.game_level_info());
    }
    if (from.has_game_time_info()) {
      mutable_game_time_info()->::bgs::protocol::account::v1::GameTimeInfo::MergeFrom(from.game_time_info());
    }
    if (from.has_game_status()) {
      mutable_game_status()->::bgs::protocol::account::v1::GameStatus::MergeFrom(from.game_status());
    }
    if (from.has_raf_info()) {
      mutable_raf_info()->::bgs::protocol::account::v1::RAFInfo::MergeFrom(from.raf_info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountState::CopyFrom(const GameAccountState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountState::IsInitialized() const {

  if (has_game_level_info()) {
    if (!this->game_level_info().IsInitialized()) return false;
  }
  return true;
}

void GameAccountState::Swap(GameAccountState* other) {
  if (other != this) {
    std::swap(game_level_info_, other->game_level_info_);
    std::swap(game_time_info_, other->game_time_info_);
    std::swap(game_status_, other->game_status_);
    std::swap(raf_info_, other->raf_info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountState_descriptor_;
  metadata.reflection = GameAccountState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameAccountStateTagged::kGameAccountStateFieldNumber;
const int GameAccountStateTagged::kGameAccountTagsFieldNumber;
#endif  // !_MSC_VER

GameAccountStateTagged::GameAccountStateTagged()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.GameAccountStateTagged)
}

void GameAccountStateTagged::InitAsDefaultInstance() {
  game_account_state_ = const_cast< ::bgs::protocol::account::v1::GameAccountState*>(&::bgs::protocol::account::v1::GameAccountState::default_instance());
  game_account_tags_ = const_cast< ::bgs::protocol::account::v1::GameAccountFieldTags*>(&::bgs::protocol::account::v1::GameAccountFieldTags::default_instance());
}

GameAccountStateTagged::GameAccountStateTagged(const GameAccountStateTagged& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.GameAccountStateTagged)
}

void GameAccountStateTagged::SharedCtor() {
  _cached_size_ = 0;
  game_account_state_ = NULL;
  game_account_tags_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameAccountStateTagged::~GameAccountStateTagged() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.GameAccountStateTagged)
  SharedDtor();
}

void GameAccountStateTagged::SharedDtor() {
  if (this != default_instance_) {
    delete game_account_state_;
    delete game_account_tags_;
  }
}

void GameAccountStateTagged::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameAccountStateTagged::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameAccountStateTagged_descriptor_;
}

const GameAccountStateTagged& GameAccountStateTagged::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

GameAccountStateTagged* GameAccountStateTagged::default_instance_ = NULL;

GameAccountStateTagged* GameAccountStateTagged::New() const {
  return new GameAccountStateTagged;
}

void GameAccountStateTagged::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_game_account_state()) {
      if (game_account_state_ != NULL) game_account_state_->::bgs::protocol::account::v1::GameAccountState::Clear();
    }
    if (has_game_account_tags()) {
      if (game_account_tags_ != NULL) game_account_tags_->::bgs::protocol::account::v1::GameAccountFieldTags::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameAccountStateTagged::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.GameAccountStateTagged)
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
        if (input->ExpectTag(18)) goto parse_game_account_tags;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 2;
      case 2: {
        if (tag == 18) {
         parse_game_account_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_game_account_tags()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.GameAccountStateTagged)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.GameAccountStateTagged)
  return false;
#undef DO_
}

void GameAccountStateTagged::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.GameAccountStateTagged)
  // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
  if (has_game_account_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account_state(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 2;
  if (has_game_account_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->game_account_tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.GameAccountStateTagged)
}

::google::protobuf::uint8* GameAccountStateTagged::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.GameAccountStateTagged)
  // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
  if (has_game_account_state()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account_state(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 2;
  if (has_game_account_tags()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->game_account_tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.GameAccountStateTagged)
  return target;
}

int GameAccountStateTagged::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountState game_account_state = 1;
    if (has_game_account_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_state());
    }

    // optional .bgs.protocol.account.v1.GameAccountFieldTags game_account_tags = 2;
    if (has_game_account_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account_tags());
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

void GameAccountStateTagged::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameAccountStateTagged* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameAccountStateTagged*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameAccountStateTagged::MergeFrom(const GameAccountStateTagged& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account_state()) {
      mutable_game_account_state()->::bgs::protocol::account::v1::GameAccountState::MergeFrom(from.game_account_state());
    }
    if (from.has_game_account_tags()) {
      mutable_game_account_tags()->::bgs::protocol::account::v1::GameAccountFieldTags::MergeFrom(from.game_account_tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameAccountStateTagged::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameAccountStateTagged::CopyFrom(const GameAccountStateTagged& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameAccountStateTagged::IsInitialized() const {

  if (has_game_account_state()) {
    if (!this->game_account_state().IsInitialized()) return false;
  }
  return true;
}

void GameAccountStateTagged::Swap(GameAccountStateTagged* other) {
  if (other != this) {
    std::swap(game_account_state_, other->game_account_state_);
    std::swap(game_account_tags_, other->game_account_tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameAccountStateTagged::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameAccountStateTagged_descriptor_;
  metadata.reflection = GameAccountStateTagged_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AuthorizedData::kDataFieldNumber;
const int AuthorizedData::kLicenseFieldNumber;
#endif  // !_MSC_VER

AuthorizedData::AuthorizedData()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AuthorizedData)
}

void AuthorizedData::InitAsDefaultInstance() {
}

AuthorizedData::AuthorizedData(const AuthorizedData& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AuthorizedData)
}

void AuthorizedData::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AuthorizedData::~AuthorizedData() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AuthorizedData)
  SharedDtor();
}

void AuthorizedData::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void AuthorizedData::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AuthorizedData::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AuthorizedData_descriptor_;
}

const AuthorizedData& AuthorizedData::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AuthorizedData* AuthorizedData::default_instance_ = NULL;

AuthorizedData* AuthorizedData::New() const {
  return new AuthorizedData;
}

void AuthorizedData::Clear() {
  if (has_data()) {
    if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      data_->clear();
    }
  }
  license_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AuthorizedData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AuthorizedData)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_data()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->data().data(), this->data().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "data");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_license;
        break;
      }

      // repeated uint32 license = 2;
      case 2: {
        if (tag == 16) {
         parse_license:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 16, input, this->mutable_license())));
        } else if (tag == 18) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_license())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_license;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AuthorizedData)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AuthorizedData)
  return false;
#undef DO_
}

void AuthorizedData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AuthorizedData)
  // optional string data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "data");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->data(), output);
  }

  // repeated uint32 license = 2;
  for (int i = 0; i < this->license_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(
      2, this->license(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AuthorizedData)
}

::google::protobuf::uint8* AuthorizedData::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AuthorizedData)
  // optional string data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "data");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->data(), target);
  }

  // repeated uint32 license = 2;
  for (int i = 0; i < this->license_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32ToArray(2, this->license(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AuthorizedData)
  return target;
}

int AuthorizedData::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string data = 1;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->data());
    }

  }
  // repeated uint32 license = 2;
  {
    int data_size = 0;
    for (int i = 0; i < this->license_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->license(i));
    }
    total_size += 1 * this->license_size() + data_size;
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

void AuthorizedData::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AuthorizedData* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AuthorizedData*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AuthorizedData::MergeFrom(const AuthorizedData& from) {
  GOOGLE_CHECK_NE(&from, this);
  license_.MergeFrom(from.license_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AuthorizedData::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AuthorizedData::CopyFrom(const AuthorizedData& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AuthorizedData::IsInitialized() const {

  return true;
}

void AuthorizedData::Swap(AuthorizedData* other) {
  if (other != this) {
    std::swap(data_, other->data_);
    license_.Swap(&other->license_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AuthorizedData::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AuthorizedData_descriptor_;
  metadata.reflection = AuthorizedData_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BenefactorAddress::kRegionFieldNumber;
const int BenefactorAddress::kIgrAddressFieldNumber;
#endif  // !_MSC_VER

BenefactorAddress::BenefactorAddress()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.BenefactorAddress)
}

void BenefactorAddress::InitAsDefaultInstance() {
}

BenefactorAddress::BenefactorAddress(const BenefactorAddress& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.BenefactorAddress)
}

void BenefactorAddress::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  region_ = 0u;
  igr_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BenefactorAddress::~BenefactorAddress() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.BenefactorAddress)
  SharedDtor();
}

void BenefactorAddress::SharedDtor() {
  if (igr_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete igr_address_;
  }
  if (this != default_instance_) {
  }
}

void BenefactorAddress::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BenefactorAddress::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BenefactorAddress_descriptor_;
}

const BenefactorAddress& BenefactorAddress::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

BenefactorAddress* BenefactorAddress::default_instance_ = NULL;

BenefactorAddress* BenefactorAddress::New() const {
  return new BenefactorAddress;
}

void BenefactorAddress::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    region_ = 0u;
    if (has_igr_address()) {
      if (igr_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        igr_address_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BenefactorAddress::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.BenefactorAddress)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 region = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &region_)));
          set_has_region();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_igr_address;
        break;
      }

      // optional string igr_address = 2;
      case 2: {
        if (tag == 18) {
         parse_igr_address:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_igr_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->igr_address().data(), this->igr_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "igr_address");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.BenefactorAddress)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.BenefactorAddress)
  return false;
#undef DO_
}

void BenefactorAddress::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.BenefactorAddress)
  // optional uint32 region = 1;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->region(), output);
  }

  // optional string igr_address = 2;
  if (has_igr_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->igr_address().data(), this->igr_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "igr_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->igr_address(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.BenefactorAddress)
}

::google::protobuf::uint8* BenefactorAddress::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.BenefactorAddress)
  // optional uint32 region = 1;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->region(), target);
  }

  // optional string igr_address = 2;
  if (has_igr_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->igr_address().data(), this->igr_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "igr_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->igr_address(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.BenefactorAddress)
  return target;
}

int BenefactorAddress::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 region = 1;
    if (has_region()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->region());
    }

    // optional string igr_address = 2;
    if (has_igr_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->igr_address());
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

void BenefactorAddress::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BenefactorAddress* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BenefactorAddress*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BenefactorAddress::MergeFrom(const BenefactorAddress& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_region()) {
      set_region(from.region());
    }
    if (from.has_igr_address()) {
      set_igr_address(from.igr_address());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BenefactorAddress::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BenefactorAddress::CopyFrom(const BenefactorAddress& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BenefactorAddress::IsInitialized() const {

  return true;
}

void BenefactorAddress::Swap(BenefactorAddress* other) {
  if (other != this) {
    std::swap(region_, other->region_);
    std::swap(igr_address_, other->igr_address_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BenefactorAddress::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BenefactorAddress_descriptor_;
  metadata.reflection = BenefactorAddress_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ExternalBenefactorLookup::kBenefactorIdFieldNumber;
const int ExternalBenefactorLookup::kRegionFieldNumber;
#endif  // !_MSC_VER

ExternalBenefactorLookup::ExternalBenefactorLookup()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.ExternalBenefactorLookup)
}

void ExternalBenefactorLookup::InitAsDefaultInstance() {
}

ExternalBenefactorLookup::ExternalBenefactorLookup(const ExternalBenefactorLookup& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.ExternalBenefactorLookup)
}

void ExternalBenefactorLookup::SharedCtor() {
  _cached_size_ = 0;
  benefactor_id_ = 0u;
  region_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ExternalBenefactorLookup::~ExternalBenefactorLookup() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.ExternalBenefactorLookup)
  SharedDtor();
}

void ExternalBenefactorLookup::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ExternalBenefactorLookup::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ExternalBenefactorLookup::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ExternalBenefactorLookup_descriptor_;
}

const ExternalBenefactorLookup& ExternalBenefactorLookup::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

ExternalBenefactorLookup* ExternalBenefactorLookup::default_instance_ = NULL;

ExternalBenefactorLookup* ExternalBenefactorLookup::New() const {
  return new ExternalBenefactorLookup;
}

void ExternalBenefactorLookup::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ExternalBenefactorLookup*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(benefactor_id_, region_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ExternalBenefactorLookup::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.ExternalBenefactorLookup)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 benefactor_id = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &benefactor_id_)));
          set_has_benefactor_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.ExternalBenefactorLookup)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.ExternalBenefactorLookup)
  return false;
#undef DO_
}

void ExternalBenefactorLookup::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.ExternalBenefactorLookup)
  // optional fixed32 benefactor_id = 1;
  if (has_benefactor_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->benefactor_id(), output);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->region(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.ExternalBenefactorLookup)
}

::google::protobuf::uint8* ExternalBenefactorLookup::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.ExternalBenefactorLookup)
  // optional fixed32 benefactor_id = 1;
  if (has_benefactor_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->benefactor_id(), target);
  }

  // optional uint32 region = 2;
  if (has_region()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->region(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.ExternalBenefactorLookup)
  return target;
}

int ExternalBenefactorLookup::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 benefactor_id = 1;
    if (has_benefactor_id()) {
      total_size += 1 + 4;
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

void ExternalBenefactorLookup::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ExternalBenefactorLookup* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ExternalBenefactorLookup*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ExternalBenefactorLookup::MergeFrom(const ExternalBenefactorLookup& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_benefactor_id()) {
      set_benefactor_id(from.benefactor_id());
    }
    if (from.has_region()) {
      set_region(from.region());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ExternalBenefactorLookup::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ExternalBenefactorLookup::CopyFrom(const ExternalBenefactorLookup& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExternalBenefactorLookup::IsInitialized() const {

  return true;
}

void ExternalBenefactorLookup::Swap(ExternalBenefactorLookup* other) {
  if (other != this) {
    std::swap(benefactor_id_, other->benefactor_id_);
    std::swap(region_, other->region_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ExternalBenefactorLookup::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ExternalBenefactorLookup_descriptor_;
  metadata.reflection = ExternalBenefactorLookup_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AuthBenefactor::kIgrAddressFieldNumber;
const int AuthBenefactor::kBenefactorIdFieldNumber;
const int AuthBenefactor::kActiveFieldNumber;
const int AuthBenefactor::kLastUpdateTimeFieldNumber;
#endif  // !_MSC_VER

AuthBenefactor::AuthBenefactor()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.AuthBenefactor)
}

void AuthBenefactor::InitAsDefaultInstance() {
}

AuthBenefactor::AuthBenefactor(const AuthBenefactor& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.AuthBenefactor)
}

void AuthBenefactor::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  igr_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  benefactor_id_ = 0u;
  active_ = false;
  last_update_time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AuthBenefactor::~AuthBenefactor() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.AuthBenefactor)
  SharedDtor();
}

void AuthBenefactor::SharedDtor() {
  if (igr_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete igr_address_;
  }
  if (this != default_instance_) {
  }
}

void AuthBenefactor::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AuthBenefactor::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AuthBenefactor_descriptor_;
}

const AuthBenefactor& AuthBenefactor::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

AuthBenefactor* AuthBenefactor::default_instance_ = NULL;

AuthBenefactor* AuthBenefactor::New() const {
  return new AuthBenefactor;
}

void AuthBenefactor::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<AuthBenefactor*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(benefactor_id_, last_update_time_);
    if (has_igr_address()) {
      if (igr_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        igr_address_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AuthBenefactor::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.AuthBenefactor)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string igr_address = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_igr_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->igr_address().data(), this->igr_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "igr_address");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_benefactor_id;
        break;
      }

      // optional fixed32 benefactor_id = 2;
      case 2: {
        if (tag == 21) {
         parse_benefactor_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &benefactor_id_)));
          set_has_benefactor_id();
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
        if (input->ExpectTag(32)) goto parse_last_update_time;
        break;
      }

      // optional uint64 last_update_time = 4;
      case 4: {
        if (tag == 32) {
         parse_last_update_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &last_update_time_)));
          set_has_last_update_time();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.AuthBenefactor)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.AuthBenefactor)
  return false;
#undef DO_
}

void AuthBenefactor::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.AuthBenefactor)
  // optional string igr_address = 1;
  if (has_igr_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->igr_address().data(), this->igr_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "igr_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->igr_address(), output);
  }

  // optional fixed32 benefactor_id = 2;
  if (has_benefactor_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->benefactor_id(), output);
  }

  // optional bool active = 3;
  if (has_active()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->active(), output);
  }

  // optional uint64 last_update_time = 4;
  if (has_last_update_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->last_update_time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.AuthBenefactor)
}

::google::protobuf::uint8* AuthBenefactor::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.AuthBenefactor)
  // optional string igr_address = 1;
  if (has_igr_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->igr_address().data(), this->igr_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "igr_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->igr_address(), target);
  }

  // optional fixed32 benefactor_id = 2;
  if (has_benefactor_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->benefactor_id(), target);
  }

  // optional bool active = 3;
  if (has_active()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->active(), target);
  }

  // optional uint64 last_update_time = 4;
  if (has_last_update_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->last_update_time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.AuthBenefactor)
  return target;
}

int AuthBenefactor::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string igr_address = 1;
    if (has_igr_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->igr_address());
    }

    // optional fixed32 benefactor_id = 2;
    if (has_benefactor_id()) {
      total_size += 1 + 4;
    }

    // optional bool active = 3;
    if (has_active()) {
      total_size += 1 + 1;
    }

    // optional uint64 last_update_time = 4;
    if (has_last_update_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->last_update_time());
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

void AuthBenefactor::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AuthBenefactor* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AuthBenefactor*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AuthBenefactor::MergeFrom(const AuthBenefactor& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_igr_address()) {
      set_igr_address(from.igr_address());
    }
    if (from.has_benefactor_id()) {
      set_benefactor_id(from.benefactor_id());
    }
    if (from.has_active()) {
      set_active(from.active());
    }
    if (from.has_last_update_time()) {
      set_last_update_time(from.last_update_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AuthBenefactor::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AuthBenefactor::CopyFrom(const AuthBenefactor& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AuthBenefactor::IsInitialized() const {

  return true;
}

void AuthBenefactor::Swap(AuthBenefactor* other) {
  if (other != this) {
    std::swap(igr_address_, other->igr_address_);
    std::swap(benefactor_id_, other->benefactor_id_);
    std::swap(active_, other->active_);
    std::swap(last_update_time_, other->last_update_time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AuthBenefactor::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AuthBenefactor_descriptor_;
  metadata.reflection = AuthBenefactor_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ApplicationInfo::kPlatformIdFieldNumber;
const int ApplicationInfo::kLocaleFieldNumber;
const int ApplicationInfo::kApplicationVersionFieldNumber;
#endif  // !_MSC_VER

ApplicationInfo::ApplicationInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.ApplicationInfo)
}

void ApplicationInfo::InitAsDefaultInstance() {
}

ApplicationInfo::ApplicationInfo(const ApplicationInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.ApplicationInfo)
}

void ApplicationInfo::SharedCtor() {
  _cached_size_ = 0;
  platform_id_ = 0u;
  locale_ = 0u;
  application_version_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ApplicationInfo::~ApplicationInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.ApplicationInfo)
  SharedDtor();
}

void ApplicationInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ApplicationInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ApplicationInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ApplicationInfo_descriptor_;
}

const ApplicationInfo& ApplicationInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

ApplicationInfo* ApplicationInfo::default_instance_ = NULL;

ApplicationInfo* ApplicationInfo::New() const {
  return new ApplicationInfo;
}

void ApplicationInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ApplicationInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(platform_id_, application_version_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ApplicationInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.ApplicationInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 platform_id = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &platform_id_)));
          set_has_platform_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_locale;
        break;
      }

      // optional fixed32 locale = 2;
      case 2: {
        if (tag == 21) {
         parse_locale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &locale_)));
          set_has_locale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_application_version;
        break;
      }

      // optional int32 application_version = 3;
      case 3: {
        if (tag == 24) {
         parse_application_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &application_version_)));
          set_has_application_version();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.ApplicationInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.ApplicationInfo)
  return false;
#undef DO_
}

void ApplicationInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.ApplicationInfo)
  // optional fixed32 platform_id = 1;
  if (has_platform_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->platform_id(), output);
  }

  // optional fixed32 locale = 2;
  if (has_locale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->locale(), output);
  }

  // optional int32 application_version = 3;
  if (has_application_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->application_version(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.ApplicationInfo)
}

::google::protobuf::uint8* ApplicationInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.ApplicationInfo)
  // optional fixed32 platform_id = 1;
  if (has_platform_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->platform_id(), target);
  }

  // optional fixed32 locale = 2;
  if (has_locale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->locale(), target);
  }

  // optional int32 application_version = 3;
  if (has_application_version()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->application_version(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.ApplicationInfo)
  return target;
}

int ApplicationInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 platform_id = 1;
    if (has_platform_id()) {
      total_size += 1 + 4;
    }

    // optional fixed32 locale = 2;
    if (has_locale()) {
      total_size += 1 + 4;
    }

    // optional int32 application_version = 3;
    if (has_application_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->application_version());
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

void ApplicationInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ApplicationInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ApplicationInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ApplicationInfo::MergeFrom(const ApplicationInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_platform_id()) {
      set_platform_id(from.platform_id());
    }
    if (from.has_locale()) {
      set_locale(from.locale());
    }
    if (from.has_application_version()) {
      set_application_version(from.application_version());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ApplicationInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ApplicationInfo::CopyFrom(const ApplicationInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ApplicationInfo::IsInitialized() const {

  return true;
}

void ApplicationInfo::Swap(ApplicationInfo* other) {
  if (other != this) {
    std::swap(platform_id_, other->platform_id_);
    std::swap(locale_, other->locale_);
    std::swap(application_version_, other->application_version_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ApplicationInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ApplicationInfo_descriptor_;
  metadata.reflection = ApplicationInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DeductRecord::kGameAccountFieldNumber;
const int DeductRecord::kBenefactorFieldNumber;
const int DeductRecord::kStartTimeFieldNumber;
const int DeductRecord::kEndTimeFieldNumber;
const int DeductRecord::kClientAddressFieldNumber;
const int DeductRecord::kApplicationInfoFieldNumber;
const int DeductRecord::kSessionOwnerFieldNumber;
const int DeductRecord::kFreeSessionFieldNumber;
#endif  // !_MSC_VER

DeductRecord::DeductRecord()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.DeductRecord)
}

void DeductRecord::InitAsDefaultInstance() {
  game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
  benefactor_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
  application_info_ = const_cast< ::bgs::protocol::account::v1::ApplicationInfo*>(&::bgs::protocol::account::v1::ApplicationInfo::default_instance());
}

DeductRecord::DeductRecord(const DeductRecord& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.DeductRecord)
}

void DeductRecord::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  game_account_ = NULL;
  benefactor_ = NULL;
  start_time_ = GOOGLE_ULONGLONG(0);
  end_time_ = GOOGLE_ULONGLONG(0);
  client_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  application_info_ = NULL;
  session_owner_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  free_session_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DeductRecord::~DeductRecord() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.DeductRecord)
  SharedDtor();
}

void DeductRecord::SharedDtor() {
  if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete client_address_;
  }
  if (session_owner_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_owner_;
  }
  if (this != default_instance_) {
    delete game_account_;
    delete benefactor_;
    delete application_info_;
  }
}

void DeductRecord::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DeductRecord::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DeductRecord_descriptor_;
}

const DeductRecord& DeductRecord::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

DeductRecord* DeductRecord::default_instance_ = NULL;

DeductRecord* DeductRecord::New() const {
  return new DeductRecord;
}

void DeductRecord::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<DeductRecord*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(start_time_, end_time_);
    if (has_game_account()) {
      if (game_account_ != NULL) game_account_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_benefactor()) {
      if (benefactor_ != NULL) benefactor_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_client_address()) {
      if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        client_address_->clear();
      }
    }
    if (has_application_info()) {
      if (application_info_ != NULL) application_info_->::bgs::protocol::account::v1::ApplicationInfo::Clear();
    }
    if (has_session_owner()) {
      if (session_owner_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        session_owner_->clear();
      }
    }
    free_session_ = false;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DeductRecord::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.DeductRecord)
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
        if (input->ExpectTag(18)) goto parse_benefactor;
        break;
      }

      // optional .bgs.protocol.account.v1.GameAccountHandle benefactor = 2;
      case 2: {
        if (tag == 18) {
         parse_benefactor:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_benefactor()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_start_time;
        break;
      }

      // optional uint64 start_time = 3;
      case 3: {
        if (tag == 24) {
         parse_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &start_time_)));
          set_has_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_end_time;
        break;
      }

      // optional uint64 end_time = 4;
      case 4: {
        if (tag == 32) {
         parse_end_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &end_time_)));
          set_has_end_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_client_address;
        break;
      }

      // optional string client_address = 5;
      case 5: {
        if (tag == 42) {
         parse_client_address:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->client_address().data(), this->client_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "client_address");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_application_info;
        break;
      }

      // optional .bgs.protocol.account.v1.ApplicationInfo application_info = 6;
      case 6: {
        if (tag == 50) {
         parse_application_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_application_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_session_owner;
        break;
      }

      // optional string session_owner = 7;
      case 7: {
        if (tag == 58) {
         parse_session_owner:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_owner()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->session_owner().data(), this->session_owner().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "session_owner");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_free_session;
        break;
      }

      // optional bool free_session = 8;
      case 8: {
        if (tag == 64) {
         parse_free_session:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &free_session_)));
          set_has_free_session();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.DeductRecord)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.DeductRecord)
  return false;
#undef DO_
}

void DeductRecord::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.DeductRecord)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle benefactor = 2;
  if (has_benefactor()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->benefactor(), output);
  }

  // optional uint64 start_time = 3;
  if (has_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->start_time(), output);
  }

  // optional uint64 end_time = 4;
  if (has_end_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->end_time(), output);
  }

  // optional string client_address = 5;
  if (has_client_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_address().data(), this->client_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->client_address(), output);
  }

  // optional .bgs.protocol.account.v1.ApplicationInfo application_info = 6;
  if (has_application_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->application_info(), output);
  }

  // optional string session_owner = 7;
  if (has_session_owner()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_owner().data(), this->session_owner().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_owner");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->session_owner(), output);
  }

  // optional bool free_session = 8;
  if (has_free_session()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->free_session(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.DeductRecord)
}

::google::protobuf::uint8* DeductRecord::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.DeductRecord)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional .bgs.protocol.account.v1.GameAccountHandle benefactor = 2;
  if (has_benefactor()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->benefactor(), target);
  }

  // optional uint64 start_time = 3;
  if (has_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->start_time(), target);
  }

  // optional uint64 end_time = 4;
  if (has_end_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->end_time(), target);
  }

  // optional string client_address = 5;
  if (has_client_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_address().data(), this->client_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "client_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->client_address(), target);
  }

  // optional .bgs.protocol.account.v1.ApplicationInfo application_info = 6;
  if (has_application_info()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->application_info(), target);
  }

  // optional string session_owner = 7;
  if (has_session_owner()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->session_owner().data(), this->session_owner().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "session_owner");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->session_owner(), target);
  }

  // optional bool free_session = 8;
  if (has_free_session()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->free_session(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.DeductRecord)
  return target;
}

int DeductRecord::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    if (has_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
    }

    // optional .bgs.protocol.account.v1.GameAccountHandle benefactor = 2;
    if (has_benefactor()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->benefactor());
    }

    // optional uint64 start_time = 3;
    if (has_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->start_time());
    }

    // optional uint64 end_time = 4;
    if (has_end_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->end_time());
    }

    // optional string client_address = 5;
    if (has_client_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_address());
    }

    // optional .bgs.protocol.account.v1.ApplicationInfo application_info = 6;
    if (has_application_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->application_info());
    }

    // optional string session_owner = 7;
    if (has_session_owner()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_owner());
    }

    // optional bool free_session = 8;
    if (has_free_session()) {
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

void DeductRecord::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DeductRecord* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DeductRecord*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DeductRecord::MergeFrom(const DeductRecord& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_game_account()) {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
    }
    if (from.has_benefactor()) {
      mutable_benefactor()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.benefactor());
    }
    if (from.has_start_time()) {
      set_start_time(from.start_time());
    }
    if (from.has_end_time()) {
      set_end_time(from.end_time());
    }
    if (from.has_client_address()) {
      set_client_address(from.client_address());
    }
    if (from.has_application_info()) {
      mutable_application_info()->::bgs::protocol::account::v1::ApplicationInfo::MergeFrom(from.application_info());
    }
    if (from.has_session_owner()) {
      set_session_owner(from.session_owner());
    }
    if (from.has_free_session()) {
      set_free_session(from.free_session());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DeductRecord::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DeductRecord::CopyFrom(const DeductRecord& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DeductRecord::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  if (has_benefactor()) {
    if (!this->benefactor().IsInitialized()) return false;
  }
  return true;
}

void DeductRecord::Swap(DeductRecord* other) {
  if (other != this) {
    std::swap(game_account_, other->game_account_);
    std::swap(benefactor_, other->benefactor_);
    std::swap(start_time_, other->start_time_);
    std::swap(end_time_, other->end_time_);
    std::swap(client_address_, other->client_address_);
    std::swap(application_info_, other->application_info_);
    std::swap(session_owner_, other->session_owner_);
    std::swap(free_session_, other->free_session_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DeductRecord::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DeductRecord_descriptor_;
  metadata.reflection = DeductRecord_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int IgrId::kGameAccountFieldNumber;
const int IgrId::kExternalIdFieldNumber;
#endif  // !_MSC_VER

IgrId::IgrId()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.account.v1.IgrId)
}

void IgrId::InitAsDefaultInstance() {
  IgrId_default_oneof_instance_->game_account_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
  IgrId_default_oneof_instance_->external_id_ = 0u;
}

IgrId::IgrId(const IgrId& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.account.v1.IgrId)
}

void IgrId::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  clear_has_type();
}

IgrId::~IgrId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.account.v1.IgrId)
  SharedDtor();
}

void IgrId::SharedDtor() {
  if (has_type()) {
    clear_type();
  }
  if (this != default_instance_) {
  }
}

void IgrId::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* IgrId::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IgrId_descriptor_;
}

const IgrId& IgrId::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_account_5ftypes_2eproto();
  return *default_instance_;
}

IgrId* IgrId::default_instance_ = NULL;

IgrId* IgrId::New() const {
  return new IgrId;
}

void IgrId::clear_type() {
  switch(type_case()) {
    case kGameAccount: {
      delete type_.game_account_;
      break;
    }
    case kExternalId: {
      // No need to clear
      break;
    }
    case TYPE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = TYPE_NOT_SET;
}


void IgrId::Clear() {
  clear_type();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool IgrId::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.account.v1.IgrId)
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
        if (input->ExpectTag(21)) goto parse_external_id;
        break;
      }

      // optional fixed32 external_id = 2;
      case 2: {
        if (tag == 21) {
         parse_external_id:
          clear_type();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &type_.external_id_)));
          set_has_external_id();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.account.v1.IgrId)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.account.v1.IgrId)
  return false;
#undef DO_
}

void IgrId::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.account.v1.IgrId)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_account(), output);
  }

  // optional fixed32 external_id = 2;
  if (has_external_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->external_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.account.v1.IgrId)
}

::google::protobuf::uint8* IgrId::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.account.v1.IgrId)
  // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
  if (has_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->game_account(), target);
  }

  // optional fixed32 external_id = 2;
  if (has_external_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->external_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.account.v1.IgrId)
  return target;
}

int IgrId::ByteSize() const {
  int total_size = 0;

  switch (type_case()) {
    // optional .bgs.protocol.account.v1.GameAccountHandle game_account = 1;
    case kGameAccount: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_account());
      break;
    }
    // optional fixed32 external_id = 2;
    case kExternalId: {
      total_size += 1 + 4;
      break;
    }
    case TYPE_NOT_SET: {
      break;
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

void IgrId::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const IgrId* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const IgrId*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void IgrId::MergeFrom(const IgrId& from) {
  GOOGLE_CHECK_NE(&from, this);
  switch (from.type_case()) {
    case kGameAccount: {
      mutable_game_account()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.game_account());
      break;
    }
    case kExternalId: {
      set_external_id(from.external_id());
      break;
    }
    case TYPE_NOT_SET: {
      break;
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void IgrId::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void IgrId::CopyFrom(const IgrId& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool IgrId::IsInitialized() const {

  if (has_game_account()) {
    if (!this->game_account().IsInitialized()) return false;
  }
  return true;
}

void IgrId::Swap(IgrId* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(_oneof_case_[0], other->_oneof_case_[0]);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata IgrId::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = IgrId_descriptor_;
  metadata.reflection = IgrId_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace account
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
