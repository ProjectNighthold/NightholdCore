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
#include "connection_service.pb.h"

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
namespace connection {
namespace v1 {

namespace {

const ::google::protobuf::Descriptor* ConnectRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConnectRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ConnectionMeteringContentHandles_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConnectionMeteringContentHandles_reflection_ = NULL;
const ::google::protobuf::Descriptor* ConnectResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConnectResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* BoundService_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BoundService_reflection_ = NULL;
const ::google::protobuf::Descriptor* BindRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BindRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* BindResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BindResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* EchoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* EchoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* DisconnectRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DisconnectRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* DisconnectNotification_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DisconnectNotification_reflection_ = NULL;
const ::google::protobuf::Descriptor* EncryptRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EncryptRequest_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* ConnectionService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_connection_5fservice_2eproto() {
  protobuf_AddDesc_connection_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "connection_service.proto");
  GOOGLE_CHECK(file != NULL);
  ConnectRequest_descriptor_ = file->message_type(0);
  static const int ConnectRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectRequest, client_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectRequest, bind_request_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectRequest, use_bindless_rpc_),
  };
  ConnectRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConnectRequest_descriptor_,
      ConnectRequest::default_instance_,
      ConnectRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConnectRequest));
  ConnectionMeteringContentHandles_descriptor_ = file->message_type(1);
  static const int ConnectionMeteringContentHandles_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectionMeteringContentHandles, content_handle_),
  };
  ConnectionMeteringContentHandles_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConnectionMeteringContentHandles_descriptor_,
      ConnectionMeteringContentHandles::default_instance_,
      ConnectionMeteringContentHandles_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectionMeteringContentHandles, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectionMeteringContentHandles, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConnectionMeteringContentHandles));
  ConnectResponse_descriptor_ = file->message_type(2);
  static const int ConnectResponse_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, server_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, client_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, bind_result_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, bind_response_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, content_handle_array_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, server_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, use_bindless_rpc_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, binary_content_handle_array_),
  };
  ConnectResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConnectResponse_descriptor_,
      ConnectResponse::default_instance_,
      ConnectResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConnectResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConnectResponse));
  BoundService_descriptor_ = file->message_type(3);
  static const int BoundService_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BoundService, hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BoundService, id_),
  };
  BoundService_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BoundService_descriptor_,
      BoundService::default_instance_,
      BoundService_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BoundService, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BoundService, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BoundService));
  BindRequest_descriptor_ = file->message_type(4);
  static const int BindRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, deprecated_imported_service_hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, deprecated_exported_service_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, exported_service_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, imported_service_),
  };
  BindRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BindRequest_descriptor_,
      BindRequest::default_instance_,
      BindRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BindRequest));
  BindResponse_descriptor_ = file->message_type(5);
  static const int BindResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindResponse, imported_service_id_),
  };
  BindResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BindResponse_descriptor_,
      BindResponse::default_instance_,
      BindResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BindResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BindResponse));
  EchoRequest_descriptor_ = file->message_type(6);
  static const int EchoRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, network_only_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, payload_),
  };
  EchoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoRequest_descriptor_,
      EchoRequest::default_instance_,
      EchoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoRequest));
  EchoResponse_descriptor_ = file->message_type(7);
  static const int EchoResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, payload_),
  };
  EchoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoResponse_descriptor_,
      EchoResponse::default_instance_,
      EchoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoResponse));
  DisconnectRequest_descriptor_ = file->message_type(8);
  static const int DisconnectRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectRequest, error_code_),
  };
  DisconnectRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DisconnectRequest_descriptor_,
      DisconnectRequest::default_instance_,
      DisconnectRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DisconnectRequest));
  DisconnectNotification_descriptor_ = file->message_type(9);
  static const int DisconnectNotification_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectNotification, error_code_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectNotification, reason_),
  };
  DisconnectNotification_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DisconnectNotification_descriptor_,
      DisconnectNotification::default_instance_,
      DisconnectNotification_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectNotification, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DisconnectNotification, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DisconnectNotification));
  EncryptRequest_descriptor_ = file->message_type(10);
  static const int EncryptRequest_offsets_[1] = {
  };
  EncryptRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EncryptRequest_descriptor_,
      EncryptRequest::default_instance_,
      EncryptRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EncryptRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EncryptRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EncryptRequest));
  ConnectionService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_connection_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConnectRequest_descriptor_, &ConnectRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConnectionMeteringContentHandles_descriptor_, &ConnectionMeteringContentHandles::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConnectResponse_descriptor_, &ConnectResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BoundService_descriptor_, &BoundService::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BindRequest_descriptor_, &BindRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BindResponse_descriptor_, &BindResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoRequest_descriptor_, &EchoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoResponse_descriptor_, &EchoResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DisconnectRequest_descriptor_, &DisconnectRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DisconnectNotification_descriptor_, &DisconnectNotification::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EncryptRequest_descriptor_, &EncryptRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_connection_5fservice_2eproto() {
  delete ConnectRequest::default_instance_;
  delete ConnectRequest_reflection_;
  delete ConnectionMeteringContentHandles::default_instance_;
  delete ConnectionMeteringContentHandles_reflection_;
  delete ConnectResponse::default_instance_;
  delete ConnectResponse_reflection_;
  delete BoundService::default_instance_;
  delete BoundService_reflection_;
  delete BindRequest::default_instance_;
  delete BindRequest_reflection_;
  delete BindResponse::default_instance_;
  delete BindResponse_reflection_;
  delete EchoRequest::default_instance_;
  delete EchoRequest_reflection_;
  delete EchoResponse::default_instance_;
  delete EchoResponse_reflection_;
  delete DisconnectRequest::default_instance_;
  delete DisconnectRequest_reflection_;
  delete DisconnectNotification::default_instance_;
  delete DisconnectNotification_reflection_;
  delete EncryptRequest::default_instance_;
  delete EncryptRequest_reflection_;
}

