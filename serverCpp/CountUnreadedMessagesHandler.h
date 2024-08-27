#pragma once
#include "RequestHandler.h"
class CountUnreadedMessagesHandler:public RequestHandler
{
public:
	void executeCommand(std::string request, std::string& message);
};

