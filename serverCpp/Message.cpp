#include "Message.h"

Message::Message(const std::string& from, const std::string& message)
{
	this->from = from;
	this->message = message;
	timeMessage = time(0);
}

std::string Message::printMessage()
{
	char dataAndTime[26];
	ctime_s(dataAndTime,sizeof dataAndTime,&timeMessage);
	return "from: \t" + from + "\nrecived at:\t" + dataAndTime +"\nmessage:\t" + message + "\n";
}
