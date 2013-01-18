/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef message_TYPES_H
#define message_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace squirrel { namespace common {

struct MessageType {
  enum type {
    MESSAGE_TYPE_SCHEDULE = 0,
    MESSAGE_TYPE_ROUTE = 1,
    MESSAGE_TYPE_DATA_PROXY = 2,
    MESSAGE_TYPE_GATEWAY = 3
  };
};

extern const std::map<int, const char*> _MessageType_VALUES_TO_NAMES;


class Message {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  Message() : type_((MessageType::type)0), message_("") {
  }

  virtual ~Message() throw() {}

  MessageType::type type_;
  std::string message_;

  void __set_type_(const MessageType::type val) {
    type_ = val;
  }

  void __set_message_(const std::string& val) {
    message_ = val;
  }

  bool operator == (const Message & rhs) const
  {
    if (!(type_ == rhs.type_))
      return false;
    if (!(message_ == rhs.message_))
      return false;
    return true;
  }
  bool operator != (const Message &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Message & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

}} // namespace

#endif
