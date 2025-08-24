add_executable(stock-market-api main.cpp
        server/server.cpp
        server/server.h
        services/exchange_service.cpp
        services/exchange_service.h
        services/security_service.cpp
        services/security_service.h)
target_link_libraries(stock-market-api PRIVATE spdlog CLI11 proto_lib dal_lib)