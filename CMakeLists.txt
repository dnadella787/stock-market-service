cmake_minimum_required(VERSION 3.25...4.1)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(stock-market-service)
set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET OFF)

include(FetchContent)

# ---- Fetch CLI11 (cli flag parsing lib) ----
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.5.0)
FetchContent_MakeAvailable(CLI11)

add_subdirectory(grpc-contract)
add_subdirectory(src/common)
add_subdirectory(src/dal)
add_subdirectory(src/cli)
add_subdirectory(src/api)