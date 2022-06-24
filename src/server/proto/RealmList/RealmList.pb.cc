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
#include "RealmList.pb.h"

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

namespace JSON {
namespace RealmList {

namespace {

const ::google::protobuf::Descriptor* RealmListTicketIdentity_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmListTicketIdentity_reflection_ = NULL;
const ::google::protobuf::Descriptor* ClientVersion_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClientVersion_reflection_ = NULL;
const ::google::protobuf::Descriptor* ClientInformation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ClientInformation_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmListTicketClientInformation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmListTicketClientInformation_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmCharacterCountEntry_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmCharacterCountEntry_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmCharacterCountList_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmCharacterCountList_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmEntry_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmEntry_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmState_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmListUpdates_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmListUpdates_reflection_ = NULL;
const ::google::protobuf::Descriptor* IPAddress_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  IPAddress_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmIPAddressFamily_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmIPAddressFamily_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealmListServerIPAddresses_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealmListServerIPAddresses_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_RealmList_2eproto() {
  protobuf_AddDesc_RealmList_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "RealmList.proto");
  GOOGLE_CHECK(file != NULL);
  RealmListTicketIdentity_descriptor_ = file->message_type(0);
  static const int RealmListTicketIdentity_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketIdentity, gameaccountid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketIdentity, gameaccountregion_),
  };
  RealmListTicketIdentity_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmListTicketIdentity_descriptor_,
      RealmListTicketIdentity::default_instance_,
      RealmListTicketIdentity_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketIdentity, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketIdentity, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmListTicketIdentity));
  ClientVersion_descriptor_ = file->message_type(1);
  static const int ClientVersion_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, versionmajor_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, versionminor_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, versionrevision_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, versionbuild_),
  };
  ClientVersion_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClientVersion_descriptor_,
      ClientVersion::default_instance_,
      ClientVersion_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientVersion, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClientVersion));
  ClientInformation_descriptor_ = file->message_type(2);
  static const int ClientInformation_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, platform_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, buildvariant_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, timezone_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, currenttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, textlocale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, audiolocale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, versiondatabuild_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, secret_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, clientarch_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, systemversion_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, platformtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, systemarch_),
  };
  ClientInformation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ClientInformation_descriptor_,
      ClientInformation::default_instance_,
      ClientInformation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ClientInformation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ClientInformation));
  RealmListTicketClientInformation_descriptor_ = file->message_type(3);
  static const int RealmListTicketClientInformation_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketClientInformation, info_),
  };
  RealmListTicketClientInformation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmListTicketClientInformation_descriptor_,
      RealmListTicketClientInformation::default_instance_,
      RealmListTicketClientInformation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketClientInformation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListTicketClientInformation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmListTicketClientInformation));
  RealmCharacterCountEntry_descriptor_ = file->message_type(4);
  static const int RealmCharacterCountEntry_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountEntry, wowrealmaddress_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountEntry, count_),
  };
  RealmCharacterCountEntry_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmCharacterCountEntry_descriptor_,
      RealmCharacterCountEntry::default_instance_,
      RealmCharacterCountEntry_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountEntry, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountEntry, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmCharacterCountEntry));
  RealmCharacterCountList_descriptor_ = file->message_type(5);
  static const int RealmCharacterCountList_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountList, counts_),
  };
  RealmCharacterCountList_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmCharacterCountList_descriptor_,
      RealmCharacterCountList::default_instance_,
      RealmCharacterCountList_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountList, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmCharacterCountList, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmCharacterCountList));
  RealmEntry_descriptor_ = file->message_type(6);
  static const int RealmEntry_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, wowrealmaddress_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, cfgtimezonesid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, populationstate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, cfgcategoriesid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, cfgrealmsid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, flags_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, cfgconfigsid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, cfglanguagesid_),
  };
  RealmEntry_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmEntry_descriptor_,
      RealmEntry::default_instance_,
      RealmEntry_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmEntry, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmEntry));
  RealmState_descriptor_ = file->message_type(7);
  static const int RealmState_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmState, update_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmState, deleting_),
  };
  RealmState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmState_descriptor_,
      RealmState::default_instance_,
      RealmState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmState));
  RealmListUpdates_descriptor_ = file->message_type(8);
  static const int RealmListUpdates_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListUpdates, updates_),
  };
  RealmListUpdates_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmListUpdates_descriptor_,
      RealmListUpdates::default_instance_,
      RealmListUpdates_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListUpdates, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListUpdates, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmListUpdates));
  IPAddress_descriptor_ = file->message_type(9);
  static const int IPAddress_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IPAddress, ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IPAddress, port_),
  };
  IPAddress_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      IPAddress_descriptor_,
      IPAddress::default_instance_,
      IPAddress_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IPAddress, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IPAddress, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(IPAddress));
  RealmIPAddressFamily_descriptor_ = file->message_type(10);
  static const int RealmIPAddressFamily_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmIPAddressFamily, family_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmIPAddressFamily, addresses_),
  };
  RealmIPAddressFamily_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmIPAddressFamily_descriptor_,
      RealmIPAddressFamily::default_instance_,
      RealmIPAddressFamily_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmIPAddressFamily, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmIPAddressFamily, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmIPAddressFamily));
  RealmListServerIPAddresses_descriptor_ = file->message_type(11);
  static const int RealmListServerIPAddresses_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListServerIPAddresses, families_),
  };
  RealmListServerIPAddresses_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealmListServerIPAddresses_descriptor_,
      RealmListServerIPAddresses::default_instance_,
      RealmListServerIPAddresses_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListServerIPAddresses, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealmListServerIPAddresses, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealmListServerIPAddresses));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_RealmList_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmListTicketIdentity_descriptor_, &RealmListTicketIdentity::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClientVersion_descriptor_, &ClientVersion::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ClientInformation_descriptor_, &ClientInformation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmListTicketClientInformation_descriptor_, &RealmListTicketClientInformation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmCharacterCountEntry_descriptor_, &RealmCharacterCountEntry::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmCharacterCountList_descriptor_, &RealmCharacterCountList::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmEntry_descriptor_, &RealmEntry::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmState_descriptor_, &RealmState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmListUpdates_descriptor_, &RealmListUpdates::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    IPAddress_descriptor_, &IPAddress::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmIPAddressFamily_descriptor_, &RealmIPAddressFamily::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealmListServerIPAddresses_descriptor_, &RealmListServerIPAddresses::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_RealmList_2eproto() {
  delete RealmListTicketIdentity::default_instance_;
  delete RealmListTicketIdentity_reflection_;
  delete ClientVersion::default_instance_;
  delete ClientVersion_reflection_;
  delete ClientInformation::default_instance_;
  delete ClientInformation_reflection_;
  delete RealmListTicketClientInformation::default_instance_;
  delete RealmListTicketClientInformation_reflection_;
  delete RealmCharacterCountEntry::default_instance_;
  delete RealmCharacterCountEntry_reflection_;
  delete RealmCharacterCountList::default_instance_;
  delete RealmCharacterCountList_reflection_;
  delete RealmEntry::default_instance_;
  delete RealmEntry_reflection_;
  delete RealmState::default_instance_;
  delete RealmState_reflection_;
  delete RealmListUpdates::default_instance_;
  delete RealmListUpdates_reflection_;
  delete IPAddress::default_instance_;
  delete IPAddress_reflection_;
  delete RealmIPAddressFamily::default_instance_;
  delete RealmIPAddressFamily_reflection_;
  delete RealmListServerIPAddresses::default_instance_;
  delete RealmListServerIPAddresses_reflection_;
}

