#include "stock.grpc.pb.h"
#include <CLI/CLI.hpp>
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "spdlog/spdlog.h"
#include "service/stock_market.h"


void StartServer(std::string& server_address) {
    service::StockMarketServiceImpl stock_market_service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&stock_market_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    spdlog::info("Starting server on {}", server_address);
    server->Wait();
}

int main(const int argc, char* argv[]) {
    // Flag assignment variables
    bool debug_log = true;
    std::string server_address;

    CLI::App app{"Messaging client CLI"};
    app.add_flag("-d,--debug", debug_log, "Enable debug logging"); // note debug level defaults to true
    app.add_option("-s,--server_address", server_address, "Address of server in form [localIP]:[port] (i.e. 127.0.0.1:21000)")
        ->default_val("127.0.0.1:21000");

    CLI11_PARSE(app, argc, argv);
    spdlog::set_level(debug_log ? spdlog::level::debug : spdlog::level::info);

    StartServer(server_address);
    return 0;
}