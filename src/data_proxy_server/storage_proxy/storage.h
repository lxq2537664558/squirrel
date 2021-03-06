//
// Summary: squirrel source code.
//
// Author: Tony.
// Email: tonyjobmails@gmail.com.
// Last modify: 2012-09-05 20:35:27.
// File name: storage.h
//
// Description: 
// Define class Storage.
//

#ifndef _squirrel_dataproxy_storage__STORAGE__H
#define _squirrel_dataproxy_storage__STORAGE__H

#include <string>

#include <boost/shared_ptr.hpp>
#include <mysql++/mysql++.h>

#include "core/base/types.h"
#include "core/base/noncopyable.h"
#include "data_proxy_server/storage_proxy/procedure_type.h"
#include "data_proxy_server/storage_proxy/procedure_configure.h"

namespace squirrel {

namespace dataproxy {

namespace storage {

class Storage : public core::Noncopyable {
  // typedef boost::shared_ptr<mysqlpp::Connection> MysqlConnectionPtr;
 public:
  enum { STORAGE_SERIOUS_ERROR = -1, };

  Storage();
  ~Storage();

  bool Initialize(const std::string &host, core::uint16 port,
    const std::string &user, const std::string &passwd,
    const std::string &db, const ProcedureConfigure &configure);

  bool Start();
  bool Reconnect();

  bool CheckConnectState() { return this->connecting_; }

  //////////////////////////////////////
  // Key-Value type:
  //  Set (key to set, value to set).
  int KeyvalueSet(const std::string &key, const std::string &value);
  //  Get (key to get, value to get).
  int KeyvalueGet(const std::string &key, std::string &value);
  //  Delete (key to delete).
  int KeyvalueDelete(const std::string &key);
  //////////////////////////////////////

  //////////////////////////////////////
  // Number type.
  //  Increase (key to increase, increment value, value returned).
  int NumberIncrease(const std::string &key, const std::string &increment, std::string &value);
  //  Decrease (key to increase, decrement value, value returned).
  int NumberDecrease(const std::string &key, const std::string &decrement, std::string &value);
  //  Reset (key to set zero).
  int NumberReset(const std::string &key);
  //  Delete (key to delete).
  int NumberDelete(const std::string &key);
  //////////////////////////////////////

  //////////////////////////////////////
  // List type.
  //  Push (key to push, element).
  int ListPush(const std::string &key, const std::string &element);
  //  Pop (key to pop, element returned).
  int ListPop(const std::string &key, std::string &element);
  //  Remove (key to remove, element to remove).
  int ListRemove(const std::string &key, const std::string &element);
  //  Clear (key to clear).
  int ListClear(const std::string &key);
  //  Delete (key to delete).
  int ListDelete(const std::string &key);
  //////////////////////////////////////

  //////////////////////////////////////
  // Map type.
  //  Insert (key, score is rank value, element).
  int MapInsert(const std::string &key, const std::string &score, const std::string &element);
  //  Remove (key, element).
  int MapRemove(const std::string &key, const std::string &element);
  //  Query rank (key, element, sort type[true for asc, false for desc]).
  int MapQueryRank(const std::string &key, const std::string &element, std::string &ranking, bool asc);
  //  Query sort range (key, rank start value, rank end value, sort type[true for asc, false for desc]).
  int MapQueryRange(const std::string &key, const std::string &rank_start,
      const std::string &rank_end, bool asc);
  //  Auery sort range and response with scores(key, rank start value, rank end value, sort type).
  int MapQueryRangeWithscores(const std::string &key, const std::string &rank_start,
      const std::string &rank_end, bool asc);
  //  Fetch sort range value (score the element's, element).
  bool MapFetchRangeValue(std::string &element, size_t index);
  bool MapFetchRangeValueWithscores(std::string &score, std::string &element, size_t index);
  //  Quit fetch range, to free reply object.
  void MapQuitFetchRange();
  //  Reset element's score(key, element, new score).
  int MapResetScore(const std::string &key, const std::string &score, const std::string &element);
  //  Clear (key to clear).
  int MapClear(const std::string &key);
  //  Delete (key to delete).
  int MapDelete(const std::string &key);
  //////////////////////////////////////

 private:
  void ResetQuery();

  bool Connected();

  bool connecting_;

  std::string procedure_[ProcedureType::PROCEDURE_MAX];
  std::string db_name_;
  std::string host_;
  core::uint16 port_;
  std::string user_;
  std::string passwd_;

  //MysqlConnectionPtr connection_;
  mysqlpp::Connection connection_;
  mysqlpp::Query query_;
  mysqlpp::StoreQueryResult result_;
};

typedef boost::shared_ptr<Storage> StoragePtr;

}  // namespace storage

}  // namespace dataproxy

}  // namespace squirrel

#endif  // _squirrel_dataproxy_storage__STORAGE__H

