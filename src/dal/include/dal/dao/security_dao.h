//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef SECURITY_DAO_H
#define SECURITY_DAO_H

#include "dal/connection/postgres_data_store.h"

namespace dal::dao {

class SecurityDao {
public:
	explicit SecurityDao(const std::shared_ptr<store::PostgresDataStore> &pg);
	// model::Security GetSecurity(std::string& symbol);
private:
	std::shared_ptr<store::PostgresDataStore> pg_;
};

} // namespace dal::dao

#endif // SECURITY_DAO_H
