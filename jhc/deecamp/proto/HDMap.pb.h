// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: HDMap.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_HDMap_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_HDMap_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Divider.pb.h"
#include "TrafficLight.pb.h"
#include "LaneMarking.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_HDMap_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_HDMap_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_HDMap_2eproto;
namespace hdmap {
class HDMap;
class HDMapDefaultTypeInternal;
extern HDMapDefaultTypeInternal _HDMap_default_instance_;
}  // namespace hdmap
PROTOBUF_NAMESPACE_OPEN
template<> ::hdmap::HDMap* Arena::CreateMaybeMessage<::hdmap::HDMap>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace hdmap {

// ===================================================================

class HDMap :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:hdmap.HDMap) */ {
 public:
  HDMap();
  virtual ~HDMap();

  HDMap(const HDMap& from);
  HDMap(HDMap&& from) noexcept
    : HDMap() {
    *this = ::std::move(from);
  }

  inline HDMap& operator=(const HDMap& from) {
    CopyFrom(from);
    return *this;
  }
  inline HDMap& operator=(HDMap&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HDMap& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HDMap* internal_default_instance() {
    return reinterpret_cast<const HDMap*>(
               &_HDMap_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HDMap& a, HDMap& b) {
    a.Swap(&b);
  }
  inline void Swap(HDMap* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HDMap* New() const final {
    return CreateMaybeMessage<HDMap>(nullptr);
  }

  HDMap* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HDMap>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HDMap& from);
  void MergeFrom(const HDMap& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HDMap* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "hdmap.HDMap";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_HDMap_2eproto);
    return ::descriptor_table_HDMap_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDividersFieldNumber = 2,
    kTafficlightsFieldNumber = 3,
    kLanemarkingsFieldNumber = 4,
    kSceneIdFieldNumber = 1,
    kVersionFieldNumber = 5,
  };
  // repeated .hdmap.Divider dividers = 2;
  int dividers_size() const;
  void clear_dividers();
  ::hdmap::Divider* mutable_dividers(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::Divider >*
      mutable_dividers();
  const ::hdmap::Divider& dividers(int index) const;
  ::hdmap::Divider* add_dividers();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::Divider >&
      dividers() const;

  // repeated .hdmap.TrafficLight tafficlights = 3;
  int tafficlights_size() const;
  void clear_tafficlights();
  ::hdmap::TrafficLight* mutable_tafficlights(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::TrafficLight >*
      mutable_tafficlights();
  const ::hdmap::TrafficLight& tafficlights(int index) const;
  ::hdmap::TrafficLight* add_tafficlights();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::TrafficLight >&
      tafficlights() const;

  // repeated .hdmap.LaneMarking lanemarkings = 4;
  int lanemarkings_size() const;
  void clear_lanemarkings();
  ::hdmap::LaneMarking* mutable_lanemarkings(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::LaneMarking >*
      mutable_lanemarkings();
  const ::hdmap::LaneMarking& lanemarkings(int index) const;
  ::hdmap::LaneMarking* add_lanemarkings();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::LaneMarking >&
      lanemarkings() const;

  // string scene_id = 1;
  void clear_scene_id();
  const std::string& scene_id() const;
  void set_scene_id(const std::string& value);
  void set_scene_id(std::string&& value);
  void set_scene_id(const char* value);
  void set_scene_id(const char* value, size_t size);
  std::string* mutable_scene_id();
  std::string* release_scene_id();
  void set_allocated_scene_id(std::string* scene_id);
  private:
  const std::string& _internal_scene_id() const;
  void _internal_set_scene_id(const std::string& value);
  std::string* _internal_mutable_scene_id();
  public:

  // string version = 5;
  void clear_version();
  const std::string& version() const;
  void set_version(const std::string& value);
  void set_version(std::string&& value);
  void set_version(const char* value);
  void set_version(const char* value, size_t size);
  std::string* mutable_version();
  std::string* release_version();
  void set_allocated_version(std::string* version);
  private:
  const std::string& _internal_version() const;
  void _internal_set_version(const std::string& value);
  std::string* _internal_mutable_version();
  public:

  // @@protoc_insertion_point(class_scope:hdmap.HDMap)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::Divider > dividers_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::TrafficLight > tafficlights_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::LaneMarking > lanemarkings_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr scene_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr version_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_HDMap_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HDMap

// string scene_id = 1;
inline void HDMap::clear_scene_id() {
  scene_id_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& HDMap::scene_id() const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.scene_id)
  return _internal_scene_id();
}
inline void HDMap::set_scene_id(const std::string& value) {
  _internal_set_scene_id(value);
  // @@protoc_insertion_point(field_set:hdmap.HDMap.scene_id)
}
inline std::string* HDMap::mutable_scene_id() {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.scene_id)
  return _internal_mutable_scene_id();
}
inline const std::string& HDMap::_internal_scene_id() const {
  return scene_id_.GetNoArena();
}
inline void HDMap::_internal_set_scene_id(const std::string& value) {
  
  scene_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void HDMap::set_scene_id(std::string&& value) {
  
  scene_id_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hdmap.HDMap.scene_id)
}
inline void HDMap::set_scene_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  scene_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hdmap.HDMap.scene_id)
}
inline void HDMap::set_scene_id(const char* value, size_t size) {
  
  scene_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hdmap.HDMap.scene_id)
}
inline std::string* HDMap::_internal_mutable_scene_id() {
  
  return scene_id_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* HDMap::release_scene_id() {
  // @@protoc_insertion_point(field_release:hdmap.HDMap.scene_id)
  
  return scene_id_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void HDMap::set_allocated_scene_id(std::string* scene_id) {
  if (scene_id != nullptr) {
    
  } else {
    
  }
  scene_id_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), scene_id);
  // @@protoc_insertion_point(field_set_allocated:hdmap.HDMap.scene_id)
}

