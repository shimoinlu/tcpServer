#include "LoginRequestHandler.h"
#include <ctime>
LoginRequestHandler::LoginRequestHandler()
{
}

void LoginRequestHandler::executeCommand(std::string request, std::string& message)
{
	string username = getValueFromRequest(request, "Username");
	string password = getValueFromRequest(request, "Password");
	mud->isExistUserAndPasswordIsCorrect(username, password);

	std::hash<time_t> hashLoginCode;
	time_t t = time(NULL);
	std::ostringstream oss;
	std::string hash = std::to_string(hashLoginCode(t));
	oss << "{";
	oss << "\"hashCode\": \"" << hash << "\"";
	oss << "}";
	message = oss.str();
	RequestHandler::dataConnection[username] = hash;
}
