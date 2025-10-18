//
// Created by Dhanush Nadella on 10/18/25.
//

#include "common/config/config_loader_exception.h"

namespace common::config::exception {

ConfigLoaderException::ConfigLoaderException(const std::string &error_msg) : std::runtime_error(error_msg) {}

} // namespace common::config::exception