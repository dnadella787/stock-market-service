//
// Created by Dhanush Nadella on 8/11/25.
//

#ifndef EXCHANGE_SERVICE_H
#define EXCHANGE_SERVICE_H
#include "service/exchange.grpc.pb.h"
#include "../db/postgres_client.h"

using namespace service;

namespace apiservice {

class ExchangeServiceImpl final : public ExchangeService::Service {

public:
    ExchangeServiceImpl(std::shared_ptr<db::PostgresClient> db_client);

    // API implementations
    grpc::Status GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) override;
    grpc::Status ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) override;
private:
    std::shared_ptr<db::PostgresClient> db_client_;
};

} // apiservice

#endif //EXCHANGE_SERVICE_H
