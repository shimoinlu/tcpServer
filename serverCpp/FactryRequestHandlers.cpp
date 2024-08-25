#include "FactryRequestHandlers.h"

enum TypeRequest
{
    LOGIN, EXIT, SEND_MESSAGE, RECIVE_MESSAGES
};

RequestHandler* FactryRequestHandlers::getHandler(std::string recvbuf,size_t size, string& msg )
{
    std::string request = recvbuf.substr(0, size);
    TypeRequest r = indicateTypeRequest(RequestHandler::getValueFromRequest(request, "TypeRequest"));
    switch (r)
    {
    case LOGIN: {
        return new LoginRequestHandler;
    }
    case EXIT:
    {
        break;
    }
    case SEND_MESSAGE: {
        return new SendMessagesHandler;
    }
    case RECIVE_MESSAGES:
    {
        return new ReciveMessagesHandler(msg);
    }
    default:
        throw exception("invalid Request");
    }
}
FactryRequestHandlers::FactryRequestHandlers()
{
    mud = ManageUsersData::getInstance();
}
TypeRequest FactryRequestHandlers::indicateTypeRequest(std::string r)
{
    if (r.compare("login") == 0)
        return TypeRequest::LOGIN;
    else if (r.compare("sendMessage") == 0)
        return TypeRequest::SEND_MESSAGE;
    else if (r.compare("receiveMessage") == 0)
        return TypeRequest::RECIVE_MESSAGES;
}
