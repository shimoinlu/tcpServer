#pragma once
#include <string>
#include <winsock2.h>
#include "RequestHandler.h"
#include "LoginRequestHandler.h"
#include "ReciveMessagesHandler.h"
#include "SendMessagesHandler.h"

enum TypeRequest;

class FactryRequestHandlers
{
	ManageUsersData* mud;
public:
	FactryRequestHandlers();
	TypeRequest indicateTypeRequest(std::string r);
	RequestHandler* getHandler(std::string recvbuf, size_t size, string& msg);
};

