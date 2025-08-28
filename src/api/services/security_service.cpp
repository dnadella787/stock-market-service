//
// Created by Dhanush Nadella on 8/23/25.
//

#include "security_service.h"

#include "absl/log/log.h"

using namespace service;

namespace api::service {

SecurityServiceImpl::SecurityServiceImpl(const std::shared_ptr<dal::dao::SecurityDao> &security_dao) {
    security_dao_ = security_dao;
}

grpc::Status SecurityServiceImpl::GetSecurity(grpc::ServerContext* context, const GetSecurityRequest* request, GetSecurityResponse* response) {
    LOG(INFO) << "Received GetSecurity request with symbol=" << request->symbol();

    Security* security = response->mutable_security();
    security->set_symbol("VOO");
    security->set_full_name("Vanguard Total Market ETF");
    security->set_current_pe_ratio(32.1);

    common::Money* price = security->mutable_current_price();
    price->set_currency_code("USD");
    price->set_price(522.1);

    return grpc::Status::OK;
}

grpc::Status SecurityServiceImpl::ListSecurities(grpc::ServerContext *context, const ListSecuritiesRequest *request, ListSecuritiesResponse *response) {
    return grpc::Status::OK;
}

}