//
// Created by Dhanush Nadella on 8/12/25.
//

#ifndef POSTGRES_CLIENT_H
#define POSTGRES_CLIENT_H
#include <pqxx/pqxx>

namespace db {

class PostgresClient {
public:
    PostgresClient(const std::string& host, const int& port, const std::string& dbname, const std::string& user, std::string& password);
private:
    pqxx::connection connection_;
};

}

#endif //POSTGRES_CLIENT_H
