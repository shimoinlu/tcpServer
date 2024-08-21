#include "ManageClientsConnections.h"



void ManageClientsConnections::HandleConnectionRequest(SOCKET & clientSocket)
{
    char recvbuf[512];
    int recvbuflen = 512;

    int iResult = recv(clientSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        std::string request(recvbuf, iResult);

        // Parse HTTP Request
        std::istringstream requestStream(request);
        std::string method;
        std::string path;
        std::string httpVersion;

        // Parse the request line
        requestStream >> method >> path >> httpVersion;
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
        mud.isExistUserAndPasswordIsCorrect(headers["Username"], headers["Password"]);

    }
}
