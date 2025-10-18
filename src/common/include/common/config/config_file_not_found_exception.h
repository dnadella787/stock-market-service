//
// Created by Dhanush Nadella on 10/18/25.
//

#ifndef CONFIG_LOADER_EXCEPTION_H
#define CONFIG_LOADER_EXCEPTION_H

#include <stdexcept>
#include <string_view>

namespace common::config::exception {

class ConfigFileNotFoundException : public std::runtime_error {
public:
	ConfigFileNotFoundException(std::string_view file_name);
};

} // namespace common::config::exception

#endif // CONFIG_LOADER_EXCEPTION_H
