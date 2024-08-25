#include "ReciveMessagesHandler.h"


void ReciveMessagesHandler::executeCommand(std::string request)
{
	string username = getValueFromRequest(request, "Username");
	output = mud->allMessagesAsJsonForSpecificUser(username);
}
