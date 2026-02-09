//
// Created by Dhanush Nadella on 2/4/26.
//

#ifndef STOCK_MARKET_SERVICE_CONN_H
#define STOCK_MARKET_SERVICE_CONN_H

#include <string>

namespace dal::dao {
class ExchangeDao;
class SecurityDao;
}

namespace dal::store {

class PostgresDataStore {
public:
	PostgresDataStore(
		const std::string &host,
		const int &port,
		const std::string &db_name,
		const std::string &user,
		const std::string &password);

	~PostgresDataStore();
private:
	class ConnectionHandler;
	std::unique_ptr<ConnectionHandler> handler_;

	friend class dao::ExchangeDao;
	[[nodiscard]] ConnectionHandler* get_handler() const { return handler_.get(); }
};

}
#endif // STOCK_MARKET_SERVICE_CONN_H
