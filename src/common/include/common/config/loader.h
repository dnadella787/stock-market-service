//
// Created by Dhanush Nadella on 9/3/25.
//

#ifndef LOADER_H
#define LOADER_H

#include "absl/log/log.h"
#include "nlohmann/json.hpp"
#include <format>
#include <fstream>

namespace common::config {

class Loader {
private:
    static constexpr const char* CONFIG_LOCATION_ENV_VAR = "CONFIG_LOCATION";
    static constexpr const char* BASE_CONFIG_FILE = "base.json";

public:
    template<typename T>
    T Load(const std::string_view env_string) {
        // 1. Get CONFIG_LOCATION environment variable
        const char* env_ptr = std::getenv(CONFIG_LOCATION_ENV_VAR);
        if (!env_ptr) {
            throw std::runtime_error(std::format(
                "{} environment variable could not be found", CONFIG_LOCATION_ENV_VAR));
        }
        std::filesystem::path config_location = env_ptr;

        // 2. Load base config
        std::filesystem::path base_path = config_location / BASE_CONFIG_FILE;
        std::ifstream base_file(base_path, std::ios::binary);
        if (!base_file.is_open()) {
            throw std::runtime_error("Could not open config file: " + base_path.string());
        }

        nlohmann::json j = nlohmann::json::parse(base_file);

        // 3. Apply overrides from env_string (comma-separated)
        for (auto&& env : std::views::split(env_string, ',')) {
            std::string_view env_name(&*env.begin(), std::ranges::distance(env));
            LOG(INFO) <
            std::filesystem::path override_path = config_location / std::format("{}.json", env_name);

            std::ifstream override_file(override_path);
            if (!override_file.is_open()) {
                throw std::runtime_error("Could not open config file: " + override_path.string());
            }

            j.update(nlohmann::json::parse(override_file));
        }

        // 4. Convert JSON to target class
        return j.get<T>();
    }
};

}

#endif //LOADER_H