// repeated .hdmap.Divider dividers = 2;
inline int HDMap::dividers_size() const {
  return dividers_.size();
}
inline ::hdmap::Divider* HDMap::mutable_dividers(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.dividers)
  return dividers_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::Divider >*
HDMap::mutable_dividers() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.dividers)
  return &dividers_;
}
inline const ::hdmap::Divider& HDMap::dividers(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.dividers)
  return dividers_.Get(index);
}
inline ::hdmap::Divider* HDMap::add_dividers() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.dividers)
  return dividers_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::Divider >&
HDMap::dividers() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.dividers)
  return dividers_;
}

// repeated .hdmap.TrafficLight tafficlights = 3;
inline int HDMap::tafficlights_size() const {
  return tafficlights_.size();
}
inline ::hdmap::TrafficLight* HDMap::mutable_tafficlights(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.tafficlights)
  return tafficlights_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::TrafficLight >*
HDMap::mutable_tafficlights() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.tafficlights)
  return &tafficlights_;
}
inline const ::hdmap::TrafficLight& HDMap::tafficlights(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.tafficlights)
  return tafficlights_.Get(index);
}
inline ::hdmap::TrafficLight* HDMap::add_tafficlights() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.tafficlights)
  return tafficlights_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::TrafficLight >&
HDMap::tafficlights() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.tafficlights)
  return tafficlights_;
}

// repeated .hdmap.LaneMarking lanemarkings = 4;
inline int HDMap::lanemarkings_size() const {
  return lanemarkings_.size();
}
inline ::hdmap::LaneMarking* HDMap::mutable_lanemarkings(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::LaneMarking >*
HDMap::mutable_lanemarkings() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.lanemarkings)
  return &lanemarkings_;
}
inline const ::hdmap::LaneMarking& HDMap::lanemarkings(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Get(index);
}
inline ::hdmap::LaneMarking* HDMap::add_lanemarkings() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::hdmap::LaneMarking >&
HDMap::lanemarkings() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.lanemarkings)
  return lanemarkings_;
}

// string version = 5;
inline void HDMap::clear_version() {
  version_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& HDMap::version() const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.version)
  return _internal_version();
}
inline void HDMap::set_version(const std::string& value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:hdmap.HDMap.version)
}
inline std::string* HDMap::mutable_version() {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.version)
  return _internal_mutable_version();
}
inline const std::string& HDMap::_internal_version() const {
  return version_.GetNoArena();
}
inline void HDMap::_internal_set_version(const std::string& value) {
  
  version_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void HDMap::set_version(std::string&& value) {
  
  version_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hdmap.HDMap.version)
}
inline void HDMap::set_version(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  version_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hdmap.HDMap.version)
}
inline void HDMap::set_version(const char* value, size_t size) {
  
  version_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hdmap.HDMap.version)
}
inline std::string* HDMap::_internal_mutable_version() {
  
  return version_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* HDMap::release_version() {
  // @@protoc_insertion_point(field_release:hdmap.HDMap.version)
  
  return version_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void HDMap::set_allocated_version(std::string* version) {
  if (version != nullptr) {
    
  } else {
    
  }
  version_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), version);
  // @@protoc_insertion_point(field_set_allocated:hdmap.HDMap.version)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_HDMap_2eproto
