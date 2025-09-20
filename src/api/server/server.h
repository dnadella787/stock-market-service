//
// Created by Dhanush Nadella on 8/17/25.
//

#ifndef API_SERVER_H
#define API_SERVER_H
#include <string>

#include "../config/server_config.h"
#include "grpcpp/server.h"

namespace api::server {

class Server {
public:
	Server(const config::ApiServerCfg &cfg);
	void Shutdown() const;

private:
	std::unique_ptr<grpc::Server> server_ = nullptr;
};

} // namespace api::server

#endif // API_SERVER_H