void protobuf_AddDesc_connection_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bgs::protocol::protobuf_AddDesc_content_5fhandle_5ftypes_2eproto();
  ::bgs::protocol::protobuf_AddDesc_rpc_5ftypes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030connection_service.proto\022\032bgs.protocol"
    ".connection.v1\032\032content_handle_types.pro"
    "to\032\017rpc_types.proto\"\233\001\n\016ConnectRequest\022*"
    "\n\tclient_id\030\001 \001(\0132\027.bgs.protocol.Process"
    "Id\022=\n\014bind_request\030\002 \001(\0132\'.bgs.protocol."
    "connection.v1.BindRequest\022\036\n\020use_bindles"
    "s_rpc\030\003 \001(\010:\004true\"W\n ConnectionMeteringC"
    "ontentHandles\0223\n\016content_handle\030\001 \003(\0132\033."
    "bgs.protocol.ContentHandle\"\264\003\n\017ConnectRe"
    "sponse\022*\n\tserver_id\030\001 \002(\0132\027.bgs.protocol"
    ".ProcessId\022*\n\tclient_id\030\002 \001(\0132\027.bgs.prot"
    "ocol.ProcessId\022\023\n\013bind_result\030\003 \001(\r\022\?\n\rb"
    "ind_response\030\004 \001(\0132(.bgs.protocol.connec"
    "tion.v1.BindResponse\022Z\n\024content_handle_a"
    "rray\030\005 \001(\0132<.bgs.protocol.connection.v1."
    "ConnectionMeteringContentHandles\022\023\n\013serv"
    "er_time\030\006 \001(\004\022\037\n\020use_bindless_rpc\030\007 \001(\010:"
    "\005false\022a\n\033binary_content_handle_array\030\010 "
    "\001(\0132<.bgs.protocol.connection.v1.Connect"
    "ionMeteringContentHandles\"(\n\014BoundServic"
    "e\022\014\n\004hash\030\001 \002(\007\022\n\n\002id\030\002 \002(\r\"\230\002\n\013BindRequ"
    "est\022.\n deprecated_imported_service_hash\030"
    "\001 \003(\007B\004\020\001\030\001\022Q\n\033deprecated_exported_servi"
    "ce\030\002 \003(\0132(.bgs.protocol.connection.v1.Bo"
    "undServiceB\002\030\001\022B\n\020exported_service\030\003 \003(\013"
    "2(.bgs.protocol.connection.v1.BoundServi"
    "ce\022B\n\020imported_service\030\004 \003(\0132(.bgs.proto"
    "col.connection.v1.BoundService\"1\n\014BindRe"
    "sponse\022!\n\023imported_service_id\030\001 \003(\rB\004\020\001\030"
    "\001\"I\n\013EchoRequest\022\014\n\004time\030\001 \001(\006\022\033\n\014networ"
    "k_only\030\002 \001(\010:\005false\022\017\n\007payload\030\003 \001(\014\"-\n\014"
    "EchoResponse\022\014\n\004time\030\001 \001(\006\022\017\n\007payload\030\002 "
    "\001(\014\"\'\n\021DisconnectRequest\022\022\n\nerror_code\030\001"
    " \002(\r\"<\n\026DisconnectNotification\022\022\n\nerror_"
    "code\030\001 \002(\r\022\016\n\006reason\030\002 \001(\t\"\020\n\016EncryptReq"
    "uest2\330\005\n\021ConnectionService\022h\n\007Connect\022*."
    "bgs.protocol.connection.v1.ConnectReques"
    "t\032+.bgs.protocol.connection.v1.ConnectRe"
    "sponse\"\004\200\265\030\001\022b\n\004Bind\022\'.bgs.protocol.conn"
    "ection.v1.BindRequest\032(.bgs.protocol.con"
    "nection.v1.BindResponse\"\007\210\002\001\200\265\030\002\022_\n\004Echo"
    "\022\'.bgs.protocol.connection.v1.EchoReques"
    "t\032(.bgs.protocol.connection.v1.EchoRespo"
    "nse\"\004\200\265\030\003\022f\n\017ForceDisconnect\0222.bgs.proto"
    "col.connection.v1.DisconnectNotification"
    "\032\031.bgs.protocol.NO_RESPONSE\"\004\200\265\030\004\022B\n\tKee"
    "pAlive\022\024.bgs.protocol.NoData\032\031.bgs.proto"
    "col.NO_RESPONSE\"\004\200\265\030\005\022T\n\007Encrypt\022*.bgs.p"
    "rotocol.connection.v1.EncryptRequest\032\024.b"
    "gs.protocol.NoData\"\007\210\002\001\200\265\030\006\022c\n\021RequestDi"
    "sconnect\022-.bgs.protocol.connection.v1.Di"
    "sconnectRequest\032\031.bgs.protocol.NO_RESPON"
    "SE\"\004\200\265\030\007\032-\312>*bnet.protocol.connection.Co"
    "nnectionServiceB=\n\033bnet.protocol.connect"
    "ion.v1B\026ConnectionServiceProtoH\001\200\001\000\210\001\001", 2198);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "connection_service.proto", &protobuf_RegisterTypes);
  ConnectRequest::default_instance_ = new ConnectRequest();
  ConnectionMeteringContentHandles::default_instance_ = new ConnectionMeteringContentHandles();
  ConnectResponse::default_instance_ = new ConnectResponse();
  BoundService::default_instance_ = new BoundService();
  BindRequest::default_instance_ = new BindRequest();
  BindResponse::default_instance_ = new BindResponse();
  EchoRequest::default_instance_ = new EchoRequest();
  EchoResponse::default_instance_ = new EchoResponse();
  DisconnectRequest::default_instance_ = new DisconnectRequest();
  DisconnectNotification::default_instance_ = new DisconnectNotification();
  EncryptRequest::default_instance_ = new EncryptRequest();
  ConnectRequest::default_instance_->InitAsDefaultInstance();
  ConnectionMeteringContentHandles::default_instance_->InitAsDefaultInstance();
  ConnectResponse::default_instance_->InitAsDefaultInstance();
  BoundService::default_instance_->InitAsDefaultInstance();
  BindRequest::default_instance_->InitAsDefaultInstance();
  BindResponse::default_instance_->InitAsDefaultInstance();
  EchoRequest::default_instance_->InitAsDefaultInstance();
  EchoResponse::default_instance_->InitAsDefaultInstance();
  DisconnectRequest::default_instance_->InitAsDefaultInstance();
  DisconnectNotification::default_instance_->InitAsDefaultInstance();
  EncryptRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_connection_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_connection_5fservice_2eproto {
  StaticDescriptorInitializer_connection_5fservice_2eproto() {
    protobuf_AddDesc_connection_5fservice_2eproto();
  }
} static_descriptor_initializer_connection_5fservice_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ConnectRequest::kClientIdFieldNumber;
const int ConnectRequest::kBindRequestFieldNumber;
const int ConnectRequest::kUseBindlessRpcFieldNumber;
#endif  // !_MSC_VER

ConnectRequest::ConnectRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.ConnectRequest)
}

void ConnectRequest::InitAsDefaultInstance() {
  client_id_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  bind_request_ = const_cast< ::bgs::protocol::connection::v1::BindRequest*>(&::bgs::protocol::connection::v1::BindRequest::default_instance());
}

ConnectRequest::ConnectRequest(const ConnectRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.ConnectRequest)
}

void ConnectRequest::SharedCtor() {
  _cached_size_ = 0;
  client_id_ = NULL;
  bind_request_ = NULL;
  use_bindless_rpc_ = true;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConnectRequest::~ConnectRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.ConnectRequest)
  SharedDtor();
}

void ConnectRequest::SharedDtor() {
  if (this != default_instance_) {
    delete client_id_;
    delete bind_request_;
  }
}

void ConnectRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConnectRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConnectRequest_descriptor_;
}

const ConnectRequest& ConnectRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

ConnectRequest* ConnectRequest::default_instance_ = NULL;

ConnectRequest* ConnectRequest::New() const {
  return new ConnectRequest;
}

void ConnectRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_client_id()) {
      if (client_id_ != NULL) client_id_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_bind_request()) {
      if (bind_request_ != NULL) bind_request_->::bgs::protocol::connection::v1::BindRequest::Clear();
    }
    use_bindless_rpc_ = true;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConnectRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.ConnectRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .bgs.protocol.ProcessId client_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_client_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_bind_request;
        break;
      }

      // optional .bgs.protocol.connection.v1.BindRequest bind_request = 2;
      case 2: {
        if (tag == 18) {
         parse_bind_request:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_bind_request()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_use_bindless_rpc;
        break;
      }

      // optional bool use_bindless_rpc = 3 [default = true];
      case 3: {
        if (tag == 24) {
         parse_use_bindless_rpc:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &use_bindless_rpc_)));
          set_has_use_bindless_rpc();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.ConnectRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.ConnectRequest)
  return false;
