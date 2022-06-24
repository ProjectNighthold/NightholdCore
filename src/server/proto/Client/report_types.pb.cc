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
#include "report_types.pb.h"

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
namespace report {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ReportType_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ReportType_reflection_ = NULL;
struct ReportTypeOneofInstance {
  const ::bgs::protocol::report::v1::CustomReport* custom_report_;
  const ::bgs::protocol::report::v1::SpamReport* spam_report_;
  const ::bgs::protocol::report::v1::HarassmentReport* harassment_report_;
  const ::bgs::protocol::report::v1::RealLifeThreatReport* real_life_threat_report_;
  const ::bgs::protocol::report::v1::InappropriateBattleTagReport* inappropriate_battle_tag_report_;
  const ::bgs::protocol::report::v1::HackingReport* hacking_report_;
  const ::bgs::protocol::report::v1::BottingReport* botting_report_;
}* ReportType_default_oneof_instance_ = NULL;
const ::google::protobuf::Descriptor* CustomReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CustomReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* SpamReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SpamReport_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* SpamReport_SpamSource_descriptor_ = NULL;
const ::google::protobuf::Descriptor* HarassmentReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HarassmentReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* RealLifeThreatReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RealLifeThreatReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* InappropriateBattleTagReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InappropriateBattleTagReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* HackingReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HackingReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* BottingReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BottingReport_reflection_ = NULL;
const ::google::protobuf::Descriptor* Report_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Report_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_report_5ftypes_2eproto() {
  protobuf_AddDesc_report_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "report_types.proto");
  GOOGLE_CHECK(file != NULL);
  ReportType_descriptor_ = file->message_type(0);
  static const int ReportType_offsets_[9] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ReportType, note_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, custom_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, spam_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, harassment_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, real_life_threat_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, inappropriate_battle_tag_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, hacking_report_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(ReportType_default_oneof_instance_, botting_report_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ReportType, type_),
  };
  ReportType_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ReportType_descriptor_,
      ReportType::default_instance_,
      ReportType_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ReportType, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ReportType, _unknown_fields_),
      -1,
      ReportType_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ReportType, _oneof_case_[0]),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ReportType));
  CustomReport_descriptor_ = file->message_type(1);
  static const int CustomReport_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CustomReport, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CustomReport, programid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CustomReport, attribute_),
  };
  CustomReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CustomReport_descriptor_,
      CustomReport::default_instance_,
      CustomReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CustomReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CustomReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CustomReport));
  SpamReport_descriptor_ = file->message_type(2);
  static const int SpamReport_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpamReport, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpamReport, source_),
  };
  SpamReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SpamReport_descriptor_,
      SpamReport::default_instance_,
      SpamReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpamReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpamReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SpamReport));
  SpamReport_SpamSource_descriptor_ = SpamReport_descriptor_->enum_type(0);
  HarassmentReport_descriptor_ = file->message_type(3);
  static const int HarassmentReport_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HarassmentReport, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HarassmentReport, text_),
  };
  HarassmentReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HarassmentReport_descriptor_,
      HarassmentReport::default_instance_,
      HarassmentReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HarassmentReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HarassmentReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HarassmentReport));
  RealLifeThreatReport_descriptor_ = file->message_type(4);
  static const int RealLifeThreatReport_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealLifeThreatReport, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealLifeThreatReport, text_),
  };
  RealLifeThreatReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RealLifeThreatReport_descriptor_,
      RealLifeThreatReport::default_instance_,
      RealLifeThreatReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealLifeThreatReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RealLifeThreatReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RealLifeThreatReport));
  InappropriateBattleTagReport_descriptor_ = file->message_type(5);
  static const int InappropriateBattleTagReport_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InappropriateBattleTagReport, target_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InappropriateBattleTagReport, battle_tag_),
  };
  InappropriateBattleTagReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InappropriateBattleTagReport_descriptor_,
      InappropriateBattleTagReport::default_instance_,
      InappropriateBattleTagReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InappropriateBattleTagReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InappropriateBattleTagReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InappropriateBattleTagReport));
  HackingReport_descriptor_ = file->message_type(6);
  static const int HackingReport_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HackingReport, target_),
  };
  HackingReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HackingReport_descriptor_,
      HackingReport::default_instance_,
      HackingReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HackingReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HackingReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HackingReport));
  BottingReport_descriptor_ = file->message_type(7);
  static const int BottingReport_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BottingReport, target_),
  };
  BottingReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BottingReport_descriptor_,
      BottingReport::default_instance_,
      BottingReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BottingReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BottingReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BottingReport));
  Report_descriptor_ = file->message_type(8);
  static const int Report_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, report_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, attribute_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, report_qos_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, reporting_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, reporting_game_account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, report_timestamp_),
  };
  Report_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Report_descriptor_,
      Report::default_instance_,
      Report_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Report, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Report));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_report_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ReportType_descriptor_, &ReportType::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CustomReport_descriptor_, &CustomReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SpamReport_descriptor_, &SpamReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HarassmentReport_descriptor_, &HarassmentReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RealLifeThreatReport_descriptor_, &RealLifeThreatReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InappropriateBattleTagReport_descriptor_, &InappropriateBattleTagReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HackingReport_descriptor_, &HackingReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BottingReport_descriptor_, &BottingReport::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Report_descriptor_, &Report::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_report_5ftypes_2eproto() {
  delete ReportType::default_instance_;
  delete ReportType_default_oneof_instance_;
  delete ReportType_reflection_;
  delete CustomReport::default_instance_;
  delete CustomReport_reflection_;
  delete SpamReport::default_instance_;
  delete SpamReport_reflection_;
  delete HarassmentReport::default_instance_;
  delete HarassmentReport_reflection_;
  delete RealLifeThreatReport::default_instance_;
  delete RealLifeThreatReport_reflection_;
  delete InappropriateBattleTagReport::default_instance_;
  delete InappropriateBattleTagReport_reflection_;
  delete HackingReport::default_instance_;
  delete HackingReport_reflection_;
  delete BottingReport::default_instance_;
  delete BottingReport_reflection_;
  delete Report::default_instance_;
  delete Report_reflection_;
}

