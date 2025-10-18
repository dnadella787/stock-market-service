set(JSON_BuildTests OFF CACHE INTERNAL "") # disable JSON lib unit tests
# ---- Fetch JSON parsing lib ----
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        v3.12.0)
FetchContent_MakeAvailable(json)

# Create interface lib (no cpp files, header only)
add_library(common_lib INTERFACE)

# Make headers in this lib visible to others that link against it
target_include_directories(
        common_lib
        INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link dependencies (header-only and external)
target_link_libraries(
        common_lib
        INTERFACE
            nlohmann_json::nlohmann_json
            absl::log
)