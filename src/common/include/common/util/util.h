//
// Created by Dhanush Nadella on 10/2/25.
//

#ifndef UTIL_H
#define UTIL_H
#include <string>

namespace common::util {

static std::string LoadEnvVar(const std::string& env_var, const std::string &default_val);

static char* LoadEnvVar(const char* env_var, const std::string default_val);

}

#endif //UTIL_H
