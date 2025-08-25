//
// Created by Dhanush Nadella on 8/11/25.
//

#ifndef EXCHANGE_SERVICE_H
#define EXCHANGE_SERVICE_H
#include "../../dal/include/dao/exchange_dao.h"
#include "service/exchange.grpc.pb.h"

using namespace service;

namespace api::service {

class ExchangeServiceImpl final : public ExchangeService::Service {
public:
    ExchangeServiceImpl(const std::shared_ptr<dal::dao::ExchangeDao> &exchange_dao);

    // API implementations
    grpc::Status GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) override;
    grpc::Status ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) override;
private:
    std::shared_ptr<dal::dao::ExchangeDao> exchange_dao_;
};

}

#endif //EXCHANGE_SERVICE_H
