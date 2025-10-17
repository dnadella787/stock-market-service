//
// Created by Dhanush Nadella on 9/8/25.
//

#ifndef DB_CONFIG_H
#define DB_CONFIG_H
#include <string>

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"

namespace dal::config {
static constexpr int DEFAULT_PORT = 5432;

struct DbConfig {
	std::string name_;
	std::string host_;
	int port_ = DEFAULT_PORT;
	std::string username_;
	std::string password_;
};

inline void from_json(const nlohmann::json &json, DbConfig &cfg) {
	json.at("name").get_to(cfg.name_);
	json.at("host").get_to(cfg.host_);
	json.at("port").get_to(cfg.port_);
	json.at("username").get_to(cfg.username_);
	json.at("password").get_to(cfg.password_);
}
} // namespace dal::config

#endif // DB_CONFIG_H
