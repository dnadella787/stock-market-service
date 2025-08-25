//
// Created by Dhanush Nadella on 8/17/25.
//

#include "server.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "spdlog/spdlog.h"
#include "../services/exchange_service.h"
#include "../services/security_service.h"

namespace api::server {

Server::Server(
            const std::string &server_address,
            const std::string &db_host,
            const int &db_port,
            const std::string &db_name,
            const std::string &db_user,
            const std::string &db_pwd) {
    const std::shared_ptr<pqxx::connection> pg_conn = std::make_shared<pqxx::connection>(std::format("host={} port={} dbname={} user={} password={}", db_host, db_port, db_name, db_user, db_pwd));
    const std::shared_ptr<dal::dao::ExchangeDao> exchange_dao = std::make_shared<dal::dao::ExchangeDao>(pg_conn);
    const std::shared_ptr<dal::dao::SecurityDao> security_dao = std::make_shared<dal::dao::SecurityDao>(pg_conn);

    service::SecurityServiceImpl security_service(security_dao);
    service::ExchangeServiceImpl exchange_service(exchange_dao);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&security_service);
    builder.RegisterService(&exchange_service);

    server_ = builder.BuildAndStart();
    spdlog::info("Starting server on {}", server_address);
    server_->Wait();
}

void Server::Shutdown() const {
    server_->Shutdown();
    spdlog::info("Successfully shutdown server");
}

}
