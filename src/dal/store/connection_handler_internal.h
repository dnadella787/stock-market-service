//
// Created by Dhanush Nadella on 2/9/26.
//

#ifndef STOCK_MARKET_SERVICE_CONNECTION_HANDLER_INTERNAL_H
#define STOCK_MARKET_SERVICE_CONNECTION_HANDLER_INTERNAL_H

#include "dal/store/postgres_data_store.h"
#include <memory>
#include <pqxx/transaction>

namespace dal::store {

class PostgresDataStore::ConnectionHandler {
public:
	std::unique_ptr<pqxx::connection> pq_conn_;

	explicit ConnectionHandler(const std::string &connection_string) {
		pq_conn_ = std::make_unique<pqxx::connection>(connection_string);
	};

	void PrepareStatement(const std::string &statement_name, const std::string &statement) {
		pq_conn_->prepare(statement_name, statement);
	}

	[[nodiscard]] pqxx::read_transaction GetReadTransaction() const {
		return pqxx::read_transaction{*pq_conn_};
	}
};

}

#endif // STOCK_MARKET_SERVICE_CONNECTION_HANDLER_INTERNAL_H
