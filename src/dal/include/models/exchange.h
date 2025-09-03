//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <string>

namespace dal::model {

class Exchange {
public:
	Exchange(const std::string &code, const std::string &name, const std::string &city, const std::string &country);

	// Getters
	[[nodiscard]] std::string code() const;
	[[nodiscard]] std::string name() const;
	[[nodiscard]] std::string city() const;
	[[nodiscard]] std::string country() const;

private:
	std::string code_;
	std::string name_;
	std::string city_;
	std::string country_;
};

} // namespace dal::model

#endif // EXCHANGE_H