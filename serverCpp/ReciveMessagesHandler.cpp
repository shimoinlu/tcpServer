#include "ReciveMessagesHandler.h"

void ReciveMessagesHandler::executeCommand(std::string request,std::string& message)
{
	string username = getValueFromRequest(request, "Username");
	output = mud->allMessagesAsJsonForSpecificUser(username);
}
