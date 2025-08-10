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

# Find all protobuf and gRPC generated files to build lib
file(GLOB PROTO_SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.pb.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.grpc.pb.cc"
)

file(GLOB PROTO_HDRS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.pb.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.grpc.pb.h"
)

# Build lib
add_library(proto_lib ${PROTO_SRCS} ${PROTO_HDRS})

# Ensure this library's headers are visible to anything that links it
target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against protobuf and gRPC
target_link_libraries(proto_lib PUBLIC grpc++)
