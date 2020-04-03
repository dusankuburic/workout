// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simple.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_simple_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_simple_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_simple_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_simple_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_simple_2eproto;
namespace example {
namespace simple {
class SimpleMessage;
class SimpleMessageDefaultTypeInternal;
extern SimpleMessageDefaultTypeInternal _SimpleMessage_default_instance_;
}  // namespace simple
}  // namespace example
PROTOBUF_NAMESPACE_OPEN
template<> ::example::simple::SimpleMessage* Arena::CreateMaybeMessage<::example::simple::SimpleMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace example {
namespace simple {

// ===================================================================

class SimpleMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:example.simple.SimpleMessage) */ {
 public:
  SimpleMessage();
  virtual ~SimpleMessage();

  SimpleMessage(const SimpleMessage& from);
  SimpleMessage(SimpleMessage&& from) noexcept
    : SimpleMessage() {
    *this = ::std::move(from);
  }

  inline SimpleMessage& operator=(const SimpleMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline SimpleMessage& operator=(SimpleMessage&& from) noexcept {
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
  static const SimpleMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SimpleMessage* internal_default_instance() {
    return reinterpret_cast<const SimpleMessage*>(
               &_SimpleMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SimpleMessage& a, SimpleMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(SimpleMessage* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SimpleMessage* New() const final {
    return CreateMaybeMessage<SimpleMessage>(nullptr);
  }

  SimpleMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SimpleMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SimpleMessage& from);
  void MergeFrom(const SimpleMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SimpleMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "example.simple.SimpleMessage";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_simple_2eproto);
    return ::descriptor_table_simple_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSampleListFieldNumber = 4,
    kNameFieldNumber = 3,
    kIdFieldNumber = 1,
    kIsSimpleFieldNumber = 2,
  };
  // repeated int32 sample_list = 4;
  int sample_list_size() const;
  private:
  int _internal_sample_list_size() const;
  public:
  void clear_sample_list();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_sample_list(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_sample_list() const;
  void _internal_add_sample_list(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_sample_list();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 sample_list(int index) const;
  void set_sample_list(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_sample_list(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      sample_list() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_sample_list();

  // string name = 3;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // int32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // bool is_simple = 2;
  void clear_is_simple();
  bool is_simple() const;
  void set_is_simple(bool value);
  private:
  bool _internal_is_simple() const;
  void _internal_set_is_simple(bool value);
  public:

  // @@protoc_insertion_point(class_scope:example.simple.SimpleMessage)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > sample_list_;
  mutable std::atomic<int> _sample_list_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  bool is_simple_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_simple_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SimpleMessage

// int32 id = 1;
inline void SimpleMessage::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SimpleMessage::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SimpleMessage::id() const {
  // @@protoc_insertion_point(field_get:example.simple.SimpleMessage.id)
  return _internal_id();
}
inline void SimpleMessage::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void SimpleMessage::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:example.simple.SimpleMessage.id)
}

// bool is_simple = 2;
inline void SimpleMessage::clear_is_simple() {
  is_simple_ = false;
}
inline bool SimpleMessage::_internal_is_simple() const {
  return is_simple_;
}
inline bool SimpleMessage::is_simple() const {
  // @@protoc_insertion_point(field_get:example.simple.SimpleMessage.is_simple)
  return _internal_is_simple();
}
inline void SimpleMessage::_internal_set_is_simple(bool value) {
  
  is_simple_ = value;
}
inline void SimpleMessage::set_is_simple(bool value) {
  _internal_set_is_simple(value);
  // @@protoc_insertion_point(field_set:example.simple.SimpleMessage.is_simple)
}

// string name = 3;
inline void SimpleMessage::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& SimpleMessage::name() const {
  // @@protoc_insertion_point(field_get:example.simple.SimpleMessage.name)
  return _internal_name();
}
inline void SimpleMessage::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:example.simple.SimpleMessage.name)
}
inline std::string* SimpleMessage::mutable_name() {
  // @@protoc_insertion_point(field_mutable:example.simple.SimpleMessage.name)
  return _internal_mutable_name();
}
inline const std::string& SimpleMessage::_internal_name() const {
  return name_.GetNoArena();
}
inline void SimpleMessage::_internal_set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void SimpleMessage::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:example.simple.SimpleMessage.name)
}
inline void SimpleMessage::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:example.simple.SimpleMessage.name)
}
inline void SimpleMessage::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:example.simple.SimpleMessage.name)
}
inline std::string* SimpleMessage::_internal_mutable_name() {
  
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* SimpleMessage::release_name() {
  // @@protoc_insertion_point(field_release:example.simple.SimpleMessage.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void SimpleMessage::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:example.simple.SimpleMessage.name)
}

// repeated int32 sample_list = 4;
inline int SimpleMessage::_internal_sample_list_size() const {
  return sample_list_.size();
}
inline int SimpleMessage::sample_list_size() const {
  return _internal_sample_list_size();
}
inline void SimpleMessage::clear_sample_list() {
  sample_list_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SimpleMessage::_internal_sample_list(int index) const {
  return sample_list_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SimpleMessage::sample_list(int index) const {
  // @@protoc_insertion_point(field_get:example.simple.SimpleMessage.sample_list)
  return _internal_sample_list(index);
}
inline void SimpleMessage::set_sample_list(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  sample_list_.Set(index, value);
  // @@protoc_insertion_point(field_set:example.simple.SimpleMessage.sample_list)
}
inline void SimpleMessage::_internal_add_sample_list(::PROTOBUF_NAMESPACE_ID::int32 value) {
  sample_list_.Add(value);
}
inline void SimpleMessage::add_sample_list(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_sample_list(value);
  // @@protoc_insertion_point(field_add:example.simple.SimpleMessage.sample_list)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
SimpleMessage::_internal_sample_list() const {
  return sample_list_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
SimpleMessage::sample_list() const {
  // @@protoc_insertion_point(field_list:example.simple.SimpleMessage.sample_list)
  return _internal_sample_list();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
SimpleMessage::_internal_mutable_sample_list() {
  return &sample_list_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
SimpleMessage::mutable_sample_list() {
  // @@protoc_insertion_point(field_mutable_list:example.simple.SimpleMessage.sample_list)
  return _internal_mutable_sample_list();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace simple
}  // namespace example

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_simple_2eproto