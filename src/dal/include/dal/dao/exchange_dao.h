//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef EXCHANGE_DAO_H
#define EXCHANGE_DAO_H

#include "dal/store/postgres_data_store.h"
#include "dal/models/exchange.h"
#include <memory>

namespace dal::dao {

class ExchangeDao {
public:
	static constexpr std::string_view ExchangeEntityType = "Exchange";

	explicit ExchangeDao(const std::shared_ptr<store::PostgresDataStore> &pg_conn);
	[[nodiscard]] std::unique_ptr<model::Exchange> GetExchange(const std::string &exchange_code) const;
private:
	std::shared_ptr<store::PostgresDataStore> pg_;
};

} // namespace dal::dao

#endif // EXCHANGE_DAO_H