#undef DO_
}

void ConnectRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.ConnectRequest)
  // optional .bgs.protocol.ProcessId client_id = 1;
  if (has_client_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->client_id(), output);
  }

  // optional .bgs.protocol.connection.v1.BindRequest bind_request = 2;
  if (has_bind_request()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->bind_request(), output);
  }

  // optional bool use_bindless_rpc = 3 [default = true];
  if (has_use_bindless_rpc()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->use_bindless_rpc(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.ConnectRequest)
}

::google::protobuf::uint8* ConnectRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.ConnectRequest)
  // optional .bgs.protocol.ProcessId client_id = 1;
  if (has_client_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->client_id(), target);
  }

  // optional .bgs.protocol.connection.v1.BindRequest bind_request = 2;
  if (has_bind_request()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->bind_request(), target);
  }

  // optional bool use_bindless_rpc = 3 [default = true];
  if (has_use_bindless_rpc()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->use_bindless_rpc(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.ConnectRequest)
  return target;
}

int ConnectRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .bgs.protocol.ProcessId client_id = 1;
    if (has_client_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->client_id());
    }

    // optional .bgs.protocol.connection.v1.BindRequest bind_request = 2;
    if (has_bind_request()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->bind_request());
    }

    // optional bool use_bindless_rpc = 3 [default = true];
    if (has_use_bindless_rpc()) {
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

void ConnectRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConnectRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConnectRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConnectRequest::MergeFrom(const ConnectRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_client_id()) {
      mutable_client_id()->::bgs::protocol::ProcessId::MergeFrom(from.client_id());
    }
    if (from.has_bind_request()) {
      mutable_bind_request()->::bgs::protocol::connection::v1::BindRequest::MergeFrom(from.bind_request());
    }
    if (from.has_use_bindless_rpc()) {
      set_use_bindless_rpc(from.use_bindless_rpc());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConnectRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConnectRequest::CopyFrom(const ConnectRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConnectRequest::IsInitialized() const {

  if (has_client_id()) {
    if (!this->client_id().IsInitialized()) return false;
  }
  if (has_bind_request()) {
    if (!this->bind_request().IsInitialized()) return false;
  }
  return true;
}

void ConnectRequest::Swap(ConnectRequest* other) {
  if (other != this) {
    std::swap(client_id_, other->client_id_);
    std::swap(bind_request_, other->bind_request_);
    std::swap(use_bindless_rpc_, other->use_bindless_rpc_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConnectRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConnectRequest_descriptor_;
  metadata.reflection = ConnectRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ConnectionMeteringContentHandles::kContentHandleFieldNumber;
#endif  // !_MSC_VER

ConnectionMeteringContentHandles::ConnectionMeteringContentHandles()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
}

void ConnectionMeteringContentHandles::InitAsDefaultInstance() {
}

ConnectionMeteringContentHandles::ConnectionMeteringContentHandles(const ConnectionMeteringContentHandles& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
}

void ConnectionMeteringContentHandles::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConnectionMeteringContentHandles::~ConnectionMeteringContentHandles() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  SharedDtor();
}

void ConnectionMeteringContentHandles::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ConnectionMeteringContentHandles::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConnectionMeteringContentHandles::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConnectionMeteringContentHandles_descriptor_;
}

const ConnectionMeteringContentHandles& ConnectionMeteringContentHandles::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

ConnectionMeteringContentHandles* ConnectionMeteringContentHandles::default_instance_ = NULL;

ConnectionMeteringContentHandles* ConnectionMeteringContentHandles::New() const {
  return new ConnectionMeteringContentHandles;
}

void ConnectionMeteringContentHandles::Clear() {
  content_handle_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConnectionMeteringContentHandles::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .bgs.protocol.ContentHandle content_handle = 1;
      case 1: {
        if (tag == 10) {
         parse_content_handle:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_content_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_content_handle;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  return false;
#undef DO_
}

void ConnectionMeteringContentHandles::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  // repeated .bgs.protocol.ContentHandle content_handle = 1;
  for (int i = 0; i < this->content_handle_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->content_handle(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
}

::google::protobuf::uint8* ConnectionMeteringContentHandles::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  // repeated .bgs.protocol.ContentHandle content_handle = 1;
  for (int i = 0; i < this->content_handle_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->content_handle(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.ConnectionMeteringContentHandles)
  return target;
}

int ConnectionMeteringContentHandles::ByteSize() const {
  int total_size = 0;

  // repeated .bgs.protocol.ContentHandle content_handle = 1;
  total_size += 1 * this->content_handle_size();
  for (int i = 0; i < this->content_handle_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->content_handle(i));
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

void ConnectionMeteringContentHandles::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConnectionMeteringContentHandles* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConnectionMeteringContentHandles*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConnectionMeteringContentHandles::MergeFrom(const ConnectionMeteringContentHandles& from) {
  GOOGLE_CHECK_NE(&from, this);
  content_handle_.MergeFrom(from.content_handle_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConnectionMeteringContentHandles::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConnectionMeteringContentHandles::CopyFrom(const ConnectionMeteringContentHandles& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConnectionMeteringContentHandles::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->content_handle())) return false;
  return true;
}

void ConnectionMeteringContentHandles::Swap(ConnectionMeteringContentHandles* other) {
  if (other != this) {
    content_handle_.Swap(&other->content_handle_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConnectionMeteringContentHandles::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConnectionMeteringContentHandles_descriptor_;
  metadata.reflection = ConnectionMeteringContentHandles_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ConnectResponse::kServerIdFieldNumber;
const int ConnectResponse::kClientIdFieldNumber;
const int ConnectResponse::kBindResultFieldNumber;
const int ConnectResponse::kBindResponseFieldNumber;
const int ConnectResponse::kContentHandleArrayFieldNumber;
const int ConnectResponse::kServerTimeFieldNumber;
const int ConnectResponse::kUseBindlessRpcFieldNumber;
const int ConnectResponse::kBinaryContentHandleArrayFieldNumber;
#endif  // !_MSC_VER

ConnectResponse::ConnectResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.ConnectResponse)
}

void ConnectResponse::InitAsDefaultInstance() {
  server_id_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  client_id_ = const_cast< ::bgs::protocol::ProcessId*>(&::bgs::protocol::ProcessId::default_instance());
  bind_response_ = const_cast< ::bgs::protocol::connection::v1::BindResponse*>(&::bgs::protocol::connection::v1::BindResponse::default_instance());
  content_handle_array_ = const_cast< ::bgs::protocol::connection::v1::ConnectionMeteringContentHandles*>(&::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::default_instance());
  binary_content_handle_array_ = const_cast< ::bgs::protocol::connection::v1::ConnectionMeteringContentHandles*>(&::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::default_instance());
}

ConnectResponse::ConnectResponse(const ConnectResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.ConnectResponse)
}

void ConnectResponse::SharedCtor() {
  _cached_size_ = 0;
  server_id_ = NULL;
  client_id_ = NULL;
  bind_result_ = 0u;
  bind_response_ = NULL;
  content_handle_array_ = NULL;
  server_time_ = GOOGLE_ULONGLONG(0);
  use_bindless_rpc_ = false;
  binary_content_handle_array_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConnectResponse::~ConnectResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.ConnectResponse)
  SharedDtor();
}

void ConnectResponse::SharedDtor() {
  if (this != default_instance_) {
    delete server_id_;
    delete client_id_;
    delete bind_response_;
    delete content_handle_array_;
    delete binary_content_handle_array_;
  }
}

void ConnectResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConnectResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConnectResponse_descriptor_;
}

const ConnectResponse& ConnectResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

ConnectResponse* ConnectResponse::default_instance_ = NULL;

ConnectResponse* ConnectResponse::New() const {
  return new ConnectResponse;
}

void ConnectResponse::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ConnectResponse*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(bind_result_, server_time_);
    if (has_server_id()) {
      if (server_id_ != NULL) server_id_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_client_id()) {
      if (client_id_ != NULL) client_id_->::bgs::protocol::ProcessId::Clear();
    }
    if (has_bind_response()) {
      if (bind_response_ != NULL) bind_response_->::bgs::protocol::connection::v1::BindResponse::Clear();
    }
    if (has_content_handle_array()) {
      if (content_handle_array_ != NULL) content_handle_array_->::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::Clear();
    }
    if (has_binary_content_handle_array()) {
      if (binary_content_handle_array_ != NULL) binary_content_handle_array_->::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConnectResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.ConnectResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .bgs.protocol.ProcessId server_id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_server_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_client_id;
        break;
      }

      // optional .bgs.protocol.ProcessId client_id = 2;
      case 2: {
        if (tag == 18) {
         parse_client_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_client_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_bind_result;
        break;
      }

      // optional uint32 bind_result = 3;
      case 3: {
        if (tag == 24) {
         parse_bind_result:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &bind_result_)));
          set_has_bind_result();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_bind_response;
        break;
      }

      // optional .bgs.protocol.connection.v1.BindResponse bind_response = 4;
      case 4: {
        if (tag == 34) {
         parse_bind_response:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_bind_response()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_content_handle_array;
        break;
      }

      // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles content_handle_array = 5;
      case 5: {
        if (tag == 42) {
         parse_content_handle_array:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_content_handle_array()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_server_time;
        break;
      }

      // optional uint64 server_time = 6;
      case 6: {
        if (tag == 48) {
         parse_server_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &server_time_)));
          set_has_server_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_use_bindless_rpc;
        break;
      }

      // optional bool use_bindless_rpc = 7 [default = false];
      case 7: {
        if (tag == 56) {
         parse_use_bindless_rpc:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &use_bindless_rpc_)));
          set_has_use_bindless_rpc();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_binary_content_handle_array;
        break;
      }

      // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles binary_content_handle_array = 8;
      case 8: {
        if (tag == 66) {
         parse_binary_content_handle_array:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_binary_content_handle_array()));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.ConnectResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.ConnectResponse)
  return false;
#undef DO_
}

void ConnectResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.ConnectResponse)
  // required .bgs.protocol.ProcessId server_id = 1;
  if (has_server_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->server_id(), output);
  }

  // optional .bgs.protocol.ProcessId client_id = 2;
  if (has_client_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->client_id(), output);
  }

  // optional uint32 bind_result = 3;
  if (has_bind_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->bind_result(), output);
  }

  // optional .bgs.protocol.connection.v1.BindResponse bind_response = 4;
  if (has_bind_response()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->bind_response(), output);
  }

  // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles content_handle_array = 5;
  if (has_content_handle_array()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->content_handle_array(), output);
  }

  // optional uint64 server_time = 6;
  if (has_server_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(6, this->server_time(), output);
  }

  // optional bool use_bindless_rpc = 7 [default = false];
  if (has_use_bindless_rpc()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->use_bindless_rpc(), output);
  }

  // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles binary_content_handle_array = 8;
  if (has_binary_content_handle_array()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->binary_content_handle_array(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.ConnectResponse)
}

::google::protobuf::uint8* ConnectResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.ConnectResponse)
  // required .bgs.protocol.ProcessId server_id = 1;
  if (has_server_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->server_id(), target);
  }

  // optional .bgs.protocol.ProcessId client_id = 2;
  if (has_client_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->client_id(), target);
  }

  // optional uint32 bind_result = 3;
  if (has_bind_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->bind_result(), target);
  }

  // optional .bgs.protocol.connection.v1.BindResponse bind_response = 4;
  if (has_bind_response()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->bind_response(), target);
  }

  // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles content_handle_array = 5;
  if (has_content_handle_array()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->content_handle_array(), target);
  }

  // optional uint64 server_time = 6;
  if (has_server_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(6, this->server_time(), target);
  }

  // optional bool use_bindless_rpc = 7 [default = false];
  if (has_use_bindless_rpc()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->use_bindless_rpc(), target);
  }

  // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles binary_content_handle_array = 8;
  if (has_binary_content_handle_array()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->binary_content_handle_array(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.ConnectResponse)
  return target;
}

int ConnectResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .bgs.protocol.ProcessId server_id = 1;
    if (has_server_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->server_id());
    }

    // optional .bgs.protocol.ProcessId client_id = 2;
    if (has_client_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->client_id());
    }

    // optional uint32 bind_result = 3;
    if (has_bind_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->bind_result());
    }

    // optional .bgs.protocol.connection.v1.BindResponse bind_response = 4;
    if (has_bind_response()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->bind_response());
    }

    // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles content_handle_array = 5;
    if (has_content_handle_array()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->content_handle_array());
    }

    // optional uint64 server_time = 6;
    if (has_server_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->server_time());
    }

    // optional bool use_bindless_rpc = 7 [default = false];
    if (has_use_bindless_rpc()) {
      total_size += 1 + 1;
    }

    // optional .bgs.protocol.connection.v1.ConnectionMeteringContentHandles binary_content_handle_array = 8;
    if (has_binary_content_handle_array()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->binary_content_handle_array());
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

void ConnectResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConnectResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConnectResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConnectResponse::MergeFrom(const ConnectResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_server_id()) {
      mutable_server_id()->::bgs::protocol::ProcessId::MergeFrom(from.server_id());
    }
    if (from.has_client_id()) {
      mutable_client_id()->::bgs::protocol::ProcessId::MergeFrom(from.client_id());
    }
    if (from.has_bind_result()) {
      set_bind_result(from.bind_result());
    }
    if (from.has_bind_response()) {
      mutable_bind_response()->::bgs::protocol::connection::v1::BindResponse::MergeFrom(from.bind_response());
    }
    if (from.has_content_handle_array()) {
      mutable_content_handle_array()->::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::MergeFrom(from.content_handle_array());
    }
    if (from.has_server_time()) {
      set_server_time(from.server_time());
    }
    if (from.has_use_bindless_rpc()) {
      set_use_bindless_rpc(from.use_bindless_rpc());
    }
    if (from.has_binary_content_handle_array()) {
      mutable_binary_content_handle_array()->::bgs::protocol::connection::v1::ConnectionMeteringContentHandles::MergeFrom(from.binary_content_handle_array());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConnectResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConnectResponse::CopyFrom(const ConnectResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConnectResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_server_id()) {
    if (!this->server_id().IsInitialized()) return false;
  }
  if (has_client_id()) {
    if (!this->client_id().IsInitialized()) return false;
  }
  if (has_content_handle_array()) {
    if (!this->content_handle_array().IsInitialized()) return false;
  }
  if (has_binary_content_handle_array()) {
    if (!this->binary_content_handle_array().IsInitialized()) return false;
  }
  return true;
}

