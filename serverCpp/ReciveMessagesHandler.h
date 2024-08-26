#pragma once
#include <string>
#include <winsock2.h>
#include "RequestHandler.h"

class ReciveMessagesHandler :
    public RequestHandler
{
private:
        string& output;
public:
    ReciveMessagesHandler(string& msg) :output(msg) {}
    void executeCommand(std::string request,std::string& message)override;
};

