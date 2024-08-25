#include "FactryRequestHandlers.h"
enum TypeRequest
{
    LOGIN, EXIT, SEND_MESSAGE, RECIVE_MESSAGES
};

RequestHandler& FactryRequestHandlers::getHandler(std::string recvbuf,size_t size)
{
    std::string request = recvbuf.substr(0, size);
    TypeRequest r = indicateTypeRequest(RequestHandler::getValueFromRequest(request, "TypeRequest"));
    switch (r)
    {
    case LOGIN: {
        LoginRequestHandler lr = (mud);
        return lr;
    }
    case EXIT:
    {
        break;
    }
    case SEND_MESSAGE: {
        SendMessagesHandler smr(mud);
        return smr;
    }
    case RECIVE_MESSAGES:
    {
        ReciveMessagesHandler rmr(mud);
        return rmr;
    }
    default:
        throw exception("invalid Request");
    }
}
TypeRequest FactryRequestHandlers::indicateTypeRequest(std::string r)
{
    if (r.compare("login") == 0)
        return TypeRequest::LOGIN;
    else if (r.compare("sendMessage") == 0)
        return TypeRequest::SEND_MESSAGE;
}
