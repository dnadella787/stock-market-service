//
// Created by Dhanush Nadella on 8/23/25.
//

#include "dal/dao/exchange_dao.h"

#include "../store/connection_handler_internal.h"
#include "dal/connection/postgres_data_store.h"
#include "dal/exceptions/entity_not_found_exception.h"
#include <pqxx/transaction>

namespace dal::dao {

ExchangeDao::ExchangeDao(const std::shared_ptr<store::PostgresDataStore> &pg) : pg_(pg) {
	pg_->get_handler()->PrepareStatement("get_exchange", "SELECT * FROM exchanges WHERE exchange_code = $1;");
}

[[nodiscard]] std::unique_ptr<model::Exchange> ExchangeDao::GetExchange(const std::string &exchange_code) const {
	pqxx::read_transaction txn = pg_->get_handler()->GetReadTransaction();
	try {
		const pqxx::row res = txn.exec(pqxx::prepped("get_exchange"), pqxx::params(exchange_code)).one_row();
		return std::make_unique<model::Exchange>(res["exchange_code"].as<std::string>(),
		                                         res["exchange_name"].as<std::string>(), res["city"].as<std::string>(),
		                                         res["country"].as<std::string>());
	} catch (const pqxx::unexpected_rows &_) {
		throw exception::EntityNotFoundException(ExchangeEntityType, exchange_code);
	}
}

} // namespace dal::dao
