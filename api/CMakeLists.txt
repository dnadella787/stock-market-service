# ---- Fetch gRPC and deps----
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE) # Don't let abseil set the C++ version
set(ABSL_ENABLE_INSTALL ON CACHE BOOL "" FORCE)    # Install abseil globally
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

# Generate the gRPC and protobuf source files
file(GLOB proto_files "${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto")
set(proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.pb.cc")
set(proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.pb.h")
set(grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.grpc.pb.cc")
set(grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.grpc.pb.h")
set(protobuf_loc "/Users/dhanushnadella/Downloads/protoc-31.1-osx-aarch_64/bin/protoc")
set(grpc_cpp_plugin_loc "/opt/homebrew/Cellar/grpc/1.74.1/bin/grpc_cpp_plugin")
add_custom_command(
        OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
        COMMAND ${protobuf_loc}
        ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
        -I "${CMAKE_CURRENT_SOURCE_DIR}/proto"
        --plugin=protoc-gen-grpc="${grpc_cpp_plugin_loc}"
        "${proto_files}"
        DEPENDS "${proto_files}")

# Build lib from generated Protobuf + gRPC source files
add_library(proto_lib ${proto_srcs} ${proto_hdrs} ${grpc_srcs} ${grpc_hdrs})

# Make headers in this lib visible to others that link against it
target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against gRPC (protobuf comes w/ gRPC)
target_link_libraries(proto_lib PUBLIC grpc++)
