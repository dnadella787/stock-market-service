//
// Created by Dhanush Nadella on 8/11/25.
//

#include "exchange_service.h"
#include "spdlog/spdlog.h"

using namespace service;

namespace apiservice {

ExchangeServiceImpl::ExchangeServiceImpl(std::shared_ptr<db::PostgresClient> db_client) {
    db_client_ = db_client;
}

grpc::Status ExchangeServiceImpl::GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) {
    return grpc::Status::OK;
}

grpc::Status ExchangeServiceImpl::ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) {
    return grpc::Status::OK;
}


} // apiservice