//
// Created by Dhanush Nadella on 8/24/25.
//

#include "dal/models/security.h"

namespace dal::model {

Security::Security(const std::string &symbol, const std::string &company_name, const std::string &exchange_code)
    : symbol(symbol), company_name(company_name), exchange_code(exchange_code) {
}

} // namespace dal::model
