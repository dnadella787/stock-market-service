//
// Created by Dhanush Nadella on 8/12/25.
//

#ifndef POSTGRES_CLIENT_H
#define POSTGRES_CLIENT_H
#include <pqxx/pqxx>

#include "../server/api_server.h"

namespace db {

class PostgresClient {
private:
    // Private constructor
    PostgresClient(const std::string& host, const int& port, const std::string& dbname, const std::string& user, const std::string& password);

    // Prototype factory method that has access to PostgresClient private constructor
    // Returns a unique client each time, not a singleton instance of the PG client
    friend std::unique_ptr<PostgresClient> get_postgres_client(const std::string& host, const int& port, const std::string& dbname, const std::string& user, const std::string& password);

    // Private variables
    pqxx::connection connection_;
};

std::unique_ptr<PostgresClient> get_postgres_client(const std::string& host, const int& port, const std::string& dbname, const std::string& user, const std::string& password);
}

#endif //POSTGRES_CLIENT_H
