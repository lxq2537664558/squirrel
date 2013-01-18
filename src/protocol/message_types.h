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



namespace squirrel { namespace protocol {

struct DataType {
  enum type {
    DATA_TYPE_KEYVALUE = 0,
    DATA_TYPE_NUMBER = 1,
    DATA_TYPE_LIST = 2,
    DATA_TYPE_MAP = 3
  };
};

extern const std::map<int, const char*> _DataType_VALUES_TO_NAMES;

struct StorageType {
  enum type {
    STORAGE_TYPE_CACHE = 1,
    STORAGE_TYPE_DISK = 2
  };
};

extern const std::map<int, const char*> _StorageType_VALUES_TO_NAMES;


class Request {
 public:

  static const char* ascii_fingerprint; // = "320A4E0A7D1C541E521D7F65F2108F77";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x0A,0x4E,0x0A,0x7D,0x1C,0x54,0x1E,0x52,0x1D,0x7F,0x65,0xF2,0x10,0x8F,0x77};

  Request() : data_type_((DataType::type)0), storage_type_((StorageType::type)0), request_("") {
  }

  virtual ~Request() throw() {}

  DataType::type data_type_;
  StorageType::type storage_type_;
  std::string request_;

  void __set_data_type_(const DataType::type val) {
    data_type_ = val;
  }

  void __set_storage_type_(const StorageType::type val) {
    storage_type_ = val;
  }

  void __set_request_(const std::string& val) {
    request_ = val;
  }

  bool operator == (const Request & rhs) const
  {
    if (!(data_type_ == rhs.data_type_))
      return false;
    if (!(storage_type_ == rhs.storage_type_))
      return false;
    if (!(request_ == rhs.request_))
      return false;
    return true;
  }
  bool operator != (const Request &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Request & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Response {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  Response() : data_type_((DataType::type)0), response_("") {
  }

  virtual ~Response() throw() {}

  DataType::type data_type_;
  std::string response_;

  void __set_data_type_(const DataType::type val) {
    data_type_ = val;
  }

  void __set_response_(const std::string& val) {
    response_ = val;
  }

  bool operator == (const Response & rhs) const
  {
    if (!(data_type_ == rhs.data_type_))
      return false;
    if (!(response_ == rhs.response_))
      return false;
    return true;
  }
  bool operator != (const Response &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Response & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

}} // namespace

#endif