void protobuf_AddDesc_RealmList_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017RealmList.proto\022\016JSON.RealmList\"K\n\027Rea"
    "lmListTicketIdentity\022\025\n\rgameAccountID\030\001 "
    "\002(\007\022\031\n\021gameAccountRegion\030\002 \002(\r\"j\n\rClient"
    "Version\022\024\n\014versionMajor\030\001 \002(\r\022\024\n\014version"
    "Minor\030\002 \002(\r\022\027\n\017versionRevision\030\003 \002(\r\022\024\n\014"
    "versionBuild\030\004 \002(\007\"\310\002\n\021ClientInformation"
    "\022\020\n\010platform\030\001 \002(\007\022\024\n\014buildVariant\030\002 \002(\t"
    "\022\014\n\004type\030\003 \002(\007\022\020\n\010timeZone\030\004 \002(\t\022\023\n\013curr"
    "entTime\030\005 \002(\r\022\022\n\ntextLocale\030\006 \002(\007\022\023\n\013aud"
    "ioLocale\030\007 \002(\007\022\030\n\020versionDataBuild\030\010 \002(\007"
    "\022.\n\007version\030\t \002(\0132\035.JSON.RealmList.Clien"
    "tVersion\022\016\n\006secret\030\n \002(\014\022\022\n\nclientArch\030\013"
    " \002(\007\022\025\n\rsystemVersion\030\014 \002(\t\022\024\n\014platformT"
    "ype\030\r \002(\007\022\022\n\nsystemArch\030\016 \002(\007\"S\n RealmLi"
    "stTicketClientInformation\022/\n\004info\030\001 \002(\0132"
    "!.JSON.RealmList.ClientInformation\"B\n\030Re"
    "almCharacterCountEntry\022\027\n\017wowRealmAddres"
    "s\030\001 \002(\007\022\r\n\005count\030\002 \002(\r\"S\n\027RealmCharacter"
    "CountList\0228\n\006counts\030\001 \003(\0132(.JSON.RealmLi"
    "st.RealmCharacterCountEntry\"\377\001\n\nRealmEnt"
    "ry\022\027\n\017wowRealmAddress\030\001 \002(\007\022\026\n\016cfgTimezo"
    "nesID\030\002 \002(\r\022\027\n\017populationState\030\003 \002(\r\022\027\n\017"
    "cfgCategoriesID\030\004 \002(\r\022.\n\007version\030\005 \002(\0132\035"
    ".JSON.RealmList.ClientVersion\022\023\n\013cfgReal"
    "msID\030\006 \002(\r\022\r\n\005flags\030\007 \002(\r\022\014\n\004name\030\010 \002(\t\022"
    "\024\n\014cfgConfigsID\030\t \002(\r\022\026\n\016cfgLanguagesID\030"
    "\n \002(\r\"J\n\nRealmState\022*\n\006update\030\001 \001(\0132\032.JS"
    "ON.RealmList.RealmEntry\022\020\n\010deleting\030\002 \002("
    "\010\"\?\n\020RealmListUpdates\022+\n\007updates\030\001 \003(\0132\032"
    ".JSON.RealmList.RealmState\"%\n\tIPAddress\022"
    "\n\n\002ip\030\001 \002(\t\022\014\n\004port\030\002 \002(\r\"T\n\024RealmIPAddr"
    "essFamily\022\016\n\006family\030\001 \002(\r\022,\n\taddresses\030\002"
    " \003(\0132\031.JSON.RealmList.IPAddress\"T\n\032Realm"
    "ListServerIPAddresses\0226\n\010families\030\001 \003(\0132"
    "$.JSON.RealmList.RealmIPAddressFamilyB\002H"
    "\002", 1401);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "RealmList.proto", &protobuf_RegisterTypes);
  RealmListTicketIdentity::default_instance_ = new RealmListTicketIdentity();
  ClientVersion::default_instance_ = new ClientVersion();
  ClientInformation::default_instance_ = new ClientInformation();
  RealmListTicketClientInformation::default_instance_ = new RealmListTicketClientInformation();
  RealmCharacterCountEntry::default_instance_ = new RealmCharacterCountEntry();
  RealmCharacterCountList::default_instance_ = new RealmCharacterCountList();
  RealmEntry::default_instance_ = new RealmEntry();
  RealmState::default_instance_ = new RealmState();
  RealmListUpdates::default_instance_ = new RealmListUpdates();
  IPAddress::default_instance_ = new IPAddress();
  RealmIPAddressFamily::default_instance_ = new RealmIPAddressFamily();
  RealmListServerIPAddresses::default_instance_ = new RealmListServerIPAddresses();
  RealmListTicketIdentity::default_instance_->InitAsDefaultInstance();
  ClientVersion::default_instance_->InitAsDefaultInstance();
  ClientInformation::default_instance_->InitAsDefaultInstance();
  RealmListTicketClientInformation::default_instance_->InitAsDefaultInstance();
  RealmCharacterCountEntry::default_instance_->InitAsDefaultInstance();
  RealmCharacterCountList::default_instance_->InitAsDefaultInstance();
  RealmEntry::default_instance_->InitAsDefaultInstance();
  RealmState::default_instance_->InitAsDefaultInstance();
  RealmListUpdates::default_instance_->InitAsDefaultInstance();
  IPAddress::default_instance_->InitAsDefaultInstance();
  RealmIPAddressFamily::default_instance_->InitAsDefaultInstance();
  RealmListServerIPAddresses::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_RealmList_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_RealmList_2eproto {
  StaticDescriptorInitializer_RealmList_2eproto() {
    protobuf_AddDesc_RealmList_2eproto();
  }
} static_descriptor_initializer_RealmList_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RealmListTicketIdentity::kGameAccountIDFieldNumber;
const int RealmListTicketIdentity::kGameAccountRegionFieldNumber;
#endif  // !_MSC_VER

