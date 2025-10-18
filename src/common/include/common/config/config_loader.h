//
// Created by Dhanush Nadella on 9/3/25.
//

#ifndef LOADER_H
#define LOADER_H

#include "absl/log/log.h"
#include "nlohmann/json.hpp"
#include <format>
#include <fstream>

#include "config_loader_exception.h"

namespace common::config {

class ConfigLoader {
private:
	static constexpr const char *CONFIG_LOCATION_ENV_VAR = "CONFIG_LOCATION";
	static constexpr const char *BASE_CONFIG_FILE = "base.json";

public:
	ConfigLoader() = delete; // static class, prevent instantiation

	template <typename T>
	static T Load(const std::string_view env_string) {
		// 1. Get CONFIG_LOCATION environment variable
		const char *env_ptr = std::getenv(CONFIG_LOCATION_ENV_VAR);
		if (!env_ptr) {
			throw exception::ConfigLoaderException(std::format("{} env var not found", CONFIG_LOCATION_ENV_VAR));
		}
		LOG(INFO) << "Loading config from " << env_ptr;
		std::filesystem::path config_location = env_ptr;

		// 2. Load base config
		std::filesystem::path base_path = config_location / BASE_CONFIG_FILE;
		std::ifstream base_file(base_path, std::ios::binary);
		if (!base_file.is_open()) {
			throw exception::ConfigLoaderException(
			    std::format("Config file '{}' could not be found", base_path.string()));
		}

		nlohmann::json j = nlohmann::json::parse(base_file);
		LOG(INFO) << "Successfully loaded base config from " << base_path.string();

		// 3. Apply overrides from env_string (comma-separated)
		for (auto &&env : std::views::split(env_string, ',')) {
			std::string_view env_name(&*env.begin(), std::ranges::distance(env));
			std::filesystem::path override_path = config_location / std::format("{}.json", env_name);

			std::ifstream override_file(override_path);
			if (!override_file.is_open()) {
				throw exception::ConfigLoaderException(
				    std::format("Config file '{}' could not be found", override_path.string()));
			}

			j.update(nlohmann::json::parse(override_file));
			LOG(INFO) << "Successfully loaded " << env_name << " override config from " << override_path.string();
		}

		// 4. Convert JSON to target class
		return j.get<T>();
	}
};

} // namespace common::config

#endif // LOADER_H
