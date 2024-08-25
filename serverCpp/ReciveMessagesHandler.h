#pragma once
#include <string>
#include "RequestHandler.h"

class ReciveMessagesHandler :
    public RequestHandler
{
    ManageUsersData& mud;
public:

    ReciveMessagesHandler(ManageUsersData& m):mud(m){}
    void executeCommand(std::string request)override;
};

