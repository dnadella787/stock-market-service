//
// Created by Dhanush Nadella on 8/12/25.
//

#include "postgres_client.h"

#include "spdlog/spdlog.h"

namespace db {
    PostgresClient::PostgresClient(const std::string& host, const int& port, const std::string& dbname, const std::string& user, std::string& password) {
        std::string connection_uri = std::format("host={} port={} dbname={} user={} password={}", host, port, dbname, user, password);
        spdlog::info("Initiating connection to Postgres DB (host={}:{}, dbname={})", host, port, dbname);
        connection_ = pqxx::connection(connection_uri);
        spdlog::info("Postgres client successfully initialized");
        password.clear();
    }

}
