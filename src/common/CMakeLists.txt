set(JSON_BuildTests OFF CACHE INTERNAL "") # disable JSON lib unit tests
# ---- Fetch JSON parsing lib ----
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        v3.12.0)
FetchContent_MakeAvailable(json)

# Build lib from all common cpp + header files
file(GLOB_RECURSE srcs "*.cpp")
add_library(common_lib ${srcs})

# Make headers in this lib visible to others that link against it
target_include_directories(common_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(common_lib PUBLIC nlohmann_json::nlohmann_json)