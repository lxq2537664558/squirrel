/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "async_request_object_types.h"

namespace squirrel { namespace common {

const char* AsyncRequestObject::ascii_fingerprint = "8CFADE1976027CCC2C5EFD96B68CDAD3";
const uint8_t AsyncRequestObject::binary_fingerprint[16] = {0x8C,0xFA,0xDE,0x19,0x76,0x02,0x7C,0xCC,0x2C,0x5E,0xFD,0x96,0xB6,0x8C,0xDA,0xD3};

uint32_t AsyncRequestObject::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_request_id_ = false;
  bool isset_terminal_guid_ = false;
  bool isset_type_ = false;
  bool isset_storage_type_ = false;
  bool isset_key_ = false;
  bool isset_key_hash_value_ = false;
  bool isset_request_ = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->request_id_);
          isset_request_id_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->terminal_guid_);
          isset_terminal_guid_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->type_ = ( ::squirrel::common::RequestType::type)ecast0;
          isset_type_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast1;
          xfer += iprot->readI32(ecast1);
          this->storage_type_ = ( ::squirrel::common::StorageType::type)ecast1;
          isset_storage_type_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->key_);
          isset_key_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->key_hash_value_);
          isset_key_hash_value_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->request_);
          isset_request_ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_request_id_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_terminal_guid_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_type_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_storage_type_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_key_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_key_hash_value_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_request_)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t AsyncRequestObject::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("AsyncRequestObject");
  xfer += oprot->writeFieldBegin("request_id_", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->request_id_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("terminal_guid_", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->terminal_guid_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("type_", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->type_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("storage_type_", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((int32_t)this->storage_type_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("key_", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeBinary(this->key_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("key_hash_value_", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->key_hash_value_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("request_", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeBinary(this->request_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}} // namespace
