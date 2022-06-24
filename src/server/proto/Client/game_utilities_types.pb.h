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

#ifndef PROTOBUF_game_5futilities_5ftypes_2eproto__INCLUDED
#define PROTOBUF_game_5futilities_5ftypes_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "attribute_types.pb.h"
#include "entity_types.pb.h"
#include "Define.h"
// @@protoc_insertion_point(includes)

namespace bgs {
namespace protocol {
namespace game_utilities {
namespace v1 {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_game_5futilities_5ftypes_2eproto();
void protobuf_AssignDesc_game_5futilities_5ftypes_2eproto();
void protobuf_ShutdownFile_game_5futilities_5ftypes_2eproto();

class PlayerVariables;
class ClientInfo;

// ===================================================================

class PlayerVariables : public ::google::protobuf::Message {
 public:
  PlayerVariables();
  virtual ~PlayerVariables();

  PlayerVariables(const PlayerVariables& from);

  inline PlayerVariables& operator=(const PlayerVariables& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PlayerVariables& default_instance();

  void Swap(PlayerVariables* other);

  // implements Message ----------------------------------------------

  PlayerVariables* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayerVariables& from);
  void MergeFrom(const PlayerVariables& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .bgs.protocol.Identity identity = 1;
  inline bool has_identity() const;
  inline void clear_identity();
  static const int kIdentityFieldNumber = 1;
  inline const ::bgs::protocol::Identity& identity() const;
  inline ::bgs::protocol::Identity* mutable_identity();
  inline ::bgs::protocol::Identity* release_identity();
  inline void set_allocated_identity(::bgs::protocol::Identity* identity);

  // optional double rating = 2;
  inline bool has_rating() const;
  inline void clear_rating();
  static const int kRatingFieldNumber = 2;
  inline double rating() const;
  inline void set_rating(double value);

  // repeated .bgs.protocol.Attribute attribute = 3;
  inline int attribute_size() const;
  inline void clear_attribute();
  static const int kAttributeFieldNumber = 3;
  inline const ::bgs::protocol::Attribute& attribute(int index) const;
  inline ::bgs::protocol::Attribute* mutable_attribute(int index);
  inline ::bgs::protocol::Attribute* add_attribute();
  inline const ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >&
      attribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >*
      mutable_attribute();

  // @@protoc_insertion_point(class_scope:bgs.protocol.game_utilities.v1.PlayerVariables)
 private:
  inline void set_has_identity();
  inline void clear_has_identity();
  inline void set_has_rating();
  inline void clear_has_rating();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::bgs::protocol::Identity* identity_;
  double rating_;
  ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute > attribute_;
  friend void protobuf_AddDesc_game_5futilities_5ftypes_2eproto();
  friend void protobuf_AssignDesc_game_5futilities_5ftypes_2eproto();
  friend void protobuf_ShutdownFile_game_5futilities_5ftypes_2eproto();

  void InitAsDefaultInstance();
  static PlayerVariables* default_instance_;
};
// -------------------------------------------------------------------

class ClientInfo : public ::google::protobuf::Message {
 public:
  ClientInfo();
  virtual ~ClientInfo();

  ClientInfo(const ClientInfo& from);

