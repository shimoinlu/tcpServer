#pragma once
#include "ManageUsersData.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include "DisconnectedException.h"

struct CustomCompare {
	bool operator()(const std::string& lhs, const std::string& rhs) const {
		// Custom comparison logic
		return lhs < rhs; // Example: lexicographical order
	}
};

class RequestHandler
{
protected:
	ManageUsersData* mud;
public:
	static std::map<std::string, std::string>  dataConnection;

	RequestHandler();
	virtual void executeCommand(std::string request,std::string& message) = 0;
	static string getValueFromRequest(string request, string key);
};

