//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef SECURITY_SERVICE_H
#define SECURITY_SERVICE_H
#include <service/security.grpc.pb.h>
#include "../db/postgres_client.h"

using namespace service;

namespace apiservice {

class SecurityServiceImpl final : public SecurityService::Service {
    public:
        SecurityServiceImpl(std::shared_ptr<db::PostgresClient> db_client);

        // API implementations
        grpc::Status GetSecurity(grpc::ServerContext *context, const GetSecurityRequest *request, GetSecurityResponse *response) override;
        grpc::Status ListSecurities(grpc::ServerContext *context, const ListSecuritiesRequest *request, ListSecuritiesResponse *response) override;
    private:
        std::shared_ptr<db::PostgresClient> db_client_;
    };

} // apiservice

#endif //SECURITY_SERVICE_H