  inline ClientInfo& operator=(const ClientInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ClientInfo& default_instance();

  void Swap(ClientInfo* other);

  // implements Message ----------------------------------------------

  ClientInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ClientInfo& from);
  void MergeFrom(const ClientInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string client_address = 1;
  inline bool has_client_address() const;
  inline void clear_client_address();
  static const int kClientAddressFieldNumber = 1;
  inline const ::std::string& client_address() const;
  inline void set_client_address(const ::std::string& value);
  inline void set_client_address(const char* value);
  inline void set_client_address(const char* value, size_t size);
  inline ::std::string* mutable_client_address();
  inline ::std::string* release_client_address();
  inline void set_allocated_client_address(::std::string* client_address);

  // optional bool privileged_network = 2;
  inline bool has_privileged_network() const;
  inline void clear_privileged_network();
  static const int kPrivilegedNetworkFieldNumber = 2;
  inline bool privileged_network() const;
  inline void set_privileged_network(bool value);

  // @@protoc_insertion_point(class_scope:bgs.protocol.game_utilities.v1.ClientInfo)
 private:
  inline void set_has_client_address();
  inline void clear_has_client_address();
  inline void set_has_privileged_network();
  inline void clear_has_privileged_network();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* client_address_;
  bool privileged_network_;
  friend void protobuf_AddDesc_game_5futilities_5ftypes_2eproto();
  friend void protobuf_AssignDesc_game_5futilities_5ftypes_2eproto();
  friend void protobuf_ShutdownFile_game_5futilities_5ftypes_2eproto();

  void InitAsDefaultInstance();
  static ClientInfo* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// PlayerVariables

// required .bgs.protocol.Identity identity = 1;
inline bool PlayerVariables::has_identity() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayerVariables::set_has_identity() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayerVariables::clear_has_identity() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayerVariables::clear_identity() {
  if (identity_ != NULL) identity_->::bgs::protocol::Identity::Clear();
  clear_has_identity();
}
inline const ::bgs::protocol::Identity& PlayerVariables::identity() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.game_utilities.v1.PlayerVariables.identity)
  return identity_ != NULL ? *identity_ : *default_instance_->identity_;
}
inline ::bgs::protocol::Identity* PlayerVariables::mutable_identity() {
  set_has_identity();
  if (identity_ == NULL) identity_ = new ::bgs::protocol::Identity;
  // @@protoc_insertion_point(field_mutable:bgs.protocol.game_utilities.v1.PlayerVariables.identity)
  return identity_;
}
inline ::bgs::protocol::Identity* PlayerVariables::release_identity() {
  clear_has_identity();
  ::bgs::protocol::Identity* temp = identity_;
  identity_ = NULL;
  return temp;
}
inline void PlayerVariables::set_allocated_identity(::bgs::protocol::Identity* identity) {
  delete identity_;
  identity_ = identity;
  if (identity) {
    set_has_identity();
  } else {
    clear_has_identity();
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.game_utilities.v1.PlayerVariables.identity)
}

// optional double rating = 2;
inline bool PlayerVariables::has_rating() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PlayerVariables::set_has_rating() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PlayerVariables::clear_has_rating() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PlayerVariables::clear_rating() {
  rating_ = 0;
  clear_has_rating();
}
inline double PlayerVariables::rating() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.game_utilities.v1.PlayerVariables.rating)
  return rating_;
}
inline void PlayerVariables::set_rating(double value) {
  set_has_rating();
  rating_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.game_utilities.v1.PlayerVariables.rating)
}

// repeated .bgs.protocol.Attribute attribute = 3;
inline int PlayerVariables::attribute_size() const {
  return attribute_.size();
}
inline void PlayerVariables::clear_attribute() {
  attribute_.Clear();
}
inline const ::bgs::protocol::Attribute& PlayerVariables::attribute(int index) const {
  // @@protoc_insertion_point(field_get:bgs.protocol.game_utilities.v1.PlayerVariables.attribute)
  return attribute_.Get(index);
}
inline ::bgs::protocol::Attribute* PlayerVariables::mutable_attribute(int index) {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.game_utilities.v1.PlayerVariables.attribute)
  return attribute_.Mutable(index);
}
inline ::bgs::protocol::Attribute* PlayerVariables::add_attribute() {
  // @@protoc_insertion_point(field_add:bgs.protocol.game_utilities.v1.PlayerVariables.attribute)
  return attribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >&
PlayerVariables::attribute() const {
  // @@protoc_insertion_point(field_list:bgs.protocol.game_utilities.v1.PlayerVariables.attribute)
  return attribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >*
PlayerVariables::mutable_attribute() {
  // @@protoc_insertion_point(field_mutable_list:bgs.protocol.game_utilities.v1.PlayerVariables.attribute)
  return &attribute_;
}

// -------------------------------------------------------------------

// ClientInfo

// optional string client_address = 1;
inline bool ClientInfo::has_client_address() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ClientInfo::set_has_client_address() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ClientInfo::clear_has_client_address() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ClientInfo::clear_client_address() {
  if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    client_address_->clear();
  }
  clear_has_client_address();
}
inline const ::std::string& ClientInfo::client_address() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
  return *client_address_;
}
inline void ClientInfo::set_client_address(const ::std::string& value) {
  set_has_client_address();
  if (client_address_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    client_address_ = new ::std::string;
  }
  client_address_->assign(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
}
inline void ClientInfo::set_client_address(const char* value) {
  set_has_client_address();
  if (client_address_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    client_address_ = new ::std::string;
  }
  client_address_->assign(value);
  // @@protoc_insertion_point(field_set_char:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
}
inline void ClientInfo::set_client_address(const char* value, size_t size) {
  set_has_client_address();
  if (client_address_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    client_address_ = new ::std::string;
  }
  client_address_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
}
inline ::std::string* ClientInfo::mutable_client_address() {
  set_has_client_address();
  if (client_address_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    client_address_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
  return client_address_;
}
inline ::std::string* ClientInfo::release_client_address() {
  clear_has_client_address();
  if (client_address_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = client_address_;
    client_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void ClientInfo::set_allocated_client_address(::std::string* client_address) {
  if (client_address_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete client_address_;
  }
  if (client_address) {
    set_has_client_address();
    client_address_ = client_address;
  } else {
    clear_has_client_address();
    client_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.game_utilities.v1.ClientInfo.client_address)
}

// optional bool privileged_network = 2;
inline bool ClientInfo::has_privileged_network() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ClientInfo::set_has_privileged_network() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ClientInfo::clear_has_privileged_network() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ClientInfo::clear_privileged_network() {
  privileged_network_ = false;
  clear_has_privileged_network();
}
inline bool ClientInfo::privileged_network() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.game_utilities.v1.ClientInfo.privileged_network)
  return privileged_network_;
}
inline void ClientInfo::set_privileged_network(bool value) {
  set_has_privileged_network();
  privileged_network_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.game_utilities.v1.ClientInfo.privileged_network)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace game_utilities
}  // namespace protocol
}  // namespace bgs

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_game_5futilities_5ftypes_2eproto__INCLUDED
