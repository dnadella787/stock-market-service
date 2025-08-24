cmake_minimum_required(VERSION 3.31)
project(listener)
set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET OFF)

include(FetchContent)

# ---- Fetch spdlog (logging lib) ----
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.15.3
)
# ---- Fetch CLI11 (cli flag parsing lib) ----
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.5.0
)
# ---- Fetch libpqxx (postgres C++ lib) ----
FetchContent_Declare(
        libpqxx
        GIT_REPOSITORY https://github.com/jtv/libpqxx.git
        GIT_TAG 7.10.1
)
FetchContent_MakeAvailable(spdlog CLI11 libpqxx)

add_subdirectory(api)

add_executable(listener src/main.cpp
        src/server/api_server.cpp
        src/server/api_server.h
        src/api_service/security_service.cpp
        src/api_service/security_service.h
        src/api_service/exchange_service.cpp
        src/api_service/exchange_service.h
        src/dal/exchange_dao.cpp
        src/dal/exchange_dao.h
        src/dal/security_dao.cpp
        src/dal/security_dao.h
        src/dal/models/exchange.h
        src/dal/models/security.h
        src/dal/exceptions/entity_not_found_exception.h)
target_link_libraries(listener PRIVATE spdlog CLI11 libpqxx::pqxx proto_lib)