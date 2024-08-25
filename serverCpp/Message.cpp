#include "Message.h"

Message::Message(const std::string& from, const std::string& message)
{
	this->from = from;
	this->message = message;
	timeMessage = time(0);
}
std::string Message::toJSON() {

	char dateAndTime[26];
	ctime_s(dateAndTime, sizeof(dateAndTime), &timeMessage);

	// Remove the newline character added by ctime_s
	dateAndTime[strcspn(dateAndTime, "\n")] = '\0';

	std::ostringstream oss;
	oss << "{";
	oss << "\"from\": \"" << from << "\", ";
	oss << "\"message\": \"" << message << "\", ";
	oss << "\"timeMessage\": \"" << dateAndTime << "\"";
	oss << "}";

	return oss.str();
}