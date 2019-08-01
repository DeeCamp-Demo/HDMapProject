// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: HDMap.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "HDMap.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace hdmap {
class HDMapDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<HDMap>
     _instance;
} _HDMap_default_instance_;

namespace protobuf_HDMap_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, scene_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, dividers_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, tafficlights_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, lanemarkings_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HDMap, version_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(HDMap)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_HDMap_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "HDMap.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::hdmap::protobuf_Divider_2eproto::InitDefaults();
  ::hdmap::protobuf_TrafficLight_2eproto::InitDefaults();
  ::hdmap::protobuf_LaneMarking_2eproto::InitDefaults();
  _HDMap_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_HDMap_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\013HDMap.proto\022\005hdmap\032\rDivider.proto\032\022Tra"
      "fficLight.proto\032\021LaneMarking.proto\"\241\001\n\005H"
      "DMap\022\020\n\010scene_id\030\001 \001(\t\022 \n\010dividers\030\002 \003(\013"
      "2\016.hdmap.Divider\022)\n\014tafficlights\030\003 \003(\0132\023"
      ".hdmap.TrafficLight\022(\n\014lanemarkings\030\004 \003("
      "\0132\022.hdmap.LaneMarking\022\017\n\007version\030\005 \001(\tb\006"
      "proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 246);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "HDMap.proto", &protobuf_RegisterTypes);
  ::hdmap::protobuf_Divider_2eproto::AddDescriptors();
  ::hdmap::protobuf_TrafficLight_2eproto::AddDescriptors();
  ::hdmap::protobuf_LaneMarking_2eproto::AddDescriptors();
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_HDMap_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int HDMap::kSceneIdFieldNumber;
const int HDMap::kDividersFieldNumber;
const int HDMap::kTafficlightsFieldNumber;
const int HDMap::kLanemarkingsFieldNumber;
const int HDMap::kVersionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

HDMap::HDMap()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_HDMap_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:hdmap.HDMap)
}
HDMap::HDMap(const HDMap& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      dividers_(from.dividers_),
      tafficlights_(from.tafficlights_),
      lanemarkings_(from.lanemarkings_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  scene_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.scene_id().size() > 0) {
    scene_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.scene_id_);
  }
  version_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.version().size() > 0) {
    version_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.version_);
  }
  // @@protoc_insertion_point(copy_constructor:hdmap.HDMap)
}

void HDMap::SharedCtor() {
  scene_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  version_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

HDMap::~HDMap() {
  // @@protoc_insertion_point(destructor:hdmap.HDMap)
  SharedDtor();
}

void HDMap::SharedDtor() {
  scene_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  version_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void HDMap::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HDMap::descriptor() {
  protobuf_HDMap_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_HDMap_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const HDMap& HDMap::default_instance() {
  protobuf_HDMap_2eproto::InitDefaults();
  return *internal_default_instance();
}

HDMap* HDMap::New(::google::protobuf::Arena* arena) const {
  HDMap* n = new HDMap;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void HDMap::Clear() {
// @@protoc_insertion_point(message_clear_start:hdmap.HDMap)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  dividers_.Clear();
  tafficlights_.Clear();
  lanemarkings_.Clear();
  scene_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool HDMap::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:hdmap.HDMap)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string scene_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_scene_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->scene_id().data(), static_cast<int>(this->scene_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "hdmap.HDMap.scene_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .hdmap.Divider dividers = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_dividers()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .hdmap.TrafficLight tafficlights = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_tafficlights()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .hdmap.LaneMarking lanemarkings = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lanemarkings()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string version = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->version().data(), static_cast<int>(this->version().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "hdmap.HDMap.version"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:hdmap.HDMap)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hdmap.HDMap)
  return false;
#undef DO_
}

void HDMap::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hdmap.HDMap)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string scene_id = 1;
  if (this->scene_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->scene_id().data(), static_cast<int>(this->scene_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "hdmap.HDMap.scene_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->scene_id(), output);
  }

  // repeated .hdmap.Divider dividers = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->dividers_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->dividers(static_cast<int>(i)), output);
  }

  // repeated .hdmap.TrafficLight tafficlights = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->tafficlights_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->tafficlights(static_cast<int>(i)), output);
  }

  // repeated .hdmap.LaneMarking lanemarkings = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->lanemarkings_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->lanemarkings(static_cast<int>(i)), output);
  }

  // string version = 5;
  if (this->version().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->version().data(), static_cast<int>(this->version().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "hdmap.HDMap.version");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->version(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:hdmap.HDMap)
}

::google::protobuf::uint8* HDMap::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:hdmap.HDMap)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string scene_id = 1;
  if (this->scene_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->scene_id().data(), static_cast<int>(this->scene_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "hdmap.HDMap.scene_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->scene_id(), target);
  }

  // repeated .hdmap.Divider dividers = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->dividers_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, this->dividers(static_cast<int>(i)), deterministic, target);
  }

  // repeated .hdmap.TrafficLight tafficlights = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->tafficlights_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        3, this->tafficlights(static_cast<int>(i)), deterministic, target);
  }

  // repeated .hdmap.LaneMarking lanemarkings = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->lanemarkings_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        4, this->lanemarkings(static_cast<int>(i)), deterministic, target);
  }

  // string version = 5;
  if (this->version().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->version().data(), static_cast<int>(this->version().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "hdmap.HDMap.version");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->version(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hdmap.HDMap)
  return target;
}

