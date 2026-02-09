# ---- Fetch libpqxx (postgres C++ lib) ----
FetchContent_Declare(
        libpqxx
        GIT_REPOSITORY https://github.com/jtv/libpqxx.git
        GIT_TAG 7.10.5)
FetchContent_MakeAvailable(libpqxx)

# Build lib from all dal cpp + header files
file(GLOB_RECURSE srcs "*.cpp" "*.h")
add_library(dal_lib ${srcs})

# Make headers in this lib visible to others that link against it
target_include_directories(
        dal_lib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
        dal_lib
        PRIVATE
            common_lib
            libpqxx::pqxx)