#include <CLI/CLI.hpp>
#include <grpcpp/grpcpp.h>
#include "absl/log/log.h"
#include "client/exchange_client.h"

int main(const int argc, char *argv[]) {
	// Flag assignment variables
	bool debug_log = false;
	std::string exchange_symbol;

	CLI::App app {"Messaging client CLI"};
	app.add_flag("-d,--debug", debug_log, "Enable debug logging");
	app.add_option("-e,--exchange-symbol", exchange_symbol, "Exchange symbol")->required();

	CLI11_PARSE(app, argc, argv);

	LOG(INFO) << "Initiating exchange market gRPC client creation";
	client::ExchangeClient client(grpc::CreateChannel("127.0.0.1:21000", grpc::InsecureChannelCredentials()));
	client.GetExchange(exchange_symbol);
	return 0;
}