size_t HDMap::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:hdmap.HDMap)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .hdmap.Divider dividers = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->dividers_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->dividers(static_cast<int>(i)));
    }
  }

  // repeated .hdmap.TrafficLight tafficlights = 3;
  {
    unsigned int count = static_cast<unsigned int>(this->tafficlights_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tafficlights(static_cast<int>(i)));
    }
  }

  // repeated .hdmap.LaneMarking lanemarkings = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->lanemarkings_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->lanemarkings(static_cast<int>(i)));
    }
  }

  // string scene_id = 1;
  if (this->scene_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->scene_id());
  }

  // string version = 5;
  if (this->version().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->version());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HDMap::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:hdmap.HDMap)
  GOOGLE_DCHECK_NE(&from, this);
  const HDMap* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const HDMap>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:hdmap.HDMap)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:hdmap.HDMap)
    MergeFrom(*source);
  }
}

void HDMap::MergeFrom(const HDMap& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:hdmap.HDMap)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  dividers_.MergeFrom(from.dividers_);
  tafficlights_.MergeFrom(from.tafficlights_);
  lanemarkings_.MergeFrom(from.lanemarkings_);
  if (from.scene_id().size() > 0) {

    scene_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.scene_id_);
  }
  if (from.version().size() > 0) {

    version_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.version_);
  }
}

void HDMap::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:hdmap.HDMap)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HDMap::CopyFrom(const HDMap& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:hdmap.HDMap)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HDMap::IsInitialized() const {
  return true;
}

void HDMap::Swap(HDMap* other) {
  if (other == this) return;
  InternalSwap(other);
}
void HDMap::InternalSwap(HDMap* other) {
  using std::swap;
  dividers_.InternalSwap(&other->dividers_);
  tafficlights_.InternalSwap(&other->tafficlights_);
  lanemarkings_.InternalSwap(&other->lanemarkings_);
  scene_id_.Swap(&other->scene_id_);
  version_.Swap(&other->version_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata HDMap::GetMetadata() const {
  protobuf_HDMap_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_HDMap_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// HDMap

// string scene_id = 1;
void HDMap::clear_scene_id() {
  scene_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& HDMap::scene_id() const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.scene_id)
  return scene_id_.GetNoArena();
}
void HDMap::set_scene_id(const ::std::string& value) {
  
  scene_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hdmap.HDMap.scene_id)
}
#if LANG_CXX11
void HDMap::set_scene_id(::std::string&& value) {
  
  scene_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hdmap.HDMap.scene_id)
}
#endif
void HDMap::set_scene_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  scene_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hdmap.HDMap.scene_id)
}
void HDMap::set_scene_id(const char* value, size_t size) {
  
  scene_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hdmap.HDMap.scene_id)
}
::std::string* HDMap::mutable_scene_id() {
  
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.scene_id)
  return scene_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* HDMap::release_scene_id() {
  // @@protoc_insertion_point(field_release:hdmap.HDMap.scene_id)
  
  return scene_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void HDMap::set_allocated_scene_id(::std::string* scene_id) {
  if (scene_id != NULL) {
    
  } else {
    
  }
  scene_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), scene_id);
  // @@protoc_insertion_point(field_set_allocated:hdmap.HDMap.scene_id)
}

