#include "SendMessagesHandler.h"

void SendMessagesHandler::executeCommand(std::string request)
{
    string from = getValueFromRequest(request, "Username");
    string data = request.substr(request.find("recipient"));
    string recipient = data.substr(data.find_first_of("=") + 1);
    recipient = recipient.substr(0, recipient.find("&"));
    string message = data.substr(data.find_last_of("=") + 1);
    mud->pushMessage(from, recipient, message);

}