RealmListTicketIdentity::RealmListTicketIdentity()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmListTicketIdentity)
}

void RealmListTicketIdentity::InitAsDefaultInstance() {
}

RealmListTicketIdentity::RealmListTicketIdentity(const RealmListTicketIdentity& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmListTicketIdentity)
}

void RealmListTicketIdentity::SharedCtor() {
  _cached_size_ = 0;
  gameaccountid_ = 0u;
  gameaccountregion_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmListTicketIdentity::~RealmListTicketIdentity() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmListTicketIdentity)
  SharedDtor();
}

void RealmListTicketIdentity::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmListTicketIdentity::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmListTicketIdentity::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmListTicketIdentity_descriptor_;
}

const RealmListTicketIdentity& RealmListTicketIdentity::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmListTicketIdentity* RealmListTicketIdentity::default_instance_ = NULL;

RealmListTicketIdentity* RealmListTicketIdentity::New() const {
  return new RealmListTicketIdentity;
}

void RealmListTicketIdentity::Swap(RealmListTicketIdentity* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmListTicketIdentity::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmListTicketIdentity_descriptor_;
  metadata.reflection = RealmListTicketIdentity_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ClientVersion::kVersionMajorFieldNumber;
const int ClientVersion::kVersionMinorFieldNumber;
const int ClientVersion::kVersionRevisionFieldNumber;
const int ClientVersion::kVersionBuildFieldNumber;
#endif  // !_MSC_VER

ClientVersion::ClientVersion()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.ClientVersion)
}

