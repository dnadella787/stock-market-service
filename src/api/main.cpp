//
// Created by Dhanush Nadella on 8/24/25.
//

#include <CLI/CLI.hpp>

#include "absl/log/globals.h"
#include "common/config/config_loader.h"
#include "grpcpp/security/server_credentials.h"
#include "server/server.h"

int main(const int argc, char *argv[]) {
	// Flag assignment variables
	std::string env;

	// Setup CLI flag parsing logic
	CLI::App app {"Start a gRPC server that returns stock market data"};
	app.add_option("--env", env, "Env to use (local, beta, prod)")->default_val("prod");

	// parse flags
	CLI11_PARSE(app, argc, argv);

	try {
		const api::config::ApiServerCfg cfg = common::config::ConfigLoader::Load<api::config::ApiServerCfg>(env);

		// create and start server
		api::server::Server server(cfg);
	} catch (const common::config::exception::ConfigFileNotFoundException &e) {
		LOG(ERROR) << "Exception while loading API server config: " << e.what();
		LOG(INFO) << "Exiting gracefully without starting server...";
		exit(-1);
	} catch (const std::exception &e) {
		LOG(ERROR) << "Unknown exception occurred: " << e.what();
		LOG(INFO) << "Exiting gracefully without starting server...";
		exit(-1);
	}

	return 0;
}