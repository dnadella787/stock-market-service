//
// Created by Dhanush Nadella on 8/17/25.
//

#ifndef API_SERVER_H
#define API_SERVER_H
#include <string>

#include "grpcpp/server.h"
#include "../db/postgres_client.h"

namespace server {

class ApiServer {
public:
    ApiServer(const std::string& server_address, const std::string& db_host, const int& db_port, const std::string& db_name, const std::string& db_user, const std::string& db_pwd);
private:
    grpc::Server* server_;
};

} // server namespace



#endif //API_SERVER_H
