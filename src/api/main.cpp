//
// Created by Dhanush Nadella on 8/24/25.
//

#include <CLI/CLI.hpp>

#include "absl/log/globals.h"
#include "grpcpp/security/server_credentials.h"
#include "server/server.h"


int main(const int argc, char* argv[]) {
    // Flag assignment variables
    std::string server_address;
    std::string db_host;
    std::string db_name;
    int db_port;
    std::string db_user;
    std::string db_pwd;

    // Setup CLI flag parsing logic
    CLI::App app{"Start a gRPC server that returns stock market data"};
    app.add_option("-s,--server_address", server_address, "Address of server in form [localIP]:[port] (i.e. 127.0.0.1:21000)")
        ->default_val("127.0.0.1:21000");
    app.add_option("--db-host", db_host, "Host of postgres DB")->required();
    app.add_option("--db-port", db_port, "Port of postgres DB")->required();
    app.add_option("--db-name", db_name, "Name of postgres DB")->required();
    app.add_option("--db-user", db_user, "Username to access postgres DB")->required();
    app.add_option("--db-pwd", db_pwd, "Password to access postgres DB")->required();

    // parse flags
    CLI11_PARSE(app, argc, argv);

    absl::
    absl::SetLogColorMessageStyle(absl::LogColorMessageStyle::kAlways);
    // create and start server
    api::server::Server server(server_address, db_host, db_port, db_name, db_user, db_pwd);

    return 0;
}