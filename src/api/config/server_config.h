//
// Created by Dhanush Nadella on 9/3/25.
//

#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

#include <string>

#include "dal/config/db_config.h"

namespace api::config {

struct ApiServerCfg {
	std::string server_address_;
	dal::config::DbConfig db_config_;
};

inline void from_json(const nlohmann::json &json, ApiServerCfg &cfg) {
	json.at("serverAddress").get_to(cfg.server_address_);
	json.at("dbConfig").get_to(cfg.db_config_);
}

} // namespace api::config

#endif // SERVER_CONFIG_H
