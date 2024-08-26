#include "ReciveMessagesHandler.h"

void ReciveMessagesHandler::executeCommand(std::string request,std::string& message)
{
	string username = getValueFromRequest(request, "Username");
	std::map<std::string, std::string>::iterator it = RequestHandler::dataConnection.find(username);
	if (it != dataConnection.end() && it->second == getValueFromRequest(request, "hashCode"))
		output = mud->allMessagesAsJsonForSpecificUser(username);
	else
		throw DisconnectedException();
}
