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

Server::Server(const config::ApiServerCfg &cfg) {
	// TODO: write pqxx::connection wrapper and pass it off to DAL
	const std::shared_ptr<dal::store::PostgresDataStore> pg_conn = std::make_shared<dal::store::PostgresDataStore>(
		cfg.db_config_.host_, cfg.db_config_.port_, cfg.db_config_.name_, cfg.db_config_.username_, cfg.db_config_.password_);
	const std::shared_ptr<dal::dao::ExchangeDao> exchange_dao = std::make_shared<dal::dao::ExchangeDao>(pg_conn);
	const std::shared_ptr<dal::dao::SecurityDao> security_dao = std::make_shared<dal::dao::SecurityDao>(pg_conn);

	service::SecurityServiceImpl security_service(security_dao);
	service::ExchangeServiceImpl exchange_service(exchange_dao);

	grpc::ServerBuilder builder;
	builder.AddListeningPort(cfg.server_address_, grpc::InsecureServerCredentials());
	builder.RegisterService(&security_service);
	builder.RegisterService(&exchange_service);

	server_ = builder.BuildAndStart();
	LOG(INFO) << "Starting server on " << cfg.server_address_;
	server_->Wait();
}

void Server::Shutdown() const {
	server_->Shutdown();
	LOG(INFO) << "Successfully shutdown server";
}

} // namespace api::server