// repeated .hdmap.Divider dividers = 2;
int HDMap::dividers_size() const {
  return dividers_.size();
}
void HDMap::clear_dividers() {
  dividers_.Clear();
}
const ::hdmap::Divider& HDMap::dividers(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.dividers)
  return dividers_.Get(index);
}
::hdmap::Divider* HDMap::mutable_dividers(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.dividers)
  return dividers_.Mutable(index);
}
::hdmap::Divider* HDMap::add_dividers() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.dividers)
  return dividers_.Add();
}
::google::protobuf::RepeatedPtrField< ::hdmap::Divider >*
HDMap::mutable_dividers() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.dividers)
  return &dividers_;
}
const ::google::protobuf::RepeatedPtrField< ::hdmap::Divider >&
HDMap::dividers() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.dividers)
  return dividers_;
}

// repeated .hdmap.TrafficLight tafficlights = 3;
int HDMap::tafficlights_size() const {
  return tafficlights_.size();
}
void HDMap::clear_tafficlights() {
  tafficlights_.Clear();
}
const ::hdmap::TrafficLight& HDMap::tafficlights(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.tafficlights)
  return tafficlights_.Get(index);
}
::hdmap::TrafficLight* HDMap::mutable_tafficlights(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.tafficlights)
  return tafficlights_.Mutable(index);
}
::hdmap::TrafficLight* HDMap::add_tafficlights() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.tafficlights)
  return tafficlights_.Add();
}
::google::protobuf::RepeatedPtrField< ::hdmap::TrafficLight >*
HDMap::mutable_tafficlights() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.tafficlights)
  return &tafficlights_;
}
const ::google::protobuf::RepeatedPtrField< ::hdmap::TrafficLight >&
HDMap::tafficlights() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.tafficlights)
  return tafficlights_;
}

// repeated .hdmap.LaneMarking lanemarkings = 4;
int HDMap::lanemarkings_size() const {
  return lanemarkings_.size();
}
void HDMap::clear_lanemarkings() {
  lanemarkings_.Clear();
}
const ::hdmap::LaneMarking& HDMap::lanemarkings(int index) const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Get(index);
}
::hdmap::LaneMarking* HDMap::mutable_lanemarkings(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Mutable(index);
}
::hdmap::LaneMarking* HDMap::add_lanemarkings() {
  // @@protoc_insertion_point(field_add:hdmap.HDMap.lanemarkings)
  return lanemarkings_.Add();
}
::google::protobuf::RepeatedPtrField< ::hdmap::LaneMarking >*
HDMap::mutable_lanemarkings() {
  // @@protoc_insertion_point(field_mutable_list:hdmap.HDMap.lanemarkings)
  return &lanemarkings_;
}
const ::google::protobuf::RepeatedPtrField< ::hdmap::LaneMarking >&
HDMap::lanemarkings() const {
  // @@protoc_insertion_point(field_list:hdmap.HDMap.lanemarkings)
  return lanemarkings_;
}

// string version = 5;
void HDMap::clear_version() {
  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& HDMap::version() const {
  // @@protoc_insertion_point(field_get:hdmap.HDMap.version)
  return version_.GetNoArena();
}
void HDMap::set_version(const ::std::string& value) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hdmap.HDMap.version)
}
#if LANG_CXX11
void HDMap::set_version(::std::string&& value) {
  
  version_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hdmap.HDMap.version)
}
#endif
void HDMap::set_version(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hdmap.HDMap.version)
}
void HDMap::set_version(const char* value, size_t size) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hdmap.HDMap.version)
}
::std::string* HDMap::mutable_version() {
  
  // @@protoc_insertion_point(field_mutable:hdmap.HDMap.version)
  return version_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* HDMap::release_version() {
  // @@protoc_insertion_point(field_release:hdmap.HDMap.version)
  
  return version_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void HDMap::set_allocated_version(::std::string* version) {
  if (version != NULL) {
    
  } else {
    
  }
  version_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), version);
  // @@protoc_insertion_point(field_set_allocated:hdmap.HDMap.version)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap

// @@protoc_insertion_point(global_scope)