void ConnectResponse::Swap(ConnectResponse* other) {
  if (other != this) {
    std::swap(server_id_, other->server_id_);
    std::swap(client_id_, other->client_id_);
    std::swap(bind_result_, other->bind_result_);
    std::swap(bind_response_, other->bind_response_);
    std::swap(content_handle_array_, other->content_handle_array_);
    std::swap(server_time_, other->server_time_);
    std::swap(use_bindless_rpc_, other->use_bindless_rpc_);
    std::swap(binary_content_handle_array_, other->binary_content_handle_array_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConnectResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConnectResponse_descriptor_;
  metadata.reflection = ConnectResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BoundService::kHashFieldNumber;
const int BoundService::kIdFieldNumber;
#endif  // !_MSC_VER

BoundService::BoundService()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.BoundService)
}

void BoundService::InitAsDefaultInstance() {
}

BoundService::BoundService(const BoundService& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.BoundService)
}

void BoundService::SharedCtor() {
  _cached_size_ = 0;
  hash_ = 0u;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BoundService::~BoundService() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.BoundService)
  SharedDtor();
}

void BoundService::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BoundService::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BoundService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BoundService_descriptor_;
}

const BoundService& BoundService::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

BoundService* BoundService::default_instance_ = NULL;

BoundService* BoundService::New() const {
  return new BoundService;
}

void BoundService::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<BoundService*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(hash_, id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BoundService::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.BoundService)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 hash = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &hash_)));
          set_has_hash();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // required uint32 id = 2;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.BoundService)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.BoundService)
  return false;
#undef DO_
}

void BoundService::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.BoundService)
  // required fixed32 hash = 1;
  if (has_hash()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->hash(), output);
  }

  // required uint32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.BoundService)
}

::google::protobuf::uint8* BoundService::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.BoundService)
  // required fixed32 hash = 1;
  if (has_hash()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->hash(), target);
  }

  // required uint32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.BoundService)
  return target;
}

int BoundService::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 hash = 1;
    if (has_hash()) {
      total_size += 1 + 4;
    }

    // required uint32 id = 2;
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

void BoundService::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BoundService* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BoundService*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BoundService::MergeFrom(const BoundService& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_hash()) {
      set_hash(from.hash());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BoundService::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BoundService::CopyFrom(const BoundService& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BoundService::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void BoundService::Swap(BoundService* other) {
  if (other != this) {
    std::swap(hash_, other->hash_);
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BoundService::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BoundService_descriptor_;
  metadata.reflection = BoundService_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BindRequest::kDeprecatedImportedServiceHashFieldNumber;
const int BindRequest::kDeprecatedExportedServiceFieldNumber;
const int BindRequest::kExportedServiceFieldNumber;
const int BindRequest::kImportedServiceFieldNumber;
#endif  // !_MSC_VER

BindRequest::BindRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.BindRequest)
}

void BindRequest::InitAsDefaultInstance() {
}

BindRequest::BindRequest(const BindRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.BindRequest)
}

void BindRequest::SharedCtor() {
  _cached_size_ = 0;
  _deprecated_imported_service_hash_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BindRequest::~BindRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.BindRequest)
  SharedDtor();
}

void BindRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BindRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BindRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BindRequest_descriptor_;
}

const BindRequest& BindRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

BindRequest* BindRequest::default_instance_ = NULL;

BindRequest* BindRequest::New() const {
  return new BindRequest;
}

void BindRequest::Clear() {
  deprecated_imported_service_hash_.Clear();
  deprecated_exported_service_.Clear();
  exported_service_.Clear();
  imported_service_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BindRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.BindRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated fixed32 deprecated_imported_service_hash = 1 [packed = true, deprecated = true];
      case 1: {
        if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, this->mutable_deprecated_imported_service_hash())));
        } else if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 1, 10, input, this->mutable_deprecated_imported_service_hash())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_deprecated_exported_service;
        break;
      }

      // repeated .bgs.protocol.connection.v1.BoundService deprecated_exported_service = 2 [deprecated = true];
      case 2: {
        if (tag == 18) {
         parse_deprecated_exported_service:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_deprecated_exported_service()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_deprecated_exported_service;
        if (input->ExpectTag(26)) goto parse_exported_service;
        break;
      }

      // repeated .bgs.protocol.connection.v1.BoundService exported_service = 3;
      case 3: {
        if (tag == 26) {
         parse_exported_service:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_exported_service()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_exported_service;
        if (input->ExpectTag(34)) goto parse_imported_service;
        break;
      }

      // repeated .bgs.protocol.connection.v1.BoundService imported_service = 4;
      case 4: {
        if (tag == 34) {
         parse_imported_service:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_imported_service()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_imported_service;
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.BindRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.BindRequest)
  return false;
#undef DO_
}

void BindRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.BindRequest)
  // repeated fixed32 deprecated_imported_service_hash = 1 [packed = true, deprecated = true];
  if (this->deprecated_imported_service_hash_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(1, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_deprecated_imported_service_hash_cached_byte_size_);
  }
  for (int i = 0; i < this->deprecated_imported_service_hash_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32NoTag(
      this->deprecated_imported_service_hash(i), output);
  }

  // repeated .bgs.protocol.connection.v1.BoundService deprecated_exported_service = 2 [deprecated = true];
  for (int i = 0; i < this->deprecated_exported_service_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->deprecated_exported_service(i), output);
  }

  // repeated .bgs.protocol.connection.v1.BoundService exported_service = 3;
  for (int i = 0; i < this->exported_service_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->exported_service(i), output);
  }

  // repeated .bgs.protocol.connection.v1.BoundService imported_service = 4;
  for (int i = 0; i < this->imported_service_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->imported_service(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.BindRequest)
}

::google::protobuf::uint8* BindRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.BindRequest)
  // repeated fixed32 deprecated_imported_service_hash = 1 [packed = true, deprecated = true];
  if (this->deprecated_imported_service_hash_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      1,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _deprecated_imported_service_hash_cached_byte_size_, target);
  }
  for (int i = 0; i < this->deprecated_imported_service_hash_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFixed32NoTagToArray(this->deprecated_imported_service_hash(i), target);
  }

  // repeated .bgs.protocol.connection.v1.BoundService deprecated_exported_service = 2 [deprecated = true];
  for (int i = 0; i < this->deprecated_exported_service_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->deprecated_exported_service(i), target);
  }

  // repeated .bgs.protocol.connection.v1.BoundService exported_service = 3;
  for (int i = 0; i < this->exported_service_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->exported_service(i), target);
  }

  // repeated .bgs.protocol.connection.v1.BoundService imported_service = 4;
  for (int i = 0; i < this->imported_service_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->imported_service(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.BindRequest)
  return target;
}