void ClientVersion::InitAsDefaultInstance() {
}

ClientVersion::ClientVersion(const ClientVersion& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.ClientVersion)
}

void ClientVersion::SharedCtor() {
  _cached_size_ = 0;
  versionmajor_ = 0u;
  versionminor_ = 0u;
  versionrevision_ = 0u;
  versionbuild_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClientVersion::~ClientVersion() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.ClientVersion)
  SharedDtor();
}

void ClientVersion::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ClientVersion::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClientVersion::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientVersion_descriptor_;
}

const ClientVersion& ClientVersion::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

ClientVersion* ClientVersion::default_instance_ = NULL;

ClientVersion* ClientVersion::New() const {
  return new ClientVersion;
}

void ClientVersion::Swap(ClientVersion* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata ClientVersion::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClientVersion_descriptor_;
  metadata.reflection = ClientVersion_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ClientInformation::kPlatformFieldNumber;
const int ClientInformation::kBuildVariantFieldNumber;
const int ClientInformation::kTypeFieldNumber;
const int ClientInformation::kTimeZoneFieldNumber;
const int ClientInformation::kCurrentTimeFieldNumber;
const int ClientInformation::kTextLocaleFieldNumber;
const int ClientInformation::kAudioLocaleFieldNumber;
const int ClientInformation::kVersionDataBuildFieldNumber;
const int ClientInformation::kVersionFieldNumber;
const int ClientInformation::kSecretFieldNumber;
const int ClientInformation::kClientArchFieldNumber;
const int ClientInformation::kSystemVersionFieldNumber;
const int ClientInformation::kPlatformTypeFieldNumber;
const int ClientInformation::kSystemArchFieldNumber;
#endif  // !_MSC_VER

ClientInformation::ClientInformation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.ClientInformation)
}

void ClientInformation::InitAsDefaultInstance() {
  version_ = const_cast< ::JSON::RealmList::ClientVersion*>(&::JSON::RealmList::ClientVersion::default_instance());
}