void protobuf_AddDesc_report_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::account::v1::protobuf_AddDesc_account_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_attribute_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_entity_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022report_types.proto\022\026bgs.protocol.repor"
    "t.v1\032\023account_types.proto\032\025attribute_typ"
    "es.proto\032\022entity_types.proto\032\017rpc_types."
    "proto\"\227\004\n\nReportType\022\014\n\004note\030\001 \001(\t\022=\n\rcu"
    "stom_report\030\n \001(\0132$.bgs.protocol.report."
    "v1.CustomReportH\000\0229\n\013spam_report\030\013 \001(\0132\""
    ".bgs.protocol.report.v1.SpamReportH\000\022E\n\021"
    "harassment_report\030\014 \001(\0132(.bgs.protocol.r"
    "eport.v1.HarassmentReportH\000\022O\n\027real_life"
    "_threat_report\030\r \001(\0132,.bgs.protocol.repo"
    "rt.v1.RealLifeThreatReportH\000\022_\n\037inapprop"
    "riate_battle_tag_report\030\016 \001(\01324.bgs.prot"
    "ocol.report.v1.InappropriateBattleTagRep"
    "ortH\000\022\?\n\016hacking_report\030\017 \001(\0132%.bgs.prot"
    "ocol.report.v1.HackingReportH\000\022\?\n\016bottin"
    "g_report\030\020 \001(\0132%.bgs.protocol.report.v1."
    "BottingReportH\000B\006\n\004type\"[\n\014CustomReport\022"
    "\014\n\004type\030\001 \001(\t\022\021\n\tprogramId\030\002 \001(\t\022*\n\tattr"
    "ibute\030\003 \003(\0132\027.bgs.protocol.Attribute\"\321\001\n"
    "\nSpamReport\022:\n\006target\030\001 \001(\0132*.bgs.protoc"
    "ol.account.v1.GameAccountHandle\022D\n\006sourc"
    "e\030\002 \001(\0162-.bgs.protocol.report.v1.SpamRep"
    "ort.SpamSource:\005OTHER\"A\n\nSpamSource\022\t\n\005O"
    "THER\020\001\022\021\n\rFRIEND_INVITE\020\002\022\013\n\007WHISPER\020\003\022\010"
    "\n\004CHAT\020\004\"\\\n\020HarassmentReport\022:\n\006target\030\001"
    " \001(\0132*.bgs.protocol.account.v1.GameAccou"
    "ntHandle\022\014\n\004text\030\002 \001(\t\"`\n\024RealLifeThreat"
    "Report\022:\n\006target\030\001 \001(\0132*.bgs.protocol.ac"
    "count.v1.GameAccountHandle\022\014\n\004text\030\002 \001(\t"
    "\"n\n\034InappropriateBattleTagReport\022:\n\006targ"
    "et\030\001 \001(\0132*.bgs.protocol.account.v1.GameA"
    "ccountHandle\022\022\n\nbattle_tag\030\002 \001(\t\"K\n\rHack"
    "ingReport\022:\n\006target\030\001 \001(\0132*.bgs.protocol"
    ".account.v1.GameAccountHandle\"K\n\rBotting"
    "Report\022:\n\006target\030\001 \001(\0132*.bgs.protocol.ac"
    "count.v1.GameAccountHandle\"\345\001\n\006Report\022\023\n"
    "\013report_type\030\001 \002(\t\022*\n\tattribute\030\002 \003(\0132\027."
    "bgs.protocol.Attribute\022\025\n\nreport_qos\030\003 \001"
    "(\005:\0010\0221\n\021reporting_account\030\004 \001(\0132\026.bgs.p"
    "rotocol.EntityId\0226\n\026reporting_game_accou"
    "nt\030\005 \001(\0132\026.bgs.protocol.EntityId\022\030\n\020repo"
    "rt_timestamp\030\006 \001(\006B\005H\001\200\001\000", 1665);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "report_types.proto", &protobuf_RegisterTypes);
  ReportType::default_instance_ = new ReportType();
  ReportType_default_oneof_instance_ = new ReportTypeOneofInstance;
  CustomReport::default_instance_ = new CustomReport();
  SpamReport::default_instance_ = new SpamReport();
  HarassmentReport::default_instance_ = new HarassmentReport();
  RealLifeThreatReport::default_instance_ = new RealLifeThreatReport();
  InappropriateBattleTagReport::default_instance_ = new InappropriateBattleTagReport();
  HackingReport::default_instance_ = new HackingReport();
  BottingReport::default_instance_ = new BottingReport();
  Report::default_instance_ = new Report();
  ReportType::default_instance_->InitAsDefaultInstance();
  CustomReport::default_instance_->InitAsDefaultInstance();
  SpamReport::default_instance_->InitAsDefaultInstance();
  HarassmentReport::default_instance_->InitAsDefaultInstance();
  RealLifeThreatReport::default_instance_->InitAsDefaultInstance();
  InappropriateBattleTagReport::default_instance_->InitAsDefaultInstance();
  HackingReport::default_instance_->InitAsDefaultInstance();
  BottingReport::default_instance_->InitAsDefaultInstance();
  Report::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_report_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_report_5ftypes_2eproto {
  StaticDescriptorInitializer_report_5ftypes_2eproto() {
    protobuf_AddDesc_report_5ftypes_2eproto();
  }
} static_descriptor_initializer_report_5ftypes_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ReportType::kNoteFieldNumber;
const int ReportType::kCustomReportFieldNumber;
const int ReportType::kSpamReportFieldNumber;
const int ReportType::kHarassmentReportFieldNumber;
const int ReportType::kRealLifeThreatReportFieldNumber;
const int ReportType::kInappropriateBattleTagReportFieldNumber;
const int ReportType::kHackingReportFieldNumber;
const int ReportType::kBottingReportFieldNumber;
#endif  // !_MSC_VER

