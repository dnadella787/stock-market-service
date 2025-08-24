cmake_minimum_required(VERSION 3.31)
project(stock-market-service)
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
FetchContent_MakeAvailable(spdlog CLI11)

add_subdirectory(grpc-contract)
add_subdirectory(src/dal)
add_subdirectory(src/api)