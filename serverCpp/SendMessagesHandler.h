#pragma once
#include "RequestHandler.h"
class SendMessagesHandler :
    public RequestHandler
{
private:
public:
	SendMessagesHandler() = default;
	void executeCommand(std::string request,std::string& message) override;
};