ClientInformation::ClientInformation(const ClientInformation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.ClientInformation)
}

void ClientInformation::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  platform_ = 0u;
  buildvariant_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0u;
  timezone_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  currenttime_ = 0u;
  textlocale_ = 0u;
  audiolocale_ = 0u;
  versiondatabuild_ = 0u;
  version_ = NULL;
  secret_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clientarch_ = 0u;
  systemversion_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  platformtype_ = 0u;
  systemarch_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClientInformation::~ClientInformation() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.ClientInformation)
  SharedDtor();
}

void ClientInformation::SharedDtor() {
  if (buildvariant_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete buildvariant_;
  }
  if (timezone_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete timezone_;
  }
  if (secret_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete secret_;
  }
  if (systemversion_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete systemversion_;
  }
  if (this != default_instance_) {
    delete version_;
  }
}

void ClientInformation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ClientInformation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientInformation_descriptor_;
}

const ClientInformation& ClientInformation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

ClientInformation* ClientInformation::default_instance_ = NULL;

ClientInformation* ClientInformation::New() const {
  return new ClientInformation;
}

void ClientInformation::Swap(ClientInformation* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata ClientInformation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ClientInformation_descriptor_;
  metadata.reflection = ClientInformation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmListTicketClientInformation::kInfoFieldNumber;
#endif  // !_MSC_VER

RealmListTicketClientInformation::RealmListTicketClientInformation()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmListTicketClientInformation)
}

void RealmListTicketClientInformation::InitAsDefaultInstance() {
  info_ = const_cast< ::JSON::RealmList::ClientInformation*>(&::JSON::RealmList::ClientInformation::default_instance());
}

RealmListTicketClientInformation::RealmListTicketClientInformation(const RealmListTicketClientInformation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmListTicketClientInformation)
}

void RealmListTicketClientInformation::SharedCtor() {
  _cached_size_ = 0;
  info_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmListTicketClientInformation::~RealmListTicketClientInformation() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmListTicketClientInformation)
  SharedDtor();
}

void RealmListTicketClientInformation::SharedDtor() {
  if (this != default_instance_) {
    delete info_;
  }
}

void RealmListTicketClientInformation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmListTicketClientInformation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmListTicketClientInformation_descriptor_;
}

const RealmListTicketClientInformation& RealmListTicketClientInformation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmListTicketClientInformation* RealmListTicketClientInformation::default_instance_ = NULL;

RealmListTicketClientInformation* RealmListTicketClientInformation::New() const {
  return new RealmListTicketClientInformation;
}

void RealmListTicketClientInformation::Swap(RealmListTicketClientInformation* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmListTicketClientInformation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmListTicketClientInformation_descriptor_;
  metadata.reflection = RealmListTicketClientInformation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmCharacterCountEntry::kWowRealmAddressFieldNumber;
const int RealmCharacterCountEntry::kCountFieldNumber;
#endif  // !_MSC_VER

RealmCharacterCountEntry::RealmCharacterCountEntry()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmCharacterCountEntry)
}

void RealmCharacterCountEntry::InitAsDefaultInstance() {
}

RealmCharacterCountEntry::RealmCharacterCountEntry(const RealmCharacterCountEntry& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmCharacterCountEntry)
}

void RealmCharacterCountEntry::SharedCtor() {
  _cached_size_ = 0;
  wowrealmaddress_ = 0u;
  count_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmCharacterCountEntry::~RealmCharacterCountEntry() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmCharacterCountEntry)
  SharedDtor();
}

void RealmCharacterCountEntry::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmCharacterCountEntry::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmCharacterCountEntry::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmCharacterCountEntry_descriptor_;
}

const RealmCharacterCountEntry& RealmCharacterCountEntry::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmCharacterCountEntry* RealmCharacterCountEntry::default_instance_ = NULL;

RealmCharacterCountEntry* RealmCharacterCountEntry::New() const {
  return new RealmCharacterCountEntry;
}

void RealmCharacterCountEntry::Swap(RealmCharacterCountEntry* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmCharacterCountEntry::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmCharacterCountEntry_descriptor_;
  metadata.reflection = RealmCharacterCountEntry_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmCharacterCountList::kCountsFieldNumber;
#endif  // !_MSC_VER

RealmCharacterCountList::RealmCharacterCountList()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmCharacterCountList)
}

