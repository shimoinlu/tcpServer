#pragma once
#include <string>
#include <ctime>
class Message
{
private:
	std::string message;
	std::string from;
	time_t timeMessage;
public:
	Message(const std::string& from, const std::string& message);
	std::string printMessage();
};

