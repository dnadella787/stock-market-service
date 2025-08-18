//
// Created by Dhanush Nadella on 8/11/25.
//

#include "stock_market.h"
#include "spdlog/spdlog.h"

namespace service {

grpc::Status StockMarketServiceImpl::GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) {
    return grpc::Status::OK;
}

grpc::Status StockMarketServiceImpl::ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) {
    return grpc::Status::OK;
}

grpc::Status StockMarketServiceImpl::GetStock(grpc::ServerContext* context, const GetStockRequest* request, GetStockResponse* response) {
    spdlog::info("Received GetStock request with symbol={}", request->symbol());

    Stock *stock = response->mutable_stock();
    stock->set_symbol("VOO");
    stock->set_full_name("Vanguard Total Market ETF");
    stock->set_current_pe_ratio(32.1);

    Money *price = stock->mutable_current_price();
    price->set_currency_code("USD");
    price->set_price(522.1);

    return grpc::Status::OK;
}

grpc::Status StockMarketServiceImpl::ListStocks(grpc::ServerContext *context, const ListStockRequest *request, ListStockResponse *response) {
    spdlog::info("Received ListStocks request with limit={}", request->page_size());
    return grpc::Status::OK;
}


} // service