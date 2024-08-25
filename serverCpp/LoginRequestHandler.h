#pragma once
#include "RequestHandler.h"
#include "ManageUsersData.h"
class LoginRequestHandler:
    public RequestHandler
{
private:
    ManageUsersData& mud;

public:
    LoginRequestHandler(ManageUsersData& m) :mud(m) {}
    void executeCommand(std::string request)override;
};

