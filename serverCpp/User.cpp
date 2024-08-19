#include "User.h"
User::User(const std::string& userNameParameter, const std::string& password)
{
	userName = userNameParameter;
	pass = password;
}

bool User::validatePassword(const std::string& password)
{
	return pass.compare(password);
}
bool User::operator<(User Right)
{
	return strcmp(userName.c_str(), Right.getUserName().c_str()) < 0;
}

