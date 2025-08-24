//
// Created by Dhanush Nadella on 8/23/25.
//

#include "security_dao.h"

namespace dal {

SecurityDao::SecurityDao(std::shared_ptr<pqxx::connection> pg_conn) : pg_conn_(pg_conn) {}

}