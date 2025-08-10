#include "stock.grpc.pb.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/security/server_credentials.h"
#include "spdlog/spdlog.h"

class StockMarketImpl final : public StockMarket::Service {
    grpc::Status GetStock(grpc::ServerContext* context, const GetStockRequest* request, GetStockResponse* response) override {
        spdlog::info("Received GetStock request with symbol={}", request->symbol());

        response->set_symbol("VOO");
        response->set_full_name("Vanguard Total Market ETF");
        response->set_current_pe_ratio(32.1);
        response->set_current_price(522.1);

        return grpc::Status::OK;
    }
};

void RunServer() {
    std::string server_address("127.0.0.1:21000");
    StockMarketImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    spdlog::info("Starting server on {}", server_address);
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}