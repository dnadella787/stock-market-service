//
// Created by Dhanush Nadella on 8/17/25.
//

#include "api_server.h"
#include "../db/postgres_client.h"
#include "../apiservice/exchange_service.h"
#include "../apiservice/security_service.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "spdlog/spdlog.h"

namespace server {

ApiServer::ApiServer(const std::string &server_address, const std::string &db_host, const int &db_port, const std::string &db_name, const std::string &db_user, const std::string &db_pwd) {
    const std::shared_ptr<db::PostgresClient> pg_client = db::get_postgres_client(db_host, db_port, db_name, db_user, db_pwd);

    apiservice::SecurityServiceImpl security_service(pg_client);
    apiservice::ExchangeServiceImpl exchange_service(pg_client);

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
