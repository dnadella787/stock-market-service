//
// Created by Dhanush Nadella on 8/17/25.
//

#include "server.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "../services/exchange_service.h"
#include "../services/security_service.h"
#include "absl/log/log.h"

namespace api::server {

Server::Server(const ServerCfg& cfg) {
	const std::shared_ptr<pqxx::connection> pg_conn = std::make_shared<pqxx::connection>(
	    std::format("host={} port={} dbname={} user={} password={}", cfg.db_host, cfg.db_port, cfg.db_name, cfg.db_user, cfg.db_pwd));
	const std::shared_ptr<dal::dao::ExchangeDao> exchange_dao = std::make_shared<dal::dao::ExchangeDao>(pg_conn);
	const std::shared_ptr<dal::dao::SecurityDao> security_dao = std::make_shared<dal::dao::SecurityDao>(pg_conn);

	service::SecurityServiceImpl security_service(security_dao);
	service::ExchangeServiceImpl exchange_service(exchange_dao);

	grpc::ServerBuilder builder;
	builder.AddListeningPort(cfg.server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&security_service);
	builder.RegisterService(&exchange_service);

	server_ = builder.BuildAndStart();
	LOG(INFO) << "Starting server on " << cfg.server_address;
	server_->Wait();
}

void Server::Shutdown() const {
	server_->Shutdown();
	LOG(INFO) << "Successfully shutdown server";
}

} // namespace api::server
