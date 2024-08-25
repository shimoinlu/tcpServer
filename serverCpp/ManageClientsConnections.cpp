#include "ManageClientsConnections.h"
#include "RequestHandler.h"
#include "FactryRequestHandlers.h"
#include <thread>


ManageClientsConnections::ManageClientsConnections()
{
    mud = ManageUsersData::getInstance();
}

void ManageClientsConnections::HandleConnectionRequest(void* clientSocket)
{

    char recvbuf[512];
    int recvbuflen = 512;

    SOCKET* pClientSocket = static_cast<SOCKET*>(clientSocket);
    SOCKET ClientSocket = *pClientSocket;
    string message;
    int iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        std::string request(recvbuf, iResult);
        try {
            message.clear();
            FactryRequestHandlers f;
            RequestHandler* r = nullptr;
                 r = f.getHandler(recvbuf, iResult,message);
            r->executeCommand(string(recvbuf, iResult));
            RetHttpOk(ClientSocket, message);
            delete r;
        }
        catch (exception& e)
        {
            RetErrorHttpRespone(ClientSocket, e.what());
            closesocket(ClientSocket);
        }
        closesocket(ClientSocket);
        free(pClientSocket);
    }
    else {
        int e = WSAGetLastError();
            std::cout << "error is: " << e;
    }
}



string ManageClientsConnections::getValueFromRequest(string request, string key)
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
void ManageClientsConnections::RetHttpOk(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 200 OK\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header
        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(), 0);

}
void ManageClientsConnections::RetErrorHttpRespone(SOCKET& cs, std::string message)
{
    std::string httpResponse =
        "HTTP/1.1 487 Miss Data\r\n"  // Status line
        "Content-Type: text/plain\r\n"  // Content-Type header
        "Content-Length: " + std::to_string(message.length()) + "\r\n"  // Content-Length header

        "\r\n"  // End of headers
        + message;
    send(cs, httpResponse.c_str(), httpResponse.size(), 0);

}