void RealmCharacterCountList::InitAsDefaultInstance() {
}

RealmCharacterCountList::RealmCharacterCountList(const RealmCharacterCountList& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmCharacterCountList)
}

void RealmCharacterCountList::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmCharacterCountList::~RealmCharacterCountList() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmCharacterCountList)
  SharedDtor();
}

void RealmCharacterCountList::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmCharacterCountList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmCharacterCountList::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmCharacterCountList_descriptor_;
}

const RealmCharacterCountList& RealmCharacterCountList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmCharacterCountList* RealmCharacterCountList::default_instance_ = NULL;

RealmCharacterCountList* RealmCharacterCountList::New() const {
  return new RealmCharacterCountList;
}

void RealmCharacterCountList::Swap(RealmCharacterCountList* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmCharacterCountList::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmCharacterCountList_descriptor_;
  metadata.reflection = RealmCharacterCountList_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmEntry::kWowRealmAddressFieldNumber;
const int RealmEntry::kCfgTimezonesIDFieldNumber;
const int RealmEntry::kPopulationStateFieldNumber;
const int RealmEntry::kCfgCategoriesIDFieldNumber;
const int RealmEntry::kVersionFieldNumber;
const int RealmEntry::kCfgRealmsIDFieldNumber;
const int RealmEntry::kFlagsFieldNumber;
const int RealmEntry::kNameFieldNumber;
const int RealmEntry::kCfgConfigsIDFieldNumber;
const int RealmEntry::kCfgLanguagesIDFieldNumber;
#endif  // !_MSC_VER

RealmEntry::RealmEntry()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmEntry)
}

void RealmEntry::InitAsDefaultInstance() {
  version_ = const_cast< ::JSON::RealmList::ClientVersion*>(&::JSON::RealmList::ClientVersion::default_instance());
}

RealmEntry::RealmEntry(const RealmEntry& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmEntry)
}

void RealmEntry::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  wowrealmaddress_ = 0u;
  cfgtimezonesid_ = 0u;
  populationstate_ = 0u;
  cfgcategoriesid_ = 0u;
  version_ = NULL;
  cfgrealmsid_ = 0u;
  flags_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cfgconfigsid_ = 0u;
  cfglanguagesid_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmEntry::~RealmEntry() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmEntry)
  SharedDtor();
}

void RealmEntry::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
    delete version_;
  }
}

void RealmEntry::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmEntry::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmEntry_descriptor_;
}

const RealmEntry& RealmEntry::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmEntry* RealmEntry::default_instance_ = NULL;

RealmEntry* RealmEntry::New() const {
  return new RealmEntry;
}

void RealmEntry::Swap(RealmEntry* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmEntry::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmEntry_descriptor_;
  metadata.reflection = RealmEntry_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmState::kUpdateFieldNumber;
const int RealmState::kDeletingFieldNumber;
#endif  // !_MSC_VER

RealmState::RealmState()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmState)
}

void RealmState::InitAsDefaultInstance() {
  update_ = const_cast< ::JSON::RealmList::RealmEntry*>(&::JSON::RealmList::RealmEntry::default_instance());
}

RealmState::RealmState(const RealmState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmState)
}

void RealmState::SharedCtor() {
  _cached_size_ = 0;
  update_ = NULL;
  deleting_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmState::~RealmState() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmState)
  SharedDtor();
}

void RealmState::SharedDtor() {
  if (this != default_instance_) {
    delete update_;
  }
}

void RealmState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmState_descriptor_;
}

const RealmState& RealmState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmState* RealmState::default_instance_ = NULL;

RealmState* RealmState::New() const {
  return new RealmState;
}

void RealmState::Swap(RealmState* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmState_descriptor_;
  metadata.reflection = RealmState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmListUpdates::kUpdatesFieldNumber;
#endif  // !_MSC_VER

RealmListUpdates::RealmListUpdates()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmListUpdates)
}

void RealmListUpdates::InitAsDefaultInstance() {
}

RealmListUpdates::RealmListUpdates(const RealmListUpdates& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmListUpdates)
}

void RealmListUpdates::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmListUpdates::~RealmListUpdates() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmListUpdates)
  SharedDtor();
}

