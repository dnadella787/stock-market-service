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

# Generate the gRPC and protobuf source files
# TODO: Find the protoc and grpc_cpp_plugin executables dynamically
file(GLOB proto_files "${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto")
set(proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.pb.cc")
set(proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.pb.h")
set(grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.grpc.pb.cc")
set(grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/stockmarket.grpc.pb.h")
set(protobuf_loc "/Users/dhanushnadella/Downloads/protoc-31.1-osx-aarch_64/bin/protoc")
set(grpc_cpp_plugin_loc "${grpc_BINARY_DIR}/grpc_cpp_plugin")
add_custom_command(
        OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
        COMMAND ${protobuf_loc}
        ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
        -I "${CMAKE_CURRENT_SOURCE_DIR}/proto"
        --plugin=protoc-gen-grpc="${grpc_cpp_plugin_loc}"
        "${proto_files}"
        DEPENDS "${proto_files}")

# Build lib
add_library(proto_lib ${proto_srcs} ${proto_hdrs} ${grpc_srcs} ${grpc_hdrs})

# Ensure this library's headers are visible to anything that links it
target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against protobuf and gRPC
target_link_libraries(proto_lib PUBLIC grpc++)
