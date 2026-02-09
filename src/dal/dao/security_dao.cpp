//
// Created by Dhanush Nadella on 8/23/25.
//

#include "dal/dao/security_dao.h"

namespace dal::dao {

SecurityDao::SecurityDao(const std::shared_ptr<store::PostgresDataStore> &pg_conn) : pg_(pg_conn) {}

} // namespace dal::dao