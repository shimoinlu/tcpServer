#pragma once
#include "RequestHandler.h"
#include "ManageUsersData.h"
class LoginRequestHandler:
    public RequestHandler
{
private:

public:
    LoginRequestHandler();
    void executeCommand(std::string request,std::string& message)override;
};

