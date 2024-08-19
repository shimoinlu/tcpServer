#include "User.h"
#include <algorithm>
User::User(const std::string& userNameParameter, const std::string& password)
{
	userName = userNameParameter;
	pass = password;
	messageCounter = readedMessage = 0;
}

bool User::validatePassword(const std::string& password)
{
	return pass.compare(password);
}
bool User::operator<(User Right)
{
	return strcmp(userName.c_str(), Right.getUserName().c_str()) < 0;
}

void User::addMessage(const Message& msg)
{
	++messageCounter;
	vecMsg.push_back(msg);
}

std::string User::printAllMessages()
{
	std::string res = "";
	for(auto& msg : vecMsg)
	{
		res += msg.printMessage();
	}
	return res;
}

