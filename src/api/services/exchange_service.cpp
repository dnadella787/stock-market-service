//
// Created by Dhanush Nadella on 8/11/25.
//

#include "exchange_service.h"

#include "absl/log/log.h"
#include "dal/exceptions/entity_not_found_exception.h"

using namespace service;

namespace api::service {

ExchangeServiceImpl::ExchangeServiceImpl(const std::shared_ptr<dal::dao::ExchangeDao> &exchange_dao) {
	exchange_dao_ = exchange_dao;
}

grpc::Status ExchangeServiceImpl::GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request,
                                              GetExchangeResponse *response) {
	LOG(INFO) << "Received GetExchange request for exchange_code=" << request->code();
	try {
		const std::unique_ptr<dal::model::Exchange> db_exchange = exchange_dao_->GetExchange(request->code());

		Exchange *exchange = response->mutable_exchange();
		exchange->set_code(db_exchange->code());
		exchange->set_full_name(db_exchange->name());
		exchange->set_city(db_exchange->city());
		exchange->set_country(db_exchange->country());

		LOG(INFO) << "Returning successful GetExchange response for exchange_code=" << request->code();
		return grpc::Status::OK;
	} catch (const dal::exception::EntityNotFoundException &e) {
		LOG(ERROR) << "No exchange in DB with exchange_code=" << request->code();
		return {grpc::StatusCode::NOT_FOUND, e.what()};
	} catch (const std::exception &e) {
		LOG(ERROR) << "Getting exchange from DB with exchange_code=" << request->code()
		           << " resulted in unknown exception=" << e.what();
		return {grpc::StatusCode::INTERNAL, "Internal server error"};
	}
}

grpc::Status ExchangeServiceImpl::ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request,
                                                ListExchangesResponse *response) {
	return grpc::Status::OK;
}

} // namespace api::service