int BindRequest::ByteSize() const {
  int total_size = 0;

  // repeated fixed32 deprecated_imported_service_hash = 1 [packed = true, deprecated = true];
  {
    int data_size = 0;
    data_size = 4 * this->deprecated_imported_service_hash_size();
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _deprecated_imported_service_hash_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated .bgs.protocol.connection.v1.BoundService deprecated_exported_service = 2 [deprecated = true];
  total_size += 1 * this->deprecated_exported_service_size();
  for (int i = 0; i < this->deprecated_exported_service_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->deprecated_exported_service(i));
  }

  // repeated .bgs.protocol.connection.v1.BoundService exported_service = 3;
  total_size += 1 * this->exported_service_size();
  for (int i = 0; i < this->exported_service_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->exported_service(i));
  }

  // repeated .bgs.protocol.connection.v1.BoundService imported_service = 4;
  total_size += 1 * this->imported_service_size();
  for (int i = 0; i < this->imported_service_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->imported_service(i));
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

void BindRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BindRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BindRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BindRequest::MergeFrom(const BindRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  deprecated_imported_service_hash_.MergeFrom(from.deprecated_imported_service_hash_);
  deprecated_exported_service_.MergeFrom(from.deprecated_exported_service_);
  exported_service_.MergeFrom(from.exported_service_);
  imported_service_.MergeFrom(from.imported_service_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BindRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BindRequest::CopyFrom(const BindRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BindRequest::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->deprecated_exported_service())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->exported_service())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->imported_service())) return false;
  return true;
}

void BindRequest::Swap(BindRequest* other) {
  if (other != this) {
    deprecated_imported_service_hash_.Swap(&other->deprecated_imported_service_hash_);
    deprecated_exported_service_.Swap(&other->deprecated_exported_service_);
    exported_service_.Swap(&other->exported_service_);
    imported_service_.Swap(&other->imported_service_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BindRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BindRequest_descriptor_;
  metadata.reflection = BindRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BindResponse::kImportedServiceIdFieldNumber;
#endif  // !_MSC_VER

BindResponse::BindResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.BindResponse)
}

void BindResponse::InitAsDefaultInstance() {
}

BindResponse::BindResponse(const BindResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.BindResponse)
}

void BindResponse::SharedCtor() {
  _cached_size_ = 0;
  _imported_service_id_cached_byte_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BindResponse::~BindResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.BindResponse)
  SharedDtor();
}

void BindResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BindResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BindResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BindResponse_descriptor_;
}

const BindResponse& BindResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

BindResponse* BindResponse::default_instance_ = NULL;

BindResponse* BindResponse::New() const {
  return new BindResponse;
}

void BindResponse::Clear() {
  imported_service_id_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BindResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.BindResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated uint32 imported_service_id = 1 [packed = true, deprecated = true];
      case 1: {
        if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_imported_service_id())));
        } else if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 10, input, this->mutable_imported_service_id())));
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.BindResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.BindResponse)
  return false;
#undef DO_
}

void BindResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.BindResponse)
  // repeated uint32 imported_service_id = 1 [packed = true, deprecated = true];
  if (this->imported_service_id_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(1, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_imported_service_id_cached_byte_size_);
  }
  for (int i = 0; i < this->imported_service_id_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->imported_service_id(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.BindResponse)
}

::google::protobuf::uint8* BindResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.BindResponse)
  // repeated uint32 imported_service_id = 1 [packed = true, deprecated = true];
  if (this->imported_service_id_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      1,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _imported_service_id_cached_byte_size_, target);
  }
  for (int i = 0; i < this->imported_service_id_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->imported_service_id(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.BindResponse)
  return target;
}

int BindResponse::ByteSize() const {
  int total_size = 0;

  // repeated uint32 imported_service_id = 1 [packed = true, deprecated = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->imported_service_id_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->imported_service_id(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _imported_service_id_cached_byte_size_ = data_size;
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

void BindResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BindResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BindResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BindResponse::MergeFrom(const BindResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  imported_service_id_.MergeFrom(from.imported_service_id_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BindResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BindResponse::CopyFrom(const BindResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BindResponse::IsInitialized() const {

  return true;
}

void BindResponse::Swap(BindResponse* other) {
  if (other != this) {
    imported_service_id_.Swap(&other->imported_service_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BindResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BindResponse_descriptor_;
  metadata.reflection = BindResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int EchoRequest::kTimeFieldNumber;
const int EchoRequest::kNetworkOnlyFieldNumber;
const int EchoRequest::kPayloadFieldNumber;
#endif  // !_MSC_VER

EchoRequest::EchoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.EchoRequest)
}

void EchoRequest::InitAsDefaultInstance() {
}

EchoRequest::EchoRequest(const EchoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.EchoRequest)
}

void EchoRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  time_ = GOOGLE_ULONGLONG(0);
  network_only_ = false;
  payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoRequest::~EchoRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.EchoRequest)
  SharedDtor();
}

void EchoRequest::SharedDtor() {
  if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete payload_;
  }
  if (this != default_instance_) {
  }
}

void EchoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoRequest_descriptor_;
}

const EchoRequest& EchoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

EchoRequest* EchoRequest::default_instance_ = NULL;

EchoRequest* EchoRequest::New() const {
  return new EchoRequest;
}

void EchoRequest::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    time_ = GOOGLE_ULONGLONG(0);
    network_only_ = false;
    if (has_payload()) {
      if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        payload_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EchoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.EchoRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed64 time = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &time_)));
          set_has_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_network_only;
        break;
      }

      // optional bool network_only = 2 [default = false];
      case 2: {
        if (tag == 16) {
         parse_network_only:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &network_only_)));
          set_has_network_only();
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.EchoRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.EchoRequest)
  return false;
#undef DO_
}

void EchoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.EchoRequest)
  // optional fixed64 time = 1;
  if (has_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->time(), output);
  }

  // optional bool network_only = 2 [default = false];
  if (has_network_only()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->network_only(), output);
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
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.EchoRequest)
}

::google::protobuf::uint8* EchoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.EchoRequest)
  // optional fixed64 time = 1;
  if (has_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->time(), target);
  }

  // optional bool network_only = 2 [default = false];
  if (has_network_only()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->network_only(), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.EchoRequest)
  return target;
}

int EchoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed64 time = 1;
    if (has_time()) {
      total_size += 1 + 8;
    }

    // optional bool network_only = 2 [default = false];
    if (has_network_only()) {
      total_size += 1 + 1;
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

void EchoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EchoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EchoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EchoRequest::MergeFrom(const EchoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_time()) {
      set_time(from.time());
    }
    if (from.has_network_only()) {
      set_network_only(from.network_only());
    }
    if (from.has_payload()) {
      set_payload(from.payload());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EchoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoRequest::CopyFrom(const EchoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoRequest::IsInitialized() const {

  return true;
}

void EchoRequest::Swap(EchoRequest* other) {
  if (other != this) {
    std::swap(time_, other->time_);
    std::swap(network_only_, other->network_only_);
    std::swap(payload_, other->payload_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EchoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoRequest_descriptor_;
  metadata.reflection = EchoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int EchoResponse::kTimeFieldNumber;
const int EchoResponse::kPayloadFieldNumber;
#endif  // !_MSC_VER

EchoResponse::EchoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.EchoResponse)
}

void EchoResponse::InitAsDefaultInstance() {
}

EchoResponse::EchoResponse(const EchoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.EchoResponse)
}

void EchoResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  time_ = GOOGLE_ULONGLONG(0);
  payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoResponse::~EchoResponse() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.EchoResponse)
  SharedDtor();
}

void EchoResponse::SharedDtor() {
  if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete payload_;
  }
  if (this != default_instance_) {
  }
}

void EchoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoResponse_descriptor_;
}

const EchoResponse& EchoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

EchoResponse* EchoResponse::default_instance_ = NULL;

EchoResponse* EchoResponse::New() const {
  return new EchoResponse;
}

void EchoResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    time_ = GOOGLE_ULONGLONG(0);
    if (has_payload()) {
      if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        payload_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EchoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.EchoResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed64 time = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &time_)));
          set_has_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_payload;
        break;
      }

      // optional bytes payload = 2;
      case 2: {
        if (tag == 18) {
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.EchoResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.EchoResponse)
  return false;
#undef DO_
}

void EchoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.EchoResponse)
  // optional fixed64 time = 1;
  if (has_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->time(), output);
  }

  // optional bytes payload = 2;
  if (has_payload()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->payload(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.EchoResponse)
}

::google::protobuf::uint8* EchoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.EchoResponse)
  // optional fixed64 time = 1;
  if (has_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->time(), target);
  }

  // optional bytes payload = 2;
  if (has_payload()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->payload(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.EchoResponse)
  return target;
}

int EchoResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed64 time = 1;
    if (has_time()) {
      total_size += 1 + 8;
    }

    // optional bytes payload = 2;
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

void EchoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EchoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EchoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EchoResponse::MergeFrom(const EchoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_time()) {
      set_time(from.time());
    }
    if (from.has_payload()) {
      set_payload(from.payload());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EchoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoResponse::CopyFrom(const EchoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoResponse::IsInitialized() const {

  return true;
}

void EchoResponse::Swap(EchoResponse* other) {
  if (other != this) {
    std::swap(time_, other->time_);
    std::swap(payload_, other->payload_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EchoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoResponse_descriptor_;
  metadata.reflection = EchoResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DisconnectRequest::kErrorCodeFieldNumber;
#endif  // !_MSC_VER

DisconnectRequest::DisconnectRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.DisconnectRequest)
}

void DisconnectRequest::InitAsDefaultInstance() {
}

DisconnectRequest::DisconnectRequest(const DisconnectRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.DisconnectRequest)
}

void DisconnectRequest::SharedCtor() {
  _cached_size_ = 0;
  error_code_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DisconnectRequest::~DisconnectRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.DisconnectRequest)
  SharedDtor();
}

void DisconnectRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DisconnectRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DisconnectRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DisconnectRequest_descriptor_;
}

const DisconnectRequest& DisconnectRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

DisconnectRequest* DisconnectRequest::default_instance_ = NULL;

DisconnectRequest* DisconnectRequest::New() const {
  return new DisconnectRequest;
}

void DisconnectRequest::Clear() {
  error_code_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DisconnectRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.DisconnectRequest)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.DisconnectRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.DisconnectRequest)
  return false;
#undef DO_
}

void DisconnectRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.DisconnectRequest)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->error_code(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.DisconnectRequest)
}

::google::protobuf::uint8* DisconnectRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.DisconnectRequest)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->error_code(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.DisconnectRequest)
  return target;
}

int DisconnectRequest::ByteSize() const {
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

void DisconnectRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DisconnectRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DisconnectRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DisconnectRequest::MergeFrom(const DisconnectRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error_code()) {
      set_error_code(from.error_code());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DisconnectRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DisconnectRequest::CopyFrom(const DisconnectRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DisconnectRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void DisconnectRequest::Swap(DisconnectRequest* other) {
  if (other != this) {
    std::swap(error_code_, other->error_code_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DisconnectRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DisconnectRequest_descriptor_;
  metadata.reflection = DisconnectRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DisconnectNotification::kErrorCodeFieldNumber;
const int DisconnectNotification::kReasonFieldNumber;
#endif  // !_MSC_VER

DisconnectNotification::DisconnectNotification()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.DisconnectNotification)
}

void DisconnectNotification::InitAsDefaultInstance() {
}

DisconnectNotification::DisconnectNotification(const DisconnectNotification& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.DisconnectNotification)
}

void DisconnectNotification::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  error_code_ = 0u;
  reason_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DisconnectNotification::~DisconnectNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.DisconnectNotification)
  SharedDtor();
}

void DisconnectNotification::SharedDtor() {
  if (reason_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete reason_;
  }
  if (this != default_instance_) {
  }
}

void DisconnectNotification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DisconnectNotification::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DisconnectNotification_descriptor_;
}

const DisconnectNotification& DisconnectNotification::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

DisconnectNotification* DisconnectNotification::default_instance_ = NULL;

DisconnectNotification* DisconnectNotification::New() const {
  return new DisconnectNotification;
}

void DisconnectNotification::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    error_code_ = 0u;
    if (has_reason()) {
      if (reason_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        reason_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DisconnectNotification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.DisconnectNotification)
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
        if (input->ExpectTag(18)) goto parse_reason;
        break;
      }

      // optional string reason = 2;
      case 2: {
        if (tag == 18) {
         parse_reason:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_reason()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->reason().data(), this->reason().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "reason");
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.DisconnectNotification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.DisconnectNotification)
  return false;
#undef DO_
}

void DisconnectNotification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.DisconnectNotification)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->error_code(), output);
  }

  // optional string reason = 2;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->reason().data(), this->reason().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "reason");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->reason(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.DisconnectNotification)
}

::google::protobuf::uint8* DisconnectNotification::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.DisconnectNotification)
  // required uint32 error_code = 1;
  if (has_error_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->error_code(), target);
  }

  // optional string reason = 2;
  if (has_reason()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->reason().data(), this->reason().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "reason");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->reason(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.DisconnectNotification)
  return target;
}

int DisconnectNotification::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 error_code = 1;
    if (has_error_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->error_code());
    }

    // optional string reason = 2;
    if (has_reason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->reason());
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

void DisconnectNotification::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DisconnectNotification* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DisconnectNotification*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DisconnectNotification::MergeFrom(const DisconnectNotification& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error_code()) {
      set_error_code(from.error_code());
    }
    if (from.has_reason()) {
      set_reason(from.reason());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DisconnectNotification::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DisconnectNotification::CopyFrom(const DisconnectNotification& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DisconnectNotification::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void DisconnectNotification::Swap(DisconnectNotification* other) {
  if (other != this) {
    std::swap(error_code_, other->error_code_);
    std::swap(reason_, other->reason_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DisconnectNotification::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DisconnectNotification_descriptor_;
  metadata.reflection = DisconnectNotification_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

EncryptRequest::EncryptRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.connection.v1.EncryptRequest)
}

void EncryptRequest::InitAsDefaultInstance() {
}

EncryptRequest::EncryptRequest(const EncryptRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.connection.v1.EncryptRequest)
}

void EncryptRequest::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EncryptRequest::~EncryptRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.connection.v1.EncryptRequest)
  SharedDtor();
}

void EncryptRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void EncryptRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EncryptRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EncryptRequest_descriptor_;
}

const EncryptRequest& EncryptRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_connection_5fservice_2eproto();
  return *default_instance_;
}

EncryptRequest* EncryptRequest::default_instance_ = NULL;

EncryptRequest* EncryptRequest::New() const {
  return new EncryptRequest;
}

