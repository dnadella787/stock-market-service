//
// Created by Dhanush Nadella on 10/18/25.
//

#include "common/config/config_file_not_found_exception.h"

#include <format>

namespace common::config::exception {

    ConfigFileNotFoundException::ConfigFileNotFoundException(std::string_view file_name)
        : std::runtime_error(std::format("Config file '{}' could not be found.")) {
    }

} // namespace dal::exception