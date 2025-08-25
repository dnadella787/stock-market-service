//
// Created by Dhanush Nadella on 8/24/25.
//

#include "models/exchange.h"

namespace dal::model {

Exchange::Exchange(const std::string& code, const std::string& name, const std::string& city, const std::string& country)
    : code(code), name(name), city(city), country(country) {}

}

