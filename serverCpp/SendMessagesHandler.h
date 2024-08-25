#pragma once
#include "RequestHandler.h"
class SendMessagesHandler :
    public RequestHandler
{
private:
	ManageUsersData& mud;
public:
	SendMessagesHandler(ManageUsersData& m):mud(m){}
	void executeCommand(std::string request) override;
};

