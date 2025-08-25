//
// Created by Dhanush Nadella on 8/23/25.
//

#include "dao/security_dao.h"

namespace dal::dao {

SecurityDao::SecurityDao(const std::shared_ptr<pqxx::connection> &pg_conn) : pg_conn_(pg_conn) {}

}