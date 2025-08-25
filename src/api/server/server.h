//
// Created by Dhanush Nadella on 8/17/25.
//

#ifndef API_SERVER_H
#define API_SERVER_H
#include <string>

#include "grpcpp/server.h"

namespace api::server {

class Server {
public:
    Server(const std::string& server_address, const std::string& db_host, const int& db_port, const std::string& db_name, const std::string& db_user, const std::string& db_pwd);
    void Shutdown() const;
private:
    std::unique_ptr<grpc::Server> server_;
};

}



#endif //API_SERVER_H
