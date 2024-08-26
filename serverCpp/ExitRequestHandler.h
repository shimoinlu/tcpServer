#pragma once
#include "RequestHandler.h"
class ExitRequestHandler:public RequestHandler
{
public:
	ExitRequestHandler() {}
	void executeCommand(std::string request, std::string& message);
};

