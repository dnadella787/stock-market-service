//
// Created by Dhanush Nadella on 8/11/25.
//

#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H
#include "stockmarket.grpc.pb.h"

namespace service {

class StockMarketServiceImpl final : public StockMarket::Service {
public:
    grpc::Status GetExchange(grpc::ServerContext *context, const GetExchangeRequest *request, GetExchangeResponse *response) override;
    grpc::Status ListExchanges(grpc::ServerContext *context, const ListExchangesRequest *request, ListExchangesResponse *response) override;
    grpc::Status GetStock(grpc::ServerContext *context, const GetStockRequest *request, GetStockResponse *response) override;
    grpc::Status ListStocks(grpc::ServerContext *context, const ListStockRequest *request, ListStockResponse *response) override;
};

} // service

#endif //STOCK_MARKET_H
