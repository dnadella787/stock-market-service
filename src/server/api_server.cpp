//
// Created by Dhanush Nadella on 8/17/25.
//

#include "api_server.h"
#include "../api_service/exchange_service.h"
#include "../api_service/security_service.h"
#include "../dal/exchange_dao.h"
#include "../dal/security_dao.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include <pqxx/connection>
#include "spdlog/spdlog.h"

namespace server {

ApiServer::ApiServer(
            const std::string &server_address,
            const std::string &db_host,
            const int &db_port,
            const std::string &db_name,
            const std::string &db_user,
            const std::string &db_pwd) {
    const std::shared_ptr<pqxx::connection> pg_conn = std::make_shared<pqxx::connection>(std::format("host={} port={} dbname={} user={} password={}", db_host, db_port, db_name, db_user, db_pwd));
    const std::shared_ptr<dal::ExchangeDao> exchange_dao = std::make_shared<dal::ExchangeDao>(pg_conn);
    const std::shared_ptr<dal::SecurityDao> security_dao = std::make_shared<dal::SecurityDao>(pg_conn);

    api_service::SecurityServiceImpl security_service(security_dao);
    api_service::ExchangeServiceImpl exchange_service(exchange_dao);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&security_service);
    builder.RegisterService(&exchange_service);

    server_ = builder.BuildAndStart();
    spdlog::info("Starting server on {}", server_address);
    server_->Wait();
}

void ApiServer::Shutdown() const {
    server_->Shutdown();
    spdlog::info("Successfully shutdown server");
}

} // server namespace
