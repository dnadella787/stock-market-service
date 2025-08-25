//
// Created by Dhanush Nadella on 8/23/25.
//

#ifndef SECURITY_SERVICE_H
#define SECURITY_SERVICE_H
#include <service/security.grpc.pb.h>

#include "../../dal/include/dao/security_dao.h"

using namespace service;

namespace api::service {

class SecurityServiceImpl final : public SecurityService::Service {
public:
    SecurityServiceImpl(const std::shared_ptr<dal::dao::SecurityDao> &security_dao);

    // API implementations
    grpc::Status GetSecurity(grpc::ServerContext *context, const GetSecurityRequest *request, GetSecurityResponse *response) override;
    grpc::Status ListSecurities(grpc::ServerContext *context, const ListSecuritiesRequest *request, ListSecuritiesResponse *response) override;
private:
    std::shared_ptr<dal::dao::SecurityDao> security_dao_;
};

}

#endif //SECURITY_SERVICE_H