//
// Created by Dhanush Nadella on 8/23/25.
//

#include "exchange_dao.h"

#include <format>
#include <pqxx/transaction>

#include "exceptions/entity_not_found_exception.h"
#include "spdlog/spdlog.h"

namespace dal {

ExchangeDao::ExchangeDao(std::shared_ptr<pqxx::connection> pg_conn) : pg_conn_(pg_conn) {
    pg_conn_->prepare("get_exchange", "SELECT * FROM exchanges WHERE exchange_code = $1;");
}

std::unique_ptr<model::Exchange> ExchangeDao::GetExchange(const std::string& exchange_code) {
    pqxx::read_transaction txn{*pg_conn_};
    pqxx::result res = txn.exec(pqxx::prepped("get_exchange"), pqxx::params(exchange_code));
    if (res.empty()) {
        throw EntityNotFoundException(ExchangeEntityType, exchange_code);
    }
    const pqxx::row row = res[0];
    return std::make_unique<model::Exchange>(
        row["exchange_code"].as<std::string>(),
        row["exchange_name"].as<std::string>(),
        row["city"].as<std::string>(),
        row["country"].as<std::string>());
}

}
