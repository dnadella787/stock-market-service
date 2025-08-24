//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef SECURITY_DAO_H
#define SECURITY_DAO_H
#include <pqxx/connection>

namespace dal {

class SecurityDao {
public:
    explicit SecurityDao(std::shared_ptr<pqxx::connection> pg_conn);
    // model::Security GetSecurity(std::string& symbol);
private:
    std::shared_ptr<pqxx::connection> pg_conn_;
};

}


#endif //SECURITY_DAO_H
