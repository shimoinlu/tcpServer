#pragma once
#include <cstring>
#include <string>
#include <vector>
#include "Message.h"

class User
{
private:
	std::string userName;
	std::string pass;
	std::vector<Message> vecMsg;
	int messageCounter;
	int readedMessage;
public:
	User( std::string const& userNameParameter, std::string const& password);
	User( std::string const& line);
	bool validatePassword(const std::string& password);
	std::string getUserName() { return userName; }
	bool operator< (User Right);
	bool operator> (User Right);
	bool operator== (User Right);

	std::vector<Message> getMessages() { return vecMsg; }
	void addMessage(const Message& msg);
	std::string printAllMessages();
};


