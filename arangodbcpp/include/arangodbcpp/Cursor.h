#ifndef FUERTE_CURSOR_H
#define FUERTE_CURSOR_H

#include "arangodbcpp/Database.h"
#include "arangodbcpp/Connection.h"

namespace arangodb {

namespace dbinterface {

class Cursor {
 public:
  typedef std::shared_ptr<Cursor> SPtr;
  enum class CacheMode : uint8_t { on = 0, off, demand };

  Cursor(const Database::SPtr& inp);
  Cursor() = delete;

  void httpCreate(const Connection::SPtr& pCon, const std::string query,
                  uint16_t batSize = 0, const bool bAsync = false);
  void httpCreate(const Connection::SPtr& pCon, const Connection::VPack& config,
                  const bool bAsync = false);
  static Connection::VPack httpCreate(const bool bSort,
                                      const Connection::SPtr& pCon);

  void httpMore(const Connection::SPtr& pCon, std::string id,
                const bool bAsync = false);
  static Connection::VPack httpMore(const bool bSort,
                                    const Connection::SPtr& pCon);

  void httpAddFnc(const Connection::SPtr& pCon, const std::string& name,
                  const std::string& code, const bool bAsync);
  static Connection::VPack httpAddFnc(bool bSort, const Connection::SPtr& pCon);

  void httpDeleteFnc(const Connection::SPtr& pCon, const std::string& name,
                     const bool bAsync);
  static Connection::VPack httpDeleteFnc(const bool bSort,
                                         const Connection::SPtr& pCon);

  void httpGetFncs(const Connection::SPtr& pCon, const bool bAsync);
  static Connection::VPack httpGetFncs(const bool bSort,
                                       const Connection::SPtr& pCon);

  void httpDelete(const Connection::SPtr& pCon, std::string id,
                  const bool bAsync = false);
  static Connection::VPack httpDelete(const bool bSort,
                                      const Connection::SPtr& pCon);

  void httpClearCache(const Connection::SPtr& pCon, const bool bAsync = false);
  static Connection::VPack httpClearCache(const bool bSort,
                                          const Connection::SPtr& pCon);

  void httpCacheProperties(const Connection::SPtr& pCon,
                           const bool bAsync = false);
  static Connection::VPack httpCacheProperties(const bool bSort,
                                               const Connection::SPtr& pCon);

  void httpSetCacheProps(const Connection::SPtr& pCon, enum CacheMode mode,
                         uint16_t max, const bool bAsync = false);
  static Connection::VPack httpSetCacheProps(const bool bSort,
                                             const Connection::SPtr& pCon);

  static std::string moreId(const Connection::VPack& res);

 private:
  std::string httpCursorUrl() const;
  std::string httpAqlFnc() const;
  std::string httpCacheUrl() const;
  std::string httpCachePropsUrl() const;

  Database::SPtr _database;
};

inline Cursor::Cursor(const Database::SPtr& inp) : _database(inp) {}

std::ostream& operator<<(std::ostream& os, Cursor::CacheMode mode);

inline Connection::VPack Cursor::httpCreate(const bool bSort,
                                            const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpMore(const bool bSort,
                                          const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpDelete(const bool bSort,
                                            const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpClearCache(const bool bSort,
                                                const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpCacheProperties(
    const bool bSort, const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpSetCacheProps(
    bool bSort, const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpAddFnc(const bool bSort,
                                            const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpDeleteFnc(bool bSort,
                                               const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}

inline Connection::VPack Cursor::httpGetFncs(const bool bSort,
                                             const Connection::SPtr& pCon) {
  return pCon->fromJSon(bSort);
}
}
}

#endif  // FUERTE_CURSOR_H
