#include "RequestHandler.h"



std::map<std::string, std::string> RequestHandler::dataConnection;

RequestHandler::RequestHandler()
{
    mud = ManageUsersData::getInstance();
}

string RequestHandler::getValueFromRequest(string request, string key)
{
    {
        std::istringstream requestStream(request);

        // Parse the request line
        std::string headerLine;
        std::map<std::string, std::string> headers;

        while (std::getline(requestStream, headerLine) && headerLine != "\r\n") {
            size_t pos = headerLine.find(": ");
            if (pos != std::string::npos) {
                std::string headerName = headerLine.substr(0, pos);
                std::string headerValue = headerLine.substr(pos + 2);
                headers[headerName] = headerValue.substr(0, headerValue.length() - 1);
            }
        }


        return headers[key];
    }
}