ReportType::ReportType()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.ReportType)
}

void ReportType::InitAsDefaultInstance() {
  ReportType_default_oneof_instance_->custom_report_ = const_cast< ::bgs::protocol::report::v1::CustomReport*>(&::bgs::protocol::report::v1::CustomReport::default_instance());
  ReportType_default_oneof_instance_->spam_report_ = const_cast< ::bgs::protocol::report::v1::SpamReport*>(&::bgs::protocol::report::v1::SpamReport::default_instance());
  ReportType_default_oneof_instance_->harassment_report_ = const_cast< ::bgs::protocol::report::v1::HarassmentReport*>(&::bgs::protocol::report::v1::HarassmentReport::default_instance());
  ReportType_default_oneof_instance_->real_life_threat_report_ = const_cast< ::bgs::protocol::report::v1::RealLifeThreatReport*>(&::bgs::protocol::report::v1::RealLifeThreatReport::default_instance());
  ReportType_default_oneof_instance_->inappropriate_battle_tag_report_ = const_cast< ::bgs::protocol::report::v1::InappropriateBattleTagReport*>(&::bgs::protocol::report::v1::InappropriateBattleTagReport::default_instance());
  ReportType_default_oneof_instance_->hacking_report_ = const_cast< ::bgs::protocol::report::v1::HackingReport*>(&::bgs::protocol::report::v1::HackingReport::default_instance());
  ReportType_default_oneof_instance_->botting_report_ = const_cast< ::bgs::protocol::report::v1::BottingReport*>(&::bgs::protocol::report::v1::BottingReport::default_instance());
}

ReportType::ReportType(const ReportType& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.ReportType)
}

void ReportType::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  note_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  clear_has_type();
}

ReportType::~ReportType() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.ReportType)
  SharedDtor();
}

void ReportType::SharedDtor() {
  if (note_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete note_;
  }
  if (has_type()) {
    clear_type();
  }
  if (this != default_instance_) {
  }
}

void ReportType::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ReportType::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ReportType_descriptor_;
}

const ReportType& ReportType::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

ReportType* ReportType::default_instance_ = NULL;

ReportType* ReportType::New() const {
  return new ReportType;
}

void ReportType::clear_type() {
  switch(type_case()) {
    case kCustomReport: {
      delete type_.custom_report_;
      break;
    }
    case kSpamReport: {
      delete type_.spam_report_;
      break;
    }
    case kHarassmentReport: {
      delete type_.harassment_report_;
      break;
    }
    case kRealLifeThreatReport: {
      delete type_.real_life_threat_report_;
      break;
    }
    case kInappropriateBattleTagReport: {
      delete type_.inappropriate_battle_tag_report_;
      break;
    }
    case kHackingReport: {
      delete type_.hacking_report_;
      break;
    }
    case kBottingReport: {
      delete type_.botting_report_;
      break;
    }
    case TYPE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = TYPE_NOT_SET;
}


void ReportType::Clear() {
  if (has_note()) {
    if (note_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      note_->clear();
    }
  }
  clear_type();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ReportType::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.ReportType)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string note = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_note()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->note().data(), this->note().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "note");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_custom_report;
        break;
      }

      // optional .bgs.protocol.report.v1.CustomReport custom_report = 10;
      case 10: {
        if (tag == 82) {
         parse_custom_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_custom_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_spam_report;
        break;
      }

      // optional .bgs.protocol.report.v1.SpamReport spam_report = 11;
      case 11: {
        if (tag == 90) {
         parse_spam_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_spam_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_harassment_report;
        break;
      }

      // optional .bgs.protocol.report.v1.HarassmentReport harassment_report = 12;
      case 12: {
        if (tag == 98) {
         parse_harassment_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_harassment_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_real_life_threat_report;
        break;
      }

      // optional .bgs.protocol.report.v1.RealLifeThreatReport real_life_threat_report = 13;
      case 13: {
        if (tag == 106) {
         parse_real_life_threat_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_real_life_threat_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(114)) goto parse_inappropriate_battle_tag_report;
        break;
      }

      // optional .bgs.protocol.report.v1.InappropriateBattleTagReport inappropriate_battle_tag_report = 14;
      case 14: {
        if (tag == 114) {
         parse_inappropriate_battle_tag_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_inappropriate_battle_tag_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(122)) goto parse_hacking_report;
        break;
      }

      // optional .bgs.protocol.report.v1.HackingReport hacking_report = 15;
      case 15: {
        if (tag == 122) {
         parse_hacking_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_hacking_report()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(130)) goto parse_botting_report;
        break;
      }

      // optional .bgs.protocol.report.v1.BottingReport botting_report = 16;
      case 16: {
        if (tag == 130) {
         parse_botting_report:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_botting_report()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.ReportType)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.ReportType)
  return false;
#undef DO_
}

void ReportType::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.ReportType)
  // optional string note = 1;
  if (has_note()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->note().data(), this->note().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "note");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->note(), output);
  }

  // optional .bgs.protocol.report.v1.CustomReport custom_report = 10;
  if (has_custom_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->custom_report(), output);
  }

  // optional .bgs.protocol.report.v1.SpamReport spam_report = 11;
  if (has_spam_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->spam_report(), output);
  }

  // optional .bgs.protocol.report.v1.HarassmentReport harassment_report = 12;
  if (has_harassment_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->harassment_report(), output);
  }

  // optional .bgs.protocol.report.v1.RealLifeThreatReport real_life_threat_report = 13;
  if (has_real_life_threat_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      13, this->real_life_threat_report(), output);
  }

  // optional .bgs.protocol.report.v1.InappropriateBattleTagReport inappropriate_battle_tag_report = 14;
  if (has_inappropriate_battle_tag_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      14, this->inappropriate_battle_tag_report(), output);
  }

  // optional .bgs.protocol.report.v1.HackingReport hacking_report = 15;
  if (has_hacking_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      15, this->hacking_report(), output);
  }

  // optional .bgs.protocol.report.v1.BottingReport botting_report = 16;
  if (has_botting_report()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      16, this->botting_report(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.ReportType)
}

