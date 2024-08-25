#pragma once
#include <string>
#include "RequestHandler.h"

class ReciveMessagesHandler :
    public RequestHandler
{
public:
    ReciveMessagesHandler();
    void executeCommand(std::string request)override;
};

