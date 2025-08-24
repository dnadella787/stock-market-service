//
// Created by Dhanush Nadella on 8/11/25.
//

#include "exchange_service.h"

#include "exceptions/entity_not_found_exception.h"
#include "spdlog/spdlog.h"

using namespace service;

namespace api {
namespace service {

ExchangeServiceImpl::ExchangeServiceImpl(std::shared_ptr<dal::ExchangeDao> exchange_dao) {
    exchange_dao_ = exchange_dao;
}

grpc::Status ExchangeServiceImpl::GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) {
    spdlog::info("Received GetExchange request for exchange_code={}", request->code());
    try {
        std::unique_ptr<model::Exchange> db_exchange = exchange_dao_->GetExchange(request->code());

        Exchange* exchange = response->mutable_exchange();
        exchange->set_code(db_exchange->code);
        exchange->set_full_name(db_exchange->name);
        exchange->set_city(db_exchange->city);
        exchange->set_country(db_exchange->country);

        spdlog::info("Returning successful GetExchange response for exchange_code={}", request->code());
        return grpc::Status::OK;
    } catch (const dal::EntityNotFoundException &e) {
        spdlog::error("Exchange with code={} could not be found in DB", request->code());
        return grpc::Status(grpc::StatusCode::NOT_FOUND, e.what());
    }
}

grpc::Status ExchangeServiceImpl::ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) {
    return grpc::Status::OK;
}

} // apiservice
}