::google::protobuf::uint8* ReportType::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.ReportType)
  // optional string note = 1;
  if (has_note()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->note().data(), this->note().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "note");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->note(), target);
  }

  // optional .bgs.protocol.report.v1.CustomReport custom_report = 10;
  if (has_custom_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->custom_report(), target);
  }

  // optional .bgs.protocol.report.v1.SpamReport spam_report = 11;
  if (has_spam_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->spam_report(), target);
  }

  // optional .bgs.protocol.report.v1.HarassmentReport harassment_report = 12;
  if (has_harassment_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->harassment_report(), target);
  }

  // optional .bgs.protocol.report.v1.RealLifeThreatReport real_life_threat_report = 13;
  if (has_real_life_threat_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        13, this->real_life_threat_report(), target);
  }

  // optional .bgs.protocol.report.v1.InappropriateBattleTagReport inappropriate_battle_tag_report = 14;
  if (has_inappropriate_battle_tag_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        14, this->inappropriate_battle_tag_report(), target);
  }

  // optional .bgs.protocol.report.v1.HackingReport hacking_report = 15;
  if (has_hacking_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        15, this->hacking_report(), target);
  }

  // optional .bgs.protocol.report.v1.BottingReport botting_report = 16;
  if (has_botting_report()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        16, this->botting_report(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.ReportType)
  return target;
}

int ReportType::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string note = 1;
    if (has_note()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->note());
    }

  }
  switch (type_case()) {
    // optional .bgs.protocol.report.v1.CustomReport custom_report = 10;
    case kCustomReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->custom_report());
      break;
    }
    // optional .bgs.protocol.report.v1.SpamReport spam_report = 11;
    case kSpamReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->spam_report());
      break;
    }
    // optional .bgs.protocol.report.v1.HarassmentReport harassment_report = 12;
    case kHarassmentReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->harassment_report());
      break;
    }
    // optional .bgs.protocol.report.v1.RealLifeThreatReport real_life_threat_report = 13;
    case kRealLifeThreatReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->real_life_threat_report());
      break;
    }
    // optional .bgs.protocol.report.v1.InappropriateBattleTagReport inappropriate_battle_tag_report = 14;
    case kInappropriateBattleTagReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->inappropriate_battle_tag_report());
      break;
    }
    // optional .bgs.protocol.report.v1.HackingReport hacking_report = 15;
    case kHackingReport: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->hacking_report());
      break;
    }
    // optional .bgs.protocol.report.v1.BottingReport botting_report = 16;
    case kBottingReport: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->botting_report());
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

void ReportType::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ReportType* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ReportType*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ReportType::MergeFrom(const ReportType& from) {
  GOOGLE_CHECK_NE(&from, this);
  switch (from.type_case()) {
    case kCustomReport: {
      mutable_custom_report()->::bgs::protocol::report::v1::CustomReport::MergeFrom(from.custom_report());
      break;
    }
    case kSpamReport: {
      mutable_spam_report()->::bgs::protocol::report::v1::SpamReport::MergeFrom(from.spam_report());
      break;
    }
    case kHarassmentReport: {
      mutable_harassment_report()->::bgs::protocol::report::v1::HarassmentReport::MergeFrom(from.harassment_report());
      break;
    }
    case kRealLifeThreatReport: {
      mutable_real_life_threat_report()->::bgs::protocol::report::v1::RealLifeThreatReport::MergeFrom(from.real_life_threat_report());
      break;
    }
    case kInappropriateBattleTagReport: {
      mutable_inappropriate_battle_tag_report()->::bgs::protocol::report::v1::InappropriateBattleTagReport::MergeFrom(from.inappropriate_battle_tag_report());
      break;
    }
    case kHackingReport: {
      mutable_hacking_report()->::bgs::protocol::report::v1::HackingReport::MergeFrom(from.hacking_report());
      break;
    }
    case kBottingReport: {
      mutable_botting_report()->::bgs::protocol::report::v1::BottingReport::MergeFrom(from.botting_report());
      break;
    }
    case TYPE_NOT_SET: {
      break;
    }
  }
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_note()) {
      set_note(from.note());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ReportType::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ReportType::CopyFrom(const ReportType& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReportType::IsInitialized() const {

  if (has_custom_report()) {
    if (!this->custom_report().IsInitialized()) return false;
  }
  if (has_spam_report()) {
    if (!this->spam_report().IsInitialized()) return false;
  }
  if (has_harassment_report()) {
    if (!this->harassment_report().IsInitialized()) return false;
  }
  if (has_real_life_threat_report()) {
    if (!this->real_life_threat_report().IsInitialized()) return false;
  }
  if (has_inappropriate_battle_tag_report()) {
    if (!this->inappropriate_battle_tag_report().IsInitialized()) return false;
  }
  if (has_hacking_report()) {
    if (!this->hacking_report().IsInitialized()) return false;
  }
  if (has_botting_report()) {
    if (!this->botting_report().IsInitialized()) return false;
  }
  return true;
}

void ReportType::Swap(ReportType* other) {
  if (other != this) {
    std::swap(note_, other->note_);
    std::swap(type_, other->type_);
    std::swap(_oneof_case_[0], other->_oneof_case_[0]);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ReportType::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ReportType_descriptor_;
  metadata.reflection = ReportType_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CustomReport::kTypeFieldNumber;
const int CustomReport::kProgramIdFieldNumber;
const int CustomReport::kAttributeFieldNumber;
#endif  // !_MSC_VER

CustomReport::CustomReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.CustomReport)
}

void CustomReport::InitAsDefaultInstance() {
}

CustomReport::CustomReport(const CustomReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.CustomReport)
}

void CustomReport::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  programid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CustomReport::~CustomReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.CustomReport)
  SharedDtor();
}

