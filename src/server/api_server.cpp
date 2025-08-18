//
// Created by Dhanush Nadella on 8/17/25.
//

#include "api_server.h"
#include "../db/postgres_client.h"
#include "../apiservice/stock_market.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "spdlog/spdlog.h"

namespace server {

ApiServer::ApiServer(const std::string &server_address, const std::string &db_host, const int &db_port, const std::string &db_name, const std::string &db_user, const std::string &db_pwd) {
    const std::unique_ptr<db::PostgresClient> pg_client = db::get_postgres_client(db_host, db_port, db_name, db_user, db_pwd);
    service::StockMarketServiceImpl stock_market_service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&stock_market_service);

    server_(builder.BuildAndStart());
    spdlog::info("Starting server on {}", server_address);
    server_->Wait();
}



} // server namespace
