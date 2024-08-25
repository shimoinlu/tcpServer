#pragma once
#include "ManageUsersData.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>



class RequestHandler
{
protected:
	ManageUsersData* mud;
public:
	RequestHandler();
	virtual void executeCommand(std::string request) = 0;
	static string getValueFromRequest(string request, string key);
};

