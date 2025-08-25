//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef SECURITY_H
#define SECURITY_H

#include <string>

namespace dal::model {

class Security {
    Security(const std::string& symbol, const std::string& company_name, const std::string& exchange_code);
    std::string symbol;
    std::string company_name;
    std::string exchange_code;
};

}

#endif //SECURITY_H
