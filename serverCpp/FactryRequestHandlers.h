#pragma once
#include <string>
#include "RequestHandler.h"
#include "LoginRequestHandler.h"
#include "ReciveMessagesHandler.h"
#include "SendMessagesHandler.h"

enum TypeRequest;

class FactryRequestHandlers
{
	ManageUsersData& mud;
public:
	FactryRequestHandlers(ManageUsersData& m):mud(m){}
	TypeRequest indicateTypeRequest(std::string r);
	RequestHandler& getHandler(std::string recvbuf, size_t size);
};

