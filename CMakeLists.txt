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

# ---- Fetch Abseil (required for gRPC) ----
FetchContent_Declare(
        abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG 20250512.1
)
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE)
set(ABSL_ENABLE_INSTALL ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(abseil)

# ---- Fetch gRPC ----
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG v1.74.1
)
FetchContent_MakeAvailable(gRPC)

set(GENERATED_PROTO_SRCS
        ${CMAKE_SOURCE_DIR}/api/stock.grpc.pb.cc
        ${CMAKE_SOURCE_DIR}/api/stock.pb.cc
)

add_executable(listener src/main.cpp ${GENERATED_PROTO_SRCS})
target_link_libraries(listener PRIVATE spdlog CLI11 grpc++)