#include "ExitRequestHandler.h"


void ExitRequestHandler::executeCommand(std::string request, std::string& message)
{
	dataConnection.erase(getValueFromRequest(request, "hashCode"));
}
