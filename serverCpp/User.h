#pragma once
#include <cstring>
#include <string>
#include <vector>


class User
{
private:
	std::string userName;
	std::string pass;
public:
	User(const std::string& userNameParameter, const std::string& password);
	bool validatePassword(const std::string& password);
	std::string getUserName() { return userName; }
	bool operator< (User Right);


};


