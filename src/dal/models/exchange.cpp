//
// Created by Dhanush Nadella on 8/24/25.
//

#include "models/exchange.h"

namespace dal::model {

Exchange::Exchange(const std::string &code, const std::string &name, const std::string &city,
                   const std::string &country)
    : code_(code), name_(name), city_(city), country_(country) {
}

[[nodiscard]] std::string Exchange::code() const {
	return code_;
}

[[nodiscard]] std::string Exchange::name() const {
	return name_;
}

[[nodiscard]] std::string Exchange::city() const {
	return city_;
}

[[nodiscard]] std::string Exchange::country() const {
	return country_;
}

} // namespace dal::model