void CustomReport::SharedDtor() {
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (programid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete programid_;
  }
  if (this != default_instance_) {
  }
}

void CustomReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CustomReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CustomReport_descriptor_;
}

const CustomReport& CustomReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

CustomReport* CustomReport::default_instance_ = NULL;

CustomReport* CustomReport::New() const {
  return new CustomReport;
}

void CustomReport::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_type()) {
      if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        type_->clear();
      }
    }
    if (has_programid()) {
      if (programid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        programid_->clear();
      }
    }
  }
  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CustomReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.CustomReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string type = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->type().data(), this->type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_programId;
        break;
      }

      // optional string programId = 2;
      case 2: {
        if (tag == 18) {
         parse_programId:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_programid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->programid().data(), this->programid().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "programid");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.CustomReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.CustomReport)
  return false;
#undef DO_
}

void CustomReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.CustomReport)
  // optional string type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->type(), output);
  }

  // optional string programId = 2;
  if (has_programid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->programid().data(), this->programid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "programid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->programid(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->attribute(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.CustomReport)
}

::google::protobuf::uint8* CustomReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.CustomReport)
  // optional string type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->type(), target);
  }

  // optional string programId = 2;
  if (has_programid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->programid().data(), this->programid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "programid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->programid(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 3;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->attribute(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.CustomReport)
  return target;
}

int CustomReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
    }

    // optional string programId = 2;
    if (has_programid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->programid());
    }

  }
  // repeated .bgs.protocol.Attribute attribute = 3;
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

void CustomReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CustomReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CustomReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CustomReport::MergeFrom(const CustomReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_programid()) {
      set_programid(from.programid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CustomReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CustomReport::CopyFrom(const CustomReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CustomReport::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  return true;
}

void CustomReport::Swap(CustomReport* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(programid_, other->programid_);
    attribute_.Swap(&other->attribute_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CustomReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CustomReport_descriptor_;
  metadata.reflection = CustomReport_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* SpamReport_SpamSource_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SpamReport_SpamSource_descriptor_;
}
bool SpamReport_SpamSource_IsValid(int value) {
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
const SpamReport_SpamSource SpamReport::OTHER;
const SpamReport_SpamSource SpamReport::FRIEND_INVITE;
const SpamReport_SpamSource SpamReport::WHISPER;
const SpamReport_SpamSource SpamReport::CHAT;
const SpamReport_SpamSource SpamReport::SpamSource_MIN;
const SpamReport_SpamSource SpamReport::SpamSource_MAX;
const int SpamReport::SpamSource_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int SpamReport::kTargetFieldNumber;
const int SpamReport::kSourceFieldNumber;
#endif  // !_MSC_VER

SpamReport::SpamReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.SpamReport)
}

void SpamReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

SpamReport::SpamReport(const SpamReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.SpamReport)
}

void SpamReport::SharedCtor() {
  _cached_size_ = 0;
  target_ = NULL;
  source_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SpamReport::~SpamReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.SpamReport)
  SharedDtor();
}

void SpamReport::SharedDtor() {
  if (this != default_instance_) {
    delete target_;
  }
}

void SpamReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SpamReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SpamReport_descriptor_;
}

const SpamReport& SpamReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

SpamReport* SpamReport::default_instance_ = NULL;

SpamReport* SpamReport::New() const {
  return new SpamReport;
}

void SpamReport::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    source_ = 1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SpamReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.SpamReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_source;
        break;
      }

      // optional .bgs.protocol.report.v1.SpamReport.SpamSource source = 2 [default = OTHER];
      case 2: {
        if (tag == 16) {
         parse_source:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::bgs::protocol::report::v1::SpamReport_SpamSource_IsValid(value)) {
            set_source(static_cast< ::bgs::protocol::report::v1::SpamReport_SpamSource >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.SpamReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.SpamReport)
  return false;
#undef DO_
}

void SpamReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.SpamReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  // optional .bgs.protocol.report.v1.SpamReport.SpamSource source = 2 [default = OTHER];
  if (has_source()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->source(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.SpamReport)
}

::google::protobuf::uint8* SpamReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.SpamReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  // optional .bgs.protocol.report.v1.SpamReport.SpamSource source = 2 [default = OTHER];
  if (has_source()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->source(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.SpamReport)
  return target;
}

int SpamReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
    }

    // optional .bgs.protocol.report.v1.SpamReport.SpamSource source = 2 [default = OTHER];
    if (has_source()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->source());
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

void SpamReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SpamReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SpamReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SpamReport::MergeFrom(const SpamReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
    if (from.has_source()) {
      set_source(from.source());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SpamReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SpamReport::CopyFrom(const SpamReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SpamReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void SpamReport::Swap(SpamReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(source_, other->source_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SpamReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SpamReport_descriptor_;
  metadata.reflection = SpamReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int HarassmentReport::kTargetFieldNumber;
const int HarassmentReport::kTextFieldNumber;
#endif  // !_MSC_VER

HarassmentReport::HarassmentReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.HarassmentReport)
}

void HarassmentReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

HarassmentReport::HarassmentReport(const HarassmentReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.HarassmentReport)
}

void HarassmentReport::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  target_ = NULL;
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HarassmentReport::~HarassmentReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.HarassmentReport)
  SharedDtor();
}

void HarassmentReport::SharedDtor() {
  if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete text_;
  }
  if (this != default_instance_) {
    delete target_;
  }
}

void HarassmentReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HarassmentReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HarassmentReport_descriptor_;
}

const HarassmentReport& HarassmentReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

HarassmentReport* HarassmentReport::default_instance_ = NULL;

HarassmentReport* HarassmentReport::New() const {
  return new HarassmentReport;
}

void HarassmentReport::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        text_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HarassmentReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.HarassmentReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_text;
        break;
      }

      // optional string text = 2;
      case 2: {
        if (tag == 18) {
         parse_text:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "text");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.HarassmentReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.HarassmentReport)
  return false;
#undef DO_
}

void HarassmentReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.HarassmentReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  // optional string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->text(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.HarassmentReport)
}

::google::protobuf::uint8* HarassmentReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.HarassmentReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  // optional string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->text(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.HarassmentReport)
  return target;
}

int HarassmentReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
    }

    // optional string text = 2;
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
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

void HarassmentReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HarassmentReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HarassmentReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HarassmentReport::MergeFrom(const HarassmentReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
    if (from.has_text()) {
      set_text(from.text());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HarassmentReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HarassmentReport::CopyFrom(const HarassmentReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HarassmentReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void HarassmentReport::Swap(HarassmentReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(text_, other->text_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HarassmentReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HarassmentReport_descriptor_;
  metadata.reflection = HarassmentReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RealLifeThreatReport::kTargetFieldNumber;
const int RealLifeThreatReport::kTextFieldNumber;
#endif  // !_MSC_VER

RealLifeThreatReport::RealLifeThreatReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.RealLifeThreatReport)
}

void RealLifeThreatReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

RealLifeThreatReport::RealLifeThreatReport(const RealLifeThreatReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.RealLifeThreatReport)
}

void RealLifeThreatReport::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  target_ = NULL;
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RealLifeThreatReport::~RealLifeThreatReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.RealLifeThreatReport)
  SharedDtor();
}

void RealLifeThreatReport::SharedDtor() {
  if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete text_;
  }
  if (this != default_instance_) {
    delete target_;
  }
}

void RealLifeThreatReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RealLifeThreatReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RealLifeThreatReport_descriptor_;
}

const RealLifeThreatReport& RealLifeThreatReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

RealLifeThreatReport* RealLifeThreatReport::default_instance_ = NULL;

RealLifeThreatReport* RealLifeThreatReport::New() const {
  return new RealLifeThreatReport;
}

void RealLifeThreatReport::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        text_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RealLifeThreatReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.RealLifeThreatReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_text;
        break;
      }

      // optional string text = 2;
      case 2: {
        if (tag == 18) {
         parse_text:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "text");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.RealLifeThreatReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.RealLifeThreatReport)
  return false;
#undef DO_
}

void RealLifeThreatReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.RealLifeThreatReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  // optional string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->text(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.RealLifeThreatReport)
}

::google::protobuf::uint8* RealLifeThreatReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.RealLifeThreatReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  // optional string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->text(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.RealLifeThreatReport)
  return target;
}

int RealLifeThreatReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
    }

    // optional string text = 2;
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
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

void RealLifeThreatReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RealLifeThreatReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RealLifeThreatReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RealLifeThreatReport::MergeFrom(const RealLifeThreatReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
    if (from.has_text()) {
      set_text(from.text());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RealLifeThreatReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RealLifeThreatReport::CopyFrom(const RealLifeThreatReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RealLifeThreatReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void RealLifeThreatReport::Swap(RealLifeThreatReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(text_, other->text_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RealLifeThreatReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RealLifeThreatReport_descriptor_;
  metadata.reflection = RealLifeThreatReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InappropriateBattleTagReport::kTargetFieldNumber;
const int InappropriateBattleTagReport::kBattleTagFieldNumber;
#endif  // !_MSC_VER

InappropriateBattleTagReport::InappropriateBattleTagReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.InappropriateBattleTagReport)
}

void InappropriateBattleTagReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

InappropriateBattleTagReport::InappropriateBattleTagReport(const InappropriateBattleTagReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.InappropriateBattleTagReport)
}

void InappropriateBattleTagReport::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  target_ = NULL;
  battle_tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InappropriateBattleTagReport::~InappropriateBattleTagReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.InappropriateBattleTagReport)
  SharedDtor();
}

void InappropriateBattleTagReport::SharedDtor() {
  if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete battle_tag_;
  }
  if (this != default_instance_) {
    delete target_;
  }
}

void InappropriateBattleTagReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InappropriateBattleTagReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InappropriateBattleTagReport_descriptor_;
}

const InappropriateBattleTagReport& InappropriateBattleTagReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

InappropriateBattleTagReport* InappropriateBattleTagReport::default_instance_ = NULL;

InappropriateBattleTagReport* InappropriateBattleTagReport::New() const {
  return new InappropriateBattleTagReport;
}

void InappropriateBattleTagReport::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_target()) {
      if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
    }
    if (has_battle_tag()) {
      if (battle_tag_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        battle_tag_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InappropriateBattleTagReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.InappropriateBattleTagReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_battle_tag;
        break;
      }

      // optional string battle_tag = 2;
      case 2: {
        if (tag == 18) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.InappropriateBattleTagReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.InappropriateBattleTagReport)
  return false;
#undef DO_
}

void InappropriateBattleTagReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.InappropriateBattleTagReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  // optional string battle_tag = 2;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->battle_tag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.InappropriateBattleTagReport)
}

::google::protobuf::uint8* InappropriateBattleTagReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.InappropriateBattleTagReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  // optional string battle_tag = 2;
  if (has_battle_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->battle_tag().data(), this->battle_tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "battle_tag");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->battle_tag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.InappropriateBattleTagReport)
  return target;
}

int InappropriateBattleTagReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
    }

    // optional string battle_tag = 2;
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

void InappropriateBattleTagReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InappropriateBattleTagReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InappropriateBattleTagReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InappropriateBattleTagReport::MergeFrom(const InappropriateBattleTagReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
    if (from.has_battle_tag()) {
      set_battle_tag(from.battle_tag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InappropriateBattleTagReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InappropriateBattleTagReport::CopyFrom(const InappropriateBattleTagReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InappropriateBattleTagReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void InappropriateBattleTagReport::Swap(InappropriateBattleTagReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(battle_tag_, other->battle_tag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata InappropriateBattleTagReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InappropriateBattleTagReport_descriptor_;
  metadata.reflection = InappropriateBattleTagReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int HackingReport::kTargetFieldNumber;
#endif  // !_MSC_VER

HackingReport::HackingReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.HackingReport)
}

void HackingReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

HackingReport::HackingReport(const HackingReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.HackingReport)
}

void HackingReport::SharedCtor() {
  _cached_size_ = 0;
  target_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HackingReport::~HackingReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.HackingReport)
  SharedDtor();
}

void HackingReport::SharedDtor() {
  if (this != default_instance_) {
    delete target_;
  }
}

void HackingReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HackingReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HackingReport_descriptor_;
}

const HackingReport& HackingReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

HackingReport* HackingReport::default_instance_ = NULL;

HackingReport* HackingReport::New() const {
  return new HackingReport;
}

void HackingReport::Clear() {
  if (has_target()) {
    if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HackingReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.HackingReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.HackingReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.HackingReport)
  return false;
#undef DO_
}

void HackingReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.HackingReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.HackingReport)
}

::google::protobuf::uint8* HackingReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.HackingReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.HackingReport)
  return target;
}

int HackingReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
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

void HackingReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HackingReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HackingReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HackingReport::MergeFrom(const HackingReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HackingReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HackingReport::CopyFrom(const HackingReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HackingReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void HackingReport::Swap(HackingReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HackingReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HackingReport_descriptor_;
  metadata.reflection = HackingReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BottingReport::kTargetFieldNumber;
#endif  // !_MSC_VER

BottingReport::BottingReport()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.BottingReport)
}

void BottingReport::InitAsDefaultInstance() {
  target_ = const_cast< ::bgs::protocol::account::v1::GameAccountHandle*>(&::bgs::protocol::account::v1::GameAccountHandle::default_instance());
}

BottingReport::BottingReport(const BottingReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.BottingReport)
}

void BottingReport::SharedCtor() {
  _cached_size_ = 0;
  target_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BottingReport::~BottingReport() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.BottingReport)
  SharedDtor();
}

void BottingReport::SharedDtor() {
  if (this != default_instance_) {
    delete target_;
  }
}

void BottingReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BottingReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BottingReport_descriptor_;
}

const BottingReport& BottingReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

BottingReport* BottingReport::default_instance_ = NULL;

BottingReport* BottingReport::New() const {
  return new BottingReport;
}

void BottingReport::Clear() {
  if (has_target()) {
    if (target_ != NULL) target_->::bgs::protocol::account::v1::GameAccountHandle::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BottingReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.BottingReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_target()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.BottingReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.BottingReport)
  return false;
#undef DO_
}

void BottingReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.BottingReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->target(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.BottingReport)
}

::google::protobuf::uint8* BottingReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.BottingReport)
  // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
  if (has_target()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->target(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.BottingReport)
  return target;
}

int BottingReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.account.v1.GameAccountHandle target = 1;
    if (has_target()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->target());
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

void BottingReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BottingReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BottingReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BottingReport::MergeFrom(const BottingReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_target()) {
      mutable_target()->::bgs::protocol::account::v1::GameAccountHandle::MergeFrom(from.target());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BottingReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BottingReport::CopyFrom(const BottingReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BottingReport::IsInitialized() const {

  if (has_target()) {
    if (!this->target().IsInitialized()) return false;
  }
  return true;
}

void BottingReport::Swap(BottingReport* other) {
  if (other != this) {
    std::swap(target_, other->target_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BottingReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BottingReport_descriptor_;
  metadata.reflection = BottingReport_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Report::kReportTypeFieldNumber;
const int Report::kAttributeFieldNumber;
const int Report::kReportQosFieldNumber;
const int Report::kReportingAccountFieldNumber;
const int Report::kReportingGameAccountFieldNumber;
const int Report::kReportTimestampFieldNumber;
#endif  // !_MSC_VER

Report::Report()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.report.v1.Report)
}

void Report::InitAsDefaultInstance() {
  reporting_account_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
  reporting_game_account_ = const_cast< ::bgs::protocol::EntityId*>(&::bgs::protocol::EntityId::default_instance());
}

Report::Report(const Report& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.report.v1.Report)
}

void Report::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  report_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  report_qos_ = 0;
  reporting_account_ = NULL;
  reporting_game_account_ = NULL;
  report_timestamp_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Report::~Report() {
  // @@protoc_insertion_point(destructor:bgs.protocol.report.v1.Report)
  SharedDtor();
}

void Report::SharedDtor() {
  if (report_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete report_type_;
  }
  if (this != default_instance_) {
    delete reporting_account_;
    delete reporting_game_account_;
  }
}

void Report::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Report::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Report_descriptor_;
}

const Report& Report::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_report_5ftypes_2eproto();
  return *default_instance_;
}

