//
// Created by Dhanush Nadella on 8/11/25.
//

#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H
#include "stock.grpc.pb.h"

namespace service {

class StockMarketServiceImpl final : public StockMarket::Service {
public:
    grpc::Status GetStock(grpc::ServerContext *context, const GetStockRequest *request, GetStockResponse *response) override;
};

} // service

#endif //STOCK_MARKET_H
