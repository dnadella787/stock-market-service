//
// Created by Dhanush Nadella on 8/11/25.
//

#include "stock_market.h"
#include "spdlog/spdlog.h"

namespace service {

grpc::Status StockMarketServiceImpl::GetStock(grpc::ServerContext* context, const GetStockRequest* request, GetStockResponse* response) {
    spdlog::info("Received GetStock request with symbol={}", request->symbol());

    response->set_symbol("VOO");
    response->set_full_name("Vanguard Total Market ETF");
    response->set_current_pe_ratio(32.1);
    response->set_current_price(522.1);

    return grpc::Status::OK;
}

} // service