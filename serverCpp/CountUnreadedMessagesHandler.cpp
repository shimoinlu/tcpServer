#include "CountUnreadedMessagesHandler.h"

void CountUnreadedMessagesHandler::executeCommand(std::string request, std::string& message)
{
	cout << "from function " << __FUNCTION__ << '\n'; 
	string username = getValueFromRequest(request, "Username");
	std::map<std::string, std::string>::iterator it = RequestHandler::dataConnection.find(username);
	if (it != dataConnection.end() && it->second == getValueFromRequest(request, "hashCode"))
	{
		int unreadMessages = mud->NumOfUnreadMessagesForSpecificUser(username);
		std::ostringstream oss;
		oss << "{";
		oss << "\"unreadMessages\": \"" << unreadMessages << "\"";
		oss << "}";
		message = oss.str();
	}
	else
		throw DisconnectedException();

}
