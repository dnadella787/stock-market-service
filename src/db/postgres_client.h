//
// Created by Dhanush Nadella on 8/12/25.
//

#ifndef POSTGRES_CLIENT_H
#define POSTGRES_CLIENT_H
#include <pqxx/pqxx>

#include "../server/api_server.h"

namespace db {

class PostgresClient {
public:
    // Private constructor
    PostgresClient(const std::string& host, const int& port, const std::string& dbname, const std::string& user, const std::string& password);
private:
    // Private variables
    pqxx::connection connection_;
public:
    // pqxx::result exec_read(const constexpr std::string_view& query_name, const pqxx::params &params);
    // pqxx::result exec_commit(const std::string& query);
};

std::shared_ptr<PostgresClient> get_postgres_client(const std::string& host, const int& port, const std::string& dbname, const std::string& user, const std::string& password);
}

#endif //POSTGRES_CLIENT_H
