# ---- Fetch gRPC and deps----
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE) # Don't let abseil set the C++ version
set(ABSL_ENABLE_INSTALL ON CACHE BOOL "" FORCE)    # Install abseil
FetchContent_Declare(
        abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG 20250512.1
)
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc.git
        GIT_TAG v1.74.1
)
FetchContent_MakeAvailable(abseil gRPC)

# Grab list of gRPC and protobuf files
file(GLOB_RECURSE srcs "*.pb.cc" "*.pb.h")

# Build lib from generated Protobuf + gRPC source files
add_library(proto_lib ${srcs})

# Make headers in this lib visible to others that link against it
target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against gRPC (protobuf comes w/ gRPC)
target_link_libraries(proto_lib PUBLIC grpc++)
