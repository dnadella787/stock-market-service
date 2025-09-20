//
// Created by Dhanush Nadella on 9/3/25.
//

#ifndef LOADER_H
#define LOADER_H

#include "nlohmann/json.hpp"
#include <format>
#include <fstream>

namespace common::config {

class Loader {
    public:
    template<typename T>
    T Load(const std::string_view env) {
        std::string path = std::format("../../../config/{}.json", env);
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
