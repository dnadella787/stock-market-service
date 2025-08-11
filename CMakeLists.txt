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
FetchContent_MakeAvailable(spdlog)

# ---- Fetch CLI11 (cli flag parsing lib) ----
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.5.0
)
FetchContent_MakeAvailable(CLI11)

add_subdirectory(api)

add_executable(listener src/main.cpp
        src/service/stock_market.cpp
        src/service/stock_market.h)
target_link_libraries(listener PRIVATE spdlog CLI11 proto_lib)