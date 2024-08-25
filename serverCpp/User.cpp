#include "User.h"
#include <algorithm>
User::User( std::string const & userNameParameter,  std::string const& password)
{
	userName = userNameParameter;
	pass = password;
	messageCounter = readedMessage = 0;
	vecMsg = std::vector<Message>();
}

User::User(std::string const& line)
	:User(line.substr(0, line.find(" ")), line.substr(line.find(" ")+1))
{

}

bool User::validatePassword(const std::string& password)
{
	return pass.compare(password) == 0;
}
bool User::operator<(User Right)
{
	return strcmp(userName.c_str(), Right.getUserName().c_str()) < 0;
}

bool User::operator>(User Right)
{
	return Right < *this;
}

bool User::operator==(User Right)
{
	return !(*this < Right) && !(*this > Right);
}

void User::addMessage(const Message msg)
{
	++messageCounter;
	vecMsg.push_back(msg);
}

std::string User::printAllMessagesAsJson()
{
		std::ostringstream oss;
		oss << "[";  // Start of JSON array

		for (size_t i = 0; i < vecMsg.size(); ++i) {
			oss << vecMsg[i].toJSON();
			if (i < vecMsg.size() - 1) {
				oss << ", ";  // Add a comma between JSON objects
			}
		}
		oss << "]";  // End of JSON array
		return oss.str();
}