Report* Report::default_instance_ = NULL;

Report* Report::New() const {
  return new Report;
}

void Report::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Report*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 61) {
    ZR_(report_timestamp_, report_qos_);
    if (has_report_type()) {
      if (report_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        report_type_->clear();
      }
    }
    if (has_reporting_account()) {
      if (reporting_account_ != NULL) reporting_account_->::bgs::protocol::EntityId::Clear();
    }
    if (has_reporting_game_account()) {
      if (reporting_game_account_ != NULL) reporting_game_account_->::bgs::protocol::EntityId::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  attribute_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Report::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.report.v1.Report)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string report_type = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_report_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->report_type().data(), this->report_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "report_type");
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
        if (input->ExpectTag(24)) goto parse_report_qos;
        break;
      }

      // optional int32 report_qos = 3 [default = 0];
      case 3: {
        if (tag == 24) {
         parse_report_qos:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &report_qos_)));
          set_has_report_qos();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_reporting_account;
        break;
      }

      // optional .bgs.protocol.EntityId reporting_account = 4;
      case 4: {
        if (tag == 34) {
         parse_reporting_account:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_reporting_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_reporting_game_account;
        break;
      }

      // optional .bgs.protocol.EntityId reporting_game_account = 5;
      case 5: {
        if (tag == 42) {
         parse_reporting_game_account:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_reporting_game_account()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(49)) goto parse_report_timestamp;
        break;
      }

      // optional fixed64 report_timestamp = 6;
      case 6: {
        if (tag == 49) {
         parse_report_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &report_timestamp_)));
          set_has_report_timestamp();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.report.v1.Report)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.report.v1.Report)
  return false;
#undef DO_
}

void Report::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.report.v1.Report)
  // required string report_type = 1;
  if (has_report_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->report_type().data(), this->report_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "report_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->report_type(), output);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->attribute(i), output);
  }

  // optional int32 report_qos = 3 [default = 0];
  if (has_report_qos()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->report_qos(), output);
  }

  // optional .bgs.protocol.EntityId reporting_account = 4;
  if (has_reporting_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->reporting_account(), output);
  }

  // optional .bgs.protocol.EntityId reporting_game_account = 5;
  if (has_reporting_game_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->reporting_game_account(), output);
  }

  // optional fixed64 report_timestamp = 6;
  if (has_report_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(6, this->report_timestamp(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.report.v1.Report)
}

::google::protobuf::uint8* Report::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.report.v1.Report)
  // required string report_type = 1;
  if (has_report_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->report_type().data(), this->report_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "report_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->report_type(), target);
  }

  // repeated .bgs.protocol.Attribute attribute = 2;
  for (int i = 0; i < this->attribute_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->attribute(i), target);
  }

  // optional int32 report_qos = 3 [default = 0];
  if (has_report_qos()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->report_qos(), target);
  }

  // optional .bgs.protocol.EntityId reporting_account = 4;
  if (has_reporting_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->reporting_account(), target);
  }

  // optional .bgs.protocol.EntityId reporting_game_account = 5;
  if (has_reporting_game_account()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->reporting_game_account(), target);
  }

  // optional fixed64 report_timestamp = 6;
  if (has_report_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(6, this->report_timestamp(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.report.v1.Report)
  return target;
}

int Report::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string report_type = 1;
    if (has_report_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->report_type());
    }

    // optional int32 report_qos = 3 [default = 0];
    if (has_report_qos()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->report_qos());
    }

    // optional .bgs.protocol.EntityId reporting_account = 4;
    if (has_reporting_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->reporting_account());
    }

    // optional .bgs.protocol.EntityId reporting_game_account = 5;
    if (has_reporting_game_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->reporting_game_account());
    }

    // optional fixed64 report_timestamp = 6;
    if (has_report_timestamp()) {
      total_size += 1 + 8;
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

void Report::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Report* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Report*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Report::MergeFrom(const Report& from) {
  GOOGLE_CHECK_NE(&from, this);
  attribute_.MergeFrom(from.attribute_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_report_type()) {
      set_report_type(from.report_type());
    }
    if (from.has_report_qos()) {
      set_report_qos(from.report_qos());
    }
    if (from.has_reporting_account()) {
      mutable_reporting_account()->::bgs::protocol::EntityId::MergeFrom(from.reporting_account());
    }
    if (from.has_reporting_game_account()) {
      mutable_reporting_game_account()->::bgs::protocol::EntityId::MergeFrom(from.reporting_game_account());
    }
    if (from.has_report_timestamp()) {
      set_report_timestamp(from.report_timestamp());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Report::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Report::CopyFrom(const Report& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Report::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->attribute())) return false;
  if (has_reporting_account()) {
    if (!this->reporting_account().IsInitialized()) return false;
  }
  if (has_reporting_game_account()) {
    if (!this->reporting_game_account().IsInitialized()) return false;
  }
  return true;
}

void Report::Swap(Report* other) {
  if (other != this) {
    std::swap(report_type_, other->report_type_);
    attribute_.Swap(&other->attribute_);
    std::swap(report_qos_, other->report_qos_);
    std::swap(reporting_account_, other->reporting_account_);
    std::swap(reporting_game_account_, other->reporting_game_account_);
    std::swap(report_timestamp_, other->report_timestamp_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Report::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Report_descriptor_;
  metadata.reflection = Report_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace report
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
