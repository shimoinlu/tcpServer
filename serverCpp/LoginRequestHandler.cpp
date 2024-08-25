#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler()
{
}

void LoginRequestHandler::executeCommand(std::string request)
{
    string username = getValueFromRequest(request, "Username");
    string password = getValueFromRequest(request, "Password");
    mud->isExistUserAndPasswordIsCorrect(username, password);
}