void EncryptRequest::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EncryptRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:bgs.protocol.connection.v1.EncryptRequest)
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
  // @@protoc_insertion_point(parse_success:bgs.protocol.connection.v1.EncryptRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:bgs.protocol.connection.v1.EncryptRequest)
  return false;
#undef DO_
}

void EncryptRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:bgs.protocol.connection.v1.EncryptRequest)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:bgs.protocol.connection.v1.EncryptRequest)
}

::google::protobuf::uint8* EncryptRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.connection.v1.EncryptRequest)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.connection.v1.EncryptRequest)
  return target;
}

int EncryptRequest::ByteSize() const {
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

void EncryptRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EncryptRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EncryptRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EncryptRequest::MergeFrom(const EncryptRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EncryptRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EncryptRequest::CopyFrom(const EncryptRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EncryptRequest::IsInitialized() const {

  return true;
}

void EncryptRequest::Swap(EncryptRequest* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EncryptRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EncryptRequest_descriptor_;
  metadata.reflection = EncryptRequest_reflection_;
  return metadata;
}


// ===================================================================

ConnectionService::ConnectionService(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {
}

ConnectionService::~ConnectionService() {
}

google::protobuf::ServiceDescriptor const* ConnectionService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConnectionService_descriptor_;
}

void ConnectionService::Connect(::bgs::protocol::connection::v1::ConnectRequest const* request, std::function<void(::bgs::protocol::connection::v1::ConnectResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.Connect(bgs.protocol.connection.v1.ConnectRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::connection::v1::ConnectResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 1, request, std::move(callback));
}

void ConnectionService::Bind(::bgs::protocol::connection::v1::BindRequest const* request, std::function<void(::bgs::protocol::connection::v1::BindResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.Bind(bgs.protocol.connection.v1.BindRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::connection::v1::BindResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 2, request, std::move(callback));
}

void ConnectionService::Echo(::bgs::protocol::connection::v1::EchoRequest const* request, std::function<void(::bgs::protocol::connection::v1::EchoResponse const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.Echo(bgs.protocol.connection.v1.EchoRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::connection::v1::EchoResponse response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 3, request, std::move(callback));
}

void ConnectionService::ForceDisconnect(::bgs::protocol::connection::v1::DisconnectNotification const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.ForceDisconnect(bgs.protocol.connection.v1.DisconnectNotification{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 4, request);
}

void ConnectionService::KeepAlive(::bgs::protocol::NoData const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.KeepAlive(bgs.protocol.NoData{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 5, request);
}

void ConnectionService::Encrypt(::bgs::protocol::connection::v1::EncryptRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback) {
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.Encrypt(bgs.protocol.connection.v1.EncryptRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {
    ::bgs::protocol::NoData response;
    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))
      responseCallback(&response);
  };
  SendRequest(service_hash_, 6, request, std::move(callback));
}

void ConnectionService::RequestDisconnect(::bgs::protocol::connection::v1::DisconnectRequest const* request) { 
  TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Server called client method ConnectionService.RequestDisconnect(bgs.protocol.connection.v1.DisconnectRequest{ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  SendRequest(service_hash_, 7, request);
}

void ConnectionService::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {
  switch(methodId) {
    case 1: {
      ::bgs::protocol::connection::v1::ConnectRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.Connect server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 1, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::connection::v1::ConnectResponse response;
      uint32 status = HandleConnect(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.Connect(bgs.protocol.connection.v1.ConnectRequest{ %s }) returned bgs.protocol.connection.v1.ConnectResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 1, token, &response);
      else
        SendResponse(service_hash_, 1, token, status);
      break;
    }
    case 2: {
      ::bgs::protocol::connection::v1::BindRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.Bind server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 2, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::connection::v1::BindResponse response;
      uint32 status = HandleBind(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.Bind(bgs.protocol.connection.v1.BindRequest{ %s }) returned bgs.protocol.connection.v1.BindResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 2, token, &response);
      else
        SendResponse(service_hash_, 2, token, status);
      break;
    }
    case 3: {
      ::bgs::protocol::connection::v1::EchoRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.Echo server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 3, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::connection::v1::EchoResponse response;
      uint32 status = HandleEcho(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.Echo(bgs.protocol.connection.v1.EchoRequest{ %s }) returned bgs.protocol.connection.v1.EchoResponse{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 3, token, &response);
      else
        SendResponse(service_hash_, 3, token, status);
      break;
    }
    case 4: {
      ::bgs::protocol::connection::v1::DisconnectNotification request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.ForceDisconnect server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 4, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleForceDisconnect(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.ForceDisconnect(bgs.protocol.connection.v1.DisconnectNotification{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 4, token, status);
      break;
    }
    case 5: {
      ::bgs::protocol::NoData request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.KeepAlive server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 5, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleKeepAlive(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.KeepAlive(bgs.protocol.NoData{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 5, token, status);
      break;
    }
    case 6: {
      ::bgs::protocol::connection::v1::EncryptRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.Encrypt server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 6, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      ::bgs::protocol::NoData response;
      uint32 status = HandleEncrypt(&request, &response);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.Encrypt(bgs.protocol.connection.v1.EncryptRequest{ %s }) returned bgs.protocol.NoData{ %s } status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), response.ShortDebugString().c_str(), status);
      if (!status)
        SendResponse(service_hash_, 6, token, &response);
      else
        SendResponse(service_hash_, 6, token, status);
      break;
    }
    case 7: {
      ::bgs::protocol::connection::v1::DisconnectRequest request;
      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {
        TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Failed to parse request for ConnectionService.RequestDisconnect server method call.", GetCallerInfo().c_str());
        SendResponse(service_hash_, 7, token, ERROR_RPC_MALFORMED_REQUEST);
        return;
      }

      uint32 status = HandleRequestDisconnect(&request);
      TC_LOG_DEBUG(LOG_FILTER_PROTOBUF, "%s Client called server method ConnectionService.RequestDisconnect(bgs.protocol.connection.v1.DisconnectRequest{ %s }) status %u.",
        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);
      if (status)
        SendResponse(service_hash_, 7, token, status);
      break;
    }
    default:
      TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "Bad method id %u.", methodId);
      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);
      break;
    }
}

uint32 ConnectionService::HandleConnect(::bgs::protocol::connection::v1::ConnectRequest const* request, ::bgs::protocol::connection::v1::ConnectResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.Connect({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleBind(::bgs::protocol::connection::v1::BindRequest const* request, ::bgs::protocol::connection::v1::BindResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.Bind({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleEcho(::bgs::protocol::connection::v1::EchoRequest const* request, ::bgs::protocol::connection::v1::EchoResponse* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.Echo({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleForceDisconnect(::bgs::protocol::connection::v1::DisconnectNotification const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.ForceDisconnect({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleKeepAlive(::bgs::protocol::NoData const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.KeepAlive({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleEncrypt(::bgs::protocol::connection::v1::EncryptRequest const* request, ::bgs::protocol::NoData* response) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.Encrypt({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 ConnectionService::HandleRequestDisconnect(::bgs::protocol::connection::v1::DisconnectRequest const* request) {
  TC_LOG_ERROR(LOG_FILTER_PROTOBUF, "%s Client tried to call not implemented method ConnectionService.RequestDisconnect({ %s })",
    GetCallerInfo().c_str(), request->ShortDebugString().c_str());
  return ERROR_RPC_NOT_IMPLEMENTED;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace connection
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)
