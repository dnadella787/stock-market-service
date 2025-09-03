//
// Created by Dhanush Nadella on 8/17/25.
//

#ifndef API_SERVER_H
#define API_SERVER_H
#include <string>

#include "grpcpp/server.h"

namespace api::server {

struct ServerCfg {
	std::string server_address;
	std::string db_host;
	int db_port;
	std::string db_name;
	std::string db_user;
	std::string db_pwd;
};

class Server {
public:
	Server(const ServerCfg& cfg);
	void Shutdown() const;

private:
	std::unique_ptr<grpc::Server> server_ = nullptr;
};

} // namespace api::server

#endif // API_SERVER_H
