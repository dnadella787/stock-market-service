//
// Created by Dhanush Nadella on 10/2/25.
//

#include "util.h"

#include <string>

#include "absl/log/log.h"
#include "common/config/loader.h"

namespace common::util {

static const char* LoadEnvVar(const char *env_var, const char *default_val) override {
    const char* val = std::getenv(env_var);
    if (val == nullptr) {
        LOG(INFO) << env_var << " not set, using default value: " << default_val;
        return default_val;
    }
    return val;
}

}
