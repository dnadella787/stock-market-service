//
// Created by Dhanush Nadella on 2/2/26.
//

#ifndef EXCHANGE_CLIENT_H
#define EXCHANGE_CLIENT_H

#endif // EXCHANGE_CLIENT_H

#include "absl/log/log.h"
#include "service/exchange.grpc.pb.h"

namespace client {

class ExchangeClient {
public:
	explicit ExchangeClient(const std::shared_ptr<grpc::Channel> &channel)
	    : stub_(service::ExchangeService::NewStub(channel)) {
	}

	void GetExchange(const std::string &code) const {
		service::GetExchangeRequest request;
		request.set_code(code);

		service::GetExchangeResponse response;
		grpc::ClientContext context;
		grpc::Status status = stub_->GetExchange(&context, request, &response);

		if (!status.ok()) {
			LOG(ERROR) << "GetExchange request failed with message=" << status.error_message()
			           << " details=" << status.error_details();
			throw std::runtime_error("GetExchange request failed");
		}
		service::Exchange exchange = response.exchange();
		LOG(INFO) << "Successful GetExchange: code=" << exchange.code() << ", name=" << exchange.full_name()
		          << "city=" << ", country=" << exchange.city() << ", exchange.country()";
	}

private:
	std::unique_ptr<service::ExchangeService::Stub> stub_;
};

} // namespace client
