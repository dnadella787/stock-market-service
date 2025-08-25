//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <string>

namespace dal::model {

class Exchange {
public:
    Exchange(const std::string& code, const std::string& name, const std::string& city, const std::string& country);
    std::string code;
    std::string name;
    std::string city;
    std::string country;
};

}

#endif //EXCHANGE_H