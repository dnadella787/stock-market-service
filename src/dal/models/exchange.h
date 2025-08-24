//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef EXCHANGE_H
#define EXCHANGE_H
#include <string>

namespace model {

class Exchange {
public:
    Exchange(std::string code, std::string name, std::string city, std::string country) : code(code), name(name), city(city), country(country) {};
    std::string code;
    std::string name;
    std::string city;
    std::string country;
};

}



#endif //EXCHANGE_H
