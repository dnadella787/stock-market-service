//
// Created by Dhanush Nadella on 8/12/25.
//

#include "postgres_client.h"
#include "spdlog/spdlog.h"

namespace server {
    class ApiServer;
}

namespace db {
PostgresClient::PostgresClient(
           const std::string& host,
           const int& port,
           const std::string& dbname,
           const std::string& user,
           const std::string& password)
: connection_(std::format("host={} port={} dbname={} user={} password={}", host, port, dbname, user, password))
{
    if (!connection_.is_open()) {
        throw std::runtime_error("Failed to connect to postgres DB");
    }
    spdlog::info("Postgres DB client successfully initialized");
}

std::shared_ptr<PostgresClient> get_postgres_client(
            const std::string& host,
            const int& port,
            const std::string& dbname,
            const std::string& user,
            const std::string& password) {
    return std::make_shared<PostgresClient>(host, port, dbname, user, password);
}

// pqxx::result PostgresClient::exec_read(const constexpr std::string_view& query_name, const pqxx::params &params) {
//     pqxx::read_transaction txn{connection_};
//     return txn.exec(query_name, params);
// }
//
// pqxx::result PostgresClient::exec_commit(const std::string& query) {
//     pqxx::work txn{connection_};
//     const pqxx::result res = txn.exec(query);
//     txn.commit();
//     return res;
// }

}