void RealmListUpdates::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmListUpdates::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmListUpdates::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmListUpdates_descriptor_;
}

const RealmListUpdates& RealmListUpdates::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmListUpdates* RealmListUpdates::default_instance_ = NULL;

RealmListUpdates* RealmListUpdates::New() const {
  return new RealmListUpdates;
}

void RealmListUpdates::Swap(RealmListUpdates* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmListUpdates::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmListUpdates_descriptor_;
  metadata.reflection = RealmListUpdates_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int IPAddress::kIpFieldNumber;
const int IPAddress::kPortFieldNumber;
#endif  // !_MSC_VER

IPAddress::IPAddress()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.IPAddress)
}

void IPAddress::InitAsDefaultInstance() {
}

IPAddress::IPAddress(const IPAddress& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.IPAddress)
}

void IPAddress::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

IPAddress::~IPAddress() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.IPAddress)
  SharedDtor();
}

void IPAddress::SharedDtor() {
  if (ip_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete ip_;
  }
  if (this != default_instance_) {
  }
}

void IPAddress::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* IPAddress::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IPAddress_descriptor_;
}

const IPAddress& IPAddress::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

IPAddress* IPAddress::default_instance_ = NULL;

IPAddress* IPAddress::New() const {
  return new IPAddress;
}

void IPAddress::Swap(IPAddress* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata IPAddress::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = IPAddress_descriptor_;
  metadata.reflection = IPAddress_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmIPAddressFamily::kFamilyFieldNumber;
const int RealmIPAddressFamily::kAddressesFieldNumber;
#endif  // !_MSC_VER

RealmIPAddressFamily::RealmIPAddressFamily()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmIPAddressFamily)
}

void RealmIPAddressFamily::InitAsDefaultInstance() {
}

RealmIPAddressFamily::RealmIPAddressFamily(const RealmIPAddressFamily& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmIPAddressFamily)
}

void RealmIPAddressFamily::SharedCtor() {
  _cached_size_ = 0;
  family_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmIPAddressFamily::~RealmIPAddressFamily() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmIPAddressFamily)
  SharedDtor();
}

void RealmIPAddressFamily::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmIPAddressFamily::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmIPAddressFamily::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmIPAddressFamily_descriptor_;
}

const RealmIPAddressFamily& RealmIPAddressFamily::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmIPAddressFamily* RealmIPAddressFamily::default_instance_ = NULL;

RealmIPAddressFamily* RealmIPAddressFamily::New() const {
  return new RealmIPAddressFamily;
}

void RealmIPAddressFamily::Swap(RealmIPAddressFamily* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmIPAddressFamily::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmIPAddressFamily_descriptor_;
  metadata.reflection = RealmIPAddressFamily_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealmListServerIPAddresses::kFamiliesFieldNumber;
#endif  // !_MSC_VER

RealmListServerIPAddresses::RealmListServerIPAddresses()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:JSON.RealmList.RealmListServerIPAddresses)
}

void RealmListServerIPAddresses::InitAsDefaultInstance() {
}

RealmListServerIPAddresses::RealmListServerIPAddresses(const RealmListServerIPAddresses& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:JSON.RealmList.RealmListServerIPAddresses)
}

void RealmListServerIPAddresses::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealmListServerIPAddresses::~RealmListServerIPAddresses() {
  // @@protoc_insertion_point(destructor:JSON.RealmList.RealmListServerIPAddresses)
  SharedDtor();
}

void RealmListServerIPAddresses::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RealmListServerIPAddresses::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealmListServerIPAddresses::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealmListServerIPAddresses_descriptor_;
}

const RealmListServerIPAddresses& RealmListServerIPAddresses::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RealmList_2eproto();
  return *default_instance_;
}

RealmListServerIPAddresses* RealmListServerIPAddresses::default_instance_ = NULL;

RealmListServerIPAddresses* RealmListServerIPAddresses::New() const {
  return new RealmListServerIPAddresses;
}

void RealmListServerIPAddresses::Swap(RealmListServerIPAddresses* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata RealmListServerIPAddresses::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealmListServerIPAddresses_descriptor_;
  metadata.reflection = RealmListServerIPAddresses_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace RealmList
}  // namespace JSON

// @@protoc_insertion_point(global_scope)
