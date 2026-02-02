add_executable(
        cli main.cpp
)

target_link_libraries(
        cli
        PRIVATE
        CLI11
        proto_lib
        common_lib
)