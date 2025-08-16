//
// Created by Dhanush Nadella on 8/12/25.
//

#include "postgres_client.h"
#include "spdlog/spdlog.h"

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

}
