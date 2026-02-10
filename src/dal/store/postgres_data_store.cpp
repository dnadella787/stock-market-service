//
// Created by Dhanush Nadella on 2/4/26.
//

#include "dal/store/postgres_data_store.h"
#include "connection_handler_internal.h"
#include <format>

namespace dal::store {

PostgresDataStore::PostgresDataStore(
	const std::string &host,
	const int &port,
	const std::string &db_name,
	const std::string &user,
	const std::string &password) {
	handler_ = std::make_unique<ConnectionHandler>(std::format("host={} port={} dbname={} user={} password={}",
		host, port, db_name, user, password));
}

PostgresDataStore::~PostgresDataStore() = default;

}
