//
// Created by Dhanush Nadella on 9/3/25.
//

#ifndef LOADER_H
#define LOADER_H

#include "nlohmann/json.hpp"
#include <format>
#include <fstream>
#include "util.h"

namespace common::config {

class Loader {
private:
    static constexpr const char* CONFIG_LOCATION_ENV_VAR = "CONFIG_LOCATION";
    static constexpr std::string DEFAULT_CONFIG_LOCATION = "../../../config/";
    static constexpr std::string BASE_CONFIG_FILE = "base.json";

public:
    template<typename T>
    T Load(const std::string env_string) {
        const char* config_location = common::util::LoadEnvVar();
        
        std::ifstream config_file(config_location, std::ios::binary);

        std::string path = std::format("base.json");
        std::vector<std::string> envs = std::views::split(env_string, ',');
        std::ifstream file(path);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open config file: " + path);
        }

        nlohmann::json j = nlohmann::json::parse(file);
        return j.get<T>();
    }
};

}

#endif //LOADER_H
